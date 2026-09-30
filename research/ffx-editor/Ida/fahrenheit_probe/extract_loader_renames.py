#!/usr/bin/env python3
"""Extrai renames candidatos dos enderecos do fahrenheit-managed-loader (RVAs -> VAs).

Regras: nome vem da MESMA linha (membro antes de => ou variavel local antes de =);
select(a, b, c) -> so o PRIMEIRO endereco (FFX); FhMethodLocation usa VA direto.
"""
import json
import re
import sys
from pathlib import Path

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
SRC = Path(r"C:\Users\wande\Downloads\Compressed\FFX Analiser\fahrenheit-managed-loader\fahrenheit-managed-loader\core")
BASE = 0x400000

ADDR = re.compile(r"0x([0-9A-Fa-f]{5,8})")
NAME_BEFORE = re.compile(r"^\s*(?:public\s+static\s+[^=;]+?|static\s+[^=;]+?|public\s+[^=;]+?|internal\s+[^=;]+?|byte\*\s*|byte\s*|nint\*\s*|nint\s*|uint\*\s*|uint\s*|int\*\s*|int\s*|bool\s*|void\*\s*|float\*\s*|float\s*|short\s*|ushort\s*|char\*\s*)\s*([A-Za-z_][A-Za-z0-9_]*)\s*(?:=>|\{ get \}|=)")


def clean(name: str) -> str:
    n = name.strip()
    if n.startswith("__addr_"):
        n = n[7:]
    elif n.startswith("dptr_"):
        n = n[5:]
    elif n.startswith("ptr_"):
        n = n[4:]
    if not n or n.startswith("FUN_") or n in ("FhMethodLocation", "FhEnvironment", "FhUtil", "new", "return", "var", "select", "pal", "save", "get", "set"):
        return None
    parts = [p for p in re.split(r"[_\s]+", n) if p]
    n = "".join(p[:1].upper() + p[1:] for p in parts)
    return n if n else None


renames = {}
for f in SRC.rglob("*.cs"):
    if f.name in ("usings.cs", "dptr.cs", "log.cs", "i18n.cs", "imguihelp.cs", "creatwth.cs"):
        continue
    for i, line in enumerate(f.read_text(encoding="utf-8", errors="replace").splitlines()):
        if "0x" not in line:
            continue
        nm = None
        mm = NAME_BEFORE.search(line)
        if mm:
            nm = clean(mm.group(1))
        if not nm:
            continue
        # seleciona o endereco certo da linha
        if "FhMethodLocation" in line and "FFX.exe" in line:
            va = int(ADDR.search(line).group(1), 16)
        else:
            # primeiro endereco (FFX no select; ou o unico ptr_at/get_at/BaseAddr)
            sel = ADDR.search(line)
            if not sel:
                continue
            va = int(sel.group(1), 16) + BASE
        key = f"0x{va:X}"
        if key not in renames:
            renames[key] = {"name": nm, "file": f.name, "line": line.strip()[:90]}

out = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\loader_renames.json")
out.write_text(json.dumps(renames, indent=1, ensure_ascii=False), encoding="utf-8")
print(f"candidatos={len(renames)}")
for k, v in list(renames.items())[:20]:
    print(f"  {k} -> {v['name']}  ({v['file']})")

