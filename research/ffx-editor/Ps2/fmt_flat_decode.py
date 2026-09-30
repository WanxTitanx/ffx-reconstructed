#!/usr/bin/env python3
"""fmt_flat_decode.py — decode FFX PS2 `menu/*.fmt` flat bitmap blobs to PNG.

WHY this exists (2026-09-18, lane Jarvis-FONT-SWIZZLE):
  Several PS2 menu `.fmt` files are *headerless raw pixel blobs* — no TIM2
  header, no palette, no swizzle.  Two layouts were proven by direct render +
  IoU comparison against the extracted HD `font_0_*.png` / `worldmap.dds`
  counterparts (see docs/reverse/FFX_FONT_SWIZZLE_2026-09-18.md):

    subfont.fmt / xfont1208.fmt   16,384 B = 4bpp 128x256, row-major,
                                  little-endian nibble order (byte n ->
                                  pixel 2n = LO nibble, 2n+1 = HI nibble,
                                  intensity = nibble * 17), UPRIGHT.
                                  Content ~= HD xfont1208 font_0_1 page
                                  (IoU ~0.74 after HD vertical flip).
                                  NOTE: an earlier guess that each byte held
                                  two glyph planes (lo/hi nibble = plane A/B)
                                  was TESTED AND REFUTED — swapped-nibble
                                  decode scores far worse vs HD and the two
                                  nibble planes are just even/odd columns of
                                  one bitmap.

    worldmap.fmt                 212,992 B = 8bpp 512x416, row-major,
                                  BOTTOM-UP (flip vertically for viewing).
                                  Linear — NO interior swizzle.  Earlier
                                  "even/odd row two-map" artifact came from
                                  wrongly assuming 256x832.

  The 128x256 font geometry matches the FFX font-chain upload: PSMT4 page
  at TBP 15744 (0x3D80) is documented as "128x256 auxiliary subfont page"
  in docs/reverse/FFX_FONT_CHAIN_2026-09-17.md.

Usage:
  fmt_flat_decode.py <in.fmt> <out.png> [options]

Options:
  --kind auto|font|map|raw   force layout (default: auto by file size)
  --flip                     vertical flip (worldmap needs it; font does NOT)
  --grid CXxCY               overlay a cell grid, e.g. --grid 16x10
  --scale N                  nearest-neighbour upscale (default 1)
  --raw WxH BPP              explicit geometry for --kind raw (bpp: 4 or 8)
  --stats                    print ink-bbox / per-band stats

Examples:
  fmt_flat_decode.py /mnt/nvme-xpg/ffx_ps2/ffx/master/uspc/menu/xfont1208.fmt xf.png --scale 3
  fmt_flat_decode.py /mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/menu/worldmap.fmt  wm.png --flip --scale 2
"""
import argparse
import os
import sys
from PIL import Image, ImageDraw

# ── Known layouts ────────────────────────────────────────────────────────
# size -> (kind, w, h, bpp, needs_flip)
LAYOUTS = {
    16384: ("font", 128, 256, 4, False),   # subfont.fmt, xfont1208.fmt
    212992: ("map", 512, 416, 8, True),    # worldmap.fmt (bottom-up)
}


def decode_4bpp(b, w, h):
    """Row-major 4bpp, little-endian nibble order -> L image."""
    img = Image.new("L", (w, h))
    px = img.load()
    for i in range(w * h):
        byte = b[i >> 1]
        px[i % w, i // w] = ((byte & 0xF) if (i & 1) == 0 else (byte >> 4)) * 17
    return img


def decode_8bpp(b, w, h):
    img = Image.new("L", (w, h))
    img.putdata(list(b[: w * h]))
    return img


def stats(img, name=""):
    data = list(img.getdata())
    ink = sum(1 for v in data if v > 40)
    bb = Image.eval(img, lambda v: 255 if v > 40 else 0).getbbox()
    print(f"{name}size={img.size} ink_px={ink} ({100.0*ink/len(data):.1f}%) "
          f"ink_bbox={bb}")
    # per-16-row band ink (find empty regions)
    w, h = img.size
    px = img.load()
    for y0 in range(0, h, 16):
        n = sum(1 for y in range(y0, min(y0 + 16, h))
                for x in range(w) if px[x, y] > 40)
        bar = "#" * (n * 40 // (w * 16))
        print(f"  y{y0:3d}-{min(y0+16,h):3d} {n:5d} {bar}")


def main():
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("src", help="input .fmt file")
    ap.add_argument("out", help="output PNG path")
    ap.add_argument("--kind", choices=["auto", "font", "map", "raw"],
                    default="auto")
    ap.add_argument("--raw", metavar="WxH,BPP",
                    help="explicit geometry for --kind raw, e.g. 256x128,4")
    ap.add_argument("--flip", action="store_true", help="vertical flip")
    ap.add_argument("--grid", metavar="CXxCY",
                    help="overlay cell grid, e.g. 16x10")
    ap.add_argument("--scale", type=int, default=1)
    ap.add_argument("--stats", action="store_true")
    args = ap.parse_args()

    b = open(args.src, "rb").read()
    kind = args.kind
    w = h = bpp = None
    flip = args.flip
    if kind == "auto":
        if len(b) in LAYOUTS:
            kind, w, h, bpp, need = LAYOUTS[len(b)]
            flip = flip or need
            print(f"auto: {os.path.basename(args.src)} -> {kind} "
                  f"{w}x{h}x{bpp} (flip={flip})")
        else:
            sys.exit(f"unknown size {len(b)} — pass --kind raw --raw WxH,BPP")
    elif kind == "font":
        w, h, bpp = 128, 256, 4
    elif kind == "map":
        w, h, bpp = 512, 416, 8
    else:
        if not args.raw:
            sys.exit("--kind raw needs --raw WxH,BPP")
        (w, h), bpp = args.raw.split(","), None
        w, h = (int(v) for v in args.raw.split(",")[0].split("x"))
        bpp = int(args.raw.split(",")[1])

    need = w * h * bpp // 8
    if len(b) < need:
        sys.exit(f"file too small: {len(b)} < {need} for {w}x{h}x{bpp}")

    img = decode_4bpp(b, w, h) if bpp == 4 else decode_8bpp(b, w, h)
    if flip:
        img = img.transpose(Image.FLIP_TOP_BOTTOM)
    if args.grid:
        cx, cy = (int(v) for v in args.grid.split("x"))
        g = img.convert("RGB")
        dr = ImageDraw.Draw(g)
        for x in range(0, w + 1, cx):
            dr.line([(x, 0), (x, h)], fill=(255, 0, 0))
        for y in range(0, h + 1, cy):
            dr.line([(0, y), (w, y)], fill=(255, 0, 0))
        img = g
    if args.scale != 1:
        img = img.resize((w * args.scale, h * args.scale), Image.NEAREST)
    os.makedirs(os.path.dirname(os.path.abspath(args.out)), exist_ok=True)
    img.save(args.out)
    print("wrote", args.out, img.size, img.mode)
    if args.stats:
        stats(img, name=os.path.basename(args.src) + " ")


if __name__ == "__main__":
    main()
