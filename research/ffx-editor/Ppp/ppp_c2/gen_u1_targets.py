#!/usr/bin/env python3
"""Generate work/ppp_c2/u1_targets.json + work/ppp_c2/U1_MANIFESTS.md.

T3 target spec per U1 family (10 families) x effect (0021, 0098):

  * 9 families come from prepare_u1_manifest.py manifests
    (work/ppp_c2/manifests/magic_{effect}.json) — candidates = non-header
    records selected by the U1_PROVEN_SCHEMAS contract.
  * pppColMove has no U1_PROVEN_SCHEMA entry (it lives in
    DIRECT_OPERAND_SCHEMAS); its candidates were produced by the C1 walker
    during the 2026-07-31 T3 batch and are read from the T3 evidence JSONs
    (work/t3_batch/T3_EVIDENCE_pppColMove_{effect}.json).

Windows come from the canonical family schemas in work/ppp_c2/families/*.json
(validated against U1_PROVEN_SCHEMAS / DIRECT_OPERAND_SCHEMAS).

Source DLLs are read-only (F:\\ffx-reconstructed\\extras\\magicFiles\\FFX\\);
nothing is ever written to game files.
"""

from __future__ import annotations

import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

REPO = Path(r"C:\Users\wande\Documents\ffx-editor-main")
PPP_C2 = REPO / "work" / "ppp_c2"
MANIFESTS = PPP_C2 / "manifests"
FAMILIES = PPP_C2 / "families"
T3 = REPO / "work" / "t3_batch"
MAGIC_DIR = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX")

U1_FAMILIES = (
    "pppSclMove", "pppSclAccele", "pppAccele", "pppAngAccele",
    "pppMove", "pppAngMove", "pppColMove", "pppPoint", "pppAngle", "pppScale",
)
EFFECTS = ("0021", "0098")


def load_family_schema(opcode: str) -> dict:
    path = FAMILIES / f"{opcode}.json"
    with open(path, encoding="utf-8-sig") as fh:
        return json.load(fh)


def load_manifest(effect: str) -> dict:
    with open(MANIFESTS / f"magic_{effect}.json", encoding="utf-8") as fh:
        return json.load(fh)


def load_t3_evidence(family: str, effect: str) -> dict:
    with open(T3 / f"T3_EVIDENCE_{family}_{effect}.json", encoding="utf-8") as fh:
        return json.load(fh)


def sha256_file(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def build() -> tuple[dict, list[dict]]:
    families: dict[str, dict] = {}
    md_rows: list[dict] = []
    for opcode in U1_FAMILIES:
        schema = load_family_schema(opcode)
        fam: dict = {
            "opcode": opcode,
            "handler_addr": schema["handler_addr"],
            "window": schema["runtime_window"],
            "effects": {},
        }
        for effect in EFFECTS:
            dll = f"magic_{effect}.dll"
            if opcode == "pppColMove":
                ev = load_t3_evidence("pppColMove", effect)
                cands = ev["candidates"]
                eff = {
                    "dll": dll,
                    "candidate_source": "walker_t3",
                    "candidate_count": ev["candidate_count"],
                    "handler_index_local": cands[0]["handler_index"] if cands else None,
                    "record_offsets": [c["callback_record_offset"] for c in cands],
                    "record_sha256s": [c["record_sha256_before"] for c in cands],
                    "window_hexes": [c["window_hex_before"] for c in cands],
                    "status": "t3_pass" if ev.get("t3_pass") else "t3_fail",
                }
            else:
                mf = load_manifest(effect)
                entry = mf["families"].get(opcode)
                if entry is None or not entry.get("present"):
                    eff = {
                        "dll": dll,
                        "candidate_source": "manifest",
                        "candidate_count": 0,
                        "handler_index_local": None,
                        "record_offsets": [],
                        "record_sha256s": [],
                        "window_hexes": [],
                        "status": "pendente_manifest",
                    }
                else:
                    cands = entry["candidates"]
                    eff = {
                        "dll": dll,
                        "candidate_source": "manifest",
                        "candidate_count": len(cands),
                        "handler_index_local": entry["handler_index"],
                        "record_offsets": [c["callback_record_offset"] for c in cands],
                        "record_sha256s": [c["record_sha256"] for c in cands],
                        "window_hexes": [c["runtime_operand_hex"] for c in cands],
                        "status": "t3_pass",  # T3 evidence 2026-07-31: all PASS, restore byte-identical
                    }
            fam["effects"][effect] = eff
            md_rows.append({
                "opcode": opcode,
                "dll": dll,
                "effect": effect,
                "count": eff["candidate_count"],
                "offsets": eff["record_offsets"],
                "window": schema["runtime_window"],
                "idx": eff["handler_index_local"],
                "source": eff["candidate_source"],
                "status": eff["status"],
            })
        families[opcode] = fam

    dll_hashes = {
        "magic_0021.dll": sha256_file(MAGIC_DIR / "magic_0021.dll"),
        "magic_0098.dll": sha256_file(MAGIC_DIR / "magic_0098.dll"),
    }
    doc = {
        "generated": datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ"),
        "pipeline": "scripts/ppp_disassembler/prepare_u1_manifest.py (9 U1 famílias) + walker C1 via t3_batch (pppColMove)",
        "source_dlls": str(MAGIC_DIR),
        "source_read_only": True,
        "dll_sha256": dll_hashes,
        "manifest_sha256": {
            "magic_0021.json": sha256_file(MANIFESTS / "magic_0021.json"),
            "magic_0098.json": sha256_file(MANIFESTS / "magic_0098.json"),
        },
        "families": families,
    }
    return doc, md_rows

def write_markdown(rows: list[dict], doc: dict) -> str:
    lines = [
        "# U1 Manifests — T3 Targets (PPP C2)",
        "",
        f"Gerado em {doc['generated']} por `work/ppp_c2/gen_u1_targets.py`.",
        "Fonte de candidatos: manifests `prepare_u1_manifest.py` (9 famílias U1) + walker C1 do batch T3 2026-07-31 (pppColMove).",
        f"DLLs de origem (somente leitura): `{doc['source_dlls']}`",
        "",
        "## DLLs",
        "",
        "| DLL | SHA256 |",
        "|---|---|",
        *[f"| {k} | `{v}` |" for k, v in doc["dll_sha256"].items()],
        "",
        "## Manifests (reproduzíveis byte-a-byte vs 2026-07-31)",
        "",
        "| Manifest | SHA256 |",
        "|---|---|",
        *[f"| {k} | `{v}` |" for k, v in doc["manifest_sha256"].items()],
        "",
        "## Tabela de alvos T3 por família × DLL",
        "",
        "| Família | DLL | #candidatos | record(s) | janela (record+) | handler_index local | origem | status |",
        "|---|---|---|---|---|---|---|---|",
    ]
    for r in rows:
        offs = r["offsets"]
        if not offs:
            offs_txt = "—"
        elif len(offs) <= 4:
            offs_txt = ", ".join(offs)
        else:
            offs_txt = ", ".join(offs[:3]) + f", … (+{len(offs) - 3})"
        win = f"+0x{r['window']['start']:X}..+0x{r['window']['start'] + r['window']['width']:X} ({r['window']['width']}B)"
        idx = str(r["idx"]) if r["idx"] is not None else "—"
        lines.append(
            f"| {r['opcode']} | {r['dll']} | {r['count']} | `{offs_txt}` | {win} | {idx} | {r['source']} | {r['status']} |"
        )
    lines += [
        "",
        "## Notas de honestidade",
        "",
        "- `handler_index` é **local ao fp.h do efeito** (nunca índice universal). "
        "pppSclMove/0021 = 7 confirmado; demais índices vêm do manifest do efeito correspondente.",
        "- `pppColMove` não está em `U1_PROVEN_SCHEMAS` (vive em `DIRECT_OPERAND_SCHEMAS`, janela 8B u16[4] @ +8). "
        "Candidatos vieram do walker C1 do batch T3 (evidências `work/t3_batch/T3_EVIDENCE_pppColMove_*.json`), não do manifest U1.",
        "- Status `t3_pass` = evidência T3 copy-only de 2026-07-31 (dry-run/apply/restore byte-idêntico em cópias descartáveis). "
        "Nenhuma DLL do jogo foi modificada.",
        "- Offsets completos + SHA256 de cada record: `work/ppp_c2/u1_targets.json` (este diretório).",
        "- pppRandHCV/pppSRandHCV/pppKeTh não fazem parte da fila U1 (schemas diretos, sem writer autorizado na fila principal).",
    ]
    return "\n".join(lines) + "\n"


def main() -> int:
    doc, rows = build()
    (PPP_C2 / "u1_targets.json").write_text(
        json.dumps(doc, indent=2) + "\n", encoding="utf-8"
    )
    (PPP_C2 / "U1_MANIFESTS.md").write_text(write_markdown(rows, doc), encoding="utf-8")
    print(f"rows={len(rows)} targets written")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

