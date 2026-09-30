#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""ps2_fp_reader.py — PS2 FFX `par/*.fp` field-particle dev source reader.

PROVEN (corpus lane, 2026-09-17 — 11/11 files are pure ASCII text).

  `.fp` = "Fielad Particle data" (literal header banner; "Field Particle"
  — dev-source particle definitions that shipped inside the game data
  under `yonishi_data/dat_et*/.../par/`). Grammar:

    [HEADER  // Fielad Particle data        <- banner comment line
      @0 @2 @3 @0  @0 @0 @0 @0;             <- 8 x 8 int rows (';' ends row)
      ...
    [PAR0000                                <- particle entry section
      @Z:\\effect\\jo_eff\\mon_hit\\par\\rush_rsi.par;   <- source .par path
      @x @y @z;                             <- vec3 (pos offset)
      @x @y @z;                             <- vec3 (rotation?)
      @x @y @z;                             <- vec3 (scale, usually 1.0)
      @a @f @f @f   @i @i @i @;             <- param rows
      ...]
    [PAR0001 ...

  Tokens are `@`-prefixed ints/floats/paths, `;` = record end, `[` = new
  section. Fully parseable — the runtime probably consumes a compiled
  equivalent; these are authored dev artifacts.

Usage: ps2_fp_reader.py FILE.fp... [--json]
"""
import re
import sys
import json

TOKEN = re.compile(r"@([^;\s]+)")
SECTION = re.compile(r"\[([A-Za-z]+)(\d*)\s*(//[^\n]*)?")


def parse(path):
    text = open(path, "rb").read().decode("ascii", "replace")
    sections = []
    cur = None
    for m in SECTION.finditer(text):
        sections.append({"name": m.group(1), "id": m.group(2) or "",
                         "comment": (m.group(3) or "").strip(),
                         "rows": []})
        cur = sections[-1]
        # rows until next '['
        nxt = text.find("[", m.end())
        body = text[m.end(): nxt if nxt >= 0 else len(text)]
        for line in body.split(";"):
            toks = TOKEN.findall(line)
            if toks:
                cur["rows"].append(toks)
    return {"path": path, "size": len(text.encode()),
            "sections": sections}


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
                print("%s: %dB" % (path, rep["size"]))
                for s in rep["sections"]:
                    print("   [%s%s] %s — %d rows"
                          % (s["name"], s["id"], s["comment"], len(s["rows"])))
                    for r in s["rows"][:3]:
                        print("      ", r)
        except Exception as e:
            print("%s: FAIL %s" % (path, e))
    print("%d/%d parsed" % (nok, len(files)))
    return 0 if nok == len(files) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
