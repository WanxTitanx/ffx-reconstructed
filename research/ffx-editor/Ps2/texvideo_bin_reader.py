#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""texvideo_bin_reader.py — PS3 `PS3Data/TextureVideo/texVideo*.bin` reader.

PROVEN (corpus lane, 2026-09-17 — 22/22 files, byte-exact; layout derived
from decompiled `FFX_TextureVideo_LoadScenarioSidecar` @0x66FD10 in
ffx-reconstructed, which memcpy's each array with exactly these sizes).

  TextureVideo = the in-world video screens (Luca stadium, Home lchb01/
  lchb04) — per-scenario geometry sidecar that tells the engine where to
  map the FMV texture. Selected by strstr() on the scenario name.

  Layout (little-endian):
    +0x00  u32 recordCount (observed 1 in all shipping files)
    then per record:
      +0  u32 vCount
      +4  u32 fCount        (face-vertex count; /3 = triangles)
      +8  f32 pos[vCount][3]        (vertex positions)
      .   f32 arr[fCount][3]        (normals — vec3)
      .   f32 arr[fCount][4]        (tangent/color — vec4)
      .   f32 uv[fCount][2]         (UVs — vec2)
      .   u16 idx[fCount]           (indices)

  The engine copies these verbatim into PTexture2D-backed render slots
  (the video surface is a 1920x1080 texture, `setDimensions(0x780,0x438)`).

Usage: texvideo_bin_reader.py FILE.bin... [--json] [--dump-obj]
"""
import struct
import sys
import json


def parse(path):
    d = open(path, "rb").read()
    n = struct.unpack_from("<I", d, 0)[0]
    recs = []
    off = 4
    for i in range(n):
        vc, fc = struct.unpack_from("<II", d, off)
        p = off + 8
        pos = [struct.unpack_from("<3f", d, p + 12 * k) for k in range(vc)]
        p += 12 * vc
        arr3 = [struct.unpack_from("<3f", d, p + 12 * k) for k in range(fc)]
        p += 12 * fc
        arr4 = [struct.unpack_from("<4f", d, p + 16 * k) for k in range(fc)]
        p += 16 * fc
        uv = [struct.unpack_from("<2f", d, p + 8 * k) for k in range(fc)]
        p += 8 * fc
        idx = list(struct.unpack_from("<%dH" % fc, d, p))
        p += 2 * fc
        recs.append({"vCount": vc, "fCount": fc, "positions": pos,
                     "vec3": arr3, "vec4": arr4, "uv": uv, "indices": idx})
        off = p
    if off != len(d):
        raise ValueError("trailing %d bytes" % (len(d) - off))
    return {"path": path, "size": len(d), "recordCount": n, "records": recs}


def dump_obj(rep, out):
    """Emit Wavefront OBJ (positions + per-face-vertex UVs/indices)."""
    voff = 0
    with open(out, "w") as f:
        f.write("# texVideo dump: %s\n" % rep["path"])
        for r in rep["records"]:
            for p in r["positions"]:
                f.write("v %.6f %.6f %.6f\n" % p)
            for t in r["uv"]:
                f.write("vt %.6f %.6f\n" % t)
            fc = r["fCount"]
            for t in range(0, fc - 2, 3):
                i0, i1, i2 = r["indices"][t:t + 3]
                f.write("f %d/%d %d/%d %d/%d\n"
                        % (i0 + 1 + voff, t + 1, i1 + 1 + voff, t + 2,
                           i2 + 1 + voff, t + 3))
            voff += r["vCount"]
    print("  wrote", out)


def main(argv):
    as_json = "--json" in argv
    dobj = "--dump-obj" in argv
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
                print("%s: %dB, %d record(s)" % (path, rep["size"],
                                                 rep["recordCount"]))
                for i, r in enumerate(rep["records"]):
                    print("   rec%d: %d verts, %d face-verts (%d tris)"
                          % (i, r["vCount"], r["fCount"], r["fCount"] // 3))
            if dobj:
                dump_obj(rep, path + ".obj")
        except Exception as e:
            print("%s: FAIL %s" % (path, e))
    print("%d/%d parsed" % (nok, len(files)))
    return 0 if nok == len(files) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
