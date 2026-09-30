#!/usr/bin/env python3
"""Frente 3: renomeia os 3 globals sem modulo claro (runtime C++ + render)."""
import ida_name
import idc

RENAMES = {
    0xC8B43C: "FFX_CppRuntime_StdErrorCondition",
    0xC8B438: "FFX_CppRuntime_StdErrorConditionB",
    0xC169D4: "FFX_Render_UpdateTransformMatrixGlobal",
}


def main():
    applied = 0
    for ea, name in RENAMES.items():
        cur = ida_name.get_name(ea)
        if not cur or cur.startswith(("dword_", "byte_", "unk_", "off_")):
            if ida_name.set_name(ea, name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
                applied += 1
    idc.save_database("")
    print(f"DONE: applied={applied} — db salva.", flush=True)


if __name__ == "__main__":
    main()
