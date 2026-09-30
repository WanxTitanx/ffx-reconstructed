import ida_funcs, idc

f = ida_funcs.get_func(0x88CA30)
if not f:
    print("no func at 0x88CA30")
else:
    print(f"func 0x{f.start_ea:X} - 0x{f.end_ea:X}, size {f.size()}")
    ea = f.start_ea
    count = 0
    while ea < f.end_ea and count < 120:
        print(f"0x{ea:X}: {idc.generate_disasm_line(ea, 0)}")
        ea = idc.next_head(ea, f.end_ea)
        count += 1
