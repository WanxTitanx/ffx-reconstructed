import ida_hexrays, ida_funcs, json

out = {}
try:
    r = ida_hexrays.term_hexrays_plugin()
    out["term"] = r
except Exception as e:
    out["term"] = f"EXC {type(e).__name__}: {e}"

try:
    r2 = ida_hexrays.init_hexrays_plugin()
    out["reinit"] = r2
except Exception as e:
    out["reinit"] = f"EXC {type(e).__name__}: {e}"

# Now test decompile
addr = 0x9da420
f = ida_funcs.get_func(addr)
hf = ida_hexrays.hexrays_failure_t()
cf = ida_hexrays.decompile_func(f, hf)
if cf:
    out["decompile"] = "OK len=" + str(len(str(cf)))
else:
    out["decompile"] = f"FAIL: {hf} (code {hf.code})"
print(json.dumps(out, indent=1))
