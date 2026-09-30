import idc
start = 0xa657c0
end = start + 0x295e
ea = start
out = []
while ea < end and ea != idc.BADADDR:
    out.append("%08x: %s" % (ea, idc.generate_disasm_line(ea, 0)))
    ea = idc.next_head(ea, end)
with open(r"C:/Users/wande/Documents/ffx-editor-main/work/research_tools/ida_omd_disasm.txt", "w") as f:
    f.write("\n".join(out))
print("wrote %d lines" % len(out))
