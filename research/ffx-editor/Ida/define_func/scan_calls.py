#!/usr/bin/env python3
"""scan_calls.py — enumerate all call/jmp code heads in .text with disasm.

Same 128KB-window pagination as scan_heads. Output JSONL per record:
{"a": site, "f": func_start_or_0, "d": disasm_text, "m": "call"|"jmp"}
"""
import json, os, sys, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from mcpc import Ida

HERE = os.path.dirname(os.path.abspath(__file__))
TEXT_START = 0x401000
TEXT_END = 0xB0C000
WIN = 0x20000
COUNT = 5000


def scan(ida, mnem, out_name, pos_name):
    out = os.path.join(HERE, out_name)
    pos = os.path.join(HERE, pos_name)
    resume = TEXT_START
    if os.path.exists(pos):
        resume = int(open(pos).read().strip(), 16)
    fh = open(out, "a" if resume > TEXT_START else "w")
    w = resume
    t0 = time.time()
    while w < TEXT_END:
        wend = min(w + WIN, TEXT_END)
        start = w
        n = 0
        try:
            while start < wend:
                r = ida.call("insn_query", {"queries": [{
                    "mnem": mnem, "start": hex(start), "end": hex(wend),
                    "count": COUNT, "include_fn": True,
                    "include_disasm": True}]})
                ms = (r[0].get("matches") or [])
                if not ms:
                    break
                for m in ms:
                    a = int(m["addr"], 16)
                    f = m.get("fn")
                    fa = int(f["addr"], 16) if f else 0
                    fh.write(json.dumps({"a": a, "f": fa,
                                         "d": m.get("disasm", ""),
                                         "m": mnem}) + "\n")
                n += len(ms)
                if len(ms) < COUNT:
                    break
                start = int(ms[-1]["addr"], 16) + 1
        except Exception as e:
            print(f"ERR {mnem} win {w:#x} @{start:#x}: {e}", flush=True)
            fh.flush()
            with open(pos, "w") as pf:
                pf.write(hex(w))
            raise
        fh.flush()
        with open(pos, "w") as pf:
            pf.write(hex(wend))
        print(f"{mnem} win {w:#x}-{wend:#x}: {n}  ({time.time()-t0:.0f}s)",
              flush=True)
        w = wend
    fh.close()
    print(f"{mnem} DONE", flush=True)


def main():
    ida = Ida()
    scan(ida, "call", "calls.jsonl", "scan_calls.pos")
    scan(ida, "jmp", "jmps.jsonl", "scan_jmps.pos")
    print("ALL DONE", flush=True)


if __name__ == "__main__":
    main()
