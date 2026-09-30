#!/usr/bin/env python3
"""Analyze FTCX font layout - render image, find glyphs, test mappings."""
import sys, struct

def read_ftc(path):
    d = open(path, 'rb').read()
    magic, r1, r2, typ, r3, r4 = struct.unpack_from('<IHHHHI', d, 0)
    tcount, tw, th = struct.unpack_from('<IHH', d, 0x10)
    imgptr, imgsize, iw, ih = struct.unpack_from('<IIHH', d, 0x20)
    wptr, wsize = struct.unpack_from('<II', d, 0x30)
    return dict(magic=magic, type=typ, tcount=tcount, tw=tw, th=th,
                imgptr=imgptr, imgsize=imgsize, iw=iw, ih=ih,
                wptr=wptr, wsize=wsize, data=d)

def get_pixel(img, iw, x, y):
    row = y * (iw // 2)
    off = row + x // 2
    b = img[off]
    return (b >> 4) & 0xF if (x & 1) == 0 else b & 0xF

def render_tile(img, iw, tw, th, tx, ty, p=" .:-=+*#%@"):
    out = []
    for y in range(th):
        line = ''
        for x in range(tw):
            v = get_pixel(img, iw, tx + x, ty + y)
            line += p[min(v * (len(p)-1) // 15, len(p)-1)]
        out.append(line)
    return out

def main():
    path = sys.argv[1]
    f = read_ftc(path)
    print(f"magic={f['magic']:08X} type={f['type']} tiles={f['tcount']} "
          f"cell={f['tw']}x{f['th']} img={f['iw']}x{f['ih']} "
          f"imgptr={f['imgptr']:#x} imgsize={f['imgsize']} "
          f"wptr={f['wptr']:#x} wsize={f['wsize']}")
    img = f['data'][f['imgptr']:f['imgptr']+f['imgsize']]
    wt = f['data'][f['wptr']:f['wptr']+f['wsize']]
    tw, th = f['tw'], f['th']
    tpr = f['iw'] // tw          # tiles per row
    rows = f['ih'] // th
    slots = tpr * rows
    print(f"tiles/row={tpr} rows={rows} slots={slots}")
    print(f"width table: {len(wt)} bytes, min={min(wt)} max={max(wt)}")
    # print first 64 width entries
    print("width[0:64]:", list(wt[:64]))
    # render first 2 rows of tiles
    for t in range(min(18, slots)):
        tx = (t % tpr) * tw
        ty = (t // tpr) * th
        print(f"--- tile slot {t} (x={tx},y={ty}) ---")
        for line in render_tile(img, f['iw'], tw, th, tx, ty):
            print(line)

if __name__ == '__main__':
    main()
