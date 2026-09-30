#!/usr/bin/env python3
"""Diagnostica APIs de flags no IDA 9.x."""
import ida_bytes


def main():
    cands = [n for n in dir(ida_bytes) if 'FF_' in n or 'unknown' in n.lower() or 'udb' in n.lower()]
    print("ida_bytes cands:", cands[:30], flush=True)
    flags = ida_bytes.get_flags(0x401000)
    print("flags sample:", hex(flags), flush=True)
    for fn in ["is_unknown", "is_udb", "is_byte", "is_word", "is_dword", "is_qword", "is_data", "is_code", "is_head", "is_tail"]:
        f = getattr(ida_bytes, fn, None)
        if f:
            try:
                print(f"{fn}(flags) = {f(flags)}", flush=True)
            except Exception as ex:
                print(f"{fn} err: {ex}", flush=True)
    # constantes candidatas
    for c in ["FF_UD", "FF_CODE", "FF_DATA", "FF_BYTE", "FF_DWORD"]:
        v = getattr(ida_bytes, c, None)
        print(f"ida_bytes.{c} = {v}" if v is not None else f"ida_bytes.{c} = MISSING", flush=True)


if __name__ == "__main__":
    main()
