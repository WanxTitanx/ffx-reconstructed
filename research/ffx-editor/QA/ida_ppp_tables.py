import ida_bytes, ida_name, ida_funcs, json

# pppSysProgTbl @ 0xC3A500 — PPP system program table
out = {}
for base, label in [(0xC3A500, "pppSysProgTbl"), (0xC48E78, "g_FFX_MagicSidePassTable"), (0xC492C8, "g_FFX_MagicPostProcTable")]:
    entries = []
    for i in range(16):
        ea = base + i*4
        val = ida_bytes.get_dword(ea)
        f = ida_funcs.get_func(val) if val else None
        hname = ida_name.get_name(f.start_ea) if f else ""
        entries.append([hex(val), hname, hex(f.size()) if f else None])
    out[label] = entries

with open(r"C:\Users\wande\Documents\ffx-editor-main\work\research_tools\magic_ppp_tables.json", "w") as fp:
    json.dump(out, fp, indent=1)
print(json.dumps(out, indent=1))
