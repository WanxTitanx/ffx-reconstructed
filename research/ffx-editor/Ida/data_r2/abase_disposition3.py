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
        except Exception:
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
        return d[0].get('xrefs', []), d[0].get('more', False)
    return [], False
def name_at(ea):
    d = json.loads(call('entity_query', {'queries':{'kind':'names','min_addr':hex(ea),'max_addr':hex(ea+4),'count':5}}))
    if isinstance(d, list) and d:
        data = d[0].get('data', [])
        if data: return data[0].get('name')
    return None
IMG = 0x400000
RDATA_MAX = 0xD00000  # rdata region approx

bases = {}
for e in edges:
    bases.setdefault(e['td'], {'base': e['base'], 'edges': []})
    bases[e['td']]['edges'].append(e)

out = {'bases': {}, 'edges': []}
for td_s, info in bases.items():
    td = int(td_s, 16)
    xrefs, more = xref_list(td)
    cols, bcds, other = [], [], []
    for x in xrefs:
        fa = int(x['addr'],16) if isinstance(x.get('addr'), str) else x.get('addr')
        v = u32(fa+4)
        if v >= IMG:  # COL candidate: fa = col+0xC, col+0x10 = chd ptr
            col = fa - 0xC
            f = [u32(col+4*i) for i in range(5)]
            if f[3] == td and f[0] == 0 and IMG <= f[4] < RDATA_MAX:
                cols.append(col); continue
        # BCD candidate: fa = bcd+0; check pdisp/vdisp pattern and pCHD at +0x18
        f = [u32(fa+4*i) for i in range(7)]
        if f[0] == td and f[3] == 0xFFFFFFFF and IMG <= f[6] < RDATA_MAX:
            bcds.append({'bcd': hex(fa), 'num_contained': f[1], 'mdisp': f[2],
                         'attrs': hex(f[5]), 'chd': hex(f[6])})
        else:
            other.append({'addr': hex(fa), 'f1': hex(f[1]), 'f6': hex(f[6])})
    rec = {'base': info['base'], 'td': td_s, 'cols': [], 'bcd_refs': bcds, 'other_refs': other, 'more': more}
    for col in cols:
        f = [u32(col+4*i) for i in range(5)]
        chd = f[4]
        chd_f = [u32(chd+4*i) for i in range(4)] if IMG <= chd < RDATA_MAX else []
        vts = []
        xr2, _ = xref_list(col)
        for x in xr2:
            fa = int(x['addr'],16) if isinstance(x.get('addr'), str) else x.get('addr')
            nm = name_at(fa+4) or name_at(fa)
            # vtable sits at fa+4; check first slot is code ptr
            first = u32(fa+4)
            is_code = IMG <= first < 0xB00000
            vts.append({'ref': hex(fa), 'vtbl_addr': hex(fa+4), 'name': nm, 'first_slot': hex(first), 'code_ptr': is_code})
        rec['cols'].append({'col': hex(col), 'fields': [hex(v) for v in f],
                            'chd': hex(chd), 'chd_num_bases': chd_f[2] if chd_f else None,
                            'vtbl_refs': vts})
        print(info['base'], 'REAL COL', hex(col), 'chd', hex(chd), 'nb', chd_f[2] if chd_f else '?',
              'vt', [(v['vtbl_addr'], v['name'], v['code_ptr']) for v in vts])
    print(info['base'], td_s, '| cols:', len(cols), 'bcds:', len(bcds), 'other:', other, 'more:', more)
    out['bases'][td_s] = rec

for e in edges:
    bcd = int(e['bcd'], 16)
    f = [u32(bcd+4*i) for i in range(7)]
    out['edges'].append({**e, 'bcd_ok': f[0] == int(e['td'],16), 'bcd_num_contained': f[1],
                         'bcd_mdisp': f[2], 'bcd_pdisp': hex(f[3]), 'bcd_attrs': hex(f[5]),
                         'bcd_chd': hex(f[6])})
json.dump(out, open(W + 'abase_disposition_raw.json','w'), indent=1)
print('DONE bases:', len(out['bases']), 'edges:', len(out['edges']))
