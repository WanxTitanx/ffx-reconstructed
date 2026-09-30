#!/usr/bin/env python3
import json, sys, urllib.request

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

sess,_ = _post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"scan156","version":"1"}}})
_post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)

def unwrap(out):
    d=json.loads(out)
    res=d.get('result',d)
    if isinstance(res,dict) and 'structuredContent' in res:
        return res['structuredContent']['result']
    if isinstance(res,dict) and 'content' in res:
        return json.loads(res['content'][0]['text'])
    return res

start = 0x401000; end = 0xB10000; step = 0x60000
all_matches=[]
a = start
while a < end:
    b = min(a+step, end)
    q = {"op_any":156,"start":hex(a),"end":hex(b),"count":5000}
    _,out = _post({"jsonrpc":"2.0","id":1,"method":"tools/call","params":{"name":"insn_query","arguments":{"queries":q}}}, sess)
    try:
        res=unwrap(out)[0]
        ms=[m['addr'] for m in res['matches']]
        all_matches+=ms
        print(f"{hex(a)}-{hex(b)}: scanned={res['scanned']} trunc={res['truncated']} -> {ms}", flush=True)
    except Exception as e:
        print(f"{hex(a)}-{hex(b)}: ERR {e} out={out[:300]}", flush=True)
    a = b
print("TOTAL:", all_matches)
