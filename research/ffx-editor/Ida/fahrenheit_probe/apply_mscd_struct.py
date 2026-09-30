#!/usr/bin/env python3
"""Lote 14: tipa a fila Mscd (64 slots x 56B) em 0x1127C84."""
import ida_typeinf
import ida_name
import idc


def main():
    idati = ida_typeinf.get_idati()
    ti = ida_typeinf.tinfo_t()
    ok = ida_typeinf.parse_decl(
        ti, idati,
        "struct FFX_MscdQueueSlot { int cmd; int unk1; int args[4]; int pad1; "
        "int param; int unk2; int flags; };", 0)
    print(f"struct MscdQueueSlot: {ok}", flush=True)
    arr = ida_typeinf.tinfo_t()
    if arr.create_array(ti, 64):
        if ida_typeinf.apply_tinfo(0x1127C84, arr, ida_typeinf.TINFO_DEFINITE):
            print("FFX_MscdQueueSlot[64] aplicado em 0x1127C84", flush=True)
    # contador de sequencia (dword[895] = offset 0xDFC)
    cur = ida_name.get_name(0x1127C84 + 0xDFC)
    if not cur or cur.startswith(("dword_", "byte_", "unk_")):
        if ida_name.set_name(0x1127C84 + 0xDFC, "FFX_Mscd_SequenceCounter",
                             ida_name.SN_NOCHECK | ida_name.SN_FORCE):
            print("contador renomeado", flush=True)
    idc.save_database("")
    print("db salva", flush=True)


if __name__ == "__main__":
    main()
