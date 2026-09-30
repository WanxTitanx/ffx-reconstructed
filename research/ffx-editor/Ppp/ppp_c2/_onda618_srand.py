import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.18: SRandHCV/DownHCV payload (ease G/I) + FpPointLight addr errado
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

def rand_ease(op, addr, nota):
    v = fam.get(op, {})
    if not v:
        print(f"!! nao encontrado: {op}")
        return
    v.update({
        "status": "FECHADO", "payload_consumer": True, "editable": True,
        "window": {"start": 4, "width": 13},
        "fields": [
            {"name": "target", "offset": 4, "width": 4, "type": "s32", "semantics": "s32@+4 — offset node alvo (-1 = default)"},
            {"name": "ranges", "offset": 8, "width": 8, "type": "u16", "semantics": "4x s16 ranges @+8..+15 (4 canais)"},
            {"name": "ease", "offset": 16, "width": 1, "type": "u8", "semantics": "u8@+16 — parametro de ease"},
        ],
        "handler_addr": addr,
        "usage": (v.get("usage") or "") + " [ONDA6.18 " + nota + "]",
    })
    print(f"{op} FECHADO (4+13)")

rand_ease("pppSRandHCV", "0x7337B0", "decompile: FFX_MagicHost_ApplyTransformEase_G (4x s16 ranges, ease random)")
rand_ease("pppSRandDownHCV", "0x733DE0", "decompile: FFX_MagicHost_ApplyTransformEase_I (variante Down)")

fpl = fam.get("pppFpPointLight", {})
if fpl:
    fpl["usage"] = (fpl.get("usage") or "") + " [ONDA6.18: addr 0x75D8E0 = FieldMap_DebugOverlayRenderTriangle (debug, NAO handler de luz) — addr errado]"

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"embedded: {len(emb)}")
