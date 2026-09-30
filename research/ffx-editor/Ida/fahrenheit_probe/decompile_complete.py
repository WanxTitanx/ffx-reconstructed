#!/usr/bin/env python3
"""DECOMPILE TOTAL v3: checkpoint (grava o ea atual antes de cada decompile) +
blacklist (pula funcoes que crasham o hrtng.dll). Relancar ate completar."""
import os
import re
import time

import ida_funcs
import ida_hexrays
import ida_name
import idc

OUT_ROOT = r"F:\ffx-reconstructed\pseudocode\complete"
CHECKPOINT = os.path.join(OUT_ROOT, "checkpoint.txt")
BLACKLIST = os.path.join(OUT_ROOT, "blacklist.txt")
BAD = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_|unknown)")


def load_blacklist():
    if not os.path.exists(BLACKLIST):
        return set()
    return {int(l.strip(), 16) for l in open(BLACKLIST, encoding="utf-8") if l.strip()}


def main(force=False):
    """Decompila funcoes com nome real. force=True: ignora .c existentes (gera cache Hex-Rays)."""
    t0 = time.time()
    if not ida_hexrays.init_hexrays_plugin():
        print("ERRO: hexrays", flush=True)
        return
    black = load_blacklist()
    print(f"blacklist: {len(black)}", flush=True)
    qty = ida_funcs.get_func_qty()
    ok = 0
    skip_existing = 0
    skipped_bad = 0
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        ea = f.start_ea
        name = ida_name.get_name(ea) or ""
        if not name or BAD.match(name):
            skipped_bad += 1
            continue
        band = f"{(ea >> 20) << 20:08X}"
        safe = re.sub(r"[^A-Za-z0-9_]", "_", name)[:60]
        out_path = os.path.join(OUT_ROOT, band, f"{ea:08X}_{safe}.c")
        if not force and os.path.exists(out_path):
            skip_existing += 1
            continue
        if ea in black:
            skip_existing += 1
            continue
        with open(CHECKPOINT, "w", encoding="utf-8") as fo:
            fo.write(f"{ea:08X} {name}\n")
        try:
            cf = ida_hexrays.decompile(f)
        except Exception:
            ok += 1
            with open(out_path, "w", encoding="utf-8") as fo:
                fo.write(f"// DECOMPILE FAILED (exception): {name}\n")
            continue
        if not cf:
            ok += 1
            with open(out_path, "w", encoding="utf-8") as fo:
                fo.write(f"// DECOMPILE FAILED (None): {name}\n")
            continue
        try:
            code = str(cf)
        except Exception:
            code = ""
        if code:
            ok += 1
            os.makedirs(os.path.dirname(out_path), exist_ok=True)
            with open(out_path, "w", encoding="utf-8", errors="replace") as fo:
                fo.write(code)
        else:
            ok += 1
            with open(out_path, "w", encoding="utf-8") as fo:
                fo.write(f"// DECOMPILE FAILED (vazio): {name}\n")
        if (i + 1) % 3000 == 0:
            print(f"...{i+1}/{qty} ok={ok} existentes={skip_existing} ({time.time()-t0:.0f}s)", flush=True)
    print(f"DONE: ok={ok} existentes={skip_existing} bad={skipped_bad} ({time.time()-t0:.0f}s)", flush=True)
    idc.save_database("")
    print("db salva", flush=True)


if __name__ == "__main__":
    main()

