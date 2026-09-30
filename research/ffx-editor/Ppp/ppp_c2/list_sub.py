# -*- coding: utf-8 -*-
# List ALL sub_* (unnamed) functions in PPP ranges, with size; flag table presence.
import ida_bytes, ida_name, ida_funcs, idautils, struct

HOST = 0xC64CE8
N = 512
data = ida_bytes.get_bytes(HOST, N * 8)
addr_slots = {}
for i in range(N):
    a, b = struct.unpack('<II', data[i * 8:i * 8 + 8])
    if a: addr_slots.setdefault(a, []).append(i)
    if b: addr_slots.setdefault(b, []).append(i)

RANGES = [(0x72C000, 0x760000), (0x716000, 0x71B000)]
out = []
for lo, hi in RANGES:
    for ea in idautils.Functions():
        if lo <= ea < hi:
            name = ida_name.get_name(ea) or ''
            if name.startswith('sub_'):
                f = ida_funcs.get_func(ea)
                size = (f.end_ea - f.start_ea) if f else 0
                out.append((ea, size, addr_slots.get(ea, [])))
out.sort()
for ea, size, slots in out:
    print('0x%x size=0x%x slots=%s' % (ea, size, slots))
print('TOTAL sub_*:', len(out))
