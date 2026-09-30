#!/usr/bin/env python3
"""Verifica/repara os renames das frentes 2-3 na COPY (podem ter sido perdidos)."""
import ida_name
import idc

RENAMES = {
    0xC65AC4: "Phyre_Vftable_C65AC4",
    0xC65AE0: "Phyre_Vftable_C65AE0",
    0xC8B43C: "FFX_CppRuntime_StdErrorCondition",
    0xC8B438: "FFX_CppRuntime_StdErrorConditionB",
    0xC169D4: "FFX_Render_UpdateTransformMatrixGlobal",
}


def main():
    applied = 0
    for ea, name in RENAMES.items():
        cur = ida_name.get_name(ea)
        if cur == name:
            print(f"OK     {hex(ea)} ja tem {name}", flush=True)
            continue
        if not cur or cur.startswith(("dword_", "byte_", "unk_", "off_", "flt_", "qword_", "word_")):
            if ida_name.set_name(ea, name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
                applied += 1
                print(f"FIX    {hex(ea)} -> {name}", flush=True)
            else:
                print(f"FALHOU {hex(ea)} -> {name}", flush=True)
        else:
            print(f"CONFLITO {hex(ea)} tem {cur} (nao sobrescrevi)", flush=True)
    idc.save_database("")
    print(f"DONE: applied={applied} — db salva.", flush=True)


if __name__ == "__main__":
    main()
