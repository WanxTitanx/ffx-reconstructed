#!/usr/bin/env python3
"""Mass xref sweep: distinctive strings -> referencing functions."""
import json, sys, time
sys.path.insert(0, '.')
from mcp import Mcp

d = json.load(open('distinctive_strings.json'))
by_ea = {x['ea']: x['s'] for x in d}
addrs = [x['ea'] for x in d]
m = Mcp()
out = {}
B = 25
for i in range(0, len(addrs), B):
    batch = addrs[i:i+B]
    for attempt in range(3):
        try:
            r = m.call('xrefs_to', {'addrs': batch, 'limit': 60})
            o = json.loads(r)
            break
        except Exception as e:
            print(f'retry {attempt} @{i}: {e}', flush=True)
            time.sleep(2)
            m = Mcp()
    else:
        o = [{'addr': a, 'error': 'failed'} for a in batch]
    for rec in o:
        a = rec.get('addr')
        if a in by_ea:
            rec['s'] = by_ea[a]
        out[a] = rec
    if (i // B) % 10 == 0:
        print(f'{i}/{len(addrs)}', flush=True)
        json.dump(out, open('str_xrefs_all.json', 'w'), ensure_ascii=False)
json.dump(out, open('str_xrefs_all.json', 'w'), ensure_ascii=False)
print('DONE', len(out))
