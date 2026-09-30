# FFX Reconstructed

Reconstrução verificável do `FFX.exe` de Final Fantasy X HD Remaster para Windows x86, com ferramentas para compilar alterações dentro do próprio executável.

## Estado verificado em 30/09/2026

A baseline reconstruída reproduz **todos os 10.675.712 bytes** da referência:

```text
SHA-256: 78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced
Formato: PE32 / x86
Comparação integral: 0 bytes diferentes
```

As evidências estão em [`recon/ffx/complete/proof.json`](recon/ffx/complete/proof.json), no manifesto e nos recibos associados. A aceitação confere os bytes, a procedência dos insumos e uma segunda linkagem independente. O linker da baseline não lê o executável original; a referência é usada pelo verificador separado.

A representação combina **C, assembly simbólico e dados declarados**. O plano contém 2.142.911 registros de instruções de assembly e 35.956 bytes de código proveniente de C compilado. Isso reconstrói o executável completo; a recuperação de todas as funções em C/C++ de alto nível continua sendo trabalho futuro.

O usuário reportou que a baseline instalada abriu normalmente pela Steam no Linux/Proton em 30/09/2026. Essa sessão usava os módulos já presentes na instalação. É um teste manual de abertura; alterações novas ainda precisam de validação própria de gameplay.

## Organização

| Caminho | Conteúdo |
| --- | --- |
| [`recon/ffx/complete/`](recon/ffx/complete/) | Receitas e evidências da reconstrução integral |
| [`recon/ffx/text_program/`](recon/ffx/text_program/) | Instruções simbólicas, referências e seleção dos provedores C |
| [`recon/ffx/pe_data/`](recon/ffx/pe_data/) e [`pe_headers/`](recon/ffx/pe_headers/) | Dados, recursos, cabeçalhos e estrutura PE |
| [`recon/ffx/c_leaf/`](recon/ffx/c_leaf/), [`c_reloc/`](recon/ffx/c_reloc/) e [`byteproof/`](recon/ffx/byteproof/) | Fontes e receitas de compilação C/assembly com prova estrita |
| [`recon/ffx/mods/`](recon/ffx/mods/) | Compilação e linkagem de código novo no executável |
| [`tools/match/`](tools/match/) | Assembler, linker, verificadores, testes e pesquisas de correspondência |
| [`research/`](research/) | Pesquisas e referências de engenharia reversa, incluindo materiais do FFX Editor |
| [`recon/STATUS.md`](recon/STATUS.md) | Estado detalhado das funções e das frentes de recuperação |
| [`src/`](src/) e `CMakeLists.txt` | Protótipo anterior em C++; a receita da baseline byte-idêntica fica em `tools/match/` |

## Ambiente e dependências

O ambiente validado usa Linux, Python 3.14, `iced-x86==1.21.0`, LLVM/Clang 21, GNU binutils, GCC com suporte a i386 e `strace`. Os provedores C históricos usam **MSVC 2012 x86 17.00.50727.1**, com opções específicas registradas em cada pacote. A compilação desses provedores foi feita em uma VM Windows.

Este repositório publica fontes, declarações preparadas e recibos. Instaladores, SDKs, ferramentas binárias, bancos IDA, ambientes virtuais, caches e executáveis gerados ficam no backup local. Um clone novo exige instalar as ferramentas e reconstruir os objetos C conforme as receitas abaixo; os recibos, sozinhos, não substituem esses objetos.

```bash
python3.14 -m venv recon/ffx/.venv-asm
recon/ffx/.venv-asm/bin/python -m pip install iced-x86==1.21.0 pytest==9.1.1
```

Consulte as receitas de [`c_leaf`](recon/ffx/c_leaf/README.md), [`c_reloc`](recon/ffx/c_reloc/README.md) e [`byteproof`](recon/ffx/byteproof/README.md) para gerar os objetos e seus manifestos com a toolchain histórica. Preserve os diretórios `build/`, logs, snapshots de entrada e recibos produzidos.

O `.gitattributes` preserva os bytes dos fontes, inclusive os finais de linha, em checkouts Linux e Windows. As evidências históricas registram caminhos absolutos do ambiente em que foram geradas. Em outra máquina, configure a referência usada por `tools/match/definitive_match.py` e regenere os recibos aplicáveis. Não edite hashes dos manifestos para contornar verificações.

## Reconstruir a baseline

Com as dependências e os objetos dos provedores C preparados, execute da raiz:

```bash
ffx_root="$(pwd -P)"
strace -f -s 4096 -yy -e trace=open,openat,openat2,execve \
  -o "$ffx_root/recon/ffx/complete/build.trace" \
  "$ffx_root/recon/ffx/.venv-asm/bin/python" \
  "$ffx_root/tools/match/run_source_only.py" \
  "$ffx_root/tools/match/rebuild_complete.py"

recon/ffx/.venv-asm/bin/python tools/match/complete_acceptance.py record-audit
recon/ffx/.venv-asm/bin/python tools/match/verify_complete_image.py
```

O resultado é `recon/ffx/complete/FFX.exe`. A referência original, com a hash acima, deve ser fornecida localmente para a verificação. A descrição completa do processo e de suas provas está em [`complete/README.md`](recon/ffx/complete/README.md).

## Compilar código novo no FFX.exe

O caminho de mods compila C/C++ para COFF i386 e resolve as referências durante a linkagem. Código, constantes e dados graváveis podem ocupar seções novas `.modtxt`, `.modro` e `.moddat`.

```bash
recon/ffx/.venv-asm/bin/python tools/match/run_source_only.py tools/match/mod_link.py
recon/ffx/.venv-asm/bin/python tools/match/mod_acceptance.py --native-demo
```

O exemplo [`compare_demo`](recon/ffx/mods/compare_demo/) substitui as referências a `FFX_memcmp`, em `0x401020`, por uma implementação compilada nova. Ele altera a magnitude do resultado e registra comparações em dados adicionados. As sete chamadas existentes são resolvidas pelo linker. Esse fluxo dispensa a instalação de hooks, trampolins ou DLL de modificação em runtime.

A variante modificada tem tamanho e hash diferentes por definição. Desativar o pacote reconstrói a baseline byte-idêntica:

```bash
recon/ffx/.venv-asm/bin/python tools/match/mod_link.py --disable \
  --output recon/ffx/mods/build/disabled
```

O ensaio nativo do exemplo cobre 101.400 chamadas em três bases de carga. Ele testa a rotina modificada por uma chamada relinkada; não executa o chamador inteiro nem uma partida. O formato de `mod.json`, os bindings, o contrato de ABI e as limitações do linker estão em [`mods/README.md`](recon/ffx/mods/README.md).

## Verificação local e publicação

A suíte inclui três testes que executam o demo nativo. Gere primeiro seus artefatos com `mod_acceptance.py --native-demo`; uma árvore sem esses produtos de build ainda não atende à pré-condição desses testes.

```bash
recon/ffx/.venv-asm/bin/python -m pytest -q tools/match
```

A publicação de 30/09/2026 reúne a integração `ebed41f4d` e pesquisas locais adicionais em um snapshot sobre a `main` remota anterior. O histórico de desenvolvimento local e os insumos grandes foram preservados em backup, sem reescrever a história remota existente.

As verificações de publicação são executadas localmente. Não há workflow de GitHub Actions adicionado por esta atualização. O relatório sanitizado da auditoria de segredos fica em [`security/publication-audit.json`](security/publication-audit.json); evidências que possam conter material sensível permanecem privadas.

Final Fantasy X e as bibliotecas de terceiros pertencem aos respectivos titulares. A reconstrução não recupera o projeto C++ original. As licenças dos componentes de terceiros continuam aplicáveis aos respectivos arquivos.
