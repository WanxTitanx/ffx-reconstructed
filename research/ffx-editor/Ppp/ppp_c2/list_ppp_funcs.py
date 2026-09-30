# -*- coding: utf-8 -*-
# List all functions in PPP module ranges, flag which appear in HostContextTable.
import ida_bytes, ida_name, ida_funcs, idautils, struct, json

HOST = 0xC64CE8
N = 512
data = ida_bytes.get_bytes(HOST, N * 8)
addr_slots = {}
for i in range(N):
    a, b = struct.unpack('<II', data[i * 8:i * 8 + 8])
    if a: addr_slots.setdefault(a, []).append(i)
    if b: addr_slots.setdefault(b, []).append(i)

RANGES = [(0x72D000, 0x760000), (0x749000, 0x74B000)]

def in_ranges(ea):
    for lo, hi in RANGES:
        if lo <= ea < hi:
            return True
    return False

out = []
for ea in idautils.Functions():
    if not in_ranges(ea):
        continue
    name = ida_name.get_name(ea) or ''
    slots = addr_slots.get(ea, [])
    if name.startswith('sub_') or slots:
        out.append((ea, name, slots))

out.sort()
for ea, name, slots in out:
    print('0x%x %-55s slots=%s' % (ea, name or '<NO NAME>', slots))
print('TOTAL', len(out))
