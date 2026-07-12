#!/usr/bin/env python3
"""Generate INDEX.md from the function list JSON."""
import json, os

DIR = os.path.dirname(os.path.abspath(__file__))
FUNCS_FILE = os.path.join(DIR, "funcs_400000_600000.json")

with open(FUNCS_FILE, "r") as f:
    funcs = json.load(f)

def sanitize(name):
    return "".join(c if c.isalnum() or c in "._-" else "_" for c in name)

lines = []
lines.append("# Pseudocode Index — Address Range 0x400000–0x600000")
lines.append("")
lines.append(f"**Total functions in range: {len(funcs)}**")
lines.append("")
lines.append("| # | Address | Name | Size | Status |")
lines.append("|---|---------|------|------|--------|")

for i, f in enumerate(funcs):
    addr = f["addr"]
    name = f["name"]
    size = f.get("size", "?")
    safe = sanitize(name)
    fname = f"{addr.replace('0x','').lower()}_{safe}.c"
    status = "Not extracted — IDA MCP disconnected"
    lines.append(f"| {i+1} | {addr} | `{name}` | {size} | {status} |")

lines.append("")
lines.append("## Notes")
lines.append("")
lines.append("- Extraction was interrupted when the IDA MCP server disconnected.")
lines.append("- The function list was collected from IDA DB session with Hex-Rays decompiler.")
lines.append("- To complete extraction: reconnect IDALIB MCP server and re-run extract_all.py.")
lines.append("- Script extract_all.py is ready for batch processing via idalib_analyze_batch.")
lines.append("- Source DB: ffx_exe_copy.i64 (imagebase 0x400000)")
lines.append("")

idx_path = os.path.join(DIR, "INDEX.md")
with open(idx_path, "w", encoding="utf-8") as f:
    f.write("\n".join(lines))

print(f"INDEX.md created: {len(funcs)} function entries")
