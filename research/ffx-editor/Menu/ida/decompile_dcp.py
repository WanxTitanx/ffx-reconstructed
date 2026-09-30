import ida_hexrays, ida_funcs, idc

f = ida_funcs.get_func(0x88CA30)
if f:
    cf = ida_hexrays.decompile(f.start_ea)
    if cf:
        print(str(cf))
    else:
        print("decompile failed")
else:
    print("no func")
