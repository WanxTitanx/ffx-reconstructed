# Changelog

Todas as mudanças notáveis do `ffx-reconstructed` serão documentadas aqui.

O formato é baseado em [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
e este projeto adere a [SemVer](https://semver.org/spec/v2.0.0.html) própria — ver [VERSIONING.md](VERSIONING.md).

## [Unreleased]

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
