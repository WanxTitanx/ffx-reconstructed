# RECOVERED 2026-09-18 (lane Jarvis-TOOLS-REPAIR): source restored from git history
# commit 53d82b2a, original path RuntimeTools/FFXMapViewerWeb/work/reverse/ida/scripts/<name>.
# The work/reverse/ida/scripts/ tree was never committed at its original location;
# only __pycache__/*.pyc + this history copy survived. Cited by docs/reverse/* + SESSION_HANDOFF.
"""Apply INFERNO/M26 semantic IDA renames to FFX_recon.i64 (headless).

Skips auto-generated INFERNO placeholder names (FFX_I##_*, Jarvis_RE_Inferno_*).
Only promotes sub_/unk_ symbols when a proved FFX_* name exists in repo docs.
"""
import json
from pathlib import Path

import ida_auto
import ida_funcs
import ida_kernwin
import ida_name
import idc

# FIX 2026-09-18 (Jarvis-TOOLS-REPAIR): parents[3] = repo root at the new
# research_tools/Ida/jarvis_goal/ location; parents[4] was stale from the
# FFXMapViewerWeb recovery and resolved to ~/Documents/ (reports would write outside the repo).
REPO_ROOT = Path(__file__).resolve().parents[3]
REPORT_PATH = REPO_ROOT / "work" / "reverse" / "ida" / "exports" / "re_inferno" / "inferno_semantic_rename_apply_report.json"

# addr, desired_name, repeatable_comment
RENAMES = [
    (
        0x00781D60,
        "FFX_Field_RequestEncounterTransition",
        "[proved INFERNO I13/M26] Field VM wrapper -> sub_7828B0; queues battle transition globals.",
    ),
    (
        0x007A3550,
        "FFX_Battle_LaunchBattle",
        "[proved INFERNO I13/M26] ATEL launchBattle [7002]: pops VM operands, calls RequestEncounterTransition.",
    ),
    (
        0x007817C0,
        "FFX_Battle_QueueGateCheck",
        "[proved M26] Encounter queue gate; many field/battle callers.",
    ),
    (
        0x007B15A0,
        "FFX_Battle_OverdriveAddClamp",
        "[proved INFERNO I06/M26] OD charge add/clamp on actor+0x5BC/+0x5BD.",
    ),
    (
        0x007B0D60,
        "FFX_Battle_OverdriveDamageHealEvent",
        "[proved M26] OD event on damage/heal path; calls OverdriveAddClamp.",
    ),
    (
        0x007B12D0,
        "FFX_Battle_OverdriveStatusEvent",
        "[proved M26] OD event on status/evasion branch.",
    ),
    (
        0x007B13D0,
        "FFX_Battle_CtbEdgeOverdriveEvent",
        "[proved M26] OD event on CTB turn-edge.",
    ),
    (
        0x007B1550,
        "FFX_Battle_OverdriveVictorEvent",
        "[proved M26] OD event on battle victory.",
    ),
    (
        0x00794030,
        "FFX_Field_ResolveActor",
        "[proved M26] MemoryChr / actor record lookup.",
    ),
    (
        0x007861B0,
        "FFX_Field_RecomputeStats",
        "[proved INFERNO I23/M26] Save->battle stat sync; command learn tables.",
    ),
    (
        0x007B2DD0,
        "FFX_Battle_AiQueryMoveProperty",
        "[proved INFERNO I24/I08] AI move property getter; Nul cases 49-57 incl +0x613/+0x614.",
    ),
    (
        0x007B4B80,
        "FFX_Btl_ATEL_ApplyActorOpcode",
        "[proved INFERNO I24] ATEL actor property writer; cases 56/57 -> +0x613/+0x614.",
    ),
    (
        0x007A50E0,
        "FFX_Btl_ATEL_DispatchOpcode",
        "[proved NUL matrix] ATEL opcode dispatch -> ApplyActorOpcode.",
    ),
    (
        0x0078C330,
        "FFX_Battle_ResolveHitDamagePrecheck",
        "[proved INFERNO I24] Pre-damage helper; null/absorb/reflect result codes before writeback.",
    ),
    (
        0x0079C090,
        "FFX_Btl_SetActorCommandBit",
        "[proved INFERNO I20] Runtime per-char command bit setter (twin of IsCommandAvailable).",
    ),
    (
        0x00897F80,
        "FFX_Battle_SubmenuOvrRowBuild",
        "[proved Ronso IDA] Submenu greyout row builder; charge/max ratio per command.",
    ),
    (
        0x008661E0,
        "FFX_Battle_InitBattleAndScheduleEntry",
        "[proved INFERNO I13/Arena+] Schedules battle entry FSM after btlbin init.",
    ),
    (
        0x0072C570,
        "FFX_MagicHost_LinkResourceBufferRange",
        "[proved INFERNO I18/Thundafira] Magic host resource buffer linker (KeThRes lane).",
    ),
    (
        0x00792AB0,
        "FFX_Btl_BattleMenuInputDispatch",
        "[proved Ronso middle-ring] Battle menu input dispatch.",
    ),
    (
        0x007ACEC0,
        "FFX_Btl_UI_BuildCommandRing",
        "[proved Ronso middle-ring] UI command ring builder.",
    ),
    (
        0x0088E9D0,
        "FFX_Scene_RequestTransition",
        "[proved INFERNO I26] Field scene transition request.",
    ),
    (
        0x0088DFE0,
        "FFX_Scene_InitScene",
        "[proved INFERNO I26] Scene init / TK:Init Scene.",
    ),
    (
        0x008AB780,
        "FFX_Res_GetPathByGroupIndex",
        "[proved INFERNO I26] ResMgr group/index path resolver.",
    ),
    (
        0x00A42830,
        "FFX_Res_GetEventObjPathForIndex",
        "[proved INFERNO I26] Event /event/obj path index resolver.",
    ),
    (
        0x00773CF0,
        "FFX_Scan_IsLearnedWrapper",
        "[proved INFERNO I22] Thin Scan learned check -> command 0x3032.",
    ),
    (
        0x0079AD40,
        "FFX_Btl_IsCommandAvailable",
        "[proved INFERNO I19/I20] Battle menu command bit read gate.",
    ),
    (
        0x0079BB70,
        "FFX_Btl_BuildActorCommandMenu",
        "[proved INFERNO I19/I20] Builds actor command menu; loops id < 320.",
    ),
    (
        0x007850E0,
        "FFX_IsCommandLearnedPersistent",
        "[proved INFERNO I20] Persistent learned-command test.",
    ),
    (
        0x00785D10,
        "FFX_GrantCommandToCharacter",
        "[proved INFERNO I20] Grant command to per-char bank.",
    ),
    (
        0x00790AE0,
        "FFX_Kernel_GetCommandEntryById",
        "[proved INFERNO I03] command.bin row lookup by id.",
    ),
    (
        0x007AB890,
        "FFX_Table_GetEntryByIdRange",
        "[proved INFERNO I03] Generic range table lookup.",
    ),
    (
        0x00789800,
        "FFX_Battle_ApplyHitDamage_Loop",
        "[proved INFERNO I04] Multi-hit damage apply loop.",
    ),
    (
        0x00789CB0,
        "FFX_Battle_DamageFormulaDispatch",
        "[proved INFERNO I04] Damage formula dispatch hub.",
    ),
    (
        0x0078A420,
        "FFX_Battle_ApplyElementResist",
        "[proved INFERNO I04] Element resist application.",
    ),
    (
        0x0078E680,
        "FFX_Battle_ComputeHitDamage",
        "[proved INFERNO I04] Core hit damage computation + clamp.",
    ),
    (
        0x00872E90,
        "FFX_Event_LoadObjResources",
        "[proved INFERNO I26] Loads /event/obj EV/BIN/FTC for scene.",
    ),
    (
        0x0080CD60,
        "FFX_Magic_RunRuntimeRootPhase_structural",
        "[proved INFERNO I16] Magic VM root runtime phase (structural).",
    ),
    (
        0x0080BEA0,
        "FFX_Magic_RunAuxRuntimeRootPass_structural",
        "[proved INFERNO I16] Magic aux runtime root pass (structural).",
    ),
    (
        0x00906420,
        "FFX_Magic_BuildPs3MagicTexturePath",
        "[proved INFERNO I17] PS3Data magic texture path builder.",
    ),
    (
        0x007A4D70,
        "FFX_Atel_Battle_readChrProperty_CALL",
        "[proved I08] ATEL Battle readChrProperty CALL handler.",
    ),
    (
        0x00795560,
        "FFX_Battle_GetOvrCharge",
        "[proved Ronso IDA] Read actor OD charge byte.",
    ),
    (
        0x008953F0,
        "FFX_Battle_OverdriveReadyGate",
        "[proved Ronso IDA] OD ready / menu gate.",
    ),
    (
        0x007810F0,
        "FFX_Battle_InitEncounterFromBtlbin",
        "[proved music/battle] btl.bin encounter kernel loader.",
    ),
    (
        0x007830D0,
        "FFX_BattleScene_InitStateMachine",
        "[proved AI/battle] Battle scene ATEL state machine init.",
    ),
    (
        0x00790C60,
        "FFX_Btl_MainBattleTick",
        "[proved Ronso catalog] Main battle tick loop.",
    ),
    (
        0x00D334CC,
        "g_BattlePlayerList",
        "[proved M26/Ronso] Party list pointer global.",
    ),
]


def is_default_name(name: str) -> bool:
    return (
        not name
        or name.startswith("sub_")
        or name.startswith("nullsub_")
        or name.startswith("loc_")
        or name.startswith("off_")
        or name.startswith("dword_")
        or name.startswith("qword_")
        or name.startswith("byte_")
        or name.startswith("word_")
        or name.startswith("unk_")
    )


def apply_name(ea: int, desired_name: str):
    current_name = ida_name.get_name(ea) or ""
    if current_name == desired_name:
        return {"status": "already_named", "old_name": current_name, "new_name": desired_name}

    if current_name and not is_default_name(current_name):
        return {"status": "skipped_name_conflict", "old_name": current_name, "new_name": desired_name}

    ok = ida_name.set_name(ea, desired_name, ida_name.SN_NOWARN)
    return {
        "status": "renamed" if ok else "rename_failed",
        "old_name": current_name,
        "new_name": desired_name,
    }


def main():
    ida_auto.auto_wait()
    ida_kernwin.msg("apply_inferno_semantic_renames: start\n")

    results = []
    counts = {"renamed": 0, "already_named": 0, "skipped_name_conflict": 0, "rename_failed": 0}

    for ea, name, comment in RENAMES:
        row = {"ea": f"0x{ea:X}", "desired_name": name, "comment": comment}
        row.update(apply_name(ea, name))
        if row["status"] == "renamed" or row["status"] == "already_named":
            idc.set_cmt(ea, comment, 1)
        results.append(row)
        counts[row["status"]] = counts.get(row["status"], 0) + 1
        ida_kernwin.msg(f"  {row['ea']} {row.get('old_name','')} -> {name}: {row['status']}\n")

    report = {
        "script": "apply_inferno_semantic_renames.py",
        "input_db": idc.get_idb_path(),
        "total": len(RENAMES),
        "counts": counts,
        "results": results,
        "note": "Did NOT apply 160 INFERNO placeholder renames (FFX_I##_*) from doc generator.",
    }
    REPORT_PATH.parent.mkdir(parents=True, exist_ok=True)
    REPORT_PATH.write_text(json.dumps(report, indent=2), encoding="utf-8")
    ida_kernwin.msg(f"apply_inferno_semantic_renames: done -> {REPORT_PATH}\n")
    ida_kernwin.qexit(0)


if __name__ == "__main__":
    main()
