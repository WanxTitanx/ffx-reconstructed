import idautils, idc, ida_funcs

# xrefs to the sps2 path strings and menu format strings
addrs = [0xb5e818, 0xb5e898, 0xb5eaf8, 0xb5ebf8, 0xb655d8]
for a in addrs:
    print("=== xrefs to 0x%X ===" % a)
    for xref in idautils.XrefsTo(a):
        f = ida_funcs.get_func(xref.frm)
        fname = idc.get_func_name(xref.frm) if f else "?"
        print("  from 0x%X (%s) in %s" % (xref.frm, fname, hex(f.start_ea) if f else "?"))
