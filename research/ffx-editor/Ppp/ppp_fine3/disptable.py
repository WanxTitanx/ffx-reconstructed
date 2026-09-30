#!/usr/bin/env python3
import json, urllib.request, struct
URL = "http://192.168.122.85:8745/mcp"
def _post(payload, sess=None):
    req = urllib.request.Request(URL, data=json.dumps(payload).encode(),
        headers={"Content-Type":"application/json","Accept":"application/json, text/event-stream"})
    if sess: req.add_header("mcp-session-id", sess)
    r = urllib.request.urlopen(req, timeout=600)
    body = r.read().decode()
    lines=[l[6:] for l in body.splitlines() if l.startswith("data: ")]
    return r.headers.get("mcp-session-id"), ("\n".join(lines) if lines else body)
sess,_ = _post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"disp","version":"1"}}})
_post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
def call(tool,args):
    _,out=_post({"jsonrpc":"2.0","id":1,"method":"tools/call","params":{"name":tool,"arguments":args}},sess)
    d=json.loads(out); res=d.get('result',d)
    if isinstance(res,dict) and 'structuredContent' in res: return res['structuredContent']
    if isinstance(res,dict) and 'content' in res:
        try: return json.loads(res['content'][0]['text'])
        except: return res['content'][0]['text']
    return res
def getb(addr,size):
    r=call("get_bytes",{"regions":[{"addr":hex(addr),"size":size}]})
    if isinstance(r,list): r=r[0]
    s=r["data"]
    return bytes(int(x,16) for x in s.split())
def getname(p):
    try:
        b=getb(p,40); return b.split(b'\x00')[0].decode('ascii','replace')
    except Exception as e: return '?'+hex(p)
# table at 0xC3DD18; read 4KB
tab=getb(0xC3DD18,4096)
for i in range(0,4096,40):
    e=tab[i:i+40]
    if len(e)<40: break
    name_ptr=struct.unpack('<I',e[0:4])[0]
    w3=struct.unpack('<I',e[0x0C:0x10])[0]
    w7=struct.unpack('<I',e[0x1C:0x20])[0]
    w8=struct.unpack('<I',e[0x20:0x24])[0]
    nm=getname(name_ptr) if 0x400000<=name_ptr<0x1200000 else hex(name_ptr)
    print(hex(0xC3DD18+i), nm.ljust(22), 'w3='+hex(w3), 'w7='+hex(w7), 'w8='+hex(w8))
