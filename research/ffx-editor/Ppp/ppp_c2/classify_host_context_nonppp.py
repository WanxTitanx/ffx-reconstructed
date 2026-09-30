# -*- coding: utf-8 -*-
"""Pós-processamento local (fora do IDA): classifica os 439 slots não-PPP da
HostContextTable e imprime totais + até 30 exemplos por categoria.
"""
import json
import collections

BASE = r'C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/host_context_all_named.json'
CATALOG = r'C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/host_context_ppp_catalog.json'

rows = json.load(open(BASE, encoding='utf-8'))
ppp_slots = {x['slot'] for x in json.load(open(CATALOG, encoding='utf-8'))}

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


def subcat(n):
    """Subcategoria dentro de 'outro'."""
    if n.startswith('FFX_'):
        return 'FFX_' + n.split('_')[1]
    return n.split('_')[0]


nonppp = [r for r in rows if r['slot'] not in ppp_slots]
by_cat = collections.defaultdict(list)
for r in nonppp:
    by_cat[cat_of(r)].append(r)

print('=== TOTAIS POR CATEGORIA (439 naoppp) ===')
for k in sorted(by_cat, key=lambda k: -len(by_cat[k])):
    print('%-22s %3d' % (k, len(by_cat[k])))

# Detalhe do 'outro' e do 'outro(vazio/anon)'
extra = by_cat['outro']
subs = collections.Counter(subcat(primary(r)) for r in extra)
print()
print('=== SUBCATEGORIAS DE "outro" (%d) ===' % len(extra))
for k, v in subs.most_common():
    print('  %-24s %3d' % (k, v))

anon = by_cat['outro(vazio/anon)']
print()
print('=== "outro(vazio/anon)" (%d) — padrões de nome ===' % len(anon))
pats = collections.Counter()
for r in anon:
    for key in ('a_name', 'b_name'):
        n = r[key]
        if n:
            if n.startswith('0x'):
                pats['hex_bruto'] += 1
            else:
                pats[n.split('_')[0] + '_'] += 1
    if not r['a_name'] and not r['b_name']:
        pats['(vazio)'] += 1
for k, v in pats.most_common():
    print('  %-18s %3d' % (k, v))

print()
print('=== 30 EXEMPLOS POR CATEGORIA ===')
lines = []
for k in sorted(by_cat, key=lambda k: -len(by_cat[k])):
    lines.append('')
    lines.append('--- %s (%d slots) ---' % (k, len(by_cat[k])))
    for r in by_cat[k][:30]:
        lines.append('  slot %3d  a=%s  b=%s' % (r['slot'], r['a_name'] or r['a'], r['b_name'] or r['b']))
        print('  slot %3d  a=%s  b=%s' % (r['slot'], r['a_name'] or r['a'], r['b_name'] or r['b']))
with open(r'C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/classify_report_utf8.txt', 'w', encoding='utf-8') as f:
    f.write('\n'.join(lines))
