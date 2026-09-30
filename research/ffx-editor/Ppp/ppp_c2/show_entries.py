# -*- coding: utf-8 -*-
# Show ALL candidate entries (w[0]==name) for key ppp names, across all tables.
import ida_bytes, ida_name, idautils, struct

NAMES = ['pppKeThSft', 'pppKeTh', 'pppKeThTp', 'pppKeThRes32', 'pppDrawMatrix',
         'pppDrawMatrixFront', 'pppDrawMdl', 'pppDrawMdl2', 'pppDrawMdlSemi2',
         'pppKeShpTail2', 'pppVertexAp', 'pppVertexApLc', 'pppDrawShape',
         'pppKeBornRnd3', 'pppKeMdlDttDraw', 'pppColor', 'pppKeDrct']

def nm(a):
    if not a:
        return ''
    n = ida_name.get_name(a)
    return n or ('0x%x' % a)

for s in idautils.Strings():
    txt = None
    try:
        txt = str(s)
    except Exception:
        continue
    if txt not in NAMES:
        continue
    sea = s.ea
    print('=== %s (str 0x%x) ===' % (txt, sea))
    for xr in idautils.XrefsTo(sea, 0):
        base = xr.frm
        d = ida_bytes.get_bytes(base, 0x28)
        if not d or len(d) < 0x28:
            continue
        w = struct.unpack('<10I', d)
        if w[0] != sea:
            continue
        print('  entry 0x%x | f1=0x%x(%s) f2=0x%x(%s) f3=0x%x f7=0x%x(%s) f8=0x%x(%s) f9=0x%x' % (
            base, w[1], nm(w[1]), w[2], nm(w[2]), w[3], w[7], nm(w[7]), w[8], nm(w[8]), w[9]))
