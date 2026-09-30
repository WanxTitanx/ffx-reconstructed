#!/usr/bin/env python3
# ============================================================================
# mono2.py — CORRECTED bit-monotonicity test (violation = bit CLEARS in story
#            order: (a & ~b) != 0; the earlier volatility.py/monowindows.py had
#            this inverted and their mono columns are INVALID — fixed here).
# Runs over: TAS run A (ffx_020..ffx_050, monotonic story 42->3205) and the
#            long real-user jump ffx_002(2017) -> ffx_000(2026).
# ============================================================================
import os, re, struct

REPO = "/home/wanderson/Documents/ffx-editor-main"
TAS = os.path.join(REPO, "Utilities/FFX_TAS_Python/tas_saves")
US = os.path.join(REPO, "work/_saves_re/user_slots")

def u16(b,o): return struct.unpack_from('<H',b,o)[0]
def load(d,f): return open(os.path.join(d,f),'rb').read()

runA = sorted([f for f in os.listdir(TAS) if 20 <= int(re.search(r'\d+',f).group()) <= 50],
              key=lambda x: int(re.search(r'\d+',x).group()))
tas_bufs = [load(TAS,f) for f in runA]
uA = load(US,'ffx_002')      # 2017 mid-game (identical to .bak_jarvis of 2017)
uB = load(US,'ffx_000')      # 2026 end-game

CHAINS = [
    ("TAS runA 020->050 (24 saves)", tas_bufs),
    ("USER 002(2017)->000(2026)", [uA, uB]),
]

REGIONS = [
    ("G7  items_acquired   @0x420C-0x422C", 0x420C, 0x422C),
    ("G7  items_used       @0x422C-0x424C", 0x422C, 0x424C),
    ("G8  monsters_captured@0x424C-0x444C", 0x424C, 0x444C),
    ("G8  monsters_seen    @0x444C-0x448C", 0x444C, 0x448C),
    ("G8  monsters_defeated@0x448C-0x44CC", 0x448C, 0x44CC),
    ("G9  key_items        @0x44CC-0x44DC", 0x44CC, 0x44DC),
    ("G6  event_flags(atlas)@0x3E0C-0x3F0C", 0x3E0C, 0x3F0C),
    ("G3  dark aeons etc   @0xCC9-0xCD2 ", 0xCC9, 0xCD2),
    ("GAP3 unmapped        @0x0D18-0x19C4", 0x0D18, 0x19C4),
    ("GAP2 unmapped        @0x0441-0x062C", 0x0441, 0x062C),
    ("G5  ability_map_limit@0x3DAC-0x3DE4", 0x3DAC, 0x3DE4),
    ("NAM character_names  @0x638C-0x64F4", 0x638C, 0x64F4),
]

for cname, bufs in CHAINS:
    print(f"== {cname} ==")
    for label, s, e in REGIONS:
        tot = cleared = 0
        for i in range(len(bufs)-1):
            a, b = bufs[i], bufs[i+1]
            for o in range(s, e):
                if a[o] != b[o]:
                    tot += 1
                    if (a[o] & ~b[o] & 0xFF) != 0:
                        cleared += 1
        verdict = "MONO (bits never clear)" if tot and cleared == 0 else \
                  ("frozen" if tot == 0 else f"CLEARING ({cleared}/{tot})")
        print(f"  {label:42s} changed={tot:5d} cleared={cleared:5d}  {verdict}")
    print()

# sliding windows on run A (CORRECT orientation) — where do bits only ever set?
print("== sliding 256B windows on TAS runA (>=32 changed bytes), sorted by clear% ==")
res = []
W, S = 256, 128
first, last = tas_bufs[0], tas_bufs[-1]
for s in range(0x40, 0x64F8 - W, S):
    e = s + W
    ch = [o for o in range(s, e) if first[o] != last[o]]
    if len(ch) < 32: continue
    cl = sum(1 for o in ch if (first[o] & ~last[o] & 0xFF) != 0)
    res.append((cl/len(ch), len(ch), s, e))
res.sort()
for clp, ch, s, e in res[:20]:
    print(f"  0x{s:04X}-0x{e:04X} changed={ch:3d} clear%={clp*100:5.1f}")
