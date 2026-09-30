import ida_xref, idc, ida_funcs, ida_name

# Find callers of FFX_Scene_CreatePObject (0x88CDF0)
print("callers of 0x88CDF0:")
ea = ida_xref.get_first_cref_to(0x88CDF0)
while ea != idc.BADADDR:
    f = ida_funcs.get_func(ea)
    fname = ida_name.get_name(f.start_ea) if f else "?"
    print(f"  0x{ea:X} in func 0x{f.start_ea:X} {fname}" if f else f"  0x{ea:X}")
    ea = ida_xref.get_next_cref_to(0x88CDF0, ea)
