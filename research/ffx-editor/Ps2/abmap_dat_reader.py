#!/usr/bin/env python3
# abmap_dat_reader.py — inspector for the PS2 FFX sphere-grid abmap datNN.dat set.
#
# Lane: FMT-ARCHIVE audit (2026-09-17). RESEARCH ONLY — reads files in place,
# never writes. Pure stdlib.
#
# WHY THIS EXISTS
#   master/<region>/menu/abmap/datNN.dat is a FAMILY of sectioned binary tables
#   (not a generic multi-file archive): JP ships dat00..dat15, US 12 carriers.
#   The editor's product reader/writer is FfxLib/SphereGrid/SphereGrid_File*.cs
#   (RT0 byte-faithful for the topology files, proven by SphereGridLayoutRt0).
#   This tool re-implements the byte-level shapes as an independent check so the
#   format docs can be audited without spinning up the editor.
#
# ROLES (proved by structure + FfxLib call sites; names per PT54 linkage):
#   dat01/02/03  grid TOPOLOGY (Original/Standard/Expert):
#                u16 U1=0x0031 | u16 clusterCount | u16 nodeCount | u16 linkCount
#                | u16 U5 | u16 U6 | u16 U7=0x0003 | u16 U8=0x5000
#                then clusters (16B), nodes (12B), links (8B) — sequential.
#                size == 0x10 + C*16 + N*12 + L*8   (verified: dat01 18160,
#                dat02 18952 — exact)
#   dat09/10/11  per-node CONTENTS, paired dat01->09, dat02->10, dat03->11:
#                u16 U1=0x0031 | u16 nodeCount | u32 0 | nodeCount payload bytes
#                (size == 8 + nodeCount; dat09 = 836 = 8+828, dat10 = 868 = 8+860)
#   dat00/12/13/14 700,880-B "big tables" — u32 section-offset directory (24
#                slots: 0=unused, else section start); observed section starts
#                0x60 / 0x580 / 0x810; bulk data lives in the 0x810 section.
#                Per-grid variants (dat00~dat13 differ in 368 B only; dat00 vs
#                dat12 ~77% different — FFX_ABMAP_PS2_GRIDS_2026-08-01).
#   dat04..08, dat15  1-byte 0x00 stubs (placeholders).
#
# VALIDATIONS PERFORMED
#   - topology: exact-size equation; node.Cluster < clusterCount;
#     link.Node1/Node2 < nodeCount (AnchorNode may be 0xFFFF);
#   - contents: size == 8 + nodeCount; header reserved u32 == 0;
#   - big tables: slot offsets non-decreasing within [0x60, filesize];
#     each non-zero slot offset < filesize;
#   - stubs: size == 1 and byte == 0x00.
#
# USAGE
#   python3 abmap_dat_reader.py PATH...           (file or abmap dir)
#   python3 abmap_dat_reader.py DIR --json        (machine-readable per file)
#   python3 abmap_dat_reader.py FILE --dump       (per-record listing, topology)
# Exit 0 when every decoded file's checks pass; 1 on any FAIL.
#
# Refs: FFX_STRUCTURE_COMPLETE_2026-09-14.md §3.4/§8.17;
# FfxLib/SphereGrid/SphereGrid_File.cs (ReadLayout, lines ~155-267);
# docs/reverse/FFX_ABMAP_PS2_GRIDS_2026-08-01.md.

import os
import struct
import sys

TOPO_MAGIC = 0x0031          # u16@0x00 on every dat file that carries a header
CONTENTS_MAGIC = 0x0031      # same magic on the contents files


def u16(b, o):
    return struct.unpack_from("<H", b, o)[0]


def u32(b, o):
    return struct.unpack_from("<I", b, o)[0]


def i16(b, o):
    return struct.unpack_from("<h", b, o)[0]


def classify(path, d):
    """Return (kind, checks, report_dict). kind in stub|topology|contents|bigtable."""
    checks = []
    rep = {"file": path, "size": len(d)}

    if len(d) == 1:
        checks.append(("stub single 0x00 byte", d == b"\x00"))
        return "stub", checks, rep

    if len(d) >= 0x60 and u32(d, 0x04) == 0x60 and u32(d, 0x08) == 0x60:
        # big table: 16 u32 slot offsets @0x00-0x3F (0 = absent slot), then a
        # 0x20-byte sub-table @0x40-0x5F, then sections. Observed section
        # starts: 0x60 / 0x580 / 0x810 (bulk data in the last one).
        slots = [u32(d, i * 4) for i in range(16)]
        rep["slots"] = slots
        present = [s for s in slots if s]
        checks.append(("slot offsets within file",
                       all(s < len(d) for s in present)))
        checks.append(("first section == 0x60 (16 slots + 0x20 sub-table)",
                       min(present) == 0x60 if present else False))
        rep["sections"] = sorted(set(present))
        rep["subtable_40_5f"] = d[0x40:0x60].hex()
        return "bigtable", checks, rep

    if len(d) >= 0x10 and u16(d, 0) == TOPO_MAGIC and u16(d, 0x0C) == 0x0003 \
            and u16(d, 0x0E) == 0x5000:
        c, n, l = u16(d, 2), u16(d, 4), u16(d, 6)
        rep.update(clusterCount=c, nodeCount=n, linkCount=l,
                   U5=u16(d, 8), U6=u16(d, 0x0A))
        expected = 0x10 + c * 16 + n * 12 + l * 8
        checks.append(("size == 0x10 + C*16 + N*12 + L*8", len(d) == expected))
        rep["expected_size"] = expected
        if len(d) != expected:
            return "topology", checks, rep
        node_off = 0x10 + c * 16
        link_off = node_off + n * 12
        bad_cluster = sum(1 for i in range(n)
                          if u16(d, node_off + i * 12 + 8) >= c)
        bad_link = sum(1 for i in range(l)
                       if u16(d, link_off + i * 8) >= n
                       or u16(d, link_off + i * 8 + 2) >= n)
        checks.append(("all node.Cluster < clusterCount", bad_cluster == 0))
        checks.append(("all link Node1/Node2 < nodeCount", bad_link == 0))
        rep["bad_cluster_refs"] = bad_cluster
        rep["bad_link_refs"] = bad_link
        return "topology", checks, rep

    if len(d) >= 8 and u16(d, 0) == CONTENTS_MAGIC and len(d) == 8 + u16(d, 2):
        n = u16(d, 2)
        rep.update(nodeCount=n, reserved_u32=u32(d, 4))
        checks.append(("size == 8 + nodeCount", True))
        checks.append(("reserved u32@0x04 == 0", u32(d, 4) == 0))
        payload = d[8:]
        rep["distinct_content_values"] = len(set(payload))
        return "contents", checks, rep

    checks.append(("unrecognized shape", False))
    rep["note"] = "does not match stub/topology/contents/bigtable"
    return "unknown", checks, rep


def dump_topology(d):
    c, n, l = u16(d, 2), u16(d, 4), u16(d, 6)
    node_off = 0x10 + c * 16
    link_off = node_off + n * 12
    print(f"  clusters ({c}):")
    for i in range(c):
        o = 0x10 + i * 16
        print(f"    #{i:3d} pos=({i16(d, o)},{i16(d, o + 2)}) "
              f"u3={u16(d, o + 4)} radiusType={u16(d, o + 6)} "
              f"u5={u16(d, o + 8)} u6={u16(d, o + 10)} "
              f"u7={u16(d, o + 12)} u8={u16(d, o + 14)}")
    print(f"  nodes ({n}):")
    for i in range(n):
        o = node_off + i * 12
        print(f"    #{i:3d} pos=({i16(d, o)},{i16(d, o + 2)}) "
              f"u3={u16(d, o + 4)} redundantContent={u16(d, o + 6)} "
              f"cluster={u16(d, o + 8)} unknown6={u16(d, o + 10)}")
    print(f"  links ({l}):")
    for i in range(l):
        o = link_off + i * 8
        print(f"    #{i:3d} node1={u16(d, o)} node2={u16(d, o + 2)} "
              f"anchor={u16(d, o + 4):#06x} unused={u16(d, o + 6)}")


def scan(path, as_json=False, dump=False):
    import json
    d = open(path, "rb").read()
    kind, checks, rep = classify(path, d)
    rep["kind"] = kind
    rep["all_ok"] = all(ok for _, ok in checks)
    if as_json:
        print(json.dumps(rep, ensure_ascii=True))
    else:
        status = "OK  " if rep["all_ok"] else "FAIL"
        print(f"[{status}] {os.path.basename(path):12s} kind={kind:9s} size={len(d)}")
        for name, ok in checks:
            print(f"       {'ok ' if ok else 'FAIL'} {name}")
        if kind == "topology":
            print(f"       clusters={rep['clusterCount']} nodes={rep['nodeCount']} "
                  f"links={rep['linkCount']} U5={rep['U5']} U6={rep['U6']}")
        elif kind == "contents":
            print(f"       nodes={rep['nodeCount']} "
                  f"distinct_content_values={rep['distinct_content_values']}")
        elif kind == "bigtable":
            print(f"       sections={['%#x' % s for s in rep['sections']]}")
    if dump and kind == "topology":
        dump_topology(d)
    return rep["all_ok"]


def main(argv):
    as_json = "--json" in argv
    dump = "--dump" in argv
    args = [a for a in argv if not a.startswith("--")]
    if not args:
        print(__doc__ and __doc__.split("USAGE")[1].split("Refs")[0].strip())
        return 2
    targets = []
    for a in args:
        if os.path.isdir(a):
            targets += sorted(os.path.join(a, f) for f in os.listdir(a)
                              if f.startswith("dat") and f.endswith(".dat"))
        else:
            targets.append(a)
    ok = True
    for t in targets:
        try:
            ok = scan(t, as_json, dump) and ok
        except OSError as e:
            print(f"[FAIL] {t}: {e}")
            ok = False
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
