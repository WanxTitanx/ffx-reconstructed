import subprocess, json, re, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")


def decode(raw: bytes) -> str:
    for enc in ("utf-16", "utf-8-sig", "utf-8"):
        try:
            return raw.decode(enc)
        except Exception:
            continue
    return raw.decode("utf-8", errors="replace")


targets = {
    "0x734a80": "pppChrSclXZMatrix", "0x734b00": "pppChrSclYMatrix",
    "0x734b70": "pppChrYSclXYZMatrix", "0x734bc0": "pppChrXSclXYZMatrix",
    "0x737280": "pppNeiChrPointLight", "0x7491a0": "pppKeMdlBmp",
}
for a, n in targets.items():
    r = subprocess.run(
        ["python", r"C:/Users/wande/Documents/ffx-editor-main/scripts/ida_mcp_client.py",
         "--port", "13337", "decompile", a],
        capture_output=True, timeout=25)
    out = decode(r.stdout)
    try:
        j = json.loads(out)
        code = j.get("code", "")
        fn = code.split("\\n")[0] if code else ""
    except Exception:
        code, fn = "", ""
    offs = sorted(set(int(x) for x in re.findall(r"a2\s*\+\s*(\d+)", code)))
    offs_hex = sorted(set(int(x, 16) for x in re.findall(r"a2\s*\+\s*0x([0-9A-Fa-f]+)", code)))
    offs = sorted(set(offs) | set(offs_hex))
    start = offs[0] if offs else None
    width = (offs[-1] - offs[0] + 4) if offs else None
    nargs = "4" if ("__fastcall" in fn and ", int a3, int a4" in code) or "int a4" in code else "3"
    print(f"{n} {a}: offs={offs} janela={start}+{width} args~{nargs} :: {fn[:90]}")
