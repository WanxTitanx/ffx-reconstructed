#!/usr/bin/env python3
# PROMOTED 2026-09-18 (lane Jarvis-TOOLS-REPAIR) from work/_dummies3/ (gitignored scratch).
# Origin: DUMMIES3 rename sweep 2026-09-17/18 (3,656/3,662 renames applied+verified,
#   doc docs/reverse/FFX_DUMMIES3_2026-09-17.md, CSVs docs/reverse/data/wave13/dummies3_*.csv).
# Promoted per WAVE-LEDGER recommendation: the authoritative post-rename verification
# method (names-index dump + per-addr reconcile) must live in research_tools/, not scratch.
# Requires the live idalib-mcp endpoint (IDA_MCP_URL, default 192.168.122.85:8745).
"""Emit docs/reverse/data/wave13/dummies3_renames.csv + dummies3_verdicts.csv
from apply3_results.json + verdicts3.json + census data.
"""
import json, csv, os, collections

OUT = '/home/wanderson/Documents/ffx-editor-main/docs/reverse/data/wave13'
res = json.load(open('apply3_merged.json'))
verds = json.load(open('verdicts3.json'))
refs = json.load(open('unk_refs3b.json'))['targets']
old_plan = {p['addr'] for p in json.load(open('../_dummies2/unk_plan.json'))}

# ---------- renames.csv ----------
with open(f'{OUT}/dummies3_renames.csv', 'w', newline='') as f:
    w = csv.writer(f)
    w.writerow(['va', 'old', 'new', 'cls', 'confidence', 'evidence'])
    for r in sorted(res, key=lambda x: int(x['addr'], 16)):
        if r['ok']:
            w.writerow([r['addr'], r['old'], r['new'], r.get('cls'),
                        r.get('conf', ''), r.get('why')])
rows_ok = sum(1 for r in res if r['ok'])

# ---------- verdicts.csv ----------
vrows = []
# 1) individually adjudicated stays
for v in sorted(verds, key=lambda x: int(x['addr'], 16)):
    vrows.append([v['addr'], v['old'], v.get('cls'), 'stays', v['why']])
# 1b) plan items that could NOT take our name
for r in sorted(res, key=lambda x: int(x['addr'], 16)):
    if r['ok']:
        continue
    st = r.get('status', '?')
    if st == 'other-name':
        why = (f"addr already bound to a different name "
               f"({r.get('actual')}) — left untouched (other lane/winner)")
    else:
        why = f"rename did not land ({st}); planned {r['new']}"
    vrows.append([r['addr'], r['old'], r.get('cls'), 'not-renamed', why])
# 2) unmapped comment-residue targets (below imagebase)
for a, t in refs.items():
    if int(a, 16) < 0x401000:
        vrows.append([a, f'unk_{int(a,16):X}', 'UNMAPPED', 'stays',
                      'addr below imagebase — appears only inside '
                      'DEFINE-FUNC-SWEEP comment text; no live item'])
# 3) remaining still-dummy unk_ below the gate (single-code-hit names that
#    were never candidates), and comment-only residue names
seen = {v['addr'] for v in verds} | {r['addr'] for r in res}
for a, t in refs.items():
    if a in seen or int(a, 16) < 0x401000:
        continue
    nm = f'unk_{int(a,16):X}'
    if t['code_hits'] == 0:
        cls = 'RENAMED-ELSEWHERE' if a in old_plan else 'COMMENT-RESIDUE'
        why = ('old name lingers only in comments — item already renamed'
               if a in old_plan else
               'name occurs only inside comment text — no live item to name')
    else:
        cls = 'UNK-LOW'
        why = f'{t["code_hits"]} live operand ref(s) — below the >=2 honest gate'
    vrows.append([a, nm, cls, 'stays', why])
with open(f'{OUT}/dummies3_verdicts.csv', 'w', newline='') as f:
    w = csv.writer(f)
    w.writerow(['va', 'old', 'cls', 'verdict', 'why'])
    w.writerows(vrows)
print('renames ok:', rows_ok, '/', len(res))
print('verdict rows:', len(vrows))
print(collections.Counter(v[2] for v in vrows).most_common())
