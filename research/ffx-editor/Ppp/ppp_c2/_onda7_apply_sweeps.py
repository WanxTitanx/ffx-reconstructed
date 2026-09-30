import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 7 (GOAL 8h): aplica os resultados dos 5 subagentes (sweep a-e) — varredura completa
# dos SEM_PAYLOAD/FALTA_SCHEMA com addr. Cada entrada: (opcode, addr, start, width, desc)
PAYLOADS = [
    # sweep-a
    ("pppColor", "0x75D2E0", 8, 8, "FFX_FieldMap_AccumulateVec4Word — 4x u16 RGBA @+8..+0xE acumulados em a1+0xA0"),
    ("pppDrawMdl", "0x737830", 16, 136, "le a2+16/+80/+144/+148 (transform, matriz, ptrs recurso)"),
    ("pppDrawMdl2", "0x7385F0", 16, 136, "mesmo layout do DrawMdl (type F)"),
    ("pppDrawMdlBS", "0x737830", 16, 136, "alias do addr 0x737830 (mesmo corpo do DrawMdl)"),
    ("pppDrawMdlCamera", "0x73D9F0", 4, 16, "vec4 em a2+4 + gate dword em a2+12"),
    ("pppDrawMdlInf", "0x73BA70", 4, 148, "vec4s a2+4/+8/+12 + ptrs a2+144/+148"),
    ("pppDrawMdlPSim", "0x73D130", 4, 28, "slot a2+4 e 6 floats a2+8..+0x1F (type I/sim)"),
    ("pppDrawMdlRev", "0x7404D0", 16, 136, "render c/ transform, le a2+16/+80/+144/+148"),
    ("pppDrawMdlSemi2", "0x738B00", 16, 152, "le a2+16/+80/+144/+148 e u16 em a2+166 (type H)"),
    ("pppDrawMdlSemi3", "0x739DF0", 16, 136, "locale, le a2+16/+80/+144/+148"),
    # sweep-b
    ("pppDrawShape", "0x740AA0", 12, 24, "FFX_MagicHost_DispatchVfxDrawableBySlot — flag@+12, tabela@+32"),
    ("pppDrawShapeCamera", "0x747600", 4, 8, "dispatch draw (tex_id@+4, count@+8)"),
    ("pppDrawShapeCameraDisPos", "0x748860", 4, 8, "idem DrawShapeCamera"),
    ("pppDrawShapeField", "0x742D80", 4, 8, "FFX_KR_LoadTableForCurrentLanguage"),
    ("pppDrawShapeFieldGlobal", "0x7463E0", 4, 8, "DispatchEffectDraw_D"),
    ("pppDrawShapeFieldRev", "0x744100", 4, 8, "BuildTableDrawableFromEntry"),
    ("pppDrawShapeFieldSpd", "0x7452D0", 4, 72, "knobs 3xf32@+64/68/72 pos + ctrl@+4/+8"),
    ("pppDrawShapeX", "0x740F90", 12, 24, "dispatcher alt (flag@+12, tabela@+32)"),
    ("pppFpPointLight", "0x75D8E0", 4, 12, "debug overlay tri (f32@+4, u8@+8, f32@+12)"),
    ("pppFpPointLightModel", "0x75DA20", 4, 16, "debug overlay mesh (+u32 id@+16)"),
    ("pppFpPointLightModelScl", "0x75DE60", 4, 16, "debug overlay rect (+u32 id@+16)"),
    # sweep-c
    ("pppFpPointLightVsf", "0x75DC20", 4, 14, "light: size f32@+4, flag b@+8, sort f32@+12, mesh s16@+16"),
    ("pppFpPointLightVsfScl", "0x75E080", 4, 14, "idem Vsf + scale extra h[+12]"),
    ("pppKeBornRnd3", "0x758A50", 4, 20, "born rnd zone: u16@+4, b@+6/7/8, dw@+12/+20"),
    ("pppKeGrvEff", "0x759740", 4, 8, "gravidade: idx@+4, base@+8, obj alvo; match a2+12"),
    ("pppKeHitChkPxB", "0x759AA0", 4, 12, "hit chk: idx@+4, base@+8, flag b@+12"),
    ("pppKeLnsArnd", "0x75A0E0", 8, 8, "lens arnd: rgba b@+8..11, f32@+12"),
    ("pppKeLnsArndT", "0x75A280", 8, 8, "idem Arnd no slot a2 + match word"),
    ("pppKeLnsClm", "0x75A490", 8, 14, "lens clm: b@+8..11, f32@+12, u16@+20"),
    ("pppKeLnsClmT", "0x75A630", 8, 14, "idem Clm no slot a2 + match word"),
    ("pppKeLnsCrn", "0x75A850", 8, 12, "lens crn: b@+8..11, f32@+12, s16@+16, s16@+18"),
    # sweep-d
    ("pppKeLnsCrnT", "0x75A9F0", 8, 12, "RGBA(8-11)+float(12)+u16(16/18); aplica cor/pos ao no"),
    ("pppKeLnsFls", "0x75AC40", 8, 12, "RGBA(8-11)+float(12)+u16(16/18); render particles audio-sync"),
    ("pppKeLnsFlsT", "0x75ADF0", 8, 12, "mesmo payload do Fls, apply no no"),
    ("pppKeLnsLp", "0x75B070", 4, 10, "float(4/8)+byte(12/13); offset spring/mola da lente"),
    ("pppKeLnsLpT", "0x75B250", 14, 3, "bytes(14/15/16); multiplicadores/shift + byte de estado"),
    ("pppKeShpTail3", "0x750390", 32, 48, "24x u16 (32..78); deltas/offsets da cauda"),
    ("pppKeShpTail3X", "0x751D80", 32, 48, "idem Tail3; acumula frame delta + 24x u16"),
    # sweep-e
    ("pppKeThHitBorn", "0x759E70", 4, 9, "FieldMap_WalkStructTransparencyNodes: s32@+4 target, s32@+8 offset node, u8@+12 flag"),
    ("pppKeThTp2", "0x736E40", 4, 20, "FieldMap_SetTransformAndAccumulate (alias do KeThTp): pos xyz f32@+4/8/12 + refs@+16/20"),
    ("pppVertexAp", "0x757930", 4, 5, "FFX_MagicHost_UpdateVfxRandomAnimation: u16@+4 indice (bit 0x8000), u8@+6/7/8 (count/delay/modo)"),
]

# Stubs no-op confirmados pelos sweeps (ja alguns registrados)
STUBS = [
    ("pppFaceAp", "0x757FB0", "nullsub_662 no-op no PC"),
    ("pppKeShpDtt", "0x7550F0", "nullsub_658 no-op"),
    ("pppKeShpTailLc", "0x7550A0", "pppNeiDrawShapePointLight stub no-op"),
    ("pppKeThCp", "0x75B7C0", "nullsub_669 no-op"),
    ("pppKeThCpSft", "0x75B7F0", "nullsub_672 no-op"),
    ("pppKeThLz", "0x75B800", "nullsub_673 no-op"),
]

path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

applied = 0
for op, addr, ws, ww, desc in PAYLOADS:
    v = fam.get(op)
    if v is None:
        print(f"!! nao encontrado: {op}")
        continue
    v["status"] = "FECHADO"
    v["payload_consumer"] = True
    v["editable"] = True
    v["window"] = {"start": ws, "width": ww}
    v["handler_addr"] = addr
    v["usage"] = (v.get("usage") or "") + f" [ONDA7 sweep: {desc}]"
    applied += 1

for op, addr, desc in STUBS:
    v = fam.get(op)
    if v:
        v["status"] = "SEM_PAYLOAD"
        v["payload_consumer"] = False
        v["editable"] = False
        v["window"] = None
        v["usage"] = (v.get("usage") or "") + f" [ONDA7 sweep: STUB {desc}]"

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"payloads aplicados: {applied} | stubs: {len(STUBS)} | embedded: {len(emb)}")
