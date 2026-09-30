---
date: 2026-06-29
tags:
  - knowledge-base-entry
  - ffx-project
  - documentation-hub
  - research-absorption
  - spirareforge
aliases:
  - FFX Knowledge Base
  - Projeto FFX Editor - Base de Conhecimento
  - Master Knowledge Base Entry
---
# FFX Project Editor - Knowledge Base

Este arquivo e a porta de entrada unica da base de conhecimento consolidada do projeto.

Se voce quer entender rapidamente:

- o que cada familia de oficina descobriu;
- o que ja foi absorvido pela `main`;
- o que ainda e `research only`;
- que runtime fields, offsets e guardrails ja viraram verdade operacional;
- onde estao os atlas mais completos;

comece por aqui.

## Leituras Principais

- [FFX Phyre PC — m001 DXT1, dez mipmaps e asset ID, 2026-09-05](docs/reverse/FFX_PHYRE_PC_M001_AUDIT_2026-09-05.md) — uma folha pinada, vínculo m_format e dez níveis/174.776 bytes; descritor BC1/4bpp por dez janelas do EXE, derivação Python e dez controles. Separa ID embutido/caminho físico, exemplo histórico não pinado e prova estática/runtime; Task11 e catálogo integral continuam abertos.
- [FFX Phyre PC — pixels BC3/ARGB8 por decoder independente, 2026-09-05](docs/reverse/FFX_PHYRE_PC_PIXEL_DECODING_2026-09-05.md) — três folhas, 11 mips, 2.173.611 pixels e zero divergências JavaScript/Pillow; 35 testes, dois guards corrigidos com RED comportamental e relatório v2 reproduzido idêntico. Âncoras de correção DXT5=16B e cobertura sintética distinguida do corpus. Sem glyph mapping, runtime, writer, Task11 ou catálogo integral promovidos.
- [FFX Phyre PC — consumidor do suffix e mipmaps, 2026-09-05](docs/reverse/FFX_PHYRE_PC_MIP_CONSUMERS_2026-09-05.md) — 17 corpos/7893 bytes/2600 instruções por ferramenta; leitura clampada, descarte por sobrescrita e pitches D3D distintos do avanço final. Mesmos 24 arquivos, 240 simulações com bytes de linhas iguais; 13 testes e releitura idêntica. Sem upload/runtime/pixels/writer/RT2/Task11 promovidos.
- [FFX Phyre PC — fixups compactos e descritores, 2026-09-05](docs/reverse/FFX_PHYRE_PC_FIXUPS_2026-09-05.md) — corrige a ordem pointer10→array3 do v2;24/24 vínculos estáticos nome→m_format,23DXT5/1ARGB8, callback/lista/descritores DXGI77/87 no EXE por hash;43corpos/16576bytes/5449instruções por ferramenta.11testes +2MCP, revisão independente e releitura idêntica. Semântica geral/payload visual/writer/RT2/Task11 continuam pendentes.
- [FFX Phyre PC — fontes reais e auditoria do handoff GLM, 2026-09-05](docs/reverse/FFX_PHYRE_PC_FONT_AUDIT_2026-09-05.md) — 24arquivos/7.961.557bytes; header, metadata, grupos116B e regiões de mipmaps; corrige spec hipotética e formato DXGI. Limites internos e binding atualizados pelo follow-up acima; v1/v2 preservados como históricos. Renderer e glyph mapping global continuam abertos, sem integração funcional no editor.
- [FFX FTC — consumidores PC, cópia B, métricas signed e stubs, 2026-09-04](docs/reverse/FFX_FTC_PC_CONSUMERS_2026-09-04.md) — +0x10 copia bytes de base+u32(+0x30); código por hash/GNU/LLVM, seis contrapartes PC/PS4 correspondentes ao censo PS3 e caudas não zero. Corrige largura versus glyph mapping e atribuições históricas; sem runtime/renderer/Unicode/editor funcional.
- [FFX — censo FTC, pacote legado DMA/GIF e correções, 2026-09-04](docs/reverse/FFX_FTC_FAMILY_AUDIT_2026-09-04.md) — 1.535 arquivos PS3 por hash, legado byte-idêntico às cópias PC/PS4, partição completa de 58.192 bytes; 1.354 contraexemplos de +0x34, magic corrigido e glyph mapping não resolvido. Diagnóstico offline, sem writer/engine/editor funcional.
- [FFX PS3 — leitura integral do PSARC e blocos armazenados, 2026-09-04](docs/reverse/FFX_PSARC_PS3_FULL_STREAM_AUDIT_2026-09-04.md) — arquivo inteiro de 5,51 GB por hash, 68.100 assets, 251.167 blocos zlib e 404 trechos crus conferidos byte a byte com extrações PS3; exceções de extensão/prefixo, sem aceitação semântica integral ou engine.
- [FFX PS3 — PSARC, índice e correções do atlas, 2026-09-04](docs/reverse/FFX_PSARC_PS3_INDEX_RECHECK_2026-09-04.md) — 68.100 nomes/MD5 conferidos, header flags2, 78 blocos de nomes, cinco slots de entradas vazias e dois contraexemplos do writer; índice offline, não valida assets ou engine.
- [FFX HD no Linux — PS3 localizado e duas amostras PC/PS3/PS4, 2026-09-04](docs/reverse/FFX_HD_CORPUS_IDENTITY_2026-09-04.md) — PARAM.SFO BLUS31211, comparação byte-exata de m001.chr/m001.bin e correspondência com dois payloads do PSARC PS3; não autentica mídia nem equivalência integral dos corpora.
- [Correções offline do atlas FFX — amostras PC, 2026-09-04](docs/reverse/FFX_ATLAS_CORRECTIONS_PC_2026-09-04.md) — Monster BIN/StatSheet e tabelas de caracteres por hash; não é atlas integral nem aceitação Task 7/11/runtime.

- [CHANGELOG.md](CHANGELOG.md)
- [PORT_STATUS.md](PORT_STATUS.md)
- [docs/ai/CLINE_KNOWLEDGE_EXTRACT.md](docs/ai/CLINE_KNOWLEDGE_EXTRACT.md)
- [docs/history/PT2_TO_PT45_MASTER_KNOWLEDGE_BASE.md](docs/history/PT2_TO_PT45_MASTER_KNOWLEDGE_BASE.md)
- [docs/history/PRODUCTION_ABSORPTION_MATRIX.md](docs/history/PRODUCTION_ABSORPTION_MATRIX.md)
- [docs/history/OFFICIAL_MERGE_PLAN_2026-05-31.md](docs/history/OFFICIAL_MERGE_PLAN_2026-05-31.md)
- [docs/history/PT52_TO_PT58_CLOSEOUT_REPORT_2026-05-31.md](docs/history/PT52_TO_PT58_CLOSEOUT_REPORT_2026-05-31.md)
- [docs/history/PT52_PT56_PT57_ARCHIVE_CLOSEOUT_2026-06-01.md](docs/history/PT52_PT56_PT57_ARCHIVE_CLOSEOUT_2026-06-01.md)
- [docs/history/PT52_BIN_FTC_FILE_MEANING_GUIDE_2026-06-01.md](docs/history/PT52_BIN_FTC_FILE_MEANING_GUIDE_2026-06-01.md)
- [docs/history/PT53_BATTLE_MAGIC_FILE_MEANING_GUIDE_2026-06-01.md](docs/history/PT53_BATTLE_MAGIC_FILE_MEANING_GUIDE_2026-06-01.md)
- [docs/history/PT54_PROJECT_ABMAP_FILE_MEANING_GUIDE_2026-06-01.md](docs/history/PT54_PROJECT_ABMAP_FILE_MEANING_GUIDE_2026-06-01.md)
- [docs/history/PT56_TEXTURE_PALETTE_FILE_MEANING_GUIDE_2026-06-01.md](docs/history/PT56_TEXTURE_PALETTE_FILE_MEANING_GUIDE_2026-06-01.md)
- [docs/reverse/FFX_GHIDRA_FAHRENHEIT_SYMBOL_IMPORT_2026-07-31.md](docs/reverse/FFX_GHIDRA_FAHRENHEIT_SYMBOL_IMPORT_2026-07-31.md) — importação do catálogo Ghidra (fahrenheit) na db + mapa do LpAbilityMapEngine
- [docs/reverse/FFX_ATEL_CALL_TARGETS_TABLES_2026-08-01.md](docs/reverse/FFX_ATEL_CALL_TARGETS_TABLES_2026-08-01.md) — **VM ATEL completa**: dispatch namespace/index, entry 16B, channels reais, 12 tabelas ~12K handlers
- [docs/reverse/FFX_DATA_SECTION_SCAN_2026-08-01.md](docs/reverse/FFX_DATA_SECTION_SCAN_2026-08-01.md) — 20/20 buffers do .data identificados
- [docs/reverse/FFX_RUNTIME_STRUCTS_2026-08-01.md](docs/reverse/FFX_RUNTIME_STRUCTS_2026-08-01.md) — structs aplicadas (LpAbilityMapEngine, FmodCommand[150], MscdQueueSlot[64], fila CTB)
- [docs/reverse/FFX_DB_COVERAGE_100PCT_2026-08-01.md](docs/reverse/FFX_DB_COVERAGE_100PCT_2026-08-01.md) — 100% das funções reais da COPY nomeadas
- [docs/reverse/FFX_EXE_ANATOMY_2026-08-01.md](docs/reverse/FFX_EXE_ANATOMY_2026-08-01.md) — 32.748 funções por módulo (Phyre 58%)
- [docs/reverse/FFX_EXE_FILE_PATHS_2026-08-01.md](docs/reverse/FFX_EXE_FILE_PATHS_2026-08-01.md) — 639 paths embutidos (shaders GCM, VideoList, mapeadores de áudio)

- [docs/history/PT57_PRESENTATION_CONTAINER_FILE_MEANING_GUIDE_2026-06-01.md](docs/history/PT57_PRESENTATION_CONTAINER_FILE_MEANING_GUIDE_2026-06-01.md)
- [docs/history/PT58_FFX_PS2_OWNERSHIP_AND_LINKAGE_GUIDE_2026-06-01.md](docs/history/PT58_FFX_PS2_OWNERSHIP_AND_LINKAGE_GUIDE_2026-06-01.md)
- [docs/history/BRANCH_DEPENDENCY_EDITABILITY_MATRIX_2026-06-02.md](docs/history/BRANCH_DEPENDENCY_EDITABILITY_MATRIX_2026-06-02.md)
- [docs/history/PRIORITY_ACTION_BOARD_2026-06-02.md](docs/history/PRIORITY_ACTION_BOARD_2026-06-02.md)
- [docs/history/FAN_MODS_VANILLA_BYTE_COMPARISON_2026-06-02.md](docs/history/FAN_MODS_VANILLA_BYTE_COMPARISON_2026-06-02.md)
- [docs/history/FAN_MODS_AND_ARENA_TRACKER_RELEVANCE_2026-06-02.md](docs/history/FAN_MODS_AND_ARENA_TRACKER_RELEVANCE_2026-06-02.md)
- [docs/history/MONSTER_ARENA_TRACKER_INTEGRATION_NOTES_2026-06-02.md](docs/history/MONSTER_ARENA_TRACKER_INTEGRATION_NOTES_2026-06-02.md)
- [docs/history/AI_RUNTIME_IDA_MASTER_LEDGER.md](docs/history/AI_RUNTIME_IDA_MASTER_LEDGER.md)
- [docs/history/IDA_STRUCTURAL_REFERENCES_REPORT_2026-06-02.md](docs/history/IDA_STRUCTURAL_REFERENCES_REPORT_2026-06-02.md)
- [docs/history/IDA_EXPORT_CHAIN_ANALYSIS_2026-06-02.md](docs/history/IDA_EXPORT_CHAIN_ANALYSIS_2026-06-02.md)
- [docs/history/EXE_CHOOSER_OWNER_CHAIN.md](docs/history/EXE_CHOOSER_OWNER_CHAIN.md)
- [docs/history/TRIGGER_EDGE_AND_STAGING_DECOMP_MAP.md](docs/history/TRIGGER_EDGE_AND_STAGING_DECOMP_MAP.md)
- [docs/history/WORD_112CA90_LAYOUT_MAP_2026-06-03.md](docs/history/WORD_112CA90_LAYOUT_MAP_2026-06-03.md)
- [docs/history/DWORD_C5273C_OVERRIDE_TRACE_2026-06-03.md](docs/history/DWORD_C5273C_OVERRIDE_TRACE_2026-06-03.md)
- [docs/history/STAGING_112CA20_24_28_WRITER_TRACE_2026-06-03.md](docs/history/STAGING_112CA20_24_28_WRITER_TRACE_2026-06-03.md)
- [docs/history/LIVE_BATTLE_RUNTIME_TRUTH_REPORT.md](docs/history/LIVE_BATTLE_RUNTIME_TRUTH_REPORT.md)
- [docs/history/EDITOR_READONLY_ABSORPTION_REPORT_2026-06-01.md](docs/history/EDITOR_READONLY_ABSORPTION_REPORT_2026-06-01.md)
- [docs/history/PT_OPERATIONAL_FLOW_2026-06-01.md](docs/history/PT_OPERATIONAL_FLOW_2026-06-01.md)
- [docs/history/PT50_PT51_HISTORICAL_CLEANUP_2026-05-31.md](docs/history/PT50_PT51_HISTORICAL_CLEANUP_2026-05-31.md)
- [docs/history/FFX_PHYRE_MAP_MATERIAL_IDA_FINDINGS_2026-06-03.md](docs/history/FFX_PHYRE_MAP_MATERIAL_IDA_FINDINGS_2026-06-03.md) — IDA (Map Viewer): `PParameterBuffer.field172/0xAC` = offset de membro de **reflection real do Phyre** (`ida-structural-confirmed`); runtime liga textura por **NOME** de shader param (djb2 `sub_67B980`), não por `+0xAC`; resposta ao handoff `CLAUDE_HANDOFF_FFX_PHYRE_MAP_MATERIAL_IDA`
- [docs/history/FFX_MAGIC_REPORTS_MASTER_INDEX_2026-06-05.md](docs/history/FFX_MAGIC_REPORTS_MASTER_INDEX_2026-06-05.md) — indice mestre da frente `Magic`: cronologia pass1..pass10, matriz dos exports, DLL x `ps3data\magic`, e ponte para a catalogacao no IDA

### Magic DLL Master Atlas (2026-07-08)

Atlas completo das 587 `magic_*.dll` com classificação, color storage, ferramentas e RT2 validado:

- [docs/reverse/magic_dlls/MAGIC_DLL_ATLAS.md](docs/reverse/magic_dlls/MAGIC_DLL_ATLAS.md) — **Master doc**, navegação única para tudo
- [docs/reverse/magic_dlls/FAMILY_A_REFERENCE.md](docs/reverse/magic_dlls/FAMILY_A_REFERENCE.md) — Family A (ParticleSelfContained, 261 DLLs)
- [docs/reverse/magic_dlls/FAMILY_B_REFERENCE.md](docs/reverse/magic_dlls/FAMILY_B_REFERENCE.md) — Family B (RootRecordInterpreter, 141 DLLs)
- [docs/reverse/magic_dlls/FAMILY_C_REFERENCE.md](docs/reverse/magic_dlls/FAMILY_C_REFERENCE.md) — Family C (RootSelfGovernedParam, 63 DLLs)
- [docs/reverse/magic_dlls/FAMILY_D_REFERENCE.md](docs/reverse/magic_dlls/FAMILY_D_REFERENCE.md) — Family D (EgoTasklist, 122 DLLs)
- [docs/reverse/magic_dlls/CROSS_FAMILY_MATRIX.md](docs/reverse/magic_dlls/CROSS_FAMILY_MATRIX.md) — Comparação lado-a-lado
- [docs/reverse/magic_dlls/COLOR_STORAGE_ANALYSIS.md](docs/reverse/magic_dlls/COLOR_STORAGE_ANALYSIS.md) — Color storage universal
- [docs/reverse/magic_dlls/COLOR_CHANGE_RECIPES.md](docs/reverse/magic_dlls/COLOR_CHANGE_RECIPES.md) — Receitas de recolor
- [docs/reverse/magic_dlls/RECOLOR_GUIDE.md](docs/reverse/magic_dlls/RECOLOR_GUIDE.md) — Guia validado (RT2)
- Ferramentas: `scripts/universal_recolor.py`, `scripts/color_scanner.py`, `scripts/batch_classify.py`, `scripts/batch_decompiler.py`
- Testes: `scripts/tests/magic_atlas/` — 30/30 passando

## Atualizacao 2026-06-26

- Magic effect authoring entrou em modo runbook operacional: `Prism Flare` (`monmagic2` row 247 / `0x60F7`, `Anim1=714`, `Anim2=715`) foi confirmado pelo usuario em RT2 visual, com recolor pegando de fato no efeito Fira-like inteiro. Esse vira controle positivo para skills de monstro texture-driven via `.dds.phyre` same-shape. `ThundaFira` segue como controle parcial: explosao/impacto recolor OK, mas o raio inicial (`0716`, Thundaga Family D PPP/KeThRes) continua bloqueado. Novo doc: [docs/reverse/FFX_MAGIC_EFFECT_AUTHORING_SPECIALIZATION_2026-06-26.md](docs/reverse/FFX_MAGIC_EFFECT_AUTHORING_SPECIALIZATION_2026-06-26.md).
- O goal de nomeacao do `FFX.exe` continua aberto: `1969` funcoes + `134` data rows (`2103` simbolos) no snapshot mais recente. A retomada pos-desligamento recuperou o replay lot19 (`1377/112/1489`) a partir de `__pycache__/apply_jarvis_goal_renames_20260617.cpython-313.pyc`, porque o fonte/report no disco tinham voltado para `980/91/1071`. O lot20 adicionou `62` handlers estruturais da tabela ATEL Movie `B010..B01F` (`g_FFX_Atel_MovieFuncspaceTable_candidate @ 0x00C40E20`, slots `CALL/STATUS/FLOATRET/INTRET`). O lot21 adicionou `6` anchors de battle monster AI file loader/CHR/MGRP (`783730`, `783BB0`, `783ED0`, `784120`, `829660`, `8368F0`). O lot22 adicionou `11` functions + `1` data row em menu/Flash, FMOD, controlled CHR e `g_FFX_SoundCmdHandlerTable @ 0x00C3A3A4`. O lot23 adicionou `47` handlers SoundCmd sync + corrigiu `0x708490` para cmd64 BattleStreaming. O lot24 promoveu `6` helpers FieldDebug model browser/controlled CHR. O lot25 adicionou `13` functions CHR/MGRP/MSEQ + `3` globals de pool/registry. O lot26 adicionou `16` functions MGRP/CHR/ResourceCache (`82A540`, `82A760`, `829F70`, `826960`, `826F20`, `837610`, `837670`, `837790`, `837730`, `8377B0`, `83FFE0`, `840560`, `8405F0`, `8406F0`, `840DD0` etc.). O lot27 adicionou `2` candidates de CHRINFO/motion debug (`837270`, `8537D0`). O lot28 adicionou `125` functions: `114` slots ATEL Movie `B020..B03F` table-backed (preservando `0x773CF0 FFX_Scan_IsLearnedWrapper`) + `11` rows MagicHost/Phyre da shortlist Laplace (`788EA0`, `7948B0`, `795E30`, `7889E0`, `7BC040`, `798940`, `7EB210`, `82BF60`, `800010`, `7E3D40`, `6A3CA0`). O lot29 adicionou `61` slots ATEL Movie `B040..B04F`, todos `sub_*` antes do rename. O lot30 adicionou `37` rows ATEL Movie `B050..B05F` num trecho esparso da tabela, sem preencher slots zerados. O lot31 adicionou `63` rows ATEL Movie `B060..B06F`, com densidade cheia ate `B06E` e `B06F` sem `INTRET` nao-zero. O lot32 adicionou `64` rows ATEL Movie `B070..B07F`, com quarteto completo em todos os `16` records e `64/64` `sub_*` antes do rename. O lot33 adicionou `35` rows ATEL Movie `B080..B088`, mas parou quando o tail deixou de parecer uma mesa limpa de function pointers (`B088.INTRET = 0x1`, `B089+` ambiguo/reusado). O lot34 colheu `15` anchors novos sugeridos pelos subagentes: loaders de locale/kernel/sphere-grid/ps3data e registradores `Phyre::PParameterBuffer*`. O lot35 sincronizou `0x82B5E0` e `0x86C3C0` como microfollow-up de CHR/menu. O lot36 promoveu o trio `0x433120`, `0x53F670`, `0x82A100` em Phyre animation descriptors + helper de motion path numeric-id. O lot37 matou o held de locale com `FFX_Locale_GetLanguageId` (`0x887C70`) e seu thunk `FFX_Locale_GetLanguageId_Thunk` (`0x887BA0`). O lot38 matou o ultimo cinza do microcluster `0x82A6xx` com `FFX_Resource_PumpPendingReadsThunk_structural` (`0x82A660`). O lot39 promoveu `9` data rows em SPU/Magic/Phyre (`0xC4946C`, `0xCA5040`, `0xC48D9C`, `0xC48E04`, `0xC48EC0`, `0xC49000`, `0xC49084`, `0xC490DC`, `0xC49128`) e segurou `0xC42A08`/`0xC48FF0` por boundary ainda ambigua. O lot40 promoveu `0xA45010` para `FFX_Abmap_MainInputDispatcher` depois de a docsweep dos subagentes bater com o live component review no IDB canonico. O lot41 adicionou `4` follow-ups table-driven: `0x821860 FFX_SgMenu_GetResult`, `0xA79A10 FFX_Atel_ChEvent_loadMapMotionBundle_ExecPoll_candidate`, `0xA79A20 FFX_Atel_ChEvent_loadMapMotionBundle_INTRET_candidate` e `0xA788A0 FFX_Atel_ChEvent_awaitMotion_ExecPoll_candidate`, alem de sincronizar o drift antigo em `0xA78770`, `0x91C530` e `0x91C5B0`. O lot42 adicionou `4` funcoes (`0x820720`, `0x821870`, `0x821D80`, `0x7A5EE0`) e fechou os dois helds de dado `0xC42A08`/`0xC48FF0` como `g_FFX_Atel_Battle_camReq_CallTarget_candidate` e `g_FFX_MagicCoreOp4AFamilyLeadIn_candidate`. O lot43 adicionou `3` data rows (`0x1130C9C`, `0x1130D04`, `0xC5273C`) e `3` funcoes do lane de forced-field override (`0x862CF0`, `0x86B650`, `0x8700D0`). O lot44 adicionou `9` funcoes (`0x85BFA0`, `0x780D40`, `0x7810C0`, `0x782960`, `0x790AA0`, `0x790AC0`, `0x793510`, `0x793540`, `0x795AB0`) e `4` data rows (`0x112A930`, `0x112A934`, `0x1134460`, `0x1135FEC`) no follow-up encounter/kernel/battle-list. O survey vivo do IDB em `2026-06-28` agora registra `47,397` funcoes totais; `45,428` funcoes ainda ficam fora do replay do goal.

## Atualizacao 2026-06-24

- `v2.179.0.0..v2.181.0.0` expande random encounters pós-Luca: Mi'ihen (16 bins), Mushroom Rock (19 bins), Djose Highroad (13 bins) — 2-3 → 4-5 inimigos. Doc: `docs/ai/PROMPT_JARVIS_FORM_ENCOUNTERS.md` (Anexos A/B/C), `FFX_ENCOUNTER_BATTLE_KNOWLEDGE.md`.
- `v2.174.0.0` e a versao corrente do editor: `KimahriLancetDualGrantHook` shipped, com Lancet learn-on-use 104-115 granta Blue Mage clone 323-334 + menu `#322` via GridTeach.
- `v2.173.0.2` fecha o anti-padrao Kimahri Blue Magic: donor Special `#276` e `sub=14` (+232), nao Ronso `#282` / +296.
- `v2.173.0.0` consolida os submenus de batalha como prova de infraestrutura: Yuna White Magic+ `#366` e Kimahri Blue Magic `#322` seguem como menus distintos sobre o mesmo `GridTeachHook`.
- Historico do goal `FFX.exe` antes do lot20: o transform matrix lot19 (`2026-06-25`) fechou o boundary pass `C8F*` sem promover globals sujos e adicionou anchors MagicHost/PPP de matriz/ordem Euler (`42EE40`, `72A3D0`, `72C820..72CD60`). O data correction lot18 corrige Menu2D `0x010CC81C/0x010CC838` para `0x00CCC81C/0x00CCC838` e adiciona globals Phyre/Magic runtime-root (`CCC898`, `12A2280`, `12A4080`, `12A40C0`). Ainda ha espaco grande para lotes table-driven em ATEL, Magic, UI/menu, MGRP e Resource/Phyre.

## ONDA 2026-06-15 — RE Deep Inferno I01-I30 (research-only + headless IDA + semantic rename)

Maratona `docs/ai/FFX_RE_DEEP_INFERNO_PROMPT_GPT55_2026-06-15.md`: 20 tarefas obrigatorias I01-I20 + 10 bonus I21-I30. **Research-only** — nao rodou FFX, nao patchou DLL/game files. O MCP IDA continuou sem `session_id`, mas batch headless em copia limpa do `.i64` abriu Hex-Rays e exportou `27/27` funcoes no batch obrigatorio e `13/13` targets no batch bonus. A rodada final expandiu I01-I20 para bater o criterio do prompt: **16/20 docs >=400 linhas nao vazias**, **20/20** com evidencia/bloqueio, **100 decompile cards**, **85 hook specs**, **160 rename queue** (`inferno_mandatory_doc_quality_summary.json`) — **a fila de 160 placeholders NAO deve ser aplicada cegamente** (gerador produz `FFX_I##_`/`sub_unknown_I##_`).

**Passada semantica (Cursor/idalib, 2026-06-15):** ~**45 renames** aplicados no `FFX_recon.i64` a partir de docs provados (M26, INFERNO addenda, warp, Ronso, Nul). Hooks/editor **nao ficam bloqueados** por rename pendente — so qualidade de nomenclatura IDA.

- [docs/reverse/FFX_RE_DEEP_INFERNO_INDEX_2026-06-15.md](docs/reverse/FFX_RE_DEEP_INFERNO_INDEX_2026-06-15.md) — indice I01-I30, status por item, hooks/RVAs e bloqueios.
- [docs/reverse/FFX_RE_DEEP_INFERNO_DELIVERY_BUNDLE_2026-06-15.md](docs/reverse/FFX_RE_DEEP_INFERNO_DELIVERY_BUNDLE_2026-06-15.md) — entrega unica consolidada do pacote.
- [docs/reverse/FFX_RE_DEEP_INFERNO_AUDIT_2026-06-15.md](docs/reverse/FFX_RE_DEEP_INFERNO_AUDIT_2026-06-15.md) — auditoria honesta contra o prompt original e registro do fallback IDA headless.
- [docs/reverse/FFX_RE_DEEP_INFERNO_HEADLESS_IDA_ADDENDUM_2026-06-15.md](docs/reverse/FFX_RE_DEEP_INFERNO_HEADLESS_IDA_ADDENDUM_2026-06-15.md) — addendum com 27 funcoes exportadas e achados fortes: ATEL `sub_877770`, command lookup `790AE0/7AB890`, ComputeHitDamage, OD `7B15A0`, encounter wrappers, Magic VM/path, menu/learn split 96-bit.
- [docs/reverse/FFX_RE_DEEP_INFERNO_BONUS_IDA_ADDENDUM_2026-06-15.md](docs/reverse/FFX_RE_DEEP_INFERNO_BONUS_IDA_ADDENDUM_2026-06-15.md) — addendum bonus com I21-I30, batch `13/13` e status parcial/bloqueado honesto por alvo.
- [docs/reverse/FFX_RE_DEEP_INFERNO_SEMANTIC_RENAME_APPLY_2026-06-15.md](docs/reverse/FFX_RE_DEEP_INFERNO_SEMANTIC_RENAME_APPLY_2026-06-15.md) — tabela dos ~45 renames aplicados + pendentes (`0x7828B0`, W2S, `g_BattlePlayerList`).
- [docs/ai/FFX_RE_SEMANTIC_DRIFT_AUDIT_PROMPT_GPT55_2026-06-15.md](docs/ai/FFX_RE_SEMANTIC_DRIFT_AUDIT_PROMPT_GPT55_2026-06-15.md) — maratona S01-S12 para corrigir drift camera/menu e fechar pendentes.
- [docs/reverse/FFX_RE_SEMANTIC_DRIFT_AUDIT_2026-06-15.md](docs/reverse/FFX_RE_SEMANTIC_DRIFT_AUDIT_2026-06-15.md) — **12/12** auditoria pos-INFERNO; **12 renames** no `FFX_recon.i64` (`v2.116.0.1`–`v2.116.0.2`): drift camera→menu UI, aggregate `7B2DD0`, blob helpers, GetActorRecord, precheck_structural, `g_BattlePlayerList`.
- [docs/reverse/FFX_RE_SEMANTIC_DRIFT_INDEX_2026-06-15.md](docs/reverse/FFX_RE_SEMANTIC_DRIFT_INDEX_2026-06-15.md) — indice S01-S12 + JSONs `work/reverse/ida/exports/re_semantic_audit/`.
- [docs/reverse/FFX_RE_SEMANTIC_DRIFT_FFX_ADDRESSES_PROPAGATION_2026-06-16.md](docs/reverse/FFX_RE_SEMANTIC_DRIFT_FFX_ADDRESSES_PROPAGATION_2026-06-16.md) — tabela RVA↔nome para hooks Ronso/Nul (`ffx_addresses.h`).
- **BIBLE OF SPIRA (in-app):** `AiBibleCatalog.cs` ganhou `btlGetCalcResult (0x707A)` e `readMovePropertyForActor (0x7078)` em `v2.113.0.3`; UI `BibleOfSpiraGuide_Window` reflete catalogo ao rebuild.

Bloqueios preservados: CTB scheduler, AI field reload/cache, Capture/Steal, Copycat/Doublecast, native chunk3 spawn cap, semantica runtime de `btlGetCalcResult(0x707A)` e os bonus ainda parciais/bloqueados (W2S owner fixo, weakness draw loop, arena selector, Mix handler, third equip slot).

## ONDA 2026-06-15 — Nul Ward / Radiant Umbra (preflight + ATEL 56/57 + matriz 24 planos)

Frente **Nul Ward** (comandos 320/321 Holy/Dark block) — `v2.113.0.0` preflight offline + hook fix; `v2.113.0.1` 12 planos RE; `v2.113.0.2` matriz integracao 24 rotas. **Research/lab** — RT2 core P05 pendente.

- [docs/reverse/FFX_NUL_WARD_RESEARCH_PLANS_2026-06-15.md](docs/reverse/FFX_NUL_WARD_RESEARCH_PLANS_2026-06-15.md) — R01–R12 com ancora IDA (`sub_7B2DD0` contadores `+0x60E..0x610`, teach id≥96 party bank).
- [docs/reverse/FFX_NUL_WARD_INTEGRATION_MATRIX_2026-06-15.md](docs/reverse/FFX_NUL_WARD_INTEGRATION_MATRIX_2026-06-15.md) — P01–P32; ATEL cases **56/57** escrevem `actor+0x613/0x614`; crosswalk INFERNO I24.
- [docs/reverse/FFX_RADIANT_UMBRA_WARD_HANDOFF_2026-06-15.md](docs/reverse/FFX_RADIANT_UMBRA_WARD_HANDOFF_2026-06-15.md) — handoff Radiant/Umbra + gap parser AI fields 0x33–0x36.

## ONDA 2026-06-11 — Auto-Abilities NOVAS: todas as vias + cookbook de formulas (research-only)

Pesquisa multi-agente (Jarvis-MAGIC, 3 workflows) sobre a viabilidade de criar auto-abilities (habilidades de arma/armadura) NOVAS no FFX HD PC. **READ-ONLY** — nenhum writer; `a_ability.bin` segue `reader + no-edit guard`. Veredito: SIM, com split duro **DATA-DRIVEN** (elementos/status/stat%/auto-SOS/Ribbon = reproduzivel por bytes em qualquer slot, provado por offset em IDA) vs **HARDCODED-POR-ID** (~31 abilities = 1 bit em `0x62/0x64/0x66`, handler em C, so via hook/exe). A engine ACEITA grow >0x86 (count vem do header, sem literal `0x86`); 5 slots livres reais 129-133. Doc-indice mestre primeiro:

- [docs/reverse/FFX_AUTOABILITIES_NOVAS_MASTER_2026-06-11.md](docs/reverse/FFX_AUTOABILITIES_NOVAS_MASTER_2026-06-11.md) — INDICE/veredito unificado: amarra os 3 streams, matriz dos 12 metodos, split data-driven vs hardcoded, cookbook condensado, lacunas de RE.
- [docs/reverse/FFX_NEW_AUTO_ABILITY_FEASIBILITY_2026-06-11.md](docs/reverse/FFX_NEW_AUTO_ABILITY_FEASIBILITY_2026-06-11.md) — via ESTATICA (editar `a_ability.bin`): repurpose/grow/combos; prova IDA do count no header; os 3 guards C#; text pool.
- [docs/reverse/FFX_AUTO_ABILITY_NEW_VIA_HOOK_DLL_RUNTIME_FEASIBILITY_2026-06-11.md](docs/reverse/FFX_AUTO_ABILITY_NEW_VIA_HOOK_DLL_RUNTIME_FEASIBILITY_2026-06-11.md) — via RUNTIME/DLL: expandir tabela em RAM / injetar efeito nativo; pipeline no actor (`MemoryChr`); hook ja provado (`DINPUT8` + PolyHook2), sem anti-cheat na Steam.
- [docs/reverse/FFX_AUTOABILITIES_NOVAS_VIAS_E_FORMULAS_COOKBOOK_2026-06-11.md](docs/reverse/FFX_AUTOABILITIES_NOVAS_VIAS_E_FORMULAS_COOKBOOK_2026-06-11.md) — 12 metodos + COOKBOOK de bytes completo (receita por efeito, evidencia por id) + patch de exe + ability-as-script (refutado p/ player) + familia command/item/monmagic.

## ONDA 2026-06-12 — Novas magias/armas/efeitos: grow vs hook vs asset

Pesquisa de decisao para a pergunta "podemos so aumentar/adicionar ou precisa hook?". Veredito: **grow puro so basta quando o consumidor e count/header-driven**. Magia aprendivel normal nao cresce so com `command.bin` por causa de `AbiMap`/menu/save; arma comum deve preferir data/repurpose/grow de catalogo; reskin same-shape e asset-level; modelo 3D novo segue HD lane/lab; visual novo de magia ainda nao tem compiler e passa por `magic_####.dll`/interpreter/callbacks.

- [docs/reverse/FFX_LIMIT_GROW_HOOK_WEAPON_MAGIC_ASSET_DECISION_2026-06-12.md](docs/reverse/FFX_LIMIT_GROW_HOOK_WEAPON_MAGIC_ASSET_DECISION_2026-06-12.md) — matriz final por alvo: spell learn, `command.bin` AI/direct, gear catalog, reskin, Phyre model, magia visual e KIND novo.
- [docs/reverse/FFX_SPELL_LIMIT_EXTENSION_HOOK_FEASIBILITY_2026-06-12.md](docs/reverse/FFX_SPELL_LIMIT_EXTENSION_HOOK_FEASIBILITY_2026-06-12.md) — prova IDA especifica para aumento de magia/comando: lookup header-driven, mas learn/menu exigem hook.
- [docs/reverse/FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md](docs/reverse/FFX_SPELL_FREE_ID_AUDIT_2026-06-12.md) — nao ha id livre limpo em `0..95`; primeira via data-only e repurpose.
- [docs/reverse/FFX_NEW_CONTENT_TEXT_LINKAGE_NAMING_RESEARCH_2026-06-12.md](docs/reverse/FFX_NEW_CONTENT_TEXT_LINKAGE_NAMING_RESEARCH_2026-06-12.md) — decisao de nome/descricao: usar carriers nativos (`command.bin`, `a_ability.bin`, `w_name.bin`, `*_txt.bin` quando ja wired); DLL so para menu/runtime/sidecar dinamico; evento/battle text e mensagem contextual, nao nome canonico.
- [docs/reverse/FFX_AUTOABILITY_MAGIC_PS3_WRITER_REPACK_BLOCKERS_2026-06-12.md](docs/reverse/FFX_AUTOABILITY_MAGIC_PS3_WRITER_REPACK_BLOCKERS_2026-06-12.md) — matriz dos bloqueios AutoAbility + Magic/PS3 e primeiro writer LAB de `ps3data\magic`: `--ps3magic-phyre-repack-rt0` troca mip0 same-shape em `.dds.phyre` real, aceita `.dds` compativel, prova no-edit byte-identico e diff confinado ao mip0; nao e compiler/timeline de magia.
- [docs/reverse/FFX_MAGIC_DLL_AND_COLOR_AUTHORING_LAB_2026-06-12.md](docs/reverse/FFX_MAGIC_DLL_AND_COLOR_AUTHORING_LAB_2026-06-12.md) — frente runtime/visual de magia: `Magic DLLs (FFX)` decompila PE/import/export/sections/strings/overlay evidence, recompila byte-identico e tem `Direct Patch Builder` no menu para byte/ASCII patch por `file offset`/`RVA` emitindo DLL de saida; `v2.88.0` adiciona `Candidate Value Workbench`, com scan/edit assistido de `float32`, `vec3f/vec4f`, `push imm8/imm32` e referencias u32 de `Host Context` para tentar cor/alpha/escala/velocidade/timer/flag/count sem hex cru; `PS3 Magic (HD)` le a DLL runtime correspondente ao `magic_####`, compoe preview Alpha/Additive e gera recolor same-shape por textura/pasta; `--magic-effect-link-rt0` valida tambem `magicFiles\FFX\magic_####.dll`; `--ps3magic-recolor-rt0` PASS com diff confinado ao mip0; `--magicdll-semantics-rt0` PASS gera naming pass de slots/host fields. Semantica de valores segue candidate ate RT2.
- [docs/reverse/FFX_THUNDAFIRA_PHASE_SPLIT_STATUS_2026-06-14.md](docs/reverse/FFX_THUNDAFIRA_PHASE_SPLIT_STATUS_2026-06-14.md) — **placar Fase1/Fase2** (explosão OK, raios bloqueados)
- [docs/reverse/FFX_THUNDAFIRA_HANDOFF_CONTINUE_2026-06-14.md](docs/reverse/FFX_THUNDAFIRA_HANDOFF_CONTINUE_2026-06-14.md) — **ThundaFira handoff completo** (Family D PPP, RT2 falhas vec4, próximos passos; ler antes de retomar)
- [docs/reverse/FFX_THUNDAFIRA_FAMILY_D_RT2_2026-06-14.md](docs/reverse/FFX_THUNDAFIRA_FAMILY_D_RT2_2026-06-14.md) — Thundaga = Family D; vec4 `0x31640` = matriz PPP; patch 2D falhou
- [docs/reverse/FFX_THUNDAFIRA_VISUAL_RECOLOR_PIPELINE_2026-06-14.md](docs/reverse/FFX_THUNDAFIRA_VISUAL_RECOLOR_PIPELINE_2026-06-14.md) — pipeline LAB (trecho vec4 antigo — ver handoff acima)
- [docs/reverse/FFX_MAGIC_DLL_SEMANTIC_RE_NAMING_PASS_2026-06-12.md](docs/reverse/FFX_MAGIC_DLL_SEMANTIC_RE_NAMING_PASS_2026-06-12.md) — primeira engenharia reversa semantica em lote das Magic DLLs: FFX `583/583` inspecionadas (`581` com overlay CSV), FFX-2 `844/844` inspecionadas como corpus separado; IDA em `FFX.exe` reforca `host+2864=sub_80CD60`, `host+2884=sub_80BEA0` e `sub_817200`; inclui fontes publicas Qhimm/Phyre/DDS e guardrail de nomes candidatos.
- [docs/reverse/FFX_MAGIC_RUNTIME_ANIMATION_CHAIN_RESEARCH_2026-06-13.md](docs/reverse/FFX_MAGIC_RUNTIME_ANIMATION_CHAIN_RESEARCH_2026-06-13.md) — resposta direta ao limite do `Runtime Map`: cadeia estrutural `FFX.exe -> magic_####.dll -> InitMagicPRX/GetEffectOverlayTable -> dat_et runtime root -> sub_800530/590/950 -> sub_80CD60 -> opcode handler sub_817200/root+84/root+88 -> callbacks/payload Phyre`; prova em `magic_0688.dll` que slots repetidos/stubs e reescrita de overlay table em runtime impedem tratar a surface como playlist de frames; `v2.88.1` implementa `Simulate` no `RuntimeTools/FFXMagicViewerWeb` como `Runtime Simulation Candidate` continuo (fases/cursor/callbacks/payload), menos falso que `Cycle Surface`, mas ainda sem interpreter completo, timing frame-accurate ou RT2 engine-accurate.
- [docs/reverse/FFX_MAGIC_DLL_LOGICAL_DECOMPILE_WAVE1_2026-06-14.md](docs/reverse/FFX_MAGIC_DLL_LOGICAL_DECOMPILE_WAVE1_2026-06-14.md) — wave 1: decompilacao logica estatica em 119 DLLs (~20%/familia); host-offset fingerprint, stub detect, pseudocode template; gate `--magicdll-logical-decompile-wave1`.
- [docs/reverse/FFX_MAGIC_DLL_LOGICAL_DECOMPILE_WAVE2_2026-06-14.md](docs/reverse/FFX_MAGIC_DLL_LOGICAL_DECOMPILE_WAVE2_2026-06-14.md) — wave 2: corpus 583/583, clustering slot0 (534 clusters, 34 shared), filas Hex-Rays tiered (pinned/shared/all); gate `--magicdll-logical-decompile-wave2`; UI Logical Decompile tab no Magic DLL Browser (`v2.91.0.0`).
- [docs/reverse/FFX_MAGIC_DLL_HEXRAYS_ALL_COMPLETE_2026-06-14.md](docs/reverse/FFX_MAGIC_DLL_HEXRAYS_ALL_COMPLETE_2026-06-14.md) — Hex-Rays ALL tier: **534 DLLs / 1829 slots** decompilados via `scripts/magic_dll_hexrays_batch.py` (6 workers paralelos, ~16 min); artefatos em `work/magic_dll_logical_decompile_wave2/hexrays_output/` (`v2.92.0.0`).
- [docs/reverse/FFX_MAGIC_DLL_WAVE3_CLASSIFICATION_2026-06-14.md](docs/reverse/FFX_MAGIC_DLL_WAVE3_CLASSIFICATION_2026-06-14.md) — wave3: sibling registry, subfamily slot0+1, spell↔PS3 linkage, 714/715 clone class, VM bridge, secondary Hex-Rays **1480 slots**; postprocess host auto no batch (`v2.93.0.0`).
- [docs/reverse/FFX_MAGIC_DLL_DEEP_CORPUS_WAVE4_2026-06-14.md](docs/reverse/FFX_MAGIC_DLL_DEEP_CORPUS_WAVE4_2026-06-14.md) — wave4: data/PPP inventory, kernel row expansion, host API profiles, slot4 phase patterns, RT2 human queue (`v2.93.0.0`).
- [docs/reverse/FFX_MAGIC_DLL_ORPHAN_CATALOG_2026-06-14.md](docs/reverse/FFX_MAGIC_DLL_ORPHAN_CATALOG_2026-06-14.md) — orphan attribution multi-fonte: `MagicDllMoveAnimParser` (+44 `moveAnim/None`), 463 catalog+kernel, 109 engine carriers, 0 unresolved (`v2.93.0.0`).
- [docs/reverse/FFX_MAGIC_DLL_HEXRAYS_PINNED_PROGRESS_2026-06-14.md](docs/reverse/FFX_MAGIC_DLL_HEXRAYS_PINNED_PROGRESS_2026-06-14.md) — tier pinned 28/35 OK (anchors 0084/0098/0082/0148/0688); superseded pelo ALL complete mas mantem notas de falhas iniciais.
- [docs/reverse/FFX_MAGIC_ENGINE_MASTER_2026-06-14.md](docs/reverse/FFX_MAGIC_ENGINE_MASTER_2026-06-14.md) — **hub unico** da frente magia: liga VM EXE (`sub_80CD60`, dispatch duplo core/overlay), classificacao 581 DLLs (A/B/C/D, RT2 581/581), infiltradas C, clusters de opcodes e guia de edicao A/C; ponto de entrada antes dos docs filhos.
- [docs/reverse/FFX_MAGIC_TIMELINE_VM_OPCODE_TABLES_2026-06-14.md](docs/reverse/FFX_MAGIC_TIMELINE_VM_OPCODE_TABLES_2026-06-14.md) — mapa completo da VM de timeline: `g_FFX_MagicOpcodeTable_core` (119 funcoes unicas), post-proc (12), side-pass (20); corrige parse manual DeepSeek; 146 renames no `FFX_recon.i64`.
- [docs/reverse/FFX_MAGIC_DLL_BUCKET_COMPLETE_CLASSIFICATION_2026-06-13.md](docs/reverse/FFX_MAGIC_DLL_BUCKET_COMPLETE_CLASSIFICATION_2026-06-13.md) — 5 buckets x 4 familias por decompile Hex-Rays; prova que bucket 404 mistura A e B; contagens 261/141/63/116.
- [docs/reverse/FFX_MAGIC_DLL_INFILTRATED_C_VALIDATION_2026-06-14.md](docs/reverse/FFX_MAGIC_DLL_INFILTRATED_C_VALIDATION_2026-06-14.md) — 13 DLLs Family C no bucket 404; byte-scan gate 13/13; amostras IDA `0183`/`0244`/`0700`.
- [docs/reverse/FFX_MAGIC_VM_OPCODE_CLUSTERS_2026-06-14.md](docs/reverse/FFX_MAGIC_VM_OPCODE_CLUSTERS_2026-06-14.md) — taxonomia por cluster (branch/transform/matrix/draw/param) com amostra decompilada; proximo passo engine sem decompilar 119 handlers 1-a-1.
- [docs/reverse/FFX_MAGIC_FAMILY_AC_EDITING_GUIDE_2026-06-14.md](docs/reverse/FFX_MAGIC_FAMILY_AC_EDITING_GUIDE_2026-06-14.md) — playbook lab cor/velocidade: prioriza familias A/C + Value Workbench; VM core em segundo plano; checklist RT2 visual.
- [docs/reverse/FFX_MAGIC_DLL_SIMILAR_SPELL_PATTERN_ANALYSIS_2026-06-13.md](docs/reverse/FFX_MAGIC_DLL_SIMILAR_SPELL_PATTERN_ANALYSIS_2026-06-13.md) — pesquisa `v2.88.1.2` de padroes entre magias parecidas: cruza `AiCommandMetadataCatalog.Generated.cs` (`979` rows, `689` com `moveAnim`), overlay CSV (`581` rows) e DLLs `magicFiles\FFX\magic_####.dll`; prova offline que `Power`/hits/status ficam na row de comando enquanto o visual vem de `moveAnim`; mapeia familias Fire/Thunder/Water simples `nz9/u5`, Ice/curas/Flare-like PPP mais largas, reuso Cure/Potion/Mixes e o contraexemplo `Death`; nova passada `Death`/`Mega Death` mostra `magic_0098` e `magic_0351` com overlay/slots de textura compartilhados, mas hashes/payload diferentes; recomenda `Family Comparator` e RT2 em clones `0714/0715` antes de nomear floats/pushes como cor/velocidade.
- [docs/reverse/FFX_PHYRE_PACKAGE_IO_EDITOR_INTEGRATION_2026-06-12.md](docs/reverse/FFX_PHYRE_PACKAGE_IO_EDITOR_INTEGRATION_2026-06-12.md) — nova UI `Extras -> Phyre Package I/O`: inspect/extract/import nativo de pacotes Phyre; `.dds.phyre` tem DDS/raw mip0 import same-shape; `.dae.phyre` tem inspect/manifest/protected compiled-package import, sem prometer compiler glTF/FBX/DAE -> Phyre; `--phyre-package-io-rt0` PASS em DDS + DAE no-edit byte-identicos.
- [docs/reverse/FFX_VBF_EXTRACT_EDITOR_INTEGRATION_2026-06-12.md](docs/reverse/FFX_VBF_EXTRACT_EDITOR_INTEGRATION_2026-06-12.md) — `Extras -> VBF Extract`: wrapper extract-only do `vbfextract.exe` local para preparar a arvore fonte `D:\FFX Extracted\FFX`/`FFX2`/`MetaMenu`; `--vbfextract-rt0` PASS em `FFX_Data`, `FFX2_Data` e `metamenu`; repack VBF fica `lab-only/research`, sem botao publico.
- [docs/reverse/FFX_NOVAS_MAGIAS_COMO_CRIAR_RESEARCH_2026-06-12.md](docs/reverse/FFX_NOVAS_MAGIAS_COMO_CRIAR_RESEARCH_2026-06-12.md) — resposta operacional para "como criaremos novas magias?": jogador aprende via Sphere Grid/`LearnedMove` dentro do limite `AbiMap 0..95`; primeira rota honesta e `Spell Repurpose Creator LAB` em id existente `43..83`; magia de monstro e rota mais facil via `monmagic1/2` + AI `performCommand`; id novo preservando vanilla exige hook de learn/menu/save; visual novo fica separado entre textura same-shape e runtime/compiler.
- [docs/ai/MEGA_PLANO_IMPLEMENTACAO_NOVAS_MAGIAS_ARMAS_EFEITOS_ASSETS_HOOKS_2026-06-12.md](docs/ai/MEGA_PLANO_IMPLEMENTACAO_NOVAS_MAGIAS_ARMAS_EFEITOS_ASSETS_HOOKS_2026-06-12.md) — plano gigante executavel para transformar a pesquisa em implementacao: carriers nativos, `NewContentTextPlan`, AutoAbility id129/grow, PS3 Magic same-shape, gear/spell repurpose, hooks e campanha RT2, deixando AI/ATEL/Monster AI Editor fora da frente.
- [docs/reverse/FFX_NEW_CONTENT_TEXT_CARRIER_MATRIX_2026-06-12.md](docs/reverse/FFX_NEW_CONTENT_TEXT_CARRIER_MATRIX_2026-06-12.md) — matriz implementada de nome/descricao/linkage por tipo de conteudo; `--newcontent-textplan-rt0` PASS 10/10, `--autoability-id129-pilot-rt0` PASS, gates finais de weapon/shop/command/PS3 Magic registrados com escopo RT0 honesto.
- [docs/ai/NEW_CONTENT_RT2_PILOT_RUNBOOK_2026-06-12.md](docs/ai/NEW_CONTENT_RT2_PILOT_RUNBOOK_2026-06-12.md) — runbook vivo para promover de RT0 para RT2: PS3 Magic same-shape, AutoAbility id129 `0x8081`, weapon/gear repurpose, spell/command repurpose e fronteira grow/hook com backup/hash/revert e criterios PASS/FAIL.
- [docs/reverse/FFX_MONSTER_ARENA_NEW_TABS_AND_CREATIONS_RESEARCH_2026-06-12.md](docs/reverse/FFX_MONSTER_ARENA_NEW_TABS_AND_CREATIONS_RESEARCH_2026-06-12.md) — pesquisa aprofundada para novas abas/novos monstros liberados no Monster Arena: editor tabs e overlay sao viaveis agora; runtime vanilla mostra `104` contadores + `35` flags em `0xD30C9C`; `ArenaId` mapeia capturaveis `0..103`; `_m347.._m360` no dump atual nao provam slots novos porque declaram `MonsterId=301`; boss custom em battle segue offline/RT2 pendente; tab nativa nova e creation 36 exigem RE/hook.
- [docs/reverse/FFX_MONSTER_ARENA_DLL_HOOK_INSERTION_RESEARCH_2026-06-13.md](docs/reverse/FFX_MONSTER_ARENA_DLL_HOOK_INSERTION_RESEARCH_2026-06-13.md) — follow-up via DLL/hook para inserir Monster Arena custom: rota curta `Arena+` no `NativeMenuShell`/`FfxHooksDll` com leitura do bloco `0xD30C9C`, sidecar custom e Force Battle; rota longa para hookar o menu original exige localizar callbacks/builders da Arena, unlock checks, confirm handler, capture increment e save hooks.
- [docs/reverse/FFX_MONSTER_ARENA_UNLOCK_FLAGS_DARK_AEON_ARENA_RESEARCH_2026-06-13.md](docs/reverse/FFX_MONSTER_ARENA_UNLOCK_FLAGS_DARK_AEON_ARENA_RESEARCH_2026-06-13.md) — validacao complementar para a decisao **Arena+**: `ArenaUnlocks[0..34]` vivem em `0xD30D04..0xD30D26`; Dark Aeons/Penance ja tem save vars nomeados em `SaveData+0x0A9D..0x0AA5` (`0xD2D52D..0xD2D535`), permitindo liberar entries por derrota real sem Capture; rota recomendada e mesmo NPC/opcao nova/submenu Arena+, deixando "mesmo modo vanilla com mais slots" para fase pesada de hooks.
- [docs/reverse/FFX_NPC_OPTION_ARENA_PLUS_DLL_HOOK_RESEARCH_2026-06-13.md](docs/reverse/FFX_NPC_OPTION_ARENA_PLUS_DLL_HOOK_RESEARCH_2026-06-13.md) — pesquisa especifica para aplicar uma nova opcao em NPC via DLL: usar `ACT_ARENA -> ArenaPlus_RequestOpen` como primeira validacao, depois `arena-flags`, `menu-pool-dump` e `npc-scout` na Monster Arena para decidir entre row nativa real no menu do NPC ou hook de evento/ATEL; inclui runbook RT2 para validar UI nativa, flags, NPC context e battle launch in-game.
- [docs/reverse/FFX_NPC_OPTION_DLL_FINAL_SCOUT_AND_RT2_PLAN_2026-06-13.md](docs/reverse/FFX_NPC_OPTION_DLL_FINAL_SCOUT_AND_RT2_PLAN_2026-06-13.md) — dossie final pre-RT2 para nova opcao de NPC via DLL: reconfirma no `FFX.exe` o pool `0x18408C0`, callbacks `+12/+16`, popup `0x8E33D0`, VM ATEL/funcspaces `0x864180/0x877720/0x1328518`, field actor scout `0x86A7C0/0x794030` e nomeia todas as opcoes possiveis (`NativeShell`, `NpcContextProxy`, `NativeListRowInjection`, `PopupChoiceHook`, `AtelChoiceHook`, `FuncspaceNativeCall`, `.ebp`, `VanillaArenaSlotExpansion`), com runbook de testes ingame.
- [docs/reverse/FFX_ARENA_PLUS_PRE_RT2_RESEARCH_2026-06-13.md](docs/reverse/FFX_ARENA_PLUS_PRE_RT2_RESEARCH_2026-06-13.md) — dossie consolidado Arena+: identifica o evento real `nagi0700 (Calm Lands - Arena)`, o top menu do NPC em `w0E::f05` via `Common.displayFieldChoice [013B]` string `[4A]`, o seletor de monstros em `w0E::f07` via `SgEvent.showModularMenu [401D]`, o launch em `Battle.launchBattle [7002]` e o unlock de creations `0x0300..0x0322`; RT2 2026-06-13 provou hooks trace-only `Common.013B`/`SgEvent.401D`/`Battle.7002`, objeto vanilla `group=0x106` com callbacks IDA `0x8A9180`/`0x8A9300`, `ACT_ARENA -> ArenaPlus_RequestOpen`, tela nativa `Arena+` propria com Dark Aeons/Penance `LOCKED`, launch vanilla `route=current field=425 group=0 formation=0 -> ret=-1 queued` e retorno vivo pos-vitoria; ainda nao prova row nova no menu vanilla, Dark Aeon battle mapping, expansao `ArenaUnlocks[35+]` ou writer de save.
- [docs/reverse/FFX_ARENA_PLUS_COMPOSE_CAMERA_CHUNK0_TEMPLATE_2026-06-23.md](docs/reverse/FFX_ARENA_PLUS_COMPOSE_CAMERA_CHUNK0_TEMPLATE_2026-06-23.md) — **bible RT2 OK** Arena+ Custom Mix: camera = **chunk0 ATEL** (nao chunk3 `monLive` sozinho); donor `mcyt00_21` → carrier `mcyt00_22`; slot swap `0x1153`=Anima / `0x1154`=Yojimbo; **barras pretas = Overdrive**; F7 sub-menus Dark Rematch / Gauntlet / Custom Mix; **playbook Aurora** para multi-actor camera splice.

## ONDA 2026-06-15 — Research queue Jarvis-RESEARCH-TROUXA (offline encerrada)

Pesquisas curtas geradas para coordenação entre chats sem estourar contexto (ThundaFira, Magic RT2, Prism, Arena+, infra). **Não são produto shippable** — servem como veto, mapa e runbook RT2.

- [docs/reverse/FFX_RESEARCH_QUEUE_TROUXA_INDEX_2026-06-15.md](docs/reverse/FFX_RESEARCH_QUEUE_TROUXA_INDEX_2026-06-15.md) — **índice mestre**: qual doc abrir por tarefa + prioridade pós-pesquisa.
- ThundaFira: [FFX_THUNDAFIRA_DEAD_ENDS_INDEX_2026-06-15.md](docs/reverse/FFX_THUNDAFIRA_DEAD_ENDS_INDEX_2026-06-15.md), [FFX_MAGIC_DLL_RT2_ATTEMPT_LEDGER_2026-06-15.md](docs/reverse/FFX_MAGIC_DLL_RT2_ATTEMPT_LEDGER_2026-06-15.md) (**ledger único 32 RT2 + ~28 renames**), [FFX_THUNDAFIRA_DRAW_PATH_ONEPAGER_2026-06-15.md](docs/reverse/FFX_THUNDAFIRA_DRAW_PATH_ONEPAGER_2026-06-15.md), [FFX_THUNDAFIRA_DATAA_B50_DIFF_2026-06-15.md](docs/reverse/FFX_THUNDAFIRA_DATAA_B50_DIFF_2026-06-15.md), [FFX_THUNDAFIRA_ASSET_IDENTITY_MAP_2026-06-15.md](docs/reverse/FFX_THUNDAFIRA_ASSET_IDENTITY_MAP_2026-06-15.md).
- Magic: [FFX_MAGIC_RT2_VISUAL_QUEUE_TOP10_2026-06-15.md](docs/reverse/FFX_MAGIC_RT2_VISUAL_QUEUE_TOP10_2026-06-15.md), [FFX_MAGIC_ELEMENT_OVERLAY_DIFF_2026-06-15.md](docs/reverse/FFX_MAGIC_ELEMENT_OVERLAY_DIFF_2026-06-15.md), [FFX_MAGIC_ENGINE_OVERLAY_CARRIER_PROFILE_FULL_2026-06-15.md](docs/reverse/FFX_MAGIC_ENGINE_OVERLAY_CARRIER_PROFILE_FULL_2026-06-15.md) (#19b).
- RT2 humano: [FFX_PRISM_FLARE_RT2_CHECKLIST_2026-06-15.md](docs/reverse/FFX_PRISM_FLARE_RT2_CHECKLIST_2026-06-15.md), [FFX_ARENA_PLUS_BOSS_TOKEN_TABLE_2026-06-15.md](docs/reverse/FFX_ARENA_PLUS_BOSS_TOKEN_TABLE_2026-06-15.md), [FFX_ARENA_PLUS_GIL_RT2_SCENARIOS_2026-06-15.md](docs/reverse/FFX_ARENA_PLUS_GIL_RT2_SCENARIOS_2026-06-15.md).

Implementação viva (pode superseder pesquisa): `SESSION_HANDOFF.md` entradas Jarvis-MAGIC / Jarvis-ARENAPLUS (tint `0x37710`, live dataA vs PE, Arena+ OST v5).

## ONDA 2026-06-15 — Research queue Jarvis-HEAVY H01–H15 (offline encerrada)

Pesquisas profundas paralelas (GPT 5.5 / chats dedicados): ThundaFira tint/draw, Magic VM/PE diff, Arena+ OST timeline, AutoAbility bytes, fps-scout, offline CI, event JP encoding, Sphere Grid UI spec. **Research-only** — não promover RT2 sem evidência in-game.

- **Sphere Grid True New Node follow-up (`v2.141.0.1`, 2026-06-18):** [FFX_SPHEREGRID_EXIT_POST_A54860_RE_2026-06-18](docs/reverse/FFX_SPHEREGRID_EXIT_POST_A54860_RE_2026-06-18.md) — exit vanilla `FFX_Abmap_ExitConfirmPersistAndLeave@0xA56060` chama `A5BB70 → A54860 → FFX_Abmap_DeactivateAndReturnToFieldUI@0x8E27E0`; menu ptr não anulado; suspeitos pós-probe RT2 = UI mode transition + render teardown. Hook v5.1 corrige writeback `after-A5BB70` e observe-only em recompute.
- **Sphere Grid True New Node follow-up (`v2.140.0.8`, 2026-06-18):** [FFX_SPHEREGRID_ABMAP_MENU_STATE_STATIC_BUFFER_RE_2026-06-18](docs/reverse/FFX_SPHEREGRID_ABMAP_MENU_STATE_STATIC_BUFFER_RE_2026-06-18.md) — `dword_2305834` / `g_FFX_AbmapMenuStatePtr` não é heap undersized; `FFX_Abmap_InitStaticMenuStateBuffers@0xA572E0` aponta para buffer estático `0x12FC0`, node records `1024 * 0x28`; hipótese A5BB70 OOB por allocator 860 **refutada**. True New Node segue LAB/RT2-blocked; próximo gate é probe pós-`A54860`/`after-A5BB70`.
- [docs/reverse/FFX_RESEARCH_CHAT_GENERATED_FILES_2026-06-15.md](docs/reverse/FFX_RESEARCH_CHAT_GENERATED_FILES_2026-06-15.md) — **índice mestre H01–H15** + código tocado (`EventRt0`, fps-scout já em `dllmain`).
- ThundaFira: [SUB_71B980](docs/reverse/FFX_THUNDAFIRA_SUB_71B980_IDA_2026-06-15.md) (H01), [LIVE_PE_REGION_MAP](docs/reverse/FFX_THUNDAFIRA_LIVE_PE_REGION_MAP_2026-06-15.md) (H02), [KETHRES_BLOB_OPCODE](docs/reverse/FFX_THUNDAFIRA_KETHRES_BLOB_OPCODE_MAP_2026-06-15.md) (H03), [TINT_37710_XREF](docs/reverse/FFX_THUNDAFIRA_TINT_37710_XREF_2026-06-15.md) (H04). **Wave 5 corpus:** [FFX_MAGIC_DLL_WAVE5_KETHRES_CORPUS](docs/reverse/FFX_MAGIC_DLL_WAVE5_KETHRES_CORPUS_2026-06-15.md) (114/116 Family D `dataA` idêntico ao 0094), [FFX_MAGIC_WAVE5_EXE_PPP_HOST_BATCH](docs/reverse/FFX_MAGIC_WAVE5_EXE_PPP_HOST_BATCH_2026-06-15.md). Hook PPPDRAW inline EXE **aposentado** — ver [DEAD_ENDS](docs/reverse/FFX_THUNDAFIRA_DEAD_ENDS_INDEX_2026-06-15.md).
- **Magic DLL RT2 ledger (`v2.115.0.1`–`v2.116.0.3`):** blue vec4 Family C/D = timing-risk (`FFX_MAGIC_DLL_POSSIBLE_TIMING_VEC4_FAMILY_D`); **32 tentativas** documentadas (`FFX_MAGIC_DLL_RT2_ATTEMPT_LEDGER`); editor `MagicDllRt2VerdictCatalog` bloqueia offsets mortos Thundaga `0094`/`0716` e marca `0718` timing provado.
- **Flan Flood / Sin skills (`v2.114.0.0`+):** clone Waterga `0718/0719`, row monmagic2 #249 `0x60F9`, phyre magma ([LAB](docs/reverse/FFX_FLAN_FLOOD_FLAMEFLAN_LAB_2026-06-15.md), [playbook](docs/reverse/FFX_FLAN_FLOOD_RECOLOR_PLAYBOOK_2026-06-15.md), [DLL timing RT2](docs/reverse/FFX_FLAN_FLOOD_DLL_TIMING_RT2_FAIL_2026-06-15.md)); Spira Reforge [SIN_INFECTED_MONSTER_SKILLS](mods/Spira%20Reforge/SIN_INFECTED_MONSTER_SKILLS.md).
- **Ability SFX (2026-06-15, `v2.119.0.0`):** Tier 2 Phase 2 **novo seId** sem overwrite — FSB append (`FsbDumpDatAppender`), FEV registration + `9999_common.txt` row, triple pack — [I36](docs/reverse/FFX_FEV9999_SEQUENCE_CLONE_INFERNO_2026-06-15.md), [I35](docs/reverse/FFX_FEV_LEGACY_SEQUENCE_WRITER_2026-06-15.md). Gates: `--fsb9999-append-lab`, `--fev9999-sequence-clone-wave9`, `--command-sound-new-seid-pack`; UI **New seId slot**. Offline RT0 PASS; RT2 in-game pendente.
- **Ability SFX (2026-06-15, `v2.117.0.0`):** Tier 2 Phase 1 custom WAV via FSB sample replace (fsbext+vgmstream) — [I34](docs/reverse/FFX_FEV9999_SEID_TO_FSB_SAMPLE_INFERNO_2026-06-15.md). Gates: `--fsb9999-lab`, `--fev9999-seid-map-wave8`, `--command-sound-custom-pack`; UI Custom WAV panel; bootstrap `scripts/bootstrap_fsb_audio_tools.ps1`. RT2 in-game custom FSB pendente.
- **Ability SFX (2026-06-15, `v2.116.0.0`):** som de spell **não** é coluna do kernel — pipeline FMOD via SeSep na magic DLL ([I31](docs/reverse/FFX_ABILITY_SFX_FMOD_STREAMING_INFERNO_2026-06-15.md), [I32](docs/reverse/FFX_MAGIC_DLL_ABILITY_SFX_CORPUS_INFERNO_2026-06-15.md), [I33](docs/reverse/FFX_FEV9999_SEQUENCE_INDEX_INFERNO_2026-06-15.md), [matrix](docs/reverse/FFX_ABILITY_SFX_INTEGRATION_MATRIX_2026-06-15.md)). Gates: `--magicdll-sound-corpus-wave6`, `--command-sound-rt0`, `--command-sound-pack`, `--fev9999-corpus-wave7`, `--command-sound-custom-wizard`; UI Battle SFX editável + Magic DLL SeSep tab; `AbilitySfxHook` lab. RT2 in-game pendente.
- Magic: [0083_0087_PE_DIFF](docs/reverse/FFX_MAGIC_0083_0087_PE_DIFF_2026-06-15.md) (H05), [VM_TINT_HANDLERS](docs/reverse/FFX_MAGIC_VM_TINT_HANDLERS_IDA_2026-06-15.md) (H06), [ENGINE_OVERLAY_CARRIER_CONTEXT](docs/reverse/FFX_MAGIC_ENGINE_OVERLAY_CARRIER_CONTEXT_2026-06-15.md) (H07), [0084_HOST3732_PATCH_MAP](docs/reverse/FFX_MAGIC_0084_HOST3732_PATCH_MAP_2026-06-15.md) (H08).
- Gameplay/infra: [BTL_GET_CALC_RESULT_IDA_TABLE](docs/reverse/FFX_BTL_GET_CALC_RESULT_IDA_TABLE_2026-06-15.md) (H09), [ARENA_PLUS_MUSIC_TIMELINE](docs/reverse/FFX_ARENA_PLUS_MUSIC_TIMELINE_CONSOLIDATED_2026-06-15.md) (H10), [AUTOABILITY_SLOTS_129_133_BYTES](docs/reverse/FFX_AUTOABILITY_SLOTS_129_133_BYTES_2026-06-15.md) (H11), [FPS_SCOUT_IMPLEMENTATION](docs/reverse/FFX_FPS_SCOUT_IMPLEMENTATION_2026-06-15.md) (H12), [OFFLINE_CI_RECONCILE](docs/reverse/FFX_OFFLINE_CI_RECONCILE_2026-06-15.md) (H13), [EVENT_TEXT_ENCODING_REGRESSION](docs/reverse/FFX_EVENT_TEXT_ENCODING_REGRESSION_2026-06-15.md) (H14 — gate `--event-rt0` JP leads `13/13`), [SPHEREGRID_BUILDER_UI_SPEC](docs/reverse/FFX_SPHEREGRID_BUILDER_UI_SPEC_2026-06-15.md) (H15).
- Ronso Mana (paralelo, não H-lote): **bíblia lane** — [KIMAHRI_ONLY_IDA_MAP](docs/reverse/FFX_RONSO_MANA_KIMAHRI_ONLY_IDA_MAP_2026-06-15.md), [JUNCTIONS_WAVE2](docs/reverse/FFX_KIMAHRI_JUNCTIONS_IDA_WAVE2_2026-06-15.md), [HOOK_IDA](docs/reverse/FFX_RONSO_MANA_HOOK_IDA_2026-06-15.md), [DRAIN_G2_COMPLETE](docs/reverse/FFX_RONSO_MANA_DRAIN_G2_COMPLETE_2026-06-15.md), actor struct [AURORA_0xF90_DEEP](docs/reverse/FFX_AURORA_ACTOR_0xF90_STRUCT_C_DEEP_2026-06-15.md); brief [BLUE_MAGE](docs/reverse/FFX_RONSO_MANA_BLUE_MAGE_SYSTEM_RESEARCH_BRIEF_2026-06-15.md). **DLL:** `hudSafe=5` `v2.112.0.13` — G1'+G0+G3'+G2; RT2 reabrir submenu pendente; drain PASS.
- MonEditor battle models: [FFX_BATTLE_MODEL_CATALOG_MONEDITOR](docs/reverse/FFX_BATTLE_MODEL_CATALOG_MONEDITOR_2026-06-15.md) — catálogo FFXmon + preview Model1/Model2 `v2.112.0.0`.

Complementa a fila troxa ([índice](docs/reverse/FFX_RESEARCH_QUEUE_TROUXA_INDEX_2026-06-15.md)); abrir só o doc da tarefa ativa.

## ONDA 2026-06-15 — Mods / Spira Reforge (MG pesquisa GPT 5.5)

Pacote mod versionado em [`mods/`](mods/). Bíblia: [`mods/Spira Reforge/VISION_AND_ROADMAP.md`](mods/Spira%20Reforge/VISION_AND_ROADMAP.md).

> **Reconciliação 2026-09-23 (Halyson, in-game):** questionário item-a-item confirmou funcional a maior parte do que os docs marcavam como pendente/lab — Arena+ ladder completa (duo→penta RT2, catálogo consumido, progressão via `BattleEndHook`→`RecordCleared`, tiers UI), Custom Mix disco **e** CustomMix Ultra RAM, GridTeach, Lancet dual grant, Double/Triple Drop (rows grown até idx 134 no `a_ability.bin`), S.I.N. RAM submenu F7, Difficulty Director, SinCurseHook, MusicHook, F8/F9, Speed Hack; extended commands resolvidos (Biora→Lulu `#348` no bin, Drainga MP68/Osmose-ga MP12, Yuna *ga MP↑, Flare/Ultima); Monster AI Overdrive provado em qualquer monstro. **Pendentes reais:** Capture Cascade (Cap-1/2/3, UI, bestiary), Omega Ruins inteiro, SIN·DA clones, AP boost DA, SIN finalização (curses/presets, curva por área doc-only, tutorial gate/popup, rosters só Macalania), Sphere Grid wire + Pacote B, textos in-game, `arms_rate[134]`, armor pass, Break Limits/Devil's Bargain/Mana Spring, party reworks (Lulu Fury, Auron, Tidus/Wakka, Copycat-QH, Auron HP>99k, cast speed), Dark Aeon stat revert. QH CTB Rank = decidido não mexer. Detalhe completo no `PORT_STATUS.md` (entrada 2026-09-23) e nos docs do mod.

> **Encontros (censo/sync em disco 2026-09-23):** fonte com 99 lineups existentes alterados e
> `nagi05_46` novo; quatro overlays mantêm o chunk 2 do baseline. O sync posterior alinhou os 568
> bins ativos do pacote à instalação (104/104 BTL e 0 hashes divergentes). Ver `PORT_STATUS.md`;
> isso não é nova prova de RT2.


- **Maratona pesquisa:** [`docs/ai/FFX_MODS_MEGA_RESEARCH_PROMPT_GPT55_2026-06-15.md`](docs/ai/FFX_MODS_MEGA_RESEARCH_PROMPT_GPT55_2026-06-15.md) — **M01–M30** (Spira Patch, party meta, Arena+, Modo SIN, Forbidden Rite, OD/multicast, tooling matrix, IDEAs).
- **Índice M01–M30:** [`docs/reverse/FFX_MODS_MEGA_RESEARCH_INDEX_2026-06-15.md`](docs/reverse/FFX_MODS_MEGA_RESEARCH_INDEX_2026-06-15.md) — 29 docs + matriz de status, top RT2/IDEAs e plano 90 dias. Tipo: **síntese operacional research-only**, não deep IDA por item.
- **Auditoria:** [`docs/reverse/FFX_MODS_MEGA_RESEARCH_AUDIT_2026-06-15.md`](docs/reverse/FFX_MODS_MEGA_RESEARCH_AUDIT_2026-06-15.md) — registra gap honesto contra o alvo 250–500 linhas/doc e sugere deep follow-up M01/M10/M14/M15/M26.
- Spec bulk edit: [`docs/specs/SPIRA_PATCH_FORMAT_2026-06-15.md`](docs/specs/SPIRA_PATCH_FORMAT_2026-06-15.md).
- Modo SIN: [`mods/Spira Reforge/arena/SIN_DIFFICULTY_MODE_SPEC.md`](mods/Spira%20Reforge/arena/SIN_DIFFICULTY_MODE_SPEC.md).

### Extended battle submenus — viável sem quebrar o jogo (`2026-06-23`, RT2 parcial)

**Veredito:** novos menus de batalha (opener + filhas) **funcionam** com `command.bin` grow + `GridTeachHook` v4.5 — **sem** UI nativa nova por menu. Yuna **White Magic+ `#366`** = RT2 **PASS**; Kimahri **Blue Magic `#322`** exigiu separar filhas para `sub=14` (+232) longe do anel OD (+296).

- **Doc canônico:** [`docs/reverse/FFX_EXTENDED_BATTLE_SUBMENU_FEASIBILITY_2026-06-23.md`](docs/reverse/FFX_EXTENDED_BATTLE_SUBMENU_FEASIBILITY_2026-06-23.md)
- Casos: [`FFX_YUNA_WHITE_MAGIC_PLUS_MENU_2026-06-23.md`](docs/reverse/FFX_YUNA_WHITE_MAGIC_PLUS_MENU_2026-06-23.md), [`FFX_KIMAHRI_BLUE_MAGIC_MENU_RING_FIX_2026-06-23.md`](docs/reverse/FFX_KIMAHRI_BLUE_MAGIC_MENU_RING_FIX_2026-06-23.md), [`FFX_GRID_TEACH_EXTENDED_BANK_WIDEN_2026-06-23.md`](docs/reverse/FFX_GRID_TEACH_EXTENDED_BANK_WIDEN_2026-06-23.md)

### Capture Cascade (Spira Reforge feature) — Phases A + B + C (`v2.122.0.1` → `v2.123.3.1` → `v2.127.0.0`)

Captura DA com Capture weapon vanilla "acorda" a regiao canonica (T7 SIN-curse). Decomposto em Cap-1 (popup + flag), Cap-2 (region T7 override), Cap-3 (DA-patrulha em encounter). Player-facing brand: **Yoke of Spira / Jugo de Spira**.

- **Master research doc:** [`docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_CASCADE_RESEARCH_2026-06-16.md`](docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_CASCADE_RESEARCH_2026-06-16.md) — design completo, decisoes Halyson 8/8, naming convention dual.
- **Phase A artefatos (`v2.123.0.2`):** sidecar schema [`spira-reforge-flags.schema.json`](mods/Spira%20Reforge/save-schemas/spira-reforge-flags.schema.json), region map [`dark-aeon-region-map.json`](mods/Spira%20Reforge/arena/dark-aeon-region-map.json) (8 DA → área canônica + safe-zones; bumped v0.6.0 com `m_id` canônicos em `v2.123.3.1`).
- **Phase B RE spike RESULT (`v2.123.3.1`, Jarvis-CAPTURE-RE):** [`docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_BIT_M_HEADER_RE_RESULT_2026-06-16.md`](docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_BIT_M_HEADER_RE_RESULT_2026-06-16.md) — byte `capturable` localizado: `bytes[StatSheetPointer + 0x78]` (`0xFF`=uncap, `0x00..0x67`=slot Monster Arena vanilla 104), validado com **58 amostras**, byte-precisão estrutural via `FfxLib/Monster/Monster_StatSheet.cs` linhas 49-50. **Correção operacional importante:** os Dark Aeons reais são `m334..m343` (NÃO `m106..m113`); Magus Sisters = `m341/m342/m343` (3 entries separadas); Penance + bracos = `m344..m346`. Receita do writer Phase C inclusa na §5.1 do RESULT.
- Phase B PLAN doc (handoff original): [`docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_BIT_M_HEADER_RE_PLAN_2026-06-16.md`](docs/reverse/FFX_SPIRA_REFORGE_CAPTURE_BIT_M_HEADER_RE_PLAN_2026-06-16.md) — banner `BLOQUEIO RESOLVIDO` no topo + IDs DA corrigidos.
- Scripts read-only de evidência: [`work/_capture_re_2026-06-16/`](work/_capture_re_2026-06-16/) — parser CLI + bulk dump + JSON 58 rows + hex dump forense.
- **Phase C writer + RT0 gate (`v2.127.0.0` MINOR, Jarvis-CAPCAS-WRITE, 2026-06-16):** writer offline da capture flag pronto e validado em **361/361 vanilla `m###.bin`** (corpus completo `D:\FFX Extracted\FFX\ffx_ps2\ffx\master\jppc\battle\mon`). API: [`FFXProjectEditor/FfxLib/Monster/MonsterCaptureFlagWriter.cs`](FFXProjectEditor/FfxLib/Monster/MonsterCaptureFlagWriter.cs) (`WriteCaptureFlag(byte[] monBin, byte newSlot)` retorna copia, escreve em `bytes[StatSheetPointer + 0x78]`, recusa variantes onde `+0x79` != `0x00`). Gate: [`FFXProjectEditor/Tools/MonsterCaptureFlagRt0.cs`](FFXProjectEditor/Tools/MonsterCaptureFlagRt0.cs) — 3 invariantes (same-value byte-identity, slot-only diff em 1 byte, flip-and-restore round-trip), wired no `Program.cs` via `--monster-capture-bit-rt0` e em `RuntimeTools/offline_ci.ps1` (`monster-capture-bit`). Resultado: zero variantes de padding (`+0x79` `0x00` em todas as 361). Bloqueios remanescentes: Cap-1 RT2 in-game (Halyson — gravar slot Arena num `m###.bin`, ver popup correto, capturar in-battle; nao depende mais de RE), Phase D UI (Capture Cascade tab no `MonsterEditor`).

## ONDA 2026-06-16 — Aurora finalizacao balistica (Jarvis-AURORA, plano 10-fases offline ENCERRADO)

Plano `.cursor/plans/aurora_balistica.plan.md` (escopo A+B aprovado pelo Halyson) executado pelo lado offline; 5 RT2 ativas pre-armadas + 1 spike IDA bloqueado em humano. Saga shippada em **4 bumps** (`v2.123.5.1` REVISION → `v2.125.0.0` MINOR → `v2.125.1.0` PATCH → `v2.125.1.1` REVISION).

- **Fases concluidas:** F0 reconciliacao docs (corrige Honestidade do `Aurora Chamber` no `PORT_STATUS.md`, comentario JSDoc legado no `aurora-overlay.js`, badge `runtime selector UNVERIFIED` na UI do `AuroraChamber`); F1 [aurora-calib-v2 probe](docs/reverse/FFX_AURORA_CALIBRATION_PROBE_SPEC_2026-06-15.md) (CSV/JSON com residual `identity`/`flipz`/`yaw180` + `height_0x534`); F3 offline (drag preview diff `(orig) → (new) Δ=(...)` no overlay); F5 gate `camera-chunk0-edit-rt0` ja coberto pelo `BattleCameraScanLab` (gate C08 do `offline_ci.ps1`); F6 PhotoMode wiring no `FfxHooksDll` ja completo (`Tick()` no Present hook, `Enter`/`Exit` via `NativeMenu`); F7 spike IDA W2S consolidado em [3 docs deep](docs/reverse/FFX_AURORA_W2S_MATRIX_OWNER_IDA_DEEP_2026-06-15.md); F8 spike IDA variant selector consolidado em [3 docs](docs/reverse/FFX_AURORA_ARENA_VARIANT_SELECTION_RE_2026-06-15.md).
- **RT2 fila pre-armada (Halyson):** F2 calib-v2 em 4 batalhas golden + analise residuo Y; F3 RT2 drag position-only; F4 grow normal nao-Dark Aeon; F5 RT2 polar edit; F6 RT2 PhotoMode minimo. Recipe completa em [FFX_AURORA_FORCE_BATTLE_CALIBRATION_PROTOCOL_2026-06-15.md](docs/reverse/FFX_AURORA_FORCE_BATTLE_CALIBRATION_PROTOCOL_2026-06-15.md) e [FFX_AURORA_MASTER_RT2_CHECKLIST_2026-06-15.md](docs/reverse/FFX_AURORA_MASTER_RT2_CHECKLIST_2026-06-15.md).
- **Bloqueios remanescentes:** W2S owner final + selector oracle hook (RVA do selector nativo precisa de `.i64` local destravada para o `idalib-mcp`); variant selector RE (mesma dependencia).

## ONDA 2026-06-15 — MEGA Research marathon (GPT 5.5 sintético + deep follow-up)

Maratona única: **23 docs** Aurora/gameplay + [índice mestre](docs/reverse/FFX_MEGA_RESEARCH_INDEX_2026-06-15.md). Tipo: **síntese operacional** (~50 linhas/doc) — útil para RT2 queue e placar, não substitui IDA deep.

- [FFX_MEGA_RESEARCH_AUDIT_2026-06-15.md](docs/reverse/FFX_MEGA_RESEARCH_AUDIT_2026-06-15.md) — auditoria pós-marathon (o que é provado vs síntese).
- [FFX_MEGA_RESEARCH_DEEP_INDEX_2026-06-15.md](docs/reverse/FFX_MEGA_RESEARCH_DEEP_INDEX_2026-06-15.md) — deep follow-up **concluído** (D01–D07, ~260–390 linhas/doc).
- [FFX_MEGA_RESEARCH_DEEP_FOLLOWUP_PROMPT_GPT55_2026-06-15.md](docs/ai/FFX_MEGA_RESEARCH_DEEP_FOLLOWUP_PROMPT_GPT55_2026-06-15.md) — prompt autor da maratona D01–D07.
- Deep D01–D07: [W2S owner](docs/reverse/FFX_AURORA_W2S_MATRIX_OWNER_IDA_DEEP_2026-06-15.md), [chunk3 spawn](docs/reverse/FFX_AURORA_CHUNK3_SPAWN_LOOP_IDA_DEEP_2026-06-15.md), [arena variant](docs/reverse/FFX_AURORA_ARENA_VARIANT_IDA_DEEP_2026-06-15.md), [actor 0xF90](docs/reverse/FFX_AURORA_ACTOR_0xF90_STRUCT_C_DEEP_2026-06-15.md), [camera FSM](docs/reverse/FFX_AURORA_CAMERA_CHUNK0_RUNTIME_FSM_DEEP_2026-06-15.md), [btlGetCalcResult](docs/reverse/FFX_BTL_GET_CALC_RESULT_RUNTIME_DEEP_2026-06-15.md), [ground height Y](docs/reverse/FFX_AURORA_GROUND_HEIGHT_CORPUS_DEEP_2026-06-15.md).
- Aurora (A01–A15): começar por [MASTER_RT2_CHECKLIST](docs/reverse/FFX_AURORA_MASTER_RT2_CHECKLIST_2026-06-15.md), [CALIBRATION_PROBE_SPEC](docs/reverse/FFX_AURORA_CALIBRATION_PROBE_SPEC_2026-06-15.md), [W2S_MATRIX_IDA_CHAIN](docs/reverse/FFX_AURORA_W2S_MATRIX_IDA_CHAIN_2026-06-15.md).
- Extras (C01–C08): [RONSO_MANA_DRAIN_G2](docs/reverse/FFX_RONSO_MANA_DRAIN_G2_COMPLETE_2026-06-15.md), [OFFLINE_CI_PORT_STATUS_PATCH](docs/reverse/FFX_OFFLINE_CI_PORT_STATUS_PATCH_2026-06-15.md), [DAMAGE_CAP_CONSOLIDATED](docs/reverse/FFX_DAMAGE_CAP_RESEARCH_CONSOLIDATED_2026-06-15.md).

**RT2 Halyson (top 5 do índice):** aurora-calib-v2 → drag position-only → grow 1 ator → selector oracle/W2S → Ronso G2 log-only.

## ONDA 2026-06-13 — 60fps / frame-pacing / FPS unlock (research-only)

Pesquisa de viabilidade para destravar Final Fantasy X HD PC para minimo 60fps. Veredito: nao tratar como "trocar um cap"; separar `visual 60` por frame generation/interpolacao externa, frame pacing 30fps, render 60 com simulacao 30/interpolador interno, e `engine-exact 60fps` como moonshot ate scout provar os clocks. Follow-up do usuario aceita cutscenes/FMV em 30fps e mira gameplay, o que reduz sync audiovisual mas nao elimina os clocks separados de field, battle, MSEQ, camera, CTB, magia/VFX, menus, loads e minigames.

- [docs/reverse/FFX_GAMEPLAY_60FPS_DEEP_RESEARCH_2026-06-13.md](docs/reverse/FFX_GAMEPLAY_60FPS_DEEP_RESEARCH_2026-06-13.md) — dossie `v2.88.1.4` Jarvis-GAMEPLAY60: recorta o alvo como gameplay 60 com cutscenes/FMV em 30; define sucesso por camada, detalha as 4 rotas (`visual 60`, frame pacing/VRR/Present doctor, render 60 com simulacao 30/interpolador, `engine-exact 60fps` moonshot), e especifica o `fps-scout` read-only com CSV/summary de `Present`, heartbeat/tick, modo de jogo, MSEQ cursor e compat UnX/SpecialK antes de qualquer patch.
- [docs/reverse/FFX_60FPS_UNLOCK_FEASIBILITY_RESEARCH_2026-06-13.md](docs/reverse/FFX_60FPS_UNLOCK_FEASIBILITY_RESEARCH_2026-06-13.md) — dossie Jarvis-FPS: cruza UnX/SpecialK, Steam, DINPUT8/main-thread do repo, hook de `Present`, MSEQ `frameRate=7680 (30fps*256)` e a fronteira Magic/runtime. Proximo passo seguro: `fps-scout` read-only em `FfxHooksDll`/`FfxDinput8Probe`, medindo `Present`, tick, cursor MSEQ e modo de jogo antes de qualquer patch.

## ONDA 2026-06-11 — Monster AI: ciclos dinamicos, Multi-* e Anti-Ribbon

Sessao Monster AI Editor focada em leitura humana de comportamento, alvos calculados e bugfixes do `Forbidden Rite LAB`. Estes docs registram conhecimento de design/RE para autoria futura; nem tudo e writer publico ainda.

**Nota operacional 2026-06-13:** `Monster AI Editor 2` foi 100% descontinuado por decisao do usuario e nao deve mais ser mexido. Nao adicionar feature, fix, refactor ou fluxo novo em `MonsterAiEditor2_*`; usar o `Monster AI Editor` principal como superficie ativa.

- [docs/ai/MONSTER_AI_EDITOR_LATEST_ACHIEVEMENTS_RESEARCH_2026-06-13.md](docs/ai/MONSTER_AI_EDITOR_LATEST_ACHIEVEMENTS_RESEARCH_2026-06-13.md) — dossie Jarvis das conquistas recentes do `Monster AI Editor`: separa `RT2 byte-local/producao`, `offline forte pronto para RT2` e `LAB/research`; revalida em 2026-06-13 `--ai2`, `--ai3`, `--phase-rotation-rt0`, `--multivar-guard-rt0`, `--names`, `--var-grow`, `--var-flow`, `--sin-census`, `--sin-grimoire` e build do editor. Guardrail atualizado: `PhaseRotationRecipe` e Overdrive seguem exigindo RT2 especifico antes de wording publico de gameplay; `Prism Flare` teve RT2 visual confirmado para o recorte de recolor Fira-like, sem provar todas as familias/layers de magia.
- [docs/ai/MONSTER_AI_OVERDRIVE_DYNAMIC_FLOW_RESEARCH_2026-06-13.md](docs/ai/MONSTER_AI_OVERDRIVE_DYNAMIC_FLOW_RESEARCH_2026-06-13.md) — nova tentativa Jarvis para Overdrive de monstros: corrige o setup de barra para o shape corpus-backed `writeChrProperty(Self,field,value)` via `7018` (separado do botao generico `setStatField 70AB`), adiciona `AiScriptLab --overdrive-flow` e revalida `--overdrive-gauge-rt0` com `346/346` scripts. O censo achou `44` candidatos, `26` setups de gauge, `21` full-flow candidates e `39` scripts com tracked `writeChrProperty`; carga dinamica/finisher automatico seguem LAB/RT2.
- [docs/ai/MONSTER_AI_OVERDRIVE_AUTHORING_RECIPE_2026-06-13.md](docs/ai/MONSTER_AI_OVERDRIVE_AUTHORING_RECIPE_2026-06-13.md) — implementacao da receita autoral LAB no `Monster AI Editor`: setup da barra, inicio vazio/cheio/custom e bloco `Forbidden Overdrive Mode` vermelho para carga composta direta por `OverdriveCurrent`. A carga composta usa condicoes normais de IA (`guard/hook -> payload`): turno do monstro/onHit/HP/chance/dano recebido %, apos acao selecionada, contador de turnos/fase, faixa de HP, status no monstro, party/alvo, dano zero/evitado e ultimo atacante vivo; fisico/magico/reducao/status/cura ficam como categorias de pesquisa sem writer. A receita tambem cobre clamp, sequencia de habilidades, reset, opcao `Usar assim que a barra estiver cheia (fora do turno)` com prova RT2 no `m020` e atualizacao/limpeza de receita existente, incluindo o shape inline apos acao. `--overdrive-authoring-rt0` PASS em `work\monster_ai_overdrive_authoring_forbidden_conditions_20260613.json`: `330/330`, after-action `293/293`, onHit extras `307/307`, strip false-positive `0`, footprint limpo `330/330`; build `work\_build_overdrive_forbidden_conditions_20260613` passou. `--overdrive-modes` achou `11` writes de `OverdriveMode` no corpus de monstros, todos `0x13/Aeon`, sem reads; teste RT2 posterior no `m020` escreveu `Aeon 0x13`, mas a barra nao carregou sozinha (`gaugeAddWrites=0`). Os writes de `OverdriveMode` foram removidos da UI ativa; multi-modo/carga nativa garantida continua sendo frente DLL/hook chamando a soma/clamp nativa. Teste do usuario no `m020` provou barra visual, carga ao apanhar ingame, `Heavenly Strike` (`0x4095`) ao encher no turno do monstro e uso imediato ao encher fora do turno; teste em Flan comum tambem provou `Ao apanhar`. Universalidade absoluta e novas condicoes gameplay seguem RT2-pendentes; carga passiva independente de turno/hit fica como pesquisa runtime/DLL no edge CTB `0x791000 -> 0x7B13D0` ou throttle equivalente.
- Atualizacao Jarvis 2026-06-13: o multiselect `OverdriveMode comum via ETEL` e depois o checkbox `OverdriveMode: Aeon 0x13` foram removidos; o authoring ativo agora separa `Barra` de `Forbidden Overdrive Mode`, que soma `OverdriveCurrent` por condicoes do AI script e nao escreve `OverdriveMode` nativo.
- [docs/reverse/FFX_OVERDRIVE_MODE_NATIVE_RUNTIME_RESEARCH_2026-06-13.md](docs/reverse/FFX_OVERDRIVE_MODE_NATIVE_RUNTIME_RESEARCH_2026-06-13.md) — pesquisa IDA do runtime nativo de OverdriveMode: `MemoryChr+0x5BB/5BC/5BD`, getter `0x795560/0x7955A0`, add/clamp central `0x7B15A0`, eventos nativos por modo (`0x7B0D60`, `0x7B12D0`, `0x7B0F90`, `0x7B13D0`, `0x7B10A0`, `0x7B1550`). Prova RE forte de que modos `0x00..0x10` e `0x13` tem rota nativa; `Unused1/Unused2` sem caller observado. Guardrail: o campo nativo ainda e um unico byte; multi-modo real exige `Forbidden OverdriveMode DLL LAB` hookando eventos e chamando `sub_7B15A0`.
- [docs/ai/MONSTER_AI_SEYMOUR_NATUS_DYNAMIC_MULTI_TARGETING_2026-06-11.md](docs/ai/MONSTER_AI_SEYMOUR_NATUS_DYNAMIC_MULTI_TARGETING_2026-06-11.md) — Seymour Natus (`m126`) mostra que `Multi-*` de monstro pode ser acao composta por script: comandos extras via `addCommand`, rotacao em `battleVar`, alvo calculado e dois casts sequenciais.
- [docs/ai/MONSTER_AI_DARK_FLAN_PROBABILITY_TREE_AUTHORING_2026-06-11.md](docs/ai/MONSTER_AI_DARK_FLAN_PROBABILITY_TREE_AUTHORING_2026-06-11.md) — Dark Flan (`m021`) como arvore/roleta de probabilidade, com `RET`/parada como semantica humana obrigatoria para nao vender falso combo.
- [docs/ai/MONSTER_AI_DYNAMIC_CYCLE_AUTHORING_NOTES_2026-06-11.md](docs/ai/MONSTER_AI_DYNAMIC_CYCLE_AUTHORING_NOTES_2026-06-11.md) — padrao observado em Flame Flan: chance -> acao -> status direto opcional -> parar ou continuar, incluindo o caso honesto de "pular turno" se nenhuma acao obrigatoria existir.
- [docs/ai/MONSTER_AI_PHASE_ROTATION_VAR_MODEL_VALIDATION_2026-06-11.md](docs/ai/MONSTER_AI_PHASE_ROTATION_VAR_MODEL_VALIDATION_2026-06-11.md) — validacao do modelo de vars de fase: `var[n]` e indice em tabela de variaveis independentes (`priv`/`battleVar`/`saveData`), nao um unico contador magico; Seymour Natus tem 19 vars e o corpus chega a 32.
- [docs/ai/MONSTER_AI_VAR_TABLE_GROW_AND_FLOW_RESEARCH_2026-06-11.md](docs/ai/MONSTER_AI_VAR_TABLE_GROW_AND_FLOW_RESEARCH_2026-06-11.md) — pesquisa de crescimento/uso de tabela de vars: usar vars existentes e seguro estruturalmente; criar nova var local `priv` fica em LAB com descriptor/slot livre e ainda exige RT2 antes de virar authoring publico.
- [docs/ai/MONSTER_AI_MULTIVAR_JUMP_RELEASE_RESEARCH_2026-06-12.md](docs/ai/MONSTER_AI_MULTIVAR_JUMP_RELEASE_RESEARCH_2026-06-12.md) — pesquisa do caminho para liberar `salto multivar`: primeiro builder de condicao booleana com `PUSHV`/comparadores/`LAND`/`LOR` + `AppendGuardedAction`; depois statements de var (`set/reset/add/copy`); so entao flowgraph/`SWITCH` com labels e jump-table propria.
- [docs/ai/MONSTER_AI_ATEL_VM_ASSEMBLY_BOUNDARY_VALIDATION_2026-06-12.md](docs/ai/MONSTER_AI_ATEL_VM_ASSEMBLY_BOUNDARY_VALIDATION_2026-06-12.md) — decisao de fronteira: ATEL nao e assembly nativo, mas e assembly de VM stack-based; authoring humano pode compilar para ATEL desde que opcode/stack/func-id/worker/jump/var estejam validados. Gates da sessao: base RT0 `361/361`, `--ai2` PASS e `--names` com `160` call ids nomeados.
- [docs/ai/MONSTER_AI_PROBABILITY_TREE_WINDOW_IDEA_2026-06-11.md](docs/ai/MONSTER_AI_PROBABILITY_TREE_WINDOW_IDEA_2026-06-11.md) — ideia preservada, mas retirada da UI principal: janela visual de arvore/roleta de probabilidades deve amadurecer antes de virar writer; por enquanto ciclos e roletas ficam no fluxo de condicoes/fases.
- [docs/ai/MONSTER_AI_COMMON_MONSTER_ATTACK_PATTERN_ATLAS_2026-06-11.md](docs/ai/MONSTER_AI_COMMON_MONSTER_ATTACK_PATTERN_ATLAS_2026-06-11.md) — atlas de padroes vanilla comuns: Dingo/Mi'ihen Fang/Garm/Snow Wolf/Bandersnatch usam roleta 50/50 entre menor HP vivo e alvo vivo aleatorio; Sand Wolf e simples; Shred e modelo composto com rota literal/fallback menor HP + rota aleatoria; Dinonix/Ipiria/Raptor/Melusine/Yowie/Zaurus/Iguion sao familia reptil linear com alvo vivo calculado e variante de ataque com status; Cave Iguion e variante linear simples/forte; Ornitholestes e lizard de arena/boss com roleta por fase de HP; Floating Eye/Buer/Bat Eye usam Gaze linear fraco, Evil Eye usa Gaze linear forte, Ahriman/Floating Death usam roleta Ultrasonics/Gaze, One-Eye e arena/boss com Shockwave/Black Stare + contador/menor HP; Condor/Simurgh/Alcyone usam roleta aerea com Wakka-priority (`2/3` tenta Wakka, fallback vivo; `1/3` vivo calculado); Pteryx e arena/boss com abertura Beak of Woe em Character#1/#2/#3 e depois procura alvo sem Curse; Yellow/White/Red/Gold/Blue Element sao magia fixa em alvo vivo calculado; Dark/Nega usam Reflect engine com self-cast intencional; Black Element usa rota status-first/Berserk com fallback Demi/Flare; Raldo/Bunyip/Murussu/Mafdet/Shred usam `casco dinamico 50/50` com alvo literal Auron/Character#2 + fallback menor HP ou vivo calculado; Halma e Swamp Mafdet sao lineares por contexto; Funguar/Thorn/Exoray sao casters lineares Fire/Fira/Firaga com counter Pollen em `FrontlineChars`; Sleep Sprout e arena/boss com abertura Goodnight, roleta de seis magias e counter fisico; Bomb/Grenade/Puroboros sao maquinas de estado com Fire/Fira/Firaga inicial, Grow2/Grow3 ao apanhar, `RUSH` depois de crescer e `Self-Destruct` em `LastAttacker` no terceiro dano relevante; Bomb King escala por hits (3/6/9) ate Ultima e nao usa Self-Destruct no CombatHandler lido; Dual Horn comum e roleta `1/3 Gore` + `2/3 Attack`, enquanto Valaha/Grendel usam estado entre turnos `Charging -> Flame Ball`; Iron Giant usa menor HP por ciclo e Reaper em grupo; Gemini A/B usam contador compartilhado de dano + espera/sync para Double Reaper, e quando sozinhos rolam Attack/Reaper/Leaping Swing; `m183`/`m325` sao falsos parentes.
- [docs/ai/SIN_LETHAL_EXPANSION_AND_RIBBON_BYPASS_PLAN_2026-06-08.md](docs/ai/SIN_LETHAL_EXPANSION_AND_RIBBON_BYPASS_PLAN_2026-06-08.md) — plano SIN/Anti-Ribbon atualizado com os fields negativos diretos do `btlActorProperty` e guardrail para Death/KO.
- [docs/reverse/FFX_ABILITY_EFFECT_AUTHORING_RESEARCH_2026-06-12.md](docs/reverse/FFX_ABILITY_EFFECT_AUTHORING_RESEARCH_2026-06-12.md) — LAB de magia nova + efeito visual: `--monmagic-grow-rt0` cria `Prism Flare` como nova row real de `monmagic2.bin` (`247 -> 248`, operand `0x60F7`); `--magic-effect-link-rt0` prova `Anim1Id/Anim2Id -> magic_####` e agora tambem valida `magicFiles\FFX\magic_####.dll`; `--magic-effect-assign-rt0` isola a row nova em clones dedicados `magic_0714/magic_0715` (clonados de `magic_0082/magic_0086`) para nao sobrescrever efeitos vanilla; `--ps3magic-recolor-rt0` prova nova cor same-shape em `magic_0714` com diff so no mip0. Status atualizado em 2026-06-26: RT2 visual do usuario confirmou que Prism Flare recolor muda de fato o efeito Fira-like; ThundaFira permanece parcial, com explosao/impacto recolor OK e raio inicial bloqueado.

## ONDA 2026-06-06 — Formatos de Evento/Fonte/Som/Script/Animacao crackados (RE, research-only)

Sessao IDA + corpus offline na `.i64` canonica. **3 formatos que nunca tinham sido decodados cairam** (encoding de texto de evento JP, VM de script ATEL, payload do cue de som SeSep). Tudo `research only` — sem writer publico ainda; o que destrava e leitura/edicao futura honesta. Doc-indice mestre primeiro:

- [docs/reverse/FFX_EVENT_FORMATS_MASTER_CRACK_2026-06-06.md](docs/reverse/FFX_EVENT_FORMATS_MASTER_CRACK_2026-06-06.md) — INDICE/resumo executivo da onda: ~20 funcoes nomeadas+comentadas na `.i64`, linka cada item abaixo; lido a implementacao real no EXE quando estatistica de corpus nao bastava.
- [docs/reverse/FFX_EVENT_TEXT_ENCODING_CRACKED_2026-06-06.md](docs/reverse/FFX_EVENT_TEXT_ENCODING_CRACKED_2026-06-06.md) — encoding de texto de evento JP (INEDITO): stream variavel 1-byte/2-byte sobre 6 font slots (`FFX_EventText_AdvanceCharGlyph@0x8B92E0`), verificado 324/324; expoe o bug do `FfxEncoding` que trata `0x26-0x2F` como controle (kanji vira `<MISS>`).
- [docs/reverse/FFX_EVENT_ATEL_VM_OPCODES_2026-06-06.md](docs/reverse/FFX_EVENT_ATEL_VM_OPCODES_2026-06-06.md) — VM de script de evento (linguagem ATEL, INEDITO): tabela de opcodes 0x00..0x7A decompilada (`FFX_Atel_InterpretWorkerOpcodes@0x864180`); mesmo dialeto que roda chunk0, IA de field actor e o schedule do cue SeSep — e o que o codec `FfxLib/Ai/AiScript_File` ja le.
- [docs/reverse/FFX_EVENT_SESEP_PAYLOAD_CRACKED_2026-06-06.md](docs/reverse/FFX_EVENT_SESEP_PAYLOAD_CRACKED_2026-06-06.md) — payload do chunk2 SeSep = descritor de cue de SOM (INEDITO): `+0x11 u16 waveDataId` (o sample SPU), `+0x08 seId`, `+0x13+` schedule; `FFX_SeSep_PreloadWaveData@0x81E710` pre-carrega; provado em 14.348 records / 267 samples.
- [docs/reverse/FFX_EVENT_SESEP_CONTENTLEN_SOLVED_2026-06-06.md](docs/reverse/FFX_EVENT_SESEP_CONTENTLEN_SOLVED_2026-06-06.md) — formula do `contentLen` do header SeSep: `X = (end_rec & ~0xF) - 0x10`, provado 348/348 offline (pass anterior so 101); destrava recompute byte-exato ao append/remover cue.
- [docs/reverse/FFX_EVENT_FTCX_IS_KANJI_SHEET_2026-06-06.md](docs/reverse/FFX_EVENT_FTCX_IS_KANJI_SHEET_2026-06-06.md) — identificacao do FTCX (chunk3): e a folha de glyphs de KANJI especificos do evento (celulas 14x18), confirmado VISUALMENTE renderizando o 4bpp pra PNG.
- [docs/reverse/FFX_EVENT_FTCX_PALETTE_FINDING_2026-06-06.md](docs/reverse/FFX_EVENT_FTCX_PALETTE_FINDING_2026-06-06.md) — "palette" do FTCX resolvida: NAO ha CLUT externa — o nibble 4bpp e intensidade/coverage (alpha), renderizado na cor corrente do texto; corpus 324/324.
- [docs/reverse/FFX_EVENT_FTCX_GLYPH_ORDER_2026-06-06.md](docs/reverse/FFX_EVENT_FTCX_GLYPH_ORDER_2026-06-06.md) — organizacao do FTCX = per-evento text-derived (NAO ordem-fixa/master-font); cada evento embute so os kanji do seu texto; provado no corpus (40/43 grupos de mesmo glyphCount tem bitmap diferente).
- [docs/reverse/FFX_MGRP_MSEQ_KEYFRAME_CODEC_PROVEN_2026-06-06.md](docs/reverse/FFX_MGRP_MSEQ_KEYFRAME_CODEC_PROVEN_2026-06-06.md) — codec de animacao keyframe (.mgrp/MSEQ) 100% reversado: container 20B → record → canais com modos 2-bit → stream RLE de deltas → pose; da pra escrever reader/baker C# offline.

> **Honestidade:** o elo final "qual token do texto JP referencia o glyph N da FTCX" ainda NAO foi crackado byte-a-byte (bate na codificacao JP multi-byte completa, base.ftc=999 glyphs) — status registrado em `docs/reverse/FFX_EVENT_TEXT_GLYPH_REF_STATUS_2026-06-06.md`. Estrutura do FTCX (header/bitmap/widths) ficou em `FFX_EVENT_FTCX_CHUNK3_RE_2026-06-05.md`.

## Familias Tecnicas

- `Pt2 + Pt9 + Pt31..Pt35` = `Model Viewer / Binding`
- `Pt6 + Pt23..Pt28 + Pt36..Pt45` = `Battle / AI / Runtime Truth`
- `Pt3 + Pt10 + Pt11 + Pt16 + Pt21 + Pt22` = `Text Safety`
- `Pt5 + Pt7 + Pt8` = `Kernel / Shop`
- `Pt12 + Pt13 + Pt14 + Pt15 + Pt17 + Pt18 + Pt19 + Pt20` = `Tooling / Safety / Release`
- `Pt29 + Pt30` = `Production Crashfixes`
- `Pt46..Pt58` = `PS2 / Extras / Asset Tree Research`

## O Que Ja Esta Na Main

- `Pt3` em tooling de texto e writer seguro de `Monster Localizations`
- `Pt5` com `PlayerGrowthEditor`, `CtbBaseEditor`, `MixTableEditor`
- `Pt7` e `Pt21/Pt22` como `reader + no-edit guard` de `AutoAbility` / `KeyItem`
- `Pt8` em `Shop Explorer` com recorte conservador
- `Pt16` `Slice 1`
- `Pt17` `ProductionSafetySmoke`
- `Pt18` governanca/release
- `Pt19` surface publica atual
- `Pt29` crashfix de `Key Items`
- `Pt30` crashfix/hardening de `Auto-Abilities`
- `Pt52` em `Extras / BIN-FTC Atlas`
- `Pt54` em `Extras / Project / Pipeline`
- `Pt56` em `Extras / Textures (TM2)`
- `Pt58` em `Extras / PS2 Knowledge`
- `Pt67` em `Extras / Magic Effects`
- `Pt57` em `Extras / Presentation Containers`
- `Pt44` em `Extras / Battle Corpus Crosswalk`

## O Que Vale Portar Depois

- `Pt44` como crosswalk read-only `formation -> actor row -> corpus`
- expansoes de `Pt56` para `txc/clt` e fidelidade de preview
- expansoes de `Pt58` para atlas, badges e provenance mais profundos
- mini-tools read-only vindas de `Pt52`, `Pt53`, `Pt54`, `Pt55` e `Pt57`
- recortes futuros de `Pt14` e `Pt15`, reimplementados com escopo estreito

## O Que Continua Knowledge Only

- a campanha `Pt23..Pt28` e `Pt36..Pt45` como linguagem, taxonomia e guardrails de `Pt6`
- a campanha `Pt31..Pt35` como linguagem, taxonomia e guardrails de `Pt9`
- `Pt20` como mapa historico de absorcao
- `Pt24` e `Pt26` como frontier snapshots permanentes

## O Que Nunca Entra Por Blind Merge

- `runtime + memory + encounter tooling` vindo direto de lab
- writer amplo de `btl_txt.bin`
- writer amplo de `Field String`
- writer publico de `w_name.bin`
- mutacao publica de `important.bin` / `a_ability.bin` fora do slice `reader + no-edit guard`
- claims de `exact launch` ou `AI patcher` sem prova causal

## Atlas Mais Importantes

- batalha e IA:
  - [docs/history/PT6_RUNTIME_AI_DISCOVERY_ATLAS.md](docs/history/PT6_RUNTIME_AI_DISCOVERY_ATLAS.md)
  - [docs/history/BATTLE_AI_FRONTIER_2026-05-31.md](docs/history/BATTLE_AI_FRONTIER_2026-05-31.md)
- model viewer e binding:
  - [docs/history/MODELVIEWER_BINDING_FRONTIER_2026-05-31.md](docs/history/MODELVIEWER_BINDING_FRONTIER_2026-05-31.md)
- bases agregadas:
  - [docs/history/PT2_TO_PT11_KNOWLEDGE_BASE.md](docs/history/PT2_TO_PT11_KNOWLEDGE_BASE.md)
  - [docs/history/PT12_TO_PT22_KNOWLEDGE_BASE.md](docs/history/PT12_TO_PT22_KNOWLEDGE_BASE.md)
  - [docs/history/PT23_TO_PT45_KNOWLEDGE_BASE.md](docs/history/PT23_TO_PT45_KNOWLEDGE_BASE.md)
  - [docs/history/PT2_TO_PT45_MASTER_KNOWLEDGE_BASE.md](docs/history/PT2_TO_PT45_MASTER_KNOWLEDGE_BASE.md)
- campanhas de arvore bruta:
  - [docs/history/FFX_PS3_MAPVIEWER_PROJECT_PLAN_2026-06-02.md](docs/history/FFX_PS3_MAPVIEWER_PROJECT_PLAN_2026-06-02.md)
  - [docs/history/FFX_PHYRE_MAP_EXPORT_LAB_10_STEP_PLAN_2026-06-02.md](docs/history/FFX_PHYRE_MAP_EXPORT_LAB_10_STEP_PLAN_2026-06-02.md)
  - [docs/history/FFX_PHYRE_MAP_EXPORT_LAB_AZIT00_STATIC_CANDIDATE_2026-06-02.md](docs/history/FFX_PHYRE_MAP_EXPORT_LAB_AZIT00_STATIC_CANDIDATE_2026-06-02.md)
  - [docs/history/FFX_PHYRE_MAP_EXPORT_LAB_AZIT00_TEXTURE_CANDIDATE_2026-06-02.md](docs/history/FFX_PHYRE_MAP_EXPORT_LAB_AZIT00_TEXTURE_CANDIDATE_2026-06-02.md)
  - [docs/history/FFX_PHYRE_MAP_MATERIAL_IDA_PLAN_2026-06-02.md](docs/history/FFX_PHYRE_MAP_MATERIAL_IDA_PLAN_2026-06-02.md)
  - [docs/history/FFX_PHYRE_MAP_MATERIAL_LINK_DUMP_FINDINGS_2026-06-02.md](docs/history/FFX_PHYRE_MAP_MATERIAL_LINK_DUMP_FINDINGS_2026-06-02.md)
  - [docs/history/FFX_PHYRE_MAP_MATERIAL_SLOT_CANDIDATE_2026-06-02.md](docs/history/FFX_PHYRE_MAP_MATERIAL_SLOT_CANDIDATE_2026-06-02.md)
  - [docs/history/FFX_MAPVIEWER_TEXTURE_IMPORT_BINDING_2026-06-03.md](docs/history/FFX_MAPVIEWER_TEXTURE_IMPORT_BINDING_2026-06-03.md) — MapViewer texture binding: rota primaria `PParameterBuffer field172 -> TextureSampler`, rota secundaria conservadora por link unico resolvido via `PAssetReferenceImport -> map/.../tex/*.dds`, e fallback `2d_prerendered` para `2d/<field>.ahwin32`; batch `RuntimeTools/FFXMapViewerWeb/public/maps` regenerado com 298/299 glTFs, 0 referencias ausentes, 20,987/29,525 rows bound; ainda `structural_candidate`, nao `engine_exact_material`
  - [docs/ai/CLAUDE_HANDOFF_FFX_PHYRE_MAP_MATERIAL_IDA_2026-06-02.md](docs/ai/CLAUDE_HANDOFF_FFX_PHYRE_MAP_MATERIAL_IDA_2026-06-02.md)
  - [RuntimeTools/FFXMapViewerWeb/README.md](RuntimeTools/FFXMapViewerWeb/README.md)
  - [docs/history/PS3DATA_FULL_TREE_RESEARCH_PLAN.md](docs/history/PS3DATA_FULL_TREE_RESEARCH_PLAN.md)
  - [docs/history/PS3DATA_CHECKLIST_MASTER_2026-06-01.md](docs/history/PS3DATA_CHECKLIST_MASTER_2026-06-01.md)
  - [docs/history/PS2_FULL_TREE_RESEARCH_PLAN.md](docs/history/PS2_FULL_TREE_RESEARCH_PLAN.md)
  - [docs/history/PT52_TO_PT58_CLOSEOUT_REPORT_2026-05-31.md](docs/history/PT52_TO_PT58_CLOSEOUT_REPORT_2026-05-31.md)
- [docs/history/PT52_PT56_PT57_ARCHIVE_CLOSEOUT_2026-06-01.md](docs/history/PT52_PT56_PT57_ARCHIVE_CLOSEOUT_2026-06-01.md)
- [docs/history/PT50_PT51_HISTORICAL_CLEANUP_2026-05-31.md](docs/history/PT50_PT51_HISTORICAL_CLEANUP_2026-05-31.md)
- [docs/history/CHAT_MASTER_DOSSIER_2026-06-01.md](docs/history/CHAT_MASTER_DOSSIER_2026-06-01.md)
- [docs/history/DOSSIÊ FFX 01-06-2026/INDEX.md](<docs/history/DOSSIÊ FFX 01-06-2026/INDEX.md>)

## Leitura Curta

O projeto ja venceu a parte de "existir como editor".

O que sobra esta dividido em dois blocos:

- o que ja pode virar `Extras` read-only e tooling auxiliar;
- o boss final de `battle + AI + exact launch + patcher honesto`.

Este arquivo existe para impedir que essa memoria volte a se espalhar entre chats, branches e handoffs soltos.

Para auditoria total de conversas, handoffs e dependencias citadas, use tambem:

- `docs/history/CHAT_MASTER_DOSSIER_2026-06-01.md`
- `docs/history/DOSSIÊ FFX 01-06-2026/`
