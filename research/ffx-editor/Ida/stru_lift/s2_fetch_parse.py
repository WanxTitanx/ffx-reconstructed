#!/usr/bin/env python3
"""stru-lift s2: bulk-fetch .rdata bytes covering the stru_* population and
parse each item into its MSVC EH/RTTI structure fields.

Outputs:
  region.bin            raw bytes of [REG_LO, REG_HI)
  stru_parsed.json      name -> {addr, role, fields...}
"""
import json, re, sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', '..',
                                'research_tools', 'Ida', 'global_names'))
from mcpdrv import Mcp

HERE = os.path.dirname(os.path.abspath(__file__))
REG_LO, REG_HI = 0xBCB000, 0xC06000      # EH table region (stru census min/max)
ODD = (0xB0DFC0, 0xB0E040)               # oddball stru_B0E000 context
CHUNK = 0x10000

m = Mcp()
blob = {}
for lo, hi in [(REG_LO, REG_HI), ODD]:
    a = lo
    while a < hi:
        sz = min(CHUNK, hi - a)
        r = m.call('get_bytes', {'regions': [{'addr': hex(a), 'size': sz}]})
        regs = r['result'] if isinstance(r, dict) and 'result' in r else r
        reg = regs[0] if isinstance(regs, list) else regs
        bs = bytes(int(x, 16) for x in reg['data'].split())
        for i, b in enumerate(bs):
            blob[a + i] = b
        a += sz
        sys.stderr.write(f'fetched to {hex(a)}\n')

with open(os.path.join(HERE, 'region.bin'), 'wb') as f:
    f.write(bytes(blob[a] for a in range(REG_LO, REG_HI)))
with open(os.path.join(HERE, 'region_odd.bin'), 'wb') as f:
    f.write(bytes(blob[a] for a in range(ODD[0], ODD[1])))


def u32(addr):
    return int.from_bytes(bytes(blob.get(addr + i, 0) for i in range(4)),
                          'little')


census = json.load(open(os.path.join(HERE, 'stru_census.json')))
parsed = {}
for nm, v in census['defs'].items():
    a = int(v['addr'], 16)
    line = v['line']
    mm = re.search(re.escape(nm) + r'\s+(\S+)', line)
    typ = mm.group(1) if mm else '?'
    rec = {'addr': hex(a), 'typ': typ, 'line': line}
    if typ == 'FuncInfo':
        f = [u32(a + 4 * i) for i in range(9)]
        rec.update(role='FuncInfo', magic=f[0], maxState=f[1],
                   pUnwindMap=f[2], nTryBlocks=f[3], pTryBlockMap=f[4],
                   nIPMap=f[5], pIPtoStateMap=f[6], dispUW=f[7], EHFlags=f[8])
    elif typ == 'UnwindMapEntry':
        rec.update(role='UnwindMapEntry', toState=u32(a), action=u32(a + 4))
    elif typ == 'TryBlockMapEntry':
        rec.update(role='TryBlockMapEntry', tryLow=u32(a), tryHigh=u32(a + 4),
                   catchHigh=u32(a + 8), nCatches=u32(a + 12),
                   pHandlerArray=u32(a + 16))
    elif typ == 'HandlerType':
        rec.update(role='HandlerType', adjectives=u32(a), pType=u32(a + 4),
                   dispCatchObj=u32(a + 8), handlerAddr=u32(a + 12))
    elif typ == '_EH4_SCOPETABLE':
        rec.update(role='EH4ScopeTable',
                   gsOff=u32(a), gsXor=u32(a + 4), ehOff=u32(a + 8),
                   ehXor=u32(a + 12))
    else:
        rec.update(role='OTHER')
    parsed[nm] = rec

with open(os.path.join(HERE, 'stru_parsed.json'), 'w') as f:
    json.dump(parsed, f, indent=0)

import collections
roles = collections.Counter(r['role'] for r in parsed.values())
magics = collections.Counter(r.get('magic') for r in parsed.values()
                           if r['role'] == 'FuncInfo')
print('roles:', dict(roles))
print('funcinfo magics:', dict(magics))
bad = [n for n, r in parsed.items() if r['role'] == 'FuncInfo'
       and r['magic'] != 0x19930522]
print('bad magic funcinfos:', len(bad), bad[:10])
