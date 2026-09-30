import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.13b: KeShpTailLc = stub no-op (pppNeiDrawShapePointLight)
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)
v = fam.get("pppKeShpTailLc", {})
if v:
    v["status"] = "SEM_PAYLOAD"
    v["payload_consumer"] = False
    v["usage"] = (v.get("usage") or "") + " [ONDA6.13: 0x7550A0 = pppNeiDrawShapePointLight (STUB NO-OP no PC)]"
    json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
    print("KeShpTailLc = stub no-op registrado")
