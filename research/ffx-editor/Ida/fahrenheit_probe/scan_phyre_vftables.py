#!/usr/bin/env python3
"""Frente 2: scan de vftables Phyre no .rdata (sequencias >= 5 ponteiros p/ funcoes Phyre).

Renomeia o inicio da sequencia como Phyre_Vftable_<ADDR> (default-only).
"""
import ida_bytes
import ida_funcs
import ida_name
import idc
import re

DEFAULT = re.compile(r"^(off_|dword_|unk_)", re.I)
VFT_START = 0xC00000
VFT_END = 0x1400000
MIN_RUN = 5


def main():
    raw = ida_bytes.get_bytes(VFT_START, VFT_END - VFT_START) or b""
    applied = 0
    found = 0
    i = 0
    runs = []
    while i < len(raw) - 4:
        ptr = int.from_bytes(raw[i:i + 4], "little")
        if 0x400000 <= ptr < 0x1000000 and ida_funcs.get_func(ptr):
            name = ida_name.get_name(ptr) or ""
            if name.startswith(("Phyre", "PClassDescriptor", "P", "FFX_Phyre")):
                # conta a corrida
                run = 1
                j = i + 4
                while j < len(raw) - 4:
                    p2 = int.from_bytes(raw[j:j + 4], "little")
                    if 0x400000 <= p2 < 0x1000000 and ida_funcs.get_func(p2):
                        n2 = ida_name.get_name(p2) or ""
                        if n2.startswith(("Phyre", "PClassDescriptor", "P", "FFX_Phyre")):
                            run += 1
                            j += 4
                            continue
                    break
                if run >= MIN_RUN:
                    runs.append((VFT_START + i, run))
                    i = j
                    continue
        i += 4
    print(f"vftables candidatas (>= {MIN_RUN}): {len(runs)}", flush=True)
    for ea, run in runs[:25]:
        cur = ida_name.get_name(ea)
        if not cur or DEFAULT.match(cur):
            if ida_name.set_name(ea, f"Phyre_Vftable_{ea:X}", ida_name.SN_NOCHECK | ida_name.SN_FORCE):
                applied += 1
                print(f"  {hex(ea)} run={run} -> Phyre_Vftable_{ea:X}", flush=True)
        else:
            print(f"  {hex(ea)} run={run} (ja tem {cur})", flush=True)
    idc.save_database("")
    print(f"DONE: vftables={len(runs)} applied={applied} — db salva.", flush=True)


if __name__ == "__main__":
    main()
