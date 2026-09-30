#!/usr/bin/env python3
"""Survey: cobertura de nomes nas dispatch tables PPP + funcoes default restantes."""
import ida_bytes
import ida_funcs
import ida_name
import re

DEFAULT = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_)", re.I)

# dispatch tables PPP (do doc PPP_DISPATCH_TABLE_RE): entry 0x28B
TABLES = [("principal", 0xC3A500, 418), ("alt", 0xC3E798, 246), ("keyhole", 0xC86080, 32)]


def main():
    for tname, taddr, n in TABLES:
        raw = ida_bytes.get_bytes(taddr, n * 0x28) or b""
        named, default = 0, 0
        for i in range(n):
            base = i * 0x28
            if base + 4 > len(raw):
                break
            fn = int.from_bytes(raw[base + 0x0C:base + 0x10], "little")  # handler +0x0C?
            if fn and 0x400000 < fn < 0x2000000:
                name = ida_name.get_name(fn)
                if name and not DEFAULT.match(name):
                    named += 1
                else:
                    default += 1
        print(f"  {tname} @ {hex(taddr)}: {named} named / {default} default", flush=True)

    qty = ida_funcs.get_func_qty()
    default_fns = 0
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea)
        if name and DEFAULT.match(name):
            default_fns += 1
    print(f"funcoes default restantes: {default_fns}", flush=True)


if __name__ == "__main__":
    main()
