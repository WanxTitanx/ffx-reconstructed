#!/usr/bin/env python3
"""stru-lift s1: fresh census of `stru_*` dummy-named data definitions.

Scans the rendered listing (.idata/.rdata/.data/.rodata/_RDATA) for
`stru_<HEX>` labels that are the head's own name, via mcpdrv.scan_pattern
(adaptive subdivision). Output: stru_census.json {name: {addr, seg, line}}.
"""
import json, re, sys, os, collections
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', '..',
                                'research_tools', 'Ida', 'global_names'))
from mcpdrv import Mcp, scan_pattern

PAT = r'\bstru_[0-9A-Fa-f]+\b'
NAME_RE = re.compile(PAT)
# same segment map as leva-8 global-names scan
SEGS = [('.idata', 0xB0C000, 0xB0C8C0), ('.rdata', 0xB0C8C0, 0xC0A000),
        ('.data', 0xC0A000, 0x25D7000), ('.rodata', 0x25D7000, 0x25D8000),
        ('_RDATA', 0x25D8000, 0x25D9000)]

m = Mcp()
defs = {}
for seg, s, e in SEGS:
    hits = scan_pattern(m, PAT, s, e, code_only=False, include='disasm')
    sys.stderr.write(f'{seg}: {len(hits)} raw hits\n')
    for h in hits:
        for mt in h.get('matches', []):
            txt = mt.get('text', '')
            for nm in NAME_RE.findall(txt):
                try:
                    if int(nm.split('_', 1)[1], 16) != int(h['addr'], 16):
                        continue
                except Exception:
                    continue
                if nm not in defs:
                    defs[nm] = {'addr': h['addr'], 'seg': h.get('segment', seg),
                                'line': txt.strip()}

per_seg = collections.Counter(v['seg'] for v in defs.values())
per_typ = collections.Counter()
for nm, v in defs.items():
    mm = re.search(re.escape(nm) + r'\s+(\S+)', v['line'])
    per_typ[mm.group(1) if mm else '?'] += 1

out = {'total': len(defs), 'per_seg': dict(per_seg), 'per_typ': dict(per_typ),
       'defs': {k: v for k, v in sorted(defs.items(),
                                        key=lambda kv: int(kv[1]['addr'], 16))}}
with open(os.path.join(os.path.dirname(__file__), 'stru_census.json'), 'w') as f:
    json.dump(out, f, indent=0)
print(json.dumps({'total': len(defs), 'per_seg': dict(per_seg),
                  'per_typ': dict(per_typ)}, indent=1))
