#!/usr/bin/env python3
import json, re, urllib.request, sys
URL='http://192.168.122.85:8745/mcp'
H={'Content-Type':'application/json','Accept':'application/json, text/event-stream'}
def post(p,s=None):
    h=dict(H)
    if s:h['mcp-session-id']=s
    r=urllib.request.Request(URL,data=json.dumps(p).encode(),headers=h)
    resp=urllib.request.urlopen(r,timeout=180); sid=resp.headers.get('mcp-session-id',s)
    out=[]
    for line in resp.read().decode().splitlines():
        if line.startswith('data: '):out.append(line[6:])
        elif line and not line.startswith('event:') and not line.startswith(':'):out.append(line)
    return sid,'\n'.join(out)
def call(tool,args):
    s,_=post({'jsonrpc':'2.0','id':1,'method':'initialize','params':{'protocolVersion':'2025-03-26','capabilities':{},'clientInfo':{'name':'x','version':'1'}}})
    post({'jsonrpc':'2.0','method':'notifications/initialized'},s)
    _,b=post({'jsonrpc':'2.0','id':2,'method':'tools/call','params':{'name':tool,'arguments':args}},s)
    d=json.loads(b); res=d.get('result',d)
    if isinstance(res,dict) and 'content' in res:
        txt='\n'.join(c.get('text','') for c in res['content'] if c.get('type')=='text')
        return json.loads(txt)  # raise on parse fail
    return res
handlers=json.load(open('work/_ppp_aux/handler_addrs.json'))
mach=json.load(open('work/_ppp_aux/machinery_addrs.json'))
alladdrs=handlers+mach
pat=re.compile(r'\+(14|18)h\]')
hits={}
errors=[]
CH=8
for i in range(0,len(alladdrs),CH):
    chunk=alladdrs[i:i+CH]
    qs=[{'addr':a,'include_disasm':True,'max_disasm_insns':3000} for a in chunk]
    try:
        res=call('analyze_batch',{'queries':qs})
    except Exception as e:
        errors.append((chunk[0],str(e)[:200])); print('ERR chunk',i,str(e)[:120],file=sys.stderr); continue
    items = res if isinstance(res,list) else [res]
    for it in items:
        if not isinstance(it,dict):
            errors.append(('nondict',str(it)[:100])); continue
        addr=it.get('addr') or it.get('target') or '?'
        an=it.get('analysis') or {}
        dis=an.get('disasm') or {}
        lines=dis.get('lines') if isinstance(dis,dict) else dis
        if not lines:
            errors.append((addr,'no lines')); continue
        for line in lines:
            if pat.search(str(line)):
                hits.setdefault(addr,[]).append(str(line).strip())
    print(f'chunk {i}..{i+len(chunk)-1} hits {sum(len(v) for v in hits.values())}',file=sys.stderr)
json.dump({'hits':hits,'errors':errors},open('work/_ppp_aux/aux1418_scan.json','w'),indent=1)
print('fns with +14h/+18h operand lines:',len(hits),'errors:',len(errors))
for a,ls in sorted(hits.items()):
    print('##',a)
    for l in ls: print('   ',l)
