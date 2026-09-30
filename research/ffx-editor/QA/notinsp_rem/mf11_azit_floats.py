#!/usr/bin/env python3
# M-F11 adjudication: azit00 mapout.vpa geometry section @0x16fac0 (161KB) has
# "422 real floats (of 40272 total)" per legacy. Anchors: 0x16fbd0=-1.66,
# 0x16fbd8=-1.49, 0x16fbe0=-1.9, 0x16fbf4=-0.67, 0x16fbfc=0.26, heights like 72.0.
import struct, math
from pathlib import Path
p = Path("/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/map/azit/azit00/bin/mapout.vpa")
d = p.read_bytes()
print("file size:", len(d), hex(len(d)))
base = 0x16fac0
size = 161088  # 161KB = 40272 dwords
sec = d[base:base+size]
print("section dwords:", len(sec)//4)
vals = struct.unpack("<%df" % (len(sec)//4), sec)
nonzero = [(i, v) for i, v in enumerate(vals) if v != 0.0 and math.isfinite(v)]
print("non-zero finite floats:", len(nonzero))
# anchors check
for a in (0x16fbd0, 0x16fbd8, 0x16fbe0, 0x16fbf4, 0x16fbfc):
    v = struct.unpack_from("<f", d, a)[0]
    print(f"anchor {hex(a)} = {v:.2f}")
# distribution summary
import collections
mag = collections.Counter()
for i, v in nonzero:
    if abs(v) <= 2: mag["|v|<=2"] += 1
    elif abs(v) <= 100: mag["2<|v|<=100"] += 1
    elif abs(v) <= 1000: mag["100<|v|<=1000"] += 1
    else: mag[">1000"] += 1
print(mag)
# 72.0 heights
h72 = sum(1 for i, v in nonzero if abs(v - 72.0) < 0.01)
print("values ~=72.0:", h72)

# --- stride-16 hypothesis: nonzero position residues mod 16 (in dwords) ---
import collections
res = collections.Counter()
for i, v in nonzero:
    res[i % 4] += 1
print("nonzero count by dword index mod 4:", dict(res))
# runs of consecutive nonzeros
runs = []
cur = 0
for i in range(len(vals)):
    if vals[i] != 0.0 and math.isfinite(vals[i]):
        cur += 1
    else:
        if cur: runs.append(cur)
        cur = 0
if cur: runs.append(cur)
print("nonzero runs:", len(runs), "first 20 run lengths:", runs[:20], "total:", sum(runs))
