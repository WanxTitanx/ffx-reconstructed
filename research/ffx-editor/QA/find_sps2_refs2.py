import ida_segment, ida_bytes, idc, ida_funcs, ida_name

str_addrs = [0xB5E818, 0xB5E838, 0xB5E858, 0xB5E878, 0xB5E898, 0xB5E8B8, 0xB5E8D8, 0xB5E900, 0xB5E928, 0xB5E950]
for sa in str_addrs:
    target = bytes([sa & 0xFF, (sa >> 8) & 0xFF, (sa >> 16) & 0xFF, (sa >> 24) & 0xFF])
    hits = []
    for seg_idx in range(ida_segment.get_segm_qty()):
        seg = ida_segment.getnseg(seg_idx)
        if not seg or not (seg.perm & ida_segment.SEGPERM_READ):
            continue
        data = ida_bytes.get_bytes(seg.start_ea, seg.end_ea - seg.start_ea)
        if not data:
            continue
        idx = 0
        while True:
            idx = data.find(target, idx)
            if idx < 0:
                break
            hits.append(seg.start_ea + idx)
            idx += 1
    if hits:
        for h in hits[:6]:
            f = ida_funcs.get_func(h)
            fname = ida_name.get_name(f.start_ea) if f else "?"
            print(f"0x{sa:X} -> 0x{h:X} in func 0x{f.start_ea:X} {fname}" if f else f"0x{sa:X} -> 0x{h:X} (no func)")
