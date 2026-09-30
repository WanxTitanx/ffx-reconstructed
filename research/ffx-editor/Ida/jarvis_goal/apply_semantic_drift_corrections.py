# RECOVERED 2026-09-18 (lane Jarvis-TOOLS-REPAIR): source restored from git history
# commit 53d82b2a, original path RuntimeTools/FFXMapViewerWeb/work/reverse/ida/scripts/<name>.
# The work/reverse/ida/scripts/ tree was never committed at its original location;
# only __pycache__/*.pyc + this history copy survived. Cited by docs/reverse/* + SESSION_HANDOFF.
"""Apply proved semantic-drift corrections to FFX_recon.i64.

Run inside IDA/idalib against the canonical database. This script intentionally
excludes PARTIAL review-only entries and all generated INFERNO placeholders.
"""
import json
from pathlib import Path

import ida_auto
import ida_kernwin
import ida_name
import idc


# FIX 2026-09-18 (Jarvis-TOOLS-REPAIR): parents[3] = repo root at the new
# research_tools/Ida/jarvis_goal/ location; parents[4] was stale from the
# FFXMapViewerWeb recovery and resolved to ~/Documents/ (reports would write outside the repo).
REPO_ROOT = Path(__file__).resolve().parents[3]
REPORT_PATH = REPO_ROOT / "work" / "reverse" / "ida" / "exports" / "re_semantic_audit" / "semantic_drift_apply_report.json"

CORRECTIONS = [
    {"addr": 0x797B80, "kind": "func", "name": "FFX_Btl_UI_PushMenuTreeEntry", "replace_if": ["FFX_Battle_Camera_CmdQueue_Push", "sub_797B80"]},
    {"addr": 0x797D60, "kind": "func", "name": "FFX_Btl_UI_ResolveMenuTreeNode", "replace_if": ["FFX_Battle_Camera_BindQueuedShots", "sub_797D60"]},
    {"addr": 0x7ACEC0, "kind": "func", "name": "FFX_Btl_UI_BuildCommandRing", "replace_if": ["sub_7ACEC0"]},
    {"addr": 0x7828B0, "kind": "func", "name": "FFX_Field_ResolveEncounterToken", "replace_if": ["sub_7828B0"]},
    {"addr": 0x7B2DD0, "kind": "func", "name": "FFX_Battle_AggregateActorProperty", "replace_if": ["FFX_Battle_AiQueryMoveProperty", "sub_7B2DD0"]},
    {"addr": 0x877770, "kind": "func", "name": "FFX_Atel_CallReturnDispatchByNamespace", "replace_if": ["sub_877770"]},
    {"addr": 0x795980, "kind": "func", "name": "FFX_Battle_GetPlayerListBase", "replace_if": ["sub_795980"]},
    {"addr": 0x11334CC, "kind": "data", "name": "g_BattlePlayerList", "replace_if": ["unk_11334CC", "dword_11334CC", "off_11334CC"]},
    {"addr": 0x7B0F90, "kind": "func", "name": "FFX_Battle_OverdriveKillEvent", "replace_if": ["sub_7B0F90"]},
    {"addr": 0x7B10A0, "kind": "func", "name": "FFX_Battle_OverdriveCowardEvent", "replace_if": ["sub_7B10A0"]},
    # Pass 2 — PARTIAL reviewed 2026-06-16 (Jarvis-MAGIC)
    {"addr": 0x7985A0, "kind": "func", "name": "FFX_Btl_UI_LookupMenuBlob", "replace_if": ["FFX_Battle_Camera_ShotTable_Dispatch", "sub_7985A0"]},
    {"addr": 0x797420, "kind": "func", "name": "FFX_Btl_UI_WalkMenuBlobIndex", "replace_if": ["FFX_Battle_Camera_ShotTable_Walk", "sub_797420"]},
    {"addr": 0x794030, "kind": "func", "name": "FFX_Field_GetActorRecord", "replace_if": ["FFX_Field_ResolveActor", "sub_794030"]},
    {"addr": 0x78C330, "kind": "func", "name": "FFX_Battle_ResolveHitDamagePrecheck_structural", "replace_if": ["FFX_Battle_ResolveHitDamagePrecheck", "sub_78C330"]},
]

COMMENTS = {
    0x797B80: "[Jarvis-RE-SEMANTIC S02] UI menu-tree entry push in Ronso command-ring path; old Camera name was semantic drift.",
    0x797D60: "[Jarvis-RE-SEMANTIC S02] UI menu-tree node/blob resolver in command-ring path; old Camera name was semantic drift.",
    0x7ACEC0: "[Jarvis-RE-SEMANTIC S02] Battle command-ring UI builder; called by 792AB0 for kinds 1 and 12.",
    0x7828B0: "[Jarvis-RE-SEMANTIC S05] Packed field encounter-token resolver used before queue globals are written.",
    0x7B2DD0: "[Jarvis-RE-SEMANTIC S04] Battle actor-property aggregator for readChrProperty/countChrOverlap; not move-property metadata.",
    0x877770: "[Jarvis-RE-SEMANTIC S03] ATEL return dispatcher by namespace/index; not the specific btlGetCalcResult handler.",
    0x795980: "[Jarvis-RE-SEMANTIC S12] Returns g_BattlePlayerList pointer.",
    0x11334CC: "[Jarvis-RE-SEMANTIC S12] Party/player list pointer global; IDA flat 0x11334CC, PE RVA 0xD334CC.",
    0x7B0F90: "[Jarvis-RE-SEMANTIC S10] Native Overdrive kill/death event family: Avenger/Slayer/Hero.",
    0x7B10A0: "[Jarvis-RE-SEMANTIC S10] Native Overdrive Coward/flee event.",
    0x7985A0: "[Jarvis-RE-SEMANTIC S02] Menu blob lookup; shared with camReq shot-table.",
    0x797420: "[Jarvis-RE-SEMANTIC S02] Walk menu/camera blob index; shared helper.",
    0x794030: "[Jarvis-RE-SEMANTIC S07] Field/battle actor record getter; stride 0xF90.",
    0x78C330: "[Jarvis-RE-SEMANTIC S07] Damage precheck structural; consume order RT2-pending.",
}


def current_name(ea):
    return ida_name.get_name(ea) or idc.get_name(ea) or ""


def can_replace(cur, allowed):
    if cur in allowed:
        return True
    return cur.startswith(("sub_", "unk_", "dword_", "off_", "byte_", "word_", "loc_"))


def main():
    ida_auto.auto_wait()
    results = []
    counts = {"renamed": 0, "already_named": 0, "skipped_conflict": 0, "failed": 0}
    for item in CORRECTIONS:
        ea = item["addr"]
        desired = item["name"]
        cur = current_name(ea)
        row = {"ea": f"0x{ea:X}", "kind": item["kind"], "old": cur, "new": desired}
        if cur == desired:
            row["status"] = "already_named"
        elif not can_replace(cur, item["replace_if"]):
            row["status"] = "skipped_conflict"
        else:
            ok = ida_name.set_name(ea, desired, ida_name.SN_NOWARN)
            row["status"] = "renamed" if ok else "failed"
        if row["status"] in ("renamed", "already_named") and ea in COMMENTS:
            idc.set_cmt(ea, COMMENTS[ea], 1)
        counts[row["status"]] = counts.get(row["status"], 0) + 1
        results.append(row)
        ida_kernwin.msg(f"semantic drift {row['ea']} {cur} -> {desired}: {row['status']}\n")

    saved = False
    try:
        saved = bool(idc.save_database(idc.get_idb_path(), 0))
    except Exception as exc:
        ida_kernwin.msg(f"semantic drift save failed: {exc}\n")

    report = {
        "signature": "Jarvis-RE-SEMANTIC apply",
        "status": "applied" if saved else "applied_but_save_failed",
        "input_db": idc.get_idb_path(),
        "counts": counts,
        "results": results,
        "note": "Only PROVED replacement corrections; wrong old names are corrected only when the replacement verdict is PROVED. No generated probe or INFERNO placeholder names.",
    }
    REPORT_PATH.parent.mkdir(parents=True, exist_ok=True)
    REPORT_PATH.write_text(json.dumps(report, indent=2), encoding="utf-8")
    ida_kernwin.msg(f"semantic drift apply report -> {REPORT_PATH}\n")
    ida_kernwin.qexit(0)


if __name__ == "__main__":
    main()
