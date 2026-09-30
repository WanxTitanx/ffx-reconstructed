#!/usr/bin/env python3
"""Inventario rapido do F:\\ffx_ps2\\ffx: extensoes e contagens (sem ler arquivos)."""
import os
import sys
import json
from collections import Counter

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
ROOT = r"F:\ffx_ps2\ffx"

ext_count = Counter()
ext_size = Counter()
ext_magic = {}
total_files = 0
total_size = 0
magic_read = 0

for dirpath, dirs, files in os.walk(ROOT):
    for fn in files:
        total_files += 1
        fp = os.path.join(dirpath, fn)
        try:
            size = os.path.getsize(fp)
        except OSError:
            continue
        total_size += size
        ext = os.path.splitext(fn)[1].lower() or "(sem ext)"
        ext_count[ext] += 1
        ext_size[ext] += size
        if magic_read < 400:
            ext_magic.setdefault(ext, set())
            if len(ext_magic[ext]) < 2:
                try:
                    with open(fp, "rb") as f:
                        ext_magic[ext].add(f.read(4).hex())
                    magic_read += 1
                except OSError:
                    pass

print(f"TOTAL: {total_files} arquivos, {total_size/1e6:.1f} MB, {len(ext_count)} extensoes")
print()
print(f"{'ext':<14} {'qtd':>7} {'MB':>9}  magic")
for ext, count in ext_count.most_common(60):
    size_mb = ext_size[ext] / 1e6
    magics = ", ".join(sorted(ext_magic.get(ext, set()))[:2])
    print(f"{ext:<14} {count:>7} {size_mb:>9.1f}  {magics}")

with open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\ffx_ps2_inventory.json", "w", encoding="utf-8") as f:
    json.dump({
        "total_files": total_files, "total_size": total_size,
        "exts": {e: {"count": ext_count[e], "size": ext_size[e], "magic": sorted(ext_magic.get(e, []))} for e in ext_count}
    }, f, indent=1, ensure_ascii=False)
print()
print("JSON salvo")

