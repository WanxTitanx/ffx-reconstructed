# -*- coding: utf-8 -*-
import ida_bytes, ida_name, ida_funcs, idautils, struct

HOST = 0xC64CE8
N = 512
data = ida_bytes.get_bytes(HOST, N * 8)
addr_slots = {}
for i in range(N):
    a, b = struct.unpack('<II', data[i * 8:i * 8 + 8])
    if a: addr_slots.setdefault(a, []).append(i)
    if b: addr_slots.setdefault(b, []).append(i)

RANGES = [(0x746000, 0x752000), (0x752000, 0x757000)]

for lo, hi in RANGES:
    print('=== RANGE %x-%x ===' % (lo, hi))
    out = []
    for ea in idautils.Functions():
        if lo <= ea < hi:
            out.append((ea, ida_name.get_name(ea) or ''))
    out.sort()
    for ea, name in out:
        tag = 'T' if ea in addr_slots else ' '
        print('%s 0x%x %s' % (tag, ea, name))
    print('TOTAL', len(out))
