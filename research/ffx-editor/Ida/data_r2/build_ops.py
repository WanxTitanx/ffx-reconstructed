#!/usr/bin/env python3
"""build_ops.py — build comment ops for the 26 abstract-base edges.
Disposition for ALL: NO_EMITTED_VTABLE (RTTI-only / non-polymorphic data base):
 - base own CHD has only BCD referrers, zero COL sites
 - derived vtable blob contains only the primary vftable section
 - derived ctor writes only the primary vptr (verified: PType 0xaf9f90,
   PClassDescriptor 0x43b0a0, PInputDevicePad 0x620360)
"""
import json
W = '/home/wanderson/Documents/ffx-editor-main/work/_data_r2/'
ev = json.load(open(W + 'edge_evidence.json'))

ops = []
by_base = {}
for e in ev:
    by_base.setdefault(e['td'], []).append(e)

# per-edge: comment on derived vtbl + on the BCD inside derived CHD
for e in ev:
    md = e['mdisp']
    ops.append({'addr': e['derived_vtbl'], 'scope': 'line',
        'comment': f"[ABASE] {e['base']} @+{md:#x}: RTTI-only base — no vftable emitted "
                   f"(non-polymorphic data subobj; ctor writes only primary vptr). "
                   f"TD={e['td']} ownCHD={e['base_chd']} BCD={e['bcd']} [data-r2]"})
    ops.append({'addr': e['bcd'], 'scope': 'line',
        'comment': f"[ABASE] BCD {e['derived_class']}<-{e['base']} mdisp={md:#x}: "
                   f"data-only subobject (no vptr at this offset); base TD={e['td']} "
                   f"ownCHD={e['base_chd']} — no vftable for base [data-r2]"})

# per-base: comment on TD + own CHD (aggregated)
for td, es in by_base.items():
    e0 = es[0]
    deriveds = sorted({x['derived_class'] for x in es})
    n_bcd = len(e0['bcd_sites'])
    chain = [c.get('td_name','?') for c in e0['base_chain']]
    ops.append({'addr': td, 'scope': 'line',
        'comment': f"[ABASE] {e0['base']}: RTTI-only base — NO vftable emitted in binary "
                   f"(own CHD {e0['base_chd']} has 0 COL referrers; {n_bcd} derived-BCD refs). "
                   f"Data-only subobj of: {'; '.join(deriveds)} [data-r2]"})
    ops.append({'addr': e0['base_chd'], 'scope': 'line',
        'comment': f"[ABASE] own CHD of {e0['base']} ({e0['chd_raw'][2]} BCDs); xrefs only from "
                   f"derived BCD.pCHD — class is abstract/RTTI-only, no COL/vftable exists. "
                   f"chain tds: {' '.join(chain)[:180]} [data-r2]"})

json.dump(ops, open(W + 'comment_ops.json', 'w'), indent=1)
print('ops:', len(ops))
