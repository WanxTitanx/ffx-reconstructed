import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6 (GOAL 8h): declara os FIELDS das familias Rand provadas na Onda 1
# (decompile na canonica: target u32@+4, delta(s), flag) — sem fields o
# ResolveAllFields retorna vazio e o editor nao mostra nada editavel.

path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

def fields_rand(target_type="u32", delta_type="f32", delta_off=8, delta_width=4, flag_off=None):
    """Padrao provado por decompile (Onda 1): target u32@+4, delta@+8.., flag u8 no fim."""
    f = [
        {"name": "target", "offset": 4, "width": 4, "type": target_type,
         "semantics": "target u32@+4 — offset do campo a mutar (rel. node); -1 = ppvDbgTemp"},
        {"name": "delta", "offset": delta_off, "width": delta_width, "type": delta_type,
         "semantics": "delta@+8 — valor somado a *target (int)(rng * delta - delta)"},
    ]
    if flag_off is not None:
        f.append({"name": "flag_double_random", "offset": flag_off, "width": 1, "type": "u8",
                  "semantics": "flag u8 — 1 = double-random (2 sorteios)"})
    return f

# Rand com delta f32 4B (FV/IV/SRand*): janela 4+32 -> target@+4, delta@+8 (4B), flag@+12
rand32 = {op: fields_rand("u32", "f32", 8, 4, 12) for op in
          ["pppRandFV", "pppRandUpFV", "pppRandDownFV", "pppRandIV", "pppRandUpIV", "pppRandDownIV",
           "pppSRandFV", "pppSRandUpFV", "pppSRandDownFV", "pppSRandCV", "pppSRandUpFV2", "pppSRandDownFV2"]}

# Rand Char (6B): target@+4 u32, delta@+8 u8, flag@+9
rand_char = {op: fields_rand("u32", "u8", 8, 1, 9) for op in
             ["pppRandChar", "pppRandUpChar", "pppRandDownChar"]}

# Rand Short (7B): target@+4 u32, delta@+8 u16, flag@+10
rand_short = {op: fields_rand("u32", "u16", 8, 2, 10) for op in
              ["pppRandShort", "pppRandUpShort", "pppRandDownShort"]}

# Rand Int (9B): target@+4 u32, delta@+8 u32 (int), flag@+12
rand_int = {op: fields_rand("u32", "s32", 8, 4, 12) for op in
            ["pppRandInt", "pppRandUpInt", "pppRandDownInt"]}

# Rand CV (9B): target@+4 u32, 4x delta s8@+8..+11, flag@+12
rand_cv = {op: [
    {"name": "target", "offset": 4, "width": 4, "type": "u32",
     "semantics": "target u32@+4 — offset do campo a mutar (rel. node); -1 = ppvDbgTemp"},
    {"name": "delta_x", "offset": 8, "width": 1, "type": "s8", "semantics": "delta s8@+8 (4 canais)"},
    {"name": "delta_y", "offset": 9, "width": 1, "type": "s8", "semantics": "delta s8@+9"},
    {"name": "delta_z", "offset": 10, "width": 1, "type": "s8", "semantics": "delta s8@+10"},
    {"name": "delta_w", "offset": 11, "width": 1, "type": "s8", "semantics": "delta s8@+11"},
    {"name": "flag_double_random", "offset": 12, "width": 1, "type": "u8", "semantics": "flag u8 — 1 = double-random"},
] for op in ["pppRandCV", "pppRandUpCV", "pppRandDownCV"]}

# DrawMdlTs2 (8+28): drawable@+8 u32, params@+12.. — minimo honesto
draw_ts2 = {"pppDrawMdlTs2": [
    {"name": "drawable", "offset": 8, "width": 4, "type": "u32",
     "semantics": "drawable u32@+8 — recurso de textura (cadeia draw)"},
]}

all_fields = {}
for g in (rand32, rand_char, rand_short, rand_int, rand_cv, draw_ts2):
    all_fields.update(g)

applied = 0
for op, fields in all_fields.items():
    v = fam.get(op)
    if v is None:
        print(f"!! nao encontrado: {op}")
        continue
    if v.get("fields"):
        print(f"!! ja tem fields: {op} ({len(v['fields'])}) — mantido")
        continue
    v["fields"] = fields
    applied += 1

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print(f"fields declarados: {applied} familias")
for op in all_fields:
    print(" -", op, f"({len(all_fields[op])} fields)")
