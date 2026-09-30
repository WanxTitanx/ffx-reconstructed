import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

tbl = json.load(open(r"C:/Users/wande/Documents/ffx-editor-main/work/noclip_reference/instruction_table_20260802.json"))
MAP = json.load(open(r"C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/visual_map_20260802.json"))
fm = json.load(open(r"C:/Users/wande/Documents/ffx-editor-main/work/magic_editor/field_map.json", encoding="utf-8"))
pc = {k: v for k, v in fm["families"].items() if v.get("payload_consumer")}

L = []
L.append("# PPP — SEMÂNTICA VISUAL DAS FAMÍLIAS EDITÁVEIS (cruzamento com o noclip.website) — 2026-08-02")
L.append("")
L.append("**Lane:** Jarvis-PPP-C2C3 · **Método:** instructionTable do noclip (85 entries, `particle.ts`) cruzada com os 44 payload_consumer do field_map (janelas provadas por decompile).")
L.append("**Aviso:** o noclip renderiza o formato PS2 (makeTask MIPS + emitters) — as equivalências são de COMPORTAMENTO (mesmo sistema em outra representação), não de layout.")
L.append("")
L.append("## 1. Tabela família nossa → classe noclip → comportamento visual")
L.append("")
L.append("| Família (PC) | Classe noclip | Confiança | Comportamento visual |")
L.append("|---|---|---|---|")
for k in sorted(pc):
    if k in MAP:
        cls, conf, desc = MAP[k]
        L.append(f"| {k} | {cls} | {conf} | {desc} |")
    else:
        w = pc[k].get("window") or {}
        L.append(f"| {k} | — | — | Sem equivalente claro (janela {w.get('width','?')}B) |")
L.append("")
L.append("## 2. As 85 instruções do noclip (referência)")
L.append("")
L.append("| Opcode | Classe | Formato |")
L.append("|---|---|---|")
for op, cls, fmt in tbl:
    L.append(f"| 0x{op:02X} | {cls} | {fmt} |")
L.append("")
L.append("## 3. Como isso direciona o T4")
L.append("")
L.append("- **U1 (Move/SclMove/Scale/Angle/Point)**: mutar um f32 em +0x10..+0x1F deve alterar trajetória/forma VISIVELMENTE.")
L.append("- **Rand**: mutação muda a DISPERSÃO (aleatório) — observar a variação entre casts (estatístico).")
L.append("- **Draw (Ts/Loop/Semi)**: mutar os 6 f32 deltas anima o modelo; mutar a key (+4 do programa) troca o RECURSO (risco alto).")
L.append("- **KeTh/KeThSft**: mutar canais u16 de bone muda a animação de ossos do scene object.")
L.append("- **NeiPointLight/EiWindFun**: mutar f32 muda luz/vento.")
L.append("")
L.append("*2026-08-02 · Jarvis-PPP-C2C3 · fonte: work/noclip_reference/instruction_table_20260802.json + visual_map_20260802.json*")
L.append("")

path = r"C:/Users/wande/Documents/ffx-editor-main/docs/reverse/PPP_FAMILIES_VISUAL_SEMANTICS_20260802.md"
open(path, "w", encoding="utf-8").write("\n".join(L) + "\n")
print("gerado:", path, len(L), "linhas")
