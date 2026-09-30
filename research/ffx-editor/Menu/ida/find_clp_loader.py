import ida_segment, ida_bytes, idc

pat = bytes([0x2E, 0x63, 0x6C, 0x70])  # ".clp"
hits = []
for seg_idx in range(ida_segment.get_segm_qty()):
    seg = ida_segment.getnseg(seg_idx)
    if not seg or not (seg.perm & ida_segment.SEGPERM_READ):
        continue
    ea = seg.start_ea
    end = seg.end_ea
    # manual scan
    data = ida_bytes.get_bytes(ea, end - ea)
    if not data:
        continue
    idx = 0
    while True:
        idx = data.find(pat, idx)
        if idx < 0:
            break
        hits.append(ea + idx)
        idx += 1

print(f".clp hits: {len(hits)}")
for h in hits[:30]:
    s = idc.get_strlit_contents(h, -1, idc.STRTYPE_C)
    print(f"  0x{h:X}: {s}")
