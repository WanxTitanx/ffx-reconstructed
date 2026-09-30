import ida_hexrays, ida_funcs, json

out = {}
addr = 0x9da420
f = ida_funcs.get_func(addr)
hf = ida_hexrays.hexrays_failure_t()
cf = ida_hexrays.decompile_func(f, hf)
if cf:
    out["ok"] = True
    out["len"] = len(str(cf))
else:
    out["ok"] = False
    out["hf_str"] = str(hf)
    out["hf_code"] = hf.code
print(json.dumps(out, indent=1))
