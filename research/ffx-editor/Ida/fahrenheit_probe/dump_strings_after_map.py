#!/usr/bin/env python3
"""Extrai strings ASCII legiveis da regiao 0xC6DC90..0xC85EB0 (apos a tabela Map)."""
import ida_bytes
import re


def main():
    start = 0xC6DC90
    end = 0xC85EB0
    raw = ida_bytes.get_bytes(start, end - start) or b""
    strings = []
    for m in re.finditer(rb"[\x20-\x7E]{6,}", raw):
        strings.append((start + m.start(), m.group().decode("ascii", "replace")))
    print(f"strings: {len(strings)}", flush=True)
    for off, s in strings[:40]:
        print(f"  {hex(off)}: {s[:80]}", flush=True)


if __name__ == "__main__":
    main()
