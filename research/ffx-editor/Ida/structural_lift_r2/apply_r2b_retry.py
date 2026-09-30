#!/usr/bin/env python3
"""Structural-lift apply: verify current names -> rename -> append provenance comments -> re-verify."""
import json, os, re, sys, time, urllib.request

BASE = os.environ.get("IDA_MCP_URL", "http://192.168.122.85:8745/mcp")
ORIGIN = re.sub(r"/mcp$", "", BASE)
HDRS = {"Content-Type": "application/json", "Accept": "application/json, text/event-stream"}
OUT = "/home/wanderson/Documents/ffx-editor-main/work/_structural_r2"
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
                    "clientInfo":{"name":"structural-r2","version":"1.0"}}})
    post({"jsonrpc":"2.0","method":"notifications/initialized"})

def main():
    plan = [dict(zip(("addr","old","new","evidence","kind"), r))
            for r in json.load(open(f"{OUT}/rename_plan_r2b_retry.json"))]
    init()

    # 1. verify current names (never clobber a fresher name)
    cur = {}
    addrs = [p["addr"] for p in plan]
    for i in range(0, len(addrs), 50):
        for t in call("lookup_funcs", {"queries": addrs[i:i+50]}):
            try:
                for e in json.loads(t):
                    if e.get("fn"): cur[e["fn"]["addr"].lower()] = e["fn"]["name"]
            except Exception: pass
    todo, skipped = [], []
    for p in plan:
        a = p["addr"].lower()
        now = cur.get(a)
        if now is None: skipped.append((p["addr"], "lookup-miss"))
        elif now != p["old"]: skipped.append((p["addr"], f"drift now={now}"))
        else: todo.append(p)
    print(f"verified {len(todo)} / skipped {len(skipped)}", flush=True)
    for a,w in skipped[:40]: print("  SKIP", a, w)

    # 2. rename in batches of 25
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
                        else: fail.append(rr)
            except Exception:
                pass
        print(f"  renamed {min(i+25,len(todo))}/{len(todo)}", flush=True)
    print("rename ok:", ok, "fail:", len(fail), flush=True)

    # 3. provenance comments
    items = []
    for p in todo:
        if "MISLABEL_FIX" in p["kind"] or p["kind"].startswith("FIX_MISLABEL"):
            c = f"// MISLABEL-FIX: was {p['old']}; real role: {p['evidence']} [structural-r2 2026-09-16]"
        elif "MISLABEL" in p["kind"]:
            c = f"// was {p['old']} — position-corrected on {p['evidence']} [structural-r2 2026-09-16]"
        elif p["kind"] == "ATEL_NAMED_DEMOTE":
            c = f"// was {p['old']} — op-name unverifiable; demoted to funcspace positional on {p['evidence']} [structural-r2 2026-09-16]"
        elif "MISLABEL" in p["kind"] or "CATFIX" in p["kind"] or "FHFIX" in p["kind"] or "FIXSLOT" in p["kind"] or p["kind"]=="FIX_VALID":
            c = f"// was {p['old']} — corrected on {p['evidence']} [structural-r2 2026-09-16]"
        else:
            c = f"// was {p['old']} — upgraded on {p['evidence']} [structural-r2 2026-09-16]"
        items.append({"addr": p["addr"], "comment": c})
    for i in range(0, len(items), 25):
        for t in call("append_comments", {"items": items[i:i+25]}):
            pass
        print(f"  comments {min(i+25,len(items))}/{len(items)}", flush=True)

    # 4. re-verify
    after = {}
    for i in range(0, len(addrs), 50):
        for t in call("lookup_funcs", {"queries": addrs[i:i+50]}):
            try:
                for e in json.loads(t):
                    if e.get("fn"): after[e["fn"]["addr"].lower()] = e["fn"]["name"]
            except Exception: pass
    bad = [(p["addr"], p["new"], after.get(p["addr"].lower())) for p in todo
           if after.get(p["addr"].lower()) != p["new"]]
    print("post-verify mismatches:", len(bad))
    for b in bad[:30]: print("  MISMATCH", b)

    save_idb()
    json.dump({"renamed": [p["addr"] for p in todo],
               "skipped": skipped, "fail": fail, "post_mismatch": bad},
              open(f"{OUT}/rename_result_r2b_retry.json", "w"), indent=1)

def save_idb():
    for t in call("idb_save", {}):
        print("idb_save:", t[:200], flush=True)

if __name__ == "__main__":
    main()
