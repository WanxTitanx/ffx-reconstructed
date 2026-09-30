#!/usr/bin/env python3
"""stru-lift s4: build rename+comment plan for the stru_* EH population.

Linkage (all mechanically provable from parsed bytes):
  FuncInfo.code xref          -> owner function   (s3 owners.json)
  FuncInfo.pUnwindMap         -> UnwindMapEntry[] head label
  FuncInfo.pTryBlockMap       -> TryBlockMapEntry[] head label
  TryBlockMapEntry.pHandlerArray -> HandlerType[] head label
  EH4ScopeTable.code xref     -> owner function

Names: ehfi_/ehuw_/ehtb_/ehct_/ehsc_ + sanitized owner name.
Decorated owners (??_L etc.) demangled via llvm-undname -> sanitized suffix.
Orphans (entries inside arrays, not heads) attributed by address range.
"""
import json, re, sys, os, subprocess, collections
HERE = os.path.dirname(os.path.abspath(__file__))

p = json.load(open(os.path.join(HERE, 'stru_parsed.json')))
o = json.load(open(os.path.join(HERE, 'owners.json')))

SANE = re.compile(r'[^A-Za-z0-9_.$]')
def sane(s):
    s = SANE.sub('_', s)
    return re.sub(r'_+', '_', s).strip('_')


# llvm-undname echoes these back undecorated (they're non-type function
# encodings it refuses); provide known-correct demanglings for the 7
# decorated owner names in this DB.
KNOWN_DEMANGLES = {  # verified via llvm-undname 2026-09-16
    '??_L@YGXPAXIHP6EX0@Z1@Z': 'eh_vector_ctor_iter',
    '??_M@YGXPAXIHP6EX0@Z@Z': 'eh_vector_dtor_iter',
    '?__ArrayUnwind@@YGXPAXIHP6EX0@Z@Z': '__ArrayUnwind',
    '??2@YAPAXIABUnothrow_t@std@@@Z': 'operator_new_nothrow',
    '?_RunTask@_TaskCollectionImpl@details@Concurrency@@SAXP6AXPAX@Z0W4_TaskInliningMode@23@@Z':
        'Concurrency_details__TaskCollectionImpl__RunTask',
    '??0_TaskCollection@details@Concurrency@@QAE@XZ':
        'Concurrency_details__TaskCollection_ctor',
    '?CheckStaticConstruction@SchedulerBase@details@Concurrency@@CAXXZ':
        'Concurrency_details_SchedulerBase_CheckStaticConstruction',
}

def demangle_owner(name):
    """Decorated MSVC name -> readable suffix (hard table; only 7 in DB)."""
    if name.startswith('DEAD_') and name[5:] in KNOWN_DEMANGLES:
        return 'DEAD_' + KNOWN_DEMANGLES[name[5:]]
    return KNOWN_DEMANGLES.get(name, name)


# owner_name -> sanitized suffix (cached)
_suffix = {}
def owner_suffix(owner_name):
    if owner_name not in _suffix:
        n = demangle_owner(owner_name)
        _suffix[owner_name] = sane(n)[:170]
    return _suffix[owner_name]


# ---- build linkage maps ------------------------------------------------
fi = {n: r for n, r in p.items() if r['role'] == 'FuncInfo'}
uw_by_addr = {int(r['addr'], 16): n for n, r in p.items()
              if r['role'] == 'UnwindMapEntry'}
tb_by_addr = {int(r['addr'], 16): n for n, r in p.items()
              if r['role'] == 'TryBlockMapEntry'}
ht_by_addr = {int(r['addr'], 16): n for n, r in p.items()
              if r['role'] == 'HandlerType'}

fi_by_uw = {r['pUnwindMap']: n for n, r in fi.items()}
fi_by_tb = {r['pTryBlockMap']: n for n, r in fi.items() if r['pTryBlockMap']}
tb_by_ht = {r['pHandlerArray']: n for n, r in p.items()
            if r['role'] == 'TryBlockMapEntry' and r['pHandlerArray']}

# orphan attribution by array range
def find_uw_owner(a):
    for n, r in fi.items():
        if r['pUnwindMap'] <= a < r['pUnwindMap'] + 8 * r['maxState']:
            return n, int((a - r['pUnwindMap']) / 8)
    return None, -1


# Build the complete set of tryblock slots (labeled heads + unlabeled
# interior entries) by walking every FuncInfo's pTryBlockMap range and
# reading slot fields straight from region.bin.
import struct
_blob = open(os.path.join(HERE, 'region.bin'), 'rb').read()
_BLO = 0xBCB000
def _u32(a):
    return struct.unpack_from('<I', _blob, a - _BLO)[0]

tb_slots = []   # {addr, nCatches, pHandlerArray, fi_name}
for n, r in fi.items():
    if not r['nTryBlocks']:
        continue
    for k in range(r['nTryBlocks']):
        a = r['pTryBlockMap'] + 20 * k
        tb_slots.append({'addr': a, 'tryLow': _u32(a), 'tryHigh': _u32(a + 4),
                         'catchHigh': _u32(a + 8), 'nCatches': _u32(a + 12),
                         'pHandlerArray': _u32(a + 16), 'fi': n, 'idx': k})


def find_ht_owner(a):
    """Return (tb_slot_dict) whose handler array covers addr a."""
    for s in tb_slots:
        if s['pHandlerArray'] \
           and s['pHandlerArray'] <= a < s['pHandlerArray'] + 16 * s['nCatches']:
            return s
    return None

TAG = '[stru-lift 2026-09-16]'
plan = []   # {stru, addr, role, new, comment, conf}
residual = []

# FuncInfo -> ehfi_<owner>
for n, r in sorted(fi.items(), key=lambda kv: int(kv[1]['addr'], 16)):
    a = int(r['addr'], 16)
    ow = o.get(n, {})
    oname = ow.get('owner_name')
    if not oname:
        residual.append({'stru': n, 'addr': r['addr'], 'role': 'FuncInfo',
                         'reason': 'no owner xref'})
        continue
    suf = owner_suffix(oname)
    new = f'ehfi_{suf}'
    cmt = (f"// MSVC EH __CxxFrameHandler3 FuncInfo for {oname} "
           f"(@{ow['owner_addr']}): maxState={r['maxState']} "
           f"unwind={hex(r['pUnwindMap'])} nTry={r['nTryBlocks']} "
           f"tryMap={hex(r['pTryBlockMap'])} EHFlags={r['EHFlags']} {TAG}")
    plan.append({'stru': n, 'addr': r['addr'], 'role': 'FuncInfo',
                 'new': new, 'comment': cmt, 'conf': 'CONFIRMED',
                 'owner': oname})

# UnwindMapEntry -> ehuw_<owner> (+idx if orphan-inside-array)
for n, r in sorted(p.items(), key=lambda kv: int(kv[1]['addr'], 16)):
    if r['role'] != 'UnwindMapEntry':
        continue
    a = int(r['addr'], 16)
    fin = fi_by_uw.get(a)
    if fin:
        fo = fi[fin]
        oname = o[fin]['owner_name']
        new = f"ehuw_{owner_suffix(oname)}"
        cmt = (f"// MSVC EH UnwindMapEntry[0..{fo['maxState']-1}] array for "
               f"{oname} (FuncInfo ehf_i@{fin}): entry0 toState="
               f"{r['toState'] & 0xffffffff:#x} action={hex(r['action'])} {TAG}")
        plan.append({'stru': n, 'addr': r['addr'], 'role': 'UnwindMapEntry',
                     'new': new, 'comment': cmt, 'conf': 'CONFIRMED',
                     'owner': oname})
    else:
        fin2, idx = find_uw_owner(a)
        if fin2:
            oname = o[fin2]['owner_name']
            new = f"ehuw_{owner_suffix(oname)}_{idx}"
            cmt = (f"// MSVC EH UnwindMapEntry[{idx}] for {oname} "
                   f"(interior entry, label not at array head): toState="
                   f"{r['toState'] & 0xffffffff:#x} action={hex(r['action'])} "
                   f"{TAG}")
            plan.append({'stru': n, 'addr': r['addr'], 'role': 'UnwindMapEntry',
                         'new': new, 'comment': cmt, 'conf': 'VALID',
                         'owner': oname})
        else:
            residual.append({'stru': n, 'addr': r['addr'],
                             'role': 'UnwindMapEntry',
                             'reason': 'not in any FuncInfo unwind range'})

# TryBlockMapEntry -> ehtb_<owner>(_k for k-th tryblock of same func)
seen_tb = collections.Counter()
for n, r in sorted(p.items(), key=lambda kv: int(kv[1]['addr'], 16)):
    if r['role'] != 'TryBlockMapEntry':
        continue
    a = int(r['addr'], 16)
    fin = fi_by_tb.get(a)
    if not fin:
        residual.append({'stru': n, 'addr': r['addr'],
                         'role': 'TryBlockMapEntry',
                         'reason': 'not pointed by any FuncInfo'})
        continue
    oname = o[fin]['owner_name']
    k = seen_tb[oname]
    seen_tb[oname] += 1
    new = f"ehtb_{owner_suffix(oname)}" + (f'_{k}' if k else '')
    cmt = (f"// MSVC EH TryBlockMapEntry[{k}] for {oname}: try "
           f"[{r['tryLow']}..{r['tryHigh']}] catchHi={r['catchHigh']} "
           f"nCatches={r['nCatches']} handlers={hex(r['pHandlerArray'])} {TAG}")
    plan.append({'stru': n, 'addr': r['addr'], 'role': 'TryBlockMapEntry',
                 'new': new, 'comment': cmt, 'conf': 'CONFIRMED',
                 'owner': oname})

# HandlerType -> ehct_<owner>_<slot>
seen_ht = collections.Counter()
for n, r in sorted(p.items(), key=lambda kv: int(kv[1]['addr'], 16)):
    if r['role'] != 'HandlerType':
        continue
    a = int(r['addr'], 16)
    slot = find_ht_owner(a)
    if not slot:
        residual.append({'stru': n, 'addr': r['addr'], 'role': 'HandlerType',
                         'reason': 'not in any try-block handler array'})
        continue
    oname = o[slot['fi']]['owner_name']
    hidx = int((a - slot['pHandlerArray']) / 16)
    k = seen_ht[oname]
    seen_ht[oname] += 1
    new = f"ehct_{owner_suffix(oname)}" + (f'_{k}' if k else '')
    cmt = (f"// MSVC EH HandlerType[{hidx}] (catch descriptor) for {oname} "
           f"via TryBlockMapEntry@{hex(slot['addr'])}"
           f"{' [interior slot]' if 'stru_%X' % slot['addr'] not in p else ''}: "
           f"adjectives={hex(r['adjectives'])} pType={hex(r['pType'])} "
           f"catchObjDisp={r['dispCatchObj']} handler={hex(r['handlerAddr'])} "
           f"{TAG}")
    plan.append({'stru': n, 'addr': r['addr'], 'role': 'HandlerType',
                 'new': new, 'comment': cmt, 'conf': 'CONFIRMED',
                 'owner': oname})

# EH4ScopeTable -> ehsc_<owner>
for n, r in sorted(p.items(), key=lambda kv: int(kv[1]['addr'], 16)):
    if r['role'] != 'EH4ScopeTable':
        continue
    ow = o.get(n, {})
    oname = ow.get('owner_name')
    if not oname:
        residual.append({'stru': n, 'addr': r['addr'], 'role': 'EH4ScopeTable',
                         'reason': 'no owner xref'})
        continue
    new = f"ehsc_{owner_suffix(oname)}"
    cmt = (f"// MSVC EH4 (_seh4_translator) scopetable header for {oname} "
           f"(@{ow['owner_addr']}): gsOff={r['gsOff']} gsXor={r['gsXor']} "
           f"ehOff={r['ehOff']} ehXor={r['ehXor']} {TAG}")
    plan.append({'stru': n, 'addr': r['addr'], 'role': 'EH4ScopeTable',
                 'new': new, 'comment': cmt, 'conf': 'CONFIRMED',
                 'owner': oname})

# OTHER items -> classify by content. stru_B0E000 is the ASCII tail of a
# demangled Phyre script-accessor signature string ("...PTimer *>::Get")
# inside a class-name blob at .rdata:0xB0DFC0+, mistyped by IDA as a
# 4-dword struct 'Vtable_FunctionCallerAbstract_Phyre'. Zero xrefs.
# Descriptive rename only (no semantic overclaim).
for n, r in p.items():
    if r['role'] == 'OTHER':
        if n == 'stru_B0E000':
            plan.append({'stru': n, 'addr': r['addr'], 'role': 'OTHER',
                         'new': 'a_PhyreDemangledNameBlob_B0E000',
                         'comment': ("// ASCII tail of demangled Phyre script-"
                                     "accessor signature string "
                                     "(\"...PObjectAccessor<class Phyre::"
                                     "PTimer *>::Get\"), inside a class-name "
                                     "blob @.rdata:0xB0DFC0+; mistyped by IDA "
                                     "as struct Vtable_FunctionCallerAbstract_"
                                     f"Phyre {TAG}"),
                         'conf': 'VALID', 'owner': None})
        else:
            residual.append({'stru': n, 'addr': r['addr'], 'role': 'OTHER',
                             'reason': 'non-EH mistyped item',
                             'line': r['line']})

# ---- collision check ----------------------------------------------------
names = collections.Counter(x['new'] for x in plan)
dups = {k: c for k, c in names.items() if c > 1}
if dups:
    # suffix colliding names deterministically
    seen = collections.Counter()
    for x in plan:
        if names[x['new']] > 1:
            k = seen[x['new']]
            seen[x['new']] += 1
            if k:
                x['new'] = f"{x['new']}_{k}"
                x['comment'] += f' [name-collision suffix {k}]'
    names2 = collections.Counter(x['new'] for x in plan)
    dups2 = {k: c for k, c in names2.items() if c > 1}
    print('post-suffix dups:', dups2)

byrole = collections.Counter(x['role'] for x in plan)
print('plan size:', len(plan), dict(byrole))
print('residual:', len(residual))
for x in residual:
    print('  RES:', x)
with open(os.path.join(HERE, 'rename_plan.json'), 'w') as f:
    json.dump({'plan': plan, 'residual': residual}, f, indent=0)
print('sample names:')
for x in plan[:6] + plan[-6:]:
    print('  ', x['stru'], '->', x['new'])
