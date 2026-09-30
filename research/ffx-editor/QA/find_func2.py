import idc, ida_funcs, json
for name in ["FFX_Menu2D_BuildNoTextureVertices", "FFX_MagicHost_KeyholeTexture_Init", "FFX_Abmap_NodeDraw", "FFX_Abmap_DrawNodeColorOverlay", "FFX_Abmap_QueuePlacementAnim"]:
    ea = idc.get_name_ea_simple(name)
    if ea != idc.BADADDR:
        f = ida_funcs.get_func(ea)
        print("%s = 0x%x (start 0x%x end 0x%x)" % (name, ea, f.start_ea if f else 0, f.end_ea if f else 0))
    else:
        print("%s NOTFOUND" % name)
