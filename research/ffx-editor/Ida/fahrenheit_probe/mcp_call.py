#!/usr/bin/env python3
"""Cliente MCP HTTP (streamable) minimo para o ida-pro-mcp do IDA GUI.

Uso:
  python mcp_call.py tools                     # lista tools
  python mcp_call.py call <tool> <json-params> # chama uma tool
  python mcp_call.py exec <path.py>            # py_exec_file (script dentro do GUI)
  python mcp_call.py rename <addr> <name>      # rename global/funcao
  python mcp_call.py save                      # salva a db
  python mcp_call.py getname <addr>            # nome atual
"""
import json
import subprocess
import sys
import tempfile
from pathlib import Path

BASE = "http://127.0.0.1:13337/mcp"
SESSION = {}


def post(payload: dict, notify: bool = False) -> dict:
    tmp = Path(tempfile.gettempdir()) / "mcp_body.json"
    tmp.write_text(json.dumps(payload), encoding="utf-8")
    cmd = ["curl.exe", "-s", "-i", "-X", "POST", BASE,
           "-H", "Content-Type: application/json",
           "-H", "Accept: application/json"]
    if SESSION.get("id"):
        cmd += ["-H", f"mcp-session-id: {SESSION['id']}"]
    cmd += ["--data-binary", f"@{tmp}"]
    out = subprocess.run(cmd, capture_output=True, text=True, encoding="utf-8", errors="replace", timeout=60).stdout
    if "--debug" in sys.argv:
        print(f"[DEBUG] curl stdout: {out[:500]!r}", flush=True)
    head, _, body = out.partition("\r\n\r\n")
    if not body and "\n\n" in out:
        head, _, body = out.partition("\n\n")
    sid = None
    for line in head.splitlines():
        if line.lower().startswith("mcp-session-id:"):
            sid = line.split(":", 1)[1].strip()
    if sid:
        SESSION["id"] = sid
    body = body.strip()
    if not body or payload.get("id") is None:
        # notifications (sem "id") nao tem resposta; 202 "Accepted" e normal
        return {}
    if body.lstrip().startswith("event:"):
        out_d = None
        for line in body.splitlines():
            if line.startswith("data:"):
                out_d = json.loads(line[5:].strip())
        return out_d or {}
    try:
        return json.loads(body)
    except json.JSONDecodeError:
        print(f"[DEBUG] JSON invalido: {body[:300]}", flush=True)
        raise
    # 202 Accepted => resposta chega via GET no mesmo endpoint (MCP Streamable HTTP)
    if status == 202 or (not raw.strip() and status >= 200):
        raw = http_get()
    if not raw.strip():
        print(f"[DEBUG] resposta vazia (status={status}) para {payload.get('method')}", flush=True)
        return {}
    if raw.lstrip().startswith("event:"):
        out = None
        for line in raw.splitlines():
            if line.startswith("data:"):
                out = json.loads(line[5:].strip())
        return out or {}
    try:
        return json.loads(raw)
    except json.JSONDecodeError as exc:
        print(f"[DEBUG] JSON invalido (status={status}): {raw[:400]}", flush=True)
        raise


def http_get() -> str:
    headers = {"Accept": "application/json, text/event-stream"}
    if SESSION.get("id"):
        headers["mcp-session-id"] = SESSION["id"]
    req = urllib.request.Request(BASE, headers=headers, method="GET")
    try:
        with urllib.request.urlopen(req, timeout=30) as resp:
            return resp.read().decode("utf-8", errors="replace")
    except urllib.error.HTTPError as exc:
        return exc.read().decode("utf-8", errors="replace")


def rpc(method: str, params: dict, _id: int = 1) -> dict:
    return post({"jsonrpc": "2.0", "id": _id, "method": method, "params": params})


def ensure_session() -> None:
    if not SESSION.get("id"):
        rpc("initialize", {"protocolVersion": "2024-11-05", "capabilities": {},
                           "clientInfo": {"name": "jarvis-cline", "version": "1.0"}})
        post({"jsonrpc": "2.0", "method": "notifications/initialized"})


def unwrap(resp: dict):
    if "result" in resp:
        return resp["result"]
    return resp


def main() -> int:
    cmd = sys.argv[1] if len(sys.argv) > 1 else "tools"
    ensure_session()
    if cmd == "tools":
        r = unwrap(rpc("tools/list", {}))
        for t in r.get("tools", []):
            print(t.get("name"))
        print(f"TOTAL_TOOLS={len(r.get('tools', []))}")
    elif cmd == "call":
        tool = sys.argv[2]
        params = json.loads(sys.argv[3]) if len(sys.argv) > 3 else {}
        print(json.dumps(unwrap(rpc("tools/call", {"name": tool, "arguments": params})), indent=1, ensure_ascii=False)[:4000])
    elif cmd == "exec":
        path = sys.argv[2]
        print(json.dumps(unwrap(rpc("tools/call", {"name": "py_exec_file", "arguments": {"file_path": path}})), indent=1, ensure_ascii=False)[:4000])
    elif cmd == "rename":
        addr, name = sys.argv[2], sys.argv[3]
        r = unwrap(rpc("tools/call", {"name": "rename", "arguments": {"batch": {"globals": [{"addr": addr, "name": name}]}}}))
        print(json.dumps(r, indent=1, ensure_ascii=False)[:2000])
    elif cmd == "save":
        print(json.dumps(unwrap(rpc("tools/call", {"name": "save_database", "arguments": {}})), indent=1, ensure_ascii=False)[:2000])
    elif cmd == "getname":
        addr = sys.argv[2]
        r = unwrap(rpc("tools/call", {"name": "get_global", "arguments": {"addr": addr}}))
        print(json.dumps(r, indent=1, ensure_ascii=False)[:2000])
    else:
        print(f"comando desconhecido: {cmd}")
        return 2
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except Exception as exc:  # noqa: BLE001
        print(f"ERRO: {exc}")
        sys.exit(1)
