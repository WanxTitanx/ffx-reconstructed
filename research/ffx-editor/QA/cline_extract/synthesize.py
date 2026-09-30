#!/usr/bin/env python3
"""
synthesize.py — Sintese executiva dos resumos destilados das sessoes do Cline.

Por que existe (2026-08-14, Jarvis-ZCODE):
  154 resumos individuais sao uteis como referencia, mas ninguem le 300 KB.
  Este script manda o corpus compactado (titulo/objetivo/decisoes/descobertas/
  estado/tags) em UM call ao deepseek-v4-flash (1M ctx, tokens Verboo) e gera
  a sintese executiva: top regras, descobertas, frentes abertas, conflitos e
  topicos candidatos a memoria do zcode.

Avisos de manutencao:
  - Importa verboo_router como MODULO (sys.path) para nao depender de argv.
  - Provedor e modelo agora sao obrigatorios; nao existe default nem fallback.
  - reasoning/thinking nunca e aceito como sintese final.

Uso:
  python research_tools/QA/cline_extract/synthesize.py \
      --provider verboo --model exact-model --allow-external
  -> research_tools/QA/cline_extract/synthesis.md
"""

import argparse
import json
import os
from pathlib import Path
import sys
from types import SimpleNamespace

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, "..", "..", ".."))
OUT = os.path.join(HERE, "synthesis.md")

sys.path.insert(0, os.path.join(REPO, "scripts"))
import verboo_router  # noqa: E402


# Adapted from the user-supplied FFX_AGENTS_Skills_2026-09-19 package
# (2026-09-19): private response parsing was replaced by public infer(). WHY:
# reasoning-only output is unfinished work and must never be persisted as the
# executive synthesis, while the corrected root keeps imports checkout-local.

SYSTEM = (
    "Voce e Jarvis-ZCODE, o sintetizador de conhecimento do ecossistema FFX "
    "(ffx-editor-main). Trabalha em PT-BR, tom tecnico direto, sem enfeite."
)

PROMPT_TPL = """Abaixo esta o corpus destilado de {n} sessoes de um agente de engenharia (Cline CLI) no projeto FFX Project Editor (RE do FFX PS2, editor Avalonia/C#, hooks C++). Cada item tem: sessao, data, titulo, objetivo, decisoes, descobertas, estado, proximos passos, tags.

Produza uma sintese executiva em markdown com EXATAMENTE estas secoes:

## Top 20 licoes e regras permanentes
(numere; frases curtas; so regras/verdades que se repetem ou sao estruturais — padroes de projeto, regras de ouro, armadilhas recorrentes)

## Descobertas tecnicas mais valiosas
(RE enderecos/offsets, formatos binarios, arquitetura, decisoes de produto; agrupe por dominio: MagicDll/PPP, Monster, TreasureMap, ModelViewer, Hooks, Infra/Verboo)

## Frentes abertas e bloqueios pendentes
(lista com dono/pendencia; marque as que parecem abandonadas ha semanas)

## Conflitos ou contradicoes entre sessoes
(se algum conhecimento se contradiz; se nao houver, diga "nenhum detectado")

## Top 10 topicos candidatos a memoria persistente (zcode Memory)
Para cada topico: titulo curto, tipo (rule|decision|workflow|feedback), e 2-3 frases com o conteudo da memoria. Formato de lista.

Regras: baseie-se SOMENTE no corpus. Nao invente enderecos nem arquivos. Se uma secao nao tiver material, diga isso.

--- CORPUS ({n} sessoes) ---
{corpus}
"""


def compact(items):
    rows = []
    for sid, e in items.items():
        s = e.get("summary") or {}
        m = e.get("meta") or {}
        rows.append({
            "sessao": sid,
            "data": (m.get("started_at") or "")[:10],
            "titulo": s.get("titulo") or "",
            "objetivo": s.get("objetivo") or "",
            "decisoes": s.get("decisoes") or [],
            "descobertas": s.get("descobertas") or [],
            "estado": s.get("estado_final") or "",
            "proximos": s.get("proximos_passos") or [],
            "tags": s.get("tags") or [],
        })
    return rows


def paths_alias(first: Path, second: Path) -> bool:
    if first.expanduser().resolve(strict=False) == second.expanduser().resolve(strict=False):
        return True
    try:
        return first.exists() and second.exists() and first.samefile(second)
    except OSError:
        return False


def parser():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--input", default=os.path.join(HERE, "summaries.json"))
    ap.add_argument("--out", default=OUT)
    ap.add_argument("--provider", required=True,
                    choices=[*verboo_router.REMOTE, "ollama"])
    ap.add_argument("-m", "--model", required=True, help="modelo exato; nunca substituido")
    ap.add_argument("--allow-external", action="store_true")
    ap.add_argument("--api", choices=["chat", "responses"], default="chat")
    ap.add_argument("-t", "--max-tokens", type=verboo_router.positive, default=16384)
    return ap


def main(argv=None):
    args = parser().parse_args(argv)
    route = SimpleNamespace(
        provider=args.provider,
        model=args.model,
        allow_external=args.allow_external,
        api=args.api,
        max_tokens=args.max_tokens,
    )
    try:
        # Validate the route before reading the private distilled corpus.
        verboo_router.provider_config(route.provider, route.allow_external)
        input_path = Path(args.input)
        output_path = Path(args.out)
        if paths_alias(input_path, output_path):
            raise ValueError("--input and --out must identify different files")
        data = json.loads(verboo_router.read_text(str(input_path)))
        items = data["parsed"]
        if not isinstance(items, dict):
            raise ValueError("summaries parsed field must be an object")
        corpus = json.dumps(compact(items), ensure_ascii=False, indent=1)
        prompt = PROMPT_TPL.format(n=len(items), corpus=corpus)
        print(f"prompt: {len(prompt)} chars, {len(items)} sessoes")
        result = verboo_router.infer(
            route,
            [{"role": "system", "content": SYSTEM},
             {"role": "user", "content": prompt}],
        )
        output = result["output"]
        if not isinstance(output, str) or not output.strip():
            print("ERRO: nenhuma resposta final; reasoning nao e resultado", file=sys.stderr)
            return 1
        with output_path.open("w", encoding="utf-8") as stream:
            stream.write(output)
    except (ValueError, RuntimeError, OSError, KeyError, TypeError, json.JSONDecodeError) as exc:
        print(f"ERRO: {exc}", file=sys.stderr)
        return 1
    print(f"sintese: {len(output)} chars -> {args.out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
