#!/usr/bin/env python3
"""stru-lift s5b: re-apply comments (s5 passed dedupe at top level -> rejected).
dedupe belongs inside each item; default is true anyway. Captures every
response and counts appended/failed per item."""
import json, sys, os, time, collections
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', '..',
                                'research_tools', 'Ida', 'global_names'))
from mcpdrv import Mcp

HERE = os.path.dirname(os.path.abspath(__file__))
plan = json.load(open(os.path.join(HERE, 'rename_plan.json')))['plan']

CLS = 'Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PDynamicMesh::' \
      'PDynamicSegmentDesc>'
TAG = '[stru-lift 2026-09-16]'
RTTI_EXTRA = [
    {'addr': '0xc10248', 'role': 'TypeDescriptor'},
    {'addr': '0xb99a7c', 'role': 'ClassHierarchyDescriptor'},
    {'addr': '0xb99a68', 'role': 'CompleteObjectLocator'},
]

items = [{'addr': x['addr'], 'comment': x['comment'], 'dedupe': True}
         for x in plan]
items += [{'addr': x['addr'],
           'comment': f"// RTTI {x['role']} for {CLS} — missed by IDA RTTI "
                      f"analysis; lifted via hierarchy.json linkage {TAG}",
           'dedupe': True} for x in RTTI_EXTRA]

m = Mcp()
ok = appended = skipped = 0
fails = []
B = 150
for i in range(0, len(items), B):
    chunk = items[i:i + B]
    for attempt in range(4):
        try:
            r = m.call('append_comments', {'items': chunk})
            break
        except Exception as e:
            sys.stderr.write(f'chunk {i} retry {attempt}: {e}\n')
            time.sleep(3 * (attempt + 1))
    else:
        fails.append({'chunk': i, 'err': 'call failed'})
        continue
    lst = r if isinstance(r, list) else (r.get('result', r)
                                       if isinstance(r, dict) else r)
    if isinstance(lst, str):
        fails.append({'chunk': i, 'err': lst[:200]})
        continue
    for it in (lst if isinstance(lst, list) else []):
        ok += 1
        if it.get('appended'):
            appended += 1
        elif it.get('skipped') or it.get('deduped'):
            skipped += 1
        elif it.get('error'):
            fails.append(it)
    if i % 1500 == 0:
        sys.stderr.write(f'{i}/{len(items)} appended={appended}\n')

json.dump({'items': len(items), 'responses': ok, 'appended': appended,
           'skipped': skipped, 'fails': fails},
          open(os.path.join(HERE, 'comment_results.json'), 'w'), indent=1)
print(json.dumps({'items': len(items), 'responses': ok, 'appended': appended,
                  'skipped': skipped, 'fails': len(fails)}))
for f in fails[:10]:
    print('FAIL', f)
