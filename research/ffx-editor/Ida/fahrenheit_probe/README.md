# work/_fahrenheit_probe — Scripts da Operação FFX.EXE (2026-08-01/02)

Pipeline completo de RE na db (`ffxoficial_COPY.i64` = db de trabalho; canônica = `ffxoficial.exe.i64`).

## Cliente MCP (falar com o IDA GUI aberto)

- `mcp_call.py <tools|exec <script.py>|call <tool> <json>|...>` — cliente MCP Streamable HTTP do plugin ida-pro-mcp (porta **13338**). Use `$env:PYTHONIOENCODING='utf-8'` antes.
- `apply_json_in_gui.py` — aplica renames JSON no GUI (py_exec_file).

## Importação de símbolos (Ghidra/loader/Phyre)

- `ida_apply_ghidra_names.py` — aplica CSVs do Ghidra (functions/globals) na db headless.
- `ida_apply_renames_from_json.py` — aplica JSON de renames genérico.
- `extract_loader_renames.py` — extrai renames do fahrenheit-managed-loader (RVAs → VA+0x400000).
- `extract_phyre_methods.py` — extrai métodos dos headers do Phyre (357 no JSON).
- `apply_renames_in_gui.py` — aplica na COPY via GUI (MCP py_exec_file).

## VM ATEL (Fase 3.3)

- `apply_atel_table_types.py` — cria `FFX_AtelFuncspaceEntry` (callpopa/status/float_return/int_return) e aplica nas 12 tabelas com tamanhos REAIS.
- `survey_atel_3fields.py` — conta entradas preenchidas por tabela nos 3 campos.
- `map_battle_table_full.py` — dump da tabela Battle (311 entradas com nomes).
- `apply_atel_battle_targets.py` / `check_atel_divergences.py` — cruzam catálogo do Spira com a tabela.
- `check_common_table.py` — valida base de IDs da Common (ID direto).
- `disasm_init_vm.py` — desassembly do InitVm (channels reais).
- `batch_rename_atel_defaults.py` — renomeia handlers default com prefixo da tabela.

## Scan do .data/.rdata (Fase 3.2)

- `scan_data_globals.py` — scan original (1.429 globals).
- `rank_data_globals.py` — ranking por xrefs + função dominante → `data_globals_report.json`.
- `list_c8f510_users.py` — usuários do SharedTransformContext.
- `batch_rename_globals_by_module.py` / `batch_rename_globals_all.py` — renomeia globals `.data` por módulo (`FFX_<MOD>_Global_<ADDR>`).
- `batch_rename_rdata_consts.py` — idem para `.rdata` (`FFX_<MOD>_Const_<ADDR>`).
- `batch_rename_subfuncs.py` — funções default com pai único.
- `batch_rename_thunks.py` — `j_X` → `X_Thunk` (1.138!).
- `batch_rename_ppp_handlers.py` — handlers PPP via blob de nomes 0xC3DC28 (89 ppp*).
- `batch_rename_nameblob_fns.py` — outros blobs name_ptr+fn_ptr.
- `apply_data_buffer_names.py` — renames fixos dos buffers provados (20+).
- `apply_lpamng_struct.py` / `apply_fmod_struct.py` / `apply_mscd_struct.py` — structs aplicadas.
- `probe_map_excess.py` / `dump_strings_after_map.py` / `name_shader_pool.py` — investigação da Map/pool de shaders.
- `extract_exe_paths.py` — 639 paths do filesystem → `exe_file_paths.json`.
- `exe_anatomy.py` — funções por módulo.
- `survey_hostcontext.py` / `survey_ppp_dispatch_coverage.py` / `survey_atel_default_handlers.py` / `survey_default_fns.py` / `survey_nullsub_handlers.py` / `final_state_check.py` — surveys de cobertura.

## Propagação

- `propagate_to_canonical.py` — aplica TODOS os lotes determinísticos na db canônica (rodar quando ela liberar; a COPY está à frente).

## Saídas

- `data_globals_report.json` — 1.253 globals com xrefs + função dominante.
- `exe_file_paths.json` — 639 paths.
- `battle_table_map.txt` — dump da tabela Battle.
- `c8f510_users.json` — 118 usuários do contexto de transform.
