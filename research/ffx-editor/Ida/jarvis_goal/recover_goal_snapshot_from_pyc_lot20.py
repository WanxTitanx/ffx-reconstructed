# RECOVERED 2026-09-18 (lane Jarvis-TOOLS-REPAIR): source restored from git history
# commit 53d82b2a, original path RuntimeTools/FFXMapViewerWeb/work/reverse/ida/scripts/<name>.
# The work/reverse/ida/scripts/ tree was never committed at its original location;
# only __pycache__/*.pyc + this history copy survived. Cited by docs/reverse/* + SESSION_HANDOFF.
import json
import marshal
import pathlib
import re
import types

ROOT = pathlib.Path(".")
APPLY = ROOT / "work/reverse/ida/scripts/apply_jarvis_goal_renames_20260617.py"
VALIDATOR = ROOT / "work/reverse/ida/scripts/validate_jarvis_goal_snapshot.py"
REPORT = ROOT / "work/reverse/ida/exports/jarvis_goal_renames_20260617_report.json"
PYC = ROOT / "work/reverse/ida/scripts/__pycache__/apply_jarvis_goal_renames_20260617.cpython-313.pyc"

LOT20_ROWS = [
    ("0x7723B0", "FFX_Atel_Movie_FuncB010_CALL_structural"),
    ("0x772420", "FFX_Atel_Movie_FuncB010_STATUS_structural"),
    ("0x772480", "FFX_Atel_Movie_FuncB010_FLOATRET_structural"),
    ("0x7724F0", "FFX_Atel_Movie_FuncB010_INTRET_structural"),
    ("0x772560", "FFX_Atel_Movie_FuncB011_CALL_structural"),
    ("0x7725D0", "FFX_Atel_Movie_FuncB011_STATUS_structural"),
    ("0x772600", "FFX_Atel_Movie_FuncB011_FLOATRET_structural"),
    ("0x772660", "FFX_Atel_Movie_FuncB011_INTRET_structural"),
    ("0x7726C0", "FFX_Atel_Movie_FuncB012_CALL_structural"),
    ("0x772730", "FFX_Atel_Movie_FuncB012_STATUS_structural"),
    ("0x7727E0", "FFX_Atel_Movie_FuncB012_FLOATRET_structural"),
    ("0x772840", "FFX_Atel_Movie_FuncB012_INTRET_structural"),
    ("0x7728A0", "FFX_Atel_Movie_FuncB013_CALL_structural"),
    ("0x772900", "FFX_Atel_Movie_FuncB013_STATUS_structural"),
    ("0x772AE0", "FFX_Atel_Movie_FuncB01E_FLOATRET_structural"),
    ("0x772AF0", "FFX_Atel_Movie_FuncB014_CALL_structural"),
    ("0x772B60", "FFX_Atel_Movie_FuncB014_STATUS_structural"),
    ("0x772BD0", "FFX_Atel_Movie_FuncB014_FLOATRET_structural"),
    ("0x772C40", "FFX_Atel_Movie_FuncB014_INTRET_structural"),
    ("0x772CB0", "FFX_Atel_Movie_FuncB015_CALL_structural"),
    ("0x772D20", "FFX_Atel_Movie_FuncB015_STATUS_structural"),
    ("0x772D60", "FFX_Atel_Movie_FuncB015_FLOATRET_structural"),
    ("0x772DD0", "FFX_Atel_Movie_FuncB015_INTRET_structural"),
    ("0x772E40", "FFX_Atel_Movie_FuncB016_CALL_structural"),
    ("0x772EB0", "FFX_Atel_Movie_FuncB016_STATUS_structural"),
    ("0x772F30", "FFX_Atel_Movie_FuncB016_FLOATRET_structural"),
    ("0x772FB0", "FFX_Atel_Movie_FuncB016_INTRET_structural"),
    ("0x772FF0", "FFX_Atel_Movie_FuncB017_CALL_structural"),
    ("0x773060", "FFX_Atel_Movie_FuncB017_STATUS_structural"),
    ("0x7730D0", "FFX_Atel_Movie_FuncB017_FLOATRET_structural"),
    ("0x773140", "FFX_Atel_Movie_FuncB017_INTRET_structural"),
    ("0x7731B0", "FFX_Atel_Movie_FuncB018_CALL_structural"),
    ("0x773220", "FFX_Atel_Movie_FuncB018_STATUS_structural"),
    ("0x773260", "FFX_Atel_Movie_FuncB018_FLOATRET_structural"),
    ("0x7732D0", "FFX_Atel_Movie_FuncB018_INTRET_structural"),
    ("0x773340", "FFX_Atel_Movie_FuncB019_CALL_structural"),
    ("0x7733B0", "FFX_Atel_Movie_FuncB019_STATUS_structural"),
    ("0x773420", "FFX_Atel_Movie_FuncB019_FLOATRET_structural"),
    ("0x773490", "FFX_Atel_Movie_FuncB019_INTRET_structural"),
    ("0x7734D0", "FFX_Atel_Movie_FuncB01A_CALL_structural"),
    ("0x773540", "FFX_Atel_Movie_FuncB01A_STATUS_structural"),
    ("0x7735B0", "FFX_Atel_Movie_FuncB01A_FLOATRET_structural"),
    ("0x773620", "FFX_Atel_Movie_FuncB01A_INTRET_structural"),
    ("0x773670", "FFX_Atel_Movie_FuncB01B_CALL_structural"),
    ("0x7736B0", "FFX_Atel_Movie_FuncB01B_STATUS_structural"),
    ("0x7736F0", "FFX_Atel_Movie_FuncB01B_FLOATRET_structural"),
    ("0x773730", "FFX_Atel_Movie_FuncB01B_INTRET_structural"),
    ("0x773770", "FFX_Atel_Movie_FuncB01C_CALL_structural"),
    ("0x7737B0", "FFX_Atel_Movie_FuncB01C_STATUS_structural"),
    ("0x7737F0", "FFX_Atel_Movie_FuncB01C_FLOATRET_structural"),
    ("0x773830", "FFX_Atel_Movie_FuncB01C_INTRET_structural"),
    ("0x773870", "FFX_Atel_Movie_FuncB01D_CALL_structural"),
    ("0x7738D0", "FFX_Atel_Movie_FuncB01D_STATUS_structural"),
    ("0x7738F0", "FFX_Atel_Movie_FuncB01D_FLOATRET_structural"),
    ("0x773950", "FFX_Atel_Movie_FuncB01D_INTRET_structural"),
    ("0x7739D0", "FFX_Atel_Movie_FuncB01E_CALL_structural"),
    ("0x773A10", "FFX_Atel_Movie_FuncB01E_STATUS_structural"),
    ("0x773A60", "FFX_Atel_Movie_FuncB01E_INTRET_structural"),
    ("0x773AB0", "FFX_Atel_Movie_FuncB01F_CALL_structural"),
    ("0x773B20", "FFX_Atel_Movie_FuncB01F_STATUS_structural"),
    ("0x773B90", "FFX_Atel_Movie_FuncB01F_FLOATRET_structural"),
    ("0x773C00", "FFX_Atel_Movie_FuncB01F_INTRET_structural"),
]

EXPECTED = {"func_rows": 1439, "data_rows": 112, "total_rows": 1551}


def walk_consts(code):
    for const in code.co_consts:
        if isinstance(const, str):
            yield const
        elif isinstance(const, types.CodeType):
            yield from walk_consts(const)


def extract_pyc_rows():
    data = PYC.read_bytes()
    code = marshal.loads(data[16:])
    strings = list(walk_consts(code))
    func_rows = max(
        (s for s in strings if "Phyre_" in s and "FFX_" in s and "0x" in s),
        key=len,
    )
    data_rows = max(
        (s for s in strings if "g_FFX_" in s and " dword" in s and "0x" in s),
        key=len,
    )
    return func_rows.strip("\n"), data_rows.strip("\n")


def count_rows(rows):
    return len(
        [
            line
            for line in rows.splitlines()
            if line.strip() and not line.strip().startswith("#")
        ]
    )


def insert_lot20(func_rows):
    lines = [line.rstrip() for line in func_rows.splitlines() if line.strip()]
    names = {line.split()[1] for line in lines}
    additions = [f"{ea} {name}" for ea, name in LOT20_ROWS if name not in names]
    if not additions:
        return "\n".join(lines)

    anchors = [
        "0x76EDE0 FFX_Atel_Movie_FuncB00F_INTRET_structural",
        "0x773CF0 FFX_Scan_IsLearnedWrapper",
    ]
    idx = None
    for anchor in anchors:
        for i, line in enumerate(lines):
            if line == anchor:
                idx = i + (1 if "B00F" in anchor else 0)
                break
        if idx is not None:
            break
    if idx is None:
        raise RuntimeError("Movie insertion anchor not found")

    lines[idx:idx] = additions
    return "\n".join(lines)


def replace_triple(text, name, value):
    pattern = rf'{name} = """\r?\n[\s\S]*?\r?\n"""'
    replacement = f'{name} = """\n{value}\n"""'
    new_text, n = re.subn(pattern, replacement, text, count=1)
    if n != 1:
        raise RuntimeError(f"Failed to replace {name}")
    return new_text


def main():
    func_rows, data_rows = extract_pyc_rows()
    func_rows = insert_lot20(func_rows)
    counts = {
        "func_rows": count_rows(func_rows),
        "data_rows": count_rows(data_rows),
        "total_rows": count_rows(func_rows) + count_rows(data_rows),
    }
    if counts != EXPECTED:
        raise RuntimeError(f"row count mismatch: {counts}")

    apply_text = APPLY.read_text(encoding="utf-8")
    apply_text = replace_triple(apply_text, "FUNC_ROWS", func_rows)
    apply_text = replace_triple(apply_text, "DATA_ROWS", data_rows)
    APPLY.write_text(apply_text, encoding="utf-8", newline="\n")

    validator_text = VALIDATOR.read_text(encoding="utf-8")
    validator_text = re.sub(
        r"EXPECTED = \{[^\n]+\}",
        f"EXPECTED = {EXPECTED!r}",
        validator_text,
        count=1,
    )
    VALIDATOR.write_text(validator_text, encoding="utf-8", newline="\n")

    report = json.loads(REPORT.read_text(encoding="utf-8"))
    report["counts"] = EXPECTED
    report["latest_batch_lot20_atel_movie_funcspace_b010_b01f"] = {
        "date": "2026-06-26",
        "cluster": "ATEL Movie funcspace extension B010-B01F",
        "source": (
            "Live IDB table-backed sweep of "
            "g_FFX_Atel_MovieFuncspaceTable_candidate at 0x00C40E20; "
            "16-byte records with CALL/STATUS/FLOATRET/INTRET slots. "
            "0x7723B0 was defined as code before rename."
        ),
        "new_func_rows": len(LOT20_ROWS),
        "new_data_rows": 0,
        "snapshot_after_batch": EXPECTED,
        "rows": [{"ea": ea, "name": name} for ea, name in LOT20_ROWS],
        "guardrail": (
            "Names are structural table-slot labels only; no new semantic FMV "
            "behavior is claimed beyond the already documented B000 "
            "load/current/await entries."
        ),
    }
    REPORT.write_text(
        json.dumps(report, indent=2, ensure_ascii=False) + "\n",
        encoding="utf-8",
        newline="\n",
    )
    print(json.dumps({"counts": counts, "lot20_rows": len(LOT20_ROWS)}, indent=2))


if __name__ == "__main__":
    main()
