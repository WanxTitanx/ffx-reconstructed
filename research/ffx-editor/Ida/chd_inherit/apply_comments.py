#!/usr/bin/env python3
"""apply_comments.py — append 'inherits:' comments to vtables via append_comments
in batches of 100. Logs per-item results to comment_results.json."""
import sys, json, time
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post

W = '/home/wanderson/Documents/ffx-editor-main/work/_chd_inherit/'
ops = json.load(open(W + 'comment_ops.json')) + json.load(open(W + 'comment_roots.json'))

sess, _ = post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                           "clientInfo": {"name": "chd-inherit", "version": "1"}}})
post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sess)

results = []
B = 100
for i in range(0, len(ops), B):
    chunk = ops[i:i + B]
    for attempt in range(3):
        try:
            _, body = post({"jsonrpc": "2.0", "id": 2, "method": "tools/call",
                            "params": {"name": "append_comments",
                                       "arguments": {"items": chunk}}}, sess)
            d = json.loads(body)
            r = d.get('result', d)
            txt = r['content'][0]['text'] if isinstance(r, dict) and 'content' in r else json.dumps(r)
            try:
                arr = json.loads(txt)
            except Exception:
                arr = [{'raw': txt[:500]}]
            results += arr if isinstance(arr, list) else [arr]
            break
        except Exception as e:
            print('batch', i, 'retry', attempt, e, file=sys.stderr)
            time.sleep(2)
    if i % 500 == 0:
        print(f'{i}/{len(ops)}', flush=True)

json.dump(results, open(W + 'comment_results.json', 'w'), indent=1)
okc = sum(1 for r in results if r.get('ok') or r.get('appended') or (isinstance(r, dict) and not r.get('error')))
print('results:', len(results), 'sample:', results[:2])
errs = [r for r in results if isinstance(r, dict) and r.get('error')]
print('errors:', len(errs), errs[:5])
