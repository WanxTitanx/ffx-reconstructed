import idc, idautils
for s in idautils.Strings():
    txt = str(s)
    if 'ffxmap' in txt.lower():
        print("string", hex(s.ea), repr(txt))
