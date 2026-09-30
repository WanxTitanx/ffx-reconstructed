import ida_hexrays, traceback, json

out = {}
for addr in [0x9da420, 0x7fd640, 0x401020]:
    try:
        cf = ida_hexrays.decompile(addr)
        if cf is None:
            out[hex(addr)] = "decompile returned None"
        else:
            out[hex(addr)] = "OK len=" + str(len(str(cf)))
    except Exception as e:
        out[hex(addr)] = f"EXC {type(e).__name__}: {e}"
print(json.dumps(out, indent=1))
