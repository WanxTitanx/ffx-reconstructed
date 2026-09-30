import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.15: familia KeThCp/Sft do PC = stubs no-op (copia/thread desativada no Remaster)
stubs = {
    "pppKeThCp": "0x75B7A0 = pppKeThCp (STUB NO-OP)",
    "pppKeThCpSft": "0x75B7B0 = pppKeThCpSft (STUB NO-OP)",
}
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)
for op, nota in stubs.items():
    v = fam.get(op)
    if v:
        v["status"] = "SEM_PAYLOAD"
        v["payload_consumer"] = False
        v["usage"] = (v.get("usage") or "") + " [ONDA6.15: " + nota + "]"
json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("stubs registrados:", list(stubs))
