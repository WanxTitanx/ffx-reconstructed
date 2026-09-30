import ida_hexrays, ida_name, json, re

# Rodada 2026-08-02 (lote 2) — prova as janelas dos handlers Rand Up/Down/Short.
targets = {
    0x72FEB0: "pppRandDownChar",
    0x730090: "pppRandShort",
    0x730260: "pppRandUpShort",
    0x730430: "pppRandDownShort",
    0x7307F0: "pppRandUpInt",
    0x7309C0: "pppRandDownInt",
    0x731AD0: "pppRandUpCV",
    0x731D30: "pppRandDownCV",
}

out = {}
for addr, name in targets.items():
    try:
        cf = ida_hexrays.decompile(addr)
        code = str(cf)
        offs = sorted({int(m) for m in re.findall(r"\*\([^)]*\)\(a2 \+ (\d+)\)", code)} |
                      {int(m) for m in re.findall(r"a2 \+ (\d+)", code)})
        cur = ida_name.get_name(addr)
        out[name] = {"addr": hex(addr), "cur": cur, "offsets": offs[:16], "max": max(offs) if offs else None}
    except Exception as e:
        out[name] = {"addr": hex(addr), "error": str(e)[:120]}

print(json.dumps(out))
