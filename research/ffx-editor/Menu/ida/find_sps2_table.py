import ida_segment, ida_bytes, idc, ida_funcs, ida_name

# The 10 .sps2 strings start at these addresses
str_addrs = [0xB5E818, 0xB5E838, 0xB5E858, 0xB5E878, 0xB5E898, 0xB5E8B8, 0xB5E8D8, 0xB5E900, 0xB5E928, 0xB5E950]
# Search for a run of 10 consecutive pointers to these
for seg_idx in range(ida_segment.get_segm_qty()):
    seg = ida_segment.getnseg(seg_idx)
    if not seg or not (seg.perm & ida_segment.SEGPERM_READ):
        continue
    data = ida_bytes.get_bytes(seg.start_ea, seg.end_ea - seg.start_ea)
    if not data:
        continue
    # search for first pointer
    first = bytes([str_addrs[0] & 0xFF, (str_addrs[0] >> 8) & 0xFF, (str_addrs[0] >> 16) & 0xFF, (str_addrs[0] >> 24) & 0xFF])
    idx = 0
    while True:
        idx = data.find(first, idx)
        if idx < 0:
            break
        addr = seg.start_ea + idx
        # check if next 9 are consecutive pointers to the other strings
        ok = True
        for i in range(1, 10):
            off = addr + i*4
            if off + 4 > seg.end_ea:
                ok = False
                break
            val = int.from_bytes(data[off-seg.start_ea:off-seg.start_ea+4], "little")
            if val != str_addrs[i]:
                ok = False
                break
        if ok:
            print(f"TABLE FOUND at 0x{addr:X}")
            f = ida_funcs.get_func(addr)
            fname = ida_name.get_name(f.start_ea) if f else "?"
            print(f"  in func 0x{f.start_ea:X} {fname}" if f else "  (no func)")
        idx += 1
