# -*- coding: utf-8 -*-
import idaapi
import idc
import ida_hexrays
import ida_funcs
import ida_auto
import sys

print("== hexrays diagnostics ==")
try:
    import ida_hexrays as hx
    print("hexrays module OK")
    try:
        print("has_cpp:", hx.has_cpp())
    except Exception as e:
        print("has_cpp err:", e)
    try:
        ver = hx.get_hexrays_version()
        print("hexrays version:", ver)
    except Exception as e:
        print("version err:", e)
    try:
        import ida_idaapi
        print("headless/plugin present")
    except Exception as e:
        print("idaapi err:", e)
except Exception as e:
    print("hexrays import failed:", repr(e))

sys.stdout.flush()

# Info about the failing functions
targets = {
    0xA57710: "FFX_Abmap_BuildLinkBatchSegment_structural",
    0xA581F0: "FFX_Abmap_BuildLinkBatchEnd",
    0xA5A800: "FFX_Abmap_UpdateRuntimeLinkGeometry",
    0x681DB0: "FFX_Menu2D_InitBatchBuffers_NoTextureFallback",
}

for ea, name in targets.items():
    f = ida_funcs.get_func(ea)
    if f is None:
        print("NO FUNC at %X" % ea)
        continue
    flag = f.flags
    print("FUNC %s @%X size=%X flags=%X chunks=%d" % (
        name, ea, f.size(), flag, f.chunk_qty()))
    try:
        cf = ida_hexrays.decompile(ea)
        if cf:
            cs = str(cf)
            print("  DECOMPILED len=%d head=%r" % (len(cs), cs[:80]))
        else:
            print("  decompile -> None")
    except Exception as e:
        print("  decompile EXC: %r" % (e,))
    sys.stdout.flush()
