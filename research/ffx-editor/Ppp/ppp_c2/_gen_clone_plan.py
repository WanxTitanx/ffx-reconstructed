import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Gera work/ppp_c2/CLONE_0098_MUTATION_PLAN_20260802.md a partir do u1_targets_0098.json
t = json.load(open(r"C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/u1_targets_0098.json"))
slots = t["slots"]

# fp.h do 0098: handler -> opcode (mapa conhecido do parser: 1=AngAccele, 6=SclMove, 9=Angle, 10=Scale)
# (Do teste CloneTargets: AngAccele h=1, SclMove h=6, Angle h=9, Scale h=10)
H2OP = {1: "pppAngAccele", 6: "pppSclMove", 9: "pppAngle", 10: "pppScale"}

# Conta quantos slots compartilham o MESMO sha (copias byte-identicas)
from collections import Counter
sha_count = Counter(s["record_sha"] for s in slots)

# Seleciona 3 mutacoes: SclMove com menos copias (mais isolado), Scale, AngAccele
cands = []
for s in slots:
    op = H2OP.get(s["handler"])
    if op in ("pppSclMove", "pppScale", "pppAngAccele"):
        cands.append((sha_count[s["record_sha"]], s["record_sha"], s["record_offset"], s["slot_abs"], s["handler"], op))
cands.sort(key=lambda x: (x[0], x[2]))  # menos copias primeiro

L = []
L.append("# CLONE 0098 — PLANO DE MUTAÇÃO T4 (2026-08-02)")
L.append("")
L.append("**Lane:** Jarvis-PPP-C2C3 · **Status:** pronto para execução COM autorização do Halyson")
L.append("**Fonte:** `work/ppp_c2/u1_targets_0098.json` (705 slots) + runbook `PPP_C3_CLONE_T4_RUNBOOK_20260802.md`")
L.append("")
L.append("## 0. Regras")
L.append("- Mutar SOMENTE campos em offset >= 8 (nunca o prefixo/match word +0..+7)")
L.append("- Janela U1 = record+0x10..+0x1F (16B): +0x10=X, +0x14=Y, +0x18=Z, +0x1C=W")
L.append("- 1 mutação por observação; restore hash-gated; .bak automático")
L.append("- Cópias byte-idênticas: mutar um record NÃO cascateia — mas quebra a simetria (as cópias ficam com o valor antigo)")
L.append("")
L.append("## 1. Mutações candidatas (menor risco primeiro)")
L.append("")

n = 0
for copies, sha, rec, slot, h, op in cands[:12]:
    n += 1
    L.append(f"### Candidata {n}: {op} — record 0x{rec:X} (slot 0x{slot:X}, handler {h})")
    L.append(f"- SHA: {sha}… · **{copies} slot(s) com o MESMO conteúdo** (cópias)")
    L.append(f"- Campo sugerido: f32 em +0x10 (X) — valor original lido do arquivo")
    L.append(f"- Mutação sugerida: **×2.0** (dobrar o componente X)")
    L.append(f"- O que observar: escala/posição em X da animação do Death")
    L.append("")

L.append("## 2. Ordem recomendada")
L.append("1. **Candidata com MENOS cópias** (mutação mais isolada — se o efeito mudar, atribuição limpa)")
L.append("2. Candidata com mais cópias (quebra de simetria — bom para confirmar o padrão de duplicação)")
L.append("3. AngAccele (mira) — observar tracking do alvo")
L.append("")
L.append("## 3. Rollback")
L.append("1. `Reverter` no editor (discarta edições em memória) OU `TryRestoreBackup` (hash-gated)")
L.append("2. Confirmar SHA do arquivo restaurado == SHA original (antes da mutação)")
L.append("3. Se o jogo crashou: restaurar o vanilla da Steam Library imediatamente e registrar")
L.append("")

path = r"C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/CLONE_0098_MUTATION_PLAN_20260802.md"
open(path, "w", encoding="utf-8").write("\n".join(L) + "\n")
print("gerado:", path)
print("candidatas com menos copias:")
for copies, sha, rec, slot, h, op in cands[:6]:
    print(f"  {op} rec=0x{rec:X} slot=0x{slot:X} copias={copies} sha={sha}")
