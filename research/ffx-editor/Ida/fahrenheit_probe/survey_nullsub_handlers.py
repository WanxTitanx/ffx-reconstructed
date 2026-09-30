#!/usr/bin/env python3
"""Frente B: nullsub_* que aparecem como handlers em tabelas ATEL (funcionalidade desabilitada)."""
import ida_bytes
import ida_name
import re

DEFAULT = re.compile(r"^nullsub_\d+$")
TABLES = [("Movie", 0xC40E20, 383), ("Battle", 0xC42618, 311), ("Camera", 0xC43988, 3180),
          ("Common", 0xC50050, 689), ("Default", 0xC52B60, 8), ("Math", 0xC52BE0, 31),
          ("Debug", 0xC52DD8, 2734), ("Mount", 0xC5D8C0, 61), ("Map", 0xC5DC90, 4096),
          ("AbiMap", 0xC85EB0, 749), ("SgEvent", 0xC88D88, 71), ("ChEvent", 0xC891F8, 256)]


def main():
    for tname, taddr, n in TABLES:
        raw = ida_bytes.get_bytes(taddr, n * 16) or b""
        nulls = {}
        for i in range(n):
            for field in (0, 8, 12):
                ptr = int.from_bytes(raw[i * 16 + field:i * 16 + field + 4], "little")
                if not (0x400000 <= ptr < 0xA00000):
                    continue
                name = ida_name.get_name(ptr)
                if name and DEFAULT.match(name):
                    nulls.setdefault(ptr, []).append(f"0x{i & 0xFFF:X}")
        if nulls:
            print(f"{tname}: {len(nulls)} nullsub handlers", flush=True)
            for ptr, slots in list(nulls.items())[:5]:
                print(f"  {hex(ptr)} slots={slots[:4]}", flush=True)


if __name__ == "__main__":
    main()
