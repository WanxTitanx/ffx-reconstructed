#!/usr/bin/env python3
"""Correlate the 592 glyph cells of the legacy 0x73 event font
(jppc/event/obj/base.ftc, 16x12 cells, 4bpp+shadow) against the 999-glyph
FTCX menu font (jppc/menu/base.ftc, sjistbl order) via normalized ink-mask
distance. Output: best matches CSV + summary.

Normalization: crop to ink bbox, pad to square, resize to 16x16 L-mode,
compare by absolute-difference sum (PIL C-level ops; no numpy).
"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                "..", "..", "research_tools", "Ps2"))
from PIL import Image, ImageChops
import ftc73_dump
import ftc_reader

MASTER = "/mnt/nvme-xpg/ffx_ps2/ffx/master"
EV = MASTER + "/jppc/event/obj/base.ftc"
MENU = MASTER + "/jppc/menu/base.ftc"
OUT = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                   "evfont_glyph_match.csv")
N = 16  # normalized size


def norm_mask(rows, w, h, thresh):
    """rows[y][x] intensity -> cropped square 16x16 L image (ink=white)."""
    xs, ys = [], []
    for y in range(h):
        for x in range(w):
            if rows[y][x] >= thresh:
                xs.append(x)
                ys.append(y)
    if not xs:
        return None
    x0, x1, y0, y1 = min(xs), max(xs), min(ys), max(ys)
    cw, ch = x1 - x0 + 1, y1 - y0 + 1
    im = Image.new("L", (cw, ch))
    p = im.load()
    for y in range(ch):
        for x in range(cw):
            p[x, y] = 255 if rows[y0 + y][x0 + x] >= thresh else 0
    side = max(cw, ch)
    sq = Image.new("L", (side, side))
    sq.paste(im, ((side - cw) // 2, (side - ch) // 2))
    return sq.resize((N, N), Image.BILINEAR)


def diff(a, b):
    d = ImageChops.difference(a, b)
    return sum(d.histogram()[i] * i for i in range(256))


def main():
    ev = ftc73_dump.parse(EV)
    epx, ew, eh = ftc73_dump.sheet_pixels(ev, "packed4")
    mf = ftc_reader.parse(MENU)

    # menu glyph masks (999), event cell masks (592)
    menu_masks = []
    for g in range(mf["count"]):
        bm = ftc_reader.glyph_bitmap(mf, g)
        menu_masks.append(norm_mask(bm, mf["cellW"], mf["cellH"], 1))
    ev_masks = []
    for c in range(len(ev["pairs"])):
        cx, cy = c % (ew // 16), c // (ew // 16)
        cell = [row[cx * 16:(cx + 1) * 16]
                for row in epx[cy * 12:(cy + 1) * 12]]
        ev_masks.append(norm_mask(cell, 16, 12, 8))  # ink = nibble >= 8

    lines = ["cell,adv,ink,match1,dist1,match2,dist2,match3,dist3"]
    hits = 0
    for c, m in enumerate(ev_masks):
        if m is None:
            lines.append("%d,%d,%d,,,,," % (c, *ev["pairs"][c]))
            continue
        scored = []
        for g, mm in enumerate(menu_masks):
            if mm is None:
                continue
            scored.append((diff(m, mm), g))
        scored.sort()
        top = scored[:3]
        if top[0][0] < 9000:  # rough same-shape threshold (16x16*~35)
            hits += 1
        row = "%d,%d,%d" % (c, *ev["pairs"][c])
        for d, g in top:
            row += ",%d,%d" % (g, d)
        lines.append(row)
    open(OUT, "w").write("\n".join(lines) + "\n")
    print("wrote", OUT, " hits(<9000):", hits, "/", sum(1 for m in ev_masks if m))


if __name__ == "__main__":
    main()
