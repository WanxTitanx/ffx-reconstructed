import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 10b: CORRIGE os fields genericos — tipo SEMPRE compativel com o width real
# (4B=f32, 2B=u16, 1B=u8; nunca gera width 1/3 com tipo u16/f32 — isso lancava
# ArgumentOutOfRange no BitConverter.ToUInt16(span de 1 byte)).
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

def gen_fields(ws, ww):
    fields = []
    off = ws
    i = 0
    end = ws + ww
    while off < end:
        remaining = end - off
        # largura do campo: 4 se couber, 2 se couber, 1 se sobrar
        w = 4 if remaining >= 4 else (2 if remaining >= 2 else 1)
        t = "f32" if w == 4 else ("u16" if w == 2 else "u8")
        fields.append({"name": f"v{i}", "offset": off, "width": w, "type": t,
                       "semantics": f"campo {i} (janela {ws}+{ww} provada por decompile)"})
        off += w
        i += 1
    return fields

fixed = 0
for op, v in fam.items():
    if not v.get("payload_consumer"):
        continue
    win = v.get("window")
    if not win or not v.get("fields"):
        continue
    # regenera so os que tem campos "genéricos" (vN) — preserva os nomeados manualmente
    if any(f.get("name", "").startswith("v") for f in v["fields"]):
        v["fields"] = gen_fields(win["start"], win["width"])
        fixed += 1

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"fields regenerados com tipos corretos: {fixed} | embedded: {len(emb)}")

# validacao: nenhum campo com width 1/3 e tipo u16/f32
bad = []
for op, v in fam.items():
    for f in (v.get("fields") or []):
        if f["width"] == 1 and f["type"] in ("u16", "f32", "s16", "s32", "u32"):
            bad.append((op, f["name"], f["width"], f["type"]))
        if f["width"] == 3 and f["type"] in ("u16", "f32"):
            bad.append((op, f["name"], f["width"], f["type"]))
print("campos invalidos restantes:", bad if bad else "NENHUM ✓")
