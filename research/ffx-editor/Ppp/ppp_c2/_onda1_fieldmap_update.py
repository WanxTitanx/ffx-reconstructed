import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 1 2026-08-02 — fechar field_map com provas de decompile na canonica (porta 13337).
# Cada entrada: (opcode, status, window, handler_addr, nota_prova)
provas = [
    # --- 12 PARCIAL -> FECHADO (janelas provadas por decompile) ---
    ("pppRandChar",      "FECHADO",   [4, 6],  "0x72FB00", "decompile 0x72FB00 pattern D: target u32@+4, delta u8@+8, flag u8@+9"),
    ("pppRandUpChar",    "FECHADO",   [4, 6],  "0x72FCD0", "decompile 0x72FCD0 pattern E: idem RandChar + media 0.5 na flag"),
    ("pppRandDownChar",  "FECHADO",   [4, 6],  "0x72FEB0", "decompile 0x72FEB0 pattern F: idem RandChar (sinal invertido)"),
    ("pppRandShort",     "FECHADO",   [4, 7],  "0x730090", "decompile 0x730090 pattern G: target u32@+4, delta u16@+8, flag u8@+10"),
    ("pppRandUpShort",   "FECHADO",   [4, 7],  "0x730260", "decompile: idem RandShort + media 0.5 (familia Up)"),
    ("pppRandDownShort", "FECHADO",   [4, 7],  "0x730430", "decompile: idem RandShort (familia Down)"),
    ("pppRandInt",       "FECHADO",   [4, 9],  "0x730610", "decompile 0x730610 pattern J: target u32@+4, delta u32@+8, flag u8@+12"),
    ("pppRandUpInt",     "FECHADO",   [4, 9],  "0x7307F0", "decompile: idem RandInt (familia Up)"),
    ("pppRandDownInt",   "FECHADO",   [4, 9],  "0x7309C0", "decompile: idem RandInt (familia Down)"),
    ("pppRandCV",        "FECHADO",   [4, 9],  "0x731860", "decompile 0x731860 pattern S: target u32@+4, 4x delta s8@+8..+11, flag u8@+12"),
    ("pppRandUpCV",      "FECHADO",   [4, 9],  "0x731AD0", "decompile: idem RandCV (familia Up)"),
    ("pppRandDownCV",    "FECHADO",   [4, 9],  "0x731D30", "decompile: idem RandCV (familia Down)"),
    # --- 5 FALTA_SCHEMA_PAYLOAD -> resolvidos ---
    ("pppKeHmgEff",      "FECHADO",   [4, 12], "0x759CE0", "decompile 0x759CE0: KNOB HUD/portrait — lerp f32@+4, refs node +8/+12, guard PausedFlag, match program[0]==ctx[+12]"),
    ("pppKeParMatR",     "SEM_PAYLOAD_NOKNOB", None, "0x734950", "decompile 0x734950 = FFX_MagicHost_ProjectChildCoords(a1): NAO le a2 (sem payload) — reclassificado"),
    ("pppMatrixZYX",     "SEM_PAYLOAD_NOKNOB", None, "0x72DDD0", "decompile 0x72DDD0: matriz Euler interna (le a3/estado, nao a2) — reclassificado"),
    ("pppMatrixYZX",     "SEM_PAYLOAD_NOKNOB", None, "0x72DA10", "decompile 0x72DA10: matriz Euler interna (le a3/estado, nao a2) — reclassificado"),
    ("pppKeMdlTfdUv3",   "FECHADO",   [4, 57], "0x74A0C0", "decompile 0x74A0C0 (renomeado FFX_PppHandler_KeMdlTfdUv3): drawable@+4, 3xVec3 acumulado @+8..+52, flags@+56..+60, globals@+20/+24, stride@+28 — janela +4..+60"),
    # --- KeMdlTfdUv (PARCIAL) -> FECHADO por familia Uv2/Uv3 identicos ---
    ("pppKeMdlTfdUv",    "FECHADO",   [8, 49], "0x749D60", "familia provada: Uv2 (0x749D60) e Uv3 (0x74A0C0) decompilados — estrutura identica (acumulador 3xVec3 + batch drawable)"),
]

# --- Rand* restantes ja provados na rodada 10 (sessao anterior) — so garantir status ---
rodada10 = ["pppRandDownFV", "pppRandDownFloat", "pppRandDownHCV", "pppRandDownIV",
            "pppRandFV", "pppRandFloat", "pppRandHCV", "pppRandIV", "pppRandUpFV",
            "pppRandUpHCV", "pppSRandCV", "pppSRandDownFV", "pppSRandUpFV",
            "pppRandUpFloat", "pppRandUpIV", "pppKeOfsPt"]

path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

def find(opcode):
    if opcode in fam:
        return fam[opcode]
    for k, v in fam.items():
        if k == opcode:
            return v
    return None

changed = []
for op, status, win, addr, nota in provas:
    v = find(op)
    if v is None:
        print(f"!! opcode nao encontrado no field_map: {op}")
        continue
    if status.startswith("FECHADO"):
        v["status"] = "FECHADO"
        v["payload_consumer"] = True
        v["editable"] = True
        v["window"] = {"start": win[0], "width": win[1]}
    else:
        v["status"] = status
        v["payload_consumer"] = False
        v["editable"] = False
        v["window"] = None
    if addr:
        v["handler_addr"] = addr
    v["usage"] = (v.get("usage") or "") + " [ONDA1 " + nota + "]"
    changed.append(op)

for op in rodada10:
    v = find(op)
    if v is not None and (v.get("status") or "") in ("", None):
        v["status"] = "FECHADO"
        changed.append(op)

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print(f"Atualizado: {len(changed)} familias")
for c in changed:
    print(" -", c)
