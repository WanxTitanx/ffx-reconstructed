# RECOVERED 2026-09-18 (lane Jarvis-TOOLS-REPAIR): source restored from git history
# commit 53d82b2a, original path RuntimeTools/FFXMapViewerWeb/work/reverse/ida/scripts/<name>.
# The work/reverse/ida/scripts/ tree was never committed at its original location;
# only __pycache__/*.pyc + this history copy survived. Cited by docs/reverse/* + SESSION_HANDOFF.
"""Apply Seymour native-layer renames proved on 2026-06-29.

Run inside IDA/idalib against the canonical database. This script is intentionally
small and idempotent: it only replaces generic auto names or explicitly stale
aliases for the Seymour/Anima native battle-scene package.
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
REPORT_PATH = (
    REPO_ROOT
    / "work"
    / "reverse"
    / "ida"
    / "exports"
    / "seymour_native"
    / "apply_seymour_native_renames_20260629_report.json"
)

RENAMES = [
    {
        "addr": 0x7A4F40,
        "kind": "func",
        "name": "FFX_Atel_Battle_PerformCommand_CALLPOPA",
        "replace_if": ["sub_7A4F40"],
    },
    {
        "addr": 0x7A4E80,
        "kind": "func",
        "name": "FFX_Atel_Battle_ClearActorCommandState_CALL_structural",
        "replace_if": ["sub_7A4E80"],
    },
    {
        "addr": 0x79EBC0,
        "kind": "func",
        "name": "FFX_Battle_ExecutePackedCommand",
        "replace_if": ["sub_79EBC0"],
    },
    {
        "addr": 0x79EB30,
        "kind": "func",
        "name": "FFX_Battle_ExecutePackedCommandCore",
        "replace_if": ["sub_79EB30"],
    },
    {
        "addr": 0x7A5A30,
        "kind": "func",
        "name": "FFX_Atel_Battle_SceneCleanupPoll",
        "replace_if": ["sub_7A5A30"],
    },
    {
        "addr": 0x788EB0,
        "kind": "func",
        "name": "FFX_Battle_PackCommandHandle",
        "replace_if": ["sub_788EB0"],
    },
    {
        "addr": 0x112A8E5,
        "kind": "data",
        "name": "g_BattleSceneTypeFlag_candidate",
        "replace_if": ["unk_112A8E5", "byte_112A8E5"],
    },
    {
        "addr": 0x112CA09,
        "kind": "data",
        "name": "g_BattleFlowStatusByte_candidate",
        "replace_if": ["unk_112CA09", "byte_112CA09"],
    },
]

COMMENTS = {
    0x7A4F40: "[Jarvis-SEYMOUR-NATIVE] Real ATEL performCommand handler. Pops three operands, resolves target mask, and routes into the generic packed-command execution pipeline. No special-case branch for 0x6051.",
    0x7A4E80: "[Jarvis-SEYMOUR-NATIVE] Clears actor command-state fields 0x415/0x417 for the selected actor slot. This is command-state cleanup, not summon/dismiss logic.",
    0x79EBC0: "[Jarvis-SEYMOUR-NATIVE] Wrapper around the generic packed-command execution path used by performCommand.",
    0x79EB30: "[Jarvis-SEYMOUR-NATIVE] Core packed-command executor. Increments command counters, packs the handle, and hands off to the generic battle action executor.",
    0x7A5A30: "[Jarvis-SEYMOUR-NATIVE] Scene cleanup/poll opcode. Reads n2_6, qualifies scene flags/status bytes, and returns 5 only when the scene has fully settled.",
    0x788EB0: "[Jarvis-SEYMOUR-NATIVE] Packs command handle as counter<<16 | mode<<8 | slot. This helper is not the row lookup itself.",
    0x112A8E5: "[Jarvis-SEYMOUR-NATIVE] Provisional scene-type qualifier for the n2_6 battle-scene gate. 1 behaves like the 'large scene' case in the native flow.",
    0x112CA09: "[Jarvis-SEYMOUR-NATIVE] Provisional battle-flow status byte touched by scene cleanup and rendered by the native debug HUD.",
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
    for item in RENAMES:
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
        ida_kernwin.msg(f"seymour native rename {row['ea']} {cur} -> {desired}: {row['status']}\n")

    saved = False
    try:
        saved = bool(idc.save_database(idc.get_idb_path(), 0))
    except Exception as exc:
        ida_kernwin.msg(f"seymour native save failed: {exc}\n")

    report = {
        "signature": "Jarvis-SEYMOUR-NATIVE apply",
        "status": "applied" if saved else "applied_but_save_failed",
        "input_db": idc.get_idb_path(),
        "counts": counts,
        "results": results,
        "note": "Applies only the proved Seymour native-layer rename queue from 2026-06-29.",
    }
    REPORT_PATH.parent.mkdir(parents=True, exist_ok=True)
    REPORT_PATH.write_text(json.dumps(report, indent=2), encoding="utf-8")
    ida_kernwin.msg(f"seymour native rename report -> {REPORT_PATH}\n")
    ida_kernwin.qexit(0)


if __name__ == "__main__":
    main()
