import re, sys, json
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Extrai a instructionTable completa do particle.ts (noclip) — opcode -> classe + formato.
s = open(r"C:/Users/wande/Documents/ffx-editor-main/work/noclip_reference/particle.ts", encoding="utf-8").read()
i = s.find("const instructionTable")
j = s.find("];", i)
tbl = s[i:j + 2]

rows = []
for m in re.finditer(r"_\s*\(\s*0x([0-9A-Fa-f]+)\s*,\s*([A-Za-z.]+)(?:\s*,\s*([A-Za-z0-9_]+))?\s*\)", tbl):
    op = int(m.group(1), 16)
    cls = m.group(2)
    fmt = m.group(3) or ""
    rows.append((op, cls, fmt))
for m in re.finditer(r"Q\s*\(\s*0x([0-9A-Fa-f]+)\s*,\s*([A-Za-z.]+)(?:\s*,\s*([A-Za-z0-9_]+))?\s*\)", tbl):
    op = int(m.group(1), 16)
    cls = m.group(2)
    fmt = m.group(3) or ""
    rows.append((op, cls, fmt))

rows.sort()
print(f"entries: {len(rows)}")
for op, cls, fmt in rows:
    print(f"  0x{op:02X}: {cls} ({fmt})")

json.dump(rows, open(r"C:/Users/wande/Documents/ffx-editor-main/work/noclip_reference/instruction_table_20260802.json", "w"), indent=0)
print("salvo em instruction_table_20260802.json")
