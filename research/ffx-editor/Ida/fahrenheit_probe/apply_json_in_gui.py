#!/usr/bin/env python3
"""Aplica renames de um JSON {addr: {name, ...}} na db ABERTA no IDA GUI e salva.

Como usar: File > Script File... ou via mcp_call.py exec.
"""
import json
import re
from pathlib import Path

import ida_name
import idc

REPORT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\loader_renames.json")
FUNC_DEFAULT = re.compile(r"^(FUN_|sub_|nullsub_|loc_|j_|unknown)", re.I)
GLOB_DEFAULT = re.compile(r"^(dword_|unk_|byte_|word_|flt_|off_|dbl_|qword_)", re.I)


def main():
    d = json.loads(REPORT.read_text(encoding="utf-8"))
    print(f"DB atual: {idc.get_root_filename()} — aplicando {len(d)} renames...", flush=True)
    fun, glob, skipped = 0, 0, 0
    for addr_s, info in d.items():
        ea = int(addr_s, 16)
        name = info["name"] if isinstance(info, dict) else info
        if not re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", name):
            continue
        cur = ida_name.get_name(ea)
        if cur and not FUNC_DEFAULT.match(cur) and not GLOB_DEFAULT.match(cur):
            skipped += 1
            continue
        if ida_name.set_name(ea, name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
            fun += 1
    idc.save_database("")
    print(f"DONE: funcoes={fun} skipped={skipped} — db salva.", flush=True)


if __name__ == "__main__":
    main()
