import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.10 (GOAL 8h): MoveLoop/SclMoveLoop PROVADOS payload por decompile
# (0x75C1A0 FieldMap_AccumulateTripleLayerDelta: a2+16/20/24 = 3x f32, camada tripla — janela 16..27
#  0x75C380 FFX_BoneAnim_ApplyDeltaFloat3: idem — janela 16..27)
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

def loop_family(op, addr, nota):
    v = fam.get(op, {})
    if not v:
        print(f"!! nao encontrado: {op}")
        return
    v.update({
        "status": "FECHADO", "payload_consumer": True, "editable": True,
        "window": {"start": 16, "width": 12},
        "fields": [
            {"name": "delta_x", "offset": 16, "width": 4, "type": "f32", "semantics": "f32@+16 — delta X por frame (loop)"},
            {"name": "delta_y", "offset": 20, "width": 4, "type": "f32", "semantics": "f32@+20 — delta Y por frame (loop)"},
            {"name": "delta_z", "offset": 24, "width": 4, "type": "f32", "semantics": "f32@+24 — delta Z por frame (loop)"},
        ],
        "handler_addr": addr,
        "usage": (v.get("usage") or "") + " [ONDA6.10 " + nota + "]",
    })
    print(f"{op} FECHADO (16+12)")

loop_family("pppMoveLoop", "0x75C1A0", "decompile: FieldMap_AccumulateTripleLayerDelta (3x f32@+16/20/24, camada tripla node0+=node1+=delta)")
loop_family("pppSclMoveLoop", "0x75C380", "decompile: FFX_BoneAnim_ApplyDeltaFloat3 (3x f32@+16/20/24, idem)")

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"embedded: {len(emb)}")
