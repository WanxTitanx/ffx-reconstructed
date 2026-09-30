#!/usr/bin/env python3
"""Lote 6: renomeia thunks j_* -> <Destino>_Thunk; conta sub_* reais restantes."""
import ida_bytes
import ida_funcs
import ida_name
import idc
import re

J_RE = re.compile(r"^j_(.+)$")
SUB_RE = re.compile(r"^sub_[0-9A-F]+$")


def main():
    qty = ida_funcs.get_func_qty()
    thunk_applied, sub_real = 0, 0
    sub_samples = []
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea) or ""
        m = J_RE.match(name)
        if m:
            target = m.group(1)
            if target.startswith("FFX_") or target.startswith("Phyre") or target.startswith("ppp"):
                new_name = f"{target}_Thunk"
                if ida_name.set_name(f.start_ea, new_name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
                    thunk_applied += 1
            continue
        if SUB_RE.match(name) and f.size() > 8:
            sub_real += 1
            if len(sub_samples) < 10:
                sub_samples.append((f.start_ea, f.size()))
    idc.save_database("")
    print(f"thunks renomeados: {thunk_applied}", flush=True)
    print(f"sub_* reais (size>8) restantes: {sub_real}", flush=True)
    for ea, size in sub_samples:
        print(f"  {hex(ea)} size={size}", flush=True)


if __name__ == "__main__":
    main()
