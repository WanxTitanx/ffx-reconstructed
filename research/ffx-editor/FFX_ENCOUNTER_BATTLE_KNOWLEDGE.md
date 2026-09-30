---
date: 2026-06-29
tags:
  - ffx-battle-system
  - random-encounters
  - btl-bin-structure
  - atel-script
  - formation-lineup
  - spirareforge
aliases:
  - FFX Encounter Knowledge Base
  - Jarvis Battle Transfer Document
  - Spira Reforge Battle System
---
# FFX Encontros & Sistema de Batalha — Knowledge Base

> Documento de transferência de conhecimento entre agentes Jarvis.
> Compilado em 2026-06-25 a partir de toda a base de RE, código-fonte e
> experimentos práticos do projeto FFX Editor / Spira Reforge.

---

## Índice

1. [Estrutura do Battle .bin](#1-estrutura-do-battle-bin)
2. [Encontros Aleatórios (Random Encounters)](#2-encontros-aleatórios-random-encounters)
3. [Zonas de Encontro (mapout.vpa)](#3-zonas-de-encontro-mapoutvpa)
4. [Tabela de Encontros (btl.bin)](#4-tabela-de-encontros-btlbin)
5. [Tokens de Batalha (781D60, 7002)](#5-tokens-de-batalha-781d60-7002)
6. [Chunk0 — ATEL Script & Câmera](#6-chunk0--atel-script--câmera)
7. [Chunk2 — Formation (Lineup de Monstros)](#7-chunk2--formation-lineup-de-monstros)
8. [Chunk3 — Posicionamento (monLive, Arena Anchors)](#8-chunk3--posicionamento-monlive-arena-anchors)
9. [Grow Writer vs Position Writer](#9-grow-writer-vs-position-writer)
10. [Sistema de Carrier / Custom Mix (Arena+)](#10-sistema-de-carrier--custom-mix-arena)
11. [Sistema de Cenários (Scenario System)](#11-sistema-de-cenários-scenario-system)
12. [Grids de Spread (Posicionamento de Múltiplos Monstros)](#12-grids-de-spread-posicionamento-de-múltiplos-monstros)
13. [Câmera de Batalha (Onde REALMENTE Está)](#13-câmera-de-batalha-onde-realmente-está)
14. [Sistema de Música (MusicHook)](#14-sistema-de-música-musichook)
15. [Sistema de Progresso (ArenaProgressSidecar)](#15-sistema-de-progresso-arenaprogresssidecar)
16. [Field Scout / Field Explorer (Pipeline de Campo)](#16-field-scout--field-explorer-pipeline-de-campo)
17. [Runtime: AI, MemoryChr, MemoryBtl](#17-runtime-ai-memorychr-memorybtl)
18. [Tabela de Tokens dos Bosses](#18-tabela-de-tokens-dos-bosses)
19. [Autoria de Múltiplos Atores (Add/Remove Monster)](#19-autoria-de-múltiplos-atores-addremove-monster)
20. [Arquivos-Chave por Função](#20-arquivos-chave-por-função)
21. [Limitações Conhecidas / Itens em Aberto](#21-limitações-conhecidas--itens-em-aberto)

---

## 1. Estrutura do Battle .bin

Cada batalha em FFX é definida por um arquivo `.bin` em:
```
battle/btl/<id>/<id>.bin
```

### Cabeçalho (primeiros bytes)

```
+0x00: u32 rawChunkValue — chunk count = rawChunkValue - 1
+0x04: u32 chunkOffsets[] — offsets absolutos no arquivo
```

### Layout de Chunks

| Chunk | Label | Conteúdo | Editor |
|-------|-------|----------|--------|
| **0** | ATEL Script | Script AI da batalha. Chamadas de câmera VIVEM AQUI. | `AiScript_File` (863/863 RT0) |
| **1** | Worker Mapping | Mapeamento de workers ATEL para atores + shot table de câmera | Preservado (não editado) |
| **2** | Formation | Lineup de monstros: 8 x u16 slots (IDs de monstros) | `FormationSlotWriter` |
| **3** | Battle Areas | Arena anchors: posições party/monstros/aeons | `PositionWriter` / `GrowWriter` |
| 4+ | Texto | Nomes, descrições de scan (JP, EN, FTCX) | Raramente tocado |

Uma batalha é "unsafe format" quando `ChunkCount == 4` (sem chunks de texto).

### Mapa (field) -> BattleId

Cada entrada na tabela `btl.bin` tem um campo `map` de 6 chars no formato:
```
<area:4><NN:2>
```
Exemplo: `azit03` → a área `azit`, tile `03`.

O `BattleId` resultante é: `${map}_${formationId:00}`
Exemplo: `azit03_00`, `mcfr00_00`, `kino00_70`

---

## 2. Encontros Aleatórios (Random Encounters)

### Pipeline por Frame

```
1. FFX_Field_ResolveEncounterZoneIndices (0x875AC0)
   - Sampleia posição do jogador contra polígonos de zona
   - Atualiza g_FFX_SceneStateObject+0x10 (byte do grupo)

2. FFX_Field_UpdateWalkEncounter (0x871B60)
   - Lê o byte do grupo
   - Chama MsBattleEncountExe(0x780DE0) com:
     arg1 = fieldSelector (+0x04)
     arg2 = group (+0x10)
     arg3 = walkDelta

3. MsBattleEncountExe
   - Consulta btl.bin para a formação do grupo
   - Seleciona formação aleatória por peso (weight)
   - Aciona transição de batalha
```

### O Campo battlefield (bf)

O `battlefield` NÃO é o seletor de cena — é um **arena-ID global** que parametriza câmera/arena. A cena real é resolvida pelo campo `map` (6 chars).

### A Função de Resolução de Token

```c
unsigned __int8 *FFX_Field_ResolveEncounterToken(
    int token, int *outField, _DWORD *outGroup, _DWORD *outEntry)
```

1. Toma `HIWORD(token)` e chama `FFX_Field_LookupEncounterFieldRowByKey`
   - Scan linear sobre `g_EncounterFieldTable` (array de 14-byte rows)
2. Pega base da tabela de grupos de `g_EncounterGroupBlobBase + row.groupOffset`
3. Anda pelos grupos, cada um com:
   ```
   struct FFX_EncounterGroupRecord {
     u8 entryCount;
     u8 hdr[4];      // 4 bytes NÃO decodificados
     u16 entries[count];
   }
   ```
4. Compara `lowWord` (u16 zero-extended de `0x00YY`) contra `entry` u8 values
   - Match requer `lowByte == entry` e `highByte == 0`

**4 callers conhecidos:** `FFX_Field_RequestEncounterTransition (0x781D60)` + 3 outros.

### Formato do Token

```
token = 0xXXXX00YY
- HIWORD (bits 16..31) = field/map key
- bits 8..15 = DEVE ser 0 (senão no match)
- low byte 0xYY = entry key (dentro do grupo daquele field)
```

---

## 3. Zonas de Encontro (mapout.vpa)

### Estrutura

Arquivos `mapout.vpa` têm header PS2 `MAP1` (ou `VPA1`?). Contêm polígonos de trigger de encontro dentro de blocos de geometria `eC!`.

### Decodificação do Polígono

Cada polígono tem um **entryKey** codificado num **meta block** no slot de header `0x38`. A chave é extraída via:

```c
(polyMetaDword >> 17) & 0x7FFF
```

na função `FFX_FieldMap_DecodeEncounterGroupFromPolyMeta` (0x83E980).

### Formato dos Polígonos

- Micro-formatados como pares `s16 x/z`
- Escala: `1/float@+12`
- Sentinel `0x80 / -1` = separador
- File `ffxmap.id` carregado via `FFX_FieldMap_LoadEncounterGuideFromFfxmapId` (0x844D10)
  - Path: `/ffx/proj/map/master/%s/%s/bin`

### Runtime Chain

```
mapout.vpa -> polígonos eC! -> meta slot 0x38 -> entryKey
  -> FFX_Field_ResolveEncounterZoneIndices -> g_FFX_SceneStateObject+0x10
  -> FFX_Field_UpdateWalkEncounter -> MsBattleEncountExe
```

### Field Scout

O sistema Field Scout captura dados de zona durante walkthroughs:
- **407 amostras** de `ultra_zone_trace` / `ultra_encounter_sample` ligando posição a zoneA/B por field
- Polígonos renderizados como overlay semi-transparente verde no mapa no MapViewer
- Pipeline: walk JSONL -> `process-scout-session.ps1` -> `publish-scout-to-editor.ps1` -> Aurora Field Explorer

---

## 4. Tabela de Encontros (btl.bin)

### Estrutura Geral

O arquivo `btl.bin` (4096 bytes em `battle/kernel/btl.bin`) é a tabela global de encontros.

- chunk0: 0x10, chunk1: 0x550, end: 0x1000
- **96 tabelas x 0x0E** (header) + **192 grupos** (payload)

### Header Entry (14 bytes cada)

```
+0x00: u16  Id
+0x02: u16  DataOffset (offset no chunk1)
+0x04: u16  FormationOffset
+0x06: char Map[6] (6-byte UTF-8 map name)
+0x0C: u16  MapNamePadding (constante 0 em 192/192 registros)
```

### Data Block (Payload)

```
u8   TotalFormationCount
u8   GroupCount

for each group:
  u8   FormationCount
  u16  Battlefield
  u8   Danger
  u8   TotalWeight

  for each formation:
    u8   FormationId
    u8   Weight
```

### Writer Safety

- `Write()` — slot-only writer: clona bytes originais, re-stampa campos editáveis in-place. Sem mudança estrutural = byte-identical no-edit.
- `Rebuild()` — reconstrói estruturalmente: suporta formation count variável e tabelas novas. Preserva block sharing e trailing alignment.

### No Editor (Aurora Field Explorer)

Cada field mostra (através de `CursorFieldMap`):
- **"Grupos deste field"** — grupos de encontro do tile/NN específico
- **"Mesma area (outros NN)"** — grupos de tiles irmãos (mesmo prefixo) para referência

Cada grupo exibe: formation id, `w` (weight/peso), `bf` (battlefield id), `danger` level

---

## 5. Tokens de Batalha (781D60, 7002)

### sub_781D60 — Função de Transição

**Endereço PE RVA:** `0x381D60`, IDA flat: `0x781D60`

```c
int __cdecl sub_781D60(int token, char a2, char a3) {
  if (unk_112CA2C != 1 && !sub_7817C0()) {
    if (sub_7828B0(a1, &v6, v5, v4)) {
      MEMORY[0x112C256] = v6;    // field
      unk_112C258 = v5[0];       // group
      unk_112C259 = v4[0];       // entry
      unk_112A9D4 = a2;          // transition mode
      MEMORY[0x112A8E2] = 2;     // state = battle requested
      unk_112A9D5 = a3;
    }
  }
  return -1;
}
```

O wrapper ATEL em `0x7A3550` pops operandos da VM de campo e chama `sub_781D60(v4, 1, v3)`.

### Battle.7002 (ATEL opcode)

- `0x7002` = `launchBattle` (ATEL funcspace opcode).
- O Arena+ launch **substitui** a próxima chamada vanilla de Battle.7002 pelo token do boss.
- `g_FFX_SceneStateObject` (0x112CA90) contém o field state block.

### Tokens dos Carriers (Custom Mix)

| Carrier | Token | Field | Group | Formation |
|---------|-------|-------|-------|-----------|
| `mcyt00_22` | `0x01540016` | 42 | 0 | 22 |
| `nagi05_23` | `0x01AE0017` | 430 | 2 | 23 |
| `nagi05_22` | `0x01AE0016` | 430 | 2 | 22 |

### Token Custom Range Proposto

Range `0xA001..0xAFFF` (HIWORD), com low byte `0x46` e middle byte `0x00`.
Um hook custom no `FFX_Field_ResolveEncounterToken` traduziria tokens custom para tokens vanilla via JSON.

**Arquivo:** `mods/Spira Reforge/arena/spira-arena-custom-tokens.json`

---

## 6. Chunk0 — ATEL Script & Câmera

### Estrutura

```
+0x00: u32 codeLength
+0x10: u32 declaredLength (deve == chunk length)
+0x14: u16 workersTotal
+0x30: scriptStart
+0x36: u8 workerCount
```

### Opcodes de Câmera

| Func-ID | Nome | Args | Função |
|---------|------|------|--------|
| `0x703F` | `camReq` | SHOT (1-based), TARGET (actor id) | Solicita corte de câmera |
| `0x6004` | `camSetPolar` | horizontal, elevation, distance | Define câmera polar |
| `0x6020` | `refSetPos` | x, y, z | Define ponto de referência |
| `0x603A` | `camSetRoll` | roll | Roll da câmera |
| `0x603B` | `camSetScrDpt` | depth | Screen depth |
| `0x6040/0x6044/0x6045` | `camSetBtlPolar*` | variado | Variantes de batalha |

**Namespace de câmera = high nibble do func-id = `0x6`**

### camReq — Disparo de Câmera

`camReq` tem dois operandos, ambos valores imediatos `PUSHII` (0xAE):
- **SHOT** (1-based) — índice do ângulo na shot table
- **TARGET** — ator a enquadrar (`0xFFFF` = nenhum)

**3736/3736 chamadas são 100% editáveis byte-local** (editar 2 bytes no chunk0 preserva todos os outros chunks).

### Chain Runtime da Câmera

```
camReq (chunk0)
  -> FFX_Battle_Camera_RequestShot @ 0x797BD0
    -> FFX_Battle_Camera_CmdQueue_Push @ 0x797B80 (16-entry queue)
    -> FFX_Battle_Camera_BindQueuedShots @ 0x797D60
      -> FFX_Battle_Camera_ShotTable_Dispatch @ 0x7985A0
        -> FFX_Battle_Camera_ShotTable_Walk @ 0x797420
          -> scene/effect NODE id
```

### Float Pool

Argumentos float das funções de câmera vêm do **float pool** do script (operando `PUSHF`/0xAF = índice do pool). Cada entrada no pool é um float32 editável byte-local.

---

## 7. Chunk2 — Formation (Lineup de Monstros)

**Arquivo:** `FFXProjectEditor/FfxLib/Battle/Battle_File.cs` (class `Battle_Formation`)

### Layout

| Offset | Campo | Descrição |
|--------|-------|-----------|
| +0x00 | CommonVoiceLinesByte | Boolean (se usa voice lines comuns) |
| +0x01 | UnknownByte01 | Desconhecido |
| +0x02 | UnknownByte02 | Seletor de recurso de batalha |
| +0x03 | InWaterByte | Flag de batalha na água |
| +0x04..+0x0B | Padding | 8 bytes de padding |
| +0x0C..+0x1B | **8 x u16 monster slots** | IDs dos monstros |

### Formato dos Monster Slots (u16 raw)

```
raw & 0x0FFF = dictionary monster ID (ex: 0x114E = m334 = Dark Valefor)
raw & 0x1000 = "live on field" flag (bit 12)
0xFFFF       = empty slot
```

### Formação ao Vivo vs MonsterPositionCount

O número de slots de formation preenchidos (`raw != 0xFFFF`) NÃO é o mesmo que `MonsterPositionCount` (chunk3 +0x06). Eles diferem em 305/863 batalhas. O `MonsterPositionCount` = número de âncoras reservadas, não de monstros ao vivo.

**Slot `i` do formation (chunk2) mapeia para entrada `i` do monLive (chunk3 +0x20).**

### Coordenadas de Monstro (monLive 16-byte entry)

Cada entrada monLive tem 16 bytes: X(float), Y(float), Z(float), W(float=0).

**Sistema de coordenadas (da perspectiva da câmera de batalha):**
- **X:** lateral (esquerda/direita). Negativo = esquerda, Positivo = direita
- **Y:** altura (solo/voador). 0 = solo, >0 = voador
- **Z:** profundidade. **Negativo ≈ perto da câmera (na frente)**, **Positivo ≈ longe da câmera (atrás)**
- **W:** sempre 0

**Padrão de spread (3-na-frente / 2-atrás para 5 mobs):**

```
            CÂMERA DO JOGADOR
                    |
              Z negativo (-55)
          +----------+----------+
          |  Slot 2  |  Slot 3  |
          | (X=78)   | (X=102)  |
          +----------+----------+
               Slot 4 (X=90)
          +----------+----------+
          |  Slot 0  |  Slot 1  |
          | (X=-37)  | (X=-1)   |
          +----------+----------+
              Z positivo (+42)
                    |
            FUNDO DA TELA
```

**Regras empíricas (validadas em Random Encounters com BF=1031~1042):**
1. **3 perto da câmera, 2 ao fundo** para formação de 5
2. **X spread amplo** (30-50 unidades entre extremos) pra não amontoar
3. **Y=0** pra monstros de chão, **Y=5~15** pra voadores (flutuar acima do grupo)
4. **NUNCA** colocar todos na mesma Z — precisa de profundidade
5. **Slot 4** (âncora) geralmente no centro X entre os grupos de Z

### Exemplo Real: BF=1034 (Oldroad, Mi'ihen)

Câmera levemente inclinada — NÃO simétrica. O spread precisa seguir a diagonal.

**Padrão do usuário (válido):**
```
  Z positivo (atrás, esquerda)
  [-57, +15]  <- Slots 0,1 no canto esquerdo-fundo
  
  Z negativo (frente, direita)
  [78, -55]   <- Slots 2,3,4 no lado direito-frente
  [102, -55]
  [90, -52]
```

**Licoes:**
- Slots 0,1 vao pro lado **oposto** dos slots 2,3,4 (nao simetrico)
- Z define "profundidade" relativa a camera, nao valor absoluto
- Cada BF precisa ser analisado individualmente — nao existe spread universal

### Tabela de Padroes por BF (Mi'ihen — validado pelo usuario)

#### BF=1031 (Central — mihn07)
Camera frontal simetrica. 2 atras (Z+), 3 frente (Z-).

| Slot | X range | Z range | Funcao |
|------|---------|---------|--------|
| 0 | -46 a +44 | +3 a +51 | Atras, X variavel |
| 1 | -46 a -0 | +3 a +40 | Atras, X variavel |
| 2 | +78 a +90 | -90 a -55 | Frente, direita |
| 3 | +102 a +114 | -90 a -55 | Frente, extrema direita |
| 4 | +90 a +102 | -87 a -52 | Frente, ancora centro-direita |

**Variacao:** Slots 0,1 mudam de posicao. Slots 2-4 mantem padrao.

#### BF=1034 (Oldroad — mihn04 G1)
Camera inclinada diagonal. 2 atras-esquerda, 3 frente-direita.

| Slot | X range | Z range | Funcao |
|------|---------|---------|--------|
| 0 | -57 a -23 | +21 a +92 | Atras, esquerda |
| 1 | -57 a +24 | +15 a +53 | Atras, esquerda/direita |
| 2 | +78 | -55 | Frente, direita (fixo) |
| 3 | +102 | -55 | Frente, extrema direita (fixo) |
| 4 | +90 | -52 | Frente, ancora (fixo) |

**Variacao:** Slots 0,1 variam. Slots 2-4 fixos.

#### BF=1033 (Newroad North — mihn04 G0 / mihn05)
Camera frontal com profundidade. 2 atras (Z+), 3 frente (Z baixo).

| Slot | X range | Z range | Funcao |
|------|---------|---------|--------|
| 0 | -86 a +55 | +18 a +85 | Atras, X muito variavel |
| 1 | -86 a +82 | +10 a +96 | Atras, X muito variavel |
| 2 | -11 a +1 | -1 a +6 | Frente, centro-esquerda |
| 3 | +13 a +25 | -1 a +6 | Frente, centro-direita |
| 4 | +1 a +13 | +2 a +9 | Frente, ancora centro |

**Variacao:** Slots 0,1 tem liberdade TOTAL. Slots 2-4 semi-fixos.

### Principios Gerais (aprendidos do usuario)

1. **Slots 0,1 (atras):** Mais variaveis — cada formacao deve ter posicao unica
2. **Slots 2-4 (frente):** Mais consistentes no mesmo BF
3. **NUNCA** repetir coordenadas entre formacoes do mesmo BF
4. **Y=0** para monstros de chao, Y=5~15 para voadores
5. **Cada BF tem sua propria diagonal** — o spread segue o angulo da camera

### BF=1042 (Thunder Plains — Camera Lateral validada)

Camera de LADO. O campo e visto na horizontal.

```
[M0] [M1]               <- X=-121~-35, Z=+37~+70 (fundo-esquerda)
                      [M2] [M3] [M4]   <- X=+6~114, Z=-58~-52 (frente-direita)
         <- PARTY ->      (visto de lado)
```

| Slot | X range | Z range | Funcao |
|------|---------|---------|--------|
| 0 | -121 a +23 | +37 a +54 | Fundo-esquerda (atras do party) |
| 1 | -84 a +0 | +37 a +70 | Fundo-esquerda (bem variado) |
| 2 | +18 a +78 | -58 a -55 | Frente-direita (fixo) |
| 3 | +42 a +102 | -58 a -55 | Frente-direita (fixo) |
| 4 | +30 a +90 | -55 a -52 | Frente, ancora centro (fixo) |

**Regra:** Slots 0,1 vao SEMPRE para X negativo (lado esquerdo) e Z positivo (fundo). Slots 2-4 ficam no lado direito com Z negativo (frente). Assim cria-se a diagonal que acompanha a camera lateral.

---

## 8. Chunk3 — Posicionamento (monLive, Arena Anchors)

### Arena Record (96 bytes stride)

**Arquivo:** `FFXProjectEditor/FfxLib/BattleMap/BattleArenaAnchors_File.cs`

| Offset | Campo | Conteúdo |
|--------|-------|----------|
| +0x00 | fmtFlag | `0` = stride 96 (862/862 batalhas) |
| +0x01 | AreaCount | Número de records de área (144 casos multi-área) |
| +0x04 | PartyCount | = 3 normalmente |
| +0x05 | AeonCount | = 12 normalmente |
| **+0x06** | **MonsterPositionCount** | **Número de slots de posição de monstro** |
| +0x10 | PartyFront | Âncoras do party frontal (16B x count) |
| +0x14 | PartyBack | Âncoras do party traseiro |
| +0x18 | Aeon | Âncoras dos aeons (16B x 12) |
| +0x1C | MonsterStagingA | Âncoras de staging A (fora do campo, "off-field") |
| **+0x20** | **MonsterLive** | **Âncoras dos monstros NO CAMPO** — **alvo de edição** |
| +0x24 | MonsterStagingB | Âncoras de staging B (fora do campo / flee) |
| +0x28 | OriginAllActors | Origem de todos os atores |
| +0x2C | Camera | Record de câmera (4 floats CONSTANTES, NÃO é a câmera real) |

### Cada Âncora (Anchor)

**16 bytes = 4 x float32 (X, Y, Z, W):**
- `X` (float32): posição lateral
- `Y` (float32): altura (ground height)
- `Z` (float32): profundidade (battle frame, NÃO scene frame)
- `W` (float32): `0.0` para posições

### Categoria Mapa (IDA-Proven)

A função `FFX_Battle_AreaChunk_GetSetPosition` (0x7AC000) mapeia:
- cat 2 = area-extent floats (+0x30)
- cat 3 = party-front (+0x10)
- cat 4 = aeon (+0x18)
- **cat 5 = monster-live (+0x20)**
- cat 6 = party-back (+0x14)
- cat 7 = mon-stagingA (+0x1C)
- cat 8 = mon-stagingB (+0x24)
- cat 11 = "camera" (+0x2C) — lê 4-byte floats, NÃO vec4. **Valor CONSTANTE em 713/713 batalhas.**

### Ordem dos Arrays (fixa, provada em 863/863 batalhas)

```
origin < party < partyB < aeon < monA < monLive < monB < camera
```

### Battle-to-Scene Transform = Identity

**Provado em:** `docs/reverse/FFX_AURORA_BATTLE_TO_SCENE_TRANSFORM_IDA_PROVEN_2026-06-05.md`

Coordenadas que o Aurora Chamber pega no scene space são escritas **verbatim** (sem flip nem scale).

### Party-Facing Monster Placement

A função `MonsterZForParty` em `BattleComposeRunner.cs`:
```
se partyCentroidZ >= 0: monsterZ = partyCentroidZ - depth
senão: monsterZ = partyCentroidZ + depth
```

Exemplo: `mcyt00_22` tem party Z ~ +2 (precisa de Z negativo para monstros)
`mcyt00_21` tem party Z ~ -17 (precisa de Z positivo)

---

## 9. Grow Writer vs Position Writer

### PositionWriter (value-only)

**Arquivo:** `BattleArenaPositionWriter.cs`

- Edita SOMENTE X/Y/Z de âncoras existentes in-place
- Preserva W, count, pointers inalterados
- Gate: BattleArenaPositionLab 862/862 RT0
- Cria `.aurora.bak` antes da primeira escrita
- RT2: pendente (precisa verificação in-game)

### GrowWriter (structural)

**Arquivo:** `BattleArenaGrowWriter.cs`

- Adiciona ou remove slots de monLive estruturalmente
- Re-stampa `monB`, `camera section`, `chunk offsets`, `count +0x06`
- Gate: 700/700 RT0 para no-edit/add/remove
- RT2 parcial: atores extra carregam e rodam AI, mas crash possível por content mismatch (observado com Dark Aeons)
- **Hard actor cap: 8** (conservative, até IDA provar contrário)
  - O corpus `MonsterPositionCount` máximo é 15 (boss-rush `znkd09`)
  - Editor usa 8 como conservative

### Algoritmo de Grow Seguro (BattleArenaGrowWriter.cs)

1. Insere `(newCount - oldCount) x 16` bytes no fim do monLive (= início do monB)
2. Shift tudo após splice por `delta x 16`
3. Re-stampa pointers `monB (+0x24)` e `camera (+0x2C)`
4. Seta `MonsterPositionCount@+0x06 = newCount`
5. Escreve as monLive coords (W=0)

**Safety guards:** single-area (`AreaCount==1`); monLive tight; `newCount` entre 1 e `HardActorCap` (8).

### BattleArenaAuthor (Orquestrador)

**Arquivo:** `BattleArenaAuthor.cs`

High-level "add/remove a monster" que mantém chunk2 e chunk3 em lock-step:

- **Regime 1** (free reserved anchor): `next formation slot index < MonsterPositionCount` => fill next empty formation slot (chunk2-only, sem mudança chunk3)
- **Regime 2** (no reserved anchor): `next index == MonsterPositionCount` => grow chunk3 monLive then fill formation slot

---

## 10. Sistema de Carrier / Custom Mix (Arena+)

### O Conceito de Carrier

Um **carrier** é um battle bin vanilla pré-existente que serve como alvo de deploy para composições Custom Mix.

O carrier fornece:
- **O token F7** para lançamento
- **O cenário base** (qual btlmap backdrop renderizar)
- **Grid de spread default** para posicionamento de monstros
- **O slot na tabela de encontros** (field/group/formation) para o hook do menu F7

### Carriers Oficiais

| Actors | Carrier | Token | Source Template (chunk0) |
|--------|---------|-------|--------------------------|
| 3 | `mcyt00_22` | `0x01540016` | `mcyt00_21` (câmera behind-party provada) |
| 4 | `nagi05_23` | `0x01AE0017` | `nagi05_24` |
| 5 | `nagi05_22` | `0x01AE0016` | `nagi05_50` |

### Pick Catalog (IDs dos Dark Aeons)

| Pick | Slot ID | Monster | Notes |
|------|---------|---------|-------|
| `valefor` | 0x114E | m334 | Dark Valefor |
| `ifrit` | 0x114F | m335 | Dark Ifrit |
| `ixion` | 0x1150 | m336 | Dark Ixion |
| `shiva` | 0x1151 | m337 | Dark Shiva |
| `bahamut` | 0x1152 | m338 | Dark Bahamut |
| `yojimbo` | 0x1154 | m340 | Dark Yojimbo |
| `anima` | 0x1153 | m339 | Dark Anima |
| `magus` | 0x1155 | m341..343 | Dark Magus Sisters (expande 3 slots) |

### Compose Pipeline

```
1. Jogador picka Dark Aeons no menu F7
2. Hook C++ (ArenaPlusComposePick.cpp) salva pick em compose_last.json
3. Jogador aperta Build+Launch
4. Hook chama ArenaMultiBossLab.exe:
   --compose --pick valefor,ixion,yojimbo --scenario remiem
5. Lab:
   a. Mapeia picks para slot IDs (0x114E, 0x1150, 0x1154)
   b. Escolhe carrier por actor count (x3/x4/x5)
   c. Copia chunk0 (câmera) + chunk1 do source template
   d. Escreve chunk2 slots (monster IDs)
   e. Calcula monLive spread orientado do party centroid
   f. Aplica grow se necessário (mais atores que reservados)
   g. Deploy no <mod_btl>/<carrier>/<carrier>.bin
6. Token F7 mantido como o token base do carrier
```

### Cross-Map Carriers

Para cenários em MAPAS DIFERENTES do carrier nativo:
- Usam o próprio battle ID como output (não o carrier nagi/mcyt)
- Lançam via scenario FGF (field/group/formation), não token direto
- Exigem `ScenarioFieldBattleId` para deploy visual + `CameraChunk0TemplateId` para câmera

---

## 11. Sistema de Cenários (Scenario System)

### Definição (de BattleComposeRunner.cs)

```csharp
record ScenarioOption(
    string Key,           // chave técnica
    string Label,         // label visível
    string SourceTemplateId, // battle ID do template de chunk0
    int Field,            // índice na tabela de encontros
    int Group,            // grupo
    int Formation,        // formação
    int BattlefieldId,    // arena-ID (bf)
    string? CameraChunk0TemplateId = null  // graft de câmera opcional
);
```

### X3 Scenarios

| Key | Label | Scene | Field | G/F | bf |
|-----|-------|-------|-------|-----|----|
| `macalania_forest` | Macalania Forest | `mcfr00_00` | 36 | 0/0 | 1044 |
| `macalania_open` | Macalania Open | `mcyt00_00` | 42 | 0/0 | 1046 |
| `macalania_open2` | Macalania Open 2 | `mcyt00_21` | 42 | 0/21 | 1046 |
| `remiem` | Mushroom Rock Road | `kino00_00` | 24 | 0/0 | 1035 |

### X4 Scenarios

| Key | Label | Scene | Field | G/F | bf | CameraGraft |
|-----|-------|-------|-------|-----|----|-------------|
| `cavern` | Calm Lands Cavern | `nagi05_24` | 63 | 2/24 | 1080 | — |
| `bikanel` | Bikanel Desert | `bika02_01` | 47 | 0/1 | 1049 | `nagi05_24` |
| `remiem` | Mushroom Rock Road | `kino00_00` | 24 | 0/0 | 1035 | — |

### X5 Scenarios

| Key | Label | Scene | Field | G/F | bf |
|-----|-------|-------|-------|-----|----|
| `cavern` | Calm Lands Cavern (wide) | `nagi05_50` | 63 | 2/50 | 1080 |
| `cavern_alt` | Calm Lands (alt) | `nagi05_25` | 63 | 2/25 | 1080 |
| `remiem` | Mushroom Rock Road | `kino00_00` | 24 | 0/0 | 1035 |

---

## 12. Grids de Spread (Posicionamento de Múltiplos Monstros)

### X3 Grid (role-based, maior no centro-traseiro)

```
left wing  : (-48.0, 0.0, 68.0)
right wing : ( 48.0, 0.0, 68.0)
center back: (  0.0, 0.0, 96.0)
```

### X4 Grid (trapezoid, provado nagi05_24)

```
back left  : (-35.0, 0.0, 54.0)   — maior aeon
back right : ( 35.0, 0.0, 54.0)
front right: ( 28.0, 0.0, 30.0)
front left : (-28.0, 0.0, 30.0)
```

### X5 Grid

```
(-48.0, 0.0, 72.0), (48.0, 0.0, 72.0),
(-22.0, 0.0, 88.0), (22.0, 0.0, 88.0),
(0.0, 0.0, 104.0)
```

### Boss Nudges

| Boss | Nudge |
|------|-------|
| Anima | Z + 8 (empurrado pra trás) |
| Bahamut | Z + 8 |
| Valefor | Z + 4 |
| Magus Sisters | Z + 4 |

### Orientação de Grid

`OrientSpreadToCarrierParty` orienta o eixo Z baseado no sinal do Z do centroid do party:

```csharp
private static float MonsterZForParty(float partyCentroidZ, float depth) =>
    partyCentroidZ >= 0f ? partyCentroidZ - depth : partyCentroidZ + depth;
```

**Exemplos:**
- `mcyt00_22`: party Z ~ +2 → monstros em Z negativo (depth subtraída)
- `mcyt00_21`: party Z ~ -17 → monstros em Z positivo (depth somada)

---

## 13. Câmera de Batalha (Onde REALMENTE Está)

### Descoberta Crítica

**O registro de câmera em chunk3 +0x2C NÃO é a câmera real.**
É um DEFAULT CONSTANTE `(68.10, 6.68, 1.23, 6.68)` em 713/713 batalhas.

**A câmera REAL é script-COMPUTADA no chunk0 ATEL.**

### camSetPolar (0x6004)

Fórmula de projeção polar para cartesiana (IDA-proven):
```
eye.x = refX + cos(horizontal) * cos(elevation) * distance
eye.y = refY + sin(elevation) * distance
eye.z = refZ + sin(horizontal) * cos(elevation) * distance
```

- Ângulos em graus no script, convertidos para radianos pelo handler
- Fórmula inversa provada para drag-to-edit
- **802/855 establishing shots são editáveis**

### Editando a Câmera

A `BattleCameraSetup_File` (C#) lê e edita floats do pool do chunk0. Métodos:

```csharp
// Lê o establishing shot
BattleCameraSetup_File setup = BattleCameraSetup_File.ReadFromBattleBin(id, bin);
CameraEstablishingShot e = setup.Establishing;

// Edita polar horizontal/elevation
byte[] output = setup.WithFloat(e.PolarHorizontalIndex, newValue);
output = BattleCameraSetup_File.ReadFromBattleBin(id, output)
    .WithFloat(e.PolarElevationIndex, newElevation);
```

**Gate:** `CanEditPolarEye` = `HasPolar && PolarFuncId == CamSetPolarFuncId && indices >= 0`

### Template Swap

Quando se usa um **source template** de chunk0 (ex: `mcyt00_21` → `mcyt00_22`), troca-se o chunk0 inteiro mais o chunk1 (shot table) do donor. Isso é mais seguro que editar floats individuais porque o donor já tem câmera behind-party calibrada.

### Chunk1 = Camera Worker Mapping

Carregado por `FFX_Battle_ParseBattleBinChunks` (0x783ED0) em `g_CameraShotChannels[8]` (kind2/id1). Contém:
- `battleWorkerCount`
- `battleWorkerSlotCount` (0x8A)
- slot-to-workerIndex mapping
- worker records com `sectionOffset` apontando para tag tables (u16 tagCount + u16 tags[] = node references)

### Correção de Câmera (Mushroom Rock Road — Exemplo Prático)

Problema: `ApplyRemiemX4BehindPartyCamera` usava `e=+5.13` (do `nagi05_24`, Cavern), mas no `kino00_00` o vanilla tem `e=-11.33` — forçar +5.13 jogava câmera 16° pra cima.

| Parâmetro | Vanilla `kino00_00` | Fix antigo (quebrado) | Fix final (funciona) |
|-----------|--------------------|-----------------------|----------------------|
| h | 12.93° | -194.57° | **-104.57°** (gira ~90°) |
| e | -11.33° | +5.13° ❌ | **-25.0°** (aérea) |
| dist | 122.10 | mantido | mantido |

---

## 14. Sistema de Música (MusicHook)

### Como Funciona

**Arquivo:** `RuntimeTools/FfxHooksDll/hooks/MusicHook.cpp`

O MusicHook intercepta 3 funções de áudio do FFX:
- `FmodPlayTrack` — toca música por índice
- `FmodSwitchCrossfade` — troca com crossfade
- `MusicPrepBattleTrack` — prepara trilha de batalha
- `FmodPlayTrackWithPreload` — toca com pré-carregamento

### Fluxo Arena+

1. Antes de lançar batalha: `SetArenaBattleMusicPending(trackIndex, fadeFrames)`
2. Na entrada da batalha, os shims interceptam e trocam `trackIndex` pelo pending
3. O pending é **consumido** (`ConsumeArenaBattleMusicPending`) imediatamente após o swap
4. Timeout de segurança: 45s (se não consumido, expira automático)

### Fix do Bug de Fuga (2026-06-25)

O `g_arenaBattleMusicPending` NÃO era consumido depois de aplicar o swap. Quando o jogador fugia, o hook ainda via o pending ativo e trocava a música de campo de volta pra boss theme.

**Fix:** Adicionar `ConsumeArenaBattleMusicPending()` nos 3 shims que aplicam o swap (PlayTrack, SwitchCrossfade, PlayTrackWithPreload).

### Como Armar

- Flag: `arena_plus_music.flag` ou `FFXHOOKS_ARENAPLUS_MUSIC=1`
- Track config: `arena_plus_music_<row>.txt` ou `FFXHOOKS_ARENAPLUS_MUSIC_TRACK_<N>`
- Default track: `arena_plus_music_default.txt`

---

## 15. Sistema de Progresso (ArenaProgressSidecar)

### BattleEndHook (Lane 3 Scaffold)

**Arquivo:** `RuntimeTools/FfxHooksDll/hooks/BattleEndHook.cpp`

Hook de read-only no dispatcher de cleanup de batalha (`FFX_Battle_EndCleanupDispatcher @ RVA 0x0039E650`).

Gate: `arena_plus_victory_hook.flag` ou `FFXHOOKS_ENABLE_ARENA_PLUS_VICTORY_HOOK=1`

**State atual: scaffold apenas.** O hook dispara o callback `ArenaPlus_OnBattleEnd` mas:
- (a) AINDA NÃO distingue vitória vs derrota vs fuga (campo `result` sempre `kUnknown`)
- (b) AINDA NÃO mapeia effectHandle para progress flag

Quando ambos TODOs forem resolvidos, o callback chamará:
```csharp
ArenaProgress_RecordCleared(progressFlag)
```

### ArenaProgressSidecar (C#)

**Arquivo:** `FFXProjectEditor/FfxLib/ArenaProgressSidecar.cs`

Lê quadro de progresso de batalha do save slot ativo via probe (JSON sobre pipe):
- `active_slot` / `active_slot_name`
- `slot_<N>_capture_sum`
- `slot_<N>_gil`

Usa um overlay no módulo existente com polling periódico (`slotProbeIntervalMs`).

---

## 16. Field Scout / Field Explorer (Pipeline de Campo)

### Workflow

```
walk JSONL (ffx-hooks)
  -> process-scout-session.ps1 (ingestão)
    -> publish-scout-to-editor.ps1 (publicação)
      -> Aurora Field Explorer (visualização)
```

### O que o Scout Captura

Por sessão de walkthrough (50+ fields):
- **306 pontos de trace** do jogador
- **407 amostras de encounter zone** (zoneA/B por field)
- **239 CHR spawns** (personagens no campo)
- **54 field loads**

### CHR Classification

O scout inicial contava TODAS as entradas ativas da CHR table como "NPCs". O fix foi `ChrClassifier.cs` que categoriza por prefixo:

| Prefixo | Tipo |
|---------|------|
| `n###` | Story NPC |
| `c###` | Party (party echoes) |
| `m###` | Fiend/monstro |
| `f###` | Prop/objeto |
| `s###`/`w###`/`k###` | Outros |

### Current Status

- **Overlay v2 (P0):** entregue (EncounterOverlayCompiler.cs, ChrClassifier.cs, layer toggles)
- **Field Actor Scout (P3):** NÃO implementado. Hooks em `FFX_Field_GetActorByIndex` / `GetActorRecord` para capturar roster real.

### MapViewer

**Arquivo:** `RuntimeTools/FFXMapViewerWeb/app.js`

Visualizador 3D dos campos. Encounter zones renderizadas como:
- Semi-transparent green polygons no ground
- Overlay de CHR spawns (toggleable por layer)
- Dados publicados via WalkManifest/fields/*.json shards

---

## 17. Runtime: AI, MemoryChr, MemoryBtl

### MemoryChr (offsets por ator)

| Offset | Campo | Propósito |
|--------|-------|-----------|
| 0x416 | `Stat_move_target` | Hint de alvo/movimento |
| 0x438 | `Seck_target_id` | Strong hint de alvo |
| 0x5C4 | `Provoked_by_id` | Contexto de provocação |
| 0x5C5 | `Threatened_by_id` | Contexto de ameaça |
| 0x5CB | `Stat_prov_command_flag` | Lane de provocação |
| 0xDCA | `Stat_target_list` | Lista de alvos/candidatos |
| 0xDD6 | `Stat_action` | Strong hint de ação |
| 0xDDA | `Stat_effect_target_flag` | Lane de efeito/alvo |
| 0xF78 | `Ptr_script_chunks` | Pointer para dados de script |
| 0xF7C | `Ptr_script_data` | Pointer para dados de script |

### MemoryBtl

| Offset | Campo | Propósito |
|--------|-------|-----------|
| 0x2008 | `last_com` | Último comando visto |

### Runtime Enemy Rows

- Formation slots: `0..7` (static truth)
- Runtime enemy rows: `0..10` (runtime surface)
- Row stride: `0xF90` (stride dos atores inimigos)
- Raw monster ID join: `rawMonsterId & 0x0FFF`
- **Guardrail:** rows 8..10 são watchlist, NÃO provado como expansion de formation

---

## 18. Tabela de Tokens dos Bosses

### Vanilla Boss Tokens

| Boss | Token | BattleId | Field | G/F |
|------|-------|----------|-------|-----|
| Dark Valefor | `0x00480046` | `bsil07_70` | — | — |
| Dark Ifrit | `0x01610046` | `bika03_70` | — | — |
| Dark Ixion | `0x012F0046` | `kami03_70` | — | — |
| Dark Shiva | `0x01540046` | `mcyt00_70` | — | — |
| Dark Bahamut | `0x02090046` | `dome06_70` | — | — |
| Dark Yojimbo | `0x01AE0046` | `nagi05_70` | — | — |
| Dark Anima | `0x01E60046` | `mtgz01_70` | — | — |
| Dark Magus | `0x00DC0046` | `kino00_70` | — | — |
| Penance | `0x018B0046` | `hiku15_70` | — | — |

### F7 Menu Structure (v2.164.0.0+)

```
Hub
├── Dark Aeon Rematch   (9 solo rows, 8 DA + Penance)
├── Aeon Gauntlet        (Duo / Trio / Quartet / Penta / Specials)
└── Custom Mix
    ├── Custom Mix x3
    ├── Custom Mix x4
    └── Custom Mix x5
```

---

## 19. Autoria de Múltiplos Atores (Add/Remove Monster)

### BattleArenaAuthor (C#)

**Arquivo:** `FFXProjectEditor/FfxLib/BattleMap/BattleArenaAuthor.cs`

Orquestrador high-level que mantém chunk2 (lineup) e chunk3 (posições) em lock-step:

```
AddMonster(battleId, monsterSlotId):
  1. Se formation slot livre existe (raw == 0xFFFF):
     -> Preenche slot (chunk2-only)
  2. Se não há slot livre mas há âncora reservada:
     -> Preenche próximo slot vazio + próxima âncora monLive
  3. Se não há âncora reservada:
     -> Grow chunk3 (GrowWriter) + preenche slot + âncora

RemoveMonster(battleId, slotIndex):
  1. Seta formation slot para 0xFFFF
  2. Opcional: shrink chunk3 se último slot
```

### BattleArenaPositionLab (CLI de Teste)

**Arquivo:** `RuntimeTools/FieldPackFactory/`

Lab RT2 que valida edição byte-safety:
- Position-only: testa 862/862 batalhas
- Grow: testa 700/700 batalhas
- Gate PASS: diff mostra APENAS os bytes editados

---

## 20. Arquivos-Chave por Função

### Source Code (C#) — FFXProjectEditor

| Arquivo | Propósito |
|---------|-----------|
| `FfxLib/Battle/Battle_File.cs` | Container multi-chunk reader/writer |
| `FfxLib/Battle/EncounterTable_File.cs` | btl.bin encounter table |
| `FfxLib/Battle/FormationSlotWriter.cs` | Chunk2 slot-only writer |
| `FfxLib/BattleMap/BattleArenaAnchors_File.cs` | Chunk3 arena anchor decoder |
| `FfxLib/BattleMap/BattleArenaPositionWriter.cs` | Position value-only writer (X/Y/Z) |
| `FfxLib/BattleMap/BattleArenaGrowWriter.cs` | Structural grow/shrink |
| `FfxLib/BattleMap/BattleArenaAuthor.cs` | High-level add/remove monster |
| `FfxLib/BattleMap/BattleCameraSetup_File.cs` | Camera float-pool reader (chunk0) |
| `FfxLib/BattleMap/BattleCameraScript_File.cs` | camReq shot/target reader |
| `FfxLib/Ai/AiScript_File.cs` | ATEL script codec (chunk0) |

### Source Code (C++) — FfxHooksDll

| Arquivo | Propósito |
|---------|-----------|
| `dllmain.cpp` | Main hook layer, F7 launch |
| `hooks/ArenaPlusComposePick.cpp` | In-game Custom Mix F7 native menu |
| `hooks/MusicHook.cpp` | Battle music interception |
| `hooks/ResolverLogHook.cpp` | Encounter token logger |
| `hooks/BattleEndHook.cpp` | Post-battle hook |
| `hooks/ArenaProgressSidecar.cpp` | Save slot progress overlay |
| `hooks/FieldScoutHook.cpp` | Walk encounter data capture |

### Tools (CLI)

| Arquivo | Propósito |
|---------|-----------|
| `RuntimeTools/ArenaMultiBossLab/Program.cs` | Composer CLI |
| `RuntimeTools/ArenaMultiBossLab/BattleComposeRunner.cs` | Spread grids, scenarios |
| `RuntimeTools/ArenaMultiBossLab/BattleRecipeApplicator.cs` | Recipe → battle bin |

### Documentação RE

| Arquivo | Conteúdo |
|---------|----------|
| `docs/reverse/FFX_BATTLE_CAMERA_NOT_IN_CHUNK3_IDA_2026-06-07.md` | Câmera NÃO em chunk3 |
| `docs/reverse/FFX_BATTLE_CAMERA_SHOT_TABLE_IDA_2026-06-07.md` | Shot table decode |
| `docs/reverse/FFX_BATTLE_CAMERA_CAMREQ_CORPUS_PROVEN_2026-06-07.md` | camReq 100% editável |
| `docs/reverse/FFX_BATTLEFIELD_SCENE_BRIDGE_2026-06-05.md` | btl.bin structure |
| `docs/reverse/FFX_BATTLE_FORMATION_POSITION_CHUNK3_DECODED_2026-06-05.md` | Chunk3 monLive |
| `docs/reverse/FFX_AURORA_CHUNK3_GROW_SPAWN_IDA_2026-06-15.md` | Grow writer |
| `docs/reverse/FFX_AURORA_ENCOUNTER_DRAG_WRITE_SPEC_2026-06-15.md` | Position writer spec |
| `docs/reverse/FFX_ENCOUNTER_LAUNCH_FSM_INFERNO_2026-06-15.md` | FSM encounter launch |
| `docs/reverse/FFX_ENCOUNTER_FORMATION_ATLAS_2026-06-15.md` | Mapa de authoring |
| `docs/reverse/FFX_ARENA_PLUS_BOSS_TOKEN_TABLE_2026-06-15.md` | Tabela de tokens |
| `docs/reverse/FFX_ARENA_PLUS_CUSTOM_TOKEN_RESOLVER_HOOK_SPIKE.md` | Hook de token custom |
| `docs/reverse/FFX_ARENA_PLUS_COMPOSE_CAMERA_CHUNK0_TEMPLATE_2026-06-23.md` | Camera template |
| `docs/reverse/FFX_ARENA_PLUS_PRE_RT2_RESEARCH_2026-06-13.md` | Pre-RT2 dossier |
| `docs/reverse/FFX_AURORA_BATTLE_TO_SCENE_TRANSFORM_IDA_PROVEN_2026-06-05.md` | Transform identity |
| `docs/reverse/FFX_MAPOUT_VPA_ENCOUNTER_ZONES_2026-06-16.md` | mapout.vpa zones |
| `docs/reverse/FFX_MAPOUT_VPA_ENCOUNTER_ZONES_IDA_2026-06-16.md` | Runtime zone chain |

### Game Data (mods)

| Arquivo | Propósito |
|---------|-----------|
| `mods/Spira Reforge/arena/spira-arena-catalog.json` | Arena+ catalog |
| `mods/Spira Reforge/arena/spira-arena-custom-tokens.json` | Custom token map |
| `mods/Spira Reforge/data/mods/ffx_ps2/ffx/master/jppc/battle/kernel/btl.bin` | Encounter table (mod) |

---

## 21. Limitações Conhecidas / Itens em Aberto

1. **HardActorCap = 8** — Conservative até IDA provar contrário. Corpus max é 15 (boss-rush `znkd09`).

2. **Chunk3 camera record** — Constante default. Editar é byte-safe mas NÃO move câmera. A câmera real está no chunk0 ATEL.

3. **Custom token resolution** — Range `0xA001..0xAFFF` via hook em `0x7828B0` está DESENHADO mas NÃO implementado no main branch. `spira-arena-custom-tokens.json` pre-declarado.

4. **Encounter group header** — 4 bytes em `FFX_EncounterGroupRecord` + 10 bytes padding em `FFX_EncounterFieldRow` NÃO decodificados.

5. **Battle.7002 FSM** — Full FSM de encounter launch (random vs forced vs arena) listado como `partial / full FSM cases pending`.

6. **AI patcher** — Exact launch / safe patcher NÃO resolvidos. Projeto opera em hints observacionais, não pode provar causal ownership de AI choices.

7. **BattleEndHook** — scaffold-only. (a) resultado vitória/derrota/fuga não distinguido. (b) effectHandle → progress flag não mapeado.

8. **9th monster** — Comportamento desconhecido (crash/ignore/clamp não testado).

9. **Field Actor Scout (P3)** — Não implementado. Hooks em `FFX_Field_GetActorByIndex` para roster verdadeiro em vez de CHR pool sampling.

10. **MusicHook after flee** — Bug resolvido (pending não consumido causava música errada após fuga).

---

*Gerado por Jarvis em 2026-06-25. Para atualizações, ver `PORT_STATUS.md` e `SESSION_HANDOFF.md`.*
