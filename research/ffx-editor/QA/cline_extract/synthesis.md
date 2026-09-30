## Top 20 licoes e regras permanentes

1. **Nunca `git add -A`** — working tree é multi-lane; commits sempre seletivos e coordenados com as lanes ativas.
2. **PORT_STATUS.md é a verdade operacional** — ler na ordem SHARED_CONTEXT → SESSION_HANDOFF → PORT_STATUS → KNOWLEDGE_BASE antes de claims, merges ou novas direções.
3. **Research ≠ production** — sem blind merge de labs; gates do PORT_STATUS decidem promoção.
4. **Bump de versão exige 4 campos** — csproj + CHANGELOG.md + changelogUS.md + VERSIONING.md, sempre com changelog duplo PT/EN.
5. **Nunca hookar no DllMain** — worker thread dorme FFXHOOKS_INSTALL_DELAY_MS antes do InstallHooks().
6. **CreateBlock MMF é deferido** — criação incondicional causa heap corruption 0xc0000374.
7. **CreateRemoteThread está aposentado** — hooks rodam na main thread via bridge DINPUT8 (GetDeviceState vtable[9] é race-free).
8. **Hooks novos OFF por padrão** — gate hierarchy: env FFXHOOKS_* > ffx-hooks.ini > modules\*.flag > config\*.flag.
9. **Sempre verificar calling convention** (thiscall/stdcall/fastcall) antes de criar/modificar hooks — ComposeWorldMatrix teve bug de retn4 double-pop.
10. **Validar com RT2 in-game após deploy de hooks**; F7/F8 não alteram core antes disso.
11. **Padrão C++↔C# são blocos MMF** — Local\FFXProbeBlock_v1 (580B) e Local\FFXHooksBlock_v1 (256B); WireInstanceToSceneNodes NÃO é o padrão.
12. **Regra de ouro Magic PPP** — pppColor é a menor prioridade; nunca é caminho crítico nem base para declarar C2 útil.
13. **Não commitar working tree de lanes paralelas sem instrução** — corrida de lanes é o maior risco de conflito do repo.
14. **i18n: EN é a fonte de verdade**; usar Python UTF-8 como fonte canônica de geração; PowerShell 5.1 lê UTF-8 sem BOM como ANSI (scripts precisam BOM).
15. **PowerShell pitfall** — usar [math]::Floor, não [int], para truncar doubles (2.7576 → 3 com [int]).
16. **Fallback de visão** — Ollama local → gpt-5.6-luna → Verboo; nunca llama3.2-vision no Windows (mllama não suportada no Ollama 0.32.9).
17. **Sem segredos no repo público** — chaves fora do diretório do projeto; .env gitignored.
18. **DebugLog, nunca Console.WriteLine**; auditoria e claims exigem prova documental (build + testes).
19. **Pular MonsterAiEditor2** — descontinuado (regra dura); SPIRA FORGE permanece pausado.
20. **Contratos MMF devem ter fonte única** (contracts/) para evitar drift C++/C#.

## Descobertas tecnicas mais valiosas

### MagicDll/PPP
- **pppAccele/pppAngAccele são double-layer**: layerB += delta no match; layerA += layerB sempre; estado em +0xA0..+0xAC (=+160..+172).
- **Byte-identity provada**: pppMove==pppAccele, pppAngMove==pppAngAccele, pppPoint==pppScale (mesmo código, opcodes diferentes).
- pppColMove usa delta u16[4] em a2+8..+15 (janela editável 8B); pppPoint/pppAngle/pppScale são single-layer (só node[0]).
- **Entry U1**: handler em +0x08, auxiliar idêntico em +0x1C/+0x20 (padrão SetFromGlobals).
- Dispatch table PPP: 4 cópias em .data (primária **0xC3A500**), 274 opcodes, entries de 40B com 3 slots de handler; opcodes 0xC3A820/0xC3A848 a reconciliar.
- Cadeia PPP mapeada no FFX.exe: 0x711540/0x711910/0x7186F0/0x712080; **0x737830 = FFX_MagicHost_BuildVfxTexture_TypeK (= pppDrawMdl)**.
- Inventory: 589 DLLs, 56 famílias, 275.104 slots; Magic DLL 583/587 decompiladas (99,3%); EBP 815/815 handlers nomeados.
- Não existe opcode pppWait — string pppSendWait é debug de FFX_FieldMap_WalkStruct_BattleTrigger.
- NovaSuperDamageHook bypassa cap 99.999 da Nova (LAB RT2 PASS v2.110.1.1); patch RVA **0x78EDD5** (jle +2), bytes esperados 7E 02 8B C3 89, anchor mov ebx, 99999.

### Monster
- Monster_File: header 0x34, assinatura int em 0x00 (vanilla=8), ponteiros 0x04..0x1C, FileSize 0x20, padding 0x24; seções começam em 0x30; **os 4 bytes de padding sobrepõem AiFile[0..3]** — preservar Signature/Padding.
- Read() percorre ponteiros de trás para frente (Text ← ... ← Ai); Write() reemite header e grava seções contíguas.
- StatSheet.WriteSingle() é preserve-only: mantém OriginalSectionBytes + 5 TextScriptInfo (+0x00..+0x13) e reescreve bloco fixo de 104 bytes em +0x14 (HP/MP, stats, flags, resistências, abilities, IDs).
- Battle_File: header u32 chunkCount+1 + tabela offsets; formation com 8 slots u16 (0xFFFF=vazio) no chunk 2; EncounterTable_File: header 2 chunks, entradas de 0x0E bytes.
- _MON_unknown é Monster File real (sig 08, header 0x30, 7 chunks, HP 50.000); parser validado 2/2.
- MonsterFileAdapter: keys namespaced Stat.*/Loot.*/Metadata.*, SHA-256 hex lowercase, Risk Moderate, cap HP/MP 99999; 126/126 testes com fixtures m000.bin/m001.bin.

### TreasureMap (Treasure/takara.bin)
- takara.bin: header 0x14 bytes, **498 entradas** (min=0, max=0x01F1) × 4 bytes = 0x07C8; Treasure_Entry = Kind (byte) + Quantity (byte) + Type (u16 LE).
- WriteAll aceita exatamente 498 entradas (shape preservado); ReadAll→WriteAll é byte-idêntico (round-trip provado).
- WriteTable preserva bytes originais e sobrescreve entries em 0x14 + i*4.

### ModelViewer (Aurora/noclip)
- noclip: LEVEL_MODEL_SCALE=10, MapTri{passability,encounter} por triângulo, groundTri para altura, EncounterData.battlePositions[].party.
- fahrenheit confirma Actor 0x880 com chr_scale_vec @0x5C e chr_optpos_vec_1 @0x534 (altura do modelo — valida hipótese do Y residual no Aurora).
- Escala real por âncora usando scaleOwnSize 0x7028 do ATEL; MonsterAthAnimCatalog reimplementa tabelas .ath.
- Battle_File do Spira Modifier: chunk0 ATEL + chunk2 Formation 8 slots + chunk3 Areas com posições 16B.
- Magic Studio no noclip: 372 magias/55 cenários/246 monstros; magicTable é MagicDescriptor[][] (5 categorias FFXMagicSceneDesc 0-4); setMagic(desc) carrega 11/<id>.bin.
- GLB export por data-URI base64; bug de validação: header GLB 'total' precisa incluir os 8 bytes de cabeçalho de cada chunk.

### Hooks
- FfxHooksDll usa PolyHook2 (x86Detour) + MinHook; cadeia: DINPUT8.dll (main thread) → ffx-probe.dll → ffx-hooks.dll.
- 4 técnicas: PolyHook2 x86Detour (dominante), MinHook (leitura), inline patch com validação de assinatura, vtable hook no probe dinput8.
- UnX legado (dxgi.dll) crasha boot com ffx-probe.dll — conflito GetDeviceState vtable[9] (INC-002); fora do deploy.
- F7 offsets: enemy list base+0xD37634 (fallback 0xD34460); entry = list + 0xF90×slot; slot ocupado se (u16*)(entry+0x0E)!=0xFFFF; +0x606 Status_suffer (bit 0..24), +0x641 Status_resist (imunidade, não suffer).
- Speed hack: FFX_GameTick + __UNX_speed_mod em base+0x420C00; F8 = dashboard GDI 6 tabs; dxgi.dll é Special K 0.8.36, unx.dll carrega via SKPlugIn_Init.
- ffx_addresses.h é o ledger canônico de RVAs; runtime usa GetModuleHandle+RVA, nunca IDA flat.

### Infra/Verboo
- Router Verboo expõe 4 modelos reais: deepseek-v4-flash (reasoning: exige max_tokens generoso e retorna reasoning_content), glm-4.7-flash e 2 com visão; concorrência até 6 requests.
- Cline: hub daemon porta 25463; **`cline auth` derruba o hub e desconecta chats**; `cline --id <session>` resume sessões; MCP settings só carregam no boot do daemon (CLI 3.0.48/4.0.11).
- Config real do Cline: ~/.cline/data/settings/cline_mcp_settings.json; ClinePass gateway https://api.cline.bot/api/v1 (chave em providers.json); ZCode/ZAI em ~/.zcode/config.json.
- DeepSeek peak/off-peak billing (desde 16/08/2026 16:00 UTC): peak = 01:00-04:00 e 06:00-10:00 UTC; off-peak = metade do preço; relógios via HKCU AdditionalClocks.
- hub-daemon.log crescia 136 KB/s (~12 GB/dia) — causa provável do Kernel-Power 41; rotação >2GB agendada.
- Crash recovery: teams.db (1GB, 1.867.175 eventos) preserva payload_json completo; messages.json foi zerado; compaction.json preservou estado.
- exports Ghidra do FFX.exe (base 0x400000): functions.ffx.csv (6.3MB, 56.558 funções/11.504 nomeadas) e globals.ffx.csv (60KB, 762 globals); db COPY (45.616 funções nomeadas) é a melhor db do projeto.
- ffx-reconstructed: 47.432 funções nomeadas, 7.706 globais, 13.962 strings; IDA MCP na porta 13337 (ida-pro-mcp autostart, 60 tools).

### Outros (Sphere Grid / RE)
- Struct LpAbilityMapEngine: Size=0x12FC0; nodes[1024]@0x808, links[1024]@0xA808, clusters[128]@0x8; limites 1024/1024/128 são arrays fixos; ponteiro global RVA 0x1F05834 = dword_2305834.
- Render buffers 0x681DB0 são fixos para 861 nodes (861×48); 12 funções ABMAP usam 1024 como limite; endereços 0xA581F0/0xA57710 do ZanarkandWorkshop = nossas FFX_Abmap_BuildLinkBatchEnd/BuildLinkBatchSegment.
- NodeType do jogo tem LOCK_1..4; 'L.3' = LOCK_3 (referência para True New Node).
- ZanarkandWorkshop limita grids game-compatible a 860 nós/1021 links Standard/Original/934 Expert/5 links por nó — constantes a validar por RE.
- PcFfx round-trip: header 0x40 + payload 25848B + footer 1032B = 26944B; DetectFormat aceita 26944 e 26880 (bug corrigido).
- i18n: elo code→glyph provado: FFX_EventText_AdvanceCharGlyph 0x8B92E0 e FFX_Font_GetSlotGlyphMeta 0x8AC380 destravam JA/KO/ZH (font-bank pendente de RT2).

## Frentes abertas e bloqueios pendentes

- **Commit coordenado do bundle MagicDll** (v2.228/v2.229/v2.230/v2.231 + scan i18n PT) — dono: lanes Shiva/w6k3n + kbh7i; pendente há ~2 semanas (desde 08-01/08-02); parece estagnado.
- **Criação do repo público de hooks** (runtime + SIN) — dono: lane hooks; decidido em 08-14, nunca iniciado; recente.
- **RT2 in-game F7/F8** — dono: humano (próximo passo é humano); pendente desde 08-01; parece abandonado há ~2 semanas.
- **Maturar hook F7 Monster AI Swap / F8 dashboard** — aguarda RT2; sem progresso desde 08-13.
- **True New Node do Sphere Grid** — bloqueado por allocator dword_2305834; research-only; since 07-31; parece abandonado há 2 semanas.
- **C2/C3 PPP Assembler** — pausado aguardando reconciliação da dispatch table (0xC3A500/0xC3A820/0xC3A848); desde 07-31; parece abandonado há 2 semanas.
- **Probe T1/T2 do Magic PPP** (janela 16B disco→runtime, 145 aliases) — pppSclMove T3 copy-only READY; T1/T2 sem backup binário do baseline 16-07; pendente.
- **Lançamento dos 3 repos** — releases vazios (launcher 0 releases), CTA do site quebrado (v0.8.0 sem downloadUrl), conteúdo FMX dummy 518B, editor com 19 commits não pushados; dono: lane SENTINELA; desde 08-12.
- **Migration i18n: 2.414 literais hardcoded** + lacunas IT (Niente) — desde 08-02; parece abandonado ~2 semanas.
- **Font-bank JA/KO/ZH** — bloqueado por probe RT2 (SlotGlyphMeta); desde 08-02.
- **Remoção do Git LFS** — incompleta (sessão interrompida); desde 08-03; parece abandonada.
- **git gc** (30,68 GiB loose) — adiado, requer confirmação explícita; desde 08-03.
- **Phase Manager V2 smoke manual + RT2** — builds verdes, RT0 PASS; "Precisa Testar" desde 07-31; parece abandonado.
- **Validar MonsterFileAdapter em fluxo real + RT2** — status Validado RT pendente; desde 07-31.
- **Onda Gemini UI/UX** — documento reescrito + spec, zero entregas de UI; desde 07-31.
- **Primera release do launcher** (asset win-x64.zip) — auto-updater pronto, release não publicada; desde 08-01.
- **Backup em camadas** (EXA Cloud bulk antes do fim da promoção, mover "só pra guardar" para G:) — dono: usuário/Shiva; desde 08-14.
- **Shape check do gate --phase-rotation-rt0** (0/319) — débito registrado; desde 07-31/08-01; sem solução visível.
- **TODO: espelhar o drift de parser elementskill.dll** e o V187 skills_origins — repo ace-mcp; contínuo.

## Conflitos ou contradicoes entre sessoes

- **C2/C3 PPP**: sessão 1785564779578 aponta divergência — PORT_STATUS marca C2/C3 "bloqueadas" enquanto handoffs de 07-31 dizem dispatch table "reconciliada (418+246+32)" e "validada"; outra sessão fala em 274 opcodes e entries 0x28B. Estado real não reconciliado.
- **Versões em conflito entre csproj e docs**: v2.199.1.3 vs v2.199.0.2 (PORT_STATUS); v2.197.0.0 vs v2.192.0.2 (resumo das regras); v2.214.2.0 (csproj working tree) vs v2.215.0.0 (HEAD git); v2.224.0.5 vs v2.224.1.30. A cadeia de versão quebrou mais de uma vez por corrida de lanes.
- **Mojibake do DataModel.cs do Sphere Grid**: sessão 749v7 (08-01) diz que há mojibake real (linhas 687/693/694); sessão 55xzh (mesma data) diz que era artefato de exibição — bytes UTF-8 válidos, exceto '→' e 'Á'. Julgamentos opostos.
- **LBA da extração PS2**: script antigo lia 279 entries; descoberto depois que a ISO tem 367 entries válidas — o "conhecimento" oficial de 279 era erro de loop, corrigido em 08-01.
- **Regra de commit coordenado vs prática**: sessões kbh7i/n3uzj/w6k3n insistem "não commitar nada sem coordenação", mas commits isolados foram feitos (612a4bb2 pushado, f7f0de9e criado, bump v2.192.0.4 por outra lane) e depois cobrados como débito.
- **Contagem de 8 gates quebrados**: sessão 6qflr classifica como "não regressão (Phase Manager)"; a auditoria Goal 4 mostra que o único FAIL do offline_ci é drift de corpus — a interpretação de quão quebrado está o Phase Manager varia entre sessões.
- **MCP do Cline**: sessão 1785526462890 afirma que o Cline carrega MCPs via .clinerules/ e settings; sessão 1785529277061 descobre que o daemon não faz hot-reload e os MCPs só carregam no boot — visões diferentes da mesma infraestrutura.
- **"196 GB liberados" vs "F: 100% cheio"**: a limpeza de 08-03 liberou C:, mas a extração PS2 de 08-01 encheu F: — conflito de capacidade entre discos não documentado em um único lugar.

## Top 10 topicos candidatos a memoria persistente (zcode Memory)

1. **Commit coordenado multi-lane** (rule) — Nunca `git add -A`; working tree é sempre misto entre lanes; commits seletivos e coordenados, senão há conflito de versão/csproj e débito de changelog.
2. **PORT_STATUS como gate de produção** (rule) — Ler PORT_STATUS na ordem SHARED_CONTEXT→SESSION_HANDOFF→PORT_STATUS→KNOWLEDGE_BASE; research ≠ production; sem blind merge de labs; claims exigem prova documental.
3. **Padrão MMF de hooks C++↔C#** (decision) — Comunicação via blocos MMF Local\FFXProbeBlock_v1 (580B) e FFXHooksBlock_v1 (256B); WireInstanceToSceneNodes não é padrão; contratos com fonte única em contracts/.
4. **Regras de segurança de hooks runtime** (rule) — Nunca hookar no DllMain (delay thread); CreateBlock MMF deferido (heap corruption 0xc0000374); CreateRemoteThread aposentado (crash); usar bridge DINPUT8 main thread; verificar calling convention; hooks OFF por padrão; validar RT2 após deploy.
5. **Bump de versão 4 campos + changelog duplo** (workflow) — Toda adição shippable exige csproj + CHANGELOG.md + changelogUS.md + VERSIONING.md; caixa de versão é ponto frequente de conflito entre lanes.
6. **Regra de ouro Magic PPP** (rule) — pppColor é a menor prioridade, nunca foco/milestone; fila principal prova escala, movimento, aceleração, ângulo, matriz, draw e KeTh; pppAccele/pppMove são double-layer com janela +0xA0..+0xAC.
7. **Gate RT2 in-game para hooks/i18n** (workflow) — F7/F8, font-bank JA/KO/ZH e True New Node estão bloqueados por RT2 in-game (passo humano); não alterar core dessas frentes antes do teste; usar "Safe Transplant Mode" no Sphere Grid.
8. **DeepSeek peak/off-peak billing** (decision) — Desde 16/08/2026 16:00 UTC: peak 01:00-04:00 e 06:00-10:00 UTC, off-peak custa metade; regra de preço é base para relógios/alertas e scripts de custo.
9. **Fallback de visão e modelos Ollama** (decision) — Nunca llama3.2-vision no Windows (mllama não suportada); fallback Ollama local → gpt-5.6-luna → Verboo; qwen3-vl:8b 12/12 e gemma4:26b 11/12 validados.
10. **Recovery pós-crash das lanes Cline** (workflow) — `cline auth` derruba o hub (porta 25463); mensagens sobrevivem em ~/.cline/data/sessions/ e teams.db; `cline --id <session>` resume; hub-daemon.log rotacionar >2GB; MCP settings só recarregam no boot do daemon.