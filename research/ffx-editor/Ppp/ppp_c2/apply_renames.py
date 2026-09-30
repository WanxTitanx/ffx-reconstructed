# -*- coding: utf-8 -*-
# Apply canonical ppp* renames (discovered: fp.h x HostContextTable cross).
import ida_name, ida_bytes

RENAMES = {
    0x75d2e0: 'pppColor',
    0x75d330: 'pppColorCon',
    0x75e520: 'pppKeDrct',
    0x75e560: 'pppKeDrctCon',
    0x7326c0: 'pppSRandFV',
    0x734200: 'pppMatrixLoc',
    0x734950: 'pppKeParMatR',
    0x734710: 'pppParMatrix',
    0x734fc0: 'pppKeDMatFrDraw',
    0x736f20: 'pppKeThTpCon',
    0x736f50: 'pppKeThSft',
    0x736110: 'pppKeTh',
    0x740aa0: 'pppDrawShape',
    0x740f70: 'pppDrawShapeConstruct',
    0x72e870: 'pppKeMdlDttDraw',
    0x74e570: 'pppKeShpTail2',
    0x74e650: 'pppKeShpTail2Draw',
    0x74e620: 'pppKeShpTail2Con',
    0x757930: 'pppVertexAp',
    0x757c20: 'pppVertexApCon',
    0x7580e0: 'pppVertexApLc',
    0x758340: 'pppVertexApLcCon',
    0x758a50: 'pppKeBornRnd3',
    0x758ac0: 'pppKeBornRnd3Con',
    0x738b00: 'pppDrawMdlSemi2',
    0x75bbb0: 'pppColAcceleCon',
}

ok = 0
for ea, name in RENAMES.items():
    old = ida_name.get_name(ea) or ''
    if ida_name.set_name(ea, name, ida_name.SN_NOWARN):
        ok += 1
        print('0x%x %s -> %s' % (ea, old, name))
    else:
        print('FAIL 0x%x %s' % (ea, name))
print('renamed %d/%d' % (ok, len(RENAMES)))
