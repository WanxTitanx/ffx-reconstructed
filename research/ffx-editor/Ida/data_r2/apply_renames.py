#!/usr/bin/env python3
import sys, json, time
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post
W = '/home/wanderson/Documents/ffx-editor-main/work/_data_r2/'
renames = json.load(open(W + 'rename_ops.json'))
sess, _ = post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"data-r2","version":"1"}}})
post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
results = []
for i in range(0, len(renames), 50):
    chunk = renames[i:i+50]
    for attempt in range(3):
        try:
            _, body = post({"jsonrpc":"2.0","id":2,"method":"tools/call",
                            "params":{"name":"rename","arguments":{"batch":{"data":chunk}}}}, sess)
            d = json.loads(body); r = d.get('result', d)
            txt = r['content'][0]['text'] if isinstance(r, dict) and 'content' in r else json.dumps(r)
            try: arr = json.loads(txt)
            except Exception: arr = [{'raw': txt[:400]}]
            results += arr if isinstance(arr, list) else [arr]
            break
        except Exception as e:
            print('batch', i, 'retry', attempt, e, file=sys.stderr); time.sleep(2)
json.dump(results, open(W + 'rename_results.json','w'), indent=1)
print('results:', len(results))
ok = sum(1 for r in results if isinstance(r,dict) and (r.get('ok') or r.get('renamed') or r.get('success')))
errs = [r for r in results if isinstance(r,dict) and (r.get('error') or r.get('ok') is False)]
print('ok:', ok, 'errs:', len(errs))
for e in errs[:20]: print('ERR', e)
