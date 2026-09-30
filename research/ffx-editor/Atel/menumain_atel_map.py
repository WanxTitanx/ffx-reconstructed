#!/usr/bin/env python3
"""menumain.bin ATEL worker/entry-point mapper (Jarvis-MENUMENU-ATEL).

Parses the legacy ATEL script at master/<loc>pc/menu/menumain.bin (the
in-menu tutorial driver), enumerates its workers + entry-point table,
linear-sweeps each EP region, and emits a CSV inventory plus a JSON
report used by docs/reverse/FFX_MENUMAIN_ATEL_2026-09-18.md.

Proven native anchors (ffxoficial.exe):
  * Worker "func table" (desc +0x20, count at +0x08) IS the entry-point
    table: FFX_FieldActor_InitPriorityNode @0x869040 reads
    *(desc+0x20)[node.ev] and stores it as the worker's resume pc
    (workerCtx+24 = scriptBase + codeStart + epOffset).
  * Node ev = u16 at node+8, queued by REQ-family opcodes
    (FFX_AtelOp_QueueActorNodeType0 family) or by the menu path
    FFX_MenuPad_ReadTriggerEdge_A @0x8BE340 -> QueuePayloadNodeIfAbsent.
  * The script is instantiated into context slot 6 by
    FFX_MenuPad_ReadTriggerEdge_B @0x8BE370 ->
    FFX_Field_InitActorsFromScript(6, &atelactorbuf_, 0x1576F30,
    0x157EF30) where 0x1576F30 holds menu/menumain.bin (Mscd group
    0x12 slot 0xC) and 0x157EF30 holds the string blob loaded by
    FFX_Scene_LoadPakGroup("menumain") from new_<loc>pc/menu/menumain.bin.

Usage:
  menumain_atel_map.py <menumain.bin> [<menumain2.bin> ...]
  menumain_atel_map.py --csv out.csv jp.bin us.bin
"""
import csv
import json
import struct
import sys
import os

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from atel_disasm import AtelBlob, OPS  # noqa: E402

# Common-namespace funcIds referenced by this script, resolved via the
# ATEL call-target census (work/_atel_tbl/atel_map.csv, raw slot +0x0C =
# int-return handler invoked by FFX_Atel_CallReturnDispatchByNamespace).
COMMON_HANDLERS = {
    0x02D: ("FFX_FieldVM_Op_SetActorFloat86F060", 0x857F10),
    0x061: ("FFX_FieldVM_Op_SetActorPositionScalar", 0x857020),
    0x062: ("FFX_FieldOp_SetFloatAtOffset68", 0x857180),
    0x063: ("FFX_FieldOp_SetFloatOffset60", 0x857390),
    0x064: ("FFX_Atel_Common_displayFieldString_CALL", 0x857710),
    0x065: ("FFX_AtelOp_CreateEventStructWithLocaleFixup", 0x857F60),
    0x066: ("FFX_FieldVM_Op_WriteByteToActorStruct", 0x8581D0),
    0x069: ("FFX_FieldOp_StoreTwoBytesAtStruct", 0x858810),
    0x06A: ("FFX_Atel_Common_DrawItemChoiceList", 0x8589F0),
    0x06B: ("FFX_FieldVM_Op_SetListItemSelect", 0x858F00),
    0x06C: ("FFX_FieldVM_Op_SetActorFloat86F2E0", 0x857E30),
    0x06D: ("FFX_FieldOp_PopFloatCall86F150", 0x85AA40),
    0x06E: ("FFX_FieldOp_PopFloatCall86F100", 0x85AD00),
    0x06F: ("FFX_FieldOp_PopFloatCall86F240", 0x85ADD0),
    0x070: ("FFX_FieldOp_PopFloatCall86F1F0", 0x85B0D0),
    0x071: ("FFX_FieldOp_PopFloatCall86F1A0", 0x85B320),
    0x074: ("FFX_FieldOp_PopAiJumpHandler", 0x85BC60),
    0x076: ("FFX_FieldOp_GetActorScriptType", 0x85F420),
    0x085: ("FFX_FieldOp_SetFloatOffset72", 0x856300),
    0x08D: ("FFX_FieldOp_SetFloatOffset76", 0x857660),
    0x0E4: ("FFX_Atel_Common_Func00E4_FLOATRET", 0x85AED0),
}

WORKER_TYPE = {0: "System", 1: "FieldObject", 2: "PlayerEdge", 3: "Zone",
               4: "Scenario", 5: "Edge", 6: "ZoneEdge"}


def sweep_region(blob, start, end):
    """Linear-sweep one EP region (code-relative offsets -> insns)."""
    ins = []
    pos = start
    while pos < end:
        op = blob.b[blob.code_off + pos]
        if op & 0x80:
            arg = struct.unpack_from("<H", blob.b, blob.code_off + pos + 1)[0]
            ins.append((pos, op, arg))
            pos += 3
        else:
            ins.append((pos, op, None))
            pos += 1
    return ins


def region_stats(ins):
    calls, strids, reqs, pushes = [], [], [], 0
    for i, (pc, op, arg) in enumerate(ins):
        name = OPS.get(op, "?")
        if op in (0xB5, 0xD8):
            calls.append((pc, name, arg))
            # displayFieldString(evIdx, strId): strId is the operand of
            # the PUSHII immediately preceding CALLPOPA 0x64.
            if arg == 0x64:
                for j in range(i - 1, max(0, i - 6), -1):
                    if ins[j][1] in (0xAD, 0xAE):
                        strids.append(ins[j][2])
                        break
        if op in (0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x45, 0x46, 0x47,
                  0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50,
                  0x51, 0x52, 0x53, 0x77, 0x78):
            reqs.append((pc, name, arg))
        if op in (0xAD, 0xAE, 0xAF):  # PUSHI/PUSHII/PUSHF const
            pushes += 1
    return calls, sorted(set(strids)), reqs, pushes


def analyze(path, locale):
    blob = AtelBlob(path)
    rep = {"path": path, "locale": locale, "size": len(blob.b),
           "codeLen": blob.code_len, "codeOff": blob.code_off,
           "totalLen": blob.total_len,
           "creator": _cstr(blob.b, blob.creator_off),
           "scriptName": _cstr(blob.b, blob.script_id_off),
           "workerCount": blob.worker_count,
           "actorCount": blob.actor_count, "workers": []}
    rows = []
    for wi, w in enumerate(blob.workers):
        eps = sorted(w["funcs"])
        jumps = sorted(w["jumps"])
        wrec = {"index": wi, "descOff": w["off"],
                "eventType": w["eventType"],
                "typeName": WORKER_TYPE.get(w["eventType"], "?"),
                "varCount": w["varCount"], "entryPoints": eps,
                "jumpEntries": jumps, "regions": []}
        FAMILY = {(0, 2): "SphereGrid tutorial", (0, 3): "SG lock/select",
                  (0, 4): "Customize tutorial",
                  (0, 5): "Aeon abilities/Summoner's Soul",
                  (0, 6): "Aeon attributes/Aeon's Soul",
                  (0, 7): "tail (hosts w1 EP0)", (0, 0): "init stub",
                  (0, 1): "init stub", (1, 0): "menu actor pos/motion init"}
        bounds = eps[1:] + [blob.code_len]
        for ei, ep in enumerate(eps):
            end = bounds[ei]
            ins = sweep_region(blob, ep, min(end, blob.code_len))
            calls, strids, reqs, pushes = region_stats(ins)
            uniq = []
            for _, _, f in calls:
                if f not in uniq:
                    uniq.append(f)
            fids = [f"0x{f:03x}x{sum(1 for _,_,g in calls if g==f)}"
                    for f in uniq]
            handlers = []
            for f in uniq:
                h = COMMON_HANDLERS.get(f)
                handlers.append(h[0] if h else f"Common_0x{f:03x}")
            wrec["regions"].append({
                "ep": ei, "off": ep, "end": end, "insns": len(ins),
                "calls": fids, "strIdRange":
                    (f"{min(strids)}-{max(strids)}" if strids else ""),
                "strIds": strids, "reqs": [n for _, n, _ in reqs],
                "pushes": pushes})
            rows.append({
                "locale": locale, "worker": wi, "desc_off": hex(w["off"]),
                "event_type": w["eventType"],
                "type_name": wrec["typeName"], "ep_index": ei,
                "code_off": hex(ep),
                "code_range": f"0x{ep:x}-0x{end:x}",
                "insns": len(ins),
                "call_sites": "; ".join(fids),
                "handlers": "; ".join(handlers),
                "strid_range": (f"{min(strids)}-{max(strids)}"
                                if strids else ""),
                "req_ops": "; ".join(n for _, n, _ in reqs),
                "family": FAMILY.get((wi, ei), "")})
        rep["workers"].append(wrec)
    return rep, rows


def _cstr(b, o):
    if o <= 0 or o >= len(b):
        return ""
    e = b.find(b"\x00", o)
    return b[o:e if e >= 0 else len(b)].decode("ascii", "replace")


def main():
    args = sys.argv[1:]
    csv_path = None
    if args and args[0] == "--csv":
        csv_path = args[1]
        args = args[2:]
    if not args:
        print(__doc__)
        return 1
    all_rows, reports = [], []
    for p in args:
        loc = "us" if "uspc" in p else ("jp" if "jppc" in p else "?")
        rep, rows = analyze(p, loc)
        reports.append(rep)
        all_rows += rows
        w0 = rep["workers"][0]
        print(f"{loc}: {rep['path']}")
        print(f"  size={rep['size']} codeLen=0x{rep['codeLen']:x} "
              f"creator={rep['creator']!r} name={rep['scriptName']!r} "
              f"workers={rep['workerCount']} actors={rep['actorCount']}")
        for w in rep["workers"]:
            print(f"  worker{w['index']} type={w['eventType']}"
              f"({w['typeName']}) desc@0x{w['descOff']:x} "
              f"eps={len(w['entryPoints'])} jumps={w['jumpEntries']}")
            for r in w["regions"]:
                print(f"    ep{r['ep']} 0x{r['off']:04x}-0x{r['end']:04x} "
                      f"insns={r['insns']} strIds={r['strIdRange'] or '-'} "
                      f"calls={len(r['calls'])} reqs={len(r['reqs'])}")
    if csv_path:
        with open(csv_path, "w", newline="") as f:
            wr = csv.DictWriter(f, fieldnames=list(all_rows[0].keys()))
            wr.writeheader()
            wr.writerows(all_rows)
        print("csv ->", csv_path)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
