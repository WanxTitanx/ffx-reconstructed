import ida_hexrays, ida_idaapi, json

out = {}
outfile = r"C:\Users\wande\Documents\ffx-editor-main\work\research_tools\test_decompile_many2.c"
# Build a proper uint64vec_t
vec = ida_idaapi.uint64vec_t()
for a in [0x9da420, 0x9dae70]:
    vec.push_back(a)
try:
    r = ida_hexrays.decompile_many(outfile, vec, 0)
    out["decompile_many"] = r
except Exception as e:
    out["decompile_many"] = f"EXC {type(e).__name__}: {e}"
print(json.dumps(out, indent=1))
