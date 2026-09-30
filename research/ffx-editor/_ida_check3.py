import idc
for a in [0x844D10, 0x844BC0, 0x8447A0]:
    print(hex(a), idc.get_func_name(a))
