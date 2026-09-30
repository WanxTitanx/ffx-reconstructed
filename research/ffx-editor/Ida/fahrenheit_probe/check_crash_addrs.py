#!/usr/bin/env python3
"""Verifica o que existe nos VAs dos crashes sem funcao."""
import ida_bytes
import ida_name
import idc


def main():
    vaddrs = [0x78261E, 0x79F150, 0x834420, 0x705AAE, 0x82AD8D, 0x67BB65]
    for va in vaddrs:
        name = ida_name.get_name(va) or "(sem nome)"
        seg = idc.get_segm_name(va) or "?"
        # funcao mais proxima antes
        prev = None
        ea = va
        while ea > 0x400000:
            n = ida_name.get_name(ea)
            if n:
                prev = (hex(ea), n)
                break
            ea -= 1
        print(f"{hex(va)} [{seg}] nome={name} anterior={prev}", flush=True)


if __name__ == "__main__":
    main()
