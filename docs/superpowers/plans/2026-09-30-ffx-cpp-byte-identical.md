# Plano de implementação: FFX em C/C++ com igualdade binária

> Para a IA executora: execute este plano em lotes pequenos, na ordem indicada. Se usar Superpowers, o fluxo aplicável é `executing-plans`. Este documento não autoriza criar subagentes, disparar Actions, fazer backups volumosos ou substituir o executável da Steam. O usuário escolheu entregar a execução a outra IA.

**Objetivo:** substituir progressivamente o assembly reconstruído por C/C++ legível, compilado e efetivamente usado no `FFX.exe`, preservando a igualdade de todos os bytes da baseline sem modificações.

**Arquitetura:** manter o assembler, os dados declarados e o linker PE existentes como sustentação. Cada função ou grupo recuperado passa a fornecer código COFF compilado; somente os intervalos comprovados passam de assembly para C/C++. O caminho de modificações continua separado e pode gerar código e dados adicionais.

**Tecnologias:** PE32/x86; MSVC 2012 x86 17.00.50727.1 para o código que precisa corresponder ao original; Python 3.14, iced-x86 1.21.0, GNU binutils/GCC e `strace`; LLVM/Clang 21 no caminho de mods existente. Confirmar hashes e receitas antes de executar.

**Especificação:** pedido do usuário em 30/09/2026, concretizado no contrato abaixo. `recon/ffx/GOAL.md` documenta a baseline e o fluxo de mods já obtidos; esta migração é uma etapa nova e não deve apagar essas provas anteriores.

## Contrato de migração

1. **Vanilla:** sem modificações de comportamento, todo executável aceito tem exatamente **10.675.712 bytes** e SHA-256 **`78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced`**. O `cmp` integral deve retornar 0. Não se ignora nenhum byte de código, dados, cabeçalhos, imports, relocações ou padding.
2. **C/C++ real:** uma promoção exige fonte compilável, receita reproduzível, objetos recém-compilados e prova de que esses objetos forneceram os intervalos correspondentes do executável final. Um pseudocódigo, um nome recuperado ou um match isolado não satisfazem isso.
3. **Fonte utilizável:** nomes fundamentados, assinatura/ABI documentada, tipos e offsets conferidos, fluxo de controle compreensível e testes que expliquem o comportamento. Tipos ou significados ainda desconhecidos devem ser identificados como tal.
4. **Modificado:** novas funcionalidades intencionalmente mudam o binário e seu hash. Elas usam o fluxo de mods; desativá-las deve voltar à baseline exata. Não se pode exigir igualdade com o original e, ao mesmo tempo, alterar seu comportamento por código novo no mesmo artefato.
5. **Garantia operacional:** nenhum lote é promovido sem passar por todos os critérios. Isso garante o que foi aceito; não promete antecipadamente que toda função poderá ser expressa em C/C++ puro com o mesmo codegen. Bloqueios continuam explícitos, sem declarar a migração completa enquanto restar assembly de instruções.

## Ponto de partida conferido

Inspeção dos fontes e das evidências na revisão pública **`1ead8db85e7ddb8b183bc5b62b3fdfa2087ccb59`**. Os números abaixo descrevem esse ponto de partida, não uma nova compilação executada durante a elaboração deste plano.

| Medida | Estado inicial |
| --- | ---: |
| Prova integral da baseline | zero diferenças em 10.675.712 bytes |
| Bytes de `.text` provenientes de C compilado | **35.956** |
| Bytes representados por registros de instruções de assembly | **6.715.479** |
| Registros de instruções de assembly | **2.142.911** |
| Assembly externo manual | **144 bytes** |
| Padding declarado | **583.710 bytes** |
| Dados declarados dentro de `.text` | **48.775 bytes** |
| Total dessas categorias de `.text` | **7.384.064 bytes** |
| Endereços únicos no catálogo de correspondências | **19.593** |
| Soma dos tamanhos desses endereços | **864.146 bytes** |
| Entradas classificadas nas famílias estritas `*-exact` | **16.148 / 319.826 bytes** |
| Entradas restantes do catálogo | **3.445 candidatos**, não prova estrita |

Os 35.956 bytes representam aproximadamente **0,49% do tamanho bruto de `.text`**. O campo `compiled_providers=5895` inclui 5.894 provedores C e um de assembly; não significa 5.895 implementações C distintas. Há reutilização de implementações pequenas em vários endereços.

**Inconsistência existente a corrigir:** `recon/STATUS.md` anuncia 866.276 bytes no catálogo. A soma das 19.593 entradas de `recon/matched_functions.json` é 864.146, igual ao campo `totals` do JSON. Não copiar o valor incorreto para relatórios novos.

O aumento das correspondências do catálogo não mede a substituição do assembly. A métrica principal desta etapa vem dos provedores realmente selecionados e emitidos no build final.

## Restrições globais

- Preservar a referência original e seus hashes. Não trocar a referência por um resultado reconstruído para fazer o teste passar.
- Não alterar comparadores, constantes de aceitação ou classificações para esconder divergências.
- Zero máscaras de operandos na aceitação; zero correções de instruções após a compilação; zero extração de bytes do original para preencher código faltante.
- Relocações COFF verdadeiras, resolvidas pelo linker, são permitidas e necessárias. Copiar operandos do original para corrigir o compilador não é relocação legítima.
- `__asm`, funções naked com corpo em assembly, `_emit`, arrays de opcodes, `incbin` ou conversões mecânicas que apenas escondam o disassembly dentro de C não contam como C/C++ recuperado.
- Intrínsecos do compilador podem ser usados quando fundamentados no comportamento original. Registrá-los explicitamente; não confundir intrínseco com emissão manual de bytes.
- Dados, recursos, cabeçalhos e padding podem continuar declarados no formato atual. Não os contabilizar como avanço de código C/C++.
- Objetos e bibliotecas binárias de terceiros podem servir como referência ou dependência identificada. Reutilizar um `.lib` sem recompilar seu fonte não aumenta a recuperação C/C++.
- Uma função promovida que deixe de compilar ou corresponder deve fazer o build falhar. **Nunca voltar silenciosamente ao assembly e manter o crédito de C/C++.**
- Não substituir o linker existente por um build comum de CMake/MSVC esperando o mesmo layout. A identidade depende também do posicionamento, dos símbolos e da geração do PE.
- Não alterar automaticamente o `FFX.exe` instalado na Steam. Gere e valide os candidatos no espaço de trabalho da tarefa.
- Trabalhar localmente, com um agente por padrão. Não executar GitHub Actions nem criar cópias de `ExtrasExtras`, SDKs, jogos, bancos IDA ou do repositório inteiro.

## Base de trabalho e referências

Repositório: [WanxTitanx/ffx-reconstructed](https://github.com/WanxTitanx/ffx-reconstructed). Pacote existente: [build-backup-2026-09-30](https://github.com/WanxTitanx/ffx-reconstructed/releases/tag/build-backup-2026-09-30).

O checkout físico `/mnt/ssd-kingston/ffx-reconstructed` estava na `main` local antiga, commit `2f86bb8a4`, com trabalho de outras frentes. **Não confundir esse nome de branch com a `main` pública atual.** A referência local `codex/public-20260930` apontava para `1ead8db8` na elaboração do plano.

- Partir de uma revisão pública verificada, sem trazer o histórico privado antigo por merge. Se a `main` remota tiver avançado, conferir o delta e registrar o SHA efetivamente escolhido.
- Reutilizar um checkout adequado e livre de alterações de outro autor. Se for necessário isolamento, usar um worktree leve/sparse a partir da revisão pública, buscando apenas fontes e evidências necessários. Não fazer um clone dos diretórios extras.
- Comparar branch, HEAD, arquivos modificados e staging antes de escrever. Não usar `reset`, `clean`, stash automático ou staging global no checkout compartilhado.
- O pacote compacto já está em `/mnt/nvme-samsung/ffx-reconstruction-backups/ffx-build-20260930.tar.zst` e na release `build-backup-2026-09-30`. Extrair somente os itens faltantes; não criar outro backup geral.
- O ambiente Python existente é `/mnt/ssd-kingston/ffx-reconstructed/work/cos-byteproof-41719/recon/ffx/.venv-asm/bin/python`. Conferir que existe e corresponde à versão exigida.
- A referência usada nesta máquina é `/home/wanderson/Documents/ffx-editor-main/work/_ppp_pool/FFX.exe`; conferir a hash antes de utilizá-la.
- A VM disponível na sessão anterior era `windows11-dev-next`. Confirmar o estado e a toolchain antes de compilar. Os pacotes C existentes explicam a execução no Windows.

Leitura inicial obrigatória, nesta ordem:

1. Instruções de trabalho aplicáveis e este plano.
2. `recon/ffx/GOAL.md`, `recon/ffx/complete/README.md`, `recon/ffx/mods/README.md`.
3. `tools/match/code_providers.py`, `text_program.py`, `text_build.py`, `pe_link.py`.
4. `tools/match/coff_relocations.py`, `leaf_build.py` e os READMEs de `c_leaf`, `c_reloc` e `byteproof`.
5. `recon/matched_functions.json`, recibos das famílias estritas e `research/README.md`.

As pesquisas importadas estão em `research/ffx-editor/`; os fontes e investigações locais do Phyre/SDK são referências de comportamento e tipos. Não presumir que a versão do SDK seja a usada pelo executável. As tentativas históricas com Bullet, Lua e Phyre orientam a busca; seus resultados não são prova de impossibilidade de uma reconstrução futura.

## Arquitetura a implementar

### Reutilizar o que já existe

- `coff_relocations.parse_coff(data)` já lê **COFF binário**, inclusive tabelas de símbolos. Reutilizar esse leitor; não criar outro parser nem basear a promoção em nomes truncados do `dumpbin`.
- `code_providers.load(root)` retorna `(providers, observed)`. Cada provedor contém `key`, `family`, `va`, `size`, `section`, `sha256` e `build_manifest_sha256`.
- `text_program.prepare(...)` escolhe os provedores e grava `recon/ffx/text_program/plan.json.gz` e os registros preparados.
- `text_build.build(...)` revalida o plano, carrega os provedores e emite os objetos de `.text`. O `ClassificationGuard` protege a classificação independente dos intervalos.
- `pe_link.py`, `verify_complete_image.py`, `complete_acceptance.py` e `mod_acceptance.py` fecham a prova do arquivo completo.

### Novos componentes propostos

Estes caminhos **ainda não são ferramentas existentes**. Criá-los somente quando executar as tarefas correspondentes.

| Caminho | Responsabilidade |
| --- | --- |
| `recon/ffx/recovered/registry.json` | Seleção explícita de módulos e intervalos C/C++ promovidos |
| `recon/ffx/recovered/include/ffx_abi.h` | Tipos, convenções de chamada e verificações de layout compatíveis com VS2012 |
| `recon/ffx/recovered/src/<sistema>/` | Implementações legíveis, organizadas por responsabilidade |
| `recon/ffx/recovered/contracts/<va>.json` | Evidência de ABI, limites, argumentos, efeitos e dependências de cada alvo |
| `recon/ffx/recovered/recipes/<modulo>.json` | Compilador, flags, fontes, includes, ordem e bibliotecas necessárias |
| `recon/ffx/recovered/proofs/<modulo>.json` | Provas das funções e referências aos recibos de compilação |
| `recon/ffx/recovered/coverage.json` | Contagem derivada do build final; não mantida manualmente |
| `recon/ffx/recovered/HANDOFF.md` | Estado do último lote, comandos, bloqueios e próximos alvos |
| `tools/match/recovered_build.py` | Compilar módulos em diretórios vazios e publicar recibos verificáveis |
| `tools/match/recovered_providers.py` | Validar o registro e entregar provedores no formato já existente |
| `tools/match/recovered_status.py` | Calcular cobertura e diferenças entre duas construções |

`recovered_providers.load(root, observed)` deve retornar `dict[int, dict]`, indexado por VA, compatível com os provedores existentes. Use a família `c_recovered` e registre a linguagem separadamente. O chamador não pode sobrescrever outro provedor ou aceitar intervalos sobrepostos.

O registro deve declarar: versão do esquema, hash do alvo, módulo, fontes e headers, receita, recibo de build, estado ativo/inativo e funções com VA, tamanho, símbolo COFF real e bindings. O símbolo é extraído do objeto e precisa corresponder à assinatura comprovada; não inferir sua decoração só pelo nome no IDA.

O recibo de compilação deve registrar os hashes de todos os insumos transitivos, ferramentas e bibliotecas, os comandos efetivos, os objetos produzidos, seus símbolos/relocações e o resultado da compilação. Fonte alterado, objeto antigo ou recibo incompleto invalidam a promoção.

Interfaces de linha de comando propostas, a implementar na Tarefa 1:

```text
recovered_build.py stage --root ROOT --module ID --output PACKAGE_DIR
recovered_build.py compile --package PACKAGE_DIR --output BUILD_DIR
recovered_build.py verify --root ROOT --module ID --build-dir BUILD_DIR --proof PROOF_JSON
recovered_status.py --root ROOT --image-dir IMAGE_DIR --output COVERAGE_JSON [--before PREVIOUS_JSON]
```

`stage` copia apenas os fontes/headers declarados, a receita e o auxiliar necessário. `compile` roda no Windows com a toolchain fixada, em saída vazia, e limpa flags herdadas no ambiente do processo filho. `verify` roda contra a referência pinada e valida fonte, objetos, ABI declarada e relocações; um resultado aprovado ainda exige a prova do PE completo. O transporte para a VM usa o mecanismo já disponível na máquina, sem embutir credenciais no pacote.

## Tarefa 0 — reproduzir o controle e corrigir a medição

**Arquivos:** `recon/STATUS.md`, `recon/ffx/GOAL.md`, evidências em `recon/ffx/recovered/`; receitas existentes de `c_leaf`, `c_reloc` e `byteproof`.

**Consome:** revisão pública, referência pinada e toolchains identificadas. **Produz:** controle reproduzido, métricas iniciais corretas e árvore de trabalho definida.

- [ ] Conferir HEAD, estado local, espaço livre, referência e versões. Registrar os hashes em um recibo pequeno.
- [ ] Reconstruir os provedores C atuais a partir dos fontes com suas receitas documentadas, ao menos uma vez na preparação desta etapa. Não confundir revalidação de objetos armazenados com recompilação do fonte.
- [ ] Reproduzir a baseline e o demo de mods antes de mexer na seleção de provedores. A execução habitual de `mod_acceptance.py` revalida os provedores legados; ela não substitui a recompilação desses provedores descrita no item anterior.
- [ ] Recalcular o catálogo por VA único e soma dos tamanhos. Corrigir a divergência de 866.276 para 864.146 no estado inicial, se os dados continuarem iguais aos desta inspeção.
- [ ] Registrar uma meta nova de migração C/C++ em `GOAL.md`, preservando o marco anterior de reconstrução mista já concluído.
- [ ] Distinguir no relatório: C/C++ emitido, assembly de instruções, assembly manual, bibliotecas binárias externas, dados e padding. Manter fixo o mapa de classificação usado como referência.

**Aceitação:** controle sem diferenças, ferramentas identificadas e métricas calculadas dos artefatos. Se falhar, resolver o ambiente ou o erro concreto antes de atribuir qualquer avanço à recuperação.

## Tarefa 1 — integrar provedores recuperados ao build real

**Criar:** `recovered_build.py`, `recovered_providers.py`, `registry.json`, `test_recovered_build.py` e `test_recovered_providers.py`.

**Modificar:** `code_providers.load`, a preparação/validação em `text_program.py` e `text_build.py`, apenas onde necessário para admitir a nova família. Reutilizar `coff_relocations.py` e as validações existentes.

**Consome:** módulos compilados com recibos completos. **Produz:** intervalos realmente fornecidos por C/C++ no PE final.

- [ ] Definir e validar o esquema do registro e dos recibos, incluindo unicidade de VA, limites e procedência.
- [ ] Adicionar testes negativos para: fonte alterado após compilar, objeto ausente/antigo, símbolo ambíguo, tamanho errado, faixa sobreposta e relocação inválida.
- [ ] Testar também includes fora do manifesto, toolchain divergente, flags herdadas e compilação que falha sem produzir objeto novo. Um recibo antigo não pode certificar a tentativa atual.
- [ ] Adicionar um caso em que os bytes coincidam na base original, mas falte a relocação de um ponteiro absoluto. A promoção deve falhar.
- [ ] Usar o COFF binário completo para obter nomes longos, símbolos, seções, COMDATs, auxiliares e relocações. Migrar apenas as rotas textuais que ainda estejam limitadas pelo `dumpbin`.
- [ ] Implementar o carregamento da família `c_recovered` sem alterar a validação das famílias antigas.
- [ ] Exigir que o registro preparado selecione o objeto novo para cada intervalo promovido. Rastrear objeto, seção, símbolo e fonte responsáveis pelos bytes emitidos.
- [ ] Testar o controle mais importante: alterar deliberadamente uma constante da função promovida e verificar que o build falha. Não pode reaparecer o assembly anterior por fallback automático.
- [ ] Preservar símbolos canônicos e a participação dos novos chamadores C nas substituições de `mods/`. Chamadas e ponteiros precisam continuar visíveis ao relinker.

**Aceitação:** testes negativos demonstram que a prova não pode ser obtida com objeto errado ou assembly oculto. A infraestrutura sozinha ainda não conta como código recuperado; o piloto da próxima tarefa precisa provar seu uso.

## Tarefa 2 — primeiro piloto real

Os alvos abaixo constam de famílias estritas do catálogo, mas **nenhum está entre os provedores C selecionados no `plan.json.gz` inspecionado**. São candidatos para investigação, não promessas de que a assinatura ou o fonte já estejam prontos.

| VA | Nome atual no catálogo | Tamanho | Evidência atual |
| --- | --- | ---: | --- |
| `0x0093D3D0` | `FFX_Math_Vec3Normalize` | 102 | `arch_ia32_rel32_exact.json` |
| `0x00452680` | `Vector3_Normalize` | 100 | `arch_ia32_rel32_exact.json` |
| `0x005F6130` | `BulletPhysics_TransformNormalizedDirection` | 122 | `phyre_rel32_exact.json` |
| `0x0048CA00` | `Engine_Memcpy64Loop` | 48 | `phyre_rel32_exact.json` |
| `0x0048CAA0` | `Engine_Memcpy32Loop` | 48 | `phyre_rel32_exact.json` |
| `0x009F0C80` | `Phyre_Stream_ReadSegment` | 151 | `phyre_rel32_exact.json` |
| `0x00A5D5F0` | `FFX_Abmap_SphereGridDebugDump` | 1.891 | `string_sym_rel32_exact.json` |

**Preferência inicial:** examinar `0x0093D3D0`. Se o fonte/receita não forem recuperáveis ou a fronteira não for segura, documentar isso e selecionar um dos loops de memória. Não usar `FFX_memcmp` como novo avanço: ele já é fornecido por C.

**Arquivos:** fonte em `recovered/src/math/` ou `recovered/src/memory/`, contrato pelo VA, receita do módulo, prova e testes comportamentais do alvo.

- [ ] Localizar o fonte e a receita que sustentam o match, não somente o dump de um objeto. Conferir o corpo na referência atual.
- [ ] Documentar assinatura real, convenção de chamada, uso de ECX/EDX, pilha, retorno, registradores preservados, campos acessados e efeitos em memória. Tratar o nome existente como hipótese até validar o comportamento.
- [ ] Confirmar extensão única, referências para o interior, tail merging, entradas por continuidade e aliases. Se depender de um bloco inseparável, recuperar o grupo ou adiar; não recortar bytes arbitrariamente.
- [ ] Escrever C legível e compatível com a toolchain histórica. Começar com tipos explícitos e estruturas pequenas; usar C++ quando o ABI e o codegen estiverem compreendidos.
- [ ] Para campos desconhecidos, usar nomes de offset e comentar a incerteza. Para estruturas conhecidas, conferir `sizeof`, alinhamento e `offsetof` com asserts compatíveis com VS2012.
- [ ] Compilar em uma área vazia. Resolver referências por símbolos e bindings, sem literais de endereço usados como ponteiros para contornar relocações.
- [ ] Comparar o corpo completo depois das relocações reais. Registrar toda diferença por offset; investigar assinatura, expressão, temporários e flags a partir dessa diferença.
- [ ] Executar casos de comportamento na ABI correta. Para matemática: zero, sinais, valores usuais e casos especiais de ponto flutuante compatíveis com o contrato observado. Para memória: comprimentos de fronteira, alinhamento, regiões sentinela e retorno; não presumir que sobreposição seja permitida.
- [ ] Ativar o provedor, regenerar o plano de `.text`, reconstruir o executável inteiro e executar os gates da seção seguinte.

**Aceitação:** C emitido aumenta, assembly de instruções correspondente diminui e a baseline inteira continua idêntica. Compilar o alvo sem integrá-lo não encerra esta tarefa.

## Tarefa 3 — tornar cada promoção verificável e contabilizável

**Criar:** `recovered_status.py`, `test_recovered_status.py`, `coverage.json` e o formato de relatório de lote.

**Consome:** registro preparado, manifesto do build final, recibos e mapa nativo independente. **Produz:** contagem auditável e uma decisão de promoção.

- [ ] Calcular cobertura pela união dos intervalos emitidos, evitando duplicação de aliases e sobreposições.
- [ ] Separar bytes das faixas de provedores C de instruções, dados e alinhamento dentro dessas faixas. Uma mudança de classificação não pode aumentar artificialmente a recuperação.
- [ ] Registrar quantidade de implementações-fonte distintas, quantidade de alvos/instâncias e bytes efetivamente emitidos. Não trocar essas medidas entre si.
- [ ] Demonstrar com testes que adicionar um match ao catálogo, adicionar um `.c` não utilizado ou repetir uma entrada não aumenta a cobertura.
- [ ] Exigir ganho de C emitido em lotes declarados como migração. Trabalho de ferramentas, tipos ou documentação pode ter delta zero, desde que seja reportado com essa classificação.
- [ ] Associar a cada promoção um recibo da compilação nova, prova do corpo, prova do PE completo e hashes das entradas utilizadas.

**Aceitação:** um terceiro consegue reproduzir a contagem e determinar de qual fonte vieram os bytes novos. O relatório nunca usa o tamanho do catálogo como substituto para a cobertura C/C++.

## Gates obrigatórios de cada lote

Defina `FFX_PYTHON` para o Python com as dependências exigidas e `FFX_REFERENCE` para a referência pinada. Execute da raiz do checkout de trabalho autorizado.

```bash
FFX_PYTHON=/mnt/ssd-kingston/ffx-reconstructed/work/cos-byteproof-41719/recon/ffx/.venv-asm/bin/python
FFX_REFERENCE=/home/wanderson/Documents/ffx-editor-main/work/_ppp_pool/FFX.exe

sha256sum "$FFX_REFERENCE"

# Executar antes as receitas de compilação dos módulos recuperados.
# A forma do novo recovered_build.py é definida na Tarefa 1.

"$FFX_PYTHON" tools/match/text_program.py prepare
"$FFX_PYTHON" tools/match/mod_acceptance.py --native-demo
"$FFX_PYTHON" -m pytest -q tools/match

cmp -- "$FFX_REFERENCE" recon/ffx/mods/build/disabled/FFX.exe
sha256sum recon/ffx/mods/build/disabled/FFX.exe
```

Esses comandos finais já existem. Não executar um nome de ferramenta proposto neste plano antes de implementá-lo.

`mod_acceptance.py` usa a referência configurada em `definitive_match.EXE_DEFAULT` e não oferece `--reference`. Conferir esse caminho: definir `FFX_REFERENCE` no shell controla os comandos explícitos de hash/`cmp`, mas não muda sozinho a configuração interna do verificador. Em outra máquina, ajustar o caminho de configuração, preservando a hash obrigatória do alvo.

Para a construção dedicada de `complete/FFX.exe`, usar também a sequência documentada em `recon/ffx/complete/README.md`: build sob `strace`, `complete_acceptance.py record-audit` e `verify_complete_image.py`. Respeitar os argumentos e o formato de trace exigidos pelo verificador; não fabricar recibos.

Cada lote precisa comprovar:

- [ ] Novos módulos C/C++ compilados duas vezes, em diretórios vazios, com os mesmos fontes/headers e opções. Não reutilizar o `.obj` anterior como segunda compilação.
- [ ] Compilador, dependências, comandos e todos os objetos ligados ao recibo correspondente. Se uma toolchain legada gerar metadata não determinística no COFF, documentar a causa; não editar o objeto para forçar uma hash. Código, dados colocados, relocações e PE final continuam sujeitos à igualdade literal.
- [ ] Dois PEs vanilla produzidos independentemente, iguais entre si e ao original inteiro; tamanho e SHA fixados neste plano.
- [ ] `different_bytes=0`, `masked_bytes=0`, `raw_code_blob_fallbacks=0`, `source_backed_link_verified=true`, mais rastreabilidade completa dos novos insumos.
- [ ] Build/link sem ler o EXE de referência, confirmado pelo mecanismo de auditoria aplicável. A referência fica na análise/verificação separada. Um diretório vazio, sozinho, não prova quais arquivos o processo abriu.
- [ ] Relocações HIGHLOW e imagens rebaseadas verificadas nas bases do ensaio existente. Não aceitar ponteiros que só funcionem na base preferida.
- [ ] Testes comportamentais específicos da função e testes adversariais do ferramental afetado. A suíte inicial tinha 402 testes e 386 subtestes; esse número crescerá e não deve ser congelado como critério.
- [ ] `mod_acceptance.py --native-demo` continua funcionando: nova compilação, segunda construção independente, chamadas relinkadas e retorno à baseline com o mod desativado. O ensaio de 101.400 chamadas não equivale a gameplay completo.
- [ ] A cobertura adicional aparece nos bytes emitidos, e não somente em `matched_functions.json`.

**Regra de publicação:** um único gate obrigatório falhou, o lote não é promovido. Preserve o último resultado aceito e registre o candidato/bloqueio. Não instalar, publicar como equivalente nem mascarar a falha.

## Tarefa 4 — recuperar módulos que facilitem modificações reais

Depois de um piloto completo, executar lotes de aproximadamente 5–10 funções ou um grupo inseparável de dependências. Selecionar por valor para edição e evidência disponível, não apenas pelo número de funções fáceis.

Ordem sugerida:

1. Matemática, memória, strings, buffers e pequenos contêineres com contratos verificáveis.
2. Leitura/escrita e parsers de formatos, estados e tabelas que alimentam o jogo.
3. Sistemas de gameplay com bom material no FFX Editor: estado de batalha, atributos, comandos, CTB, inventário/equipamentos e pontes ATEL. Obter os VAs da referência atual; não transferir endereços de outra plataforma ou versão.
4. Menus e estruturas de UI, carregamento de assets, entidades e interfaces do Phyre.
5. Renderização e partes complexas do engine, à medida que tipos e dependências estejam estabelecidos.

Para cada módulo, entregar um header utilizável, fontes organizados, contratos e testes, além da prova binária. Evitar reconstruir classes C++ inteiras por suposição: construtores, vtables, RTTI, exceções, estáticos e layout precisam de evidência própria.

Não é necessário recuperar todos os callees antes de um chamador. Ele pode continuar referenciando rotinas ainda em assembly, desde que as assinaturas, os símbolos, as relocações e o comportamento sejam corretos. Recuperar conjuntamente quando o inlining, as caudas compartilhadas ou a geração de código exigirem.

## Tarefa 5 — preservar a liberdade de criar código novo

Manter dois produtos explícitos:

| Produto | O que pode mudar | Aceitação |
| --- | --- | --- |
| Vanilla reconstruída | Representação-fonte e organização interna do projeto | PE inteiro byte-idêntico ao original |
| Variante modificada | Regras, funções, código/dados adicionais e referências previstas no pacote | Build reproduzível, relink correto e testes específicos da mudança |

Reutilizar `mod.json`, `replacements`, `bindings` e as seções `.modtxt`, `.modro`, `.moddat`. Não criar um segundo sistema de hooks para contornar o linker.

- [ ] Os headers recuperados podem ser compartilhados com módulos novos quando forem compatíveis com o perfil de compilação de mods.
- [ ] O código novo usa símbolos para acessar funções e dados existentes; não espalhar endereços absolutos no fonte.
- [ ] Cada substituição preserva a assinatura e a convenção esperadas, ou inclui uma adaptação explicitamente projetada e validada.
- [ ] Um módulo opt-in demonstra o ciclo editar C/C++ → compilar → linkar dentro do EXE → testar → desativar → obter novamente a hash original.
- [ ] Funcionalidades de gameplay ganham seus próprios testes de cena, estado e persistência quando aplicável. Não apresentar a aceitação do demo de comparação como prova de um mod de batalha ou menu.

O código novo pode crescer. Já a reconstrução vanilla não recebe permissões especiais para mudar de tamanho, de endereços ou de hash.

## Tarefa 6 — fechar os casos difíceis sem adulterar os critérios

Esta fase inclui casos de alocação de registradores, x87, SEH/EH, thunks, funções compartilhadas, inlining/LTCG, constantes e tabelas emitidas pelo compilador e código sem fronteira de função bem estabelecida.

- [ ] Usar as experiências anteriores para não repetir varreduras cegas. Toda tentativa deve indicar uma hipótese concreta e registrar a combinação de fonte, flags e toolchain já testada.
- [ ] Para diferenças de codegen, investigar assinatura, tipos, ordem das expressões, duração dos temporários, aliasing e contexto da unidade de tradução. Não atribuir toda divergência a flags.
- [ ] Para nomes truncados ou símbolos não resolvidos, usar o objeto COFF e sua tabela de strings completos. Não resolver nomes ambíguos por prefixo.
- [ ] Para ponto flutuante, preservar instruções, precisão intermediária e convenção de retorno observadas. Não aceitar apenas proximidade numérica.
- [ ] Não interpretar um `.obj` de LTCG como COFF comum. Quando o alvo depender de LTCG, adicionar uma receita e uma prova próprias para o resultado de link, sem tratar isso como licença para recortar o EXE original.
- [ ] Não concluir que um SDK é incompatível para sempre só porque uma configuração amostrada não corresponde. Registrar versão, flags, contexto e evidência; retomar quando houver uma hipótese nova.
- [ ] Resolver também instruções fora dos intervalos hoje catalogados. Converter apenas as 66.557 entradas do inventário pode não cobrir toda a região executável.
- [ ] Se um trecho permanecer em assembly, mantê-lo visível na contagem e no relatório. Não rebatizá-lo como C para encerrar a meta.

**Conclusão de longo prazo:** toda instrução nativa pretendida nesta migração tem origem em C/C++ compilado ou está explicitamente pendente. A meta de zero assembly só está cumprida quando a cobertura e a prova integral demonstrarem isso; dados e padding continuam discriminados.

## Foco de revisão

Estes casos precisam aparecer nos testes das tarefas responsáveis:

1. **ABI e tipos:** retorno, limpeza da pilha, registradores preservados, signedness, truncamento e campos/alinhamento errados. Uma assinatura plausível pelo nome não é suficiente.
2. **Relocações e identidade de símbolos:** nomes longos, strings iguais em endereços diferentes, DIR32/REL32, adendos, chamadas e ponteiros que precisam continuar funcionando após rebasing e relink de mods.
3. **Fronteiras e propriedade dos bytes:** caudas compartilhadas, entradas internas, padding, dados em `.text`, aliases e COFF com várias funções. Nenhuma sobreposição ou fatia arbitrária recebe crédito.
4. **Proveniência:** objeto antigo, fonte alterado, falha de compilação, biblioteca sem fonte, arquivos fora do manifesto e fallback silencioso. Os testes negativos devem realmente reprovar esses casos.
5. **Codegen e comportamento:** x87/SSE, NaN/zero com sinal quando relevantes, loops de fronteira, efeitos em memória e decisões de inlining. Depois da comparação estrita, o fonte ainda precisa ser compreensível para alterações futuras.

## Entrega e coordenação de cada lote

O commit deve incluir somente os arquivos revisados do lote: fontes/headers, contratos, receitas, registro, testes e evidências necessárias. Respeitar o `.gitignore`, auditar segredos antes de publicação e manter ferramentas/SDKs volumosos fora do Git. Não fazer merge de branches privadas antigas apenas para transportar alguns fontes para a história pública.

Atualizar `recovered/HANDOFF.md` com:

- SHA do código e identidade da referência/toolchain.
- VAs e implementações-fonte promovidos; arquivos e símbolos correspondentes.
- Bytes C/C++ efetivamente emitidos antes/depois, assembly restante e dados/padding separados.
- Comandos e resultados da compilação, testes, `cmp`, hash final e replay independente.
- Bloqueios concretos, experiências já feitas e próximos candidatos.
- Escopo real do runtime testado; não chamar validação offline de gameplay.

**Primeira entrega exigida da IA:** controle reproduzido + infraestrutura mínima de provedores + uma função não trivial integrada como C/C++ + ganho real de cobertura + executável inteiro idêntico. Depois disso, continuar em lotes. Não terminar a primeira etapa apenas com um relatório maior de matches.

## Prompt para entregar à outra IA

> Continue o projeto https://github.com/WanxTitanx/ffx-reconstructed seguindo `docs/superpowers/plans/2026-09-30-ffx-cpp-byte-identical.md`. O objetivo novo é substituir o assembly por C/C++ legível que realmente forneça os bytes do executável final. A baseline sem mods deve sempre ter 10.675.712 bytes, SHA-256 `78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced` e `cmp` integral com saída 0.
>
> Confira primeiro a revisão pública e preserve o checkout compartilhado. Não comece pela `main` local antiga só por ela se chamar main. Reutilize o pipeline existente; avance inicialmente pelas Tarefas 0–3 e entregue uma promoção real antes de ampliar o lote. O ponto de partida tem 35.956 bytes de C no build, apesar de 19.593 endereços catalogados. Aumentar o catálogo, gerar pseudocódigo ou compilar objetos que não são ligados não cumpre a missão.
>
> Não use máscaras, patches de instruções, arrays de opcodes disfarçados de C, stubs substitutos ou fallback silencioso para obter sucesso. Compile os novos provedores de fontes em áreas vazias, valide ABI e relocações e reconstrua o PE inteiro. Preserve também o caminho de mods, no qual alterações intencionais têm outra hash e a desativação volta ao original.
>
> Trabalhe localmente, sem Actions e sem novos backups de SDKs, ExtrasExtras ou do repositório inteiro. Não crie subagentes por conta própria. Registre a cobertura efetiva, as provas e os bloqueios; prossiga para funções e módulos que tornem gameplay, menus e sistemas do engine mais editáveis, mantendo os critérios de aceitação.
