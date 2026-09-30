import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.13 (GOAL 8h): KeShpTailPht PROVADO payload por decompile
# (0x754000 FFX_KR_InitTableStructArray: a2+28/32/36 (4B), a2+48..94 (u16s), __int16@+94 — janela 28..95)
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

v = fam.get("pppKeShpTailPht", {})
assert v, "pppKeShpTailPht nao encontrado"
v.update({
    "status": "FECHADO", "payload_consumer": True, "editable": True,
    "window": {"start": 28, "width": 68},
    "fields": [
        {"name": "param_a", "offset": 28, "width": 4, "type": "u32", "semantics": "u32@+28 — parametro do init de tabela"},
        {"name": "param_b", "offset": 32, "width": 4, "type": "u32", "semantics": "u32@+32 — parametro do init de tabela"},
        {"name": "param_c", "offset": 36, "width": 4, "type": "u32", "semantics": "u32@+36 — parametro do init de tabela"},
        {"name": "table_data", "offset": 48, "width": 46, "type": "u16", "semantics": "u16s @+48..+94 — dados da tabela (init de array de structs)"},
        {"name": "tail", "offset": 94, "width": 2, "type": "s16", "semantics": "s16@+94 — valor final"},
    ],
    "usage": (v.get("usage") or "") + " [ONDA6.13 decompile 0x754000: init de array de structs (KR table)]",
})
json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"KeShpTailPht FECHADO (28+68) | embedded: {len(emb)}")
