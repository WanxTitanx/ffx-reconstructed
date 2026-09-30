#!/usr/bin/env python3
import json, urllib.request, sys, os
URL = "http://192.168.122.85:8745/mcp"
def _post(payload, sess=None):
    req = urllib.request.Request(URL, data=json.dumps(payload).encode(),
        headers={"Content-Type":"application/json","Accept":"application/json, text/event-stream"})
    if sess: req.add_header("mcp-session-id", sess)
    r = urllib.request.urlopen(req, timeout=600)
    body = r.read().decode()
    lines=[l[6:] for l in body.splitlines() if l.startswith("data: ")]
    return r.headers.get("mcp-session-id"), ("\n".join(lines) if lines else body)
sess,_ = _post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"dec2","version":"1"}}})
_post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
def call(tool,args):
    _,out=_post({"jsonrpc":"2.0","id":1,"method":"tools/call","params":{"name":tool,"arguments":args}},sess)
    d=json.loads(out); res=d.get('result',d)
    if isinstance(res,dict) and 'structuredContent' in res:
            sc=res['structuredContent']; return sc.get('result',sc)
    if isinstance(res,dict) and 'content' in res:
        try: return json.loads(res['content'][0]['text'])
        except: return res['content'][0]['text']
    return res
for a in sys.argv[1:]:
    r=call("decompile",{"addr":a})
    code=r.get('code') if isinstance(r,dict) else str(r)
    fn=f"dec_{a}_code.txt"
    open(fn,"w").write(code or "")
    print(a, len(code or ""), (code or "").split(chr(10))[2][:80] if code else "")
