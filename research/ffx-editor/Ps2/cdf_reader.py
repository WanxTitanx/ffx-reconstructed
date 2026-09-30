#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""cdf_reader.py — PS3-era FFX `chr/*/*.cdf` reader.

PROVEN (corpus lane, 2026-09-17 — 396/396 files parse clean, size-exact).
SEMANTICS UPDATED (wave-13 CDF-CMF-JOIN, 2026-09-18): the record tail is
NOT a 3D AABB — it is **3x vec2 corner positions in a normalized [0,4096]
parametric space** (cloth rest layout). `.cdf` = the collider/target mesh
set for the character's cloth binding; `.cmf` keys reference these records
by index (see docs/reverse/FFX_CDF_CMF_JOIN_2026-09-18.md). The `bbox`
field name is kept in parse() output only for backward compatibility.

  `.cdf` sits next to `.cmf`/`.ah`/`.ahx64`/`mdl/`/`tex/` in every chr dir.
  Loaded by `FFX_Chr_LoadCdfFile` (0x63D410) via `FFX_Chr_LoadCdfCmfForAnimation`
  (0x82A1C0) — the pair is animation/cloth-binding support data.

  Layout (little-endian):
    +0x00  f32 bboxMin[3], f32 bboxMax[3]   (whole-model bounds)
    then repeated GROUP headers:
             +0 u16 a    (group type: 0 or 2 observed)
             +2 u16 b    (group index 0..N-1 sequential)
             +4 u16 count
             +6 u16 pad  (0xCDCD debug-fill or 0)
      each followed by `count` x 32B records:
             +0  u16 i0
             +2  u16 i1
             +4  u16 i2   (model-vertex indices — collider triangle)
             +6  u16 zero (always 0)
             +8  f32 u0,v0, u1,v1, u2,v2  (3 corner positions, [0,4096] space)
    terminator: u32 0xFFFFFFFF at EOF.

Usage: cdf_reader.py FILE.cdf... [--json]
"""
import struct
import sys
import json


def parse(path):
    d = open(path, "rb").read()
    if len(d) < 0x20:
        raise ValueError("too small")
    bbox = struct.unpack_from("<6f", d, 0)
    groups = []
    off = 0x18
    while True:
        a, b, cnt, pad = struct.unpack_from("<4H", d, off)
        off += 8
        if cnt > 4000:
            raise ValueError("runaway count %d @%#x" % (cnt, off - 8))
        recs = []
        for i in range(cnt):
            i0, i1, i2, iz = struct.unpack_from("<4H", d, off)
            rb = struct.unpack_from("<6f", d, off + 8)
            recs.append({"i": (i0, i1, i2), "pad": iz, "bbox": rb})
            off += 32
        groups.append({"a": a, "b": b, "pad": pad, "count": cnt,
                       "records": recs})
        term = struct.unpack_from("<I", d, off)[0] if off + 4 <= len(d) else 0
        if term == 0xFFFFFFFF:
            off += 4
            break
    if off != len(d):
        raise ValueError("trailing %d bytes" % (len(d) - off))
    return {"path": path, "size": len(d), "bbox": list(bbox),
            "nGroups": len(groups),
            "nRecords": sum(g["count"] for g in groups),
            "groups": groups}


def main(argv):
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
                bb = rep["bbox"]
                print("%s: %dB bbox=(%.2f,%.2f,%.2f)-(%.2f,%.2f,%.2f) "
                      "groups=%d records=%d"
                      % (path, rep["size"], bb[0], bb[1], bb[2],
                         bb[3], bb[4], bb[5], rep["nGroups"], rep["nRecords"]))
                for gi, g in enumerate(rep["groups"]):
                    print("   group%d a=%d b=%d n=%d pad=%#x"
                          % (gi, g["a"], g["b"], g["count"], g["pad"]))
        except Exception as e:
            print("%s: FAIL %s" % (path, e))
    print("%d/%d parsed" % (nok, len(files)))
    return 0 if nok == len(files) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
