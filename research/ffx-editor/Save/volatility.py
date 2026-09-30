#!/usr/bin/env python3
# ============================================================================
# volatility.py — per-offset volatility map + bit-monotonicity test over the TAS
#                 chain (lane FFX-STRUCTURES / SAVE-STRUCT-RE, 2026-09-14).
# PURPOSE : (1) find which offsets change in EVERY story jump (always-volatile
#               fields: time/room/counters/CRC);
#           (2) test bit-monotonicity (b & ~a == 0, i.e. bits only get SET in
#               story order) per region — the signature of event/progress flags;
#               candidate regions: G6 @0x3E0C (atlas claim) vs GAP3 @0x0D18-0x19C4.
# MAINT   : read-only over Utilities/FFX_TAS_Python/tas_saves (in-place, no copy).
# ============================================================================
import os, re, json, struct

REPO = "/home/wanderson/Documents/ffx-editor-main"
TAS = os.path.join(REPO, "Utilities/FFX_TAS_Python/tas_saves")
OUT = os.path.join(REPO, "work/_saves_re")

files = sorted(os.listdir(TAS), key=lambda x: int(re.search(r'\d+', x).group()))
bufs = [open(os.path.join(TAS, f), 'rb').read() for f in files]
N = len(bufs)
PLEN = 0x64F8

# per-offset: how many adjacent pairs changed that offset
vol = [0] * (PLEN + 8)
# per-offset monotonicity violations (bits that CLEAR in story order)
viol = [0] * (PLEN + 8)
changed = [0] * (PLEN + 8)
for i in range(N - 1):
    a, b = bufs[i], bufs[i + 1]
    for o in range(PLEN):
        if a[o] != b[o]:
            vol[o] += 1
            if (b[o] & ~a[o] & 0xFF) != 0:
                viol[o] += 1

REGIONS = {
    "HDR":  (0x0000, 0x0040),
    "G1":   (0x0040, 0x02B9),
    "G2":   (0x02B9, 0x0441),
    "GAP2": (0x0441, 0x062C),
    "G3":   (0x062C, 0x0D18),
    "GAP3": (0x0D18, 0x19C4),
    "G4":   (0x19C4, 0x21CC),
    "SG":   (0x21EC, 0x350C),
    "GAP5": (0x350C, 0x3D4C),
    "G5":   (0x3D4C, 0x3E0C),
    "G6":   (0x3E0C, 0x3F0C),
    "G11":  (0x3F0C, 0x420C),
    "G7":   (0x420C, 0x424C),
    "G8":   (0x424C, 0x44CC),
    "G9":   (0x44CC, 0x44DC),
    "EQP":  (0x44DC, 0x560C),
    "G12":  (0x560C, 0x6074),
    "G10":  (0x6074, 0x638C),
    "NAM":  (0x638C, 0x64F4),
    "CRC":  (0x64F4, 0x64F8),
}

print(f"{'region':6s} {'size':>5s} {'bytes_changed':>13s} {'always(65/65)':>13s} "
      f"{'>=80%':>6s} {'mono_viol':>9s} {'mono_bytes':>10s}")
report = {}
for k, (s, e) in REGIONS.items():
    ch = sum(1 for o in range(s, e) if vol[o] > 0)
    always = sum(1 for o in range(s, e) if vol[o] == N - 1)
    often = sum(1 for o in range(s, e) if vol[o] >= 0.8 * (N - 1))
    mv = sum(1 for o in range(s, e) if viol[o] > 0)          # offsets with >=1 bit-clear
    mono = sum(1 for o in range(s, e) if 0 < vol[o] and viol[o] == 0)  # changed & never cleared
    print(f"{k:6s} {e-s:5d} {ch:13d} {always:13d} {often:6d} {mv:9d} {mono:10d}")
    report[k] = dict(size=e-s, bytes_changed=ch, always=always, pct80=often,
                     mono_viol_offsets=mv, monotonic_changed=mono)

# always-volatile offsets list (the "fields that always change" discovery)
alw = [o for o in range(0x40, PLEN) if vol[o] == N - 1]
# cluster into runs
runs = []
for o in alw:
    if runs and o - runs[-1][1] <= 3: runs[-1][1] = o
    else: runs.append([o, o])
print("\nalways-volatile runs (changed in all 65 pairs, payload body):")
for s, e in runs:
    print(f"  0x{s:04X}-0x{e:04X} ({e-s+1} B)")

# GAP3 monotonic detail: which sub-runs of GAP3 are bit-monotonic (event-flag-like)?
print("\nGAP3 detail: changed runs, volatility, mono-violations")
a, b = bufs[0], bufs[-1]  # first vs last checkpoint (whole-game jump)
g3d = [o for o in range(0x0D18, 0x19C4) if a[o] != b[o]]
rr = []
for o in g3d:
    if rr and o - rr[-1][1] <= 4: rr[-1][1] = o
    else: rr.append([o, o])
for s, e in rr[:40]:
    v = sum(viol[s:e+1]); vv = sum(1 for o in range(s, e+1) if viol[o])
    print(f"  0x{s:04X}-0x{e:04X} len={e-s+1:3d} viol_offsets={vv}")

json.dump({'report': report, 'always_runs': [[hex(s), hex(e)] for s, e in runs]},
          open(os.path.join(OUT, 'volatility.json'), 'w'), indent=1)
print("\nwrote work/_saves_re/volatility.json")
