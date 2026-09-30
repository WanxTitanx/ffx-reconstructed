#!/usr/bin/env python3
"""apply_resilient.py — finish renames + comments with crash recovery.

Strategy: small batches (150), periodic idb_save (every ~20 batches),
on connection failure -> restart server via vm_exec.sh, wait for health,
resume (idempotent via current-name check).
"""
import json, os, subprocess, sys, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from mcpc import Ida

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, "..", ".."))
VM_EXEC = os.path.join(REPO, "research_tools", "Vm", "vm_exec.sh")
plan = json.load(open(os.path.join(HERE, "rename_plan.json")))
STATE = os.path.join(HERE, "apply_state.json")

ida = None


def health():
    global ida
    try:
        ida = Ida()
        r = ida.call("server_health", {})
        return isinstance(r, dict) and r.get("status") == "ok"
    except Exception:
        return False


def restart_server():
    print("RESTARTING server via QGA...", flush=True)
    try:
        subprocess.run(["bash", VM_EXEC, "cmd /c C:\\IDA_DB\\mcp8745.bat", "10"],
                       timeout=60, capture_output=True)
    except Exception as e:
        print("vm_exec err", e, flush=True)
    for i in range(40):
        time.sleep(15)
        if health():
            print(f"server healthy after {(i+1)*15}s", flush=True)
            return True
    print("server never came back", flush=True)
    return False


def call(tool, payload, tries=8):
    for att in range(tries):
        try:
            return ida.call(tool, payload)
        except Exception as e:
            print(f"ERR {tool}: {e} (att {att})", flush=True)
            if att >= 2:
                if not health():
                    restart_server()
                else:
                    time.sleep(5)
            else:
                time.sleep(3)
    raise RuntimeError(f"{tool} failed after {tries}")


def save():
    r = call("idb_save", {})
    print("SAVED", json.dumps(r)[:200], flush=True)


def main():
    if not health():
        if not restart_server():
            sys.exit(3)

    # ---- renames ----
    ren = [p for p in plan if p.get("rename")]
    i = 0
    batches = 0
    while i < len(ren):
        # refresh current names for this page
        part = ren[i:i + 150]
        r = call("lookup_funcs",
                 {"queries": [hex(p["addr"]) for p in part]})
        todo = []
        for p, q in zip(part, r):
            fn = q.get("fn")
            if fn and fn["name"].startswith("sub_"):
                todo.append({"addr": hex(p["addr"]), "name": p["name"]})
        if todo:
            r2 = call("rename", {"batch": {"func": todo}})
            s = (r2 or {}).get("summary", {})
            if s.get("failed"):
                print(f"  batch@{i}: failed={s.get('failed')}", flush=True)
        i += 150
        batches += 1
        if batches % 20 == 0:
            save()
            print(f"rename progress {i}/{len(ren)}", flush=True)
    save()
    print("renames complete", flush=True)

    # ---- comments ----
    i = 0
    batches = 0
    while i < len(plan):
        part = plan[i:i + 150]
        call("set_comments", {"items": [{"addr": hex(p["addr"]),
                                         "comment": p["comment"]}
                                        for p in part]})
        i += 150
        batches += 1
        if batches % 20 == 0:
            save()
            print(f"comments progress {i}/{len(plan)}", flush=True)
    save()
    print("ALL DONE", flush=True)


if __name__ == "__main__":
    main()
