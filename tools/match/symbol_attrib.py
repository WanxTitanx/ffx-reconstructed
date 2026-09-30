#!/usr/bin/env python3
"""Attribute candidates by exact mangled symbol name.

IDA resolved a real mangled name for 586 functions (DEAD_?length@?$char_traits...).
A compiled candidate carries the same mangled symbol in its dumpbin label. When
both the symbol and the bytes agree, the address attribution is exact and needs
no uniqueness argument.

Usage: symbol_attrib.py <inv.tsv> <out.json> <dis-dir>...
"""
import collections, csv, json, os, re, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import definitive_match as D

SUFFIX = re.compile(r'_\d+$')
# Form (c): '@name@N' 32-bit stdcall/fastcall decoration, e.g. '@__security_check_cookie@4'.
AT_DECORATED = re.compile(r'^@[^@\s]*@\d+$')


def symbol_of(name):
    """Extract the mangled symbol from a dumpbin label / inventory name.

    Handles all three name forms the IDA inventory and dumpbin labels use:
      (a) 'DEAD_<mangled>'   - IDA's canary marker on rows, e.g. DEAD_?length@...
      (b) '?<mangled>'       - plain MSVC C++ mangled name;
      (c) '_<cdecl mangled>' - plain C / cdecl name, e.g. _strstr, __RTC_NumErrors.
    The '@name@N' stdcall/fastcall decoration form is accepted too.  Any name
    without a mangling marker is semantic (Phyre_/FFX_/Engine_/Menu2D_/plain)
    and is skipped.
    """
    n = name.strip()
    if n.startswith('DEAD_'):
        n = n[5:]
    idx = n.find(' (')
    if idx > 0:
        n = n[:idx]
    # A dumpbin label may carry an 'RVA  VA  name' prefix; keep only the name.
    sp = n.split()
    if len(sp) > 1:
        n = sp[-1]
    for pre in ('Phyre_', 'FFX_', 'Engine_', 'Menu2D_'):
        if n.startswith(pre):
            return None
    if n.startswith('?') or n.startswith('_') or AT_DECORATED.match(n):
        return SUFFIX.sub('', n)
    return None


def main():
    inv_path, out_path = sys.argv[1], sys.argv[2]
    data, secs = D.load_pe(D.EXE_DEFAULT)
    read = D.va_reader(data, secs)

    want = {}
    for r in csv.DictReader(open(inv_path, encoding='utf-8'), delimiter='\t'):
        sym = symbol_of(r['name'])
        if not sym:
            continue
        want.setdefault(SUFFIX.sub('', sym), []).append(
            (int(r['start'], 16), int(r['size']), r['name']))
    print(f'inventory mangled symbols: {len(want)}', flush=True)

    confirmed = {}
    for d in sys.argv[3:]:
        if not os.path.isdir(d):
            continue
        for fn in sorted(os.listdir(d)):
            if not fn.endswith('.txt'):
                continue
            for name, ch in D.functions_from_dump(os.path.join(d, fn)):
                sym = symbol_of(name)
                if not sym:
                    continue
                for va, size, iname in want.get(sym, ()):
                    if va in confirmed:
                        continue
                    b = D.contiguous(ch)
                    if not b or len(b) != size:
                        continue
                    ref = read(va, size)
                    if ref is not None and D.equal_modulo_relocations(b, ref)[0]:
                        confirmed[va] = {'va': va, 'size': size, 'idb_name': iname,
                                         'symbol': sym, 'object': fn[:-4],
                                         'source_name': name}
                        break
    out = list(confirmed.values())
    json.dump(out, open(out_path, 'w'), indent=1)
    print(f'confirmed by exact symbol + bytes: {len(out)}')
    print(f'bytes: {sum(c["size"] for c in out):,}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
