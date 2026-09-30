# -*- coding: utf-8 -*-
# Cross fp.h pppProgTbl_FP handlers with HostContextTable (0xC64CE8) and
# PPP dispatch table (0xC3A820, 0x28-byte entries, fn @ +0x0C).
# Runs inside IDA via ida-pro-mcp exec_file.
import ida_bytes, ida_name, idautils, json, struct

HOST = 0xC64CE8
N = 512
DISP = 0xC3A820
ESZ = 0x28
OUT = r'C:\Users\wande\Documents\ffx-editor-main\work\ppp_c2\fp_vs_hostctx.json'

def nm(addr):
    if not addr:
        return ''
    n = ida_name.get_name(addr)
    return n or ''

# ---- 1. HostContextTable ----
data = ida_bytes.get_bytes(HOST, N * 8)
host = []
for i in range(N):
    a, b = struct.unpack('<II', data[i * 8:i * 8 + 8])
    host.append({'slot': i, 'p0': a, 'p1': b,
                 'n0': nm(a), 'n1': nm(b)})

addr_slots = {}
for i in range(N):
    a = host[i]['p0']; b = host[i]['p1']
    if a: addr_slots.setdefault(a, []).append(i)
    if b: addr_slots.setdefault(b, []).append(i)

# ---- 2. Dispatch table 0xC3A820 ----
dispatch = []
for i in range(512):
    e = ida_bytes.get_bytes(DISP + i * ESZ, ESZ)
    if not e or len(e) < 0x10:
        break
    fn = struct.unpack('<I', e[0x0C:0x10])[0]
    if fn:
        dispatch.append({'entry': i, 'fn': fn, 'name': nm(fn)})

# ---- 3. name -> ea index for ppp-related symbols ----
name2ea = {}
for ea, name in idautils.Names():
    if name.startswith('ppp') or 'PppHandler' in name or name.startswith('FFX_Ppp'):
        name2ea[name] = ea

# ---- 4. fp.h function references (union of mag_0021 + mag_0098) ----
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

def resolve(name):
    if name in name2ea:
        return name2ea[name]
    # try FFX_PppHandler_<suffix>
    if name.startswith('ppp'):
        cand = 'FFX_PppHandler_' + name[3:]
        if cand in name2ea:
            return name2ea[cand]
    return None

handlers = []
for name in FPH:
    ea = resolve(name)
    slots = addr_slots.get(ea, []) if ea else []
    handlers.append({
        'nome': name,
        'addr': ('0x%x' % ea) if ea else None,
        'slot_global': slots,
    })

out = {
    'host_table': host,
    'dispatch': dispatch,
    'handlers': handlers,
}
with open(OUT, 'w') as f:
    json.dump(out, f, indent=1)
print('DONE handlers=%d host=%d dispatch=%d' % (len(handlers), len(host), len(dispatch)))
