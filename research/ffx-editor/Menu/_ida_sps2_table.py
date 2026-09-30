import ida_bytes, idc, idautils

# dump the string table around 0xC58E44
print("=== strings around 0xC58E00 ===")
for off in range(0, 0x100, 4):
    ea = 0xC58E00 + off
    b = ida_bytes.get_dword(ea)
    if 0x400000 < b < 0x500000:
        s = idc.get_strlit_contents(b, -1, 0)
        print("  0x%X: 0x%08X -> %s" % (ea, b, s.decode('ascii','ignore') if s else "?"))
    else:
        print("  0x%X: 0x%08X" % (ea, b))

# find xrefs to 0xC58E00 (table start)
print("\n=== xrefs to 0xC58E00 ===")
for xref in idautils.XrefsTo(0xC58E00):
    print("  from 0x%X" % xref.frm)
