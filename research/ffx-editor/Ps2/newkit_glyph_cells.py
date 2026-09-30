#!/usr/bin/env python3
"""newkit_glyph_cells.py — dump `menu/newkit.ftc` HD atlas cells as per-GLYPH
PNGs (bank-5 index order), rendered black-ink-on-white and upscaled for
OCR/vision pipelines.

WHY this exists (2026-09-17, lane Jarvis-DEVIN / NEWKIT-OCR):
  work/_ftc_res/newkit_cells.py names cells by LINEAR CELL INDEX
  (page*36 + row*9 + col), which is NOT the bank-5 glyph index.  This tool
  applies the PROVEN glyph->cell map from
  docs/reverse/FFX_FMT_FTC_RESIDUAL_2026-09-17.md §2.2:

      page = g & 1                # even glyph -> page0, odd -> page1
      k    = g >> 1               # glyph-pair index
      row  = (ROWS-1) - k // COLS # pairs fill BOTTOM-UP
      col  = k % COLS

  (proven by metric<->ink-width correlation, 60/60 glyphs, avg err < 1px).

Atlas: menu/newkit_ftc/d3d11/font_0_{0,1}.png — 512x256 RGBA, 9 cols x 4 rows
of 56x64 cells, 36 cells/page, 72 total; newkit.ftc declares 60 live glyphs
(+0x10) with 72-cell capacity (+0x34).  Glyph ink lives in the ALPHA channel.

Outputs (into --out):
  glyph_NN.png   per-glyph crop, alpha->black on white, ink-bbox + pad, --scale x
  sheet.png      labeled contact sheet (all glyphs in index order, "gNN" captions)
  glyph_map.csv  glyph -> (page,row,col) -> ink bbox + px count (audit trail)

Usage:
  python3 newkit_glyph_cells.py --out work/_newkit_ocr
  python3 newkit_glyph_cells.py --src <atlas_dir> --out <dir> --scale 6
"""
import argparse
import csv
import os
from PIL import Image, ImageDraw, ImageFont

COLS, ROWS, CW, CH = 9, 4, 56, 64
N_GLYPHS = 62          # 60 declared + spare authored pair (k=30 -> g60/g61)
SRC_DEFAULT = "/mnt/nvme-samsung/FFX Mods/ps3data_textures_png/menu/newkit_ftc/d3d11"


def glyph_cell(g):
    """Proven map: bank-5 glyph index -> (page, row, col) in the atlas."""
    page = g & 1
    k = g >> 1
    row = (ROWS - 1) - k // COLS
    col = k % COLS
    if row < 0:
        return None
    return page, row, col


def ink_on_white(cell):
    """RGBA cell -> L image, glyph ink black (0) on white (255), via alpha."""
    a = cell.split()[3]
    return Image.eval(a, lambda v: 255 - v)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--src", default=SRC_DEFAULT,
                    help="dir with font_0_0.png / font_0_1.png")
    ap.add_argument("--out", required=True, help="output dir (scratch, e.g. work/_newkit_ocr)")
    ap.add_argument("--scale", type=int, default=6, help="upscale factor (default 6)")
    ap.add_argument("--pad", type=int, default=4, help="px padding around ink bbox (native res)")
    ap.add_argument("--count", type=int, default=N_GLYPHS, help="glyphs to emit (default 62)")
    args = ap.parse_args()

    pages = [Image.open(os.path.join(args.src, "font_0_%d.png" % p)).convert("RGBA")
             for p in (0, 1)]
    os.makedirs(args.out, exist_ok=True)

    try:
        font = ImageFont.truetype("DejaVuSans-Bold.ttf", 18)
    except Exception:  # noqa: BLE001
        font = ImageFont.load_default()

    rows = []
    rendered = {}  # g -> upscaled L image
    for g in range(args.count):
        loc = glyph_cell(g)
        if loc is None:
            continue
        page, row, col = loc
        cell = pages[page].crop((col * CW, row * CH, col * CW + CW, row * CH + CH))
        a = cell.split()[3]
        bb = a.getbbox()
        ink = sum(1 for v in a.getdata() if v > 32)
        rows.append((g, page, row, col,
                     "" if bb is None else "%d,%d,%d,%d" % bb, ink))
        if bb is None:
            continue
        p = args.pad
        x0, y0 = max(0, bb[0] - p), max(0, bb[1] - p)
        x1, y1 = min(CW, bb[2] + p), min(CH, bb[3] + p)
        bw = ink_on_white(cell.crop((x0, y0, x1, y1)))
        bw = bw.resize((bw.width * args.scale, bw.height * args.scale),
                       Image.LANCZOS)
        bw.save(os.path.join(args.out, "glyph_%02d.png" % g))
        rendered[g] = bw

    # labeled contact sheet: COLS glyphs per row, caption "gNN" under each cell
    cell_w = CW * args.scale // 2   # sheet cells at half the OCR scale
    cell_h = CH * args.scale // 2
    cap = 26
    cols = COLS
    n = len(rendered)
    sheet_rows = (n + cols - 1) // cols
    sheet = Image.new("RGB", (cols * cell_w, sheet_rows * (cell_h + cap)), "white")
    dr = ImageDraw.Draw(sheet)
    for i, g in enumerate(sorted(rendered)):
        r, c = i // cols, i % cols
        thumb = rendered[g].resize(
            (min(cell_w, rendered[g].width * cell_h // max(1, rendered[g].height)),
             cell_h), Image.LANCZOS)
        x = c * cell_w + (cell_w - thumb.width) // 2
        sheet.paste(thumb, (x, r * (cell_h + cap)))
        dr.text((c * cell_w + 4, r * (cell_h + cap) + cell_h + 2),
                "g%d" % g, fill="red", font=font)
    sheet.save(os.path.join(args.out, "sheet.png"))

    with open(os.path.join(args.out, "glyph_map.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["glyph", "page", "row", "col", "ink_bbox_xyxy", "ink_px"])
        w.writerows(rows)

    print("wrote %d glyph PNGs + sheet.png + glyph_map.csv -> %s"
          % (len(rendered), args.out))
    empt = [r[0] for r in rows if r[5] == 0]
    if empt:
        print("empty cells (no ink):", empt)


if __name__ == "__main__":
    main()
