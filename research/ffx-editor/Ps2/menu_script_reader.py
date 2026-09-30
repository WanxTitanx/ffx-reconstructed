#!/usr/bin/env python3
# ── menu_script_reader.py — PS2 FFX `menu/*_script.bin` reader/validator ──────
#
# Format verdict (docs/reverse/FFX_FMT_SCRIPTBIN_GRAMMAR_2026-09-17.md,
# lane Jarvis-CORPUS, corpus = jppc + uspc, the only locales that ship
# `battle_script.bin` / `menu_script.bin` / `system_script.bin`):
#
#   Header:  52 x u32 section-offset table @0x00 (0 = unused slot).
#            Sections tile the file; section end = next non-zero slot offset.
#
#   Four section kinds (identified structurally, no explicit type field):
#
#   A) DICT  {u32 count; count x rec; namePool}
#        rec = {u16 nameOff; u16 tag; u32 payload[tag >> 8]}
#        tag in {0x0100, 0x0200, 0x0400} — the high byte IS the payload arity
#        (1/2/4 u32s). Semantic class comes from the name prefix:
#          col_*/c_*/kuro*/lefc*/...  tag 0x0100  -> 1 x u32 RGBA color
#          num_*                    tag 0x0100  -> 1 x u32 integer
#          pos_*/p_*/point_*        tag 0x0200  -> 2 x u32 (x, y)
#          rect_*/r_*               tag 0x0400  -> 4 x u32 (x, y, w, h)
#          dum*/dumm*               any         -> dummy/scratch entries
#        nameOff = absolute file offset into this section's NUL-separated
#        ASCII pool (pool follows the records; NUL-padded to 4 bytes).
#
#   B) LINK  {u32 count; count x {u32 nameOff; u32 dataOff; u32 rsv=0}; pool}
#        name -> "scene block" inside the slot-32 arena (see C).
#        menu_script names: scene0..scene34; battle_script: b* layouts.
#
#   C) ARENA (always slot 32)
#        {u32 widgetOff[N] ascending; sceneBlock region}
#        widgetOff[i] = absolute offset of widget-descriptor record i inside
#        the descriptor blob. The blob physically lives in the tail of the
#        LAST dict section (s15 in menu/battle, s13 in system) — i.e. the
#        bytes between that dict's name pool and the next section start.
#        widgetOff[0] == blob start; blob end == slot32 section start.
#        Table has NO count field: it ends at the first word that is not a
#        non-decreasing in-blob offset (scene counts are small ints, never
#        in the blob range, so termination is unambiguous).
#        Descriptor record grammar — PROVEN across all 6 files
#        (1000/1000 records consume exactly up to the next widgetOff /
#        blob end; see FFX_FMT_SCRIPTBIN_DEEP_2026-09-17.md and the
#        native-runtime residual doc FFX_SCRIPTBIN_RESIDUAL_2026-09-17.md):
#          record := item*  END(u32 0x00000000)
#          item   := {u16 tag; u16 param; payload[DESC_PSIZE[tag & 0xFF]]}
#          tag low byte = opcode base; tag high byte = flag bitfield
#          (0x00/0x08/0x10/0x20/0x30/0x80/0x90 observed — flags do NOT
#          change payload size). Payload sizes by base op are now
#          DECOMPILER-PROVEN: the runtime dispatcher
#          FFX_FieldVM_Opcode_DispatchTable7 (0xA7B510) advances the
#          instruction cursor by g_MenuDescInstrStrideTable[op] u16 words
#          (0xC89C40 = {2,2,2,2,10,10,12,12,2,2,16}), i.e. total item
#          sizes 4/4/4/4/20/20/24/24/4/4/32 bytes:
#            0:0 1:0 2:0 3:0 4:16 5:16 6:20 7:20 8:0 9:0 10:28
#          (op3 has NO payload — the earlier "u32 v" reading was actually
#          the following op8 loop instruction, e.g. `03 00 01 00 08 08
#          00 00` = op3(param=1) + op8(flag 0x08,param=0).)
#        Semantics (evidence-graded, see doc):
#          op2 = widget-link/sibling-select (param compared against the
#                descriptor-list link id; native case 2).
#          op4 = 16B rect  {u32 colA, u32 colB, i16 x,y,w,h}
#          op5 = 16B line  {u32 colA, u32 colB, i16 x0,y0,x1,y1}
#                (y0==y1 horizontal dominates; c0!=c1 = gradient)
#          op6 = 20B quad  {u32 colA, u32 colB, i16 x,y,w,h, u32 aux<512}
#                aux = sprite/atlas record selector (decompiler-proven).
#          op3 = timed transition setup (param = duration in ticks).
#          op8 = loop-end: repeats to the op9 mark `param` times, or
#                indefinitely when flag bit 0x08 (runtime bit 0x800) set.
#          op9 = loop-start mark (records cursor position for op8).
#          op1 = lerp-base commit (snapshots cursor for interpolation).
#          op7/opA = 20B/28B timed draw ops (native cases 7/0xA).
#          flag+param on 4/5/6 = variant items preceding their flag-0
#          default twin (param semantics unresolved).
#        sceneBlock = {u32 n; n x 20-byte entry}
#        entry = {u32 widgetIdx; u32 rsv0=0; u32 rsv1=0; u32 0x0000ffff;
#                 u32 rsv2=0}  — widgetIdx indexes the arena table
#        (max observed = tableSize-1 exactly, in every file).
#
#   Slot table = the serialized runtime hash table (PROVEN 2026-09-17):
#        slots 0-15   = dict  buckets: slot == XOR(name bytes) & 0xF
#        slots 16-31  = link  buckets: slot == 16 + XOR(name) & 0xF
#        slots 32-35  = aux[4]: only 32 (arena) ever used
#        slots 36-51  = tableC idxlist buckets (group key NOT derivable
#                       from the record name — proven negative)
#        Matches FFX_Menu_Widget_LookupStringByHash/LookupBtidByName
#        (docs/reverse/FFX_EVENT_RESIDUALS_2026-09-17.md §2.2-2.4).
#
#   D) IDXLIST (slots >= 33)
#        {u32 n; n x u32 recordAddr} — absolute addresses of LINK records,
#        stored in descending order. These are numbered selection groups
#        over the link records (e.g. battle s36 = main menu entries,
#        s37 = *lay variants, s40 = wakk group; menu s36 = primary scene
#        list, s39/s40/s44 = small sub-groups).
#
# Cross-locale: jppc vs uspc are byte-identical except a handful of dict
# payload values (battle 57 u32s, menu 9, system 0) — pure per-locale
# layout tuning (positions/sizes for different text lengths). Structure,
# names, sections, widget tables: identical.
#
# stdlib only. Usage:
#   menu_script_reader.py FILE...          parse + validate, print summary
#   menu_script_reader.py FILE -v          verbose record dump
#   menu_script_reader.py FILE --json out.json
# Exit 0 iff every file parses with zero errors.
# ──────────────────────────────────────────────────────────────────────────────
import json
import os
import string
import struct
import sys
from collections import Counter

PRINTABLE = set(bytes(string.printable, "ascii")) - set(b"\x0b\x0c\r\n\t")
SLOT_COUNT = 52
ARENA_SLOT = 32
VALID_TAGS = (0x0100, 0x0200, 0x0400)

# Descriptor payload sizes indexed by (tag & 0xFF). DECOMPILER-PROVEN via
# g_MenuDescInstrStrideTable @0xC89C40 = {2,2,2,2,10,10,12,12,2,2,16} u16
# words per base op (FFX_FieldVM_Opcode_DispatchTable7 advances the stream
# cursor by stride[op]*2 bytes). Ops 7/9/10 are NEVER authored — zero items
# in all six files (re-verified 2026-09-18 Jarvis-OPSDORMANT; the earlier
# "menu op7=5, op9=2, op10=1; battle op9=3" line was a stale
# intermediate-parse count — see docs/reverse/FFX_OPS_DORMANT_2026-09-18.md
# section 2). All six files still exact-tile
# [widgetOff[i], widgetOff[i+1]/blobEnd) under these sizes.
DESC_PSIZE = {0: 0, 1: 0, 2: 0, 3: 0, 4: 16, 5: 16, 6: 20, 7: 20,
              8: 0, 9: 0, 10: 28}

SEMANTIC = {  # name prefix -> widget class label
    "col": "color-rgba", "c": "color-rgba", "kuro": "color-rgba",
    "kuros": "color-rgba", "norkuro": "color-rgba", "wazakuro": "color-rgba",
    "lefc": "color-rgba", "2lefc": "color-rgba", "limitc": "color-rgba",
    "limgc": "color-rgba", "stbc": "color-rgba", "lefmura": "color-rgba",
    "wazabox": "color-rgba", "limsiro": "color-rgba",
    "num": "number", "pos": "position", "p": "position",
    "point": "position", "fkpos": "position",
    "rect": "rect", "r": "rect", "dum": "dummy", "dumm": "dummy",
}


def u32(b, o):
    return struct.unpack_from("<I", b, o)[0]


def u16(b, o):
    return struct.unpack_from("<H", b, o)[0]


def i16(b, o):
    return struct.unpack_from("<h", b, o)[0]


def cstr(b, o):
    """ASCII NUL-terminated string at absolute offset o, else None."""
    if o < 0 or o >= len(b):
        return None
    e = o
    while e < len(b) and b[e] != 0:
        if b[e] not in PRINTABLE:
            return None
        e += 1
    if e >= len(b):
        return None
    return b[o:e].decode("ascii")


def semantic_class(name):
    pfx = name.split("_")[0] if "_" in name else "".join(
        ch for ch in name if not ch.isdigit())
    return SEMANTIC.get(pfx, "label" if not pfx else "other")


class Section(object):
    def __init__(self, slot, off, end):
        self.slot = slot
        self.off = off
        self.end = end
        self.kind = "raw"
        self.records = []      # dict/link recs (dicts keep 'payload')
        self.pool_off = None
        self.blob_off = None   # arena-blob start when section carries it
        self.errors = []


def try_link(b, sec):
    o, end = sec.off, sec.end
    cnt = u32(b, o)
    if cnt == 0 or cnt > 512 or o + 4 + 12 * cnt > end:
        return False
    recs = [(u32(b, o + 4 + 12 * i), u32(b, o + 8 + 12 * i), u32(b, o + 12 + 12 * i))
            for i in range(cnt)]
    pool = o + 4 + 12 * cnt
    for noff, doff, rsv in recs:
        if rsv != 0 or not (pool <= noff < end) or cstr(b, noff) is None:
            return False
        if not (0 < doff < len(b)):
            return False
    sec.kind = "link"
    sec.records = [{"nameOff": n, "dataOff": d, "name": cstr(b, n)}
                   for n, d, _ in recs]
    sec.pool_off = pool
    return True


def try_dict(b, sec):
    o, end = sec.off, sec.end
    cnt = u32(b, o)
    if cnt == 0 or cnt > 512 or o + 4 + 4 * cnt > end:
        return False
    p = o + 4
    recs = []
    for _ in range(cnt):
        if p + 4 > end:
            return False
        w0 = u32(b, p)
        noff, tag = w0 & 0xFFFF, (w0 >> 16) & 0xFFFF
        if tag not in VALID_TAGS:
            return False
        n = tag >> 8
        if p + 4 * (n + 1) > end:
            return False
        recs.append({"at": p, "nameOff": noff, "tag": tag,
                     "payload": [u32(b, p + 4 + 4 * j) for j in range(n)]})
        p += 4 * (n + 1)
    # every name must live inside the trailing pool of THIS section
    for r in recs:
        if not (p <= r["nameOff"] < end):
            return False
        r["name"] = cstr(b, r["nameOff"])
        if r["name"] is None:
            return False
    sec.kind = "dict"
    sec.records = recs
    sec.pool_off = p
    return True


def parse_desc_record(b, off, end):
    """Decode one widget-descriptor record at absolute offset `off`.

    Grammar (PROVEN, exact-tile on the whole 6-file corpus):
        record := item*  END(u32 0x00000000)
        item   := {u16 tag; u16 param; payload[DESC_PSIZE[tag & 0xFF]]}

    Returns (items, nextOff) — nextOff == the byte right after the END
    sentinel — or (None, off) on any structural violation. Payloads are
    decoded to *structural* fields only (raw u32/i16 words); names like
    colA/colB/x/y/w/h in the dump are corpus-supported interpretations,
    NOT proven runtime semantics (flags/params remain unresolved — see
    FFX_FMT_SCRIPTBIN_DEEP_2026-09-17.md §4).
    """
    items = []
    p = off
    while p + 4 <= end:
        tag, param = u16(b, p), u16(b, p + 2)
        p += 4
        if tag == 0 and param == 0:
            return items, p
        base, flags = tag & 0xFF, tag >> 8
        if base not in DESC_PSIZE:
            return None, off
        sz = DESC_PSIZE[base]
        if p + sz > end:
            return None, off
        it = {"at": p - 4, "tag": tag, "base": base, "flags": flags,
              "param": param}
        pl = b[p:p + sz]
        if base in (4, 5, 7, 10):
            # two u32 words (corpus-consistent with RGBA colors) + i16 tail
            it["w"] = [u32(pl, 0), u32(pl, 4)]
            it["g"] = [i16(pl, 8 + 2 * j) for j in range((sz - 8) // 2)]
        elif base == 6:
            it["w"] = [u32(pl, 0), u32(pl, 4)]
            it["g"] = [i16(pl, 8 + 2 * j) for j in range(4)]
            it["aux"] = u32(pl, 16)
        else:
            it["raw"] = pl.hex()
        items.append(it)
        p += sz
    return None, off


def parse(path):
    b = open(path, "rb").read()
    size = len(b)
    if size < SLOT_COUNT * 4:
        return None, ["file too small for 52-slot table"]
    slots = [u32(b, 4 * i) for i in range(SLOT_COUNT)]
    used = sorted(o for o in slots if o)
    if not used or min(used) < SLOT_COUNT * 4 or max(used) >= size:
        return None, ["section table out of bounds"]

    def eof(o):
        hi = [x for x in used if x > o]
        return min(hi) if hi else size

    secs = []
    for si, o in enumerate(slots):
        if not o:
            continue
        s = Section(si, o, eof(o))
        secs.append(s)
        if si == ARENA_SLOT:
            s.kind = "arena"
            continue
        # link first: its record triples can alias as tag-0 dict records
        if try_link(b, s):
            continue
        if try_dict(b, s):
            continue
        s.kind = "raw"

    # ── arena (slot 32): offset table into descriptor blob + scene blocks ──
    arena = next((s for s in secs if s.slot == ARENA_SLOT), None)
    widget_offs, blocks_lo = [], None
    if arena is not None:
        p = arena.off
        prev = -1
        while p + 4 <= arena.end:
            v = u32(b, p)
            if 0 < v < arena.off and v >= prev:
                widget_offs.append(v)
                prev = v
                p += 4
            else:
                break
        blocks_lo = p
        arena.widget_offs = widget_offs
        arena.blocks_lo = blocks_lo
        if not widget_offs:
            arena.errors.append("arena: empty widget-offset table")
    else:
        arena = None

    # ── dict trailing blob -> descriptor arena cross-check ──
    blob = None
    for s in secs:
        if s.kind != "dict":
            continue
        p = s.pool_off
        while p < s.end and cstr(b, p) is not None:
            p += len(cstr(b, p)) + 1
        tail = s.end - p
        if tail > 16:
            s.blob_off = p
            blob = (p, s.end)
    if arena is not None and widget_offs:
        if blob is None or widget_offs[0] != blob[0] or arena.off != blob[1]:
            arena.errors.append(
                "arena: table/blob mismatch (table0=%s blob=%s)"
                % (hex(widget_offs[0]), blob))

    # ── descriptor records: decode + exact-tile validation ──
    # Record i occupies [widgetOff[i], widgetOff[i+1]) (last one ends at the
    # blob end = arena section start). The END sentinel is part of the span.
    desc = []
    if arena is not None and widget_offs and blob is not None:
        for i, wo in enumerate(widget_offs):
            rend = (widget_offs[i + 1] if i + 1 < len(widget_offs)
                    else blob[1])
            items, nxt = parse_desc_record(b, wo, rend)
            if items is None or nxt != rend:
                arena.errors.append(
                    "descriptor record %d @%#x failed exact-tile" % (i, wo))
                continue
            desc.append({"i": i, "off": wo, "items": items})
        arena.desc = desc

    # ── record-address universe for idxlist validation ──
    rec_addr = {}
    for s in secs:
        if s.kind == "dict":
            for k, r in enumerate(s.records):
                rec_addr[r["at"]] = (s.slot, k, r["name"])
        elif s.kind == "link":
            for k, r in enumerate(s.records):
                rec_addr[s.off + 4 + 12 * k] = (s.slot, k, r["name"])

    # ── idxlist classification for remaining raw sections ──
    for s in secs:
        if s.kind != "raw":
            continue
        n = u32(b, s.off)
        if n == 0 or n > 4096 or s.off + 4 + 4 * n > s.end:
            continue
        addrs = [u32(b, s.off + 4 + 4 * i) for i in range(n)]
        if all(a in rec_addr for a in addrs):
            s.kind = "idxlist"
            s.records = [{"addr": a, "target": rec_addr[a]} for a in addrs]
        else:
            bad = [a for a in addrs if a not in rec_addr]
            s.errors.append("raw section; %d/%d addrs unmapped" % (len(bad), n))

    # ── scene blocks: validate every link target decodes ──
    nblocks = 0
    if arena is not None:
        for s in secs:
            if s.kind != "link":
                continue
            for r in s.records:
                d = r["dataOff"]
                if not (blocks_lo <= d < arena.end):
                    r["blockError"] = "target outside arena blocks region"
                    continue
                n = u32(b, d)
                if n > 64 or d + 4 + 20 * n > arena.end:
                    r["blockError"] = "bad block count %d" % n
                    continue
                ids = [u32(b, d + 4 + 20 * i) for i in range(n)]
                ok = all(i < len(widget_offs) for i in ids)
                tail_ok = all(
                    u32(b, d + 4 + 20 * i + 4) == 0
                    and u32(b, d + 4 + 20 * i + 8) == 0
                    and u32(b, d + 4 + 20 * i + 12) == 0x0000FFFF
                    and u32(b, d + 4 + 20 * i + 16) == 0
                    for i in range(n))
                r["block"] = {"count": n, "widgetIds": ids,
                              "idsInRange": ok, "tailConst": tail_ok}
                nblocks += 1
                if not ok:
                    r["blockError"] = "widgetIdx out of range"

    errors = []
    for s in secs:
        for e in s.errors:
            errors.append("s%d: %s" % (s.slot, e))
    for s in secs:
        if s.kind == "link":
            for r in s.records:
                if "blockError" in r:
                    errors.append("s%d %s: %s" % (s.slot, r["name"], r["blockError"]))
    return {"path": path, "size": size, "slots": slots, "sections": secs,
            "arena": arena, "blob": blob, "nblocks": nblocks}, errors


def describe(rep):
    out = []
    secs = rep["sections"]
    kinds = Counter(s.kind for s in secs)
    out.append("%s: %d B, %d/%d slots used — %s"
               % (rep["path"], rep["size"], len(secs), SLOT_COUNT,
                  ", ".join("%s=%d" % kv for kv in sorted(kinds.items()))))
    for s in secs:
        if s.kind == "dict":
            tags = Counter(r["tag"] for r in s.records)
            names = [r["name"] for r in s.records]
            out.append("  s%-2d dict   n=%-3d tags=%s names=%s%s"
                       % (s.slot, len(s.records), dict(tags),
                          ",".join(names[:6]),
                          "…" if len(names) > 6 else ""))
        elif s.kind == "link":
            out.append("  s%-2d link   n=%-3d %s"
                       % (s.slot, len(s.records), " ".join(
                           "%s->%#x" % (r["name"], r["dataOff"])
                           for r in s.records[:6])))
        elif s.kind == "arena":
            out.append("  s%-2d arena  widgets=%d blocksRegion=[%#x,%#x)"
                       % (s.slot, len(s.widget_offs), s.blocks_lo, s.end))
        elif s.kind == "idxlist":
            tg = [r["target"][2] for r in s.records]
            out.append("  s%-2d idxlist n=%-3d -> {%s}"
                       % (s.slot, len(s.records), ",".join(tg[:10])))
        else:
            out.append("  s%-2d RAW    @%#x..%#x" % (s.slot, s.off, s.end))
    if rep["blob"]:
        out.append("  descriptor blob [%#x,%#x) = %d B"
                   % (rep["blob"][0], rep["blob"][1],
                      rep["blob"][1] - rep["blob"][0]))
    arena = rep["arena"]
    if arena is not None and getattr(arena, "desc", None) is not None:
        oph = Counter("f%02X.%d" % (it["flags"], it["base"])
                      for r in arena.desc for it in r["items"])
        out.append("  descriptor records decoded: %d/%d — items %s"
                   % (len(arena.desc), len(arena.widget_offs),
                      dict(sorted(oph.items()))))
    out.append("  scene blocks decoded: %d" % rep["nblocks"])
    return "\n".join(out)


def to_json(rep):
    def sec(s):
        d = {"slot": s.slot, "off": s.off, "end": s.end, "kind": s.kind,
             "records": s.records, "errors": s.errors}
        if s.kind == "arena":
            d["widgetOffs"] = s.widget_offs
            d["blocksLo"] = s.blocks_lo
            d["desc"] = getattr(s, "desc", [])
        return d
    return {"path": rep["path"], "size": rep["size"],
            "sections": [sec(s) for s in rep["sections"]]}


def main(argv):
    args = [a for a in argv if not a.startswith("-")]
    verbose = "-v" in argv
    jout = None
    if "--json" in argv:
        i = argv.index("--json")
        jout = argv[i + 1]
        args = [a for a in args if a != argv[i + 1]]
    if not args:
        # default corpus sweep
        root = "/mnt/nvme-xpg/ffx_ps2/ffx/master"
        for loc in sorted(os.listdir(root)):
            md = os.path.join(root, loc, "menu")
            if not os.path.isdir(md):
                continue
            for f in sorted(os.listdir(md)):
                if f.endswith("_script.bin"):
                    args.append(os.path.join(md, f))
    total_err = 0
    allrep = []
    for path in args:
        rep, errs = parse(path)
        if rep is None:
            print("%s: FATAL %s" % (path, errs))
            total_err += len(errs)
            continue
        print(describe(rep))
        if verbose:
            for s in rep["sections"]:
                if s.kind == "dict":
                    for r in s.records:
                        print("     s%d @%#x %-18s tag=%#06x cls=%s payload=%s"
                              % (s.slot, r["at"], r["name"], r["tag"],
                                 semantic_class(r["name"]),
                                 [hex(x) for x in r["payload"]]))
                elif s.kind == "link":
                    for r in s.records:
                        blk = r.get("block")
                        print("     s%d %-14s -> block @%#x %s"
                              % (s.slot, r["name"], r["dataOff"],
                                 ("widgets=%s" % blk["widgetIds"])
                                 if blk else r.get("blockError", "?")))
            arena = rep["arena"]
            if arena is not None and getattr(arena, "desc", None):
                for r in arena.desc:
                    txt = []
                    for it in r["items"]:
                        t = "%02X/%02X" % (it["flags"], it["base"])
                        if it["base"] in (4, 5):
                            t += " w=%s g=%s" % (
                                [hex(x) for x in it["w"]], it["g"])
                        elif it["base"] == 6:
                            t += " w=%s g=%s aux=%#x" % (
                                [hex(x) for x in it["w"]], it["g"],
                                it["aux"])
                        elif it["base"] == 3:
                            t += " v=%#x" % it["v"]
                        t += " p=%d" % it["param"]
                        txt.append(t)
                    print("     w%-3d @%#x  %s" % (r["i"], r["off"],
                                                   " | ".join(txt)))
        for e in errs:
            print("  ERROR: " + e)
        total_err += len(errs)
        allrep.append(rep)
    print("\n%d/%d files parsed clean" % (
        sum(1 for r in allrep if not any(s.errors for s in r["sections"])),
        len(allrep)))
    if jout:
        json.dump([to_json(r) for r in allrep], open(jout, "w"), indent=1)
    return 0 if total_err == 0 else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
