#!/usr/bin/env python3
"""EBP/.bin text-record table scanner — FFX-STRUCTURES leva 6 (EBP-TEXT-EDGE).

Parses the 8-byte text records {u16 off, u16 attr, u16 offAlt, u16 attr2}
found in .ebp chunk1 (JP text, EV01 offset-table[1] @+8), .ebp chunk4, and
the localized sidecar new_<loc>pc/event/obj_ps3/*.bin files.

Record-table length is derived from the smallest nonzero offset of the first
record (n = first_off // 8) — the string pool begins immediately after the
table. Reports: record count, zero-field records (off==0 / offAlt==0 —
inheritance markers that trigger the EbpMessageAdrs stale-pointer path),
offAlt!=off divergences (alternate-string variants consumed by ATEL op
0x1D2 enteredAirshipPasswordEquals), attr/attr2 histograms (attr2==attr in
100%% of the measured corpus), and out-of-bounds offsets.

Usage: python3 ebp_text_records_scan.py [corpus_root] [out.json]
Evidence: docs/reverse/FFX_EBP_EDGE_CASES_2026-09-15.md (2026-09-15,
Jarvis-DEVIN leva 6). Corpus run: chunk1 21545 recs / 251 divergent,
.bin 35732 recs / 3 divergent, chunk4 18831 recs / 162 zero-pairs.
"""
import os, struct, json, sys
ROOT = sys.argv[1] if len(sys.argv) > 1 else "/mnt/nvme-xpg/ffx_ps2/ffx/master"  # canonical corpus (jppc/event/obj + new_*pc/event/obj_ps3)

def scan_table(buf, base, end):
    stats = dict(n=0, off0=0, alt0=0, diff=0, attr=0, attr2=0, both0=0, bad=0,
                 attrvals={}, attr2vals={}, ex_diff=[], ex_zero=[], ex_bad=[])
    if base < 0 or base >= len(buf) or end <= base:
        return stats
    end = min(end, len(buf))
    first_off = None
    for i in range(0x800):
        if base + i*8 + 8 > end: break
        off, attr, alt, attr2 = struct.unpack_from('<4H', buf, base + i*8)
        if off or alt:
            first_off = min(x for x in (off, alt) if x)
            break
    if first_off is None or first_off < 8:
        return stats
    n = first_off // 8
    for i in range(n):
        if base + i*8 + 8 > len(buf): break
        off, attr, alt, attr2 = struct.unpack_from('<4H', buf, base + i*8)
        stats['n'] += 1
        if off == 0: stats['off0'] += 1; stats['ex_zero'].append((i,'off',alt,attr,attr2))
        if alt == 0: stats['alt0'] += 1; stats['ex_zero'].append((i,'alt',off,attr,attr2))
        if off != alt: stats['diff'] += 1; stats['ex_diff'].append((i,off,alt,attr,attr2))
        if attr: stats['attr'] += 1; stats['attrvals'][attr]=stats['attrvals'].get(attr,0)+1
        if attr2: stats['attr2'] += 1; stats['attr2vals'][attr2]=stats['attr2vals'].get(attr2,0)+1
        if off == 0 and alt == 0: stats['both0'] += 1
        for v,tag in ((off,'off'),(alt,'alt')):
            if v and (v < first_off or base + v >= end):
                stats['bad'] += 1; stats['ex_bad'].append((i,tag,v,attr,attr2))
    stats['ex_diff']=stats['ex_diff'][:10]; stats['ex_zero']=stats['ex_zero'][:10]; stats['ex_bad']=stats['ex_bad'][:10]
    stats['attrvals']={hex(k):v for k,v in sorted(stats['attrvals'].items())}
    stats['attr2vals']={hex(k):v for k,v in sorted(stats['attr2vals'].items())}
    return stats

def bounds(offs, idx, dlen):
    o = offs[idx]
    if o == 0 or o == 0xffffffff or o >= dlen: return None
    others = [x for j,x in enumerate(offs[1:6],start=1) if j!=idx and x!=0xffffffff and x>=o]
    end = min(others) if others else dlen
    if end - o < 8: return None
    return o, end

agg = {}
def add(tag, s, rel=None):
    a = agg.setdefault(tag, dict(n=0,off0=0,alt0=0,diff=0,attr=0,attr2=0,both0=0,bad=0,files=0,attrvals={},attr2vals={}))
    a['files'] += 1
    for k in ('n','off0','alt0','diff','attr','attr2','both0','bad'): a[k]+=s[k]
    for k,v in s['attrvals'].items(): a['attrvals'][k]=a['attrvals'].get(k,0)+v
    for k,v in s['attr2vals'].items(): a['attr2vals'][k]=a['attr2vals'].get(k,0)+v

examples_diff, examples_zero, examples_bad, per_file = [], [], [], {}
neb=nb=0
for dirp,_,files in os.walk(ROOT):
    for fn in files:
        p=os.path.join(dirp,fn); rel=os.path.relpath(p,ROOT)
        if fn.endswith('.ebp'):
            try: d=open(p,'rb').read()
            except: continue
            if d[:2]!=b'EV' or len(d)<0x20: continue
            neb+=1
            offs=struct.unpack_from('<7I',d,4)
            for idx,tag in ((1,'ebp_chunk1'),(4,'ebp_chunk4')):
                b=bounds(offs,idx,len(d))
                if not b: continue
                s=scan_table(d,b[0],b[1]); add(tag,s)
                pf=per_file.setdefault(rel,{})
                pf[tag]=dict(n=s['n'],diff=s['diff'],off0=s['off0'],alt0=s['alt0'])
                if s['diff']: examples_diff.append((rel,tag,s['ex_diff']))
                if s['off0'] or s['alt0']: examples_zero.append((rel,tag,s['ex_zero'],s['n']))
                if s['bad']: examples_bad.append((rel,tag,s['ex_bad']))
        elif fn.endswith('.bin') and '/event/' in dirp+'/':
            try: d=open(p,'rb').read()
            except: continue
            if len(d)<16: continue
            nb+=1
            s=scan_table(d,0,len(d)); add('bin_table',s)
            pf=per_file.setdefault(rel,{}); pf['bin']=dict(n=s['n'],diff=s['diff'],off0=s['off0'],alt0=s['alt0'])
            if s['diff']: examples_diff.append((rel,'bin',s['ex_diff']))
            if s['off0'] or s['alt0']: examples_zero.append((rel,'bin',s['ex_zero'],s['n']))
            if s['bad']: examples_bad.append((rel,'bin',s['ex_bad']))

print('scanned:',neb,'.ebp,',nb,'.bin')
for tag,a in agg.items():
    print(f"== {tag}: files={a['files']} recs={a['n']} off0={a['off0']} alt0={a['alt0']} off!=alt={a['diff']} attr!=0={a['attr']} attr2!=0={a['attr2']} both0={a['both0']} bad={a['bad']}")
    print('   attrvals:',a['attrvals'])
    print('   attr2vals:',a['attr2vals'])
print('--- diff examples:',len(examples_diff))
for e in examples_diff[:25]: print('  ',e)
print('--- zero-field files:',len(examples_zero))
for e in examples_zero[:25]: print('  ',e)
print('--- bad-offset files:',len(examples_bad))
for e in examples_bad[:15]: print('  ',e)
json.dump({'agg':agg,'diff':examples_diff,'zero':examples_zero,'bad':examples_bad,'per_file':per_file},
          open(sys.argv[2] if len(sys.argv) > 2 else 'scan_records_out.json','w'))
