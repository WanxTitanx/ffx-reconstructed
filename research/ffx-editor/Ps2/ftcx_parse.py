#!/usr/bin/env python3
"""ftcx_parse.py — completed FFX .ftc subsection parser (all kinds, byte-exact).

FTCX-PARSER lane (2026-09-18), research deliverable. Stdlib only.
Completes the coverage left open by FTC-BODY (`ftc_reader.py`, 664/665):
this parser covers EVERY container kind found in the corpus and verifies
that 100% of each file's bytes belong to a decoded subsection.

Corpus (7,049 .ftc files on disk, three trees):
    ffx_ps2/ffx/master                                  665 files (PS2 rip)
    FFX/data/FFX_Data/ffx_ps2/ffx/master              1,535 files (HD data)
    FFX2_Data/ffx_ps2/ffx2/master                     4,849 files (FFX-2)

Container classes (dispatch on first 4 bytes):
    "FTCX"  7,047 files — header + descriptor subsections
    0x73        2 files — legacy PS2 DMA/GIF event-font container
            (jppc/event/obj/base.ftc, byte-identical in both FFX-1 trees;
            FFX-2 does not ship it)

FTCX subsection grammar (every file is a CONTIGUOUS tiling — zero gaps
verified on all 7,047):

    [0x00,0x40)  header: magic/ver/buildTag/slot + 3 descriptor subsections
                   TILE_INFO  @+0x10 {tile_count u32, tile_w u16, tile_h u16,
                                      pad u32, pad u32}
                   IMAGE_INFO @+0x20 {data_ptr u32, data_size u32,
                                      data_w u16, data_h u16, pad u32}
                   WIDTH_INFO @+0x30 {data_ptr u32, data_size u32,
                                      pad u32, pad u32}
    [0x40, imgEnd)   IMAGE subsection — 4 kinds observed:
                       absent          6,968  imgSize==0 (HD: bitmaps in DDS
                                              font_0_{0,1}.phyre atlases)
                       stub               72  imgSize==64, all-zero
                       full4bpp            5  imgSize==imgW*imgH/2
                       rowInterleaved      2  imgSize==imgW*imgH/4 — each
                                              stored byte = 2x2 virtual px
                                              block (hi nib = top row pair,
                                              lo = bottom), then the bit-3
                                              plane split applies
    [moff, EOF)      WIDTH/metric subsection — exactly align16(count) bytes:
                       [0, count)                    live u8 advances
                       [count, min(cap,aligned))     capacity-slot values
                                                     (authored advance or
                                                     0x07 default)
                       [max(cap,count), aligned)     alignment pad:
                                                     0x00 on 7,043 files,
                                                     0x07 on 4 files
                                                     (credits.ftc x3 locales
                                                     + new_cnpc/menu/base.ftc)

Legacy 0x73 grammar (contiguous tiling, verified):
    [0x000,0x040)  64B header (+0x0A tblSize, +0x12 imgSize, +0x14/+0x16
                   texture WxH, +0x18 1-byte glyph count, +0x1A 2-byte cells)
    [0x040,0x4E0)  u8 advance table (tblSize bytes, 1 per glyph slot)
    [0x4E0,0x550)  DMA tag + GIF tags + A+D register setup
    [0x550,EOF)    IMAGE qword payload (PSMT4HH sheet)

Usage:
    ftcx_parse.py FILE [--json] [--dump-glyph N]
    ftcx_parse.py --batch DIR [DIR ...] [--csv OUT] [--verify]
"""

import json
import os
import struct
import sys

MAGIC = b"FTCX"
HEADER_SIZE = 0x40
VERSION_GATE = 0xC8
BUILD_TAG = 0x0614
NIBBLE_PLANES = 2
STUB_SIZE = 64
DEFAULT_PAD = 0x07   # "empty slot" default advance / alternate pad byte
ZERO_PAD = 0x00


class FtcxError(Exception):
    pass


def _u16(d, o):
    return struct.unpack_from("<H", d, o)[0]


def _u32(d, o):
    return struct.unpack_from("<I", d, o)[0]


def _u64(d, o):
    return struct.unpack_from("<Q", d, o)[0]


def align16(n):
    return (n + 15) // 16 * 16


def classify(d):
    if len(d) >= 4 and d[:4] == MAGIC:
        return "ftcx"
    if len(d) >= 4 and _u32(d, 0) == 0x73:
        return "legacy73"
    return "unknown"


# ===========================================================================
# FTCX container
# ===========================================================================

def parse_ftcx(d, name="<bytes>"):
    """Full subsection parse of an FTCX blob. Raises FtcxError on
    structural violations; informational anomalies land in warnings."""
    if len(d) < HEADER_SIZE:
        raise FtcxError("%s: truncated FTCX header (%d < 64)" % (name, len(d)))
    h = {
        "file": name, "size": len(d), "class": "ftcx",
        "version": _u16(d, 0x04), "buildTag": _u16(d, 0x06),
        "slot": _u32(d, 0x08),
        # TILE_INFO descriptor (+0x10..0x20)
        "count": _u16(d, 0x10),
        "cellW": _u16(d, 0x14), "cellH": _u16(d, 0x16),
        # IMAGE_INFO descriptor (+0x20..0x30)
        "imgOff": _u32(d, 0x20), "imgSize": _u32(d, 0x24),
        "imgW": _u16(d, 0x28), "imgH": _u16(d, 0x2A),
        # WIDTH_INFO descriptor (+0x30..0x40)
        "metricOff": _u32(d, 0x30), "metricSize": _u32(d, 0x34),
    }
    warns = []
    if h["version"] != VERSION_GATE:
        warns.append("version 0x%X != 0x%X" % (h["version"], VERSION_GATE))
    if h["buildTag"] != BUILD_TAG:
        warns.append("buildTag 0x%X != 0x%X" % (h["buildTag"], BUILD_TAG))
    # reserved header fields — zero on all 7,047 corpus files
    res = {"+0x0A": _u16(d, 0x0A), "+0x0C": _u32(d, 0x0C),
           "+0x0E": _u16(d, 0x0E), "+0x12": _u16(d, 0x12),
           "+0x18": _u32(d, 0x18), "+0x1C": _u32(d, 0x1C),
           "+0x2C": _u32(d, 0x2C), "+0x38": _u64(d, 0x38)}
    h["reserved"] = res
    for k, v in res.items():
        if v:
            warns.append("reserved field %s = 0x%X" % (k, v))
    if not h["cellW"] or not h["cellH"]:
        raise FtcxError("%s: zero cell dims" % name)

    # nominal capacity from the declared sheet geometry — populated even on
    # metrics-only files (dims stay filled when imgSize==0)
    h["capacity"] = ((h["imgW"] // h["cellW"])
                     * (h["imgH"] // h["cellH"]) * NIBBLE_PLANES)
    cap = h["capacity"]
    count = h["count"]
    if count > cap:
        warns.append("count %d > nominal capacity %d" % (count, cap))

    # ---- IMAGE subsection -------------------------------------------------
    img_end = h["imgOff"] + h["imgSize"]
    if h["imgSize"] == 0:
        h["imgKind"] = "absent"
        if h["imgOff"] != HEADER_SIZE:
            warns.append("no image but imgOff 0x%X != 0x40" % h["imgOff"])
    else:
        if h["imgOff"] != HEADER_SIZE:
            warns.append("imgOff 0x%X != 0x40" % h["imgOff"])
        if img_end > len(d):
            raise FtcxError("%s: image 0x%X..0x%X past EOF 0x%X"
                            % (name, h["imgOff"], img_end, len(d)))
        img = d[h["imgOff"]:img_end]
        full = h["imgW"] * h["imgH"] // 2
        if not any(img):
            h["imgKind"] = "stub"
        elif h["imgSize"] == full:
            h["imgKind"] = "full4bpp"
        elif h["imgSize"] * 4 == h["imgW"] * h["imgH"]:
            h["imgKind"] = "rowInterleaved"
        else:
            h["imgKind"] = "subsize-unknown"
            warns.append("unusual image size %d for %dx%d"
                         % (h["imgSize"], h["imgW"], h["imgH"]))
    h["rowPacked"] = h["imgKind"] == "rowInterleaved"
    if h["imgKind"] == "stub" and h["imgSize"] != STUB_SIZE:
        warns.append("stub image %dB != %dB" % (h["imgSize"], STUB_SIZE))

    # ---- WIDTH/metric subsection ------------------------------------------
    moff, msz = h["metricOff"], h["metricSize"]
    if moff == 0 or moff > len(d):
        raise FtcxError("%s: metric offset 0x%X outside file" % (name, moff))
    aligned = align16(count)
    h["metricTailAligned"] = aligned
    avail = len(d) - moff
    h["metricAvail"] = avail
    if avail != aligned:
        raise FtcxError("%s: metric tail %d != align16(count)=%d"
                        % (name, avail, aligned))
    if moff != img_end and h["imgSize"]:
        raise FtcxError("%s: metric table overlaps/leaves gap vs image"
                        % name)
    if not h["imgSize"] and moff != HEADER_SIZE:
        raise FtcxError("%s: no image but metricOff 0x%X != 0x40"
                        % (name, moff))
    if msz == aligned:
        h["metricSizeKind"] = "align16"
    elif msz == cap:
        h["metricSizeKind"] = "capacity"
    elif msz == count:
        h["metricSizeKind"] = "count"
    else:
        h["metricSizeKind"] = "other"
        warns.append("declared metricSize %d is neither capacity %d, "
                     "count %d nor align16 %d" % (msz, cap, count, aligned))
    if msz < count:
        warns.append("declared metricSize %d < live count %d" % (msz, count))

    tail = d[moff:moff + aligned]
    h["metrics"] = list(tail[:count])
    # pad law: [count, min(cap,aligned)) = capacity-slot fill (authored or
    # 0x07); [max(cap,count), aligned) = alignment pad (0x00 or 0x07)
    fill_end = min(max(cap, count), aligned)
    h["capFill"] = list(tail[count:fill_end])
    pad = tail[fill_end:aligned]
    h["padLen"] = len(pad)
    if not pad:
        h["padFlavor"] = "none"
    elif all(b == ZERO_PAD for b in pad):
        h["padFlavor"] = "zero"
    elif all(b == DEFAULT_PAD for b in pad):
        h["padFlavor"] = "seven"
    else:
        h["padFlavor"] = "mixed"
        warns.append("alignment pad has non-{0x00,0x07} bytes: %s"
                     % pad.hex())

    # ---- byte-exact region accounting --------------------------------------
    h["regions"] = _regions_ftcx(h)
    h["byteExact"], h["coverage"] = _coverage(h["regions"], len(d))
    if not h["byteExact"]:
        warns.append("regions do not tile the file contiguously")
    h["warnings"] = warns
    h["_data"] = d
    return h


def _regions_ftcx(h):
    r = [("header", 0, HEADER_SIZE)]
    if h["imgSize"]:
        r.append(("image:%s" % h["imgKind"], h["imgOff"], h["imgSize"]))
    a = h["metricTailAligned"]
    r.append(("metrics:live", h["metricOff"], min(h["count"], a)))
    if h["count"] < a:
        fill_end = min(max(h["capacity"], h["count"]), a)
        if fill_end > h["count"]:
            r.append(("metrics:capFill", h["metricOff"] + h["count"],
                      fill_end - h["count"]))
        if a > fill_end:
            r.append(("metrics:pad:%s" % h["padFlavor"],
                      h["metricOff"] + fill_end, a - fill_end))
    return r


def _coverage(regions, size):
    """True iff regions tile [0,size) contiguously. Returns (ok, frac)."""
    pos = 0
    for _name, off, sz in regions:
        if off != pos:
            return False, 0.0
        pos += sz
    if pos != size:
        return False, pos / size
    return True, 1.0


# ===========================================================================
# Legacy 0x73 container (PS2 DMA/GIF event font) — ported from ftc73_dump.py
# ===========================================================================

_PSM = {0: "PSMCT32", 1: "PSMCT24", 2: "PSMCT16", 10: "PSMCT16S",
        19: "PSMT8", 20: "PSMT4", 27: "PSMT8H", 36: "PSMT4HL",
        44: "PSMT4HH", 48: "PSMZ32", 49: "PSMZ24", 50: "PSMZ16",
        58: "PSMZ16S"}
_GSREG = {0x50: "BITBLTBUF", 0x51: "TRXPOS", 0x52: "TRXREG",
          0x53: "TRXDIR", 0x54: "HWREG"}
_DMA_ID = {0: "REFE", 1: "CNT", 2: "NEXT", 3: "REF", 4: "REFS",
           5: "CALL", 6: "RET", 7: "END"}
_GIF_FLG = {0: "PACKED", 1: "REGLIST", 2: "IMAGE", 3: "DISABLED"}


def _dec_dmatag(q):
    return {"qwc": q & 0xFFFF, "pce": (q >> 26) & 3,
            "id": _DMA_ID.get((q >> 28) & 7, "?%d" % ((q >> 28) & 7)),
            "irq": (q >> 31) & 1, "addr": (q >> 32) & 0x7FFFFFFF,
            "spr": (q >> 63) & 1}


def _dec_giftag(q):
    return {"nloop": q & 0x7FFF, "eop": (q >> 15) & 1,
            "pre": (q >> 46) & 1, "prim": (q >> 47) & 0x7FF,
            "flg": _GIF_FLG.get((q >> 58) & 3, "?"), "nreg": (q >> 60) & 0xF}


def _dec_ad(reg, data):
    if reg == 0x50:
        return {"SBP": data & 0x3FFF, "SBW": (data >> 16) & 0x3F,
                "SPSM": _PSM.get((data >> 24) & 0x3F, "?"),
                "DBP": (data >> 32) & 0x3FFF, "DBW": (data >> 48) & 0x3F,
                "DPSM": _PSM.get((data >> 56) & 0x3F, "?")}
    if reg == 0x51:
        return {"SSAX": data & 0x7FF, "SSAY": (data >> 16) & 0x7FF,
                "DSAX": (data >> 32) & 0x7FF, "DSAY": (data >> 48) & 0x7FF,
                "DIR": (data >> 59) & 3}
    if reg == 0x52:
        return {"RRW": data & 0xFFF, "RRH": (data >> 32) & 0xFFF}
    if reg == 0x53:
        return {"XDIR": data & 3}
    return None


def parse_legacy(d, name="<bytes>"):
    """Parse the legacy 0x73 DMA/GIF event-font container."""
    if len(d) < 0x40:
        raise FtcxError("%s: truncated legacy header" % name)
    h = {"file": name, "size": len(d), "class": "legacy73",
         "sig": _u32(d, 0),
         "tblSizeA": _u16(d, 0x0A), "tblSizeB": _u16(d, 0x10),
         "imgSize": _u16(d, 0x12), "imgW": _u16(d, 0x14),
         "imgH": _u16(d, 0x16), "oneByteGlyphs": _u16(d, 0x18),
         "twoByteCells": _u16(d, 0x1A)}
    warns = []
    tbl_end = 0x40 + h["tblSizeA"]
    if tbl_end > len(d):
        raise FtcxError("%s: metric table past EOF" % name)
    h["metrics"] = list(d[0x40:tbl_end])

    # DMA/GIF packet chain
    off = tbl_end
    h["packetOff"] = off
    pk = []
    dma = _dec_dmatag(_u64(d, off))
    pk.append({"off": off, "kind": "DMA", **dma})
    pos = off + 16
    gt = _dec_giftag(_u64(d, pos))
    regs_desc = _u64(d, pos + 8)
    regs = [(regs_desc >> (4 * i)) & 0xF for i in range(gt["nreg"] or 16)]
    pk.append({"off": pos, "kind": "GIF", **gt, "regs": regs})
    pos += 16
    for _i in range(gt["nloop"]):
        data, reg = _u64(d, pos), _u64(d, pos + 8)
        rn = _GSREG.get(reg & 0x7F, "0x%02X" % reg)
        entry = {"off": pos, "kind": "A+D", "reg": rn,
                 "data": "0x%016X" % data}
        dec = _dec_ad(reg & 0x7F, data)
        if dec:
            entry["decoded"] = dec
        pk.append(entry)
        pos += 16
    gt2 = _dec_giftag(_u64(d, pos))
    pk.append({"off": pos, "kind": "GIF", **gt2})
    pos += 16
    h["imgOff"] = pos
    img_end = pos + gt2["nloop"] * 16
    if img_end != len(d):
        warns.append("IMAGE payload ends 0x%X != EOF 0x%X"
                     % (img_end, len(d)))
    pk.append({"off": pos, "kind": "IMAGE", "bytes": img_end - pos,
               "nloop": gt2["nloop"]})
    h["packet"] = pk
    h["imgEnd"] = img_end
    h["qwcCheck"] = dma["qwc"] == (img_end - off - 16) // 16
    if not h["qwcCheck"]:
        warns.append("DMA QWC %d != qwords after tag" % dma["qwc"])
    if h["imgSize"] != img_end - pos:
        warns.append("header imgSize %d != payload %d"
                     % (h["imgSize"], img_end - pos))

    h["regions"] = [("header", 0, 0x40),
                    ("metrics", 0x40, h["tblSizeA"]),
                    ("dmaGifPacket", off, pos - off),
                    ("image:psmt4hh", pos, len(d) - pos)]
    h["byteExact"], h["coverage"] = _coverage(h["regions"], len(d))
    if not h["byteExact"]:
        warns.append("regions do not tile the file contiguously")
    h["warnings"] = warns
    h["_data"] = d
    return h


# ===========================================================================
# dispatch + glyph decode
# ===========================================================================

def parse(path_or_bytes):
    """Parse any .ftc blob — dispatches on signature."""
    if isinstance(path_or_bytes, (bytes, bytearray)):
        d, name = bytes(path_or_bytes), "<bytes>"
    else:
        name = path_or_bytes
        d = open(path_or_bytes, "rb").read()
    if len(d) < 4:
        raise FtcxError("%s: file too small (%d bytes)" % (name, len(d)))
    k = classify(d)
    if k == "ftcx":
        return parse_ftcx(d, name)
    if k == "legacy73":
        return parse_legacy(d, name)
    raise FtcxError("%s: unknown signature 0x%08X"
                    % (name, _u32(d, 0)))


def glyph_xy(f, g):
    """(cellX, cellY, plane) of glyph g in the packed sheet."""
    if not f["imgSize"]:
        raise FtcxError("no embedded image")
    cpr = f["imgW"] // f["cellW"]
    cell = g >> 1
    return (cell % cpr) * f["cellW"], (cell // cpr) * f["cellH"], g & 1


def glyph_bitmap(f, g):
    """Extract glyph g as rows of 0..7 intensities (FTCX nibble planes)."""
    d = f["_data"]
    x0, y0, plane = glyph_xy(f, g)
    tw, th, iw = f["cellW"], f["cellH"], f["imgW"]
    img = d[f["imgOff"]:f["imgOff"] + f["imgSize"]]
    stride = iw // 2

    def nib(img, idx):
        return img[idx] if 0 <= idx < len(img) else 0

    out = []
    for y in range(th):
        row = []
        for x in range(tw):
            xx, yy = x0 + x, y0 + y
            if f.get("rowPacked"):
                b = nib(img, (yy >> 1) * stride + (xx >> 1))
                v = (b >> 4) if (yy & 1) == 0 else (b & 0xF)
            else:
                b = nib(img, yy * stride + (xx >> 1))
                v = (b >> 4) if (xx & 1) == 0 else (b & 0xF)
            row.append((v & 7) if (v >> 3) == plane else 0)
        out.append(row)
    return out


def legacy_glyph_bitmap(f, g, cw=16, ch=12):
    """Extract glyph g from the legacy PSMT4HH sheet (2 glyphs per cell)."""
    d = f["_data"]
    img = d[f["imgOff"]:f["imgEnd"]]
    w = f["imgW"]
    cols = w // cw
    cell = g >> 1
    plane = g & 1
    x0, y0 = (cell % cols) * cw, (cell // cols) * ch
    out = []
    for y in range(ch):
        row = []
        for x in range(cw):
            xx, yy = x0 + x, y0 + y
            b = img[yy * (w // 2) + (xx >> 1)] if yy * (w // 2) + (xx >> 1) < len(img) else 0
            v = (b >> 4) if (xx & 1) == 0 else (b & 0xF)
            row.append((v & 7) if (v >> 3) == plane else 0)
        out.append(row)
    return out


def render_ascii(bm, chars=" .:-=+*#"):
    n = len(chars) - 1
    return "\n".join("".join(chars[min(v * n // 7, n)] for v in row)
                     for row in bm)


def serialize(f):
    """Rebuild the file from its parsed regions — the byte-exact proof.
    Returns bytes identical to the input for every corpus file."""
    d = f["_data"]
    out = bytearray()
    for _name, off, sz in f["regions"]:
        out += d[off:off + sz]
    return bytes(out)


# ===========================================================================
# batch / coverage report
# ===========================================================================

def iter_ftc(root):
    for dirpath, _dirs, files in os.walk(root):
        for fn in files:
            if fn.lower().endswith(".ftc"):
                yield os.path.join(dirpath, fn)


CSV_FIELDS = ["tree", "file", "size", "class", "slot", "count", "capacity",
              "cellW", "cellH", "imgKind", "imgOff", "imgSize", "imgW",
              "imgH", "metricOff", "metricAvail", "mszKind", "padFlavor",
              "byteExact", "coverage", "warnings"]


def _csv_row(f, tree, root):
    rel = os.path.relpath(f["file"], root)
    get = f.get
    vals = {"tree": tree, "file": rel, "size": f["size"],
            "class": f["class"], "slot": get("slot", ""),
            "count": get("count", len(get("metrics", ()))),
            "capacity": get("capacity", ""),
            "cellW": get("cellW", ""), "cellH": get("cellH", ""),
            "imgKind": get("imgKind", "psmt4hh"),
            "imgOff": get("imgOff", ""), "imgSize": get("imgSize", ""),
            "imgW": get("imgW", ""), "imgH": get("imgH", ""),
            "metricOff": get("metricOff", ""),
            "metricAvail": get("metricAvail", ""),
            "mszKind": get("metricSizeKind", ""),
            "padFlavor": get("padFlavor", ""),
            "byteExact": int(f["byteExact"]),
            "coverage": "%.4f" % f["coverage"],
            "warnings": "; ".join(f["warnings"])}
    return [str(vals[k]) for k in CSV_FIELDS]


def batch(roots, csv_path=None, verify=False):
    """Parse every .ftc under roots; optionally write a coverage CSV and
    re-serialize each file to prove byte-exactness.

    Each root may be "DIR" (tree label = basename) or "NAME=DIR" (explicit
    label for the CSV's tree column)."""
    import csv
    from collections import Counter
    rows, failed = [], []
    stats = {"class": Counter(), "imgKind": Counter(),
             "padFlavor": Counter(), "mszKind": Counter(),
             "slot": Counter(), "warned": 0, "byteExact": 0}
    total = 0
    for root in roots:
        if "=" in root and not os.path.isdir(root):
            tree, root = root.split("=", 1)
        else:
            tree = os.path.basename(os.path.normpath(root))
        for p in sorted(iter_ftc(root)):
            total += 1
            try:
                f = parse(p)
            except Exception as e:  # noqa: BLE001
                failed.append("%s: %s" % (p, e))
                continue
            if verify and serialize(f) != f["_data"]:
                f["byteExact"] = False
                f["warnings"].append("serialize() != input bytes")
            stats["class"][f["class"]] += 1
            if f["class"] == "ftcx":
                stats["imgKind"][f["imgKind"]] += 1
                stats["padFlavor"][f["padFlavor"]] += 1
                stats["mszKind"][f["metricSizeKind"]] += 1
                stats["slot"][f["slot"]] += 1
            if f["warnings"]:
                stats["warned"] += 1
            if f["byteExact"]:
                stats["byteExact"] += 1
            rows.append(_csv_row(f, tree, root))
    if csv_path:
        with open(csv_path, "w", newline="") as fh:
            w = csv.writer(fh)
            w.writerow(CSV_FIELDS)
            w.writerows(rows)
    print("== ftcx_parse batch ==")
    print("files: %d   parsed: %d   byte-exact: %d   failed: %d"
          % (total, total - len(failed), stats["byteExact"], len(failed)))
    print("classes: %s" % dict(stats["class"]))
    print("imgKinds: %s" % dict(stats["imgKind"]))
    print("padFlavor: %s" % dict(stats["padFlavor"]))
    print("mszKind: %s" % dict(stats["mszKind"]))
    print("slots: %s" % dict(sorted(stats["slot"].items())))
    print("files with informational warnings: %d" % stats["warned"])
    if failed:
        print("failures:")
        for s in failed:
            print("  ", s)
    return rows, failed


def main(argv):
    if len(argv) < 2:
        print(__doc__)
        return 2
    if argv[1] == "--batch":
        args = argv[2:]
        csv_path = None
        if "--csv" in args:
            i = args.index("--csv")
            csv_path = args[i + 1]
            del args[i:i + 2]
        verify = "--verify" in args
        args = [a for a in args if a != "--verify"]
        _rows, failed = batch(args, csv_path, verify)
        return 0 if not failed else 1
    f = parse(argv[1])
    info = {k: v for k, v in f.items() if k not in ("_data", "metrics")}
    if f.get("metrics") is not None:
        info["metricCount"] = len(f["metrics"])
        info["metricMin"] = min(f["metrics"]) if f["metrics"] else 0
        info["metricMax"] = max(f["metrics"]) if f["metrics"] else 0
    if "--json" in argv:
        print(json.dumps(info, indent=2, default=str))
    else:
        for k, v in info.items():
            if k == "packet":
                for e in v:
                    print("  [%05X] %s" % (e["off"], e))
            elif k == "regions":
                for r in v:
                    print("  region %-22s 0x%06X + 0x%X" % (r[0], r[1], r[2]))
            else:
                print("%-16s %s" % (k, v))
    if "--dump-glyph" in argv:
        g = int(argv[argv.index("--dump-glyph") + 1])
        if f["class"] == "legacy73":
            print(render_ascii(legacy_glyph_bitmap(f, g)))
        else:
            print("glyph %d (cell %d plane %d) metric=%s"
                  % (g, g >> 1, g & 1,
                     f["metrics"][g] if g < len(f.get("metrics", ())) else "-"))
            print(render_ascii(glyph_bitmap(f, g)))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
