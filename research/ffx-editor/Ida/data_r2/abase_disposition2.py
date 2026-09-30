#!/usr/bin/env python3
import sys, json, struct, time
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post
W = '/home/wanderson/Documents/ffx-editor-main/work/_data_r2/'
edges = json.load(open(W + 'abstract_edges.json'))
sess, _ = post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"abase","version":"1"}}})
post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
def call(tool, args):
    for a in range(3):
        try:
            _, body = post({"jsonrpc":"2.0","id":2,"method":"tools/call","params":{"name":tool,"arguments":args}}, sess)
            d = json.loads(body); r = d.get('result', d)
            return r['content'][0]['text'] if isinstance(r, dict) and 'content' in r else json.dumps(r)
        except Exception as ex:
            time.sleep(1.5)
    return '[]'
def rd(ea, n):
    d = json.loads(call('get_bytes', {'regions':[{'addr': hex(ea), 'size': n}]}))
    if isinstance(d, list): d = d[0]
    data = d.get('data')
    return bytes(int(x,16) for x in data.split()) if isinstance(data,str) else bytes(data or b'')
def u32(ea): return struct.unpack('<I', rd(ea,4))[0]
def xref_list(ea):
    d = json.loads(call('xrefs_to', {'addrs': hex(ea), 'limit': 200}))
    if isinstance(d, list) and d and isinstance(d[0], dict):
        return d[0].get('xrefs', [])
    return []
def name_at(ea):
    d = json.loads(call('entity_query', {'queries':{'kind':'names','min_addr':hex(ea),'max_addr':hex(ea+4),'count':5}}))
    if isinstance(d, list) and d:
        data = d[0].get('data', [])
        if data: return data[0].get('name')
    return None

bases = {}
for e in edges:
    bases.setdefault(e['td'], {'base': e['base'], 'edges': []})
    bases[e['td']]['edges'].append(e)

out = {'bases': {}, 'edges': []}
for td_s, info in bases.items():
    td = int(td_s, 16)
    # find COL: xrefs to TD; COL pTD field at col+0xC
    cols = []
    for x in xref_list(td):
        fa = int(x['addr'], 16) if isinstance(x.get('addr'), str) else x.get('addr')
        col = fa - 0xC
        try:
            f = [u32(col + 4*i) for i in range(5)]
            if f[3] == td and f[0] in (0,1) and col not in cols:
                cols.append(col)
        except Exception: pass
    rec = {'base': info['base'], 'td': td_s, 'cols': []}
    for col in cols:
        f = [u32(col + 4*i) for i in range(5)]
        chd = f[4]
        chd_fields = [u32(chd + 4*i) for i in range(4)] if chd else []
        # vtables referencing this col: xref at vtbl-4
        vts = []
        for x in xref_list(col):
            fa = int(x['addr'],16) if isinstance(x.get('addr'), str) else x.get('addr')
            nm = name_at(fa+4) or name_at(fa)
            vts.append({'ref': hex(fa), 'vtbl_guess': hex(fa+4), 'name': nm})
        rec['cols'].append({'col': hex(col), 'fields': [hex(v) for v in f],
                            'chd': hex(chd) if chd else None,
                            'chd_sig': hex(chd_fields[0]) if chd_fields else None,
                            'chd_num_bases': chd_fields[2] if chd_fields else None,
                            'vtbl_refs': vts})
        print(info['base'], 'COL', hex(col), 'chd', hex(chd), 'nb', chd_fields[2] if chd_fields else '?',
              'vtrefs', [(v['ref'], v['name']) for v in vts])
    if not cols:
        print(info['base'], 'NO COL FOUND for td', td_s)
    out['bases'][td_s] = rec

for e in edges:
    bcd = int(e['bcd'], 16)
    ptd = u32(bcd); ncont = u32(bcd+4); mdisp = u32(bcd+8); attrs = u32(bcd+0x14); bchd = u32(bcd+0x18)
    out['edges'].append({**e, 'bcd_ok': ptd == int(e['td'],16), 'bcd_num_contained': ncont,
                         'bcd_mdisp': mdisp, 'bcd_attrs': hex(attrs), 'bcd_chd': hex(bchd)})
json.dump(out, open(W + 'abase_disposition_raw.json','w'), indent=1)
print('done')
