#!/usr/bin/env python3
# M-F02 adjudication: .tm2 "maioria 8bpp" — scan all 84 .tm2 headers using the
# SAME field offsets as the product reader (Ps2Tim2Reader.cs: PaletteBytes@0x14,
# ImageBytes@0x18, ColorCount@0x1E, Bppish@0x23, W/H@0x24/0x26).
import struct, sys, collections
from pathlib import Path

root = Path("/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx")
files = sorted(root.rglob("*.tm2"))
rows = []
cnt = collections.Counter()
for f in files:
    d = f.read_bytes()[:0x40]
    if len(d) < 0x28 or d[:4] != b"TIM2":
        cnt["BAD_MAGIC"] += 1
        rows.append((str(f.relative_to(root)), "BAD_MAGIC"))
        continue
    pal, img = struct.unpack_from("<I", d, 0x14)[0], struct.unpack_from("<I", d, 0x18)[0]
    colors = struct.unpack_from("<H", d, 0x1E)[0]
    bpp = d[0x23]
    w, h = struct.unpack_from("<HH", d, 0x24)
    # classify like product: 5 w/256col=8bpp; 4 w/16col=4bpp; 1 no-clut=direct16
    if bpp == 5 and pal == 1024 and colors == 256:
        k = "8bpp_indexed(0x23=5,1024B/256c)"
    elif bpp == 4 and pal == 64 and colors == 16:
        k = "4bpp_indexed(0x23=4,64B/16c)"
    elif bpp == 1 and pal == 0:
        k = "direct_16bpp(0x23=1,no clut)"
    else:
        k = f"other(bpp_byte={bpp},pal={pal},colors={colors})"
    cnt[k] += 1
    rows.append((str(f.relative_to(root)), k, w, h, pal, img, colors, bpp))

for name, *rest in rows:
    print(name, "|", " | ".join(str(x) for x in rest))
print("\n=== DISTRIBUTION (total %d) ===" % len(files))
for k, v in cnt.most_common():
    print(f"{v:3d}  {k}")
