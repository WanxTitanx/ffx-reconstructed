import json, urllib.request, re, collections
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
    return sid,out
def call(tool,args):
    s,_=post({'jsonrpc':'2.0','id':1,'method':'initialize','params':{'protocolVersion':'2025-03-26','capabilities':{},'clientInfo':{'name':'x','version':'1'}}})
    post({'jsonrpc':'2.0','method':'notifications/initialized'},s)
    _,lines=post({'jsonrpc':'2.0','id':2,'method':'tools/call','params':{'name':tool,'arguments':args}},s)
    for l in lines:
        try: d=json.loads(l)
        except Exception: continue
        res=d.get('result')
        if res is None: continue
        if isinstance(res,dict) and 'content' in res:
            txt='\n'.join(c.get('text','') for c in res['content'] if c.get('type')=='text')
            try: return json.loads(txt)
            except Exception: return txt
        return res
    return None
d=json.load(open('work/_ppp_aux/xrefs_7e3720.json'))
sites=[(x['addr'],(x.get('fn') or {}).get('addr'),(x.get('fn') or {}).get('name')) for x in d[0]['xrefs'] if x['type']=='code']
fncache={}
out=[]
for s,fa,fn in sites:
    if fa is None:
        # no function: disasm a window starting ~0x30 before
        res=call('disasm',{'addr':hex(int(s,16)-0x30),'max_instructions':60})
    else:
        if fa not in fncache:
            fncache[fa]=call('disasm',{'addr':fa,'max_instructions':9000})
        res=fncache[fa]
    if not res or isinstance(res,str): out.append((s,fn,'NORES')); continue
    asm=res.get('asm',{})
    lines=[(l['addr'],l['instruction']) for l in asm.get('lines',[]) if isinstance(l,dict)]
    target=s.lower().replace('0x','')
    found=False
    for i,(a,ins) in enumerate(lines):
        if a==target and 'call' in ins:
            found=True
            pushes=[]
            for j in range(i-1,max(-1,i-10),-1):
                ins2=lines[j][1].split(';')[0].strip()
                if ins2.startswith('push'):
                    m=re.search(r'push\s+(?:dword ptr )?(.+)',ins2)
                    pushes.append(m.group(1).strip() if m else ins2)
                elif ins2.startswith('call') or ins2=='retn': break
            out.append((s,fn,list(reversed(pushes))))
            break
    if not found: out.append((s,fn,'call-not-found'))
n8=collections.Counter()
for s,fn,p in out:
    if isinstance(p,list) and len(p)>=2: n8[p[1]]+=1
print('n8 (2nd pushed arg = n8 param):',dict(n8))
for s,fn,p in out:
    print(s,fn,p)
