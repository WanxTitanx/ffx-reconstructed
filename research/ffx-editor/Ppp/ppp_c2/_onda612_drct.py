import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.12 (GOAL 8h): KeDrct + EiWfacc PROVADOS payload por decompile
# (0x75E520 FFX_Pmcom_MatchAndCopyPosition: 3x f32@+16/20/24 copia para node — janela 16..27
#  0x75BC20 FieldMap_ApplySpringForce: 5 valores @+4..+23 — janela 4..23)
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

def update(op, addr, win, fields, nota):
    v = fam.get(op, {})
    if not v:
        print(f"!! nao encontrado: {op}")
        return
    v.update({
        "status": "FECHADO", "payload_consumer": True, "editable": True,
        "window": {"start": win[0], "width": win[1]},
        "fields": fields,
        "handler_addr": addr,
        "usage": (v.get("usage") or "") + " [ONDA6.12 " + nota + "]",
    })
    print(f"{op} FECHADO ({win[0]}+{win[1]})")

update("pppKeDrct", "0x75E520", (16, 12), [
    {"name": "pos_x", "offset": 16, "width": 4, "type": "f32", "semantics": "f32@+16 — posicao X (copiada p/ node)"},
    {"name": "pos_y", "offset": 20, "width": 4, "type": "f32", "semantics": "f32@+20 — posicao Y"},
    {"name": "pos_z", "offset": 24, "width": 4, "type": "f32", "semantics": "f32@+24 — posicao Z"},
], "decompile: FFX_Pmcom_MatchAndCopyPosition (match id, copia 3x f32 p/ node)")

update("pppEiWfacc", "0x75BC20", (4, 20), [
    {"name": "spring_a", "offset": 4, "width": 4, "type": "f32", "semantics": "f32@+4 — parametro de mola"},
    {"name": "spring_b", "offset": 8, "width": 4, "type": "f32", "semantics": "f32@+8 — parametro de mola"},
    {"name": "spring_c", "offset": 12, "width": 4, "type": "f32", "semantics": "f32@+12 — parametro de mola"},
    {"name": "spring_d", "offset": 16, "width": 4, "type": "f32", "semantics": "f32@+16 — parametro de mola"},
    {"name": "spring_e", "offset": 20, "width": 4, "type": "f32", "semantics": "f32@+20 — parametro de mola"},
], "decompile: FieldMap_ApplySpringForce (5 valores de forca de mola)")

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"embedded: {len(emb)}")
