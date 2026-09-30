#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""textlay_siblings.py — Jarvis-TEXTLAYOUT-SIBLINGS rename manifest + apply/verify/CSV tool (2026-09-18).

Reusable research tool for the out-of-range `FFX_Save_*` → text-layout/menu-text
adjudication. It embeds the verified rename manifest (104 functions + 16 globals)
and can, against the canonical IDB MCP endpoint:

  * `apply`   — re-apply every rename (idempotent) in small batches;
  * `verify`  — read every addr/name back and report mismatches;
  * `csv`     — regenerate `docs/reverse/data/wave13/textlay_siblings.csv`;
  * `report`  — print the verdict summary.

Endpoint: `FFX_IDA_MCP` env var (default http://192.168.122.85:8745/mcp).
Depends only on `ida_mcp.py` (same folder) or falls back to an inline client.

  python3 textlay_siblings.py verify
  python3 textlay_siblings.py csv
"""
import csv
import json
import os
import sys

_HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, _HERE)
try:
    from ida_mcp import call  # noqa: E402
except Exception:  # standalone fallback
    import urllib.request
    MCP = os.environ.get("FFX_IDA_MCP", "http://192.168.122.85:8745/mcp")
    _sid = [None]

    def _post(payload):
        req = urllib.request.Request(
            MCP, data=json.dumps(payload).encode(),
            headers={"Content-Type": "application/json",
                     "Accept": "application/json, text/event-stream"})
        if _sid[0]:
            req.add_header("Mcp-Session-Id", _sid[0])
        with urllib.request.urlopen(req, timeout=120) as r:
            _sid[0] = _sid[0] or r.headers.get("Mcp-Session-Id")
            return r.read().decode()

    def call(tool, args=None):
        if _sid[0] is None:
            _post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                   "params": {"protocolVersion": "2024-11-05", "capabilities": {},
                              "clientInfo": {"name": "tls", "version": "1.0"}}})
            _post({"jsonrpc": "2.0", "method": "notifications/initialized"})
        body = _post({"jsonrpc": "2.0", "id": 2, "method": "tools/call",
                      "params": {"name": tool, "arguments": args or {}}})
        try:
            return json.loads(body)
        except json.JSONDecodeError:
            for line in reversed(body.splitlines()):
                if line.startswith("data:"):
                    return json.loads(line[5:].strip())
            raise


def _load_manifest():
    """Import the authoritative manifest kept beside the scratch dir."""
    for cand in (os.path.join(_HERE, "..", "work", "_textlay_siblings"),
                 os.path.join(_HERE, "..", "..", "work", "_textlay_siblings")):
        mp = os.path.join(cand, "manifest.py")
        if os.path.exists(mp):
            sys.path.insert(0, cand)
            import manifest  # noqa: E402
            return manifest.FUNCS, manifest.GLOBALS
    raise SystemExit("manifest.py not found; expected work/_textlay_siblings/manifest.py")


FUNCS, GLOBALS = _load_manifest()
CSV_PATH = os.path.join(_HERE, "..", "docs", "reverse", "data", "wave13",
                        "textlay_siblings.csv")


def cmd_apply(_):
    """Re-apply all renames (idempotent) in small batches."""
    B = 12
    funcs = [{"addr": a, "name": n} for a, _, n, _, _ in FUNCS]
    datas = [{"old": o, "new": n} for a, o, n, e in GLOBALS]
    for i in range(0, len(funcs), B):
        res = call("rename", {"batch": {"func": funcs[i:i + B]}})
        print(f"func batch {i//B}: applied")
    for i in range(0, len(datas), B):
        res = call("rename", {"batch": {"data": datas[i:i + B]}})
        print(f"data batch {i//B}: applied")
    print("done")


def cmd_verify(_):
    """Read back every rename; report mismatches."""
    bad = []
    for i in range(0, len(FUNCS), 15):
        chunk = FUNCS[i:i + 15]
        res = call("lookup_funcs", {"queries": [c[0] for c in chunk]})
        data = json.loads(res["result"]["content"][0]["text"])
        for it in data:
            a = it.get("addr") or it.get("query")
            fn = it.get("fn") or {}
            want = next((c[2] for c in chunk if c[0].lower() == str(a).lower()), None)
            if fn.get("name") != want:
                bad.append((a, want, fn.get("name")))
    for a, o, n, e in GLOBALS:
        res = call("entity_query", {"queries": {"kind": "names", "filter": n, "count": 5}})
        data = json.loads(res["result"]["content"][0]["text"])
        if not any(x.get("name") == n and x.get("addr", "").lower() == a.lower()
                   for x in data[0].get("data", [])):
            bad.append((a, o, n))
    print(f"verify: {len(FUNCS)} funcs + {len(GLOBALS)} globals -> {len(bad)} mismatches")
    for b in bad:
        print("  MISMATCH", b)
    return 1 if bad else 0


def cmd_csv(_):
    os.makedirs(os.path.dirname(CSV_PATH), exist_ok=True)
    with open(CSV_PATH, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["kind", "va", "old_name", "new_name", "verdict", "evidence"])
        for a, o, n, v, e in FUNCS:
            w.writerow(["func", a, o, n, v, e])
        for a, o, n, e in GLOBALS:
            w.writerow(["data", a, o, n, "TEXT-DATA", e])
    print("wrote", CSV_PATH)


def cmd_report(_):
    from collections import Counter
    fam = Counter(n.split("_")[1] if "_" in n else n for _, _, n, _, _ in FUNCS)
    verdict = Counter(v for _, _, _, v, _ in FUNCS)
    print(f"funcs={len(FUNCS)} globals={len(GLOBALS)}")
    print("verdicts:", dict(verdict))
    print("families:", dict(fam))


CMDS = {"apply": cmd_apply, "verify": cmd_verify, "csv": cmd_csv, "report": cmd_report}


def main(argv):
    if len(argv) < 2 or argv[1] not in CMDS:
        sys.stderr.write(__doc__)
        return 2
    fn = CMDS[argv[1]]
    rc = fn(argv[2:])
    return rc if isinstance(rc, int) else 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
