# Migração C/C++ — estado do primeiro lote

Base pública: `0591e41bc32ce172d0bee299d574e1f436077fc7`.
Branch de trabalho: `cos/cpp-recovery-41520`.
Checkout isolado: `/mnt/nvme-samsung/ffx-cpp-recovery-41520`.
Plano: `docs/superpowers/plans/2026-09-30-ffx-cpp-byte-identical.md`.

O controle foi reproduzido com recompilação dos três pacotes C legados. A
infraestrutura de recuperação está implementada e o piloto foi compilado duas
vezes, ligado em dois PEs completos e testado na ABI x86. O catálogo continua em
19.593 endereços / 864.146 bytes; ele não é a medida da migração.

## Provedor promovido

`0x0093D3D0`, 102 bytes, símbolo COFF `_FFX_Math_Vec3Normalize`.
Fonte: `src/math/vec3_normalize.c`; contrato: `contracts/0093d3d0.json`.
Receita: `recipes/math_vec3.json`. Registro ativo seleciona a compilação B.
Referência externa: `__CIsqrt` ligada a `_sym_009497b8` por REL32 verdadeiro.
Nenhuma alteração em instruções de compilador ou fallback de assembly.

Compilador MSVC 2012 x86 17.00.50727.1; arquivos e flags pinados na receita.
Build IDs: A `54f1845d01b24aeaa36db4a598962e9b`,
B `929532358f3c47be8d861b0eac6eb80a`. As duas áreas Windows foram criadas vazias.
`proofs/math_vec3-repeatability.json` vincula objetos, recibos, seções e PEs.

| Medida | Controle | Primeiro lote |
|---|---:|---:|
| C emitido | 35.956 | 36.058 |
| Assembly de instruções, bytes | 6.715.479 | 6.715.377 |
| Registros de instruções | 2.142.911 | 2.142.865 |
| Implementações C distintas | 1.158 | 1.159 |
| Instâncias C selecionadas | 5.894 | 5.895 |
| Assembly manual | 144 | 144 |
| Padding declarado | 583.710 | 583.710 |
| Dados declarados em .text | 48.775 | 48.775 |

## Construções aceitas

Em `recon/ffx/mods/build/recovered-lot1-a/disabled/` e
`recon/ffx/mods/build/recovered-lot1-b/disabled/`, ambos os PEs têm 10.675.712 bytes,
zero diferenças entre si e contra a referência, SHA-256
`78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced`.
Os demos em `compare_demo/` passaram na compilação independente, linkagem e
ensaio de 101.400 chamadas. SHA do mod:
`f9adb847cebf552678e7b3283f7c3bff8a9e468140f7304e616b2195f5c319d4`.

Comandos efetivamente executados: `recovered_build.py stage`, duas invocações
Windows de `compile`, duas de `verify`, `text_program.py prepare` para cada
seleção, `mod_acceptance.py --output ... --native-demo` para cada lote, `cmp`
integral e `recovered_status.py` revalidando os traces e snapshots.
Os logs correspondentes estão em `evidence/lot1/` e `control/`.

Validação final do primeiro lote: 461 testes e 416 subtestes aprovados em 31,13 s;
`cmp` integral retornou 0. A revisão de whitespace usou
`git -c core.whitespace=trailing-space,space-before-tab,cr-at-eol diff --cached --check`
e retornou 0, preservando o CRLF original dos recibos Windows. O log completo é
`evidence/lot1/tests.log.gz`. Os hashes dos arquivos de evidência estão em
`evidence/lot1/files.json`.

Ensaio de matemática: 331.776 comparações / 663.564 chamadas totais; detalhes e
limites em `proofs/native_math_vec3/report.json`. Bases Windows 0x10000000,
0x20000000 e 0x50000000. O endereço preferido 0x400000 colide com alocações do
loader Windows; o teste Linux existente permanece cobrindo-o. Não houve gameplay.
`proofs/no-fallback.json` registra uma mutação deliberada do fonte ativo,
rejeitada pelo build, seguida de restauração byte-exata desse fonte.

## Próximos candidatos já examinados

Os símbolos dos dumps compilados ajudam a corrigir nomes imprecisos do catálogo:

| VA | Identidade fundamentada | Bytes |
|---|---|---:|
| 0x0048CA00 | CopyConstructArray de PSpriteAttributes | 48 |
| 0x0048CAA0 | CopyConstructArray de PSkeletonJointBounds | 48 |
| 0x005F6130 | btBoxShape::batchedUnitVectorGetSupportingVertexWithoutMargin | 122 |
| 0x009F0C80 | std::_Insertion_sort1 de PSortedOccluder | 151 |
| 0x00452680 | Normalização de três componentes, sem guarda de comprimento | 100 |

Os quatro primeiros foram atribuídos por comparação literal com dumps existentes
de objetos SDK, depois da inspeção do executável atual. O último tem prova no
catálogo `arch_ia32_rel32_exact.json`. Nenhum recebe crédito adicional até passar
pela compilação, admissão, PE e comportamento. A ordenação de oclusores não deve
ser documentada como leitura de stream; o batch de btBoxShape não normaliza
vetores. O SDK e o binário continuam sendo evidências distintas, com versões
conferidas por função.

## Restrições que continuam

Não usar a main local antiga, Actions, subagentes, instalação Steam ou backup
geral. Preservar todos os gates e as provas mistas anteriores. Ainda restam
6.715.377 bytes de assembly de instruções e 144 bytes manuais: a migração completa
para C/C++ continua em andamento. Expandir os lotes por utilidade dos módulos e
contratos verificáveis, sem transformar matches de catálogo em cobertura emitida.
