#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""ida_mcp.py — DEPRECATED thin shim -> canonical `research_tools/ida_mcp_client.py`.

Jarvis-TEXTLAYOUT-SIBLINGS (2026-09-18) wrote this as a self-contained minimal
ida-pro-mcp client. Residual wave-13 (q) consolidated the MCP clients into the
canonical `ida_mcp_client.py` (urllib transport + SSE/plain-JSON + lazy
initialize/session-id handshake + retry/backoff). To stop client proliferation,
this file is now a **shim**: it preserves the `call(tool,args)` -> JSON-RPC
envelope contract used by `textlay_siblings.py` (and any other caller) and its
convenience CLI subcommands, delegating transport to the canonical client.

Prefer `ida_mcp_client.py` for new work. Env overrides live there
(`IDA_MCP_URL`, `IDA_MCP_NO_HANDSHAKE`, `IDA_MCP_TIMEOUT`, `IDA_MCP_RETRIES`,
`IDA_MCP_DATABASE`). The legacy `FFX_IDA_MCP` env var is honored below for
backward compatibility with this shim's original callers.

Library usage:
    from ida_mcp import call
    res = call("decompile", {"addr": "0x8DFD70"})
    code = res["result"]["content"][0]["text"]

CLI usage:
    python3 ida_mcp.py health | decompile <addr> | disasm <addr> | lookup <a>..
    python3 ida_mcp.py xrefs|callees <addr> | listfns '<pat>' [--max N] [--lo A] [--hi A]
    python3 ida_mcp.py rename <addr> <name> | renames renames.json | comment <addr> "note"
    python3 ida_mcp.py save | call <tool> '<json-args>'
"""
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ida_mcp_client as _c  # canonical client (owns transport/handshake/retry)

# Backward-compat: this shim's original env var wins if set.
if os.environ.get("FFX_IDA_MCP"):
    _c.URL = os.environ["FFX_IDA_MCP"]


def call(tool, args=None):
    """Call an MCP tool -> decoded JSON-RPC result/envelope dict.

    Delegates to the canonical `call_raw` (returns the full envelope). Emits a
    one-time DeprecationWarning so library callers know to move to
    `ida_mcp_client` directly.
    """
    import warnings
    warnings.warn("ida_mcp.call is deprecated; use ida_mcp_client.call_raw",
                  DeprecationWarning, stacklevel=2)
    return _c.call_raw(tool, args or {})


def _text(res):
    """Extract concatenated text from a tools/call result envelope."""
    out = res.get("result", res) if isinstance(res, dict) else res
    if isinstance(out, dict) and "content" in out:
        parts = []
        for c in out["content"]:
            parts.append(c["text"] if c.get("type") == "text" else json.dumps(c))
        return "\n".join(parts)
    return json.dumps(out, indent=1, ensure_ascii=False)


def _j(res):
    """Parse the tool's text payload as JSON (best effort)."""
    try:
        return json.loads(_text(res))
    except Exception:
        return None


# ── CLI subcommands (delegate via call() -> canonical transport) ───────────

def cmd_health(_):
    print(_text(call("server_health", {})))


def cmd_decompile(a):
    res = call("decompile", {"addr": a[0]})
    print(_j(res) or _text(res))


def cmd_disasm(a):
    print(_text(call("disasm", {"addr": a[0]})))


def cmd_lookup(addrs):
    print(_text(call("lookup_funcs", {"queries": addrs})))


def cmd_xrefs(a):
    print(_text(call("xrefs_to", {"addrs": [a[0]], "limit": 30})))


def cmd_callees(a):
    print(_text(call("callees", {"addrs": [a[0]], "limit": 30})))


def cmd_listfns(argv):
    pat = argv[0]
    lo = hi = None
    mx = 600
    i = 1
    while i < len(argv):
        if argv[i] == "--lo":
            lo = argv[i + 1]; i += 2
        elif argv[i] == "--hi":
            hi = argv[i + 1]; i += 2
        elif argv[i] == "--max":
            mx = int(argv[i + 1]); i += 2
        else:
            i += 1
    q = {"filter": pat, "count": mx}
    if lo:
        q["min_addr"] = lo
    if hi:
        q["max_addr"] = hi
    res = call("func_query", {"queries": q})
    data = _j(res)
    rows = (data[0].get("data") or data[0].get("functions")) if data else []
    for f in (rows or []):
        print(f.get("addr"), f.get("name"))
    print("total:", len(rows or []))


def cmd_rename(a):
    print(_text(call("rename", {"batch": {"func": [{"addr": a[0], "name": a[1]}]}})))


def cmd_renames(a):
    ops = json.load(open(a[0]))
    print(_text(call("rename", {"batch": {"func": ops}})))


def cmd_comment(a):
    print(_text(call("append_comments", {"items": [{"addr": a[0], "comment": a[1],
                                                    "scope": "func", "dedupe": True}]})))


def cmd_save(_):
    print(_text(call("idb_save", {})))


def cmd_call(a):
    print(_text(call(a[0], json.loads(a[1]) if len(a) > 1 else {})))


CMDS = {
    "health": cmd_health, "decompile": cmd_decompile, "disasm": cmd_disasm,
    "lookup": cmd_lookup, "xrefs": cmd_xrefs, "callees": cmd_callees,
    "listfns": cmd_listfns, "rename": cmd_rename, "renames": cmd_renames,
    "comment": cmd_comment, "save": cmd_save, "call": cmd_call,
}


def main(argv):
    if len(argv) < 2 or argv[1] not in CMDS:
        sys.stderr.write(__doc__)
        return 2
    import warnings
    warnings.simplefilter("ignore", DeprecationWarning)  # CLI: don't spam
    try:
        CMDS[argv[1]](argv[2:])
        return 0
    except Exception as e:  # noqa: BLE001 - CLI surface
        sys.stderr.write(f"error: {e}\n")
        return 1


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
