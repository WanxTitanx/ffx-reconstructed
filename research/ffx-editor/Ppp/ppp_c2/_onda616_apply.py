import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.16: payloads achados no SWEEP automatizado (decompile -> le a2+offset)
# Cada: (opcode, addr, window_start, window_width, desc)
achados = [
    ("pppPointLoop",    "0x75C5F0", 16, 12, "FFX_BoneAnim_CheckAndApplyTransform — 3x f32@+16/20/24"),
    ("pppScaleLoop",    "0x75D180", 16, 12, "idem loop — 3x f32@+16/20/24"),
    ("pppKeBornRnd",    "0x7585C0", 4, 21,  "nascimento random (le a2+20)"),
    ("pppKeBornRnd2",   "0x7588A0", 4, 25,  "nascimento random v2 (le a2+24)"),
    ("pppKeGrvTgt",     "0x7598A0", 4, 9,   "gravidade alvo (le a2+8)"),
    ("pppKeHitBall",    "0x759920", 4, 5,   "hit ball (le a2+4)"),
    ("pppKeZCrct",      "0x735230", 4, 49,  "correcao Z (le a2+48)"),
    ("pppParMatrix",    "0x734710", 4, 5,   "parent matrix (le a2+4)"),
    ("pppPointAp",      "0x7574B0", 4, 5,   "point apply (le a2+4)"),
    ("pppPointRAp",     "0x757580", 4, 29,  "point reverse apply (le a2+28)"),
    ("pppSRandFV",      "0x7326C0", 4, 33,  "SRandFV EXISTE (addr 0x7326C0, le a2+32) — CORRECAO do fantasma"),
    ("pppNeiLightEikyo","0x75D6C0", 4, 25,  "luz vizinha (le a2+24)"),
    ("pppVertexAttend", "0x75D430", 4, 13,  "vertex attend (le a2+12)"),
    ("pppVtMime",       "0x72EC00", 4, 21,  "vertex mime (le a2+20)"),
    ("pppKeMatSN",      "0x7340F0", 4, 169, "material SN (le a2+168)"),
    ("pppKeMdlDtt",     "0x72E870", 4, 169, "model detail (le a2+168)"),
]

path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

for op, addr, ws, ww, desc in achados:
    v = fam.get(op)
    if v is None:
        print(f"!! nao encontrado: {op}")
        continue
    v["status"] = "FECHADO"
    v["payload_consumer"] = True
    v["editable"] = True
    v["window"] = {"start": ws, "width": ww}
    v["handler_addr"] = addr
    v["usage"] = (v.get("usage") or "") + f" [ONDA6.16 sweep: {desc}]"
    print(f"{op} FECHADO ({ws}+{ww})")

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"\nembedded: {len(emb)}")
