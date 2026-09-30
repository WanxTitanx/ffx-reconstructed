#!/usr/bin/env python3
"""Find tile boundaries in FTCX image by analyzing pixel density."""
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

f = read_ftc(sys.argv[1])
img = f['data'][f['imgptr']:f['imgptr']+f['imgsize']]
iw = f['iw']

def get_pixel(x, y):
    off = y * (iw // 2) + x // 2
    b = img[off]
    return (b >> 4) & 0xF if (x & 1) == 0 else b & 0xF

# Column density: for each x, count non-zero pixels down the whole image
print("Column density (x: count of non-zero pixels over all rows):")
for x in range(iw):
    cnt = sum(1 for y in range(f['ih']) if get_pixel(x, y) > 0)
    print(f"  x={x:3d}: {cnt:4d}", end='')
    if x % 4 == 3: print()
print()

# Row density: for each y, count non-zero pixels across the width
print("Row density (y: count of non-zero pixels across width):")
for y in range(f['ih']):
    cnt = sum(1 for x in range(iw) if get_pixel(x, y) > 0)
    print(f"  y={y:3d}: {cnt:3d}", end='')
    if y % 4 == 3: print()
