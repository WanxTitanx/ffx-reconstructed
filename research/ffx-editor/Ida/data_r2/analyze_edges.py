#!/usr/bin/env python3
"""analyze_edges.py — for each of the 26 abstract-base edges, resolve the base's
own CHD (via BCD+0x18), then find whether ANY vftable section references that
CHD via a COL (=> emitted vtable for the base, possibly embedded in another
class's blob). Output: edge_evidence.json"""
import sys, json, struct, time
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post

W = '/home/wanderson/Documents/ffx-editor-main/work/_data_r2/'
edges = json.load(open(W + 'abstract_edges.json'))

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
            if isinstance(r, dict) and 'content' in r:
                return r['content'][0]['text']
            return json.dumps(r)
        except Exception as e:
            if i == tries - 1:
                return json.dumps({'error': str(e)})
            time.sleep(2)

_raw_cache = {}
def raw(a, n):
    key = (a, n)
    if key in _raw_cache:
        return _raw_cache[key]
    d = json.loads(call('get_bytes', {'regions': [{'addr': hex(a), 'size': n}]}))
    hexs = d[0]['data']
    if isinstance(hexs, str):
        b = bytes(int(t, 16) for t in hexs.replace('0x', '').split())
    else:
        b = bytes(hexs)
    _raw_cache[key] = b
    return b

def dw(a, n):
    return list(struct.unpack('<%dI' % n, raw(a, n * 4)))

def dword(a):
    return dw(a, 1)[0]

def xrefs(a):
    d = json.loads(call('xrefs_to', {'addrs': [hex(a)], 'limit': 200}))
    return d[0].get('xrefs', []) if d else []

def name_at(a):
    d = json.loads(call('entity_query', {'queries': {'kind': 'names',
                        'min_addr': hex(a), 'max_addr': hex(a), 'count': 1}}))
    try:
        return d[0]['data'][0]['name']
    except Exception:
        return None

def is_col_at(site):  # site = address of pCHD field inside a COL => col = site-0x10
    col = site - 0x10
    try:
        c = dw(col, 5)
    except Exception:
        return None
    sig, off, cd, ptd, pchd = c
    if sig in (0, 1) and cd in (0,) and 0xB00000 <= ptd <= 0x1000000 and pchd == col_target:
        return {'col': col, 'off': off, 'td': ptd}
    # cdOffset may be nonzero on x64, accept small vals
    if sig in (0, 1) and 0 <= cd <= 0x100 and 0xB00000 <= ptd <= 0x1000000 and pchd == col_target:
        return {'col': col, 'off': off, 'td': ptd}
    return None

results = []
base_cache = {}
for e in edges:
    td = int(e['td'], 16)
    bcd = int(e['bcd'], 16)
    key = (td, e['base'])
    if key not in base_cache:
        base_chd = dword(bcd + 0x18)
        # parse base CHD
        chd = dw(base_chd, 4)
        n_bases = chd[2]
        r2 = chd[3]
        chain = []
        try:
            for bp in dw(r2, n_bases):
                b = dw(bp, 7)
                chain.append({'bcd': hex(bp), 'td': hex(b[0]),
                              'td_name': name_at(b[0]), 'mdisp': b[2],
                              'pdisp': b[3] if b[3] != 4294967295 else -1,
                              'vdisp': b[4], 'attr': hex(b[5]), 'pCHD': hex(b[6])})
        except Exception as ex:
            chain.append({'error': str(ex)})
        # xrefs to base CHD -> BCD sites (derived classes) vs COL sites (vftables)
        chd_xrefs = xrefs(base_chd)
        col_sites = []
        bcd_sites = []
        for x in chd_xrefs:
            s = int(x['addr'], 16)
            col_target = base_chd
            info = is_col_at(s)
            if info:
                col_sites.append(info)
            else:
                bcd_sites.append(hex(s))
        # for each COL, find vtbl sections referencing it
        vtbl_sections = []
        for cs in col_sites:
            for xx in xrefs(cs['col']):
                sx = int(xx['addr'], 16)
                vtbl_sections.append({'col': hex(cs['col']), 'col_off': cs['off'],
                                      'col_td': hex(cs['td']),
                                      'vtbl': hex(sx + 4),
                                      'vtbl_name': name_at(sx + 4)})
        base_cache[key] = {'base_chd': hex(base_chd), 'chd_raw': [hex(x) for x in chd],
                           'base_chain': chain, 'chd_xrefs': [x['addr'] for x in chd_xrefs],
                           'col_sites': col_sites, 'bcd_sites': bcd_sites,
                           'vtbl_sections': vtbl_sections,
                           'td_name': name_at(td)}
        print('base', e['base'], 'chd', hex(base_chd), 'xrefs', len(chd_xrefs),
              'cols', len(col_sites), 'vtbls', vtbl_sections, flush=True)
    r = dict(e)
    r.update(base_cache[key])
    results.append(r)

json.dump(results, open(W + 'edge_evidence.json', 'w'), indent=1)
print('WROTE', len(results))
