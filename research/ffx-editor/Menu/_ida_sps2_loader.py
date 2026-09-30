import idautils, idc, ida_funcs, ida_bytes

# find function containing 0xC58E44 (sps2 table)
for ea in [0xC58E44, 0xC58E54]:
    f = ida_funcs.get_func(ea)
    print("0x%X in func: %s @ %s" % (ea, idc.get_func_name(ea) if f else "?", hex(f.start_ea) if f else "?"))
    if f:
        # dump the function start
        print("  func start: 0x%X size: 0x%X" % (f.start_ea, f.size()))
        # check for the table around 0xC58E44
        for off in range(0, 0x80, 4):
            ea2 = 0xC58E00 + off
            b = ida_bytes.get_dword(ea2)
            print("  0x%X: 0x%08X" % (ea2, b))
