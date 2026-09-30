#!/usr/bin/env python3
"""ps2_tim2_dump.py — minimal header dump for .tm2/.tim2 (PS2 TIM2 texture).

PROVEN (atlas §7.x/§11.3 + Ps2Tim2Reader + Ps2Tim2Writer):
  +0x00 char[4] 'TIM2'
  +0x04 u8 version (4), u8 format(?) — bytes 04 00 01 00 typical
  +0x10 u32 file-total size-ish (blockSize)
  +0x14 u32 palette (CLUT) bytes
  +0x18 u32 image bytes
  +0x1C u16 picture-header size   +0x1E u16 color count
  +0x23 u8  bpp-ish               +0x24 u16 width  +0x26 u16 height
  file size == 0x40 + imageBytes + paletteBytes  (Ps2Tim2Reader formula)
This tool prints the header fields and checks the size formula.
"""
import os, sys, struct, glob

def dump(path):
    d = open(path, 'rb').read()
    if len(d) < 0x28 or d[:4] != b'TIM2':
        return f"{os.path.basename(path)}: NOT TIM2 ({d[:8].hex()})"
    ver, fmt = d[4], d[6]
    blk, pal, img = struct.unpack_from('<3I', d, 0x10)
    phsz, ncol = struct.unpack_from('<2H', d, 0x1C)
    bpp = d[0x23]
    w, h = struct.unpack_from('<2H', d, 0x24)
    expect = 0x40 + img + pal
    ok = "OK" if expect == len(d) else f"SIZE-MISMATCH exp=0x{expect:X}"
    return (f"{os.path.basename(path)} ({len(d)}B): TIM2 v{ver} fmt={fmt} "
            f"blk=0x{blk:X} pal=0x{pal:X} img=0x{img:X} phdr=0x{phsz:X} colors={ncol} "
            f"bpp~{bpp} {w}x{h} {ok}")

def main():
    if len(sys.argv) < 2:
        print(__doc__); return 2
    root, pat = sys.argv[1], sys.argv[2] if len(sys.argv) > 2 else '*.tm2'
    files = [root] if os.path.isfile(root) else sorted(
        os.path.join(dp, f) for dp, _, fns in os.walk(root)
        for f in fns if glob.fnmatch.fnmatch(f.lower(), (pat or '*').lower()))
    for f in files:
        print(dump(f))
    print(f"== {len(files)} files dumped")

if __name__ == '__main__':
    sys.exit(main())
