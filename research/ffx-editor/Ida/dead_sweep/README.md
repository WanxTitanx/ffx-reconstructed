# dead_sweep — censo de código morto no FFX.exe (leva 7, DEAD-SWEEP)

Pipeline que classificou **12.358 funções mortas** (26% do .text) em
`ffxoficial.exe.i64`. Critério CONFIRMADO nos dois sentidos: 0 code xrefs
(`xrefs_to`) **E** 0 data pointers (`find_bytes` do dword LE na imagem toda —
cobre vtables/jump/call-target tables) **E** não-entrypoint, com fecho
transitivo até fixpoint.

Ordem: `census.py` → `analyze.py` → `refine.py` → `classify.py` → `apply.py`
(escreve `DEAD_*` + comentários no IDB; roda dry-run por padrão — atenção:
`dry_run` vai **dentro** do campo `batch` no schema do rename tool).

Requer MCP idalib em `IDA_MCP_URL` (default http://192.168.122.85:8745/mcp).
Evidência: `docs/reverse/FFX_DEAD_CODE_CENSUS_2026-09-16.md`,
raw em `work/_dead_sweep/` (dead.json, clusters_final.json).
