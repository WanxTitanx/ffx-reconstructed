#!/usr/bin/env python3
import json
W = '/home/wanderson/Documents/ffx-editor-main/work/_data_r2/'
edges = json.load(open(W + 'abstract_edges.json'))
raw = json.load(open(W + 'abase_disposition_raw.json'))
h = json.load(open('/home/wanderson/Documents/ffx-editor-main/work/_chd_inherit/hierarchy.json'))
bcd_owner = {}
for vtbl, rec in h.items():
    for b in rec.get('base_detail', []):
        bcd_owner.setdefault(b['bcd'], []).append((rec.get('class'), b.get('direct')))

edge_bcds = set(e['bcd'] for e in edges)
bcd_derived = {}
for e in edges:
    bcd_derived.setdefault(e['bcd'], []).append(e['derived_class'])
td_derived = {}
for e in edges:
    td_derived.setdefault(e['td'], []).append(e['derived_class'])

def clip(items, n=4):
    s = ', '.join(items)
    return s if len(s) <= 150 else ', '.join(items[:n]) + f' (+{len(items)-n} more)'

ops = []
for td_s, rec in raw['bases'].items():
    base = rec['base']
    dlist = sorted(set(td_derived[td_s]))
    dstr = clip(dlist)
    ops.append({'addr': td_s, 'kind': 'td', 'base': base,
        'comment': f'[ABASE-R2 CONFIRMED] RTTI TypeDescriptor for {base}: abstract non-polymorphic base; NO CompleteObjectLocator/vtable emitted (all TD xrefs are BCDs). Direct base of: {dstr}.'})
    for chd in sorted(set(b['chd'] for b in rec['bcd_refs'])):
        ops.append({'addr': chd, 'kind': 'chd', 'base': base,
            'comment': f'[ABASE-R2 CONFIRMED] RTTI CHD of {base}: emitted for BCD resolution in derived hierarchies, but base has no COL/vtable (non-polymorphic). Direct base of: {dstr}.'})
    for b in rec['bcd_refs']:
        baddr = b['bcd']
        if baddr in edge_bcds:
            ds = clip(sorted(set(bcd_derived[baddr])))
            c = f'[ABASE-R2 CONFIRMED] BCD: {base} direct base of {ds} at mdisp={b["mdisp"]} (attrs {b["attrs"]}); base non-polymorphic - no emitted base vtable.'
        else:
            owners = bcd_owner.get(baddr, [])
            if owners:
                dirc = [o[0] for o in owners if o[1]]
                c = f'[ABASE-R2 VALID] BCD: {base} transitive base record (mdisp={b["mdisp"]}, attrs {b["attrs"]}) shared by {len(owners)} class CHDs; base non-polymorphic - no emitted base vtable.'
            else:
                c = f'[ABASE-R2 VALID] BCD: root/self record of {base} in own CHD {b["chd"]} (mdisp={b["mdisp"]}); base non-polymorphic - no emitted base vtable.'
        ops.append({'addr': baddr, 'kind': 'bcd', 'base': base, 'comment': c})

seen = set(); uops = []
for o in ops:
    k = (o['addr'], o['kind'])
    if k in seen: continue
    seen.add(k); uops.append(o)
json.dump(uops, open(W + 'abase_comment_ops.json','w'), indent=1)
print(len(uops), 'comment ops')
