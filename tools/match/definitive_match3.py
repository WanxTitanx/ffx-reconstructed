#!/usr/bin/env python3
"""Definitive matcher with correct COFF function splitting.

Two parsing defects in the original made candidates mis-sized, and therefore
rejected:

1. a fresh function starts at every label, so an internal jump target
   (`$LN35:`) ended the candidate early;
2. a wrapped instruction's continuation line has no address and its bytes were
   dropped.

In a `dumpbin /DISASM` of a COFF object each function's first instruction sits at
address 0, so the correct split is "new function whenever an instruction address
returns to 0". Labels only name things. This handles one-function and
many-function objects alike.

Usage: definitive_match3.py <dump-dis-dir> <inventory.tsv> <out.json>
"""
import collections, csv, json, os, re, sys

sys.path.insert(0, '/mnt/ssd-kingston/ffx-reconstructed/tools/match')
import definitive_match as D

CONT = re.compile(r'^\s+((?:[0-9A-F]{2}\s?)+)\s*$')


def parse_units(path):
    """Yield (name, blob) per function, splitting when the address returns to 0."""
    units = []
    name = None
    chunks = []          # ordered (addr, bytes)
    pending = None       # last chunk index for continuations

    def flush():
        if name is not None or chunks:
            blob = _contig(chunks)
            units.append((name or '?', blob))
            chunks.clear()

    for line in open(path, encoding='utf-8', errors='replace'):
        stripped = line.lstrip()
        if not D.INSN_ONLY_RX.match(stripped):
            m = D.LABEL_RX.match(line)
            if m:
                # a label does not start a function by itself; remember the name
                if not chunks:
                    name = m.group(1)
                continue
            c = CONT.match(line)
            if c and chunks:
                extra = bytearray()
                for tok in c.group(1).split():
                    if re.fullmatch(r'[0-9A-F]{2}', tok):
                        extra.append(int(tok, 16))
                if extra:
                    a, b = chunks[-1]
                    chunks[-1] = (a, b + bytes(extra))
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
        if addr == 0 and chunks:
            flush()
            name = None
        chunks.append((addr, bytes(bs)))
    flush()
    return units


def _contig(chunks):
    if not chunks:
        return None
    chunks = sorted(chunks)
    blob = bytearray()
    expect = chunks[0][0]
    for a, b in chunks:
        if a != expect:
            return None
        blob += b
        expect = a + len(b)
    return bytes(blob)


def main():
    dis_dir, inv_path, out_path = sys.argv[1], sys.argv[2], sys.argv[3]
    data, secs = D.load_pe(D.EXE_DEFAULT)
    read = D.va_reader(data, secs)
    by_size = collections.defaultdict(list)
    va_name = {}
    for r in csv.DictReader(open(inv_path, encoding='utf-8'), delimiter='\t'):
        va = int(r['start'], 16)
        by_size[int(r['size'])].append(va)
        va_name[va] = r['name']

    confirmed, ambiguous, scanned, noncontig = [], 0, 0, 0
    for fn in sorted(os.listdir(dis_dir)):
        if not fn.endswith('.txt'):
            continue
        for name, blob in parse_units(os.path.join(dis_dir, fn)):
            if blob is None:
                noncontig += 1
                continue
            if len(blob) < 16:
                continue
            scanned += 1
            hits = [va for va in by_size.get(len(blob), ())
                    if (lambda ref: ref is not None and D.equal_modulo_relocations(blob, ref)[0])(read(va, len(blob)))]
            if len(hits) == 1:
                confirmed.append({'object': fn[:-4], 'source_name': name,
                                  'size': len(blob), 'va': hits[0], 'idb_name': va_name[hits[0]]})
            elif len(hits) > 1:
                ambiguous += 1
    json.dump(confirmed, open(out_path, 'w'), indent=1)
    print(f'candidates scanned   : {scanned}')
    print(f'exactly one boundary : {len(confirmed)}')
    print(f'ambiguous            : {ambiguous}')
    print(f'non-contiguous       : {noncontig}')
    print(f'bytes                : {sum(c["size"] for c in confirmed):,}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())

