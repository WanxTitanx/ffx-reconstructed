#!/usr/bin/env python3
# ── menuscript_menublob.py — FFX "menu blob" (MsgBlob) parser + binding dump ──
#
# Lane: Jarvis-MENUSCRIPT-OPS (2026-09-18). Stdlib only.
#
# Implements the decompiler-proven record grammar of the "menu script blob"
# walked by FFX_MsgBlob_WalkSectionItemIndex @0x797420 and consumed by
# FFX_MsgBlob_LookupSourceEntry @0x7985A0 / FFX_Atel_SetupMenuBlobScripts
# @0x7976B0 (the "~99 bindings").
#
#   Blob layout (encounter-pack section 8; also actor blob, EV01 text chunk):
#     +0x00  u8   lane1Base   ("g_BtlMsgBlobRec0" byte — slot count of lane 0;
#                            lane-1 item slots get +lane1Base)
#     +0x01  u8   count       item-id space (u8)
#     +0x02  u8[count]        itemId -> section index (0xFF = absent)
#     pad to u16 boundary
#     +4     u16 secRec[i]    i in [(count+1)/2 .. ) — WAIT: see walk below.
#
# Walk (exact port of the decompile):
#   s   = secIdx[itemId];  if s == 0xFF or itemId >= count -> miss
#   v6  = (count+1)//2 + 2*s          (u16 index into the u16 stream at +4)
#   mapOff = i16(blob + 4 + 2*v6)     -> {u16 n; u16 map[n]} at blob+mapOff
#   ret = blob + 2*v6 + 2 = &stream[v6-1]  — i.e. the u16 BEFORE mapOff.
#   So section record s = {u16 slotBase @stream[tab0-1+2s],
#                          u16 mapOff @stream[tab0+2s]} — contiguous 4B recs
#   starting at stream[tab0-1]; callers read rec[0] = LOBYTE(slotBase)
#   ("pad_0000[0]") as the per-section slot base.
#   out = (ioIn < n && map[ioIn] != 0xFFFF) ? map[ioIn] : -1
#
#   slotIndex = laneBase + LOBYTE(secRec.slotBase)
#     laneBase = 0 for lane 0; = blob[0] (lane1Base) for lane 1
#     (LookupSourceEntry case 2: *a4 = 0 / movsx byte g_BtlMsgBlobRec0)
#
# The blob pointer table (BSS, filled per-encounter):
#   laneRec base 0x112A994 stride 0x20: lane n blob ptr = *(0x112A994 + 0x20*n)
#   lane0 = encBlob+hdr[+8] (encounter-pack section 8)
#   lane1 = same encBlob+hdr[+8] via defaults+0x10 (0x112A9B4) — SAME blob.
#
# Usage:
#   menuscript_menublob.py BLOBFILE [--dump]
#   menuscript_menublob.py --pack BTLPACK.bin          (reads hdr +8 offset)
#   menuscript_menublob.py --bindings BTLPACK.bin      (SetupMenuBlobScripts
#                                                     item->slot->scriptId)
import struct
import sys


def u16(b, o):
    return struct.unpack_from("<H", b, o)[0]


def parse_blob(b, base=0):
    """Return dict {lane1Base, count, secIdx[], secRecs[], sections[]}.

    secRecs[i] = {u16 mapOff, u16 slotBase} read at blob+4+2*((count+1)//2+2i).
    sections[i] = {n, map[]} at blob+mapOff.
    """
    lane1 = b[base]
    count = b[base + 1]
    secIdx = list(b[base + 2: base + 2 + count])
    tab0 = (count + 1) // 2            # first u16 index of section records
    nsec = max([s for s in secIdx if s != 0xFF], default=-1) + 1
    secRecs, sections = [], []
    for i in range(nsec):
        v6 = tab0 + 2 * i
        # rec = {u16 slotBase @stream[v6-1], u16 mapOff @stream[v6]}
        slotBase = u16(b, base + 4 + 2 * (v6 - 1))
        mapOff = u16(b, base + 4 + 2 * v6)
        n = u16(b, base + mapOff) if mapOff else 0
        mp = [u16(b, base + mapOff + 2 + 2 * j) for j in range(n)] if n else []
        secRecs.append({"mapOff": mapOff, "slotBase": slotBase})
        sections.append({"n": n, "map": mp})
    return {"lane1Base": lane1, "count": count, "secIdx": secIdx,
            "secRecs": secRecs, "sections": sections, "base": base}


def walk(blob, item_id, io_in=0):
    """Port of FFX_MsgBlob_WalkSectionItemIndex. Returns (rec_slotbase,
    out_idx) or None (miss)."""
    lane1 = blob["lane1Base"]
    count = blob["count"]
    if item_id >= count:
        return None
    s = blob["secIdx"][item_id]
    if s == 0xFF:
        return None
    rec = blob["secRecs"][s]
    sec = blob["sections"][s]
    out = -1
    if io_in < sec["n"] and sec["map"][io_in] != 0xFFFF:
        out = sec["map"][io_in]
    return {"section": s, "slotBaseLo": rec["slotBase"] & 0xFF,
            "slotBase": rec["slotBase"], "mapOff": rec["mapOff"],
            "out": out}


def pack_menu_blob(path):
    """Load a battle pack, return (bytes, base) of section-8 menu blob."""
    b = open(path, "rb").read()
    off = struct.unpack_from("<I", b, 8)[0]
    return b, off


# FFX_Atel_SetupMenuBlobScripts(ctx2) static binding program (decompile-proven
# @0x7976B0): (lane, itemLo, itemHi, scriptId = item - itemLo)
BIND_LOOPS = [
    (1, 41, 55),   # 15 items  -> script 0..14   lane 1 (base = blob[0])
    (0, 5, 32),    # 28 items  -> script 0..27   lane 0 (base 0)
    (0, 79, 106),  # 28 items  -> script 0..27   lane 0
    (0, 109, 136), # 28 items  -> script 0..27   lane 0
]
# hardcoded FFX_Atel_SetMenuBlobByte(2, 0, itemId, scriptId)
BIND_FIXED = [(0, 33, 28), (0, 34, 29), (0, 35, 30), (0, 37, 14),
              (0, 38, 15), (0, 39, 16), (0, 40, 17)]
# ctx3 (monster AI): LookupSourceEntry(3, i+20, msgId, &out) x8 for msgId in
# (61, 4, 64) -> script id = i+20
BIND_CTX3 = [(3, 20, 27, m) for m in (61, 4, 64)]


def bindings(blob):
    """Yield (lane, itemId, section, slotBaseLo, slotIndex, scriptId)."""
    out = []
    for lane, lo, hi in BIND_LOOPS:
        lane_base = blob["lane1Base"] if lane > 0 else 0
        for item in range(lo, hi + 1):
            w = walk(blob, item)
            if w is None:
                out.append((lane, item, None, None, None, item - lo))
            else:
                slot = lane_base + w["slotBaseLo"]
                out.append((lane, item, w["section"], w["slotBaseLo"],
                            slot, item - lo))
    for lane, item, sid in BIND_FIXED:
        lane_base = blob["lane1Base"] if lane > 0 else 0
        w = walk(blob, item)
        if w is None:
            out.append((lane, item, None, None, None, sid))
        else:
            out.append((lane, item, w["section"], w["slotBaseLo"],
                        lane_base + w["slotBaseLo"], sid))
    return out


def main(argv):
    if len(argv) < 2:
        print(__doc__.split("Usage:")[-1])
        return 2
    args = argv[1:]
    mode = "dump"
    if args[0] == "--pack":
        b, base = pack_menu_blob(args[1])
    elif args[0] == "--bindings":
        mode = "bindings"
        b, base = pack_menu_blob(args[1])
    else:
        b = open(args[0], "rb").read()
        base = int(args[2], 0) if len(args) > 2 else 0
    blob = parse_blob(b, base)
    print("%s @%#x: lane1Base=%d count=%d sections=%d"
          % (args[-1], base, blob["lane1Base"], blob["count"],
             len(blob["secRecs"])))
    present = [(i, s) for i, s in enumerate(blob["secIdx"]) if s != 0xFF]
    print("present items: %d -> %s"
          % (len(present), " ".join("%d:s%d" % p for p in present)))
    for i, r in enumerate(blob["secRecs"]):
        sec = blob["sections"][i]
        print("  sec%d mapOff=%#x slotBase=%d (lo %d) n=%d map=%s"
              % (i, r["mapOff"], r["slotBase"], r["slotBase"] & 0xFF,
                 sec["n"], sec["map"]))
    if mode == "bindings":
        print("item bindings (lane,item,sec,slotBaseLo,slot,scriptId):")
        for row in bindings(blob):
            print("  L%d item=%-3d sec=%-4s baseLo=%-4s slot=%-4s script=%s"
                  % (row[0], row[1],
                     str(row[2]), str(row[3]), str(row[4]), row[5]))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
