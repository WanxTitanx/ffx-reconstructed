#!/usr/bin/env python3
"""scan_blobs.py — count vftable sections inside each derived class's vtable
blob. A section boundary = dword pointing to a valid COL
{sig 0|1, cd small, pTD->rdata, pCHD->rdata} that is not the blob's own -4 ptr.
Also resolves names for all RTTI addrs used by the edges."""
import sys, json, struct, time
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post

W = '/home/wanderson/Documents/ffx-editor-main/work/_data_r2/'
edges = json.load(open(W + 'abstract_edges.json'))
ev = json.load(open(W + 'edge_evidence.json'))
evmap = {(int(e['td'],16), int(e['bcd'],16)): e for e in ev}
H = json.load(open('/home/wanderson/Documents/ffx-editor-main/work/_chd_inherit/hierarchy.json'))
vtbl_starts = sorted(int(k,16) for k in H.keys())

sess, _ = post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                           "clientInfo": {"name": "data-r2", "version": "1"}}})
post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sess)

def call(tool, args, tries=3):
    for i in range(tries):
        try:
            _, body = post({"jsonrpc": "2.0", "id": 2, "method": "tools/call",
                            "params": {"name": tool, "arguments": args}}, sess)
            d = json.loads(body)
            r = d.get('result', d)
            return r['content'][0]['text'] if isinstance(r, dict) and 'content' in r else json.dumps(r)
        except Exception as e:
            if i == tries-1: return json.dumps({'error': str(e)})
            time.sleep(2)

def raw(a, n):
    d = json.loads(call('get_bytes', {'regions': [{'addr': hex(a), 'size': n}]}))
    hexs = d[0]['data']
    return bytes(int(t,16) for t in hexs.replace('0x','').split()) if isinstance(hexs,str) else bytes(hexs)

def dw(a, n):
    return list(struct.unpack('<%dI'%n, raw(a, n*4)))

def name_at(a):
    d = json.loads(call('entity_query', {'queries': {'kind':'names','min_addr':hex(a),'max_addr':hex(a),'count':1}}))
    try: return d[0]['data'][0]['name']
    except Exception: return None

def is_col(a):
    try: c = dw(a, 5)
    except Exception: return None
    if c[0] in (0,1) and 0 <= c[2] <= 0x100 and 0xB00000 <= c[3] <= 0x1000000 and 0xB00000 <= c[4] <= 0x1000000:
        return {'col': a, 'off': c[1], 'td': c[3], 'chd': c[4]}
    return None

deriveds = {}
for e in edges:
    dv = int(e['derived_vtbl'], 16)
    if dv in deriveds: continue
    i = vtbl_starts.index(dv)
    nxt = vtbl_starts[i+1] if i+1 < len(vtbl_starts) else dv + 0x400
    # scan [vtbl-4, next_vtbl-4) for colptrs
    vals = dw(dv-4, (nxt-(dv-4))//4)
    sections = []
    for j, v in enumerate(vals):
        a = dv - 4 + j*4
        if 0xB00000 <= v <= 0x1000000:
            c = is_col(v)
            if c:
                sections.append({'sec_vtbl': hex(a+4), 'col': hex(v), 'col_off': c['off'], 'col_td': hex(c['td']), 'col_chd': hex(c['chd'])})
    deriveds[hex(dv)] = {'name': e['derived_vtbl_name'], 'scan_end': hex(nxt), 'sections': sections}
    print(hex(dv), e['derived_vtbl_name'], 'sections:', sections, flush=True)

json.dump(deriveds, open(W + 'derived_sections.json', 'w'), indent=1)
print('DONE', len(deriveds))
