#!/usr/bin/env python3
"""Grep binario de 'sphere' nas DLLs do jogo."""
import os
import sys

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
base = r"D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster"
PATS = [b"sphere_build", b"Sphere Grid", b"SphereGrid", b"contents.dat", b"Standard Sphere"]
for f in os.listdir(base):
    if not f.lower().endswith(".dll"):
        continue
    p = os.path.join(base, f)
    try:
        data = open(p, "rb").read()
    except OSError:
        continue
    for pat in PATS:
        idx = data.find(pat)
        if idx >= 0:
            print(f"{f}: {pat} @ {idx}", flush=True)
            ctx = data[max(0, idx - 30):idx + 60]
            print(f"    {ctx!r}", flush=True)
