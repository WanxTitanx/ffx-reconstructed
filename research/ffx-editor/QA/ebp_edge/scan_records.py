#!/usr/bin/env python3
"""Scan FFX text-table records (8B: u16 off, u16 attr, u16 offAlt, u16 attr2)
across the whole corpus: jppc .ebp chunk1+chunk4, and new_*pc .bin tables.
Questions:
  - does off==0 ever occur (triggers EbpMessageAdrs fallback)?
  - is offAlt ever != off (two-pair purpose)?
  - are attr/attr2 ever nonzero?
"""
import os, struct, sys, json

ROOT = "/mnt/nvme-samsung/SteamLibrary/steamapps/common/FINAL FANTASY FFX&FFX-2 HD Remaster/data/mods/ffx_ps2/ffx/master"

def scan_table(buf, base, end):
    """Records at buf[base:]; record count = min_nonzero_offset/8 (strings start)."""
    stats = dict(n=0, off0=0, alt0=0, diff=0, attr=0, attr2=0, both0=0, bad=0,
                 ex_diff=[], ex_zero=[])
    if base <= 0 or base >= len(buf):
        return stats
    end = min(end, len(buf))
    # first pass: find first nonzero offset => record count bound
    first_off = None
    i = 0
    while True:
        if base + i*8 + 8 > end: break
        off, attr, alt, attr2 = struct.unpack_from('<4H', buf, base + i*8)
        if off == 0 and alt == 0 and attr == 0 and attr2 == 0 and i == 0:
            # all-zero first record: ambiguous, treat as record anyway
            pass
        if off:
            first_off = off
            break
        if alt:
            first_off = alt
            break
        i += 1
        if i > 0x400: break
    if first_off is None or first_off < 8:
        return stats
    n = first_off // 8
    for i in range(n):
        if base + i*8 + 8 > len(buf): break
        off, attr, alt, attr2 = struct.unpack_from('<4H', buf, base + i*8)
        stats['n'] += 1
        if off == 0: stats['off0'] += 1; stats['ex_zero'].append((i,'off'))
        if alt == 0: stats['alt0'] += 1; stats['ex_zero'].append((i,'alt'))
        if off != alt: stats['diff'] += 1; stats['ex_diff'].append((i,off,alt,attr,attr2))
        if attr: stats['attr'] += 1
        if attr2: stats['attr2'] += 1
        if off == 0 and alt == 0: stats['both0'] += 1
        # sanity: offsets should be >= first_off and < chunk size
        for v in (off, alt):
            if v and (v < first_off or base + v >= end):
                stats['bad'] += 1
    stats['ex_diff'] = stats['ex_diff'][:8]
    stats['ex_zero'] = stats['ex_zero'][:8]
    return stats

def ev01_chunks(d):
    if d[:2] != b'EV': return None
    offs = struct.unpack_from('<7I', d, 4)
    return offs  # chunk0..4, end at idx5 (0xffffffff = file end marker sometimes)

def chunk_bounds(offs, idx, dlen):
    o = offs[idx]
    if o == 0 or o == 0xffffffff or o >= dlen: return None
    nxt = [x for x in offs[1:6] if x and x != 0xffffffff and x > o]
    end = min(nxt) if nxt else dlen
    return o, end

tot = dict(ebp=0, ebp_c1=None, ebp_c4=None, bin=0)
agg = {}
def add(tag, s):
    a = agg.setdefault(tag, dict(n=0,off0=0,alt0=0,diff=0,attr=0,attr2=0,both0=0,bad=0,files=0))
    a['files'] += 1
    for k in ('n','off0','alt0','diff','attr','attr2','both0','bad'): a[k]+=s[k]
    return a

examples_diff, examples_zero = [], []
for dirp, _, files in os.walk(ROOT):
    for fn in files:
        p = os.path.join(dirp, fn)
        rel = os.path.relpath(p, ROOT)
        if fn.endswith('.ebp'):
            try: d = open(p,'rb').read()
            except: continue
            offs = ev01_chunks(d)
            if not offs: continue
            tot['ebp'] += 1
            for idx, tag in ((1,'ebp_chunk1'), (4,'ebp_chunk4')):
                b = chunk_bounds(offs, idx, len(d))
                if not b: continue
                s = scan_table(d, b[0], b[1])
                add(tag, s)
                if s['diff']: examples_diff.append((rel, tag, s['ex_diff']))
                if s['off0'] or s['alt0']: examples_zero.append((rel, tag, s['ex_zero'], s['n']))
        elif fn.endswith('.bin') and '/event/' in p:
            try: d = open(p,'rb').read()
            except: continue
            if len(d) < 16: continue
            tot['bin'] += 1
            s = scan_table(d, 0, len(d))
            add('bin_table', s)
            if s['diff']: examples_diff.append((rel, 'bin', s['ex_diff']))
            if s['off0'] or s['alt0']: examples_zero.append((rel, 'bin', s['ex_zero'], s['n']))

print('files scanned:', tot['ebp'], '.ebp,', tot['bin'], '.bin')
for tag, a in agg.items():
    print(f"{tag}: files={a['files']} records={a['n']} off==0:{a['off0']} alt==0:{a['alt0']} off!=alt:{a['diff']} attr!=0:{a['attr']} attr2!=0:{a['attr2']} both0:{a['both0']} badoff:{a['bad']}")
print('--- examples off!=alt:', len(examples_diff))
for e in examples_diff[:20]: print('  ', e)
print('--- examples zero-field:', len(examples_zero))
for e in examples_zero[:20]: print('  ', e)
json.dump({'agg':agg,'diff':examples_diff[:200],'zero':examples_zero[:200]},
          open('/home/wanderson/Documents/ffx-editor-main/work/_ebp_edge/scan_records_out.json','w'), indent=1)
