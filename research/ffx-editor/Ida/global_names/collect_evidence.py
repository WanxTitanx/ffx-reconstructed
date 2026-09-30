#!/usr/bin/env python3
"""Phase C: for each candidate global, collect xrefs_to + raw bytes + the
decompile of its top 2 informative accessors (cached, shared across targets)."""
import json, sys, collections
from mcpdrv import Mcp

cands = json.load(open('targets.json'))
m = Mcp()

# --- batch xrefs_to ---
xrefs = {}
B = 25
for i in range(0, len(cands), B):
    batch = [c['addr'] for c in cands[i:i+B]]
    r = m.call('xrefs_to', {'addrs': batch, 'limit': 15})
    for e in (r if isinstance(r, list) else []):
        xrefs[e['addr'].lower()] = e
    sys.stderr.write(f'xrefs {i+len(batch)}/{len(cands)}\n')

# --- batch get_bytes (init values) ---
vals = {}
for i in range(0, len(cands), B):
    regs = [{'addr': c['addr'], 'size': 16} for c in cands[i:i+B]]
    r = m.call('get_bytes', {'regions': regs})
    for e in (r if isinstance(r, list) else []):
        vals[e['addr'].lower()] = e.get('data', '')
    sys.stderr.write(f'bytes {i+len(regs)}/{len(cands)}\n')

# --- pick accessor functions to decompile ---
want = []          # (cand_idx, func_addr)
fn_for = collections.defaultdict(set)
for i, c in enumerate(cands):
    xe = xrefs.get(c['addr'].lower(), {})
    fns = [(x.get('fn') or {}) for x in xe.get('xrefs', [])]
    # prefer named, non-DEAD, non-'?' functions; keep insertion order
    good = [f for f in fns if f.get('name') and not f['name'].startswith('DEAD')]
    pick = (good or fns)[:2]
    for f in pick:
        if f.get('addr'):
            fn_for[f['addr']].add(i)

# decompile each chosen function once
decomp = {}
todo = sorted(fn_for, key=lambda a: -len(fn_for[a]))
for k, fa in enumerate(todo):
    r = m.call('decompile', {'addr': fa})
    if isinstance(r, dict):
        decomp[fa] = r.get('code', '')
    else:
        decomp[fa] = str(r)[:4000]
    if k % 10 == 0:
        sys.stderr.write(f'decomp {k}/{len(todo)}\n')

out = []
for i, c in enumerate(cands):
    xe = xrefs.get(c['addr'].lower(), {})
    fns = [{'fn': (x.get('fn') or {}).get('name'), 'faddr': (x.get('fn') or {}).get('addr'),
            'site': x.get('addr'), 'type': x.get('type')} for x in xe.get('xrefs', [])]
    acc = []
    for f in fns:
        if f['faddr'] and f['faddr'].lower() in decomp:
            acc.append({'fn': f['fn'], 'faddr': f['faddr'], 'code': decomp[f['faddr'].lower()]})
    out.append({'name': c['name'], 'addr': c['addr'], 'code_refs': c['code_refs'],
                'nfuncs': len(c['funcs']), 'bytes': vals.get(c['addr'].lower(), ''),
                'xrefs': fns, 'accessor_decomp': acc[:2]})

json.dump({'targets': out, 'decomp_cache_size': len(decomp)},
          open('evidence.json', 'w'), indent=0)
print(f'done: {len(out)} targets, {len(decomp)} decompiled accessors', file=sys.stderr)
