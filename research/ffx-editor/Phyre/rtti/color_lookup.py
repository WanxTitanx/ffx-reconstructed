import idautils, idc
hits = [(f, idc.get_func_name(f)) for f in idautils.Functions()
        if 'Color' in (idc.get_func_name(f) or '') and ('Register' in (idc.get_func_name(f) or '') or 'Descriptor' in (idc.get_func_name(f) or ''))]
print(len(hits))
for f, n in hits[:25]:
    print(hex(f), n)
