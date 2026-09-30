#!/usr/bin/env python3
"""Validate the Jarvis FFX.exe naming-goal replay/report counters."""

from __future__ import annotations

import ast
import json
from pathlib import Path


# FIX 2026-09-18 (Jarvis-TOOLS-REPAIR): parents[3] = repo root at the new
# research_tools/Ida/jarvis_goal/ location; parents[4] was stale from the
# pre-relocation scratch path and resolved to ~/Documents/.
ROOT = Path(__file__).resolve().parents[3]
SCRIPT = ROOT / "work/reverse/ida/scripts/apply_jarvis_goal_renames_20260617.py"
REPORT = ROOT / "work/reverse/ida/exports/jarvis_goal_renames_20260617_report.json"
EXPECTED = {'func_rows': 1969, 'data_rows': 134, 'total_rows': 2103}


def _rows(block: str) -> list[str]:
    return [line.strip() for line in block.splitlines() if line.strip()]


def _literal_assigns(path: Path) -> dict[str, str]:
    tree = ast.parse(path.read_text(encoding="utf-8"))
    values: dict[str, str] = {}
    for node in tree.body:
        if not isinstance(node, ast.Assign):
            continue
        if len(node.targets) != 1 or not isinstance(node.targets[0], ast.Name):
            continue
        name = node.targets[0].id
        if name in {"FUNC_ROWS", "DATA_ROWS"} and isinstance(node.value, ast.Constant):
            values[name] = str(node.value.value)
    return values


def main() -> int:
    assigns = _literal_assigns(SCRIPT)
    func_rows = _rows(assigns["FUNC_ROWS"])
    data_rows = _rows(assigns["DATA_ROWS"])
    func_addrs = [row.split()[0].lower() for row in func_rows]
    data_addrs = [row.split()[0].lower() for row in data_rows]
    report = json.loads(REPORT.read_text(encoding="utf-8"))

    counts = {
        "func_rows": len(func_rows),
        "data_rows": len(data_rows),
        "total_rows": len(func_rows) + len(data_rows),
    }
    func_dupes = len(func_addrs) - len(set(func_addrs))
    data_dupes = len(data_addrs) - len(set(data_addrs))

    print(f"func_rows={counts['func_rows']}")
    print(f"data_rows={counts['data_rows']}")
    print(f"total_rows={counts['total_rows']}")
    print(f"func_dupes={func_dupes}")
    print(f"data_dupes={data_dupes}")
    print(f"json_counts={report['counts']}")

    ok = (
        counts == EXPECTED
        and report["counts"] == EXPECTED
        and func_dupes == 0
        and data_dupes == 0
    )
    print(f"ok={ok}")
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
