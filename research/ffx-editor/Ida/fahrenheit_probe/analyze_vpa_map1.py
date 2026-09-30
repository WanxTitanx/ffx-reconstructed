#!/usr/bin/env python3
"""Analisa o .vpa MAP1 em profundidade: header + estrutura de secoes."""
import os
import struct
import sys

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
fp = r"F:\ffx_ps2\ffx\master\jppc\btlmap\azit\azit03_a\bin\mapout.vpa"
data = open(fp, "rb").read()
sz = len(data)
print(f"mapout.vpa: {sz} bytes")

# header 0x40
print("header (0x40):")
u32 = lambda o: struct.unpack_from("<I", data, o)[0]
u16 = lambda o: struct.unpack_from("<H", data, o)[0]
for i in range(0, 0x40, 4):
    v = u32(i)
    if v:
        print(f"  +{i:02X}: {v} (0x{v:X})")

# u32@0x14 = tamanho da regiao 1; u32@0x28 = offset da proxima
r1_size = u32(0x14)
r2_off = u32(0x28)
print(f"\nregiao1 tamanho: {r1_size} (0x{r1_size:X}) @ 0x40")
print(f"regiao2 offset: {r2_off} (0x{r2_off:X})")
if 0 < r2_off < sz:
    print(f"regiao2 header: {data[r2_off:r2_off+32].hex()}")

# strings ascii no inicio
import re
strs = re.findall(rb"[\x20-\x7E]{5,}", data[:0x1000])
print(f"\nstrings nos primeiros 4KB: {[s.decode('ascii','replace') for s in strs[:10]]}")
