#!/usr/bin/env python3
# ── FFX PS2 .tm2 (TIM2) validator + decoder to PNG (research tool) ─────────────
#
# Purpose: validate every .tm2 texture in the PS2 corpus against the byte-level
# layout proven below, and decode pixels (4/8bpp indexed via CLUT, plus a
# documented-assumption path for 16bpp direct) to PNG — stdlib only (zlib for
# PNG IDAT + hand-built chunks; no PIL/numpy).
#
# Proven layout (empirical, re-proven on the full 84-file corpus 2026-09-14).
# Cross-check vs the product preview reader FfxLib/Ps2/Ps2Tim2Reader.cs: its
# u32@0x18 imageBytes read is CORRECT (84/84 here); what this tool adds is the
# strict size/CLUT inclusions, a full pixel decode to PNG, and evidence that
# the CLUT byte order is [R,G,B,A] (the product preview assumes [B,G,R,A] —
# its own warnings admit CLUT order was unvalidated).
#
#   FILE HEADER (16 bytes)
#     +0x00 char[4] magic "TIM2"
#     +0x04 u8  version   (4 on all 84 files)
#     +0x05 u8  formatId  (0 on all 84 files)
#     +0x06 u16 imageCount (1 on all 84 files — single picture per file here)
#     +0x08 u32 0         (reserved)
#     +0x0C 4B  zero pad except trailing byte 0x6F on 2 files (raw recorded;
#                 semantics unknown, informational only)
#
#   PICTURE HEADER (48 bytes @ 0x10..0x3F; size 48 constant on all 84 files)
#     +0x10 u32 pictureTotalSize  == fileSize - 16   (84/84 exact)
#     +0x14 u32 paletteBytes      (1024 = 256*4 / 64 = 16*4 / 0)
#     +0x18 u32 imageBytes        FULL image data size (84/84 ==
#                                  width*height*bpp). Incidental structure:
#                                  high u16 = count of 65536-byte units,
#                                  low u16 = remainder — an arithmetic
#                                  identity, NOT two semantic fields (an
#                                  early mipmap interpretation of the high
#                                  half was tested and REFUTED).
#     +0x1C u16 pictureHeaderSize (48, constant)
#     +0x1E u16 colorCount        (256 / 16 / 0; paletteBytes == colorCount*4)
#     +0x20 u16 256               (raw; semantics unproven — constant 256 even
#                                  on the 16-color and CLUT-less files)
#     +0x22 u8  3 for CLUT images / 0 for direct color (raw; likely CLUT fmt)
#     +0x23 u8  imageType: 5 = 8bpp indexed (81 files), 4 = 4bpp indexed
#                                  (1 file: num_16.tm2), 1 = 16bpp direct
#                                  (2 files: encount/encount2 bg_1.tm2)
#     +0x24 u16 width
#     +0x26 u16 height
#     +0x28 16B  GS register block (raw, 78 distinct variants; not decoded)
#
#   INCLUSIONS (all hold on 84/84):
#     fileSize == 0x40 + imageBytes + paletteBytes
#     imageBytes == width * height * bpp   (bpp from imageType)
#   PIXEL ORDER: image data @ 0x40, CLUT AFTER the image @ 0x40+imageBytes
#     (opposite of classic PS1 TIM; verified by size math + byte inspection).
#   CLUT ENTRIES: u32 little-endian, byte order [R,G,B,A] — GS convention
#     (0xAABBGGRR). Evidence: semantic oracles fire5.tm2 (fire: byte0 sum
#     dominant = red-heavy) vs sky_02.tm2 / icetex.tm2 (sky/ice: byte2 sum
#     dominant = blue-heavy); a [B,G,R,A] reading would invert both.
#     Alpha byte is written to PNG as-is; the 0x80==opaque vs 128/255 question
#     stays open (fire5 uses constant 0x80, sky_02 uses full 0..255 range).
#   4-BPP NIBBLES: low nibble = left pixel (PS convention, consistent with the
#     product reader's experimental preview; not visually re-proven here).
#   16-BPP DIRECT (type 1): ASSUMED RGBA5551 (r=v>>11, g=v>>6 & 31, b=v>>1 & 31,
#     a=v&1) per PS2 PSMCT16 — flagged as assumption in every report line.
#
# MAINT: research-only script (research_tools/), does NOT ship in the editor.
# Writer/encoder stays a P1 gap. No swizzle handling observed/needed: image
# bytes are linear rows in this corpus (imageBytes == W*H*bpp exactly).

import argparse
import os
import struct
import sys
import zlib

IMAGE_HEADER_SIZE = 0x40
BLOCK = 65536

# imageType@0x23 -> bytes per pixel (proven via imageBytes == W*H*bpp on 84/84)
BPP_BY_TYPE = {5: 1, 4: 0.5, 1: 2}
TYPE_NAMES = {5: "CLUT8", 4: "CLUT4", 1: "16bpp-direct(assumed)"}


class Tim2FormatError(Exception):
    """Validation failure with a human-readable reason."""


class Tim2Image:
    def __init__(self, path):
        self.path = path
        self.reasons = []          # non-fatal notes
        self.assumption = None     # set when decode relies on an assumption
        with open(path, "rb") as fh:
            data = fh.read()
        self.data = data
        if len(data) < IMAGE_HEADER_SIZE or data[:4] != b"TIM2":
            raise Tim2FormatError(f"magic {data[:4]!r} != b'TIM2' or file < 64B")
        self.version = data[0x04]
        self.format_id = data[0x05]
        self.image_count, = struct.unpack_from("<H", data, 0x06)
        self.reserved = data[0x08:0x10]
        (self.picture_total, self.palette_bytes, self.image_bytes,
         self.header_size, self.color_count) = struct.unpack_from("<IIIHH",
                                                                  data, 0x10)
        self.image_blocks = self.image_bytes // BLOCK   # informational only
        self.image_rem = self.image_bytes % BLOCK       # (arithmetic identity)
        self.u16_0x20, = struct.unpack_from("<H", data, 0x20)
        self.u8_0x22 = data[0x22]
        self.image_type = data[0x23]
        self.width, self.height = struct.unpack_from("<HH", data, 0x24)
        self.gs_block = data[0x28:0x40]

        # ── Strict validation (each check names its law) ──
        if self.version != 4:
            self.reasons.append(f"version={self.version} (expected 4)")
        if self.format_id != 0:
            self.reasons.append(f"formatId={self.format_id} (expected 0)")
        if self.image_count != 1:
            self.reasons.append(
                f"imageCount={self.image_count} != 1 (multi-picture "
                f"unsupported by this validator)")
        if self.header_size != 48:
            self.reasons.append(f"pictureHeaderSize={self.header_size} != 48")
        if self.picture_total != len(data) - 16:
            self.reasons.append(
                f"pictureTotalSize {self.picture_total} != fileSize-16 "
                f"{len(data) - 16}")
        if self.image_type not in BPP_BY_TYPE:
            raise Tim2FormatError(f"unknown imageType {self.image_type}@0x23")
        bpp = BPP_BY_TYPE[self.image_type]
        if self.width == 0 or self.height == 0:
            raise Tim2FormatError(f"zero dimension {self.width}x{self.height}")
        if self.palette_bytes != self.color_count * 4:
            self.reasons.append(
                f"paletteBytes {self.palette_bytes} != colorCount*4 "
                f"{self.color_count * 4}")
        if self.image_bytes != int(self.width * self.height * bpp):
            self.reasons.append(
                f"imageBytes {self.image_bytes} != W*H*bpp "
                f"{int(self.width * self.height * bpp)}")
        if len(data) != IMAGE_HEADER_SIZE + self.image_bytes + self.palette_bytes:
            self.reasons.append(
                f"fileSize {len(data)} != 0x40+imageBytes+paletteBytes "
                f"{IMAGE_HEADER_SIZE + self.image_bytes + self.palette_bytes}")
        if self.u8_0x22 not in (0, 3):
            self.reasons.append(f"u8@0x22={self.u8_0x22} unexpected")
        if self.image_type == 1:
            self.assumption = "16bpp read as RGBA5551 (PSMCT16) — UNPROVEN"

    @property
    def type_name(self):
        return TYPE_NAMES[self.image_type]

    def decode_rgba(self):
        """Decode to rows of RGBA bytes (len == height, row len == width*4)."""
        d = self.data
        w, h = self.width, self.height
        img_off = IMAGE_HEADER_SIZE
        clut_off = img_off + self.image_bytes

        if self.image_type in (5, 4):
            if self.color_count == 0 or self.palette_bytes < self.color_count * 4:
                raise Tim2FormatError("CLUT image without usable palette")
            clut = d[clut_off:clut_off + self.color_count * 4]
            rows = []
            if self.image_type == 5:
                if len(d) < img_off + w * h:
                    raise Tim2FormatError("8bpp image data truncated")
                for y in range(h):
                    row = bytearray(w * 4)
                    base = img_off + y * w
                    for x in range(w):
                        idx = d[base + x]
                        o = idx * 4
                        # CLUT byte order [R,G,B,A] (GS convention; evidence
                        # in file header comment).
                        row[x * 4 + 0] = clut[o + 0]
                        row[x * 4 + 1] = clut[o + 1]
                        row[x * 4 + 2] = clut[o + 2]
                        row[x * 4 + 3] = clut[o + 3]
                    rows.append(bytes(row))
            else:  # 4bpp, low nibble = left pixel
                row_bytes = w // 2
                if len(d) < img_off + row_bytes * h:
                    raise Tim2FormatError("4bpp image data truncated")
                for y in range(h):
                    row = bytearray(w * 4)
                    base = img_off + y * row_bytes
                    for x in range(w):
                        packed = d[base + x // 2]
                        idx = (packed & 0x0F) if (x & 1) == 0 else (packed >> 4) & 0x0F
                        o = idx * 4
                        row[x * 4 + 0] = clut[o + 0]
                        row[x * 4 + 1] = clut[o + 1]
                        row[x * 4 + 2] = clut[o + 2]
                        row[x * 4 + 3] = clut[o + 3]
                    rows.append(bytes(row))
            return rows

        if self.image_type == 1:
            # 16bpp direct — RGBA5551 ASSUMPTION (see header comment).
            if len(d) < img_off + w * h * 2:
                raise Tim2FormatError("16bpp image data truncated")
            rows = []
            for y in range(h):
                row = bytearray(w * 4)
                base = img_off + y * w * 2
                for x in range(w):
                    v, = struct.unpack_from("<H", d, base + x * 2)
                    row[x * 4 + 0] = ((v >> 11) & 0x1F) << 3
                    row[x * 4 + 1] = ((v >> 6) & 0x1F) << 3
                    row[x * 4 + 2] = ((v >> 1) & 0x1F) << 3
                    row[x * 4 + 3] = 255 if (v & 1) else 0
                rows.append(bytes(row))
            return rows

        raise Tim2FormatError(f"decode unsupported for type {self.image_type}")


# ── Minimal PNG writer (color type 6, 8-bit RGBA, filter 0 rows) ───────────────
def png_chunk(tag, payload):
    return (struct.pack(">I", len(payload)) + tag + payload +
            struct.pack(">I", zlib.crc32(tag + payload) & 0xFFFFFFFF))


def write_png(path, width, height, rgba_rows):
    raw = b"".join(b"\x00" + r for r in rgba_rows)
    ihdr = struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0)
    png = (b"\x89PNG\r\n\x1a\n" + png_chunk(b"IHDR", ihdr) +
           png_chunk(b"IDAT", zlib.compress(raw, 9)) + png_chunk(b"IEND", b""))
    with open(path, "wb") as fh:
        fh.write(png)


def scan(root, png_out=None, limit=0):
    files = []
    for dirpath, _dirs, names in os.walk(root):
        for n in sorted(names):
            if n.lower().endswith(".tm2"):
                files.append(os.path.join(dirpath, n))
    files.sort()
    if limit:
        files = files[:limit]

    rows = []
    counters = {"pass": 0, "fail": 0, "png": 0}
    type_histo = {}
    for path in files:
        rel = os.path.relpath(path, root)
        try:
            img = Tim2Image(path)
        except (Tim2FormatError, OSError, struct.error) as exc:
            counters["fail"] += 1
            rows.append(("FAIL", rel, str(exc), ""))
            continue
        try:
            rgba = img.decode_rgba()
        except (Tim2FormatError, struct.error) as exc:
            counters["fail"] += 1
            rows.append(("FAIL", rel, f"decode: {exc}", ""))
            continue
        counters["pass"] += 1
        type_histo[img.type_name] = type_histo.get(img.type_name, 0) + 1
        note = "; ".join(img.reasons) if img.reasons else "all checks exact"
        if img.assumption:
            note += f" | {img.assumption}"
        png_path = ""
        if png_out:
            os.makedirs(png_out, exist_ok=True)
            safe = rel.replace(os.sep, "__").replace("/", "__") + ".png"
            png_path = os.path.join(png_out, safe)
            write_png(png_path, img.width, img.height, rgba)
            counters["png"] += 1
        rows.append(("PASS", rel,
                     f"{img.type_name} {img.width}x{img.height} "
                     f"img={img.image_bytes}B pal={img.palette_bytes}B",
                     png_path))
    return rows, counters, type_histo


def main(argv=None):
    ap = argparse.ArgumentParser(
        description="FFX PS2 .tm2 (TIM2) validator + PNG decoder "
                    "(stdlib-only research tool)")
    ap.add_argument("root", help="corpus root to scan for *.tm2")
    ap.add_argument("--png-out", metavar="DIR",
                    help="write one PNG per decoded file into DIR "
                         "(omit to validate only)")
    ap.add_argument("--limit", type=int, default=0,
                    help="process only the first N files (0 = all)")
    args = ap.parse_args(argv)

    rows, counters, type_histo = scan(args.root, args.png_out, args.limit)
    print(f"== .tm2 corpus scan: {args.root}")
    for status, rel, info, png in rows:
        line = f"{status}  {rel}  [{info}]"
        if png:
            line += f" -> {os.path.basename(png)}"
        print(line)
    total = counters["pass"] + counters["fail"]
    print(f"== summary: {counters['pass']}/{total} validated+decoded without "
          f"error; {counters['fail']} failed"
          + (f"; {counters['png']} PNGs written to {args.png_out}"
             if args.png_out else ""))
    print(f"== type histogram: {type_histo}")
    print("== notes: CLUT byte order read as [R,G,B,A] (GS convention, "
          "semantic-oracle evidence); alpha copied raw (0x80-opaque question "
          "open); 16bpp path is an ASSUMED RGBA5551 read; 4bpp low-nibble-left "
          "per PS convention.")
    return 0 if counters["fail"] == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
