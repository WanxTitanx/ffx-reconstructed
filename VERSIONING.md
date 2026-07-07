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
| D    | Type System      | 🟡 Parcial (phyre_pclass.cpp 100% stub) |
| E    | Deploy+Test      | ✅ Fechada (build verde + 10/10 tests green) |
| F    | Editor Preview   | ⏳ Pendente (escopo outro repo) |
| G    | Phyre Stubs      | 🟡 Parcial (49 asserts em phyre_render.cpp) |

## Histórico de versões

| Versão   | Data       | Mudança                                                                                 |
| -------- | ---------- | --------------------------------------------------------------------------------------- |
| v1.8.0.0 | 2026-07-06 | Snapshot inicial público (50 fns, 17 core stubs + 33 math). Rotas A/B fechadas.        |
| v1.8.0.1 | 2026-07-07 | P1 — test harness + 5 vtables aplicadas no .rdata + Versioning/Changelog + fix CMakeLists |
| v1.9.0.0 | 2026-07-07 | P2 — 20 enums FFX aplicados na DB IDA + PhyrePClassDescriptor 6 fields renomeados + 4 PInputSource ctors implementados + 8 Save getters + ResetData + GetCompletion + Rota E fechada (10/10 tests green) |

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
