import ida_hexrays, json

out = {}
outfile = r"C:\Users\wande\Documents\ffx-editor-main\work\research_tools\test_decompile_many.c"
try:
    r = ida_hexrays.decompile_many(outfile, [0x9da420], 0)
    out["decompile_many"] = r
except Exception as e:
    out["decompile_many"] = f"EXC {type(e).__name__}: {e}"
print(json.dumps(out, indent=1))
