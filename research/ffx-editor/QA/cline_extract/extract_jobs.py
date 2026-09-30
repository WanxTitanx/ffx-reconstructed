#!/usr/bin/env python3
"""
cline_extract.py — Extrai as sessoes do Cline CLI (sessions.db + messages.json)
e gera jobs.jsonl para o batch do verboo_router.py (destilacao de conhecimento).

Por que existe (2026-08-14, Jarvis-ZCODE):
  O Cline CLI guarda 298 sessoes em ~/.cline/data/db/sessions.db, com o
  transcript em ~/.cline/data/sessions/<id>/<id>.messages.json. Para importar
  o conhecimento no ecossistema ZCode (regra do projeto: memoria compartilhada
  em arquivos versionados, nao em DB privado de uma ferramenta), cada sessao
  vira um job de resumo estruturado (JSON) processado pelo deepseek-v4-flash
  via verboo_router.py (tokens ilimitados).

Avisos de manutencao:
  - Leitura ESTRITAMENTE read-only (mode=ro) — nunca abrir sessions.db sem ro:
    o Cline CLI escreve WAL nele enquanto roda.
  - Cada job embute "sessao_id" no prompt e pede "sessao_id" na resposta:
    o batch retorna resultados fora de ordem (as_completed), entao o mapeamento
    e feito pelo id, nao pela posicao.
  - Transcripts truncados por sessao (~14K chars, mensagens iniciais + finais):
    suficiente para destilar conhecimento; o conteudo bruto continua no Cline.

Uso:
  python work/cline_extract/extract_jobs.py
  -> gera work/cline_extract/jobs.jsonl (1 job/linha) + meta.json
"""

import json
import os
import sqlite3

HERE = os.path.dirname(os.path.abspath(__file__))
DB = os.path.expanduser("~/.cline/data/db/sessions.db")
OUT_JOBS = os.path.join(HERE, "jobs.jsonl")
OUT_META = os.path.join(HERE, "meta.json")

MAX_SESSION_CHARS = 14000      # teto por sessao (evita job gigante)
CAP_USER_MSG = 1500            # teto por mensagem de usuario
CAP_ASST_MSG = 2500            # teto por mensagem de assistente
FIRST_N = 12                   # primeiras mensagens sempre incluidas
LAST_N = 10                    # ultimas mensagens sempre incluidas


def msg_to_text(msg):
    """Converte uma mensagem Cline (content = str ou lista de blocks) em texto plano."""
    c = msg.get("content")
    if isinstance(c, str):
        return c
    if isinstance(c, list):
        parts = []
        for b in c:
            if not isinstance(b, dict):
                continue
            t = b.get("type")
            if t == "text":
                parts.append(b.get("text", ""))
            elif t == "tool_use":
                # Nome da ferramenta ajuda a saber arquivos/acoes sem o payload
                parts.append(f"[tool_use:{b.get('name', '')}]")
            elif t == "tool_result":
                # Resultado bruto costuma ser enorme e de pouco sinal — so marcador
                parts.append("[tool_result]")
            # blocks de imagem/audio sao ignorados de proposito
        return "\n".join(p for p in parts if p)
    return ""


def build_transcript(messages):
    """Seleciona mensagens uteis (user/assistant text) com teto de tamanho."""
    picked = []
    total = 0
    n = len(messages)
    keep_idx = set(list(range(min(FIRST_N, n))) + list(range(max(0, n - LAST_N), n)))
    for i, m in enumerate(messages):
        role = m.get("role")
        if role not in ("user", "assistant"):
            continue
        txt = msg_to_text(m).strip()
        if not txt:
            continue
        cap = CAP_USER_MSG if role == "user" else CAP_ASST_MSG
        txt = txt[:cap]
        if i in keep_idx:
            add = True
        else:
            # Mensagens do meio so entram se couberem no orcamento
            add = total + len(txt) <= MAX_SESSION_CHARS
        if add:
            picked.append(f"--- {role} ---\n{txt}")
            total += len(txt)
            if total > MAX_SESSION_CHARS:
                break
    return "\n\n".join(picked)


PROMPT_TEMPLATE = """Resuma esta sessao de um agente Cline CLI (repositorio ffx-editor-main) em conhecimento DURAVEL para o ecossistema do projeto.

Saida EXATAMENTE JSON puro (sem markdown, sem texto antes/depois):
{{"sessao_id":"{sid}","titulo":"...","objetivo":"...","decisoes":["..."],"descobertas":["..."],"arquivos_tocados":["..."],"estado_final":"...","proximos_passos":["..."],"tags":["..."]}}

Regras:
- PT-BR. Maximo 6 itens por lista. Frases curtas e especificas.
- So conhecimento duravel: decisoes, descobertas tecnicas, regras, avisos, arquivos criados/alterados. Ignore conversa trivial, pedidos de infra e fofoca.
- Se a sessao nao produziu nada duravel, devolva listas vazias e estado_final="nada duravel".

--- DADOS DA SESSAO ---
sessao_id: {sid}
inicio: {started}
atualizada: {updated}
modelo: {model}
titulo: {title}
prompt inicial do usuario: {prompt}

--- TRANSCRICAO (resumida) ---
{transcript}
"""


def main():
    con = sqlite3.connect(f"file:{DB}?mode=ro", uri=True)
    con.row_factory = sqlite3.Row
    rows = con.execute(
        "SELECT * FROM sessions WHERE messages_path != '' AND is_subagent = 0 "
        "ORDER BY started_at DESC"
    ).fetchall()
    con.close()

    jobs = []
    skipped = 0
    for r in rows:
        sid = r["session_id"]
        mp = r["messages_path"]
        if not os.path.exists(mp):
            skipped += 1
            continue
        try:
            data = json.load(open(mp, encoding="utf-8"))
        except Exception:
            skipped += 1
            continue
        messages = data.get("messages", []) if isinstance(data, dict) else []
        if not messages:
            skipped += 1
            continue

        try:
            meta = json.loads(r["metadata_json"] or "{}")
        except Exception:
            meta = {}
        title = meta.get("title") or ""
        transcript = build_transcript(messages)
        prompt = PROMPT_TEMPLATE.format(
            sid=sid,
            started=r["started_at"] or "",
            updated=r["updated_at"] or "",
            model=r["model"] or "",
            title=title,
            prompt=(r["prompt"] or "")[:500],
            transcript=transcript,
        )
        jobs.append({"prompt": prompt, "meta": {
            "session_id": sid, "started_at": r["started_at"], "model": r["model"],
            "title": title, "cwd": r["cwd"], "team_name": r["team_name"],
        }})

    with open(OUT_JOBS, "w", encoding="utf-8") as fh:
        for j in jobs:
            fh.write(json.dumps(j, ensure_ascii=False) + "\n")
    with open(OUT_META, "w", encoding="utf-8") as fh:
        json.dump({"total_sessions": len(rows), "jobs": len(jobs), "skipped": skipped},
                  fh, ensure_ascii=False, indent=2)
    print(f"sessoes no DB: {len(rows)} | jobs gerados: {len(jobs)} | puladas: {skipped}")
    print(f"jobs: {OUT_JOBS}")


if __name__ == "__main__":
    main()
