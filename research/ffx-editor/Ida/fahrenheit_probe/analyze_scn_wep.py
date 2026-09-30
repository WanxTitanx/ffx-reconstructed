#!/usr/bin/env python3
"""Analisa scn (s00..s18) e wep (w0001..74) - formatos."""
import os
import struct
import sys

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
base = r"F:\ffx_ps2\ffx\master\jppc\battle"


def show(p, label):
    sz = os.path.getsize(p)
    with open(p, "rb") as f:
        d = f.read(96)
    u32 = lambda o: struct.unpack_from("<I", d, o)[0]
    print(f"=== {label} ({os.path.basename(p)}) {sz}B")
    print("  head:", d[:56].hex())
    print("  u32:", [u32(i * 4) for i in range(8)])


import glob
scn = sorted(glob.glob(os.path.join(base, "scn", "*.bin")))[:2]
for p in scn:
    show(p, "scn")
wep = sorted(glob.glob(os.path.join(base, "wep", "*.bin")))[:2]
for p in wep:
    show(p, "wep")
