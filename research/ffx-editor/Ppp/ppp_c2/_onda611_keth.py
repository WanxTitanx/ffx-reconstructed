import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.11 (GOAL 8h): KeThTp PROVADO payload por decompile
# (0x736E40 FieldMap_SetTransformAndAccumulate: 3x f32@+4/8/12 set transform, refs@+16/20 — janela 4..23)
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

v = fam.get("pppKeThTp", {})
assert v, "pppKeThTp nao encontrado"
v.update({
    "status": "FECHADO", "payload_consumer": True, "editable": True,
    "window": {"start": 4, "width": 20},
    "fields": [
        {"name": "pos_x", "offset": 4, "width": 4, "type": "f32", "semantics": "f32@+4 — posicao X (set transform)"},
        {"name": "pos_y", "offset": 8, "width": 4, "type": "f32", "semantics": "f32@+8 — posicao Y"},
        {"name": "pos_z", "offset": 12, "width": 4, "type": "f32", "semantics": "f32@+12 — posicao Z"},
        {"name": "ref_a", "offset": 16, "width": 4, "type": "s32", "semantics": "s32@+16 — ref de node (-1 = nulo)"},
        {"name": "ref_b", "offset": 20, "width": 4, "type": "s32", "semantics": "s32@+20 — ref de node (-1 = nulo)"},
    ],
    "usage": (v.get("usage") or "") + " [ONDA6.11 decompile 0x736E40: set transform + acumula em node]",
})

hit = fam.get("pppKeThHitBorn", {})
if hit:
    hit["usage"] = (hit.get("usage") or "") + " [ONDA6.11: 0x759E70 = FieldMap_WalkStructTransparencyNodes (le a2+12 u8) — payload marginal, manter SEM_PAYLOAD]"

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"KeThTp FECHADO (4+20) | embedded: {len(emb)}")
