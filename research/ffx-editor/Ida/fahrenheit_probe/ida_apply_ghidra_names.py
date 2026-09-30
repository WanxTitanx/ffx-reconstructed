#!/usr/bin/env python3
"""Aplica renames do Ghidra (fahrenheit symbol tables) na DB canonica do FFX.

Fonte: C:\\Users\\wande\\Downloads\\Compressed\\FFX Analiser\\fahrenheit-save-ui-rework
  - functions.ffx.csv (56.558 funcoes, 11.504 nomeadas)
  - globals.ffx.csv    (762 globals user-defined com tipos)

Regras:
  - Aplica nome do Ghidra SOMENTE onde o nome atual na db e default
    (FUN_/sub_/nullsub_/loc_/j_/unknown para funcoes;
     dword_/unk_/byte_/word_/flt_/off_/dbl_/qword_ para globals).
  - NUNCA sobrescreve nomes do projeto (FFX_*, ja nomeados).
  - Sources: USER_DEFINED + IMPORTED (todos); ANALYSIS (exceto Catch_All/Sentry/thunk).
  - Globals: aplica tipo primitivo quando mapeavel (remap do STEP).
"""
import csv
import io
import json
import re
import sys
from pathlib import Path

import idapro

CSV_FUN = Path(r"C:\Users\wande\Downloads\Compressed\FFX Analiser\fahrenheit-save-ui-rework\fahrenheit-save-ui-rework\src\step\data\functions.ffx.csv")
CSV_GLOB = Path(r"C:\Users\wande\Downloads\Compressed\FFX Analiser\fahrenheit-save-ui-rework\fahrenheit-save-ui-rework\src\step\data\globals.ffx.csv")
DB = sys.argv[1] if len(sys.argv) > 1 else r"F:\ffx-reconstructed\extras\ffxoficial.exe.i64"
OUT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\ida_results\ghidra_renames_report.json")

REMAP = {
    "void": "", "bool": "bool", "byte": "byte", "byte*": "byte*", "char": "char",
    "double": "double", "dword": "uint", "float": "float", "int": "int", "int*": "int*",
    "long": "int", "longlong": "long", "short": "short", "uint": "uint",
    "ulong": "uint", "ulonglong": "ulong", "undefined": None, "undefined1": "byte",
    "undefined2": "ushort", "undefined4": "uint", "undefined8": "ulong",
    "ushort": "ushort", "word": "ushort", "pointer": "void*", "string": "char*",
}

FUNC_DEFAULT = re.compile(r"^(FUN_|sub_|nullsub_|loc_|j_|unknown)", re.I)
GLOB_DEFAULT = re.compile(r"^(dword_|unk_|byte_|word_|flt_|off_|dbl_|qword_)", re.I)
ANALYSIS_NOISE = re.compile(r"^(Catch_All|Sentry|thunk_)", re.I)
NAME_OK = re.compile(r"^[A-Za-z_][A-Za-z0-9_$:]*$")


def sanitize(name: str) -> str:
    n = name.strip()
    if n.startswith("+"):
        n = n[1:]
    n = n.replace(" ", "_").replace("@", "_").replace("*", "p").replace("&", "_").replace(".", "_").replace(",", "_")
    if not NAME_OK.match(n):
        return None
    return n[:512]



def load_rows(path: Path) -> list:
    with io.open(path, "r", encoding="utf-8") as fh:
        return list(csv.reader(fh))


def main() -> int:
    import ida_funcs
    import ida_name
    import ida_typeinf

    print(f"OPEN DB: {DB}", flush=True)
    rc = idapro.open_database(DB, False)
    if rc != 0:
        print(f"FATAL: open_database rc={rc}", flush=True)
        return 2
    print("DB opened (rw).", flush=True)

    fun_rows = load_rows(CSV_FUN)
    glob_rows = load_rows(CSV_GLOB)

    applied_fun, skipped_named, skipped_noise = [], [], []
    for r in fun_rows[1:]:
        if len(r) < 4:
            continue
        name_raw, addr_s, source = r[0], r[1], r[3]
        if name_raw.startswith("FUN_"):
            continue
        if source == "ANALYSIS" and ANALYSIS_NOISE.match(name_raw):
            skipped_noise.append({"ea": addr_s, "name": name_raw})
            continue
        try:
            ea = int(addr_s, 16)
        except ValueError:
            continue
        name = sanitize(name_raw)
        if not name:
            continue
        cur = ida_name.get_name(ea)
        if cur and not FUNC_DEFAULT.match(cur):
            skipped_named.append({"ea": addr_s, "name": name_raw, "current": cur})
            continue
        if ida_name.set_name(ea, name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
            applied_fun.append({"ea": addr_s, "name": name_raw, "renamed_to": name, "source": source})
        else:
            skipped_named.append({"ea": addr_s, "name": name_raw, "current": cur, "fail": True})
    print(f"[FUN] applied={len(applied_fun)} skipped_named={len(skipped_named)} noise={len(skipped_noise)}", flush=True)

    applied_glob, skipped_glob = [], []
    for r in glob_rows[1:]:
        if len(r) < 5:
            continue
        name_raw, addr_s, dtype = r[0], r[1], r[3]
        try:
            ea = int(addr_s, 16)
        except ValueError:
            continue
        name = sanitize(name_raw)
        if not name:
            continue
        cur = ida_name.get_name(ea)
        if cur and not GLOB_DEFAULT.match(cur):
            skipped_glob.append({"ea": addr_s, "name": name_raw, "current": cur})
            continue
        ok = ida_name.set_name(ea, name, ida_name.SN_NOCHECK | ida_name.SN_FORCE)
        t = REMAP.get(dtype.strip())
        if ok and t:
            try:
                ida_typeinf.apply_tinfo(ea, ida_typeinf.tinfo_t(ida_typeinf.get_named_type(None, t, ida_typeinf.NTF_TYPE)), ida_typeinf.TINFO_DEFINITE)
            except Exception:  # noqa: BLE001
                pass
        if ok:
            applied_glob.append({"ea": addr_s, "name": name_raw, "type": dtype})
        else:
            skipped_glob.append({"ea": addr_s, "name": name_raw, "current": cur, "fail": True})
    print(f"[GLOB] applied={len(applied_glob)} skipped={len(skipped_glob)}", flush=True)

    report = {
        "db": DB,
        "functions_applied": applied_fun,
        "functions_skipped_named": skipped_named,
        "functions_skipped_noise": skipped_noise,
        "globals_applied": applied_glob,
        "globals_skipped": skipped_glob,
        "counts": {
            "fun_applied": len(applied_fun),
            "fun_skipped_named": len(skipped_named),
            "fun_noise": len(skipped_noise),
            "glob_applied": len(applied_glob),
            "glob_skipped": len(skipped_glob),
        },
    }
    OUT.write_text(json.dumps(report, indent=1, ensure_ascii=False), encoding="utf-8")

    print("Saving DB (renames)...", flush=True)
    idapro.close_database(True)
    print(f"DONE -> {OUT}", flush=True)
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except Exception:  # noqa: BLE001
        import traceback
        traceback.print_exc()
        sys.exit(1)
