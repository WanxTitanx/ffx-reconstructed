#!/usr/bin/env python3
"""Conta globals FFX_*_Const_* no .rdata + renomeia 0xB92210."""
import ida_bytes
import ida_name
import idc
import re

PAT = re.compile(r"^FFX_(\w+)_Const_[0-9A-F]+$")


def main():
    seg = idc.get_segm_by_sel(idc.selector_by_name(".rdata")) or idc.get_first_seg()
    start = idc.get_segm_start(seg)
    end = idc.get_segm_end(seg)
    ea = start
    count = 0
    while ea < end:
        name = ida_name.get_name(ea)
        if name and PAT.match(name):
            count += 1
        ea = ida_bytes.next_head(ea, end)
    print(f"total FFX_*_Const_*: {count}", flush=True)
    # renomeia 0xB92210 se default
    cur = ida_name.get_name(0xB92210)
    if cur and cur.startswith(("qword_", "dword_", "unk_")):
        if ida_name.set_name(0xB92210, "FFX_Engine_GlobalScaleConstant",
                             ida_name.SN_NOCHECK | ida_name.SN_FORCE):
            print("0xB92210 -> FFX_Engine_GlobalScaleConstant", flush=True)
    idc.save_database("")
    print("db salva", flush=True)


if __name__ == "__main__":
    main()
