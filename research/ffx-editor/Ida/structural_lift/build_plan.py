#!/usr/bin/env python3
"""Build the full rename manifest for the structural-lift pass."""
import json, re, collections

OUT = '/home/wanderson/Documents/ffx-editor-main/work/_structural_lift'

profs = {p['addr']: p for p in (json.loads(l) for l in open(f'{OUT}/profiles.jsonl'))}
tables = json.load(open(f'{OUT}/atel_tables_dump.json'))
catalog = {int(k): v for k, v in json.load(open(f'{OUT}/atel_callname_catalog.json')).items()}
fh = json.load(open(f'{OUT}/fahrenheit_delegates.json'))
cam_list = fh.get('6', [])

NS2FAM = {0:'Common',1:'Math',4:'SgEvent',5:'ChEvent',6:'Camera',7:'Battle',
          8:'Map',9:'Mount',0xB:'Movie',0xC:'Debug',0xD:'AbilityMap'}
FAM2NS = {v:k for k,v in NS2FAM.items()}
BOUNDS = {'Common':616,'Math':30,'SgEvent':71,'ChEvent':145,'Camera':138,
          'Battle':296,'Map':108,'Mount':1,'Movie':137,'Debug':94,'AbilityMap':1}
SLOTS = ['CALL','STATUS','FLOATRET','INTRET']

ptr_map = collections.defaultdict(list)
for key, t in tables.items():
    ns = int(key.split('_')[0], 16); fam = NS2FAM[ns]
    for i, e in enumerate(t['entries'][:BOUNDS[fam]]):
        for si, v in enumerate(e):
            v = int(v, 16)
            if v and 0x401000 <= v < 0xC00000:
                ptr_map[v].append((ns, i, SLOTS[si]))

NAME_RE = re.compile(r'^FFX_Atel_(?P<ns>[A-Za-z0-9]+)_(?P<op>.+?)_'
                     r'(?P<slot>CALLPOPA|CALL|STATUS|FLOATRET|INTRET|SLOT08)'
                     r'(?P<noop>_noop)?_structural$')
FUNC_RE = re.compile(r'^Func([0-9A-Fa-f]{4})$')

def pascal(s):
    return s[:1].upper() + s[1:] if s else s

def norm(s):
    return re.sub(r'[^a-z0-9]', '', s.lower())

plan = []   # (addr, old, new, evidence, kind)
specials = []  # handled by hand

for p in profs.values():
    name = p['name']
    if not name.endswith('_structural'):
        continue
    addr = int(p['addr'], 16)
    m = NAME_RE.match(name)
    if m:  # FFX_Atel_<ns>_<op>_<slot>_structural
        ns_name, op, slot, noop = m.group('ns'), m.group('op'), m.group('slot'), m.group('noop') or ''
        actual = ptr_map.get(addr, [])
        if not actual:
            specials.append(('NOT_IN_TABLE', p)); continue
        ns_list = [a for a in actual if NS2FAM[a[0]] == ns_name]
        if not ns_list:
            specials.append(('NS_MISMATCH', p, actual)); continue
        ans, aidx, aslot = ns_list[0]
        funcid = (ans << 12) | aidx
        fm = FUNC_RE.match(op)
        claimed_id = int(fm.group(1), 16) if fm else None
        claimed_slot = {'CALLPOPA':'CALL','SLOT08':'FLOATRET'}.get(slot, slot)
        if fm:
            # positional name: funcId+slot must match; keep CALLPOPA tag if slot0 & id ok
            if claimed_id == funcid and claimed_slot == aslot:
                tail = 'CALLPOPA' if slot == 'CALLPOPA' else aslot
                new = f'FFX_Atel_{ns_name}_Func{funcid:04X}_{tail}{noop}'
                if new == name[:-11]:
                    plan.append((p['addr'], name, new, f'funcspace-table {ns_name}[0x{aidx:X}].{aslot} (funcId 0x{funcid:04X})', 'ATEL_POS_VERIFIED'))
                else:
                    plan.append((p['addr'], name, new, f'funcspace-table {ns_name}[0x{aidx:X}].{aslot}; slot-normalized {slot}->{aslot}', 'ATEL_POS_VERIFIED_FIXSLOT'))
            else:
                # funcId or slot wrong -> correct positional name
                new = f'FFX_Atel_{ns_name}_Func{funcid:04X}_{aslot}{noop}'
                plan.append((p['addr'], name, new,
                             f'funcspace-table {ns_name}[0x{aidx:X}].{aslot} (funcId 0x{funcid:04X}); was mislabeled Func{claimed_id:04X}_{slot}',
                             'ATEL_POS_MISLABEL'))
        else:
            # named op
            cat = catalog.get(funcid)
            fhname = cam_list[aidx] if ans == 6 and aidx < len(cam_list) else None
            matched_src = None
            if cat and (norm(cat['name']) == norm(op) or norm(op).endswith(norm(cat['name'])) or norm(cat['name']).endswith(norm(op))):
                matched_src = f'AiCallNameCatalog[{hex(funcid)}]="{cat["name"]}"'
            elif fhname and (norm(fhname) == norm(op) or norm(op) == norm(fhname) or norm(op).endswith(norm(fhname))):
                matched_src = f'fahrenheit cam[{aidx}]="{fhname}"'
            if matched_src:
                new = f'FFX_Atel_{ns_name}_{op}_{aslot}{noop}'
                plan.append((p['addr'], name, new,
                             f'funcspace {ns_name}[0x{aidx:X}].{aslot} + {matched_src}; slot-fix {slot}->{aslot}' if claimed_slot != aslot else
                             f'funcspace {ns_name}[0x{aidx:X}].{aslot} + {matched_src}',
                             'ATEL_NAMED_VERIFIED'))
            elif cat:
                new = f'FFX_Atel_{ns_name}_{pascal(cat["name"])}_{aslot}{noop}'
                plan.append((p['addr'], name, new,
                             f'funcspace {ns_name}[0x{aidx:X}].{aslot}; op-name corrected to catalog "{cat["name"]}" (was "{op}")',
                             'ATEL_NAMED_CATFIX'))
            elif fhname:
                new = f'FFX_Atel_{ns_name}_{pascal(fhname)}_{aslot}{noop}'
                plan.append((p['addr'], name, new,
                             f'funcspace {ns_name}[0x{aidx:X}].{aslot}; op-name corrected to fahrenheit "{fhname}" (was "{op}")',
                             'ATEL_NAMED_FHFIX'))
            else:
                new = f'FFX_Atel_{ns_name}_Func{funcid:04X}_{aslot}{noop}'
                plan.append((p['addr'], name, new,
                             f'funcspace {ns_name}[0x{aidx:X}].{aslot}; unverifiable op-name "{op}" demoted to positional',
                             'ATEL_NAMED_DEMOTE'))
        continue
    specials.append(('NON_ATEL', p))

json.dump(plan, open(f'{OUT}/rename_plan_atel.json', 'w'), indent=1)
c = collections.Counter(k for *_ , k in plan)
print(c, 'specials:', collections.Counter(s[0] for s in specials))
for s in specials:
    print('  SPECIAL', s[0], s[1]['addr'], s[1]['name'], s[2] if len(s) > 2 else '')
# sanity: any duplicate target names?
names = [n for _,_,n,_,_ in plan]
dups = [n for n, c in collections.Counter(names).items() if c > 1]
print('dup final names:', dups[:20], len(dups))
