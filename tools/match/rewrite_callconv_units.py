#!/usr/bin/env python3
"""Rewrite stale cdecl externs in previously emitted function units."""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import gen_pseudocode_chunks as G


def main():
    if len(sys.argv) != 4:
        raise SystemExit(
            'usage: rewrite_callconv_units.py <input-dir> <output-dir> <call-conventions.json>'
        )
    input_dir, output_dir = Path(sys.argv[1]), Path(sys.argv[2])
    G.FUNCTION_CONVENTIONS = json.loads(Path(sys.argv[3]).read_text(encoding='utf-8'))
    output_dir.mkdir(parents=True, exist_ok=True)

    scanned = rewritten = declarations = 0
    for path in sorted(input_dir.glob('f*.c')):
        scanned += 1
        source, count = G.rewrite_unit_call_conventions(
            path.read_text(encoding='utf-8', errors='replace')
        )
        if count:
            (output_dir / path.name).write_text(source, encoding='utf-8')
            rewritten += 1
            declarations += count

    print('units scanned:', scanned)
    print('units rewritten:', rewritten)
    print('declarations corrected:', declarations)


if __name__ == '__main__':
    main()
