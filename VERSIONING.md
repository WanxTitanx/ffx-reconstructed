# Versionamento — FFX.EXE RECONSTRUCTION

Este projeto segue **SemVer própria** enquanto a reconstrução for parcial.

## Regra

- **MAJOR**: fixo em `1` até a reconstrução ser ~80% completa (Rotas F-G fechadas)
- **MINOR**: incrementa a cada **rota fechada** (A, B, C, D, E, F, G)
- **PATCH**: incrementa a cada **stub crítico fechado**, hotfix, ou quick win de DB

## Rotas (estado de referência)

| Rota | Descrição        | Estado |
| ---- | ---------------- | ------ |
| A    | Render 2D        | ✅ Fechada (estável ~95%) |
| B    | Battle HUD       | 🟡 Parcial (data model OK, visual 0%) |
| C    | Save/Load UI     | 🟡 Parcial (CRC+IO OK, orchestrators stub) |
| D    | Type System      | 🟡 Parcial (PhyrePClassDescriptor 6 funcs real, 26 stub) |
| E    | Deploy+Test      | ✅ Fechada (build verde + 10/10 tests green) |
| F    | Editor Preview   | ⏳ Pendente (escopo outro repo) |
| G    | Phyre Stubs      | 🟡 Parcial (49 asserts em phyre_render.cpp) |

## Histórico de versões

| Versão   | Data       | Mudança                                                                                 |
| -------- | ---------- | --------------------------------------------------------------------------------------- |
| v1.8.0.0 | 2026-07-06 | Snapshot inicial público (50 fns, 17 core stubs + 33 math). Rotas A/B fechadas.        |
| v1.8.0.1 | 2026-07-07 | P1 — test harness + 5 vtables aplicadas no .rdata + Versioning/Changelog + fix CMakeLists |
| v1.9.0.0 | 2026-07-07 | P2 — 20 enums FFX aplicados na DB IDA + PhyrePClassDescriptor 6 fields renomeados + 4 PInputSource ctors implementados + 8 Save getters + ResetData + GetCompletion + Rota E fechada (10/10 tests green) |
| v1.10.0.0 | 2026-07-07 | P3 — Battle HUD rendering (HP/MP/Overdrive bars) + 6 PClassDescriptor funcs real-implemented + 4 structs renomeados na DB (PhyrePClassMember, PhyrePResult, PhyrePNamespace, PhyrePRenderer) + ffx_structs.h synced |
| v1.11.0.0 | 2026-07-07 | P4 — 53 asserts removidos de phyre_render.cpp (safe no-op) + .rdata extraction PoC (desafio DeepSeek: IMPOSSIVEL -> POSSIVEL) + 4 testes rdata_dump |
| v1.12.0.0 | 2026-07-07 | P5 — 3 ThreadPool setters + PArray_Reserve/Compact/Swap + PString_Format + 8 testes PhyreString (22/22 total) |
| v1.13.0.0 | 2026-07-07 | P6 — PhyrePCamera struct inferred via decompile (49 fields → 3 matrizes + near/far) + DB type applied + 6 PhyreCamera tests (28/28 total) |
| v1.14.0.0 | 2026-07-07 | P7 — **88/88 FFX_LOG_STUB eliminados (100%)** + FFXMagicHost 16 fields HIGH confidence aplicados no DB (slot_count, slot_records_ptr, is_multi_channel, channel_count, channel_mask, commit_prep_flag, buffer_chain_head, next_drawable_ptr, state_flags) |
| v1.15.0.0 | 2026-07-07 | P8 — **FFX_System_Host discovery** (singleton 69KB, não FFXFieldMap 396B) + FFXBattleActorData struct (3984B) com offsets reais confirmados (HP@1488, maxHp@1428, status@1448-1455, activeFlag@3546) + FFXBtlActor/FFXActor identificados como structs órfãos sem xrefs |
| v1.16.0.0 | 2026-07-07 | P8.2 — FFXBattleActorData expandido com 35+ fields de ALTA confiança (modelHandle, hasActiveAction, menuActionState, actionLockedFlag, commandStyle, overdriveActionState, overdriveLevel, reflectActiveFlag, mainStateMode, subStateMode, actorTurnState, turnSkipFlag, actionRingIndex, statusBitfieldA, etc.) |
| v1.17.0.0 | 2026-07-07 | P9 — Struct analysis batch (5 subagentes paralelos): 4 orphans confirmados (FFXEncounterState, FFXMenu2DContext, FFXBattleState, PhyreScriptContext — todos zero xrefs) + PhyrePRendererBase confirmado vivo (2 fields unnamed, confiança baixa) + strategy pivot para .rdata extraction |
| v1.18.0.0 | 2026-07-07 | P10 — FFXBattleActorData MAJOR expansion: 8 base stats nomeados (STR/DEF/MAG/MDEF/AGI/LUCK/EVA/ACC @ 0x5A8-0x5AF) + 6 charge levels + CTB fields + 4 effective stats DWORD + .rdata 48KB extraídos (40+ tipos Phyre) + 3 live globals documentados (g_pBattleContext 74 xrefs, g_pMenu2DContext 29 xrefs) |
| v1.19.0.0 | 2026-07-07 | P11 — **ffx_addresses.h sync total**: 8 novos campos confirmados em FFXBattleActorData (overdriveCharge@0x5BC, nulTideBlock@0x60E, nulShockBlock@0x610, nulHolyBlock@0x613, nulDarkBlock@0x614, inlineActionId@0x72C, autoAbilities2@0x6BE, actionSlot@0xDE5) + struct byte-accurato com `static_assert(sizeof==0xF90)` + **ffx_rva.h gerado** (354 constexpr RVA defines em namespace FFX_RVA, organizados por seção) |
| v1.20.0.0 | 2026-07-07 | P12 — **10 Phyre Physics types declarados** (DB + C++ simultaneamente): PPhysicsMaterial(12B), PPhysicsModel(12B), PPhysicsShape(92B), PPhysicsSphere(100B), PPhysicsCylinder(108B), PPhysicsCapsule(112B), PPhysicsBox(112B), PPhysicsWorld(168B), PPhysicsRigidBody(228B), PPhysicsCharacterController(348B) — tamanhos confirmados via PClassDescriptor_ctor no binário + .rdata extraction 0xB3D000-0xB49000 (1061 strings: post-processing pipeline, AtelLight0-3, character IDs, LoveParam, Al Bhed encoding, ESC Menu ActionScript, Steam integration, Vita title IDs) |

## Próximas metas

- **v1.9.0.0**: fechar **Rota C** (Save/Load UI completa) + DB boost (enums PhyreP* fields)
- **v1.10.0.0**: fechar **Rota B** (Battle HUD rendering) + **Rota D** inicial (PhyrePClassDescriptor ctor)
- **v1.11.0.0**: fechar **Rota G** (Phyre Stubs restantes)
- **v1.20.0.0**: fechar **Rota E** (Deploy+Test com CI)
- **v2.0.0.0**: reconstrução ~80% — MAJOR bump

## DB IDA canonica

`D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\ffxoficial.exe.i64`

**Snapshot 2026-07-07:**
- 47.435 funções totais
- 45.114 nomeadas (95,1%)
- 382 structs declaradas
- 65 enums
- 98 vtable structs
- 94 vtables aplicadas no `.rdata` (5 restantes para v1.8.0.1)

A DB **não** vai no repo (75MB binário). Apenas os scripts que a mutam vão em `scripts/ida/`.
| v1.21.0.0 | 2026-07-07 | P13+P14 — FFX_System_Host reconstruido (69096B, 33 sub-regions do construtor 0x64DDB0) + 3 tipos Phyre novos (ClothInstancing, ShadowDynamicMesh) + FFX_SteamAchievement enum (35 entries) + .rdata 0xB49000-0xB55000 (1331 strings: 280 ATEL/PMCOM opcodes, pppYanagi.c, FMOD, Flash debug UI, PS2 legacy) + MagicHostContextTable = static 512-fn-ptr array |
