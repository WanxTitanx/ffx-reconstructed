#!/usr/bin/env python3
"""Analisa os monster data files (mXXX.bin)."""
import os
import struct
import sys

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
base = r"F:\ffx_ps2\ffx\master\jppc\battle\mon"
for name in ["m000", "m050", "m200"]:
    p = os.path.join(base, name + ".bin")
    if not os.path.exists(p):
        print(f"{name}.bin NAO existe")
        continue
    sz = os.path.getsize(p)
    with open(p, "rb") as f:
        d = f.read(128)
    u32 = lambda o: struct.unpack_from("<I", d, o)[0]
    print(f"=== {name}.bin {sz}B")
    print("  head:", d[:56].hex())
    print("  u32:", [u32(i * 4) for i in range(8)])
