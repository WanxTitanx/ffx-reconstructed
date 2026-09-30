#!/usr/bin/env python3
"""
consolidate.py — Consolida o resultado do batch de destilacao (out.json) das
sessoes do Cline CLI em um documento de conhecimento versionado.

Por que existe (2026-08-14, Jarvis-ZCODE):
  O batch do verboo_router.py devolve resultados em ordem de CONCLUSAO
  (as_completed), sem ecoar o prompt. Cada resposta embute "sessao_id" no
  JSON — o mapeamento volta por id, nao por posicao. Este script junta
  resposta + metadados da sessao (jobs.jsonl) + team_tasks (teams.db) e
  gera docs/ai/CLINE_KNOWLEDGE_EXTRACT.md + summaries.json (insumo da
  sintese executiva).

Avisos de manutencao:
  - Parsing tolerante: respostas podem vir com cerca de markdown ```json,
    texto extra ou campos faltando. Nunca falhar o lote por causa de uma
    resposta torta — registrar em "falhas" e seguir.
  - Leitura read-only de teams.db (mesma regra do extract_jobs.py).

Uso:
  python work/cline_extract/consolidate.py
"""

import json
import os
import re
import sqlite3
from datetime import datetime

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, "..", ".."))
OUT_JSON = os.path.join(HERE, "out.json")
JOBS = os.path.join(HERE, "jobs.jsonl")
SUMMARIES = os.path.join(HERE, "summaries.json")
DOC = os.path.join(REPO, "docs", "ai", "CLINE_KNOWLEDGE_EXTRACT.md")
TEAMS_DB = os.path.expanduser("~/.cline/data/db/teams.db")

FENCE_RE = re.compile(r"```(?:json)?\s*(.*?)```", re.S)


def repair_json(text):
    """Reparo de ultima instancia para JSON com aspas internas nao escapadas
    (falha classica de modelo: 'porta 13337, "v1.0.0" ativo' dentro de string).
    Escapa a aspa na posicao do erro e re-tenta, com teto de 30 reparos.
    O original continua intacto em out.json — aqui so se salva o que parsear."""
    for _ in range(30):
        try:
            obj = json.loads(text)
            return obj
        except json.JSONDecodeError as e:
            pos = e.pos - 1
            if pos <= 0 or pos >= len(text) or text[pos] != '"' or (pos > 0 and text[pos - 1] == "\\"):
                return None
            text = text[:pos] + '\\"' + text[pos + 1:]
    return None


def extract_json(text):
    """Tira cerca de markdown e acha o primeiro objeto JSON valido."""
    if not text:
        return None
    m = FENCE_RE.search(text)
    candidates = [m.group(1) if m else text]
    candidates.append(text)
    for cand in candidates:
        if not cand:
            continue
        try:
            obj = json.loads(cand)
            if isinstance(obj, dict):
                return obj
        except Exception:
            pass
        # Fallback: primeiro objeto JSON valido embutido em texto sujo
        # (raw_decode acha o fim exato do objeto, sem exigir que o resto seja JSON)
        dec = json.JSONDecoder()
        i = cand.find("{")
        while i != -1:
            try:
                obj, _ = dec.raw_decode(cand[i:])
                if isinstance(obj, dict):
                    return obj
            except Exception:
                pass
            i = cand.find("{", i + 1)
        # Ultima instancia: reparo de aspas internas nao escapadas
        if cand.startswith("{"):
            obj = repair_json(cand)
            if isinstance(obj, dict):
                return obj
    return None


def iso_date(s):
    return (s or "")[:10]


def main():
    results = json.load(open(OUT_JSON, encoding="utf-8"))
    ok_n = sum(1 for r in results if r.get("ok"))
    print(f"resultados: {len(results)} | ok: {ok_n} | falhas: {len(results) - ok_n}")

    # Metadados das sessoes (jobs.jsonl) — id -> meta
    meta_by_id = {}
    for line in open(JOBS, encoding="utf-8"):
        j = json.loads(line)
        meta_by_id[j["meta"]["session_id"]] = j["meta"]

    parsed = {}
    failures = []
    for r in results:
        if not r.get("ok"):
            failures.append({"erro": r.get("error", "")[:200]})
            continue
        obj = extract_json(r.get("output"))
        if not obj or not obj.get("sessao_id"):
            failures.append({"erro": "sem JSON/idsessao", "head": (r.get("output") or "")[:120]})
            continue
        sid = obj["sessao_id"]
        parsed[sid] = obj

    print(f"parsed: {len(parsed)} | irrecuperaveis: {len(failures)}")

    # team_tasks do teams.db (destiladas pelo proprio Cline)
    team_tasks = []
    try:
        con = sqlite3.connect(f"file:{TEAMS_DB}?mode=ro", uri=True)
        con.row_factory = sqlite3.Row
        team_tasks = [dict(x) for x in con.execute(
            "SELECT team_name, task_id, title, description, status, assignee, updated_at "
            "FROM team_tasks ORDER BY updated_at DESC").fetchall()]
        con.close()
    except Exception as e:
        print("teams.db indisponivel:", e)

    # Ordena sessoes por data desc
    items = sorted(
        parsed.items(),
        key=lambda kv: meta_by_id.get(kv[0], {}).get("started_at") or "",
        reverse=True,
    )

    lines = []
    lines.append("---")
    lines.append("date: 2026-08-14")
    lines.append("tags: [cline-import, knowledge-extract, zcode-migration]")
    lines.append("---")
    lines.append("")
    lines.append("# CLINE KNOWLEDGE EXTRACT (2026-08-14)")
    lines.append("")
    lines.append(
        f"Conhecimento destilado de **{len(items)} sessoes** do Cline CLI "
        "(`~/.cline/data/db/sessions.db`, resumo por sessao via `deepseek-v4-flash`, "
        "tokens Verboo ilimitados) + `team_tasks` do `teams.db`. "
        "Fonte bruta continua no Cline; este doc e a versao versionada compartilhada "
        "com ZCode/ZAI/Codex."
    )
    lines.append("")
    lines.append("Gerado por: `work/cline_extract/extract_jobs.py` + `consolidate.py` "
                 "(batch `verboo_router.py`). Regenerar: rodar os dois scripts.")
    lines.append("")
    lines.append("## Sessoes")
    lines.append("")

    for sid, o in items:
        meta = meta_by_id.get(sid, {})
        title = (o.get("titulo") or meta.get("title") or sid)
        lines.append(f"### {iso_date(meta.get('started_at'))} — {title}")
        lines.append("")
        lines.append(f"- **Sessao:** `{sid}` | modelo `{meta.get('model') or '?'}` | "
                     f"team `{meta.get('team_name') or '-'}` | cwd `{meta.get('cwd') or '-'}`")
        if o.get("objetivo"):
            lines.append(f"- **Objetivo:** {o['objetivo']}")
        if o.get("decisoes"):
            lines.append("- **Decisoes:**")
            for d in o["decisoes"]:
                lines.append(f"  - {d}")
        if o.get("descobertas"):
            lines.append("- **Descobertas:**")
            for d in o["descobertas"]:
                lines.append(f"  - {d}")
        if o.get("arquivos_tocados"):
            lines.append(f"- **Arquivos:** {', '.join(f'`{a}`' for a in o['arquivos_tocados'])}")
        if o.get("estado_final"):
            lines.append(f"- **Estado final:** {o['estado_final']}")
        if o.get("proximos_passos"):
            lines.append("- **Proximos passos:**")
            for p in o["proximos_passos"]:
                lines.append(f"  - {p}")
        if o.get("tags"):
            lines.append(f"- **Tags:** {', '.join(o['tags'])}")
        lines.append("")

    lines.append("## Team tasks (Cline teams)")
    lines.append("")
    if team_tasks:
        lines.append("| Team | Task | Titulo | Status | Assignee | Atualizado |")
        lines.append("|------|------|--------|--------|----------|------------|")
        for t in team_tasks:
            lines.append(
                f"| `{t['team_name']}` | {t['task_id']} | {t['title']} | {t['status']} | "
                f"`{t['assignee'] or '-'}` | {iso_date(t['updated_at'])} |"
            )
    else:
        lines.append("(indisponivel)")
    lines.append("")

    # Falhas de parse (transparencia)
    if failures:
        lines.append(f"## Falhas de parse ({len(failures)})")
        lines.append("")
        for f in failures[:20]:
            lines.append(f"- {f['erro']}")
        lines.append("")

    open(DOC, "w", encoding="utf-8").write("\n".join(lines))
    json.dump({
        "generated": datetime.utcnow().isoformat() + "Z",
        "parsed": {sid: {"meta": meta_by_id.get(sid, {}), "summary": o}
                   for sid, o in parsed.items()},
        "failures": failures,
    }, open(SUMMARIES, "w", encoding="utf-8"), ensure_ascii=False, indent=2)
    print(f"doc: {DOC}")
    print(f"summaries: {SUMMARIES}")


if __name__ == "__main__":
    main()
