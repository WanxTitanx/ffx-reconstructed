import json, sys
from collections import Counter
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Classifica os 83 opcodes EXE-only (stubs/reservados/knobs/internos).
cat = json.load(open(r"C:/Users/wande/Documents/ffx-editor-main/work/magic_editor/EXE_ONLY_CATALOG.json"))
fm = json.load(open(r"C:/Users/wande/Documents/ffx-editor-main/work/magic_editor/field_map.json", encoding="utf-8"))
fams = fm["families"]

stubs = [r for r in cat if r["handler"] == "0x0"]
reserved = [r for r in cat if r["slot"] == 0 and r["handler"] != "0x0"]  # slot 0 = sem handler?
knobs = [r for r in cat if r["handler"] != "0x0" and r["name"] in fams and fams[r["name"]].get("payload_consumer")]
internal = [r for r in cat if r["handler"] != "0x0" and r not in knobs and r not in reserved]

print(f"Total: {len(cat)}")
print(f"Stubs nullsub (handler 0x0): {len(stubs)}")
print(f"Reservados (sem handler): {len(reserved)}")
print(f"KNOBS (payload_consumer): {len(knobs)}")
print(f"Internos (node/estado): {len(internal)}")

print("\n--- STUBS ---")
print(", ".join(r["name"] for r in stubs))
print("\n--- KNOBS ---")
for r in knobs:
    w = fams[r["name"]].get("window", {})
    print(f"  {r['name']}: {r['handler']} janela {w}")
print("\n--- RESERVADOS (amostra) ---")
print(", ".join(r["name"] for r in reserved[:15]))
print("\n--- INTERNOS (amostra) ---")
print(", ".join(r["name"] for r in internal[:15]))
