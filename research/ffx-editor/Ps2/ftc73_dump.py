#!/usr/bin/env python3
"""ftc73_dump.py — decoder for the legacy 0x73 .ftc container
(jppc/event/obj/base.ftc), the ONE non-FTCX file of the 665-file corpus.

FTC-RESIDUAL (2026-09-17), lane Jarvis-DEVIN (corpus, no IDA).

Format (semi-open intervals, all offsets LE):

    [0x000,0x040)  64B header:  +0x00 u32 = 0x73 (115)   - signature/class
                                +0x0A u16 = 1184         - metric table size
                                +0x10 u16 = 1184         - table size (dup)
                                +0x12 u16 = 56832        - IMAGE payload size
                                +0x14 u16 = 256          - texture width  (RRW)
                                +0x16 u16 = 444          - texture height (RRH)
                                +0x18 u16 = 208          - 1-byte glyph count
                                                         = trail-byte span
                                +0x1A u16 = 416          - 2-byte cell budget
                                                         (832 bank0 slots /2)
    [0x040,0x4E0)  1184B = one u8 advance per glyph slot (glyphs 0..1183);
                     real advances for glyphs ~0-489, then 0x01 defaults
    [0x4E0,0x550)  DMA/GIF packet: DMAtag END QWC=3558
                     GIFtag1 PACKED NLOOP=4 NREG=1 regs=[A+D]
                       -> BITBLTBUF/TRXPOS/TRXREG/TRXDIR setup
                     GIFtag2 IMAGE NLOOP=3552 EOP=1
    [0x550,0xE350) 56832B packed-4bpp glyph sheet (256x444 px)

Sheet layout: 16 cols x 37 rows of 16x12 cells = 592 cells nominal; each
cell packs TWO glyphs via nibble bit3 -- even glyph index in nibble
values 0-7 (intensity = v), odd glyph in 8-15 (intensity = v-8), i.e.
cell c holds glyphs 2c (lo plane) + 2c+1 (hi plane); glyph g -> cell
g>>1, plane g&1. Glyph order = ffxsjistbl_jp.bin order, i.e. sheet glyph
N == sjistbl char N (0-207 = 1-byte charset = JpDecoder order, 208+ =
bank-0 kanji/Latin; verified: glyph208='Ａ', 260='暗', 312='期', 489='存').

Authored content = cells 0-271 (rows 0-16, glyph slots 0-543 =
sjistbl[0..543]).  Rows 17-36 are BYTE-IDENTICAL copies of row 16 -- the
assembler tiled the last authored row to reach the declared 444px DMA
height.  Live/usable font ~= glyphs 0-489 (metrics go default-1 from
490); glyphs 490-543 have authored bitmaps but default metrics, and the
nominal capacity is 592 cells / 1184 metric slots (mostly reserved).

Usage:
    ftc73_dump.py FILE [--sheet PREFIX] [--cells DIR] [--json]
"""
import json
import os
import struct
import sys
import zlib

# GS PSM names (pixel storage modes)
PSM = {0: "PSMCT32", 1: "PSMCT24", 2: "PSMCT16", 10: "PSMCT16S",
       19: "PSMT8", 20: "PSMT4", 27: "PSMT8H", 36: "PSMT4HL",
       44: "PSMT4HH", 48: "PSMZ32", 49: "PSMZ24", 50: "PSMZ16",
       58: "PSMZ16S"}

# GS privileged/packed register addresses (A+D targets)
GSREG = {0x00: "PRIM", 0x01: "RGBAQ", 0x02: "ST", 0x03: "UV", 0x04: "XYZF2",
         0x05: "XYZ2", 0x06: "TEX0_1", 0x07: "TEX0_2", 0x08: "CLAMP_1",
         0x09: "CLAMP_2", 0x0A: "FOG", 0x0B: "XYZF3", 0x0C: "XYZ3",
         0x0E: "A+D", 0x14: "TEX1_1", 0x15: "TEX1_2", 0x16: "TEX2_1",
         0x17: "TEX2_2", 0x18: "XYOFFSET_1", 0x19: "XYOFFSET_2",
         0x1A: "PRMODECONT", 0x1B: "PRMODE", 0x1C: "TEXCLUT",
         0x3B: "TEXA", 0x3C: "FOGCOL", 0x3D: "TEXFLUSH", 0x3F: "MIPTBP1_1",
         0x40: "MIPTBP2_1", 0x45: "SCISSOR_1", 0x46: "SCISSOR_2",
         0x47: "ALPHA_1", 0x48: "ALPHA_2", 0x49: "DIMX", 0x4A: "DTHE",
         0x4B: "COLCLAMP", 0x4C: "TEST_1", 0x4D: "TEST_2", 0x4E: "PABE",
         0x50: "BITBLTBUF", 0x51: "TRXPOS", 0x52: "TRXREG", 0x53: "TRXDIR",
         0x54: "HWREG", 0x60: "SIGNAL", 0x61: "FINISH", 0x62: "LABEL",
         0x63: "NOP", 0x64: "FRAME_1", 0x65: "FRAME_2", 0x66: "ZBUF_1",
         0x67: "ZBUF_2", 0x68: "TEXA_2", 0x69: "FBA_1", 0x6A: "FBA_2",
         0x6C: "PIXELORDER", 0x70: "TEX0_1?", 0x76: "MIPTBP1_2"}

DMA_ID = {0: "REFE", 1: "CNT", 2: "NEXT", 3: "REF", 4: "REFS",
          5: "CALL", 6: "RET", 7: "END"}
GIF_FLG = {0: "PACKED", 1: "REGLIST", 2: "IMAGE", 3: "DISABLED"}


def u16(d, o):
    return struct.unpack_from("<H", d, o)[0]


def u32(d, o):
    return struct.unpack_from("<I", d, o)[0]


def u64(d, o):
    return struct.unpack_from("<Q", d, o)[0]


def dec_dmatag(q):
    return {"qwc": q & 0xFFFF, "pce": (q >> 26) & 3,
            "id": DMA_ID.get((q >> 28) & 7, "?%d" % ((q >> 28) & 7)),
            "irq": (q >> 31) & 1, "addr": (q >> 32) & 0x7FFFFFFF,
            "spr": (q >> 63) & 1}


def dec_giftag(q):
    return {"nloop": q & 0x7FFF, "eop": (q >> 15) & 1,
            "pre": (q >> 46) & 1, "prim": (q >> 47) & 0x7FF,
            "flg": GIF_FLG.get((q >> 58) & 3, "?"), "nreg": (q >> 60) & 0xF}


def dec_bitbltbuf(v):
    return {"SBP": v & 0x3FFF, "SBW": (v >> 16) & 0x3F,
            "SPSM": PSM.get((v >> 24) & 0x3F, "?%d" % ((v >> 24) & 0x3F)),
            "DBP": (v >> 32) & 0x3FFF, "DBW": (v >> 48) & 0x3F,
            "DPSM": PSM.get((v >> 56) & 0x3F, "?%d" % ((v >> 56) & 0x3F)),
            "DBP_byte": ((v >> 32) & 0x3FFF) * 64 * 4}


def dec_trxpos(v):
    return {"SSAX": v & 0x7FF, "SSAY": (v >> 16) & 0x7FF,
            "DSAX": (v >> 32) & 0x7FF, "DSAY": (v >> 48) & 0x7FF,
            "DIR": (v >> 59) & 3}


def dec_trxreg(v):
    return {"RRW": v & 0xFFF, "RRH": (v >> 32) & 0xFFF}


def dec_trxdir(v):
    return {"XDIR": v & 3}


def parse(path):
    d = open(path, "rb").read()
    h = {"file": path, "size": len(d), "sig": u32(d, 0),
         "tblSizeA": u16(d, 0x0A), "tblSizeB": u16(d, 0x10),
         "imgSize": u16(d, 0x12), "imgW": u16(d, 0x14),
         "imgH": u16(d, 0x16), "f18": u16(d, 0x18), "f1A": u16(d, 0x1A)}
    # WHY: the 1184-byte region is a FLAT u8-per-glyph advance table, NOT
    # 592 (advance,width) pairs.  Proven 2026-09-17: metrics[10] (fullwidth
    # space) = 3, metrics[208] ('Ａ') = 10, metrics[312] ('期') = 15, and the
    # values track drawn ink width, not a paired struct.  Real values for
    # glyphs ~0-489, then a long run of 0x01 defaults to slot 1183.
    h["metrics"] = list(d[0x40:0x40 + h["tblSizeA"]])

    # ---- DMA/GIF packet ---------------------------------------------------
    off = 0x40 + h["tblSizeA"]
    h["packetOff"] = off
    pk = []
    dma = dec_dmatag(u64(d, off))
    pk.append({"off": off, "kind": "DMA", **dma})
    qwords_after = dma["qwc"]
    pos = off + 16
    # GIFtag1 (PACKED A+D)
    gt = dec_giftag(u64(d, pos))
    regs_desc = u64(d, pos + 8)
    regs = [(regs_desc >> (4 * i)) & 0xF for i in range(gt["nreg"] or 16)]
    pk.append({"off": pos, "kind": "GIF", **gt, "regs": regs})
    pos += 16
    n = gt["nloop"] * (gt["nreg"] or 16)
    for i in range(gt["nloop"]):
        data, reg = u64(d, pos), u64(d, pos + 8)
        rn = GSREG.get(reg & 0x7F, "0x%02X" % reg)
        entry = {"off": pos, "kind": "A+D", "reg": rn, "data": "0x%016X" % data}
        if reg == 0x50:
            entry["decoded"] = dec_bitbltbuf(data)
        elif reg == 0x51:
            entry["decoded"] = dec_trxpos(data)
        elif reg == 0x52:
            entry["decoded"] = dec_trxreg(data)
        elif reg == 0x53:
            entry["decoded"] = dec_trxdir(data)
        pk.append(entry)
        pos += 16
    # GIFtag2 (IMAGE)
    gt2 = dec_giftag(u64(d, pos))
    pk.append({"off": pos, "kind": "GIF", **gt2})
    pos += 16
    h["imgOff"] = pos
    img_end = pos + gt2["nloop"] * 16
    pk.append({"off": pos, "kind": "IMAGE", "bytes": img_end - pos,
               "nloop": gt2["nloop"]})
    h["packet"] = pk
    h["imgEnd"] = img_end
    h["qwcCheck"] = qwords_after == (img_end - off - 16) // 16
    h["_data"] = d
    return h


def sheet_pixels(h, mode="packed4"):
    """Decode the IMAGE payload.

    mode packed4: 2 px/byte -> W*H/2 bytes (proven: audit's 256x444 sheet).
    mode t4hh8:   1 px/byte -> W*H bytes (alternate T4HH transfer model).
    """
    d = h["_data"]
    img = d[h["imgOff"]:h["imgEnd"]]
    w = h["imgW"]
    if mode == "packed4":
        hh = len(img) * 2 // w
        px = [[0] * w for _ in range(hh)]
        for y in range(hh):
            for x in range(w):
                b = img[y * (w // 2) + (x >> 1)]
                px[y][x] = (b >> 4) & 0xF if (x & 1) == 0 else b & 0xF
        return px, w, hh
    else:
        hh = len(img) // w
        px = [[(img[y * w + x] >> 4) & 0xF for x in range(w)]
              for y in range(hh)]
        return px, w, hh


def png_write(path, px, w, h, scale=1):
    def chunk(tag, data):
        c = struct.pack(">I", len(data)) + tag + data
        return c + struct.pack(">I", zlib.crc32(tag + data) & 0xFFFFFFFF)
    rows = []
    for y in range(h):
        row = b""
        for x in range(w):
            v = px[y][x] * 17
            row += bytes((v, v, v, 255)) * scale
        for _ in range(scale):
            rows.append(b"\x00" + row)
    raw = b"".join(rows)
    ihdr = struct.pack(">IIBBBBB", w * scale, h * scale, 8, 6, 0, 0, 0)
    open(path, "wb").write(b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", ihdr)
                           + chunk(b"IDAT", zlib.compress(raw))
                           + chunk(b"IEND", b""))


def ascii_cell(px, w, cx, cy, cw=16, ch=12, pal=" .:-=+*#%@&$!~^?"):
    out = []
    for y in range(ch):
        row = ""
        for x in range(cw):
            v = px[cy * ch + y][cx * cw + x]
            row += pal[min(v, len(pal) - 1)]
        out.append(row)
    return "\n".join(out)


def main(argv):
    f = parse(argv[1])
    info = {k: v for k, v in f.items() if k not in ("_data", "metrics")}
    mets = f["metrics"]
    info["metricCount"] = len(mets)
    # WHY: a metric of 1 is the encoder's "unused slot" default; the last
    # real advance is at glyph 489 -> the authored font is ~490 glyphs and
    # the remaining ~694 slots are reserved.
    real = [m for m in mets if m != 1]
    info["metricReal"] = len(real)
    info["metricDefault1"] = len(mets) - len(real)
    info["lastRealGlyph"] = max(i for i, m in enumerate(mets) if m != 1)
    info["cellCount"] = len(mets) // 2  # 2 glyphs per cell (lo/hi nibble)
    if "--json" in argv:
        print(json.dumps(info, indent=2, default=str))
    else:
        for k, v in info.items():
            if k == "packet":
                for e in v:
                    print("  [%05X] %s" % (e["off"], e))
            elif k != "metrics":
                print("%-10s %s" % (k, v))
    if "--sheet" in argv:
        pref = argv[argv.index("--sheet") + 1]
        px, w, hh = sheet_pixels(f, "packed4")
        png_write(pref + "_sheet.png", px, w, hh, scale=1)
        px2, w2, h2 = sheet_pixels(f, "t4hh8")
        png_write(pref + "_sheet_t4hh8.png", px2, w2, h2, scale=1)
        print("wrote %s_sheet.png (%dx%d) + _t4hh8 (%dx%d)"
              % (pref, w, hh, w2, h2))
    if "--cells" in argv:
        cd = argv[argv.index("--cells") + 1]
        os.makedirs(cd, exist_ok=True)
        px, w, hh = sheet_pixels(f, "packed4")
        cols = w // 16
        ncells = len(f["metrics"]) // 2
        for c in range(ncells):
            cx, cy = c % cols, c // cols
            cell = [row[cx * 16:(cx + 1) * 16] for row in
                    px[cy * 12:(cy + 1) * 12]]
            png_write(os.path.join(cd, "cell_%03d.png" % c), cell, 16, 12,
                      scale=4)
        print("wrote %d cells to %s" % (ncells, cd))
    if "--dump-cell" in argv:
        c = int(argv[argv.index("--dump-cell") + 1])
        px, w, hh = sheet_pixels(f, "packed4")
        cx, cy = c % (w // 16), c // (w // 16)
        # glyphs 2c (lo nibble) and 2c+1 (hi nibble) share this cell
        print("cell %d (col %d row %d) glyphs %d/%d metrics=%s/%s"
              % (c, cx, cy, 2 * c, 2 * c + 1,
                 f["metrics"][2 * c], f["metrics"][2 * c + 1]))
        print(ascii_cell(px, w, cx, cy))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
