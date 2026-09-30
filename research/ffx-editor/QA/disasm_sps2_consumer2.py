import ida_funcs, idc

f = ida_funcs.get_func(0x770540)
ea = f.start_ea
lines = []
while ea < f.end_ea:
    lines.append(f"0x{ea:X}: {idc.generate_disasm_line(ea, 0)}")
    ea = idc.next_head(ea, f.end_ea)
for l in lines[210:260]:
    print(l)
