#!/usr/bin/env python3
"""Scan real byte-a-byte do .rodata e _RDATA (4KB cada)."""
import ida_bytes


def scan_unknown(start, end, label):
    n = 0
    first = -1
    ea = start
    while ea < end:
        if ida_bytes.is_unknown(ida_bytes.get_flags(ea)):
            n += 1
            if first < 0:
                first = ea
        ea += 1
    print(f"{label}: {n} unknown reais (primeiro: {hex(first) if first >= 0 else '-'})", flush=True)


def main():
    scan_unknown(0x25D7000, 0x25D8000, ".rodata")
    scan_unknown(0x25D8000, 0x25D9000, "_RDATA")


if __name__ == "__main__":
    main()

