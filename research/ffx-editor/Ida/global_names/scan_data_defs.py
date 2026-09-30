#!/usr/bin/env python3
"""Phase B: scan data segments (.idata .rdata .data .rodata _RDATA) for
dummy-named item DEFINITIONS -> total unnamed census by prefix."""
import json, re, sys, collections
from mcpdrv import Mcp, scan_pattern

PAT = r'\b((?:dword|byte|word|unk|off|dbl|flt|stru|qword|xmmword|ymmword|tbyte|asc)_[0-9A-Fa-f]+)\b'
NAME_RE = re.compile(PAT)
SEGS = [('.idata', 0xB0C000, 0xB0C8C0), ('.rdata', 0xB0C8C0, 0xC0A000),
        ('.data', 0xC0A000, 0x25D7000), ('.rodata', 0x25D7000, 0x25D8000),
        ('_RDATA', 0x25D8000, 0x25D9000)]

m = Mcp()
defs = {}            # name -> (addr, seg, rendered)
per_seg = collections.Counter()
per_pref = collections.Counter()
for seg, s, e in SEGS:
    hits = scan_pattern(m, PAT, s, e, code_only=False, include='disasm')
    sys.stderr.write(f'{seg}: {len(hits)} raw hits\n')
    for h in hits:
        for mt in h.get('matches', []):
            txt = mt.get('text', '')
            for nm in NAME_RE.findall(txt):
                # keep only true label definitions: the dummy suffix is the
                # head's own address ("dword_C8A538 dd 5Dh" at 0xC8A538).
                try:
                    if int(nm.split('_', 1)[1], 16) != int(h['addr'], 16):
                        continue
                except Exception:
                    continue
                if nm not in defs:
                    defs[nm] = (h['addr'], h.get('segment', seg), txt.strip())
    sys.stderr.write(f'{seg} cumulative unique: {len(defs)}\n')

for nm, (a, seg, txt) in defs.items():
    per_seg[seg] += 1
    per_pref[nm.split('_', 1)[0]] += 1

out = {
    'total_unique_defs': len(defs),
    'per_segment': dict(per_seg),
    'per_prefix': dict(per_pref),
    'defs': {nm: {'addr': a, 'seg': seg, 'line': txt}
             for nm, (a, seg, txt) in sorted(defs.items(),
                                           key=lambda kv: int(kv[0].split('_', 1)[1], 16))},
}
with open('data_defs.json', 'w') as f:
    json.dump(out, f, indent=0)
print(json.dumps({'total': len(defs), 'per_seg': dict(per_seg), 'per_pref': dict(per_pref)}, indent=1))
