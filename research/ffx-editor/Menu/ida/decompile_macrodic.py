import ida_hexrays, ida_funcs

f = ida_funcs.get_func(0x8B8570)
if f:
    cf = ida_hexrays.decompile(f.start_ea)
    if cf:
        print(str(cf))
    else:
        print("decompile failed")
else:
    print("no func")
