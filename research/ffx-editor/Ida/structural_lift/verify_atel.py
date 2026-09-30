#!/usr/bin/env python3
"""Cross-check every FFX_Atel*_structural name against the funcspace tables."""
import json, re, collections

OUT = '/home/wanderson/Documents/ffx-editor-main/work/_structural_lift'

profs = [json.loads(l) for l in open(f'{OUT}/profiles.jsonl')]
tables = json.load(open(f'{OUT}/atel_tables_dump.json'))
catalog = {int(k): v for k, v in json.load(open(f'{OUT}/atel_callname_catalog.json')).items()}

NS2FAM = {0:'Common',1:'Math',4:'SgEvent',5:'ChEvent',6:'Camera',7:'Battle',
          8:'Map',9:'Mount',0xB:'Movie',0xC:'Debug',0xD:'AbilityMap'}
FAM2NS = {v:k for k,v in NS2FAM.items()}
# bounded entries (Movie physical extent = 137; Mount/AbilityMap declared=1)
BOUNDS = {'Common':616,'Math':30,'SgEvent':71,'ChEvent':145,'Camera':138,
          'Battle':296,'Map':108,'Mount':1,'Movie':137,'Debug':94,'AbilityMap':1}
SLOTS = ['CALL','STATUS','FLOATRET','INTRET']

# build ptr -> [(ns,idx,slot)] within bounds
ptr_map = collections.defaultdict(list)
for key, t in tables.items():
    ns = int(key.split('_')[0], 16)
    fam = NS2FAM[ns]
    for i, e in enumerate(t['entries'][:BOUNDS[fam]]):
        for si, v in enumerate(e):
            v = int(v, 16)
            if v and 0x401000 <= v < 0xC00000:
                ptr_map[v].append((ns, i, SLOTS[si]))

NAME_RE = re.compile(
    r'^FFX_Atel_(?P<ns>[A-Za-z0-9]+)_(?P<op>.+?)_'
    r'(?P<slot>CALLPOPA|CALL|STATUS|FLOATRET|INTRET|SLOT08)'
    r'(?P<noop>_noop)?_structural$')
FUNC_RE = re.compile(r'^Func([0-9A-Fa-f]{4})$')

report = []
for p in profs:
    name = p['name']
    if not name.startswith('FFX_Atel_'):
        continue
    addr = int(p['addr'], 16)
    m = NAME_RE.match(name)
    actual = ptr_map.get(addr, [])
    row = {'addr': p['addr'], 'name': name, 'actual': actual}
    if not m:
        row['verdict'] = 'UNPARSED'
        report.append(row); continue
    ns_name, op, slot = m.group('ns'), m.group('op'), m.group('slot')
    row.update(ns=ns_name, op=op, slot=slot)
    if not actual:
        row['verdict'] = 'NOT_IN_TABLE'
        report.append(row); continue
    # does any actual entry match the claimed namespace+slot?
    ns_ok = [a for a in actual if NS2FAM[a[0]] == ns_name]
    slot_norm = {'CALLPOPA':'CALL','SLOT08':'FLOATRET'}.get(slot, slot)
    slot_ok = [a for a in ns_ok if a[2] == slot_norm or (slot=='CALLPOPA' and a[2]=='CALL')]
    row['ns_match'] = bool(ns_ok)
    row['slot_match'] = bool(slot_ok)
    fm = FUNC_RE.match(op)
    if fm:
        claimed_id = int(fm.group(1), 16)
        row['claimed_funcid'] = hex(claimed_id)
        id_ok = [a for a in slot_ok if ((a[0]<<12)|a[1]) == claimed_id]
        row['funcid_match'] = bool(id_ok)
        row['verdict'] = 'VERIFIED_POS' if (ns_ok and slot_ok and id_ok) else 'MISMATCH'
    else:
        # named op: verify against catalog where possible
        if ns_ok:
            funcid = (ns_ok[0][0]<<12) | ns_ok[0][1]
            row['actual_funcid'] = hex(funcid)
            cat = catalog.get(funcid)
            if cat:
                # case-insensitive compare, tolerate Btl prefix differences
                a = re.sub(r'[^a-z0-9]', '', op.lower())
                b = re.sub(r'[^a-z0-9]', '', cat['name'].lower())
                row['catalog_name'] = cat['name']
                row['catalog_match'] = (a == b) or a.endswith(b) or b.endswith(a)
                row['verdict'] = 'VERIFIED_NAMED' if (slot_ok and row['catalog_match']) else (
                                 'NAME_MISMATCH' if slot_ok else 'MISMATCH')
            else:
                row['verdict'] = 'POS_ONLY_NAMED' if slot_ok else 'MISMATCH'
        else:
            row['verdict'] = 'MISMATCH'
    report.append(row)

json.dump(report, open(f'{OUT}/atel_verify.json','w'), indent=1)
c = collections.Counter(r['verdict'] for r in report)
print(c)
print('\n=== MISMATCH / NOT_IN_TABLE / UNPARSED ===')
for r in report:
    if r['verdict'] in ('MISMATCH','NOT_IN_TABLE','UNPARSED','NAME_MISMATCH'):
        print(f"{r['verdict']:14s} {r['addr']} {r['name'][:65]} -> {r.get('actual')}")
