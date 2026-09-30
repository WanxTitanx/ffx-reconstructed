#!/usr/bin/env python3
# ── ops_dormant_arm_scan.py — dormant-but-armable surface evidence tool ──────
#
# Lane: Jarvis-OPSDORMANT (2026-09-18). Stdlib only. Research-only.
#
# Emits docs/reverse/data/wave15/ops_dormant_{arming,writers}.csv for
# docs/reverse/FFX_OPS_DORMANT_2026-09-18.md.
#
# What it verifies on disk (corpus side of the adjudication):
#   A) Descriptor-op census — all six menu/*_script.bin files
#      (jppc+uspc x {battle,menu,system}): PROVES zero authored items use
#      ops 7 / 9 / A (tag low byte 0x07/0x09/0x0A — equivalent to the
#      runtime mask tag&0x7FF because no authored tag sets bits 8-10;
#      see report §2). Also prints the full per-(op,flag) histogram so a
#      non-zero drift is visible, and scans every other file under menu/
#      for 52-slot-table descriptor streams (none exist).
#   B) EV01/.ebp opcode census for ops 0x3C/0x3D/0x3E/0x3F (RET family) —
#      the trigger ops for the dormant ctrl+0x28 callback slot. PROVES
#      op 0x3C is the ubiquitous script terminator (88k sites) so an armed
#      +0x28 hook would be HOT, unlike the never-authored B-ops.
#
# The writers/readers half of the CSV is static IDB-audit evidence
# (decompile-verified addresses, same as the report) — the tool emits it
# verbatim so the CSV ships with the tool.
#
# Usage:
#   ops_dormant_arm_scan.py            (writes both CSVs + prints summary)
#   ops_dormant_arm_scan.py --stdout   (prints, writes nothing)
#
import csv
import os
import struct
import sys
from collections import Counter

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "Ps2"))
import menu_script_reader as msr  # noqa: E402

CORPUS = "/mnt/nvme-xpg/ffx_ps2/ffx/master"
SCRIPT_FILES = ["battle_script.bin", "menu_script.bin", "system_script.bin"]
LOCALES = ["jppc", "uspc"]
OUTDIR = os.path.join(os.path.dirname(__file__), "..", "..",
                      "docs", "reverse", "data", "wave15")

u32 = lambda b, o: struct.unpack_from("<I", b, o)[0]

# ── A. descriptor-op census over the six script bins ─────────────────────────

def desc_census():
    """Return (rows, hist, other_streams) — per-file op7/9/A counts + full
    (base,flags) histogram + any non-script file under menu/ that parses as
    a descriptor blob (expected: none)."""
    rows = []
    hist = Counter()
    for loc in LOCALES:
        for fn in SCRIPT_FILES:
            path = os.path.join(CORPUS, loc, "menu", fn)
            rep, errors = msr.parse(path)
            arena = rep.get("arena") if rep else None
            desc = getattr(arena, "desc", None) if arena else None
            items = [it for r in (desc or []) for it in r["items"]]
            for it in items:
                hist[(it["base"], it["flags"])] += 1
            rows.append({
                "file": "%s/menu/%s" % (loc, fn),
                "records": "%d/%d" % (len(desc or []),
                                      len(getattr(arena, "widget_offs", []) or [])),
                "parse_errors": len(errors),
                "items": len(items),
                "op7_items": sum(1 for it in items if it["base"] == 7),
                "op9_items": sum(1 for it in items if it["base"] == 9),
                "opA_items": sum(1 for it in items if it["base"] == 10),
            })
    # scan every other file under */menu/ for descriptor streams
    other = []
    import glob
    for loc in LOCALES:
        for p in sorted(glob.glob(os.path.join(CORPUS, loc, "menu", "**", "*"),
                                  recursive=True)):
            if not os.path.isfile(p) or os.path.basename(p) in SCRIPT_FILES:
                continue
            b = open(p, "rb").read()
            if len(b) < 208:
                continue
            slots = [u32(b, 4 * i) for i in range(52)]
            used = [o for o in slots if o]
            if not (3 <= len(used) <= 52 and min(used) >= 208
                    and max(used) < len(b)):
                continue
            rep, _ = msr.parse(p)
            if rep and rep.get("arena") is not None \
               and getattr(rep["arena"], "desc", None):
                other.append(p)
    return rows, hist, other


# ── B. EV01/.ebp RET-family census (ctrl+0x28 trigger ops) ───────────────────

def ebp_ret_census(root):
    """Decode the ATEL code region of every EV01 file under `root`.
    Returns (files, bad, files_with, hist) for ops 0x3C/0x3D/0x3E/0x3F."""
    hist = Counter()
    files = bad = files_with = 0
    for dp, _dirs, fns in os.walk(root):
        for fn in fns:
            if not fn.lower().endswith(".ebp"):
                continue
            p = os.path.join(dp, fn)
            files += 1
            try:
                data = open(p, "rb").read()
            except OSError:
                bad += 1
                continue
            if data[:4] != b"EV01":
                bad += 1
                continue
            bo = u32(data, 4)
            if bo >= len(data):
                bad += 1
                continue
            blob = data[bo:]
            if len(blob) < 0x3C:
                bad += 1
                continue
            cl, co = u32(blob, 0), u32(blob, 0x30)
            if not (0 < cl < 0x800000 and 0 < co < len(blob)):
                bad += 1
                continue
            end = min(co + cl, len(blob))
            i, hit = co, False
            while i < end:
                op = blob[i]
                if op < 0x80:
                    if op in (0x3C, 0x3D, 0x3E, 0x3F):
                        hist[op] += 1
                        hit = True
                    i += 1
                else:
                    i += 3
            if hit:
                files_with += 1
    return files, bad, files_with, hist


# ── static IDB-audit rows (decompile-verified, see report §3-§4) ─────────────

ARMING_ROWS = [
    # op, stride_u16, total_bytes, tag, param, payload_layout,
    # arm_effect, arm_prereq, verdict
    dict(op="0x07", stride_u16=12, total_bytes=24,
         tag="0x0007 (+optional flags: 0x1000 dead / 0x2000,0x3000,0x4000 "
             "easing / 0x8000 add linkrec origin to x,y)",
         param="duration frames; 0 = silent consume (saved-state only, no draw)",
         payload="+4 u32 colA (lerped->rec+4,unconsumed) +8 u32 colB "
                 "(lerped->rec+8,unconsumed) +12 i16 x +14 u16 y "
                 "+16 i16(lerped,unconsumed) +18 i16(unconsumed) "
                 "+20 i16(unconsumed) +22 u16 DEAD",
         arm_effect="FFX_Render_DrawDebugQuad @0x8FE080 -> "
                    "FFX_Menu2D_DrawQuad_SolidAlpha(\"123456789\",x,y): "
                    "gray dev text at (x,y)+origin for `param` frames",
         arm_prereq="item inside a bound descriptor record; cursor reaches it; "
                    "param>0 for visible draw; same-size in-place arm = patch "
                    "op6 tag 0x0006->0x0007 (both stride 12)",
         verdict="ARMABLE-IN-PRACTICE (safe: menu text draw only)"),
    dict(op="0x09", stride_u16=2, total_bytes=4,
         tag="0x0009 (flags unread by case9)", param="ignored",
         payload="none",
         arm_effect="entry+14 (loop mark) := cursor+2 (u16 offset of item "
                    "after op9); later op8 counter>0 jumps to mark",
         arm_prereq="must precede its op8 in the same record; inert alone "
                    "(no draw, no state change visible without op8)",
         verdict="ARMABLE-IN-PRACTICE (flow op; pairs with op8)"),
    dict(op="0x0A", stride_u16=16, total_bytes=32,
         tag="0x000A (+optional flags, same as op7)",
         param="duration frames; 0 = silent consume",
         payload="+4 u32 colA +8 u32 colB +12 i16 x +14 u16 y "
                 "+16..+24 i16 x5 (all lerped->rec, unconsumed) "
                 "+26 u16 DEAD (never read) +28 i16 ->rec+26 (lerped, "
                 "unconsumed) +30 u16 actorIndex->rec+28=a1[14] "
                 "(lerped — decompiler-verified @0xa7c5e8..0xa7c614)",
         arm_effect="FFX_Render_DrawOverdriveRow @0x8FE040 -> "
                    "FFX_BtlUI_DrawOverdriveCommandRow(actorIndex,x,y): "
                    "162x44 frame + face atlas 440+idx + name x+97 + "
                    "HP/MP/OD gauge y+23",
         arm_prereq="bound record + cursor reach + param>0; reads battle actor "
                    "data (FFX_BtlUI_GetActorDataFloatPtr) — context-correct in "
                    "battle_script.bin; stale/garbage risk in field menus; "
                    "no 32B authored op exists -> insertion+widgetOff fixup "
                    "required (no same-size patch)",
         verdict="ARMABLE-IN-PRACTICE (context caveat: battle-data read)"),
    dict(op=">=0x0B", stride_u16="-", total_bytes="-",
         tag="tag&0x7FF > 0xA", param="-", payload="-",
         arm_effect="NONE — dispatcher default case `continue`s without "
                    "advancing v8 -> HARD INFINITE LOOP @0xA7B728 "
                    "(test edi,edi; jnz loc_A7B580), VM thread hangs",
         arm_prereq="unarmable by construction (hang, not rejection)",
         verdict="DEAD-BY-HANG (negative-control boundary)"),
]

WRITER_ROWS = [
    # slot, addr, insn, kind, verdict, note
    dict(slot="ctrl+0x28", addr="0x86EE47",
         insn="mov dword ptr [edx+28h], 0",
         kind="writer (zero-init)",
         fn="FFX_Field_InitActorSlot @0x86EDA0",
         verdict="ONLY writer of the slot anywhere; writes 0",
         note="edx = &Controllers[568*n3]; part of the callback-block "
              "zero-init (+0x20/+0x28/+0x2C/+0x30/+0x4C/+0x58/+0x5C/+0x60)"),
    dict(slot="ctrl+0x28", addr="0x8711A0",
         insn="(no write)",
         kind="non-writer (defaults installer)",
         fn="FFX_Field_InitScriptWorkerDefaults @0x871130",
         verdict="VERIFIED skips +0x28 — defaults +0x20,+0x2C,+0x4C,+0x58,"
                 "+0x5C,+0x60 only (dword idx 10 untouched)",
         note="=> slot stays 0 for the controller's whole lifetime"),
    dict(slot="ctrl+0x28", addr="0x865079",
         insn="mov ecx,[eax+28h]; test ecx,ecx; jz 0x865083; call ecx",
         kind="reader (guarded call site, EVOP_3C RET)",
         fn="FFX_Field_EventParser @0x864180",
         verdict="null-checked -> fallback StopAndUnbindTriggerNode(actor,-1,0); "
                 "args: fn(actorIdx_u16=worker+0x2E, 0x3C); cdecl; ret discarded",
         note="armed hook REPLACES the unbind-all fallback (hook must do its "
              "own cleanup); fires on every authored RET (88,134 sites)"),
    dict(slot="ctrl+0x28", addr="0x865104",
         insn="mov ecx,[eax+28h]; test ecx,ecx; jz 0x86510E; call ecx",
         kind="reader (guarded call site, EVOP_3E RETT)",
         fn="FFX_Field_EventParser @0x864180",
         verdict="null-checked -> fallback StopAndUnbindTriggerNode(actor,-1,1); "
                 "args: fn(actorIdx_u16, 0x3E); cdecl; ret discarded",
         note="ZERO authored RETT sites in 397 EV01 files (0x3E absent from "
              "corpus; the 6 tail-family sites are op 0x3F RETTN, a different "
              "op) — this call site is reachable in code but never fired by "
              "shipped scripts"),
    dict(slot="ctrl+0x28", addr="0x862CE7",
         insn="mov AtelCurCtrlWork, &Controllers[568*a1]",
         kind="context selector (not a field write)",
         fn="FFX_Field_SwitchContextSlot @0x862CD0",
         verdict="proves AtelCurCtrlWork = &Controllers[568*slot]; "
                 "ctrl+0x28 VA = 0x1325B88 + 0x238*slot",
         note="PushScriptContext @0x860FC0 saves/restores the pointer only"),
    dict(slot="ctrl+0x28", addr="(exe-wide)",
         insn="-", kind="unguarded readers / non-zero writers",
         fn="-",
         verdict="NONE — +28h sweep over 0x860000-0x880000 (all 108 "
                 "AtelCurCtrlWork fns + all 75 Controllers-xref fns live in "
                 "range) + 0 direct xrefs to Controllers+0x28 (0x1325B88)",
         note="every +28h write hit audited: EventStruct, event-resource "
              "352B array, AiScriptStateMachine worker ctx, SaveRam, actor "
              "table, debug struct — none is the controller"),
]


def main(argv):
    rows, hist, other = desc_census()
    efiles, ebad, ewith, ehist = ebp_ret_census(CORPUS)
    for r in rows:
        print("%-42s rec=%s err=%d items=%-4d op7=%d op9=%d opA=%d"
              % (r["file"], r["records"], r["parse_errors"], r["items"],
                 r["op7_items"], r["op9_items"], r["opA_items"]))
    print("full (base,flag) histogram:", dict(sorted(hist.items())))
    print("other descriptor streams under menu/:", other or "none")
    print("EV01 .ebp: %d files (%d bad) — RET family sites %s; files "
          "containing: %d" % (efiles, ebad, dict(sorted(ehist.items())), ewith))
    if "--stdout" in argv:
        return 0
    os.makedirs(OUTDIR, exist_ok=True)
    p1 = os.path.join(OUTDIR, "ops_dormant_arming.csv")
    with open(p1, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(ARMING_ROWS[0].keys()))
        w.writeheader()
        w.writerows(ARMING_ROWS)
    p2 = os.path.join(OUTDIR, "ops_dormant_writers.csv")
    with open(p2, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(WRITER_ROWS[0].keys()))
        w.writeheader()
        w.writerows(WRITER_ROWS)
    print("wrote %s + %s" % (p1, p2))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
