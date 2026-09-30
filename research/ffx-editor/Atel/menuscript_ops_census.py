#!/usr/bin/env python3
# ── menuscript_ops_census.py — descriptor-op census + menublob binding dump ──
#
# Lane: Jarvis-MENUSCRIPT-OPS (2026-09-18). Stdlib only.
#
# Emits the wave13 CSVs for docs/reverse/FFX_MENUSCRIPT_OPS_2026-09-18.md:
#
#   menuscript_ops_census.csv    — per (locale,file): decoded descriptor
#                                  records + per-(flags,op) item counts.
#   menuscript_ops_semantics.csv — per opcode 0..A: stride, total size,
#                                  handler chain, verdict, semantics, fields.
#   menublob_bindings.csv        — the "99 bindings" of
#                                  FFX_Atel_SetupMenuBlobScripts @0x7976B0:
#                                  item -> lookup lane/sub -> section/slot
#                                  (system_01.bin walk, corpus-verified) ->
#                                  positional scriptId written to
#                                  worker[slot]+0xC0, plus the 7 hardcoded
#                                  SetMenuBlobByte rows and the ctx3 actor
#                                  branch. Presence columns are per-pack
#                                  corpus facts, NOT static guarantees.
#
# Evidence anchors (all decompile-proven, see doc):
#   dispatcher   FFX_FieldVM_Opcode_DispatchTable7  @0xA7B510
#   lerp/draw    FFX_Render_VertexInterpLerp        @0xA7B290
#                FFX_Render_VertexInterpDraw       @0xA7BBC0
#                FFX_Render_EasingFunc             @0xA7C6F0
#   stride table g_MenuDescInstrStrideTable        @0xC89C40 (u8[11])
#   traverse     FFX_Menu_Window_VramEntryTraverse @0xA7B460
#
# Usage:
#   menuscript_ops_census.py                 (writes the 3 CSVs to
#                                             docs/reverse/data/wave13/)
#   menuscript_ops_census.py --stdout        (prints census summary only)

import csv
import os
import struct
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "Ps2"))
import menu_script_reader as msr  # noqa: E402
sys.path.insert(0, os.path.dirname(__file__))
import menuscript_menublob as mmb  # noqa: E402

CORPUS = "/mnt/nvme-xpg/ffx_ps2/ffx/master"
FILES = ["battle_script.bin", "menu_script.bin", "system_script.bin"]
LOCALES = ["jppc", "uspc"]
OUTDIR = os.path.join(os.path.dirname(__file__), "..", "..",
                      "docs", "reverse", "data", "wave13")

# ── opcode semantics table (decompile-anchored; verdicts per evidence rules) ──
# fields: (op, stride_u16, total_bytes, payload_bytes, handler, verdict,
#          semantics, fields)
OPS = [
    (0, 2, 4, 0, "DispatchTable7 case0 (in-switch)",
     "PROVEN",
     "END: clears runtime-entry dword0 top bits (bound 0x80000000 + anim "
     "0x40000000) -> entry unbinds; timer=0, dur=-1; returns 0 -> when ALL "
     "entries dead VramEntryTraverse clears linkrec anim bit 0x40000000.",
     "none"),
    (1, 2, 4, 0, "DispatchTable7 case1 (in-switch)",
     "PROVEN(mech)/PARTIAL(intent)",
     "LERP-SOURCE RESET marker: entry+10 (saved instr pos) = entry+8 "
     "(cursor at the op1 itself, a non-drawable op) then cursor advances "
     "by last-stride. Next VertexInterpLerp sees saved-tag=op1 -> "
     "VertexInterpDraw early-returns (ops 0,1,2,3,8,9 draw nothing) -> "
     "neutralizes the interp 'from' state between draw groups.",
     "param unused by dispatcher"),
    (2, 2, 4, 0, "DispatchTable7 case2 (in-switch)",
     "PROVEN",
     "SIBLING LINK/park: param = sibling runtime-entry streamIdx tag "
     "(compared vs entry[0].dword0&0x3FFFFFFF; decompile quirk = "
     "loop-invariant so match -> idx 0 else -1). If bound sibling entry "
     "dword0 < 0 (still bound/animating) -> entry parks (returns 1, stays "
     "alive, draws saved state); when sibling unbinds -> advances past "
     "the op2. Corpus: params = valid descriptor-record indices.",
     "param = sibling streamIdx tag"),
    (3, 2, 4, 0, "DispatchTable7 case3 (in-switch)",
     "PROVEN",
     "TIMED HOLD: entry+4 = param (frame countdown, consumed once -> "
     "param-1), dur=-1, saved-pos = op3 itself -> interp draws NOTHING "
     "for param frames (VertexInterpDraw no-ops on tag 3). param==0 -> "
     "falls through, pure marker (equivalent to op1).",
     "param = hold frames"),
    (4, 10, 20, 16, "VertexInterpDraw case4 -> FFX_Render_DrawVertexQuad "
     "@0x8FDF20 -> FFX_Menu_RenderEnqueue @0x63F090",
     "PROVEN",
     "2-COLOR GRADIENT RECT: builds 20B record {colA,colB,x,y,w,h}, "
     "RenderEnqueue expands 2 corners (x,y)-(x+w,y+h) into quad + 8 "
     "color bytes. SKIPPED on render layer a5==1. Special fixup: if "
     "widget 'bwakk' open and y==7,h==22 -> y:=67. flag 0x8000 adds "
     "linkrec origin to x,y.",
     "+4 colA u32; +8 colB u32; +12 x i16; +14 y u16; +16 w i16; "
     "+18 h u16 (all lerped); param = duration frames"),
    (5, 10, 20, 16, "VertexInterpDraw case5 -> "
     "FFX_Render_DescOp5_LineDraw_Stubbed @0x8FE070 (1-byte ret)",
     "PROVEN(stub)",
     "TWO-POINT PRIMITIVE, RENDERER COMPILED OUT: builds 20B record "
     "{colA,colB,pt0=(+12,+14),pt1=(+16,+18)} — flag 0x8000 adds origin "
     "to BOTH points — then calls FFX_Render_DescOp5_LineDraw_Stubbed "
     "(empty). Draws NOTHING in this build. Structural corpus reading "
     "(line: y0==y1 dominates) is consistent but unprovable.",
     "+4 colA; +8 colB; +12 x0 i16; +14 y0 u16; +16 x1 i16; +18 y1 u16 "
     "(both pts origin-adjusted on 0x8000); param = duration"),
    (6, 12, 24, 20, "VertexInterpDraw case6 -> "
     "FFX_Menu2D_DrawDescSpriteQuad @0x8FE0B0 -> DrawTexQuadAtlas "
     "@0x903EE0 / DrawTexQuadSolid @0x903BB0 / TableLookupSpriteData "
     "@0x8FA7D0 / AtlasBase @0x8FA450 / TexHandleByAtlasId @0x8AC870 / "
     "Font_ResolveSheetDims @0x8AC3B0",
     "PROVEN",
     "SPRITE/GLYPH QUAD: 22B record {colA,colB,x,y,scalePct,spriteAux,"
     "spriteId}. spriteId(+20) dispatches: <0xC8 -> TableLookupSpriteData"
     "(id); 0xC8-0x190 -> font sheet 15872 (id-200); 0x190-0x258 -> atlas"
     " 16128 (id-400); 240 -> DrawTexQuadSolid fixed pane; 417 -> scaled"
     " TexQuadAtlas pane; 411/412/415/419/507 -> skipped. scalePct(+16)"
     " !=100 rescales; +14<=330 gate on the 417 pane; serialized +22 "
     "UNUSED (dead field).",
     "+4 colA; +8 colB; +12 x i16; +14 y u16; +16 scale% i16; +18 aux "
     "i16; +20 spriteId u16; +22 unused"),
    (7, 12, 24, 20, "VertexInterpDraw case7 -> FFX_Render_DrawDebugQuad "
     "@0x8FE080 -> Menu2D_DrawQuad_SolidAlpha -> DrawTextRunClipped",
     "PROVEN",
     "DEV PLACEHOLDER: draws literal '123456789' in gray at x,y. "
     "Lerped +16/+18/+20 + colors unconsumed by the draw. NEVER authored "
     "in corpus.",
     "+4 colA; +8 colB; +12 x; +14 y; +16/+18/+20 lerped-but-unused"),
    (8, 2, 4, 0, "DispatchTable7 case8 (in-switch)",
     "PROVEN",
     "LOOP-END: if flag 0x0800 -> counter := 1 (loop forever); elif "
     "entry+16>0 -> decrement; else entry+16 := param (initial count). "
     "counter>0 -> cursor := entry+14 (loop mark set by op9; default 0 "
     "= record start); counter<=0 -> advance past, entry+16:=0.",
     "param = repeat count; flag 0x0800 = infinite"),
    (9, 2, 4, 0, "DispatchTable7 case9 (in-switch)",
     "PROVEN",
     "LOOP-MARK: entry+14 := cursor+2 (position after op9 = loop top "
     "for op8). Never authored in corpus — authored op8 loops default "
     "to mark 0 = record start.",
     "none"),
    (10, 16, 32, 28, "VertexInterpDraw case10 -> "
     "FFX_Render_DrawOverdriveRow @0x8FE040 -> "
     "FFX_BtlUI_DrawOverdriveCommandRow",
     "PROVEN",
     "OVERDRIVE COMMAND/STATUS ROW: frame quad 162x44 + face icon atlas"
     " 440+idx + actor name centered x+97 + HP/MP/OD gauge y+23. "
     "serialized +28 = actorIndex (record +26), +30 -> record +28. "
     "serialized +26 SKIPPED (never read). Never authored in corpus.",
     "+4 colA; +8 colB; +12 x; +14 y; +16..+24 lerped; +26 unused; "
     "+28 actorIndex; +30 aux"),
]

FLAG_NOTES = {
    0x00: "none",
    0x08: "op8 loop-forever bit (0x0800); reserved on other ops",
    0x10: "0x1000 — matches no easing arm (falls to linear); semantics OPEN",
    0x20: "0x2000 quadOut — t runs 0->1 (REVERSED: blends toward saved "
          "state, unlike linear/quadIn/cos which run from->to)",
    0x30: "0x3000 quadIn (t = (remain/dur)^2, 1->0 slow start)",
    0x80: "0x8000 add link-record origin (dict+linkrec +8/+10) to x,y "
          "(op5: both points)",
    0x90: "0x8000 origin + 0x1000 (unresolved bit)",
}


def census_rows():
    rows = []
    totals = {}
    for loc in LOCALES:
        for fn in FILES:
            path = os.path.join(CORPUS, loc, "menu", fn)
            rep, errors = msr.parse(path)
            arena = rep.get("arena") if rep else None
            desc = getattr(arena, "desc", None) if arena else None
            items = [it for r in (desc or []) for it in r["items"]]
            nrec = len(desc or [])
            nw = len(getattr(arena, "widget_offs", []) or [])
            from collections import Counter
            byflag = Counter()
            for it in items:
                byflag[(it["base"], it["flags"])] += 1
            for (base, flags), n in sorted(byflag.items()):
                rows.append({
                    "locale": loc, "file": fn, "records": "%d/%d"
                    % (nrec, nw), "op": base, "flags": "0x%02X" % flags,
                    "count": n,
                    "flag_note": FLAG_NOTES.get(flags, "?")})
                totals[(fn, base)] = totals.get((fn, base), 0) + n
            rows.append({"locale": loc, "file": fn, "records": "%d/%d"
                         % (nrec, nw), "op": "*", "flags": "*",
                         "count": len(items), "flag_note": "all items"})
    return rows, totals


def write_census(path):
    rows, totals = census_rows()
    with open(path, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["locale", "file", "records",
                                          "op", "flags", "count",
                                          "flag_note"])
        w.writeheader()
        w.writerows(rows)
    # summary totals appended as a second logical block in the same csv
    with open(path, "a", newline="") as f:
        w = csv.writer(f)
        w.writerow([])
        w.writerow(["TOTALS(both locales)", "", "", "", "", "", ""])
        w.writerow(["file", "op", "total_items", "", "", "", ""])
        for (fn, op), n in sorted(totals.items()):
            w.writerow([fn, op, n])
    return rows, totals


def write_semantics(path):
    with open(path, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["op", "stride_u16", "total_bytes", "payload_bytes",
                    "handler_chain", "verdict", "semantics",
                    "serialized_fields"])
        for r in OPS:
            w.writerow(r)


def _try_pack_blob(b):
    off = struct.unpack_from("<I", b, 8)[0]
    if off <= 0 or off >= len(b) - 4:
        return None
    try:
        bl = mmb.parse_blob(b, off)
        if bl["count"] > 200 or bl["count"] < 1:
            return None
        if any(s != 0xFF and s > 0x80 for s in bl["secIdx"]):
            return None
        return bl
    except Exception:
        return None


def corpus_item_coverage():
    """item -> {packs: n, example: name, secRec slotBaseLo}.

    Scans every jppc battle pack's hdr[2] menu blob (the lane-0 source;
    the lane-1 pointer targets the same blob kind in packs that author
    the 41-55 family)."""
    import glob
    cov = {}
    for p in glob.glob(os.path.join(
            CORPUS, "jppc", "battle", "btl", "**", "*.bin"),
            recursive=True):
        try:
            b = open(p, "rb").read()
            if len(b) < 0x20:
                continue
            bl = _try_pack_blob(b)
            if not bl:
                continue
            name = os.path.basename(os.path.dirname(p))
            for i, s in enumerate(bl["secIdx"]):
                if s != 0xFF:
                    c = cov.setdefault(i, {"packs": 0, "example": name,
                                           "slotBaseLo": bl["secRecs"][s]
                                           ["slotBase"] & 0xFF})
                    c["packs"] += 1
        except Exception:
            continue
    return cov


def write_bindings(path):
    pack = os.path.join(CORPUS, "jppc", "battle", "btl",
                        "system_01", "system_01.bin")
    b = open(pack, "rb").read()
    blob = mmb.parse_blob(b, struct.unpack_from("<I", b, 8)[0])
    cov = corpus_item_coverage()
    rows = []
    for lane, lo, hi in mmb.BIND_LOOPS:
        lane_base = blob["lane1Base"] if lane > 0 else 0
        for item in range(lo, hi + 1):
            w = mmb.walk(blob, item)
            c = cov.get(item, {})
            rows.append({
                "item": item, "group": "%d-%d" % (lo, hi),
                "lookupLane": 2, "lookupSub": lane,
                "scriptId": item - lo, "source": "loop",
                "presentInSystem01": "y" if w else "n",
                "section": w["section"] if w else "",
                "slotBaseLo": w["slotBaseLo"] if w else "",
                "slotGlobal": lane_base + w["slotBaseLo"] if w else "",
                "packsAuthoring": c.get("packs", 0),
                "examplePack": c.get("example", ""),
                "note": "worker[slot]+0xC0 := %d (positional); "
                        "slot=laneBase(%d)+secRec[0]" % (item - lo,
                                                        lane_base)})
    for lane, item, sid in mmb.BIND_FIXED:
        w = mmb.walk(blob, item)
        c = cov.get(item, {})
        rows.append({
            "item": item, "group": "hardcoded", "lookupLane": 2,
            "lookupSub": lane, "scriptId": sid, "source": "SetMenuBlobByte",
            "presentInSystem01": "y" if w else "n",
            "section": w["section"] if w else "",
            "slotBaseLo": w["slotBaseLo"] if w else "",
            "slotGlobal": w["slotBaseLo"] if w else "",
            "packsAuthoring": c.get("packs", 0),
            "examplePack": c.get("example", ""),
            "note": "items 37-40 alias scripts 14-17 (shared EPs)"})
    for m in (61, 4, 64):
        for i in range(8):
            rows.append({
                "item": "actor%d+20" % i, "group": "ctx3-msg%d" % m,
                "lookupLane": 3, "lookupSub": i + 20, "scriptId": i + 20,
                "source": "ctx3-loop", "presentInSystem01": "",
                "section": "", "slotBaseLo": "",
                "slotGlobal": "", "packsAuthoring": "",
                "examplePack": "",
                "note": "LookupSourceEntry(3, i+20, %d)" % m})
    with open(path, "w", newline="") as f:
        wcsv = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
        wcsv.writeheader()
        wcsv.writerows(rows)
    return rows


def main(argv):
    if "--stdout" in argv:
        rows, totals = census_rows()
        for r in rows:
            if r["flags"] == "*":
                print("%-5s %-18s records=%s items=%d"
                      % (r["locale"], r["file"], r["records"], r["count"]))
        print(totals)
        return 0
    os.makedirs(OUTDIR, exist_ok=True)
    rows, totals = write_census(os.path.join(
        OUTDIR, "menuscript_ops_census.csv"))
    write_semantics(os.path.join(OUTDIR, "menuscript_ops_semantics.csv"))
    binds = write_bindings(os.path.join(OUTDIR, "menublob_bindings.csv"))
    print("wrote census(%d rows) + semantics(%d ops) + bindings(%d rows) -> %s"
          % (len(rows), len(OPS), len(binds), OUTDIR))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
