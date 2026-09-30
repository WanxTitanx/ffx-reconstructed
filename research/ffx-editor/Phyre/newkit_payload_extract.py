#!/usr/bin/env python3
"""newkit_payload_extract.py — extract the REAL bitmap payload out of any
`newkit_ftc/*.dds.phyre` variant (PC `RYHPT`/D3D11, PS4 `RYHPX`/GNM,
PS3 `PHYR`/GCM), decode the DXT mip0 to PNG, and crop the glyph-22 (`ー`
U+30FC chōonpu) atlas cell as proof.

WHY this exists (2026-09-18, lane w17 / NEWKIT-PAYLOAD):
  FONT-RUNTIME (docs/reverse/FFX_FONT_RUNTIME_2026-09-18.md §5) proved the
  PC exe loads slot5 pixels from `menu[_kr,_ch]/newkit_ftc` D3D11 phyre
  textures, and the PS2 `.ftc` is a 128B metrics stub — but no lane had
  decoded the PC cluster itself. This tool closes that: parse ANY variant
  with the proven ryhpx_dds_reader Cluster parser, take the contiguous
  payload (`mip chain` for T, shared-video blob for X, vram blob for PHYR),
  DXT5-decode it and render the glyph cell the char table/OCR pipeline
  identified (docs/reverse/data/wave13/newkit_char_table.csv).

Atlas layout (PROVEN, docs/reverse/FFX_FMT_FTC_RESIDUAL_2026-09-17.md §2.2 +
research_tools/Ps2/newkit_glyph_cells.py):
    page = g & 1 ; k = g >> 1 ; row = (ROWS-1) - k//COLS ; col = k%COLS
    COLS=9 ROWS=4 CW=56 CH=64  ->  glyph 22 = page0, row2, col2 (x112,y128)

Usage:
  python3 newkit_payload_extract.py <file.dds.phyre> [--out DIR] [--glyph N]
  python3 newkit_payload_extract.py A.phyre B.phyre ... --out DIR --compare

Outputs (per input): <tag>.png full atlas, <tag>_gNN.png glyph cell crop,
<tag>.bin raw payload, plus JSON lines on stdout (variant/format/W/H/payload
off+size, sha256 of raw payload and of decoded RGBA — identical hashes across
platforms prove the same authored atlas ships everywhere).
"""
import argparse
import hashlib
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ryhpx_dds_reader import Cluster  # proven RYHP/PHYR parser (lane Jarvis-DEVIN)

try:
    from PIL import Image
except ImportError:  # pragma: no cover - PIL optional, PNGs skipped without it
    Image = None

# Atlas grid (same constants as newkit_glyph_cells.py)
COLS, ROWS, CW, CH = 9, 4, 56, 64


# ── DXT5 (BC3) block decoder ────────────────────────────────────────────────
# Copied verbatim from work/parallel-zcode-20260905/H-dds-phyre-decode/
# scripts/extract_phyre_dds.py (Jarvis-ZCODE, 2026-09-05) — proven on 374/374
# real GCM font clusters. DXT payloads are linear row-major on GCM and D3D11;
# GNM (PS4) is GPU-tiled (Thin_1dThin micro tiles, Morton inside) — extract_one
# detiles it via gnm_detile.detile_gnm_bc3 (PROVEN w18, 2026-09-18).

def _rgb565(v):
    r = (v >> 11) & 0x1F
    g = (v >> 5) & 0x3F
    b = v & 0x1F
    return (r << 3) | (r >> 2), (g << 2) | (g >> 4), (b << 3) | (b >> 2)


def _color_palette(c0, c1):
    p0, p1 = _rgb565(c0), _rgb565(c1)
    pal = [p0, p1]
    if c0 > c1:
        pal.append(tuple((2 * p0[i] + p1[i]) // 3 for i in range(3)))
        pal.append(tuple((p0[i] + 2 * p1[i]) // 3 for i in range(3)))
    else:
        pal.append(tuple((p0[i] + p1[i]) // 2 for i in range(3)))
        pal.append((0, 0, 0))
    return pal


def decode_dxt5(payload, w, h):
    img = bytearray(w * h * 4)
    bw, bh = (w + 3) // 4, (h + 3) // 4
    off = 0
    for by in range(bh):
        for bx in range(bw):
            a0, a1 = payload[off], payload[off + 1]
            abits = payload[off + 2:off + 8]
            off += 8
            aval = [0] * 16
            acc = int.from_bytes(abits, 'little')
            for i in range(16):
                aval[i] = (acc >> (3 * i)) & 7
            if a0 > a1:
                apal = [a0, a1,
                        (6 * a0 + 1 * a1) // 7, (5 * a0 + 2 * a1) // 7,
                        (4 * a0 + 3 * a1) // 7, (3 * a0 + 4 * a1) // 7,
                        (2 * a0 + 5 * a1) // 7, (1 * a0 + 6 * a1) // 7]
            else:
                apal = [a0, a1,
                        (4 * a0 + 1 * a1) // 5, (3 * a0 + 2 * a1) // 5,
                        (2 * a0 + 3 * a1) // 5, (1 * a0 + 4 * a1) // 5,
                        0, 255]
            c0, c1 = struct.unpack_from('<HH', payload, off)
            off += 4
            bits = struct.unpack_from('<I', payload, off)[0]
            off += 4
            pal = _color_palette(c0, c1)
            for py in range(4):
                for px in range(4):
                    i = py * 4 + px
                    ci = (bits >> (2 * i)) & 3
                    r, g, b = pal[ci]
                    o = (((by * 4 + py) * w) + bx * 4 + px) * 4
                    img[o:o + 4] = bytes((r, g, b, apal[aval[i]]))
    return bytes(img)


DECODERS = {'DXT1': None, 'DXT3': None, 'DXT5': decode_dxt5}


def glyph_cell(g):
    """Bank-5 glyph index -> (page,row,col); PROVEN map (see module docstring)."""
    page = g & 1
    k = g >> 1
    row = (ROWS - 1) - k // COLS
    if row < 0:
        return None
    return page, row, k % COLS


def extract_one(path, outdir, glyph):
    c = Cluster(path)
    ti = c.texture_info()
    res = {
        'file': path,
        'variant': c.variant, 'platform': c.platform,
        'endian': 'LE' if c._e == '<' else 'BE',
        'payload_off': c.payload_off, 'payload_size': c.payload_size,
        'texture': ti,
    }
    w, h, fmt = ti.get('width'), ti.get('height'), ti.get('format')
    if not (w and h and fmt):
        res['error'] = 'no texture dims/format'
        return res
    if fmt != 'DXT5':
        res['error'] = 'format %s not decoded here' % fmt
        return res
    payload = c.d[c.payload_off:c.payload_off + c.payload_size]
    # mip0 size for DXT5 = 1 byte per stored pixel, 4x4 blocks
    mip0 = ((w + 3) // 4) * ((h + 3) // 4) * 16
    res['mip0_size'] = mip0
    if len(payload) < mip0:
        res['error'] = 'payload %d < mip0 %d' % (len(payload), mip0)
        return res
    # GNM (PS4) payloads are GPU-tiled (kTileModeThin_1dThin per the embedded
    # sce::Gnm::Texture): 8x8-block micro tiles, Morton order inside, tiles
    # row-major. Detile to linear before decoding — PROVEN 2026-09-18
    # (research_tools/Phyre/gnm_detile.py; docs/reverse/FFX_GNM_DETILE_2026-09-18.md).
    raw_mip0 = payload[:mip0]
    if c.variant == 'GNM/GCM' and c.platform.startswith('GNM'):
        from gnm_detile import detile_gnm_bc3
        raw_mip0 = detile_gnm_bc3(raw_mip0, w, h)
        res['detiled'] = 'Thin_1dThin'
    rgba = decode_dxt5(raw_mip0, w, h)
    res['sha256_payload'] = hashlib.sha256(payload[:mip0]).hexdigest()[:16]
    res['sha256_rgba'] = hashlib.sha256(rgba).hexdigest()[:16]

    # tag: <platform>_<menu-dir>_<file> e.g. DX11_menu_font_0_0
    stem = os.path.basename(os.path.splitext(os.path.splitext(path)[0])[0])
    menu_dir = ''
    parts = path.replace('\\', '/').split('/')
    for seg in parts:
        if seg.startswith('menu'):
            menu_dir = seg
    plat = c.platform.replace('\\x02', '').replace('\x00', '').strip() or c.variant
    tag = '%s_%s_%s' % (plat, menu_dir or 'x', stem)
    tag = ''.join(ch if ch.isalnum() or ch in '_-' else '_' for ch in tag)
    res['tag'] = tag

    if outdir:
        os.makedirs(outdir, exist_ok=True)
        with open(os.path.join(outdir, tag + '.bin'), 'wb') as f:
            f.write(payload[:mip0])
        if Image is not None:
            img = Image.frombytes('RGBA', (w, h), rgba)
            img.save(os.path.join(outdir, tag + '.png'))
            loc = glyph_cell(glyph)
            # glyph map is proven only for the JP 512x256 two-page atlas;
            # kr/ch atlases have different dims+charset (not the same map)
            page_ok = (w, h) == (512, 256)
            if loc is not None and page_ok and loc[0] == (0 if 'font_0_0' in path else 1):
                # cell lives on this page's atlas
                _, row, col = loc
                cell = img.crop((col * CW, row * CH, col * CW + CW, row * CH + CH))
                cell.resize((CW * 4, CH * 4), Image.NEAREST).save(
                    os.path.join(outdir, '%s_g%02d.png' % (tag, glyph)))
                res['glyph'] = glyph
                res['glyph_cell'] = {'row': row, 'col': col,
                                     'x': col * CW, 'y': row * CH}
            # ink stats: alpha>32 pixels, glyph-cell ink
            a = img.split()[3]
            res['ink_px'] = sum(1 for v in a.getdata() if v > 32)
    return res


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('files', nargs='+')
    ap.add_argument('--out', help='output dir for PNG/BIN artifacts')
    ap.add_argument('--glyph', type=int, default=22, help='glyph to crop (default 22 = ー)')
    ap.add_argument('--compare', action='store_true',
                    help='also print payload/rgba hash comparison across inputs')
    args = ap.parse_args()

    results = []
    for p in args.files:
        try:
            r = extract_one(p, args.out, args.glyph)
        except Exception as e:  # noqa: BLE001 - report and continue batch
            r = {'file': p, 'error': str(e)}
        results.append(r)
        print(json.dumps(r, ensure_ascii=False))

    if args.compare and len(results) > 1:
        groups = {}
        for r in results:
            key = (r.get('texture', {}).get('width'),
                   r.get('texture', {}).get('height'),
                   r.get('sha256_rgba'))
            groups.setdefault(key, []).append(r['tag'])
        print('== compare (w,h,rgba_sha) groups:')
        for k, v in groups.items():
            print('   %s -> %s' % (k, v))


if __name__ == '__main__':
    main()
