#!/usr/bin/env python3
# PROMOTED 2026-09-18 (lane Jarvis-TOOLS-REPAIR) from work/_dummies3/ (gitignored scratch).
# Origin: DUMMIES3 rename sweep 2026-09-17/18 (3,656/3,662 renames applied+verified,
#   doc docs/reverse/FFX_DUMMIES3_2026-09-17.md, CSVs docs/reverse/data/wave13/dummies3_*.csv).
# Promoted per WAVE-LEDGER recommendation: the authoritative post-rename verification
# method (names-index dump + per-addr reconcile) must live in research_tools/, not scratch.
# Requires the live idalib-mcp endpoint (IDA_MCP_URL, default 192.168.122.85:8745).
"""Authoritative per-address reconciliation of the DUMMIES3 plan.

For each of the 3662 plan items, look up the name actually bound to the
address in the names index (names3_new.json + names3_old.json, produced by
dump_names3.py). Statuses:

  ok            name[addr] == planned new (or the _<ADDR> collision variant)
  still-dummy   name[addr] == old dummy name          -> needs rename
  unnamed       addr has no indexed name              -> needs investigation
  other-name    addr bound to a different name        -> adjudicate (other
                lane / pre-existing name; do NOT overwrite blindly)

For 'unnamed'/'other-name' items a precise entity_query bounded to the exact
addr resolves what name (if any) is really there.

Outputs: reconcile3.json ({old: {status, actual, ...}}),
         pending3.json (plan items still needing a rename).
"""
import json, sys, time
from mcpdrv import Mcp

m = Mcp()
plan = json.load(open('rename_plan3.json'))
names = {}
for f in ('names3_new.json', 'names3_old.json'):
    try:
        for a, n in json.load(open(f)).items():
            names[a.lower()] = n
    except FileNotFoundError:
        sys.stderr.write(f'warning: {f} missing\n')

suff = lambda p: f"{p['new']}_{int(p['addr'],16):X}"
rec = {}
pending = []
for p in plan:
    a = p['addr'].lower()
    actual = names.get(a)
    if actual in (p['new'], suff(p)):
        rec[p['old']] = {'status': 'ok', 'actual': actual, 'addr': a}
    elif actual == p['old']:
        rec[p['old']] = {'status': 'still-dummy', 'actual': actual, 'addr': a}
        pending.append(p)
    elif actual is None:
        rec[p['old']] = {'status': 'unnamed', 'actual': None, 'addr': a}
    else:
        rec[p['old']] = {'status': 'other-name', 'actual': actual, 'addr': a}

# Phase 2: resolve 'unnamed' items — query the exact address for any name.
un = [o for o, r in rec.items() if r['status'] == 'unnamed']
sys.stderr.write(f'phase2: resolving {len(un)} unnamed addrs\n')
pmap = {p['old']: p for p in plan}
for i in range(0, len(un), 8):
    grp = un[i:i + 8]
    queries = [{'kind': 'names', 'min_addr': rec[o]['addr'],
                'max_addr': rec[o]['addr'], 'count': 4} for o in grp]
    r = None
    for attempt in range(6):
        try:
            r = m.call('entity_query', {'queries': queries})
            break
        except Exception as e:
            sys.stderr.write(f'  p2 retry {attempt+1} @{i}: {e}\n')
            time.sleep(8 * (attempt + 1))
    if not isinstance(r, list):
        r = [r] if isinstance(r, dict) else []
    for o, d in zip(grp, r):
        data = d.get('data') if isinstance(d, dict) else None
        hit = None
        for it in (data or []):
            if it.get('addr', '').lower() == rec[o]['addr']:
                hit = it['name']
                break
        p = pmap[o]
        if hit is None:
            rec[o]['status'] = 'truly-unnamed'
            pending.append(p)
        elif hit == p['old']:
            rec[o]['status'] = 'still-dummy'
            rec[o]['actual'] = hit
            pending.append(p)
        elif hit in (p['new'], suff(p)):
            rec[o]['status'] = 'ok'
            rec[o]['actual'] = hit
        else:
            rec[o]['status'] = 'other-name'
            rec[o]['actual'] = hit
    sys.stderr.write(f'  p2 {i + len(grp)}/{len(un)}\n')
    json.dump(rec, open('reconcile3.json', 'w'), indent=0)

json.dump(rec, open('reconcile3.json', 'w'), indent=0)
json.dump(pending, open('pending3.json', 'w'), indent=0)
import collections
c = collections.Counter(r['status'] for r in rec.values())
print(json.dumps(c.most_common(), indent=1))
print('pending rename:', len(pending))
