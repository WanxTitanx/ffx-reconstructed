#!/usr/bin/env python3
"""Export the authoritative function inventory from the IDA database.

Runs on the Windows VM under `py -3.11` (idalib). Writes a TSV with one row per
function: start_hex, end_hex, size, flags, sha256(machine bytes), name.

This file is the measuring stick for byte-identical reconstruction: every
candidate build is compared against these exact byte ranges.
"""

import hashlib
import json
import sys
import time

import idapro  # noqa: E402  (idalib runtime)
import ida_auto
import ida_bytes
import ida_funcs
import idautils


def main() -> int:
    if len(sys.argv) < 3:
        print("usage: export_inventory.py <idb.i64> <out.tsv>", file=sys.stderr)
        return 2

    idb_path, out_path = sys.argv[1], sys.argv[2]
    t0 = time.time()
    print(f"[open] {idb_path}", flush=True)
    idapro.open_database(idb_path, False)
    ida_auto.auto_wait()
    print(f"[open] done in {time.time() - t0:.1f}s", flush=True)

    rows = []
    total_bytes = 0
    unnamed = 0
    for ea in idautils.Functions():
        fn = ida_funcs.get_func(ea)
        if fn is None:
            continue
        size = fn.end_ea - fn.start_ea
        name = ida_funcs.get_func_name(fn.start_ea) or ""
        if not name or name.startswith("sub_"):
            unnamed += 1
        raw = ida_bytes.get_bytes(fn.start_ea, size)
        if raw is None:
            raw = b""
        digest = hashlib.sha256(raw).hexdigest()
        rows.append(
            (
                fn.start_ea,
                fn.end_ea,
                size,
                int(fn.flags),
                digest,
                name,
                len(raw),
            )
        )
        total_bytes += size

    rows.sort(key=lambda r: r[0])
    with open(out_path, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("start\tend\tsize\tflags\tsha256\tname\treadable\n")
        for start, end, size, flags, digest, name, readable in rows:
            fh.write(
                f"{start:#010x}\t{end:#010x}\t{size}\t{flags:#x}\t{digest}\t{name}\t{readable}\n"
            )

    summary = {
        "idb": idb_path,
        "out": out_path,
        "functions": len(rows),
        "code_bytes": total_bytes,
        "unnamed": unnamed,
        "elapsed_s": round(time.time() - t0, 1),
    }
    with open(out_path + ".summary.json", "w", encoding="utf-8") as fh:
        json.dump(summary, fh, indent=2)
    print(json.dumps(summary, indent=2), flush=True)
    idapro.close_database(False)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
