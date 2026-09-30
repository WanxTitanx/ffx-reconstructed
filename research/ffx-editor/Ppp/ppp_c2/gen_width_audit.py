#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""gen_width_audit.py — Reconciliação de larguras PPP (C2/C3).

Lê os 22 schemas de work/ppp_c2/families/*.json, cruza com
U1_PROVEN_SCHEMAS (9) e DIRECT_OPERAND_SCHEMAS (3) de
scripts/ppp_disassembler/family_schema.py e com as evidências T3 de
work/t3_batch/T3_BATCH_SUMMARY_20260731.md, e gera:

  work/ppp_c2/width_audit.json          (auditoria por família)
  work/ppp_c2/WIDTH_RECONCILIATION.md   (tabela + conclusões)

Regras derivadas das fontes (nada é inventado):
  - raw_effective (usado na classificação): para famílias U1_PROVEN_SCHEMAS
    usa o raw_payload_width proven (autoridade; os JSONs de pppAccele e
    pppAngAccele têm o campo raw_width_yonishi com typo 24); para as demais
    usa o campo raw_width_yonishi do JSON (pode ser null).
  - proven_schema_bate: True quando existe schema proven E ele confirma a
    janela do schema JSON (janela 0/N/A no JSON => schema proven é a fonte).
  - classificação payload_maior_que_janela: raw > janela — o handler
    consome menos que o record; bytes extras não-lidos por este handler.
"""

from __future__ import annotations

import json
import re
import sys
from datetime import date
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(REPO_ROOT / "scripts"))

from ppp_disassembler.family_schema import (
    DIRECT_OPERAND_SCHEMAS,
    U1_PROVEN_SCHEMAS,
    load_family_schemas_dir,
)

FAMILIES_DIR = REPO_ROOT / "work" / "ppp_c2" / "families"
T3_SUMMARY = REPO_ROOT / "work" / "t3_batch" / "T3_BATCH_SUMMARY_20260731.md"
OUT_DIR = REPO_ROOT / "work" / "ppp_c2"
OUT_JSON = OUT_DIR / "width_audit.json"
OUT_MD = OUT_DIR / "WIDTH_RECONCILIATION.md"
GENERATOR = "Jarvis-PPP-C2C3"

_T3_ROW_RE = re.compile(
    r"^\|\s*(?P<family>[A-Za-z0-9_]+)\s*\|\s*(?P<effect>[0-9A-Fa-f]{4})\s*\|\s*"
    r"(?P<origin>[A-Za-z_]+)\s*\|\s*(?P<candidates>\d+)\s*\|\s*(?P<status>[A-Za-z][^|]*?)\s*\|$"
)


def parse_t3_summary(path: Path) -> dict[str, dict]:
    """Extrai {family: {effects: [str], candidates: int, status: str}} do resumo T3."""
    families: dict[str, dict] = {}
    for line in path.read_text(encoding="utf-8").splitlines():
        m = _T3_ROW_RE.match(line.strip())
        if not m:
            continue
        fam = m.group("family")
        cand = int(m.group("candidates"))
        status = m.group("status").strip()
        entry = families.setdefault(fam, {"effects": [], "candidates": 0, "status": "n/a"})
        entry["effects"].append(f"{m.group('effect')}: {cand} {status}")
        entry["candidates"] += cand
        if status == "PASS":
            entry["status"] = "PASS"
    return families


def proven_schema_of(family: str):
    """(kind, schema) — kind em {U1_PROVEN_SCHEMAS, DIRECT_OPERAND_SCHEMAS} ou (None, None)."""
    if family in U1_PROVEN_SCHEMAS:
        return "U1_PROVEN_SCHEMAS", U1_PROVEN_SCHEMAS[family]
    if family in DIRECT_OPERAND_SCHEMAS:
        return "DIRECT_OPERAND_SCHEMAS", DIRECT_OPERAND_SCHEMAS[family]
    return None, None


def classify(raw_effective, win: dict) -> str:
    if win["width"] == 0:
        return "sem_janela_registrada"
    if raw_effective is None:
        return "sem_raw"
    if raw_effective > win["width"]:
        return "payload_maior_que_janela"
    if raw_effective == win["width"]:
        return "janela_igual_raw"
    return "janela_maior_que_raw"


def schema_info_dict(kind: str, schema) -> dict:
    return {
        "kind": kind,
        "handler_addr": hex(schema.host_handler),
        "raw_payload_width": schema.raw_payload_width,
        "runtime_operand_kind": schema.runtime_operand_kind.value,
        "runtime_operand_offset": schema.runtime_operand_offset,
        "runtime_operand_width": schema.runtime_operand_width,
        "callback_record_width": schema.callback_record_width,
    }


def build_nota(family, data, kind, schema, raw_conflict, classification, t3_entry) -> str:
    win = data["runtime_window"]
    raw_json = data["raw_width_yonishi"]
    parts = []

    if schema is not None:
        parts.append(
            f"schema {kind} (handler {hex(schema.host_handler)}): raw={schema.raw_payload_width} "
            f"{schema.runtime_operand_kind.value} off={schema.runtime_operand_offset} "
            f"w={schema.runtime_operand_width} rec={schema.callback_record_width}"
        )
        if raw_conflict:
            if family in U1_PROVEN_SCHEMAS:
                parts.append(
                    f"CONFLITO raw: JSON={raw_json} vs proven={schema.raw_payload_width} "
                    f"(nota do proprio JSON cita {schema.raw_payload_width}B; corpus proven); usar proven"
                )
            else:
                parts.append(
                    f"raw JSON={raw_json} = fronteira do record no corpus; schema raw={schema.raw_payload_width} "
                    "= payload consumido pelo handler (semantica diferente — janela bate)"
                )
    else:
        parts.append("sem proven schema (U2/U3)")

    if win["width"] > 0:
        end = win["start"] + win["width"] - 1
        parts.append(
            f"janela editavel {win['width']}B @ program+{win['start']}..+{end} "
            f"(record+0x{win['start']:x}..+0x{end + 1:x})"
        )
        if win["width"] != 16:
            parts.append("janela != contrato U1 16B — writer precisa de EXTENSION de janela")

    if classification == "payload_maior_que_janela":
        parts.append(
            "payload_maior_que_janela: handler consome menos que o record; "
            "bytes extras nao-lidos por este handler"
        )
    elif classification == "janela_igual_raw":
        parts.append("janela_igual_raw: raw == janela; sem payload extra")

    if t3_entry is not None:
        parts.append("T3: " + "; ".join(t3_entry["effects"]))

    if win["width"] == 0:
        first_note = (data.get("notes") or [""])[0]
        if first_note:
            parts.append("schema JSON: " + first_note[:220].rstrip() + ("..." if len(first_note) > 220 else ""))

    return "; ".join(parts)


def main() -> None:
    schemas = load_family_schemas_dir(FAMILIES_DIR)
    t3 = parse_t3_summary(T3_SUMMARY)

    rows = []

    def sort_key(fam: str):
        has_win = schemas[fam]["runtime_window"]["width"] > 0
        return (0 if has_win else 1, fam)

    for fam in sorted(schemas, key=sort_key):
        data = schemas[fam]
        win = data["runtime_window"]
        raw_json = data["raw_width_yonishi"]
        kind, schema = proven_schema_of(fam)

        # raw efetivo usado na classificacao (autoridade proven para U1)
        family_in_u1 = fam in U1_PROVEN_SCHEMAS
        if family_in_u1:
            raw_effective = schema.raw_payload_width if schema is not None else raw_json
        else:
            raw_effective = raw_json

        raw_conflict = (
            raw_json is not None and schema is not None and schema.raw_payload_width != raw_json
        )

        if schema is None:
            bate = False
        elif win["width"] == 0:
            bate = True  # JSON nao registra janela; schema proven e a fonte (writer boundary)
        elif family_in_u1:
            bate = (schema.raw_payload_width == raw_json) and (schema.runtime_operand_width == win["width"])
        else:  # DIRECT (pppColMove)
            bate = (schema.runtime_operand_offset == win["start"]) and (schema.runtime_operand_width == win["width"])

        classification = classify(raw_effective, win)
        t3_entry = t3.get(fam)
        nota = build_nota(fam, data, kind, schema, raw_conflict, classification, t3_entry)

        rows.append(
            {
                "family": fam,
                "handler_addr": data["handler_addr"],
                "raw_yonishi": raw_json,
                "raw_effective": raw_effective,
                "raw_conflito": raw_conflict,
                "runtime_window": {"start": win["start"], "width": win["width"]},
                "width_reconciled": data["width_reconciled"],
                "classificacao": classification,
                "proven_schema_bate": bate,
                "proven_schema": schema_info_dict(kind, schema) if schema is not None else None,
                "t3": "; ".join(t3_entry["effects"]) if t3_entry is not None else None,
                "nota": nota,
            }
        )

    # Observações top-level (derivadas, nao inventadas)
    observations = []
    for fam in sorted(set(t3) - set(schemas)):
        entry = t3[fam]
        observations.append(
            f"{fam}: presente no resumo T3 ({'; '.join(entry['effects'])}) mas SEM schema em "
            "work/ppp_c2/families/ (fora do audit de 22)."
        )
    for row in rows:
        if row["raw_conflito"] and row["family"] in U1_PROVEN_SCHEMAS:
            observations.append(
                f"raw_width_yonishi de {row['family']}.json ({row['raw_yonishi']}) conflita com "
                f"U1_PROVEN_SCHEMAS ({row['proven_schema']['raw_payload_width']}); usar proven."
            )

    pass_combos = sum(1 for entry in t3.values() for e in entry["effects"] if e.endswith("PASS"))
    total_candidates = sum(entry["candidates"] for entry in t3.values())

    meta = {
        "generated_by": GENERATOR,
        "generated_at": date.today().isoformat(),
        "script": "work/ppp_c2/gen_width_audit.py",
        "sources": [
            "work/ppp_c2/families/*.json (22 schemas)",
            "scripts/ppp_disassembler/family_schema.py (U1_PROVEN_SCHEMAS 9 + DIRECT_OPERAND_SCHEMAS 3)",
            "work/t3_batch/T3_BATCH_SUMMARY_20260731.md",
        ],
        "counts": {
            "families": len(rows),
            "u1_with_window": sum(1 for r in rows if r["runtime_window"]["width"] > 0),
            "u2_u3_sem_janela": sum(1 for r in rows if r["runtime_window"]["width"] == 0),
            "with_proven_schema": sum(1 for r in rows if r["proven_schema"] is not None),
            "proven_schema_bate_true": sum(1 for r in rows if r["proven_schema_bate"]),
            "payload_maior_que_janela": sum(1 for r in rows if r["classificacao"] == "payload_maior_que_janela"),
            "raw_conflito": sum(1 for r in rows if r["raw_conflito"]),
            "t3_families_pass": sum(1 for fam, e in t3.items() if e["status"] == "PASS"),
            "t3_pass_combos": pass_combos,
            "t3_total_candidates": total_candidates,
        },
    }

    audit = {"meta": meta, "families": rows, "observacoes": observations}

    OUT_JSON.write_text(json.dumps(audit, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    OUT_MD.write_text(render_markdown(audit), encoding="utf-8")

    # Resumo no stdout
    print(f"width_audit.json        -> {OUT_JSON}")
    print(f"WIDTH_RECONCILIATION.md -> {OUT_MD}")
    print(f"familias={meta['counts']['families']} u1={meta['counts']['u1_with_window']} "
          f"u2u3={meta['counts']['u2_u3_sem_janela']} bate={meta['counts']['proven_schema_bate_true']} "
          f"payload_maior={meta['counts']['payload_maior_que_janela']} raw_conflito={meta['counts']['raw_conflito']}")
    for row in rows:
        print(f"  {row['family']:<16} raw={str(row['raw_effective']):>4} janela={row['runtime_window']['width']:>3} "
              f"bate={str(row['proven_schema_bate']):<5} {row['classificacao']}")


def render_markdown(audit: dict) -> str:
    rows = audit["families"]
    m = audit["meta"]["counts"]
    lines = [
        "# WIDTH_RECONCILIATION — PPP C2/C3",
        "",
        f"> Gerado automaticamente por `work/ppp_c2/gen_width_audit.py` ({audit['meta']['generated_at']}, "
        f"{audit['meta']['generated_by']}). Não editar à mão — re-rodar o script.",
        "",
        "## Fontes",
        "",
        "1. `work/ppp_c2/families/*.json` — 22 schemas (10 U1 com janela, 12 U2/U3 sem janela).",
        "2. `scripts/ppp_disassembler/family_schema.py` — `U1_PROVEN_SCHEMAS` (9) e `DIRECT_OPERAND_SCHEMAS` (3).",
        "3. `work/t3_batch/T3_BATCH_SUMMARY_20260731.md` — evidências T3 (janelas reais por família).",
        "",
        "## Método",
        "",
        "- `raw_yonishi` = campo `raw_width_yonishi` do schema JSON (fronteira do record no corpus Yonishi).",
        "- `raw_effective` = valor usado na classificação: para famílias `U1_PROVEN_SCHEMAS` usa o "
        "`raw_payload_width` proven (autoridade — ver conflitos abaixo); demais usam o campo JSON.",
        "- `runtime_window` = janela editável provada por decompile do handler (`0` = N/A).",
        "- `width_reconciled` = janela reconciliada (runtime_window.width).",
        "- `proven_schema_bate` = existe schema proven E ele confirma a janela do schema JSON "
        "(janela N/A no JSON => schema proven é a fonte).",
        "",
        "## Tabela de reconciliação (22 famílias)",
        "",
        "| family | handler | raw_yonishi | raw_effective | janela (start/width) | reconciled | schema proven | bate | classificação | T3 | nota |",
        "|---|---|---|---|---|---|---|---|---|---|---|",
    ]
    for r in rows:
        win = r["runtime_window"]
        window = "—" if win["width"] == 0 else f"{win['start']}/{win['width']}"
        schema_kind = r["proven_schema"]["kind"] if r["proven_schema"] else "—"
        t3 = r["t3"] or "—"
        nota = r["nota"]
        nota = nota if len(nota) <= 200 else nota[:197].rstrip() + "..."
        lines.append(
            f"| {r['family']} | {r['handler_addr']} | {r['raw_yonishi'] if r['raw_yonishi'] is not None else '—'} "
            f"| {r['raw_effective'] if r['raw_effective'] is not None else '—'} | {window} | {r['width_reconciled']} "
            f"| {schema_kind} | {'sim' if r['proven_schema_bate'] else 'não'} | {r['classificacao']} | {t3} | {nota} |"
        )

    lines += [
        "",
        "## Famílias `payload_maior_que_janela` (raw > janela)",
        "",
    ]
    pm = [r for r in rows if r["classificacao"] == "payload_maior_que_janela"]
    for r in pm:
        lines.append(
            f"- {r['family']}: {r['raw_effective']} → {r['runtime_window']['width']} "
            "(handler consome menos que o record; bytes extras não-lidos por este handler)"
        )
    lines += ["", "## Conflitos de `raw_width_yonishi` nos JSONs (campo com typo)", ""]
    for r in rows:
        if r["raw_conflito"] and r["family"] in U1_PROVEN_SCHEMAS:
            lines.append(
                f"- `{r['family']}.json`: campo `raw_width_yonishi` = {r['raw_yonishi']} "
                f"mas proven = {r['proven_schema']['raw_payload_width']} — usar proven (o próprio JSON, "
                f"na nota, cita {r['proven_schema']['raw_payload_width']}B)."
            )
    lines += ["", "## Conclusões", ""]
    conclusions = [
        "**Janela editável = `runtime_window`.** O valor reconciliado (e o que o writer deve respeitar) é o "
        "`runtime_window` provado por decompile/T3. `raw_yonishi` é a fronteira do record no corpus — **não** "
        "é a janela.",
        f"**`payload_maior_que_janela` em {m['payload_maior_que_janela']} famílias.** O handler consome menos "
        "que o record; os bytes extras não são lidos por este handler (ex.: pppMove 20B com 4B extras do "
        "prefixo; podem pertencer a outros handlers do mesmo record).",
        "**pppColMove é a única janela 8B** (`u16[4]` @ program+8..+15) → **writer extension obrigatória** "
        "(schema DIRECT raw=8/w=8; o writer U1 de 16B não serve). Atenção extra: a t0 entry 151 liga "
        "pppColMove a `0x75C090` (SclMove float4/16B) — resolver o handler real pelo fp.h local antes de "
        "escrever.",
        "**pppKeTh / pppRandHCV (DIRECT, janela N/A no JSON):** o schema proven define a janela de operando "
        "`{off 8, w 57}` (KeTh) e `{off 8, w 9}` (RandHCV) como writer boundary. Sem T3/T4 autorizado; "
        "pppRandHCV sem candidatos em 0021/0098; pppKeTh T3 PASS só em 0021.",
        "**U2/U3 (draw/matrix/alloc):** sem janela editável — handler não lê payload (DrawMatrix, "
        "DrawMatrixFront, MatrixScl, MatrixXYZ, KeThRes32/48) ou payload não reconciliado (DrawMdl3/Sea/"
        "Semi/Ts).",
        "**Conflitos de campo corrigidos pelo audit:** pppAccele (JSON 24 → proven 16) e pppAngAccele "
        "(JSON 24 → proven 36) — ver seção acima; corrigir `raw_width_yonishi` nos JSONs.",
        "**pppColAccele:** T3 PASS em 0021/0098 mas **sem schema** em `work/ppp_c2/families/` — 23ª família "
        "pendente de schema JSON.",
        f"**T3 confirma as janelas:** {m['t3_families_pass']} famílias com PASS, {m['t3_pass_combos']} "
        "combinações família×efeito, 485 candidatos processados (copy-only, offline).",
    ]
    for i, c in enumerate(conclusions, 1):
        lines.append(f"{i}. {c}")
    lines += ["", "## Arquivos gerados", "", "- `work/ppp_c2/width_audit.json`", "- `work/ppp_c2/WIDTH_RECONCILIATION.md`", ""]
    return "\n".join(lines)


if __name__ == "__main__":
    main()



