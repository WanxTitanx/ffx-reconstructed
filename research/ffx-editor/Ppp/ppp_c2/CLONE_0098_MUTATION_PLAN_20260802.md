# CLONE 0098 — PLANO DE MUTAÇÃO T4 (2026-08-02)

**Lane:** Jarvis-PPP-C2C3 · **Status:** pronto para execução COM autorização do Halyson
**Fonte:** `work/ppp_c2/u1_targets_0098.json` (705 slots) + runbook `PPP_C3_CLONE_T4_RUNBOOK_20260802.md`

## 0. Regras
- Mutar SOMENTE campos em offset >= 8 (nunca o prefixo/match word +0..+7)
- Janela U1 = record+0x10..+0x1F (16B): +0x10=X, +0x14=Y, +0x18=Z, +0x1C=W
- 1 mutação por observação; restore hash-gated; .bak automático
- Cópias byte-idênticas: mutar um record NÃO cascateia — mas quebra a simetria (as cópias ficam com o valor antigo)

## 1. Mutações candidatas (menor risco primeiro)

### Candidata 1: pppAngAccele — record 0x19A30 (slot 0x19988, handler 1)
- SHA: c4c7a152492aaca7… · **1 slot(s) com o MESMO conteúdo** (cópias)
- Campo sugerido: f32 em +0x10 (X) — valor original lido do arquivo
- Mutação sugerida: **×2.0** (dobrar o componente X)
- O que observar: escala/posição em X da animação do Death

### Candidata 2: pppAngAccele — record 0x1A1E0 (slot 0x1A13C, handler 1)
- SHA: 941ab1df4a082ce7… · **1 slot(s) com o MESMO conteúdo** (cópias)
- Campo sugerido: f32 em +0x10 (X) — valor original lido do arquivo
- Mutação sugerida: **×2.0** (dobrar o componente X)
- O que observar: escala/posição em X da animação do Death

### Candidata 3: pppAngAccele — record 0x1A9C0 (slot 0x1A8EC, handler 1)
- SHA: 052ff4d9ab51f9d4… · **1 slot(s) com o MESMO conteúdo** (cópias)
- Campo sugerido: f32 em +0x10 (X) — valor original lido do arquivo
- Mutação sugerida: **×2.0** (dobrar o componente X)
- O que observar: escala/posição em X da animação do Death

### Candidata 4: pppSclMove — record 0x1C0F0 (slot 0x1BFDC, handler 6)
- SHA: 26c32de06d31b383… · **1 slot(s) com o MESMO conteúdo** (cópias)
- Campo sugerido: f32 em +0x10 (X) — valor original lido do arquivo
- Mutação sugerida: **×2.0** (dobrar o componente X)
- O que observar: escala/posição em X da animação do Death

### Candidata 5: pppScale — record 0x1C1D0 (slot 0x1C01C, handler 10)
- SHA: 27232e018d8c0791… · **1 slot(s) com o MESMO conteúdo** (cópias)
- Campo sugerido: f32 em +0x10 (X) — valor original lido do arquivo
- Mutação sugerida: **×2.0** (dobrar o componente X)
- O que observar: escala/posição em X da animação do Death

### Candidata 6: pppAngAccele — record 0x1C6D0 (slot 0x1C584, handler 1)
- SHA: 17041265ea459f4f… · **1 slot(s) com o MESMO conteúdo** (cópias)
- Campo sugerido: f32 em +0x10 (X) — valor original lido do arquivo
- Mutação sugerida: **×2.0** (dobrar o componente X)
- O que observar: escala/posição em X da animação do Death

### Candidata 7: pppAngAccele — record 0x1CEB0 (slot 0x1CD64, handler 1)
- SHA: 1235c185d3a19e7e… · **1 slot(s) com o MESMO conteúdo** (cópias)
- Campo sugerido: f32 em +0x10 (X) — valor original lido do arquivo
- Mutação sugerida: **×2.0** (dobrar o componente X)
- O que observar: escala/posição em X da animação do Death

### Candidata 8: pppSclMove — record 0x1D6D0 (slot 0x1D4D8, handler 6)
- SHA: 5ded66e7869ecbf1… · **1 slot(s) com o MESMO conteúdo** (cópias)
- Campo sugerido: f32 em +0x10 (X) — valor original lido do arquivo
- Mutação sugerida: **×2.0** (dobrar o componente X)
- O que observar: escala/posição em X da animação do Death

### Candidata 9: pppScale — record 0x1D7E0 (slot 0x1D518, handler 10)
- SHA: 79813694dccfe293… · **1 slot(s) com o MESMO conteúdo** (cópias)
- Campo sugerido: f32 em +0x10 (X) — valor original lido do arquivo
- Mutação sugerida: **×2.0** (dobrar o componente X)
- O que observar: escala/posição em X da animação do Death

### Candidata 10: pppAngAccele — record 0x1DD80 (slot 0x1DC18, handler 1)
- SHA: 0e82f1815e3a7d64… · **1 slot(s) com o MESMO conteúdo** (cópias)
- Campo sugerido: f32 em +0x10 (X) — valor original lido do arquivo
- Mutação sugerida: **×2.0** (dobrar o componente X)
- O que observar: escala/posição em X da animação do Death

### Candidata 11: pppSclMove — record 0x1DE80 (slot 0x1DC68, handler 6)
- SHA: dc9448d5724d626e… · **1 slot(s) com o MESMO conteúdo** (cópias)
- Campo sugerido: f32 em +0x10 (X) — valor original lido do arquivo
- Mutação sugerida: **×2.0** (dobrar o componente X)
- O que observar: escala/posição em X da animação do Death

### Candidata 12: pppScale — record 0x1DF90 (slot 0x1DCA8, handler 10)
- SHA: 1cf68cf3fdb65847… · **1 slot(s) com o MESMO conteúdo** (cópias)
- Campo sugerido: f32 em +0x10 (X) — valor original lido do arquivo
- Mutação sugerida: **×2.0** (dobrar o componente X)
- O que observar: escala/posição em X da animação do Death

## 2. Ordem recomendada
1. **Candidata com MENOS cópias** (mutação mais isolada — se o efeito mudar, atribuição limpa)
2. Candidata com mais cópias (quebra de simetria — bom para confirmar o padrão de duplicação)
3. AngAccele (mira) — observar tracking do alvo

## 3. Rollback
1. `Reverter` no editor (discarta edições em memória) OU `TryRestoreBackup` (hash-gated)
2. Confirmar SHA do arquivo restaurado == SHA original (antes da mutação)
3. Se o jogo crashou: restaurar o vanilla da Steam Library imediatamente e registrar

