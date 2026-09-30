#!/usr/bin/env python3
"""Generate rename + comment payloads for PPP dispatch-table IDA pass (2026-09-16).

Evidence-driven: every name/comment cites table, slot, field-offset role and fn.
Roles (verified in FFX_Render_PppProgramProcessor 0x7170F0 / _2 0x716D20,
InvokeSectionCallbacks_A 0x712E00 / _B 0x712E70, FreeResourceBufferChain 0x7169D0):
  +0x00 name ptr ('ppp*' string)
  +0x04 direct  : whole-section batched exec  fn(section,program,cmdrec,cmdIdx)  (replaces per-particle loop)
  +0x08 exec    : per-particle exec A         fn(node,dataOff,cmdrec)
  +0x0C draw    : per-particle exec B, gated (program.flags&1)==0; sole handler for Draw* ops
  +0x10         : unused (always 0 in all 697 records)
  +0x14 aux14   : rare; no call site located (BuildWoodBasis in pppDrawMatrixWood)
  +0x18 aux18   : rare; no call site located (single no-op in pppKeAcmSolid)
  +0x1C init    : per-cmdref init    fn(entry,cmdref)  via InvokeSectionCallbacks_B (batch-entry insert)
  +0x20 reset   : per-cmdref periodic fn(entry,cmdref) via InvokeSectionCallbacks_A (counter wrap)
  +0x24 free    : per-cmdref destroy fn(entry,cmdref)  via FreeResourceBufferChain
"""
import json, collections, re

W = 'work/_ppp_dispatch/'
tables = json.load(open(W + 'all_tables.json'))
fnames = {int(k, 16): v[0] for k, v in json.load(open(W + 'fn_names.json')).items()}
FL = ('f04', 'f08', 'f0c', 'f14', 'f18', 'f1c', 'f20', 'f24')
ROLE = {'f04': 'Direct', 'f08': 'Exec', 'f0c': 'Draw', 'f14': 'Aux14', 'f18': 'Aux18',
        'f1c': 'Init', 'f20': 'Reset', 'f24': 'Free'}
TAB = {'pppSysProgTbl': 'SYS', 'pppProgTbl': 'PMC', 'FFX_PppKeyholeDispatchTable': 'KEY'}

# ---- indexes -------------------------------------------------------------
sys_idx = {}
for r in tables['pppSysProgTbl']['records']:
    sys_idx.setdefault(r['name'], []).append(r['idx'])

uses = collections.defaultdict(list)            # fn -> [(table,idx,op,field)]
for tn, tt in tables.items():
    for r in tt['records']:
        for f in FL:
            if r[f]:
                uses[r[f]].append((tn, r['idx'], r['name'], f))

# ---- rename manifest ------------------------------------------------------
def mk_name(addr, cur):
    us = uses[addr]
    ops = sorted({u[2] for u in us})
    flds = sorted({u[3] for u in us}, key=FL.index)
    op = ops[0][3:] if ops[0].startswith('ppp') else ops[0]  # strip 'ppp'
    roles = [ROLE[f] for f in flds]
    is_nop = ('nullsub' in cur) or cur.endswith('_nop')
    if is_nop:
        return 'PppOp_%s_Noop%s' % (op, ''.join(roles))
    m = re.match(r'Vtable_ClearFloat4_([0-9A-F]+)(?:_[A-H])?', cur)
    if m:
        return 'PppOp_%s_%sClearVec4%s' % (op, ''.join(roles), m.group(1))
    if cur == 'Vtable_ClearIntFloat3_A0_C':
        return 'PppOp_%s_%sIntFloat3A0' % (op, ''.join(roles))
    if cur == 'Vtable_Init64AndSetFloat1':
        return 'PppOp_%s_Init64SetFloat1' % op
    if cur.endswith('_structural'):   # misleading autogen names
        return 'PppOp_%s_%s' % (op, roles[0] if len(roles) == 1 else 'Cb')
    return None

renames = []
GENERIC = re.compile(r'^(sub_|nullsub_|j_|unknown_|Vtable_|FFX_Vfn|dword_|loc_)|_structural$')
for addr, name in sorted(fnames.items()):
    if name and GENERIC.search(name):
        nn = mk_name(addr, name)
        if nn:
            renames.append({'addr': '0x%x' % addr, 'old': name, 'new': nn,
                            'ops': sorted({u[2] for u in uses[addr]}),
                            'fields': [u[3] for u in uses[addr]]})
        else:
            print('UNMAPPED generic:', hex(addr), name)
json.dump(renames, open(W + 'rename_manifest.json', 'w'), indent=1)
print('renames:', len(renames))

# ---- comment manifest -----------------------------------------------------
items = []

def field_list(r):
    return ' '.join('%s=%x' % (f[1:], r[f]) for f in FL if r[f])

# per-record comments
for tn, tt in tables.items():
    tag = TAB[tn]
    for r in tt['records']:
        ea = int(r['ea'], 16)
        nm = r['name']
        extra = ''
        if tn == 'pppSysProgTbl' and r['idx'] >= 145 and r['idx'] < 290:
            extra = ' (alias of SYS#%d)' % (r['idx'] - 145)
        elif tn != 'pppSysProgTbl' and nm in sys_idx:
            extra = ' (SYS#%s mirror)' % '/'.join(map(str, sys_idx[nm]))
        if nm is None:
            c = 'PPP[%s#%d] null record — invalid/terminator slot [PPP-DISP-2026-09-16]' % (tag, r['idx'])
        else:
            c = "PPP[%s#%d] '%s'%s | %s [PPP-DISP-2026-09-16]" % (
                tag, r['idx'], nm, extra, field_list(r))
        items.append({'addr': '0x%x' % ea, 'comment': c})

# per-fn comments
for addr, us in sorted(uses.items()):
    ops = sorted({u[2] for u in us})
    if addr == 0x728AC0:
        c = ('PPP shared no-op placeholder (CONFIRMED: empty fn) — used in %d record fields '
             'across SYS/PMC/KEY; fills unused slots [PPP-DISP-2026-09-16]' % len(us))
    elif len(us) <= 8:
        slots = ', '.join('%s[%d]+%s' % (TAB[t], i, f[1:]) for t, i, _, f in us)
        c = ("PPP opcode handler '%s' — %s (%s) [PPP-DISP-2026-09-16]"
             % (ops[0], '/'.join(sorted({ROLE[f] for _, _, _, f in us}, key=lambda r: list(ROLE.values()).index(r))), slots))
    else:
        flds = collections.Counter(f for _, _, _, f in us)
        c = ("PPP handler shared by ops %s — %d record slots (%s) [PPP-DISP-2026-09-16]"
             % ('/'.join(ops[:4]) + ('…' if len(ops) > 4 else ''), len(us),
                ', '.join('%s x%d' % (ROLE[f], n) for f, n in sorted(flds.items()))))
    items.append({'addr': '0x%x' % addr, 'comment': c})

# call-site comments
CALLS = {
 0x71719D: 'indirect: ppp dispatch — rec+0x04 Direct batched exec fn(section,program,cmdrec,cmdIdx) [PPP-DISP-2026-09-16]',
 0x717225: 'indirect: ppp dispatch — rec+0x08 Exec per-particle fn(node,dataOff,cmdrec) [PPP-DISP-2026-09-16]',
 0x7173D8: 'indirect: ppp dispatch — rec+0x08 Exec per-particle fn(node,dataOff,cmdrec) [PPP-DISP-2026-09-16]',
 0x7173F3: 'indirect: ppp dispatch — rec+0x0C Draw/exec2 per-particle, gated (prog.flags&1)==0 [PPP-DISP-2026-09-16]',
 0x71746E: 'indirect: ppp dispatch — rec+0x0C Draw/exec2 per-particle, gated (prog.flags&1)==0 [PPP-DISP-2026-09-16]',
 0x71731D: 'indirect: ppp dispatch — reset/wrap path: InvokeSectionCallbacks_A -> rec+0x20 [PPP-DISP-2026-09-16]',
 0x7174CE: 'indirect: ppp dispatch — free path: FreeResourceBufferChain -> rec+0x24 [PPP-DISP-2026-09-16]',
 0x717361: 'indirect: ppp dispatch — free path: FreeResourceBufferChain -> rec+0x24 [PPP-DISP-2026-09-16]',
 0x716DE0: 'indirect: ppp dispatch — rec+0x04 Direct batched exec fn(section,program,cmdrec,cmdIdx) [PPP-DISP-2026-09-16]',
 0x716FA7: 'indirect: ppp dispatch — rec+0x08 Exec per-particle fn(node,dataOff,cmdrec) [PPP-DISP-2026-09-16]',
 0x717005: 'indirect: ppp dispatch — rec+0x08 Exec per-particle fn(node,dataOff,cmdrec) [PPP-DISP-2026-09-16]',
 0x717017: 'indirect: ppp dispatch — rec+0x0C Draw/exec2 per-particle, gated (prog.flags&1)==0 [PPP-DISP-2026-09-16]',
 0x71708A: 'indirect: ppp dispatch — rec+0x0C Draw/exec2 per-particle, gated (prog.flags&1)==0 [PPP-DISP-2026-09-16]',
 0x716EBD: 'indirect: ppp dispatch — reset/wrap path: InvokeSectionCallbacks_A -> rec+0x20 [PPP-DISP-2026-09-16]',
 0x7170D7: 'indirect: ppp dispatch — free path: FreeResourceBufferChain -> rec+0x24 [PPP-DISP-2026-09-16]',
 0x716F01: 'indirect: ppp dispatch — free path: FreeResourceBufferChain -> rec+0x24 [PPP-DISP-2026-09-16]',
 0x712E52: 'indirect: ppp dispatch — rec+0x20 Reset/wrap per-cmdref fn(entry,cmdref), called on batch-entry counter wrap [PPP-DISP-2026-09-16]',
 0x712EC2: 'indirect: ppp dispatch — rec+0x1C Init per-cmdref fn(entry,cmdref), called at batch-entry insert [PPP-DISP-2026-09-16]',
 0x716A11: 'indirect: ppp dispatch — rec+0x24 Free per-cmdref fn(entry,cmdref), resource-buffer teardown [PPP-DISP-2026-09-16]',
 # table-load sites
 0x72A8EA: 'PPP table arg: pppSysProgTbl (0xC3A500, 418x40B) for RelocatePppResourceBlob — serialized u32 prog index -> pppSysProgTbl+40*idx [PPP-DISP-2026-09-16]',
 0x800673: 'PPP table arg: pppSysProgTbl (0xC3A500) — accel path relocates against the same 418-op system table [PPP-DISP-2026-09-16]',
 0xA547C9: 'PPP table arg: FFX_PppKeyholeDispatchTable (0xC86080, 32x40B, band-A ops only) for keyhole texture path [PPP-DISP-2026-09-16]',
 0x761B67: 'PPP table arg: pppProgTbl (0xC3E770, 247x40B, rec0 null) — pmcom program stream relocates against this table [PPP-DISP-2026-09-16]',
 # table bases / interior labels
 0xC3A500: '[PPP-DISP-2026-09-16] CONFIRMED pppSysProgTbl: 418 records x 40B. Band A slots0-144 core ops; band B 145-289 = verbatim aliases (rec[i+145]==rec[i]); band C 290-417 = 128 HD-only ops. Layout: +00 name, +04 Direct, +08 Exec, +0C Draw, +14/+18 aux(rare,no caller), +1C Init, +20 Reset, +24 Free.',
 0xC3E770: '[PPP-DISP-2026-09-16] CONFIRMED pppProgTbl: 247 records x 40B; rec0 null; 246 ops = 145 band-A + 101 band-C subset, same handler pool as pppSysProgTbl. Used by FFX_Pmcom_RequestQueuePump (0x761B67).',
 0xC86080: '[PPP-DISP-2026-09-16] CONFIRMED FFX_PppKeyholeDispatchTable: 32 records x 40B, band-A ops only (Accele/Move/Point/Angle/Scale/Color + KeThRes48). Used by FFX_MagicHost_KeyholeTexture_Init (0xA547C9).',
 0xC3A800: '[PPP-DISP-2026-09-16] interior label = pppSysProgTbl[19] pppDrawMatrix — legacy "ppp_drawke_variant" band label; NOT a separate table (same 40B stream).',
 0xC3BEC8: '[PPP-DISP-2026-09-16] interior label = pppSysProgTbl[165] pppDrawMatrixFront — legacy "ppp_drawke" band label.',
 0xC3FC88: '[PPP-DISP-2026-09-16] interior label = pppProgTbl[135] pppDrawMatrixFront — legacy "ppp_matrix_kedmat" band label.',
 0xC863F0: '[PPP-DISP-2026-09-16] interior label = FFX_PppKeyholeDispatchTable[22] pppDrawMatrixFront — legacy "ppp_zcrct" band label.',
 0xC3E798: '[PPP-DISP-2026-09-16] interior label = pppProgTbl[1] pppDummyFunc — legacy "FFX_PppHostDispatchTable_AltQ" label.',
 # cmd-record layout anchors
 0x717172: 'PPP cmdrec walk: v7=program+40+16*i; cmdrec+0 = ptr to 40B dispatch record (relocated from serialized u32 index); cmdrec+4 = u16 field-id stride [PPP-DISP-2026-09-16]',
 0x716DB2: 'PPP cmdrec walk (proc2): cmdrec+0 = ptr to 40B dispatch record; +4 = u16 field-id [PPP-DISP-2026-09-16]',
}
for a, c in CALLS.items():
    items.append({'addr': '0x%x' % a, 'comment': c})

json.dump(items, open(W + 'comment_manifest.json', 'w'), indent=1)
print('comments:', len(items))
