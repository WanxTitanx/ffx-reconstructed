#!/usr/bin/env python3
"""Pull original source-file paths out of the target binary.

MSVC emits ``__FILE__``-style paths into assert strings and RTTI, so the built
executable still carries the layout of the tree it was compiled from. Those
paths are the strongest available provenance signal for which SDK revision and
directory structure the original build used.
"""

import collections
import re
import sys

SRC_RX = re.compile(rb"[A-Za-z0-9_\\.\-]{2,80}\.(?:cpp|cc|cxx|c|h|hpp|inl|hlsl|fx|asm)")


def main() -> int:
    exe = sys.argv[1]
    data = open(exe, "rb").read()

    hits = collections.Counter()
    for m in SRC_RX.finditer(data):
        raw = m.group(0)
        # Include a leading path fragment so directory names survive.
        start = m.start()
        j = start
        while j > 0 and data[j - 1] not in b"\x00\r\n\t" and start - j < 160:
            j -= 1
        full = data[j : m.end()].decode("latin-1")
        if len(full) < 4:
            continue
        hits[full] += 1

    print(f"total distinct path-ish strings: {len(hits)}")
    print()
    for path, count in sorted(hits.items(), key=lambda kv: (-kv[1], kv[0])):
        print(f"{count:6d}  {path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
