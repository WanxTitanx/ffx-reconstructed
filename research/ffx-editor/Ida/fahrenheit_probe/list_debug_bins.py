#!/usr/bin/env python3
"""Lista os .bin das strings de debug."""
import json
import re
import sys

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
d = json.load(open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\debug_strings.json", encoding="utf-8"))
strings = [s["s"] for s in d]
PAT = re.compile(r"[A-Za-z0-9_./\\:%-]{4,}\.bin")
bins = set()
for s in strings:
    for m in PAT.finditer(s):
        bins.add(m.group(0).strip())
print("bins:")
for b in sorted(bins):
    print(f"  {b[:100]}")
