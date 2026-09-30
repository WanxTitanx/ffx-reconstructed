#!/usr/bin/env python3
"""stru-lift s6: cross-check work/_chd_inherit/hierarchy.json RTTI addrs
against live IDB names, and build role+class comments.

Roles by MSVC name convention: ??_R0=TypeDescriptor, ??_R4=COL,
??_R3=CHD, ??_R1=BCD, ??_R2=BCA. Class name demangled from the TD's own
mangled string (read from IDB bytes at td+8) via msvc_demangle.
"""
import json, re, sys, os, struct, collections
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', '..',
                                'research_tools', 'Ida'))
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', '..',
                                'research_tools', 'Ida', 'global_names'))
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', '..',
                                'research_tools', 'Ida', 'vtable_recon'))
from mcpdrv import Mcp
from msvc_demangle import demangle_type_desc

HERE = os.path.dirname(os.path.abspath(__file__))
h = json.load(open('/home/wanderson/Documents/ffx-editor-main/work/'
                   '_chd_inherit/hierarchy.json'))
addrs = json.load(open(os.path.join(HERE, 'rtti_addrs.json')))

m = Mcp()

# ---- 1. fetch names in the RTTI window --------------------------------
LO, HI = 0xB92000, 0xC3A000
name_map = {}   # addr_int -> name
W = 0x8000
a = LO
while a < HI:
    off = 0
    while True:
        r = m.call('entity_query', {'queries': [{
            'kind': 'names', 'min_addr': hex(a), 'max_addr': hex(a + W),
            'count': 1000, 'offset': off, 'fields': ['addr', 'name']}]})
        items = (r[0] if isinstance(r, list)
                 else (r['result'][0] if isinstance(r, dict)
                       and 'result' in r else r))
        data = items.get('data', [])
        for it in data:
            name_map[int(it['addr'], 16)] = it['name']
        off += len(data)
        if not data or off >= items.get('total', 0):
            break
    sys.stderr.write(f'names @{hex(a)}: total {items.get("total")} '
                     f'(cum {len(name_map)})\n')
    a += W
json.dump({hex(k): v for k, v in name_map.items()},
          open(os.path.join(HERE, 'rtti_names.json'), 'w'), indent=0)

# ---- 2. fetch COL bytes -> own TD (col+0x0C) ---------------------------
cols = sorted(int(x, 16) for x in addrs['col'])
col_td = {}
B = 200
for i in range(0, len(cols), B):
    regs = [{'addr': hex(c), 'size': 20} for c in cols[i:i + B]]
    r = m.call('get_bytes', {'regions': regs})
    items = r['result'] if isinstance(r, dict) and 'result' in r else r
    for reg in items:
        bs = bytes(int(x, 16) for x in reg['data'].split())
        col_td[int(reg['addr'], 16)] = struct.unpack_from('<I', bs, 12)[0]
    sys.stderr.write(f'col batch {i}\n')
own_tds = set(col_td.values())

# ---- 3. fetch TD name strings (td+8) -> demangle -----------------------
td_all = sorted({int(x, 16) for x in addrs['td']} | own_tds)
td_name = {}
for i in range(0, len(td_all), B):
    regs = [{'addr': hex(t + 8), 'size': 96} for t in td_all[i:i + B]]
    r = m.call('get_bytes', {'regions': regs})
    items = r['result'] if isinstance(r, dict) and 'result' in r else r
    for reg in items:
        bs = bytes(int(x, 16) for x in reg['data'].split())
        raw = bs.split(b'\0')[0]
        try:
            td_name[int(reg['addr'], 16) - 8] = raw.decode('ascii', 'replace')
        except Exception:
            td_name[int(reg['addr'], 16) - 8] = ''
    sys.stderr.write(f'td batch {i}\n')

# ---- 4. classify each hierarchy addr -----------------------------------
ROLE_OF_PREFIX = {'??_R0': 'TD', '??_R4': 'COL', '??_R3': 'CHD',
                  '??_R1': 'BCD', '??_R2': 'BCA', '??_7': 'VTABLE',
                  '??_6': 'VBTABLE'}
def role_of(name):
    for pre, role in ROLE_OF_PREFIX.items():
        if name.startswith(pre):
            return role
    return 'other'

checks = []   # {addr, expect, name, role_match, class}
def expect(addr_hex, expect_role, cls_hint=None):
    a = int(addr_hex, 16)
    nm = name_map.get(a)
    got = role_of(nm) if nm else None
    checks.append({'addr': addr_hex, 'expect': expect_role, 'name': nm,
                   'got': got,
                   'match': got == expect_role if nm else False,
                   'cls': cls_hint})

for vt, e in h.items():
    cls = e.get('class')
    if e.get('col'):
        expect(e['col'], 'COL', cls)
    if e.get('chd'):
        expect(e['chd'], 'CHD', cls)
    for bd in e.get('base_detail', []):
        if bd.get('bcd'):
            expect(bd['bcd'], 'BCD', bd.get('cls'))
        if bd.get('td'):
            expect(bd['td'], 'TD', bd.get('cls'))
    otd = col_td.get(int(e['col'], 16)) if e.get('col') else None
    if otd:
        expect(hex(otd), 'TD', cls)

stats = collections.Counter()
missing = [c for c in checks if not c['name']]
mismatch = [c for c in checks if c['name'] and not c['match']]
for c in checks:
    stats[(c['expect'], 'named' if c['name'] else 'MISSING',
           'ok' if c['match'] else 'BAD')] += 1

# ---- 5. comment plan ----------------------------------------------------
TAG = '[stru-lift 2026-09-16]'
comments = []
seen = set()
for c in checks:
    a = int(c['addr'], 16)
    if a in seen:
        continue
    seen.add(a)
    if not c['name']:
        continue
    # resolve class: for TD -> demangle own string; for COL/CHD -> cls hint;
    # for BCD -> demangle the BCD's TD string
    cls = c['cls']
    if c['expect'] == 'TD':
        mang = td_name.get(a, '')
        if mang.startswith('.?A') or mang.startswith('??_R0'):
            dm = demangle_type_desc(mang)
            if dm and dm != mang:
                cls = dm
    comments.append({'addr': c['addr'], 'name': c['name'],
                     'role': c['expect'],
                     'comment': f"// RTTI {c['expect']} for {cls} {TAG}"})

out = {'stats': {f'{k[0]}|{k[1]}|{k[2]}': v for k, v in stats.items()},
       'missing': missing, 'mismatch': mismatch,
       'checks': checks, 'comments': comments,
       'own_td_count': len(own_tds),
       'td_name_sample': {hex(t): td_name[t] for t in td_all[:20]}}
json.dump(out, open(os.path.join(HERE, 'rtti_xcheck.json'), 'w'), indent=0)
print('checks:', len(checks), 'missing:', len(missing),
      'mismatch:', len(mismatch))
print(json.dumps(out['stats'], indent=1))
for c in missing[:10]:
    print('MISSING', c)
for c in mismatch[:10]:
    print('MISMATCH', c)
