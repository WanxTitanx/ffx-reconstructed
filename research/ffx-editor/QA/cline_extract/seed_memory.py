#!/usr/bin/env python3
"""
seed_memory.py — Semeia o Memory do zcode com os topicos candidatos da
sintese do CLINE_KNOWLEDGE_EXTRACT.

Por que existe (2026-08-14, Jarvis-ZCODE):
  O Memory do zcode (~/.zcode/cli/memories/projects/<base>-<hash16>/) foi
  habilitado nesta sessao (memoryEnabled=true). Este script cria a pasta do
  projeto e popula topics/ + MEMORY.md com os 10 topicos extraidos da
  sintese executiva (work/cline_extract/synthesis.md, secao "Top 10 topicos
  candidatos a memoria persistente").

Avisos de manutencao:
  - Nome da pasta: <basename do cwd, sanitizado> + '-' + sha256(cwd)[:16].
    A convencao exata do zcode (barra/contrabarra no cwd) NAO esta provada:
    se o zcode criar outra pasta numa proxima sessao, mover os topics para la.
  - O zcode pode reescrever topics na consolidacao de memoria — o conteudo
    canonico e docs/ai/CLINE_KNOWLEDGE_EXTRACT.md; este seed e conveniencia.
  - Formato do topic segue zcode-config-skill/references/memory.md.

Uso:
  python work/cline_extract/seed_memory.py [--dry-run]
"""

import hashlib
import json
import os
import re
import sys
import unicodedata
from datetime import datetime

HERE = os.path.dirname(os.path.abspath(__file__))
SYNTH = os.path.join(HERE, "synthesis.md")
MEM_PROJECTS = os.path.expanduser("~/.zcode/cli/memories/projects")
CWD = r"C:\Users\wande\Documents\ffx-editor-main"
BASE = "ffx-editor-main"
NOW = datetime.utcnow().strftime("%Y-%m-%dT%H:%M:%S.000Z")

TOPIC_RE = re.compile(r"^\d+\.\s+\*\*(.+?)\*\*\s+\((\w+)\)\s*—\s*(.+)$")


def slugify(title):
    s = unicodedata.normalize("NFKD", title)
    s = "".join(c for c in s if not unicodedata.combining(c))
    s = re.sub(r"[^a-z0-9]+", "-", s.lower()).strip("-")
    return s[:48] or "topico"


def parse_topics(text):
    topics = []
    in_section = False
    for line in text.splitlines():
        if line.startswith("## Top 10 topicos"):
            in_section = True
            continue
        if in_section:
            if line.startswith("## ") or line.startswith("---"):
                break
            m = TOPIC_RE.match(line.strip())
            if m:
                topics.append({"title": m.group(1).strip(),
                               "type": m.group(2).strip(),
                               "body": m.group(3).strip()})
    return topics


def main():
    dry = "--dry-run" in sys.argv
    text = open(SYNTH, encoding="utf-8").read()
    topics = parse_topics(text)
    if not topics:
        print("ERRO: nenhum topico parseado de", SYNTH)
        sys.exit(1)
    print(f"topicos parseados: {len(topics)}")

    h = hashlib.sha256(CWD.encode("utf-8")).hexdigest()[:16]
    proj_dir = os.path.join(MEM_PROJECTS, f"{BASE}-{h}")
    topics_dir = os.path.join(proj_dir, "topics")
    print(f"alvo: {proj_dir}  (hash16={h}, cwd usada para hash: {CWD})")

    if dry:
        for t in topics:
            print("  -", t["type"], "|", t["title"])
        return

    os.makedirs(topics_dir, exist_ok=True)
    index = []
    for t in topics:
        fname = f"{t['type']}-{slugify(t['title'])}.md"
        path = os.path.join(topics_dir, fname)
        body = (
            f"# {t['title']}\n\n"
            f"- Type: {t['type']}\n"
            f"- Updated: {NOW}\n\n"
            f"## Regra\n\n{t['body']}\n\n"
            f"Fonte: docs/ai/CLINE_KNOWLEDGE_EXTRACT_2026-08-14 (destilacao de "
            f"156 sessoes do Cline CLI, Jarvis-ZCODE).\n"
        )
        open(path, "w", encoding="utf-8").write(body)
        index.append(f"- [{t['title']}](topics/{fname}) — {t['body'][:100]}"
                     f" (type: {t['type']}, updated: {NOW})")
    open(os.path.join(proj_dir, "MEMORY.md"), "w", encoding="utf-8").write(
        "# Indice de memoria (seed Jarvis-ZCODE)\n\n" + "\n".join(index) + "\n")
    print(f"escritos: {len(topics)} topics + MEMORY.md em {proj_dir}")


if __name__ == "__main__":
    main()
