import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.3 (GOAL 8h): consistencia do field_map — payload_consumer + FECHADO + window
# implica editable=true (janela provada = editavel no editor).
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

fixed = []
for k, v in fam.items():
    if v.get("payload_consumer") and (v.get("status") == "FECHADO") and v.get("window"):
        if not v.get("editable"):
            v["editable"] = True
            fixed.append(k)

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print(f"editable corrigido para true: {len(fixed)} familias")
for f in fixed:
    print(" -", f)
