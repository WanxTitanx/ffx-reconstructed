#!/usr/bin/env python3
"""Frente 4: amostra dos handlers da tabela Debug ATEL (2.734 entradas)."""
import ida_bytes
import ida_name
import re

TABLE = 0xC52DD8
N = 2734
DEFAULT = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_)", re.I)


def main():
    raw = ida_bytes.get_bytes(TABLE, N * 16) or b""
    names = set()
    default = 0
    for i in range(N):
        for field in (0, 8, 12):
            ptr = int.from_bytes(raw[i * 16 + field:i * 16 + field + 4], "little")
            if not (0x400000 <= ptr < 0xA00000):
                continue
            name = ida_name.get_name(ptr)
            if name and not DEFAULT.match(name):
                names.add(name)
            else:
                default += 1
    print(f"handlers unicos nomeados: {len(names)} default={default}", flush=True)
    for n in sorted(names)[:40]:
        print(f"  {n}", flush=True)


if __name__ == "__main__":
    main()
