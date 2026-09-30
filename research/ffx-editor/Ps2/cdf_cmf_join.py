#!/usr/bin/env python3
"""cdf_cmf_join.py — FFX .cdf/.cmf join analysis (wave13).

Evidence-backed model (see docs/reverse/FFX_CDF_CMF_JOIN_2026-09-18.md):

  .cdf = collider/target mesh set for a character's cloth binding.
      header: f32 bboxMin[3], f32 bboxMax[3]
      group header: u16 a (type? usually 0 or 2), u16 b (group index),
                    u16 count, u16 pad
      record (32B): u16 i0,i1,i2 = model-vertex indices; u16 pad;
                    3x vec2 (u,v) = corner positions in a normalized
                    [0,4096]^2 parametric space (the cloth rest layout).
      terminator: u32 0xFFFFFFFF

  .cmf = per-character binding table.
      header: u32 ver=1, u32 unk=8, u32 w2, u32 w3
      sections (aligned stream): u32 n then n x KEY (8B) + optional n x VEC3
      KEY: u16 flag, u16 idx, u32 aux
      VEC3: f32 x,y,z — barycentric position on the referenced collider
            triangle (components sum to 1.0, corpus-proven).
      idx    = triangle index into the paired cdf group
               (0xFFFF = unbound slot; vec3 is then (0,0,0))
      flag=1 <=> aux != 0: offset binding; aux is an f32 signed offset
               (~mm scale, ±330 observed)
      flag=0 : on-surface binding

  Pairing: cmf section s corresponds to the s-th cloth-flagged
      PMeshSegment of the model (.dae.phyre); the segment's `cloth`
      field selects the cdf group: group_index = cloth % 100.
      For clothModel=0 segments the section key count == the segment's
      index-buffer count (proven s003/s004/s024); clothModel=2 (some PC
      models) uses a subset/other enumeration (PARTIAL).

Usage:
  cdf_cmf_join.py <file.cdf> [file.cmf]      # join report for one pair
  cdf_cmf_join.py --batch pairs.txt          # pairs.txt lines: cdf|cmf
"""

import sys, os, struct, math

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cdf_reader
import ps2_cmf_reader


def f32(u32):
    return struct.unpack('<f', struct.pack('<I', u32 & 0xFFFFFFFF))[0]


def group_for_section(cd, sec):
    """Best-matching cdf group for a cmf section by idx-range containment.

    Returns (group_index or None, max_idx+1, candidate list).
    """
    mx = -1
    for k in sec['keys']:
        if k['idx'] != 0xFFFF and k['idx'] > mx:
            mx = k['idx']
    need = mx + 1
    cands = [gi for gi, g in enumerate(cd['groups']) if g['count'] >= need]
    return (cands, need)


def analyze(cdfp, cmfp=None):
    """Parse a cdf/cmf pair and return a join report dict."""
    if cmfp is None:
        cmfp = cdfp[:-4] + '.cmf' if cdfp.lower().endswith('.cdf') else None
    rep = {'cdf': cdfp, 'cmf': cmfp}
    try:
        cd = cdf_reader.parse(cdfp)
    except Exception as e:
        rep['cdf_error'] = str(e)
        cd = None
    try:
        cm = ps2_cmf_reader.parse(cmfp) if cmfp else None
    except Exception as e:
        rep['cmf_error'] = str(e)
        cm = None
    if cd:
        rep['cdf_eof_ok'] = cd.get('eof_ok', True)
        rep['groups'] = [{'a': g['a'], 'b': g['b'], 'count': g['count'],
                          'idx_min': min((min(r['i']) for r in g['records']),
                                         default=-1),
                          'idx_max': max((max(r['i']) for r in g['records']),
                                         default=-1)}
                         for g in cd['groups']]
    if cm:
        rep['w2'] = cm['w2']; rep['w3'] = cm['w3']
        secs = []
        for si, s in enumerate(cm['sections']):
            ks = s['keys']
            real = [k for k in ks if k['idx'] != 0xFFFF]
            vec = s.get('vec3')
            sum_ok = 0
            if vec:
                for i, k in enumerate(ks):
                    if k['idx'] == 0xFFFF:
                        continue
                    if abs(sum(vec[i]) - 1.0) <= 0.02:
                        sum_ok += 1
            cands, need = group_for_section(cd, s) if cd else ([], 0)
            secs.append({
                'index': si, 'count': s['count'],
                'real': len(real), 'markers': len(ks) - len(real),
                'idx_max': max((k['idx'] for k in real), default=-1),
                'flag1': sum(1 for k in ks if k['flag'] == 1),
                'aux_nonzero': sum(1 for k in ks if k['aux'] != 0),
                'bary_ok': sum_ok,
                'group_candidates': cands,
            })
        rep['sections'] = secs
        rep['vec3_bary_invariant'] = all(
            s['bary_ok'] == s['real'] for s in secs)
    return rep


def report_text(rep):
    out = []
    name = os.path.basename(rep['cdf'])
    out.append("== %s" % name)
    if 'cdf_error' in rep:
        out.append("  cdf ERROR: %s" % rep['cdf_error'])
    if 'cmf_error' in rep:
        out.append("  cmf ERROR: %s" % rep['cmf_error'])
    if 'groups' in rep:
        out.append("  groups: %s" % [
            (g['b'], g['count']) for g in rep['groups']])
    if 'sections' in rep:
        out.append("  w2=%d w3=%d  bary-invariant=%s" %
                   (rep['w2'], rep['w3'], rep['vec3_bary_invariant']))
        for s in rep['sections']:
            out.append("   sec%-3d n=%-5d real=%-5d mark=%-4d idxmax=%-4d "
                       "flag1=%-4d aux!=0=%-4d -> groups %s" %
                       (s['index'], s['count'], s['real'], s['markers'],
                        s['idx_max'], s['flag1'], s['aux_nonzero'],
                        s['group_candidates']))
    return '\n'.join(out)


def main(argv):
    if argv and argv[0] == '--batch':
        pairs = [l.strip().split('|') for l in open(argv[1]) if l.strip()]
        for cdfp, cmfp in pairs:
            print(report_text(analyze(cdfp, cmfp)))
        return 0
    if not argv:
        print(__doc__)
        return 1
    print(report_text(analyze(argv[0], argv[1] if len(argv) > 1 else None)))
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
