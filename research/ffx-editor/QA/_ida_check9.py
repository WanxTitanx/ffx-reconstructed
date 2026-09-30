import idc, idautils
for ea, name in idautils.Names():
    if 'Yn_' in name or 'GuideMapSetData' in name or 'FpSetData' in name:
        print(hex(ea), name)
