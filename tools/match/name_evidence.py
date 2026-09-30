#!/usr/bin/env python3
"""Confirm candidates by byte-identity AND symbol-name evidence.

The strict verifier drops any candidate that matches more than one same-size
boundary. Many of those are genuine but duplicated across TUs (STL templates).
When a candidate is byte-identical to several boundaries, the demangled symbol
name decides which one it is -- but only when it is decisive. A candidate is
confirmed here when exactly one boundary both matches byte-for-byte and carries
a distinctive identifier shared with the candidate symbol.

Usage: name_evidence.py <dump-dis-dir> <inventory.tsv> <out.json> [--exclude matched.json]
"""
import collections, csv, json, os, re, struct, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import definitive_match as D

COMMON = {
    'std', 'void', 'char', 'int', 'unsigned', 'const', 'class', 'struct', 'public',
    'private', 'protected', 'static', 'virtual', 'thiscall', 'cdecl', 'stdcall',
    'bool', 'float', 'double', 'long', 'short', 'enum', 'typename', 'template',
    'operator', 'allocator', 'traits', 'iterator', 'value', 'type', 'first',
    'second', 'pair', 'vector', 'string', 'basic', 'pointer', 'reference',
    'Phyre', 'FFX', 'Engine', 'Menu2D', 'Bullet',
}
IDENT = re.compile(r'[A-Za-z_][A-Za-z0-9_]{4,}')

def idents(text):
    out = set()
    for t in IDENT.findall(text):
        t = t.strip('_')
        if len(t) < 5:
            continue
        if t in COMMON or t.lower() in {c.lower() for c in COMMON}:
            continue
        out.add(t)
    return out


def main():
    dis_dir, inv_path, out_path = sys.argv[1], sys.argv[2], sys.argv[3]
    exclude = set()
    if '--exclude' in sys.argv:
        ex = json.load(open(sys.argv[sys.argv.index('--exclude') + 1]))
        exclude = {e['va'] for e in ex.get('functions', ex)}

    data, secs = D.load_pe(D.EXE_DEFAULT)
    read = D.va_reader(data, secs)
    by_size = collections.defaultdict(list)
    for r in csv.DictReader(open(inv_path, encoding='utf-8'), delimiter='\t'):
        by_size[int(r['size'])].append((int(r['start'], 16), r['name']))

    confirmed, scanned, amb_total, amb_named = [], 0, 0, 0
    for fn in sorted(os.listdir(dis_dir)):
        if not fn.endswith('.txt'):
            continue
        for name, chunks in D.functions_from_dump(os.path.join(dis_dir, fn)):
            blob = D.contiguous(chunks)
            if blob is None or len(blob) < 24:
                continue
            scanned += 1
            hits = []
            for va, idb in by_size.get(len(blob), ()):
                ref = read(va, len(blob))
                if ref is None:
                    continue
                ok, _ = D.equal_modulo_relocations(blob, ref)
                if ok:
                    hits.append((va, idb))
            if len(hits) == 1:
                continue  # already handled by the strict verifier
            if len(hits) > 1:
                amb_total += 1
                cand_id = idents(name)
                if not cand_id:
                    continue
                scored = [(len(cand_id & idents(idb)), va, idb) for va, idb in hits]
                scored.sort(reverse=True)
                top = scored[0]
                if top[0] >= 1 and (len(scored) == 1 or top[0] > scored[1][0]):
                    amb_named += 1
                    if top[1] not in exclude:
                        confirmed.append({
                            'object': fn[:-4], 'source_name': name, 'size': len(blob),
                            'va': top[1], 'idb_name': top[2], 'shared_idents': top[0],
                            'rivals': len(hits),
                        })
    json.dump(confirmed, open(out_path, 'w'), indent=1)
    print(f'candidates scanned            : {scanned}')
    print(f'ambiguous (multi-boundary)    : {amb_total}')
    print(f'  name-decisive               : {amb_named}')
    print(f'NEW (not previously listed)   : {len(confirmed)}')
    print(f'NEW code bytes                : {sum(c["size"] for c in confirmed):,}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())

