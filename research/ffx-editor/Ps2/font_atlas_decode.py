#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""font_atlas_decode.py — FFX PS2 subfont/xfont1208 128x256 4bpp dual-plane atlas decoder.

RE findings implemented here (Jarvis-FONT-ATLAS, 2026-09-18):

  * `subfont.fmt` / `xfont1208.fmt` are FLAT 4bpp 128x256 pages (16384 bytes,
    row-major, LE nibbles: pixel 2n = low nibble, pixel 2n+1 = high nibble).
  * The page is a 12-col x 21-row grid of 10x12 px cells (row 21 truncated to 4 px).
  * DUAL-PLANE PACKING — the key discovery: every cell holds TWO glyphs.
      - nibble values 1..7  -> "lo" plane = EVEN logical glyph ids
      - nibble values 8..15 -> "hi" plane = ODD  logical glyph ids
    So glyph g -> cell (g >> 1), intensity plane = g & 1.
    Cell c -> glyph ids 2c (lo) and 2c+1 (hi).
    Equivalent to the FTCX glyph-record formula observed in the runtime
    (`x0 = 14*((g%18)/2)`, `y0 = 18*(g/18)` for 14x18 FTCX fonts), here with
    10x12 cells and 24 glyph slots per row: x0 = 10*((g%24)/2), y0 = 12*(g/24).
  * The HD remaster split the two planes into two RGBA pages:
      lo plane == `menu/xfont1208/d3d11/font_0_0.png` (stored bottom-up!)
      hi plane == `menu/xfont1208/d3d11/font_0_1.png`
    (PROVEN by per-cell IoU: hi-vs-f01 mean 0.889 / 252 cells > 0.5;
     lo-vs-f00 mean 0.635 — lower because lo strokes use values 1..7.)
  * Atlas block map (xfont1208.fmt / uspc subfont.fmt):
      cells   0-129 : JP block — glyph ids 0..259 = jppc/menu/ffxsjistbl.bin[0..259]
                      (digits, fullwidth punct, hiragana, katakana, fullwidth
                      A-Z + a-z). Cells 21-22 blank = sjistbl 42-45 (circled
                      number slots, undrawn). Cells 130-143 blank = sjistbl
                      260+ (kanji region, not included).
      cells 144-191 : ASCII block A — ~95-slot printable-ASCII sequence
                      (SJIS quirk: backslash slot drawn as YEN sign; extra star).
      cells 192-215 : ASCII block B — ~48-slot subset (same ordering, shorter).
      cells 216-239 : blank.
      cells 240-251 : ASCII block C — 24-slot subset (truncated by page end).
  * `jppc/menu/base.ftc` (FTCX, 999 glyphs, 14x18 cells, 128x1008) uses the
    SAME dual-plane trick: cell k = sjistbl[2k] lo + sjistbl[2k+1] hi.
  * JP vs US `subfont.fmt`: identical layout; JP redraws ~32 cells with a
    heavier stroke weight (katakana tweaks + both lowercase-Latin blocks).
    US subfont.fmt is byte-identical to xfont1208.fmt.

Maintenance caveats:
  * The "glyph id" here is the raw atlas slot index (0..503). The character at
    a slot is contextual: JP block = ffxsjistbl order; ASCII blocks = their own
    sequence; consumer font slots may anchor at a block start.
  * newkit.ftc (slot 5 / <F5:nn>) is a DIFFERENT font (62 legal kanji, own
    charset, own HD bitmaps) — it does NOT index this atlas.
  * NumPy-free by design (repo env lacks numpy): pure PIL.

Usage:
  python3 font_atlas_decode.py <fmt> --planes outdir        # dump lo/hi/full PNGs
  python3 font_atlas_decode.py <fmt> --cells out.csv        # per-cell census CSV
  python3 font_atlas_decode.py --diff <us.fmt> <jp.fmt> out.csv   # JP/US cell diff
  python3 font_atlas_decode.py --match <fmt> <font_0_0.png> <font_0_1.png> out.csv
"""
import argparse
import csv
import os
import sys

W, H = 128, 256
COLS, ROWS = 12, 21
CW, CH = 10, 12


def load_fmt(path):
    b = open(path, 'rb').read()
    if len(b) != 16384:
        raise SystemExit('expected 16384-byte flat 4bpp .fmt, got %d' % len(b))
    return b


def nibble(b, x, y):
    i = y * W + x
    byte = b[i >> 1]
    return (byte & 0xF) if (x & 1) == 0 else (byte >> 4)


def cell_plane_img(b, cell, plane, scale=1):
    """Render one cell's plane as an L image. lo uses values 1..7, hi 8..15."""
    from PIL import Image
    r, c = divmod(cell, COLS)
    im = Image.new('L', (CW, CH))
    for y in range(CH):
        for x in range(CW):
            v = nibble(b, c * CW + x, r * CH + y)
            if plane == 'lo':
                v = v if 1 <= v <= 7 else 0
            elif plane == 'hi':
                v = (v - 7) if v >= 8 else 0
            im.putpixel((x, y), min(v * scale, 255))
    return im


def page_img(b, plane=None):
    """Whole-page render. plane=None -> raw union (nibble*17)."""
    from PIL import Image
    im = Image.new('L', (W, H))
    for y in range(H):
        for x in range(W):
            v = nibble(b, x, y)
            if plane == 'lo':
                v = v if 1 <= v <= 7 else 0
                v *= 36
            elif plane == 'hi':
                v = (v - 7) if v >= 8 else 0
                v *= 32
            else:
                v *= 17
            im.putpixel((x, y), min(v, 255))
    return im


def cell_ink(b, cell, plane):
    r, c = divmod(cell, COLS)
    n = 0
    for y in range(CH):
        for x in range(CW):
            v = nibble(b, c * CW + x, r * CH + y)
            if plane == 'lo' and 1 <= v <= 7:
                n += 1
            elif plane == 'hi' and v >= 8:
                n += 1
    return n


def sjistbl_char(tbl_bytes, idx):
    raw = tbl_bytes[2 * idx:2 * idx + 2]
    try:
        return raw.decode('shift_jis')
    except Exception:
        return '??' + raw.hex()


def block_of(cell):
    if 0 <= cell <= 129:
        return 'JP'
    if 130 <= cell <= 143:
        return 'JP_blank_tail'
    if 144 <= cell <= 191:
        return 'ASCII_A'
    if 192 <= cell <= 215:
        return 'ASCII_B'
    if 216 <= cell <= 239:
        return 'blank_gap'
    if 240 <= cell <= 251:
        return 'ASCII_C'
    return '?'


def cmd_cells(fmt_path, out_csv, sjis_path):
    b = load_fmt(fmt_path)
    tbl = open(sjis_path, 'rb').read() if sjis_path else None
    rows = []
    for cell in range(COLS * ROWS):
        r, c = divmod(cell, COLS)
        gid_lo, gid_hi = 2 * cell, 2 * cell + 1
        ch_lo = sjistbl_char(tbl, gid_lo) if (tbl and block_of(cell) == 'JP' and gid_lo < len(tbl) // 2) else ''
        ch_hi = sjistbl_char(tbl, gid_hi) if (tbl and block_of(cell) == 'JP' and gid_hi < len(tbl) // 2) else ''
        rows.append({
            'cell': cell, 'row': r, 'col': c, 'block': block_of(cell),
            'glyph_lo': gid_lo, 'glyph_hi': gid_hi,
            'char_lo': ch_lo, 'char_hi': ch_hi,
            'ink_lo': cell_ink(b, cell, 'lo'), 'ink_hi': cell_ink(b, cell, 'hi'),
        })
    with open(out_csv, 'w', newline='', encoding='utf-8') as f:
        wcsv = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
        wcsv.writeheader()
        wcsv.writerows(rows)
    print('wrote', out_csv, len(rows), 'cells')


def cmd_planes(fmt_path, outdir):
    from PIL import Image
    b = load_fmt(fmt_path)
    os.makedirs(outdir, exist_ok=True)
    for plane in ['lo', 'hi', None]:
        im = page_img(b, plane)
        tag = plane or 'union'
        im.resize((W * 3, H * 3), Image.NEAREST).save(
            os.path.join(outdir, '%s_%s.png' % (os.path.basename(fmt_path).replace('.fmt', ''), tag)))
    print('wrote planes to', outdir)


def cmd_diff(us_path, jp_path, out_csv):
    us, jp = load_fmt(us_path), load_fmt(jp_path)
    rows = []
    for cell in range(COLS * ROWS):
        r, c = divmod(cell, COLS)
        lod = hid = 0
        uink = jink = 0
        for y in range(CH):
            for x in range(CW):
                a = nibble(us, c * CW + x, r * CH + y)
                d = nibble(jp, c * CW + x, r * CH + y)
                if a != d:
                    al, ah, bl, bh = 1 <= a <= 7, a >= 8, 1 <= d <= 7, d >= 8
                    if al != bl or (al and bl and a != d):
                        lod += 1
                    if ah != bh or (ah and bh and a != d):
                        hid += 1
                uink += a > 0
                jink += d > 0
        if lod or hid:
            rows.append({'cell': cell, 'row': r, 'col': c,
                         'glyph_lo': 2 * cell, 'glyph_hi': 2 * cell + 1,
                         'lo_plane_diff_px': lod, 'hi_plane_diff_px': hid,
                         'us_ink_px': uink, 'jp_ink_px': jink})
    with open(out_csv, 'w', newline='', encoding='utf-8') as f:
        wcsv = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
        wcsv.writeheader()
        wcsv.writerows(rows)
    print('wrote', out_csv, len(rows), 'differing cells')


def cmd_match(fmt_path, f00_path, f01_path, out_csv):
    from PIL import Image
    b = load_fmt(fmt_path)
    pages = {}
    for tag, p in [('f00', f00_path), ('f01', f01_path)]:
        im = Image.open(p).convert('RGBA').transpose(Image.FLIP_TOP_BOTTOM)
        pages[tag] = im

    def ciou(cell, plane, hd):
        r, c = divmod(cell, COLS)
        inter = uni = 0
        for y in range(CH):
            for x in range(CW):
                v = nibble(b, c * CW + x, r * CH + y)
                a = (1 <= v <= 7) if plane == 'lo' else (v >= 8)
                bb = hd.getpixel((c * CW + x, r * CH + y))[3] > 40
                inter += a and bb
                uni += a or bb
        return inter / uni if uni else (1.0 if inter == 0 else 0.0)

    rows = []
    for cell in range(COLS * ROWS):
        rows.append({'cell': cell, 'row': cell // COLS, 'col': cell % COLS,
                     'iou_lo_vs_f00': round(ciou(cell, 'lo', pages['f00']), 4),
                     'iou_hi_vs_f01': round(ciou(cell, 'hi', pages['f01']), 4)})
    with open(out_csv, 'w', newline='', encoding='utf-8') as f:
        wcsv = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
        wcsv.writeheader()
        wcsv.writerows(rows)
    ml = sum(rw['iou_lo_vs_f00'] for rw in rows) / 252
    mh = sum(rw['iou_hi_vs_f01'] for rw in rows) / 252
    print('wrote', out_csv, 'mean lo-vs-f00=%.3f hi-vs-f01=%.3f' % (ml, mh))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('fmt', nargs='?')
    ap.add_argument('--planes', metavar='OUTDIR')
    ap.add_argument('--cells', metavar='OUT.csv')
    ap.add_argument('--sjistbl', metavar='ffxsjistbl.bin')
    ap.add_argument('--diff', nargs=2, metavar=('US.fmt', 'JP.fmt'))
    ap.add_argument('--match', nargs=3, metavar=('FMT', 'FONT_0_0.PNG', 'FONT_0_1.PNG'))
    ap.add_argument('-o', '--out', metavar='OUT.csv', default=None)
    a = ap.parse_args()
    if a.diff:
        cmd_diff(a.diff[0], a.diff[1], a.out or 'diff.csv')
    elif a.match:
        cmd_match(a.match[0], a.match[1], a.match[2], a.out or 'match.csv')
    elif a.cells:
        cmd_cells(a.fmt, a.cells, a.sjistbl)
    elif a.planes:
        cmd_planes(a.fmt, a.planes)
    else:
        ap.print_help()


if __name__ == '__main__':
    main()
