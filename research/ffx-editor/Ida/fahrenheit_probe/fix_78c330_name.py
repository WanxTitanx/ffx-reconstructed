#!/usr/bin/env python3
"""Corrige o nome errado de 0x78C330 (era LoadMonsterBins, e na verdade e
HitDamagePrecheck - o comentario do decompile prova)."""
import ida_name
import idc


def main():
    ea = 0x78C330
    cur = ida_name.get_name(ea)
    print(f"atual: {cur}", flush=True)
    new_name = "FFX_Btl_HitDamagePrecheck_structural"
    if ida_name.set_name(ea, new_name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
        print(f"renomeado -> {new_name}", flush=True)
    else:
        print("FALHOU", flush=True)
    idc.save_database("")
    print("db salva", flush=True)


if __name__ == "__main__":
    main()
