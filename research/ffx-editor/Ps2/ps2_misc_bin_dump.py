#!/usr/bin/env python3
"""ps2_misc_bin_dump.py — generic header probe for the long-tail PS2 formats with no
dedicated reader: .sps2 .sbin .fmt .msb .clp .dcp .rbin .sc .tim .prj .out .bak .vgr .ovp
.par .pdt .oms .otp .fp .mds .grp .clc .h (binary-ish), TextureVideo .bin, metamenu .dat.

For each file: size, magic guess (ASCII/EV01/TIM2/MAP1/RYHP/MZ/known), u32[0..16],
u16[0..16], f32[0..8] sanity views, and a flag when the u32 stream looks like an
ascending offset table (common FFX container idiom).

Usage: ps2_misc_bin_dump.py <file-or-dir> [glob]
"""
import os, sys, struct, glob

MAGICS = [(b'EV01', 'EV01 event container'), (b'TIM2', 'TIM2 texture'),
          (b'MAP1', 'MAP1 mapout'), (b'RYHP', 'Phyre cluster'), (b'MZ', 'PE'),
          (b'FTCX', 'FTCX font'), (b'OggS', 'OGG'), (b'\x89PNG', 'PNG'),
          (b'VAGp', 'VAG audio'), (b'SM2', 'SM2?')]

def looks_offsets(w):
    nz = [x for x in w if x]
    return len(nz) >= 3 and all(a < b for a, b in zip(nz, nz[1:]))

def dump(path):
    fn = os.path.basename(path)
    try:
        d = open(path, 'rb').read()
    except OSError as e:
        return f"{fn}: UNREADABLE {e}"
    n = len(d)
    tag = next((name for m, name in MAGICS if d[:len(m)] == m), None)
    head = d[:16]
    asci = sum(1 for b in head if 32 <= b < 127 or b in (9, 10, 13))
    kind = tag or ('text-ish' if asci >= 12 else 'binary')
    w = struct.unpack('<%dI' % (min(n, 64) // 4), d[:(min(n, 64) // 4) * 4]) if n >= 4 else ()
    u16 = struct.unpack('<%dH' % (min(n, 32) // 2), d[:(min(n, 32) // 2) * 2]) if n >= 2 else ()
    fl = []
    for x in w[:8]:
        f = struct.unpack('<f', struct.pack('<I', x))[0]
        fl.append(f'{f:.4g}' if abs(f) < 1e10 and (f != 0) else ('0' if f == 0 else '?'))
    extra = ''
    if w and looks_offsets(list(w)):
        extra += ' [ascending-u32 offset-table candidate]'
    if n % 20 == 0 and n > 100:
        extra += ' [20B-record candidate]'
    return (f"{fn} ({n}B): {kind}\n"
            f"  u32: {' '.join(f'{x:08x}' for x in w[:12])}\n"
            f"  u16: {' '.join(f'{x:04x}' for x in u16[:12])}\n"
            f"  f32~: {' '.join(fl)}{extra}")

def main():
    args = sys.argv[1:]
    if not args:
        print(__doc__); return 2
    root, pat = args[0], args[1] if len(args) > 1 else '*'
    files = [root] if os.path.isfile(root) else sorted(
        os.path.join(dp, f) for dp, _, fns in os.walk(root)
        for f in fns if glob.fnmatch.fnmatch(f.lower(), (pat or '*').lower()))
    for f in files:
        print(dump(f))
    print(f"== {len(files)} files dumped")

if __name__ == '__main__':
    sys.exit(main())
