import idc
for a in [0x8444e4, 0x83E980, 0x8762D0, 0x875C10, 0x875AC0]:
    print(hex(a), idc.get_func_name(a))
