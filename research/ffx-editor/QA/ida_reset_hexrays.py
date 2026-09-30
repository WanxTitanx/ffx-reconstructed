import ida_hexrays, json

out = {}
try:
    r = ida_hexrays.qexit()
    out["qexit"] = r
except Exception as e:
    out["qexit"] = f"EXC {type(e).__name__}: {e}"

try:
    r2 = ida_hexrays.init_hexrays_plugin()
    out["reinit"] = r2
except Exception as e:
    out["reinit"] = f"EXC {type(e).__name__}: {e}"

print(json.dumps(out, indent=1))
