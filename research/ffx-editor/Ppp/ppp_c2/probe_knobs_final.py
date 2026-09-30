import ida_hexrays, ida_name, json, re

# Lote final — confirmacao das janelas dos 3 knobs complexos restantes.
targets = {
    0x736110: "pppKeTh",
    0x75D540: "pppEiWindFun",
    0x75D7F0: "pppNeiPointLight",
}

out = {}
for addr, name in targets.items():
    try:
        cf = ida_hexrays.decompile(addr)
        code = str(cf)
        offs = sorted({int(m) for m in re.findall(r"\*\([^)]*\)\(a2 \+ (\d+)\)", code)} |
                      {int(m) for m in re.findall(r"a2 \+ (\d+)", code)} |
                      {int(m) for m in re.findall(r"a2\[(\d+)\]", code)})
        # a2[N] = byte offset N*4
        offs4 = sorted({int(m) * 4 for m in re.findall(r"a2\[(\d+)\]", code)})
        all_offs = sorted(set(offs) | set(offs4))
        cur = ida_name.get_name(addr)
        out[name] = {"addr": hex(addr), "cur": cur, "offsets": all_offs[:24],
                     "max": max(all_offs) if all_offs else None}
    except Exception as e:
        out[name] = {"addr": hex(addr), "error": str(e)[:120]}

print(json.dumps(out))
