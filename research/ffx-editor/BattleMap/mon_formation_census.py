#!/usr/bin/env python3
# ── mon_formation_census.py — FFX monster-ID census across battle formations ──
#
# Lane: Jarvis-DEVIN swarm, leva 5 (work/_mon_formations) — 2026-09-15.
#
# Purpose: answer "which of the 366 kernel monster IDs (0..365) are referenced
#          by battle formations". Scans every battle/btl/<area>/<name>.bin of a
#          corpus tree, parses the chunk table, extracts chunk 2 (Formation,
#          8 monster slots @ +0x0C, u16 LE), splits raw = (variant<<12)|id,
#          and emits the used / never-referenced ID sets plus the high-nibble
#          (model-variant selector) cross-check.
#
# Format provenance (do NOT re-derive blindly):
#   * FFXProjectEditor/FfxLib/Battle/Battle_File.cs — canonical reader:
#       rawChunkValue = i32@0x00; chunkCount = rawChunkValue - 1;
#       offset table = (chunkCount+1) x i32 @ 0x04; 0xFFFFFFFF terminates the
#       table early; offset 0 = absent chunk; tail offset > EOF => chunk and
#       everything after it treated as absent (kino03_*, mihn05_*, cdsp00_02);
#       chunk end = next offset >= start, else EOF.
#   * Formation chunk (index 2), canonical length 0x1C:
#       +0x00 u8 commonVoiceLines, +0x01/+0x02 u8 unknown, +0x03 u8 inWater,
#       +0x04..0x0B padding, +0x0C 8 x u16 monster slots (0xFFFF = empty).
#       Observed short variant: 0x14 (klyt01_*) — only 4 slot cells fit; they
#       are extracted honestly and any non-0xFFFF tail is flagged.
#   * Slot u16: low 12 bits = kernel monster ID (0..365), high nibble =
#       model-variant selector — proven by IDA + corpus in
#       docs/reverse/FFX_MONSTER3_COUNT_2026-09-15.md ("multi-forma NAO e
#       linha extra — e o nibble alto do ID de formacao, id>>12").
#   * Kernel ID space 0..365 = monster1 0-100 (101 rows) + monster2 101-180
#       (80) + monster3 181-365 (185), stride 128B, resolver
#       FFX_Table_GetEntryByIdRange@0x7AB890 (fallback row 0).
#
# Corpus rule: Steam jppc (/mnt/nvme-samsung/...) is a LIVE MOD WORKSPACE —
# never a source. Canonical roots used: nvme-xpg PS2 master (primary),
# FitGirl FFX_Data, PS3-PSARC, PS4-P1 reconstructions (all under /mnt,
# READ-ONLY — open 'rb' only).
#
# Extra heuristic (`outside_hits`): for every unused ID, counts u16 cells
# OUTSIDE the formation chunk whose value equals the formation-slot encoding
# (0x1000|id). This is a byte-pattern hint only — chunk0 ATEL bytecode and
# other chunks can contain arbitrary u16s — so hits are reported, never
# auto-promoted to "used".
#
# Usage:
#   python3 mon_formation_census.py [--root <btl_dir> ...] --out <dir>
#                                   [--names <Monster_Dictionary.cs>]
#   --root points at a btl directory containing <area>/<name>.bin subtrees;
#   default = the 4 canonical jppc roots below.
#
# Outputs (per --out):
#   <label>_formations.csv   one row per non-empty slot cell
#   <label>_files.csv        one row per scanned .bin (chunk layout + flags)
#   census.json              full census: used/unused/multiform/anomalies

import argparse
import csv
import json
import os
import re
import struct
import sys
from collections import defaultdict

MONSTER_ID_MAX = 365          # kernel global ID space: 0..365 (366 slots)
FORMATION_CHUNK = 2           # chunk index carrying the monster lineup
FORMATION_HDR = 0x0C          # formation header size before the slot cells
FORMATION_CANON_LEN = 0x1C    # 0x0C header + 8 u16 slots
SLOT_COUNT = 8
SLOT_EMPTY = 0xFFFF

DEFAULT_ROOTS = {
    "xpg-ps2-master": "/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/battle/btl",
    "fitgirl-ffx-data": "/mnt/nvme-xpg/Final Fantasy X-X2 - HD Remaster "
                        "[FitGirl Re-repack]/FFX/data/FFX_Data/ffx_ps2/ffx/master/jppc/battle/btl",
    "ps3-psarc": "/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/FFXX2HDREMASTER/"
                 "PSARC_EXTRACTED/FFX/ffx_ps2/ffx/master/jppc/battle/btl",
    "ps4-p1": "/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/PS4FFX/extracted/"
              "FFX_Data_P1/ffx_ps2/ffx/master/jppc/battle/btl",
}


def read_i32(buf, off):
    if off < 0 or off + 4 > len(buf):
        return 0
    return struct.unpack_from("<i", buf, off)[0]


def chunk_offsets(buf):
    """Replicates Battle_File.ParseChunks offset-table semantics."""
    raw = read_i32(buf, 0x00)
    count = raw - 1
    if count <= 0:
        return raw, [], False
    offsets = []
    truncated = False
    for i in range(count + 1):
        off = read_i32(buf, 0x04 + i * 4)
        if off == -1:  # 0xFFFFFFFF sentinel
            truncated = True
            break
        offsets.append(off)
    return raw, offsets, truncated


def chunk_bounds(buf, idx):
    """Return (offset, length) of chunk idx applying the repo's end rules."""
    raw, offsets, truncated = chunk_offsets(buf)
    meta = {
        "raw_marker": raw,
        "chunk_count": max(0, raw - 1),
        "n_offsets": len(offsets),
        "sentinel_truncated": truncated,
    }
    if idx >= len(offsets):
        return 0, 0, offsets, meta
    off = offsets[idx]
    if off == 0 or off > len(buf):
        return off, 0, offsets, meta
    end = len(buf)
    for nxt in offsets[idx + 1:]:
        if nxt >= off:
            end = nxt
            break
    return off, end - off, offsets, meta


def scan_file(path):
    """Return (slot_rows, file_row, buf, c2_bounds)."""
    with open(path, "rb") as f:
        buf = f.read()
    rel = os.path.basename(os.path.dirname(path)) + "/" + os.path.basename(path)
    battle_id = os.path.basename(os.path.dirname(path))

    c2_off, c2_len, offsets, meta = chunk_bounds(buf, FORMATION_CHUNK)
    flags = []
    if meta["chunk_count"] == 4:
        flags.append("unsafe_4chunk")
    if c2_off == 0:
        flags.append("chunk2_absent")
    elif c2_len == 0 and c2_off > len(buf):
        flags.append("chunk2_past_eof")
    elif 0 < c2_len < FORMATION_CANON_LEN:
        flags.append("chunk2_short")
    elif c2_len > FORMATION_CANON_LEN:
        flags.append("chunk2_long")

    slots = []
    if c2_len > FORMATION_HDR:
        n_cells = min(SLOT_COUNT, (c2_len - FORMATION_HDR) // 2)
        for i in range(n_cells):
            raw16 = struct.unpack_from("<H", buf, c2_off + FORMATION_HDR + i * 2)[0]
            if raw16 == SLOT_EMPTY:
                continue
            mid = raw16 & 0x0FFF
            variant = raw16 >> 12
            slots.append({
                "battle_id": battle_id,
                "file": rel,
                "slot": i,
                "raw": raw16,
                "monster_id": mid,
                "variant": variant,
            })
            if mid > MONSTER_ID_MAX:
                flags.append(f"id_out_of_range:{mid}@slot{i}")
            if variant == 0:
                flags.append(f"variant0_slot{i}")
    file_row = {
        "file": rel,
        "battle_id": battle_id,
        "size": len(buf),
        "raw_marker": meta["raw_marker"],
        "chunk_count": meta["chunk_count"],
        "chunk2_offset": c2_off,
        "chunk2_len": c2_len,
        "n_filled_slots": len(slots),
        "flags": ";".join(flags),
    }
    return slots, file_row, buf, (c2_off, c2_len)


def scan_root(label, root):
    all_slots, all_files = [], []
    bufs = {}   # battle rel path -> (buf, (c2_off, c2_len)) for the heuristic
    for dirpath, _dirs, files in os.walk(root):
        for fn in sorted(files):
            if not fn.lower().endswith(".bin"):
                continue
            path = os.path.join(dirpath, fn)
            try:
                slots, frow, buf, c2 = scan_file(path)
            except Exception as exc:  # corpus read must never die silently
                slots, buf, c2 = [], b"", (0, 0)
                frow = {"file": path, "battle_id": "", "size": -1,
                        "raw_marker": 0, "chunk_count": 0, "chunk2_offset": 0,
                        "chunk2_len": 0, "n_filled_slots": 0,
                        "flags": f"read_error:{exc}"}
            all_slots.extend(slots)
            all_files.append(frow)
            if buf:
                bufs[frow["file"]] = (buf, c2)
    return all_slots, all_files, bufs


def outside_hits(bufs, wanted_ids):
    """u16 cells outside chunk2 matching the slot encoding 0x1000|id.

    Returns {monster_id: {file: count}}. Even-aligned u16 scan only — the same
    alignment the slot cells use."""
    hits = defaultdict(lambda: defaultdict(int))
    wanted = set(wanted_ids)
    for rel, (buf, (c2_off, c2_len)) in bufs.items():
        for off in range(0, len(buf) - 1, 2):
            if c2_off <= off < c2_off + c2_len:
                continue
            v = struct.unpack_from("<H", buf, off)[0]
            if (v >> 12) == 1 and (v & 0x0FFF) in wanted:
                hits[v & 0x0FFF][rel] += 1
    return hits


def load_names(path):
    """Parse Monster_Dictionary.cs { id, \"name\" } pairs."""
    txt = open(path, encoding="utf-8-sig").read()
    return {int(i): n for i, n in
            re.findall(r'\{\s*(\d+)\s*,\s*"([^"]*)"\s*\}', txt)}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", action="append", default=None,
                    help="btl dir; repeatable. Default = 4 canonical roots.")
    ap.add_argument("--out", required=True)
    ap.add_argument("--names", default=None,
                    help="optional Monster_Dictionary.cs for name enrichment")
    args = ap.parse_args()

    names = load_names(args.names) if args.names else {}
    roots = DEFAULT_ROOTS if not args.root else {
        f"custom{i}": r for i, r in enumerate(args.root)}
    os.makedirs(args.out, exist_ok=True)

    per_source = {}
    for label, root in roots.items():
        if not os.path.isdir(root):
            print(f"[WARN] missing root {label}: {root}", file=sys.stderr)
            continue
        slots, files, bufs = scan_root(label, root)
        per_source[label] = {"root": root, "slots": slots,
                             "files": files, "bufs": bufs}
        print(f"{label}: {len(files)} files, {len(slots)} filled slots, "
              f"{len({s['monster_id'] for s in slots})} distinct IDs")

        with open(os.path.join(args.out, f"{label}_formations.csv"), "w",
                  newline="") as f:
            w = csv.writer(f)
            w.writerow(["battle_id", "file", "slot", "raw_hex",
                        "monster_id", "variant"])
            for s in sorted(slots, key=lambda x: (x["file"], x["slot"])):
                w.writerow([s["battle_id"], s["file"], s["slot"],
                            f"0x{s['raw']:04X}", s["monster_id"], s["variant"]])
        with open(os.path.join(args.out, f"{label}_files.csv"), "w",
                  newline="") as f:
            w = csv.DictWriter(f, fieldnames=list(files[0].keys()))
            w.writeheader()
            for r in sorted(files, key=lambda x: x["file"]):
                w.writerow(r)

    if not per_source:
        sys.exit("no sources scanned")

    sets = {lbl: {s["monster_id"] for s in d["slots"]}
            for lbl, d in per_source.items()}
    labels = list(sets)
    base = sets[labels[0]]
    agreement = {lbl: {"n_ids": len(s), "identical_to_base": s == base,
                       "only_here": sorted(s - base),
                       "missing_vs_base": sorted(base - s)}
                 for lbl, s in sets.items()}

    union = sorted(set().union(*sets.values()))
    used = [i for i in union if i <= MONSTER_ID_MAX]
    unused = [i for i in range(MONSTER_ID_MAX + 1) if i not in set(union)]
    above = [i for i in union if i > MONSTER_ID_MAX]

    primary = per_source[labels[0]]
    by_id = defaultdict(lambda: {"count": 0, "variants": set(),
                                 "battles": set()})
    for s in primary["slots"]:
        e = by_id[s["monster_id"]]
        e["count"] += 1
        e["variants"].add(s["variant"])
        e["battles"].add(s["battle_id"])
    multiform = {str(k): sorted(v["variants"]) for k, v in by_id.items()
                 if len(v["variants"]) > 1}
    variant_hist = defaultdict(int)
    for v in by_id.values():
        for n in v["variants"]:
            variant_hist[n] += 1

    # heuristic: formation-encoded u16 outside chunk2, on the primary source
    oh = outside_hits(primary["bufs"], unused + above)
    outside = {str(k): dict(v) for k, v in sorted(oh.items())}

    anomalies = []
    for lbl, d in per_source.items():
        for r in d["files"]:
            if r["flags"]:
                anomalies.append({"source": lbl, **r})
    empty_form = [r["file"] for r in primary["files"]
                  if r["chunk2_len"] >= FORMATION_CANON_LEN
                  and r["n_filled_slots"] == 0]

    census = {
        "generated_by": "research_tools/BattleMap/mon_formation_census.py",
        "date": "2026-09-15",
        "lane": "Jarvis-DEVIN leva 5 (work/_mon_formations)",
        "kernel_id_space": "0..365 (monster1 0-100, monster2 101-180, "
                           "monster3 181-365; stride 128B)",
        "sources": {lbl: {"root": d["root"], "files": len(d["files"]),
                          "filled_slots": len(d["slots"]),
                          "distinct_ids": len(sets[lbl])}
                    for lbl, d in per_source.items()},
        "cross_source_agreement": agreement,
        "used_ids": used,
        "unused_ids": unused,
        "unused_named": {str(i): names.get(i, "<no dictionary name>")
                         for i in unused},
        "ids_above_kernel_range": above,
        "n_used": len(used),
        "n_unused": len(unused),
        "multiform_ids": multiform,
        "variant_nibble_histogram": {str(k): v for k, v in
                                     sorted(variant_hist.items())},
        "heuristic_outside_chunk2_slot_encoded_u16": {
            "note": "u16 cells == 0x1000|id outside the formation chunk; "
                    "byte-pattern hint only (ATEL bytecode/other chunks can "
                    "hold arbitrary u16s) — NOT promoted to 'used'",
            "hits": outside,
        },
        "battles_with_all_empty_slots": sorted(empty_form),
        "per_id": {str(k): {"name": names.get(k, "<no dictionary name>"),
                           "slots": v["count"],
                           "variants": sorted(v["variants"]),
                           "n_battles": len(v["battles"]),
                           "battles": sorted(v["battles"])}
                   for k, v in sorted(by_id.items())},
        "files_with_flags": len(anomalies),
        "anomalies": anomalies,
    }
    with open(os.path.join(args.out, "census.json"), "w") as f:
        json.dump(census, f, indent=1, ensure_ascii=False)

    print(f"\nused: {len(used)} / {MONSTER_ID_MAX + 1}  "
          f"unused: {len(unused)}  above-range: {len(above)}")
    print(f"unused IDs: {unused}")
    print(f"multi-form IDs: {sorted(int(k) for k in multiform)}")
    print(f"variant histogram (nibble -> #IDs): "
          f"{dict(sorted(variant_hist.items()))}")
    print(f"outside-chunk2 hits for unused IDs: "
          f"{ {k: sum(v.values()) for k, v in outside.items()} }")
    print(f"all-empty formations: {len(empty_form)} -> {sorted(empty_form)}")
    print(f"flagged files: {len(anomalies)}")
    print(f"agreement vs {labels[0]}: "
          f"{all(a['identical_to_base'] for a in agreement.values())}")
    print(f"wrote {args.out}")


if __name__ == "__main__":
    main()
