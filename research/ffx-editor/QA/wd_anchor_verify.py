#!/usr/bin/env python3
# CODEC wave2 probe 3: verify the unified anchor law:
#   anchor = desc_end (EXACT unaligned end of descriptor array)
#   start_i = desc_end + (sbo_i - sbo_0)
# Predictions:
#   P1: every CLEAN bank (old reader) has desc_end % 16 == 0 (pad in {0,16})
#   P2: dirty banks' pad area contains valid frames at desc_end+16m
#   P3: rescanning all banks with the new anchor yields 0 invalid frames
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                "..", "research_tools", "Ps2"))
from ps2_wd_reader import WdFile, WdFormatError  # noqa: E402

CORPUS = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
DIRTY = {"smikado.wd", "wave0070.wd", "wave0071.wd", "wave0127.wd",
         "wave0204.wd", "wave0205.wd", "wave0206.wd", "wave0250.wd",
         "wave0260.wd", "wave0400.wd", "wave0401.wd", "wave0513.wd",
         "wave0808.wd", "wave0821.wd", "wave0997.wd", "wave0998.wd",
         "wave0999.wd", "wave1153.wd", "wave1513.wd", "wave1520.wd",
         "wave1533.wd", "wave4101.wd", "wave4102.wd", "wave4117.wd",
         "wave5000.wd"}


def valid_frac(data, start, size):
    """Fraction of 16B frames at [start, start+size) passing strict header
    validation (filter<=4, shift<=12, flag<=7)."""
    n = size // 16
    good = 0
    for f in range(n):
        o = start + f * 16
        hdr, flag = data[o], data[o + 1]
        if (hdr >> 4) <= 4 and (hdr & 0xF) <= 12 and flag <= 7:
            good += 1
    return good / n if n else 0.0, n


# ── P1: desc_end % 16 across the WHOLE corpus ──
n_total = n_clean = n_clean_pad0 = n_clean_pad16 = n_clean_other = 0
n_dirty_resolved = 0
dirty_detail = []
old_dirty_now_clean = []
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
        n_total += 1
        desc_end = wd.desc_base + wd.n_samples * 0x20
        pad = wd.body_start - desc_end
        sbo0 = wd.descriptors[0].sbo
        # new-law bodies: distinct starts anchored at desc_end
        starts = [desc_end + (d.sbo - sbo0) for d in wd.descriptors
                  if d.reserved18 == 0]
        in_bank = [s for s in starts if 0 <= s < len(wd.data)]
        distinct = sorted(set(in_bank))
        worst = 1.0
        bad_bodies = 0
        for i, s in enumerate(distinct):
            e = distinct[i + 1] if i + 1 < len(distinct) else len(wd.data)
            frac, n = valid_frac(wd.data, s, e - s)
            if n and frac < 1.0:
                bad_bodies += 1
                worst = min(worst, frac)
        is_old_dirty = os.path.basename(path) in DIRTY
        if bad_bodies == 0:
            if is_old_dirty:
                n_dirty_resolved += 1
                old_dirty_now_clean.append(os.path.basename(path))
            n_clean += 1
            if pad == 0:
                n_clean_pad0 += 1
            elif pad == 16:
                n_clean_pad16 += 1
            else:
                n_clean_other += 1
        else:
            dirty_detail.append((os.path.basename(path), is_old_dirty,
                                 bad_bodies, worst, pad))

print(f"P1/P3 corpus: total={n_total} clean(new law)={n_clean} "
      f"(pad0={n_clean_pad0}, pad16={n_clean_pad16}, pad_other={n_clean_other})")
print(f"old-dirty now clean: {n_dirty_resolved}/25")
for b in old_dirty_now_clean:
    print(f"    RESOLVED: {b}")
print(f"still dirty under new law: {len(dirty_detail)}")
for name, was, bb, worst, pad in dirty_detail:
    print(f"    {name}: {bb} bad bodies worst={worst*100:.1f}% pad={pad} "
          f"(old-dirty={was})")
