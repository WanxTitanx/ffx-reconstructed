import ida_hexrays, os

OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\spheregrid_re"

def dump(ea, name):
    try:
        cf = ida_hexrays.decompile(ea)
        code = str(cf) if cf else "DECOMPILE FAILED"
    except Exception as e:
        code = "EXC: %r" % e
    with open(os.path.join(OUT, name + ".txt"), "w", encoding="utf-8") as f:
        f.write(code)
    return len(code)

print({"A53DE0": dump(0xA53DE0, "decompile_A53DE0"),
       "A54860": dump(0xA54860, "decompile_A54860"),
       "785000": dump(0x785000, "decompile_785000"),
       "A572E0": dump(0xA572E0, "decompile_A572E0"),
       "A48910": dump(0xA48910, "decompile_A48910")})
