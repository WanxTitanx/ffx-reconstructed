import ida_hexrays, ida_name, json, re

# Lote 3 — prova as janelas das famílias derivadas restantes.
targets = {
    0x72FCD0: "pppRandUpChar",
    0x749C10: "pppKeMdlTfd2",
    0x749F60: "pppKeMdlTfd3",
}

out = {}
for addr, name in targets.items():
    try:
        cf = ida_hexrays.decompile(addr)
        code = str(cf)
        offs = sorted({int(m) for m in re.findall(r"\*\([^)]*\)\(a2 \+ (\d+)\)", code)} |
                      {int(m) for m in re.findall(r"a2 \+ (\d+)", code)})
        cur = ida_name.get_name(addr)
        out[name] = {"addr": hex(addr), "cur": cur, "offsets": offs[:20], "max": max(offs) if offs else None}
    except Exception as e:
        out[name] = {"addr": hex(addr), "error": str(e)[:120]}

print(json.dumps(out))
