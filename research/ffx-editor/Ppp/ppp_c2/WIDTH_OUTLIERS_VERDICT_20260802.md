# WIDTH OUTLIERS — VEREDITO FINAL (2026-08-02)

**Pendência do VERDICT §6 "Outliers de largura (1B..4096B)" RESOLVIDA.**

## Investigação

Re-scan do corpus inteiro (walker Python) caçando slots com larguras raras
(1, 5, 9-11, 13, 14, 17, 19, 21, 47, 60, 67, 75, 95, 100, 149, 249, 250, 256, 4096).

## Resultados

| Achado | Qtd | Veredito |
|---|---|---|
| h=35 w=60B (magic_0325) | 1 | Único caso plausível — fp.h local do 0325 resolveria (marginal, 1 slot) |
| h=4198401/2752517 (magic_0434) | 2 | **ARTEFATO do walker Python** (handler inválido = leitura de região errada) |
| h=0 w=60B (0434) | 1 | idem — root com t1_rel de outra base |

## Conclusão

1. **Os outliers do histograma original são artefato do walker Python simplificado**
   (não valida o next-chain com a mesma rigidez do parser C#).
2. **O parser C# real é a verdade**: 581/581 DLLs abrem, RT0 byte-idêntico,
   round-trip completo — nenhum erro de largura.
3. O caso h=35/w=60B do 0325 é o único a investigar se o editor tocar esse slot
   (fp.h local resolve — baixíssima prioridade).
4. **Pendência ENCERRADA** — nenhuma ação necessária no editor.

*Jarvis-PPP-C2C3 · 2026-08-02*
