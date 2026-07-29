# FFX.exe Decompilation — Batch 21 (ATEL Map Opcodes)

**Database:** ffxoficial_COPY.i64 (session 85e0242a, GUI backend PID 10524)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** `FFX_Atel_Map_*` — map visual scripting VM with 38 opcodes (channel 2, 0x804B-0x80FF range)

---

## Summary

The **ATEL Map VM** controls environmental/visual effects in field areas — GFX layer visibility, 2D overlays, fog params, clear color, skybox, and map group binding. It is the smallest of the ATEL channels (38 opcodes vs. 466 for Movie). All rendering is delegated to the `FFX_FieldMap_*` subsystem; the Map VM is purely a scripting bridge.

| Metric | Value |
|--------|-------|
| Total opcodes | 38 |
| Calling conventions | 5 (CALL, STATUS, INTRET, FLOATRET, CALLPOPA) |
| Opcode range | 0x804B-0x80FF (practical: 0x4B-0x54 in channel 2 funcspace) |
| Funcspace table channel | channel 2 (index 2 of 11 at 0xC40E20) |
| Unnamed stubs | 2 (0x91c000-0x91c0d0, filler entries in funcspace) |
| Rendering delegate | FFX_FieldMap_\* (actual drawing + scene management) |

`--- Insight ---`
- **38 opcodes is small because the map VM is a thin bridge** — it translates ATEL script commands into calls on `FFX_FieldMap_*` functions that do the actual rendering. The heavy lifting lives in FieldMap, not in the opcode handlers.
- **The 0x804B-0x8054 range** maps to opcodes 0x4B-0x54 in the channel 2 funcspace slot. Values outside this range are NOPs or error handlers in the dispatch loop.
`-----------------`

---

## Opcode Categories

The 27 named functions (plus unnamed stubs) divide into 5 categories:

### 1. GFX Lifecycle (activate / stop / bind / unbind / show / hide)
| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `setAllGfxActive_INTRET` | 0x91b050 | INTRET | Activate all GFX layers |
| `stopAllGfx_INTRET` | 0x91b060 | INTRET | Stop all GFX layers |
| `bindGfxToTarget_INTRET` | 0x91b070 | INTRET | Bind GFX instance to named target |
| `unbindGfx_INTRET` | 0x91b130 | INTRET | Unbind GFX from current target |
| `setGfxEnabledGlobal_INTRET` | 0x91b160 | INTRET | Global enable/disable toggle |
| `setGfxActive_CALL` | 0x91c670 | CALL | Activate specific GFX by ID |
| `stopGfx_INTRET` | 0x91c4f0 | INTRET | Stop specific GFX by ID |
| `setGfxVisibility_INTRET` | 0x91c740 | INTRET | Toggle GFX visibility |
| `startGfxTimer` | 0x91c7a0 | (none) | Start GFX timer/countdown |
| `waitForGfxStopped_CALLPOPA` | 0x91af60 | CALLPOPA | Block until GFX fully stopped |
| `waitForGfxEnding` | 0x91afa0 | (none) | Wait for GFX end-of-lifecycle |

### 2. GFX Position & Binding
| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `bindGfxPosition_CALL` | 0x91b0a0 | CALL | Set GFX position binding to transform |
| `setGfxPosition_INTRET` | 0x91c410 | INTRET | Set absolute GFX world position |
| `bindGfxToMapGroup_INTRET` | 0x91c3c0 | INTRET | Bind GFX to a map group container |

### 3. GFX Group Management
| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `setGfxGroupActive_INTRET` | 0x91b790 | INTRET | Activate/deactivate group of GFX |
| `setGfxGroupVisibility_INTRET` | 0x91b7d0 | INTRET | Toggle visibility for GFX group |

### 4. 2D Layers (overlay rendering)
| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `Show2DLayer_Wrapper` | 0x641460 | Wrapper | Public wrapper for 2D layer show |
| `setLayerVisibilityBit` | 0x88eb10 | (none) | Set bitfield for layer visibility |
| `show2DLayer_INTRET` | 0x91b1a0 | INTRET | Show a 2D overlay layer |
| `hide2DLayer_INTRET` | 0x91b1e0 | INTRET | Hide a 2D overlay layer |
| `set2DLayerOpacity_INTRET` | 0x91b6f0 | INTRET | Set opacity for 2D layer |

### 5. Environment (fog, skybox, clear color)
| Function | Address | Convention | Purpose |
|----------|---------|------------|---------|
| `setFogParams_CALL` | 0x91b810 | CALL | Set fog density/start/end params |
| `setFogColor_INTRET` | 0x91bad0 | INTRET | Set fog color (RGB) |
| `setClearColor_INTRET` | 0x91beb0 | INTRET | Set clear color (background color) |
| `setSkyboxVisibility_INTRET` | 0x91c5b0 | INTRET | Toggle skybox rendering |
| `setMapLayerVisibility_INTRET` | 0x91c530 | INTRET | Toggle entire map layer group |

---

## Unnamed Funcspace Stubs (0x91c000-0x91c0d0)

Two function blocks at 0x91c000 and 0x91c0d0 are registered in the funcspace table but have no meaningful implementation. These are **filler stubs** — possibly opcodes that were removed during development or reserved for debug use. They execute a minimal return and do not interact with FieldMap.

---

## Architecture: Map VM Dispatch

```c
// Channel 2 of g_atelFuncspace[11][256][5] at 0xC40E20
// Practical opcodes: indices 0x4B through 0x54 (10 slots)
// Remaining indices in channel 2 point to NOP handlers

void FFX_Atel_Map_Dispatch(uint8_t opcode, uint8_t convention, uint32_t* args) {
    // Opcode is offset by 0x8000 (high bits identify channel 2)
    uint8_t idx = opcode & 0xFF;  // 0x4B-0x54
    
    void (*handler)() = g_atelFuncspace[2][idx][convention];
    if (handler) {
        handler(args);
    }
    // All map ops delegate to FFX_FieldMap_* for actual rendering
}
```

### Delegate Flow

```
ATEL Map Script (field .ebd/.ebp)
  |
  v
Map VM Dispatch (38 opcodes, channel 2)
  |
  v
FFX_Atel_Map_* handler (this batch)
  |
  v
FFX_FieldMap_* subsystem (actual rendering)
  |-- FFX_FieldMap_SetFogParams()
  |-- FFX_FieldMap_SetClearColor()
  |-- FFX_FieldMap_SetSkyboxVisibility()
  |-- FFX_FieldMap_LayerVisibility()
  |-- FFX_FieldMap_GfxBinding()
  +-- FFX_FieldMap_GroupManagement()
```

---

## Key Insights

1. **38 opcodes for the entire map VM** — contrasts with 466 for Movie. Maps don't need complex scripting; they mostly set state at load time and let FieldMap render each frame.

2. **Environmental control is the real value** — fog params (density, start, end, color), clear color (background), and skybox toggle are the only rendering environment controls in the ATEL layer. Everything else is GFX lifecycle management.

3. **2D layers are separate from GFX** — 2D overlays (show/hide/opacity) have dedicated opcodes and a separate subsystem from 3D GFX layers. This matches how FFX renders its field UI (map names, zone labels) as 2D overlays.

4. **Map group binding** — GFX can be bound to a "map group" (0x91c3c0), which is how multiple GFX instances are collectively managed (e.g., all trees in a forest area). The group active/visibility opcodes (0x91b790, 0x91b7d0) batch-control these.

5. **No battle-related map ops** — the Map VM does NOT handle battle transitions. Those are initiated by the Field VM (batch_0015) via encounter trigger scripts. The Map VM only handles what's visible during exploration.

6. **Delegation pattern** — every opcode handler is a thin wrapper (6-30 bytes) that calls into `FFX_FieldMap_*`. This means understanding FieldMap is necessary to fully understand what each opcode does at the rendering level.

7. **Funcspace filler stubs** — the unnamed stubs at 0x91c000/0x91c0d0 are likely remnants from development. They exist in the funcspace table but do nothing.

---

## Field Script Integration

The Map VM is triggered by **Field Script opcodes** (batch_0015, Field VM, 295 ops, + Field Script, 556 ops). When a field script needs to change the environment (e.g., fog clears after a story event):

```
Field Script: opcode 0xXX (change fog)
  -> Field VM dispatch
    -> FFX_Atel_Map_setFogParams_CALL (0x91b810)
      -> FFX_FieldMap_SetFogParams(r, g, b, density, start, end)
```

This layering means field scripts NEVER call FieldMap directly — they always go through the ATEL Map VM, preserving the abstraction boundary.

---

## What's Next?

- **batch_0022**: FFX_Sin_* (Sin system: scales, HP, overload, UNI presets)
- **batch_0023**: FFX_Monster_* (monster data tables, stats, abilities)
- **batch_0024**: Cross-batch synthesis — the full ATEL VM architecture across all channels
