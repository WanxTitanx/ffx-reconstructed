#!/usr/bin/env python3
"""Render all tiles compactly (1 line per tile, ink width) to map the layout."""
import struct, sys
sys.stdout.reconfigure(encoding='utf-8', errors='replace')

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
slots = tpr * (f['ih'] // th)
wt = f['data'][f['wptr']:f['wptr']+f['wsize']]

# For each tile, compute ink bbox and a compact 6-char signature
for t in range(slots):
    tx = (t % tpr) * tw
    ty = (t // tpr) * th
    # ink bbox
    minx, maxx, miny, maxy = 99, -1, 99, -1
    for y in range(th):
        for x in range(tw):
            if get_pixel(img, iw, tx+x, ty+y) > 0:
                if x < minx: minx = x
                if x > maxx: maxx = x
                if y < miny: miny = y
                if y > maxy: maxy = y
    if maxx < 0:
        print(f"slot {t:3d} row {t//tpr:2d} col {t%tpr} EMPTY")
        continue
    inkw = maxx - minx + 1
    inkh = maxy - miny + 1
    # compact render: 14 cols -> 7 chars (2px each)
    sig = ''
    for y in range(0, th, 3):
        line = ''
        for x in range(0, tw, 2):
            v = 0
            for dy in range(3):
                for dx in range(2):
                    if y+dy < th and x+dx < tw:
                        v = max(v, get_pixel(img, iw, tx+x+dx, ty+y+dy))
            line += ' .:-=+*#%@'[min(v, 9)]
        sig += line
    wv = wt[t] if t < len(wt) else -1
    print(f"slot {t:3d} row {t//tpr:2d} col {t%tpr} ink={inkw}x{inkh} wt[{t}]={wv} |{sig}|")
