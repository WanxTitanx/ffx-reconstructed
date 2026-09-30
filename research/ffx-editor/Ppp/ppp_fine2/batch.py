#!/usr/bin/env python3
"""K76-FINE L2: analyze_batch decompile via ida-pro-mcp JSON-RPC.
Usage: batch.py out.json 0xADDR [0xADDR ...] — saves one dec_<addr>.txt per addr + combined json."""
import json, subprocess, sys

URL = 'http://192.168.122.85:8745/mcp'

def call(name, args, rid=1):
    payload = {"jsonrpc":"2.0","id":rid,"method":"tools/call","params":{"name":name,"arguments":args}}
    r = subprocess.run(['curl','-s','-m','300',URL,'-H','Content-Type: application/json','-d',json.dumps(payload)],
                       capture_output=True, text=True)
    return json.loads(r.stdout)

if __name__ == '__main__':
    out = sys.argv[1]
    addrs = sys.argv[2:]
    queries = [{"addr": a, "include_decompile": True, "include_disasm": False} for a in addrs]
    res = call('analyze_batch', {"queries": queries})
    txt = res['result']['content'][0]['text']
    open(out,'w').write(txt)
    try:
        items = json.loads(txt)
        if isinstance(items, dict): items = items.get("result", [items])
    except Exception:
        print('non-json result, saved raw to', out); sys.exit(0)
    for it in items:
        a = it.get('target') or it.get('addr')
        name = it.get('name')
        dec = (it.get('analysis') or {}).get('decompile') or json.dumps(it)[:500]
        fn = f"dec_{a.upper().replace('0X','0x')}.txt"
        with open(fn,'w') as f:
            f.write(json.dumps(it, indent=1))
        print(f"{a}: {name} -> {fn} ({len(dec)} chars dec)")
