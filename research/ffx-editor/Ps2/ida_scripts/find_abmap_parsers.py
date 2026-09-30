import idautils, idc, ida_funcs, json

targets = [0x2305800, 0x23057FC, 0x23057F8, 0x23057F4, 0x23057F0, 0x23057EC]
results = {}
for t in targets:
    for x in idautils.XrefsTo(t, 0):
        f = ida_funcs.get_func(x.frm)
        if f:
            results.setdefault(f.start_ea, set()).add(x.frm)

out = []
for faddr, refs in sorted(results.items()):
    name = idc.get_func_name(faddr)
    out.append({"func": hex(faddr), "name": name, "refs": [hex(r) for r in sorted(refs)]})
print(json.dumps(out, indent=1))
