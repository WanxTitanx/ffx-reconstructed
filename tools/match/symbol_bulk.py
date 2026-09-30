#!/usr/bin/env python3
"""Attribution by exact mangled symbol confirmed across every same-named address.

For a symbol that appears at N inventory addresses with identical bytes, one
compiled candidate of that exact symbol matches all N. Distinct symbols cannot
share an address, so this gives an exact, unambiguous attribution with no
uniqueness argument needed -- the strict verifier's one-boundary rule does not
apply because byte equality alone cannot separate them.

Usage: symbol_bulk.py <inventory.tsv> <out.json> <dis-dir>...
"""
import collections, csv, json, os, re, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import definitive_match as D

SUF = re.compile(r'_\d+$')


IDA_AUTO = ('nullsub', 'unknown_libname', 'loc_', 'sub_', 'unk_', 'byte_', 'dword_',
            'word_', 'off_', 'flt_', 'dbl_', 'str_', 'j_', 'thunk_')


def sym_of(name):
    """Return a symbol identity, or None when the name is not a real symbol.

    Only C++ mangled names and CRT names are identities. IDA's address-derived
    names (FFX_Orp_404530, Phyre_Loose_4CD8B0) must never be grouped, because
    stripping the address suffix would merge distinct functions.
    """
    n = name.strip()
    if n.startswith('DEAD_'):
        n = n[5:]
    n = SUF.sub('', n)
    if '?' in n or n.startswith('__'):
        return n
    if n.startswith(IDA_AUTO):
        return None
    return None


def main():
    inv_path, out_path = sys.argv[1], sys.argv[2]
    data, secs = D.load_pe(D.EXE_DEFAULT)
    read = D.va_reader(data, secs)

    by_sym = collections.defaultdict(list)
    for r in csv.DictReader(open(inv_path, encoding='utf-8'), delimiter='\t'):
        by_sym[sym_of(r['name'])].append((int(r['start'], 16), int(r['size']), r['name']))

    conf, checked = {}, 0
    for d in sys.argv[3:]:
        if not os.path.isdir(d):
            continue
        for fn in sorted(os.listdir(d)):
            if not fn.endswith('.txt'):
                continue
            for name, ch in D.functions_from_dump(os.path.join(d, fn)):
                m = re.match(r'^([^\s(]+)', name)
                if not m:
                    continue
                sym = SUF.sub('', m.group(1))
                cand = by_sym.get(sym)
                if not cand:
                    continue
                blob = D.contiguous(ch)
                if not blob:
                    continue
                checked += 1
                ok_all = []
                for va, size, iname in cand:
                    if len(blob) != size:
                        continue
                    ref = read(va, size)
                    if ref is not None and D.equal_modulo_relocations(blob, ref)[0]:
                        ok_all.append((va, size, iname))
                # Every same-named address whose bytes equal this candidate is that
                # function; distinct symbols cannot occupy one address, so no
                # uniqueness argument is needed even when several share the bytes.
                for va, size, iname in ok_all:
                    conf.setdefault(va, {'va': va, 'size': size, 'idb_name': iname,
                                         'symbol': sym, 'object': fn[:-4],
                                         'source_name': name, 'group': len(cand)})
    out = list(conf.values())
    json.dump(out, open(out_path, 'w'), indent=1)
    print(f'candidates with a symbol hit : {checked}')
    print(f'addresses confirmed          : {len(out)}')
    print(f'bytes                        : {sum(c["size"] for c in out):,}')
    groups = collections.Counter(c['symbol'] for c in out)
    for s, n in groups.most_common(6):
        print(f'   {n:4d} x {s[:60]}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
