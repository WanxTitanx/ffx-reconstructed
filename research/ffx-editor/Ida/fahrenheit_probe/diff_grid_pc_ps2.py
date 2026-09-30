#!/usr/bin/env python3
"""Diff do grid do PC (sphere_build) vs PS2 (abmap/dat02): os +28 bytes."""
import os
import sys

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
pc = r"D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\data\mods\ffx_ps2\ffx\master\sphere_build\Standard Sphere Grid.dat"
ps2 = r"F:\ffx_ps2\ffx\master\jppc\menu\abmap\dat02.dat"
a = open(pc, "rb").read()
b = open(ps2, "rb").read()
print(f"PC: {len(a)}B  PS2: {len(b)}B  diff: {len(a)-len(b)}B")
print()
print("PC  head:", a[:64].hex())
print("PS2 head:", b[:64].hex())
print()
# compara os primeiros 64 bytes campo a campo
import struct
print("PC  u32:", [struct.unpack_from('<I', a, i*4)[0] for i in range(8)])
print("PS2 u32:", [struct.unpack_from('<I', b, i*4)[0] for i in range(8)])
print()
# onde difere
diffs = [i for i in range(min(len(a), len(b))) if a[i] != b[i]]
print(f"bytes diferentes nos primeiros {min(len(a),len(b))}: {len(diffs)}")
print("primeiros offsets de diff:", [hex(d) for d in diffs[:15]])
