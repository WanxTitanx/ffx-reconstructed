#!/usr/bin/env python3
"""Imprime os nomes atuais dos alvos."""
import ida_name

TARGETS = [0x2322790, 0x2322668, 0xC34194, 0xC44260, 0xC24F0C, 0xC0A09C,
           0xC53414, 0xC169B4, 0xC59564, 0xC0BB70, 0xC8F86C]


def main():
    for ea in TARGETS:
        print(f"{hex(ea)}: {ida_name.get_name(ea)}", flush=True)


if __name__ == "__main__":
    main()
