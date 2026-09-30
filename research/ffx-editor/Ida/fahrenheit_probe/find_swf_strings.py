#!/usr/bin/env python3
"""Procura strings relacionadas a SWF/Flash no exe (evidencia do player Iggy)."""
import ida_bytes
import re

START = 0x400000
END = 0x1500000
PAT = re.compile(rb"[A-Za-z0-9_./\\-]{4,}(?:SWF|swf|Flash|flash|Iggy|iggy)[A-Za-z0-9_./\\-]{0,40}")


def main():
    raw = ida_bytes.get_bytes(START, END - START) or b""
    hits = set()
    for m in PAT.finditer(raw):
        s = m.group().decode("ascii", "replace")
        hits.add(s)
    print(f"strings SWF/Flash/Iggy: {len(hits)}", flush=True)
    for s in sorted(hits)[:30]:
        print(f"  {s[:90]}", flush=True)


if __name__ == "__main__":
    main()
