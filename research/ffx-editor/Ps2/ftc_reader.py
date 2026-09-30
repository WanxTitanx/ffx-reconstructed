#!/usr/bin/env python3
"""ftc_reader.py — Final Fantasy X .ftc (FTCX) font container reader.

Research deliverable for FTC-BODY (2026-09-17). Standard library only.

Format summary (all little-endian, 64-byte header):

    +0x00  char[4]  magic "FTCX"
    +0x04  u16      version tag — 0xC8 on every observed file (gate: >= 0xC8)
    +0x06  u16      build tag — 0x0614 on every observed file
    +0x08  u32      font slot/type — 0 menu/base, 1 event FTCX, 2 battle,
                    3 help, 4 uspc base, 5 newkit
    +0x0C  u32      reserved (0)
    +0x10  u16      glyph count (live glyphs, not capacity)
    +0x12  u16      reserved
    +0x14  u16      cell width   (14 on PS2 sheets)
    +0x16  u16      cell height  (18 on PS2 sheets)
    +0x18  u16/u32  reserved
    +0x20  u32      image offset  (0x40 when an embedded image exists)
    +0x24  u32      image size    (0 on HD metrics-only files)
    +0x28  u16      image width   (typically 128)
    +0x2A  u16      image height
    +0x2C  u32      reserved
    +0x30  u32      metric-table offset
    +0x34  u32      metric-region size (declared — usually the sheet
                    capacity cells*2, sometimes align16(count); NOT reliable)

Physical law verified on all 664 FTCX files: the metric region is the file
tail at +0x30 and is exactly align16(count) bytes (count padded to a
16-byte boundary); the first `count` bytes are live per-glyph metrics.

Body = ONE packed 4bpp image + ONE u8-per-glyph metric table. There are no
per-glyph body records and nothing variable-width: glyph g lives in physical
cell (g>>1) on nibble plane (g&1) — the low nibble (values 0..7) is the even
glyph's 3-bit intensity, the high nibble (values 8..15) is the odd glyph's
intensity minus 8. Two logical glyphs share each 14x18 cell, which is why a
999-glyph font fits a 504-cell sheet (capacity 1008 logical glyphs).

Metric entry m[g] = quarter-pixel advance of glyph g (advance_px = m/4),
empirically the same unit the pool-container `keyId` lane field approximates
(sum of per-glyph advances ~= string pixel width; verified r=0.997 on
jppc/battle/kernel/menu_txt.bin, best closed form sum(m+2)-2 exact on 61%
of lanes — the residual is finer per-glyph precision than the u8 table).

Non-FTCX bodies exist (e.g. jppc/event/obj/base.ftc starts with 0x73 and is
a DMA/GIF transfer block, not a font sheet) — this reader classifies them as
'legacy' and does not try to parse them as FTCX.

Usage:
    ftc_reader.py FILE [--json] [--dump-glyph N] [--sheet PREFIX]
    ftc_reader.py --batch DIR [DIR ...]
"""

import json
import os
import struct
import sys

MAGIC = b"FTCX"
HEADER_SIZE = 0x40
VERSION_GATE = 0xC8
DEFAULT_CELL = (14, 18)
NIBBLE_PLANES = 2  # low nibble = even glyph, high nibble = odd glyph


class FtcError(Exception):
    pass


def _u16(d, o):
    return struct.unpack_from("<H", d, o)[0]


def _u32(d, o):
    return struct.unpack_from("<I", d, o)[0]


def parse(path_or_bytes):
    """Parse one .ftc blob -> dict. Raises FtcError on structural problems."""
    if isinstance(path_or_bytes, (bytes, bytearray)):
        d = bytes(path_or_bytes)
        name = "<bytes>"
    else:
        name = path_or_bytes
        d = open(path_or_bytes, "rb").read()
    if len(d) < 4:
        raise FtcError("%s: file too small (%d bytes)" % (name, len(d)))
    if d[:4] != MAGIC:
        # known legacy body: DMA/GIF packet stream (jppc/event/obj/base.ftc)
        raise FtcError("%s: not FTCX (first byte 0x%02X) — legacy/container"
                       % (name, d[0]))
    if len(d) < HEADER_SIZE:
        raise FtcError("%s: truncated FTCX header (%d < 64)" % (name, len(d)))

    h = {
        "file": name,
        "size": len(d),
        "version": _u16(d, 0x04),
        "buildTag": _u16(d, 0x06),
        "slot": _u32(d, 0x08),
        "count": _u16(d, 0x10),
        "cellW": _u16(d, 0x14),
        "cellH": _u16(d, 0x16),
        "imgOff": _u32(d, 0x20),
        "imgSize": _u32(d, 0x24),
        "imgW": _u16(d, 0x28),
        "imgH": _u16(d, 0x2A),
        "metricOff": _u32(d, 0x30),
        "metricSize": _u32(d, 0x34),
    }
    warns = []
    if h["version"] != VERSION_GATE:
        warns.append("version 0x%X != 0x%X" % (h["version"], VERSION_GATE))
    if h["buildTag"] != 0x0614:
        warns.append("buildTag 0x%X != 0x0614" % h["buildTag"])
    if h["cellW"] == 0 or h["cellH"] == 0:
        warns.append("zero cell dims")
        h["cellW"], h["cellH"] = DEFAULT_CELL

    # --- image region bounds ------------------------------------------------
    img_end = h["imgOff"] + h["imgSize"]
    if h["imgSize"]:
        if img_end > len(d):
            raise FtcError("%s: image region 0x%X..0x%X past EOF 0x%X"
                           % (name, h["imgOff"], img_end, len(d)))
        need = (h["imgW"] // 2) * h["imgH"]
        # stored physical rows actually present (2 nibbles per byte per row)
        h["imgRows"] = h["imgSize"] * 2 // h["imgW"] if h["imgW"] else 0
        h["rowPacked"] = h["imgRows"] < h["imgH"]
        img = d[h["imgOff"]:img_end]
        if not any(img):
            h["rowPacked"] = False
            warns.append("zero-stub image (%dB, nominal %dx%d) — no bitmap"
                         % (h["imgSize"], h["imgW"], h["imgH"]))
        elif need > h["imgSize"]:
            warns.append("sub-size image: %dx%d declared, %d rows stored "
                         "(row-interleaved packing)" % (h["imgW"], h["imgH"],
                                                        h["imgRows"]))
        # logical glyph capacity = physical cells * 2 nibble planes
        cells = (h["imgW"] // h["cellW"]) * (h["imgH"] // h["cellH"])
        h["cells"] = cells
        h["capacity"] = cells * NIBBLE_PLANES
        if h["count"] > h["capacity"]:
            warns.append("count %d > capacity %d" % (h["count"], h["capacity"]))
    else:
        h["cells"] = 0
        h["capacity"] = 0  # metrics-only (HD) file — no embedded sheet
    # capacity implied by the nominal sheet dims — populated for ALL files
    # because +0x34 typically declares it even on metrics-only files
    h["nominalCapacity"] = ((h["imgW"] // h["cellW"])
                            * (h["imgH"] // h["cellH"]) * NIBBLE_PLANES)

    # --- metric region bounds ------------------------------------------------
    moff, msz = h["metricOff"], h["metricSize"]
    if moff == 0 or moff >= len(d):
        raise FtcError("%s: metric offset 0x%X outside file" % (name, moff))
    # live metrics are count bytes; physical region = align16(count), the
    # file tail (verified 664/664). Declared +0x34 is nominal (capacity or
    # aligned count) — compare but never trust it for bounds.
    avail = len(d) - moff
    h["metricAvail"] = avail
    h["metricTailAligned"] = ((h["count"] + 15) // 16) * 16
    # classify what +0x34 declared (informational — it is a nominal field)
    if msz == h["metricTailAligned"]:
        h["metricSizeKind"] = "align16(count)"
    elif msz == h["nominalCapacity"]:
        h["metricSizeKind"] = "capacity"
    elif msz == h["count"]:
        h["metricSizeKind"] = "count"
    else:
        h["metricSizeKind"] = "other"
    if avail != h["metricTailAligned"]:
        warns.append("metric tail %d != align16(count)=%d"
                     % (avail, h["metricTailAligned"]))
    if msz < h["count"]:
        warns.append("declared metricSize %d < live count %d"
                     % (msz, h["count"]))
    if h["count"] > avail:
        raise FtcError("%s: count %d metrics but only %d bytes from 0x%X"
                       % (name, h["count"], avail, moff))
    if h["imgSize"] and moff < img_end:
        raise FtcError("%s: metric table overlaps image" % name)
    if moff != img_end and h["imgSize"]:
        warns.append("metricOff 0x%X != image end 0x%X" % (moff, img_end))

    h["metrics"] = list(d[moff:moff + h["count"]])
    h["warnings"] = warns
    h["_data"] = d
    return h


def glyph_xy(f, g):
    """(cellX, cellY, plane) pixel origin of glyph g in the packed sheet."""
    if not f["cells"]:
        raise FtcError("no embedded image")
    if g < 0 or g >= f["capacity"]:
        raise FtcError("glyph %d outside capacity %d" % (g, f["capacity"]))
    cpr = f["imgW"] // f["cellW"]
    cell = g >> 1
    return (cell % cpr) * f["cellW"], (cell // cpr) * f["cellH"], g & 1


def _nibble(img, idx):
    """Safe byte fetch — returns 0 (blank) past the stored image tail.

    Covers zero-stub (64B) and row-interleaved sub-size images whose nominal
    dims describe more pixels than the payload actually stores."""
    return img[idx] if 0 <= idx < len(img) else 0


def glyph_bitmap(f, g):
    """Extract glyph g as rows of 0..7 intensities (TH x TW list of lists)."""
    d = f["_data"]
    x0, y0, plane = glyph_xy(f, g)
    tw, th, iw = f["cellW"], f["cellH"], f["imgW"]
    img = d[f["imgOff"]:f["imgOff"] + f["imgSize"]]
    stride = iw // 2
    out = []
    for y in range(th):
        row = []
        for x in range(tw):
            xx = x0 + x
            yy = y0 + y
            if f.get("rowPacked"):
                # sub-size image (jppc/help/help.ftc): stored row r holds the
                # nibbles of TWO virtual rows — hi nibble = even virtual row,
                # lo = odd. Each stored nibble covers a 1x2 virtual block.
                b = _nibble(img, (yy >> 1) * stride + (xx >> 1))
                nib = (b >> 4) if (yy & 1) == 0 else (b & 0xF)
            else:
                b = _nibble(img, yy * stride + (xx >> 1))
                nib = (b >> 4) if (xx & 1) == 0 else (b & 0xF)
            row.append((nib & 7) if (nib >> 3) == plane else 0)
        out.append(row)
    return out


def render_ascii(bm, chars=" .:-=+*#"):
    pal = chars
    n = len(pal) - 1
    return "\n".join("".join(pal[min(v * n // 7, n)] for v in row)
                     for row in bm)


def write_sheet_pngs(f, prefix):
    """Write <prefix>_lo.png and <prefix>_hi.png (nibble planes separated).

    Uses a tiny built-in PNG writer (no external deps)."""
    import zlib

    def png(path, pix, w, h):
        raw = b"".join(b"\x00" + bytes(row) for row in pix)
        def chunk(tag, data):
            c = struct.pack(">I", len(data)) + tag + data
            return c + struct.pack(">I", zlib.crc32(tag + data) & 0xFFFFFFFF)
        ihdr = struct.pack(">IIBBBBB", w, h, 8, 0, 0, 0, 0)
        open(path, "wb").write(b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", ihdr)
                               + chunk(b"IDAT", zlib.compress(raw))
                               + chunk(b"IEND", b""))

    d = f["_data"]
    iw, ih = f["imgW"], f["imgH"]
    img = d[f["imgOff"]:f["imgOff"] + f["imgSize"]]
    stride = iw // 2
    lo = [[0] * iw for _ in range(ih)]
    hi = [[0] * iw for _ in range(ih)]
    for y in range(ih):
        for x in range(iw):
            if f.get("rowPacked"):
                b = _nibble(img, (y >> 1) * stride + (x >> 1))
                nib = (b >> 4) if (y & 1) == 0 else (b & 0xF)
            else:
                b = _nibble(img, y * stride + (x >> 1))
                nib = (b >> 4) if (x & 1) == 0 else (b & 0xF)
            if nib < 8:
                lo[y][x] = nib * 36
            else:
                hi[y][x] = (nib - 8) * 36
    png(prefix + "_lo.png", lo, iw, ih)
    png(prefix + "_hi.png", hi, iw, ih)


def iter_ftc(root):
    for dirpath, _dirs, files in os.walk(root):
        for fn in files:
            if fn.lower().endswith(".ftc"):
                yield os.path.join(dirpath, fn)


def batch(roots):
    files = []
    for r in roots:
        if os.path.isfile(r):
            files.append(r)
        else:
            files.extend(iter_ftc(r))
    files.sort()
    ok, warned, failed = [], [], []
    for p in files:
        try:
            f = parse(p)
            (warned if f["warnings"] else ok).append(f)
        except FtcError as e:
            failed.append(str(e))
        except Exception as e:  # noqa: BLE001 - batch must not die on one file
            failed.append("%s: %s" % (p, e))
    print("== ftc batch ==")
    print("files: %d   parsed: %d (%d clean, %d with warnings)   failed: %d"
          % (len(files), len(ok) + len(warned), len(ok), len(warned),
             len(failed)))
    from collections import Counter
    slots = Counter(f["slot"] for f in ok + warned)
    print("slots:", dict(sorted(slots.items())))
    if failed:
        print("failures:")
        for s in failed:
            print("  ", s)
    if warned:
        print("warnings:")
        for f in warned:
            print("  %s: %s" % (f["file"], "; ".join(f["warnings"])))
    return ok, warned, failed


def main(argv):
    if len(argv) < 2:
        print(__doc__)
        return 2
    if argv[1] == "--batch":
        ok, warned, failed = batch(argv[2:])
        return 0 if not failed else 1
    path = argv[1]
    f = parse(path)
    info = {k: v for k, v in f.items() if k not in ("_data", "metrics")}
    info["metricMin"] = min(f["metrics"]) if f["metrics"] else 0
    info["metricMax"] = max(f["metrics"]) if f["metrics"] else 0
    if "--json" in argv:
        print(json.dumps(info, indent=2))
    else:
        for k, v in info.items():
            print("%-12s %s" % (k, v))
    if "--dump-glyph" in argv:
        g = int(argv[argv.index("--dump-glyph") + 1])
        print("glyph %d (cell %d plane %d) metric=%d"
              % (g, g >> 1, g & 1, f["metrics"][g]))
        print(render_ascii(glyph_bitmap(f, g)))
    if "--sheet" in argv:
        pref = argv[argv.index("--sheet") + 1]
        write_sheet_pngs(f, pref)
        print("wrote %s_lo.png / %s_hi.png" % (pref, pref))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
