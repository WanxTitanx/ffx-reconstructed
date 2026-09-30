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
sess,_ = _post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"scanptr","version":"1"}}})
_post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
def call(tool,args):
    _,out=_post({"jsonrpc":"2.0","id":1,"method":"tools/call","params":{"name":tool,"arguments":args}},sess)
    d=json.loads(out); res=d.get('result',d)
    if isinstance(res,dict) and 'structuredContent' in res: return res['structuredContent']
    if isinstance(res,dict) and 'content' in res:
        try: return json.loads(res['content'][0]['text'])
        except: return res['content'][0]['text']
    return res
# byte-pattern stores to ds:0D2C248h
pats=["A3 48 C2 D2 00","89 05 48 C2 D2 00","89 0D 48 C2 D2 00","89 15 48 C2 D2 00","89 1D 48 C2 D2 00","89 25 48 C2 D2 00","89 35 48 C2 D2 00","89 3D 48 C2 D2 00","C7 05 48 C2 D2 00"]
res=call("find_bytes",{"patterns":pats,"limit":40})
print(json.dumps(res,indent=1)[:3000])
