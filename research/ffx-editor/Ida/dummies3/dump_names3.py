#!/usr/bin/env python3
# PROMOTED 2026-09-18 (lane Jarvis-TOOLS-REPAIR) from work/_dummies3/ (gitignored scratch).
# Origin: DUMMIES3 rename sweep 2026-09-17/18 (3,656/3,662 renames applied+verified,
#   doc docs/reverse/FFX_DUMMIES3_2026-09-17.md, CSVs docs/reverse/data/wave13/dummies3_*.csv).
# Promoted per WAVE-LEDGER recommendation: the authoritative post-rename verification
# method (names-index dump + per-addr reconcile) must live in research_tools/, not scratch.
# Requires the live idalib-mcp endpoint (IDA_MCP_URL, default 192.168.122.85:8745).
"""Dump authoritative addr->name map via entity_query(kind='names').

Sweep over every name matching the DUMMIES* rename namespaces (broad —
extra prior-pass matches are harmless; we only look up our 3,662 addrs).
NOTE: auto-generated dummy names (unk_/byte_/dbl_/...) are NOT in the names
index — a still-dummy addr shows as 'unnamed' here and is resolved by the
exact-addr phase of reconcile3.py / post-rename check of apply_pending3.py.

Output: names3_new.json ({addr_lower: name}).
"""
import json, sys, time
from mcpdrv import Mcp

m = Mcp()
PAGE = 300          # server cap with regex is between 300 and 499
NEW_RE = r'^(g_|kDbl_|kXMM_|kU64_|kU8|kF80_|pTo|pRva|pStr|pToLoc)'


def sweep(regex, out_path):
    out = {}
    off = 0
    while True:
        r = None
        last = None
        for attempt in range(6):
            try:
                r = m.call('entity_query', {'queries': [{
                    'kind': 'names', 'regex': regex,
                    'offset': off, 'count': PAGE}]})
                break
            except Exception as e:
                last = e
                sys.stderr.write(f'  query retry {attempt+1} @{off}: {e}\n')
                time.sleep(8 * (attempt + 1))
        if r is None:
            raise last
        d = r[0] if isinstance(r, list) else r
        if not isinstance(d, dict):
            raise RuntimeError(f'bad page @{off}: {str(r)[:200]}')
        if d.get('error'):
            raise RuntimeError(f"query error @{off}: {d['error']}")
        data = d.get('data') or []
        for it in data:
            out[it['addr'].lower()] = it['name']
        nxt = d.get('next_offset')
        sys.stderr.write(f'{out_path}: {len(out)} names '
                         f'(page {len(data)} @{off}, next={nxt}, '
                         f'total={d.get("total")})\n')
        json.dump(out, open(out_path, 'w'))
        if nxt is None or not data:
            break
        off = nxt
        time.sleep(0.3)
    return out


if __name__ == '__main__':
    n = sweep(NEW_RE, 'names3_new.json')
    print('new-space names:', len(n))
