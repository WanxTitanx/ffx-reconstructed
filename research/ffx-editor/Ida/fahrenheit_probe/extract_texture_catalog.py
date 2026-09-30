#!/usr/bin/env python3
"""Extrai TODAS as texturas .dds.phyre das strings de debug — catalogo de IDs."""
import json
import re
import sys
from collections import Counter

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
d = json.load(open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\debug_strings.json", encoding="utf-8"))
strings = [s["s"] for s in d]

PAT = re.compile(r"[A-Za-z0-9_./\\:%-]{4,}\.dds\.phyre")
textures = set()
for s in strings:
    for m in PAT.finditer(s):
        textures.add(m.group(0).strip())

print(f"texturas .dds.phyre: {len(textures)}")

# IDs numericos (o padrao %d_%d_0_0_%d_%d)
ID_PAT = re.compile(r"^(\d+)_(\d+)_0_0_(\d+)_(\d+)\.dds\.phyre$")
ids = Counter()
named = []
for t in sorted(textures):
    m = ID_PAT.match(t.rsplit("/", 1)[-1])
    if m:
        ids[int(m.group(1))] += 1
    elif not t.startswith("%"):
        named.append(t)

print(f"texturas com ID numerico: {len(ids)} IDs unicos")
print(f"IDs top (por uso): {ids.most_common(20)}")
print()
print("=== texturas nomeadas (nao numericas) ===")
for t in sorted(named)[:30]:
    print(f"  {t[:100]}")
