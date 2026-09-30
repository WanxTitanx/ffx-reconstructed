#!/usr/bin/env python3
"""Verifica a regiao da Map alem de 4096 entradas (0xC6DC90..0xC85EB0): o que sao os ponteiros?"""
import ida_bytes
import ida_name
import ida_funcs


def main():
    for ea in (0xC6DC90, 0xC70000, 0xC74000, 0xC78000, 0xC7C000, 0xC80000, 0xC84000):
        ptr = int.from_bytes(ida_bytes.get_bytes(ea, 4), "little")
        nm = ida_name.get_name(ptr) if ptr else None
        is_fn = bool(ida_funcs.get_func(ptr)) if ptr else False
        print(f"{hex(ea)}: ptr={hex(ptr)} nome={nm} eh_funcao={is_fn}", flush=True)


if __name__ == "__main__":
    main()
