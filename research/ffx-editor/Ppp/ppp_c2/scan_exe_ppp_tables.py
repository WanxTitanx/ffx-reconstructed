# -*- coding: utf-8 -*-
# FINAL: scan EXE pppProg entries (0x28B: [0]=name,[1]=f1,[2]=f2/main,[3..6]=f3-f6,[7]=f7/con,[8]=f8/con2,[9]=f9/des)
# cross with HostContextTable 0xC64CE8 (512 slots x 8B pairs) -> fp_vs_hostctx.json
import ida_bytes, ida_name, idautils, struct, json

STR_LO, STR_HI = 0xB40000, 0xB60000
HOST = 0xC64CE8
N = 512

data = ida_bytes.get_bytes(HOST, N * 8)
host = []
addr_slots = {}
for i in range(N):
    a, b = struct.unpack('<II', data[i * 8:i * 8 + 8])
    host.append({'slot': i, 'p0': a, 'p1': b})
    if a: addr_slots.setdefault(a, []).append(i)
    if b: addr_slots.setdefault(b, []).append(i)

ppp_strings = []
for s in idautils.Strings():
    ea = s.ea
    if ea < STR_LO or ea >= STR_HI:
        continue
    try:
        txt = str(s)
    except Exception:
        continue
    if txt.startswith('ppp') and len(txt) < 64:
        ppp_strings.append((ea, txt))

def nm(a):
    if not a:
        return ''
    n = ida_name.get_name(a)
    return n or ('0x%x' % a)

def slots_of(addr):
    return addr_slots.get(addr, [])

entries = []
for sea, txt in ppp_strings:
    for xr in idautils.XrefsTo(sea, 0):
        base = xr.frm
        d = ida_bytes.get_bytes(base, 0x28)
        if not d or len(d) < 0x28:
            continue
        w = struct.unpack('<10I', d)
        if w[0] != sea:
            continue
        entries.append({
            'nome': txt, 'entry': base,
            'f1': w[1], 'f2': w[2], 'f3': w[3], 'f4': w[4], 'f5': w[5], 'f6': w[6],
            'f7': w[7], 'f8': w[8], 'f9': w[9],
        })
        break

entries.sort(key=lambda r: r['entry'])
out_entries = []
for r in entries:
    out_entries.append({
        'nome': r['nome'], 'entry': hex(r['entry']),
        'main': ('0x%x' % r['f2']) if r['f2'] else None,
        'main_name': nm(r['f2']), 'main_slots': slots_of(r['f2']),
        'f1': ('0x%x' % r['f1']) if r['f1'] else None,
        'f3': ('0x%x' % r['f3']) if r['f3'] else None,
        'f4': ('0x%x' % r['f4']) if r['f4'] else None,
        'f5': ('0x%x' % r['f5']) if r['f5'] else None,
        'f6': ('0x%x' % r['f6']) if r['f6'] else None,
        'con': ('0x%x' % r['f7']) if r['f7'] else None,
        'con_name': nm(r['f7']), 'con_slots': slots_of(r['f7']),
        'con2': ('0x%x' % r['f8']) if r['f8'] else None,
        'con2_name': nm(r['f8']), 'con2_slots': slots_of(r['f8']),
        'des': ('0x%x' % r['f9']) if r['f9'] else None,
        'des_name': nm(r['f9']), 'des_slots': slots_of(r['f9']),
    })

FPH = [
    'pppKeThRes32', 'pppKeThRes32Con',
    'pppAccele', 'pppAcceleCon', 'pppAngAccele', 'pppAngAcceleCon',
    'pppSclAccele', 'pppSclAcceleCon', 'pppColAccele', 'pppColAcceleCon',
    'pppMove', 'pppMoveCon', 'pppAngMove', 'pppAngMoveCon',
    'pppSclMove', 'pppSclMoveCon', 'pppColMove', 'pppColMoveCon',
    'pppPoint', 'pppPointCon', 'pppAngle', 'pppAngleCon',
    'pppScale', 'pppScaleCon', 'pppColor', 'pppColorCon',
    'pppKeDrct', 'pppKeDrctCon',
    'pppRandFV', 'pppRandUpFV', 'pppRandDownFV', 'pppRandIV',
    'pppSRandFV', 'pppSRandUpFV', 'pppSRandDownFV',
    'pppSMatrix', 'pppMatrixXYZ', 'pppMatrixYXZ', 'pppMatrixLoc',
    'pppMatrixScl', 'pppKeParMatR', 'pppParMatrix',
    'pppDrawMatrix', 'pppDrawMatrixFront', 'pppKeDMatFrDraw',
    'pppKeThTp', 'pppKeThTpCon', 'pppKeThSft', 'pppKeThSftCon',
    'pppKeTh', 'pppKeThDraw', 'pppKeThCon', 'pppKeThCon2', 'pppKeThDes',
    'pppDrawMdl', 'pppDrawMdlTs', 'pppDrawMdlTsCon',
    'pppDrawMdl2', 'pppDrawMdlSemi2', 'pppDrawMdlTs2', 'pppDrawMdlTs2Con',
    'pppDrawShape', 'pppDrawShapeConstruct',
    'pppKeMdlDttDraw', 'pppKeMdlDttCon', 'pppKeMdlDttCon2',
    'pppKeShpTail2', 'pppKeShpTail2Draw', 'pppKeShpTail2Con',
    'pppVertexAp', 'pppVertexApCon', 'pppVertexApLc', 'pppVertexApLcCon',
    'pppKeBornRnd3', 'pppKeBornRnd3Con',
    'pppKeBornRnd5', 'pppKeBornRnd5Con',
    'pppKeBornRnd6', 'pppKeBornRnd6Con',
]

name2ea = {}
for ea, name in idautils.Names():
    if name.startswith('ppp') or 'PppHandler' in name:
        name2ea[name] = ea

def resolve_direct(name):
    if name in name2ea:
        return name2ea[name]
    if name.startswith('ppp'):
        cand = 'FFX_PppHandler_' + name[3:]
        if cand in name2ea:
            return name2ea[cand]
    return None

entry_by_name = {e['nome']: e for e in out_entries}

handlers = []
for name in FPH:
    ea = resolve_direct(name)
    entry = entry_by_name.get(name)
    rec = {
        'nome': name,
        'addr': ('0x%x' % ea) if ea else None,
        'addr_slots': slots_of(ea) if ea else [],
        'entry_exe': entry['entry'] if entry else None,
    }
    if entry:
        rec['main'] = entry['main']
        rec['main_name'] = entry['main_name']
        rec['main_slots'] = entry['main_slots']
        rec['con'] = entry['con']
        rec['con_name'] = entry['con_name']
        rec['con_slots'] = entry['con_slots']
        rec['con2'] = entry['con2']
        rec['con2_slots'] = entry['con2_slots']
        rec['des'] = entry['des']
        rec['des_slots'] = entry['des_slots']
        slot = entry['main_slots'][0] if entry['main_slots'] else (entry['con_slots'][0] if entry['con_slots'] else None)
        rec['slot_global'] = slot
    else:
        rec['slot_global'] = rec['addr_slots'][0] if rec['addr_slots'] else None
    handlers.append(rec)

out = {
    'host_table': [{'slot': h['slot'], 'p0': ('0x%x' % h['p0']) if h['p0'] else None,
                    'p1': ('0x%x' % h['p1']) if h['p1'] else None} for h in host],
    'exe_ppp_entries': out_entries,
    'handlers': handlers,
}
with open(r'C:\Users\wande\Documents\ffx-editor-main\work\ppp_c2\fp_vs_hostctx.json', 'w') as f:
    json.dump(out, f, indent=1)

print('entries=%d handlers=%d' % (len(out_entries), len(handlers)))
for h in handlers:
    print('%-22s addr=%-10s slot=%-4s entry=%s' % (h['nome'], h['addr'], h['slot_global'], h['entry_exe']))
