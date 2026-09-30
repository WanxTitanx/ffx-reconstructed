import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.7 (GOAL 8h): VertexApDisPos/Lc PROVADOS payload por decompile
# (0x757D20 FFX_KR_ProcessAnimWithCaptureBatch: a2[0] u16 id, a2[2] u16 indice bit 0x8000 — janela 0..5
#  0x7580E0 FFX_KR_ProcessAnimWithCaptureBatch_B: mesma familia, variante B)
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

def vertex_family(op, addr, nota):
    v = fam.get(op, {})
    if not v:
        print(f"!! nao encontrado: {op}")
        return
    v.update({
        "status": "FECHADO", "payload_consumer": True, "editable": True,
        "window": {"start": 4, "width": 2},
        "fields": [
            {"name": "model_index", "offset": 4, "width": 2, "type": "u16",
             "semantics": "u16@+4 — indice de modelo/vertex; bit 0x8000 = flag especial"},
        ],
        "handler_addr": addr,
        "usage": (v.get("usage") or "") + " [ONDA6.7 " + nota + "]",
    })
    print(f"{op} FECHADO (4+2)")

vertex_family("pppVertexApDisPos", "0x757D20", "decompile: FFX_KR_ProcessAnimWithCaptureBatch (u16 id@+0, u16 indice@+4 bit 0x8000)")
vertex_family("pppVertexApLc", "0x7580E0", "decompile: FFX_KR_ProcessAnimWithCaptureBatch_B (variante B, mesmo padrao)")

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"embedded: {len(emb)}")
