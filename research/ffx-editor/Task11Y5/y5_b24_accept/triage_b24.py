#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""triage_b24.py — per-claim risk triage for virtual batch y5-b24-tierb-secondpass.

Classifies each of the 494 DRAFT claims by:
  - tierb_shape bucket (from the sidecar, assigned by the deterministic predicate)
  - membership in the functionally re-derived vnext queue
    (artifacts/2026-09-15/x5-rederivation/vnext_required.rederived.json — the X5
    gate artifact; identity is a deterministic approximation, counts exact)
  - textual risk signals: lead-in ":." claims, truncated facts, duplicate texts,
    IDA-checkable signals (asm mnemonics, FFX_*/sub_* idents, exe/HLE addresses,
    register/hex refs), doc-only cross-refs.

Risk classes (honest, mechanical — NOT a truth verdict):
  A) ATLAS-DESCRIPTIVE  — the claim asserts a recorded file/format/index fact;
     verification = re-reading the pinned atlas bytes (already byte-proven by
     the validator). Safe to promote as "atlas records X".
  B) NEEDS-IDA          — the claim asserts runtime/engine semantics (function
     names, addresses, asm, formulas about live behavior). Honest acceptance
     requires Hex-Rays/disasm verification against ffxoficial.exe.i64.
  C) BORDERLINE-EDITORIAL — weak assertions (lead-ins "…:.", doc-meta leaks,
     near-empty facts). Candidates for a wording pass at materialization, not
     for claim-level acceptance.

Output: triage_b24.json (machine-readable) + stdout summary.
Read-only against the repo. Deterministic.
"""
import collections
import hashlib
import json
import re
import sys

REPO = "/home/wanderson/Documents/ffx-editor-main"
ART = f"{REPO}/artifacts/2026-09-14/y5"
B24 = "y5-b24-tierb-secondpass"
QUEUE = f"{REPO}/artifacts/2026-09-15/x5-rederivation/vnext_required.rederived.json"
OUT = f"{REPO}/work/_y5_b24_accept/triage_b24.json"

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
RE_ADDRISH = re.compile(r"\b[0-9A-Fa-f]{6,}h?\b|\+\s*0x[0-9A-Fa-f]+")
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
    doc = json.load(open(f"{ART}/drafts/y5-draft-claims-{B24}.json"))
    side = json.load(open(f"{ART}/drafts/y5-draft-claims-{B24}.units.json"))
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
        "dup_texts": len(dup_texts),
    }
    out = {"document_kind": "y5-b24 triage (mechanical risk classification; "
                            "NOT a truth verdict, NOT an attestation)",
           "generated_by": "work/_y5_b24_accept/triage_b24.py",
           "aggregate": agg, "claims": rows}
    with open(OUT, "w", encoding="utf-8") as f:
        json.dump(out, f, indent=1, ensure_ascii=False)
        f.write("\n")
    print("wrote", OUT)
    print(json.dumps(agg, indent=1, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    sys.exit(main())
