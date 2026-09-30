#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""triage_b25.py — per-claim risk triage for virtual batch
y5-b25-tierb-thirdpass (X5 tier-B THIRD pass, 163 in-queue residual units).

1:1 adaptation of research_tools/Task11Y5/y5_b24_accept/triage_b24.py to the
pass-3 artifacts under work/_x5_tierb3/. Same risk classes, same mechanical
signals — NOT a truth verdict:

  A) ATLAS-DESCRIPTIVE  — the claim asserts a recorded file/format/index fact;
     verification = re-reading the pinned atlas bytes (already byte-proven by
     the validator). Safe to promote as "atlas records X".
  B) NEEDS-IDA          — the claim asserts runtime/engine semantics (function
     names, addresses, asm, formulas about live behavior). Honest acceptance
     requires Hex-Rays/disasm verification against ffxoficial.exe.i64.
  C) BORDERLINE-EDITORIAL — weak assertions (lead-ins "…:.", doc-meta leaks,
     near-empty facts). Candidates for a wording pass at materialization.

Pass-3 note: every drafted unit is by construction a residual bucket
(prose/lead-in/bold-label/doc-meta/doc-ref/hrule) — i.e. the borderline-heavy
population; the risk classes still separate "records a real fact" from
"asserts runtime semantics" and "weak editorial leak".

Output: work/_x5_tierb3/triage_b25.json + stdout summary.
Read-only against the repo. Deterministic (document order).
"""
import collections
import json
import re
import sys

REPO = "/home/wanderson/Documents/ffx-editor-main"
OUT = f"{REPO}/work/_x5_tierb3"
B25 = "y5-b25-tierb-thirdpass"
QUEUE = f"{REPO}/artifacts/2026-09-15/x5-rederivation/vnext_required.rederived.json"

# IDA-checkable signals inside the CLAIM TEXT (what the claim asserts).
RE_FFX_IDENT = re.compile(r"\b(?:FFX|Ffx)[A-Za-z0-9_]*|sub_[0-9A-Fa-f]+|"
                          r"\b0x[0-9A-Fa-f]{5,}\b|\.text:|\.rdata:|\.data:")
RE_ASM = re.compile(r"\b(push|pop|mov|movzx|movsx|cmp|jmp|call|lea|xor|test|add|"
                    r"sub|shl|shr|sar|imul|idiv|jne|je|jz|jnz|jg|jge|jl|jle|ja|"
                    r"jb|jae|jbe|fld|fstp|fmul|fadd|cvtsi)\b\s+[a-z0-9,\[\]*+ ]",
                    re.I)
RE_RUNTIME_WORD = re.compile(
    r"\b(runtime|FFX\.exe|entry ?point|address|VA|RVA|function|vftable|vtable|"
    r"register|stack|heap|opcode handler|dispatch|decompile|ida)\b", re.I)
RE_LEADIN = re.compile(r":\.$")
# every claim_text carries the honest provenance prefix "Legacy FFX structure
# atlas (2026-08-17 snapshot), <section>: " — it would trip the FFX_/runtime
# detectors on every claim, so signals are computed on the FACT part only.
RE_PREFIX = re.compile(r"^Legacy FFX structure atlas \(2026-08-17 snapshot\), "
                       r".*?:\s+")


def risk_class(claim_text: str, bucket: str) -> tuple[str, list[str]]:
    claim_text = RE_PREFIX.sub("", claim_text, count=1)
    sig = []
    if RE_LEADIN.search(claim_text):
        sig.append("lead-in")
    if "… [truncated]" in claim_text:
        sig.append("truncated")
    if bucket == "asm-dump" or RE_ASM.search(claim_text):
        sig.append("asm")
    if RE_FFX_IDENT.search(claim_text):
        sig.append("ida-ident/addr")
    elif RE_RUNTIME_WORD.search(claim_text):
        sig.append("runtime-word")
    if sig:
        # asm / idents / addresses always outrank the lead-in flag
        hard = [s for s in sig if s in ("asm", "ida-ident/addr")]
        if hard:
            return "needs-ida", sig
        return "borderline-editorial", sig
    return "atlas-descriptive", sig


def main() -> int:
    doc = json.load(open(f"{OUT}/drafts/y5-draft-claims-{B25}.json"))
    side = json.load(open(f"{OUT}/drafts/y5-draft-claims-{B25}.units.json"))
    q = json.load(open(QUEUE))
    qid = {u["source_unit_id"]: u["lot"] for u in q["vnext_units"]}

    by_claim = {u["claim_id"]: u for u in side["units"]}
    text_seen = collections.Counter(c["claim_text"] for c in doc["claims"])
    dup_texts = {t for t, n in text_seen.items() if n > 1}

    rows = []
    for c in doc["claims"]:
        u = by_claim[c["claim_id"]]
        bucket = u.get("tierb_shape")
        inq = u["source_unit_id"] in qid
        cls, sig = risk_class(c["claim_text"], bucket)
        if c["claim_text"] in dup_texts:
            sig.append("dup-text")
        rows.append({
            "claim_id": c["claim_id"],
            "source_unit_id": u["source_unit_id"],
            "line_start": u["line_start"],
            "kind": u["kind"],
            "bucket": bucket,
            "in_rederived_queue": inq,
            "queue_lot": qid.get(u["source_unit_id"]),
            "risk": cls,
            "signals": sig,
            "claim_text": c["claim_text"],
        })

    agg = {
        "total": len(rows),
        "by_risk": dict(collections.Counter(r["risk"] for r in rows)),
        "by_bucket": dict(collections.Counter(r["bucket"] for r in rows)),
        "in_queue": sum(1 for r in rows if r["in_rederived_queue"]),
        "risk_x_queue": {
            cls: {
                "n": sum(1 for r in rows if r["risk"] == cls),
                "in_queue": sum(1 for r in rows if r["risk"] == cls
                                and r["in_rederived_queue"]),
            } for cls in ("atlas-descriptive", "needs-ida", "borderline-editorial")
        },
        "bucket_x_queue": {
            b: {
                "n": sum(1 for r in rows if r["bucket"] == b),
                "in_queue": sum(1 for r in rows if r["bucket"] == b
                                and r["in_rederived_queue"]),
            } for b in sorted({r["bucket"] for r in rows})
        },
        "lot_x_risk": {
            lot: {
                "n": sum(1 for r in rows if r["queue_lot"] == lot),
            } for lot in sorted({r["queue_lot"] for r in rows})
        },
        "dup_texts": len(dup_texts),
    }
    out = {"document_kind": "y5-b25 triage (mechanical risk classification; "
                            "NOT a truth verdict, NOT an attestation)",
           "generated_by": "work/_x5_tierb3/triage_b25.py",
           "aggregate": agg, "claims": rows}
    out_path = f"{OUT}/triage_b25.json"
    with open(out_path, "w", encoding="utf-8") as f:
        json.dump(out, f, indent=1, ensure_ascii=False)
        f.write("\n")
    print("wrote", out_path)
    print(json.dumps(agg, indent=1, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    sys.exit(main())
