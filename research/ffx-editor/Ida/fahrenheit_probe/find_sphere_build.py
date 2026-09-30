#!/usr/bin/env python3
"""Procura a string 'Standard Sphere Grid' e paths de grid no exe."""
import ida_bytes
import re

START = 0x400000
END = 0x1500000
PATS = [rb"Standard Sphere Grid", rb"sphere_build", rb"SphereGrid", rb"\.contents\.dat"]


def main():
    raw = ida_bytes.get_bytes(START, END - START) or b""
    for pat in PATS:
        hits = [m.start() for m in re.finditer(pat, raw)]
        print(f"{pat}: {len(hits)} hits", flush=True)
        for h in hits[:5]:
            s = raw[h - 20:h + 60]
            st = s.decode("ascii", "replace")
            print(f"  {hex(START + h)}: {st}", flush=True)


if __name__ == "__main__":
    main()
