import idautils, idc
for s in idautils.Strings():
    text = str(s)
    if "maho" in text.lower() or "Maho" in text or "MAHO" in text:
        print(hex(s.ea), repr(text))
