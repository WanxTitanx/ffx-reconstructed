#!/usr/bin/env python3
"""Extrai paths de arquivos das strings de debug (dds.phyre, fev, bin, dat, txt...)."""
import json
import re
import sys
from collections import Counter

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
d = json.load(open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\debug_strings.json", encoding="utf-8"))
strings = [s["s"] for s in d]

PAT = re.compile(r"[A-Za-z0-9_./\\:%-]{4,}\.(?:phyre|fev|fsb|bin|dat|txt|csv|dds|png)(?:\s|$)")
exts = Counter()
paths = set()
for s in strings:
    for m in PAT.finditer(s):
        p = m.group(0).strip().strip('"')
        if len(p) > 5:
            paths.add(p)
            exts[p.rsplit(".", 1)[-1].lower()] += 1

print("extensoes:", dict(exts.most_common(12)))
print(f"paths unicos: {len(paths)}")
print()
print("=== .fev ===")
for p in sorted(paths):
    if p.endswith(".fev"):
        print(f"  {p}")
print("=== .fsb ===")
for p in sorted(paths):
    if p.endswith(".fsb"):
        print(f"  {p}")
print("=== .bin/.dat/.txt (amostra 20) ===")
c = 0
for p in sorted(paths):
    if p.endswith((".bin", ".dat", ".txt")) and "ffx_" not in p:
        print(f"  {p}")
        c += 1
        if c >= 20:
            break
