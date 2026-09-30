import ida_hexrays, ida_funcs, json

out = {}

try:
    r = ida_hexrays.init_hexrays_plugin()
    out["init_hexrays_plugin"] = r
except Exception as e:
    out["init_hexrays_plugin"] = f"EXC {e}"

addr = 0x9da420
f = ida_funcs.get_func(addr)
out["func"] = hex(f.start_ea) if f else None

try:
    cf = ida_hexrays.decompile_func(f)
    out["decompile_func"] = "OK" if cf else "None"
    if cf:
        out["len"] = len(str(cf))
except Exception as e:
    out["decompile_func"] = f"EXC {type(e).__name__}: {e}"

try:
    cf2 = ida_hexrays.decompile(addr, 0)
    out["decompile_flags0"] = "OK" if cf2 else "None"
except Exception as e:
    out["decompile_flags0"] = f"EXC {type(e).__name__}: {e}"

print(json.dumps(out, indent=1))
