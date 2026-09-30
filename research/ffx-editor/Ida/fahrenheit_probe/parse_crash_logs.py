#!/usr/bin/env python3
"""Parse das 264 pastas de crash: extrai (data, modulo, offset EIP) de cada crash.log."""
import os
import re
import sys
from collections import Counter

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
BASE = r"D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\logs\crash"

EIP_RE = re.compile(r"EIP Addr\.:\s*([A-Za-z0-9_.-]*)\+?([0-9A-Fa-f]+)h")
FILE_RE = re.compile(r"File\.\.\.\.\.:\s*'([^']*)'")
EXC_RE = re.compile(r"<< (EXCEPTION_\w+) >>")

rows = []
for d in sorted(os.listdir(BASE)):
    p = os.path.join(BASE, d, "crash.log")
    if not os.path.exists(p):
        continue
    try:
        text = open(p, encoding="utf-8", errors="replace").read()
    except Exception:
        continue
    eip = EIP_RE.search(text)
    fm = FILE_RE.search(text)
    exc = EXC_RE.search(text)
    mod = ""
    if eip:
        mod = eip.group(1) or "(null)"
    rows.append((d, exc.group(1) if exc else "?", mod, eip.group(2) if eip else "?",
                 os.path.basename(fm.group(1)) if fm and fm.group(1) else ""))

print(f"crashes parseados: {len(rows)}")
mods = Counter(r[2] for r in rows)
print("modulos EIP:", dict(mods.most_common(15)))
files = Counter(r[4] for r in rows if r[4])
print("modulos File:", dict(files.most_common(15)))
print()
print("=== amostra (15) ===")
for r in rows[:15]:
    print(f"  {r[0]}  {r[1]}  EIP={r[2]}+{r[3]}  file={r[4]}")

