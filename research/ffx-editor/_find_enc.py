import ida_bytes, idc
# search for "enc_" string references
for ea in range(0xB70000, 0xB80000, 4):
    pass
# use find_regex via ida search for strings containing enc_
import ida_search, idaapi
# search all strings
for i in range(ida_bytes.get_segm_end(0xB70000)):
    pass
# simpler: iterate string literals
n = 0
for ea in idautils.Strings():
    s = str(ea)
    if 'enc' in s.lower() or 'omd' in s.lower():
        print(hex(ea.ea), s)
        n += 1
        if n > 40: break
