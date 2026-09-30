#!/usr/bin/env python3
"""Dump newkit_ftc HD atlas cells to PNGs + ASCII previews.

Atlas: 512x256 RGBA pages (font_0_0/font_0_1, shadow_0_*), cell pitch 56x64,
9 cols x 4 rows = 36 cells/page, 2 pages = 72 cells; newkit.ftc count=60.
"""
import os
import sys
from PIL import Image

SRC = "/mnt/nvme-samsung/FFX Mods/ps3data_textures_png/menu/newkit_ftc/d3d11"
OUT = os.path.dirname(os.path.abspath(__file__))
CW, CH, PITCH_X, PITCH_Y, COLS, ROWS = 56, 64, 56, 64, 9, 4


def main():
    pages = [Image.open(os.path.join(SRC, n)).convert("RGBA")
             for n in ("font_0_0.png", "font_0_1.png")]
    shad = [Image.open(os.path.join(SRC, n)).convert("RGBA")
            for n in ("shadow_0_0.png", "shadow_0_1.png")]
    cell_dir = os.path.join(OUT, "newkit_cells")
    os.makedirs(cell_dir, exist_ok=True)
    # contact sheet: 9 cols x 8 rows (2 pages stacked), scaled 2x
    sheet = Image.new("RGBA", (COLS * CW, 2 * ROWS * CH), (0, 0, 0, 255))
    filled = []
    for p, im in enumerate(pages):
        a = im.split()[3]
        for r in range(ROWS):
            for c in range(COLS):
                idx = p * COLS * ROWS + r * COLS + c
                box = (c * PITCH_X, r * PITCH_Y,
                       c * PITCH_X + CW, r * PITCH_Y + CH)
                cell = im.crop(box)
                cell.save(os.path.join(cell_dir, "g%02d.png" % idx))
                sheet.paste(cell, (c * CW, (p * ROWS + r) * CH))
                ca = a.crop(box)
                if ca.getbbox():
                    filled.append(idx)
    sheet.resize((COLS * CW * 2, 2 * ROWS * CH * 2),
                 Image.NEAREST).save(os.path.join(OUT, "newkit_atlas.png"))
    print("cells:", len(pages) * COLS * ROWS, "nonempty:", filled)
    # metrics from the .ftc
    import struct
    d = open("/mnt/nvme-xpg/ffx_ps2/ffx/master/new_jppc/menu/newkit.ftc",
             "rb").read()
    cnt = struct.unpack_from("<H", d, 0x10)[0]
    moff = struct.unpack_from("<I", d, 0x30)[0]
    print("ftc count:", cnt,
          "metrics:", list(d[moff:moff + cnt]))


if __name__ == "__main__":
    main()
