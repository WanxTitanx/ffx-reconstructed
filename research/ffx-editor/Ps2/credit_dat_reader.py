#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""credit_dat_reader.py — metamenu `menucreditstext/credit.dat` reader.

PROVEN (corpus lane, 2026-09-17 — the shipping file parses byte-exact:
199 index rows end exactly at indexEnd, all 173 string refs land on valid
records, the last record ends at EOF).

  Layout (little-endian):
    +0x00     u16 indexEnd      (0x037F — index occupies [4, indexEnd))
    +0x02     u16 nEntries      (199 credit rows)
    +0x04     index: nEntries x {u8 count, count x u32 relOff}
              count 0 = blank line; count 1..3 = strings in that row.
    indexEnd  u32 blobLen       (0x0CB4 — counts [indexEnd, EOF), i.e.
                                 INCLUDES itself: blobLen = size-indexEnd)
    blob      base = indexEnd+1; first 4 bytes are a header
              (0x0C 0x00 0x00 0x01), then records at relOff >= 4:
              {u16 len, u8 payload[len]} — payload ends with 0x00.

  Encoding: metamenu glyph-index text — NOT the main FFX script table.
  Letters proven by ciphertext ("DIRECTOR", "PRODUCER"): 0x09=R 0x0B=P
  0x0E=U 0x0F=T 0x12=I 0x14=O 0x18=C 0x1E=E 0x1F=D 0x7B=space 0x75='.'.
  Glyphs 0x28..0x3E are a second range (names/roles); unknown bytes are
  emitted as <NN> placeholders.

Usage: credit_dat_reader.py FILE [--json] [--raw]
"""
import struct
import sys
import json

# Partial glyph map proven by plaintext ("DIRECTOR", "PRODUCER").
GLYPH = {
    0x09: "R", 0x0B: "P", 0x0E: "U", 0x0F: "T", 0x12: "I", 0x14: "O",
    0x18: "C", 0x1E: "E", 0x1F: "D", 0x7B: " ", 0x75: ".",
}


def parse(path):
    d = open(path, "rb").read()
    size = len(d)
    idx_end, nent = struct.unpack_from("<HH", d, 0)
    entries = []
    o = 4
    for _ in range(nent):
        cnt = d[o]
        o += 1
        offs = list(struct.unpack_from("<%dI" % cnt, d, o)) if cnt else []
        o += 4 * cnt
        entries.append(offs)
    assert o == idx_end, "index end %#x != header %#x" % (o, idx_end)
    blob_len = struct.unpack_from("<I", d, idx_end)[0]
    assert blob_len == size - idx_end, "blobLen %d != %d" % (blob_len,
                                                           size - idx_end)
    base = idx_end + 1

    def get_string(rel):
        ln = struct.unpack_from("<H", d, base + rel)[0]
        seg = d[base + rel + 2: base + rel + 2 + ln]
        assert len(seg) == ln and seg.endswith(b"\x00"), "bad rec @%#x" % rel
        return seg[:-1]

    rows = [{"row": i, "strings": [get_string(r) for r in offs]}
            for i, offs in enumerate(entries)]
    return {"path": path, "size": size, "indexEnd": idx_end,
            "nEntries": nent, "blobLen": blob_len, "blobBase": base,
            "nStringRefs": sum(len(e) for e in entries), "rows": rows}


def decode(payload):
    out = []
    for b in payload:
        if b in GLYPH:
            out.append(GLYPH[b])
        else:
            out.append("<%02x>" % b)
    return "".join(out)


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
            print("%s: %dB, %d rows, %d string refs, blobLen=%d @%#x"
                  % (path, rep["size"], rep["nEntries"], rep["nStringRefs"],
                     rep["blobLen"], rep["blobBase"]))
            for r in rep["rows"]:
                for s in r["strings"]:
                    print("  row%3d: %s" % (r["row"],
                                            s.hex(" ") if raw else decode(s)))
            if as_json:
                print(json.dumps({"path": rep["path"],
                                  "rows": [[s.hex() for s in r["strings"]]
                                           for r in rep["rows"]]}, indent=1))
        except Exception as e:
            print("%s: FAIL %s" % (path, e))
    print("%d/%d parsed" % (nok, len(files)))
    return 0 if nok == len(files) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
