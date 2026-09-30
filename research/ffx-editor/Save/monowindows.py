#!/usr/bin/env python3
# ============================================================================
# monowindows.py — sliding-window bit-monotonicity scan over the whole-game TAS
#                  jump (ffx_020 -> ffx_148) to locate true event-flag regions.
# METHOD CALIBRATION: G8 monsters_seen/defeated (atlas Fh 0x440C/0x444C) are
#   pure bitfields that can only SET as story progresses — they MUST scan as
#   100% monotonic. G6 (atlas EventFlags @0x3E0C) is expected to FAIL (frozen).
# PURPOSE: decide where story/event flags really live in the HD save payload.
# ============================================================================
import os, re

REPO = "/home/wanderson/Documents/ffx-editor-main"
TAS = os.path.join(REPO, "Utilities/FFX_TAS_Python/tas_saves")
files = sorted(os.listdir(TAS), key=lambda x: int(re.search(r'\d+', x).group()))
first = open(os.path.join(TAS, files[0]), 'rb').read()
last = open(os.path.join(TAS, files[-1]), 'rb').read()
NPAIR = len(files) - 1
bufs = [open(os.path.join(TAS, f), 'rb').read() for f in files]
PLEN = 0x64F8

# ── calibration: pure-bitfield regions must be monotonic across ALL pairs ──
def region_mono(s, e, label):
    total_changed = 0; viol_bytes = 0
    for i in range(len(bufs) - 1):
        a, b = bufs[i], bufs[i+1]
        for o in range(s, e):
            if a[o] != b[o]:
                total_changed += 1
                if (b[o] & ~a[o] & 0xFF) != 0:
                    viol_bytes += 1
    print(f"{label:42s} changed_bytes={total_changed:5d} bit_clear_violations={viol_bytes:5d}"
          f"  {'100% MONO' if viol_bytes==0 else 'NOT mono'}")

print("== calibration (known pure bitfields) ==")
region_mono(0x444C, 0x448C, "G8 monsters_seen  @0x444C (Fh 0x440C)")
region_mono(0x448C, 0x44CC, "G8 monsters_defeated @0x448C (Fh 0x444C)")
region_mono(0x420C, 0x422C, "G7 items_acquired @0x420C (Fh 0x41CC)")
region_mono(0x44CC, 0x44DC, "G9 key_items @0x44CC (Fh 0x448C)")
print("\n== atlas claim (expected frozen) ==")
region_mono(0x3E0C, 0x3F0C, "G6 event_flags @0x3E0C (Fh 0x3DCC)")

# ── sliding windows: 128B window, step 64, over whole-game jump ──
print("\n== sliding 128B windows (changed>=24B), sorted by mono% then changed ==")
res = []
W, S = 128, 64
for s in range(0x40, PLEN - W, S):
    e = s + W
    ch = [o for o in range(s, e) if first[o] != last[o]]
    if len(ch) < 24: continue
    viol = sum(1 for o in ch if (last[o] & ~first[o] & 0xFF) != 0)
    res.append((viol / len(ch), len(ch), s, e))
res.sort(key=lambda t: (t[0], -t[1]))
for mono_pct, ch, s, e in res[:25]:
    print(f"  0x{s:04X}-0x{e:04X} changed={ch:3d} viol%={mono_pct*100:5.1f}")
