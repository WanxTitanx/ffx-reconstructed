#!/usr/bin/env python3
"""T3 copy-only pipeline (batch) — magic_0021 + magic_0098.

Runs the full T3 contract on disposable copies under work/t3_batch/copies/:
  * candidate enumeration (manifests for U1, C1 walker for direct families)
  * dry-run (no write): expected record SHA before, record SHA after,
    diff confined to the schema window
  * apply -> restore on the COPY returning byte-identical bytes
  * per (family, effect) evidence JSON under work/t3_batch/

The original DLLs in the Steam tree are NEVER touched; only copies under
work/t3_batch/copies/ are mutated. No repo modules are edited — the
toolchain modules are imported read-only.
"""

from __future__ import annotations

import hashlib
import json
import os
import struct
import sys
import tempfile
import time
from pathlib import Path

REPO_ROOT = Path(r"C:\Users\wande\Documents\ffx-editor-main")
sys.path.insert(0, str(REPO_ROOT / "scripts"))

from ppp_disassembler import c2_effect_overlay as overlay
from ppp_disassembler.mine_c2_raw_families import parse_yonishi_header
from ppp_disassembler.family_schema import U1_PROVEN_SCHEMAS
from ppp_disassembler.useful_ppp_candidates import (
    UsefulPppCandidate,
    UsefulPppFamilySpec,
    select_useful_ppp_candidates,
)
from ppp_disassembler.useful_ppp_writer import (
    AngularDeltas,
    ExpectedPppRecordHashMismatchError,
    apply_angular_move,
    apply_vector,
    dry_run_angular_move,
    dry_run_vector,
    restore_angular_move,
    restore_vector,
)

WORK = REPO_ROOT / "work" / "t3_batch"
COPIES = WORK / "copies"
MANIFESTS = REPO_ROOT / "work" / "layer_c" / "tomorrow_triggers" / "tomorrow_triggers" / "manifests"
YONISHI_ROOT = Path(r"D:\FFX Extracted\FFX\ffx_ps2\ffx\yonishi_data\dat_ov")

FLOAT4_FAMILIES = frozenset({"pppSclMove", "pppSclAccele", "pppMove", "pppAccele", "pppPoint", "pppScale"})
INT32_FAMILIES = frozenset({"pppAngMove", "pppAngAccele", "pppAngle"})

# ---------------------------------------------------------------------------
# Direct-operand family schemas (own schemas in THIS script; window at
# callback record +8 per canonical evidence: 4xWORD / 4xWORD+BYTE / KE layout).
# ---------------------------------------------------------------------------
DIRECT_SCHEMAS: dict[str, dict] = {
    "pppColMove":   {"host": 0x75C480, "window_offset": 8, "window_width": 8,  "record_width": 32, "kind": "u16x4"},
    "pppColAccele": {"host": 0x75BB30, "window_offset": 8, "window_width": 8,  "record_width": 32, "kind": "u16x4"},
    "pppRandHCV":   {"host": 0x731F90, "window_offset": 8, "window_width": 9,  "record_width": 32, "kind": "u16x4_u8"},
    "pppSRandHCV":  {"host": 0x7337B0, "window_offset": 8, "window_width": 9,  "record_width": 32, "kind": "u16x4_u8"},
    "pppKeTh":      {"host": 0x736F50, "window_offset": 8, "window_width": 57, "record_width": 64, "kind": "keth"},
}
DIRECT_RAW_WIDTH = {"pppColMove": 8, "pppColAccele": 8, "pppRandHCV": 16, "pppSRandHCV": 16, "pppKeTh": 64}
# Walker placeholder window width: must satisfy the UsefulPppFamilySpec
# validator (8 + offset + width <= record_width). The REAL window is
# re-assigned after the walker runs (direct windows live at callback+8).
DIRECT_PLACEHOLDER_WIDTH = {"pppColMove": 8, "pppColAccele": 8, "pppRandHCV": 9, "pppSRandHCV": 9, "pppKeTh": 48}

EFFECTS = (
    {"effect_id": "0021", "dll": "magic_0021.dll", "yonishi": "mag_0021"},
    {"effect_id": "0098", "dll": "magic_0098.dll", "yonishi": "mag_0098"},
)

U1_NAMES = tuple(U1_PROVEN_SCHEMAS)
DIRECT_NAMES = tuple(DIRECT_SCHEMAS)
ALL_FAMILIES = U1_NAMES + DIRECT_NAMES


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


# ---------------------------------------------------------------------------
# Deterministic replacements (per family kind)
# ---------------------------------------------------------------------------

def make_replacement(family: str, window: bytes) -> bytes:
    if family in DIRECT_SCHEMAS:
        kind = DIRECT_SCHEMAS[family]["kind"]
    elif family in FLOAT4_FAMILIES:
        kind = "float4"
    else:
        kind = "int32x4"
    if kind == "float4":
        vals = struct.unpack("<4f", window)
        return struct.pack("<4f", *[(v * 2.0) if v != 0.0 else 1.0 for v in vals])
    if kind == "int32x4":
        vals = struct.unpack("<4i", window)
        return struct.pack("<4i", *[v + 1 for v in vals])
    if kind == "u16x4":
        vals = struct.unpack("<4H", window)
        return struct.pack("<4H", *[(v * 2 + 1) & 0xFFFF for v in vals])
    if kind == "u16x4_u8":
        vals = struct.unpack("<4H", window[:8])
        tail = (window[8] + 1) & 0xFF
        return struct.pack("<4HB", *[(v * 2 + 1) & 0xFFFF for v in vals], tail)
    if kind == "keth":
        return bytes((b + 1) & 0xFF for b in window)
    raise ValueError(f"unknown family kind: {family}")


# ---------------------------------------------------------------------------
# Generic window-aware dry-run / apply / restore for direct families
# (same contract as useful_ppp_writer, variable window width)
# ---------------------------------------------------------------------------

def _backup_path(target: Path) -> Path:
    generic = target.with_suffix(".dll.usefulppp.bak")
    legacy = target.with_suffix(".dll.sclmove.bak")
    return generic if generic.exists() or not legacy.exists() else legacy


def _write_atomically(path: Path, data: bytes) -> None:
    last: Exception | None = None
    for attempt in range(6):
        tmp_path: Path | None = None
        try:
            with tempfile.NamedTemporaryFile(dir=path.parent, prefix=f".{path.name}.", suffix=".tmp", delete=False) as tmp:
                tmp.write(data)
                tmp_path = Path(tmp.name)
            try:
                os.replace(tmp_path, path)
            finally:
                if tmp_path is not None:
                    tmp_path.unlink(missing_ok=True)
            return
        except PermissionError as exc:
            last = exc
            time.sleep(0.4 + 0.25 * attempt)
    if last is not None:
        raise last


def _retry_call(fn, *args, attempts: int = 5, **kwargs):
    """Retry module-level writers on transient WinError 5 (external scanner /
    concurrent process touching the disposable copy)."""
    last: Exception | None = None
    for i in range(attempts):
        try:
            return fn(*args, **kwargs)
        except PermissionError as exc:
            last = exc
            time.sleep(0.35 * (i + 1))
    if last is not None:
        raise last


def _direct_patched_bytes(target: Path, cand: UsefulPppCandidate, expected_record_sha: str,
                          replacement: bytes) -> tuple[bytes, tuple[int, ...], str]:
    if len(replacement) != cand.runtime_operand_width:
        raise ValueError(f"{cand.opcode_name} replacement must be exactly {cand.runtime_operand_width} bytes")
    dll = target.read_bytes()
    section = overlay.parse_pe_data_section(dll)
    if section is None:
        raise ValueError("target DLL has no readable .data section")
    record_width = DIRECT_SCHEMAS[cand.opcode_name]["record_width"]
    record_start = cand.callback_record_offset
    record_end = record_start + record_width
    if sha256(section.bytes[record_start:record_end]) != expected_record_sha:
        raise ExpectedPppRecordHashMismatchError(f"{cand.opcode_name} callback record hash mismatch")
    window_start = cand.runtime_operand_offset
    window_end = window_start + cand.runtime_operand_width
    if window_start < record_start or window_end > len(section.bytes):
        raise ValueError(f"{cand.opcode_name} runtime window is outside the .data section")
    file_start = section.raw_ptr + window_start
    file_end = section.raw_ptr + window_end
    patched = bytearray(dll)
    patched[file_start:file_end] = replacement
    changed = tuple(i for i, (before, after) in enumerate(zip(dll, patched)) if before != after)
    if not set(changed).issubset(set(range(file_start, file_end))):
        raise RuntimeError(f"{cand.opcode_name} patch changed bytes outside runtime window")
    patched_section = overlay.parse_pe_data_section(bytes(patched))
    if patched_section is None:
        raise RuntimeError("patched DLL lost its .data section")
    return (
        bytes(patched),
        tuple(i - section.raw_ptr for i in changed),
        sha256(patched_section.bytes[record_start:record_end]),
    )


def direct_dry_run(target: Path, cand: UsefulPppCandidate, expected_record_sha: str,
                   replacement: bytes) -> dict:
    _, changed, patched_hash = _direct_patched_bytes(target, cand, expected_record_sha, replacement)
    return {"backup_path": None, "changed": changed, "record_sha256": patched_hash,
            "callback_record_offset": cand.callback_record_offset,
            "record_width": DIRECT_SCHEMAS[cand.opcode_name]["record_width"], "restored": False}


def direct_apply(target: Path, cand: UsefulPppCandidate, expected_record_sha: str,
                 replacement: bytes) -> dict:
    original = target.read_bytes()
    patched, changed, patched_hash = _direct_patched_bytes(target, cand, expected_record_sha, replacement)
    backup = _backup_path(target)
    if backup.exists() and backup.read_bytes() != original:
        raise ValueError("useful PPP backup exists with different bytes")
    if not backup.exists():
        _write_atomically(backup, original)
    _write_atomically(target, patched)
    return {"backup_path": backup, "changed": changed, "record_sha256": patched_hash,
            "callback_record_offset": cand.callback_record_offset,
            "record_width": DIRECT_SCHEMAS[cand.opcode_name]["record_width"], "restored": False}


def direct_restore(target: Path, result: dict, expected_original_record_sha: str) -> dict:
    backup = result["backup_path"]
    if backup is None or not backup.exists():
        raise ValueError("useful PPP backup is missing")
    current = target.read_bytes()
    backup_bytes = backup.read_bytes()
    section = overlay.parse_pe_data_section(current)
    original_section = overlay.parse_pe_data_section(backup_bytes)
    if section is None or original_section is None:
        raise ValueError("backup or target has no readable .data section")
    record_width = result["record_width"]
    record_start = result["callback_record_offset"]
    if sha256(section.bytes[record_start:record_start + record_width]) != result["record_sha256"]:
        raise ExpectedPppRecordHashMismatchError("patched useful PPP callback record hash mismatch")
    if sha256(original_section.bytes[record_start:record_start + record_width]) != expected_original_record_sha:
        raise ExpectedPppRecordHashMismatchError("useful PPP backup record hash mismatch")
    _write_atomically(target, backup_bytes)
    return {**result, "restored": True}


# ---------------------------------------------------------------------------
# Candidate enumeration
# ---------------------------------------------------------------------------

def manifest_candidate_to_obj(family: str, entry: dict) -> UsefulPppCandidate:
    schema = U1_PROVEN_SCHEMAS[family]
    cb = int(entry["callback_record_offset"], 16)
    ro = int(entry["runtime_operand_offset"], 16)
    return UsefulPppCandidate(
        opcode_name=family,
        handler_index=int(entry["handler_index"]),
        section_offset=0,
        program_offset=int(entry.get("program_offset", "0x0"), 16),
        slot_offset=int(entry.get("slot_offset", "0x0"), 16),
        callback_record_offset=cb,
        raw_payload_offset=cb + 8,
        raw_payload_width=schema.raw_payload_width,
        runtime_operand_offset=ro,
        runtime_operand_width=schema.runtime_operand_width,
        record_sha256=entry["record_sha256"],
    )


def walker_candidates(section_bytes: bytes, family: str, handler_index: int,
                      ) -> tuple[list[UsefulPppCandidate], list[str]]:
    """C1 walker via select_useful_ppp_candidates; re-assigns the real window
    (callback + 8) for direct families (the module spec keeps the U1
    convention raw_payload+8, which differs for direct windows)."""
    spec = UsefulPppFamilySpec(
        opcode_name=family,
        handler_index=handler_index,
        raw_payload_width=DIRECT_RAW_WIDTH[family],
        runtime_operand_offset=8,
        runtime_operand_width=DIRECT_PLACEHOLDER_WIDTH[family],
        callback_record_width=DIRECT_SCHEMAS[family]["record_width"],
    )
    selection = select_useful_ppp_candidates(section_bytes, spec)
    record_width = DIRECT_SCHEMAS[family]["record_width"]
    adjusted = []
    for cand in selection.candidates:
        adjusted.append(UsefulPppCandidate(
            opcode_name=cand.opcode_name,
            handler_index=cand.handler_index,
            section_offset=cand.section_offset,
            program_offset=cand.program_offset,
            slot_offset=cand.slot_offset,
            callback_record_offset=cand.callback_record_offset,
            raw_payload_offset=cand.raw_payload_offset,
            raw_payload_width=cand.raw_payload_width,
            runtime_operand_offset=cand.callback_record_offset + DIRECT_SCHEMAS[family]["window_offset"],
            runtime_operand_width=DIRECT_SCHEMAS[family]["window_width"],
            record_sha256=sha256(section_bytes[cand.callback_record_offset:cand.callback_record_offset + record_width]),
        ))
    return adjusted, [r.reason for r in selection.rejections]


def load_manifest(effect_id: str) -> dict:
    with open(MANIFESTS / f"magic_{effect_id}.json", encoding="utf-8") as fh:
        return json.load(fh)


def load_yonishi_dispatch(effect: dict) -> dict:
    h_path = YONISHI_ROOT / effect["yonishi"] / "par" / "fp.h"
    if not h_path.exists():
        h_path = YONISHI_ROOT / effect["yonishi"] / "fp.h"
    entries = parse_yonishi_header(h_path)
    if entries is None:
        return {}
    return {e.opcode_name: e.handler_index for e in entries}


def enumerate_family_candidates(family: str, effect: dict, manifest: dict, section: object,
                                dispatch: dict) -> tuple[list[UsefulPppCandidate], str]:
    """Returns (candidates, source) where source describes provenance:
    'manifest' or 'walker' or 'no_candidates'."""
    if family in U1_NAMES:
        fam = manifest.get("families", {}).get(family)
        if fam is None or not fam.get("present") or not fam.get("candidates"):
            return [], "no_candidates"
        cands = [manifest_candidate_to_obj(family, e) for e in fam["candidates"]]
        return cands, "manifest"
    # direct families: walker C1, needs a proven effect-local handler index
    if family not in dispatch:
        return [], "no_candidates"
    cands, _ = walker_candidates(section.bytes, family, dispatch[family])
    return cands, "walker"


def _record_width_for(family: str) -> int:
    if family in DIRECT_SCHEMAS:
        return DIRECT_SCHEMAS[family]["record_width"]
    return U1_PROVEN_SCHEMAS[family].callback_record_width


def run_candidate(family: str, copy_path: Path, cand: UsefulPppCandidate,
                  original_file_sha: str, section_bytes: bytes) -> dict:
    """Full T3 cycle for one candidate on the disposable copy:
    dry-run -> apply -> verify -> restore -> verify byte-identical."""
    entry: dict = {
        "index": 0,
        "callback_record_offset": hex(cand.callback_record_offset),
        "runtime_operand_offset": hex(cand.runtime_operand_offset),
        "runtime_operand_width": cand.runtime_operand_width,
        "record_width": _record_width_for(family),
        "handler_index": cand.handler_index,
        "record_sha256_before": cand.record_sha256,
    }
    rec_w = _record_width_for(family)
    window = section_bytes[cand.runtime_operand_offset:cand.runtime_operand_offset + cand.runtime_operand_width]
    entry["window_hex_before"] = window.hex()
    replacement = make_replacement(family, window)
    entry["replacement_hex"] = replacement.hex()
    assert len(replacement) == cand.runtime_operand_width, "replacement width mismatch"

    # ---- dry-run (no write) -------------------------------------------------
    if family in FLOAT4_FAMILIES:
        dry = dry_run_vector(copy_path, cand, cand.record_sha256, replacement)
        changed = dry.changed_offsets
        dry_patched_hash = dry.record_sha256
    elif family in INT32_FAMILIES:
        deltas = AngularDeltas(*struct.unpack("<4i", replacement))
        dry = dry_run_angular_move(copy_path, cand, cand.record_sha256, deltas)
        changed = dry.changed_offsets
        dry_patched_hash = dry.record_sha256
    else:
        dry = direct_dry_run(copy_path, cand, cand.record_sha256, replacement)
        changed = dry["changed"]
        dry_patched_hash = dry["record_sha256"]
    entry["record_sha256_after_dryrun"] = dry_patched_hash
    entry["changed_offsets"] = [hex(c) for c in changed]
    entry["changed_offsets_count"] = len(changed)

    # diff confinement: every changed byte must sit inside the window
    ws = cand.runtime_operand_offset
    we = ws + cand.runtime_operand_width
    confined = all(ws <= c < we for c in changed)
    entry["diff_confined_to_window"] = confined
    entry["window_section_range"] = [hex(ws), hex(we)]

    # ---- apply on the copy --------------------------------------------------
    if family in FLOAT4_FAMILIES:
        res = _retry_call(apply_vector, copy_path, cand, cand.record_sha256, replacement)
        backup = res.backup_path
    elif family in INT32_FAMILIES:
        deltas = AngularDeltas(*struct.unpack("<4i", replacement))
        res = _retry_call(apply_angular_move, copy_path, cand, cand.record_sha256, deltas)
        backup = res.backup_path
    else:
        res = direct_apply(copy_path, cand, cand.record_sha256, replacement)
        backup = res["backup_path"]
    patched_file_sha = sha256(copy_path.read_bytes())
    entry["file_sha256_patched"] = patched_file_sha
    entry["record_sha256_after_apply"] = res.record_sha256 if hasattr(res, "record_sha256") else res["record_sha256"]
    entry["apply_record_hash_matches_dryrun"] = (
        entry["record_sha256_after_apply"] == entry["record_sha256_after_dryrun"]
    )
    # byte-level diff between original and patched file (section-relative)
    patched_section = overlay.parse_pe_data_section(copy_path.read_bytes())
    patched_record = patched_section.bytes[cand.callback_record_offset:cand.callback_record_offset + rec_w]
    entry["record_sha256_actual_after_apply"] = sha256(patched_record)

    # ---- restore on the copy ------------------------------------------------
    if family in FLOAT4_FAMILIES or family in INT32_FAMILIES:
        _retry_call(restore_vector, copy_path, res, cand.record_sha256)
    else:
        direct_restore(copy_path, res, cand.record_sha256)
    restored_file_sha = sha256(copy_path.read_bytes())
    entry["file_sha256_restored"] = restored_file_sha
    entry["restore_byte_identical"] = restored_file_sha == original_file_sha
    entry["restore_record_sha"] = cand.record_sha256

    entry["t3_pass"] = bool(
        confined
        and entry["apply_record_hash_matches_dryrun"]
        and entry["restore_byte_identical"]
        and patched_file_sha != original_file_sha
    )
    return entry


# ---------------------------------------------------------------------------
# Orchestration
# ---------------------------------------------------------------------------

STEAM_MAGIC_DIR = Path(r"D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\magicFiles\FFX")


def ensure_pristine_copy(effect: dict) -> Path:
    """Re-materialize the disposable copy from the Steam tree when missing or
    diverged (never writes into the Steam tree)."""
    src = STEAM_MAGIC_DIR / effect["dll"]
    copy_path = COPIES / effect["dll"]
    if not copy_path.exists() or sha256(copy_path.read_bytes()) != sha256(src.read_bytes()):
        copy_path.write_bytes(src.read_bytes())
    for stale in COPIES.glob(effect["dll"].replace(".dll", "") + "*.bak"):
        stale.unlink(missing_ok=True)
    return copy_path


def process_effect(effect: dict) -> dict:
    copy_path = ensure_pristine_copy(effect)
    dll_bytes = copy_path.read_bytes()
    section = overlay.parse_pe_data_section(dll_bytes)
    if section is None:
        raise ValueError(f"{effect['dll']} has no .data section")
    original_file_sha = sha256(dll_bytes)
    manifest = load_manifest(effect["effect_id"])
    dispatch = load_yonishi_dispatch(effect)
    fams: dict[str, dict] = {}
    for family in ALL_FAMILIES:
        candidates, source = enumerate_family_candidates(family, effect, manifest, section, dispatch)
        record = {
            "effect_id": effect["effect_id"],
            "dll": effect["dll"],
            "family": family,
            "candidate_source": source,
            "candidate_count": len(candidates),
            "candidates": [],
            "t3_pass": None,
            "error": None,
        }
        if source == "no_candidates":
            fams[family] = record
            continue
        try:
            for idx, cand in enumerate(candidates):
                entry = run_candidate(family, copy_path, cand, original_file_sha, section.bytes)
                entry["index"] = idx
                record["candidates"].append(entry)
            record["t3_pass"] = all(e["t3_pass"] for e in record["candidates"])
        except Exception as exc:  # noqa: BLE001 — keep batch alive, report
            record["error"] = f"{type(exc).__name__}: {exc}"
            record["t3_pass"] = False
        # safety: copy must be byte-identical to the pristine original again
        if sha256(copy_path.read_bytes()) != original_file_sha:
            ensure_pristine_copy(effect)
        final_sha = sha256(copy_path.read_bytes())
        record["copy_final_sha256"] = final_sha
        record["copy_pristine"] = final_sha == original_file_sha
        fams[family] = record
    return {
        "effect_id": effect["effect_id"],
        "dll": effect["dll"],
        "file_sha256_original": original_file_sha,
        "data_section_raw_ptr": hex(section.raw_ptr),
        "data_section_size": hex(section.raw_size),
        "families": fams,
    }



def main() -> int:
    WORK.mkdir(parents=True, exist_ok=True)
    results = {}
    all_rows = []
    for effect in EFFECTS:
        results[effect["effect_id"]] = process_effect(effect)
        for family, rec in results[effect["effect_id"]]["families"].items():
            evidence_path = WORK / f"T3_EVIDENCE_{family}_{effect['effect_id']}.json"
            evidence_path.write_text(json.dumps(rec, indent=2) + "\n", encoding="utf-8")
            all_rows.append((effect["effect_id"], family, rec))

    # summary markdown
    lines = [
        "# T3 Batch Summary — 2026-07-31 (copy-only, offline)",
        "",
        "Pipeline T3 copy-only em cópias descartáveis (`work/t3_batch/copies/`).",
        "Nenhum arquivo do jogo foi tocado; nenhum commit foi feito.",
        "",
        "## Cobertura por família × efeito",
        "",
        "| Família | Efeito | Origem candidatos | Candidatos | T3 |",
        "|---|---|---|---|---|",
    ]
    for effect_id, family, rec in all_rows:
        status = "PASS" if rec["t3_pass"] else ("n/a (sem candidatos)" if rec["t3_pass"] is None else "FAIL")
        lines.append(f"| {family} | {effect_id} | {rec['candidate_source']} | {rec['candidate_count']} | {status} |")
    lines.append("")
    lines.append("## Totais")
    total_candidates = sum(r["candidate_count"] for _, _, r in all_rows)
    passed = sum(1 for _, _, r in all_rows if r["t3_pass"])
    no_cand = sum(1 for _, _, r in all_rows if r["t3_pass"] is None)
    lines.append(f"- Famílias×efeitos cobertos: {len(all_rows)}")
    lines.append(f"- Candidatos T3 processados: {total_candidates}")
    lines.append(f"- Combinações família×efeito PASS: {passed}")
    lines.append(f"- Combinações sem candidatos (registradas): {no_cand}")
    lines.append("")
    lines.append("## SHAs de exemplo (originais das cópias)")
    for effect_id, result in results.items():
        lines.append(f"- {result['dll']} SHA256: `{result['file_sha256_original']}`")
    for effect_id, result in results.items():
        for family, rec in result["families"].items():
            if rec["candidates"]:
                first = rec["candidates"][0]
                lines.append(
                    f"- {family}/{effect_id}: record before `{first['record_sha256_before']}` "
                    f"after-dryrun `{first['record_sha256_after_dryrun']}` "
                    f"restore={first['restore_byte_identical']}"
                )
    lines.append("")
    lines.append("## Pendências (famílias sem candidatos nos manifests/fp.h)")
    for effect_id, family, rec in all_rows:
        if rec["t3_pass"] is None:
            lines.append(f"- {family} em {effect_id}: sem candidatos no manifest/fp.h do efeito.")
    (WORK / "T3_BATCH_SUMMARY_20260731.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
    # hygiene: drop stale backup artifacts and confirm pristine copies
    for effect in EFFECTS:
        for stale in COPIES.glob(effect["dll"].replace(".dll", "") + "*.bak"):
            stale.unlink(missing_ok=True)
    for effect in EFFECTS:
        copy_path = COPIES / effect["dll"]
        src = STEAM_MAGIC_DIR / effect["dll"]
        print(f"{effect['dll']}: copy pristine={sha256(copy_path.read_bytes()) == sha256(src.read_bytes())}")
    print(f"done: {total_candidates} candidates, {passed} family/effect PASS, {no_cand} no-candidates")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())




