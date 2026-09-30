#!/usr/bin/env python3
"""build_hierarchy.py — full CHD parse for every has_col vtable; emit
hierarchy.json {vaddr: {name, bases, direct_bases, direct_base_names, ...}}."""
import json, sys
from collections import Counter
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/work/_chd_inherit')
from parse_chd import *

vt = json.load(open(VR + 'vtables2.json'))
dem = json.load(open(VR + 'demangled.json'))

# pass 1: collect per-vtable info + td->vtables map
td2vt = {}
info = {}
for e in vt:
    va = e['vtable']
    rec = {'name_now': e.get('name_now'), 'has_col': e.get('has_col'),
           'class': e.get('class'), 'slots': e['slots']}
    info[va] = rec
    if e.get('has_col'):
        col = int(e['col'], 16)
        td = dword_at(col + 0xC)
        rec['col'] = e['col']
        rec['td'] = hex(td) if td else None
        rec['col_offset'] = dword_at(col + 4)  # 0 = primary vftable
        rec['chd'] = hex(dword_at(col + 0x10))
        td2vt.setdefault(td, []).append(va)

hier = {}
for e in vt:
    if not e.get('has_col'):
        continue
    va = e['vtable']
    chd = dword_at(int(e['col'], 16) + 0x10)
    p = parse_chd(chd)
    assert p, va
    di, ok = direct_bases(p['entries'])
    assert ok, va
    bases = [p['entries'][i]['cls'] for i in range(1, p['nb'])]
    dnames = [p['entries'][i]['cls'] for i in di]
    # resolve each direct base TD -> primary vftable (col_offset==0 pref)
    daddrs = []
    for i in di:
        td = p['entries'][i]['td']
        cands = td2vt.get(td, [])
        prim = [v for v in cands if info[v].get('col_offset') == 0]
        pick = (prim or cands or [None])[0]
        daddrs.append(pick)
    hier[va] = {
        'name': e.get('name_now') or e.get('class'),
        'class': e.get('class'),
        'nbases_raw': p['nb'],                # raw CHD numBaseClasses (incl self)
        'col': e['col'], 'chd': hex(chd),
        'col_offset': info[va].get('col_offset'),
        'bases': bases,                        # all base class names (DFS order)
        'direct_bases': daddrs,                # primary vtbl addr per direct base
        'direct_base_names': dnames,
        'base_detail': [{'cls': p['entries'][i]['cls'],
                         'bcd': hex(p['entries'][i]['bcd']),
                         'td': hex(p['entries'][i]['td']),
                         'mdisp': p['entries'][i]['mdisp'],
                         'direct': i in di} for i in range(1, p['nb'])],
    }

json.dump(hier, open('/home/wanderson/Documents/ffx-editor-main/work/_chd_inherit/hierarchy.json', 'w'), indent=1)

# stats
n0 = sum(1 for v in hier.values() if not v['bases'])
n1 = sum(1 for v in hier.values() if len(v['direct_bases']) == 1)
nmi = sum(1 for v in hier.values() if len(v['direct_bases']) > 1)
print('total has_col:', len(hier), '| roots(nb=1):', n0, '| single:', n1, '| multi:', nmi)
roots = [v['class'] for v in hier.values() if not v['bases']]
print('root classes:', sorted(set(roots)))
# which classes are used as bases
used = Counter()
for v in hier.values():
    for b in v['direct_base_names']:
        used[b] += 1
print('top base classes:', used.most_common(15))
# sanity: direct_bases resolution rate
res = sum(1 for v in hier.values() for a in v['direct_bases'] if a)
tot = sum(len(v['direct_bases']) for v in hier.values())
print('direct_bases resolved to a vtbl addr:', res, '/', tot)
