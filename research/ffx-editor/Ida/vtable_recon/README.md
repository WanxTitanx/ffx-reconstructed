# vtable_recon — harvest de vtables C++ no FFX.exe (leva 7, VTABLE-RECON)

Enumerou **1.972 candidatos** em `.rdata`/`.data` e normalizou **1.593
vtables RTTI** (`??_7…` → `vtbl_<Ns>_<Classe>` demangled via
`llvm-undname`), com comentários de evidência por vtable. Detecta COL
(Complete Object Locator) em `vtable-4` para split de runs adjacentes —
corrige a fusão clássica de vtables coladas.

Pipeline: `scan_vtables2.py` (runs + COL + RTTI + member plan) →
`msvc_demangle.py` (demangle local) → `do_renames.py` (batch rename +
comment). `mcp.py` = client JSON-RPC local.

CUIDADO: `pppSysProgTbl` records (stride 0x28B com campos fn-ptr) parecem
vtables num scan ingênuo — NÃO classificar como vtable (documentado em
`docs/reverse/FFX_VTABLE_HARVEST_2026-09-16.md` §ABERTO).

Requer MCP idalib em http://192.168.122.85:8745/mcp.
Evidência: `work/_vtable_recon/` (vtable_inventory.json, vtables2.json).
