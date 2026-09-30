import ida_hexrays, json

out = {}
try:
    cf = ida_hexrays.decompile_many([0x9da420], 0)
    out["decompile_many"] = "OK" if cf else "None"
    if cf:
        out["len"] = len(str(cf))
except Exception as e:
    out["decompile_many"] = f"EXC {type(e).__name__}: {e}"

# Try DECOMP_NO_WAIT flag
try:
    cf2 = ida_hexrays.decompile_many([0x9da420], ida_hexrays.DECOMP_NO_WAIT)
    out["decompile_many_nowait"] = "OK" if cf2 else "None"
except Exception as e:
    out["decompile_many_nowait"] = f"EXC {type(e).__name__}: {e}"

print(json.dumps(out, indent=1))
