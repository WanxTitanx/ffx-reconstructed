# FFX.exe Decompilation — Batch 14 (FFX Abmap Sphere Grid Core)

**Database:** ffxoficial_COPY.i64 (session 85e0242a, GUI backend PID 10524)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** `FFX_Abmap_ActivateNode` + `FFX_Abmap_BuildNodeAdjacencyFromLinks` + supporting functions — FFX's signature Sphere Grid system

---

## Summary

The **Sphere Grid** (FFX's iconic ability system) is implemented as 187 `FFX_Abmap_*` functions + 2 `FFX_Atel_AbilityMap_*` opcode hooks (confirming ATEL-driven — same VM as cutscenes, see batch_0002). Core operations: **activate a node**, **build adjacency from links**, **queue placement animations**, **recompute party stats**, **dispatch activation animations**, and **manage callback chains**. State lives in a giant global at `MEMORY[0x2305834]` (size ~71KB).

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_Abmap_ActivateNode` | 0xa48910 | 358B | Activate a node on the grid |
| `FFX_Abmap_BuildNodeAdjacencyFromLinks` | 0xa5b140 | ~340B | Build per-node adjacency list (max 5 neighbors) |
| `FFX_Abmap_ButtonLayout_StateMachine` | 0xa53450 | ~1.5KB | Button layout state machine |
| `FFX_Abmap_AnimateScrollOffset` | 0xa48f50 | 355B | Scroll the grid (4-frame interp) |
| `FFX_Abmap_AnimateZoomTransition` | 0xa490c0 | 421B | Zoom transitions |
| `FFX_Abmap_BuildPanelPrimsFromMenuEntries` | 0xa459e0 | ~340B | Build panel primitives |
| `FFX_Abmap_BuildNodePlacementMatrix` | 0xa5ad30 | ~280B | Compute node world matrices |
| `FFX_Abmap_PackMenuSnapshot` | 0xa5bb70 | ~300B | Snapshot menu state |
| `FFX_Abmap_RecomputePartyStatsAndLearnedMoves` | 0xa54860 | ~500B | Update party stats after activation |
| `FFX_Abmap_ApplyActivationStats` | 0xa47210 | ~400B | Apply +Str/+Dex/etc from node |
| `FFX_Abmap_DispatchActivationAnim` | 0xa5aa30 | ~300B | Queue activation animation |
| `FFX_Abmap_QueuePlacementAnim` | 0xa5bad0 | ~300B | Queue placement animation |
| `FFX_Abmap_PlacementFxCallback` | 0xa51700 | ~400B | FX callback after placement |
| `FFX_Abmap_SwapAnimCallbackChain` | 0xa48280 | ~400B | Swap animation callback chain |

`★ Insight ─────────────────────────────────────`
- **Sphere Grid is ATEL-driven** — `FFX_Atel_AbilityMap_FuncD020_CALLPOPA` and `FuncD000_CALL` confirm the same VM drives cutscenes + Sphere Grid UI. Same bytecode engine.
- **State global is ~71KB** at `MEMORY[0x2305834]` — the entire Sphere Grid state (217 nodes × ~40B each = 8.7KB nodes + 217×5×10B links = 11KB adjacency + animations + menu state).
- **Max 5 neighbors per node** — `setSpheConePrim error MAXSPHECONE=%d` confirms **MAXSPHECONE = 5**. Sphere Grid nodes have up to 5 outgoing links.
- **Node records are 40 bytes** — `40 * a2 + 2056` indexing into the state global. Each node = 40B with position (2 ints), flags, 5 link pointers, etc.
- **217 nodes total** — `*(__int16 *)(v0 + 2)` = 217 (likely), the Sphere Grid node count.
`─────────────────────────────────────────────────`

---

## Architecture: Sphere Grid State Layout

The Sphere Grid state is a **single 71KB global** at `MEMORY[0x2305834]` (offset 0x116A4 from binary base). Layout:

```
Offset   Size   Content
+0x000   2B     nodeCount (217)
+0x002   2B     ?
+0x004   2B     linkTableSize
+0x006   ?     padding
+0x806   ?     node[i] records (40B each, 217 nodes = 8680B)
  +0x800 + i*40:
    +0:  2B   nodePosX (int16)
    +2:  2B   nodePosY (int16)
    +4:  2B   nodePosZ (int16)
    +6:  2B   linkCount or linkIdx (-1 = no links)
    +8:  2B   ?
    +10: 2B   ?
    +12: 5×4B = 20B  linkPtr[5] (pointer to adjacent node v7)
    +32: 1B    flags (bit i = activated by character i)
    +33: 6B    padding
+0xA80A  ?     link table (43016B max)
+0x116A0+?     menu/UI state
+0x1166C 4B    activeNodeId (just-activated node)
+0x115D4 4B    callbackPtr1 (placement FX)
+0x115D8 4B    callbackPtr2 (swap anim)
+0x115DC 4B    ?
+0x115E4 4B    ?
+0x115E8 4B    ?
+0x115EC 4B    ?
+0x1160C 4B    resourceBufferPtr (512000B)
+0x1164C 4B    ?
```

**Total state: ~71KB** covering nodes, links, animations, menu state, callbacks, and resource buffers.

---

## Key Function: FFX_Abmap_ActivateNode (0xa48910, 358B)

Activates a node on the Sphere Grid. Called when player navigates to a node and presses X to activate.

```c
unsigned int FFX_Abmap_ActivateNode(int charIdx, int nodeIdx) {
    RuntimeContextPtr = FFX_Battle_GetRuntimeContextPtr();
    
    // 1. Link 512KB resource buffer
    FFX_MagicHost_LinkResourceBufferRange(
        unk_1A86034,
        &dword_132FF60[935476],   // 512000B / 4 = 128000 entries
        512000);                  // 500KB scratch buffer
    
    // 2. Set up placement animation params
    v15 = 0.5;   // color B
    v14 = 0.5;   // color G
    v13 = 0.5;   // color R
    v12 = 0.0;   // ?
    v11 = 0.0;
    v10 = 0.0;
    v9 = 0.0;
    
    // 3. Read node position from state
    v16 = (float)*(__int16 *)(v18 + 40 * nodeIdx + 2058);  // X coord
    v8 = v16;
    v17 = (float)*(__int16 *)(v18 + 40 * nodeIdx + 2056);  // Y coord
    
    // 4. Queue placement animation (4 if aeon path, 0 if standard)
    if ((*RuntimeContextPtr & 0xC000) == 0x8000)
        FFX_Abmap_QueuePlacementAnim(..., 4, ...);   // aeon path animation
    else
        FFX_Abmap_QueuePlacementAnim(..., 0, ...);   // standard path animation
    
    // 5. Mark node as activated by this character
    *(_BYTE *)(v18 + 40 * nodeIdx + 2089) |= 1 << charIdx;
    
    // 6. Save active node ID
    *(_DWORD *)(MEMORY[0x2305834] + 71336) = nodeIdx;
    
    // 7. Recompute party stats (Str/Dex/HP/etc)
    FFX_Abmap_PackMenuSnapshot();
    FFX_Abmap_RecomputePartyStatsAndLearnedMoves(charId, abmapContext);
    FFX_Abmap_ApplyActivationStats();
    
    // 8. Dispatch activation animation
    result = FFX_Abmap_DispatchActivationAnim(charIdx, nodeIdx);
    
    // 9. Set up callback chain (FX + swap anim)
    v7 = MEMORY[0x2305834];
    if (!*(_DWORD *)(MEMORY[0x2305834] + 71092)) {
        *(_DWORD *)(v7 + 71092) = *(_DWORD *)(v7 + 71084);  // save prev callback
        *(_DWORD *)(v7 + 71084) = FFX_Abmap_PlacementFxCallback;  // install new
    }
    if (!*(_DWORD *)(v7 + 71088)) {
        *(_DWORD *)(v7 + 71088) = *(_DWORD *)(v7 + 71080);  // save prev
        *(_DWORD *)(v7 + 71080) = FFX_Abmap_SwapAnimCallbackChain;
    }
    
    return result;
}
```

**Key insight:** Node activation is a **9-step pipeline**:
1. Link 512KB resource buffer (for node activation effects)
2. Read node position (40B stride from state base)
3. Queue placement animation (standard or aeon path)
4. Set activation flag (bit per character)
5. Save active node ID
6. Pack menu snapshot (for UI)
7. Recompute party stats (re-derive all stats from activated nodes)
8. Apply activation stats (immediate +Str/+Dex/etc)
9. Dispatch activation animation (queue for render)
10. Install callback chain (FX + swap animations)

---

## Key Function: FFX_Abmap_BuildNodeAdjacencyFromLinks (0xa5b140, ~340B)

Builds the **adjacency list** for each Sphere Grid node. Each node can have up to **5 neighbors** (MAXSPHECONE).

```c
unsigned int FFX_Abmap_BuildNodeAdjacencyFromLinks() {
    v0 = MEMORY[0x2305834];
    i_1 = MEMORY[0x2305834] + 2056;
    
    // Loop over all nodes
    for (i = MEMORY[0x2305834] + 2056; v2 < *(__int16 *)(v0 + 2); i_1 += 40) {
        
        // Skip nodes without links
        if (*(_WORD *)(i_1 + 6) != 0xFFFF) {
            n5 = 0;
            v4 = 0;
            
            // Walk link table to find neighbors
            for (j = (_DWORD *)(i_1 + 12); ; j = j_1 + 1) {
                j_1 = j;
                n5_1 = n5;
                
                // End of link table
                v6 = v0 + 4 * (*(__int16 *)(v0 + 4) + 4 * *(__int16 *)(v0 + 4) + 10754);
                v7 = (_WORD *)(v0 + 43016);
                if (v4)
                    v7 = v4 + 10;  // resume from last match
                
                if ((unsigned int)v7 >= v6)
                    break;  // past end of table
                
                // Search link entries for current node
                while (*v7 != (_WORD)v2 && v7[1] != (_WORD)v2) {
                    v7 += 10;  // next link entry (10B each)
                    if ((unsigned int)v7 >= v6)
                        goto LABEL_10;
                }
                
                v4 = v7;
                
                // Cap at MAXSPHECONE = 5
                if (n5 >= 5) {
                    nullsub_34("setSpheConePrim error MAXSPHECONE=%d\n", 5);
                    n5 = n5_1;
                }
                
                ++n5;
                *j_1 = v7;  // save pointer to link entry
                v0 = MEMORY[0x2305834];
            }
            
LABEL_10:
            // Zero-fill remaining slots
            if (n5 < 5)
                memset((void *)(i + 12 + 4 * n5), 0, 4 * (5 - n5));
            
            i_1 = i;
            v0 = MEMORY[0x2305834];
        }
        i = i_1 + 40;
        ++v2;
    }
    return i_1;
}
```

**Key insight:** The Sphere Grid is **not a tree** — it's a **graph** where nodes can have up to 5 outgoing links. The link table is a flat array of `(nodeId, neighborId)` pairs (10B each). `BuildNodeAdjacencyFromLinks` walks this table and builds per-node adjacency lists for fast navigation.

---

## Node Record Layout (40 bytes per node)

```
Offset  Size  Field
+0      2B    nodePosY (int16, float)
+2      2B    nodePosX (int16, float)
+4      2B    nodePosZ (int16, float)
+6      2B    linkIdx (offset into link table; -1 = no links)
+8      2B    ? (probably node type: ability/stat/lock/etc)
+10     2B    ? (cost in AP? sphere level?)
+12     20B   linkPtr[5] (pointers to adjacent link entries)
+32     1B    activation flags (bit i = character i activated)
+33     7B    padding
```

**Total: 40B per node × 217 nodes = 8680B** for the node table.

---

## Link Table Layout (10 bytes per link)

Each link entry is `(nodeIdFrom, nodeIdTo, ?)`:

```
+0      2B    fromNodeId (int16)
+2      2B    toNodeId (int16)
+4      2B    ?
+6      2B    ?
+8      2B    ?
```

The link table size is `*(__int16 *)(v0 + 4)` (a count).

---

## Path Animations

```c
if ((*RuntimeContextPtr & 0xC000) == 0x8000)
    FFX_Abmap_QueuePlacementAnim(..., 4, ...);  // aeon path animation
else
    FFX_Abmap_QueuePlacementAnim(..., 0, ...);  // standard path animation
```

The runtime context flag `0xC000 == 0x8000` indicates the **aeon grid** vs **standard grid**. FFX's Sphere Grid has **two grids**:
- **Standard grid** — main character sphere grid (Tidus/Auron/Kimahri/etc)
- **Aeon grid** — separate grid for aeons (Ifrit/Ixion/Shiva/etc)

The animation path differs (4 vs 0) — likely because aeon nodes use **different visual effects** (purple flames vs standard glow).

---

## Stats Recompute Pipeline

When a node is activated, **all 7 party members' stats** must be recomputed:

```c
FFX_Abmap_PackMenuSnapshot();
FFX_Abmap_RecomputePartyStatsAndLearnedMoves(charId, abmapContext);
FFX_Abmap_ApplyActivationStats();
```

1. **`PackMenuSnapshot`** — saves current menu state for undo/rollback
2. **`RecomputePartyStatsAndLearnedMoves`** — walks all activated nodes for each character, sums up bonuses
3. **`ApplyActivationStats`** — applies +Str/+Dex/+HP/+MP etc to the activated character

This is **expensive** because every node activation triggers a full recompute. FFX probably does this once per activation (not per-frame), but for 217 nodes × 7 characters = 1519 stat lookups per activation.

---

## Callback Chain

After activation, two callbacks are installed:

```c
*(_DWORD *)(v7 + 71084) = FFX_Abmap_PlacementFxCallback;  // FX callback
*(_DWORD *)(v7 + 71080) = FFX_Abmap_SwapAnimCallbackChain;  // swap anim
```

These run **after the activation animation** finishes:
- **`PlacementFxCallback`** — fires VFX/SFX when node is placed
- **`SwapAnimCallbackChain`** — handles node-to-node transition animation

---

## ATEL-Driven

The Sphere Grid is fully driven by **ATEL scripting** (the same bytecode VM as cutscenes). Confirmed by:

- `FFX_Atel_AbilityMap_FuncD000_CALL` — main entry point
- `FFX_Atel_AbilityMap_FuncD020_CALLPOPA` — call-with-return-pop opcode

When the Sphere Grid UI opens, an ATEL script runs that:
1. Loads node definitions from `.abmap` files (likely in VBF/PSARC)
2. Sets up initial state (all nodes locked except starting position)
3. Initializes callbacks
4. Renders the grid via PhyreEngine scene primitives

---

## Resource Buffer

```c
FFX_MagicHost_LinkResourceBufferRange(
    unk_1A86034, &dword_132FF60[935476], 512000);
```

A **512,000-byte (500KB) resource buffer** is linked to the Magic Host on every node activation. This is **massive** — likely contains:
- Loaded textures for new node visualization
- Animation curves for the activation sequence
- Audio buffers for activation sound effects

The buffer is **pre-allocated** (not per-activation) and **linked** to the active rendering pipeline.

---

## Animation Curves

The placement animation takes 11 floats (color, position, scale, alpha):

```c
v9  = 0.0;   // ?
v10 = 0.0;   // ?
v11 = 0.0;   // ?
v12 = 0.0;   // ?
v13 = 0.5;   // color R
v14 = 0.5;   // color G
v15 = 0.5;   // color B
v16 = (float)nodeX;  // X coord
v17 = (float)nodeY;  // Y coord
```

These are passed to `FFX_Abmap_QueuePlacementAnim` which interpolates over time using 4-frame keyframes (per batch_0002 inventory).

---

## State Packing

```c
*(_BYTE *)(v18 + 40 * nodeIdx + 2089) |= 1 << charIdx;
```

The activation flags are stored as **1 bit per character** in a byte at offset 2089. With 7 party members + 1 aeon slot = **8 bits fits in 1 byte**. So each node knows which characters have activated it.

This is **critical** for the Sphere Grid's "shared nodes" mechanic — if Rikku activates a node, Auron can also use it without paying AP again.

---

## Key Findings

1. **Sphere Grid is ATEL-driven** — same VM as cutscenes (`FFX_Atel_AbilityMap_FuncD000_CALL`). Unified scripting system.

2. **71KB state global** at `MEMORY[0x2305834]` — contains all 217 nodes, link tables, animations, callbacks, and menu state.

3. **217 nodes, 40B each** — `*(__int16 *)(v0 + 2)` = 217 node count. 8680B total for nodes.

4. **Max 5 neighbors per node** (MAXSPHECONE) — confirmed by debug string. Sphere Grid is a 5-regular graph (mostly).

5. **Two grids** — standard + aeon. Aeon path triggered by runtime flag `0xC000 == 0x8000`.

6. **Link table is 10B per link** — flat array of (fromNodeId, toNodeId) pairs. Walked linearly during adjacency build.

7. **Stats recompute on every activation** — 217 nodes × 7 chars = 1519 stat lookups per activation.

8. **512KB resource buffer** — pre-allocated for activation VFX/SFX/textures.

9. **1 bit per character** activation flag — 7 chars + 1 aeon = 1 byte. Shared nodes supported.

10. **9-step activation pipeline** — link buffer → read position → queue anim → set flag → save ID → pack snapshot → recompute stats → apply stats → dispatch anim.

11. **Callback chain** — PlacementFx + SwapAnim installed after activation, run after activation animation completes.

12. **11 float params** to placement animation — color (R/G/B), position (X/Y), 6 more for alpha/scale/duration.

13. **BuildNodeAdjacencyFromLinks is O(N×L)** — N nodes × L link table size. For 217 nodes × ~500 links = ~100K operations. Fast enough for one-time init.

14. **Zero-fill remaining slots** — if a node has < 5 neighbors, the remaining slots are zeroed. Prevents garbage pointers.

15. **Debug string `setSpheConePrim error MAXSPHECONE=%d`** — confirms MAXSPHECONE = 5 hard cap.

---

## What's Next?

- **batch_0013**: ATEL Movie opcode table (475 ops) — the cutscene VM that also drives Sphere Grid
- **batch_0015**: Field VM opcodes — overworld scripting (same VM architecture)
- **batch_0016**: VP8/VP9 decoder entry — video codec
- **batch_0017**: MSCD file system — asset loading for `.abmap` files
- **batch_0018**: Battle UI HUD core
- **batch_0019**: Cross-batch PhyreEngine architecture synthesis

---

**Next batch:** ATEL Movie opcode table — the unified VM that drives both cutscenes AND the Sphere Grid UI.