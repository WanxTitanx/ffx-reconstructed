#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""ps2_otp_render.py — render f_timpos.otp page canvases to PNG.

Promoted from work/_wave13/otp_render.py (wave-13 corpus lane, 2026-09-18).
Visual proof for the .otp semantics decoded in ps2_otp_reader.py: each
record pastes its sibling .tm2 at (dstX, dstY) inside the page selected by
pageIdx; pages are sized by their sub-record's pageW/pageH. The resulting
composites reproduce the authored GS texture-page atlases.

Usage: ps2_otp_render.py OUTDIR FILE.otp...
  Writes page_<ctx>_<page>_<WxH>.png composites (+ tex_*.png when --tex).
"""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ps2_tim2_png import load_tm2, write_png
import ps2_otp_reader


def paste(canvas, cw, ch, img, iw, ih, x, y):
    for yy in range(ih):
        dy = y + yy
        if dy < 0 or dy >= ch:
            continue
        for xx in range(iw):
            dx = x + xx
            if dx < 0 or dx >= cw:
                continue
            s = (yy * iw + xx) * 4
            d = (dy * cw + dx) * 4
            if img[s + 3] == 0:
                continue
            a = img[s + 3] / 255.0
            for c in range(3):
                canvas[d + c] = int(img[s + c] * a + canvas[d + c] * (1 - a))
            canvas[d + 3] = max(canvas[d + 3], img[s + 3])


def render_otp(otp_path, outdir, dump_tex=False):
    rep = ps2_otp_reader.parse(otp_path)
    dp = os.path.dirname(otp_path)
    tag = os.path.basename(os.path.dirname(dp))
    pages = {}
    for s in rep['subRecords']:
        pages[s['pageIdx']] = {'w': s['pageW'], 'h': s['pageH'],
                               'canvas': bytearray(s['pageW'] * s['pageH'] * 4),
                               'sub': s}
    missing = []
    for r in rep['records']:
        tm2 = os.path.join(dp, r['name'])
        if not os.path.isfile(tm2):
            missing.append(r['name'])
            continue
        tw, th, rgba, info = load_tm2(tm2)
        assert (tw, th) == (r['srcW'], r['srcH']), \
            '%s dims %dx%d != otp %dx%d' % (r['name'], tw, th, r['srcW'], r['srcH'])
        pg = pages.get(r['pageIdx'])
        if pg is None:
            print('  !! %s page idx %d out of range' % (r['name'], r['pageIdx']))
            continue
        paste(pg['canvas'], pg['w'], pg['h'], rgba, tw, th, r['dstX'], r['dstY'])
        if dump_tex:
            write_png(os.path.join(outdir, 'tex_%s_%s.png' % (tag, r['name'])),
                      tw, th, rgba)
    for i, pg in pages.items():
        out = os.path.join(outdir, 'page_%s_%02d_%dx%d.png'
                           % (tag, i, pg['w'], pg['h']))
        write_png(out, pg['w'], pg['h'], pg['canvas'])
        s = pg['sub']
        print('  page %d (%dx%d, tbp=%d pxMode=%d clutBank=%d) -> %s'
              % (i, pg['w'], pg['h'], s['texTBP'], s['pxMode'],
                 s['clutBank'], os.path.basename(out)))
    if missing:
        print('  MISSING tm2:', missing)


if __name__ == '__main__':
    argv = sys.argv[1:]
    dump_tex = '--tex' in argv
    argv = [a for a in argv if a != '--tex']
    outdir = argv[0]
    os.makedirs(outdir, exist_ok=True)
    for p in argv[1:]:
        print('== %s' % p)
        render_otp(p, outdir, dump_tex=dump_tex)
