import ida_hexrays, ida_funcs, json

out = {}
addr = 0x9da420
f = ida_funcs.get_func(addr)
try:
    cf = ida_hexrays.hx_decompile(f)
    out["hx_decompile"] = "OK" if cf else "None"
    if cf:
        out["len"] = len(str(cf))
except Exception as e:
    out["hx_decompile"] = f"EXC {type(e).__name__}: {e}"

# try decompile_many
try:
    cf2 = ida_hexrays.decompile_many([addr])
    out["decompile_many"] = "OK" if cf2 else "None"
except Exception as e:
    out["decompile_many"] = f"EXC {type(e).__name__}: {e}"

print(json.dumps(out, indent=1))
