import _ida_hexrays, json

out = {}
outfile = r"C:\Users\wande\Documents\ffx-editor-main\work\research_tools\test_decompile_many3.c"

# Try calling through _ida_hexrays directly
try:
    r = _ida_hexrays.decompile_many(outfile, [0x9da420], 0)
    out["_direct"] = r
except Exception as e:
    out["_direct"] = f"EXC {type(e).__name__}: {e}"

print(json.dumps(out, indent=1))
