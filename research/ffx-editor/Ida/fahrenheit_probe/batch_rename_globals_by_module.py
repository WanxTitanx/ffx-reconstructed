#!/usr/bin/env python3
"""Lote 1: renomeia globals default do .data por MODULO da funcao dominante.

Heuristica: top_fn do relatorio (funcao que mais referenciou o global) -> prefixo do modulo.
Nome gerado: FFX_<MODULO>_Global_<ADDR> (ex: FFX_Magic_Global_C8F510).
Regras: so renomeia se o nome atual e default; nunca sobrescreve nomes existentes.
"""
import json
import re
from pathlib import Path

import ida_bytes
import ida_name
import idc

REPORT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\data_globals_report.json")
DEFAULT = re.compile(r"^(dword_|off_|flt_|byte_|word_|qword_|unk_)", re.I)

# mapeia prefixo de funcao -> modulo
MODULE_MAP = [
    ("FFX_Magic", "Magic"),
    ("FFX_Ppp", "Ppp"),
    ("ppp", "Ppp"),
    ("FFX_Abmap", "Abmap"),
    ("FFX_FieldMap", "FieldMap"),
    ("FFX_Field_", "Field"),
    ("FFX_FieldMath", "Field"),
    ("FFX_Battle", "Battle"),
    ("FFX_Btl", "Battle"),
    ("FFX_Sound", "Sound"),
    ("FFX_Menu2D", "Menu2D"),
    ("FFX_Atel", "Atel"),
    ("FFX_Save", "Save"),
    ("FFX_Sphere", "SphereGrid"),
    ("FFX_Text", "Text"),
    ("FFX_Input", "Input"),
    ("FFX_Encounter", "Encounter"),
    ("FFX_Camera", "Camera"),
    ("FFX_KR_", "Kernel"),
    ("FFX_GDraw", "GDraw"),
    ("FFX_Mscd", "Mscd"),
    ("FFX_Event", "Event"),
    ("FFX_Chr", "Chr"),
    ("Phyre", "Phyre"),
    ("PClassDescriptor", "Phyre"),
    ("FmodManager", "Sound"),
]


def module_of(fn_name):
    for prefix, mod in MODULE_MAP:
        if fn_name.startswith(prefix):
            return mod
    return None


def main():
    report = json.loads(REPORT.read_text(encoding="utf-8"))
    applied, skipped_mod, skipped_named = 0, 0, 0
    for item in report["top"]:
        ea = int(item["ea"], 16)
        cur = ida_name.get_name(ea)
        if cur and not DEFAULT.match(cur):
            skipped_named += 1
            continue
        mod = module_of(item["top_fn"])
        if not mod:
            skipped_mod += 1
            continue
        new_name = f"FFX_{mod}_Global_{ea:X}"
        if ida_name.set_name(ea, new_name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
            applied += 1
    idc.save_database("")
    print(f"DONE: applied={applied} skipped_named={skipped_named} skipped_sem_modulo={skipped_mod} — db salva.", flush=True)


if __name__ == "__main__":
    main()
