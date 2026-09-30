import ida_search, ida_hexrays, json, os

OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\spheregrid_re"

def find_imm_loop(val, limit=60):
    hits = []
    ea = 0x401000
    while True:
        ea, found = ida_search.find_imm(ea, 1, val)
        if ea == 0xFFFFFFFFFFFFFFFF or ea == 0:
            break
        hits.append(ea)
        ea += 1
        if len(hits) >= limit:
            break
    return [hex(h) for h in hits]

def decompile_to_file(ea, name):
    try:
        cf = ida_hexrays.decompile(ea)
        code = str(cf) if cf else "DECOMPILE FAILED"
    except Exception as e:
        code = "EXC: %r" % e
    with open(os.path.join(OUT, name + ".txt"), "w", encoding="utf-8") as f:
        f.write(code)
    return len(code)

report = {}
report["imm_41252"] = find_imm_loop(41252)
report["imm_41328"] = find_imm_loop(41328)
report["imm_860"] = find_imm_loop(860)
report["len_681DB0"] = decompile_to_file(0x681DB0, "decompile_681DB0")
report["len_A47D50"] = decompile_to_file(0xA47D50, "decompile_A47D50")
report["len_43F0AE"] = decompile_to_file(0x43F0AE, "decompile_43F0AE")

with open(os.path.join(OUT, "probe_report.json"), "w") as f:
    json.dump(report, f, indent=2)
print(json.dumps(report))
