# -*- coding: utf-8 -*-
# List functions in specific PPP ranges with HostContextTable slots.
import ida_bytes, ida_name, ida_funcs, idautils, struct

HOST = 0xC64CE8
N = 512
data = ida_bytes.get_bytes(HOST, N * 8)
addr_slots = {}
for i in range(N):
    a, b = struct.unpack('<II', data[i * 8:i * 8 + 8])
    if a: addr_slots.setdefault(a, []).append(i)
    if b: addr_slots.setdefault(b, []).append(i)

import sys
lo = int(sys.argv[1], 16)
hi = int(sys.argv[2], 16)

out = []
for ea in idautils.Functions():
    if lo <= ea < hi:
        name = ida_name.get_name(ea) or ''
        slots = addr_slots.get(ea, [])
        out.append((ea, name, slots))

out.sort()
for ea, name, slots in out:
    print('0x%x %-58s slots=%s' % (ea, name or '<NO NAME>', slots))
print('TOTAL', len(out))
