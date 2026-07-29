# FFX.exe Decompilation — Batch 4 (CTB Turn Scheduling)

**Database:** ffxoficial_COPY.i64 (session b1d18aaa, GUI backend PID 10524)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** Conditional Turn Battle (CTB) — priority queue, actor selection, overdrive edge events

---

## Summary

FFX uses a **Conditional Turn Battle (CTB)** system where actors are scheduled by a priority queue sorted by wait time. This batch documents the 3 core CTB functions plus 5 supporting functions they call, totaling **1,027 bytes** of decompiled code.

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_Battle_CtbQueuePushActor` | 0x78d580 | 32B | Push actor index into CTB queue |
| `FFX_Battle_CtbSelectNextActorAndRunTurnEdgeEvents` | 0x791000 | 446B | Main CTB scheduler — selects next actor, runs edge events |
| `FFX_Battle_CtbEdgeOverdriveEvent` | 0x7b13d0 | 372B | Overdrive charge edge event handler |
| `FFX_Battle_SortCtbPriorityQueue` | 0x78d4a0 | ~200B | Selection sort by CTB priority value |
| `FFX_Battle_ComputeCtbPriorityValue` | 0x78f050 | ~60B | Compute priority (lower = sooner) |
| `FFX_Battle_AccessCurrentActorData` | 0x794030 | ~70B | Actor record accessor (3-tier dispatch) |
| `FFX_Battle_AddActionRingEntrySimple` | 0x7b2440 | ~110B | Action ring buffer append |
| `FFX_Battle_UnlockOverdriveSlot` | 0x7b10d0 | ~190B | Overdrive slot unlock with bitmask |
| `FFX_Battle_OverdriveAddClamp` | 0x7b15a0 | ~380B | Overdrive charge with multipliers |
| `FFX_Battle_ComputeOverdriveLevel` | 0x78bfc0 | ~50B | Overdrive level (0-3) from charge ratio |

`★ Insight ─────────────────────────────────────`
- **CTB = priority queue by wait time**, not by speed stat directly. Lower priority value = sooner turn. Aeon menu slots get +0x10000 priority (always last).
- **3-tier actor dispatch**: actors 0-30 use 3984-byte records, actors 31-92 use 912-byte records (aeons/enemies), actors ≥93 fall back to a singleton slot. This matches FFX's battle layout: 7 player chars + 8 enemies + summons.
- **Edge events fire on turn boundaries**: overdrive charge, status tick decrements, and CTB counter increments all happen in `CtbSelectNextActorAndRunTurnEdgeEvents` — single function is the turn state machine.
`─────────────────────────────────────────────────`

---

## Architecture

### CTB Queue Layout

The CTB queue is a **byte array** at `byte_11333C4` (global), with:
- `PRIORITY_OVERDRIVE_PRIORITY_STOP_0x18` (0x11333C0) = current queue length (uint32)
- `byte_11333C4[0..N]` = actor indices (uint8 each, max 31)

```c
// Global CTB queue state
struct FFX_CtbQueue {
    uint32_t count;          // 0x11333C0 — current queue length
    uint8_t  actors[31];    // 0x11333C4 — actor indices in queue
};
```

### Actor Record (3 tiers)

`FFX_Battle_AccessCurrentActorData` returns one of 3 record pools based on actor index:

```c
FFXBattleActorRecord* FFX_Battle_AccessCurrentActorData(uint8 actorIdx) {
    if (actorIdx < 0x1F)        // 0-30: player party + regular enemies
        return g_actorPoolBase + 3984 * actorIdx;   // 3984-byte records
    if (actorIdx >= 0x5D)       // 93+: special singleton (summons?)
        return &byte_11333C4[268];
    // 31-92: aeons + special enemies
    return g_aeonPoolBase + 912 * (actorIdx - 31);   // 912-byte records
}
```

**Key insight:** Player/enemy actors have **3984-byte records** (rich status, equipment, abilities), while aeons have **912-byte records** (simpler — no equipment slots). The 0x5D+ singleton is likely the "no actor" sentinel.

### CTB Priority Value

```c
int FFX_Battle_ComputeCtbPriorityValue(uint8 actorIdx, void* actorData) {
    if (FFX_Btl_UI_IsAeonMenuSlot(actorIdx, actorData))
        return basePriority + 0x10000;  // Aeon menu slots always go last
    else
        return basePriority + ((255 - actor->pad_0764[334]) << 8);
    // pad_0764[334] = "speed" or "readiness" byte (0-255)
    // Higher readiness → lower priority value → sooner turn
}
```

**Priority encoding:**
- Bits 0-7: base priority (turn counter)
- Bits 8-15: `255 - readiness` (lower readiness = later turn)
- Bit 16+: aeon menu flag (always last)

### Selection Sort

`FFX_Battle_SortCtbPriorityQueue` is a **selection sort** (O(n²)) over the queue. For 31 actors max, this is fine — n² = 961 comparisons per sort, negligible vs. battle logic cost.

```c
void FFX_Battle_SortCtbPriorityQueue(...) {
    for (i = 0; i < count - 1; ++i) {
        min_idx = i;
        min_val = ComputeCtbPriorityValue(queue[i]);
        for (j = i + 1; j < count; ++j) {
            v = ComputeCtbPriorityValue(queue[j]);
            if (v < min_val) { min_idx = j; min_val = v; }
        }
        if (min_idx != i) swap(queue[i], queue[min_idx]);
    }
}
```

---

## Key Function Analysis

### 1. FFX_Battle_CtbSelectNextActorAndRunTurnEdgeEvents (0x791000, 446B)

This is the **CTB turn state machine**. Called every battle tick to:
1. Check battle end conditions (`unk_112A8E1[0]` or `MEMORY[0x112BDE0][0]`)
2. Clear CTB queue count
3. Iterate 31 actor slots, push eligible actors into queue
4. Sort queue by priority
5. Either advance turn counter (`a1 <= 0`) or add action ring entry (`a1 > 0`)

```c
int FFX_Battle_CtbSelectNextActorAndRunTurnEdgeEvents(int a1) {
    // Battle end check
    if (unk_112A8E1[0] || MEMORY[0x112BDE0][0])
        return 0;
    
    FFX_Battle_ClearCtbQueueCount();
    
    // Phase 1: Build CTB queue — iterate 31 actor slots
    for (i = 0; i < 31; ++i) {
        actor = FFX_Battle_AccessCurrentActorData(i);
        // Eligibility filter:
        //   !actor[1].pad_0450[18]   — not already in queue
        //   actor[1].pad_0443[1]     — is alive/present
        //   !actor[1].byte448        — not status-blocked
        //   (actor->pad_0764[424] & 4) == 0  — not "skip turn" flag
        //   !actor->pad_0764[510]    — not "delayed" flag
        //   actor[1].pad_0450[2]     — has actions available
        if (eligible(actor)) {
            // Magic ID check — certain magics force -1 (skip turn)
            if (FFX_Magic_GetCurrentMagicId() == 429
                || battleState[2806] in {12588, 16677, 12322, 12552, 16444, 24765}
                && battleState[3055] > 0)
                return -1;
            FFX_Battle_CtbQueuePushActor(actor, ctx);
        }
    }
    
    // Phase 2: Sort by CTB priority
    FFX_Battle_SortCtbPriorityQueue(ctx, queue);
    
    // Phase 3: Either advance turn or add action
    if (a1 <= 0) {
        // Turn advance branch
        if (++battleState[0] >= battleState[1]) {
            battleState[0] = 0;
            // Tick all actors: decrement wait counters, status durations
            for (j = 0; j < 31; ++j) {
                actor = FFX_Battle_AccessCurrentActorData(j);
                if (eligible_for_tick(actor)) {
                    // pad_0764[628] = status countdown (Haste/Slow/etc)
                    if (actor->pad_0764[628] != -1)
                        actor->pad_0764[628] += 1;
                    // pad_0764[510] = CTB wait counter
                    newWait = actor->pad_0764[510] - 1;
                    if (newWait > 0) {
                        if (unk_112A8FB) newWait = 1;  // force wait = 1
                    } else {
                        newWait = 0;
                        actor->pad_0450[20] = 3;  // mark "ready"
                        if (!actor->pad_0450[2])
                            newWait = actor->pad_0764[511];  // reset to base
                    }
                    actor->pad_0764[510] = newWait;
                }
            }
        }
    } else {
        // Action branch — add to action ring buffer
        if (FFX_Battle_AddActionRingEntrySimple(*v7, 0, 1, 0)) {
            FFX_Battle_AccessCurrentActorData(ctx);
            FFX_Battle_CtbEdgeOverdriveEvent(eventType, ctx);
            return -1;
        }
    }
    return -1;
}
```

**Magic IDs that force skip-turn:**
- 429 (0x1AD) — likely "Defend" or "Reflex"
- 12588, 16677, 12322, 12552, 16444, 24765 — special action IDs that block CTB advance

**Turn counter:**
- `battleState[0]` (0x112BDE2) = current tick
- `battleState[1]` (0x112BDE3) = ticks per turn (when reached, advance turn)

### 2. FFX_Battle_CtbEdgeOverdriveEvent (0x7b13d0, 372B)

Fires when an actor's turn starts. Handles **overdrive charge events** for the actor and bystanders.

```c
void FFX_Battle_CtbEdgeOverdriveEvent(uint32_t amount, void* ctx) {
    if (amount > 6) return;  // Only 7 overdrive types (0-6)
    
    // Slot 0xD: Self overdrive charge
    FFX_Battle_UnlockOverdriveSlot(amount, 0xD, 0);
    if (slotState[1467] == 13)
        FFX_Battle_OverdriveAddClamp(odType, actor, amount);
    
    // Slot 0xF: If overdrive level >= 1, unlock stronger slot
    if (FFX_Battle_ComputeOverdriveLevel(odType, actor) >= 1) {
        FFX_Battle_UnlockOverdriveSlot(amount, 0xF, 0);
        if (slotState[1467] == 15)
            FFX_Battle_OverdriveAddClamp(odType, actor, amount);
    }
    
    // Count alive actors (excluding self) without overdrive ready
    amounta = 0;
    for (i = 0; i < 18; ++i) {
        if (i != amount) {
            actor = FFX_Battle_AccessCurrentActorData(i);
            if (alive_and_has_actions(actor) && actor->byte44A == 0)
                ++amounta;
        }
    }
    
    // Slot 0x10: If no other actor ready, unlock "last stand" slot
    if (!amounta) {
        FFX_Battle_UnlockOverdriveSlot(amount, 0x10, 0);
        if (slotState[1467] == 16)
            FFX_Battle_OverdriveAddClamp(odType, actor, amount);
    }
    
    // Slot 0xE: Status-triggered overdrive (Haste/Slow/etc)
    if ((slotState[1542] & 0xA) || (slotState[1542] & 0x100)
        || slotState[1544] || slotState[1545] || slotState[1546]
        || slotState[1556] || (slotState[1558] & 0x4000)) {
        FFX_Battle_UnlockOverdriveSlot(amount, 0xE, 0);
        if (slotState[1467] == 14)
            FFX_Battle_OverdriveAddClamp(odType, actor, amount);
    }
}
```

**Overdrive slot IDs (0xD-0x10):**
- 0xD (13): Self charge — basic overdrive gain
- 0xE (14): Status-triggered — Haste/Slow/Sensor/etc
- 0xF (15): High-level charge — only if level >= 1
- 0x10 (16): Last stand — only if no other actor ready

### 3. FFX_Battle_UnlockOverdriveSlot (0x7b10d0, ~190B)

Bitmask-based slot unlock. Each actor has a 32-bit mask at `pad_0764[658]` tracking which slots are unlocked.

```c
int FFX_Battle_UnlockOverdriveSlot(uint32_t actorIdx, uint32_t slotIdx, int force) {
    if (byte_112BDE2[3075] || actorIdx > 6 || slotIdx > 0x10)
        return 0;
    
    actor = FFX_Battle_AccessCurrentActorData(ctx);
    if (!actor->byte448 && !actor->byte44A || force) {
        mask = actor->pad_0764[658];
        if ((mask & (1 << slotIdx)) == 0) {  // not yet unlocked
            slotPtr = &byte_112BDE2[148 * actorIdx + 25210];
            if (slotPtr[2 * slotIdx + 96] != 0xFFFF) {  // not maxed
                actor->pad_0764[658] = mask | (1 << slotIdx);  // set bit
                usesLeft = slotPtr[2 * slotIdx + 96];
                triggerMask = slotPtr[34];  // dword at offset 136
                if (usesLeft) slotPtr[2 * slotIdx + 96] = usesLeft - 1;
                if (!slotPtr[2 * slotIdx + 96] && !((triggerMask >> slotIdx) & 1)) {
                    byte_112BDE2[585] = 1;  // global "overdrive ready" flag
                    return 1;
                }
            }
        }
    }
    return 0;
}
```

**Key insight:** Each actor has **17 overdrive slots** (0x0-0x10), each with a 16-bit "uses remaining" counter. When uses hit 0 AND the trigger bit isn't set, the global overdrive-ready flag (`byte_112BDE2[585]`) is set — this is what makes the Overdrive command flash in the UI.

### 4. FFX_Battle_OverdriveAddClamp (0x7b15a0, ~380B)

The most complex overdrive function — applies **multipliers** to overdrive charge gain based on:
- Status flags (bits 0/1/2 of `slotState[1726]`)
- Overdrive level (multiplier if level >= 1)
- Battle flags (bits 0x20, 0x40 of `slotState[1600]`)
- Sphere grid modifiers (bits 0x40, 0x80 of `slotState[1558]`)
- Special "decay" mode (bit 3 of `slotState[1726]`)

```c
void FFX_Battle_OverdriveAddClamp(odType, actor, amount) {
    if (unk_112A916 || (slotState[1558] & 0x400) || slotState[3532] || slotState[3534])
        return;  // overdrive disabled
    
    flags = slotState[1726];
    if (flags & 2)       charge = 3 * baseCharge;       // Stoic mode
    else if (flags & 1) charge = 2 * baseCharge;       // Aggressive mode
    else if (flags & 4 && ComputeOverdriveLevel() >= 1)
        charge = 2 * baseCharge;                        // High-level bonus
    else charge = baseCharge;
    
    battleFlags = slotState[1600];
    if (battleFlags & 0x20) charge = 3 * charge / 2;   // Tidal bonus
    if (battleFlags & 0x40) charge *= 2;               // Moon bonus
    
    level = slotState[1558];
    v7 = (level & 0x40) ? 0 : charge;                  // Warrior mode
    if (level & 0x80) v7 *= 2;                          // Slayer mode
    
    if (flags & 8) {  // Decay mode
        // Sphere grid integration — overdrive charge affects AP gain
        req = FFX_SphereGrid_ComputeNextLevelApRequirement(level, charge);
        FFX_Battle_ComputeOverdriveCharge(
            maxOd, v7 * req % maxOd, amount);
        v7 = 0;
        slotState[1804] *= 0.9;  // 90% decay per turn
    }
    
    // Clamp to max
    newOd = FFX_Math_ClampInt(currentOd + v7, 0, maxOd);
    slotState[1468] = newOd;
    
    if (newOd > currentOd && newOd == maxOd)
        FFX_Battle_AddOverdriveChargeBySource(maxOd, actor, amount);
}
```

**Overdrive modes (from flags):**
- Bit 0 (0x1): Aggressive — 2x charge
- Bit 1 (0x2): Stoic — 3x charge
- Bit 2 (0x4): High-level bonus — 2x if level >= 1
- Bit 3 (0x8): Decay — charge decays by 10% per turn, integrates with sphere grid

### 5. FFX_Battle_ComputeOverdriveLevel (0x78bfc0, ~50B)

Returns overdrive level (0-3) from charge ratio:

```c
int FFX_Battle_ComputeOverdriveLevel(odType, actor) {
    if (currentCharge <= 0) return 3;  // empty = level 3 (defensive?)
    ratio = 4 * currentCharge / maxCharge;
    if (ratio < 1) return 2;           // low = level 2
    return (ratio < 2) ? 1 : 0;       // mid = 1, high = 0
}
```

**Note:** The level numbering is **inverted** — level 0 = full charge, level 3 = empty. This is likely a UI display convention.

### 6. FFX_Battle_AddActionRingEntrySimple (0x7b2440, ~110B)

Action ring buffer at `byte_112AA81`. Each entry is 8 bytes, max 62 entries.

```c
int FFX_Battle_AddActionRingEntrySimple(uint8_t a1, char a2, char a3, char a4) {
    idx = byte_112AA81[4959];  // current count
    if (idx >= 62) return 0;   // ring full
    
    actor = FFX_Battle_AccessCurrentActorData(ctx);
    ++actor->pad_0450[18];     // increment pending action count
    
    byte_112AA81[8 * idx + 0] = a4;     // param 4
    byte_112AA81[8 * idx + 1] = a3;     // param 3
    MEMORY[0x112AA80][8 * idx] = a1;    // action ID
    byte_112AA81[8 * idx + 3] = a2;     // param 2
    byte_112AA81[8 * idx + 2] = 0;      // reserved
    byte_112AA81[4959] = idx + 1;       // advance count
    return -1;  // success
}
```

**Ring entry layout (8 bytes):**
- +0: action ID
- +1: reserved (0)
- +2: param 2
- +3: param 3
- +4: param 4
- +5-7: padding/alignment

---

## CTB Turn Flow

```
Battle tick
    ↓
CtbSelectNextActorAndRunTurnEdgeEvents(a1)
    ↓
    ├── Check battle end → return 0 if ended
    ├── ClearCtbQueueCount
    ├── For i in 0..30:
    │     ├── AccessCurrentActorData(i)
    │     ├── Check eligibility (alive, not blocked, has actions)
    │     ├── Check magic ID exceptions → return -1
    │     └── CtbQueuePushActor(i)
    ├── SortCtbPriorityQueue (selection sort by ComputeCtbPriorityValue)
    ↓
    ├── If a1 <= 0 (turn advance):
    │     ├── Increment turn counter
    │     ├── If counter >= threshold:
    │     │     ├── Reset counter
    │     │     └── For j in 0..30:
    │     │           ├── Decrement wait counter (pad_0764[510])
    │     │           ├── Increment status countdown (pad_0764[628])
    │     │           └── If wait == 0: mark "ready" (pad_0450[20] = 3)
    │     └── return -1
    ↓
    └── If a1 > 0 (action):
          ├── AddActionRingEntrySimple
          ├── AccessCurrentActorData
          ├── CtbEdgeOverdriveEvent
          │     ├── UnlockOverdriveSlot(0xD) — self charge
          │     ├── If level >= 1: UnlockOverdriveSlot(0xF)
          │     ├── Count ready actors; if 0: UnlockOverdriveSlot(0x10)
          │     └── If status flags: UnlockOverdriveSlot(0xE)
          └── return -1
```

---

## Key Findings

1. **CTB is a priority queue, not a speed stat** — actors are sorted by `ComputeCtbPriorityValue` which encodes base priority + readiness + aeon flag. Lower value = sooner turn.

2. **3-tier actor dispatch** — actors 0-30 (player/enemy) have 3984-byte records, actors 31-92 (aeons) have 912-byte records, actors 93+ use a singleton. This matches FFX's battle design where aeons have simpler state (no equipment).

3. **Edge events fire on turn boundaries** — `CtbSelectNextActorAndRunTurnEdgeEvents` is the single turn state machine. It handles queue building, sorting, turn advancing, status ticking, and overdrive charging in one function.

4. **Overdrive has 17 slots per actor** — bitmask at `pad_0764[658]` tracks unlocked slots. Each slot has a 16-bit "uses remaining" counter. When uses hit 0, global overdrive-ready flag is set.

5. **Overdrive modes are bit-flag driven** — Aggressive (2x), Stoic (3x), High-level bonus (2x if level >= 1), Decay (10%/turn + sphere grid integration). Modes can stack multiplicatively.

6. **Magic ID 429 + 6 special action IDs force skip-turn** — these likely correspond to Defend/Reflex/Escape/etc actions that don't advance CTB.

7. **Turn counter is byte-pair** — `battleState[0]` (current tick) vs `battleState[1]` (ticks per turn). When current reaches threshold, all actors tick their wait counters.

8. **Selection sort is fine for 31 actors** — O(n²) = 961 comparisons, negligible vs. battle logic. No need for heap sort.

9. **Aeon menu slots always go last** — `+0x10000` priority offset ensures aeons summoned via menu don't preempt player actions.

10. **Overdrive level numbering is inverted** — level 0 = full charge, level 3 = empty. Likely a UI display convention (higher level = more urgent to use).

---

## What's Next?

- **batch_0005**: ATEL Movie dispatcher (`FFX_Atel_Movie_FuncBxxx_*` — 475 opcodes) — the cutscene VM
- **batch_0006**: AI decision loop (`FFX_Battle_AiDecisionLoop` — monster behavior)
- **batch_0007**: Particle system (`FFX_Particle_*`)
- **batch_0008**: Sound queue (`FFX_Sound_QueueCmd22/24/32/46`)
- **batch_0009**: RTTI classes via class_informer (non-PhyreEngine FFX classes)

---

**Next batch:** ATEL Movie dispatcher — the cutscene VM with 475 opcodes.
