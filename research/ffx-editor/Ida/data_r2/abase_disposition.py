#!/usr/bin/env python3
import sys, json, struct
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post
W = '/home/wanderson/Documents/ffx-editor-main/work/_data_r2/'
edges = json.load(open(W + 'abstract_edges.json'))
sess, _ = post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"abase","version":"1"}}})
post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
def call(tool, args):
    _, body = post({"jsonrpc":"2.0","id":2,"method":"tools/call","params":{"name":tool,"arguments":args}}, sess)
    d = json.loads(body); r = d.get('result', d)
    return r['content'][0]['text'] if isinstance(r, dict) and 'content' in r else json.dumps(r)
def rd(ea, n):
    t = call('get_bytes', {'regions':[{'addr': hex(ea), 'size': n}]})
    d = json.loads(t)
    if isinstance(d, list): d = d[0]
    data = d.get('data')
    if isinstance(data, str):
        return bytes(int(x, 16) for x in data.split())
    return bytes(data)
def u32(ea): return struct.unpack('<I', rd(ea,4))[0]
def xrefs(ea):
    t = call('xrefs_to', {'addrs': hex(ea), 'limit': 50})
    try:
        d = json.loads(t)
        if isinstance(d, list): d = d[0]
        return d.get('data', d)
    except Exception:
        return t

bases = {}
for e in edges:
    bases.setdefault(e['td'], {'base': e['base'], 'edges': []})
    bases[e['td']]['edges'].append(e)

out = {'bases': {}, 'edges': []}
for td_s, info in bases.items():
    td = int(td_s, 16)
    col = td - 0xC
    col_fields = [u32(col + 4*i) for i in range(5)]
    col_ok = col_fields[3] == td
    chd = col_fields[4] if col_ok else 0
    chd_fields = [u32(chd + 4*i) for i in range(4)] if chd else []
    nbases = chd_fields[2] if chd_fields else 0
    bcd_arr = chd_fields[3] if chd_fields else 0
    # xrefs to col -> potential vtables (ref at vtbl-4)
    xr = xrefs(col)
    vtrefs = []
    if isinstance(xr, list) and xr and isinstance(xr[0], dict) and 'xrefs' in xr[0]:
        items = xr[0]['xrefs']
    elif isinstance(xr, dict):
        items = xr.get('xrefs', xr.get('items', []))
    else:
        items = xr if isinstance(xr, list) else []
    for x in items:
        fa = x.get('from') or x.get('from_addr') or x.get('addr')
        if fa is None: continue
        fa_i = int(fa, 16) if isinstance(fa, str) else fa
        # is fa+4 a vtable? check dword at fa == col and name near
        vtrefs.append(hex(fa_i))
    b = {'base': info['base'], 'td': td_s, 'col': hex(col), 'col_ok': col_ok,
         'col_fields': [hex(x) for x in col_fields], 'chd': hex(chd) if chd else None,
         'chd_num_bases': nbases, 'bcd_array': hex(bcd_arr) if bcd_arr else None,
         'xrefs_to_col': vtrefs, 'raw_xrefs': items if isinstance(items, list) else items}
    out['bases'][td_s] = b
    print(info['base'], 'col', hex(col), 'col_ok', col_ok, 'chd', hex(chd), 'nbases', nbases, 'xrefcol', vtrefs)

# per edge verify bcd pTD
for e in edges:
    bcd = int(e['bcd'], 16)
    ptd = u32(bcd)
    ncont = u32(bcd+4); mdisp = u32(bcd+8); attrs = u32(bcd+0x14)
    out['edges'].append({**e, 'bcd_ok': ptd == int(e['td'],16),
                         'bcd_num_contained': ncont, 'bcd_mdisp': mdisp, 'bcd_attrs': hex(attrs),
                         'bcd_chd': hex(u32(bcd+0x18))})
    if ptd != int(e['td'],16):
        print('BCD MISMATCH', e['bcd'], hex(ptd), e['td'])
json.dump(out, open(W + 'abase_disposition_raw.json','w'), indent=1)
print('done; bases:', len(out['bases']), 'edges:', len(out['edges']))
