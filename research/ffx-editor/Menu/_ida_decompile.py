import ida_hexrays, idc

ea = 0x88ca30
cf = ida_hexrays.decompile(ea)
if cf:
    print(str(cf))
else:
    print("decompile failed")
