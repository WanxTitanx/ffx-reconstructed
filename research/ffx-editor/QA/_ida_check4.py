import idc, idautils
for ea, name in idautils.Names():
    if 'LoadAndProcessFieldVpa' in name or 'ReadFfxmapIdFile' in name or 'RasterizeEncounter' in name or 'BuildGuideMesh' in name:
        print(hex(ea), name)
