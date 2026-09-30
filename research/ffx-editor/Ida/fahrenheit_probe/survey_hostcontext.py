#!/usr/bin/env python3
"""Survey da HostContextTable @ 0xC64CE8 (512 slots): quantos nomeados vs default."""
import ida_bytes
import ida_name
import re

TABLE = 0xC64CE8
DEFAULT = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_)", re.I)


def main():
    raw = ida_bytes.get_bytes(TABLE, 512 * 4) or b""
    named, default, zero = 0, 0, 0
    samples = []
    for i in range(512):
        ptr = int.from_bytes(raw[i * 4:i * 4 + 4], "little")
        if ptr == 0:
            zero += 1
            continue
        name = ida_name.get_name(ptr)
        if name and not DEFAULT.match(name):
            named += 1
        else:
            default += 1
            if len(samples) < 10:
                samples.append((i, hex(ptr), name))
    print(f"named={named} default={default} zero={zero}", flush=True)
    for i, p, n in samples:
        print(f"  slot {i}: {p} {n}", flush=True)


if __name__ == "__main__":
    main()
