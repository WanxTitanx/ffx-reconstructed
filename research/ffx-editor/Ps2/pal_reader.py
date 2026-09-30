#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""pal_reader.py — PS3 FFX `chr/*/*.pal` / `magic/*/tex/TexList.pal` reader.

PROVEN STRUCTURE + SEMANTICS (corpus lane PAL-KEY, 2026-09-17 —
1906/1906 files, 41106/41106 records resolved):

  `.pal` is NOT a color palette. It is generated from the sibling `.ah`
  (anim-handler manifest) / `texlist.txt` — `FFX_Animation_ConvertAhPathToPal`
  @0x66AB0 does `strcpy(strstr(path, ".ah"), ".pal")`, streams it via
  `Phyre_Shader_PreAllocateFromStream`, and stashes it in the TexAnim
  file cache. It is the compiled TexAnim preload table mapping asset
  names to their serialized data-cluster descriptors.

  Record layout (20B, file is BIG-ENDIAN — PS3/GCM toolchain artifact,
  shipped byte-identical on every platform):
    +0x00 u32 key   = djb2(assetPath) & 0x7FFFFFFF   (PROVEN, see below)
    +0x04..+0x13    = the asset's 16B PDataBlock descriptor copied
                      VERBATIM from the PHYR serialized header: the
                      big-endian quad {clusterSize, 0x80, 0, 0x80} sits
                      byte-identical at file offset +0x48 of every
                      GCM-serialized asset (40,147/40,147 records on the
                      PSARC-extracted PS3 tree + 30/30 FitGirl
                      magic_0668 — wave-13 corpus lane 2026-09-18).
    +0x04 u32 val   = clusterSize = size of the asset's trailing bulk
                      data cluster (texture/mesh payload — the last
                      `val` bytes of the file). val=0 records exist:
                      `textureAnimationChar.ags.phyre` carries a literal
                      {0,0x80,0,0x80} descriptor on disk (cluster-less
                      asset). The preamble is ~4KB but NOT constant
                      (observed deltas 4014..178KB) — val is a size,
                      never an offset.
    +0x08 u32 0x00000080  (descriptor word 2 — alignment 0x80)
    +0x0C u32 0x00000000  (descriptor word 3 — reserved)
    +0x10 u32 0x00000080  (descriptor word 4 — flag)
  GNM reserializations keep an LE {size,align} variant at +0x50 instead;
  the first word equals `val` when the payload survives re-encoding
  (.ags/.dae and some .dds match; re-encoded .dds differ — expected).
  (Previous lane read the file little-endian and saw 0x80000000 — same
  bytes, wrong endianness for key/val.)

  KEY FUNCTION (cracked 2026-09-17):
    key = djb2(path) & 0x7FFFFFFF  where `path` is the asset's GCM
    dev-tree path as listed in the `.ah` `g_fileNames[]` array, e.g.
      "/FFX_Data/GameData/PS3Data/magic/magic_0668/tex/GCM/"
      "14464_19_0_0_128_256.dds.phyre"  ->  0x64B5BC3A
    djb2: h = 5381; h = h*33 + c per byte. The shipped `texlist.log`
    prints the same values next to the `R:`-prefixed host path — the
    drive prefix is NOT part of the hashed string. Bit31 is always
    clear (masked — reserved as a flag bit by the table).
    `/Shaders/` entries in `.ah` never get `.pal` records.
    Refuted: crc32/adler32, fnv1/fnv1a-32, sdbm, joaat, djb2-xor,
    filename-only, lowercase, drive-prefixed paths.

Usage: pal_reader.py FILE.pal... [--json] [--resolve]
  --resolve  scan sibling .ah/.ahx64/texlist.txt manifests and print the
             resolved asset path for each key (needs the .pal to sit in
             its original directory).
"""
import os
import re
import struct
import sys
import json

TAIL = b"\x00\x00\x00\x80\x00\x00\x00\x00\x00\x00\x00\x80"
STR_RE = re.compile(r'"((?:[^"\\]|\\.)*)"')


def name_hash(s):
    """Phyre .pal key: djb2 over the path string, bit31 masked off."""
    h = 5381
    for c in s.encode("utf-8"):
        h = (h * 33 + c) & 0xFFFFFFFF
    return h & 0x7FFFFFFF


def parse(path):
    d = open(path, "rb").read()
    if len(d) % 20:
        raise ValueError("size %d not multiple of 20" % len(d))
    recs = []
    for i in range(len(d) // 20):
        key, val = struct.unpack_from(">2I", d, 20 * i)
        if d[20 * i + 8:20 * i + 20] != TAIL:
            raise ValueError("rec%d bad tail %s" % (i, d[20 * i + 8:20 * i + 20].hex()))
        recs.append({"i": i, "key": key, "value": val})
    return {"path": path, "size": len(d), "count": len(recs),
            "records": recs}


def candidate_names(pal_path):
    """Collect hashable asset-path strings from manifests next to the .pal.

    `.ah`/`.ahx64` files carry full `g_fileNames[]` paths. `texlist.txt`
    carries bare filenames that are hashed under the file's own
    `<paldir>/GCM/` path below the PS3Data root.
    """
    dp = os.path.dirname(os.path.abspath(pal_path))
    names = []
    for fn in os.listdir(dp):
        low = fn.lower()
        fp = os.path.join(dp, fn)
        if low.endswith(".ah") or low.endswith(".ahx64"):
            try:
                txt = open(fp, encoding="utf-8", errors="replace").read()
            except OSError:
                continue
            names += [s for s in STR_RE.findall(txt) if ".phyre" in s]
        elif low == "texlist.txt":
            # pal dir relative to the nearest .../ps3data/ ancestor
            parts = dp.replace("\\", "/").split("/")
            rel = None
            for j in range(len(parts) - 1, -1, -1):
                if parts[j].lower() == "ps3data":
                    rel = "/".join(parts[j + 1:])
                    break
            try:
                lines = open(fp, encoding="utf-8", errors="replace").read().splitlines()
            except OSError:
                continue
            for ln in lines:
                ln = ln.strip()
                if not ln:
                    continue
                if rel:
                    names.append("/FFX_Data/GameData/PS3Data/%s/GCM/%s" % (rel, ln))
                names.append(ln)
    return names


def resolve(rep):
    hmap = {}
    for n in candidate_names(rep["path"]):
        hmap.setdefault(name_hash(n), n)
    nres = 0
    for r in rep["records"]:
        r["name"] = hmap.get(r["key"])
        if r["name"]:
            nres += 1
    rep["resolved"] = nres
    return rep


def main(argv):
    as_json = "--json" in argv
    do_res = "--resolve" in argv
    files = [a for a in argv if not a.startswith("-")]
    if not files:
        print(__doc__)
        return 1
    nok = 0
    for path in files:
        try:
            rep = parse(path)
            if do_res:
                resolve(rep)
            nok += 1
            if as_json:
                print(json.dumps(rep, indent=1))
            else:
                extra = ""
                if do_res:
                    extra = " (%d/%d resolved)" % (rep["resolved"], rep["count"])
                print("%s: %dB, %d records%s" % (path, rep["size"], rep["count"], extra))
                for r in rep["records"]:
                    nm = "  " + r["name"] if r.get("name") else ""
                    print("   [%3d] key=%08x val=%8d%s" % (r["i"], r["key"], r["value"], nm))
        except Exception as e:
            print("%s: FAIL %s" % (path, e))
    print("%d/%d parsed" % (nok, len(files)))
    return 0 if nok == len(files) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
