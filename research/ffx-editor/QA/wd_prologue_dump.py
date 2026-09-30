#!/usr/bin/env python3
# CODEC wave2 probe 2: dump the k-byte prologue before the first ADPCM frame of
# each distinct body in the 25 DIRTY banks + correlate k with bank fields
# (f0 pattern, nPrograms, padding between desc table end and align32).
import os
import struct
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
KS = {"smikado.wd": 4, "wave0070.wd": 12, "wave0071.wd": 4, "wave0127.wd": 4,
      "wave0204.wd": 8, "wave0205.wd": 12, "wave0206.wd": 8, "wave0250.wd": 4,
      "wave0260.wd": 12, "wave0400.wd": 12, "wave0401.wd": 4, "wave0513.wd": 4,
      "wave0808.wd": 4, "wave0821.wd": 8, "wave0997.wd": 4, "wave0998.wd": 12,
      "wave0999.wd": 4, "wave1153.wd": 8, "wave1513.wd": 4, "wave1520.wd": 4,
      "wave1533.wd": 4, "wave4101.wd": 8, "wave4102.wd": 4, "wave4117.wd": 12,
      "wave5000.wd": 12}

for name in DIRTY:
    k = KS[name]
    path = os.path.join(CORPUS, name)
    with open(path, "rb") as fh:
        data = fh.read()
    wd = WdFile(data, path)
    unalign = wd.desc_base + wd.n_samples * 0x20
    pad = wd.body_start - unalign
    f0s = sorted({d.field0 for d in wd.descriptors})
    print(f"{name:14s} k={k:2d} pad_to_align32={pad:2d} nProg={wd.n_programs} "
          f"f0set={[hex(x) for x in f0s][:6]}")
    for s_start, _s_end in wd.distinct_bodies[:3]:
        pro = data[s_start:s_start + k]
        nxt = data[s_start + k:s_start + k + 8]
        print(f"   body @{s_start:#08x}: prologue={pro.hex()} "
              f"(LE16s={[struct.unpack_from('<H', pro, i)[0] for i in range(0, len(pro), 2)]}) "
              f"first_frame={nxt.hex()}")
