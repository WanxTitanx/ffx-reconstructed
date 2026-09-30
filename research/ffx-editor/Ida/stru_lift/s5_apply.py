#!/usr/bin/env python3
"""stru-lift s5: apply rename_plan.json to the IDB.

  - renames via rename{batch:{data:[{old,new}]}} in chunks
  - comments via append_comments{items:[{addr,comment}]} in chunks
  - RTTI missing-3 renames (off_C10248/unk_B99A7C/unk_B99A68 -> td_/chd_/col_)
  - idb_save at the end (only when run with APPLY=1)

Usage: s5_apply.py            -> dry-run summary only
       s5_apply.py apply      -> perform renames+comments+save
"""
import json, sys, os, time, collections
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', '..',
                                'research_tools', 'Ida', 'global_names'))
from mcpdrv import Mcp

HERE = os.path.dirname(os.path.abspath(__file__))
plan = json.load(open(os.path.join(HERE, 'rename_plan.json')))['plan']
APPLY = len(sys.argv) > 1 and sys.argv[1] == 'apply'

# RTTI missing-3: role+class names per mission convention. Verified from the
# TD's own mangled string .?AV?$PClassDescriptorConcrete@VPDynamicSegmentDesc@
# PDynamicMesh@PGeometry@Phyre@@@Phyre@@ -> Phyre::PClassDescriptorConcrete<
# Phyre::PGeometry::PDynamicMesh::PDynamicSegmentDesc>
CLS = 'Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PDynamicMesh::' \
      'PDynamicSegmentDesc>'
SUF = 'Phyre_PClassDescriptorConcrete_PDynamicSegmentDesc'
RTTI_EXTRA = [
    {'old': 'off_C10248', 'new': f'td_{SUF}', 'addr': '0xc10248',
     'role': 'TypeDescriptor'},
    {'old': 'unk_B99A7C', 'new': f'chd_{SUF}', 'addr': '0xb99a7c',
     'role': 'ClassHierarchyDescriptor'},
    {'old': 'unk_B99A68', 'new': f'col_{SUF}', 'addr': '0xb99a68',
     'role': 'CompleteObjectLocator'},
]
TAG = '[stru-lift 2026-09-16]'

if not APPLY:
    by = collections.Counter(x['role'] for x in plan)
    print('DRY RUN — plan:', len(plan), dict(by))
    sys.exit(0)

m = Mcp()
renames = [{'old': x['stru'], 'new': x['new']} for x in plan]
renames += [{'old': x['old'], 'new': x['new']} for x in RTTI_EXTRA]

results = {'ok': 0, 'fail': []}
B = 150
for i in range(0, len(renames), B):
    chunk = renames[i:i + B]
    for attempt in range(4):
        try:
            r = m.call('rename', {'batch': {'data': chunk}})
            break
        except Exception as e:
            sys.stderr.write(f'rename chunk {i} retry {attempt}: {e}\n')
            time.sleep(3 * (attempt + 1))
    else:
        results['fail'] += [{'chunk': i, 'err': 'call failed'}]
        continue
    items = r if isinstance(r, list) else (r.get('result', r)
                                         if isinstance(r, dict) else r)
    # capture per-op status if provided
    with open(os.path.join(HERE, f'rename_resp_{i}.json'), 'w') as f:
        json.dump(items, f, indent=0)
    sys.stderr.write(f'renamed {i + len(chunk)}/{len(renames)}\n')
    results['ok'] += len(chunk)

# comments
comments = [{'addr': x['addr'], 'comment': x['comment']} for x in plan]
comments += [{'addr': x['addr'],
              'comment': f"// RTTI {x['role']} for {CLS} — "
                         f"missed by IDA RTTI analysis; lifted by addr-role "
                         f"linkage from hierarchy.json {TAG}"}
             for x in RTTI_EXTRA]
for i in range(0, len(comments), B):
    chunk = comments[i:i + B]
    for attempt in range(4):
        try:
            r = m.call('append_comments', {'items': chunk, 'dedupe': True})
            break
        except Exception as e:
            sys.stderr.write(f'comment chunk {i} retry {attempt}: {e}\n')
            time.sleep(3 * (attempt + 1))
    else:
        results['fail'] += [{'comment_chunk': i, 'err': 'call failed'}]
        continue
    sys.stderr.write(f'commented {i + len(chunk)}/{len(comments)}\n')

json.dump(results, open(os.path.join(HERE, 'apply_results.json'), 'w'),
          indent=1)
print('done:', results['ok'], 'renames,', len(comments), 'comments;',
      len(results['fail']), 'failures')

# save
r = m.call('idb_save', {})
print('idb_save:', str(r)[:300])
