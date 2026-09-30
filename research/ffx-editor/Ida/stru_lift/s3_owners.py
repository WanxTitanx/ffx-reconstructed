#!/usr/bin/env python3
"""stru-lift s3: resolve owning function for every FuncInfo / EH4ScopeTable /
OTHER stru item via batch xrefs_to (xref gives fn{addr,name,size} inline).

Output: owners.json {stru_name: {addr, owner_addr, owner_name, xref_addr}}
"""
import json, sys, os, time
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', '..',
                                'research_tools', 'Ida', 'global_names'))
from mcpdrv import Mcp

HERE = os.path.dirname(os.path.abspath(__file__))
p = json.load(open(os.path.join(HERE, 'stru_parsed.json')))
targets = {n: r for n, r in p.items()
           if r['role'] in ('FuncInfo', 'EH4ScopeTable', 'OTHER')}
addrs = [r['addr'] for r in sorted(targets.values(), key=lambda r: int(r['addr'], 16))]
print('targets:', len(addrs))

m = Mcp()
owners = {}
B = 150
for i in range(0, len(addrs), B):
    chunk = addrs[i:i + B]
    for attempt in range(4):
        try:
            r = m.call('xrefs_to', {'addrs': chunk, 'limit': 10})
            break
        except Exception as e:
            sys.stderr.write(f'chunk {i} retry {attempt}: {e}\n')
            time.sleep(3 * (attempt + 1))
    else:
        raise SystemExit(f'chunk {i} failed')
    items = r if isinstance(r, list) else r.get('result', r)
    for it in items:
        addr = it.get('addr')
        name = 'stru_' + addr.upper()[2:]
        xrs = it.get('xrefs', [])
        code = [x for x in xrs if x.get('fn')]
        rec = {'addr': addr, 'xref_count': it.get('xref_count', len(xrs)),
               'xrefs': [{'addr': x['addr'], 'type': x.get('type'),
                          'fn': x.get('fn', {}).get('addr'),
                          'fn_name': x.get('fn', {}).get('name')}
                         for x in xrs]}
        if code:
            rec['owner_addr'] = code[0]['fn']['addr']
            rec['owner_name'] = code[0]['fn']['name']
        owners[name] = rec
    sys.stderr.write(f'{i + len(chunk)}/{len(addrs)} owners={len(owners)}\n')

with open(os.path.join(HERE, 'owners.json'), 'w') as f:
    json.dump(owners, f, indent=0)
have = sum(1 for v in owners.values() if 'owner_addr' in v)
print('resolved owners:', have, '/', len(owners))
