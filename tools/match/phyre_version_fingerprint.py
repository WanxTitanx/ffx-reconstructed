#!/usr/bin/env python3
"""Fingerprint which PhyreEngine revision FFX.exe was built against.

MSVC RTTI leaves ``.?AV<class>@@`` type descriptors in .rdata for every class
that ended up in the image. Comparing that class set with the class sets of the
available PhyreEngine SDK revisions dates the engine more reliably than any
version string, because unused subsystems simply are not present.
"""

import collections
import os
import re
import sys

RTTI_RX = re.compile(rb"\.\?AV([A-Za-z_][A-Za-z0-9_@$?]*?)@@")


def rtti_classes(exe: str) -> set[str]:
    data = open(exe, "rb").read()
    out = set()
    for m in RTTI_RX.finditer(data):
        raw = m.group(1).decode("latin-1")
        # Drop template arguments and scope suffixes; keep the first two levels.
        head = raw.split("<")[0]
        parts = head.split("@")
        parts = [p for p in parts if p]
        if parts:
            out.add("::".join(parts[:2]))
    return out


def sdk_classes(root: str) -> set[str]:
    """Collect PXxx / Phyre-ish class names declared in an SDK's headers."""
    found = set()
    cls_rx = re.compile(
        r"\b(?:class|struct)\s+(?:PHYRE_\w+\s+)?(P[A-Z][A-Za-z0-9_]*)"
    )
    for dirpath, _dirnames, filenames in os.walk(root, onerror=lambda e: None):
        for fn in filenames:
            if not fn.endswith((".h", ".inl")):
                continue
            path = os.path.join(dirpath, fn)
            try:
                text = open(path, "r", encoding="latin-1").read()
            except OSError:
                continue
            for m in cls_rx.finditer(text):
                found.add(m.group(1))
    return found


def main() -> int:
    exe = sys.argv[1]
    sdks = sys.argv[2:]

    binary = rtti_classes(exe)
    phyre_bin = {c for c in binary if c.startswith("Phyre::")}
    print(f"RTTI classes in binary          : {len(binary)}")
    print(f"  Phyre:: qualified             : {len(phyre_bin)}")

    # Classes declared by the SDK headers, restricted to the P-prefixed names
    # that ffx.exe actually uses.
    bin_pnames = collections.Counter()
    for c in binary:
        leaf = c.split("::")[-1]
        if re.fullmatch(r"P[A-Z][A-Za-z0-9_]*", leaf):
            bin_pnames[leaf] += 1
    print(f"  distinct P* leaf names        : {len(bin_pnames)}")
    print()

    for root in sdks:
        if not os.path.isdir(root):
            print(f"{root}: MISSING")
            continue
        declared = sdk_classes(root)
        overlap = set(bin_pnames) & declared
        missing = sorted(set(bin_pnames) - declared)
        print(f"=== {root}")
        print(f"  P* classes declared by SDK    : {len(declared)}")
        print(f"  binary P* classes present     : {len(overlap)}")
        print(f"  binary P* classes NOT declared: {len(missing)}")
        if missing:
            print(f"    e.g. {', '.join(missing[:25])}")
        print()

    print("sample of binary Phyre:: classes:")
    for c in sorted(phyre_bin)[:40]:
        print("   ", c)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
