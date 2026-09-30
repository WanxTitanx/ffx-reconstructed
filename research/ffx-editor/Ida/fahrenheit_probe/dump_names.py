#!/usr/bin/env python3
"""dump_names.py — dumpa a nlist (todos os nomes: funcoes + globals) em JSON.
Uso: OUT_JSON env var ou argv[1]. Roda no idat (com qexit) ou via MCP (sem).
"""
import json
import os
import sys

import ida_funcs
import ida_name


def collect():
    funcs = []
    globals_ = []
    # 1) funcoes
    qty = ida_funcs.get_func_qty()
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        ea = f.start_ea
        name = ida_name.get_name(ea) or ""
        if name:
            funcs.append([ea, name])
    # 2) globals via nlist (todos os nomes nao-funcao)
    try:
        n = ida_name.get_nlist_size()
        for i in range(n):
            ea = ida_name.get_nlist_ea(i)
            name = ida_name.get_nlist_name(i)
            if not name:
                continue
            if ida_funcs.get_func(ea):
                continue  # ja contado em funcs
            globals_.append([ea, name])
    except Exception as ex:
        print(f"nlist fallback: {ex}", flush=True)
    return funcs, globals_


def main():
    out = os.environ.get("OUT_JSON") or (sys.argv[1] if len(sys.argv) > 1 else "")
    if not out:
        print("OUT_JSON nao definido", flush=True)
        return
    funcs, globals_ = collect()
    with open(out, "w", encoding="utf-8") as f:
        json.dump({"funcs": funcs, "globals": globals_}, f)
    print(f"dump: {len(funcs)} funcs + {len(globals_)} globals -> {out}", flush=True)


if __name__ == "__main__":
    main()
