import idc, idautils
print("func at 0x8447A0:", idc.get_func_name(0x8447A0))
start = idc.get_func_attr(0x8447A0, idc.FUNCATTR_START)
print("start:", hex(start) if start != idc.BADADDR else "none")
for ea, name in idautils.Names():
    if 'Raster' in name or 'Encounter' in name or 'GuideMesh' in name or 'Mapout' in name or 'YNDT' in name or 'YNGM' in name:
        print(hex(ea), name)
