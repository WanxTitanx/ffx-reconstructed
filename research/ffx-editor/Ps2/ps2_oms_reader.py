#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""ps2_oms_reader.py — PS2 FFX `rsd/*.oms` object-model dev source reader.

PROVEN (corpus lane, 2026-09-17 — 7/7 files are ASCII assembler-style
source that compiles to the binary OMD chunks consumed at runtime).

  `.oms` = "Object Model Source" — hand/tool-written text source for PS2
  model/displaylist fragments (under `yonishi_data/*/rsd/` — effect and
  field props). Grammar:

    ; comment lines (`;=====` banners, "; gt4(6 prim)" prim counts,
    "; N vertex M normal", "; group OMD_H", ";end of prim")
    .align  4                         <- alignment directive
    .word   0x00000004                <- u32 data ("; flag", "; pa,va,na")
    .short  0x0006,0x0008,0x0000      <- u16 data ("; pc, vc, nc")
    .byte   0x88,0x00                 <- u8 data  ("; alpha, alphafix")

  Group header ("OMD_H"): flag u32, then pa/va/na u32 offsets (prim,
  vertex, normal array), pc/vc/nc u16 counts, alpha bytes. Then prim
  records: `.short type,count` (type 0x0000=gt3 tri-list, 0x0600=gt4
  strip — PS2 GIFtag register count), followed per-prim by 3x u32
  (packed RGBA/UVQ-ish), 4x u16 vertex indices, 8x u16 UV coords, ending
  `.short -1,-1, 0,0,0,0,0,0` (";end of prim"). Then `;vertex`/`;normal`
  sections: `.short x,y,z` s16 triples (+-32767 fixed-point) or small
  normals.

Usage: ps2_oms_reader.py FILE.oms... [--json]
"""
import re
import sys
import json

DIRECTIVE = re.compile(r"^\s*\.(word|short|byte|align)\s+([^;]+?)\s*(;.*)?$",
                       re.M)
COMMENT = re.compile(r"^\s*;(.*)$", re.M)
NUM = re.compile(r"-?\d+|0x[0-9a-fA-F]+")


def parse(path):
    text = open(path, "rb").read().decode("ascii", "replace")
    groups = []
    cur = {"header": {}, "directives": 0, "comments": []}
    for m in DIRECTIVE.finditer(text):
        cur["directives"] += 1
    # split into OMD groups by '; group OMD_H' comments
    for m in re.finditer(r";\s*gt(\d+)\((\d+) prim\)", text):
        groups.append({"gt": int(m.group(1)), "prims": int(m.group(2))})
    vn = re.findall(r";\s*(\d+)\s+vertex\s+(\d+)\s+normal", text)
    nw = len(re.findall(r"\.word\b", text))
    ns = len(re.findall(r"\.short\b", text))
    nb = len(re.findall(r"\.byte\b", text))
    na = len(re.findall(r"\.align\b", text))
    return {"path": path, "size": len(text.encode()),
            "groups": groups,
            "vertexNormal": [(int(a), int(b)) for a, b in vn],
            "directives": {"word": nw, "short": ns, "byte": nb,
                           "align": na}}


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
                print("%s: %dB — groups=%s vn=%s dirs=%s"
                      % (path, rep["size"], rep["groups"],
                         rep["vertexNormal"], rep["directives"]))
        except Exception as e:
            print("%s: FAIL %s" % (path, e))
    print("%d/%d parsed" % (nok, len(files)))
    return 0 if nok == len(files) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
