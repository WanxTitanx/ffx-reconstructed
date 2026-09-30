#!/usr/bin/env python3
# ── ep_bounds_audit.py — corpus-wide bounds audit of the two unchecked
#    ATEL indexers (epTable[ev], workerOffTable[workerIdx]) ──────────────
#
# Lane: Jarvis-MAP-EPTABLE (2026-09-18). Stdlib only, no repo deps.
#
# Bounds the two indices proven unclamped in
# docs/reverse/FFX_MENUSCRIPT_TAIL_2026-09-18.md §Q4:
#
#   *result(workerCtx) = scriptBase + u32[scriptBase+0x38 + 4*workerIdx]
#        FFX_FieldActor_InitStateBlock @0x862C75  — workerOffTable[workerIdx]
#        never checked vs workerCount (u16 @ scriptBase+0x34)
#   resumePC = scriptBase + codeStart + u32[scriptBase+funcTableOff + 4*ev]
#        FFX_FieldActor_InitPriorityNode @0x869152 — epTable[ev]
#        never checked vs funcCount (u16 @ workerDesc+0x08)
#
# Request → node field remap (FFX_MsgQueue_ResolveRequests @0x797D60 ->
# FFX_Btl_UI_QueueResolvedMenuActorNode @0x86E970 ->
# FFX_FieldActor_RequeuePriorityNode @0x86E990, instruction-verified):
#   node+8  ev        = walk out  = map[subIdx]  (u16; -1/0xFFFF filtered)
#   node+16 workerIdx = LOBYTE(*walkRet) = secRec.slotBase & 0xFF
#                       (movzx byte [ebx] @0x797F79 -> v28[7] -> node+16
#                       via a1[7] @0x86EA66)
#   node+18 scriptSlot= lane word (ctx2) / actorData+0xDF5 (ctx3) / 0 (ctx4)
#   node+20 ctxSlot   = request type (2/3/4)         (v28[5] = RequestList[4i])
# Non-menu producers (REQ ops J-N @0x867624, QueuePayloadNodeIfAbsent,
# QueueIndexedScenarioNodes, QueueDefaultTableNode, AiGoalCheck) build only
# req[0..4]: node+16/18/20 are UNINITIALIZED STACK whenever
# AtelCurCtrlWork[126] != 0 (always true inside script execution).
#
# Blob <-> bound-script pairs (all decompile-verified this lane):
#   ctx2 lane0: jppc/battle/btl/X.bin      blob=ptr[1]   script=ptr[0] (chunk0)
#               — ctx2 scriptTable[0]=scriptTable[1]=pack+0x30 for BOTH lanes
#               (RegisterScriptInChannel x2 @0x7832DA/0x7832EC push the same
#               g_EncounterScriptSectionPtr value, once via live rec0+0x08)
#   ctx2 lane1: new_*/battle/btl/X.ftc     NOT a blob source — FTCX font-
#               texture chunks; no engine path walks a .ftc as MsgBlob.
#               Scanned here only as exploratory data (results = misparse).
#   ctx3      : jppc/battle/mon/_mNNN/mNNN.bin  blob=ptr[1]  script=ptr[0]
#               (actor blob = actorData+0xF7C; script slot = actorData+0xDF5)
#   ctx4      : jppc/event/obj/**/*.ebp    blob=chunk1 (u32@+8)  script=chunk0
#               (EV01 text-index chunk -> g_FFX_EventJpTextChunkPtr; chunk0
#               ATEL -> g_FFX_EventScriptChunkPtr, LoadEv01AndRegisterScript
#               @0x797560). TYPE CONFUSION: engine really walks chunk1 with
#               MsgBlob grammar for type-4 requests, but chunk1 is the JP
#               message-offset table, not an authored MsgBlob — audited
#               values are what the type-confused walk WOULD produce.
#
# Request-type -> bound script map (PROVEN 2026-09-18, ResolveRequests
# disasm): type2->ctx2 (pack script lane), type3->ctx3 (actor script),
# type4->ctx4 (EV01 script). workerIdx/ev bound vs funcCount(slotBase&0xFF)
# of the bound script. Type-4 is a FALLBACK lane: pushed only by
# BuildMenuTreeForAction after type-2/3 requests; dead in shipped flow.
#
# For every (item,subIdx) pair that WalkSectionItemIndex could resolve
# (secIdx[item]!=0xFF, subIdx<n, map!=0xFFFF) this audits:
#   workerIdx = slotBase & 0xFF  vs script workerCount        -> widx_oob
#   ev        = map[subIdx]      vs funcCount(workerIdx)      -> ev_oob
# Also flags sections not referenced by any item (unreachable) and .ftc
# walks that read past the file buffer (WALK_PAST_EOF — adjacent heap).
#
# Output: docs/reverse/data/wave15/ep_bounds_audit.csv
#   section rows: one per (file,section) with max indices + oob counts
#   summary rows: corpus totals, distributions, worst offenders
#
# Usage:
#   ep_bounds_audit.py [--root DIR] [--out CSV] [--verbose]
# ────────────────────────────────────────────────────────────────────────────
import argparse
import csv
import glob
import os
import struct
import sys

ROOTS = ["/mnt/nvme-xpg/ffx_ps2/ffx/master",
         "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master"]
OUT = os.path.join(os.path.dirname(__file__), "..", "..",
                   "docs", "reverse", "data", "wave15",
                   "ep_bounds_audit.csv")
# lane-1 item range bound by FFX_Atel_SetupMenuBlobScripts @0x7977D1 (41..55)
LANE1_ITEMS = range(41, 56)


def u16(b, o):
    return struct.unpack_from("<H", b, o)[0]


def u32(b, o):
    return struct.unpack_from("<I", b, o)[0]


# ── ATEL chunk0 (script) parse ───────────────────────────────────────────────
def parse_atel(b, off, limit):
    """ATEL script at b[off:limit]. Returns {workerCount, workers[{funcCount,
    funcTableOff, epMaxOff}], codeStart, codeLen} or None."""
    if off <= 0 or off + 0x3C > limit:
        return None
    wcount = u16(b, off + 0x34)
    code_start = u32(b, off + 0x30)
    code_len = u32(b, off + 0x00)
    if wcount == 0 or wcount > 0x400:
        return None
    workers = []
    for w in range(wcount):
        wo = u32(b, off + 0x38 + 4 * w)
        if wo == 0 or off + wo + 0x34 > limit:
            workers.append({"funcCount": 0, "funcTableOff": 0, "bad": True})
            continue
        desc = off + wo
        fc = u16(b, desc + 0x08)
        ft = u32(b, desc + 0x20)
        # sanity: funcTable must sit inside the script region (chunk or file)
        bad = ft == 0 or off + ft + 4 * fc > len(b)
        workers.append({"funcCount": fc, "funcTableOff": ft, "bad": bad})
    return {"workerCount": wcount, "workers": workers,
            "codeStart": code_start, "codeLen": code_len}


# ── MsgBlob parse (grammar of FFX_MsgBlob_WalkSectionItemIndex @0x797420) ────
def parse_blob(b, base, limit=None):
    """Returns {lane1Base, count, secIdx, secRecs[{slotBase,mapOff}],
    sections[{n,map}], walk_oob} or None. `walk_oob` counts secRec/map reads
    that would land past `limit` (the file buffer end)."""
    if limit is None:
        limit = len(b)
    if base <= 0 or base + 4 > limit:
        return None
    lane1 = b[base]
    count = b[base + 1]
    if count == 0:
        return {"lane1Base": lane1, "count": 0, "secIdx": [],
                "secRecs": [], "sections": [], "walk_oob": 0}
    if count > 200 or base + 2 + count > limit:
        return None
    sec_idx = list(b[base + 2: base + 2 + count])
    tab0 = (count + 1) // 2
    nsec = max([s for s in sec_idx if s != 0xFF], default=-1) + 1
    recs, secs, oob = [], [], 0
    for i in range(nsec):
        v6 = tab0 + 2 * i
        roff = base + 4 + 2 * (v6 - 1)
        moff_pos = base + 4 + 2 * v6
        if roff + 2 > limit or moff_pos + 2 > limit:
            oob += 1
            recs.append({"slotBase": 0, "mapOff": 0, "past_eof": True})
            secs.append({"n": 0, "map": []})
            continue
        slot = u16(b, roff)
        moff = u16(b, moff_pos)
        n = 0
        mp = []
        if moff and base + moff + 2 <= limit:
            n = u16(b, base + moff)
            if base + moff + 2 + 2 * n <= limit:
                mp = [u16(b, base + moff + 2 + 2 * j) for j in range(n)]
            else:
                oob += 1
                n = 0
        elif moff:
            oob += 1
        recs.append({"slotBase": slot, "mapOff": moff, "past_eof": False})
        secs.append({"n": n, "map": mp})
    return {"lane1Base": lane1, "count": count, "secIdx": sec_idx,
            "secRecs": recs, "sections": secs, "walk_oob": oob}


def pack_ptrs(b):
    """Signature-8 pack: u32 ptr table @+4. Returns list of 11 u32s."""
    if len(b) < 0x30 or u32(b, 0) != 8:
        return None
    return [u32(b, 4 + 4 * i) for i in range(11)]


# ── per-blob audit ───────────────────────────────────────────────────────────
def audit_blob(blob, atel, kind):
    """Yield per-section row dicts. `blob` from parse_blob, `atel` from
    parse_atel (None allowed -> marks everything unverifiable)."""
    rows = []
    if not blob or not blob["secRecs"]:
        return rows
    wcount = atel["workerCount"] if atel else -1
    # which items reference each section
    refs = {}
    for item, s in enumerate(blob["secIdx"]):
        if s != 0xFF:
            refs.setdefault(s, []).append(item)
    for s, rec in enumerate(blob["secRecs"]):
        sec = blob["sections"][s]
        widx = rec["slotBase"] & 0xFF
        items = refs.get(s, [])
        widx_oob = (wcount >= 0 and widx >= wcount)
        fc = -1
        if atel and not widx_oob and widx < len(atel["workers"]):
            fc = atel["workers"][widx]["funcCount"]
        valid = [m for m in sec["map"] if m != 0xFFFF]
        oob_vals = [m for m in valid if fc >= 0 and m >= fc]
        rows.append({
            "sec": s, "items": ";".join(str(i) for i in items),
            "n_items": len(items), "referenced": bool(items),
            "slotBase": rec["slotBase"], "workerIdx": widx,
            "workerCount": wcount, "widx_oob": widx_oob,
            "n_map": sec["n"], "n_valid": len(valid),
            "max_ev": max(valid) if valid else -1,
            "funcCount": fc, "ev_oob_count": len(oob_vals),
            "ev_oob_vals": ";".join(str(v) for v in sorted(set(oob_vals))),
            "past_eof": rec.get("past_eof", False)})
    return rows


def audit_file(path, blob_off, script_off, script_lim, kind, locale,
               blob_limit=None):
    """Open file, audit blob<->script pair, return (rows, meta)."""
    try:
        b = open(path, "rb").read()
    except OSError:
        return [], {"file": path, "err": "unreadable"}
    meta = {"file": path, "kind": kind, "locale": locale, "size": len(b)}
    lim = blob_limit if blob_limit is not None else len(b)
    blob = parse_blob(b, blob_off, lim)
    atel = parse_atel(b, script_off, script_lim) if script_off else None
    meta["blob_ok"] = bool(blob)
    meta["atel_ok"] = bool(atel)
    meta["walk_oob"] = blob["walk_oob"] if blob else 0
    meta["workerCount"] = atel["workerCount"] if atel else ""
    if not blob or not blob["secRecs"]:
        return [], meta
    rows = audit_blob(blob, atel, kind)
    for r in rows:
        r.update({"file": path, "kind": kind, "locale": locale})
    return rows, meta


# ── lane-1 .ftc walk simulation (items 41-55 on the raw font file) ───────────
def audit_ftc(path, pack_path, locale):
    """Simulate WalkSectionItemIndex on the FTCX font blob for the lane-1
    item range; pair with the same-name pack's chunk0. Returns
    (rows, meta)."""
    try:
        b = open(path, "rb").read()
    except OSError:
        return [], {"file": path, "err": "unreadable"}
    meta = {"file": path, "kind": "ftc_lane1", "locale": locale,
            "size": len(b)}
    atel = None
    if pack_path and os.path.exists(pack_path):
        pb = open(pack_path, "rb").read()
        pp = pack_ptrs(pb)
        if pp:
            atel = parse_atel(pb, pp[0], pp[1])
            meta["pack"] = pack_path
            meta["workerCount"] = atel["workerCount"] if atel else ""
    meta["atel_ok"] = bool(atel)
    rows = []
    if len(b) < 4:
        return rows, meta
    count = b[1]
    tab0 = (count + 1) // 2
    meta["ftc_count_byte"] = count
    for item in LANE1_ITEMS:
        if item >= count or 2 + item >= len(b):
            continue
        s = b[2 + item]
        if s == 0xFF:
            continue
        v6 = tab0 + 2 * s
        roff = 4 + 2 * (v6 - 1)
        moff_pos = 4 + 2 * v6
        past = roff + 2 > len(b) or moff_pos + 2 > len(b)
        slot = u16(b, roff) if roff + 2 <= len(b) else -1
        moff = u16(b, moff_pos) if moff_pos + 2 <= len(b) else -1
        widx = slot & 0xFF if slot >= 0 else -1
        widx_oob = (atel and widx >= 0 and widx >= atel["workerCount"])
        fc = -1
        if atel and not widx_oob and 0 <= widx < len(atel["workers"]):
            fc = atel["workers"][widx]["funcCount"]
        n = u16(b, moff) if 0 < moff <= len(b) - 2 else 0
        valid = []
        if n and moff + 2 + 2 * n <= len(b):
            valid = [u16(b, moff + 2 + 2 * j) for j in range(n)
                     if u16(b, moff + 2 + 2 * j) != 0xFFFF]
        oob_vals = [m for m in valid if fc >= 0 and m >= fc]
        rows.append({
            "sec": s, "items": str(item), "n_items": 1,
            "referenced": True, "slotBase": slot, "workerIdx": widx,
            "workerCount": atel["workerCount"] if atel else -1,
            "widx_oob": bool(widx_oob), "n_map": n,
            "n_valid": len(valid),
            "max_ev": max(valid) if valid else -1, "funcCount": fc,
            "ev_oob_count": len(oob_vals),
            "ev_oob_vals": ";".join(str(v) for v in sorted(set(oob_vals))),
            "past_eof": past, "file": path, "kind": "ftc_lane1",
            "locale": locale})
    return rows, meta


# ── corpus drivers ───────────────────────────────────────────────────────────
def packs(root):
    for loc in ("jppc", "uspc", "inpc"):
        for p in sorted(glob.glob(os.path.join(
                root, loc, "battle", "btl", "**", "*.bin"), recursive=True)):
            yield p, loc


def mons(root):
    for loc in ("jppc", "uspc", "inpc"):
        for p in sorted(glob.glob(os.path.join(
                root, loc, "battle", "mon", "**", "*.bin"), recursive=True)):
            yield p, loc


def ebps(root):
    for loc in ("jppc", "uspc", "inpc", "new_jppc", "new_uspc", "new_depc",
                "new_frpc", "new_itpc", "new_sppc", "new_krpc", "new_chpc"):
        for p in sorted(glob.glob(os.path.join(
                root, loc, "event", "obj", "**", "*.ebp"), recursive=True)):
            yield p, loc


def ftcs(root):
    for loc in ("new_jppc", "new_uspc", "new_depc", "new_frpc", "new_itpc",
                "new_sppc", "new_krpc", "new_chpc"):
        for p in sorted(glob.glob(os.path.join(
                root, loc, "battle", "btl", "**", "*.ftc"), recursive=True)):
            yield p, loc


def main(argv=None):
    ap = argparse.ArgumentParser(
        description="FFX epTable[ev]/workerOffTable[workerIdx] corpus audit")
    ap.add_argument("--root", action="append", default=[])
    ap.add_argument("--out", default=OUT)
    ap.add_argument("--verbose", action="store_true")
    a = ap.parse_args(argv)
    roots = [r for r in (a.root or ROOTS) if os.path.isdir(r)]
    if not roots:
        print("no corpus root found"); return 2

    seen = set()
    all_rows, metas = [], []
    # A) lane-0 encounter packs: blob=ptr[1], script=ptr[0]..ptr[1]
    for root in roots:
        for p, loc in packs(root):
            key = ("pack", loc, os.path.basename(p))
            if key in seen:
                continue
            seen.add(key)
            b = open(p, "rb").read()
            pp = pack_ptrs(b)
            if not pp or not pp[1]:
                metas.append({"file": p, "kind": "pack_lane0",
                              "locale": loc, "blob_ok": False})
                continue
            lim = pp[2] if pp[2] else len(b)
            rows, meta = audit_file(p, pp[1], pp[0], pp[1], "pack_lane0",
                                    loc, blob_limit=lim)
            all_rows += rows
            metas.append(meta)
    # B) lane-1 .ftc font blobs -> same-name pack chunk0
    for root in roots:
        for p, loc in ftcs(root):
            key = ("ftc", loc, os.path.basename(p))
            if key in seen:
                continue
            seen.add(key)
            name = os.path.splitext(os.path.basename(p))[0]
            pack_path = None
            for r in roots:
                cand = os.path.join(r, "jppc", "battle", "btl", name,
                                    name + ".bin")
                if os.path.exists(cand):
                    pack_path = cand
                    break
            rows, meta = audit_ftc(p, pack_path, loc)
            all_rows += rows
            metas.append(meta)
    # C) monster actor packs: blob=ptr[1], script=ptr[0]..ptr[1]
    for root in roots:
        for p, loc in mons(root):
            key = ("mon", loc, os.path.basename(p))
            if key in seen:
                continue
            seen.add(key)
            b = open(p, "rb").read()
            pp = pack_ptrs(b)
            if not pp or not pp[1]:
                metas.append({"file": p, "kind": "mon_actor",
                              "locale": loc, "blob_ok": False})
                continue
            lim = pp[2] if pp[2] else len(b)
            rows, meta = audit_file(p, pp[1], pp[0], pp[1], "mon_actor",
                                    loc, blob_limit=lim)
            all_rows += rows
            metas.append(meta)
    # D) EV01 .ebp: blob=chunk1 (u32@+8), script=chunk0 (u32@+4)
    for root in roots:
        for p, loc in ebps(root):
            key = ("ev01", loc, os.path.basename(p))
            if key in seen:
                continue
            seen.add(key)
            b = open(p, "rb").read()
            if len(b) < 0x10 or b[:4] != b"EV01":
                metas.append({"file": p, "kind": "ev01_chunk1",
                              "locale": loc, "blob_ok": False})
                continue
            c0, c1 = u32(b, 4), u32(b, 8)
            nxt = u32(b, 12)
            lim = nxt if (nxt and nxt != 0xFFFFFFFF and nxt > c1) else len(b)
            rows, meta = audit_file(p, c1, c0, c1, "ev01_chunk1",
                                    loc, blob_limit=lim)
            all_rows += rows
            metas.append(meta)

    # ── write CSV ────────────────────────────────────────────────────────────
    os.makedirs(os.path.dirname(a.out), exist_ok=True)
    fields = ["kind", "locale", "file", "sec", "items", "n_items",
              "referenced", "slotBase", "workerIdx", "workerCount",
              "widx_oob", "n_map", "n_valid", "max_ev", "funcCount",
              "ev_oob_count", "ev_oob_vals", "past_eof"]
    with open(a.out, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fields)
        w.writeheader()
        for r in all_rows:
            w.writerow({k: r.get(k, "") for k in fields})

        # ── summary block ────────────────────────────────────────────────────
        wcsv = csv.writer(f)
        wcsv.writerow([])
        wcsv.writerow(["=== SUMMARY ===", "", "", "", "", "", "", "", "", "",
                       "", "", "", "", "", "", "", ""])
        by_kind = {}
        for m in metas:
            k = m.get("kind", "?")
            by_kind.setdefault(k, {"files": 0, "blob_ok": 0,
                                   "atel_ok": 0, "walk_oob": 0})
            by_kind[k]["files"] += 1
            by_kind[k]["blob_ok"] += 1 if m.get("blob_ok") else 0
            by_kind[k]["atel_ok"] += 1 if m.get("atel_ok") else 0
            by_kind[k]["walk_oob"] += m.get("walk_oob", 0) or 0
        wcsv.writerow(["kind", "files", "blob_parsed", "atel_parsed",
                       "walk_oob_reads"])
        for k, v in sorted(by_kind.items()):
            wcsv.writerow([k, v["files"], v["blob_ok"], v["atel_ok"],
                           v["walk_oob"]])
        wcsv.writerow([])
        ref = [r for r in all_rows if r["referenced"]]
        wcsv.writerow(["sections_total", len(all_rows), "",
                       "sections_referenced", len(ref)])
        wcsv.writerow(["max_workerIdx", max((r["workerIdx"] for r in all_rows),
                                            default=-1)])
        wcsv.writerow(["max_ev", max((r["max_ev"] for r in all_rows),
                                     default=-1)])
        wcsv.writerow(["widx_oob_sections",
                       sum(1 for r in all_rows if r["widx_oob"]),
                       "", "widx_oob_referenced",
                       sum(1 for r in ref if r["widx_oob"])])
        wcsv.writerow(["ev_oob_sections",
                       sum(1 for r in all_rows if r["ev_oob_count"]),
                       "", "ev_oob_referenced",
                       sum(1 for r in ref if r["ev_oob_count"])])
        wcsv.writerow(["ev_oob_values_total",
                       sum(r["ev_oob_count"] for r in all_rows)])
        wcsv.writerow([])
        wcsv.writerow(["=== VIOLATIONS (any) ==="])
        for r in all_rows:
            if r["widx_oob"] or r["ev_oob_count"] or r["past_eof"]:
                wcsv.writerow([r["kind"], r["locale"],
                               os.path.basename(os.path.dirname(r["file"]))
                               + "/" + os.path.basename(r["file"]),
                               "sec", r["sec"], "items", r["items"],
                               "widx", r["workerIdx"], "wc",
                               r["workerCount"], "max_ev", r["max_ev"],
                               "fc", r["funcCount"], "oob_ev",
                               r["ev_oob_vals"], "past_eof",
                               r["past_eof"]])
        wcsv.writerow([])
        wcsv.writerow(["=== EV DISTRIBUTION (referenced sections, "
                       "map values) ==="])
        from collections import Counter
        dist = Counter()
        for r in ref:
            if r["n_valid"]:
                dist[r["max_ev"]] += 1
        for v in sorted(dist):
            wcsv.writerow(["max_ev", v, "sections", dist[v]])

    n_files = len(metas)
    n_viol = sum(1 for r in all_rows
                 if r["widx_oob"] or r["ev_oob_count"])
    print("audited %d blob sources -> %d section rows" % (n_files,
                                                        len(all_rows)))
    print("violating sections (widx_oob or ev_oob): %d" % n_viol)
    print("wrote %s" % a.out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
