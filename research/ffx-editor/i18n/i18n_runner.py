#!/usr/bin/env python3
"""Run resumable i18n inference jobs with an explicitly selected route.

The historical Windows paths, 14-worker default, implicit Verboo provider and
implicit mimo-v2.5 model are intentionally gone. Paths now default to this
checkout's work directory, concurrency is capped at six, and --provider plus
--model are required. Failed records remain eligible for the next run. Existing
output must carry the same input/route fingerprint; legacy output needs a new
--output path instead of being silently trusted.
"""
from __future__ import annotations

import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
from types import SimpleNamespace
import sys
import threading


REPO = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(REPO / "scripts"))
import verboo_router as vr  # noqa: E402


# Adapted from the user-supplied FFX_AGENTS_Skills_2026-09-19 package
# (2026-09-19): use the public router API and explicit authorization. WHY:
# imports must never start a batch, and a failed incremental record must not
# suppress a later retry after the provider or input problem is corrected.
DEFAULT_INPUT = REPO / "work" / "i18n_jobs.jsonl"
DEFAULT_OUTPUT = REPO / "work" / "i18n_out.jsonl"


def parser() -> argparse.ArgumentParser:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--input", default=str(DEFAULT_INPUT), help="JSONL jobs (prompt or messages)")
    ap.add_argument("--output", default=str(DEFAULT_OUTPUT), help="append-only result JSONL")
    ap.add_argument("--provider", required=True, choices=[*vr.REMOTE, "ollama"])
    ap.add_argument("-m", "--model", required=True, help="exact model; never substituted")
    ap.add_argument("--allow-external", action="store_true",
                    help="acknowledge existing authorization for the selected remote provider")
    ap.add_argument("--api", choices=["chat", "responses"], default="chat")
    ap.add_argument("-t", "--max-tokens", type=vr.positive, default=9000)
    ap.add_argument("-c", "--concurrency", type=vr.positive, default=4,
                    help="parallel jobs, limited to 1..6")
    return ap


def paths_alias(first: Path, second: Path) -> bool:
    if first.expanduser().resolve(strict=False) == second.expanduser().resolve(strict=False):
        return True
    try:
        return first.exists() and second.exists() and first.samefile(second)
    except OSError:
        return False


def resume_fingerprint(route, jobs, endpoint: str) -> str:
    """Bind incremental results to normalized inputs and output-affecting route."""
    identity = {
        "schema": 1,
        "route": {
            "provider": route.provider,
            "model": route.model,
            "endpoint": endpoint,
            "api": route.api,
            "max_tokens": route.max_tokens,
        },
        "jobs": jobs,
    }
    encoded = json.dumps(
        identity, ensure_ascii=False, sort_keys=True, separators=(",", ":")
    ).encode("utf-8")
    return hashlib.sha256(encoded).hexdigest()


def _successful_jobs(path: Path, expected_fingerprint: str) -> set[int]:
    done: set[int] = set()
    if not path.exists():
        return done
    for line_number, line in enumerate(vr.read_text(str(path)).splitlines(), 1):
        if not line.strip():
            continue
        record = json.loads(line)
        if not isinstance(record, dict):
            raise ValueError(f"Output line {line_number} is not an object")
        fingerprint = record.get("resume_fingerprint")
        if not isinstance(fingerprint, str):
            raise ValueError(
                "Existing output has legacy records without resume_fingerprint; "
                "select a new --output path"
            )
        if fingerprint != expected_fingerprint:
            raise ValueError(
                "Existing output belongs to a different input or inference route; "
                "select a new --output path"
            )
        if record.get("ok") is True and isinstance(record.get("job"), int):
            done.add(record["job"])
    return done


def main(argv=None) -> int:
    args = parser().parse_args(argv)
    if args.concurrency > 6:
        print("ERROR: concurrency must be 1..6", file=sys.stderr)
        return 2
    route = SimpleNamespace(
        provider=args.provider,
        model=args.model,
        allow_external=args.allow_external,
        api=args.api,
        max_tokens=args.max_tokens,
    )
    try:
        # Authorization is checked before private job or prior-output files.
        endpoint, _ = vr.provider_config(
            route.provider, route.allow_external
        )
        input_path = Path(args.input)
        output_path = Path(args.output)
        if paths_alias(input_path, output_path):
            raise ValueError("--input and --output must identify different files")
        jobs = [
            vr.batch_messages(json.loads(line))
            for line in vr.read_text(str(input_path)).splitlines()
            if line.strip()
        ]
        fingerprint = resume_fingerprint(route, jobs, endpoint)
        done = _successful_jobs(output_path, fingerprint)
    except (ValueError, OSError, json.JSONDecodeError) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 2

    todo = [index for index in range(len(jobs)) if index not in done]
    print(f"resume: {len(done)} successful | {len(todo)} pending | total {len(jobs)}", flush=True)
    if not todo:
        return 0

    output_path.parent.mkdir(parents=True, exist_ok=True)
    lock = threading.Lock()

    def save(record):
        with lock:
            with output_path.open("a", encoding="utf-8") as stream:
                stream.write(json.dumps(record, ensure_ascii=False) + "\n")

    def run_one(index):
        try:
            result = vr.infer(route, jobs[index])
            record = {
                "job": index,
                "ok": True,
                "output": result["output"],
                "resume_fingerprint": fingerprint,
            }
            save(record)
            print(f"[{index}/{len(jobs)}] OK", flush=True)
            return True
        except (ValueError, RuntimeError, OSError, KeyError, TypeError):
            # Keep a failure record for diagnostics, but resume only trusts ok=true.
            save({
                "job": index,
                "ok": False,
                "error": "Inference failed; no fallback attempted",
                "resume_fingerprint": fingerprint,
            })
            print(f"[{index}/{len(jobs)}] ERR", flush=True)
            return False

    with ThreadPoolExecutor(max_workers=args.concurrency) as executor:
        results = list(executor.map(run_one, todo))
    return 0 if all(results) else 1


if __name__ == "__main__":
    raise SystemExit(main())
