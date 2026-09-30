import idc, idautils, ida_bytes
# find YNDT string
for ea in idautils.Strings():
    s = str(ea)
    if 'YNDT' in s or 'YNGM' in s or 'YNED' in s:
        print("string", hex(ea), repr(s))
# find xrefs to the string
