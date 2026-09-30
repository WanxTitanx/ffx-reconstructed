# -*- coding: utf-8 -*-
"""Roda DENTRO do IDA (via ida_mcp_client.py exec_file).

Mapeia TODOS os 512 slots da HostContextTable (0xC64CE8, 8 bytes/slot = 2 u32).
Resolve nome de cada ponteiro: ida_name.get_name -> ida_funcs.get_func -> hex.
Salva work/ppp_c2/host_context_all_named.json (512 entries, inclusive vazios).
Imprime resumo: slots PPP (catálogo) vs não-PPP, e contagem por categoria.
"""
import json
import struct
from collections import Counter

import ida_bytes
import ida_funcs
import ida_name

BASE = 0xC64CE8
N = 512
STRIDE = 8
OUT = r'C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/host_context_all_named.json'
CATALOG = r'C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/host_context_ppp_catalog.json'

b = ida_bytes.get_bytes(BASE, N * STRIDE)
if b is None or len(b) < N * STRIDE:
    raise RuntimeError('get_bytes falhou: len=%r' % (None if b is None else len(b)))


def resolve(addr):
    if not addr:
        return ''
    name = ida_name.get_name(addr) or ''
    if name:
        return name
    f = ida_funcs.get_func(addr)
    if f:
        return ida_name.get_name(f.start_ea) or ('sub_%X' % f.start_ea)
    return hex(addr)


rows = []
for i in range(N):
    off = i * STRIDE
    a = struct.unpack('<I', b[off:off + 4])[0]
    bb = struct.unpack('<I', b[off + 4:off + 8])[0]
    rows.append({'slot': i, 'a': hex(a), 'a_name': resolve(a), 'b': hex(bb), 'b_name': resolve(bb)})

with open(OUT, 'w', encoding='utf-8') as f:
    json.dump(rows, f, ensure_ascii=False, indent=1)

try:
    with open(CATALOG, encoding='utf-8') as f:
        ppp_slots = {x['slot'] for x in json.load(f)}
except Exception:
    ppp_slots = set()

CATS = ['FFX_Chr', 'FFX_Mgrp', 'FFX_Mseq', 'PppMem', 'FFX_Magic', 'FFX_KR',
        'Phyre', 'FFX_FieldMap', 'FFX_Battle']
ANON = ('0x', 'sub_', 'dword_', 'loc_', 'unk_', 'nullsub', 'byte_', 'word_', '?', 'off_')


def primary(r):
    for key in ('a_name', 'b_name'):
        n = r.get(key) or ''
        if n and not n.startswith(ANON):
            return n
    return ''


def cat_of(r):
    n = primary(r)
    if not n:
        return 'outro(vazio/anon)'
    for c in CATS:
        if n.startswith(c):
            return c
    return 'outro'


nonppp = [r for r in rows if r['slot'] not in ppp_slots]
cnt = Counter(cat_of(r) for r in nonppp)
print('OK slots=%d ppp=%d naoppp=%d' % (len(rows), len(ppp_slots), len(nonppp)))
for k, v in cnt.most_common():
    print('%-22s %d' % (k, v))
