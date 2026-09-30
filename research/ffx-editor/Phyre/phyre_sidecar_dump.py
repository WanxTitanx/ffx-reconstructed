#!/usr/bin/env python3
"""phyre_sidecar_dump.py — classify + minimal dump for the Phyre/PS3 sidecar files:
  .ah / .ahx64  — auto-generated C-header TEXT (Phyre register/struct maps; "// This file is
                  auto-generated" — NOT binary). Dumped as: first lines + #define count.
  .pal          — small binary (20B-multiple records of f16/u32? observed 40B-11KB;
                  structure UNKNOWN — emit dword/float hexdump of head).
  .pfl          — plain-text path list (one /ffx_ps2/... path per line) — pack list.
  .cdf          — binary f32 records (leaden by 24B? header-less; UNKNOWN — emit floats).
  .cmf          — binary, u32 header (01,08,01,0b,... observed) — UNKNOWN semantics.
  texlist.txt   — text list of texture hashes.
  .bin in TextureVideo/ — u32 triple + f32 table (observed texVideoLchb.bin).
Usage: phyre_sidecar_dump.py <file> | <dir> [glob]
"""
import os, sys, struct, glob

def dump(path):
    fn = os.path.basename(path)
    ext = os.path.splitext(fn)[1].lower()
    d = open(path, 'rb').read()
    n = len(d)
    if ext in ('.ah', '.ahx64', '.pfl') or fn == 'texlist.txt':
        txt = d.decode('utf-8', 'replace')
        lines = txt.splitlines()
        defines = sum(1 for l in lines if l.startswith('#define'))
        head = ' | '.join(l.strip()[:60] for l in lines[:3])
        kind = {'ah': 'C-header (32-bit/GCM)', 'ahx64': 'C-header (x64/GNM)',
                'pfl': 'path list', 'txt': 'text list'}.get(ext[1:], 'text')
        return f"{fn} ({n}B): TEXT {kind}; lines={len(lines)} defines={defines} head: {head}"
    if ext == '.pal':
        w = struct.unpack('<%dI' % (min(n, 48) // 4), d[:min(n, 48)])
        return f"{fn} ({n}B): BIN .pal recSize~20B n/20={n % 20 == 0} head={' '.join(f'{x:08x}' for x in w)}"
    if ext in ('.cdf', '.cmf', '.bin'):
        w = struct.unpack('<%dI' % (min(n, 48) // 4), d[:min(n, 48)])
        fl = ' '.join(f'{struct.unpack("<f", struct.pack("<I", x))[0]:.4g}' for x in w[:12])
        return f"{fn} ({n}B): BIN {ext} u32={' '.join(f'{x:08x}' for x in w[:8])} f32~[{fl}]"
    return f"{fn} ({n}B): ext={ext} head={d[:32].hex()}"

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
