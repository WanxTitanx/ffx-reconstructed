# -*- coding: utf-8 -*-
# Headless idat batch decompile of FFX sphere-grid / abmap target functions.
# Run via idat.exe -A -S<script> on a COPY of the canonical i64.
import ida_auto
import ida_hexrays
import ida_funcs
import idc
import os
import sys

OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\_sg_idat_out.txt"
lines = []

def log(*a):
    lines.append(" ".join(str(x) for x in a))

def main():
    log("== idat headless sphere/abmap decompile ==")
    ida_auto.auto_wait()
    log("auto-analysis done")
    try:
        import ida_idaapi
        log("imagebase: 0x%X" % ida_idaapi.get_imagebase())
    except Exception as e:
        log("imgbase err", e)
    sys.stdout.flush()

    targets = [
        0xA57710, 0xA581F0, 0xA5A800,   # abmap link geometry / point budget
        0x681DB0, 0x7F4900,             # menu/abmap batch init + draw gate
    ]
    for ea in targets:
        name = idc.get_func_name(ea) or ("0x%X" % ea)
        log("=== %s @0x%X ===" % (name, ea))
        try:
            cf = ida_hexrays.decompile(ea)
            if cf:
                code = str(cf)
                log("DECOMPILED len=%d" % len(code))
                # grep interesting constants/symbols
                for tok in ["861", "0x35D", "860", "1024", "1021", "934",
                            "4096", "0x1000", "128", "0x80", "links", "Links",
                            "LinkBatch", "Batch", "buffer", "_BYTE"]:
                    c = code.count(tok)
                    if c:
                        log("  tok '%s': %d" % (tok, c))
                log("  HEAD:")
                for l in code.splitlines()[:40]:
                    log("   " + l)
            else:
                log("DECOMPILE -> None")
        except Exception as e:
            log("DECOMPILE EXC: %r" % (e,))
        sys.stdout.flush()

    try:
        with open(OUT, "w", encoding="utf-8") as f:
            f.write("\n".join(lines))
        log("WROTE " + OUT)
    except Exception as e:
        log("write err", e)

    # discard (do NOT save the DB) and exit
    idc.qexit(0)

try:
    main()
except Exception as e:
    with open(OUT, "a", encoding="utf-8") as f:
        f.write("\nFATAL: %r\n" % (e,))
    idc.qexit(1)
