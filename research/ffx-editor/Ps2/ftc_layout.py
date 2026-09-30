#!/usr/bin/env python3
"""Render full FTCX image at low res to see tile grid layout."""
import struct, sys

def read_ftc(path):
    d = open(path, 'rb').read()
    magic, r1, r2, typ, r3, r4 = struct.unpack_from('<IHHHHI', d, 0)
    tcount, tw, th = struct.unpack_from('<IHH', d, 0x10)
    imgptr, imgsize, iw, ih = struct.unpack_from('<IIHH', d, 0x20)
    wptr, wsize = struct.unpack_from('<II', d, 0x30)
    return dict(type=typ, tcount=tcount, tw=tw, th=th,
                imgptr=imgptr, imgsize=imgsize, iw=iw, ih=ih,
                wptr=wptr, wsize=wsize, data=d)

def get_pixel(img, iw, x, y):
    off = y * (iw // 2) + x // 2
    b = img[off]
    return (b >> 4) & 0xF if (x & 1) == 0 else b & 0xF

f = read_ftc(sys.argv[1])
img = f['data'][f['imgptr']:f['imgptr']+f['imgsize']]
iw = f['iw']
# Render whole image scaled down: each output char = 2x2 block, value = max
print(f"FULL IMAGE {iw}x{f['ih']} (each char = 2x2 block, max value)")
for y in range(0, f['ih'], 2):
    line = ''
    for x in range(0, iw, 2):
        v = max(get_pixel(img, iw, x, y), get_pixel(img, iw, x+1, y),
                get_pixel(img, iw, x, y+1), get_pixel(img, iw, x+1, y+1))
        line += ' .:-=+*#%@'[min(v, 9)]
    print(f"{y:4d} {line}")
