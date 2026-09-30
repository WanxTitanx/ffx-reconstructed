#!/usr/bin/env python3
"""Survey da db: estado das funcoes Phyre, globals default restantes e tabelas ATEL."""
import ida_funcs
import ida_name
import ida_bytes
import idc

PHYRE_PREFIX = ("Phyre_", "FFX_Phyre_")
DEFAULT = ("sub_", "FUN_", "nullsub_", "unk_", "dword_", "byte_", "off_", "loc_", "j_")


def main():
    print("=== FUNCOES PHYRE NA DB ===", flush=True)
    n_phyre, n_total = 0, 0
    phyre_names = set()
    qty = ida_funcs.get_func_qty()
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        n_total += 1
        name = ida_name.get_name(f.start_ea)
        if name and name.startswith(PHYRE_PREFIX):
            n_phyre += 1
            phyre_names.add(name)
    print(f"funcoes totais: {n_total}, com nome Phyre_*/FFX_Phyre_*: {n_phyre}", flush=True)
    sample = sorted(phyre_names)[:15]
    for s in sample:
        print("  ", s, flush=True)

    print("=== TABELAS ATEL: entradas preenchidas (stride 16) ===", flush=True)
    for tname, taddr in [("Movie", 0xC40E20), ("Battle", 0xC42618), ("Camera", 0xC43988),
                         ("Common", 0xC50050), ("Default", 0xC52B60), ("Math", 0xC52BE0),
                         ("Debug", 0xC52DD8), ("Mount", 0xC5D8C0), ("Map", 0xC5DC90),
                         ("AbiMap", 0xC85EB0), ("SgEvent", 0xC88D88), ("ChEvent", 0xC891F8)]:
        filled = 0
        for n in range(256):
            ptr = int.from_bytes(ida_bytes.get_bytes(taddr + n * 16, 4), "little")
            if ptr:
                filled += 1
        print(f"  {tname} @ {hex(taddr)}: {filled}/256 preenchidas", flush=True)

    print("=== BUFFERS GRANDES: nome atual ===", flush=True)
    for ea in [0x132FF60, 0x11333C4, 0x19450C4, 0xC98B4C, 0x22FB6C1, 0x1A860E4, 0x16AD870]:
        print(f"  {hex(ea)}: {ida_name.get_name(ea) or '(default)'}", flush=True)


if __name__ == "__main__":
    main()
