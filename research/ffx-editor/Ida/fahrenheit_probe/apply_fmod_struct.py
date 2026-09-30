#!/usr/bin/env python3
"""Lote 13: tipa a FmodCommandQueue (150 comandos x 20B) + renames do head."""
import ida_typeinf
import ida_name
import idc


def main():
    idati = ida_typeinf.get_idati()
    ti = ida_typeinf.tinfo_t()
    ok = ida_typeinf.parse_decl(
        ti, idati,
        "struct FFX_FmodCommand { int id; int arg1; int arg2; int arg3; int arg4; };", 0)
    print(f"struct FmodCommand: {ok}", flush=True)
    arr = ida_typeinf.tinfo_t()
    if arr.create_array(ti, 150):
        if ida_typeinf.apply_tinfo(0xCE844C, arr, ida_typeinf.TINFO_DEFINITE):
            print("FFX_FmodCommand[150] aplicado em 0xCE844C", flush=True)
    for ea, name in ((0xCE8448, "FFX_Sound_FmodQueueHead"),):
        cur = ida_name.get_name(ea)
        if not cur or cur.startswith(("byte_", "dword_", "unk_")):
            if ida_name.set_name(ea, name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
                print(f"{hex(ea)} -> {name}", flush=True)
    idc.save_database("")
    print("db salva", flush=True)


if __name__ == "__main__":
    main()
