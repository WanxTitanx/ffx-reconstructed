# Modificar e reconstruir o FFX.exe

Este caminho compila alterações C/C++ em objetos i386 e integra seu código e seus
dados ao próprio executável. As referências existentes são resolvidas na linkagem.
O produto não instala hooks, trampolins, injetores ou uma DLL de substituição.

A construção sem alterações continua sujeita ao verificador estrito original.
Seu SHA-256 é 78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced.
Uma construção modificada tem outro hash; sua prova compara todos os bytes com
uma segunda compilação/linkagem independente e registra as diferenças da base.

## Construir e verificar

Execute a partir do worktree work/cos-byteproof-41719:

~~~sh
recon/ffx/.venv-asm/bin/python tools/match/run_source_only.py tools/match/mod_link.py
~~~

O resultado fica em recon/ffx/mods/build/compare_demo/FFX.exe. O comando sempre
compila compare_demo/compare.c em um diretório temporário novo. Não usa um
executável existente como matéria-prima para produzir o modificado.

Para verificar compilação, linkagem, rastreamento, comportamento do exemplo em
x86 e retorno à baseline:

~~~sh
recon/ffx/.venv-asm/bin/python tools/match/mod_acceptance.py --native-demo
~~~

O verificador recompila em outro processo e diretório vazio. Exige igualdade do
objeto de modificação, do IR tipado, do manifesto inteiro e do PE inteiro entre
as execuções. O recibo inclui o compilador e suas bibliotecas de execução. O trace
precisa comprovar os comandos exatos, o consumo dos fontes e bibliotecas e a
criação e leitura do objeto e do IR novos. Artefatos antigos ou recibos incompletos falham.

O procedimento também reconstrói a baseline em build/disabled, reassemblando os
objetos de texto/dados e revalidando os recibos dos provedores C da toolchain
legada. Depois executa o verificador estrito, uma linkagem independente e cmp
integral contra o original. Não recompila na VM todos os provedores C legados;
o código C/C++ novo do mod é compilado do zero em ambas as execuções.

Para construir apenas a variante desativada:

~~~sh
recon/ffx/.venv-asm/bin/python tools/match/mod_link.py --disable \
  --output recon/ffx/mods/build/disabled
~~~

recon/ffx/complete/FFX.exe é protegido como baseline. O diretório mods/build contém
saídas reproduzíveis e não entra no Git.

## Definir uma alteração

O pacote contém uma unidade de tradução C/C++ e a lista explícita de seus arquivos,
incluindo os headers. O compilador trabalha com cópias desses arquivos.

~~~json
{
  "schema_version": 1,
  "name": "minha-alteracao",
  "source": "change.cpp",
  "files": ["change.cpp", "change.h"],
  "replacements": [
    {"symbol": "_sym_00401020", "target": "_FFX_memcmp_modified"}
  ],
  "bindings": {}
}
~~~

symbol identifica a entrada original no mapa reconstruído. target é o nome real
do símbolo COFF compilado. Para manter a decoração C em C++, declare extern "C"
e preserve a convenção de chamada e a assinatura originais. Uma unidade pode
definir várias funções, estruturas, constantes e globais.

bindings liga referências externas do módulo a símbolos existentes. Por exemplo,
"_original_compare": "_sym_00401020" permite declarar e chamar explicitamente o
corpo original preservado. A mesma forma permite referenciar globais e entradas
IAT existentes. Referências não resolvidas e bindings não utilizados falham.

Ponteiros literais para endereços da imagem original, como uma conversão de
0x00401020 para ponteiro de função, são rejeitados: faltaria a relocação quando
o executável mudasse de base. Declare a referência externa e use bindings. A
checagem usa o IR tipado produzido pelos mesmos fontes e opções; uma constante
inteira com os mesmos bits continua permitida. Conversões de endereços calculados
em execução são registradas separadamente e continuam exigindo análise semântica.

~~~sh
recon/ffx/.venv-asm/bin/python tools/match/run_source_only.py tools/match/mod_link.py \
  --package recon/ffx/mods/meu_pacote --output recon/ffx/mods/build/meu_pacote
~~~

O perfil é freestanding i686-pc-windows-msvc, com otimização O2, COFF determinístico
e sem dependências implícitas de runtime. Exceções, RTTI, assembly embutido e
inicialização thread-safe de estáticos C++ estão desativados. A baseline mantém
seu assembly reconstruído; a restrição de assembly embutido se aplica ao pacote
novo e impede leituras ocultas por diretivas de assembler. O compilador de código
novo não substitui a toolchain histórica dos provedores C da base.

## Contrato da linkagem

Os corpos originais permanecem intactos. Chamadas e ponteiros registrados nos
objetos originais resolvem para a definição compilada nova. O espaço adicional
usa .modtxt (leitura/execução), .modro (somente leitura) e .moddat (leitura/escrita).
Os RVAs e offsets anteriores são preservados. Cabeçalhos e HIGHLOW são produzidos
de declarações estruturadas e das relocações reais, sem correção posterior de
bytes para forçar um resultado de comparação.
As subseções COFF com sufixo $ são ordenadas pelo nome ao construir cada grupo,
preservando os offsets dos símbolos em suas respectivas subseções e respeitando
o alinhamento declarado pelo objeto, sem inserir lacunas artificiais nas tabelas.

A seleção exige uma função com extensão única confirmada pelo mapa nativo e pelo
hash dos bytes. Entradas compartilhadas, referências externas ao interior,
branches curtos sem relocação e entradas por continuidade são rejeitados.
Quando a mudança exige um bloco de funções dependentes, inclua seus corpos no
mesmo módulo e declare suas entradas; chamadas entre corpos antigos preservados
continuam pertencendo à baseline.

A cobertura é a das referências explícitas do modelo simbólico e dos objetos
COFF. Cálculos dinâmicos de endereços, contratos de ABI e efeitos de gameplay
exigem análise e testes específicos da alteração. A aprovação do exemplo não
afirma que todos os comportamentos do jogo foram testados.

Os imports existentes são preservados. Novas DLLs importadas, TLS, inicializadores
especiais de C++, diretivas não suportadas e metadados que exigem outro modelo de
carregamento não são aceitos implicitamente. As seções novas usam os três espaços
de cabeçalho disponíveis; seu tamanho pode crescer dentro dos limites PE32 e da
capacidade da tabela de relocações.

## Exemplo e evidência

compare_demo substitui FFX_memcmp em 0x401020. Mantém ordenação e igualdade,
muda a magnitude do resultado para 7 e registra chamadas em dados novos. É uma
demonstração controlada, não validada em gameplay nem em concorrência; não é
apresentada como uma correção de comparação para instalar no jogo.

O ensaio nativo usa o executável produzido e uma chamada realmente relinkada.
Confere o destino dessa chamada e executa o callee correspondente em imagens
carregadas e rebaseadas. Não equivale a executar a função chamadora inteira nem
a iniciar o jogo. O relatório informa exatamente os casos executados.

As saídas aprovadas incluem manifest.json, proof.json, source_only_audit.json,
build.trace.gz, compiler/, acceptance/, native/ e a prova em ../disabled.
O manifesto vincula fontes, ferramentas, objetos, relocações, seções e todos os
intervalos de bytes alterados. Requisitos: Python do venv, Clang i386/COFF, strace,
cmp e, para o ensaio nativo, GCC/binutils com emissão ELF i386 sem libc.
