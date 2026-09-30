#!/usr/bin/env python3
# aabb_probe.py — L3: test AABB <-> raw-vertex relation on all 295 YNGM sections.
#
# Code-derived model (from IDA decompiles, see L3 doc section):
#   SceneProcessTick@0x921410:  ScaleDiv10 = maxAbs(AABB_float) / 4000.0
#   QuantizeVertPoolToS16@0x9281D0: s16 = (int)(float_vert / ScaleDiv10)
#                                   => TRUNC toward zero (C cast via
#                                      FFX_Magic_Float4ToInt4@0x808C70)
#                                   => float ≈ s16 * ScaleDiv10
#   SetScale10@0x928540:          mat4 diag = ScaleDiv10 * 10  => ScaleDiv10 = diag/10
#   SaveGuideMap@0x938590:        AABB written per-section; when a file has >1
#                               section the X/Z bounds are UNIONED across all
#                               sections (y/w from section 0).
#   AABB itself = bounds of the PRE-QUANTIZATION float verts
#   (ComputeAABB@0x921530 over v2[1] float4 array).
#
# Predictions to measure:
#   P1: float_bounds ~= s16_bounds * (diag/10)        (per section)
#   P2: single-section file: AABB_xz == P1 +- quantization eps
#   P3: multi-section file:  AABB_xz == union over sections of P1
#   P4: maxAbs(AABB_xz) / 4000 ~= diag/10              (self-consistency)
#
# Corpus root = the jppc dir.

import json
import os
import struct
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', '..',
                                'research_tools', 'BattleMap'))
import _parse_yngm as P


def bounds(verts):
    xs = [v[0] for v in verts]
    zs = [v[2] for v in verts]
    return (min(xs), max(xs), min(zs), max(zs))


def main(root, outdir):
    rows = []
    for path in P.iter_corpus(root):
        b = open(path, 'rb').read()
        rel = os.path.relpath(path, root)
        if b[:4] != b'MAP1' or len(b) <= P.HSZ:
            continue
        res = P.decode_yngm(b)
        if res.get('status') != 'ok':
            continue
        # full vert bounds per section (decode_record keeps all verts in 'verts')
        secs = res['sections']
        preds = []
        for s in secs:
            diag = s['mat_scale'][0]
            sd10 = diag / 10.0
            bx = bounds(s['verts'])
            preds.append((bx[0] * sd10, bx[1] * sd10, bx[2] * sd10,
                          bx[3] * sd10, sd10, bx))
        for i, s in enumerate(secs):
            amin, amax = s['aabb_min'], s['aabb_max']
            u_minx = min(p[0] for p in preds)
            u_maxx = max(p[1] for p in preds)
            u_minz = min(p[2] for p in preds)
            u_maxz = max(p[3] for p in preds)
            sd10 = preds[i][4]
            own = preds[i]
            rows.append({
                'file': rel, 'sec': i, 'nsec': len(secs),
                'diag': s['mat_scale'][0], 'sd10': sd10,
                'aabb_min': amin, 'aabb_max': amax,
                'pred_own': own[:4], 'pred_union': (u_minx, u_maxx,
                                                  u_minz, u_maxz),
                'vert_bounds_s16': own[5],
                'triCount': s['triCount'], 'vertCount': s['vertCount'],
                'meta_len': s['meta_len'],
            })
    # measure residuals
    def resid(r, key):
        return (abs(r['aabb_min'][0] - r[key][0]),
                abs(r['aabb_max'][0] - r[key][1]),
                abs(r['aabb_min'][2] - r[key][2]),
                abs(r['aabb_max'][2] - r[key][3]))
    worst_own = max(max(resid(r, 'pred_own')) for r in rows)
    worst_union = max(max(resid(r, 'pred_union')) for r in rows)
    n_own_ok = sum(1 for r in rows if max(resid(r, 'pred_own')) < max(r['sd10'], 1e-6))
    n_union_ok = sum(1 for r in rows if max(resid(r, 'pred_union')) < max(r['sd10'], 1e-6))
    single = [r for r in rows if r['nsec'] == 1]
    n_single_own = sum(1 for r in single
                       if max(resid(r, 'pred_own')) < max(r['sd10'], 1e-6))
    multi = [r for r in rows if r['nsec'] > 1]
    n_multi_union = sum(1 for r in multi
                        if max(resid(r, 'pred_union')) < max(r['sd10'], 1e-6))
    # P4: maxAbs(aabb)/4000 vs sd10
    p4_err = max(abs(max(abs(r['aabb_min'][0]), abs(r['aabb_max'][0]),
                         abs(r['aabb_min'][2]), abs(r['aabb_max'][2])) / 4000.0
                     - r['sd10']) for r in rows)
    # y stats
    yvals = [(r['aabb_min'][1], r['aabb_max'][1]) for r in rows]
    out = {
        'sections': len(rows),
        'P2_single_own_ok': '%d/%d' % (n_single_own, len(single)),
        'P3_multi_union_ok': '%d/%d' % (n_multi_union, len(multi)),
        'P_all_own_ok': '%d/%d' % (n_own_ok, len(rows)),
        'P_all_union_ok': '%d/%d' % (n_union_ok, len(rows)),
        'worst_residual_own': worst_own,
        'worst_residual_union': worst_union,
        'P4_max_err': p4_err,
        'aabb_y_values': sorted(set(yvals))[:10],
        'y_all_zero': all(a == 0 and b == 0 for a, b in yvals),
    }
    # per-file detail for the worst offenders
    scored = sorted(rows, key=lambda r: -max(resid(r, 'pred_union')))
    out['worst10'] = [{
        'file': r['file'], 'sec': r['sec'], 'nsec': r['nsec'],
        'resid_union': resid(r, 'pred_union'),
        'aabb_min': r['aabb_min'], 'aabb_max': r['aabb_max'],
        'pred_union': r['pred_union'], 'sd10': r['sd10'],
    } for r in scored[:10]]
    with open(os.path.join(outdir, 'aabb_probe.json'), 'w') as f:
        json.dump({'summary': out, 'rows': rows}, f, indent=1)
    print(json.dumps(out, indent=1))


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
