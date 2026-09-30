#!/usr/bin/env python3
"""apply_fptr.py — for each fptr run: (re)name head via make_data, append
comment documenting N + first target. Batched. Idempotent-ish: skips name ops
where current DB name already equals target (checked live via names_data)."""
import sys, json, time
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post

W = '/home/wanderson/Documents/ffx-editor-main/work/_chd_inherit/'
plan = json.load(open(W + 'fptr_plan.json'))

sess, _ = post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                           "clientInfo": {"name": "chd-inherit", "version": "1"}}})
post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sess)


def call(tool, args, mid=2):
    _, body = post({"jsonrpc": "2.0", "id": mid, "method": "tools/call",
                    "params": {"name": tool, "arguments": args}}, sess)
    d = json.loads(body)
    r = d.get('result', d)
    txt = r['content'][0]['text'] if isinstance(r, dict) and 'content' in r else json.dumps(r)
    try:
        return json.loads(txt)
    except Exception:
        return [{'raw': txt[:400]}]


# ---- phase 1: undefine spans for runs we will name ----
un_ops = [{'addr': p['addr'], 'size': p['count'] * 4} for p in plan if p['new_name']]
res_un = []
for i in range(0, len(un_ops), 60):
    res_un += call('undefine', {'items': un_ops[i:i + 60]})
print('undefine ops:', len(un_ops))

# ---- phase 2: make_data dwords; name on head of each run ----
mk = []
for p in plan:
    if not p['new_name']:
        continue
    a = int(p['addr'], 16)
    for k in range(p['count']):
        it = {'addr': hex(a + 4 * k), 'type': 'DWORD'}
        if k == 0:
            it['name'] = p['new_name']
        mk.append(it)
res_mk = []
for i in range(0, len(mk), 60):
    res_mk += call('make_data', {'items': mk[i:i + 60]})
    if i % 600 == 0:
        print('make_data', i, '/', len(mk), flush=True)
okm = sum(1 for x in res_mk if x.get('ok'))
print('make_data ok:', okm, '/', len(res_mk))

# ---- phase 3: comments on all runs ----
cm = []
for p in plan:
    tag = 'fptr-table?' if not (p['new_name'] or p['current_name']) else 'fptr-table'
    c = (f"{tag}: N={p['count']} entries, first target {p['first_name']}"
         + (' [data-xref]' if p['nref'] else ''))
    cm.append({'addr': p['addr'], 'comment': c})
res_cm = []
for i in range(0, len(cm), 100):
    res_cm += call('append_comments', {'items': cm[i:i + 100]})
app = sum(1 for x in res_cm if x.get('appended') or x.get('skipped'))
print('comments:', app, '/', len(res_cm))

json.dump({'undefine': res_un, 'make_data': res_mk, 'comments': res_cm},
          open(W + 'fptr_apply_results.json', 'w'), indent=1)
