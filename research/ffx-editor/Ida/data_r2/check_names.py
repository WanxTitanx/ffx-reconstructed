#!/usr/bin/env python3
import sys, json, time
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post
sess, _ = post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"data-r2","version":"1"}}})
post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
def call(tool, args):
    _, body = post({"jsonrpc":"2.0","id":2,"method":"tools/call","params":{"name":tool,"arguments":args}}, sess)
    d = json.loads(body); r = d.get('result', d)
    return r['content'][0]['text'] if isinstance(r, dict) and 'content' in r else json.dumps(r)
top = json.load(open('/home/wanderson/Documents/ffx-editor-main/work/_data_r2/top150.json'))
res = {}
# batch: names for each addr
for i in range(0, len(top), 25):
    chunk = top[i:i+25]
    for r in chunk:
        a = int(r['addr'],16)
        try:
            t = call('entity_query', {'queries':{'kind':'names','min_addr':hex(a),'max_addr':hex(a),'count':1}})
            d = json.loads(t)
            res[r['name']] = d[0]['data'][0]['name'] if d[0].get('data') else None
        except Exception as e:
            res[r['name']] = f'ERR {e}'
    print(i, flush=True)
json.dump(res, open('/home/wanderson/Documents/ffx-editor-main/work/_data_r2/current_names.json','w'), indent=1)
still_dummy = sum(1 for k,v in res.items() if v and v.startswith(k.split('_')[0]+'_'))
renamed = {k:v for k,v in res.items() if v and not v.startswith(k.split('_')[0]+'_')}
print('still dummy:', still_dummy, 'renamed/other:', len(renamed))
for k,v in renamed.items(): print('  RENAMED:', k, '->', v)
