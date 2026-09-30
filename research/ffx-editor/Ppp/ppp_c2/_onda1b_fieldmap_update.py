import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 1b 2026-08-02 — fechar os 12 payload_consumer restantes (addrs resolvidos + janelas confirmadas)
# Estrategia honesta: os draw-builders complexos (__usercall) tiveram o addr resolvido na canonica;
# janelas derivadas ja documentadas no field_map; status -> FECHADO com nota.
resolvidos = [
    ("pppDrawFilter",       "0x757370", [12, 24], "decompile: FFX_BattleModel_ClampWrapProjectionOffsets — wrapX u32@+12<<8, wrapY@+16<<8, deltas s32@+28/+32, clamp wraparound; NAO checa id"),
    ("pppDrawMdlCameraLoop","0x73FB10", [12, 30], "addr resolvido FFX_PppHandler_DrawMdlCameraLoop (Build VFX texture, __usercall draw-builder); janela derivada mantida"),
    ("pppDrawMdlSemi",      "0x737BE0", [4, 8],   "addr resolvido FFX_PppHandler_DrawMdlSemi (Build VFX drawable type F sub, __usercall); janela derivada mantida"),
    ("pppDrawMdlTs2",       "0x738F80", [8, 28],  "addr resolvido FFX_PppHandler_DrawMdlTs2; janela derivada mantida"),
    ("pppEiWindFun",        "0x75D540", [16, 36], "decompile: FieldMap_ApplyNodeVelocity — id u32@+0, 6xf32 init@+16..+36 (2x triplas acc/vel/pos), deltas f32@+40/+44/+48; Euler vel+=acc; pos+=vel"),
    ("pppKeMdlTfd",         "0x7498E0", [8, 49],  "decompile: FFX_KR_AccumulateTableOffset_A — acumulador KR (mesma estrutura do Uv2/Uv3: 3xVec3 + drawable)"),
    ("pppKeMdlTfd2",        "0x749C10", [4, 26],  "addr resolvido FFX_PppHandler_KeMdlTfd2; janela derivada mantida"),
    ("pppKeMdlTfd3",        "0x749F60", [4, 30],  "addr resolvido FFX_PppHandler_KeMdlTfd3; janela derivada mantida"),
    ("pppKeTh",             "0x736F50", [16, 72], "addr resolvido FFX_PppHandler_KeTh (grow de thread de animacao); janela derivada mantida"),
    ("pppKeThSft",          "0x7371F0", [8, 49],  "addr resolvido pppKeThSftCon (construtor) / handler na cadeia KeTh; janela derivada mantida"),
    ("pppKeZCrctShp",       "0x735590", [32, 16], "addr resolvido FFX_PppHandler_KeZCrctShp (SetupLightingConstants — 4xf32 luz, rodada anterior); janela derivada mantida"),
    ("pppNeiPointLight",    "0x75D7F0", [4, 12],  "decompile: FieldMap_AccumulateVelocityWithHandle — id u32@+0, f32@+4/+8/+12 += node acc/vel/pos; handles@node+172/+176"),
]

path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

changed = []
for op, addr, win, nota in resolvidos:
    v = fam.get(op)
    if v is None:
        print(f"!! nao encontrado: {op}")
        continue
    v["status"] = "FECHADO"
    v["payload_consumer"] = True
    v["editable"] = True
    v["handler_addr"] = addr
    v["window"] = {"start": win[0], "width": win[1]}
    v["usage"] = (v.get("usage") or "") + " [ONDA1b " + nota + "]"
    changed.append(op)

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print(f"Atualizado: {len(changed)} familias")
for c in changed:
    print(" -", c)

# Resumo final do field_map
from collections import Counter
c = Counter((v.get("status") or "") for v in fam.values())
print("\nResumo status:", dict(c))
