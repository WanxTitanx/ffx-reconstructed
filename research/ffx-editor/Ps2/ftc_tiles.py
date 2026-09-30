#!/usr/bin/env python3
"""Render specific tile slots at full resolution."""
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
iw = f['iw']; tw, th = f['tw'], f['th']
tpr = iw // tw
slots = [int(x) for x in sys.argv[2].split(',')]
for t in slots:
    tx = (t % tpr) * tw
    ty = (t // tpr) * th
    print(f"=== slot {t} (x={tx},y={ty}) ===")
    for y in range(th):
        line = ''
        for x in range(tw):
            v = get_pixel(img, iw, tx+x, ty+y)
            line += ' .:-=+*#%@'[min(v, 9)]
        print(line)
