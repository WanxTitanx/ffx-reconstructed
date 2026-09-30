#!/usr/bin/env python3
# RECOVERED 2026-09-18 (lane Jarvis-TOOLS-REPAIR): source restored from git history
# commit 53d82b2a, original path RuntimeTools/FFXMapViewerWeb/work/reverse/ida/scripts/<name>.
# The work/reverse/ida/scripts/ tree was never committed at its original location;
# only __pycache__/*.pyc + this history copy survived. Cited by docs/reverse/* + SESSION_HANDOFF.
"""Plan the next Jarvis naming-goal batch from the Magic core opcode table."""

from __future__ import annotations

import json
import re
from pathlib import Path


# FIX 2026-09-18 (Jarvis-TOOLS-REPAIR): parents[3] = repo root at the new
# research_tools/Ida/jarvis_goal/ location; parents[4] was stale from the
# pre-relocation scratch path and resolved to ~/Documents/.
ROOT = Path(__file__).resolve().parents[3]
DOC = ROOT / "docs/reverse/FFX_MAGIC_TIMELINE_VM_OPCODE_TABLES_2026-06-14.md"
REPLAY = ROOT / "work/reverse/ida/scripts/apply_jarvis_goal_renames_20260617.py"
CLUSTERS = ROOT / "work/magic_vm_cluster/cluster_assignments_pass3.csv"


def _func_rows() -> set[int]:
    text = REPLAY.read_text(encoding="utf-8")
    block = re.search(r'FUNC_ROWS = """([\s\S]*?)"""', text)
    if not block:
        raise RuntimeError("FUNC_ROWS block not found")
    return {
        int(match.group(1), 16)
        for match in re.finditer(r"^0x([0-9A-Fa-f]+)\s+", block.group(1), re.M)
    }


def _doc_core_rows() -> list[dict[str, object]]:
    text = DOC.read_text(encoding="utf-8")
    rows: list[dict[str, object]] = []
    pat = re.compile(
        r"^\|\s*(0x[0-9A-Fa-f][^|`]*)\s*\|\s*`(0x[0-9A-Fa-f]+)`\s*\|\s*`([^`]+)`\s*\|",
        re.M,
    )
    for opcodes, ea_s, name in pat.findall(text):
        if name.startswith("FFX_MagicCoreOp_"):
            rows.append({"opcodes": opcodes.strip(), "ea": int(ea_s, 16), "doc_name": name})
    return rows


def _clusters() -> dict[int, dict[str, str]]:
    import csv

    rows: dict[int, dict[str, str]] = {}
    with CLUSTERS.open("r", encoding="utf-8", newline="") as fh:
        for row in csv.DictReader(fh):
            rows[int(row["addr_hex"], 16)] = row
    return rows


def _proposed_name(row: dict[str, object], cluster_row: dict[str, str] | None) -> str:
    base = str(row["doc_name"])
    if base == "FFX_MagicCoreOp_3F":
        return "FFX_MagicCoreOp_3F_BindResidentMotion_candidate"
    if base == "FFX_MagicCoreOp_09":
        return "FFX_MagicCoreOp_09_Stub_structural"
    if base == "FFX_MagicCoreOp_23":
        return "FFX_MagicCoreOp_23_Stub_structural"
    if base == "FFX_MagicCoreOp_57":
        return "FFX_MagicCoreOp_57_NoOpAdvance2"
    if base == "FFX_MagicCoreOp_E1":
        return "FFX_MagicCoreOp_E1_Stub_structural"
    if base == "FFX_MagicCoreOp_98":
        return "FFX_MagicCoreOp_98_99_MatrixParamRun_structural"

    cluster = (cluster_row or {}).get("cluster", "").title().replace("_", "")
    if cluster:
        return f"{base}_{cluster}_structural"
    return f"{base}_structural"


def main() -> int:
    have = _func_rows()
    unique: dict[int, dict[str, object]] = {}
    for row in _doc_core_rows():
        unique.setdefault(int(row["ea"]), row)
    clusters = _clusters()
    missing = [row for ea, row in unique.items() if ea not in have]
    for row in missing:
        row["proposed_name"] = _proposed_name(row, clusters.get(int(row["ea"])))
    print(
        json.dumps(
            {
                "doc_rows": len(_doc_core_rows()),
                "unique_handlers": len(unique),
                "missing_from_replay": len(missing),
                "missing_rows": [
                    {
                        "opcodes": row["opcodes"],
                        "ea": f"0x{int(row['ea']):X}",
                        "doc_name": row["doc_name"],
                        "proposed_name": row["proposed_name"],
                    }
                    for row in missing
                ],
                "replay_rows": [
                    f"0x{int(row['ea']):X} {row['proposed_name']}" for row in missing
                ],
            },
            indent=2,
        )
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
