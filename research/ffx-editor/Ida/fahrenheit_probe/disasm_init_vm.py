#!/usr/bin/env python3
"""Extrai os pares (channel, tabela) das chamadas RegisterFuncspace no init da VM."""
import ida_bytes
import ida_ua
import idc

START = 0x86D788
END = 0x86D830


def main():
    ea = START
    while ea < END:
        insn = ida_ua.insn_t()
        length = ida_ua.decode_insn(insn, ea)
        if length <= 0:
            break
        line = idc.generate_disasm_line(ea, 0)
        print(f"{hex(ea)}: {line}", flush=True)
        ea += length


if __name__ == "__main__":
    main()
