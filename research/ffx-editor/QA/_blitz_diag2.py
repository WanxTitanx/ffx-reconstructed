import ida_hexrays, ida_funcs, idaapi

print("init:", ida_hexrays.init_hexrays_plugin())
hf = ida_hexrays.hexrays_failure_t()
cf = ida_hexrays.decompile(0x8B1400, hf)
print("cfunc:", cf)
print("hf.code:", hf.code)
print("hf.errea:", hex(hf.errea))
print("hf.str:", hf.str)
print("MERR codes: INTERNAL=%d LIC=%d" % (ida_hexrays.MERR_INTERNAL, ida_hexrays.MERR_LICENSE))
