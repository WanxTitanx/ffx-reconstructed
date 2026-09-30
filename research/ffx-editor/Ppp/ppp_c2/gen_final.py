# -*- coding: utf-8 -*-
# FINAL GENERATOR: fp.h handlers (mag_0021 + mag_0098) x HostContextTable.
import ida_bytes, ida_name, idautils, struct, json

STR_LO, STR_HI = 0xB40000, 0xB60000
HOST = 0xC64CE8
N = 512

data = ida_bytes.get_bytes(HOST, N * 8)
addr_slots = {}
for i in range(N):
    a, b = struct.unpack('<II', data[i * 8:i * 8 + 8])
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

# entries: name -> best entry (first with any nonzero fn pointer, else first)
best = {}
for sea, txt in ppp_strings:
    cands = []
    for xr in idautils.XrefsTo(sea, 0):
        base = xr.frm
        d = ida_bytes.get_bytes(base, 0x28)
        if not d or len(d) < 0x28:
            continue
        w = struct.unpack('<10I', d)
        if w[0] != sea:
            continue
        cands.append({'entry': base, 'f1': w[1], 'f2': w[2], 'f3': w[3],
                      'f4': w[4], 'f5': w[5], 'f6': w[6], 'f7': w[7], 'f8': w[8], 'f9': w[9]})
    if not cands:
        continue
    cands.sort(key=lambda c: -(1 if any([c['f1'], c['f2'], c['f3'], c['f7'], c['f8'], c['f9']]) else 0))
    best[txt] = cands[0]

name2ea = {}
for ea, name in idautils.Names():
    if name.startswith('ppp') or 'PppHandler' in name:
        name2ea[name] = ea

def slots_of(a):
    return addr_slots.get(a, [])

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

def entry_main(e):
    for k in ('f1', 'f2', 'f3'):
        if e[k]:
            return e[k]
    return None

handlers = []
for name in FPH:
    addr = None
    src = None
    e = best.get(name)
    if name.endswith('Construct') and best.get(name[:-9]) and best[name[:-9]]['f7']:
        addr = best[name[:-9]]['f7']; src = 'entry(%s).f7' % name[:-9]
    elif name.endswith('Con2') and best.get(name[:-4]) and best[name[:-4]]['f8']:
        addr = best[name[:-4]]['f8']; src = 'entry(%s).f8' % name[:-4]
    elif name.endswith('Con') and best.get(name[:-3]) and best[name[:-3]]['f7']:
        addr = best[name[:-3]]['f7']; src = 'entry(%s).f7' % name[:-3]
    elif name.endswith('Des') and best.get(name[:-3]) and best[name[:-3]]['f9']:
        addr = best[name[:-3]]['f9']; src = 'entry(%s).f9' % name[:-3]
    elif name.endswith('Draw') and best.get(name[:-4]) and best[name[:-4]]['f3']:
        addr = best[name[:-4]]['f3']; src = 'entry(%s).f3' % name[:-4]
    elif e:
        m = entry_main(e)
        if m:
            addr = m; src = 'entry.main'
        elif e['f7']:
            addr = e['f7']; src = 'entry.con-only'
    if addr is None and name in name2ea:
        addr = name2ea[name]; src = 'direct-db'
    if addr is None:
        known = {'pppKeThRes32': 0x736A20, 'pppKeThRes32Con': 0x736A20}
        if name in known:
            addr = known[name]; src = 'documented'
    slots = slots_of(addr) if addr else []
    handlers.append({
        'nome': name,
        'addr': ('0x%x' % addr) if addr else None,
        'slot_global': slots[0] if slots else None,
        'todos_slots': slots,
        'fonte': src,
        'nome_db': nm(addr) if addr else None,
    })

with open(r'C:\Users\wande\Documents\ffx-editor-main\work\ppp_c2\fp_vs_hostctx.json', 'w') as f:
    json.dump(handlers, f, indent=1)

print('TOTAL', len(handlers))
for h in handlers:
    print('%-22s addr=%-10s slot=%-4s fonte=%-16s db=%s' % (
        h['nome'], h['addr'], h['slot_global'], h['fonte'], h['nome_db']))
