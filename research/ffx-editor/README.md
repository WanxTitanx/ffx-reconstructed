# research_tools/ — scripts de pesquisa do FFX (INVENTARIADOS NO REPO)

**Data:** 2026-09-13 · **Lane:** Jarvis-ZCODE-finalize · **Provenance:** cópia de `research_tools/`
(árvore scratch gitignored) feita por ordem do usuário — governança definida: *parsers de pesquisa
vivem como scripts inventariados DENTRO do repo; NÃO são integrados automaticamente ao editor*.
A cópia em `research_tools/` continua sendo a área de trabalho viva; esta árvore é o registro
versionado (248 arquivos / ~1,8 MB de texto; medição por bytes). Binários de amostra (`*.wav`,
`*.fsb`, `*.fev`, `*.cache`, `samples/`) ficaram de fora (originais no scratch).

> **Contagem auditada 2026-09-18 (Jarvis-TOOLS-AUDIT):** a árvore cresceu desde a cópia —
> **967 scripts** (`.py`/`.ps1`/`.sh`, recursivo, sem `bin/`/`obj/`/`__pycache__`) em
> **1.275 arquivos** (~15 MB). Tabela abaixo refeita para bater com o disco;
> divergências e refs quebradas em `docs/reverse/data/wave14/tools_audit_{inventory,refs}.csv`.
>
> **Reparo 2026-09-18 (Jarvis-TOOLS-REPAIR):** as 165 refs quebradas do audit foram
> disposicionadas — ver `docs/reverse/FFX_TOOLS_REPAIR_2026-09-18.md` + CSVs em
> `docs/reverse/data/wave15/`. Resumo: **10 tools do `Ida/jarvis_goal/` + `QA/claude_ida_tmp/
> ffx_crc_verify.py` restauradas do histórico git** (commit `53d82b2a`); **5 tools promovidas
> de `work/_dummies3/` → `Ida/dummies3/`** (verificação pós-rename: `mcpdrv`, `dump_names3`,
> `reconcile3`, `make_csvs`, `reverify_bad`); refs movidas corrigidas nos docs citantes; as
> demais = **evidência deixada em `work/_<lane>/` por política de migração** (gitignored —
> agora anotadas inline como *documented-known-broken* nos próprios docs).
>
> **Sweep W17-QA (2026-09-18, Jarvis-W17-QASWEEP):** wave-16 tool set validada —
> smoke test completo em `docs/reverse/data/wave15/w17_tool_smoke.csv` + relatório
> `docs/reverse/FFX_W17_QA_SWEEP_2026-09-18.md`. Contagem viva agora ~**1.002 scripts**
> (lanes paralelas wave-17 seguem adicionando: `irx_probe`, `dvp_ovly_probe`, `romdir_probe`,
> `cdrom_fnd_parse`, `src_census`, `btlai_census`, `ep_bounds_audit` já inventariadas abaixo).

## Por que existe

A [matriz de cobertura](docs/reverse/FFX_STRUCTURE_COVERAGE_MATRIX_2026-09-13.md) apontou que
metade das provas de parser vivia em árvore git-ignored (risco real de perda — os artefatos do exec
em `/mnt/nvme-samsung` já foram backupeados e removidos em 2026-09-13). Este diretório fecha esse
risco para os scripts.

## Cliente MCP canônico (IDA @ 192.168.122.85:8745)

**Canônico: `research_tools/ida_mcp_client.py`** — reconciliado 2026-09-18
(Jarvis-MCP-CLIENT-RECONCILE). É a ÚNICA porta de entrada para o servidor
idalib/ida-pro-mcp da VM `windows11-dev-next` (zeromcp, 65 tools, DB
`C:\IDA_DB\ffxoficial.exe.i64`). Funde o melhor dos três clientes quase-idênticos
que as lanes reinventavam: retry/backoff (servidor compartilhado — `server_health`
expõe `busy_tool`/`queued_calls`), transporte urllib (sem depender de `curl`),
handshake `initialize`→`mcp-session-id` lazy com reuso, parse de resposta JSON
pura **ou** SSE.

```bash
python3 research_tools/ida_mcp_client.py --selftest      # ping saudável (server_health)
python3 research_tools/ida_mcp_client.py list            # lista tools
python3 research_tools/ida_mcp_client.py decompile '{"addr":"0x8B9600"}'
IDA_MCP_URL=http://host:port/mcp python3 research_tools/ida_mcp_client.py ...
```

API de módulo: `call(tool, args)` → texto · `call_raw`/`rpc` → envelope ·
`post(payload, sess)` → `(sid, body)` · `tools_list()` · `ping()` · `selftest()`.
Env: `IDA_MCP_URL`, `IDA_MCP_NO_HANDSHAKE`, `IDA_MCP_TIMEOUT`, `IDA_MCP_RETRIES`,
`IDA_MCP_DATABASE` (só p/ builds cujas tools aceitam `database`).

**Folding (shims finos que re-exportam o canônico — NÃO adicionar features neles):**
`Ida/mcp8745.py` (mantém `rpc`/`call`→envelope + CLI `--list`) e `Ida/ida_mcp.py`
(mantém `post(payload, sess)`→`(sid, body)` + CLI texto — ~30 callers usam).
**Legados per-lane — DOBRADOS 2026-09-18 (Jarvis-MCP-LEGACY; prefira o canônico):**
`Ida/mcp_call_vm.py`, `Ida/mcp_ctb_tick.py`, `Ppp/ppp_fine3/mcp.py`,
`Atel/eventflags_re/mcp.py` viraram **shims** do canônico (contratos públicos
preservados); `Ida/mcp_batch.py` ficou como **lane-tool** (orquestração batch)
com transporte delegado; `Ida/ida_mcp.sh` segue wrapper curl (callers vivos em
`work/`) com header-note. Detalhe: `docs/reverse/FFX_MCP_LEGACY_FOLD_2026-09-18.md`.
**NÃO confundir:** `scripts/ida_mcp_client.py` é OUTRO cliente — plugin
ida-pro-mcp do IDA GUI no host (`127.0.0.1:13337/13338`, API `call_tool(port,...)`) —
mesmo basename, endpoint diferente.

## Mapa por família

| Pasta | Arquivos | O que contém |
|---|---|---|
| `Atel/` | 20 | utilitários ATEL: `atel_mon_ref_scan` (varredura opcode-level de monster-IDs em `.ebp`/`btl`/`mon` — grammar real + symbolic stack + assinaturas `ScriptCallTargetLib`; 1.598 arquivos, 3,1M call sites), `atel_disasm.py` (disassembler ATEL standalone — wave-12 SCRIPTBIN-DEEP), `atel_cmp_semantics.py`, `ath_parser.py`/`ath_writer.py` (ATEL header parse/write), `ev01_savevar_mining.py`, `ev01_slot_readers.py`, `fmt_event_audit.py`, `menumain_atel_map.py`, `menuscript_menublob.py` (bindings menu-script — wave-15), `optable_meta.py` (decoder/classifier optable f1/f2 — wave-13), `sysfp_probe.py` + harness `AtelHeaderFile.cs`/`test_harness.cs`, **`msgblob_decode.py` + `atel_source_hunt.py` (wave-16)** + `menuscript_ops_census.py`, `atel_op_census.py`, `src_census.py` + `btlai_census.py` + `ep_bounds_audit.py` (wave-17 parallel lanes) |
| `Audio/` | 10 | parse de FEV/FSB (sound banks): `fev_lgcy_{parse,analyze}.py`, `spu_sidecar_dump.py` + readers C# `FevReader`/`Fsb5Reader`/`MovieBinReader`/`VoiceInfoReader` |
| `BattleMap/` | 19 | parsers de batalha/mapa (kernel, encounter, formação) + **leva-3/4:** `aabb_probe.py` (YNGM AABB×ScaleDiv10), `ec_node_walker.py` (pacote `eC!` M-F11), `map1_families.py`, `yngm_chain_walker.py`, `_parse_yngm.py`, `mon_formation_census.py` + sweeps `_scan_{dispatch,ec,families,full_corpus,geom}.py`, `_test_editor_logic.py`, `_verify_rings.py` |
| `Encoding/` | 3 | encoding FFX-SJIS: `ffx_text_dump.py` + `FfxEncoding.{krchcn,tables}.cs` |
| `Ida/` | 11+20 pkgs | **clientes MCP → veja "Cliente MCP canônico" acima:** canônico = `../ida_mcp_client.py` (raiz); `ida_mcp.py`/`mcp8745.py` = shims deprecated, `ida_mcp.sh` + `mcp_{call_vm,batch,ctb_tick}.py` = legados per-lane (`IDA_MCP_URL` sobrescreve o endpoint default `192.168.122.85:8745`); soltos: `ahwin.py`, `diag_hexrays.py`, `mcp_texid.sh`, `re_sg1.py`, `sg_idat.py`; **`dead_sweep/`** (censo de código morto: 12.358 `DEAD_*`, 26% do .text — 0 xrefs + 0 dataptrs + fecho transitivo); **`string_names/`** (sweep de naming por strings: 78 renames, module map 61 srcpaths→193 fns) |
| `Kernel/` | 4 | `kernel_strides_audit.py` (strides/fields dos .bin kernel), `monmagic_diff.py`, **`kernel_table_reader.py`** (reader+validador por-formato da família kernel — decodifica TODOS os registros, checa header Excel/pool/refs, emite JSON+CSV+field-stats; validado em 967 arquivos / 66 formatos / 0 anomalias — ver `docs/reverse/FFX_FMT_KERNEL_AUDIT_2026-09-16.md`), `monster3_tail_audit.py` |
| `Magic/` | 4 | cadeia de magia: `maghost_zonec_resolver.py` (semântica dos 235 slots thunkados — wave-13), `magic_dll_ctx_dump.py` + `MonsterMagicVm.cs`, `ParticleVmInterpreter.cs` |
| `Menu/` | 24 | formatos de menu (clp/dcp/fmt/sps2 etc.): `analyze_{clp,clp2,clp3,deep,deep2,deep3,fmt,menu,sps2}*.py`, `_ida_{decompile,find_loaders,sps2_loader,sps2_table,xrefs}.py` + readers C# (`Program.cs`, `Ps2{Clp,Dcp,Fmt,Sps2}Reader.cs`) |
| `Phyre/` | 10 | HD/Phyre: `analyze_{phyre,full}.py`, `phyre_{cluster,sidecar}_dump.py`, `ryhpx_{extract,dds_reader,dds_decode}.py` (RYHPX/DXT5 — wave-13), `gen_cs.py` + `PhyreTextureReader.cs` |
| `Ps2/` | 89 | família PS2 (bin monstro, kernel, TM2 etc. — 65 `.py` + 20 readers/writers `.cs`): `kernel_bin_descriptor.py`, `wd_dirty_dossier.py`, `command_bin_dump.py` (96B-stride dumper, `--census`/`--od-join`), `newkit_glyph_cells.py` + `newkit_ocr.py` (pipeline CJK newkit.ftc — wave-13), `correlate_event_font.py` + `newkit_map.py` + `newkit_cells.py` (toolchain FTC-RESIDUAL wave-12 — mapa glyph→cell PROVEN + correlação 0x73↔FTCX), **`slps_mips_probe.py` + `font_runtime_probe.py` + `breq_dll_probe.py` + `font_atlas_decode.py` (wave-16)** + `irx_probe.py` + `dvp_ovly_probe.py` + `romdir_probe.py` + `cdrom_fnd_parse.py` (wave-17 parallel lanes), `abmap_dat_reader.py`, `cdf_{reader,cmf_join}.py`, `clp_{reader,swatch}.py`, `credit_dat_reader.py`, `fmt_flat_decode.py`, `ftc*/ftcx_parse.py`, `menu_script_reader.py`, `pal_reader.py`, `ps2_{cmf,et_eff,fp,misc_bin,msb,omd,oms,otp,phyre_cluster,sbin,scn_sNN,sig8_container,tim2_dump,tim2_png,tim2_validate,wd_reader}*.py`, `sps2_reader.py`, `texvideo_bin_reader.py`, `vbf_extract_demo.py`, `vbf_reader.py` + `ida_scripts/` |
| `Psarc/` | 12 | PSARC: `psarc_oracle.py`, `extract_entries.py`, `lockit_reader.py`, `psarc_manifest_reader.py` + harness C# (`PsarcWriter.cs`, `_psarc_repair_ffx2{,_v2}.cs`, `_psarc_test.cs`) + `test_out.psarc` fixture |
| `QA/` | ~150 | censos/verificadores de corpus (154 scripts top-level): `vpa_census`, `ebp_census` (397 .ebp — refutou overlay-table@+0x100), `ppp_dll_census` (581/587/589/591 reconciliado), `mgrp_bin_census`, `chr_census`, `locale_{census,analyze,crossname}`, `bin_ps3psv_{diff,spotcheck}` (541 pares, 100% text-domain), `stub_taxonomy`, `save_itemmap_probe` (item_map = coordenada de marcador), `ebp_text_records_scan` (records {off,attr,offAlt,attr2} em chunk1/chunk4/.bin — divergentes, zero-fields, attr≡attr2), `wd_{dirty_probe,anchor_verify,flag_semantics,prologue_dump}.py`, `ab_analysis.py`, `probe_bika_v{5,6}.py`, `scan_ui_pt2.py`, `f2_validate.py`, `vm_pull_file.py`, `test_decompile.py`, `linker.py`, sweeps `find_*`/`disasm_*`/`decompile_*` + decompiles IDA históricos (`ida_*.py`, `_ida_*.py`) |
| `Save/` | 9 | save-side: `store_value_miner.py`, `diff_saves.py`, `volatility.py`, `final_probe.py`, `mono2.py`, `monowindows.py`, `user_chain.py` + harness C# (`Program.cs`) |
| `Task11Y5/` | 18 | pipeline Y5: `y5_draft_claims{,_b25}.py` (modo `--tierb`), `classify_tierb.py` (1.331 unidades → 494 claimable), `triage_b25.py`, `y5_b24_gate_rerun.py`, `y5_batcher_validate{,_b12b23,_tierb,_tierb3}.py`, `y5_build_candidate{,_b25}.py`, `y5_x5_reconcile.py`, `generate_work_matrix.py` + **`x5_rederive/`** (re-derivação X5: derive/phase1/semtriage_rules/validate), `y5_audit/`, `y5_b24_accept/` (triagem+candidate builder do b24), `y5_batches/`, `t3_batch/` |
| `Noclip/` | 1+1 pkg | extração PPP do noclip (extract_noclip_ppp.py) + **`noclip_reference/`** (fonte .ts vendored do noclip usada como referência de port + JSONs gerados: fahrenheit_symbols, instruction_table, magic_id_names) |
| `Ppp/` | ~160 | **pipeline PPP/particle** migrado de `work/` (134 scripts em 7 pkgs): `ppp_c2/` (analyzers de curvas/header/sharing/schemas/simuladores — cobertura das 581 DLLs), `ppp_inventory/`, `ppp_dispatch/`, `ppp_chain/`, `ppp_fine{,2,3}/` |
| `Vm/` | 2 | `vm_exec.sh` (guest-exec p/ VM Windows — o helper de todas as lanes IDA) + `ffx_vm_wsl_mega_readback.sh` |
| `Hooks/` | 2 pkgs | `f8_fase4/` (run_unx_rt2_v2.ps1 — pipeline RT2 hooks), `sg_rt2_preflight/` (rt2_hooks_toggle.ps1) |
| `i18n/` | 22 | pipeline de tradução/satellites: `i18n_fase2_{apply,classify}.py`, `i18n_runner.py`, `i18n_merge.py`, onda1/2/3 migrators, deepl asia/latins, `gen_gap_fr.py`, `merge/apply_translations.py`, `i18n_{gen_all_translations,gen_asian_staging,neutral_pt_audit,regenerate_fr_de,restore_manual_es,onda2_check,onda3_survey}.py`, `apply_{f2_keys,translations}.py`, `fix_en_pt_keys.py`, `gen_cbc_utf8.py` — histórico da geração dos 9 idiomas |
| `Atel/` | +7 pkgs | + `atel_ns/` (censo de namespaces/funcids dos `.ebp`), `ev01_mining/`, `eventflags_re/`, `notinsp_batch3/`, `g2g3{,_re,_bonus}/` (miners de store-values EV01); soltos: `atel_disasm.py` (disassembler ATEL standalone — wave-12 SCRIPTBIN-DEEP) |
| `Ida/` | +19 pkgs | + `mislabel_audit/` (pipeline da auditoria de 244 mislabels), `fahrenheit_probe/` (propagação Ghidra→IDA: apply_renames/exe_anatomy/extract_exe_paths/propagate_to_canonical/scan_data_globals), `magic_capture/`, `f8_recon/`, **`jarvis_goal/`** (suite naming-goal do EXE — `apply_jarvis_goal_renames_20260617.py`, `validate_jarvis_goal_snapshot.py` + **10 tools restauradas do histórico git `53d82b2a` em 2026-09-18, TOOLS-REPAIR:** `apply_inferno_semantic_renames.py`, `apply_semantic_drift_corrections.py`, `apply_seymour_native_renames_20260629.py`, `apply_ffx_discovery_annotations.py`, `jarvis_function_census.py`, `plan_magic_core_goal_batch.py`, `recover_goal_snapshot_from_pyc_lot20.py`, `ida_batch_decompile.py`, `read_ffx_decompilation.py`, `run_ffx_ida_batch.ps1`), **`dummies3/`** (verificação pós-rename — `mcpdrv.py` driver JSON-RPC persistente, `dump_names3.py` names-index dump, `reconcile3.py` reconcile por addr, `make_csvs.py` reemite os CSVs wave13, `reverify_bad.py` — promovidas de `work/_dummies3/` em 2026-09-18), `decomp_mf11/`, `type_lift/` (fonte da FFXBattleActorData) + `btluihud/`, `chd_inherit/`, `data_r2/`, `define_func/`, `global_names/`, `misc_res/`, `ppp_aux/`, `stru_lift/`, `structural_lift{,_r2}/`, `vtable_recon/`; soltos: `mcp_batch.py`, `mcp_call_vm.py`, `diag_hexrays.py` |
| `QA/` | +12 pkgs | + `ebp_edge/` (scan_records2 — precursor do ebp_text_records_scan), `battle_corpus_re/`, `banner_fix/`, `cline_extract/`, `magic_editor/`, `master_unknown/`, `notinsp_rem/` (tm2_bpp/omd_types), `ps3data_agents/`, `reval_sweep/`, `texid_ftc/`, `val_bmsq/`, **`claude_ida_tmp/`** (`ffx_crc_verify.py` — verificador CRC16 de save, restaurado do histórico git `53d82b2a` em 2026-09-18); **soltos migrados das frentes work/_*:** `chr_census.py` (parity_cross), `ab_analysis.py` (qa_win TRX A/B), `stub_taxonomy.py`, `wd_*_probe/anchor_verify/flag_semantics/prologue_dump` (wd_dirty), `ebp_text_records_scan.py` (ebp_chunks), `vm_pull_file.py` (qa_win) — **dirs citados nos docs mas NUNCA migrados** (evidência ficou em `work/_<lane>/`, gitignored — *documented-known-broken* anotado nos docs citantes, TOOLS-REPAIR 2026-09-18): `status_tail/`, `status_cfg/`, `backlog_close/`, `ctb_resid/`, `sceneid_ppp/`, `ebp_chunks/`, `f2_ring/`, `locale_parity/`, `parity_cross/`, `qa_win/`, `wd_dirty/`, `stub_taxonomy/`, `scratch_mgrp/` (só no histórico git `a731de5f` em `RuntimeTools/FFXMapViewerWeb/work/_scratch_mgrp` + parcial em disco), `c3_keys/`, `claude_ida_tmp/recon_hp/` (só o `ffx_crc_verify.py` foi recuperado) + `k76/`+`ftc_residual/` (sem scratch correspondente) |
| `Kernel/` | +1 pkg | + `kernel_strides/`; soltos: `kernel_table_reader.py` (FMT-KERNEL audit reader, 2026-09-16), `monster3_tail_audit.py`, `monmagic_diff.py` |
| `Save/` | +5 pkgs | + `saves_re/`, `saves_exp/`, `saves_hunt/`, `cleanup_sg/` (parse_sphere2 + FFXRando ref), `spheregrid_re/` |
| `Ffx2/` | 2 | FFX-2 save RE: `ffx2_savemap.py` — SaveData 0x16660 extractor/differ/verifier (dump/scan/diff/verify/fields; field map + corpus validation in `docs/reverse/FFX2_SAVE_FIELDMAP_2026-09-17.md`) + `ffx2_resid.py` (residual fields — wave-14) |
| `Menu/` | +4 pkgs | + `yngm_unknown/`, `yngm_native/`, `yngm_l3/`, `ida/` (helpers IDA do menu) |
| `BattleMap/` | +2 pkgs | + `map1_f23/`, `decomp/` (decompiles históricos do battle-map) |
| `Phyre/` | +1 pkg | + `rtti/` (pré-estudo de registrars indiretos que alimentou o vtable_recon) |
| `Psarc/` | +1 pkg | + `psarc_rt0/` (Rt0Program.cs — harness RT0 do writer) |
| `Ps2/` | +1 pkg | + `ida_scripts/` (scripts IDA auxiliares PS2); `vbf_extract_demo.py` já contado nos 79 soltos |

> **Migração 2026-09-16 (leva-8 cleanup):** ~115 diretórios/ferramentas saíram de `work/` (gitignored) para cá — inclui pipelines completos de levas 4–7 e ferramentas históricas referenciadas pelos docs. Referências `work/…` no atlas e em `docs/reverse/` foram reescritas para os caminhos commitados. **Não migrado:** `work/_main_sync_rebuild_20260730/` (snapshot inteiro do repo — backup, não ferramenta), `work/external/fahrenheit/` + `work/_external_research/fahrenheit/` (cópias de referência de terceiro — rebaixáveis do upstream), `work/research_tools/` (snapshot obsoleto de set/01 — o committed já é mais novo nos 25 arquivos divergentes), amostras binárias `.wav/.fsb/.fev` (fixtures pesadas).
| raiz | 83 | scripts de IDA (`ida_*.py/c` — decompile/dump das seções §11.x do atlas legado), blitzball (`_blitz_diag*.py`, `gen_blitz_c.js`), omd/anm, opcode tables (`magic_opcode_table.*`, `magic_ppp_tables.*`), `chunks.c`, `fsb5_fev.c`/`fsb_fev.h`, `parse_psarc.py`, `textlay_siblings.py`, `vbf_field04_derive.py`, testes pontuais |

## Status de prova

O status PROVADO/PARCIAL/GAP por família está na matriz de cobertura
(`docs/reverse/FFX_STRUCTURE_COVERAGE_MATRIX_2026-09-13.md`) e nos 13 READMEs RT0
(`docs/reverse/parsers/readme/`). Existência ≠ integração: nada aqui é chamado pelo editor.

## Regras

0. **INVENTÁRIO OBRIGATÓRIO (definida pelo usuário, 2026-09-15):** ao fechar cada frente de pesquisa, todo script validado entra em `research_tools/<família>/` e todo artefato de evidência em `artifacts/<data>/<frente>/` (com `MANIFEST.md`: origem, bytes, sha256; arquivos >15 MB regeneráveis ficam fora do git mas manifestados com o comando de regeneração). Nada validado permanece exclusivamente em `work/` ou `/mnt`.

1. Novos scripts de pesquisa nascem no scratch (`research_tools/`) e são promovidos para cá
   quando provados/estáveis — com nota de provenance no cabeçalho.
2. Código de fonte externa leva crédito no próprio arquivo (regra permanente do repo).
3. Este diretório NÃO é referenciado por builds do editor (fora de qualquer `.csproj`/sln).
