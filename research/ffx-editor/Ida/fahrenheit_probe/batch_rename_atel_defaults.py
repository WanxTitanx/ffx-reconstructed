#!/usr/bin/env python3
"""Lote 11: renomeia handlers ATEL default com prefixo da tabela.

Nome: FFX_Atel_<TABELA>_H_<ADDR> (ex: FFX_Atel_Common_H_C12345).
"""
import ida_bytes
import ida_funcs
import ida_name
import idc
import re

DEFAULT = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_)", re.I)
TABLES = [("Movie", 0xC40E20, 383), ("Battle", 0xC42618, 311), ("Camera", 0xC43988, 3180),
          ("Common", 0xC50050, 689), ("Default", 0xC52B60, 8), ("Math", 0xC52BE0, 31),
          ("Debug", 0xC52DD8, 2734), ("Mount", 0xC5D8C0, 61), ("Map", 0xC5DC90, 4096),
          ("AbiMap", 0xC85EB0, 749), ("SgEvent", 0xC88D88, 71), ("ChEvent", 0xC891F8, 256)]


def main():
    applied = 0
    seen = set()
    for tname, taddr, n in TABLES:
        raw = ida_bytes.get_bytes(taddr, n * 16) or b""
        for i in range(n):
            for field in (0, 8, 12):
                ptr = int.from_bytes(raw[i * 16 + field:i * 16 + field + 4], "little")
                if not (0x400000 <= ptr < 0xA00000) or ptr in seen:
                    continue
                if not ida_funcs.get_func(ptr):
                    continue
                name = ida_name.get_name(ptr)
                if name and not DEFAULT.match(name):
                    seen.add(ptr)
                    continue
                seen.add(ptr)
                new_name = f"FFX_Atel_{tname}_H_{ptr:X}"
                if ida_name.set_name(ptr, new_name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
                    applied += 1
    idc.save_database("")
    print(f"DONE: applied={applied} — db salva.", flush=True)


if __name__ == "__main__":
    main()
