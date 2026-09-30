import subprocess, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")


def decode(raw: bytes) -> str:
    for enc in ("utf-16", "utf-8-sig", "utf-8"):
        try:
            return raw.decode(enc)
        except Exception:
            continue
    return raw.decode("utf-8", errors="replace")


for a, n in [("0x75d370", "pppPObjPoint"), ("0x72ef30", "pppKeTkFade")]:
    r = subprocess.run(
        ["python", r"C:/Users/wande/Documents/ffx-editor-main/scripts/ida_mcp_client.py",
         "--port", "13337", "decompile", a],
        capture_output=True, timeout=25)
    print("=" * 20, n, a, "rc:", r.returncode)
    print(decode(r.stdout)[:900])
