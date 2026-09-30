#!/usr/bin/env python3
import sys, json, time
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post
W = '/home/wanderson/Documents/ffx-editor-main/work/_data_r2/'
ops = json.load(open(W + 'comment_ops.json'))
sess, _ = post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                           "clientInfo": {"name": "data-r2", "version": "1"}}})
post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sess)
results = []
for i in range(0, len(ops), 50):
    chunk = ops[i:i+50]
    for attempt in range(3):
        try:
            _, body = post({"jsonrpc": "2.0", "id": 2, "method": "tools/call",
                            "params": {"name": "append_comments", "arguments": {"items": chunk}}}, sess)
            d = json.loads(body)
            r = d.get('result', d)
            txt = r['content'][0]['text'] if isinstance(r, dict) and 'content' in r else json.dumps(r)
            try:
                arr = json.loads(txt)
            except Exception:
                arr = [{'raw': txt[:300]}]
            results += arr if isinstance(arr, list) else [arr]
            break
        except Exception as e:
            print('batch', i, 'retry', attempt, e, file=sys.stderr)
            time.sleep(2)
json.dump(results, open(W + 'comment_results.json', 'w'), indent=1)
app = sum(1 for r in results if isinstance(r, dict) and r.get('appended'))
skp = sum(1 for r in results if isinstance(r, dict) and r.get('skipped'))
err = [r for r in results if isinstance(r, dict) and r.get('error')]
print('results:', len(results), 'appended:', app, 'skipped:', skp, 'errors:', len(err), err[:5])
