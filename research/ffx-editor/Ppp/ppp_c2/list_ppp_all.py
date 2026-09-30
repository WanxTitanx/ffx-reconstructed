# -*- coding: utf-8 -*-
# A) All functions named ppp* in the whole EXE (with slots)
# B) All sub_* functions inside PPP ranges that are in HostContextTable
import ida_bytes, ida_name, ida_funcs, idautils, struct

HOST = 0xC64CE8
N = 512
data = ida_bytes.get_bytes(HOST, N * 8)
addr_slots = {}
for i in range(N):
    a, b = struct.unpack('<II', data[i * 8:i * 8 + 8])
    if a: addr_slots.setdefault(a, []).append(i)
    if b: addr_slots.setdefault(b, []).append(i)

PPP_LO, PPP_HI = 0x72C000, 0x760000

print('=== A) ppp* named functions with slots ===')
for ea in idautils.Functions():
    name = ida_name.get_name(ea) or ''
    if name.startswith('ppp'):
        print('0x%x %-58s slots=%s' % (ea, name, addr_slots.get(ea, [])))

print('=== B) sub_* in PPP range that are in table ===')
for ea in idautils.Functions():
    if not (PPP_LO <= ea < PPP_HI):
        continue
    name = ida_name.get_name(ea) or ''
    if name.startswith('sub_') and ea in addr_slots:
        print('0x%x %-58s slots=%s' % (ea, name, addr_slots[ea]))
