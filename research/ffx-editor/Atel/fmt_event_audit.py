#!/usr/bin/env python3
# ── FFX event/script container AUDIT parser — Jarvis lane FMT-EVENT ──────────
#
# Purpose: one clean, dependency-free (stdlib-only) reader per sub-format of
# the "event/script container" family, run over the REAL corpus, dumping
# records to JSON so the atlas claims in
# docs/reverse/FFX_STRUCTURE_COMPLETE_2026-09-14.md can be verified
# byte-for-byte. Research tool — does NOT ship in the editor.
#
# Sub-formats covered (family = event/script containers):
#   1. *.ebp            EV01 container: 0x40 header + u32 offset table +
#                       0xFFFFFFFF sentinel; chunks 0..4 (ATEL / JP text /
#                       SeSep / FTCX-or-font-desc / EN text).
#   2. *.ftc            FTCX font descriptor (64B header + desc quads) and the
#                       non-FTCX `event/obj/base.ftc` variant.
#   3. cdrom.fnd/.fid   file-name directory {u32 count; u32 offs[count+1];
#                       NUL strings} + i16[65] group bases (group 12 = event).
#   4. modulesize.bin   flat u32[] module-size table (cdidx/filesize).
#   5. *_script.bin     52×u32 slot table -> count-prefixed sections with
#                       trailing ASCII name pool (menu UI resource defs).
#      menumain.bin     raw ATEL blob (same header layout as EV01 chunk0).
#      menumain.msb     8B text records {u16 off,attr,offAlt,attr2} + strings.
#   6. *.dcp            macrodic.dcp: header offsets @0x18..0x34 -> 6 u16 tables.
#   7. evmapinfo.bin    u16[1024] LUT (0xFFFF = empty), event<->map info.
#   8. new_*pc event .bin  per-locale text-record sidecars (same 8B record).
#
# Usage:
#   python3 research_tools/Atel/fmt_event_audit.py --out work/_fmt_event
#
# Defaults are the WSL mount points used by the audit lane; every root is a
# flag so it can be pointed at any extraction.
#
# Evidence base (claims being verified):
#   docs/reverse/FFX_EVENT_EBP_FORMAT_REFERENCE_2026-06-05.md  (EV01 model)
#   docs/reverse/FFX_EVENT_SESEP_*_2026-06-06.md               (chunk2)
#   docs/reverse/FFX_EVENT_FTCX_CHUNK3_RE_2026-06-05.md        (chunk3)
#   docs/reverse/FFX_EBP_CHUNK_READERS_2026-09-15.md           (loader map)
#   docs/reverse/FFX_EBP_EDGE_CASES_2026-09-15.md              (text records)
#   docs/reverse/FFX_SCENEID_PPP_RESIDUALS_2026-09-15.md       (cdrom.fnd 402x18)
#   docs/reverse/FFX_MENU_FORMATS_PS2_2026-08-01.md            (menu bins)
#   FFX_STRUCTURE_COMPLETE_2026-09-14.md §7.1/§11.x            (FTCX fields)

import argparse
import glob
import json
import os
import re
import struct
import sys
from collections import Counter

EV01_MAGIC = 0x31305645          # "EV01" little-endian
FTCX_MAGIC = 0x58435446          # "FTCX" little-endian
SESEP_SIG = b"SeSep   "          # 8-byte record signature


def u16(b, o):
    return struct.unpack_from("<H", b, o)[0]


def u32(b, o):
    return struct.unpack_from("<I", b, o)[0]


# ════════════════════════════════════════════════════════════════════════════
# 1. EV01 (.ebp)
# ════════════════════════════════════════════════════════════════════════════

def parse_ev01_table(data):
    """Return (slots, eof, sentinel_pos) or None.

    slots = chunk start offsets (0 = absent); eof = value before sentinel
    (should equal filesize); sentinel_pos = byte offset of 0xFFFFFFFF.
    """
    if len(data) < 0x44 or u32(data, 0) != EV01_MAGIC:
        return None
    offs = []
    pos = 4
    while pos + 4 <= 0x44:                       # table bounded by header 0x40
        v = u32(data, pos)
        offs.append(v)
        pos += 4
        if v == 0xFFFFFFFF:
            break
    if not offs or offs[-1] != 0xFFFFFFFF:
        return None
    entries = offs[:-1]                           # chunk slots + EOF
    if not entries:
        return None
    return entries[:-1], entries[-1], pos - 4


def ev01_chunks(data, slots, eof):
    """Slice chunks; chunk[i] = data[start .. next-nonzero-start | eof]."""
    out = []
    for i, s in enumerate(slots):
        if s == 0:
            out.append(None)
            continue
        end = next((slots[j] for j in range(i + 1, len(slots)) if slots[j] != 0),
                   eof)
        out.append(data[s:min(end, len(data))])
    return out


def sniff_chunk(i, c):
    """Content-sniff a chunk: return role label + detail dict."""
    if c is None:
        return "absent", {}
    if len(c) == 0:
        return "empty", {}
    if c[:4] == b"FTCX":
        return "ftcx", parse_ftcx(c, embedded=True)
    if i == 0:
        # ATEL vendor blob: codeLen@0, totalLen@0x10, scriptStart@0x30
        d = {}
        if len(c) >= 0x3A:
            d = {"codeLen": u32(c, 0), "totalLen": u32(c, 0x10),
                 "scriptStart": u32(c, 0x30), "workerCount": u16(c, 0x36)}
        return "atel", d
    if c[2:4] == b"\x00\x40" and len(c) > 0x20 and c[0x20:0x28] == b"SeSep   ":
        return "sesep", parse_sesep(c)
    if i == 2:
        # slot2 has 3 observed layouts: const4000 SeSep, a nested offset-table
        # sub-container (soundtest/test13 — u32 entries then 0xFFFFFFFF,
        # "SeSep   " records inside a sub-chunk), and nothing else so far.
        if u16(c, 2) == 0x4000 and len(c) > 0x20 and \
                c[0x20:0x28] == SESEP_SIG:
            return "sesep", parse_sesep(c)
        head = [u32(c, o) for o in range(0, min(0x24, len(c)), 4)]
        if head[0] == 0x40 and 0xFFFFFFFF in head[1:] \
                and b"SeSep   " in c:
            subs = head[:head.index(0xFFFFFFFF, 1)]
            return "sesep_subcontainer", {"sub_offsets": subs}
        return "unknown", {"first16": c[:16].hex()}
    if u16(c, 0) == 0x72 or u16(c, 0) == 0x73:
        # raw font descriptor (same family as event/obj/base.ftc)
        return "fontdesc", {"glyphCount?": u16(c, 0)}
    first = u16(c, 0)
    if first and first % 8 == 0 and first <= len(c):
        return "texttable", parse_text_records(c)
    return "unknown", {"first16": c[:16].hex()}


def parse_text_records(c):
    """8B records {u16 off, u16 attr, u16 offAlt, u16 attr2}; count=first/8."""
    first = u16(c, 0)
    n = first // 8
    recs = []
    diff = zero = 0
    for i in range(n):
        off, attr, offAlt, attr2 = struct.unpack_from("<HHHH", c, i * 8)
        if off != offAlt:
            diff += 1
        if off == 0 and attr == 0 and offAlt == 0 and attr2 == 0:
            zero += 1
        if len(recs) < 4:
            recs.append({"off": off, "attr": attr, "offAlt": offAlt,
                         "attr2": attr2})
    return {"records": n, "off_ne_offAlt": diff, "zero_records": zero,
            "sample": recs}


def parse_sesep(c):
    """SeSep chunk: u16 contentLen @0, u16 0x4000 @2, "SeSep   " records
    from +0x20, each {8B sig, u32 cue/se id @+8, u32 recLen @+0x0C, u8 type,
    u8 voiceCount @+0x10, u16 waveId @+0x11, cue-schedule mini-bytecode}.

    contentLen formula (FFX_EVENT_SESEP_CONTENTLEN_SOLVED, 348/348):
    X = (end_first_run & ~0xF) - 0x10 where end_first_run is the byte after
    the LAST record of the first contiguous run. RESIDUAL: 3 files
    (cdsp0200, swin0000, swin0200) carry ORPHAN records after a zero pad —
    beyond the contentLen boundary; whether the engine walker reaches them
    is OPEN (depends if it iterates by contentLen or chunk bounds).
    """
    d = {"contentLen": u16(c, 0), "const4000": u16(c, 2), "records": 0,
         "walk_ok": True}
    waves = set()

    def walk(pos):
        """Walk one contiguous record run; return (n_records, end_pos)."""
        n = 0
        while pos + 16 <= len(c) and c[pos:pos + 8] == SESEP_SIG:
            rec_len = u32(c, pos + 0x0C)
            if rec_len < 16 or pos + rec_len > len(c):
                break
            waves.add(u16(c, pos + 0x11))
            n += 1
            pos += rec_len
        return n, pos

    n, end_run = walk(0x20)
    d["records"] = n
    d["end_rec"] = end_run
    # orphan run detection: skip zero pad, look for more SeSep sigs
    probe = end_run
    while probe + 16 <= len(c) and c[probe] == 0:
        probe += 1
    d["gap_bytes"] = probe - end_run
    d["orphan_records"] = 0
    if probe + 16 <= len(c) and c[probe:probe + 8] == SESEP_SIG:
        n2, end2 = walk(probe)
        d["orphan_records"] = n2
        d["orphan_span"] = [probe, end2]
    # the run ends clean when everything after the last record is zeros
    d["walk_ok"] = all(b == 0 for b in c[end_run:])
    # contentLen covers ONLY the first contiguous run (348/348 per doc)
    d["contentLen_check"] = d["contentLen"] == ((end_run & ~0xF) - 0x10)
    tail = c[end_run:]
    d["tail_bytes"] = len(tail)
    d["tail_nonzero"] = sum(1 for b in tail if b)
    d["distinct_waves"] = len(waves)
    return d


def parse_atel_walk(c):
    """Verify the op&0x80 opcode walk closes exactly at scriptStart+codeLen."""
    if len(c) < 0x3A:
        return {"valid": False}
    code_len = u32(c, 0)
    ss = u32(c, 0x30)
    pos = ss
    end = min(ss + code_len, len(c))
    while pos < end:
        pos += 3 if (c[pos] & 0x80) else 1
    return {"valid": pos == end, "codeLen": code_len, "scriptStart": ss,
            "walkEnd": pos}


def audit_ebp(root):
    files = sorted(glob.glob(os.path.join(root, "**", "*.ebp"), recursive=True))
    rep = {"root": root, "files": len(files), "magic_ok": 0, "sentinel_ok": 0,
           "eof_eq_size": 0, "slot_counts": Counter(), "present_dist": Counter(),
           "absent_by_idx": Counter(), "roles": {}, "align_bad": [],
           "atel_walk_ok": 0, "atel_walk_bad": [], "sesep_files": 0,
           "sesep_contentlen_ok": 0, "sesep_records_total": 0,
           "fontdesc_files": [], "bad_container": [], "per_file": []}
    roles = Counter()
    for fp in files:
        data = open(fp, "rb").read()
        ev = os.path.splitext(os.path.basename(fp))[0]
        t = parse_ev01_table(data)
        if t is None:
            rep["bad_container"].append(ev)
            continue
        rep["magic_ok"] += 1
        slots, eof, sent = t
        rep["sentinel_ok"] += 1
        if eof == len(data):
            rep["eof_eq_size"] += 1
        rep["slot_counts"][len(slots)] += 1
        chunks = ev01_chunks(data, slots, eof)
        present = 0
        frec = {"id": ev, "size": len(data), "slots": len(slots), "chunks": {}}
        for i, c in enumerate(chunks):
            if c is None:
                rep["absent_by_idx"][i] += 1
                continue
            present += 1
            if slots[i] % 0x40:
                rep["align_bad"].append((ev, i, slots[i]))
            role, det = sniff_chunk(i, c)
            roles[(i, role)] += 1
            frec["chunks"][i] = {"role": role, "size": len(c)}
            if role == "atel":
                w = parse_atel_walk(c)
                if w["valid"]:
                    rep["atel_walk_ok"] += 1
                else:
                    rep["atel_walk_bad"].append(ev)
                frec["chunks"][i].update({k: v for k, v in
                                          sniff_chunk(0, c)[1].items()})
            elif role == "sesep":
                rep["sesep_files"] += 1
                rep["sesep_records_total"] += det.get("records", 0)
                if det.get("contentLen_check"):
                    rep["sesep_contentlen_ok"] += 1
                frec["chunks"][i].update(det)
            elif role == "texttable":
                frec["chunks"][i].update(det)
            elif role == "ftcx":
                frec["chunks"][i].update({k: v for k, v in det.items()
                                          if k != "raw"})
            elif role == "fontdesc":
                rep["fontdesc_files"].append(ev)
                frec["chunks"][i].update(det)
        rep["present_dist"][present] += 1
        rep["per_file"].append(frec)
    rep["slot_counts"] = dict(rep["slot_counts"])
    rep["present_dist"] = dict(rep["present_dist"])
    rep["absent_by_idx"] = dict(rep["absent_by_idx"])
    rep["roles"] = {f"{i}:{r}": n for (i, r), n in sorted(roles.items())}
    return rep


# ════════════════════════════════════════════════════════════════════════════
# 2. .ftc (FTCX) + non-FTCX base.ftc
# ════════════════════════════════════════════════════════════════════════════

def parse_ftcx(d, embedded=False):
    """Decode the 64B FTCX header + two descriptor quads.

    Header field map (atlas §FTCX + A3-E1 errata):
      +0x00 "FTCX" | +0x04 u16 200 | +0x06 u16 1556 | +0x08 u16 type
      +0x10 u32 width_copy_count | +0x14 u16 tile_w=14 | +0x16 u16 tile_h=18
      +0x20 descA {off,size,fmt=(h<<16|w),0} | +0x30 descB {off,size,0,0}
    """
    if len(d) < 0x40 or u32(d, 0) != FTCX_MAGIC:
        return {"ftcx": False}
    r = {"ftcx": True,
         "reserved1": u16(d, 4), "reserved2": u16(d, 6),
         "type": u16(d, 8),
         "width_copy_count": u32(d, 0x10),
         "tile_w": u16(d, 0x14), "tile_h": u16(d, 0x16),
         "descA_off": u32(d, 0x20), "descA_size": u32(d, 0x24),
         "descA_fmt": u32(d, 0x28),
         "descB_off": u32(d, 0x30), "descB_rawword": u32(d, 0x34)}
    r["img_w"] = r["descA_fmt"] & 0xFFFF
    r["img_h"] = r["descA_fmt"] >> 16
    # atlas-verified relations (embedded 4bpp profile): size == w*h/2,
    # descB.off == descA.off+descA.size, tail = 16*ceil(wcc/16)
    r["size_eq_wh_half"] = (r["descA_size"] == r["img_w"] * r["img_h"] // 2)
    r["descB_follows_A"] = (r["descB_off"] ==
                            r["descA_off"] + r["descA_size"])
    tail = 16 * ((r["width_copy_count"] + 15) // 16)
    r["tail16_formula_end"] = r["descB_off"] + tail
    r["tail16_eq_len"] = (r["tail16_formula_end"] == len(d))
    if embedded:
        r["len_align64_ok"] = (len(d) ==
                               ((r["descB_off"] + r["descB_rawword"] + 63)
                                & ~63))
    return r


def audit_ftc(root):
    files = sorted(glob.glob(os.path.join(root, "**", "*.ftc"), recursive=True))
    rep = {"root": root, "files": len(files), "ftcx_magic": 0,
           "non_ftcx": [], "type_dist": Counter(), "per_file": []}
    for fp in files:
        data = open(fp, "rb").read()
        rel = os.path.relpath(fp, root)
        p = parse_ftcx(data)
        if not p["ftcx"]:
            rep["non_ftcx"].append({"file": rel, "first16": data[:16].hex(),
                                    "size": len(data)})
            continue
        rep["ftcx_magic"] += 1
        rep["type_dist"][p["type"]] += 1
        rec = {"file": rel, "size": len(data)}
        rec.update(p)
        rep["per_file"].append(rec)
    rep["type_dist"] = dict(rep["type_dist"])
    return rep


# ════════════════════════════════════════════════════════════════════════════
# 3. cdrom.fnd / cdrom.fid
# ════════════════════════════════════════════════════════════════════════════

def audit_cdfnd(fnd_path, fid_path):
    d = open(fnd_path, "rb").read()
    count = u32(d, 0)
    offs = struct.unpack_from("<%dI" % (count + 1), d, 4)
    nonempty = sum(1 for i in range(count) if offs[i + 1] > offs[i] + 1)
    rep = {"file": fnd_path, "size": len(d), "count_field": count,
           "nonempty_paths": nonempty,
           "last_off_eq_eof_minus1": offs[-1] == len(d) - 1}

    def rec(i):
        return d[offs[i]:offs[i + 1]].rstrip(b"\x00")

    if fid_path and os.path.exists(fid_path):
        fid = open(fid_path, "rb").read()
        fids = struct.unpack("<65h", fid[:130])
        rep["fid_groups"] = list(fids)
        g12, g13 = fids[12], fids[13]
        rep["group12"] = {"fid12": g12, "fid13": g13, "entries": g13 - g12,
                          "eq_402x18": (g13 - g12) == 402 * 18}
        # per-block slot census over the 402 blocks
        slot_kind = {i: Counter() for i in range(18)}
        populated = 0
        for blk in range(402):
            base = g12 + blk * 18
            if any(rec(base + i) for i in range(18)):
                populated += 1
            for i in range(18):
                s = rec(base + i)
                if not s:
                    slot_kind[i]["empty"] += 1
                elif s.endswith(b".ebp"):
                    slot_kind[i]["ebp"] += 1
                elif s.endswith(b".mgrp"):
                    slot_kind[i]["mgrp"] += 1
                else:
                    slot_kind[i]["other"] += 1
        rep["group12_populated_blocks"] = populated
        rep["group12_slot_roles"] = {i: dict(c) for i, c in slot_kind.items()}
        rep["group12_sample_block0"] = [
            rec(g12 + i).decode("ascii", "replace") for i in range(18)]
    return rep


# ════════════════════════════════════════════════════════════════════════════
# 4. modulesize.bin + *_script.bin + menumain.{bin,msb} + evmapinfo.bin + .dcp
# ════════════════════════════════════════════════════════════════════════════

def audit_modulesize(path):
    d = open(path, "rb").read()
    vals = struct.unpack("<%dI" % (len(d) // 4), d)
    return {"file": path, "size": len(d), "u32_count": len(vals),
            "nonzero": sum(1 for v in vals if v),
            "values": [hex(v) for v in vals]}


def audit_script_bin(path):
    """*_script.bin: 0xD0-byte slot table (52×u32) → count-prefixed sections
    with a trailing NUL-separated ASCII name pool (menu UI resource names
    like rect_/col_/pos_/c_*plt*)."""
    d = open(path, "rb").read()
    hdr = u32(d, 0)
    n_slots = hdr // 4
    tab = struct.unpack_from("<%dI" % n_slots, d)
    used = [(i, v) for i, v in enumerate(tab) if v]
    sections = []
    for i, off in used:
        nxt = next((v for _, v in used if v > off), len(d))
        sec = d[off:nxt]
        cnt = u32(sec, 0) if len(sec) >= 4 else 0
        names = [m.group().decode("ascii") for m in
                 re.finditer(rb"[\x20-\x7e]{3,}\x00", sec)]
        sections.append({"slot": i, "off": off, "len": len(sec),
                         "count_field": cnt, "names": names[:6]})
    return {"file": path, "size": len(d), "header": hdr, "slots": n_slots,
            "used_slots": len(used), "sections": sections}


def audit_atel_blob(path):
    """menumain.bin: raw ATEL vendor blob (codeLen@0, totalLen@0x10,
    scriptStart@0x30, workerCount@0x36, worker u32 offsets @0x38)."""
    d = open(path, "rb").read()
    r = {"file": path, "size": len(d), "codeLen": u32(d, 0),
         "totalLen": u32(d, 0x10), "scriptStart": u32(d, 0x30),
         "workerCount": u16(d, 0x36)}
    r["totalLen_eq_size"] = r["totalLen"] == len(d)
    # opcode walk closure
    pos, end = r["scriptStart"], min(r["scriptStart"] + r["codeLen"], len(d))
    while pos < end:
        pos += 3 if (d[pos] & 0x80) else 1
    r["walk_closes_at_codelen"] = (pos == end)
    return r


def audit_msb(path):
    """menumain.msb: N×8B records {u16 off,attr,offAlt,attr2}; count =
    first_u16/8; FFX-encoded NUL-terminated strings after the table."""
    d = open(path, "rb").read()
    first = u16(d, 0)
    n = first // 8
    recs = []
    for i in range(n):
        off, attr, offAlt, attr2 = struct.unpack_from("<HHHH", d, i * 8)
        recs.append({"off": off, "attr": attr, "offAlt": offAlt,
                     "attr2": attr2})
    return {"file": path, "size": len(d), "record_count": n,
            "all_off_eq_offAlt": all(r["off"] == r["offAlt"] for r in recs),
            "all_attr_zero": all(r["attr"] == 0 and r["attr2"] == 0
                                 for r in recs),
            "records": recs[:8]}


def audit_dcp(path):
    """macrodic.dcp: section offsets u32 @0x18..0x34 → 6 u16 tables."""
    d = open(path, "rb").read()
    offs = [u32(d, o) for o in range(0x18, 0x38, 4)]
    offs = [o for o in offs if o] + [len(d)]
    tabs = []
    for i in range(len(offs) - 1):
        s, e = offs[i], offs[i + 1]
        n = (e - s) // 2
        vals = struct.unpack_from("<%dH" % n, d, s)
        mono = sum(1 for a, b in zip(vals, vals[1:]) if b >= a)
        tabs.append({"idx": i, "off": s, "end": e, "u16_count": n,
                     "mono_inc_frac": round(mono / max(n - 1, 1), 3),
                     "first8": list(vals[:8])})
    return {"file": path, "size": len(d), "section_offsets": offs[:-1],
            "tables": tabs}


def audit_evmapinfo(path):
    d = open(path, "rb").read()
    vals = struct.unpack("<%dH" % (len(d) // 2), d)
    live = {i: v for i, v in enumerate(vals) if v != 0xFFFF}
    return {"file": path, "size": len(d), "u16_count": len(vals),
            "populated": len(live),
            "value_range": [min(live.values()), max(live.values())],
            "entries": {i: v for i, v in list(live.items())}}


def audit_locale_bins(master_root):
    """new_<loc>pc/event/obj_{ps3,psv}/<area>/<ev>/<ev>.bin — per-locale
    8B text-record sidecars."""
    files = sorted(glob.glob(os.path.join(
        master_root, "new_*pc", "event", "obj_*", "*", "*", "*.bin"),
        recursive=True))
    rep = {"files": len(files), "parsed": 0, "bad": [],
           "total_records": 0, "by_tree": Counter(),
           "off_ne_offAlt": 0, "zero_records": 0}
    for fp in files:
        d = open(fp, "rb").read()
        tree = os.path.relpath(fp, master_root).split(os.sep)[0]
        rep["by_tree"][tree] += 1
        if len(d) < 8:
            rep["bad"].append(fp)
            continue
        first = u16(d, 0)
        if first == 0 or first % 8 or first > len(d):
            rep["bad"].append(fp)
            continue
        n = first // 8
        rep["parsed"] += 1
        rep["total_records"] += n
        for i in range(n):
            off, attr, offAlt, attr2 = struct.unpack_from("<HHHH", d, i * 8)
            if off != offAlt:
                rep["off_ne_offAlt"] += 1
            if off == attr == offAlt == attr2 == 0:
                rep["zero_records"] += 1
    rep["by_tree"] = dict(rep["by_tree"])
    return rep


# ════════════════════════════════════════════════════════════════════════════
# main
# ════════════════════════════════════════════════════════════════════════════

def dump(rep, outdir, name):
    os.makedirs(outdir, exist_ok=True)
    path = os.path.join(outdir, name)
    with open(path, "w", encoding="utf-8") as f:
        json.dump(rep, f, indent=2, ensure_ascii=False, default=str)
    print("wrote", path)


def main():
    ap = argparse.ArgumentParser(description="FFX event/script container audit")
    ap.add_argument("--ps2", default="/mnt/nvme-xpg/ffx_ps2/ffx/master",
                    help="PS2 master root (jppc/uspc/new_*pc live here)")
    ap.add_argument("--cddata",
                    default="/mnt/nvme-xpg/ffx_ps2/ffx/proj/battle/jp/cddata",
                    help="dir containing cdrom.fnd/.fid")
    ap.add_argument("--cdidx",
                    default="/mnt/nvme-xpg/ffx_ps2/ffx/proj/prog/cdidx",
                    help="dir containing modulesize.bin variants")
    ap.add_argument("--out", default="work/_fmt_event")
    args = ap.parse_args()

    m = os.path.join(args.ps2, "jppc")
    out = args.out

    # 1. .ebp corpus
    rep = audit_ebp(os.path.join(m, "event", "obj"))
    dump(rep, out, "ebp_census.json")

    # 2. .ftc corpus (whole master tree)
    rep = audit_ftc(args.ps2)
    dump(rep, out, "ftc_census.json")

    # 3. cdrom.fnd + fid (+ siblings)
    for fn in ("cdrom.fnd", "cdrom_cd.fnd", "cdrom_lc.fnd"):
        p = os.path.join(args.cddata, fn)
        if os.path.exists(p):
            rep = audit_cdfnd(p, os.path.join(args.cddata, "cdrom.fid"))
            dump(rep, out, fn.replace(".", "_") + ".json")

    # 4. modulesize.bin (filesize/ + all cdidx variants)
    mod = {"filesize_jppc": audit_modulesize(
               os.path.join(m, "filesize", "modulesize.bin"))}
    for p in sorted(glob.glob(os.path.join(args.cdidx, "**",
                                           "modulesize.bin"),
                              recursive=True) +
                    glob.glob(os.path.join(args.cdidx, "modulesize.bin"))):
        mod[os.path.relpath(p, args.cdidx)] = audit_modulesize(p)
    dump(mod, out, "modulesize.json")

    # 5. menu script containers (jppc + uspc)
    scrs = {}
    for loc in ("jppc", "uspc"):
        for fn in ("menu_script.bin", "battle_script.bin",
                   "system_script.bin", "menumain.msb"):
            p = os.path.join(args.ps2, loc, "menu", fn)
            if not os.path.exists(p):
                continue
            if fn.endswith(".msb"):
                scrs[f"{loc}/{fn}"] = audit_msb(p)
            else:
                scrs[f"{loc}/{fn}"] = audit_script_bin(p)
        p = os.path.join(args.ps2, loc, "menu", "menumain.bin")
        if os.path.exists(p):
            scrs[f"{loc}/menumain.bin"] = audit_atel_blob(p)
    dump(scrs, out, "menu_script_bins.json")

    # 6. macrodic.dcp (all locale copies)
    dcps = {}
    for p in sorted(glob.glob(os.path.join(args.ps2, "*", "menu",
                                           "macrodic.dcp"))):
        dcps[os.path.relpath(p, args.ps2)] = audit_dcp(p)
    dump(dcps, out, "macrodic_dcp.json")

    # 7. evmapinfo.bin
    p = os.path.join(m, "event", "obj", "evmapinfo.bin")
    if os.path.exists(p):
        dump(audit_evmapinfo(p), out, "evmapinfo.json")

    # 8. locale .bin sidecars
    dump(audit_locale_bins(args.ps2), out, "locale_bin_sidecars.json")


if __name__ == "__main__":
    main()
