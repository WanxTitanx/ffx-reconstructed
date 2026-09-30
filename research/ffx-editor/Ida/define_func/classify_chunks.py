#!/usr/bin/env python3
"""classify_chunks2.py — fetch exact byte span [first_head, next_overall_head)
for each orphan chunk; classify PAD (all CC/90/00) vs NONPAD.
Writes chunk_bytes2.jsonl {s,e_fetch,hex,cls}
"""
import json, os, sys, time, bisect
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from mcpc import Ida

HERE = os.path.dirname(os.path.abspath(__file__))
TEXT_END = 0xB0C000
chunks = json.load(open(os.path.join(HERE, "chunks_raw.json")))
heads = sorted(json.loads(l)["a"] for l in open(os.path.join(HERE, "heads.jsonl")))
OUT = os.path.join(HERE, "chunk_bytes2.jsonl")


def next_head(a):
    i = bisect.bisect_right(heads, a)
    return heads[i] if i < len(heads) else TEXT_END

spans = []
for s, e in chunks:
    end = next_head(e)          # head after chunk's last head
    spans.append((s, max(end - s, 1)))

def classify(b: bytes):
    if not b:
        return "EMPTY"
    if all(x in (0xCC, 0x90, 0x00) for x in b):
        return "PAD"
    return "NONPAD"

def main():
    ida = Ida()
    fh = open(OUT, "w")
    t0 = time.time()
    i = 0
    while i < len(chunks):
        part = spans[i:i + 200]
        regs = [{"addr": hex(s), "size": min(sz, 0x1000)} for s, sz in part]
        for attempt in range(4):
            try:
                r = ida.call("get_bytes", {"regions": regs})
                break
            except Exception as ex:
                print(f"ERR @{i}: {ex}", flush=True)
                time.sleep(3)
        items = r if isinstance(r, list) else r.get("regions", r.get("data", []))
        for (s, sz), it in zip(part, items):
            hexs = it.get("data") or it.get("bytes") or ""
            if isinstance(hexs, list):
                hexs = " ".join(f"{x:02x}" for x in hexs)
            toks = [t.strip().lower().replace("0x", "").zfill(2)
                    for t in str(hexs).split() if t.strip()]
            try:
                b = bytes.fromhex("".join(toks))
            except ValueError:
                b = b""
            fh.write(json.dumps({"s": s, "span": sz, "cls": classify(b),
                                 "n": len(b), "hex": "".join(toks)[:512]}) + "\n")
        fh.flush()
        i += len(part)
        if (i // 200) % 40 == 0:
            print(f"[{i}/{len(chunks)}] {time.time()-t0:.0f}s", flush=True)
    fh.close()
    print("DONE", flush=True)

if __name__ == "__main__":
    main()
