#!/usr/bin/env python3
# ============================================================================
# user_chain.py — real-user progression chain (2017-2026) + header forensics +
#                 TAS run-A (ffx_020..ffx_050, monotonic) bit-monotonicity re-test.
# CONTEXT: user slots from /mnt/disco-velho backups copied to work/_saves_re/user_slots
#          (12 slots of Backup C 2026-09-02 + ffx_002.bak_jarvis from Old C 2017,
#          byte-identical to current ffx_002 -> slot untouched for 9 years).
# ============================================================================
import os, re, struct, json, hashlib

REPO = "/home/wanderson/Documents/ffx-editor-main"
US = os.path.join(REPO, "work/_saves_re/user_slots")
TAS = os.path.join(REPO, "Utilities/FFX_TAS_Python/tas_saves")
OUT = os.path.join(REPO, "work/_saves_re")

def u8(b,o): return b[o]
def u16(b,o): return struct.unpack_from('<H',b,o)[0]
def u32(b,o): return struct.unpack_from('<I',b,o)[0]

def load(d, f): return open(os.path.join(d,f),'rb').read()

MODULES = [
    ("HDR",0x0000,0x0040),("G1",0x0040,0x02B9),("G2",0x02B9,0x0441),
    ("GAP2",0x0441,0x062C),("G3",0x062C,0x0D18),("GAP3",0x0D18,0x19C4),
    ("G4",0x19C4,0x21CC),("GAP4",0x21CC,0x21EC),("SG",0x21EC,0x350C),
    ("GAP5",0x350C,0x3D4C),("G5",0x3D4C,0x3E0C),("G6",0x3E0C,0x3F0C),
    ("G11",0x3F0C,0x420C),("G7",0x420C,0x424C),("G8",0x424C,0x44CC),
    ("G9",0x44CC,0x44DC),("EQP",0x44DC,0x560C),("G12",0x560C,0x6074),
    ("G10",0x6074,0x638C),("NAM",0x638C,0x64F4),("CRC",0x64F4,0x64F8),
]

def diffmods(a, b):
    out = {}
    for k,s,e in MODULES:
        n = sum(1 for o in range(s,e) if a[o]!=b[o])
        if n: out[k] = n
    return out

# ── 1. user real timeline ordered by in-file game_time ──
files = [f for f in os.listdir(US) if not f.endswith('.bak_jarvis')]
timeline = sorted(files, key=lambda f: u32(load(US,f), 0xFC))
print("USER TIMELINE (by game_time @0xFC):")
for f in timeline:
    b = load(US,f)
    print(f"  {f:8s} time={u32(b,0xFC):7d}s story={u16(b,0xC2C):4d} btl={u32(b,0x3D54):4d} "
          f"gil={u32(b,0x3D88):9d} room={u16(b,0x40):3d}")
pairs = list(zip(timeline[:-1], timeline[1:]))
print(f"\nUSER CHAIN DIFFS ({len(pairs)} pairs):")
agg = {}
res_pairs = []
for fa, fb in pairs:
    a, b = load(US,fa), load(US,fb)
    dm = diffmods(a,b)
    tot = sum(dm.values())
    print(f"  {fa}(story{u16(a,0xC2C)}) -> {fb}(story{u16(b,0xC2C)}): {tot:5d} diff B  {dm}")
    res_pairs.append({'a':fa,'b':fb,'story_a':u16(a,0xC2C),'story_b':u16(b,0xC2C),
                      'time_a':u32(a,0xFC),'time_b':u32(b,0xFC),'total':tot,'by_module':dm})
    for k,v in dm.items():
        agg.setdefault(k,[0,0]); agg[k][0]+=1; agg[k][1]+=v
print("\naggregate:", {k:tuple(v) for k,v in sorted(agg.items(), key=lambda x:-x[1][1])})

# ── 2. header forensics: which HDR bytes differ between user saves ──
print("\nHEADER FORENSICS (first 0x20 bytes) — 2017 save vs 2026 saves:")
old = load(US,'ffx_002.bak_jarvis')
for f in ['ffx_000','ffx_011','ffx_007']:
    b = load(US,f)
    d = [hex(o) for o in range(0x20) if old[o]!=b[o]]
    print(f"  002(2017) vs {f}: hdr diff offsets {d}")
    print(f"    002.hdr: {old[:0x20].hex(' ')}")
    print(f"    {f}.hdr: {b[:0x20].hex(' ')}")
# u32@0x10 vs game_time
print("\nu32@0x10 (hdr playtime?) vs game_time@0xFC:")
for f in timeline[:12]:
    b = load(US,f)
    print(f"  {f:8s} u32@0x10={u32(b,0x10):7d}  time@0xFC={u32(b,0xFC):7d}  delta={u32(b,0xFC)-u32(b,0x10):6d}")

# ── 3. TAS run A (020->050) monotonic chain re-test ──
runA = sorted([f for f in os.listdir(TAS) if re.match(r'ffx_0[2-5]\d\d?$', f)],
              key=lambda x: int(re.search(r'\d+',x).group()))
runA = [f for f in runA if 20 <= int(re.search(r'\d+',f).group()) <= 50]
bufs = [load(TAS,f) for f in runA]
print(f"\nTAS RUN A: {runA[0]}..{runA[-1]} ({len(runA)} saves, story {u16(bufs[0],0xC2C)}->{u16(bufs[-1],0xC2C)})")
def region_mono(s,e,label):
    tot=vio=0
    for i in range(len(bufs)-1):
        a,b = bufs[i],bufs[i+1]
        for o in range(s,e):
            if a[o]!=b[o]:
                tot+=1
                if (b[o] & ~a[o] & 0xFF)!=0: vio+=1
    print(f"  {label:44s} changed={tot:5d} bitclear_viol={vio:5d} {'MONO' if vio==0 else ''}")
region_mono(0x444C,0x448C,"G8 monsters_seen @0x444C")
region_mono(0x448C,0x44CC,"G8 monsters_defeated @0x448C")
region_mono(0x420C,0x422C,"G7 items_acquired @0x420C")
region_mono(0x44CC,0x44DC,"G9 key_items @0x44CC")
region_mono(0x3E0C,0x3F0C,"G6 event_flags(atlas) @0x3E0C")
region_mono(0x0D18,0x19C4,"GAP3 unmapped @0x0D18")

# GAP3 byte-value histogram in last save of run A (is it bitfield-like?)
last = bufs[-1]
from collections import Counter
seg = last[0x0D18:0x19C4]
c = Counter(seg)
common = c.most_common(12)
print(f"\nGAP3 byte histogram (ffx_050): {common}  | distinct={len(c)} span={len(seg)}")

json.dump({'user_chain':res_pairs}, open(os.path.join(OUT,'user_chain.json'),'w'), indent=1)
