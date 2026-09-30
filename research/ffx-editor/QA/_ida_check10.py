import idc, idautils
for ea, name in idautils.Names():
    if 'StringLoadHelper' in name:
        print(hex(ea), name)
