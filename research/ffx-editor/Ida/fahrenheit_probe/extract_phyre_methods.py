#!/usr/bin/env python3
"""Parse simples e rapido: so classes/metodos nas linhas de declaracao."""
import json
import re
import sys
from pathlib import Path

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
INC = Path(r"G:\D\ffx-reconstructed\Phyre_Engine\Phyre Engine\Include")

CLASS_RE = re.compile(r"^\s*(?:class|struct)\s+(P[A-Za-z0-9_]+)\s*[{:]")
METHOD_RE = re.compile(r"^\s*(?:virtual\s+|static\s+|inline\s+|explicit\s+)*[A-Za-z_][\w:<>,*& ]*?\s([A-Za-z_][A-Za-z0-9_]*)\s*\([^;{}]*\)\s*(?:const\s*)?[;{]")

methods = {}  # Classe_Metodo -> arquivo
for h in INC.rglob("*.h"):
    if not any(s in h.name for s in ("Serialization", "ObjectModel", "Class", "Rtti", "Component", "Entity", "Stream", "PSerial")):
        continue
    text = h.read_text(encoding="utf-8", errors="replace")
    cur = None
    for line in text.splitlines():
        cm = CLASS_RE.match(line)
        if cm:
            cur = cm.group(1)
            continue
        if cur:
            mm = METHOD_RE.search(line)
            if mm:
                methods.setdefault(f"{cur}_{mm.group(1)}", set()).add(h.name)
            if "}" in line:
                cur = None

print(f"metodos unicos (subset): {len(methods)}")
json.dump({m: sorted(v) for m, v in methods.items()},
          open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\phyre_methods.json", "w", encoding="utf-8"),
          indent=1, ensure_ascii=False)
for m in sorted(methods)[:25]:
    print(" ", m)

