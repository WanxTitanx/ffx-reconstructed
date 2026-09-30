import ida_segment, ida_bytes, idc, ida_funcs, ida_name

# Find pointer to 0xB655D8 ("macrodic")
target = bytes([0xD8, 0x55, 0xB6, 0x00])
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
print(f"ptr refs to 0xB655D8 (macrodic): {len(hits)}")
for h in hits[:20]:
    f = ida_funcs.get_func(h)
    fname = ida_name.get_name(f.start_ea) if f else "?"
    print(f"  0x{h:X} in func 0x{f.start_ea:X} {fname}" if f else f"  0x{h:X} (no func)")
