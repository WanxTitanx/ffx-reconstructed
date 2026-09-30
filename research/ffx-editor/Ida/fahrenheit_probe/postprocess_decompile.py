#!/usr/bin/env python3
"""Pos-processamento da decompilacao completa: indice + resumo de falhas."""
import os
import re
import sys
import json
from collections import Counter

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
ROOT = r"F:\ffx-reconstructed\pseudocode\complete"

# 1) indice dos .c
index = []
for dp, _, fns in os.walk(ROOT):
    for f in fns:
        if f.endswith(".c"):
            ea = int(f[:8], 16)
            index.append({"ea": hex(ea), "file": os.path.relpath(os.path.join(dp, f), ROOT)})
index.sort(key=lambda x: int(x["ea"], 16))
with open(os.path.join(ROOT, "index.json"), "w", encoding="utf-8") as fo:
    json.dump(index, fo, indent=1)
print(f"indice: {len(index)} funcoes")

# 2) falhas
fail_path = os.path.join(ROOT, "failures.log")
if os.path.exists(fail_path):
    fails = [l.strip() for l in open(fail_path, encoding="utf-8", errors="replace") if l.strip()]
    print(f"falhas: {len(fails)}")
    kinds = Counter()
    for l in fails:
        err = l.split("::")[-1].strip() if "::" in l else "?"
        kinds[err[:40]] += 1
    for k, c in kinds.most_common(10):
        print(f"  {k}: {c}")
else:
    print("sem failures.log (ainda rodando?)")
