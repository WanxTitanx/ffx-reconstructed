#!/usr/bin/env python3
import json, urllib.request, sys, re
URL = "http://192.168.122.85:8745/mcp"
def _post(payload, sess=None):
    req = urllib.request.Request(URL, data=json.dumps(payload).encode(),
        headers={"Content-Type":"application/json","Accept":"application/json, text/event-stream"})
    if sess: req.add_header("mcp-session-id", sess)
    r = urllib.request.urlopen(req, timeout=600)
    body = r.read().decode()
    lines=[l[6:] for l in body.splitlines() if l.startswith("data: ")]
    return r.headers.get("mcp-session-id"), ("\n".join(lines) if lines else body)
sess,_ = _post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"scanst","version":"1"}}})
_post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
def call(tool,args):
    _,out=_post({"jsonrpc":"2.0","id":1,"method":"tools/call","params":{"name":tool,"arguments":args}},sess)
    d=json.loads(out); res=d.get('result',d)
    if isinstance(res,dict) and 'structuredContent' in res: return res['structuredContent']
    if isinstance(res,dict) and 'content' in res:
        try: return json.loads(res['content'][0]['text'])
        except: return res['content'][0]['text']
    return res
# pattern: byte access [reg+9Ch]  -> 'byte ptr [xx+9Ch]' or movzx/cmp/mov byte
start="0x401000"; end="0xB10000"; cursor=None; allhits=[]
for page in range(20):
    args={"pattern":"byte ptr \\[\\w+\\+9Ch\\]","regex":True,"limit":500}
    if start: args["start"]=start
    if end: args["end"]=end
    res=call("search_text",args)
    hits=res.get('hits',[]) if isinstance(res,dict) else []
    allhits+=hits
    cur=res.get('cursor',{}) if isinstance(res,dict) else {}
    nxt=cur.get('next')
    print("page",page,"hits",len(hits),"next",nxt, flush=True)
    if not nxt: break
    start=nxt
open("st_9c_byte.json","w").write(json.dumps(allhits))
for h in allhits:
    for m in h['matches']:
        print(h['addr'], h.get('function'), '::', m['text'].split('  ')[-1].strip())
print("TOTAL",len(allhits))
