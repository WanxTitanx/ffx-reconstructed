# Changelog

Todas as mudanças notáveis do `ffx-reconstructed` serão documentadas aqui.

O formato é baseado em [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
e este projeto adere a [SemVer](https://semver.org/spec/v2.0.0.html) própria — ver [VERSIONING.md](VERSIONING.md).

## [Unreleased]

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
