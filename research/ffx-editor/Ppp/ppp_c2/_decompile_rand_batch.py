import subprocess, json, re, sys, time
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

batch = sys.argv[1]  # a/b/c
addrs_all = {
    "a": {"0x72f590": "pppRandFloat", "0x72f930": "pppRandDownFloat",
          "0x730ba0": "pppRandFV", "0x730dd0": "pppRandUpFV", "0x730fd0": "pppRandDownFV"},
    "b": {"0x7311e0": "pppRandIV", "0x731640": "pppRandDownIV",
          "0x732200": "pppRandUpHCV", "0x732460": "pppRandDownHCV"},
    "c": {"0x732980": "pppSRandUpFV", "0x732c10": "pppSRandDownFV", "0x732ea0": "pppSRandCV"},
}
addrs = addrs_all[batch]


def decode(raw: bytes) -> str:
    for enc in ("utf-16", "utf-8-sig", "utf-8"):
        try:
            return raw.decode(enc)
        except Exception:
            continue
    return raw.decode("utf-8", errors="replace")


results = {}
for a, n in addrs.items():
    r = subprocess.run(
        ["python", r"C:/Users/wande/Documents/ffx-editor-main/scripts/ida_mcp_client.py",
         "--port", "13337", "decompile", a],
        capture_output=True, timeout=25)
    out = decode(r.stdout)
    try:
        j = json.loads(out)
        code = j.get("code", "")
    except Exception:
        code = ""
    offs = sorted(set(int(x) for x in re.findall(r"a2 \+ (\d+)", code)))
    offs_hex = sorted(set(int(x, 16) for x in re.findall(r"a2 \+ 0x([0-9A-Fa-f]+)", code)))
    offs = sorted(set(offs) | set(offs_hex))
    start = offs[0] if offs else None
    width = (offs[-1] - offs[0] + 4) if offs else None
    results[n] = {"addr": a, "offsets": offs, "window": f"{start}+{width}" if start is not None else None}
    print(f"{n} {a}: offs={offs} janela={results[n]['window']}", flush=True)

out_path = r"C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/rand_windows_" + batch + ".json"
json.dump(results, open(out_path, "w"), indent=1)
print("salvo", out_path, flush=True)


