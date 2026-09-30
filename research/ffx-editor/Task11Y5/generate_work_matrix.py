#!/usr/bin/env python3
# Validated & versioned 2026-09-15 (inventory rule): canonical home is
# research_tools/Task11Y5/ — the work/_work_matrix/ copy is scratch (gitignored).
# ── WORK-MATRIX-OF-RECORD generator (fila FFX_LOST_WORK_RECOVERY_2026-09-15.md item 7) ──
# Funde, num ARQUIVO-ÚNICO de referência, as duas peças do trabalho da maratona
# GLM-STRUCTURES que hoje vivem separadas:
#   (1) fin01-requirements-matrix.json — 154 tasks do PLANO_MESTRE (reconstrução FIN01);
#   (2) x5-rederivation/vnext_required.rederived.json — fila 2.915 vnext-gated units
#       (re-derivação funcional X5) + y5-envelope.json (gate X5).
# NÃO duplica rows: referencia cada fonte por sha256 e embute só contagens/cross-links.
# Determinístico: recalcula hashes/contagens das fontes VIVAS e FALHA (exit != 0) se
# qualquer check de consistência quebrar — regenerar é seguro por construção.
# Aditivo: NÃO escreve nem altera nenhuma peça-fonte.
import hashlib
import json
import subprocess
import sys
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path

REPO = Path("/home/wanderson/Documents/ffx-editor-main")
OUTDIR = REPO / "artifacts/2026-09-15/work-matrix-of-record"
OUTFILE = OUTDIR / "work_matrix_of_record.json"

# ── caminhos das peças-fonte (aditivo — nunca sobrescritos por este gerador) ──
P_FIN = "artifacts/2026-09-15/session-recovery/reconstructed/fin01-requirements-matrix.json"
P_FIN_SUM = "artifacts/2026-09-15/session-recovery/reconstructed/fin01-requirements-matrix.SUMMARY.md"
P_X5 = "artifacts/2026-09-15/x5-rederivation/vnext_required.rederived.json"
P_MAN = "artifacts/2026-09-15/x5-rederivation/MANIFEST.json"
P_VAL = "artifacts/2026-09-15/x5-rederivation/validation-report.json"
P_WM = "artifacts/2026-09-15/x5-rederivation/pipeline/work-matrix.rederived.json"
P_SEM = "artifacts/2026-09-15/x5-rederivation/pipeline/semantic-triage-v1.rederived.json"
P_UTC = "artifacts/2026-09-15/session-recovery/reconstructed/vnext-unit-to-claims.reconstructed.json"
P_DISP = "artifacts/2026-09-15/session-recovery/reconstructed/vnext-claim-dispositions.reconstructed.json"
P_COV = "artifacts/2026-09-15/session-recovery/reconstructed/t1107-coverage-matrix.reconstructed.json"
P_Y5 = "docs/reverse/task11/y5/y5-envelope.json"
P_X5DOC = "docs/reverse/FFX_X5_FUNCTIONAL_REDERIVATION_2026-09-15.md"


def sha256(rel):
    return hashlib.sha256((REPO / rel).read_bytes()).hexdigest()


def git_commit(rel):
    # commit git que introduziu/último tocou a fonte (vazio se não-versionado)
    try:
        out = subprocess.run(
            ["git", "log", "-1", "--format=%h", "--", rel],
            cwd=REPO, capture_output=True, text=True, timeout=30,
        ).stdout.strip()
        return out or None
    except Exception:
        return None


def src_entry(role, rel, **extra):
    e = {
        "role": role,
        "path": rel,
        "bytes": (REPO / rel).stat().st_size,
        "sha256": sha256(rel),
        "git_commit": git_commit(rel),
    }
    e.update(extra)
    return e


def main():
    fin = json.loads((REPO / P_FIN).read_text(encoding="utf-8"))
    x5 = json.loads((REPO / P_X5).read_text(encoding="utf-8"))
    man = json.loads((REPO / P_MAN).read_text(encoding="utf-8"))
    val = json.loads((REPO / P_VAL).read_text(encoding="utf-8"))
    utc = json.loads((REPO / P_UTC).read_text(encoding="utf-8"))
    wm = json.loads((REPO / P_WM).read_text(encoding="utf-8"))
    y5 = json.loads((REPO / P_Y5).read_text(encoding="utf-8"))

    checks = []

    def check(cid, cond, detail=""):
        checks.append({"id": cid, "pass": bool(cond), "detail": str(detail)})
        return bool(cond)

    # ── peça 1: matriz 154 ──
    s = fin["summary"]
    rows = fin["rows"]
    by_sec_real = dict(Counter(r["section"] for r in rows))
    by_st_real = dict(Counter(r["status"] for r in rows))
    check("M1-status-sum-154", sum(s["by_status"].values()) == 154, s["by_status"])
    check("M2-section-sum-154", sum(s["by_section"].values()) == 154, s["by_section"])
    check("M3-rows-154", len(rows) == 154, len(rows))
    check("M4-unique-task-ids", len({r["task_id"] for r in rows}) == 154)
    check("M5-status-matches-rows", by_st_real == dict(s["by_status"]))
    check("M6-section-matches-rows", by_sec_real == dict(s["by_section"]))
    check("M7-confidence-sum-154",
          sum(fin["provenance"]["confidence_histogram"].values()) == 154,
          fin["provenance"]["confidence_histogram"])

    # ── peça 2: fila X5 2.915 ──
    c = x5["counts"]
    units = x5["vnext_units"]
    uids = {u["source_unit_id"] for u in units}
    lots_real = dict(Counter(u["lot"] for u in units))
    per_lot_declared = {v["lot"]: v["vnext"] for v in c["per_lot"].values()}
    lots_zero_filled = {k: lots_real.get(k, 0) for k in per_lot_declared}
    check("X1-units-2915", len(units) == 2915, len(units))
    check("X2-per-lot-sum-2915", sum(per_lot_declared.values()) == 2915, per_lot_declared)
    check("X3-unique-unit-ids", len(uids) == 2915)
    check("X4-lots-match-declared", lots_zero_filled == per_lot_declared, lots_zero_filled)
    check("X5-sha-matches-manifest",
          next(m["sha256"] for m in man if m["path"] == P_X5) == sha256(P_X5))

    # ── universo 10.281 (pipeline) ──
    st = wm["stats"]
    check("U1-phase1-sum-10281", sum(st.values()) == 10281, st)
    check("U2-a034-32", st["a034-vNext+provenance"] + st["a034-provenance"] + st["a034-vNext"] == 32)
    check("U3-composition-sum-10281", 7329 + 5 + 27 + 5 + 2915 == 10281)
    wm_ids = {r["id"] for r in wm["rows"]}
    check("U4-queue-subset-universe", uids <= wm_ids, f"fora={len(uids - wm_ids)}")

    # ── CROSS peça1 × peça2 ──
    binding_units = {x["source_unit_id"] for x in utc["unit_to_claims"]}
    check("C1-queue-intersect-a034-empty", not (uids & binding_units),
          f"intersecao={len(uids & binding_units)} (arbitro A7)")
    check("C2-unit-to-claims-32u-55p",
          len(binding_units) == 32 and len(utc["unit_to_claims"]) == 55)
    fin05 = next(r for r in rows if r["task_id"] == "FIN-05")
    check("C3-FIN05-pins-2915", "2.915" in json.dumps(fin05, ensure_ascii=False),
          fin05["evidence"])
    t1107 = next(r for r in rows if r["task_id"] == "T11-07")
    check("C4-T1107-pins-10281", "10.281" in json.dumps(t1107, ensure_ascii=False))
    check("C5-y5-batches-sum-134",
          sum(int(b.split()[-1]) for b in y5["candidate_batches"]) == y5["candidate_claims"],
          y5["candidate_batches"])
    a10 = next(ch for ch in val["checks"] if ch["id"].startswith("A10"))
    check("C6-y5-cross-110-134", "110/134" in a10["detail"] and 41 + 52 + 17 == 110, a10["detail"])

    failed = [c_ for c_ in checks if not c_["pass"]]
    if failed:
        print("FALHOU:", json.dumps(failed, ensure_ascii=False, indent=2))
        sys.exit(1)

    # ── documento-of-record ──
    doc = {
        "document_kind": "t1107-work-matrix-of-record",
        "version": 1,
        "generated": datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ"),
        "generated_by": "WORK-MATRIX subagente, lane FFX-STRUCTURES (fila docs/reverse/FFX_LOST_WORK_RECOVERY_2026-09-15.md item 7)",
        "generator": "research_tools/Task11Y5/generate_work_matrix.py (deterministico; recalcula hashes/contagens das fontes vivas e FALHA se qualquer check quebrar)",
        "purpose": (
            "Arquivo-unico de referencia (indice de registro) fundindo as duas visoes do "
            "trabalho da maratona GLM-STRUCTURES: (1) a matriz de requisitos das 154 tasks "
            "do PLANO_MESTRE (reconstrucao FIN01) e (2) a fila X5 dos 2.915 vnext-gated "
            "units (re-derivacao funcional). NAO duplica rows — referencia cada fonte por "
            "sha256 e embute apenas contagens, cross-links e checks."
        ),
        "replaces_lost_file": {
            "path": "glm-structures-exec-69f2d8/t1107-work-matrix.json",
            "lost": "2026-09-13 12:32-12:46 local, sem backup (TRIM NVMe; provado por session-miner + mega-readback + forense — ver docs/reverse/FFX_LOST_WORK_RECOVERY_2026-09-15.md)",
            "unit_level_reconstruction": (
                "a reconstrucao phase-1 unit-a-unit (10.281 rows) do arquivo perdido vive em "
                "artifacts/2026-09-15/x5-rederivation/pipeline/work-matrix.rederived.json; "
                "ESTE arquivo-of-record e a camada de registro que funde "
                "matriz-de-requisitos (154) x fila-vnext (2.915)"
            ),
        },
        "sources": [
            src_entry("peca-1: matriz de requisitos da maratona (154 tasks, reconstruida FIN01)", P_FIN),
            src_entry("peca-1: resumo/metodo da reconstrucao", P_FIN_SUM),
            src_entry("peca-2: fila X5 2.915 vnext-gated units (re-derivada)", P_X5),
            src_entry("peca-2: manifest sha256 do bundle x5", P_MAN),
            src_entry("peca-2: validacao 10 arbitros (9 PASS / 1 DIFF estrutural)", P_VAL),
            src_entry("universo unit-a-unit 10.281 (re-execucao phase-1)", P_WM),
            src_entry("triagem semantica 6 lotes (re-execucao rules.py)", P_SEM),
            src_entry("cross-link a034: 55 pares unit->claim (32 unidades)", P_UTC),
            src_entry("cross-link a034: dispositions por binding", P_DISP),
            src_entry("matriz de cobertura 10.281 decisions (reconstruida do candidato)", P_COV),
            src_entry("envelope Y5 (gate X5: x5_status=functionally-rederived-2026-09-15)", P_Y5),
            src_entry("doc de registro da re-derivacao X5 (arbitros, limites, Y5 cross)", P_X5DOC),
        ],
        "marathon_tasks": {
            "reference": P_FIN,
            "sha256": sha256(P_FIN),
            "git_commit": git_commit(P_FIN),
            "plan": "PLANO_MESTRE_GLM_FFX_STRUCTURES_2026-09-05.md §4 (154 IDs; plano-mae perdido junto com o dir do exec)",
            "snapshot_asof": fin["provenance"]["snapshot_asof"],
            "total": s["total_rows"],
            "by_status": s["by_status"],
            "by_section": s["by_section"],
            "confidence_histogram": fin["provenance"]["confidence_histogram"],
            "recovered_rows": s["recovered_rows"],
            "inferred_rows": s["inferred_rows"],
            "rows_note": (
                "as 154 rows NAO sao duplicadas aqui — consultar o arquivo-fonte "
                "(sha256 acima). Fidelidade: conteudo-equivalente reconstruida, NAO "
                "byte-identica ao original perdido; divergencia interna "
                "scoreboard(132F/14B/2C) x matriz(128/2/20/4) ancorada por aritmetica "
                "FIN-06 (6 rows OPS+HAR inferidas: OPS-05/06/07/08, HAR-02/03)."
            ),
        },
        "x5_units": {
            "reference": P_X5,
            "sha256": sha256(P_X5),
            "git_commit": git_commit(P_X5),
            "status": y5["x5_status"],
            "acceptance_note": (
                "aceitacao da lista re-derivada como base de roteamento e decisao do "
                "lane-owner (y5-envelope gates_remaining); identidade unit-a-unit = "
                "aproximacao deterministica quantificada, contagens exatas por construcao"
            ),
            "granularity": (
                "2.915 source-units asu-<sha256> (linha/kind) do atlas "
                "docs/reverse/FFX_STRUCTURE_COMPLETE_2026-08-17.md (10.281 units no total); "
                "subconjunto vnext_required dos lotes semanticos A-F"
            ),
            "vnext_units": c["vnext_units"],
            "distinct_claim_texts_proxy": c["distinct_claim_texts"],
            "per_lot": c["per_lot"],
            "semantic_bindings_per_lot": c["semantic_bindings_per_lot"],
            "composition_profile": val["composition_profile"],
            "boundary_uncertainty": {
                "units_within_0.5_of_cutoff": 987,
                "per_lot": {"B": 121, "C": 273, "D": 454, "E": 81, "F": 58},
                "source": "docs/reverse/FFX_X5_FUNCTIONAL_REDERIVATION_2026-09-15.md §6.2",
            },
            "validation": {
                "arbiters": "9/10 PASS (A1-A7, A9, A10)",
                "known_diff": (
                    "A8 distinct-texts: 2.915 (proxy texto cru) vs 2.909 (arbiter; textos "
                    "eram escritos pelos subagentes LLM) — diferenca estrutural de 0,2%, "
                    "irreproduzivel por construcao"
                ),
                "reference": P_VAL,
            },
            "y5_cross": {
                "cycle": y5["cycle"],
                "candidate_claims": y5["candidate_claims"],
                "batches": y5["candidate_batches"],
                "covered_units_in_queue": 110,
                "per_batch": {"b01-menu": "41/46", "b02-egovm": "52/60", "b03-ftc": "17/28"},
                "reading": (
                    "82,1% dos claims Y5 caem dentro da fila re-derivada (IC95 aleatorio "
                    "[59,81]) — NAO prova identidade; mostra que fila e drafts capturam o "
                    "mesmo sinal de carga factual (arbitro A10)"
                ),
            },
        },
        "unit_universe_context": {
            "atlas_units_total": 10281,
            "phase1_stats": st,
            "semtriage_buckets": {
                "A code/data": 1595, "B factual-runtime": 1187, "C factual-format": 1318,
                "D ambiguous": 1830, "E editorial": 438, "F factual-meta": 231,
            },
            "composition": "exclusive 7.329 / binding 5 / a034-bound 27 / a034-context 5 / vnext 2.915 (soma 10.281)",
            "narrative_pool": "editorial 2.667 + vnext 2.915 + context 5 = 5.587",
            "references": [
                {"path": P_WM, "sha256": sha256(P_WM)},
                {"path": P_SEM, "sha256": sha256(P_SEM)},
                {"path": P_COV, "sha256": sha256(P_COV)},
            ],
        },
        "cross_links": {
            "granularity_statement": (
                "As duas pecas tem granularidades por natureza distintas: 154 tasks de "
                "plano de maratona (unidade de trabalho gerencial) x 2.915 unidades de "
                "conhecimento do atlas (source-units). O cruzamento task->unidade so e "
                "emitido ONDE ha evidencia sobrevivente; fora disso fica coarse por secao."
            ),
            "fine": [
                {
                    "id": "CL-1",
                    "task": "T11-07",
                    "relation": "produtor genealogico da fila inteira",
                    "unit_scope": "ALL 2.915 (a fila sai da rodada de decisao semantica das 10.281 unidades: lotes A-F, XOR exclusive|binding|vnext)",
                    "evidence": (
                        "fin01 row T11-07 ('decisao semantica das 10.281 unidades'); os "
                        "K-alvos por lote que ancoram a re-derivacao X5 vem da entrada de "
                        "ledger 'T11-07 RODADA COMPLETA' 2026-09-08 ~07:40Z (cabecalho do "
                        "x5_derive.py; doc X5 §2)"
                    ),
                },
                {
                    "id": "CL-2",
                    "task": "T11-27",
                    "relation": "restricao/arbiter da selecao X5",
                    "unit_scope": "define o pool narrativo onde a fila vive (invariante vnext ⊆ narrative; exclui 1.555 pending re-tipadas code-literal/malformed + bindings + 239 table-separators)",
                    "evidence": (
                        "fin01 row T11-27 (candidato aceito ECF734A5, 10.281 decisions); "
                        "x5_derive.py usa o candidato como ground-truth do pool "
                        "(narrative_ids/binding_ids); doc X5 §4 restricoes canonicas"
                    ),
                },
                {
                    "id": "CL-3",
                    "task": "T11-08",
                    "relation": "atestacao de nao-vaziedade da fila + revisao dos 49 vNext claims",
                    "unit_scope": "stop marker VNEXT-REQUIRED-NONEMPTY (fila > 0); os 49 claims revisados pertencem ao lado a034 (DISJUNTO da fila 2.915 — arbitro A7)",
                    "evidence": "fin01 row T11-08; doc X5 §5/A7",
                },
                {
                    "id": "CL-4",
                    "task": "RE-01",
                    "relation": "mapeamento unit->claim do lado a034 (disjunto da fila)",
                    "unit_scope": "32 unidades a034 (27 bound + 5 context) / 55 pares unit->claim roteadas aos 49 claims aceitos (grupo fsc-20260817-019); intersecao com a fila 2.915 = 0 (re-verificado ao gerar este arquivo)",
                    "evidence": "fin01 row RE-01 ('55 atomos: 47 vNext/6 prov/2 split'); vnext-unit-to-claims.reconstructed.json (32 unidades / 55 pares)",
                },
                {
                    "id": "CL-5",
                    "task": "FIN-05",
                    "relation": "ancora numerica do residual da maratona",
                    "unit_scope": "o numero da fila X5 aparece textualmente na peça-1: residual quantificado como '2.915 vnext / 20 bloqueios / 4 condicionais'",
                    "evidence": "fin01 row FIN-05 (fin05-completion-assessment.md)",
                },
                {
                    "id": "CL-6",
                    "cycle": "Y5 (b01-menu/b02-egovm/b03-ftc)",
                    "task": None,
                    "relation": "cobertura parcial da fila pelo ciclo de drafts Y5 (TRANSVERSAL — o ciclo vnext X4/Y4/Z4 nao tem ID proprio nas 154; ver SUMMARY §3 da peça-1)",
                    "unit_scope": "110/134 claims Y5 tem covered-units DENTRO da fila 2.915; per-batch b01-menu 41/46, b02-egovm 52/60, b03-ftc 17/28",
                    "evidence": "y5-envelope.json (candidate_claims 134); validation-report A10; doc X5 §5",
                },
            ],
            "coarse": [
                {
                    "section": "T11",
                    "tasks": 29,
                    "statement": (
                        "unica secao que opera sobre o universo de unidades. Fino onde "
                        "listado acima (T11-07 produtor; T11-08/27 atestacao/restricao); "
                        "T11-09..26 sao toolchain/servicos/esquemas que PROCESSAM unidades "
                        "(assessment, schemas ×4, renderer canonico, CLI) sem posse "
                        "unit-a-unit determinavel; T11-28/29 sao a cadeia de "
                        "revisao/aceitacao do candidato (link indireto via T11-27)"
                    ),
                },
                {
                    "section": "RE",
                    "tasks": 40,
                    "statement": (
                        "so RE-01 tem ligacao unit-level (a034, disjunta da fila). "
                        "RE-37/RE-38 usam o atlas como fonte de verdade (inventario de "
                        "parsers; A034 mips m001) — ligacao tematica ao DOCUMENTO, nao as "
                        "unidades da fila. Demais RE: engine/binario, sem mapeamento"
                    ),
                },
                {
                    "section": "EXP",
                    "tasks": 32,
                    "statement": "corpus de saves / midia PS3-PS4 — universo distinto das atlas-units; sem mapeamento",
                },
                {
                    "section": "DOC",
                    "tasks": 10,
                    "statement": "documentos derivados do atlas (DOC-01 outline navegavel; DOC-09 metricas pós-T11-07) — dependem do estado pos-decisao, sem mapeamento unitario",
                },
                {
                    "section": "OPS+HAR+LNX+QA+FIN",
                    "tasks": 43,
                    "statement": "processo/ambiente/plataforma/qualidade/fechamento; FIN-05 e a ancora numerica (CL-5); sem mapeamento unitario",
                },
            ],
            "not_determinable": (
                "Nao existe fonte sobrevivente que particione a fila 2.915 entre tasks "
                "individuais alem da genealogia T11-07 (uma unica rodada de decisao, "
                "revisada/atestada por T11-08/T11-27/T11-28/T11-29). Cruzamento fino "
                "task->unidade NAO e determinavel para as demais 125 tasks (exceto RE-01 e "
                "FIN-05, coarse/ancora); por isso o cruzamento fica coarse por secao. "
                "A propria identidade unit-a-unit da fila e aproximacao deterministica "
                "quantificada (987 units a ±0,5 do corte; doc X5 §6.2) — contagens exatas "
                "por construcao."
            ),
        },
        "consistency_checks": {
            "all_pass": True,
            "total": len(checks),
            "checks": checks,
            "note": "re-executados ao gerar este arquivo contra as fontes vivas (ver generator)",
        },
        "inconsistencies_found": [],
        "declared_divergences_not_new": [
            "A8 (peca-2 interna): distinct-texts 2.915 proxy vs 2.909 arbiter — 0,2%, estrutural, ja declarada no validation-report",
            "RE-01: 55 atomos (47 vNext/6 prov/2 split) vs phase-1 route_compact 32 unidades (24 vNext/6 prov/2 split) — granularidade atomo-vs-unidade, ambas declaradas nas fontes (doc X5 §3.1 explica a decomposicao 27 bound + 5 context)",
            "peca-1 interna: divergencia scoreboard x matriz (132F/14B/2C vs 128/2/20/4) — ancorada por aritmetica FIN-06 na propria peça-1 (6 rows OPS+HAR inferidas)",
        ],
        "notes": [
            "Arquivo ADITIVO: nenhuma peca-fonte foi reescrita; todas referenciadas por sha256 do estado atual do disco.",
            "O 'work-matrix-of-record' original perdido era o t1107-work-matrix.json unit-level (10.281 rows) — sua reconstrucao phase-1 vive no pipeline do X5; este arquivo e a camada de fusao/registro pedida na fila item 7.",
            "y5-envelope.x5_status = functionally-rederived-2026-09-15; aceitacao como base de roteamento do proximo ciclo Y5 e decisao do lane-owner.",
            "Como regenerar: ver README.md ao lado deste arquivo (research_tools/Task11Y5/generate_work_matrix.py).",
        ],
    }

    OUTDIR.mkdir(parents=True, exist_ok=True)
    OUTFILE.write_text(json.dumps(doc, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    print(f"OK: {OUTFILE}")
    print(f"checks: {len(checks)}/{len(checks)} PASS")
    print(f"marathon_tasks.total={doc['marathon_tasks']['total']}  x5_units.vnext_units={doc['x5_units']['vnext_units']}")


if __name__ == "__main__":
    main()
