import idc

CMTS = {
    0x716D20: "PPP program processor #2 (gemeo do 0x7170F0; mesmo loop de slots). Dispatch: entry[+4] (4 args) -> entry[+8] (3 args) -> entry[+0xC] (3 args). Nome antigo (AudioSdStream) enganoso. Prova: PPP_DISPATCH_TABLE_RE_20260731.md",
    0x75B830: "pppAccele handler (schema U1; entry 0 da PPP host dispatch table 0xC3A500, slot +8). Acumula float4 do payload +0x10..+0x1C no estado 2-camadas +0xA0..+0xAC. Prova: PPP_DISPATCH_TABLE_RE_20260731.md",
    0x75B900: "pppAccele section-callback (entry pppAccele +0x1C/+0x20): seta float4 de globais 0xC0A004..0xC0A010 no estado +0xA0..+0xAC. Semantica provavel (Q), nao RT2. Prova: PPP_DISPATCH_TABLE_RE_20260731.md",
    0xC3A500: "PPP host dispatch table principal (418 entries x 0x28 = 0xC3A500..0xC3E650). arg2 de FFX_MagicHost_RelocatePppResourceBlob (0x712080). Campos: +0 name_ptr, +4/+8/+0xC handlers por modo, +0x1C resource alloc (KeThRes*), +0x20 section callback, +0x24 release. Prova: PPP_DISPATCH_TABLE_RE_20260731.md",
    0xC3E798: "PPP host dispatch table alternativa (246 entries x 0x28 = 0xC3E798..0xC40E08). Subset dos nomes da principal, indices diferentes; sem xrefs diretos no IDB (Q: resource grande / legada). Prova: PPP_DISPATCH_TABLE_RE_20260731.md",
    0xC86080: "PPP keyhole dispatch table (32 entries x 0x28 = 0xC86080..0xC86580). Passada como arg2 de RelocatePppResourceBlob por FFX_MagicHost_KeyholeTexture_Init (0xA54760). Prova: PPP_DISPATCH_TABLE_RE_20260731.md",
}

for ea, cmt in CMTS.items():
    idc.set_cmt(ea, cmt, 0)
    print(hex(ea), "comment set")
print("DONE")
