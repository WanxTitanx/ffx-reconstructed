#!/usr/bin/env python3
import json, urllib.request
URL = "http://192.168.122.85:8745/mcp"
def _post(payload, sess=None):
    req = urllib.request.Request(URL, data=json.dumps(payload).encode(),
        headers={"Content-Type":"application/json","Accept":"application/json, text/event-stream"})
    if sess: req.add_header("mcp-session-id", sess)
    r = urllib.request.urlopen(req, timeout=600)
    body = r.read().decode()
    lines=[l[6:] for l in body.splitlines() if l.startswith("data: ")]
    return r.headers.get("mcp-session-id"), ("\n".join(lines) if lines else body)
sess,_ = _post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"scandraw2","version":"1"}}})
_post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
def call(tool,args):
    _,out=_post({"jsonrpc":"2.0","id":1,"method":"tools/call","params":{"name":tool,"arguments":args}},sess)
    d=json.loads(out); res=d.get('result',d)
    if isinstance(res,dict) and 'structuredContent' in res: return res['structuredContent']['result']
    if isinstance(res,dict) and 'content' in res:
        try: return json.loads(res['content'][0]['text'])
        except: return res['content'][0]['text']
    return res

handlers = {"0x737830":"DrawMdl/BS","0x737be0":"DrawMdlSemi","0x738000":"DrawMdlTs","0x7385f0":"DrawMdl2","0x738b00":"DrawMdlSemi2","0x738f80":"DrawMdlTs2","0x739580":"DrawMdl3","0x739df0":"DrawMdlSemi3","0x73a430":"DrawMdlTs3","0x73aca0":"DrawMdlSea","0x73ba70":"DrawMdlInf","0x73d130":"DrawMdlPSim","0x73d9f0":"DrawMdlCamera","0x73e370":"DrawMdlLoop","0x73eb00":"DrawMdlLoopZ","0x73f2f0":"DrawMdlLoopDisPos","0x73fb10":"DrawMdlCameraLoop","0x7404d0":"DrawMdlRev","0x741660":"DrawShapeRev","0x742d80":"DrawShapeField","0x744100":"DrawShapeFieldRev","0x7452d0":"DrawShapeFieldSpd","0x7463e0":"DrawShapeFieldGlobal","0x747600":"DrawShapeCamera","0x748860":"DrawShapeCameraDisPos","0x7563b0":"DrawRain","0x757370":"DrawFilter","0x74a2b0":"NeiDrawMdlPointLight","0x74a920":"NeiDrawMdlSemiPointLight","0x74af40":"NeiDrawMdlTsPointLight"}
hs=list(handlers)
alld={}
for i in range(0,len(hs),10):
    chunk=hs[i:i+10]
    q=[{"addr":h,"include_disasm":True,"include_decompile":True,"max_disasm_insns":50000} for h in chunk]
    res=call("analyze_batch",{"queries":q})
    for r in res:
        alld[r.get('target')]=r
    print("chunk",i,"got",len(res),flush=True)
open("draw_batch_all.json","w").write(json.dumps(alld))
# grep for +9Ch in disasm lines and '156' in decompile
for h,r in alld.items():
    an=r.get('analysis',{})
    dis=an.get('disasm',{})
    for l in dis.get('lines',[]):
        ins=l if isinstance(l,str) else l.get('instruction','')
        if '9Ch]' in ins or '+9Ch' in ins:
            print(h, handlers.get(h), 'DIS:', ins[:120])
    dec=an.get('decompile','') or ''
    for line in dec.split('\n'):
        if '+ 156' in line or '+156' in line or '156)' in line or '9Ch' in line:
            print(h, handlers.get(h), 'DEC:', line.strip()[:140])
print("DONE")
