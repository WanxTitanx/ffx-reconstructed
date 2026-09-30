import ida_segment, ida_bytes, idc

# Search for "clp" anywhere (case-insensitive)
pat = bytes("clp", "ascii")
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
        idx = data.find(pat, idx)
        if idx < 0:
            break
        hits.append(seg.start_ea + idx)
        idx += 1
print(f"'clp' hits: {len(hits)}")
for h in hits[:40]:
    s = idc.get_strlit_contents(h, -1, idc.STRTYPE_C)
    print(f"  0x{h:X}: {s}")
