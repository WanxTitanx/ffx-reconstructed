#!/usr/bin/env python3
# CODEC wave2 probe: measure per-body frame alignment offset k in 0..15 for the
# 25 DIRTY banks. A valid frame = hdr byte (filter<<4|shift) with filter<=4,
# shift<=12, AND flag byte in {0..7}. Reports best k per distinct body.
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                "..", "research_tools", "Ps2"))
from ps2_wd_reader import WdFile  # noqa: E402

CORPUS = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/proj/sound/wave"
DIRTY = ["smikado.wd", "wave0070.wd", "wave0071.wd", "wave0127.wd",
         "wave0204.wd", "wave0205.wd", "wave0206.wd", "wave0250.wd",
         "wave0260.wd", "wave0400.wd", "wave0401.wd", "wave0513.wd",
         "wave0808.wd", "wave0821.wd", "wave0997.wd", "wave0998.wd",
         "wave0999.wd", "wave1153.wd", "wave1513.wd", "wave1520.wd",
         "wave1533.wd", "wave4101.wd", "wave4102.wd", "wave4117.wd",
         "wave5000.wd"]


def valid_frac(data, start, size, k):
    n = (size - k) // 16
    good = 0
    for f in range(n):
        o = start + k + f * 16
        hdr = data[o]
        flag = data[o + 1]
        if (hdr >> 4) <= 4 and (hdr & 0xF) <= 12 and flag <= 7:
            good += 1
    return good / n if n else 0.0, n


for name in DIRTY:
    path = os.path.join(CORPUS, name)
    with open(path, "rb") as fh:
        data = fh.read()
    wd = WdFile(data, path)
    per_body = []
    for s_start, s_end in wd.distinct_bodies:
        size = s_end - s_start
        if size < 64:
            continue
        best = max(range(16),
                   key=lambda k: valid_frac(data, s_start, size, k)[0])
        frac, n = valid_frac(data, s_start, size, best)
        per_body.append((s_start, size, best, frac, n))
    # histogram of best-k across bodies
    ks = {}
    for _s, _sz, k, _f, _n in per_body:
        ks[k] = ks.get(k, 0) + 1
    print(f"{name:16s} bodies={len(per_body):3d} best-k histogram: {ks}")
    # detail for first 4 bodies
    for s_start, size, best, frac, n in per_body[:4]:
        print(f"    body @{s_start:#08x} size={size:6d} best k={best:2d} "
              f"valid={frac*100:5.1f}% of {n} frames")
