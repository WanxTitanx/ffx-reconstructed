#!/usr/bin/env python3
# probe2: stride-per-tag analysis across the corpus + region bounds
import struct, sys, os, json
from collections import Counter, defaultdict
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/BattleMap')
from map1_families import u16, u32, read_dispatch

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
JPPC = os.path.join(ROOT, "ffx/master/jppc")

def iter_corpus(root):
    hits = []
    for dirpath, _dirs, files in os.walk(root):
        for fn in files:
            if fn.lower() == 'mapout.vpa':
                hits.append(os.path.join(dirpath, fn))
    return sorted(hits)

tag_strides = defaultdict(Counter)   # tag -> Counter of stride-to-next-row (sorted rows)
tag_counts = Counter()
first_last = []
for path in iter_corpus(JPPC):
    b = open(path, 'rb').read()
    if len(b) < 5 or b[:4] != b'MAP1':
        continue
    geom, meta, dabs, rows = read_dispatch(b)
    if dabs is None or not rows:
        continue
    rel = os.path.relpath(path, JPPC)
    offs = sorted(r['off'] for r in rows)
    # strides between consecutive sorted row offsets (kept offs for first_last)
    # per-row tag stride (row's own tag -> distance to next row IN TABLE ORDER)
    for i in range(len(rows) - 1):
        s = rows[i+1]['off'] - rows[i]['off']
        tag_strides[rows[i]['tag']][s] += 1
    for r in rows:
        tag_counts[r['tag']] += 1
    first_last.append((rel, len(rows), hex(min(r['off'] for r in rows)),
                       hex(max(r['off'] for r in rows)), hex(dabs - geom),
                       hex(geom + max(r['off'] for r in rows)), hex(dabs)))

with open('/home/wanderson/Documents/ffx-editor-main/work/_map1_f23/probe2_strides.txt', 'w') as W:
    W.write("== per-tag strides (row.tag -> offset delta to NEXT row in table order) ==\n")
    for tag in sorted(tag_strides):
        tot = sum(tag_strides[tag].values())
        W.write("tag 0x%04X  rows=%d  strides: %s\n" % (tag, tot,
                ', '.join('0x%X x%d' % (s, n) for s, n in tag_strides[tag].most_common(12))))
    W.write("\n== per-file: rows, minOff, maxOff, dabsRel(=dabs-geom), maxBlobAbs, dabsAbs ==\n")
    for row in first_last:
        W.write('  %s rows=%d min=%s max=%s dabsRel=%s maxBlob=%s dabs=%s  gap(dabs-maxBlob)=%d\n' %
                (row[0], row[1], row[2], row[3], row[4], row[5], row[6],
                 int(row[6],16) - int(row[5],16)))
print("files with dispatch:", len(first_last))
