#!/usr/bin/env python3
"""Fase 3.3 corrigida: cruza a tabela AtelCallTargetsBattle (stride 16!) com o catalogo do Spira.

Estrutura PROVADA: FFX_AtelFuncspaceEntry[256], 16 B/entry:
  callpopa_fn@+0 (u32), pad@+4, float_return_fn@+8, int_return_fn@+0xC.
Entrada do ID 0x7000+N em offset N*16. Prova: launchBattle(0x7002) em offset 0x20 = 0x7A3550.
"""
import json
import re
from pathlib import Path

import ida_bytes
import ida_name
import idc

TABLE = 0xC42618
ENTRY = 16
ID_BASE = 0x7000
CATALOG = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\_spira_modifier_decomp\atel_call_targets.json")
DEFAULT = re.compile(r"^(FUN_|sub_|nullsub_|loc_|j_|unknown|dword_|unk_|off_)", re.I)


def main():
    cat = {e["id"]: e for e in json.loads(CATALOG.read_text(encoding="utf-8"))}
    raw = ida_bytes.get_bytes(TABLE, 256 * ENTRY)
    applied, skipped, noptr = 0, 0, 0
    for n in range(256):
        cid = ID_BASE + n
        e = cat.get(cid)
        if not e:
            continue
        ptr = int.from_bytes(raw[n * ENTRY:n * ENTRY + 4], "little")
        if ptr == 0:
            noptr += 1
            continue
        cur = ida_name.get_name(ptr)
        if cur and not DEFAULT.match(cur):
            skipped += 1
            continue
        if ida_name.set_name(ptr, e["name"], ida_name.SN_NOCHECK | ida_name.SN_FORCE):
            applied += 1
        else:
            skipped += 1
    idc.save_database("")
    print(f"DONE: applied={applied} skipped={skipped} noptr={noptr} — db salva.", flush=True)


if __name__ == "__main__":
    main()

