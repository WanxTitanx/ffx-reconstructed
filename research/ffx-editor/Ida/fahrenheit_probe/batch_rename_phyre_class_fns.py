#!/usr/bin/env python3
"""Lote 3: renomeia funcoes default que referenciam strings de nomes de classe Phyre.

Heuristica: se a funcao default referencia (data xref) uma string que parece nome de
classe Phyre (P[A-Za-z0-9_:<>*]+), renomeia para Phyre_<Classe>_Fn_<ADDR>.
"""
import ida_bytes
import ida_funcs
import ida_name
import ida_xref
import idc
import re

DEFAULT = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_)", re.I)
CLASS_RE = re.compile(r"^P[A-Za-z][A-Za-z0-9_:<>*]*$")


def main():
    qty = ida_funcs.get_func_qty()
    applied, skipped = 0, 0
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        fname = ida_name.get_name(f.start_ea)
        if not fname or not DEFAULT.match(fname):
            continue
        classes = set()
        xb = ida_xref.get_first_dref_from(f.start_ea)
        while xb != idc.BADADDR:
            if ida_bytes.is_strlit(ida_bytes.get_flags(xb)):
                s = ida_bytes.get_strlit_contents(xb, 0, 0) or b""
                try:
                    st = s.decode("ascii", "replace").strip()
                except Exception:
                    st = ""
                if CLASS_RE.match(st):
                    classes.add(st)
            xb = ida_xref.get_next_dref_from(f.start_ea, xb)
        if len(classes) == 1:
            cls = classes.pop()
            new_name = f"Phyre_{cls}_Fn_{f.start_ea:X}"
            if ida_name.set_name(f.start_ea, new_name, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
                applied += 1
        else:
            skipped += 1
    idc.save_database("")
    print(f"DONE: applied={applied} skipped={skipped} — db salva.", flush=True)


if __name__ == "__main__":
    main()
