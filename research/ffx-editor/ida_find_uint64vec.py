import json

# Find the right vector type
candidates = ["uint64vec_t", "u64vec_t", "uint64_vec", "ea_vec", "eavec_t"]
out = {}
for c in candidates:
    try:
        import ida_idaapi
        obj = getattr(ida_idaapi, c, None)
        out[c] = "found" if obj else "not in ida_idaapi"
    except:
        pass
    try:
        import ida_hexrays
        obj = getattr(ida_hexrays, c, None)
        out[f"hex_{c}"] = "found" if obj else "not in ida_hexrays"
    except:
        pass

# Check decompile_many signature
import ida_hexrays
import inspect
try:
    sig = inspect.signature(ida_hexrays.decompile_many)
    out["decompile_many_sig"] = str(sig)
except:
    out["decompile_many_sig"] = "can't inspect"

print(json.dumps(out, indent=1))
