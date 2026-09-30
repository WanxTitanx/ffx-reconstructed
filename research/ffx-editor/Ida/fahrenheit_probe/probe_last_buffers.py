#!/usr/bin/env python3
"""Dump floats de 0xC8F934 + verifica 0xC77120 e 0xCB4D0C/0xCE844C conteudo."""
import ida_bytes
import struct


def main():
    raw = ida_bytes.get_bytes(0xC8F934, 64) or b""
    vals = struct.unpack("<16f", raw)
    print("floats 0xC8F934:", [round(v, 3) for v in vals], flush=True)
    # 0xC77120
    raw2 = ida_bytes.get_bytes(0xC77120, 32) or b""
    print("0xC77120:", raw2.hex(), flush=True)
    # 0xCB4D0C conteudo
    raw3 = ida_bytes.get_bytes(0xCB4D0C, 32) or b""
    print("0xCB4D0C:", raw3.hex(), flush=True)


if __name__ == "__main__":
    main()
