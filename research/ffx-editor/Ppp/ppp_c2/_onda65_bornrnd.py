import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.5 (GOAL 8h): KeBornRnd5/6 PROVADOS payload por decompile
# (0x759010 FieldMap_WalkStructEntry_Sub: +4 u16, +12/13/14 u8, +16/+24 s32 refs — janela 4..24
#  0x7592F0 FieldMap_WalkStructEntry2_Sub: +4 u16, +6/7/8 u8, +12/+20 s32 refs — janela 4..20)
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

def born5():
    return {
        "status": "FECHADO", "payload_consumer": True, "editable": True,
        "window": {"start": 4, "width": 21},
        "fields": [
            {"name": "countdown", "offset": 4, "width": 2, "type": "u16", "semantics": "u16@+4 — parametro de trigger (nascimento)"},
            {"name": "flag_active", "offset": 12, "width": 1, "type": "u8", "semantics": "u8@+12 — flag de ativacao"},
            {"name": "trigger", "offset": 13, "width": 1, "type": "u8", "semantics": "u8@+13 — trigger de nascimento"},
            {"name": "flag2", "offset": 14, "width": 1, "type": "u8", "semantics": "u8@+14 — flag secundaria"},
            {"name": "ref_a", "offset": 16, "width": 4, "type": "s32", "semantics": "s32@+16 — ref de node (-1 = nulo)"},
            {"name": "ref_b", "offset": 24, "width": 4, "type": "s32", "semantics": "s32@+24 — ref de node (-1 = nulo)"},
        ],
        "usage": "nascimento random com trigger zone (decompile Onda 6.5: FieldMap_WalkStructEntry_Sub)",
    }

def born6():
    return {
        "status": "FECHADO", "payload_consumer": True, "editable": True,
        "window": {"start": 4, "width": 17},
        "fields": [
            {"name": "countdown", "offset": 4, "width": 2, "type": "u16", "semantics": "u16@+4 — parametro de trigger (nascimento)"},
            {"name": "flag", "offset": 6, "width": 1, "type": "u8", "semantics": "u8@+6 — flag"},
            {"name": "trigger", "offset": 7, "width": 1, "type": "u8", "semantics": "u8@+7 — trigger de nascimento"},
            {"name": "flag2", "offset": 8, "width": 1, "type": "u8", "semantics": "u8@+8 — flag secundaria"},
            {"name": "ref_a", "offset": 12, "width": 4, "type": "s32", "semantics": "s32@+12 — ref de node (-1 = nulo)"},
            {"name": "ref_b", "offset": 20, "width": 4, "type": "s32", "semantics": "s32@+20 — ref de node (-1 = nulo)"},
        ],
        "usage": "nascimento random com trigger zone (decompile Onda 6.5: FieldMap_WalkStructEntry2_Sub)",
    }

for op, update in (("pppKeBornRnd5", born5()), ("pppKeBornRnd6", born6())):
    v = fam.get(op)
    if v is None:
        print(f"!! nao encontrado: {op}")
        continue
    v.update(update)

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"KeBornRnd5/6 FECHADOS | embedded: {len(emb)}")
