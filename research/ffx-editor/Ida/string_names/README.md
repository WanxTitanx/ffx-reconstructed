# string_names — sweep de naming dirigido por strings (leva 7, STRING-NAMES)

Varredura que aplicou **78 renames + 111 comments** a partir de xref de
strings distintivas (format strings, paths `.bin`/`.cpp`, debug text) e
montou o **module map** (61 paths `r:\hg_code\...` → 193 funções).

Ordem: `sweep_xrefs.py` (distinctive strings → funcs) → `apply_renames.py` →
`apply_comments.py`. Inputs esperados no CWD: `distinctive_strings.json`,
`renames_applied.json` (ver `work/_string_names/` para os artefatos da run).

Requer MCP idalib em http://192.168.122.85:8745/mcp.
Evidência: `docs/reverse/FFX_STRING_NAMING_SWEEP_2026-09-16.md`.
