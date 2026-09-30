# pppSMatrix — VEREDITO (2026-08-02)

**Descoberta:** pppSMatrix tem **13.921 slots no corpus** (2º opcode mais comum!),
mas a entry da dispatch table do EXE é **COMPLETAMENTE VAZIA**.

## Evidência (IDA, canônica)

```
entry idx 15  @ 0xC3A500+15*0x28: name_ptr=0xB50A38 (pppSMatrix), handlers=0x0, 0x0, 0x0
entry idx 160 @ 0xC3A500+160*0x28: idem (aliases)
todos os 10 dwords = 0 (sem alocador +0x1C, sem callback +0x20, sem release +0x24)
```

## Interpretação

1. **pppSMatrix = placeholder/reservado** — os arquivos mágicos (PS2→PC) contêm
   slots `pppSMatrix` (provavelmente "Simple Matrix" do PS2), mas o runtime PC
   **não tem handler** para ele (entry zerada → dispatch no-op).
2. Os 13.921 slots são **inertes no PC** (dead slots de compatibilidade).
3. **NÃO-editável** (editar = sem efeito; o dispatcher 0x7170F0 não chama nada).

## Ação

- field_map: `pppSMatrix.status = "RESERVADO_STUB_EXE"`, `editable = false` (já está).
- Nenhum rename necessário (nome real já existe na entry).
- **Nota para o editor**: slots pppSMatrix devem aparecer como "reservado (no-op no PC)".

*Jarvis-PPP-C2C3 · 2026-08-02*
