import ida_bytes, idc, json
base = 0xC85EF0
out = []
for i in range(70):
    p = ida_bytes.get_dword(base + i*4)
    if p:
        raw = ida_bytes.get_bytes(p, 80)
        s = raw.split(b"\x00")[0].decode("ascii", "replace") if raw else None
    else:
        s = None
    out.append("%d:%s" % (i, s))
print("\n".join(out))
