#!/usr/bin/env python3
"""Analisa debug_strings.json: categoriza por modulo e acha joias."""
import json
import re
import sys
from collections import Counter

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
d = json.load(open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\debug_strings.json", encoding="utf-8"))
strings = [s["s"] for s in d]

# categorias
cats = Counter()
joias = []
for s in strings:
    if "Fmod" in s or "FMOD" in s or ".fev" in s:
        cats["audio"] += 1
    elif "VIRTUOS" in s or "Virtuos" in s:
        cats["virtuos"] += 1
    elif "Phyre" in s:
        cats["phyre"] += 1
    elif ".cpp" in s or ".c\\" in s:
        cats["source"] += 1
    elif "error" in s.lower() or "Error" in s:
        cats["erro"] += 1
    elif "flash" in s.lower() or ".swf" in s.lower():
        cats["flash"] += 1
    elif "save" in s.lower() or "Save" in s:
        cats["save"] += 1
    else:
        cats["outros"] += 1

print("categorias:", dict(cats))
print()
print("=== strings VIRTUOS ===")
for s in strings:
    if "VIRTUOS" in s or "Virtuos" in s:
        print(f"  {s[:100]}")
print()
print("=== strings com 'Error' nao-Fmod ===")
for s in strings:
    if "Error" in s and "Fmod" not in s and "FMOD" not in s:
        print(f"  {s[:100]}")
