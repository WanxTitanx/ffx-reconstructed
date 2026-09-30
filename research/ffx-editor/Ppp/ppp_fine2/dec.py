#!/usr/bin/env python3
"""Full decompile via 'decompile' tool -> dec_<addr>.txt (raw text)."""
import json, subprocess, sys, time
URL = 'http://192.168.122.85:8745/mcp'
def call(name, args, rid=1):
    payload = {"jsonrpc":"2.0","id":rid,"method":"tools/call","params":{"name":name,"arguments":args}}
    r = subprocess.run(['curl','-s','-m','300',URL,'-H','Content-Type: application/json','-d',json.dumps(payload)],
                       capture_output=True, text=True)
    return json.loads(r.stdout)
for i,a in enumerate(sys.argv[1:]):
    res = call('decompile', {"addr": a}, 200+i)
    txt = res['result']['content'][0]['text']
    open(f'full_{a}.txt','w').write(txt)
    print(a, len(txt), txt.splitlines()[0][:80] if txt else 'EMPTY')
    time.sleep(0.15)
