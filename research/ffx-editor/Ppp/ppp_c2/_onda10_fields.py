import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 10 (GOAL 8h): declara FIELDS genericos para as payloads do sweep que nao tem
# (janela provada -> campos tipados editaveis no editor). Padrao por familia.
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

def generic_fields(ws, ww, kind):
    """Gera campos para a janela (ws..ws+ww). kind: f32 (todos f32), u16 (todos u16), mix."""
    fields = []
    off = ws
    i = 0
    while off < ws + ww:
        w = 4 if kind == "f32" else 2
        if kind == "mix":
            w = 4 if i % 2 == 0 else 2
        if off + w > ws + ww:
            w = ws + ww - off
        if w <= 0:
            break
        t = "f32" if w == 4 else "u16"
        fields.append({"name": f"v{i}", "offset": off, "width": w, "type": t,
                       "semantics": f"campo {i} (janela {ws}+{ww} provada por decompile)"})
        off += w
        i += 1
    return fields

# familias do sweep sem fields: (opcode, kind)
sem_fields = [(k, v) for k, v in fam.items() if v.get("payload_consumer") and not v.get("fields")]
print(f"payloads sem fields: {len(sem_fields)}")

applied = 0
for op, v in sem_fields:
    win = v.get("window")
    if not win:
        continue
    ws, ww = win["start"], win["width"]
    # heuristica de tipo por familia
    if any(x in op for x in ("Color", "KeLns", "Col")):
        kind = "u16"
    elif any(x in op for x in ("Draw", "KeShpTail3", "KeBorn", "KeTh", "KeHit", "KeGrv")):
        kind = "mix"
    else:
        kind = "f32"
    v["fields"] = generic_fields(ws, ww, kind)
    applied += 1

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"fields declarados: {applied} | embedded: {len(emb)}")
