#!/usr/bin/env python3
"""disasm_chunks.py — disasm every NONPAD orphan chunk (batched insn_query).
Output chunk_disasm.jsonl: {s, span, insns:[[addr,disasm],...]}
"""
import json, os, sys, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from mcpc import Ida

HERE = os.path.dirname(os.path.abspath(__file__))
chunks = {}
for l in open(os.path.join(HERE, "chunk_bytes2.jsonl")):
    d = json.loads(l)
    if d["cls"] == "NONPAD":
        chunks[d["s"]] = d["span"]
items = sorted(chunks.items())
OUT = os.path.join(HERE, "chunk_disasm.jsonl")
BATCH = 40


def main():
    ida = Ida()
    done = 0
    if os.path.exists(OUT):
        done = sum(1 for _ in open(OUT))
    fh = open(OUT, "a")
    i = done
    t0 = time.time()
    while i < len(items):
        part = items[i:i + BATCH]
        qs = [{"start": hex(s), "end": hex(s + span), "count": 2000,
               "include_disasm": True} for s, span in part]
        for attempt in range(4):
            try:
                r = ida.call("insn_query", {"queries": qs})
                break
            except Exception as ex:
                print(f"ERR @{i}: {ex}", flush=True)
                time.sleep(2 + attempt * 3)
        else:
            r = []
        for (s, span), q in zip(part, r):
            ins = [[int(m["addr"], 16), m.get("disasm", "")]
                   for m in q.get("matches") or []]
            fh.write(json.dumps({"s": s, "span": span, "insns": ins}) + "\n")
        fh.flush()
        i += len(part)
        if (i // BATCH) % 25 == 0:
            print(f"[{i}/{len(items)}] {time.time()-t0:.0f}s", flush=True)
    fh.close()
    print("DONE", flush=True)


if __name__ == "__main__":
    main()
