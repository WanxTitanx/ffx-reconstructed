import idautils, idc, ida_bytes
# Search for ".anm" and "anm/" strings and their xrefs
for s in idautils.Strings():
    text = str(s)
    if ".anm" in text or "anm/" in text or ".an2" in text or "maho" in text.lower():
        print(hex(s.ea), repr(text))
