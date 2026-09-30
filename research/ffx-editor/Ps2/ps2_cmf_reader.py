#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""ps2_cmf_reader.py — PS3-era FFX `chr/*/*.cmf` reader.

PROVEN (corpus lane, 2026-09-17 — 62/62 unique FFX `.cmf` payloads tile
byte-exactly: all FFX files under `chr/mon|pc|sum` in the PS3Data trees,
plus the FFX-2 `chr/pc` set. One unrelated homonym — a non-chr
`uccmds32.cmf` from an Analiser surface pack — is NOT this format.)

`.cmf` sits next to `.cdf` (see cdf_reader.py) in every chr dir and is
loaded right after it by `FFX_Chr_LoadCdfCmfForAnimation` (0x82A1C0):
the cdf pointer lands at char-object +0x100, the cmf pointer at +0x104.
So `.cmf` is animation-side per-character data — almost certainly
Phyre secondary-motion (cloth/hair/accessory swing) constraint tables:
the u16 `idx` fields, the `0xFFFF` group markers and the paired vec3
arrays fit per-joint param blocks; counts also scale with sibling .cdf
group sizes (e.g. s004 cdf g0 n=144 -> cmf first section 432 = 144x3).

Layout (little-endian):
  +0x00  u32 ver     = 1
  +0x04  u32 unk     = 8   (always)
  +0x08  u32 w2      = 1 in every file except s024 (=3; see below)
  +0x0C  u32 w3      = small int 3..40 (per-character sub-count?)
  then an item stream to EOF, items 4-byte aligned:
    * u32 == 0            -> filler/alignment word
    * u32 n  > 0          -> SECTION: n x 8-byte KEY records, then
                             (optionally) n x 12-byte VEC3 records
      KEY  = {u16 flag (0 or 1), u16 idx (node/joint id; 0xFFFF =
              sub-list marker), u32 aux (0, or an f32 parameter in
              pc files)}
      VEC3 = {f32 x, f32 y, f32 z}
  The float array is present for every section in the corpus EXCEPT
  s024's first section {n=1, key=(flag=0, idx=0, aux=3)} — the only
  w2=3 file. That 16-byte preamble could equally be read as two bare
  (u32,u32) param words (1,0) and (3,0); the bytes are identical, the
  reader reports the keys-only-section reading.

Parsing rule: a section's float array is taken when doing so still
lets the whole file tile to EOF (a stray nonzero word that cannot be
a section falls back to PARAM — never observed in the corpus).
Implemented as a min-PARAM DP over 4-byte-aligned offsets.

Usage: ps2_cmf_reader.py FILE.cmf... [--json] [--dump]
"""
import json
import struct
import sys


def parse(path):
    d = open(path, "rb").read()
    if len(d) < 0x10:
        raise ValueError("too small")
    ver, unk, w2, w3 = struct.unpack_from("<4I", d, 0)
    if ver != 1 or unk != 8:
        raise ValueError("bad header %#x %#x (not a chr .cmf)" % (ver, unk))
    n = len(d)
    u32 = lambda o: struct.unpack_from("<I", d, o)[0]

    # Bottom-up DP over aligned offsets: cost = number of PARAM words.
    # items: FILL(u32 0) / SECTF(n keys + n vec3) / SECTNF(n keys) / PARAM
    nW = (n - 0x10) // 4
    cost = [0] * (nW + 2)
    nxt = [None] * (nW + 2)           # (kind, consume_bytes, n)
    cost[nW] = 0                      # f(n) reachable, empty
    ok = [False] * (nW + 2)
    ok[nW] = True
    for wi in range(nW - 1, -1, -1):
        o = 0x10 + wi * 4
        c = u32(o)
        best = None                 # (cost, order, kind, size, n)
        if c == 0:
            if ok[wi + 1]:
                best = (cost[wi + 1], 2, "FILL", 4, 0)
        else:
            if o + 4 + c * 20 <= n:
                wj = wi + 1 + c * 5
                if ok[wj]:
                    best = (cost[wj], 0, "SECTF", 4 + c * 20, c)
            if o + 4 + c * 8 <= n:
                wj = wi + 1 + c * 2
                if ok[wj]:
                    cand = (cost[wj], 1, "SECTNF", 4 + c * 8, c)
                    if best is None or cand < best:
                        best = cand
            if ok[wi + 1]:
                cand = (cost[wi + 1] + 1, 3, "PARAM", 4, c)
                if best is None or cand < best:
                    best = cand
        if best is not None:
            cost[wi], _, k, sz, cnt = best
            ok[wi] = True
            nxt[wi] = (k, sz, cnt)
    if not ok[0]:
        raise ValueError("body does not tile")

    sections = []
    fills = 0
    params = []
    wi = 0
    while wi < nW:
        k, sz, cnt = nxt[wi]
        o = 0x10 + wi * 4
        if k == "FILL":
            fills += 1
        elif k == "PARAM":
            params.append({"off": o, "value": u32(o)})
        else:
            keys = []
            for i in range(cnt):
                a, b, v = struct.unpack_from("<HHI", d, o + 4 + i * 8)
                keys.append({"flag": a, "idx": b, "aux": v})
            vecs = []
            if k == "SECTF":
                fo = o + 4 + cnt * 8
                for i in range(cnt):
                    vecs.append(list(struct.unpack_from("<3f", d, fo + i * 12)))
            sections.append({"off": o, "count": cnt, "hasVec3": k == "SECTF",
                             "keys": keys, "vec3": vecs})
        wi += sz // 4
    return {"path": path, "size": n, "ver": ver, "unk": unk,
            "w2": w2, "w3": w3, "fills": fills,
            "nSections": len(sections),
            "nKeys": sum(s["count"] for s in sections),
            "nMarkers": sum(1 for s in sections
                            for k_ in s["keys"] if k_["idx"] == 0xFFFF),
            "sections": sections, "params": params}


def main(argv):
    as_json = "--json" in argv
    dump = "--dump" in argv
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
                slim = dict(rep)
                for s in slim["sections"]:
                    del s["keys"], s["vec3"]
                print(json.dumps(slim, indent=1))
            else:
                print("%s: %dB ver=%d w2=%d w3=%d sections=%d keys=%d "
                      "markers=%d fills=%d params=%d"
                      % (path, rep["size"], rep["ver"], rep["w2"], rep["w3"],
                         rep["nSections"], rep["nKeys"], rep["nMarkers"],
                         rep["fills"], len(rep["params"])))
                for si, s in enumerate(rep["sections"]):
                    print("   sect%d @%#06x n=%d vec3=%s"
                          % (si, s["off"], s["count"], s["hasVec3"]))
                    if dump:
                        for ki, k_ in enumerate(s["keys"]):
                            aux = k_["aux"]
                            af = struct.unpack("<f", struct.pack("<I", aux))[0]
                            tag = " MARK" if k_["idx"] == 0xFFFF else ""
                            print("     key%3d flag=%d idx=%-6d aux=%#010x"
                                  " (%.6g)%s"
                                  % (ki, k_["flag"], k_["idx"], aux, af, tag))
                            if s["hasVec3"]:
                                v = s["vec3"][ki]
                                print("          vec3=(%.6g, %.6g, %.6g)"
                                      % tuple(v))
        except Exception as e:
            print("%s: FAIL %s" % (path, e))
    print("%d/%d parsed" % (nok, len(files)))
    return 0 if nok == len(files) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
