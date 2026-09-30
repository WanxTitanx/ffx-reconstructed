import ida_bytes, idc, ida_xref, ida_funcs, ida_name

# Dump strings around 0xB5EAE0
for ea in range(0xB5EAE0, 0xB5EB40, 16):
    data = ida_bytes.get_bytes(ea, 16)
    if data:
        printable = ''.join(chr(b) if 32 <= b < 127 else '.' for b in data)
        print(f"0x{ea:X}: {data.hex(' ')}  {printable}")

# Find xrefs to 0xB5EB01 (.dcp)
print("\nxrefs to 0xB5EB01 (.dcp):")
ea = ida_xref.get_first_dref_to(0xB5EB01)
while ea != idc.BADADDR:
    f = ida_funcs.get_func(ea)
    fname = ida_name.get_name(f.start_ea) if f else "?"
    print(f"  dref 0x{ea:X} in func 0x{f.start_ea:X} {fname}" if f else f"  dref 0x{ea:X}")
    ea = ida_xref.get_next_dref_to(0xB5EB01, ea)
