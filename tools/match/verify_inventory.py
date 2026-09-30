#!/usr/bin/env python3
"""Cross-check the IDA function inventory against the raw PE image.

Confirms that every (start, size, sha256) row really maps onto the bytes of the
target executable, and buckets the code so we know how much of the 6.5 MB is
first-party FFX/Phyre logic versus identifiable third-party library code.
"""

import collections
import csv
import hashlib
import re
import struct
import sys

import definitive_match as exact


def load_sections(data: bytes):
    """Return (name, virtual_address, virtual_size, raw_ptr, raw_size) per section.

    The section table stores RVAs; the IDA inventory reports absolute virtual
    addresses, so image base has to be added before comparing.
    """
    return exact.parse_pe(data)[1]


def make_rva_reader(data: bytes, secs):
    return exact.va_reader(data, secs)


LIB_PATTERNS = [
    ("msvc-crt", re.compile(r"^(_?\?|_|nullsub|unknown_libname|DEAD_)")),
    ("zlib", re.compile(r"(Zlib|Inflate|Deflate|Adler|CRC32)", re.I)),
    ("vpx", re.compile(r"(Vpx|VPX_)")),
    ("lua", re.compile(r"^(LuaB|Lua|Scripting|PScript|PScriptAccessors)")),
    ("bullet", re.compile(r"^(bt|Bullet)")),
    ("iggy", re.compile(r"^Iggy")),
    ("mkv", re.compile(r"^mkvparser")),
    ("phyre", re.compile(r"^Phyre")),
    ("ffx", re.compile(r"^FFX")),
]


def classify(name: str) -> str:
    for label, rx in LIB_PATTERNS:
        if rx.search(name):
            return label
    return "other"


def main() -> int:
    exe, tsv = sys.argv[1], sys.argv[2]
    data, secs = exact.load_pe(exe)
    read = make_rva_reader(data, secs)

    rows = []
    seen = set()
    required = {'start', 'size', 'sha256', 'name'}
    with open(tsv, encoding="utf-8", newline='') as fh:
        reader = csv.DictReader(fh, delimiter='\t')
        fields = reader.fieldnames or []
        if not required.issubset(fields) or len(fields) != len(set(fields)):
            raise ValueError('inventory header is invalid')
        for number, row in enumerate(reader, 2):
            if None in row or any(not row.get(key) for key in required):
                raise ValueError(f'malformed inventory row {number}')
            va, size = int(row['start'], 16), int(row['size'])
            digest = row['sha256'].lower()
            if size <= 0 or va < 0 or not re.fullmatch('[0-9a-f]{64}', digest):
                raise ValueError(f'invalid inventory range/hash on row {number}')
            if va in seen:
                raise ValueError(f'duplicate inventory address {va:#x}')
            seen.add(va)
            rows.append((va, size, digest, row['name']))
    if not rows:
        raise ValueError('inventory is empty')

    mismatched = 0
    unreadable = 0
    buckets = collections.defaultdict(lambda: [0, 0])
    sizes = []
    for va, size, digest, name in rows:
        raw = read(va, size)
        if raw is None:
            unreadable += 1
            continue
        if hashlib.sha256(raw).hexdigest() != digest:
            mismatched += 1
        label = classify(name)
        buckets[label][0] += 1
        buckets[label][1] += size
        sizes.append(size)

    print(f"rows                 : {len(rows)}")
    print(f"sha256 mismatches    : {mismatched}")
    print(f"unreadable ranges    : {unreadable}")
    print(f"total code bytes     : {sum(sizes):,}")
    sizes.sort()
    n = len(sizes)
    if n:
        print(f"size median / mean   : {sizes[n // 2]} / {sum(sizes) // n}")
        print(f"size p90 / p99 / max : {sizes[int(n * 0.9)]} / {sizes[int(n * 0.99)]} / {sizes[-1]}")
    print()
    print(f"{'bucket':12s} {'funcs':>8s} {'bytes':>12s} {'%bytes':>7s}")
    for label, (cnt, nbytes) in sorted(buckets.items(), key=lambda kv: -kv[1][1]):
        print(f"{label:12s} {cnt:8d} {nbytes:12,d} {100 * nbytes / sum(sizes):6.1f}%")
    return 1 if mismatched or unreadable else 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, csv.Error, struct.error) as exc:
        print(f'error: {exc}', file=sys.stderr)
        raise SystemExit(2)
