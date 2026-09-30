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
sess,_ = _post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"scan4a","version":"1"}}})
_post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
def call(tool,args):
    _,out=_post({"jsonrpc":"2.0","id":1,"method":"tools/call","params":{"name":tool,"arguments":args}},sess)
    d=json.loads(out); res=d.get('result',d)
    if isinstance(res,dict) and 'structuredContent' in res: return res['structuredContent']
    if isinstance(res,dict) and 'content' in res:
        try: return json.loads(res['content'][0]['text'])
        except: return res['content'][0]['text']
    return res
allhits=[]
for page in range(20):
    args={"pattern":"\\+4Ah\\]","regex":True,"limit":500,"start":"0x401000","end":"0xB10000"}
    res=call("search_text",args)
    hits=res.get('hits',[]) if isinstance(res,dict) else []
    allhits+=hits
    nxt=(res.get('cursor') or {}).get('next')
    if not nxt: break
open("st_4a_all.json","w").write(json.dumps(allhits))
print("TOTAL",len(allhits))
for h in allhits:
    fn=(h.get('function') or {}).get('name','?')
    for m in h.get('matches',[]):
        print(h['addr'], fn, '::', m['text'].split('  ')[-1].strip())
