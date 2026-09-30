#!/usr/bin/env python3
"""fetch_vals.py — pull init bytes (item + 0x40 neighborhood) for top150 dummies."""
import sys, json, struct
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post
W = '/home/wanderson/Documents/ffx-editor-main/work/_data_r2/'
top = json.load(open(W + 'top150.json'))

sess, _ = post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                           "clientInfo": {"name": "data-r2", "version": "1"}}})
post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sess)

def call(tool, args):
    _, body = post({"jsonrpc": "2.0", "id": 2, "method": "tools/call",
                    "params": {"name": tool, "arguments": args}}, sess)
    d = json.loads(body)
    r = d.get('result', d)
    return r['content'][0]['text'] if isinstance(r, dict) and 'content' in r else json.dumps(r)

def raw(a, n):
    d = json.loads(call('get_bytes', {'regions': [{'addr': hex(a), 'size': n}]}))
    hexs = d[0]['data']
    return bytes(int(t,16) for t in hexs.replace('0x','').split()) if isinstance(hexs,str) else bytes(hexs)

out = []
for i, r in enumerate(top):
    a = int(r['addr'], 16)
    try:
        b = raw(a, 64)
    except Exception as e:
        b = b''
    e2 = dict(r)
    e2['bytes64'] = b.hex()
    # decode likely scalar
    pref = r['name'].split('_')[0]
    try:
        if pref == 'flt': e2['val'] = struct.unpack('<f', b[:4])[0]
        elif pref == 'dbl': e2['val'] = struct.unpack('<d', b[:8])[0]
        elif pref == 'word': e2['val'] = struct.unpack('<H', b[:2])[0]
        elif pref in ('dword','off'): e2['val'] = struct.unpack('<I', b[:4])[0]
        elif pref == 'byte': e2['val'] = b[0]
        elif pref == 'qword': e2['val'] = struct.unpack('<Q', b[:8])[0]
        elif pref == 'xmmword': e2['val'] = b[:16].hex()
    except Exception:
        pass
    out.append(e2)
    if i % 25 == 0: print(i, flush=True)
json.dump(out, open(W + 'top150_vals.json','w'), indent=1)
print('DONE')
