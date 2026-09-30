import ida_hexrays, ida_funcs, idaapi, idc
addr = 0x88C7D0
f = ida_funcs.get_func(addr)
if not f:
    print("NO FUNC")
else:
    print("FUNC", hex(f.start_ea), hex(f.end_ea))
    try:
        cf = ida_hexrays.decompile(f)
        print(cf)
    except Exception as e:
        print("DECOMPILE FAIL:", e)
