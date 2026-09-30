import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.6 (GOAL 8h): pppVertexApAt PROVADO payload por decompile
# (0x7583D0: u16@+4 indice de modelo (bit 0x8000 flag), u8@+6, u8@+8 — janela 4..8)
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

v = fam.get("pppVertexApAt", {})
assert v, "pppVertexApAt nao encontrado"
v.update({
    "status": "FECHADO", "payload_consumer": True, "editable": True,
    "window": {"start": 4, "width": 5},
    "fields": [
        {"name": "model_index", "offset": 4, "width": 2, "type": "u16",
         "semantics": "u16@+4 — indice de modelo/vertex; bit 0x8000 = flag especial"},
        {"name": "count", "offset": 6, "width": 1, "type": "u8",
         "semantics": "u8@+6 — contador/parametro"},
        {"name": "mode", "offset": 8, "width": 1, "type": "u8",
         "semantics": "u8@+8 — modo (1 = random via srand/RandomFloat01)"},
    ],
    "usage": (v.get("usage") or "") + " [ONDA6.6 decompile 0x7583D0: vertex apply com timing + random]",
})
json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"VertexApAt FECHADO (4+5) | embedded: {len(emb)}")
