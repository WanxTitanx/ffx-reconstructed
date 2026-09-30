#!/usr/bin/env python3
"""define_sweep.py — define_func every uncovered orphan code sub-block head.

Per chunk: take first uncovered code head h -> define_func(h) -> IDA returns
[start,end) -> mark heads < end covered -> next uncovered code head -> repeat.
Batch: 60 define items per call. Progress to stdout; define_result.jsonl.
"""
import json, os, sys, time, bisect
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from mcpc import Ida

HERE = os.path.dirname(os.path.abspath(__file__))
DATAM = lambda t: t.split(";")[0].strip().lower().startswith(
    ("dd ", "dw ", "db ", "dq ", "dt ", "align", "unicode"))

# code heads per chunk (from chunk_disasm)
chunk_code = {}   # chunk_start -> [code head addrs]
for l in open(os.path.join(HERE, "chunk_disasm.jsonl")):
    d = json.loads(l)
    ch = [a for a, t in d["insns"] if not DATAM(t)]
    if ch:
        chunk_code[d["s"]] = ch

# exclude heads that are jump-table CASE-BODY targets (dd offset loc_X in
# orphan chunks) — they belong to a switch, not to a standalone function
import re
jt_targets = set()
for l in open(os.path.join(HERE, "chunk_disasm.jsonl")):
    d = json.loads(l)
    for a, t in d["insns"]:
        m = re.match(r"d[dwbqt]\s+(?:offset\s+)?(loc_\w+)", t.split(";")[0].strip())
        if m:
            jt_targets.add(int(m.group(1)[4:], 16))
print("jmptab case-body targets excluded:", len(jt_targets))

# all candidate code heads sorted
cand = sorted(h for ch in chunk_code.values() for h in ch
              if h not in jt_targets)
print("candidate heads:", len(cand))

OUT = os.path.join(HERE, "define_result.jsonl")
POS = os.path.join(HERE, "define_sweep.pos")


def main():
    ida = Ida()
    done_idx = 0
    covered = [(0x7848E0, 0x784903), (0x89DBE0, 0x89DC1C),
               (0x887940, 0x8879FE)]          # pilot defines
    if os.path.exists(POS):
        st = json.load(open(POS))
        done_idx = st["idx"]
        covered = [tuple(x) for x in st["covered"]]
    fh = open(OUT, "a")

    covs = sorted(covered)
    def is_cov(a):
        # last range with start <= a; check a < end
        i = bisect.bisect_right(covs, (a, 0xFFFFFFFFFFFF)) - 1
        return i >= 0 and covs[i][0] <= a < covs[i][1]

    i = done_idx
    t0 = time.time()
    batch = []
    batch_idx = []
    while i < len(cand):
        h = cand[i]
        if is_cov(h):
            i += 1
            continue
        batch.append(h)
        batch_idx.append(i)
        i += 1
        if len(batch) >= 60:
            _flush(ida, batch, batch_idx, fh, covs)
            batch = []; batch_idx = []
            if len(covs) % 600 < 60:
                with open(POS, "w") as pf:
                    json.dump({"idx": i, "covered": covs}, pf)
                print(f"[{i}/{len(cand)}] defined_ranges={len(covs)} "
                      f"({time.time()-t0:.0f}s)", flush=True)
    if batch:
        _flush(ida, batch, batch_idx, fh, covs)
    with open(POS, "w") as pf:
        json.dump({"idx": i, "covered": covs}, pf)
    fh.close()
    print("DONE", flush=True)


def _flush(ida, batch, batch_idx, fh, covs):
    items = [{"addr": hex(h)} for h in batch]
    for attempt in range(4):
        try:
            r = ida.call("define_func", {"items": items})
            break
        except Exception as e:
            print("ERR define:", e, flush=True)
            time.sleep(3)
    else:
        r = []
    res = r if isinstance(r, list) else r.get("results", [])
    byq = {}
    for it in res:
        try:
            a = int(it.get("addr") or it.get("start"), 16)
            byq[a] = it
        except Exception:
            pass
    for h in batch:
        it = byq.get(h)
        if it and it.get("end"):
            s = int(it["start"], 16); e = int(it["end"], 16)
            bisect.insort(covs, (s, e))
            fh.write(json.dumps({"req": h, "start": s, "end": e,
                                 "ok": True}) + "\n")
        else:
            fh.write(json.dumps({"req": h, "ok": False,
                                 "raw": it}) + "\n")
    fh.flush()


if __name__ == "__main__":
    main()
