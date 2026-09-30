import ida_hexrays, ida_funcs, json

out = {}
addr = 0x9da420
f = ida_funcs.get_func(addr)
hf = ida_hexrays.hexrays_failure_t()
try:
    cf = ida_hexrays.decompile_func(f, hf)
    out["decompile_func_hf"] = "OK" if cf else "None"
    if cf:
        out["len"] = len(str(cf))
except Exception as e:
    out["decompile_func_hf"] = f"EXC {type(e).__name__}: {e}"

hf2 = ida_hexrays.hexrays_failure_t()
try:
    cf2 = ida_hexrays.decompile(addr, hf2)
    out["decompile_hf"] = "OK" if cf2 else "None"
    if cf2:
        out["len2"] = len(str(cf2))
except Exception as e:
    out["decompile_hf"] = f"EXC {type(e).__name__}: {e}"

print(json.dumps(out, indent=1))
