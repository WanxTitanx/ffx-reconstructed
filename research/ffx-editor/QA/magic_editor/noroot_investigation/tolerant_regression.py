#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Regression: roda o parser tolerante nas 347 OPEN_OK e compara
root_abs/program_count/total_slots com o audit original."""
import json
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\noroot_investigation")))

from tolerant_parse import data_sec, tolerant_root, walk_root  # noqa: E402

AUDIT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\magic_editor\CORPUS_AUDIT.json")
CORPUS = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")
OUT = Path(__file__).resolve().parent


def scan_one(dll_name: str) -> dict:
    raw = (CORPUS / dll_name).read_bytes()
    data = data_sec(raw)
    L = len(data)
    res = {"dll": dll_name}
    if data is None:
        res["error"] = "no_data"
        return res
    roots = []
    for R in range(0, L - 32, 4):
        rt = tolerant_root(data, R)
        if rt is not None:
            roots.append(rt)
            if len(roots) >= 8:
                break
    res["n_roots"] = len(roots)
    if roots:
        r0 = roots[0]
        res["root_R"] = r0["R"]
        res["walk"] = walk_root(data, r0["R"], r0)
    return res


def main() -> None:
    d = json.loads(AUDIT.read_text(encoding="utf-8"))
    ok = [k for k, v in d["dlls"].items() if v.get("status") == "OPEN_OK"]
    with ProcessPoolExecutor(max_workers=8) as ex:
        rows = list(ex.map(scan_one, sorted(ok)))
    # compara
    match_root = 0
    match_walk = 0
    no_root = 0
    diff_root = []
    diff_walk = []
    for r in rows:
        info = d["dlls"][r["dll"]]
        if r.get("n_roots", 0) == 0:
            no_root += 1
            diff_root.append((r["dll"], "NO_ROOT no tolerante"))
            continue
        # o audit agrega multiplos roots; comparar com o primeiro root
        roots_info = info.get("roots", [])
        first = roots_info[0] if roots_info else {}
        if first.get("root_abs") == r["root_R"]:
            match_root += 1
        else:
            diff_root.append((r["dll"], hex(first.get("root_abs", -1)),
                              hex(r["root_R"])))
        w = r["walk"]
        if w["programs"] == info.get("program_count") and \
           w["slots"] == info.get("total_slots"):
            match_walk += 1
        else:
            diff_walk.append((r["dll"], info.get("program_count"),
                              w["programs"], info.get("total_slots"),
                              w["slots"]))
    print(f"OPEN_OK testadas: {len(rows)}")
    print(f"root_abs identico: {match_root} | walk identico: {match_walk} | "
          f"sem root no tolerante: {no_root}")
    print("\ndiff root (10):")
    for x in diff_root[:10]:
        print("  ", x)
    print("\ndiff walk (10):")
    for x in diff_walk[:10]:
        print("  ", x)
    OUT.joinpath("tolerant_regression_raw.json").write_text(
        json.dumps(rows, indent=1), encoding="utf-8")


if __name__ == "__main__":
    main()
