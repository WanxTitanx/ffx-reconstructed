import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.4 (GOAL 8h): ColAccele provado PAYLOAD por decompile (0x75BB30 =
# FieldMap_AccumulateWordLayerDelta, byte-identico ao ColMove: +0 id, +8..+15 = 4x u16).
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

col_accele = fam.get("pppColAccele", {})
assert col_accele, "pppColAccele nao encontrado"
col_accele["status"] = "FECHADO"
col_accele["payload_consumer"] = True
col_accele["editable"] = True
col_accele["window"] = {"start": 8, "width": 8}
col_accele["fields"] = [
    {"name": "delta_r", "offset": 8, "width": 2, "type": "u16", "semantics": "delta de cor canal R (u16) — igual ColMove (decompile 0x75BB30)"},
    {"name": "delta_g", "offset": 10, "width": 2, "type": "u16", "semantics": "delta de cor canal G (u16)"},
    {"name": "delta_b", "offset": 12, "width": 2, "type": "u16", "semantics": "delta de cor canal B (u16)"},
    {"name": "delta_a", "offset": 14, "width": 2, "type": "u16", "semantics": "delta de cor canal A (u16)"},
]
col_accele["usage"] = (col_accele.get("usage") or "") + " [ONDA6.4 decompile 0x75BB30: payload 4x u16 @+8..+15, byte-identico ao ColMove]"

# KeGrvEff: addr errado (0x759740 = FFX_FieldMap_CheckAndRenderObject, funcao de campo) — nota honesta
kegrv = fam.get("pppKeGrvEff", {})
if kegrv:
    kegrv["usage"] = (kegrv.get("usage") or "") + " [ONDA6.4: addr 0x759740 = FFX_FieldMap_CheckAndRenderObject (NAO handler PPP) — classificar por outro addr se existir]"

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)

# regenera embedded
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"ColAccele FECHADO (payload 8+8) | embedded: {len(emb)}")
