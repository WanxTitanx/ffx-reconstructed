#!/usr/bin/env python3
"""survey_names_live.py — diagnostico de nomes/funcoes na db aberta (via MCP)."""
import re

import ida_funcs
import ida_name

BAD = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_|unknown|dword_|byte_|word_|off_|qword_|unk_)")


def main():
    qty = ida_funcs.get_func_qty()
    named = 0
    default = 0
    nullsub = 0
    by_band = {}
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        ea = f.start_ea
        name = ida_name.get_name(ea) or ""
        band = (ea >> 20) << 20
        if not name or BAD.match(name):
            if name.startswith("nullsub_"):
                nullsub += 1
            else:
                default += 1
        else:
            named += 1
            b = by_band.setdefault(band, 0)
            by_band[band] = b + 1
    print(f"total funcs: {qty}", flush=True)
    print(f"nomeadas: {named} | default (sub_/FUN_/loc_/data): {default} | nullsub_: {nullsub}", flush=True)
    for band in sorted(by_band):
        print(f"  band {band:08X}: {by_band[band]} nomeadas", flush=True)


if __name__ == "__main__":
    main()
