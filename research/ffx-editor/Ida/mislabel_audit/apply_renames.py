#!/usr/bin/env python3
"""Apply rename plan: verify current names, rename in batch, append MISLABEL-FIX comments."""
import json, os, re, sys, time, urllib.request

BASE = os.environ.get("IDA_MCP_URL", "http://192.168.122.85:8745/mcp")
ORIGIN = re.sub(r"/mcp$", "", BASE)
HDRS = {"Content-Type": "application/json", "Accept": "application/json, text/event-stream"}
_sess = None
_reqid = 0

def post(payload):
    global _sess
    h = dict(HDRS)
    if _sess: h["mcp-session-id"] = _sess
    req = urllib.request.Request(BASE, data=json.dumps(payload).encode(), headers=h)
    for attempt in range(5):
        try:
            resp = urllib.request.urlopen(req, timeout=300)
            sid = resp.headers.get("mcp-session-id")
            if sid: _sess = sid
            body = resp.read().decode()
            out = []
            for line in body.splitlines():
                if line.startswith("data: "): out.append(line[6:])
                elif line and not line.startswith("event:") and not line.startswith(":"):
                    out.append(line)
            return "\n".join(out)
        except Exception:
            if attempt == 4: raise
            time.sleep(2*(attempt+1))

def fetch_offload(url):
    if url.startswith("/"): url = ORIGIN + url
    return urllib.request.urlopen(url, timeout=300).read().decode()

def call(tool, args):
    global _reqid
    _reqid += 1
    body = post({"jsonrpc":"2.0","id":_reqid,"method":"tools/call",
                 "params":{"name":tool,"arguments":args}})
    try:
        d = json.loads(body)
        res = d.get("result", d)
        if isinstance(res, dict) and "content" in res:
            texts = [c.get("text","") for c in res["content"] if c.get("type")=="text"]
            out=[]
            for t in texts:
                m = re.search(r"curl -o \S+ (https?://\S+)", t)
                if m: t = fetch_offload(m.group(1))
                out.append(t)
            return out
    except Exception:
        pass
    return [body]

def init():
    post({"jsonrpc":"2.0","id":1,"method":"initialize",
          "params":{"protocolVersion":"2025-03-26","capabilities":{},
                    "clientInfo":{"name":"mislabel-apply","version":"1.0"}}})
    post({"jsonrpc":"2.0","method":"notifications/initialized"})

def main():
    plan = json.load(open("work/_mislabel_audit/rename_plan.json"))
    init()
    # 1. verify current names
    queries = [p["addr"] for p in plan]
    cur = {}
    for i in range(0, len(queries), 50):
        for t in call("lookup_funcs", {"queries": queries[i:i+50]}):
            try:
                d = json.loads(t)
                for e in d:
                    if e.get("fn"): cur[e["fn"]["addr"].lower()] = e["fn"]["name"]
            except Exception: pass
    todo = []
    skipped = []
    for p in plan:
        a = p["addr"].lower()
        now = cur.get(a)
        if now is None:
            skipped.append((p, "lookup-miss")); continue
        if now != p["old"]:
            skipped.append((p, f"name-drifted now={now}")); continue
        todo.append(p)
    print(f"verified: {len(todo)} to rename, {len(skipped)} skipped")
    for p, why in skipped:
        print("  SKIP", p["addr"], p["old"], why)

    # 2. rename in batches
    ok, fail = 0, []
    for i in range(0, len(todo), 25):
        batch = [{"addr": p["addr"], "name": p["new"]} for p in todo[i:i+25]]
        for t in call("rename", {"batch": {"func": batch}}):
            try:
                d = json.loads(t)
                results = d if isinstance(d, list) else d.get("results", d.get("data", []))
                for rr in results:
                    if isinstance(rr, dict):
                        if rr.get("ok") or rr.get("success") or (rr.get("error") in (None, "")):
                            ok += 1
                        else:
                            fail.append(rr)
            except Exception as e:
                print("  batch parse:", str(e)[:100], "| raw:", t[:200])
        print(f"  rename progress {min(i+25,len(todo))}/{len(todo)}", flush=True)

    # 3. comments
    items = [{"addr": p["addr"],
              "comment": f"// MISLABEL-FIX: was {p['old']}; real role: {p['evidence']} [Jarvis-DEVIN mislabel-audit 2026-09-16]"}
             for p in todo]
    for i in range(0, len(items), 25):
        for t in call("append_comments", {"items": items[i:i+25]}):
            pass
        print(f"  comments {min(i+25,len(items))}/{len(items)}", flush=True)

    json.dump({"renamed":[p["addr"] for p in todo],"skipped":[(p["addr"],w) for p,w in skipped],"fail":fail},
              open("work/_mislabel_audit/rename_result.json","w"), indent=1)
    print("renamed:", ok, "failed:", len(fail), "skipped:", len(skipped))

if __name__ == "__main__":
    main()
