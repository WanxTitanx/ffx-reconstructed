import idautils, ida_funcs, idc
# Buffer globs for an2 files: 0x23056F8 .. 0x23057E8 (buffers 6-69)
# Find all functions referencing any of these addresses
targets = set()
for addr in range(0x23056F8, 0x2305800, 4):
    targets.add(addr)
consumers = {}
for addr in targets:
    for xref in idautils.XrefsTo(addr):
        fn = ida_funcs.get_func(xref.frm)
        if fn:
            name = idc.get_func_name(fn.start_ea)
            if name and name != "FFX_SphereGrid_InitRuntimeStateFromAbmapResources":
                consumers.setdefault(fn.start_ea, set()).add(hex(addr))
for fn_ea in sorted(consumers):
    print(hex(fn_ea), idc.get_func_name(fn_ea), sorted(consumers[fn_ea])[:5])
