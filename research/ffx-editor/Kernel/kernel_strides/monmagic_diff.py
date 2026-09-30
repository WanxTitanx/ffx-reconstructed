#!/usr/bin/env python3
# Compare monmagic.bin (84B rec) vs monmagic1.bin (92B rec) record structure.
# Hypothesis: 84B = TSInfo(16) + Ability[0..0x43] (68B) i.e. missing the last
# 8 bytes of Ability_Command (statusFlags@0x44..specialBuff@0x4B).
import os, struct

K = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/battle/kernel"

def load(fn):
    b = open(os.path.join(K, fn), "rb").read()
    prev, cm1, esz, tsz, toff = struct.unpack("<hhhh i", b[8:20])
    n = cm1 + 1 - prev
    return b, toff, esz, n

for fn, esz in [("monmagic.bin", 84), ("monmagic1.bin", 92)]:
    b, toff, esz2, n = load(fn)
    assert esz == esz2
    # per-position nonzero histogram over the ability part (offset 16..esz)
    last_nz = [0] * n
    nz_at_tail = 0   # records with any nonzero byte in ab+0x44..0x4B region
    nz_44_4b_positions = {}
    for i in range(n):
        rec = b[toff + i*esz : toff + (i+1)*esz]
        ln = max((j for j, v in enumerate(rec) if v != 0), default=-1)
        last_nz[i] = ln
    from collections import Counter
    dist = Counter(last_nz)
    print(f"\n== {fn}: {n} recs x {esz}B; last-nonzero-index distribution (rec-relative):")
    for k in sorted(dist):
        print(f"   last_nz=0x{k:02X} ({k:3d}) : {dist[k]} recs")
    # nonzero frequency per ability-relative byte 0x40..end
    print("   nonzero count per byte offset (rec+0x3E..end):")
    for off in range(0x3E, esz):
        c = sum(1 for i in range(n) if b[toff+i*esz+off] != 0)
        print(f"     rec+0x{off:02X}: {c:4d} nonzero")
