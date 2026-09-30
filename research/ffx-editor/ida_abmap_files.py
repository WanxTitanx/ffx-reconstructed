import idc, ida_bytes, ida_name
# Read the 70 pointers at C85EF0 and print the strings
base = 0xC85EF0
for i in range(70):
    ptr = ida_bytes.get_dword(base + i*4)
    s = idc.get_strlit_contents(ptr, -1, idc.STRTYPE_C)
    if s is None:
        s = ida_bytes.get_bytes(ptr, 64)
    print(i, hex(ptr), s)
