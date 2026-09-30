import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.14: stubs no-op confirmados no PC (handlers desativados que o PS2 tinha)
stubs = {
    "pppKeThLz": "0x75B7E0 = pppKeThLz_0 (STUB NO-OP)",
    "pppKeThLz_1": "0x75B7F0 = nullsub_672 (STUB NO-OP)",
}
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)
for op, nota in stubs.items():
    v = fam.get(op)
    if v:
        v["status"] = "SEM_PAYLOAD"
        v["payload_consumer"] = False
        v["usage"] = (v.get("usage") or "") + " [ONDA6.14: " + nota + "]"
json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("stubs registrados:", list(stubs))
