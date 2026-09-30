#!/usr/bin/env python3
"""Parser abrangente do FFX PS2: por extensao, amostra de header (magic + primeiros 64B)
de ate 3 arquivos, para documentar a estrutura de cada formato."""
import os
import sys
import json
from collections import Counter, defaultdict

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
ROOT = r"F:\ffx_ps2\ffx"

samples = defaultdict(list)  # ext -> [(path, size, header_hex)]
counts = Counter()
sizes = Counter()

for dirpath, dirs, files in os.walk(ROOT):
    for fn in files:
        ext = os.path.splitext(fn)[1].lower() or "(sem ext)"
        counts[ext] += 1
        fp = os.path.join(dirpath, fn)
        try:
            size = os.path.getsize(fp)
        except OSError:
            continue
        sizes[ext] += size
        if len(samples[ext]) < 3:
            try:
                with open(fp, "rb") as f:
                    head = f.read(64)
                samples[ext].append({
                    "file": os.path.relpath(fp, ROOT)[:80],
                    "size": size,
                    "head": head.hex(),
                })
            except OSError:
                pass

print(f"{'ext':<10} {'qtd':>6} {'MB':>8}  header (3 amostras)")
for ext, count in counts.most_common(40):
    mb = sizes[ext] / 1e6
    heads = []
    for s in samples[ext]:
        heads.append(s["head"][:24])
    print(f"{ext:<10} {count:>6} {mb:>8.1f}  {heads[0] if heads else ''}")
    for h in heads[1:]:
        print(f"{'':<10} {'':>6} {'':>8}  {h}")

with open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\ffx_ps2_headers.json", "w", encoding="utf-8") as f:
    json.dump({
        "exts": {e: {"count": counts[e], "size": sizes[e], "samples": samples[e]} for e in counts}
    }, f, indent=1, ensure_ascii=False)
print()
print("JSON salvo")
