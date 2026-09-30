import ida_hexrays, ida_funcs, json

out = {}
addr = 0x9da420
f = ida_funcs.get_func(addr)
hf = ida_hexrays.hexrays_failure_t()
cf = ida_hexrays.decompile_func(f, hf)
out["cf"] = "None" if cf is None else "OK"
# inspect failure object
try:
    out["hf_str"] = str(hf)
except Exception as e:
    out["hf_str"] = f"EXC {e}"
try:
    out["hf_code"] = hf.code
except Exception as e:
    out["hf_code"] = f"EXC {e}"
try:
    out["hf_errcode"] = hf.errcode
except Exception as e:
    out["hf_errcode"] = f"EXC {e}"
# check if decompiler is loaded via ida_hexrays.get_hexrays_version
try:
    out["hexrays_version"] = ida_hexrays.get_hexrays_version()
except Exception as e:
    out["hexrays_version"] = f"EXC {e}"
print(json.dumps(out, indent=1))
