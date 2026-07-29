# FFX.exe Decompilation — Batch 32: Monster AI / Battle Brain

**Database:** ffxoficial_COPY.i64 (session 9993ee7e)
**Date:** 2026-07-28
**Type:** Architecture discovery + system map
**Scope:** Monster AI decision-making, CTB turn scheduling, command dispatch, action pipeline

---

## Key Discovery: MonsterAI is ATEL Bytecode, Not C++

**FFX's monster AI is NOT implemented as compiled C++ functions.** The "brain" of every monster lives in **ATEL bytecode scripts** stored in binary data files (`.bin`), interpreted at runtime by the ATEL Battle VM (channel 1, 135 opcodes, documented in batch_0020).

This means:
- There are **no standalone `FFX_MonsterAI_*` C++ functions** in the binary
- Monster behavior is defined in **data files** (per-monster `.bin` scripts)
- The C++ code is the **VM interpreter** + **opcode handlers** (already documented)
- Modding monster AI = editing `.bin` data files, not patching C++ code

`★ Insight ─────────────────────────────────────`
- **ATEL = Atelio** — PS2-era bytecode scripting language. Each monster has a script that defines: (1) phase rotation (which attack to use when), (2) target selection (who to attack), (3) conditions (HP thresholds, status checks), (4) overdrive triggers. The script is data, not code.
- **The 135 ATEL Battle opcodes** (batch_0020) are the C++ handlers that execute the bytecode. `BtlStartMotion`, `BtlSetDamageMotion`, `BtlDirTarget`, `PerformCommand` — these are the "primitives" that the bytecode calls.
- **Modding pathway**: To change monster AI, you edit the `.bin` data files ( bytecode scripts), NOT the C++ code. The C++ VM interpreter is fixed.
`─────────────────────────────────────────────────`

---

## Battle System Architecture

### Layer Diagram

```
┌─────────────────────────────────────────────────────────────┐
│                    MONSTER AI (Data Layer)                    │
│  Per-monster .bin files = ATEL bytecode scripts              │
│  Define: phase rotation, target selection, OD triggers       │
│  Read by: ATEL Battle VM (channel 1)                         │
└───────────────────────┬─────────────────────────────────────┘
                        │ bytecode interpretation
┌───────────────────────▼─────────────────────────────────────┐
│              ATEL BATTLE VM (135 opcodes)                    │
│  FFX_Atel_Battle_*_CALL_structural functions                 │
│  Channel 1 in funcspace table @ 0xC40E20                     │
│  5 conventions: CALL/STATUS/INTRET/FLOATRET/CALLPOPA        │
└───────────────────────┬─────────────────────────────────────┘
                        │ opcode handlers call into
┌───────────────────────▼─────────────────────────────────────┐
│              BATTLE ENGINE (C++ Layer)                        │
│  Command dispatch → Damage formula → Effect application      │
│  CTB turn scheduling → Actor management → UI                 │
└───────────────────────┬─────────────────────────────────────┘
                        │ renders via
┌───────────────────────▼─────────────────────────────────────┐
│              PHyreENGINE + BATTLE UI                          │
│  PEntity/PCamera/PRendering → D3D9 → Screen                 │
│  BtlUI cursor ring, HP bars, damage numbers                  │
└─────────────────────────────────────────────────────────────┘
```

---

## CTB (Conditional Turn-Based) System

The CTB system determines **turn order** based on character/enemy speed (AGI/DEX stats). Key functions discovered:

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_Btl_ApplyActionResults_Aftermath` | 0x78f0b0 | 631B | Main action aftermath handler |
| `FFX_Battle_ClampTurnCounterValue` | 0x78fa80 | — | Clamp turn counter |
| `FFX_Battle_PushSceneStateToQueue` | 0x79cff0 | — | Push state for scene transition |
| `FFX_Battle_FormatDamageNumberDisplay` | 0x79fa20 | — | Format damage display |
| `FFX_Battle_ApplyCtbOverloadDamage` | 0x78e2a0 | — | CTB overload damage |
| `FFX_Battle_ApplyMpDamage` | 0x78e400 | — | MP damage application |
| `FFX_Battle_CanActorDieFromDamage` | 0x78d460 | — | Death check |
| `FFX_Battle_OverdriveDamageHealEvent` | 0x7b0d60 | — | OD damage/heal event |
| `FFX_Battle_OverdriveAddClamp` | 0x7b15a0 | — | OD add with clamp |
| `FFX_Battle_UnlockOverdriveSlot` | 0x7b10d0 | — | Unlock OD slot |

### CTB Turn Flow

```
1. CTB tick: advance all actors' delay counters
2. When delay ≤ 0 → actor gets a turn
3. Sort by delay → select next actor
4. If actor is MONSTER:
   a. ATEL Battle VM executes monster's .bin script
   b. Script evaluates conditions (HP%, status, phase)
   c. Script selects action (attack, spell, flee, etc)
   d. Script selects target (random, lowest HP, strongest, etc)
5. If actor is PLAYER:
   a. UI shows command menu (Attack/Magic/Item/Special/Defend/Flee)
   b. Player selects command
6. Execute command → damage formula → effects → aftermath
7. Repeat from step 1
```

---

## Command Dispatch System

The command dispatch system (discovered via callgraph from `FFX_Btl_ApplyActionResults_Aftermath`):

| Function | Address | Size | Role |
|----------|---------|------|------|
| `FFX_Battle_DispatchActionCommand` | 0x7ac9e0 | 150B | Dispatch action command with targeting |
| `FFX_Battle_ResolveCommandEntryFromId` | 0x78cf10 | 264B | Resolve command by ID |
| `FFX_Battle_CheckActorValidForAction` | 0x7b24b0 | — | Validate actor for action |
| `FFX_Battle_QueryActorBitmask` | 0x794340 | — | Query actor bitmask |
| `FFX_Battle_SetActorTargetBitmaskAndCount` | 0x796440 | — | Set target bitmask |
| `FFX_Battle_AccessCurrentActorData` | 0x794030 | — | Core actor data accessor |
| `FFX_Kernel_GetCommandEntryById` | 0x790ae0 | — | Kernel command lookup |
| `FFX_Btl_IsCommandAvailable` | 0x79ad40 | — | Check command availability |
| `FFX_Btl_BuildActorCommandMenu` | 0x79bb70 | — | Build command menu (huge function) |
| `FFX_Btl_SetActorCommandBit` | 0x79c090 | — | Set command bit on actor |

### Command Dispatch Flow (from decompiled code)

```c
int FFX_Battle_DispatchActionCommand(int commandId, __int16 a2, int actorBitmask, int a4, int n64) {
    // Validate command is active
    if (*(_DWORD *)&byte_11333C4[13972] == -1) return -1;
    if (commandId != byte_11333C4[13988]) return -1;
    if (byte_11333C4[13991] >= 4) return -1;  // max 4 pending commands
    
    // Build command entry
    v13 = &byte_11333C4[16 * byte_11333C4[13991] + 13996];
    *(_WORD *)v13 = a2;
    *((_WORD *)v13 + 1) = 0;
    
    // Resolve command from kernel
    battleContext = FFX_Battle_ResolveCommandEntryFromId(commandId, 0, -1, (int)v13, 0);
    if (!battleContext) return -1;
    
    // Set target bitmask by iterating actors
    for (actorIdx = 0; actorIdx < 31; actorIdx++) {
        if ((actorBitmask >> actorIdx) & 1) {
            actorData = FFX_Battle_AccessCurrentActorData(battleContext);
            // Check if actor is valid target
            if (actorData[1].byte448) {
                if (v14)  // has permission flag
                    List |= (1 << actorIdx);
            } else if (actorData[1].pad_0443[1]) {
                List |= (1 << actorIdx);
            }
        }
    }
    
    // Apply targeting
    *((_DWORD *)v13 + 2) = List;
    if (List) {
        FFX_Battle_SetActorTargetBitmaskAndCount(commandId, List);
        ++byte_11333C4[13991];  // increment pending count
        *(_DWORD *)&byte_11333C4[13976] = a4;
        return 0;
    } else {
        // Target error
        nullsub_34(">>>>> TARGET ERROR CHR %2d : %08x : %3d <<<<<\n", commandId, List, actorIdx);
        return -1;
    }
}
```

---

## Overdrive System (from callgraph)

The Overdrive (OD) system is deeply integrated into the battle aftermath:

| Function | Address | Role |
|----------|---------|------|
| `OverdriveState_SetWithType3` | 0x7a0160 | Set OD state |
| `FFX_Battle_ComputeOverdriveLevel` | 0x78bfc0 | Compute OD level |
| `FFX_Battle_ComputeOverdriveCharge` | 0x798a10 | Compute OD charge |
| `FFX_Battle_AddOverdriveChargeBySource` | 0x785ac0 | Add OD charge from source |
| `FFX_Battle_UnlockOverdriveSlot` | 0x7b10d0 | Unlock OD slot |
| `FFX_Battle_OverdriveAddClamp` | 0x7b15a0 | OD add with clamp |
| `FFX_Battle_OverdriveDamageHealEvent` | 0x7b0d60 | OD damage/heal event |
| `FFX_Battle_ApplyCtbOverloadDamage` | 0x78e2a0 | CTB overload damage |

### OD Charge Sources (from decompiled `FFX_Battle_AddOverdriveChargeBySource`)

- Damage dealt → OD charge
- Damage received → OD charge
- Healing done → OD charge
- Status inflicted → OD charge
- Critical hit → OD charge bonus
- Overkill → OD charge bonus

---

## Effect System

| Function | Address | Role |
|----------|---------|------|
| `FFX_Battle_RequestEffect9Or10` | 0x79ed20 | Request effect type 9 or 10 |
| `FFX_Battle_RequestEffect76Or77` | 0x79ed40 | Request effect type 76 or 77 |
| `FFX_Magic_Preinst_RequestActorEffectResource` | 0x79ec00 | Pre-instantiate magic effect |
| `FFX_Magic_LoadOrQueueEffectResource` | 0x7fc200 | Load or queue effect resource |
| `FFX_Battle_DispatchGetActorPosition` | 0x7a0bd0 | Get actor position for effects |
| `FFX_Audio_Compute3DPanAndVolume` | 0x7ff9b0 | 3D audio for effects |
| `FFX_Battle_SeNodeLinkedList_AllocNode` | 0x7a0a50 | Sound effect allocation |

---

## Key Data Structures

### byte_11333C4 — Battle State Block

The central battle state is at `byte_11333C4` (global in .data segment):

```
Offset  Size  Field
+13972  4B    Active flag (-1 = inactive)
+13976  4B    Current action context
+13980  4B    Actor index
+13988  4B    Current command ID
+13991  1B    Pending command count (max 4)
+13996  64B   Command ring buffer (4 × 16B entries)
  +0:   2B    command ID
  +2:   2B    flags
  +8:   4B    target bitmask
  +12:  4B    reserved
```

### Actor Bitmask

Actors are identified by bit position in a 31-bit bitmask:
- Bits 0-6: Party members (Tidus, Yuna, Auron, etc)
- Bits 7-14: Monster slots (1-8)
- Bits 15-30: Special slots (aeons, NPCs)

---

## Monster AI Data Flow

```
Monster .bin file (ATEL bytecode)
    │
    ▼
ATEL Battle VM (channel 1)
    │
    ├── Opcode: BtlStartMotion (0x7a2d20) → start attack animation
    ├── Opcode: BtlSetDamageMotion (0x7a3110) → set damage motion
    ├── Opcode: BtlDirTarget (0x7a3db0) → face target
    ├── Opcode: BtlMove (0x7a4330) → move to position
    ├── Opcode: PerformCommand (0x7a44d0) → execute command
    ├── Opcode: BtlSetNormalEffect (0x7a4070) → apply effect
    ├── Opcode: GiveItem (0x7a2cc0) → drop item
    └── Opcode: BtlTerminateDeath (0x7a2b30) → death sequence
    │
    ▼
Battle Engine
    │
    ├── FFX_Battle_DispatchActionCommand → target selection
    ├── FFX_Battle_ComputeHitDamage → damage formula (batch_0012)
    ├── FFX_Battle_ApplyActionResults_Aftermath → apply results
    ├── Overdrive system → charge/unlock/trigger
    └── Effect system → VFX/SFX
    │
    ▼
CTB Turn Scheduling
    │
    ├── Delay = baseDelay / (AGI + modifiers)
    ├── When delay ≤ 0 → turn granted
    └── Repeat until battle ends
```

---

## Modding Implications

### What CAN be modded (data layer):
1. **Monster behavior scripts** — edit `.bin` files to change AI patterns
2. **Phase rotation** — change which attacks monsters use at which HP thresholds
3. **Target selection** — change who monsters attack (random, lowest HP, healer, etc)
4. **Overdrive triggers** — change when monsters use overdrive attacks
5. **Command availability** — change which commands are available to players
6. **Damage formulas** — modify the formula dispatch at 0x789cb0

### What CANNOT be modded without C++ patching:
1. **VM interpreter** — the ATEL opcode handlers are fixed C++
2. **CTB algorithm** — the turn scheduling is compiled C++
3. **Damage cap** — 9999/99999 is hardcoded in ComputeHitDamage
4. **Actor bitmask** — 31-actor limit is baked into the bitmask system
5. **Max pending commands** — 4-command limit in DispatchActionCommand

### Hook points for C++ mods:
1. `FFX_Battle_DispatchActionCommand` (0x7ac9e0) — intercept command dispatch
2. `FFX_Battle_ComputeHitDamage` (0x78e680) — modify damage calculation
3. `FFX_Battle_AddOverdriveChargeBySource` (0x785ac0) — modify OD charging
4. `FFX_Battle_AccessCurrentActorData` (0x794030) — read/modify actor state

---

## Key Findings

1. **MonsterAI is ATEL bytecode** — no standalone C++ functions. The "brain" is in `.bin` data files.

2. **135 ATEL Battle opcodes** are the C++ primitives that bytecode calls. Already documented in batch_0020.

3. **CTB turn scheduling** uses delay-based system. Turn order = f(AGI, modifiers, equipment).

4. **Command dispatch** is a ring buffer of 4 pending commands with 31-actor bitmask targeting.

5. **Overdrive system** has 7+ functions for charge computation, level tracking, slot management.

6. **byte_11333C4** is the central battle state block — 14KB+ of global state.

7. **Actor bitmask is 31-bit** — 7 party + 8 monsters + 16 special = 31 max actors.

8. **Effect system** uses pre-instantiation + resource queuing for VFX/SFX.

9. **Modding pathway**: Edit `.bin` data files for AI changes, hook C++ for engine changes.

10. **3D audio** is integrated into the effect system — `FFX_Audio_Compute3DPanAndVolume` positions sounds in 3D space.

---

## What's Next?

- **batch_0033**: Menu2D system (~200 funcs) — main menu, battle menus, save/load UI
- **batch_0034**: ShaderInterop + ShaderPreprocessor (~50 funcs) — shader compilation
- **batch_0035**: Input subsystem (~30 funcs) — DirectInput integration
- **batch_0036**: FieldSky + Cloud (~40 funcs) — environment effects
- **batch_0037**: Virtuos stubs + PC remnant layer (~20 funcs)
- **batch_0038**: FFX_WinMain + window management (~10 funcs)
- **batch_0039**: Cross-batch AI synthesis — monster AI architecture map
- **batch_0040**: Cross-batch battle synthesis — full battle system map
- **batch_0041**: Final architecture overview — all systems connected

---

**Note:** The "300 MonsterAI functions" estimate was incorrect. The actual AI code is 135 ATEL Battle opcodes (batch_0020) + ~30 battle engine support functions documented here. Total: ~165 functions for the complete battle brain.
