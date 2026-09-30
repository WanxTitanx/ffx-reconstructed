#!/usr/bin/env python3
"""K76-FINE: batch decompile PPP handlers via ida-pro-mcp JSON-RPC (VM 192.168.122.85:8745).
Usage: decompile.py <addr> [<addr> ...]  → saves work/_ppp_fine2/dec_<addr>.txt"""
import json, subprocess, sys, time

URL = 'http://192.168.122.85:8745/mcp'

def call(name, args, rid):
    payload = {"jsonrpc":"2.0","id":rid,"method":"tools/call","params":{"name":name,"arguments":args}}
    r = subprocess.run(['curl','-s','-m','120',URL,'-H','Content-Type: application/json','-d',json.dumps(payload)],
                       capture_output=True, text=True)
    return json.loads(r.stdout)

for i, addr in enumerate(sys.argv[1:]):
    res = call('decompile', {"addr": addr, "include_addresses": True}, 100+i)
    try:
        txt = res['result']['content'][0]['text']
    except Exception:
        txt = json.dumps(res)
    fn = f"dec_{addr}.txt"
    open(fn, 'w').write(txt)
    first = txt.splitlines()[0] if txt.splitlines() else '(empty)'
    print(f"{addr}: {len(txt)} chars -> {fn} | {first[:100]}")
    time.sleep(0.2)
