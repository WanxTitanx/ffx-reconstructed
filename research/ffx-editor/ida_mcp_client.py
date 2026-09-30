#!/usr/bin/env python3
"""ida_mcp_client.py — CANONICAL JSON-RPC client for the shared IDA MCP server.

CANONICAL CLIENT (Jarvis-MCP-CLIENT-RECONCILE, 2026-09-18): this is the single
entry point for the idalib/ida-pro-mcp server on the Windows VM
``windows11-dev-next`` — http://192.168.122.85:8745/mcp (zeromcp/1.3.0,
serverInfo ``ida-pro-mcp v1.0.0``, 65 tools, DB ``C:\\IDA_DB\\ffxoficial.exe.i64``).

Reconciled from the near-duplicate clients that lanes kept reinventing:
  * this file's original curl-based client   -> retry/backoff + text API (kept)
  * research_tools/Ida/mcp8745.py            -> urllib transport + generic rpc()
  * research_tools/Ida/ida_mcp.py            -> initialize -> mcp-session-id
                                              handshake + session reuse

Folded duplicates (now thin shims importing THIS module — do not add features
there): ``research_tools/Ida/mcp8745.py``, ``research_tools/Ida/ida_mcp.py``.
Legacy per-lane one-offs — folded 2026-09-18 (Jarvis-MCP-LEGACY): shims over
this client: ``Ida/mcp_call_vm.py``, ``Ida/mcp_ctb_tick.py``,
``Ppp/ppp_fine3/mcp.py``, ``Atel/eventflags_re/mcp.py``; lane-tool with
delegated transport: ``Ida/mcp_batch.py``; curl wrapper kept (live work/
callers): ``Ida/ida_mcp.sh``. Prefer this client for new work. Details:
``docs/reverse/FFX_MCP_LEGACY_FOLD_2026-09-18.md``.

NOTE — name collision: ``scripts/ida_mcp_client.py`` is a DIFFERENT client for
the ida-pro-mcp plugin inside a host-side IDA GUI (127.0.0.1:13337/13338, API
``call_tool(port, name, args)``). This file targets the VM server. Same basename
kept for stability — disambiguate by directory.

Server facts verified 2026-09-18 (live):
  * Replies plain JSON or SSE frames — both parsed.
  * Accepts stateless POSTs AND initialize->session-id handshake; handshake is
    ON by default (lazy, once per process) because the server issues
    ``Mcp-Session-Id`` and strict streamable-HTTP builds may require it.
  * Shared across lanes: ``server_health`` reports ``busy_tool``/``queued_calls``
    — hence retry/backoff on transport errors AND JSON-RPC errors.
  * No tool takes a ``database`` arg in this build (older idalib-mcp builds did);
    IDA_MCP_DATABASE is kept as an escape hatch only.

Env overrides:
  IDA_MCP_URL            endpoint (default http://192.168.122.85:8745/mcp)
  IDA_MCP_NO_HANDSHAKE   =1 -> stateless mode (skip initialize/session-id)
  IDA_MCP_DATABASE       inject ``database`` into every tool call's arguments
                         (only for server builds whose tools accept it)
  IDA_MCP_TIMEOUT        per-request timeout seconds (default 120)
  IDA_MCP_RETRIES        attempts per rpc()/call() (default 6)

Module API (stable):
  call(name, args, retries=6, timeout=None) -> str   tool text or 'ERROR: ...'
  call_raw(name, args, retries=6, timeout=None) -> dict   full JSON-RPC envelope
  rpc(method, params, rid=1, tries=None, timeout=None) -> dict   envelope
  post(payload, sess=None, timeout=None) -> (sid, body)   raw transport
      (same contract as the old Ida/ida_mcp.py: returns SSE-stripped body text)
  initialize() -> session-id str | None        explicit handshake
  tools_list() -> list[dict]
  ping() -> dict        server_health parsed result ({} on failure)
  selftest() -> bool    tools/list + server_health; prints a report

CLI:
  ida_mcp_client.py list | --list            list tool names + descriptions
  ida_mcp_client.py --selftest | --ping      harmless server_health ping
  ida_mcp_client.py <tool> ['<json-args>']   tools/call, prints text content
  ida_mcp_client.py --raw <tool> '<json>'    print the full JSON-RPC envelope
  flags (any position): --url URL  --no-handshake  --timeout SEC  --retries N
"""
import json
import os
import sys
import time
import urllib.error
import urllib.request

URL = os.environ.get("IDA_MCP_URL", "http://192.168.122.85:8745/mcp")
HDRS = {"Content-Type": "application/json",
        "Accept": "application/json, text/event-stream"}
PROTOCOL_VERSION = "2025-03-26"   # matches what the working per-lane copies sent
CLIENT_NAME = "ida-mcp-client"
CLIENT_VERSION = "2.0"            # reconciled canonical client

_DEFAULT_TIMEOUT = float(os.environ.get("IDA_MCP_TIMEOUT", "120"))
_DEFAULT_RETRIES = int(os.environ.get("IDA_MCP_RETRIES", "6"))
_NO_HANDSHAKE = os.environ.get("IDA_MCP_NO_HANDSHAKE", "").strip() in ("1", "true", "yes")
_DATABASE = os.environ.get("IDA_MCP_DATABASE", "").strip()

# ── Session state (lazy initialize -> mcp-session-id reuse) ────────────────
# WHY: the server hands out Mcp-Session-Id on initialize and strict builds may
# reject sessionless calls. One handshake per process; _SESSION_ID stays None
# on stateless/tolerant servers and everything still works.
_SESSION_ID = None
_HANDSHAKE_TRIED = False


def post(payload, sess=None, timeout=None):
    """Raw transport: POST one JSON-RPC payload, return (session_id, body_text).

    Same contract as the legacy Ida/ida_mcp.py ``post``: the body has SSE
    framing stripped (``data:`` payloads + non-event lines joined by newlines),
    so ``json.loads(body)`` works for normal replies. Raises urllib errors on
    transport failure — callers that want retries use rpc()/call().
    """
    h = dict(HDRS)
    if sess:
        h["mcp-session-id"] = sess
    req = urllib.request.Request(URL, data=json.dumps(payload).encode(), headers=h)
    resp = urllib.request.urlopen(req, timeout=timeout or _DEFAULT_TIMEOUT)
    sid = resp.headers.get("mcp-session-id", sess)
    body = resp.read().decode("utf-8", "replace")
    # SSE-framed reply: keep data: payloads (and stray non-event lines, same as
    # the legacy post()); plain JSON reply passes through unchanged.
    out = []
    for line in body.splitlines():
        if line.startswith("data: "):
            out.append(line[6:])
        elif line.startswith("data:"):
            out.append(line[5:].strip())
        elif line and not line.startswith("event:") and not line.startswith(":"):
            out.append(line)
    return sid, "\n".join(out)


def initialize(timeout=None):
    """Do the initialize -> notifications/initialized handshake once.

    Returns the server-issued session id (or None when the server doesn't hand
    one out / handshake disabled). Safe to call repeatedly — caches the result.
    """
    global _SESSION_ID, _HANDSHAKE_TRIED
    if _NO_HANDSHAKE:
        return None
    if _HANDSHAKE_TRIED:
        return _SESSION_ID
    _HANDSHAKE_TRIED = True
    try:
        sid, _body = post(
            {"jsonrpc": "2.0", "id": 1, "method": "initialize",
             "params": {"protocolVersion": PROTOCOL_VERSION, "capabilities": {},
                        "clientInfo": {"name": CLIENT_NAME, "version": CLIENT_VERSION}}},
            timeout=timeout)
        _SESSION_ID = sid
        try:
            post({"jsonrpc": "2.0", "method": "notifications/initialized"},
                 _SESSION_ID, timeout=timeout)
        except Exception:
            pass  # notification has no response; a dropped one is harmless
    except Exception:
        _SESSION_ID = None  # server unreachable or stateless — rpc() retries anyway
    return _SESSION_ID


def _reset_session():
    """Drop the cached session id (e.g. after a 4xx on a stale session)."""
    global _SESSION_ID, _HANDSHAKE_TRIED
    _SESSION_ID = None
    _HANDSHAKE_TRIED = False


def _inject_database(name, args):
    # Only relevant for idalib-mcp builds whose tools take a `database` arg
    # (session/idb selector). The current ida-pro-mcp build has schemas with
    # additionalProperties:false and no such arg — so this is env-gated OFF by
    # default and skipped for session-management tools (same rule the old
    # Ida/mcp_call_vm.py used).
    if _DATABASE and isinstance(args, dict) and name not in ("idb_list", "idb_open"):
        args = dict(args)
        args.setdefault("database", _DATABASE)
    return args


def _parse_body(body):
    """Parse a (possibly multi-frame) stripped SSE body into a JSON-RPC dict.

    Multi-frame SSE replies (progress notifications + final result) arrive as
    several JSON lines; prefer the LAST object carrying result/error — earlier
    frames are notifications.
    """
    best = None
    for line in body.splitlines():
        line = line.strip()
        if not line.startswith("{"):
            continue
        try:
            d = json.loads(line)
        except Exception:
            continue
        if isinstance(d, dict) and ("result" in d or "error" in d):
            best = d
    if best is not None:
        return best
    try:
        d = json.loads(body)
        return d if isinstance(d, dict) else {"_raw": body[:4000]}
    except Exception:
        return {"_raw": body[:4000]}


def rpc(method, params, rid=1, tries=None, timeout=None):
    """Low-level JSON-RPC call with retry/backoff. Returns the envelope dict.

    Retries on transport errors, unparseable bodies and JSON-RPC ``error``
    responses (the server is shared — busy/queue states are transient).
    On exhaustion returns {"error": "rpc failed after N tries: ..."}.
    """
    global _SESSION_ID
    tries = tries or _DEFAULT_RETRIES
    last = None
    for i in range(tries):
        try:
            sess = initialize(timeout=timeout)
            sid, body = post({"jsonrpc": "2.0", "id": rid, "method": method,
                              "params": params}, sess, timeout=timeout)
            if sid and not _SESSION_ID:
                _SESSION_ID = sid  # adopt server-issued id even without handshake
            d = _parse_body(body)
            if "error" in d:
                last = "rpc error: %s" % json.dumps(d["error"])[:500]
                time.sleep(min(2 ** i, 20))
                continue
            res = d.get("result")
            if isinstance(res, dict) and res.get("isError"):
                return d  # deterministic tool failure (bad name/args) — don't retry
            if "result" in d or "_raw" not in d:
                return d
            last = "unparseable body: %s" % body[:200]
        except urllib.error.HTTPError as e:
            last = "HTTP %s %s" % (e.code, e.reason)
            if e.code in (400, 404) and _SESSION_ID:
                _reset_session()  # stale session id — re-handshake on next try
            if e.code in (401, 403):
                break  # auth problems won't heal by retrying
            time.sleep(min(2 ** i, 20))
        except Exception as e:
            last = "%s: %s" % (type(e).__name__, e)
            time.sleep(min(2 ** i, 20))
    return {"error": "rpc failed after %d tries: %s" % (tries, last)}


def _extract_text(d):
    """Envelope -> tool text content (joined text blocks), else compact JSON."""
    res = d.get("result", d)
    if isinstance(res, dict) and "content" in res:
        parts = [c.get("text", "") for c in res["content"]
                 if isinstance(c, dict) and c.get("type", "text") == "text"]
        if parts:
            return "\n".join(parts)
    # 200KB cap matches the legacy Ida/ida_mcp.py CLI (bulk dumps can be big).
    return json.dumps(res, ensure_ascii=False)[:200000]


def call_raw(name, args, retries=None, timeout=None):
    """tools/call returning the full JSON-RPC envelope dict."""
    return rpc("tools/call",
               {"name": name, "arguments": _inject_database(name, args or {})},
               rid=int(time.time()) % 100000, tries=retries, timeout=timeout)


def call(name, args, retries=None, timeout=None):
    """tools/call -> text content, or 'ERROR: ...' on failure.

    Original API of this file (kept stable): callers get printable text, never
    an exception for server-side/transport failures.
    """
    d = call_raw(name, args, retries=retries, timeout=timeout)
    if "result" in d:
        return _extract_text(d)
    return "ERROR: %s" % (d.get("error") or json.dumps(d)[:500])


def tools_list(retries=None):
    """tools/list -> [{'name':..., 'description':...}, ...] ([] on failure)."""
    d = rpc("tools/list", {}, tries=retries)
    res = d.get("result") or {}
    return res.get("tools", []) if isinstance(res, dict) else []


def ping(timeout=None):
    """Harmless health probe: calls server_health and parses the JSON payload.

    Returns {} when the server is unreachable — check the printed ERROR via
    selftest() for diagnostics.
    """
    txt = call("server_health", {}, retries=2, timeout=timeout or 15)
    if txt.startswith("ERROR:"):
        return {}
    try:
        return json.loads(txt)
    except Exception:
        return {"_text": txt}


def selftest(timeout=None):
    """Self-test: tools/list + server_health against the live endpoint.

    Prints a short report; returns True when both probes succeeded. Safe to run
    when the VM/server is down — reports connectivity cleanly.
    """
    ok = True
    print("endpoint   : %s" % URL)
    tools = tools_list(retries=2)
    if tools:
        print("tools/list : OK (%d tools)" % len(tools))
    else:
        ok = False
        print("tools/list : FAILED (server down or unreachable?)")
    health = ping(timeout=timeout)
    if health:
        print("health     : %s" % json.dumps(health, ensure_ascii=False))
    else:
        ok = False
        print("health     : FAILED (no answer — is mcp8745.bat running on the VM?)")
    print("selftest   : %s" % ("OK" if ok else "FAIL"))
    return ok


def _usage():
    print(__doc__.split("CLI:")[-1].strip())


def main(argv=None):
    argv = list(sys.argv[1:] if argv is None else argv)
    global URL, _NO_HANDSHAKE, _DEFAULT_TIMEOUT, _DEFAULT_RETRIES
    raw = False
    positional = []
    i = 0
    while i < len(argv):
        a = argv[i]
        if a == "--url" and i + 1 < len(argv):
            URL = argv[i + 1]; i += 2
        elif a == "--no-handshake":
            _NO_HANDSHAKE = True; i += 1
        elif a == "--timeout" and i + 1 < len(argv):
            _DEFAULT_TIMEOUT = float(argv[i + 1]); i += 2
        elif a == "--retries" and i + 1 < len(argv):
            _DEFAULT_RETRIES = int(argv[i + 1]); i += 2
        elif a == "--raw":
            raw = True; i += 1
        else:
            positional.append(a); i += 1

    if not positional:
        _usage()
        return 2
    cmd = positional[0]

    if cmd in ("--selftest", "--ping", "selftest", "ping"):
        return 0 if selftest() else 1
    if cmd in ("list", "--list", "tools"):
        for t in tools_list():
            print("-", t.get("name"), "|", (t.get("description") or "")[:80])
        return 0

    args = json.loads(positional[1]) if len(positional) > 1 else {}
    if raw:
        print(json.dumps(call_raw(cmd, args), indent=1, ensure_ascii=False))
    else:
        print(call(cmd, args))
    return 0


if __name__ == "__main__":
    sys.exit(main())
