import subprocess, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")


def decode(raw: bytes) -> str:
    for enc in ("utf-16", "utf-8-sig", "utf-8"):
        try:
            return raw.decode(enc)
        except Exception:
            continue
    return raw.decode("utf-8", errors="replace")


for a, n in [("0x730ba0", "pppRandFV"), ("0x732200", "pppRandUpHCV")]:
    r = subprocess.run(
        ["python", r"C:/Users/wande/Documents/ffx-editor-main/scripts/ida_mcp_client.py",
         "--port", "13337", "decompile", a],
        capture_output=True, timeout=25)
    print("=" * 20, n, a, "rc:", r.returncode)
    print(decode(r.stdout)[:1200])
    print("STDERR:", decode(r.stderr)[:300])
