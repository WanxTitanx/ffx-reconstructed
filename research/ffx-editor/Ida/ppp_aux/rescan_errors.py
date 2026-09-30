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
    return sid,out   # list of data payloads
def call(tool,args):
    s,_=post({'jsonrpc':'2.0','id':1,'method':'initialize','params':{'protocolVersion':'2025-03-26','capabilities':{},'clientInfo':{'name':'x','version':'1'}}})
    post({'jsonrpc':'2.0','method':'notifications/initialized'},s)
    _,lines=post({'jsonrpc':'2.0','id':2,'method':'tools/call','params':{'name':tool,'arguments':args}},s)
    # find the JSON-RPC response containing result
    for l in lines:
        try:
            d=json.loads(l)
        except Exception:
            continue
        res=d.get('result')
        if res is None: continue
        if isinstance(res,dict) and 'content' in res:
            txt='\n'.join(c.get('text','') for c in res['content'] if c.get('type')=='text')
            return json.loads(txt)
        return res
    raise RuntimeError('no result in '+str(lines)[:200])
handlers=json.load(open('work/_ppp_aux/handler_addrs.json'))
mach=json.load(open('work/_ppp_aux/machinery_addrs.json'))
alladdrs=handlers+mach
prev=json.load(open('work/_ppp_aux/aux1418_scan.json'))
# figure out which chunks failed: errors list has chunk[0] addr
failstarts={e[0] for e in prev['errors'] if isinstance(e[0],str) and e[0].startswith('0x')}
# rebuild chunk starts
CH=8
missed=[]
for i in range(0,len(alladdrs),CH):
    if alladdrs[i] in failstarts:
        missed+=alladdrs[i:i+CH]
# also 'no lines' entries
nolines={e[0] for e in prev['errors'] if isinstance(e[0],str) and e[0].startswith('0x') and e[1]=='no lines'}
missed=sorted(set(missed)|nolines, key=lambda x:int(x,16))
print('missed fns:',len(missed),file=sys.stderr)
pat=re.compile(r'\+(14|18)h\]')
hits=prev['hits']; errors=[]
for a in missed:
    try:
        res=call('analyze_batch',{'queries':[{'addr':a,'include_disasm':True,'max_disasm_insns':4000}]})
    except Exception as e:
        errors.append((a,str(e)[:200])); print('ERR',a,str(e)[:100],file=sys.stderr); continue
    items=res if isinstance(res,list) else [res]
    for it in items:
        if not isinstance(it,dict): continue
        addr=it.get('addr') or a
        an=it.get('analysis') or {}
        dis=an.get('disasm') or {}
        lines=dis.get('lines') if isinstance(dis,dict) else dis
        if not lines: errors.append((a,'no lines')); continue
        for line in lines:
            if pat.search(str(line)):
                hits.setdefault(addr,[]).append(str(line).strip())
json.dump({'hits':hits,'errors':errors},open('work/_ppp_aux/aux1418_scan.json','w'),indent=1)
print('rescan done. hits fns:',len(hits),'new errors:',len(errors))
for a in sorted(hits,key=lambda x:int(x,16)):
    print('##',a)
    for l in hits[a]: print('   ',l)
