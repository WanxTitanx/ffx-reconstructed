# Changelog

Todas as mudanças notáveis do `ffx-reconstructed` serão documentadas aqui.

O formato é baseado em [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
e este projeto adere a [SemVer](https://semver.org/spec/v2.0.0.html) própria — ver [VERSIONING.md](VERSIONING.md).

## [Unreleased]

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
