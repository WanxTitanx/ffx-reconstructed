#!/usr/bin/env python3
"""scan_heads.py — enumerate every code head in .text with fn containment.

Drives insn_query over 128KB windows (bounded so max_scan_insns=200000 can
never truncate a window: 128KB holds at most ~131k 1-byte heads). Within a
window, pages continue via start=last_addr+1 until <count matches come back.

Writes JSONL: {"a": addr_int, "f": func_start_int_or_0}
Progress lines to stdout; checkpoint in scan_heads.pos (restartable).
"""
import json, os, sys, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from mcpc import Ida

HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(HERE, "heads.jsonl")
POS = os.path.join(HERE, "scan_heads.pos")
TEXT_START = 0x401000
TEXT_END = 0xB0C000
WIN = 0x20000
COUNT = 5000


def scan_window(ida, wstart, wend, fh):
    total = 0
    start = wstart
    while start < wend:
        r = ida.call("insn_query", {"queries": [{
            "start": hex(start), "end": hex(wend),
            "count": COUNT, "include_fn": True}]})
        q = r[0]
        ms = q.get("matches") or []
        if not ms:
            return total  # no more heads in window
        for m in ms:
            a = int(m["addr"], 16)
            f = m.get("fn")
            fa = int(f["addr"], 16) if f else 0
            fh.write(json.dumps({"a": a, "f": fa}) + "\n")
        total += len(ms)
        if len(ms) < COUNT:
            return total
        start = int(ms[-1]["addr"], 16) + 1
    return total


def main():
    ida = Ida()
    resume = TEXT_START
    if os.path.exists(POS):
        resume = int(open(POS).read().strip(), 16)
    mode = "a" if resume > TEXT_START else "w"
    fh = open(OUT, mode)
    w = resume
    t0 = time.time()
    while w < TEXT_END:
        wend = min(w + WIN, TEXT_END)
        try:
            n = scan_window(ida, w, wend, fh)
        except Exception as e:
            print(f"ERR window {w:#x}: {e}; retrying in 5s", flush=True)
            time.sleep(5)
            try:
                n = scan_window(ida, w, wend, fh)
            except Exception as e2:
                print(f"FATAL window {w:#x}: {e2}", flush=True)
                fh.close()
                sys.exit(2)
        fh.flush()
        with open(POS, "w") as pf:
            pf.write(hex(wend))
        el = time.time() - t0
        print(f"win {w:#x}-{wend:#x}: {n} heads  ({el:.0f}s)", flush=True)
        w = wend
    fh.close()
    print("SCAN COMPLETE", flush=True)


if __name__ == "__main__":
    main()
