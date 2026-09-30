#!/usr/bin/env python3
"""ps2_scn_sNN_dump.py — minimal dump for battle/scn/sNN.bin (battle scene script/data blobs).

OBSERVED layout (hexdump corpus s00..s18, 2026-09-16 — semantics PARTIALLY UNKNOWN):
  +0x00 u32 = 2          (pair of header words? constant across corpus)
  +0x04 u32 = 0x10       (constant)
  +0x08 u32 = fileSize   (verified: s00=0x153A0=86944 == stat)
  +0x0C u32 = 0
  +0x10 u32 = 2          (constant)
  +0x14 u32 = 0x0C       (constant)
  +0x18 u32 = 0x154      (first block offset — constant across corpus)
  +0x1C u32 = 0x50       (second block offset — constant)
  +0x20..               flat u32 offset table; groups separated by 4x u32 zeros.
                        All values are file offsets < fileSize (verified on s00/s11).
This tool dumps the 7-u32 header + the offset table split into zero-separated groups.

Usage: ps2_scn_sNN_dump.py <file-or-dir> [glob]
"""
import os, sys, struct, glob

def dump(path):
    d = open(path, 'rb').read()
    if len(d) < 0x20:
        return f"{path}: SMALL"
    hdr = struct.unpack_from('<7I', d, 0)
    out = [f"{os.path.basename(path)} ({len(d)}B): hdr7=[{', '.join(hex(v) for v in hdr)}]"]
    if hdr[2] != len(d):
        out.append(f"  !! fsz@+8 {hdr[2]:#x} != actual {len(d):#x}")
    # flat offset table from +0x20: ascending u32s with 4-zero separators, ends at table end.
    # table ends when values stop being in-range offsets (first block at hdr[6]=0x154).
    vals = []
    o = 0x20
    while o + 4 <= len(d):
        v = struct.unpack_from('<I', d, o)[0]
        if v >= len(d) and v != 0:
            break
        vals.append((o, v))
        o += 4
        if len(vals) > 0x2000:
            break
    # split into groups on runs of >=4 zeros
    groups, cur = [], []
    for off, v in vals:
        if v == 0:
            cur.append((off, v))
        else:
            if cur and all(x == 0 for _, x in cur) and len(cur) >= 4 and groups or cur and all(x == 0 for _, x in cur) and len(cur) >= 4 and not groups:
                if groups:
                    out.append(f"  grp{len(groups)} @{groups[-1][0]:#x}..{groups[-1][1]:#x}: n={groups[-1][2]}")
                groups.append((off, 0, 0))
                cur = []
            elif cur and all(x == 0 for _, x in cur) and len(cur) >= 4:
                groups.append((cur[0][0], off, 0))
                cur = []
            cur.append((off, v))
    # simpler: report runs
    runs = []
    run = []
    for off, v in vals:
        if v == 0:
            if run:
                runs.append((run[0][0], run[-1][0] + 4, len(run))); run = []
        else:
            run.append((off, v))
    if run:
        runs.append((run[0][0], run[-1][0] + 4, len(run)))
    out.append(f"  offset-table @{0x20:#x}: {len(vals)} slots -> {len(runs)} nonzero runs: "
               + ' '.join(f'[{a:#x}..{b:#x})n={c}' for a, b, c in runs[:10]))
    if vals:
        bad = [v for _, v in vals if v >= len(d)]
        out.append(f"  maxoff=0x{max(v for _, v in vals):X} inrange={len(bad) == 0}")
    return "\n".join(out)

def main():
    if len(sys.argv) < 2:
        print(__doc__); return 2
    root, pat = sys.argv[1], sys.argv[2] if len(sys.argv) > 2 else 's*.bin'
    files = [root] if os.path.isfile(root) else sorted(
        os.path.join(dp, f) for dp, _, fns in os.walk(root)
        for f in fns if glob.fnmatch.fnmatch(f.lower(), (pat or '*').lower()))
    for f in files:
        print(dump(f))
    print(f"== {len(files)} files dumped")

if __name__ == '__main__':
    sys.exit(main())
