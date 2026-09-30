#!/usr/bin/env python3
"""Aplica os renames Ghidra/Fahrenheit na db ABERTA no IDA GUI.

Como usar: no IDA GUI com a db aberta, File > Script File... > selecione este .py.
Le o relatorio gerado na canonica (work/_fahrenheit_probe/ida_results/ghidra_renames_report.json),
re-aplica as mesmas regras na db aberta (somente onde o nome atual e default) e SALVA a db.

Sem dependencias externas (IDAPython puro).
"""
import json
import re
from pathlib import Path

import ida_name
import ida_typeinf
import idc

REPORT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\ida_results\ghidra_renames_report.json")

FUNC_DEFAULT = re.compile(r"^(FUN_|sub_|nullsub_|loc_|j_|unknown)", re.I)
GLOB_DEFAULT = re.compile(r"^(dword_|unk_|byte_|word_|flt_|off_|dbl_|qword_)", re.I)

REMAP = {
    "byte": "byte", "byte*": "byte*", "char": "char", "double": "double",
    "float": "float", "int": "int", "int*": "int*", "long": "int", "short": "short",
    "uint": "uint", "ulong": "uint", "ulonglong": "ulong", "ushort": "ushort",
    "undefined1": "byte", "undefined2": "ushort", "undefined4": "uint",
    "undefined8": "ulong", "pointer": "void*", "string": "char*",
}


def main():
    d = json.loads(REPORT.read_text(encoding="utf-8"))
    print(f"DB atual: {idc.get_root_filename()} — aplicando renames do relatorio...", flush=True)

    fun, glob, skipped = 0, 0, 0
    for r in d["functions_applied"]:
        ea = int(r["ea"], 16)
        cur = ida_name.get_name(ea)
        if cur and not FUNC_DEFAULT.match(cur):
            skipped += 1
            continue
        if ida_name.set_name(ea, r["renamed_to"], ida_name.SN_NOCHECK):
            fun += 1

    for r in d["globals_applied"]:
        ea = int(r["ea"], 16)
        cur = ida_name.get_name(ea)
        if cur and not GLOB_DEFAULT.match(cur):
            skipped += 1
            continue
        if ida_name.set_name(ea, r["name"], ida_name.SN_NOCHECK):
            glob += 1
            t = REMAP.get(r["type"].strip())
            if t:
                try:
                    ida_typeinf.apply_tinfo(
                        ea,
                        ida_typeinf.tinfo_t(ida_typeinf.get_named_type(None, t, ida_typeinf.NTF_TYPE)),
                        ida_typeinf.TINFO_DEFINITE,
                    )
                except Exception:  # noqa: BLE001
                    pass

    idc.save_database("")
    print(f"DONE: funcoes={fun} globals={glob} skipped(nome ja presente)={skipped} — db salva.", flush=True)


if __name__ == "__main__":
    main()
