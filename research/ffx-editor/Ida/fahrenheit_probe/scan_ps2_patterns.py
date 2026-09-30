#!/usr/bin/env python3
"""Strings com padroes PS2: host:, pfs, DTK, SA_, task, sa_."""
import json
import sys

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
d = json.load(open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\debug_strings.json", encoding="utf-8"))
strings = [s["s"] for s in d]

PATS = ["host:", "pfs", "DTK", "SA_", "task_", "sa_", "iop", "sce", "Sce"]
seen = set()
print("=== padroes PS2 ===")
for s in strings:
    if any(p in s for p in PATS) and s not in seen:
        seen.add(s)
        print(f"  {s[:110]}")
        if len(seen) > 45:
            break
