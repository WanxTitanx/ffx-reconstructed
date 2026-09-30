# Provedores C/C++ recuperados

Este pacote substitui intervalos do assembly reconstruído por funções compiladas
que fornecem efetivamente os bytes do executável final. O primeiro módulo é
`math_vec3`, função `FFX_Math_Vec3Normalize` em `0x0093D3D0`, com 102 bytes.

As duas compilações independentes do piloto produziram PEs de 10.675.712 bytes,
literalmente iguais entre si e à referência, com SHA-256
`78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced`.
O C emitido passou de 35.956 para 36.058 bytes. Foram substituídos 46 registros
de instruções, sem alterar dados, padding ou os 144 bytes de assembly manual.

## O que entra na prova

`registry.json` seleciona explicitamente os módulos ativos, seus arquivos,
receitas, recibos, símbolos COFF e intervalos. Um provedor ativo inválido faz o
build falhar. Não existe retorno automático ao assembly anterior.

`recovered_build.py stage` fecha um pacote contendo somente fontes, headers,
receita, declaração do módulo e auxiliares. `compile` exige uma saída vazia e
compila no Windows com o MSVC 2012 x86 17.00.50727.1. Flags herdadas são removidas;
includes e arquivos carregados pelo compilador são registrados e vinculados por
hash. O recibo é publicado somente após sucesso e conferência dos insumos.

`recovered_providers.py` usa o leitor COFF existente. Cada função precisa ocupar
sua seção executável inteira, ter símbolo inequívoco e limites nativos seguros.
Referências são resolvidas por relocações reais. Dependências definidas em outra
seção do objeto exigem outro proprietário recuperado; um binding não pode
esconder uma constante ou função interna descartada. Ponteiros absolutos precisam
dos mesmos locais HIGHLOW da referência, mesmo quando os bytes coincidiriam na
base preferida. A aceitação não altera instruções emitidas pelo compilador.

O registro preparado e o `ClassificationGuard` continuam pertencendo ao pipeline
existente. Depois da admissão, o linker precisa produzir o PE inteiro e os gates
de `complete_acceptance.py` e `mod_acceptance.py` continuam obrigatórios.

## Compilar um módulo

No host, a partir da raiz do checkout:

~~~sh
FFX_PYTHON=/mnt/ssd-kingston/ffx-reconstructed/work/cos-byteproof-41719/recon/ffx/.venv-asm/bin/python
"$FFX_PYTHON" -B tools/match/recovered_build.py stage \
  --module math_vec3 --output recon/ffx/recovered/staging/math-new
~~~

Transporte somente esse pacote para a VM. Execute no Windows em uma saída nova:

~~~powershell
& 'C:/Program Files/Python314/python.exe' 'C:/task/package/helpers/recovered_build.py' compile --package 'C:/task/package' --output 'C:/task/build-a'
~~~

Repita em `build-b`, sem copiar o objeto da primeira compilação. Traga cada
diretório de saída inteiro, preservando `compile.json`, logs, objeto e snapshots.
Verifique os dois objetos no host:

~~~sh
"$FFX_PYTHON" -B tools/match/recovered_build.py verify \
  --module math_vec3 --build-dir recon/ffx/recovered/build/math_vec3/a \
  --proof recon/ffx/recovered/proofs/math_vec3.json
"$FFX_PYTHON" -B tools/match/recovered_build.py verify \
  --module math_vec3 --build-dir recon/ffx/recovered/build/math_vec3/b \
  --proof recon/ffx/recovered/proofs/math_vec3-second.json
~~~

O `verify` abre a referência fixada em `definitive_match.EXE_DEFAULT`. O build e
o carregamento comum de provedores não precisam abrir esse executável. As provas
de corpo, isoladamente, ainda não promovem o módulo.

Selecione primeiro `build/math_vec3/a` e a prova correspondente no registro,
prepare o plano e construa em uma saída nova. Repita com `b` e sua prova:

~~~sh
"$FFX_PYTHON" -B tools/match/text_program.py prepare
"$FFX_PYTHON" -B tools/match/mod_acceptance.py \
  --output recon/ffx/mods/build/recovered-lot1-b/compare_demo --native-demo
cmp /home/wanderson/Documents/ffx-editor-main/work/_ppp_pool/FFX.exe \
  recon/ffx/mods/build/recovered-lot1-b/disabled/FFX.exe
"$FFX_PYTHON" -B -m pytest -q tools/match
~~~

Preserve a última saída aceita ao escolher o diretório do lote seguinte. Não
execute um build experimental sobre a referência, a instalação Steam ou uma
prova que ainda precisa ser mantida.

## Cobertura derivada do executável

~~~sh
"$FFX_PYTHON" -B tools/match/recovered_status.py \
  --image-dir recon/ffx/mods/build/recovered-lot1-b/disabled \
  --output recon/ffx/recovered/coverage.json \
  --before recon/ffx/recovered/control/coverage.json
~~~

O medidor revalida os traces preservados do build e do replay, os hashes dos
snapshots, o plano selecionado e os intervalos no PE. Para os provedores novos,
ele resolve novamente o objeto compilado e compara o resultado com a faixa do
executável. Um catálogo maior, um arquivo C não ligado ou um alias duplicado não
recebem crédito. Dados e alinhamento dentro de uma faixa C são discriminados pelo
mapa nativo independente, cuja identidade deve permanecer igual entre lotes.

Relatórios históricos descrevem o executável e seus snapshots, mesmo quando o
checkout já contém outro lote. Eles não certificam automaticamente o fonte atual.

## Teste nativo de matemática

`native/vec3_check.c` é um harness separado, nunca ligado como provedor de FFX.
Ele compara o callee dos PEs completos usando o `_CIsqrt` real do `MSVCR110.dll`
fornecido com o jogo. O teste não inicia o jogo nem chama sua função de entrada.

O piloto passou em 331.776 comparações, 663.552 chamadas diferenciais e 12
chamadas de valores conhecidos. A matriz inclui 24/53/64 bits de precisão x87,
quatro arredondamentos, zero com sinal, subnormais, infinitos, NaNs, valores
usuais, dados pseudoaleatórios e alias exato de origem/destino. Confere pilha,
registradores preservados, controle/estado x87 e sentinelas. Uma implementação
deliberadamente errada falhou antes da execução positiva.

As bases Windows são `0x10000000`, `0x20000000` e `0x50000000`, com as 283.602
relocações HIGHLOW. O loader Windows ocupa a faixa de `0x400000` antes da entrada
desse harness; ela continua coberta pelo ensaio Linux i386 existente de mods e
pela comparação literal. O novo teste de matemática não alega execução Windows
nessa base. Exceções de ponto flutuante não mascaradas, sobreposição parcial e
gameplay não foram cobertos.

O runner `tools/match/recovered_native.py` recebe `--reference`, `--candidate`,
`--runtime`, `--source-dir`, `--recipe` e `--output`. Execute-o na VM com os
auxiliares Python do pacote, o harness e os dois PEs. O runtime não é distribuído
neste diretório. O relatório registra seu hash e exige o carregamento real da DLL.

## Evidências do piloto

Logs são preservados como `.log.gz` para respeitar o `.gitignore`. O SHA do
log original registrado nos recibos corresponde ao conteúdo descompactado.

- `control/`: recompilações legadas, controle, catálogos e cobertura inicial.
- `proofs/math_vec3*.json`: corpos das duas compilações e comparação entre elas.
- `proofs/no-fallback.json`: alteração real da constante rejeitada pelo build.
- `proofs/native_math_vec3/`: resultado nativo, controle negativo e traces.
- `evidence/lot1/`: recibos compactos das duas construções integrais e dos mods.
- `coverage.json`: cobertura selecionada atual, com fonte/objeto/símbolo/offset.

Os objetos COFF das duas compilações diferem no timestamp e em metadata de
depuração que registra o diretório de compilação. Código, dados das seções e
relocações coincidem; nenhum objeto foi editado para igualar hashes. Os PEs
completos permanecem literalmente iguais. `build/` e `staging/` são caches locais;
os arquivos compactos de evidência não dispensam uma recompilação nova ao promover
outro lote.
