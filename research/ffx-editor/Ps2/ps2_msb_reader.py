#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""ps2_msb_reader.py — PS2 FFX `menu/*.msb` / `btl/*/tutorial.msb` reader.

PROVEN (corpus lane, 2026-09-17 — 16/16 files: offset table + FFX-encoded
string blob; uspc blob decodes to Sphere-Grid tutorial text, jppc to the
same strings in JP encoding; FFX-2 `new_*/menu/tutorial.msb` identical
structure).

  ".msb" = menu string block. Layout (little-endian):
    +0x00  N x {u32 off, u32 off}   — duplicated-offset pairs; off[0] = N*8
                                      is also the blob start (table tiles
                                      the file: last string runs to EOF).
    blob   N NUL-terminated FFX-encoded strings (US table: byte = glyph
           index + 0x30; 0x03 = newline, 0x0A/0x0B = formatting codes with
           one param byte, 0x09 = page/entry marker + param).

  uspc `menumain.msb` = 118 tutorial strings ("Select 'Sphere Grid' from
  the Main Menu", ...). Encoding = the standard FFX glyph-index scheme —
  see research_tools/Encoding/ffx_text_dump.py / FfxEncoding.tables.cs.
  jppc strings use the JP glyph table (2-byte leads 0x26..0x2F).

Usage: ps2_msb_reader.py FILE.msb [--raw] [--json]
"""
import struct
import sys
import json

# US glyph table subset (from FfxEncoding.tables.cs / ffx_text_dump.py):
# byte value = glyph index + 0x30, so byte 0x50 -> 'A'.
_US_SEQ = ("0123456789 !\u201D#$%&\u2019()*+,-./:;<=>?"
           "ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`\u2018"
           "abcdefghijklmnopqrstuvwxyz")
US_TABLE = {0x30 + i: ch for i, ch in enumerate(_US_SEQ)}
FORMAT_CODES = {0x41: "</>", 0x43: "<W>", 0xB1: "<B>"}
CHARNAME = {0x30 + i: n for i, n in enumerate(
    ["TIDUS", "YUNA", "AURON", "KIMAHRI", "WAKKA", "LULU", "RIKKU",
     "SEYMOUR", "VALEFOR", "IFRIT", "IXION", "SHIVA", "BAHAMUT",
     "ANIMA", "YOJIMBO", "CINDY", "SANDY", "MINDY"])}


def decode(d, off):
    """Decode one NUL-terminated FFX string at file offset `off`."""
    out = []
    p = off
    while p < len(d) and d[p] != 0:
        b = d[p]
        if b == 0x03:
            out.append("\n")
        elif b in (0x0A, 0x13):  # format / charname + 1 param byte
            prm = d[p + 1] if p + 1 < len(d) else 0
            p += 1
            out.append(FORMAT_CODES.get(prm, CHARNAME.get(
                prm, "<%02x:%02x>" % (b, prm))))
        elif b in (0x06,) or 0x26 <= b <= 0x2F:  # 2-byte glyph lead
            n2 = d[p + 1] if p + 1 < len(d) else 0
            p += 1
            out.append("<GLYPH:%d>" % (208 * b + n2 - 8992))
        elif b < 0x30:
            out.append("<C%02x>" % b)
        else:
            out.append(US_TABLE.get(b, "<%02x>" % b))
        p += 1
    return "".join(out)


def parse(path):
    d = open(path, "rb").read()
    first = struct.unpack_from("<I", d, 0)[0]
    if first < 8 or first % 8 or first > len(d):
        raise ValueError("bad table start %#x" % first)
    npairs = first // 8
    offs = []
    for i in range(npairs):
        a, b = struct.unpack_from("<II", d, 8 * i)
        assert a == b, "pair %d mismatch" % i
        assert a < len(d), "offset %d oob" % i
        offs.append(a)
    return {"path": path, "size": len(d), "count": npairs,
            "offsets": offs,
            "strings": [decode(d, o) for o in offs]}


def main(argv):
    as_json = "--json" in argv
    raw = "--raw" in argv
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
                print("%s: %dB, %d strings" % (path, rep["size"], rep["count"]))
                for i, s in enumerate(rep["strings"]):
                    if raw:
                        print("  [%3d] @%#x: %r" % (i, rep["offsets"][i], s))
                    else:
                        print("  [%3d] %s" % (i, s.replace("\n", "\\n")))
        except Exception as e:
            print("%s: FAIL %s" % (path, e))
    print("%d/%d parsed" % (nok, len(files)))
    return 0 if nok == len(files) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
