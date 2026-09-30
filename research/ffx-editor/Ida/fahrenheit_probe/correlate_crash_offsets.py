#!/usr/bin/env python3
"""Gera crash_report.json + correlaciona offsets FFX.exe com a db (base 0x400000)."""
import os
import re
import sys
import json
from collections import Counter

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
BASE = r"D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\logs\crash"

EIP_RE = re.compile(r"EIP Addr\.:\s*([A-Za-z0-9_.-]*)\+?([0-9A-Fa-f]+)h")
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
    exc = EXC_RE.search(text)
    rows.append({
        "data": d,
        "exc": exc.group(1) if exc else "?",
        "mod": eip.group(1) if eip else "",
        "off": eip.group(2) if eip else "",
    })

with open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\crash_report.json", "w", encoding="utf-8") as f:
    json.dump(rows, f, indent=1)

# correlaciona offsets FFX.exe com a db (base 0x400000)
print("=== FFX.exe offsets (amostra) ===")
ffx = [r for r in rows if r["mod"] == "FFX.exe"]
for r in ffx[:10]:
    off = int(r["off"], 16)
    va = off + 0x400000
    print(f"  {r['data']}  FFX.exe+{r['off']} = db VA {hex(va)}")
