#!/usr/bin/env python3
"""apply.py — apply [type-lift-r2] prototype edits + comments, then decompile-verify.

Signature format that works: "ret __cdecl NAME(args)" (name required by server).
"""
import json, sys, re
sys.path.insert(0, ".")
from mcpc import call
from edits_r2 import EDITS

BREAK_MARKERS = ("Decompilation failed", "decompilation failed", "__asm",
                 "BAD SP", "bad sp", "/* ERROR", "could not", "spoils",
                 "positive sp", "wrong sp")

def load_names():
    names = {}
    for fn in ("analysis.json", "analysis2.json"):
        try:
            for r in json.load(open(fn)):
                a = r.get("addr")
                if a:
                    names[a.lower()] = r.get("name")
        except Exception:
            pass
    return names

def build_sig(addr, sig, names):
    name = names.get(addr) or "sub_%s" % addr[2:]
    # insert name before the arg list: "void __cdecl(...)" -> "void __cdecl NAME(...)"
    m = re.match(r"^(.*?_*(?:cdecl|stdcall|fastcall|thiscall|usercall)\b[^()]*)\((.*)\)\s*$", sig)
    if not m:
        raise ValueError(f"unparseable sig {sig}")
    return f"{m.group(1)} {name}({m.group(2)})"

def main():
    names = load_names()
    addrs = [e[0] for e in EDITS]
    full = [(a, build_sig(a, s, names), note) for a, s, note in EDITS]
    json.dump([{"addr": a, "sig": s} for a, s, _ in full],
              open("applied_sigs.json", "w"), indent=1)

    print("== A: snapshotting old prototypes", flush=True)
    try:
        old = json.load(open("old_protos.json"))
    except Exception:
        old = {}
    missing = [a for a in addrs if a not in old]
    for i in range(0, len(missing), 40):
        chunk = missing[i:i+40]
        res = call("func_profile", {"queries": [{"addr": a, "include_prototype": True} for a in chunk]})
        arr = res if isinstance(res, list) else res.get("result") or []
        for pack in arr:
            for it in (pack.get("data") or []):
                a = (it.get("addr") or "").lower()
                if a and it.get("prototype"):
                    old[a] = it["prototype"]
        print(f"  snapshot {i+len(chunk)}/{len(missing)}", flush=True)
    json.dump(old, open("old_protos.json", "w"), indent=1)

    print("== B: type_apply_batch", flush=True)
    apply_res = {}
    for i in range(0, len(full), 15):
        chunk = full[i:i+15]
        edits = [{"addr": a, "signature": s} for a, s, _ in chunk]
        r = call("type_apply_batch", {"batch": {"edits": edits, "stop_on_error": False}})
        items = (r or {}).get("results") or []
        for it in items:
            a = (it.get("edit", {}).get("addr") or "").lower()
            apply_res[a] = {"ok": it.get("ok"), "error": it.get("error"), "sig": it.get("edit", {}).get("signature")}
        print(f"  chunk {i}: applied={r.get('applied')} failed={r.get('failed')}", flush=True)
        for it in items:
            if not it.get("ok"):
                print("    FAIL", it.get("edit", {}).get("addr"), it.get("error"), flush=True)

    print("== C: append_comments", flush=True)
    for i in range(0, len(EDITS), 30):
        chunk = EDITS[i:i+30]
        items = [{"addr": a, "comment": f"[type-lift-r2] {note}", "scope": "func", "dedupe": True}
                 for a, _, note in chunk]
        r = call("append_comments", {"items": items})
        print(f"  comments {i}: {str(r)[:140]}", flush=True)

    print("== D: decompile verify", flush=True)
    report = {}
    broken = []
    for j, (a, sig, note) in enumerate(full):
        try:
            r = call("decompile", {"addr": a, "include_addresses": False})
            if isinstance(r, dict):
                text = r.get("pseudocode") or r.get("code") or r.get("text") or json.dumps(r)
            else:
                text = str(r)
            bad = [m for m in BREAK_MARKERS if m in text]
            report[a] = {"ok": not bad, "markers": bad, "len": len(text)}
            if bad:
                broken.append(a)
                print(f"    BROKEN {a} {bad}", flush=True)
        except Exception as ex:
            report[a] = {"ok": False, "error": str(ex)[:200]}
            broken.append(a)
            print(f"    ERR {a} {str(ex)[:120]}", flush=True)
        if j % 20 == 0:
            print(f"  decompiled {j}/{len(full)} (broken: {len(broken)})", flush=True)

    out = {"apply": apply_res, "decompile": report, "broken": broken}
    json.dump(out, open("apply_results.json", "w"), indent=1)
    nfail = sum(1 for v in apply_res.values() if not v.get("ok"))
    print(f"\nDONE. edits={len(full)} apply_failed={nfail} broken={len(broken)}: {broken}", flush=True)

if __name__ == "__main__":
    main()
