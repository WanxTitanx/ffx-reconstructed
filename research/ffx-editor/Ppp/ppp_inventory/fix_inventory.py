# -*- coding: utf-8 -*-
"""Correção cirúrgica do inventory_scan.py (reparo de inserts desalinhados)."""
from pathlib import Path

P = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\ppp_inventory\inventory_scan.py")
src = P.read_text(encoding="utf-8")

# --- 1) Remover o lixo após o primeiro 'if __name__ == "__main__":\n    main()' ---
marker = 'if __name__ == "__main__":\n    main()\n'
idx = src.index(marker) + len(marker)
src = src[:idx] + "\n"

# --- 2) Garantir resolve_name antes da seção '# Scan de uma DLL' ---
anchor2 = "# ---------------------------------------------------------------------------\n# Scan de uma DLL"
head, tail = src.split(anchor2, 1)
rn = (
    "def resolve_name(index: int, static: dict[int, str], exe: dict[int, str]) -> str:\n"
    '    """Nome do opcode: estático (JSON) > exe (0xC3A500) > idx_hex cru."""\n'
    "    if index in static:\n"
    "        return static[index]\n"
    "    if index in exe:\n"
    "        return exe[index]\n"
    '    return f"idx_{index:02X}"\n'
)
if "def resolve_name" not in head:
    src = head + rn + "\n" + anchor2 + tail
else:
    src = head + anchor2 + tail

# --- 3) Inserir bloco faltante em main() após 't0 = time.time()' ---
anchor3 = "    t0 = time.time()\n"
assert src.count(anchor3) == 1, f"anchor3 count={src.count(anchor3)}"
missing = (
    "    static = load_static_opcode_names()\n"
    "    exe = load_exe_dispatch_names(FFX_EXE)\n"
    '    print(f"[init] estático={len(static)} entradas | exe 0xC3A500={len(exe)} entradas | "\n'
    '          f"{time.time() - t0:.1f}s")\n'
    "\n"
    '    dll_paths = sorted(MAGIC_DIR.glob("magic_*.dll"))\n'
    "    if args.limit > 0:\n"
    "        dll_paths = dll_paths[: args.limit]\n"
    '    print(f"[init] {len(dll_paths)} DLLs alvo em {MAGIC_DIR}")\n'
)
src = src.replace(anchor3, anchor3 + missing, 1)

# --- 4) Sanidade ---
assert src.count("def resolve_name") == 1, src.count("def resolve_name")
assert src.count("def main()") == 1
assert src.count("def load_exe_dispatch_names") == 1
assert src.count('dll_paths = sorted(MAGIC_DIR.glob("magic_*.dll"))') == 1
assert src.count('static = load_static_opcode_names()') == 1

P.write_text(src, encoding="utf-8")
print("OK bytes:", len(src))
