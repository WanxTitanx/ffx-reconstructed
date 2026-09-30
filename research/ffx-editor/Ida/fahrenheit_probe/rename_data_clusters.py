#!/usr/bin/env python3
"""Frente 4: os globals default restantes — agrupa por padrao (flt/dword/word...) e
renomeia clusters contiguos como tabelas (FFX_Data_Table_<ADDR>) quando >= 8 items."""
import ida_bytes
import ida_name
import idc
import re

DEFAULT = re.compile(r"^(dword_|off_|flt_|byte_|word_|qword_|unk_)", re.I)


def main():
    seg = idc.get_segm_by_sel(idc.selector_by_name(".data"))
    start = idc.get_segm_start(seg)
    end = idc.get_segm_end(seg)
    ea = start
    defaults = []
    while ea < end:
        name = ida_name.get_name(ea)
        if name and DEFAULT.match(name):
            defaults.append(ea)
        ea = ida_bytes.next_head(ea, end)
    print(f"defaults restantes: {len(defaults)}", flush=True)
    # clusters contiguos (distancias pequenas)
    clusters = []
    cur = [defaults[0]] if defaults else []
    for i in range(1, len(defaults)):
        gap = defaults[i] - defaults[i - 1]
        if gap <= 16:
            cur.append(defaults[i])
        else:
            if len(cur) >= 8:
                clusters.append(cur)
            cur = [defaults[i]]
    if len(cur) >= 8:
        clusters.append(cur)
    print(f"clusters >= 8: {len(clusters)}", flush=True)
    applied = 0
    for cl in clusters[:30]:
        start_ea = cl[0]
        cur_name = ida_name.get_name(start_ea)
        if cur_name and DEFAULT.match(cur_name):
            new_name = f"FFX_Data_Table_{start_ea:X}"
            if ida_name.set_name(start_ea, new_name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
                applied += 1
                print(f"  {hex(start_ea)} cluster {len(cl)} -> {new_name}", flush=True)
    idc.save_database("")
    print(f"DONE: applied={applied} — db salva.", flush=True)


if __name__ == "__main__":
    main()
