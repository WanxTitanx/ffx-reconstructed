#!/usr/bin/env python3
"""Dump do buffer 0x22FB6C1 (41KB): bytes iniciais + strings."""
import ida_bytes
import re


def main():
    start = 0x22FB6C1
    size = 40999
    raw = ida_bytes.get_bytes(start, min(size, 4096)) or b""
    print("primeiros 128 bytes:", raw[:128].hex(), flush=True)
    strings = [(m.start(), m.group().decode("ascii", "replace"))
               for m in re.finditer(rb"[\x20-\x7E]{5,}", raw)]
    print(f"strings nos 4KB: {len(strings)}", flush=True)
    for off, s in strings[:12]:
        print(f"  +{off}: {s[:90]}", flush=True)


if __name__ == "__main__":
    main()
