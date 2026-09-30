#!/usr/bin/env python3
"""Lote 10: renomeia funcoes via blobs name_ptr+fn_ptr (como o PPP).

Filtros: name_ptr aponta p/ string ASCII >= 4 chars; fn_ptr e funcao default;
ignora pares repetidos (ruido). Nome: <string> (sanitizada).
"""
import ida_bytes
import ida_funcs
import ida_name
import idc
import re

DEFAULT = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_)", re.I)
BAD = re.compile(r"[^A-Za-z0-9_]")
PARS = {}


def main():
    start = 0xC00000
    end = 0xE00000
    raw = ida_bytes.get_bytes(start, end - start) or b""
    pairs = []
    i = 0
    while i < len(raw) - 8:
        v = int.from_bytes(raw[i:i + 4], "little")
        if 0xB40000 <= v < 0xB90000:
            for j in range(i + 4, min(i + 0x44, len(raw) - 4), 4):
                fv = int.from_bytes(raw[j:j + 4], "little")
                if 0x400000 <= fv < 0xA00000:
                    pairs.append((start + i, v, fv))
                    break
        i += 4
    # remove pares repetidos (mesmo name_ptr+fn_ptr)
    uniq = sorted(set(pairs))
    print(f"pares unicos: {len(uniq)}", flush=True)
    applied = 0
    for _, name_ptr, fn_ptr in uniq:
        cur = ida_name.get_name(fn_ptr)
        if cur and not DEFAULT.match(cur):
            continue
        if not ida_funcs.get_func(fn_ptr):
            continue
        s = ida_bytes.get_bytes(name_ptr, 64) or b""
        st = s.split(b"\x00")[0].decode("ascii", "replace")
        if len(st) < 4 or not st.isascii():
            continue
        clean = BAD.sub("_", st)
        if not clean[0].isalpha():
            clean = "Fn_" + clean
        if ida_name.set_name(fn_ptr, clean, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
            applied += 1
    idc.save_database("")
    print(f"DONE: applied={applied} — db salva.", flush=True)


if __name__ == "__main__":
    main()
