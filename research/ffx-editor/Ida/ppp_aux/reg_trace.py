#!/usr/bin/env python3
"""For each fn in aux1418_scan hits, fetch disasm and trace the base register
of every [reg+14h]/[reg+18h] access back through mov/lea chains to see whether
it ever flows from a record pointer (cmdrec[0] deref) vs particle data."""
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
            return json.loads(txt)
        return res
    raise RuntimeError('no result')
d=json.load(open('work/_ppp_aux/aux1418_scan.json'))
fns=sorted(d['hits'].keys(), key=lambda x:int(x,16))
hitpat=re.compile(r'\+(14|18)h\]')
assign=re.compile(r'^\s*([0-9a-f]+)\s+(mov|lea|movzx|movsx)\s+(e[a-z]{2}),\s*(.*)$')
out={}
for a in fns:
    res=call('analyze_batch',{'queries':[{'addr':a,'include_disasm':True,'max_disasm_insns':4000}]})
    it=(res if isinstance(res,list) else [res])[0]
    lines=(it.get('analysis') or {}).get('disasm',{}).get('lines',[])
    # sequential provenance tracking: reg -> set of source descriptions
    prov={}
    hits=[]
    for l in lines:
        ls=str(l)
        # strip inline comment
        codepart=ls.split(';')[0]
        m=assign.match(codepart)
        if m:
            ea,op,reg,src=m.groups()
            srcs=src.strip()
            # provenance: which regs/mems feed this reg
            refs=set(re.findall(r'e[a-z]{2}', srcs))
            membase=set(re.findall(r'\[(e[a-z]{2})', srcs))
            argref='arg' in srcs or 'ebp+' in srcs
            prov[reg]={'ea':ea,'op':op,'src':srcs,'refs':refs,'mem':bool('[' in srcs),'argref':argref,'deref0':srcs.strip().startswith('[') and '+' not in srcs.strip()[:srcs.strip().index(']')] if '[' in srcs else False}
        elif re.search(r'^\s*[0-9a-f]+\s+(xor|sub)\s+(e[a-z]{2}),\s*\2',codepart):
            m2=re.match(r'^\s*([0-9a-f]+)\s+\w+\s+(e[a-z]{2})',codepart); 
            if m2: prov[m2.group(2)]={'ea':m2.group(1),'op':'zero','src':'0','refs':set(),'mem':False}
        hm=hitpat.search(codepart)
        if hm:
            basem=re.search(r'\[(e[a-z]{2})[^[\]]*\+(14|18)h\]',codepart)
            if basem:
                breg=basem.group(1)
                # trace chain up to 6 hops
                chain=[]; cur=breg; seen=set()
                while cur in prov and cur not in seen and len(chain)<6:
                    seen.add(cur); p=prov[cur]
                    chain.append(f"{cur} <= {p['op']} {p['src']} @{p['ea']}")
                    nxt=[r for r in p['refs'] if r!=cur]
                    cur=nxt[0] if nxt else None
                hits.append({'line':codepart.strip(),'base':breg,'chain':chain})
    out[a]={'name':it.get('name'),'hits':hits}
json.dump(out,open('work/_ppp_aux/reg_trace_1418.json','w'),indent=1)
for a in fns:
    print('####',a,out[a]['name'])
    for h in out[a]['hits']:
        print('  HIT:',h['line'][:80])
        for c in h['chain']: print('      ',c[:90])
