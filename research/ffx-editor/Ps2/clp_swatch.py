#!/usr/bin/env python3
# ── clp_swatch.py — PS2 FFX `menu.clp` + `*.fmt` visual renderer ───────────────
#
# Companion to clp_reader.py (format verdict: docs/reverse/FFX_FMT_CLP_2026-09-17.md)
# and the palette-map doc (docs/reverse/FFX_FMT_CLP_PALETTE_MAP_2026-09-17.md).
#
# Model (PROVEN by direct render, 2026-09-17, lane Jarvis-RE):
#   menu.clp = 16 palettes x 256 RGBA colors  (4 banks x 4 palettes x 1 KiB)
#            = the CLUT bank the PS2 menu program uploads for its .fmt atlases
#            (sibling of .clt — the per-.txc 4 KiB palette files in
#            yonishi_data/dat/; same 256-entry RGBA CLUT role for .fmt).
#   *.fmt    = flat 8 bpp indexed texture atlases (pixel byte = CLUT index).
#            Verified geometry: meswin 256x256, battle 256x256, icon 128x128,
#            face_a/face_b 256x256, strtex 128x256, worldmap 256x832.
#            sface_ply/face_ply/face_smn + subfont/xfont1208 are stored
#            GS-swizzled / cell-packed — flat decode still noisy (residual).
#
# Alpha convention: PS2 GS alpha is 0x00..0x80 (0x80 = opaque). 0xFF is used on
# the opaque-black filler rows only. We map a -> min(255, a*2) for display.
#
# Requires: Pillow (PIL). Usage:
#   clp_swatch.py banks [loc]            -> clp_banks_<loc>.png   (4 cols x 128 rows)
#   clp_swatch.py cluts [loc]            -> clp_as_cluts_<loc>.png (16 x 256 grid)
#   clp_swatch.py fmt <name> [loc]       -> fmt_<name>_allpal.png  (16 palette sweep)
#   clp_swatch.py fmt <name> <pal> [loc] -> fmt_<name>_pal<pal>.png
#   clp_swatch.py scan [loc]             -> fmt atlas sweep for all decodable .fmt
# Default corpus: /mnt/nvme-xpg/ffx_ps2/ffx/master (override with FFX_CORPUS).
# Output dir: work/_clp_map (override with OUT env / --out).
# ──────────────────────────────────────────────────────────────────────────────
import os
import sys
from PIL import Image, ImageDraw

CORPUS = os.environ.get("FFX_CORPUS", "/mnt/nvme-xpg/ffx_ps2/ffx/master")
OUT = os.environ.get("OUT", "/home/wanderson/Documents/ffx-editor-main/work/_clp_map")

# .fmt file -> (width, name-hint). Verified-by-render geometry; height = size/w.
FMT_DIMS = {
    "meswin":   (256, "menu HUD chrome: HP/MP/AP/GIL/S.LV/Location/OD/TIME/HELP"),
    "battle":   (256, "battle UI: PAUSE/CTB/OD!!/TRIGGER/Scan/A-H letters"),
    "icon":     (128, "item/weapon icons, NEW badge, SELECT/START, OVER KILL, GUARD"),
    "face_a":   (256, "character portraits (status/equip)"),
    "face_b":   (256, "character portraits set B"),
    "strtex":   (128, "JP string-text glyph sheet"),
    "worldmap": (256, "world map screen (rows decode flat; interior swizzled?)"),
    # 512x256 clean luminance index maps (party/aeon faces); exact color
    # palette binding still open (RESIDUAL, doc sec.5/9)
    "face_ply":  (512, "party portraits 2x4 — luminance index map; color TBD"),
    "face_smn":  (512, "aeon portraits 2x5 — luminance index map; color TBD"),
    # stored swizzled/cell-packed — flat render is noisy; kept for completeness
    "sface_ply": (128, "small portraits — layout RESIDUAL"),
    "subfont":   (64, "sub font glyphs — cell-packed, RESIDUAL"),
    "xfont1208": (64, "aux font glyphs — cell-packed, RESIDUAL"),
}

# CORRELATED best-fit palette per texture (doc sec.5). These are visual /
# hue-histogram candidates only — the real binding is set by GS TEX2.CBP
# register writes in the native menu code, which is not in the corpus.
BEST_PAL = {
    "meswin": 11, "battle": 11, "icon": 15, "face_a": 3, "face_b": 3,
    "strtex": 3, "worldmap": 10, "face_ply": 3, "face_smn": 3,
}


def load_clp(loc):
    p = os.path.join(CORPUS, loc, "menu", "menu.clp")
    return open(p, "rb").read()


def rgba(clp, pal, i):
    """Palette `pal` (0-15), index i -> display RGB with GS alpha expanded."""
    o = pal * 1024 + 4 * i
    r, g, b, a = clp[o:o + 4]
    sa = min(255, a * 2)
    return (r * sa // 255, g * sa // 255, b * sa // 255)


def render_banks(loc):
    """4 bank columns; each = 8 colors x 128 rows (16 records x 8)."""
    clp = load_clp(loc)
    SW = 16
    img = Image.new("RGB", (4 * (8 * SW + 6), 128 * SW + 16), (40, 40, 40))
    px = img.load()
    dr = ImageDraw.Draw(img)
    for bank in range(4):
        x0 = bank * (8 * SW + 6)
        dr.text((x0 + 2, 2), "bank%d" % bank, fill=(255, 255, 0))
        for row in range(128):
            for c in range(8):
                i = bank * 1024 + row * 8 + c
                o = 4 * i
                r, g, b, a = clp[o:o + 4]
                sa = min(255, a * 2)
                col = (r * sa // 255, g * sa // 255, b * sa // 255)
                for dy in range(SW - 1):
                    for dx in range(SW - 1):
                        px[x0 + c * SW + dx, 14 + row * SW + dy] = col
    p = os.path.join(OUT, "clp_banks_%s.png" % loc)
    img.save(p)
    print(p, img.size)


def render_cluts(loc):
    """16 x 256-color palettes, each drawn as a 32x8 swatch grid, 4x4 layout."""
    clp = load_clp(loc)
    SW = 10
    img = Image.new("RGB", (4 * (32 * SW + 8), 4 * (8 * SW + 16)), (30, 30, 30))
    px = img.load()
    dr = ImageDraw.Draw(img)
    for pal in range(16):
        x0 = (pal % 4) * (32 * SW + 8)
        y0 = (pal // 4) * (8 * SW + 16)
        dr.text((x0 + 2, y0 + 2), "pal%02d" % pal, fill=(255, 255, 0))
        for i in range(256):
            cx, cy = i % 32, i // 32
            for dy in range(SW):
                for dx in range(SW):
                    px[x0 + cx * SW + dx, y0 + 14 + cy * SW + dy] = rgba(clp, pal, i)
    p = os.path.join(OUT, "clp_as_cluts_%s.png" % loc)
    img.save(p)
    print(p, img.size)


def render_fmt(name, loc, pal=None):
    """Render a .fmt atlas through one palette, or all 16 (pal=None)."""
    w = FMT_DIMS[name][0]
    fp = os.path.join(CORPUS, loc, "menu", "%s.fmt" % name)
    b = open(fp, "rb").read()
    h = len(b) // w
    clp = load_clp(loc)
    pals = range(16) if pal is None else [pal]
    cols = 4 if pal is None else 1
    rows = (len(pals) + cols - 1) // cols
    img = Image.new("RGB", (cols * w, rows * (h + 16)), (15, 15, 15))
    px = img.load()
    dr = ImageDraw.Draw(img)
    for k, p in enumerate(pals):
        x0 = (k % cols) * w
        y0 = (k // cols) * (h + 16)
        dr.text((x0 + 4, y0 + 2), "pal %02d" % p, fill=(255, 255, 0))
        for y in range(h):
            base = y * w
            for x in range(w):
                px[x0 + x, y0 + 16 + y] = rgba(clp, p, b[base + x])
    tag = "allpal" if pal is None else "pal%02d" % pal
    outp = os.path.join(OUT, "fmt_%s_%s_%s.png" % (name, tag, loc))
    img.save(outp)
    print(outp, img.size)


def main(argv):
    os.makedirs(OUT, exist_ok=True)
    cmd = argv[1] if len(argv) > 1 else "banks"
    loc = "jppc"
    if cmd == "banks":
        loc = argv[2] if len(argv) > 2 else "jppc"
        render_banks(loc)
    elif cmd == "cluts":
        loc = argv[2] if len(argv) > 2 else "jppc"
        render_cluts(loc)
    elif cmd == "fmt":
        name = argv[2]
        if name not in FMT_DIMS:
            print("unknown .fmt; choose from", ", ".join(FMT_DIMS))
            return 1
        pal = int(argv[3]) if len(argv) > 3 and argv[3].isdigit() else None
        if len(argv) > 4:
            loc = argv[4]
        render_fmt(name, loc, pal)
    elif cmd == "scan":
        loc = argv[2] if len(argv) > 2 else "jppc"
        for n in FMT_DIMS:
            fp = os.path.join(CORPUS, loc, "menu", "%s.fmt" % n)
            if os.path.exists(fp):
                render_fmt(n, loc, BEST_PAL.get(n))
    else:
        print(__doc__)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
