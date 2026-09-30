#!/usr/bin/env python3
"""Verify corpus units against their declared address, merging dumpbin's label splits.

dumpbin emits an internal jump target as a fresh label ($LN35:, $LN54:) inside
one function. A parser that starts a new candidate at every label therefore sees
only the entry basic block and reports a bogus size, which is why a 1,983-byte
function was measured as 76 bytes.

Here all instruction chunks of a file are merged by address, so a unit is
compared as the single function it is.

Usage: corpus_va_verify2.py <dis-dir> <out.json>
"""
import csv, json, os, re, sys

sys.path.insert(0, '/mnt/ssd-kingston/ffx-reconstructed/tools/match')
import definitive_match as D

data, secs = D.load_pe(D.EXE_DEFAULT)
read = D.va_reader(data, secs)

inv = {}
for r in csv.DictReader(open('/mnt/ssd-kingston/ffx-reconstructed/tools/match/inventory.tsv',
                             encoding='utf-8'), delimiter='\t'):
    inv[int(r['start'], 16)] = (int(r['size']), r['name'])


def merge_units(path):
    """All instruction bytes of one object, keyed by address, plus label names."""
    by_addr = {}
    names = []
    last = None
    for line in open(path, encoding='utf-8', errors='replace'):
        stripped = line.lstrip()
        if not D.INSN_ONLY_RX.match(stripped):
            m = D.LABEL_RX.match(line)
            if m:
                names.append(m.group(1))
                continue
            # dumpbin wraps a long instruction and prints the remaining bytes on
            # a continuation line with no address; append them to the last one.
            cont = re.match(r'^\s+((?:[0-9A-F]{2}\s?)+)\s*$', line)
            if cont and last is not None:
                extra = bytearray()
                for tok in cont.group(1).split():
                    if re.fullmatch(r'[0-9A-F]{2}', tok):
                        extra.append(int(tok, 16))
                if extra:
                    base, prev = by_addr[last]
                    by_addr[last] = (base, prev + bytes(extra))
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
        by_addr[addr] = (addr, bytes(bs))
        last = addr
    return {a: v[1] for a, v in by_addr.items()}, names


def contiguous_all(by_addr):
    if not by_addr:
        return None
    addrs = sorted(by_addr)
    blob = bytearray()
    expect = addrs[0]
    for a in addrs:
        if a != expect:
            return None
        blob += by_addr[a]
        expect = a + len(by_addr[a])
    return bytes(blob)


def main():
    dis_dir, out_path = sys.argv[1], sys.argv[2]
    ok, size_mismatch, byte_mismatch, gaps = [], 0, 0, 0
    for fn in sorted(os.listdir(dis_dir)):
        m = re.match(r'^dis_f([0-9A-Fa-f]{6,8})\.txt$', fn)
        if not m:
            continue
        va = int(m.group(1), 16)
        if va not in inv:
            continue
        fsize, iname = inv[va]
        ref = read(va, fsize)
        if ref is None:
            continue
        by_addr, names = merge_units(os.path.join(dis_dir, fn))
        blob = contiguous_all(by_addr)
        if blob is None:
            gaps += 1
            continue
        if len(blob) != fsize:
            size_mismatch += 1
            continue
        if D.equal_modulo_relocations(blob, ref)[0]:
            ok.append({'va': va, 'size': fsize, 'idb_name': iname,
                       'object': fn[:-4], 'source_name': names[0] if names else '?'})
        else:
            byte_mismatch += 1
    json.dump(ok, open(out_path, 'w'), indent=1)
    print(f'merged exact matches       : {len(ok)}')
    print(f'  bytes                    : {sum(o["size"] for o in ok):,}')
    print(f'size mismatch              : {size_mismatch}')
    print(f'byte mismatch (same size)  : {byte_mismatch}')
    print(f'non-contiguous             : {gaps}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
