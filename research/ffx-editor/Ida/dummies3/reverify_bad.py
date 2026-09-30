#!/usr/bin/env python3
# PROMOTED 2026-09-18 (lane Jarvis-TOOLS-REPAIR) from work/_dummies3/ (gitignored scratch).
# Origin: DUMMIES3 rename sweep 2026-09-17/18 (3,656/3,662 renames applied+verified,
#   doc docs/reverse/FFX_DUMMIES3_2026-09-17.md, CSVs docs/reverse/data/wave13/dummies3_*.csv).
# Promoted per WAVE-LEDGER recommendation: the authoritative post-rename verification
# method (names-index dump + per-addr reconcile) must live in research_tools/, not scratch.
# Requires the live idalib-mcp endpoint (IDA_MCP_URL, default 192.168.122.85:8745).
"""Re-verify every not-ok item in apply3_results.json + apply3b_*.json —
the false-'preempted' case is a batch-level verify glitch, confirmed by
live listing. Small groups (10) for reliability under load.
Writes reverify3.json {old: landed_bool}.
"""
import json, re, sys, time, glob
from mcpdrv import Mcp

m = Mcp()
bad = []
for f in ['apply3_results.json'] + glob.glob('apply3b_*.json'):
    if glob.os.path.exists(f):
        for x in json.load(open(f)):
            if not x.get('ok'):
                bad.append(x)
# dedupe by old
seen = {}
for x in bad:
    seen[x['old']] = x
bad = list(seen.values())
sys.stderr.write(f're-verifying {len(bad)} not-ok items\n')
out = {}
if glob.os.path.exists('reverify3.json'):
    out = json.load(open('reverify3.json'))
todo = [x for x in bad if x['old'] not in out]
for i in range(0, len(todo), 10):
    grp = todo[i:i+10]
    news = [x['new'] for x in grp]
    olds = [x['old'] for x in grp]
    pat = r'\b(?:' + '|'.join(re.escape(n) for n in news + olds) + r')\b'
    r = None
    for attempt in range(6):
        try:
            r = m.call('search_text', {'pattern': pat, 'regex': True,
                                       'include': 'all', 'code_only': False,
                                       'start': '0x401000', 'end': '0x25D9000',
                                       'limit': 500})
            break
        except Exception as e:
            sys.stderr.write(f'  reverify retry {attempt+1}: {e}\n')
            time.sleep(8 * (attempt + 1))
    found = set()
    if isinstance(r, dict):
        for h in r.get('hits', []):
            for mt in h.get('matches', []):
                code = mt.get('text', '').split(';', 1)[0]
                for nm in news + olds:
                    if re.search(r'\b' + re.escape(nm) + r'\b', code):
                        found.add(nm)
    for x in grp:
        # landed iff new name rendered; still-dummy iff old name rendered
        out[x['old']] = 'landed' if x['new'] in found else (
            'still-dummy' if x['old'] in found else 'vanished')
    json.dump(out, open('reverify3.json', 'w'))
    sys.stderr.write(f'{i+len(grp)}/{len(todo)}\n')
import collections
print(json.dumps(collections.Counter(out.values()).most_common()))
