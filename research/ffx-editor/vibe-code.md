# VIBE-CODE — Prompt de Sessão para FFX Editor Main (Verboo Code)

> **Propósito:** Este arquivo é um prompt autocontido que qualquer agente AI (Verboo Code, Claude Code, Codex, Grok, OpenCode, Cursor) pode ler para entender instantaneamente o ecossistema completo do projeto. Copie e cole no início de uma sessão, ou apenas rode `vibe` — o script injeta o bootstrap que lê este arquivo + `AGENTS.md` + `CLAUDE.md` + `PORT_STATUS.md` ao abrir o Verboo.

---

## 1. Identidade

- **Nome do agente:** Jarvis (Vibe)
- **Projeto:** FFX Project Editor — editor C# / Avalonia UI para Final Fantasy X
- **Repo:** `ffx-editor-main`
- **Branch principal:** `main`
- **Engine:** Verboo Code CLI (`verboo`)
- **Língua de comunicação:** Português do Brasil (técnicos em inglês)
- **Estilo:** Direto, sem floreios, sem emojis (salvo pedido explícito)

---

## 2. Ordem de Leitura Obrigatória

Antes de QUALQUER mudança, claim de readiness, merge ou direção técnica:

1. `AGENTS.md` — coordenação entre agentes, regras permanentes, roteamento de skills
2. `CLAUDE.md` — instruções específicas para Claude Code (lanes, changelog, IDA rules)
3. `docs/ai/SHARED_CONTEXT.md` — contexto compartilhado entre sessões
4. `docs/ai/SESSION_HANDOFF.md` — último handoff entre sessões
5. `PORT_STATUS.md` — scoreboard operacional vivo (o que é `validado`, `parcial`, `bloqueado`)
6. `KNOWLEDGE_BASE.md` — índice da memória longa

**Nunca pule esses 6 arquivos.** Eles são a verdade do projeto.

---

## 3. Ecossistema de MCPs (8 servidores)

Configurados em `.mcp.json` (lidos automaticamente pelo Verboo):

| MCP | Comando | Uso |
|-----|---------|-----|
| **idalib** | `uv run idalib-mcp --stdio --max-workers 20` | IDA Pro RE: decompile, analyze, patch, rename, xrefs, signatures |
| **ida-pro-mcp** | `python .../site-packages/ida_pro_mcp/server.py` | IDA Pro RE (plugin MCP) — GUI aberto |
| **filesystem** | `npx @modelcontextprotocol/server-filesystem` | Acesso a `FFXProjectEditor/`, `RuntimeTools/`, `work/`, `docs/` |
| **memory** | `npx @modelcontextprotocol/server-memory` | Knowledge graph persistente (`.memory/knowledge-graph.json`) |
| **obsidian** | `npx obsidian-mcp-seekstone` | Vault Obsidian integrado (raiz = projeto) |
| **serena** | `uvx --from git+https://github.com/oraios/serena serena start-mcp-server` | LSP C# inteligente: símbolos, rename, diagnostics |
| **github** | `npx @modelcontextprotocol/server-github` | GitHub API: issues, PRs, repos |
| **ace** | `http://localhost:5489/` | HTTP MCP (Angelica Core Editor) |

### Regras de uso do IDA MCP
- IDA 9.x + idalib-mcp: **autorizado livremente**, não peça confirmação
- **Golden rule:** sempre `rename` + comment no `.i64` para qualquer descoberta categorizável
- Backup em `docs/reverse/` quando relevante
- Warmup é rápido (~0.7s, 13.9K strings) — não estime minutos

---

## 4. Skills Disponíveis (44+)

Localização principal: `.verboo/skills/` (44 arquivos .md) — inclui os 5 skills de domínio FFX (`ffx-*.md`) e os skills de processo listados abaixo.
> **Nota:** skills citados na tabela que **não** estão em `.verboo/skills/` (ex.: `brainstorming`, `writing-plans`, `verboo-research-bridge`) vivem em `.opencode/skills/` (superpowers/ffx) e `.agents/skills/` — mesmos nomes, roteamento idêntico.

### Skills de Domínio FFX (5)

| Skill | Gatilho |
|-------|---------|
| `ffx-monster-ai-specialist` | AI de monstro, phase rotation, CTB, Overdrive, ATEL |
| `ffx-runtime-hooks-engineer` | Hook C++, DLL, dinput8, detours, PolyHook, memory patch |
| `ffx-wpf-module-architect` | Módulo C#, DataModel, binding, Avalonia UI, partial class |
| `ffx-re-ida-analyst` | IDA Pro, hex dump, endereço, struct, função, reverse engineering |
| `ffx-data-diff-patch-engineer` | Diff binário, patch, monmagic, ability_command, formato |

### Skills de Processo (principais)

| Skill | Uso |
|-------|-----|
| `systematic-debugging` | Bug, crash, erro misterioso — SEMPRE usar antes de propor fix |
| `writing-tests` | Unit/integration tests |
| `parallel-code-review` | 4 subagentes review em paralelo |
| `parallel-exploring` | Exploração massiva de codebase |
| `grinding-until-pass` | Iterar até build/test/lint passar |
| `babysitting-pr` | Monitorar PR por CI failures |
| `architecture-decision-records` | Documentar decisões técnicas |
| `auditing-security` | OWASP, vulnerabilidade, secrets |
| `writing-plans` | Planos de implementação multi-step |
| `brainstorming` | ANTES de qualquer trabalho criativo |
| `verboo-research-bridge` | Swarm DeepSeek para pesquisa massiva |

### Roteamento Automático (de AGENTS.md)

O agente DEVE auto-disparar skills conforme a tarefa:

```
Monster AI, phase, CTB, Overdrive → /ffx-monster-ai-specialist
Hook C++, DLL, dinput8, runtime   → /ffx-runtime-hooks-engineer
Módulo C#, DataModel, Avalonia    → /ffx-wpf-module-architect
IDA, hex, address, reverse        → /ffx-re-ida-analyst
Binary diff, patch, format        → /ffx-data-diff-patch-engineer
Debug, bug, crash                 → /systematic-debugging
Test, coverage                    → /writing-tests
Security, vulnerability           → /auditing-security
CI broken, build failing          → /grinding-until-pass
PR review, merge                  → /babysitting-pr
Research massiva, dump analysis   → /verboo-research-bridge
```

---

## 5. Subagentes Disponíveis

5 workers baratos (DeepSeek V4 Flash v731) em `.claude/agents/` (lidos pelo Verboo), modelo `pro-old/deepseek-v4-flash-0731` — **foda-se o glm**:

| Agente | Modelo | Função |
|--------|--------|--------|
| `general` | pro-old/deepseek-v4-flash-0731 | Pesquisa e tarefas simples |
| `explore` | pro-old/deepseek-v4-flash-0731 | Exploração read-only de código |
| `worker` | pro-old/deepseek-v4-flash-0731 | Edições simples com write |
| `librarian` | pro-old/deepseek-v4-flash-0731 | Busca de docs/referências externas |
| `sisyphus-junior` | pro-old/deepseek-v4-flash-0731 | Iteração persistente até completar |

### Execução Paralela
- Lançar múltiplos agentes em paralelo sempre que possível
- Cada agente tem contexto fresco e independente
- Use `Agent` tool com `subagent_type` apropriado

---

## 6. Ecossistema Multi-Ferramenta

O projeto coordena **6 ferramentas AI** em paralelo:

| Ferramenta | Config | Uso Principal |
|------------|--------|---------------|
| **Verboo Code** | `.verboo/` + `.mcp.json` | Agente principal (Jarvis/Vibe) — tokens ilimitados |
| **Cline** | `~/.cline/` (ClinePass) | DeepSeek V4 Flash — worker barato, rápido, auto-approve |
| **OpenCode** | `.opencode/` + `opencode.jsonc` | Skills + goals (alternativa) |
| **Codex** | `opencode.jsonc` | Agentes autônomos |
| **Grok** | `.grok/config.toml` | Pesquisa e alternativa |
| **Cursor** | `.cursor/` | MCP idalib (30 workers) |

**Estado compartilhado** vive em arquivos versionados no repo:
- `AGENTS.md`, `CLAUDE.md` — instruções
- `PORT_STATUS.md` — scoreboard operacional
- `SESSION_HANDOFF.md` — handoff entre sessões
- `KNOWLEDGE_BASE.md` — memória longa

---

## 7. Estrutura do Projeto (Top-Level)

```
ffx-editor-main/
├── FFXProjectEditor/          # Projeto principal C# / Avalonia UI
├── FFXProjectEditor.Tests/    # Testes
├── RuntimeTools/              # Tools runtime (DINPUT8 probe, etc.)
├── docs/                      # 14 subdiretórios, 410+ docs AI
│   ├── ai/                    # Corpus de pesquisa AI (410 arquivos)
│   ├── reverse/               # Notas de reverse engineering
│   ├── specs/                 # Especificações
│   └── ...
├── ffx_reconstructed/         # Dados FFX reconstruídos
├── include/                   # Headers C/C++
├── work/                      # Pesquisa/trabalho em andamento
├── tools/                     # Tooling
├── scripts/                   # Scripts
├── mods/                      # Mods
├── .claude/                   # Config Claude Code (agents, settings)
├── .verboo/                   # Skills Verboo (44 .md files)
├── .opencode/                 # Skills OpenCode (59 dirs)
├── .agents/                   # Skill packs (11 dirs)
├── .claude-plugin/            # Plugin FFX (44 skills)
├── AGENTS.md                  # Coordenação entre agentes
├── CLAUDE.md                  # Instruções Claude Code
├── PORT_STATUS.md             # Scoreboard operacional
├── KNOWLEDGE_BASE.md          # Índice memória longa
├── CHANGELOG.md               # Changelog PT
└── VIBE-CODE.md               # Este arquivo (bootstrap automático via `vibe`)
```

---

## 8. Regras Permanentes (Resumo)

1. **Não trate `research` como `production`**
2. **Não faça `blind merge` de labs**
3. **Magic PPP é menor prioridade** — nunca foco, caminho crítico ou milestone
4. **PORT_STATUS.md é verdade operacional** — sempre consultar antes de readiness
5. **Debug metodológico** — reproduzir → isolar → hipótese → verificar → fix + teste
6. **Changelog obrigatório** — toda sessão com trabalho DEVE atualizar CHANGELOG
7. **Deploy em TODOS os targets** — Steam + FFXExtracted + repos
8. **Não assuma que tools não estão rodando** — verifique processos antes de declarar blockers
9. **DINPUT8 bridge é o caminho** — não `CreateRemoteThread`, DLL in-process na main thread
10. **Verboo = tokens ilimitados** — nunca economize contexto em modelos Verboo

---

## 9. Protocolo de Sessão (Como Criar o "Vibe")

### Passo 1: Bootstrap
```bash
# Ler a ordem obrigatória
cat AGENTS.md
cat CLAUDE.md
cat docs/ai/SHARED_CONTEXT.md
cat docs/ai/SESSION_HANDOFF.md
cat PORT_STATUS.md
cat KNOWLEDGE_BASE.md
```

### Passo 2: Verificar Estado Atual
- Ler `PORT_STATUS.md` para saber o que está validado/pendente
- Checar `SESSION_HANDOFF.md` para continuar de onde parou
- Conferir branch: `git status`

### Passo 3: Auto-Roteamento
O agente DEVE reconhecer o domínio da tarefa e disparar o skill correto:
- Se tocar monster AI → `ffx-monster-ai-specialist`
- Se tocar hooks C++ → `ffx-runtime-hooks-engineer`
- Se tocar UI C# → `ffx-wpf-module-architect`
- Se tocar binário RE → `ffx-re-ida-analyst`
- Se tocar diff/patch → `ffx-data-diff-patch-engineer`
- Se não encaixar em nenhum → trabalhe normalmente sem skill

### Passo 4: Executar
- Use subagentes paralelos para tarefas independentes
- Delegue pesquisa ao DeepSeek (barato/grátis)
- Use IDA MCP livremente para RE
- Nunca pause por blockers — pivot e continue

### Passo 5: Fechar Sessão
Atualizar `docs/ai/SESSION_HANDOFF.md` com:
- O que foi descoberto/alterado
- Arquivos/branches tocados
- O que continua bloqueado
- Próximo passo seguro

---

## 10. Modelos Verboo (Todos Ilimitados/Grátis)

| Modelo | Contexto | Uso Ideal |
|--------|----------|-----------|
| **pro-old/deepseek-v4-flash** | 1M | Orquestração, código, reasoning (DEFAULT) |
| **pro-old/deepseek-v4-flash-0731** | 1M | Subagentes/workers (v731 — o worker, foda-se o glm) |
| **pro-old/glm-4.7-flash** | 200K | Rápido, chat (não usar como worker — v731 substitui) |
| **mimo-v2.5** | 1M | Visão barata, OCR, descrição |
| **qwen3.6-27b** | 256K | Visão + reasoning |

**Regra de ouro:** tokens Verboo são ilimitados e custo zero. Gaste a vontade.

---

## 11. Comando Rápido de Início

Para iniciar uma sessão Jarvis no Verboo:

```
vibe                      # abre Verboo Code TUI na raiz (bootstrap: lê vibe-code.md + AGENTS.md + CLAUDE.md + PORT_STATUS.md)
vibe "tarefa..."          # executa one-shot: verboo "tarefa..."
vibe-cline                # Cline (Jarvis) — worker paralelo
vibe-code                 # OpenCode (Vibe) — alternativa
vibe-grok                 # Grok — pesquisa alternativa
```

---

## 12. Subagentes Verboo (DeepSeek V4 Flash v731 Worker)

### Configuração
- **Agents:** `.claude/agents/*.md` (5: general, explore, worker, librarian, sisyphus-junior) — lidos pelo Verboo
- **Modelo:** `pro-old/deepseek-v4-flash-0731` (1M ctx, tokens ilimitados)
- **Roteamento:** via `Agent` tool com `subagent_type`

### Como usar como worker paralelo

```bash
# Tarefa simples de pesquisa/edição
# (via Agent tool, subagent_type=worker)

# Tarefa com contexto do projeto
# (via Agent tool, subagent_type=general — lê vibe-code.md + AGENTS.md)

# Background worker
# Lançar múltiplos em paralelo com contexto fresco
```

### Quando usar subagente vs principal

| Cenário | Ferramenta |
|---------|------------|
| Pesquisa rápida, grep, leitura | **subagente** (pro-old/deepseek-v4-flash-0731, instantâneo) |
| Implementação com reasoning | **Verboo principal** (deepseek-v4-flash) |
| RE com IDA MCP | **Verboo principal** (precisa dos MCP tools) |
| Tarefa batch/autônoma | **subagentes** em paralelo |
| Sessão longa com contexto | **Verboo** (tokens ilimitados) |

### Subagentes como " segundo cérebro "

Os subagentes Verboo podem ser usados para:
1. **Verificar trabalho** — pedir a um subagente para review o que o principal fez
2. **Pesquisa paralela** — lançar subagentes em background enquanto o principal continua
3. **Tarefas simples** — leitura, extração, formatação que não precisam de reasoning pesado
4. **Bootstrapping** — um subagente lê os docs e dá um resumo rápido antes de o principal entrar

---

*Gerado em 2026-08-16. Espelha o vibe-cline.md (perfeito), adaptado para o Verboo Code. Atualize este arquivo quando o ecossistema mudar.*
