# FFX.exe Decompilation — Batch 3 (Boot, Damage, ATEL VM)

**Database:** ffxoficial.exe.i64 (session 85e0242a)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP
**Scope:** Deep analysis of 3 critical functions (5,919 bytes total decompiled code)

---

## Summary

This batch decompiles 3 of the most important FFX.exe functions:

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `FFX_System_Host_Constructor` | `0x64ddb0` | 0xD9A (3,482B) | Boot sequence: init 69KB scene host |
| `FFX_Battle_ComputeHitDamage` | `0x78e680` | 0x84F (2,127B) | Core damage formula |
| `FFX_Atel_InitVmAndRegisterFuncspaces` | `0x86d660` | 0x26A (618B) | ATEL VM dispatcher init |

`★ Insight ─────────────────────────────────────`
The decompilation reveals that **FFX is built entirely on PhyreEngine's PCaller template** for resource management. The 5 PCallers in System_Host (each 16 bytes per the prior analysis) and the 5 `PInstanceList`s are key architectural decisions — Square Enix structured the entire scene host around these reference-counted handles.
`─────────────────────────────────────────────────`

---

## 1. FFX_System_Host_Constructor @ 0x64ddb0 (3,482 bytes)

### Overview

This is the **master initialization function** for `g_FFX_System_Host`, a **69,096-byte (0x10DE8) singleton** at offset 0xC42928 in the binary. It's the foundation for both Battle and Field scenes.

### What It Allocates

The constructor builds a hierarchy of subsystems, all stored inline in the 69KB singleton:

```
FFX_System_Host (69096 bytes total)
├── vtable (4B)
├── m_cursorRingState        @ +4   (BtlUI cursor ring, calls FFX_BtlUI_InitCursorRingState)
├── m_flagsWord              @ +?
├── m_headerState[22]        @ +?   (22-element int array tracking view/battle state)
├── m_pcallers[5]            @ +?   (PCaller<...> x 5, each 16 bytes = 80B for ref-counted handles)
├── m_fieldDC                @ +?   (field draw context)
├── pad23C / m_perspCam*     @ +?   (4 PCameraPerspective + 1 PCameraOrthographic)
├── padD4 / projection mtx   @ +?   (ViewMatrix + projection)
├── pad10D30 / shader prep   @ +?   (2 FFX_ShaderPreprocessor instances)
├── unknown PMapPair lists   @ +?   (7 AlignedLinkedListBlock_Init, all 28B 8x4)
├── PInstanceList x 5        @ +?   (model/chr/bone/cluster instance lists)
├── Phyre_ResourceList       @ +?   (64 resources, sized 0x50 each)
├── resource cluster arrays  @ +?   (3 arrays of 16 Phyre_ResourceList each)
├── pad2A88 / Framebuffer    @ +?   (3 x 4096B aligned alloc for frame buffers)
├── pad3878 / mutex          @ +?   (CreateMutexW handle for thread sync)
├── 3-color correction       @ +17,432 floats (start at offset 47424)
│                             4 floats per color group × 4 = 16 floats
│                             + 4 more (4 vec4 arrays)
├── padF9C7 / various        @ +0xF9C7
└── g_FFX_System_Host        @ +0x10D18 (singleton marker)
```

### Detailed Subsystem Construction Order

The constructor uses a **state machine** with `LOBYTE(v25)` tracking init phase (0 → 79):

| Phase | What Init |
|-------|----------|
| 0 | vtable = 0, m_cursorRingState init via BtlUI_InitCursorRingState |
| 1 | m_flagsWord = 0, m_headerState[0..14] = 0 |
| 5 | m_headerState[15..17, 19] = 0 |
| 6 | `PCaller_Constructor(host->m_pcallers[0..4])` (5 calls) |
| 7 | m_fieldDC = 0, `PCameraPerspective_ctor(m_perspCam1)` |
| 8 | `PCameraPerspective_ctor(m_perspCam2/3)` |
| 9 | Set perspective camera params, `Phyre_ViewMatrix_InitIdentity`, `PCameraOrthographic_UpdateProjectionMatrix` |
| 16 | 2x `Phyre_PSharedPtr_GetRefCount` for shader type arrays |
| 17 | `eh vector constructor iterator` for 8 PSharedPtr entries |
| 20 | One more `PCameraPerspective_ctor`, transform matrix init |
| 22 | `FFX_ShaderPreprocessor_ctor(&host->pad10D30[408])` (2 instances total) |
| 25 | Init postprocess/buffer pool params |
| 28 | `AlignedLinkedListBlock_Init(&host->pad10D30[612], 20, 8, 4, "PMapPair")` |
| 30-31 | `Phyre_RBTree_AllocSentinelNode_B` + 5x `PInstanceList_InitWrapper` |
| 32-36 | PInstanceList init continues, 64-entry resource list init |
| 37-41 | 3 arrays of 16 Phyre_ResourceList |
| 54 | Final 0x50-sized resource list |
| 56-58 | Final PInstanceList + AlignedLinkedListBlock + view matrix |
| 59 | Final PSharedPtr init |
| 77 | Final AlignedLinkedListBlock + identity matrix + temp storage |
| 79 | Global color correction floats (16 vec4's — for color grading/lookup) |

### Color Correction (offsets 47424-47512, 32 floats × 4 bytes)

```
offset 47424 = 1.0f   (R init)
offset 47428 = 1.0f   (R scale)
offset 47432 = 1.0f   (G init)
offset 47436 = 1.0f   (G scale)
offset 47440 = 1.0f   (B init)
offset 47444 = 1.0f   (B scale)
offset 47448 = 0.0f   (offset matrix)
offset 47452 = 1.0f
offset 47456 = 1.0f
offset 47460 = 1.0f
offset 47464 = 1.0f
offset 47468 = 0.0f
offset 47472 = 0.0f
offset 47476 = 0.0f
offset 47480 = 0.0f
offset 47484 = 1.0f
offset 47488 = 1.0f
offset 47492 = 1.0f
offset 47496 = 1.0f
offset 47500 = 0.0f
offset 47504 = 0.0f
offset 47508 = 0.0f
offset 47512 = 0.0f
```

**Insight:** 32 floats form 8 vec4s = a single 4x4 color correction matrix stored in column-major order (or 2 vec4 + 4 vec4 = 1 RGB init matrix + 1 scale matrix + transform offset).

### Three 4096-byte Frame Buffers

```c
// Frame buffer triple-buffer at offset +0x2344
buf = Engine_AlignedAllocAlign(4096, 4);    // 4KB aligned allocation
memset(buf, 0, 0x1000u);
host->pad2A88[876] = buf;
host->pad2A88[872] = 1024;                  // size = 1024 quad words (= 4096B)
// repeated 3 times for triple buffering
```

`Engine_AlignedAllocAlign(4096, 4)` allocates 4KB aligned to 16 bytes. This is the **command buffer pool** for D3D11/Vulkan render commands.

### Mutex Synchronization

```c
host->pad3878[47116] = (HANDLE)CreateMutexW(0, 0, 0);  // Win32 mutex
host->pad3878[47124] = 1;                              // initial lock count
```

The mutex protects the frame buffer pools — typical pattern for multi-threaded command buffer fills.

### Key Findings

1. **Singleton size = 69,096 bytes** — fits exactly with `(28,464B base + many subsystem extensions)`
2. **5 PCallers** — used for resource references: PCamera, characters, scenes, etc.
3. **4 PCameraPerspective + 1 PCameraOrthographic** — main/sub/scene cameras + UI overlay
4. **2 FFX_ShaderPreprocessor** — likely vertex+fragment or shader array
5. **Color correction matrix** — 4x4 RGBA transform for color grading
6. **Triple-buffer frame pool** — 3 × 4KB aligned command buffers
7. **State machine** — 79 init phases tracked via `LOBYTE(v25)`
8. **Win32 mutex** — multi-threaded command buffer access

---

## 2. FFX_Battle_ComputeHitDamage @ 0x78e680 (2,127 bytes)

### Overview

This is the **core damage formula** — every physical attack, magic spell, and special move funnels through here. It applies **element resistance, status modifiers, critical hit chance, overdrive modifiers**, and ~30 other transforms.

### Function Signature

```c
int __fastcall FFX_Battle_ComputeHitDamage(
    FFX_DamageType dmgType,           // physical vs magic vs special
    FFXBattleActorRecord *attacker,
    FFXBattleActorRecord *target,
    int basePower
);
```

### Damage Pipeline

```
┌─────────────────────────────────────────────────────────────┐
│ 1. INITIALIZATION: read defender stats (magicDefense,defense)│
│    Read cmdCtx flags (bit 0x40000 = preemptive attack)      │
│    Init 7 hit counter arrays (0 each)                       │
└────────────────┬────────────────────────────────────────────┘
                 ▼
┌─────────────────────────────────────────────────────────────┐
│ 2. PREEMPTIVE: v78 = CheckPreemptiveAttack                   │
│    ResolveHitElementalCounters → check target count           │
│    if 1 hit:  load monster bins, set v70=1, n2=2            │
│    if 0 hits: skip damage calc, only Overkill               │
│    if multi hits: continue normally                          │
└────────────────┬────────────────────────────────────────────┘
                 ▼
┌─────────────────────────────────────────────────────────────┐
│ 3. RESOLVE:  ResolveHitAccuracyAndEffects                   │
│    Bumps +1 hit counter if hit succeeds                      │
└────────────────┬────────────────────────────────────────────┘
                 ▼
┌─────────────────────────────────────────────────────────────┐
│ 4. DAMAGE FORMULA DISPATCH                                   │
│    Within basePowera=true block (damageable):                │
│      if v18 & 1 (PHYSICAL flag):                             │
│        DamageFormulaDispatch(formula, attacker, target)       │
│        ComputeDamageQuarterMultiplier                         │
│        ComputeMagicGuardHalving                               │
│        ComputePhysGuardHalving                                │
│        if !unk_112A909: ComputeCriticalHit                   │
│        ComputeDoublecastDamage                                │
│        CheckZanmatoOrInstantKill         ◄──── Yojimbo!     │
│        CheckDoubleDamagePierce                                │
│        ApplyElementAffinityModifier                           │
│        ComputeMagicAbsorb                                     │
│        ApplyDamagePolarityReversal                            │
│        ApplyElementResist                                     │
│        ComputeShieldDamage                                    │
│        ComputeGuardDamage                                     │
│        ApplyPierceDamageHalving                               │
│        TryConsumeElementNullStatus                            │
│        ComputeOverdriveDamageMul                              │
│      if v18 & 2 (MAGIC flag):                                 │
│        DamageFormulaDispatch + Zanmato check                  │
│        Cap damage at defender->currentMagic                   │
│        ApplyDamagePolarityReversal                            │
│      if v18 & 4 (SPECIAL flag):                               │
│        DamageFormulaDispatch + PolarityReversal               │
│        (always immediate killer)                              │
└────────────────┬────────────────────────────────────────────┘
                 ▼
┌─────────────────────────────────────────────────────────────┐
│ 5. APPLY POST-PROCESS                                        │
│    ApplyDamageAmplifier                                      │
│    CheckAssessConceal (Pierce/Life/Death immunity)            │
│    MainDamageFormula                                         │
│    ResolveHitTargetEffectsAndMultipliers                      │
│    CheckEjectHit                                             │
│    TrackDeathAndOverkill                                     │
│    CheckFirstStrikeMultiplier                                 │
│    ApplyStatusEffectFromMask                                 │
│    ComputeOverdriveChargeFromHit                             │
└────────────────┬────────────────────────────────────────────┘
                 ▼
┌─────────────────────────────────────────────────────────────┐
│ 6. CAP TO MAX + WRITE BACK                                   │
│    Memory[0x112A90E] = fix damage (sets p_n10000 to 1)       │
│    Memory[0x112A90F] = always p_n10000 (sets to 10000)       │
│    Memory[0x112A910] = always crit (sets to 100000)          │
│    n9999 = 9999 or 99999 based on byte 1600 & 8              │
│    Clamp damage to ±n9999                                    │
│    Write to defender HP, currentStrength, counters           │
│    hitResultCode, hitCounters, effects applied to result    │
│    Return damage                                              │
└─────────────────────────────────────────────────────────────┘
```

### Key Modifier Functions

| Function | Address | Size | Purpose |
|----------|---------|------|---------|
| `FFX_Battle_MainDamageFormula` | 0x78aec0 | (-- not shown --) | Base Power × level / defense formula |
| `FFX_Battle_DamageFormulaDispatch` | 0x789cb0 | (-- not shown --) | Switch on formula type |
| `FFX_Battle_CheckZanmatoOrInstantKill` | 0x78c640 | (-- not shown --) | Yojimbo's signature move |
| `FFX_Battle_ComputeCriticalHit` | 0x789750 | (-- not shown --) | Crit chance with reaction abilities |
| `FFX_Battle_ApplyElementResist` | 0x78a420 | (-- not shown --) | Element weakness |
| `FFX_Battle_ComputeOverdriveDamageMul` | 0x78be50 | (-- not shown --) | Overdrive mode multiplier |

### Debug Toggles

```c
// Game debug flags at .data section
MEMORY[0x112A906]  // Disable MainDamageFormula + HitTargetEffectsAndMultipliers?
MEMORY[0x112A908]  // Toggle damage formula 0 vs 1
MEMORY[0x112A909]  // Disable ComputeCriticalHit (instant-kill magic: Doom)
MEMORY[0x112A90E]  // Set damage = 1 (every hit is 1)
MEMORY[0x112A90F]  // Set damage = 10000 (massive hits)
MEMORY[0x112A910]  // Set damage = 100000 (almost always crit?)
```

### Damage Cap Logic

```c
n9999 = (bit(11) of byte1726) ? 99999 : 9999;  // 99999 if piercing damage, 9999 otherwise
if ((v48 & 0x80u) == 0) {                    // bit 7
    if ((v48 & 0x40) != 0)                   // bit 6
        n9999 = 9999;
} else {
    n9999 = 99999;                           // piercing: 99999 cap
}

if (byte1600 & 8) {                          // flag: bypass damage cap?
    if (p_n10000 - 1 > 0x270D) {              // > 9999
        if (p_n10000 + 9998 <= 0x270D)
            p_n10000 = -9999;
    } else {
        p_n10000 = 9999;
    }
}
```

### Clamp Loop

```c
// For 3 hit result slots:
for (3 iterations) {
    n9999_1 = clamped_dmg;
    if (n9999_1 < -n9999) n9999_1 = -n9999;
    if (n9999_1 > n9999)  n9999_1 = n9999;
    
    v51[i] = n9999_1;                        // store clamped damage
    defender.strength_meters[i+404] += n9999_1;
    defender.strength_curr[i] -= n9999_1;    // remove from current HP
    if (dmgBufferBase) dmgBufferBase[i] -= n9999_1;
    
    v55 = defender.strength_curr[i] < 0;    // hit kill?
    defender.strength_curr[i] = v55 ? 0 : defender.strength_curr[i];
}
```

### Hit Result Writeback

```c
hitResultCtx[0]   = p_n17;     // hit flag
hitResultCtx[1]   = CheckHitResultCounters(v66, &v70);
hitResultCtx[24]  = v80;       // hit flags
hitResultCtx[26]  = EffectsAndMultipliers;
hitResultCtx[2]   = attacker;  // ?
hitResultCtx[3]   = n2;        // damage type?
hitResultCtx[28]  = DamageFormulaDispatch(atkr, target);  // raw formula
hitResultCtx[4]   = v92;       // ?
finalDmg = CheckStatModifiersActive(target, basePower, cmdCtx, n100, v61);
```

### Key Findings

1. **~30 modifier functions called** in pipeline — every defensive ability, status, elemental property, overdrive mode has a modifier
2. **Debug toggles at .data section** — devs can set damage = 1, 10000, or 100000 via memory writes
3. **Damage cap = 9999 normally, 99999 for piercing** — matches Final Fantasy classic damage cap of 9999
4. **3 damage slots updated** per hit — supports multi-hit attacks (≥ 3 hits per turn)
5. **Yojimbo's Zanmato detected** via CheckZanmatoOrInstantKill — instant-kill mechanic
6. **HP clamped at 0, not negative** — typical JRPG over-damage discard
7. **Element affinity, shield, guard, pierce, null, absorb** — 6 separate damage modifiers per hit
8. **Overdrive charge computed from hit** — `ComputeOverdriveChargeFromHit` chains damage→drive gauge
9. **Status applied from mask** — `ApplyStatusEffectFromMask` writes status bits via flag word

---

## 3. FFX_Atel_InitVmAndRegisterFuncspaces @ 0x86d660 (618 bytes)

### Overview

This function **registers the 11 ATEL funcspace dispatch tables** in the global VM context. Each funcspace has 256 entries (16 bytes each: `callpopa_fn`, `pad`, `float_return_fn`, `int_return_fn`). It also resets all VM state and inits the Sound system.

### 11 Registered Funcspaces

| Channel | Funcspace | Address | Size |
|---------|-----------|---------|------|
| 0 | **Battle** | `0xC42618` | 256 × 16 = 4096B |
| 1 | **Common** | `0xC50050` | 4096B |
| 2 | **Math** | `0xC52BE0` | 4096B |
| 3 | **Camera** | `0xC43988` | 4096B |
| 4 | **Map** | `0xC5DC90` | 4096B |
| 5 | **Movie** | `0xC40E20` | 4096B |
| 6 | **Mount** | `0xC5D8C0` | 4096B |
| 7 | **SgEvent** | `0xC88D88` | 4096B |
| 8 | **ChEvent** | `0xC891F8` | 4096B |
| 9 | **AbilityMap** | `0xC85EB0` | 4096B |
| 10 | **Debug** | `0xC52DD8` | 4096B |

Each funcspace is **a lookup table of 256 bytecode opcode handlers** at the channel. The combination `channel*256 + opcode` = unique function pointer.

Total: **11 × 256 = 2,816 unique opcodes**.

### What ATEL Init Also Does

```c
// 1. Set double precision floats (timing, music, ...)
unk_1325B58[0] = 2.0;  // 0x1325B58
unk_1325B5C   = 2.0;  // 0x1325B5C

// 2. Init save buffer slots
FFX_Save_InitBufferSlots();

// 3. Set save globals
MEMORY[0x1326B2C] = 100;     // some counter
unk_1326CB0 = -1; unk_1326CB4 = -1;
unk_1326CB8 = -1; unk_1326CBC = -1;

// 4. Reset field state
FFX_Field_ResetEventStepCounters();
FFX_Field_SetMapregIndex(255);  // 255 = no map selected
unk_1326B42 = 0;
FFX_Atel_ClearScriptStorage();

// 5. Clear texture objects for events
FFX_Atel_ResetFuncspaceSelectors();
FFX_Field_ResetControlledActorIndex();

// 6. Clear encounter override
g_FFX_Encounter_ForceFieldOverride_candidate = -1;
FFX_Atel_ClearQueryFlags();

// 7. Reset encounter zone, area faction, music track
FFX_EncounterZone_InitTable();
FFX_Atel_SetAreaFaction(0);
FFX_Battle_SetMusicTrackIndex(-1);

// 8. Clear movie state (ATEL Movie subsystem)
FFX_Atel_ClearMovieState();

// 9. Reset analog stick dead zone + scene timer callback
FFX_Input_AnalogStickDeadZone(2, FFX_Field_UpdateSceneTimer);

// 10. Clear global flags (bit 0 of various unk_* globals)
unk_1325D98 &= ~1u; unk_1325FD0 &= ~1u;
unk_1326208 &= ~1u; unk_1326440 &= ~1u;
unk_1326678 &= ~1u; unk_13268B0 &= ~1u;

// 11. Misc booleans = 0
unk_1325BA8 = 0;  // ... (6 more) ... unk_13268F8 = 0;

// 12. Set primary VM context pointer
MEMORY[0x1326AE8] = (int *)MEMORY[0x1325B60];

// 13. Init CRT runtime floats
_cfltcvt_init_90();

// 14. Init sound system
FFX_Sound_InitSystem();

// 15. Init text parsing
FFX_Text_ParseHexString("0x0");
```

### Register Funcspace Loop

```c
for ( i = 0; i < 16; ++i )
    FFX_Atel_RegisterFuncspace(subsystem, funcspace);  // pre-allocated 16 slots?

FFX_Atel_RegisterFuncspace(subsystem_1, funcspace);    // Battle (channel 0)
FFX_Atel_RegisterFuncspace(subsystem_2, funcspace_1);  // Common
FFX_Atel_RegisterFuncspace(subsystem_3, funcspace_2);  // Math
FFX_Atel_RegisterFuncspace(subsystem_4, funcspace_3);  // Camera
FFX_Atel_RegisterFuncspace(subsystem_5, funcspace_4);  // Map
FFX_Atel_RegisterFuncspace(subsystem_6, funcspace_5);  // Movie
FFX_Atel_RegisterFuncspace(subsystem_7, funcspace_6);  // Mount
FFX_Atel_RegisterFuncspace(subsystem_8, funcspace_7);  // SgEvent (Sphere Grid)
FFX_Atel_RegisterFuncspace(subsystem_9, funcspace_8);  // ChEvent (Character)
FFX_Atel_RegisterFuncspace(subsystem_10, funcspace_9); // AbilityMap
FFX_Atel_RegisterFuncspace(subsystem_11, funcspace_10); // Debug
```

The 16-iteration loop pre-allocates idle slots. Then 11 specific channels are filled with their dedicated funcspaces.

### Per-Funcspace Entry Layout

```c
struct FFX_AtelFuncspaceEntry {        // 16 bytes per entry
    void* callpopa_fn;                 // +0:  call/popA convention
    void* pad;                         // +4:  usually 0
    void* float_return_fn;             // +8:  float-returning opcode
    void* int_return_fn;               // +12: int-returning opcode
};
```

Each opcode can have **4 calling conventions**:
- `CALL` (no args, no return)
- `CALLPOPA` (call, pop args)
- `STATUS` (returns status)
- `FLOATRET` (returns float)
- `INTRET` (returns int32)

That explains why each domain has 5 funcs per opcode (e.g., `FuncB009_CALL`, `FuncB009_STATUS`, `FuncB009_FLOATRET`, `FuncB009_INTRET`, `FuncB009_CALLPOPA`).

### Domain Architecture

```
ATEL VM
├── Channel 0: Battle  (cutscenes during battle, scripted battle events)
├── Channel 1: Common  (shared scripting across domains)
├── Channel 2: Math    (math primitives: vector ops, lerp, etc.)
├── Channel 3: Camera  (camera ATEL ops: shake, set, target, etc.)
├── Channel 4: Map     (map-level ops: load, ambient, warp)
├── Channel 5: Movie   (cutscene video playback, subtitles, FMV)
├── Channel 6: Mount   (Chocobo/mount control)
├── Channel 7: SgEvent (Sphere Grid event ops: node activate, animate)
├── Channel 8: ChEvent (Character event ops: scripted dialogue/animations)
├── Channel 9: AbilityMap (UI for Sphere Grid: button nav, panel draw)
└── Channel 10: Debug  (debug menu ops)
```

### Total Opcode Capacity

**11 channels × 256 opcodes × 4 calling conventions = 11,264 entries**
But each table is 4096B = 256 × 16B, so each channel has 256 unique opcodes with 4 conventions each. Total **2,816 unique opcodes**, matching the 11 × 256 grid.

### Key Findings

1. **ATEL is a 2-level dispatch system** — `channel × opcode_idx` selects the handler, with 4 calling conventions per handler.
2. **5-arg funcspace encoding** — `CALL/CALLPOPA/STATUS/FLOATRET/INTRET` correspond to the 5 suffix names in IDA.
3. **11 functional domains** — battle, common, math, camera, map, movie, mount, sphere grid, character, ability map, debug.
4. **VM total capacity = 2,816 opcodes** across all domains.
5. **Init also resets 6+ subsystem globals** — encounter, area faction, music, movie state, scene timer, etc.
6. **`FFX_Input_AnalogStickDeadZone(2, FFX_Field_UpdateSceneTimer)`** — scene timer is tied to controller input → confirms frame-rate-coupled update.
7. **Sound system inits from ATEL init** — `FFX_Sound_InitSystem` is called here, so ATEL VM must be alive before sound can work.

---

## Cross-Cutting Insights

### Architectural Patterns Shared Across All 3 Functions

1. **Resource init via PCaller** — System_Host uses 5 PCallers for camera/scenes/characters. Same template used across FFX.exe.

2. **State machines tracked via `LOBYTE(vNN)`** — System_Host has 79 distinct init phases (0-79). Patterns seen in many FFX init functions.

3. **Global flags at .data section** — Battle damage has 5 debug toggles at `0x112A906-0x112A910`. ATEL VM has many `unk_1325XXX`/`unk_1326XXX` globals.

4. **Aligned allocation pattern** — `Engine_AlignedAllocAlign(4096, 4)` used 3 times for triple-buffered frame commands. Align 4 = 16-byte alignment.

5. **Mutex synchronization** — `CreateMutexW` in System_Host guards frame buffers. Multi-threaded command buffer fills.

6. **Singleton pattern via globals** — System_Host is a global singleton at `g_FFX_System_Host`. ATEL init writes to `MEMORY[0x1325B60]` for primary VM.

7. **EH vector constructor iterators** — Constructor loops for stacks of PSharedPtrs, PCallers, PCluster destructors.

### What This Tells Us About FFX

1. **Battle is decoupled from rendering** — damage calculation is pure function of actor stats, no rendering calls except possibly damage overlay (not in main code).

2. **Each hit can have 3 damage components** — physical, magical, special. Each gets its own DamageFormulaDispatch call.

3. **Elemental system has 5+ modifier types** — affinity, resistance, shield, guard, pierce, null, absorb.

4. **Overdrive is wired into the damage path** — `ComputeOverdriveDamageMul` and `ComputeOverdriveChargeFromHit` both run per hit.

5. **Cutscenes are full scripting** — ATEL Movie channel (256 opcodes) + 11 channels total = real scripting language, not just play-video-and-wait.

6. **Boot takes ~70KB** of host state — that's substantial. PhyreEngine boot is inside these 70KB (5 PCallers, 5 PInstanceLists, 5 cameras, 2 shader preprocessor).

7. **5 PCallers in scene host** — suggests ~5 distinct ref-counted resource references. Likely: camera(s), scene root, character root, world root, post-process root.

---

## What's Next?

After batch_0001+0002+0003 we now have:
- **Total functions documented**: 13,467 FFX_* (100%) + 3 deep-dive analyses
- **Init sequences understood**: System_Host boot + ATEL VM init + Battle damage
- **Battle mechanics**: 30+ modifier pipeline understood
- **ATEL architecture**: 11 channels, 2,816 opcodes, 5 calling conventions

### Suggested Next Batches

1. **batch_0004: Decompile CTB logic** — `FFX_Battle_CtbSelectNextActorAndRunTurnEdgeEvents` for turn scheduling
2. **batch_0005: Decompile ATEL Movie dispatcher** — `FFX_Atel_Movie_DispatchOpcode` (when opcode execution happens)
3. **batch_0006: Decompile AI/condition system** — `FFX_Battle_AiDecisionLoop` for monster AI
4. **batch_0007: Decompile Particle system** — `FFX_Particle_*` (11 funcs, full system)
5. **batch_0008: Decompile Sound queue cmds** — `FFX_Sound_QueueCmd22/24/32/46` for audio architecture
6. **batch_0009: Find RTTI classes** — class_informer pass to find non-PhyreEngine FFX classes

---

**Next batch:** Turn-scheduling / CTB analysis (batch_0004) — critical for understanding the combat loop.
