#!/usr/bin/env python3
# CODEC wave2 probe 4: pin the exact anchor (desc_end vs desc_end+16) using
# frame-flag semantics. In SPU-ADPCM the LAST frame of a sample carries an
# end marker (flag 1/3/7); a START frame should not. For every distinct body
# under each candidate anchor, record first-frame and last-frame flags.
import os
import sys
from collections import Counter

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                "..", "research_tools", "Ps2"))
from ps2_wd_reader import WdFile, WdFormatError  # noqa: E402

CORPUS = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
END_FLAGS = {1, 3, 7}


def bodies(wd, anchor):
    sbo0 = wd.descriptors[0].sbo
    starts = [anchor + (d.sbo - sbo0) for d in wd.descriptors
              if d.reserved18 == 0]
    in_bank = sorted({s for s in starts if 0 <= s < len(wd.data)})
    out = []
    for i, s in enumerate(in_bank):
        e = in_bank[i + 1] if i + 1 < len(in_bank) else len(wd.data)
        if e - s >= 16:
            out.append((s, e))
    return out


stats = {"A0": Counter(), "A1": Counter()}
first_flag_hist = {"A0": Counter(), "A1": Counter()}
last_flag_hist = {"A0": Counter(), "A1": Counter()}
n_files = 0
for dirpath, _dirs, files in os.walk(CORPUS):
    for name in sorted(files):
        if not name.lower().endswith(".wd"):
            continue
        path = os.path.join(dirpath, name)
        try:
            with open(path, "rb") as fh:
                wd = WdFile(fh.read(), path)
        except (OSError, WdFormatError):
            continue
        n_files += 1
        desc_end = wd.desc_base + wd.n_samples * 0x20
        for label, anchor in (("A0", desc_end), ("A1", desc_end + 16)):
            for s, e in bodies(wd, anchor):
                n = (e - s) // 16
                ff = wd.data[s + 1]
                lf = wd.data[s + (n - 1) * 16 + 1]
                first_flag_hist[label][ff] += 1
                last_flag_hist[label][lf] += 1
                if lf in END_FLAGS:
                    stats[label]["last_END"] += 1
                if ff in END_FLAGS:
                    stats[label]["first_END(suspicious)"] += 1
                stats[label]["bodies"] += 1

print(f"files={n_files}")
for label in ("A0", "A1"):
    b = stats[label]["bodies"]
    print(f"{label} (anchor {'desc_end' if label == 'A0' else 'desc_end+16'}): "
          f"bodies={b} last-frame-END={stats[label]['last_END']} "
          f"({stats[label]['last_END']/max(b,1)*100:.1f}%) "
          f"first-frame-END={stats[label]['first_END(suspicious)']} "
          f"({stats[label]['first_END(suspicious)']/max(b,1)*100:.1f}%)")
    print(f"   first-flag top: {first_flag_hist[label].most_common(8)}")
    print(f"   last-flag  top: {last_flag_hist[label].most_common(8)}")
