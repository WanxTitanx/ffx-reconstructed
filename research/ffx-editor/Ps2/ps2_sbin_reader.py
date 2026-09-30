#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""ps2_sbin_reader.py — PS2 FFX `help/*.sbin` screen-image bundle reader.

PROVEN (corpus lane, 2026-09-17 — 20/20 unique files, byte-exact layout):

  .sbin = "screen binary" — indexed-color image bundles shipped in
  `master/<locale>/help/` and `help_inter/` (dev help-viewer data), each
  paired with a same-named `.sps2` scene file (unrelated format) and a
  16-byte `.rbin` stub.

  Layout (little-endian):
    +0x00  u32 version        (always 1)
    +0x04  u32 imageCount     (1..8; observed 1,2,4)
    +0x08  u32 reserved = 0
    +0x0C  u32 reserved = 0
    +0x10  imageCount x 16B image descriptors:
             +0  u16 width
             +2  u16 height
             +4  u8  bpp      (always 8)
             +5  u8  pad[3]   (always 0xFF 0xFF 0xFF)
             +8  u32 clutOff  (256-entry RGBA palette)
             +12 u32 pixelOff (w*h bytes, 8bpp indices)
    then per image: RGBA CLUT[256] at clutOff, indices[w*h] at pixelOff.

  Verified: dvdcopy (512x256 + 512x128 -> EOF 0x30830 exact),
  s_monitor (512x512 -> 0x40420), mon_boku (512x512 x2 + 256x256 x2
  -> 0xa1050 exact). CLUT entries are grayscale RGBA in observed files.

Usage:
  ps2_sbin_reader.py FILE.sbin [--dump-ppm OUTDIR] [--json]
"""
import struct
import sys
import json


def parse(path):
    d = open(path, "rb").read()
    if len(d) < 16:
        raise ValueError("too small")
    ver, nimg, z0, z1 = struct.unpack_from("<4I", d, 0)
    assert ver == 1 and z0 == 0 and z1 == 0, "bad header"
    assert 0 < nimg <= 8, "implausible imageCount %d" % nimg
    imgs = []
    for i in range(nimg):
        base = 0x10 + 16 * i
        w, h, bpp = struct.unpack_from("<HHB", d, base)
        pad = d[base + 5:base + 8]
        clut, px = struct.unpack_from("<II", d, base + 8)
        assert bpp == 8, "img%d bpp=%d" % (i, bpp)
        assert pad == b"\xff\xff\xff", "img%d pad=%s" % (i, pad.hex())
        assert clut + 1024 <= len(d), "img%d clut oob" % i
        assert px + w * h <= len(d), "img%d px oob" % i
        imgs.append({"index": i, "w": w, "h": h, "bpp": bpp,
                     "clutOff": clut, "pixelOff": px,
                     "clutEnd": clut + 1024, "pixelEnd": px + w * h})
    return {"path": path, "size": len(d), "version": ver,
            "imageCount": nimg, "images": imgs}


def dump_ppm(path, imgs, d, outdir):
    """Decode each image to binary PPM (P6). stdlib-only."""
    import os
    for img in imgs:
        clut = d[img["clutOff"]:img["clutOff"] + 1024]
        px = d[img["pixelOff"]:img["pixelOff"] + img["w"] * img["h"]]
        rgb = bytearray()
        for idx in px:
            o = idx * 4
            rgb += clut[o:o + 3]
        name = os.path.splitext(os.path.basename(path))[0]
        out = os.path.join(outdir, "%s_%d.ppm" % (name, img["index"]))
        with open(out, "wb") as f:
            f.write(b"P6\n%d %d\n255\n" % (img["w"], img["h"]))
            f.write(bytes(rgb))
        print("  wrote", out)


def main(argv):
    outdir = None
    if "--dump-ppm" in argv:
        i = argv.index("--dump-ppm")
        outdir = argv[i + 1]
        argv = argv[:i] + argv[i + 2:]
    as_json = "--json" in argv
    files = [a for a in argv if not a.startswith("-")]
    if not files:
        print(__doc__)
        return 1
    nok = 0
    for path in files:
        try:
            rep = parse(path)
            nok += 1
            if as_json:
                print(json.dumps(rep, indent=1))
            else:
                print("%s: %dB, %d image(s)" % (path, rep["size"], rep["imageCount"]))
                for im in rep["images"]:
                    print("   img%d: %dx%d@%dbpp clut=%#x px=%#x"
                          % (im["index"], im["w"], im["h"], im["bpp"],
                             im["clutOff"], im["pixelOff"]))
            if outdir:
                dump_ppm(path, rep["images"], open(path, "rb").read(), outdir)
        except Exception as e:
            print("%s: FAIL %s" % (path, e))
    print("%d/%d parsed" % (nok, len(files)))
    return 0 if nok == len(files) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
