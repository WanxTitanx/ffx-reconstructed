#!/usr/bin/env python3
# ============================================================================
# final_probe.py — closing analysis for the SAVE-STRUCT-RE session:
#  1. exact G6 bytes that changed in the 9-year user jump (002@2017 -> 000@2026)
#  2. maximal bit-monotonic zone in TAS runA (progress-flag region candidate)
#  3. GAP3 clearing sub-runs (counters mixed into the flag region)
#  4. Steam wrapper forensics: HDR byte diff (steam vs ps2) + tail content scan
# ============================================================================
import os, re, struct

REPO = "/home/wanderson/Documents/ffx-editor-main"
TAS = os.path.join(REPO, "Utilities/FFX_TAS_Python/tas_saves")
US = os.path.join(REPO, "work/_saves_re/user_slots")
HUNT = os.path.join(REPO, "work/_saves_hunt/corpus")

def load(d,f): return open(os.path.join(d,f),'rb').read()

# ── 1. G6 exact bytes changed in user 002->000 ──
a = load(US,'ffx_002'); b = load(US,'ffx_000')
print("1. G6 (0x3E0C-0x3F0C) bytes changed, user 002(2017)->000(2026):")
for o in range(0x3E0C, 0x3F0C):
    if a[o] != b[o]:
        print(f"   file 0x{o:04X} (Fh 0x{o-0x40:04X}): {a[o]:02x} -> {b[o]:02x} "
              f"(set bits: {bin(b[o]&0xFF|256)[3:]} <- {bin(a[o]&0xFF|256)[3:]})")

# ── 2. maximal monotonic zone in TAS runA ──
runA = sorted([f for f in os.listdir(TAS) if 20 <= int(re.search(r'\d+',f).group()) <= 50],
              key=lambda x: int(re.search(r'\d+',x).group()))
bufs = [load(TAS,f) for f in runA]
PLEN = 0x64F8
mono_changed = [False]*PLEN   # changed at least once, never cleared
for i in range(len(bufs)-1):
    x, y = bufs[i], bufs[i+1]
    for o in range(0x40, PLEN):
        if x[o] != y[o]:
            if (x[o] & ~y[o] & 0xFF) != 0:
                mono_changed[o] = False   # cleared -> excluded forever
            elif mono_changed[o] is not False or mono_changed[o] is True:
                pass
# simpler second pass: changed_flag and cleared_flag
changed = [False]*PLEN; cleared = [False]*PLEN
for i in range(len(bufs)-1):
    x, y = bufs[i], bufs[i+1]
    for o in range(0x40, PLEN):
        if x[o] != y[o]:
            changed[o] = True
            if (x[o] & ~y[o] & 0xFF) != 0:
                cleared[o] = True
mono = [changed[o] and not cleared[o] for o in range(PLEN)]
# longest contiguous monotonic runs
runs = []
for o in range(0x40, PLEN):
    if mono[o]:
        if runs and o - runs[-1][1] <= 16: runs[-1][1] = o
        else: runs.append([o, o])
runs = [r for r in runs if r[1]-r[0] >= 63]
print("\n2. contiguous bit-monotonic runs >=64B in TAS runA (flag-like regions):")
for s,e in sorted(runs, key=lambda r: -(r[1]-r[0])):
    print(f"   0x{s:04X}-0x{e:04X} ({e-s+1} B, changed_bytes={sum(1 for o in range(s,e+1) if changed[o])})")

# ── 3. GAP3 clearing sub-runs (counters mixed in) ──
print("\n3. GAP3 clearing runs (TAS runA): where bits clear (non-flag data):")
cr = [o for o in range(0x0D18, 0x19C4) if cleared[o]]
rr = []
for o in cr:
    if rr and o - rr[-1][1] <= 8: rr[-1][1] = o
    else: rr.append([o,o])
for s,e in rr:
    print(f"   0x{s:04X}-0x{e:04X} ({e-s+1} B)")

# ── 4. Steam wrapper forensics ──
st = load(HUNT,'converter_steam'); ps = load(HUNT,'converter_ps2')
print("\n4a. HDR (0x00-0x40) diff steam vs ps2:")
for o in range(0x40):
    if st[o] != ps[o]:
        print(f"   0x{o:02X}: steam={st[o]:02x} ps2={ps[o]:02x}")
print(f"4b. payload body identical bytes: {sum(1 for o in range(0x40,0x64F4) if st[o]==ps[o])}/25780")
print(f"4c. steam tail 0x64F8-0x6900 (1032B): nonzero bytes = "
      f"{sum(1 for o in range(0x64F8,0x6900) if st[o]!=0)}")
nz = [hex(o) for o in range(0x64F8,0x6900) if st[o]!=0]
print(f"    nonzero offsets: {nz[:20]}")
u0 = load(US,'ffx_000')
print(f"    user_ffx_000 tail nonzero = {sum(1 for o in range(0x64F8,0x6900) if u0[o]!=0)}")
t20 = load(TAS,'ffx_020')
print(f"    tas ffx_020 tail nonzero = {sum(1 for o in range(0x64F8,0x6900) if t20[o]!=0)}")
t147 = load(TAS,'ffx_147')
print(f"    tas ffx_147 tail nonzero = {sum(1 for o in range(0x64F8,0x6900) if t147[o]!=0)}")
print(f"    steam[0x64F8:0x6520] = {st[0x64F8:0x6520].hex(' ')}")
print(f"    u000 [0x64F8:0x6520] = {u0[0x64F8:0x6520].hex(' ')}")
