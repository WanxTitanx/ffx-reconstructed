import ida_segment, ida_bytes, idc, ida_name, ida_xref

pats = {
    ".dcp": bytes([0x2E, 0x64, 0x63, 0x70]),
    ".fmt": bytes([0x2E, 0x66, 0x6D, 0x74]),
    ".sps2": bytes([0x2E, 0x73, 0x70, 0x73, 0x32]),
    ".clp": bytes([0x2E, 0x63, 0x6C, 0x70]),
}
for name, pat in pats.items():
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
    print(f"{name}: {len(hits)} hits")
    for h in hits[:15]:
        s = idc.get_strlit_contents(h, -1, idc.STRTYPE_C)
        print(f"  0x{h:X}: {s}")
