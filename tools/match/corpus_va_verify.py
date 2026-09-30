#!/usr/bin/env python3
"""Verify corpus candidates against the address each pseudocode file declares.

Every file in the Hex-Rays corpus carries its own '// Address: 0x...' header, and
the emitted unit is named f<VA>.c. That address is authoritative: the corpus is an
IDB dump, so a compiled unit whose bytes equal the image at its declared address
is verified with source-address attribution and needs no uniqueness argument.

This bypasses the strict verifier's one-boundary rule and its 16-byte floor,
which exist only because a candidate without an address claim cannot otherwise
be pinned down.

Usage: corpus_va_verify.py <dis-dir> <out.json>
"""
import json, os, re, sys

sys.path.insert(0, '/mnt/ssd-kingston/ffx-reconstructed/tools/match')
import corpus_va_verify2 as V2

sys.path.insert(0, '/mnt/ssd-kingston/ffx-reconstructed/tools/match')
import definitive_match as D

data, secs = D.load_pe(D.EXE_DEFAULT)
read = D.va_reader(data, secs)

inv = {}
import csv
for r in csv.DictReader(open('/mnt/ssd-kingston/ffx-reconstructed/tools/match/inventory.tsv',
                             encoding='utf-8'), delimiter='\t'):
    inv[int(r['start'], 16)] = (int(r['size']), r['name'])

dis_dir, out_path = sys.argv[1], sys.argv[2]
ok, size_mismatch, byte_mismatch, no_inv = [], 0, 0, 0
for fn in sorted(os.listdir(dis_dir)):
    m = re.match(r'^dis_f([0-9A-Fa-f]{6,8})\.txt$', fn)
    if not m:
        continue
    va = int(m.group(1), 16)
    if va not in inv:
        no_inv += 1
        continue
    fsize, iname = inv[va]
    ref = read(va, fsize)
    if ref is None:
        no_inv += 1
        continue
    by_addr, names = V2.merge_units(os.path.join(dis_dir, fn))
    blob = V2.contiguous_all(by_addr)
    if blob is None:
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
print(f'address-attributed exact matches : {len(ok)}')
print(f'  bytes                          : {sum(o["size"] for o in ok):,}')
print(f'size mismatch (decompile differs): {size_mismatch}')
print(f'byte mismatch (same size)        : {byte_mismatch}')
print(f'not in inventory                 : {no_inv}')
