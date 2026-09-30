# PROMPT SINCERO — PRÓXIMO AGENTE PS2 FFX EXTRACTION

## O que FOI feito (resultados reais)

### 1. Split do ISO em chunks
- ISO original: `F:\ffx-reconstructed\ExtrasExtras\FFXINTERNATIONAL\ffx_ps2_part000/001/002` (3 partes, ~4.5GB total)
- Cada chunk é ~2GB (2048 bytes/setor)
- Processo: Python script que leu o ISO inteiro e dividiu em blocos

### 2. Extração da partição de boot (ISO 9660)
- 13 arquivos extraídos via `ps2iso_py` + `Ps2IsoTools`
- Localização: `PS2TESTE/unipyx/`
- Inclui: SLPS_250.88 (ELF PS2), IOPRP234.IMG, drivers IRX

### 3. Análise do ELF PS2 no IDA Pro
- ELF aberto via IDA MCP (session 84ef8f94)
- **10.335 funções** decompiladas
- Constantes descobertas:
  - 279 arquivos no índice do jogo
  - file_count = 279, first_file = 280
  - alloc_unit = 0x20000 (128KB)
  - Senha PFS: `ffxpassf` (6 bytes)
  - Build date: "Nov 8 2001 12:36:33"
- Funções mapeadas:
  - `sub_162EB8` — cálculo de LBA por file ID
  - `sub_1631D0` — leitura do DVD
  - `sub_164A70` — inicialização do filesystem
  - `sub_1660A0` — configuração da senha `ffxpassf`
  - `sub_166380` — montagem do PFS

### 4. Extração por Magic Bytes
- Scan de setor em setor (2048 bytes) nos 3 chunks
- Detecção de: TIM2, VAG, FTCX, SEDS, SEDB, MGRP, MON, SPS2, BTL
- **Resultado:** 347 arquivos com magic headers

### 5. Extração por Entropy Split
- **Algoritmo:** entropia de Shannon para encontrar limites de arquivos
- Index D:\ por hash de 256 bytes (3.795 arquivos)
- Threshold: mudança >2.0 = boundary de arquivo
- **Resultado:** 4.992 arquivos extraídos

### 6. LBA Table Extraction
- Tabela de alocação localizada em LBA 329066
- 279 entries × 4 bytes = 1.116 bytes
- Valores: 5.680 → 18.228 (offsets em setores)
- **Resultado:** 279 arquivos extraídos via LBA

### 7. Nomeação via D:\
- Worker naming com hash match contra D:\
- Size + entropy matching
- **Resultado:** 822 arquivos com nomes D:\ completos

### 8. Identificação por Estrutura
- Análise profunda de 496 arquivos unknown
- Detecção de: VIF_MODEL (456), GS_TEXTURE (8), BINARY_DATA (23), SPARSE_DATA (5), STRING_DATA (4)
- **Resultado:** 496 arquivos classificados por tipo

## O que NÃO foi feito (limitações reais)

### 1. Tabela LBA incompleta
- O ISO real tem 368+ entries (Worker 1 descobriu)
- Só processamos 279 entries (as primeiras)
- As 89 entries extras (279-367) não foram extraídas

### 2. Raw chunks não fatiados
- Os 34 chunks em `raw_ps2_data/` SÃO os dados brutos do jogo
- Cada chunk é um bloco contínuo de dados PS2 nativo
- NÃO foram fatiados em arquivos individuais
- Contêm: modelos VIF, texturas GS, mapas, áudio

### 3. 135 arquivos identified não nomeados
- Classificados por tipo (VIF_MODEL, GS_TEXTURE, etc)
- Mas NÃO têm nomes reais do jogo
- São categorias, não identificações

### 4. Formato PS2 nativo ≠ PC
- Arquivos PS2 têm endianness diferente
- Texturas são swizzled (não lineares)
- Modelos usam VIF packets (não Mesh)
- **Não dá pra comparar byte-a-byte com D:\**

### 5. Falta decodificação completa da tabela LBA
- A fórmula está mapeada: `(flags[N+1] & 0x3FFFFF) - (flags[N] & 0x3FFFFF)) * 2048`
- Mas não foi aplicada a todas as 368 entries
- As entries extras podem revelar mais arquivos

## O que o PRÓXIMO AGENTE deve fazer

### Prioridade 1: Completar a tabela LBA
```python
# A tabela está em LBA 329066, 4 bytes por entry
# Ler todas as 368+ entries
# Calcular LBA real de cada arquivo usando a fórmula:
# LBA = PARTITION_START + entry[i]
# Size = (entry[i+1] - entry[i]) * 2048
# Extrair cada arquivo e salvar
```

### Prioridade 2: Fatiar os raw chunks
- Cada chunk em `raw_ps2_data/` precisa ser cortado em arquivos individuais
- Usar a tabela LBA como guia
- Para arquivos sem magic header, usar entropy analysis
- Cada arquivo deve ser salvo com nome baseado no D:\ (se disponível)

### Prioridade 3: Nomear os 135 identified
- Usar match por: tamanho + entropia + first4 bytes + padrão de bytes
- Para VIF_MODEL: tentar match por estrutura interna (bone count, vertex count)
- Para GS_TEXTURE: tentar match por dimensões e formato

### Prioridade 4: Documentação completa
- Atualizar `PS2_ISO_EXTRACTION_MASTERWORK.md` com resultados finais
- Atualizar `SESSION_HANDOFF.md`
- Criar índice de todos os arquivos extraídos

## Ferramentas disponíveis
- IDA Pro MCP (session 84ef8f94, ELF SLPS_250.88)
- Python scripts em `F:\ffx-reconstructed\tools\ps2_*.py`
- D:\ reference: `D:\FFX Extracted\FFX\ffx_ps2\ffx\master\jppc\`
- Backup: `D:\PS2_FFX_BACKUP_20260731.zip` (23GB)
- Dados extraídos: `F:\ffx-reconstructed\ExtrasExtras\FFXINTERNATIONAL\PS2TESTE\`

## Dados-chave do ELF
- **File count:** 279 (ou 368+ entries na tabela real)
- **Alloc unit:** 0x20000 (128KB)
- **Partition start:** LBA 326000
- **Table location:** LBA 329066
- **Password:** `ffxpassf`
- **Entry format:** 4 bytes (offset em setores × 8 = LBA real)
