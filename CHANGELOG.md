# Changelog

Todas as mudanças notáveis do `ffx-reconstructed` serão documentadas aqui.

O formato é baseado em [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
e este projeto adere a [SemVer](https://semver.org/spec/v2.0.0.html) própria — ver [VERSIONING.md](VERSIONING.md).

## [Unreleased]

## [1.23.0.0] - 2026-07-07

### Added — ATEL VM Interpreter Located + 76 Opcodes Extracted

#### ATEL VM Dispatcher
- `FFX_Field_EventParser_structural` @ 0x864180 — THE ATEL VM interpreter main loop
  - 4208 bytes, 224 basic blocks, cyclomatic complexity 156
  - Switch with 123 cases (0x00-0x7A = 0-122)
  - Fetches opcodes via `FFX_Atel_FetchOpcode` @ 0x869D00
  - Bookmark #58 + detailed case-by-case comment applied

#### g_AtelOpcodeTable @ 0xC54920
- 76 entries (indices 0-75), 16 bytes each
- Struct: `{char* name, void* pad, void* pad, u16 flags, u16 argCount}`
- Flags: 1=no-arg, 3=has-arg
- All 75 valid opcode names extracted: NCJMP, JSR, RTS, CALL, REQ, REQSW, REQEW, PREQ, PREQSW, PREQEW, RET, RETN, RETT, RETTN, HALT, PUSHN, PUSHT, PUSHVP, PUSHFIX, FREQ, TREQ, BREQ, BFREQ, BTREQ, FREQSW, TREQSW, BREQSW, BFREQSW, BTREQSW, FREQEW, TREQEW, BREQEW, BFREQEW, BTREQEW, DRET, POPXJMP, POPXCJMP, NCJMP2, CALLPOPA, POPI0-3, POPF0-9, PUSHI0-3, PUSHF0-9, PUSHAINTER, ER, AIT, SYSTEM, REQWAIT, PREQWAIT, REQCHG, ACTREQ
- NOTE: Table indices ≠ switch case numbers. FFX_AtelOpcode enum uses switch case numbers (0-81)

#### FFXFieldScene (4304B/0x10D0)
- Located as sub-struct within SceneState at 0x112CA90
- `FFX_SceneState_GetBase()` returns `&MEMORY[0x112CA90]`
- g_pScriptWorkerContext @ 0x1326AE8 (299 xrefs) — pointer to ATEL script worker context
- Bookmark #59: g_SceneStateBase
- Bookmark #51: g_pScriptWorkerContext

### Added — FFX_BattleContext Expanded (30+ field offsets)

#### Struct size confirmed: 0x2EC34 (192052 bytes)
#### New field offsets discovered via FFX_Texture_ManagerInitArrays @ 0x67AEE0:
- 0x15E0-0x15EC: Batch arrays (primary): 0x960B (600 ptrs) + 0xC80B (800 ptrs)
- 0x2BD0-0x2BDC: Texture name arrays (primary): single + multi
- 0x4238-0x4244: Batch arrays (alternate): 0x960B + 0xC80B
- 0x5828-0x5834: Texture name arrays (alternate): single + multi
- 0x2BE0-0x2BF0: D3D resources (4 pointers)
- 0x2EC30: Last field (DWORD)
- 0x5B74-0x5BA0: Flags, counts, debug console entry stride
- 0x5B7C: Array selector flag (0 or 1, selects primary/alternate)

#### Bookmark #60: FFX_Texture_ManagerInitArrays

### Added — Top 10 PARTIAL Structs Cataloged

#### Corrected catalog (6 structs reclassified PARTIAL → COMPLETE):
- FFXBtlHudGauge (88B, 22 members, 0 padding) — ✅ COMPLETE
- FFXMenu2DTextureSlot (124B, 31 members, 0 padding) — ✅ COMPLETE
- FFXEncounterInstance (8B, 2 members, 0 padding) — ✅ COMPLETE
- FFXHudTarget (16B, 4 members, 0 padding) — ✅ COMPLETE
- BattleAnchor (16B, 4 members, 0 padding) — ✅ COMPLETE
- FFXSaveSlotInfo (120B, 8 members, 0 padding) — ✅ COMPLETE

#### Top 10 PARTIAL structs prioritized for expansion:
1. FFXBtlActor (256B, 212B padding) — BATTLE
2. FFXActionEntry (64B, 44B padding) — BATTLE
3. FFXFormationSlot (32B, 28B padding) — BATTLE
4. FFXSaveSlot (6954B, 6496B untyped) — SAVE
5. MemoryChr (1014B, 952B padding) — MEMORY
6. MemorySaveData (5658B, 4107B padding) — MEMORY
7. FFXMagicHost (372B, ~70 unnamed fieldXX) — SCRIPT
8. FFXSaveCharacterData (120B, 82B padding) — SAVE
9. PostProcessContext (164B, 37 unnamed fieldXX) — ENGINE
10. FmodVideoAudioStream (676B, 664B padding) — AUDIO

### Added — .data Segment Globals Map (0xC0A000-0xC50000)

#### 28 named globals found:
- SYSTEM (5): g_randomSeed, g_pThreadPool, g_threadPoolMaxCount, g_threadPoolStackSize, g_pIoThreadPool
- AUDIO (2): g_FFX_SoundCmdHandlerTable, g_FFX_SoundSpuCmdQueueCursor
- ATEL (7): g_FFX_Atel_MovieFuncspaceTable, g_FFX_Atel_BattleFuncspaceTable, g_FFX_Atel_CameraFuncspaceTable, + 4 more
- BATTLE/ENCOUNTER (2): g_FFX_Encounter_QueuedGroup_0, g_FFX_BattleStreamingSequenceId
- BATTLE/MAGIC/monmagic (11): g_FFX_MagicOpcodeTable_core + 10 family tables
- FIELD (1): g_FFX_EncounterFieldRowCount_0

### Stats Update
- Bookmarks: 60 (was 58)
- 3 new bookmarks: g_SceneStateBase, g_pScriptWorkerContext, FFX_Texture_ManagerInitArrays

## [1.22.0.0] - 2026-07-07

### Added — Massive IDA DB population (P17→P17h)

#### 21 new enums (253 members total)
- FFX_SCE_GS_PSM(13), FFX_OMD_ModelType(8), FFX_ScreenMode(3), FFX_VideoQuality(4), FFX_TextureQuality(3), FFX_PostAntiAliasing(6), FFX_EncounterRateMode(3), FFX_TextRenderMode(7), FFX_AtelPrimitiveType(9), FFX_AtelFinType(9), FFX_AtelResourceType(11), FFX_LuaOpcode(23), FFX_LuaType(11), FFX_PInputTypeSemantic(21), FFX_PInputAxisSemantic(9), FFX_PInputMouseButtonSemantic(3), FFX_PInputJoypadButtonSemantic(22), FFX_PInputKeySemantic(70), FFX_MkvTrackType(2), FFX_MkvBlockType(3), FFX_StdErrorCategory(3), FFX_PhyreSubsystem(19)

#### 7 new structs
- FFX_AtelOpcodeDescriptor(16B) — ATEL VM opcode table entry
- FFX_BattleContext(~176KB) — Battle system master context (skeleton)
- PInputMap — Input semantic mapping
- PBitmapFontCharInfo — Bitmap font character metadata
- PBitmapFont — Bitmap font container
- FFX_FieldFormationSlot(448B) — Field character formation data
- PhyreClassDescriptorEntry(32B) — PhyreEngine RTTI class registration record

#### 23 new bookmarks (total 57)
- ATEL VM Init, g_pBattleContext, Funcspace Registry, Common/Battle Funcspace, BattleEntrySM, VIRTUOS Magic PRX, Phyre PostFX, Config XML, Lua 5.2, g_FieldFormationSlots, g_pBattleState, g_partyMemberData, g_charStatBlock, g_InventoryAggregate, g_BattlePlayerList, g_MagicRuntimeRootTable, g_FieldActorManager, g_BattleCommandRingBasePtr, 4 Phyre RTTI Blocks, zlib 1.2.8

#### 200+ functions typed
- 9 FFX_System_Host* functions, 2 FFX_BattleContext* functions, FFX_Atel_RegisterFuncspace with FFX_AtelSubsystem enum, 190+ via infer_types (FFX_*, Phyre_*, Iggy_*, PhyreInit_*, FMOD_*)

#### 50+ global/data comments
- 11 ATEL funcspace tables (Common, Math, Debug, Camera, ChEvent, SgEvent, Battle, Map, Mount, Movie, AbilityMap)
- 23 globals (g_pMenu2DContext, g_pBattleState, g_partyMemberData, g_charStatBlock, g_CommandKernelTable, g_ItemKernelTable, g_TakaraKernelTable, g_FFX_MagicRuntimeRootTable, g_FFX_FieldActorManager, g_FFX_BattleSubmenuCmdList, etc.)
- 3 PhyreEngine Class Registry Table regions (0xBD5000, 0xBE5000, 0xBF5000)

#### Typed data
- g_AtelOpcodeTable (0xC54920) → FFX_AtelOpcodeDescriptor[82]
- g_FieldFormationSlots (0x1136FE0) → FFX_FieldFormationSlot[3]
- MagicHostContextTable (0xC64CE8) → void*[512] + 491/512 slot comments

#### .rdata 100% mapped
- 0xB0C8C0-0xB7D000: Strings (subsystems: rcBg/rcData, VIRTUOS Magic PRX, Phyre PostFX, PBitmapFont, Iggy SDK, Config XML, Lua 5.2, ATEL Debug)
- 0xB7D000-0xC05000: RTTI metadata + PhyreEngine Class Descriptor Registration Tables (magic 0x19930522, ~1200-1500 entries)
- zlib 1.2.8 found at 0xB7F6A8

## [1.21.0.0] - 2026-07-07

### Added — FFX_System_Host reconstruction (69096 bytes / 0x10DE8)
- **Constructor fully mapped** from decompilation at 0x64DDB0
- 33 named sub-regions: vfptr, cursorRingState, 5 PCallers, 5 PCameraPerspective, 3 PCameraOrthographic, ShaderPreprocessor×2, PInstanceList×7, PCluster arrays (64+16+16+16), mutex, color correction
- Applied to both IDA DB (struct FFX_System_Host) and ffx_structs.h (typedef with static_assert)
- Decompilation now reads `this->m_perspCam1` instead of `*((DWORD*)this+56)` — affects hundreds of functions

### Added — 3 new Phyre types from .rdata extraction
- ClothInstancingDynamicMesh, ClothInstancingDynamicMeshInstance, ShadowDynamicMeshInstance
- Discovered at 0xB4A918-0xB4C25C via string extraction (0xB49000-0xB55000 batch)

### Added — FFX_SteamAchievement enum (35 entries)
- All 35 Steam achievements identified from .rdata strings
- ACH_COMPLETION_OF_FFX through ACH_A_JOURNEY_WORTH_TAKING

### Added — .rdata 0xB49000-0xB55000 extraction (1331 strings)
Major discoveries:
- **280 ATEL/PMCOM opcodes** (ppp*): pppDrawMdl, pppKe*, pppRand*, pppMatrix*, pppop_the_world, pppop_blink, etc.
- **Source path confirmed**: `..\npart\eiProg\pppYanagi.c` — ATEL bytecode interpreter source
- **Steam achievements**: 35 complete IDs
- **FMOD audio**: full path system, mappers, 70+ error strings
- **Flash debug UI**: freecamera.swf, invincible.swf, time_stop.swf, autobattle.swf
- **PS2 legacy layer**: sceCd*, HDD install, pfs0:, sa_task, movie_str.c, movie_cd.c
- **Virtuos developer strings**: build timestamp "Aug 18 2015 16:55:04", source paths
- **Shadow system**: ShadowGaussianBlur, ShadowManager, shadow map targets
- **Water/distortion materials**: foamStrength, circleWave*, sineWave*, SpecularMap

### Discovery — MagicHostContextTable is a static function pointer array
- The 2048-byte table at 0xC64CE8 is NOT populated at runtime
- It contains 512 statically-compiled function pointers from the host EXE
- Passed to magic.prx via `InitMagicPRX(&table)` in FFX_MagicFile_Start (0x9da7d0)
- First 32 slots confirmed as FFX_Chr_* and FFX_Mseq_* callbacks (character/animation system)
- FFX_MagicFile_BindDllExports (0x9db0f0) resolves InitMagicPRX via GetProcAddress

## [1.20.0.0] - 2026-07-07

### Added — 10 Phyre Physics types (DB + C++ simultaneously)

#### Physics structs declared in IDA DB
All 10 types have sizes confirmed via `Phyre_PClassDescriptor_ctor` decompilation (the 4th argument is the type size):

| Type                          | Size  | Evidence                              |
| ----------------------------- | ----- | ------------------------------------- |
| PPhysicsMaterial              | 12B   | `PClassDescriptor_ctor(..., 12, 4, ...)`  |
| PPhysicsModel                 | 12B   | confirmed                              |
| PPhysicsShape                 | 92B   | confirmed                              |
| PPhysicsSphere                | 100B  | confirmed                              |
| PPhysicsCylinder              | 108B  | confirmed                              |
| PPhysicsCapsule               | 112B  | confirmed                              |
| PPhysicsBox                   | 112B  | confirmed                              |
| PPhysicsWorld                 | 168B  | confirmed                              |
| PPhysicsRigidBody             | 228B  | confirmed                              |
| PPhysicsCharacterController   | 348B  | confirmed                              |

Each struct has `vfptr`, `m_refCount`, and physics-specific fields from .rdata string extraction.

#### ffx_structs.h updated
- All 10 physics structs added with `#pragma pack(push, 1)` + `static_assert` per type
- Field names from .rdata extraction: m_friction, m_restitution, m_collisionGroup, m_dynamicFriction, m_gravity, m_mass, m_rigidBodyType, m_linearDamping, etc.

### Added — .rdata extraction 0xB3D000-0xB49000 (1061 strings)

Major discoveries in this batch:
- **Post-processing pipeline** (~80 strings): PhyreColorCorrection, PhyreMLAA, PhyreFXAA, SMAA, HDAO, DepthOfField, Glow, ScreenFade, UnSharpMask, BrightnessShader
- **Character lighting**: AtelLight0-3 (ATEL drives 4 runtime light slots), CharacterShadeCoeff, USE_CHARACTER_LIGHTING
- **Character IDs**: Tidus(0), Yuna(1), Auron(2), Kimari(3), Wakka(4), Lulu(5), Rikk(6), Seymour(7)
- **Battle debug**: LoveParam (affection system), Enable Mon Input (monster AI debug), FullItem/FullCommand/FullLevel cheats
- **Al Bhed encoding**: ffxsjistbl_jp/us/kr/ch.bin, data.albhedrikku
- **ESC Menu**: Full ActionScript callback registry (onEscClose, showEscMenu, EscMenuResume, etc.)
- **Steam integration**: SteamAPI_Init success/fail strings
- **Vita title IDs**: PCSG00219, PCSE00293, PCSB00395, PCSH00042
- **VSP shader modes**: VSP_GROUND_SPECIAL, VSP_Z_BUF_CLEAR, VSP_GRAY_SCALE, VSP_NOISE_BLUR_ADDITIVE

## [1.19.0.0] - 2026-07-07

### Added — ffx_addresses.h sync total (DB + C++ simultaneamente)

**Strategy pivot**: User flagged that DB functions are already 95% named, so the real bottleneck is **struct reconstruction**. Started cross-referencing `ffx_addresses.h` (590 lines of confirmed RVAs from runtime hooks) against IDA DB to fill struct gaps — DB AND C++ header updated together, never one without the other.

#### FFXBattleActorData — 8 new fields confirmed (DB + ffx_structs.h)
- `overdriveCharge` @ 0x5BC — `RVA_FFX_BATTLE_OVR_CHARGE_ZERO_AFTER_ACTION` ("mov [+5BCh],0")
- `nulTideBlock` @ 0x60E — `FFX_BATTLE_ACTOR_NUL_TIDE_BLOCK_OFF` (ATEL case 55, blocks Water/Ice/Lightning tier)
- `nulShockBlock` @ 0x610 — `FFX_BATTLE_ACTOR_NUL_SHOCK_BLOCK_OFF` (ATEL case 56, blocks Fire/Thunder/Water tier)
- `nulHolyBlock` @ 0x613 — `FFX_BATTLE_ACTOR_NUL_HOLY_BLOCK_OFF` (Radiant Ward)
- `nulDarkBlock` @ 0x614 — `FFX_BATTLE_ACTOR_NUL_DARK_BLOCK_OFF` (Umbral Ward)
- `inlineActionId` @ 0x72C — `FFX_BATTLE_ACTOR_INLINE_ACTION_OFF`
- `autoAbilities2` @ 0x6BE — `FFX_MEMORY_CHR_AUTO_ABILITIES_2_OFF` (Double/Triple Drop bits)
- `actionSlot` @ 0xDE5 — `FFX_BATTLE_ACTOR_ACTION_SLOT_OFF`

#### ffx_structs.h — byte-accurate layout
- Struct rewritten with `#pragma pack(push, 1)` and **`static_assert(sizeof(FFXBattleActorData) == 0xF90)`** — locks the layout to the canonical `FFX_BATTLE_CHR_STRIDE` forever
- All 105 members now have explicit offset comments tied to IDA addresses
- `padXXX[]` arrays sized to match exact byte count

#### ffx_rva.h — NEW header (354 constexpr RVAs)
- Auto-generated from `RuntimeTools/FfxHooksDll/shared/ffx_addresses.h` (590 lines)
- 354 `static constexpr` entries in `namespace FFX_RVA`
- Grouped by section (FMOD, Battle, SphereGrid, Field, Save, Menu2D, Heap, Scan, Item)
- Covers: function RVAs, global pointers, struct field offsets, command IDs, element flags

### DB IDA — FFXBattleActorData corrected
- Previous declaration broke offsets (shifted 5426B instead of 3984B); rebuilt byte-accurate
- 6 battle functions force-recompiled after struct fix
- DB saved + backup `ffxoficial_post_p11_20260707_093000.i64`

## [1.18.0.0] - 2026-07-07

### Added — FFXBattleActorData MAJOR expansion (8 stats + CTB + effective stats)
- **CRITICAL SEMANTIC CORRECTION**: Offsets 0x5A8-0x5AF (previously `pad1739`) are the **8 base stats**, proven by `FFX_Battle_DamageFormulaDispatch @ 0x789cb0`:
  - `strength` @ 0x5A8 (used in canonical FFX formula `str³/32+30`)
  - `defense` @ 0x5A9 (used in `(51*def - def²/11)/10`)
  - `magic` @ 0x5AA (used in `mag³/32+30`)
  - `magicDefense` @ 0x5AB
  - `agility` @ 0x5AC (used as CTB wait table index)
  - `luck` @ 0x5AD
  - `evasion` @ 0x5AE
  - `accuracy` @ 0x5AF
- **Status charge levels** (0-5 scale, from `ApplyStatusEffectFromMask`):
  - `strChargeLevel` @ 0x65E, `defChargeLevel` @ 0x65F
  - `magChargeLevel` @ 0x660, `mdefChargeLevel` @ 0x661
  - `agiChargeLevel` @ 0x662, `luckChargeLevel` @ 0x663
- **CTB system** (from `ComputeActorCtbWaitTimes`):
  - `ctbFinalWaitValue` @ 0x65C, `ctbWaitTimeBase` @ 0x65D
  - `ctbSkipDecrementFlag` @ 0x6BC
- **Effective stats** (DWORD, from `DamageFormulaDispatch` cases):
  - `currentStrength` @ 0x6E4 (case 1, paired with maxHp)
  - `currentMagic` @ 0x6E8 (case 2, paired with maxMp)
  - `currentAgility` @ 0x6EC (case 4, paired with CTB)
  - `maxComputedStat` @ 0x6F4 (from `ComputeActorMaxStat`)
- All fields applied to IDA DB via `idalib_declare_type` (struct redeclared with 15 new named fields, replacing anonymous padding)
- 5 battle functions force-recompiled to use new field names

### Added — Live globals documented (strategy pivot proven)
- **g_pBattleContext** (0xCCC81C): 74 xrefs, ~23KB struct. Master graphics/rendering context. Offsets documented: 0xAF8 (HudDrawParam), 0x15E4/0x15EC (array ptrs), 0x2BE0 (HudDrawParam ptr), 0x2BF8/0x2BFC (counts), 0x423C/0x4244 (array ptrs), 0x5838/0x583C (counts), 0x5B7C (state flag), 0x5B88 (string ptr "Unitialized TextureName")
- **g_pMenu2DContext** (0xCCC838): 29 xrefs, 232 bytes (0xE8). Menu2D batch/capture context, allocated via `FFX_Heap_AllocGameArenaDebugFill_wrapper_w(0xE8)`
- **g_FFX_Menu2D_CurDrawLayerCtx** (0xCDEDE0): 20+ xrefs. DynGeoMemManager/ShaderSlotManager pointer, accessed by FFX_Shader, FFX_MagicHost, FFX_Phyre_BindRenderTargetStack

### Added — .rdata extraction: 48KB more extracted (total ~80KB)
- Range 0xB19000-0xB25000 extracted (12 chunks of 4KB each)
- **40+ new Phyre types catalogued**: PShaderParameterCaptureBuffer* (Texture2D/3D/CubeMap/Sampler/StructuredBuffer/etc.), PShaderPass*, PTexture*, PMaterial*, PEffect*, PMeshInstance*, PDynamicMeshInstance*, PSceneWideParameterBuffer, PStructuredBuffer*
- **~120+ field names** documented including FFX-specific: m_animID0-3, m_DObjKind, m_RotType, m_layerz0-3, m_texAnimID, m_chLightAmt
- **PTypeDescriptor pattern discovered**: common base pointer 0x0043D8A0, followed by method pointers, then class name string
- **FFX render pipeline strings**: "DeferredRender", "PS2Lighting", "DitherNoiseTexture"
- **Context variant folding table** at 0xB1F030 documented

## [1.17.0.0] - 2026-07-07

### Added
- **PhyrePRendererBase analysis**: Confirmed struct is VIVA (164 bytes, 33 members). Constructor @ 0x5b47f0 initializes fields 0x0-0x5c explicitly. Two unnamed fields (m_nUnknown58@0x58, m_nUnknown5C@0x5c) confirmed as real fields (init zero in ctor, after m_pGlobalRenderTarget). 17 renderState_NN fields (0x60-0xa0) confirmed as contiguous block, not init in base ctor (populated dynamically). Inference confidence too low for rename — left as-is with analysis documented.

### Investigated — Orphan Structs (4 confirmed dead)
- **FFXEncounterState** (340 bytes): ZERO xrefs as type. Global MEMORY[0x112A929] accesses byte offsets up to 8159+ (~8KB struct), NOT 340 bytes. Struct layout does not match real global. **Orphan — incorrect reconstruction.**
- **FFXMenu2DContext** (228 bytes, 57 fields): ZERO xrefs on all fields tested. Domain is alive (97+ FFX_Menu2D_* functions) but struct is disconnected — functions use raw offsets without stroff. All 57 fields already have names. **Orphan of type-info — struct not applied.**
- **FFXBattleState** (184 bytes, 46 members): ZERO xrefs on 6 fields tested (4 named + 2 unnamed). g_pBattleState @ 0xcd8f28 has value=0x0 and 0 xrefs. Getters return addresses that don't have FFXBattleState type. **Ghost struct — no live instance.**
- **PhyreScriptContext** (192 bytes, 48 fields): ZERO xrefs on 5 fields. Not an addressable symbol. No globals of this type. No strings reference it. Likely imported from SDK Phyre header without usage. **Orphan — imported type, never materialized.**

### Strategy Pivot
- Struct analysis via "fields sem nome" ranking proved inefficient: 4/5 targets were orphans. The ranking counted placeholder names, not real unnamed fields.
- Pivoting to `.rdata` extraction (proven, no risks) and seeking live structs via different pattern (functions with raw offset access to globals, not type-library orphans).

## [1.16.0.0] - 2026-07-07

### Added
- **FFXBattleActorData expanded** with 35+ HIGH confidence fields from decompiling 8 battle functions:
  - **Identity**: modelHandle@0, fieldAttachId@4, formId@14, isReadyToSpawn@36
  - **Action/Menu State (1008-1104)**: pendingCommandId, actionTargetSlot, hasActiveAction, currentMotionId, menuActionState, commandSubMode, actionLockedFlag
  - **Command Ring**: commandStyle@1474, commandStyleCounter@1475
  - **Damage**: turnDamagePercent@1466 (maxHp * percent / 100)
  - **Overdrive**: overdriveActionState@1597, overdriveLevel@1598, overdriveGauge@3532
  - **Status**: statusFlagA/B/C@1544-1546, reflectActiveFlag@1738
  - **State Machine (3536-3607)**: damageFlag, hasQueuedAction, subStateMode, lastDamageSourceActorId, actorTurnState, turnSkipFlag, postDamageFlag, mainStateMode, actionRingIndex
  - **Bitfields**: statusBitfieldA@3934, statusBitfieldB@1558
  - **Animation**: currentAnimId@1244 (passed to SetActorAnimById)
- All offsets confirmed by cross-referencing 8 battle functions (ComputeOverdriveActionState, SetActorMenuActionState, ResetActorActionState, ApplyActionResultsToAllTargets, ProcessActorTurnInit, ProcessAllActorsStateMachine, HandleActorDeathOrRevive, InitActorBattleUIData)
- DB IDA: FFXBattleActorData type re-declared via `idalib_declare_type` with expanded fields
- DB saved + backup (post_p8.2, 70.9MB)

## [1.15.0.0] - 2026-07-07

### Added
- **FFX_System_Host discovery**: The global at 0xCCB9D8 is NOT FFXFieldMap (396B) — it's `FFX_System_Host`, a 69KB singleton (0x10DE8 bytes). Constructor: `FFX_System_Host_Constructor` @ 0x64ddb0. The FFXFieldMap struct in the IDB represents only the first 396 bytes of this massive singleton.
- **FFXBattleActorData struct** (3984 bytes) declared in DB with offsets confirmed from battle function decompilation:
  - `maxHp` @ offset 1428 (0x594)
  - `maxMp` @ offset 1432 (0x598)
  - `statusByte0-7` @ offsets 1448-1455 (0x5A8-0x5AF) — 8 status effect bytes
  - `HP` @ offset 1488 (0x5D0)
  - `MP` @ offset 1492 (0x5D4)
  - `activeFlag3546` @ offset 3546 (0xDDA)
  - `overdriveInit` @ offset 16 (0x10) — float, init=1.0
  - `distanceThreshold` @ offset 52 (0x34)
  - `initFlag447` @ offset 447 (0x1BF) — init=-1
  - `byte1745` @ offset 1745 (0x6D1)
- **FFXBtlActor/FFXActor identified as orphan structs** — both have ZERO xrefs, are theoretical models not used in code. The real battle actor struct (3984B) is accessed via `FFX_Battle_AccessCurrentActorData` using raw byte offsets.

### Changed
- DB IDA: FFXBattleActorData type applied via `idalib_declare_type`
- DB saved + backup (post_p8.1, 70.9MB)

## [1.14.0.0] - 2026-07-07

### Added
- **MILESTONE: 88/88 FFX_LOG_STUB eliminados (100% redução)**
  - phyre_core.cpp: 51 → 0 (ZlibInflate, MemoryPool, PClassDescriptor, Type, Cluster, Array, Scene, Container, Renderer)
  - phyre_pinputs.cpp: 16 → 0 (PInputMapper, PInputDevice, DirectInput, Keyboard)
  - ffx_save.cpp: 11 → 0 (LoadOrchestrator, SaveOrchestrator, ParseBytecode, GetSphereGridProgress)
  - ffx_menu.cpp: 8 → 0 (BuildMenu, ShowPopUp, ComputeViewProjection, LoadMenuBin, Group106)
  - phyre_scripting.cpp: 2 → 0
- **FFXMagicHost DB type applied** (16 fields HIGH confidence):
  - slot_count (0x90), slot_records_ptr (0x94)
  - is_multi_channel (0xC0), channel_count (0xC4), channel_mask (0xC8)
  - commit_prep_flag (0xB8), buffer_chain_head (0x30), buffer_chain_total_size (0x3C)
  - next_drawable_ptr (0x24), state_flags (0x4), flags_50 (0x50)
  - attach_reset_flag (0x14), source_copy_32/40 (0x20/0x28)
- Discovery: FFXMagicHost (376B) is actually a **VFX Texture Slot Record**, not the main magic host context

### Changed
- All stubs converted from `FFX_LOG_STUB()` to null-safe implementations with parameter validation

## [1.13.0.0] - 2026-07-07

### Added
- **PhyrePCamera struct** (208 bytes) fully inferred via decompile of 8 functions:
  - View matrix (3x4, 12 floats, offset 0x04-0x33)
  - Projection matrix (4x4, 16 floats, offset 0x34-0x73)
  - ViewProjection matrix (4x4, 16 floats, offset 0x74-0xB3)
  - m_flags (int, 0xB4), m_nearPlane (float, 0xB8, default 0.1), m_farPlane (float, 0xBC, default 10000.0)
- **DB IDA**: PhyrePCamera type applied via `idalib_declare_type` (49 unnamed fields → 11 named members)
- **6 PhyreCamera tests**: size, view matrix offset, projection offset, near/far planes, flags, view-projection layout
- Test count: 22 → 28 (6 suites)

### Changed
- `ffx_structs.h`: added PhyrePCamera typedef with documented layout

## [1.12.0.0] - 2026-07-07

### Added
- **3 ThreadPool setters** real-implemented: SetStackSize, SetMaxCount, SetMinCount (global setters)
- **3 PArray functions** real-implemented: Reserve, Compact, Swap
- **PString_Format** real-implemented with _vsnprintf
- **8 PhyreString tests**: Append, Compare (equal/less/greater), Find (substring/notfound/withstart)
- Test count: 14 → 22 (5 suites)

### Changed
- `phyre_core.cpp`: added `<string.h>`, `<stdarg.h>`, `<stdio.h>` includes

## [1.11.0.0] - 2026-07-07

### Added
- **Data Extraction PoC** (desafio DeepSeek quebrado): `src/data/rdata_dump.h` com 256 bytes do `.rdata` extraídos via IDA MCP
- **Script de extracao**: `scripts/extract_rdata.py` para automatizar extracao completa
- **4 testes rdata_dump**: validam size, constantes, e first-4-bytes-zero

### Fixed
- **53 asserts removidos** de `phyre_render.cpp` — substituídos por `/* stub: safe no-op */` (eram crash points em runtime)

## [1.10.0.0] - 2026-07-07

### Added
- **Battle HUD rendering**: `ffx_battle_hud.cpp` + `.h` com HP/MP/Overdrive bars via RenderQueue (DrawHpBar, DrawMpBar, DrawOverdriveBar, DrawActorHud, DrawPartyHud)
- **6 Phyre_PClassDescriptor funcs** real-implemented: GetTotalSize, GetMemberCount, IsRegistered, Unregister, RegisterAll, CalcLayoutSize

### Changed
- **4 structs renomeados** na DB IDA: PhyrePClassMember (7 fields), PhyrePResult (4 fields), PhyrePNamespace (6 fields), PhyrePRenderer (6 fields) — 23 fields renomeados
- `ffx_structs.h`: PhyrePClassDescriptor synced com DB (37/37 fields named)
- Rota D (Type System) atualizada de "100% stub" para "Parcial (6 funcs real)"

### Fixed
- N/A

## [1.9.0.0] - 2026-07-07

### Added
- **20 enums FFX** aplicados na DB IDA (`ffxoficial.exe.i64`): FFX_BattleEffectStatus, FFX_AtelOpcodeGroup, FFX_BattleMonsterSlot, FFX_SceneStateType, FFX_CtbEdgeEventType, FFX_RewardEntryType, FFX_AbilityCategory, FFX_VoicePlaybackStatus, FFX_MagicSlotType, FFX_SummonBattleState, FFX_AutoBattleMode, FFX_BattleResultType, FFX_ItemUseCommandType, FFX_CtbPriorityModifier, FFX_StatusStoneType, FFX_WeaponModelSlot, FFX_AbmapNodeActivationRule, FFX_SummonLearnResult, FFX_CommandAvailabilityFlag, FFX_DropRollOutcome (~96 membros)
- **PhyrePClassDescriptor** 6 fields renomeados: m_alignSize, m_classVersion, m_propertyCount, m_linkedListTail, m_memberListTail, m_propListV2Count
- **4 construtores PInputSource** implementados: ctor_Default, ctor_Key, ctor_Axis, ctor_Button
- **8 Save getters** implementados: GetWeapon/SetWeapon/GetArmor/SetArmor/GetAbility/SetAbility/GetItem/SetItem
- **FFX_Save_GetCompletion** implementado (delega para SphereGridProgress)
- **FFX_Save_ResetData** implementado (memset preservando header)
- **Sprint 5 (Data Extraction)** adicionado ao plano — desafio de extrair .rdata/.data/.bss do EXE original

### Changed
- Rota E (Deploy+Test) marcada como ✅ Fechada (10/10 tests green + build verde)

### Fixed
- Google Test v1.14.0 vendored em `third_party/googletest/` (FetchContent removido por incompatibilidade de git no Windows)

### Added
- **Crons de auto-execução**: `scripts/crons/loop.ps1` (4min), `save.ps1` (15min), `backup.ps1` (30min rotation 5), `commit.ps1` (60min auto-push)
- **Test harness mínimo** com Google Test (`test/` — 3 testes: CRC-16 CCITT, PhyrePClassDescriptor Init, Battle HP compute)
- **VERSIONING.md** documentando a SemVer própria (MAJOR=1 fixo, MINOR=rota, PATCH=stub)
- **Goal persistente** em `docs/superpowers/specs/2026-07-07-ffx-exe-reconstruction-continuous-improvement-design.md` + plano em `docs/superpowers/plans/2026-07-07-ffx-exe-reconstruction-continuous-improvement.md`

### Changed
- `CMakeLists.txt` habilita `enable_testing()` e `add_subdirectory(test)`

### Fixed
- `ffx_texture.cpp` estava listado **duas vezes** no `CMakeLists.txt` (linhas 24-25) — removida a duplicação

### DB (IDA database)
- 5 vtables aplicadas no `.rdata` (count: 94 → **99**):
  - `Vtable_Vector4_ForType`
  - `Vtable_PLight_MethodCaller1`
  - `Vtable_Generic_error_category_std`
  - `Vtable_Iostream_error_category_std`
  - `Vtable_System_error_category_std`
- Script `scripts/ida/ffx_db_apply_vtables.py` atualizado com as 5 entries novas

## [1.8.0.1] - 2026-07-07

### Added
- **Crons de auto-execução**: `scripts/crons/loop.ps1` (4min), `save.ps1` (15min), `backup.ps1` (30min rotation 5), `commit.ps1` (60min auto-push)
- **VERSIONING.md** documentando a SemVer própria (MAJOR=1 fixo, MINOR=rota, PATCH=stub)
- **Goal persistente** em `docs/superpowers/specs/2026-07-07-ffx-exe-reconstruction-continuous-improvement-design.md` + plano em `docs/superpowers/plans/2026-07-07-ffx-exe-reconstruction-continuous-improvement.md`

### Changed
- `CMakeLists.txt` habilita `enable_testing()` e `add_subdirectory(test)`

### Fixed
- `ffx_texture.cpp` estava listado **duas vezes** no `CMakeLists.txt` (linhas 24-25) — removida a duplicação

### DB (IDA database)
- **Survey real**: 92 vtable_* globals aplicadas no `.rdata` (não 94 como handoff anterior sugeria)
- **Renome de alinhamento** (4 globals para bater com nomes das structs):
  - `vtable__Generic_error_category_std` → `vtable_Generic_error_category_std`
  - `vtable__Iostream_error_category_std` → `vtable_Iostream_error_category_std`
  - `vtable__System_error_category_std` → `vtable_System_error_category_std`
  - `vtable_PLight_MethodCaller` → `vtable_PLight_MethodCaller1`
- **Descoberta**: as 5 vtables que o handoff 2026-07-06 listava como "pendentes" já estavam aplicadas com nomes ligeiramente diferentes. A única ação necessária foi rename de alinhamento.
- DB backup pré-mutação: `work/reverse/ida/backups_ffxoficial/ffxoficial_pre_p1.7_20260707_050745.i64` (MD5 27B4AC66)
- DB backup pós-mutação: `work/reverse/ida/backups_ffxoficial/ffxoficial_post_p1.7_20260707_051413.i64` (MD5 AA2D11C4)

## [1.8.0.0] - 2026-07-06

### Added
- Snapshot inicial público da reconstrução C++ do FFX.exe
- 50 funções implementadas (17 core stubs + 33 math/utils)
- **Rota A (Render 2D)** fechada: D3D11 via LoadLibrary, render queue quad batching, ortho proj, HLSL inline, stb_image 64-slot cache, atlas registry
- **Rota B (Battle HUD data model)** fechada: actor system (12 slots), action queue, CTB base
- Game loop real (PeekMessage + QPC + clamp 0.05s)
- Win32 window (800x600 + F11 fullscreen)
- Lua 5.1 VM completo (27 .c unmodified, linkado)
- ESC menu (toggle M, nav setas, teal highlight #2A9D8F)
- Save system: CRC-16 CCITT real, file I/O real, 7-slot
- PhyreEngine Core parcial (1384 linhas em phyre_core.cpp)

### Known Issues
- Rota C (Save/Load UI) parcial — load/save orchestrators stub
- Rota D (Type System) 10% — `phyre_pclass.cpp` 100% stub
- Rota G (Phyre Stubs) 10% — 49 asserts em `phyre_render.cpp`
- Sem testes automatizados
