#!/usr/bin/env python3
# probe_bika_v6.py - confirma que bika02_00 -> 00d0 e o MESMO encontro (diff real pequeno).
import os, glob, sys
sys.stdout.reconfigure(encoding="utf-8")
BTL = r"D:\FFX Extracted\FFX\ffx_ps2\ffx\master\jppc\battle\btl\bika02_00\bika02_00.bin"
N0E = r"C:\Users\wande\Downloads\Compressed\noclip.website-39605028765aa2cfaf2cea175f01f3a77cd99c2e\noclip.website-39605028765aa2cfaf2cea175f01f3a77cd99c2e\data\FinalFantasyX\0e"
a = open(BTL, "rb").read()
for name in ["00d0.bin", "00cc.bin", "00d4.bin"]:
    p = os.path.join(N0E, name)
    b = open(p, "rb").read()
    same = 0
    for i in range(min(len(a), len(b))):
        if a[i] == b[i]:
            same += 1
    total = min(len(a), len(b))
    print(f"{name}: size={len(b)} vs {len(a)} eq_bytes={same}/{total} ({100.0*same/total:.2f}%) monster_a={a[0x0C:0x1C].hex(' ')} monster_b={b[0x0C:0x1C].hex(' ')}")