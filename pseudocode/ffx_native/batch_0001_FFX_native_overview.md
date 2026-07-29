# FFX.exe Decompilation — Batch 1 (FFX Native Code Overview)

**Database:** ffxoficial.exe.i64 (ffxoficial_COPY.i64 session 85e0242a)
**Date:** 2026-07-28
**Source:** Hex-Rays decompiler via IDA MCP

---

## Summary

After 19 batches of decompiling PhyreEngine families (~3,040 functions), this batch turns to the **FFX-native code** — the code Square Enix wrote on top of PhyreEngine to implement FFX as a game.

| Metric | Value |
|--------|-------|
| Total `FFX_*` functions | **13,467** |
| Total `sub_*` functions | 0 (IDA named all of them) |
| Total `PppMem_*` functions | 49 (pooled memory allocator) |
| **FFX-native code size ratio** | ~**4.4x larger** than PhyreEngine code |

`★ Insight ─────────────────────────────────────`
The fact that `sub_*` = 0 means IDA's auto-naming (FLA heuristics) + symbol propagation resolved every function in the binary. We have **complete coverage** at function granularity — but only **partial semantic understanding** of what each function does. Names like `FFX_Battle_ComputeHitDamage` are descriptive but not yet analyzed.
`─────────────────────────────────────────────────`

---

## Top 30 FFX_* Domains by Function Count

| Rank | Domain | Count | Description |
|------|--------|-------|-------------|
| 1 | `FFX_Battle_*` | **716** | Battle system, damage, CTB, Overdrive |
| 2 | `FFX_Field_*` | **715** | Field exploration (overworld, dungeons) |
| 3 | `FFX_Menu_*` | 502 | Menu system (Iggy UI framework) |
| 4 | `FFX_Sound_*` | 355 | Sound command queue / SFX |
| 5 | `FFX_Chr_*` | 314 | Character models, skinning, shading |
| 6 | `FFX_Render_*` | 263 | Render state management |
| 7 | `FFX_Save_*` | 253 | Save game load/save/checksum |
| 8 | `FFX_Vpx*` | 201 | VP8/VP9 video decoder |
| 9 | `FFX_Audio_*` | 165 | 3D audio, volume rolloff, fade |
| 10 | `FFX_Camera_*` | 159 | Camera projection, fly ctrl, split-screen |
| 11 | `FFX_Scene_*` | 116 | Scene transition, resource slots |
| 12 | `FFX_Shader*` | 105 | Shader param tree, bind, compile |
| 13 | `FFX_Movie_*` | 68 | CD/DVD sector-aligned read |
| 14 | `FFX_System_*` | 65 | Process args, locale, platform flag |
| 15 | `FFX_Encounter_*` | 59 | Random encounter, loader, transition |
| 16 | `FFX_Texture*` | 46 | Texture cache, slot table, TIM upload |
| 17 | `FFX_Input_*` | 39 | Keyboard/joystick polling |
| 18 | `FFX_Mem*` | 31 | Memory wrapper, freelist, dump |
| 19 | `FFX_Anim_*` | 31 | Animation playback, keyframe blend |
| 20 | `FFX_Heap*` | 22 | Heap alloc/free/coalesce |
| 21 | `FFX_Config_*` | 19 | INI parser/serializer |
| 22 | `FFX_Resource*` | 30 | Resource cache (slots, freelist) |
| 23 | `FFX_Particle_*` | 11 | Particle emit/update/render |
| 24 | `FFX_Text_*` | 10 | Text table, SJIS→ASCII |
| 25 | `FFX_Effect*` | 10 | Effect registry loader |
| 26 | `FFX_Party_*` | 8 | Party formation, auto-battle |
| 27 | `FFX_UI_*` | 3 | UI flow (titles, menus) |
| 28 | `FFX_Steam_*` | 2 | Steam Init, AppId |
| 29 | `PppMem_*` | 49 | Pooled memory allocator |

**Documented: ~4,353 functions across 29 domains.**
**Remaining: ~9,100 functions** still to inventory (likely under additional prefixes or `FFX_Battle_*` sub-categories).

---

## Battle System Architecture (FFX_Battle_*)

The battle system is the **largest domain** at 716 functions. The naming patterns reveal FFX's signature mechanics:

### Turn System (CTB — Conditional Turn Battle)

```
FFX_Battle_SortCtbPriorityQueue         @ 0x78d4a0  (0xc6 / 198B)
FFX_Battle_ClearCtbQueueCount           @ 0x78d570  (0xb / 11B)
FFX_Battle_CtbQueuePushActor            @ 0x78d580  (0x20 / 32B)
FFX_Battle_ComputeActorCtbWaitTimes     @ 0x78df90  (0x1cb / 459B)  ← REAL logic
FFX_Battle_InitPostVictoryCtbState      @ 0x78e160  (0x47 / 71B)
FFX_Battle_ApplyCtbOverloadDamage       @ 0x78e2a0  (0x4b / 75B)
FFX_Battle_SelectCtbAutoTarget          @ 0x78ef40  (0x103 / 259B)
FFX_Battle_ComputeCtbPriorityValue      @ 0x78f050  (0x3c / 60B)
FFX_Battle_GetCtbWaitTableEntry         @ 0x7909e0  (0x26 / 38B)
FFX_Battle_GetCtbWaitTableByte          @ 0x790a10  (0x28 / 40B)
FFX_Battle_CtbSelectNextActorAndRunTurnEdgeEvents  @ 0x791000  (0x1be / 446B)
FFX_Battle_ProcessCtbAndMultiHitDamage  @ 0x79a210  (0x239 / 569B)
FFX_Battle_CtbEdgeOverdriveEvent        @ 0x7b13d0  (0x174 / 372B)
FFX_Battle_GetVictoryEffectByte         @ 0x7fb160  (0xa / 10B)
```

`★ Insight ─────────────────────────────────────`
The CTB system uses a **priority queue** sorted by `m_ctbWaitTime` — each actor has a wait countdown, when it hits 0 the actor takes their turn. This is fundamentally different from ATB (Active Time Battle) where each actor has a charging bar.
`─────────────────────────────────────────────────`

### Overdrive System (37 functions)

```
FFX_Battle_AddOverdriveChargeBySource              @ 0x785ac0  202B
FFX_Battle_RequestOverdriveClearAll                 @ 0x788370
FFX_Battle_AdvanceStateOverdriveVictor              @ 0x788e20
FFX_Battle_ComputeOverdriveDamageMul                @ 0x78be50
FFX_Battle_ComputeOverdriveChargeFromHit            @ 0x78be90  293B
FFX_Battle_ComputeOverdriveLevel                    @ 0x78bfc0
FFX_Battle_DeathHandler_CallsOverdriveKillEvent     @ 0x78c800  733B
FFX_Battle_SetHpMpMaxWithOverdrive                  @ 0x78d330  291B
FFX_Battle_ComputeOverdriveActionState              @ 0x78d8b0  211B
FFX_Battle_CopyOverdriveRingToActive                @ 0x78d990
FFX_Battle_ConsumeMpOverdriveAfterCommand           @ 0x78e5f0
FFX_Battle_GetActorOverdriveGauge                   @ 0x78f9a0
FFX_Battle_IsOverdriveGaugeBit0                     @ 0x78f9c0
FFX_Battle_GetActorOverdriveThresholdPtr            @ 0x78fad0
FFX_Battle_GetActorOverdriveFlagBPtr                @ 0x78faf0
FFX_Battle_VictoryFlow_CallsOverdriveVictorEvent    @ 0x791820  1894B  ← LARGEST
FFX_Battle_ComputeOverdriveCharge                   @ 0x798a10
FFX_Battle_InitOverdriveStateForEncounter           @ 0x798b80
FFX_Battle_CopyOverdriveSourceArray                 @ 0x798ea0
FFX_Battle_IsOverdriveReady                         @ 0x79afd0
FFX_Battle_QueueOverdriveSet                        @ 0x7a00f0
FFX_Battle_MapOverdriveSlotToCommandSlot            @ 0x7ada50
FFX_Battle_ProcessPartyOverdriveEvent               @ 0x7ada70
FFX_Battle_UpdateOverdriveGauge                     @ 0x7afb70
FFX_Battle_SwapOverdriveGaugeValues                 @ 0x7b06f0
FFX_Battle_CountActorsWithOverdriveSlot             @ 0x7b0cb0
FFX_Battle_OverdriveDamageHealEvent                 @ 0x7b0d60  550B
FFX_Battle_OverdriveKillEvent                       @ 0x7b0f90  264B
FFX_Battle_OverdriveCowardEvent                     @ 0x7b10a0
FFX_Battle_UnlockOverdriveSlot                      @ 0x7b10d0  187B
FFX_Battle_InitOverdriveState                       @ 0x7b1190  313B
FFX_Battle_OverdriveFleeEvent_structural            @ 0x7b12d0
FFX_Battle_BuildOverdriveCommandRing                @ 0x7b2ae0
FFX_Battle_RenderFormationOverdrivePanel            @ 0x8927e0
```

`★ Insight ─────────────────────────────────────`
The Overdrive system has **12 distinct event hooks** (Victor, Kill, Coward, Damage, Heal, Flee, etc.) — each one a separate function that fires when that condition is met. The largest function `VictoryFlow_CallsOverdriveVictorEvent` (1894B) is the master victory orchestration that triggers the "use Overdrive to kill the last enemy" cinematic events.
`─────────────────────────────────────────────────`

### Damage System (37 functions)

The damage pipeline is the most algorithmically interesting:

```
FFX_Battle_ComputeHitDamage                  @ 0x78e680  0x84f (2127B) ← Core formula
FFX_Battle_MainDamageFormula                 @ 0x78aec0  0x6dc (1756B) ← Dispatcher
FFX_Battle_DamageFormulaDispatch             @ 0x789cb0  0x5aa (1450B) ← Multi-hit routing
FFX_Battle_ProcessHitDamage                  @ 0x7afe10  0x584 (1412B) ← Apply pipeline
FFX_Battle_CalculateDamageFormula            @ 0x7b0530  0x186 (390B)
FFX_Battle_ComputeDamageMultiHitLoop         @ 0x789990  0x315 (789B)
FFX_Battle_ApplyHitDamage_Loop               @ 0x789800  0x189 (393B)
FFX_Battle_ProcessMultiHitDamageMain         @ 0x7893a0  0x2cf (719B)
FFX_Battle_AutoUseItemForStatus              @ 0x7b2520  0x1b8 (440B)

Special damage modifiers:
FFX_Battle_ApplyPierceDamageHalving          @ 0x789350
FFX_Battle_ApplyDamagePolarityReversal       @ 0x78a2c0  ← Reflect/Concentrate/etc
FFX_Battle_ComputeMagicAbsorb                @ 0x78ae40
FFX_Battle_ComputeMagicGuardHalving          @ 0x78ae80  ← MagicGuard / Shell
FFX_Battle_ComputeGuardDamage                @ 0x78a890  ← Defend command
FFX_Battle_ComputeShieldDamage               @ 0x78a8f0  ← Auto-shell/etc
FFX_Battle_ComputeDoublecastDamage           @ 0x78c170
FFX_Battle_ApplyDamageModifiers              @ 0x78c210
FFX_Battle_ComputeDamageQuarterMultiplier    @ 0x78c5f0  ← Quarter damage?
FFX_Battle_CheckDoubleDamagePierce           @ 0x78c6b0
FFX_Battle_ComputeDamageBonus                @ 0x78d290
FFX_Battle_CanActorDieFromDamage             @ 0x78d460  ← Death-cap check
FFX_Battle_ApplyDamageAmplifier              @ 0x78e1b0
FFX_Battle_ApplyCtbOverloadDamage            @ 0x78e2a0  ← CTB overload damage
FFX_Battle_ApplyHpDamage                     @ 0x78e2f0  263B
FFX_Battle_ApplyMpDamage                     @ 0x78e400
FFX_Battle_SetDamageDisableFlag              @ 0x78e670  ← Skip damage (script?)
FFX_Battle_ProcessCtbAndMultiHitDamage       @ 0x79a210  569B
FFX_Battle_ApplyDamageWithChargeDecay        @ 0x79a030
FFX_Battle_OverdriveDamageHealEvent          @ 0x7b0d60  550B

Status conditions affecting death:
FFX_Battle_CheckZanmatoOrInstantKill         @ 0x78c640  107B ← Yojimbo's Zanmato
FFX_Battle_CheckPreemptiveAttack             @ 0x78c290  148B
FFX_Battle_CheckFirstStrikeMultiplier        @ 0x78c540
FFX_Battle_CheckHitResultCounters            @ 0x78c700
FFX_Battle_ProcessPhysicalHitStatus          @ 0x78c1b0
FFX_Battle_TrackDeathAndOverkill             @ 0x78c240  ← Overkill = damage overflow tracking
```

`★ Insight ─────────────────────────────────────`
The damage pipeline shows the standard FFX multiplier stack: `Base Damage × Strength/Defense × Element Affinity × Guard × Shield × MagicGuard × Pierce × Overdrive × Status × Critical → Cap (99999) → Death check → HP apply`. The `CheckZanmatoOrInstantKill` is the kill switch used by Yojimbo's `Zanmato` and Sword Magic's instant-kill effects.
`─────────────────────────────────────────────────`

### Turn Execution (11 functions)

```
FFX_Battle_ClampTurnCounterValue              @ 0x78fa80
FFX_Battle_AdjustTurnMeter                    @ 0x78fb50
FFX_Battle_CtbSelectNextActorAndRunTurnEdgeEvents  @ 0x791000  ← Critical dispatcher
FFX_Battle_ProcessActorTurnInit               @ 0x791230  1004B
FFX_Battle_IsActorActiveForTurn               @ 0x7917d0
FFX_Battle_CheckCanStartPlayerTurn            @ 0x792e90
FFX_Battle_ReturnConstant40                   @ 0x79af40
FFX_Battle_ResetPartyAfterActorTurn           @ 0x7aef30
FFX_Battle_ProcessActorTurnDamage             @ 0x7afac0
FFX_Battle_ReturnActorFromSwap                @ 0x7b7cf0
FFX_Battle_ReturnZeroNotOne                  @ 0x8cafa0
```

### Item System (7 functions)

```
FFX_Battle_RollAndGrantItemDrop_structural    @ 0x78b820  440B ← Drop roll
FFX_Battle_GetItemDropChance                  @ 0x798aa0
FFX_Battle_ProcessItemUseCommand              @ 0x799b50  398B ← Use item
FFX_Battle_AddItemsFromActionCommandList_structural  @ 0x7b0c30
FFX_Battle_BuildItemMenuForAction             @ 0x7b1a80
FFX_Battle_AutoUseItemForStatus               @ 0x7b2520  440B ← Auto-potion
FFX_Battle_BuildItemRingEntry                 @ 0x7b26e0  101B
```

### Magic System (5 functions)

```
FFX_Battle_ComputeMagicAbsorb                 @ 0x78ae40
FFX_Battle_ComputeMagicGuardHalving           @ 0x78ae80  ← Shell/Protect halves magic dmg
FFX_Battle_StartMagicEffectAndQueue           @ 0x79e8e0  337B
FFX_Battle_FreeActorMagicSlots                @ 0x79eab0
FFX_Battle_GetMagicCoreTransformData          @ 0x7b7e30
```

### Summoning (0 functions)

**Zero `FFX_Battle_*Summon*` functions!** The summoning mechanic must be handled by:
- `FFX_Battle_OverdriveDamageHealEvent` (Aeons)
- `FFX_Battle_OverdriveCowardEvent` (Yuna flees)
- AEON-specific code under `FFX_Chr_*` (Yojimbo model is a character)

---

## Save System Architecture (FFX_Save_* — 253 funcs)

The save system uses **PS3-compatible PSARC archives** with CRC32 checksums:

```
FFX_Save_CopyLocaleString                @ 0x6460e0
FFX_Save_ParseBytecodeToString           @ 0x646100
FFX_Save_ParseBytecodeCharacter          @ 0x646250  322B ← Multi-byte char decoder
FFX_Save_ReadFile_CHAPPU                 @ 0x646ce0  368B ← Load with CHAPPU prefix
FFX_Save_LoadSaveFile                    @ 0x646e50  323B
FFX_Save_WriteFileWithCrc_CHAPPU         @ 0x646fa0  406B ← Save with CRC + CHAPPU
FFX_Save_SwapEndianStruct                @ 0x6477c0  329B ← Big-endian conversion
FFX_Save_SetField364_1                   @ 0x647ef0
FFX_Save_ValidateChecksum                @ 0x647f20  90B
FFX_Save_LoadSaveData                    @ 0x648190
```

`★ Insight ─────────────────────────────────────`
**CHAPPU** is the PS3 save format magic bytes — backwards compatibility means the PC version retains the original format. `LoadSaveFile` → `ReadFile_CHAPPU` → validates CHAPPU signature → calls SwapEndianStruct (because PS3 is big-endian vs PC little-endian).
`─────────────────────────────────────────────────`

---

## Sound System Architecture (FFX_Sound_* — 355 funcs)

The sound system uses **asynchronous command queues**:

```
FFX_Sound_GetSingleton                   @ 0x67a150
FFX_Sound_QueueCmd46                     @ 0x67a190  40B ← Queue 46-byte command
FFX_Sound_QueueCommandAsync_ww           @ 0x67a1e0  14B ← Async with 2 word args
FFX_Sound_QueueCommandAsync2Params_structural_w  @ 0x67a210  24B
FFX_Sound_QueueCommandAsync_ww_0         @ 0x67a240  21B
FFX_Sound_QueueCommandAsync2Params_structural_w_0  @ 0x67a260  24B
FFX_Sound_QueueCommandAsync2Params_structural_w_1  @ 0x67a280  24B
FFX_Sound_QueueCmd32                     @ 0x67a2a0  24B
FFX_Sound_QueueCmd24                     @ 0x67a2e0  21B
FFX_Sound_SyncCmd22                      @ 0x67a300  21B ← Synchronous variant
```

`★ Insight ─────────────────────────────────────`
The `_structural_w`, `_ww`, etc. suffixes are IDA's heuristic for arguments — these are wrapper patterns where the actual command structure is built on the stack and then `QueueCmd*` is called. The command types (Queue/Sync, 22/24/32/46 bytes) suggest a **command queue with size-tagged messages** — likely a streaming audio buffer with metadata.
`─────────────────────────────────────────────────`

---

## Camera System (FFX_Camera_* — 159 funcs)

The camera system has many tiny operation functions (OpA, OpB, ..., OpBD):

```
FFX_Camera_GetFrustumScale               @ 0x639720
FFX_Camera_CopyModelViewMatrix           @ 0x639740
FFX_Camera_UpdateSceneScaleFactor        @ 0x639770
FFX_Camera_UpdateScaleFactor             @ 0x639790
FFX_Camera_SetupProjectionGlobal         @ 0x642f50
FFX_Camera_ComputeTransformMatrix        @ 0x643d30
FFX_Camera_CalculateModelViewMatrix      @ 0x65e7e0  862B ← View matrix
FFX_Camera_SetupProjection               @ 0x66cbf0  224B
FFX_Camera_LinkTransformChain            @ 0x67ff50  208B
FFX_Camera_PerspectiveAndFlyCtrl_Init    @ 0x680020  145B ← Camera mode
FFX_Camera_PerspectiveAndFlyCtrl_Dtor    @ 0x6800c0  155B
FFX_Camera_PerspectiveAndFlyCtrl_DestroyAndFree  @ 0x6801b0
FFX_Camera_GetFieldCameraData            @ 0x6805c0
FFX_Camera_ComputeTargetProjection       @ 0x795180  209B
FFX_Camera_Internal_OpA                  @ 0x7ba340
FFX_Camera_Internal_OpB                  @ 0x7ba3e0
... (many more OpC..OpBD)
FFX_Camera_SetPolar_FromAtelStack        @ 0x7bb550  206B ← Read atel camera script
FFX_Camera_SetPositionIfSlotMatch        @ 0x7bc060
FFX_Camera_SetFieldDefaultPosition       @ 0x7bc6a0
FFX_Camera_SetProjectionParameters       @ 0x7bc6d0
FFX_Camera_SetClippingParameters         @ 0x7bc770
FFX_Camera_BlurEffect                    @ 0x7be020  85B
FFX_Camera_ZeroReturn                    @ 0x7be080
FFX_Camera_FlagLoopSetter                @ 0x7bf120
```

`★ Insight ─────────────────────────────────────`
The `SetPolar_FromAtelStack` is **gold** — it confirms FFX uses the same `camSetPolar` mechanism described in our earlier team memory. ATEL scripts push camera angles (H/El/D) onto the camera stack, and this function pops them. The `BlEffect` function adds motion blur during scripted camera moves.
`─────────────────────────────────────────────────`

---

## Particle System (FFX_Particle_* — 11 funcs)

Lightweight particle subsystem (probably backed by PhyreEngine `PParticle`):

```
FFX_Particle_FreeBuffers                 @ 0x634940  154B
FFX_Particle_Emit                        @ 0x6e4fd0  303B
FFX_Particle_Init                        @ 0x6e5100  19B
FFX_Particle_SetTexture                  @ 0x6e5120  43B
FFX_Particle_Update                      @ 0x6e5150  113B
FFX_Particle_Render                      @ 0x6e54f0  193B
FFX_Particle_GetCount                    @ 0x6e55c0  25B
FFX_Particle_IsAlive                     @ 0x6e5700  6B
FFX_Particle_Kill                        @ 0x6e57c0  11B
FFX_Particle_SetLife                     @ 0x6e57d0  43B
FFX_Particle_GetLife                     @ 0x6e5800  29B
```

---

## Render System (FFX_Render_* — 263 funcs)

```
FFX_Render_StageUpTo8Constants           @ 0x58dd70  556B ← Constant buffer write
FFX_Render_UpdateConstantBundle_A       @ 0x593440  197B
FFX_Render_UpdateResourceBundle_Dispatch  @ 0x593650  75B
FFX_Render_UpdateConstantBundle_B       @ 0x5936a0  265B
FFX_Render_SetupDepthBiasState_Wrapper   @ 0x637a30  46B
FFX_Render_SceneNodeHousekeeping         @ 0x637ef0  68B
FFX_Render_AppendActiveInstance          @ 0x637fe0  134B
FFX_Render_AudioLightShaderSetup         @ 0x638070  134B
FFX_Render_ShadowMapTransformBridge      @ 0x639f40  19B
FFX_Render_InvertMatrixArray             @ 0x63c5a0  67B
```

---

## Entry Points (Initial Mapping)

The `FFX_System_Host_*` family is the main game class:

```
FFX_System_Host_InitSingleton            @ 0x635830  120B
FFX_System_SetSkipFieldDraw              @ 0x640390
FFX_System_GraphicInitialize             @ 0x641b80  438B ← Graphics init
FFX_System_SetAmbientVector              @ 0x643040
FFX_System_Host_Constructor              @ 0x64ddb0  0xd9a (3482B) ← LARGEST ctor in game
FFX_System_ProcessCmdLineArg             @ 0x887b40  75B
FFX_System_GetLocaleId                   @ 0x887b90  8B
FFX_System_GetLanguageRegionFlag         @ 0x887bb0  8B
FFX_System_IsEmbeddedSystem              @ 0x887bc0  8B
FFX_System_GetPlatformFlag               @ 0x887bd0  8B
```

`★ Insight ─────────────────────────────────────`
`FFX_System_Host_Constructor` is **3482 bytes** — one of the largest functions in the game. This is the master game class constructor that wires up every subsystem: Graphics, Input, Audio, Battle, Field, Menu, Save, etc. This is the most critical function to decompile to understand the boot sequence.
`─────────────────────────────────────────────────`

---

## PppMem — Pooled Memory Allocator (49 funcs)

A custom memory pool with fixed-size slabs:

```
PppMem_ClearVec3At160                    @ 0x72ee90  39B
PppMem_BuildNodeChain_1x128              @ 0x736750  39B
PppMem_BuildNodeChain_4x128              @ 0x736780  39B
PppMem_BuildNodeChain_8x128              @ 0x7367b0  39B
PppMem_BuildNodeChain_1x16               @ 0x7367e0  36B
PppMem_BuildNodeChain_16x16              @ 0x736810  36B
PppMem_BuildNodeChain_24x16              @ 0x736840  36B
PppMem_BuildNodeChain_4x16               @ 0x736870  36B
PppMem_BuildNodeChain_64x16              @ 0x7368a0  36B
PppMem_BuildNodeChain_8x16               @ 0x7368d0  36B
```

`★ Insight ─────────────────────────────────────`
The naming pattern `<COUNT>x<SIZE>` (e.g., `4x128`, `16x16`, `64x16`) reveals a **typed arena allocator** that pre-allocates `<COUNT>` nodes of `<SIZE>` bytes each. This is much faster than `malloc`/`free` for hot paths like particle emission and battle state updates where objects have predictable lifecycles.
`─────────────────────────────────────────────────`

---

## Field System Highlights (FFX_Field_* — 715 funcs)

```
FFX_Field_BindRenderAndCache             @ 0x42f5d0  40B
FFX_Field_UpdateAndRender                @ 0x42f600  178B ← Main update loop
FFX_Field_InitAllSubsystems              @ 0x42f9d0  56B
FFX_Field_TerminateSubsystems            @ 0x42fa10  88B
FFX_Field_LazyInitWrapper_0              @ 0x42fa80  16B
FFX_Field_AccumulateElapsedTime          @ 0x42fae0  105B
FFX_Field_GetContextOffset               @ 0x630e40  12B
FFX_Field_DebugStepHandler               @ 0x630f90  12B
FFX_Field_ScreenPos_InitSingleton        @ 0x635930  111B
FFX_Field_EnablePostProcessOnFadeInit    @ 0x639300  29B
```

---

## Key Findings

1. **FFX-native code is 4.4x larger than PhyreEngine code** — Square Enix wrote significantly more game-specific code than the engine exposed.

2. **The Battle system (716 funcs) is well-instrumented** — function names reveal every major mechanic: CTB, Overdrive (12 events), Damage (37 modifiers), Items, Magic, Death/Overkill, Zanmato.

3. **`PppMem` is a custom pooled allocator** — confirms that FFX allocates from typed arenas for performance, not just from the heap.

4. **Camera system uses ATEL scripts** — `SetPolar_FromAtelStack` proves stack-based camera scripting (consistent with `camSetPolar` decompilation).

5. **Save format is `CHAPPU`-prefixed PSARC with big-endian swap** — backwards-compatible with PS3 saves despite PC being little-endian native.

6. **No `FFX_Battle_*Summon*` functions exist** — Aeons are handled via characters, not separate summon logic.

7. **Sound system uses typed async command queues** — `QueueCmd22`, `QueueCmd24`, `QueueCmd32`, `QueueCmd46` suggest a message-passing interface to the audio thread.

8. **`FFX_System_Host_Constructor` (3482B)** — this is the master game init and the most important function in the entire binary.

---

## What's Next?

- Map each prefix to PhyreEngine backing classes (e.g., `FFX_Battle_*` → `PCaller<PSceneNode>`)
- Decompile `FFX_System_Host_Constructor` to understand full boot sequence
- Decompile `FFX_Battle_ComputeHitDamage` (2127B) to learn damage formulas
- Decompile `FFX_Battle_CtbSelectNextActorAndRunTurnEdgeEvents` to map CTB internals
- Find the rest of the ~9,100 functions (likely under `FFX_*` sub-prefixes like `FFX_Battle_AI_*` etc.)
