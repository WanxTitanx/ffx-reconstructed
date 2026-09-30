#!/usr/bin/env python3
"""Locate every FFX.exe on this host and fingerprint the first .text bytes.

The IDA database was built from a file whose .text starts with
``55 8b ec 8b 45 0c 5d c3`` at 0x401000. Any copy that does not start with
those bytes is a different build and cannot be used as a matching target.
"""

import hashlib
import os
import sys

IDB_PROLOGUE = bytes.fromhex("558bec8b450c5dc3")


def main() -> int:
    roots = sys.argv[1:] or ["/home/wanderson", "/mnt"]
    groups: dict[tuple[int, str], list[str]] = {}
    count = 0
    for root in roots:
        for dirpath, dirnames, filenames in os.walk(root, onerror=lambda e: None):
            dirnames[:] = [
                d for d in dirnames if d not in ("node_modules", ".git", "obj", "bin")
            ]
            for fn in filenames:
                if fn.lower() != "ffx.exe":
                    continue
                path = os.path.join(dirpath, fn)
                try:
                    size = os.path.getsize(path)
                    with open(path, "rb") as fh:
                        head = fh.read(0x408)
                        fh.seek(0)
                        full = hashlib.sha256(fh.read()).hexdigest()
                except OSError as exc:
                    print(f"ERR {path}: {exc}")
                    continue
                text8 = head[0x400:0x408]
                groups.setdefault((size, text8.hex()), []).append(path)
                count += 1
                mark = "IDB-BUILD" if text8 == IDB_PROLOGUE else ""
                print(f"{size:>10} {text8.hex()} sha256={full[:16]} {mark:10s} {path}")

    print()
    print(f"total copies: {count}, distinct builds: {len(groups)}")
    for (size, text8), paths in sorted(groups.items(), key=lambda kv: -len(kv[1])):
        mark = " <-- IDB build" if bytes.fromhex(text8) == IDB_PROLOGUE else ""
        print(f"  size={size:>10} text[0:8]={text8} copies={len(paths)}{mark}")
        print(f"      e.g. {paths[0]}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
