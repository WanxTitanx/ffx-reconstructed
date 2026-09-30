#!/usr/bin/env python3
import json, urllib.request, sys
URL = "http://192.168.122.85:8745/mcp"
def _post(payload, sess=None):
    req = urllib.request.Request(URL, data=json.dumps(payload).encode(),
        headers={"Content-Type":"application/json","Accept":"application/json, text/event-stream"})
    if sess: req.add_header("mcp-session-id", sess)
    r = urllib.request.urlopen(req, timeout=600)
    sid = r.headers.get("mcp-session-id")
    body = r.read().decode()
    lines=[l[6:] for l in body.splitlines() if l.startswith("data: ")]
    return sid, ("\n".join(lines) if lines else body)
sess,_ = _post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"scandraw","version":"1"}}})
_post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
def call(tool,args):
    _,out=_post({"jsonrpc":"2.0","id":1,"method":"tools/call","params":{"name":tool,"arguments":args}},sess)
    d=json.loads(out); res=d.get('result',d)
    if isinstance(res,dict) and 'structuredContent' in res: return res['structuredContent']['result']
    if isinstance(res,dict) and 'content' in res:
        try: return json.loads(res['content'][0]['text'])
        except: return res['content'][0]['text']
    return res

handlers = ["0x737830","0x737be0","0x738000","0x7385f0","0x738b00","0x738f80","0x739580","0x739df0","0x73a430","0x73aca0","0x73ba70","0x73d130","0x73d9f0","0x73e370","0x73eb00","0x73f2f0","0x73fb10","0x7404d0","0x741660","0x742d80","0x744100","0x7452d0","0x7463e0","0x747600","0x748860","0x7563b0","0x757370","0x74a2b0","0x74a920","0x74af40"]
q=[{"addr":h,"include_disasm":True,"max_disasm_insns":50000} for h in handlers]
res=call("analyze_batch",{"queries":q})
open("draw_batch.json","w").write(json.dumps(res))
for i,r in enumerate(res):
    asm=r.get('disasm') or r.get('asm') or {}
    txt=json.dumps(r)
    hits=[l for l in txt.split('\\n') if '9Ch]' in l or '+9Ch' in l]
    # also search raw lines
    lines=r.get('disasm',{}).get('lines',[]) if isinstance(r.get('disasm'),dict) else []
    for l in lines:
        ins=l.get('instruction','')
        if '+9Ch' in ins or '9Ch]' in ins:
            print(handlers[i], r.get('name','?'), '::', ins)
print("done")
