# -*- coding: utf-8 -*-
import idaapi
import idc
import ida_hexrays
import sys

def resolve(addr):
    try:
        if isinstance(addr, int):
            return addr
        a = addr
        if a.startswith("0x") or a.startswith("0X"):
            return int(a, 16)
        return idc.get_name_ea_simple(a)
    except Exception as e:
        return idaapi.BADADDR

def decompile_ea(ea):
    try:
        cf = ida_hexrays.decompile(ea)
        if cf:
            return str(cf)
        return None
    except Exception as e:
        return "ERR: %s" % e

targets = [
    ("FFX_Menu2D_InitBatchBuffers_NoTextureFallback", 0x681DB0),
    ("FFX_Menu2D_DrawQuadIndexedBatch", 0x7F4900),
    ("FFX_Abmap_BuildLinkBatchEnd", 0xA581F0),
    ("FFX_Abmap_BuildLinkBatchSegment_structural", 0xA57710),
]

for name, ea in targets:
    resolved = resolve(ea)
    print("=== %s @ 0x%X (resolved 0x%X) ===" % (name, ea, resolved))
    if resolved == idaapi.BADADDR:
        print("  BADADDR")
        continue
    code = decompile_ea(resolved)
    if code is None:
        print("  DECOMPILE FAILED (None)")
        continue
    if code.startswith("ERR"):
        print("  ", code)
        continue
    printed = False
    for token in ["861", "0x35D", "0x35d", "860", "1024", "1021", "934",
                  "4096", "0x1000", "links", "Links", "LinkBatch", "buffer",
                  "Buffer", "Batch"]:
        c = code.lower().count(token.lower())
        if c:
            print("  const '%s': %d" % (token, c))
            printed = True
    if not printed:
        print("  (no token hits) len=%d" % len(code))
    print("  --- head ---")
    for l in code.splitlines()[:20]:
        print("  " + l)
    sys.stdout.flush()
