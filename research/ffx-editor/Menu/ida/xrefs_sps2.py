import ida_xref, idc, ida_funcs, ida_name

# Find xrefs to the .sps2 string at 0xB5E831
for addr in [0xB5E831, 0xB5E84F, 0xB5E86F, 0xB5E891]:
    print(f"xrefs to 0x{addr:X}:")
    for xref in ida_xref.get_first_dref_to(addr), ida_xref.get_first_cref_to(addr):
        pass
    ea = ida_xref.get_first_dref_to(addr)
    while ea != idc.BADADDR:
        f = ida_funcs.get_func(ea)
        fname = ida_name.get_name(f.start_ea) if f else "?"
        print(f"  dref 0x{ea:X} in func 0x{f.start_ea:X} {fname}" if f else f"  dref 0x{ea:X} (no func)")
        ea = ida_xref.get_next_dref_to(addr, ea)
    ea = ida_xref.get_first_cref_to(addr)
    while ea != idc.BADADDR:
        f = ida_funcs.get_func(ea)
        fname = ida_name.get_name(f.start_ea) if f else "?"
        print(f"  cref 0x{ea:X} in func 0x{f.start_ea:X} {fname}" if f else f"  cref 0x{ea:X} (no func)")
        ea = ida_xref.get_next_cref_to(addr, ea)
