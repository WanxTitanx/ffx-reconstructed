import ida_funcs, ida_lines, ida_ua, idc
start = 0xa657c0
end = start + 0x295e
ea = start
count = 0
out = []
while ea < end and count < 3000:
    out.append("%08x: %s" % (ea, idc.generate_disasm_line(ea, 0)))
    ea = idc.next_head(ea, end)
    count += 1
print("\n".join(out))
