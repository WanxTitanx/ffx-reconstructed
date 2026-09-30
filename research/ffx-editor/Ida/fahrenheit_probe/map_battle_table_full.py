#!/usr/bin/env python3
"""Mapa COMPLETO da tabela Battle (0xC42618..0xC43988 = 0x1370 B = 311 entradas de 16B)."""
import ida_bytes
import ida_name

TABLE = 0xC42618
END = 0xC43988


def main():
    raw = ida_bytes.get_bytes(TABLE, END - TABLE)
    if not raw:
        print("FALHA leitura", flush=True)
        return
    n = (END - TABLE) // 16
    print(f"entradas: {n}", flush=True)
    filled = 0
    for i in range(n):
        base = i * 16
        callpopa = int.from_bytes(raw[base:base + 4], "little")
        pad = int.from_bytes(raw[base + 4:base + 8], "little")
        float_ret = int.from_bytes(raw[base + 8:base + 12], "little")
        int_ret = int.from_bytes(raw[base + 12:base + 16], "little")
        names = []
        for off, ptr in ((0, callpopa), (8, float_ret), (0xC, int_ret)):
            if ptr:
                nm = ida_name.get_name(ptr) or f"(default {hex(ptr)})"
                names.append(f"+{off:X}={nm}")
        if names:
            filled += 1
            print(f"  [{i}] ID 0x{0x7000 + i:X} {' '.join(names)}", flush=True)
    print(f"TOTAL preenchidas: {filled}/{n}", flush=True)


if __name__ == "__main__":
    main()
