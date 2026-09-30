import ida_funcs, idc

f = ida_funcs.get_func(0x88CA30)
ea = f.start_ea
lines = []
count = 0
while ea < f.end_ea:
    lines.append(f"0x{ea:X}: {idc.generate_disasm_line(ea, 0)}")
    ea = idc.next_head(ea, f.end_ea)
    count += 1
# print from line 120 onward
for l in lines[120:]:
    print(l)
