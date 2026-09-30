import ida_hexrays, ida_name, json, re

# Lote final draw: confirmar janelas Ts2 (0x738F80), CameraLoop (0x73FB10), Semi (0x737BE0).
targets = {
    0x738F80: "pppDrawMdlTs2",
    0x73FB10: "pppDrawMdlCameraLoop",
    0x737BE0: "pppDrawMdlSemi",
}

out = {}
for addr, name in targets.items():
    try:
        cf = ida_hexrays.decompile(addr)
        code = str(cf)
        offs = sorted({int(m) for m in re.findall(r"\*\([^)]*\)\(a3 \+ (\d+)\)", code)} |
                      {int(m) for m in re.findall(r"a3 \+ (\d+)", code)} |
                      {int(m) * 4 for m in re.findall(r"a3\[(\d+)\]", code)})
        cur = ida_name.get_name(addr)
        out[name] = {"addr": hex(addr), "cur": cur, "offsets": offs[:20], "max": max(offs) if offs else None}
    except Exception as e:
        out[name] = {"addr": hex(addr), "error": str(e)[:120]}

print(json.dumps(out))
