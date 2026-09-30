#!/usr/bin/env python3
"""Phase A: scan all of .text for references to dummy-named data items
(dword_*, byte_*, word_*, unk_*, off_*, ...) and tally per-target counts +
referencing functions."""
import json, re, sys, collections
from mcpdrv import Mcp, scan_pattern

PAT = r'(?:dword|byte|word|unk|off|dbl|flt|stru|qword|xmmword|ymmword)_[0-9A-Fa-f]+'
NAME_RE = re.compile(r'\b((?:dword|byte|word|unk|off|dbl|flt|stru|qword|xmmword|ymmword)_[0-9A-Fa-f]+)\b')

m = Mcp()
hits = scan_pattern(m, PAT, 0x401000, 0xB0C000, code_only=True)
print(f'total instruction hits: {len(hits)}', file=sys.stderr)

refs = collections.defaultdict(list)   # name -> [(insn_addr, func)]
for h in hits:
    fn = h.get('function') or '?'
    for mt in h.get('matches', []):
        txt = mt.get('text', '')
        for nm in NAME_RE.findall(txt):
            refs[nm].append((h['addr'], fn))

items = sorted(refs.items(), key=lambda kv: -len(kv[1]))
out = {
    'total_hits': len(hits),
    'unique_names': len(items),
    'ranked': [
        {'name': nm, 'code_refs': len(v),
         'addr': '0x' + nm.split('_', 1)[1].upper(),
         'funcs': sorted({f for _, f in v}),
         'sites': v[:60]}
        for nm, v in items],
}
with open('code_refs.json', 'w') as f:
    json.dump(out, f, indent=0)
print(f'unique dummy-named targets referenced from code: {len(items)}', file=sys.stderr)
for nm, v in items[:40]:
    print(f'{len(v):5d}  {nm}  funcs={len(set(f for _,f in v))}', file=sys.stderr)
