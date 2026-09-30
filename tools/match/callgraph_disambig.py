#!/usr/bin/env python3
"""Disambiguate multi-boundary byte-identical matches using the call graph.

The strict verifier counts a candidate only when it matches exactly one
same-size boundary. Many genuine matches are byte-identical to several
boundaries (a template emitted in more than one translation unit, or two
functions of identical size and shape).

dumpbin prints the target symbol of every direct call and jump. Pass one learns
a mangled-symbol -> VA map from the candidates that already match exactly one
boundary. Pass two resolves each direct call of an ambiguous candidate in every
rival address and accepts a rival only when all learned symbols agree and it
outscores the runner-up.

Usage: callgraph_disambig.py <dump-dis-dir> <inventory.tsv> <out.json>
"""
import collections, csv, json, os, re, struct, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import definitive_match as D

CALL_RX = re.compile(r'\b(?:call|jmp)\s+([^\s].*?)\s*$')


def parse(path):
    cur = None
    for raw in open(path, encoding='utf-8', errors='replace'):
        line = raw.rstrip('\n')
        stripped = line.lstrip()
        is_insn = bool(D.INSN_ONLY_RX.match(stripped))
        m = None if is_insn else D.LABEL_RX.match(line)
        if m:
            if cur:
                yield cur
            cur = {'name': m.group(1), 'chunks': [], 'calls': []}
            continue
        if cur is None:
            continue
        mi = D.INSN_RX.match(line)
        if not mi:
            continue
        addr = int(mi.group(1), 16)
        bs = bytearray()
        for tok in mi.group(2).split():
            if re.fullmatch(r'[0-9A-F]{2}', tok):
                bs.append(int(tok, 16))
            else:
                break
        bs = bytes(bs)
        cur['chunks'].append((addr, bs))
        if len(bs) >= 5 and bs[0] in (0xE8, 0xE9):
            cm = CALL_RX.search(line)
            if cm:
                cur['calls'].append((addr + 1, cm.group(1).strip()))
    if cur:
        yield cur


def main():
    dis_dir, inv_path, out_path = sys.argv[1], sys.argv[2], sys.argv[3]
    data, secs = D.load_pe(D.EXE_DEFAULT)
    read = D.va_reader(data, secs)

    print('loading inventory ...', flush=True)
    by_size = collections.defaultdict(list)
    va_name = {}
    for r in csv.DictReader(open(inv_path, encoding='utf-8'), delimiter='\t'):
        va = int(r['start'], 16)
        by_size[int(r['size'])].append(va)
        va_name[va] = r['name']

    print('collecting candidate blobs ...', flush=True)
    seen = set()
    cands = []
    for fn in sorted(os.listdir(dis_dir)):
        if not fn.endswith('.txt'):
            continue
        for p in parse(os.path.join(dis_dir, fn)):
            blob = D.contiguous(p['chunks'])
            if not blob or len(blob) < 24 or len(p['calls']) < 2:
                continue
            key = (len(blob), blob)
            if key in seen:
                continue
            seen.add(key)
            p['blob'] = blob
            p['size'] = len(blob)
            cands.append(p)
    print(f'distinct candidate blobs: {len(cands)}', flush=True)

    sizes = collections.OrderedDict()
    for p in cands:
        sizes.setdefault(p['size'], None)
    print(f'distinct sizes: {len(sizes)}', flush=True)

    # cache reference bytes per size
    refs = {}
    for i, sz in enumerate(sizes):
        refs[sz] = [(va, read(va, sz)) for va in by_size.get(sz, ())]
        if i % 50 == 0:
            print(f'  cached size {sz} ({i}/{len(sizes)})', flush=True)

    print('pass 1: learning symbol map ...', flush=True)
    learned = {}
    for p in cands:
        sz = p['size']
        hits = [va for va, ref in refs.get(sz, ()) if ref is not None and D.equal_modulo_relocations(p['blob'], ref)[0]]
        if len(hits) == 1:
            for _off, s in p['calls']:
                learned.setdefault(s, hits[0])
    print(f'learned symbols: {len(learned)}', flush=True)

    print('pass 2: disambiguating ...', flush=True)
    confirmed, amb = [], 0
    for p in cands:
        sz = p['size']
        known = [(off, learned[s]) for off, s in p['calls'] if s in learned]
        if len(known) < 2:
            continue
        hits = [va for va, ref in refs.get(sz, ()) if ref is not None and D.equal_modulo_relocations(p['blob'], ref)[0]]
        if len(hits) < 2:
            continue
        amb += 1
        scores = []
        for va in hits:
            ref = read(va, sz)
            good = sum(1 for off, tva in known
                       if va + off + 4 + struct.unpack_from('<i', ref, off)[0] == tva)
            scores.append((good, va))
        scores.sort(reverse=True)
        if scores[0][0] == len(known) and scores[0][0] > scores[1][0]:
            confirmed.append({'object': 'callgraph', 'source_name': p['name'], 'size': sz,
                              'va': scores[0][1], 'idb_name': va_name.get(scores[0][1], '?'),
                              'agreed_calls': scores[0][0], 'rivals': len(hits)})
    json.dump(confirmed, open(out_path, 'w'), indent=1)
    print(f'ambiguous (byte-identical, >1 rival) : {amb}')
    print(f'confirmed by call graph              : {len(confirmed)}')
    print(f'bytes                                : {sum(c["size"] for c in confirmed):,}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())

