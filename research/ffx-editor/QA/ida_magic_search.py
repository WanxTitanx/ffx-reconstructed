import ida_funcs, ida_name, json

def find_funcs(substr, limit=500):
    results = []
    qty = ida_funcs.get_func_qty()
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        name = ida_name.get_name(f.start_ea)
        if name and substr.lower() in name.lower():
            results.append([hex(f.start_ea), name, hex(f.size())])
            if len(results) >= limit:
                break
    return results

out = {}
for s in ["Magic", "Ego", "SeSep", "Ppp"]:
    out[s] = find_funcs(s)

with open(r"C:\Users\wande\Documents\ffx-editor-main\work\research_tools\magic_funcs_search.json", "w") as fp:
    json.dump(out, fp, indent=1)
print("DONE", {k: len(v) for k, v in out.items()})
