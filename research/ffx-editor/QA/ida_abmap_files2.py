import idc, ida_bytes
base = 0xC85EF0
for i in range(70):
    ptr = ida_bytes.get_dword(base + i*4)
    s = idc.get_strlit_contents(ptr, -1, idc.STRTYPE_C)
    print(i, s.decode() if s else hex(ptr))
