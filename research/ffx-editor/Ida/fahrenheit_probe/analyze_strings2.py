#!/usr/bin/env python3
"""Analisa strings Phyre/save/erro e amostra dos 'outros'."""
import json
import sys

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
d = json.load(open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\debug_strings.json", encoding="utf-8"))
strings = [s["s"] for s in d]

print("=== Phyre (amostra 20) ===")
c = 0
for s in strings:
    if "Phyre" in s:
        print(f"  {s[:100]}")
        c += 1
        if c >= 20:
            break

print()
print("=== save (todas) ===")
for s in strings:
    if "save" in s.lower() and "Fmod" not in s:
        print(f"  {s[:100]}")

print()
print("=== outros (amostra 30) ===")
c = 0
for s in strings:
    if not any(k in s for k in ("Fmod", "FMOD", ".fev", "VIRTUOS", "Virtuos", "Phyre", ".cpp", "Error", "error", "save", "Save", "flash", ".swf")):
        print(f"  {s[:100]}")
        c += 1
        if c >= 30:
            break
