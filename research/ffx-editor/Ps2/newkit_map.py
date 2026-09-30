#!/usr/bin/env python3
"""Map newkit glyph index -> atlas cell, build glyph-ordered contact sheet,
and correlate each newkit glyph against the HD base font atlas to identify
kanji via sjistbl_jp.

Mapping (PROVEN 2026-09-17 by metric<->ink-width correlation, 60/60 cells,
mean |metric-inkwidth| < 1px): glyph g -> page = g&1, pair k = g>>1 ->
cell(row = rows-1 - k/9, col = k%9).  i.e. glyph PAIRS fill the atlas
bottom-up: even glyphs live on page 0, odd glyphs on page 1, and each
successive pair advances one 56x64 cell up the shared 9-col grid.

NOTE on the sjistbl correlation below: it is kept for completeness but is
NOT a valid semantic source -- every newkit glyph matches its best
base_ftc (sjistbl) cell at 16-31% pixel divergence, i.e. newkit glyphs are
NOT the same kanji as the base font.  newkit is a self-contained 60-glyph
supplementary bank (slot 5) of kanji + a few symbols (R-in-circle, box
frame, triple-X, chevrons); identify them by corpus context / vision, not
by this matcher.
"""
import os
import sys
from PIL import Image, ImageChops

HERE = os.path.dirname(os.path.abspath(__file__))
NK = "/mnt/nvme-samsung/FFX Mods/ps3data_textures_png/menu/newkit_ftc/d3d11"
BS = "/mnt/nvme-samsung/FFX Mods/ps3data_textures_png/menu/base_ftc/d3d11"
SJ = "/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/ffx_encoding/ffxsjistbl_jp.bin"

NK_ROWS, NK_COLS, NK_CW, NK_CH = 4, 9, 56, 64
BS_ROWS, BS_COLS, BS_CW, BS_CH = 56, 9, 56, 73


def cell_img(page_im, rows, cols, cw, ch, g):
    k, p = g >> 1, g & 1
    r = rows - 1 - k // cols
    c = k % cols
    if r < 0:
        return None
    return page_im[p].crop((c * cw, r * ch, c * cw + cw, r * ch + ch))


def norm(im, n=24):
    """alpha mask -> bbox-cropped square n x n L image"""
    a = im.split()[3]
    bb = a.getbbox()
    if not bb:
        return None
    a = a.crop(bb)
    w, h = a.size
    s = max(w, h)
    sq = Image.new("L", (s, s))
    sq.paste(a, ((s - w) // 2, (s - h) // 2))
    return sq.resize((n, n), Image.BILINEAR)


def diff(a, b):
    d = ImageChops.difference(a, b)
    h = d.histogram()
    return sum(i * h[i] for i in range(256))


def main():
    nk = [Image.open(os.path.join(NK, "font_0_%d.png" % i)).convert("RGBA")
          for i in (0, 1)]
    bs = [Image.open(os.path.join(BS, "font_0_%d.png" % i)).convert("RGBA")
          for i in (0, 1)]
    sj = open(SJ, "rb").read().decode("utf-8")

    # glyph-ordered newkit sheet
    sheet = Image.new("RGBA", (NK_COLS * NK_CW, 4 * NK_CH), (0, 0, 0, 255))
    nk_norm = {}
    for g in range(60):
        cell = cell_img(nk, NK_ROWS, NK_COLS, NK_CW, NK_CH, g)
        if cell is None:
            continue
        sheet.paste(cell, ((g % 9) * NK_CW, (g // 9) * NK_CH))
        nk_norm[g] = norm(cell)
    sheet.save(os.path.join(HERE, "newkit_glyphs_ordered.png"))
    print("wrote newkit_glyphs_ordered.png")

    # base atlas: glyph index -> normalized mask (only first ~700 to save time)
    bs_norm = {}
    for g in range(999):
        cell = cell_img(bs, BS_ROWS, BS_COLS, BS_CW, BS_CH, g)
        if cell is not None:
            bs_norm[g] = norm(cell)

    out = ["glyph,char_or_best,bestidx,dist,second,secdist"]
    for g in range(60):
        m = nk_norm.get(g)
        if m is None:
            out.append("%d,(empty),,," % g)
            continue
        scored = sorted((diff(m, mm), gi) for gi, mm in bs_norm.items()
                        if mm is not None)
        d0, i0 = scored[0]
        d1, i1 = scored[1]
        ch = sj[i0] if i0 < len(sj) else "?"
        out.append("%d,%s,%d,%d,%d,%d" % (g, ch, i0, d0, i1, d1))
    csv = os.path.join(HERE, "newkit_glyph_map.csv")
    open(csv, "w").write("\n".join(out) + "\n")
    print("wrote", csv)


if __name__ == "__main__":
    main()
