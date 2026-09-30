#!/usr/bin/env python3
"""Scan de strings em 0xD00000-0xE00000 (dados ainda nao vistos)."""
import ida_bytes
import re

START = 0xD00000
END = 0xE00000
PAT = re.compile(rb"[\x20-\x7E]{10,}")


def main():
    raw = ida_bytes.get_bytes(START, END - START) or b""
    strings = []
    for m in PAT.finditer(raw):
        s = m.group().decode("ascii", "replace")
        strings.append((START + m.start(), s))
    print(f"strings: {len(strings)}", flush=True)
    for ea, s in strings[:40]:
        print(f"  {hex(ea)}: {s[:95]}", flush=True)


if __name__ == "__main__":
    main()
