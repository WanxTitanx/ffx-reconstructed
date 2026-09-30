import idautils, idc, json
name = "FFX_Menu2D_BuildNoTextureVertices"
ea = idc.get_name_ea_simple(name)
print(hex(ea) if ea != idc.BADADDR else "NOTFOUND")
# also list all Menu2D funcs with 'Vertices' or 'Omd' or 'Anm'
for f in idautils.Functions():
    n = idc.get_func_name(f)
    if any(k in n for k in ("Vertices", "Omd", "Omd", "Anm", "Keyhole", "Texture")):
        print(hex(f), n)
