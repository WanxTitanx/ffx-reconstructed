#!/usr/bin/env python3
"""ps2_et_eff_dump.py — minimal dump for the et_*.bin / eff_*.bin effect-data family
(effect/et_battle/et_battle*.bin, yonishi_data/dat_et/bat_eff/*, dat_ov/mag_XXXX/eff_XXXX.bin).

OBSERVED layout (hexdump corpus 2026-09-16 — PARTIALLY UNKNOWN semantics):
  +0x00 u32      always 0
  +0x04..+0x24   8 u32 slots of ascending section offsets (0x60,0x70,...) — duplicates allowed
  +0x28..+0x38   5 u32 slots, always 0
  +0x3C u32      table-end sentinel (== last section offset)
  +0x40 u32      0x00010000 (tag/flags, hi=1)
  +0x44 u32      packed counts (e.g. 0x00060006 → two u16 counts: 6,6)
  +0x48..+0x54   small flags/counts (0/1/4)
Sections @ the offsets begin with a zero region then record tables — field-level decode
NOT proven (atlas §8.15 documents the container role only). This tool dumps the fixed-slot
directory + first dword at each target.

Usage: ps2_et_eff_dump.py <file-or-dir> [glob]
"""
import os, sys, struct, glob

def dump(path):
    d = open(path, 'rb').read()
    if len(d) < 0x58:
        return f"{path}: SMALL"
    hdr = struct.unpack_from('<22I', d, 0)
    slots = hdr[1:9]      # section offsets
    sent = hdr[15]        # table-end sentinel
    tag = hdr[16]
    counts = hdr[17]
    lines = [f"{os.path.basename(path)} ({len(d)}B):",
             f"  slots[1..8]: {' '.join(f'0x{v:X}' for v in slots)}",
             f"  zero[9..13]: {' '.join(f'{v:X}' for v in hdr[9:14])}  end=0x{sent:X}  tag=0x{tag:X}  counts=0x{counts:X} (u16: {counts & 0xFFFF},{counts >> 16})",
             f"  tail flags: {' '.join(f'{v:X}' for v in hdr[18:22])}"]
    uniq = sorted(set(v for v in slots if v))
    for o in uniq[:6]:
        if o + 4 <= len(d):
            w = struct.unpack_from('<4I', d, o)
            lines.append(f"  @0x{o:X}: {' '.join(f'{x:08x}' for x in w)}")
    return "\n".join(lines)

def main():
    if len(sys.argv) < 2:
        print(__doc__); return 2
    root, pat = sys.argv[1], sys.argv[2] if len(sys.argv) > 2 else None
    files = [root] if os.path.isfile(root) else sorted(
        os.path.join(dp, f) for dp, _, fns in os.walk(root)
        for f in fns if glob.fnmatch.fnmatch(f.lower(), (pat or '*').lower()))
    for f in files:
        print(dump(f))
    print(f"== {len(files)} files dumped")

if __name__ == '__main__':
    sys.exit(main())
