import ida_segment, ida_bytes, idc, ida_funcs, ida_name

# Search for the pointer value to 0xB5E831 (as little-endian u32) in all segments
target = bytes([0x31, 0xE8, 0xB5, 0x00])  # 0xB5E831 LE
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
print(f"ptr refs to 0xB5E831: {len(hits)}")
for h in hits[:20]:
    f = ida_funcs.get_func(h)
    fname = ida_name.get_name(f.start_ea) if f else "?"
    print(f"  0x{h:X} in func 0x{f.start_ea:X} {fname}" if f else f"  0x{h:X} (no func)")
