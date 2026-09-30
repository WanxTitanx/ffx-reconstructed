#!/usr/bin/env python3
"""gnm_detile.py — PS4 GNM (RYHP'X') `.dds.phyre` texture detiler.

Lane: w18 / GNM-DETILE (2026-09-18). Closes the NEWKIT-PAYLOAD caveat:
`docs/reverse/FFX_NEWKIT_PAYLOAD_2026-09-18.md` §4 proved the GNM payload is
real but left pixel decode OPEN ("PS4 GPU tiling differs from GCM's linear
BC — needs GNM detiling").

PROVEN this lane (empirically + via the file's own embedded GnmTexture):

  * The phyre PTexture2DGNM serializes a `sce::Gnm::Texture` (32B register
    image) inside PTextureStateGNM.m_buffers.m_u.m_gnmTexture
    (PTexture2D +0x30 +0x08 +0x08 +0x24). For the newkit atlases it reads:
        dataFormat=0x25 (BC3) numFormat=UNORM  w-1=511 h-1=255
        tileMode (dw3 bits20-24) = 0x0D = kTileModeThin_1dThin
  * Thin_1dThin layout (element = one 16-byte BC3 block = 4x4 px):
        micro tile = 8x8 elements (32x32 px = 1 KiB)
        within tile: Morton/Z-order, idx = interleave(x[2:0], y[2:0])
                     (x bits -> even bit positions, y bits -> odd)
        tiles: row-major over ceil(blocksW/8) x ceil(blocksH/8)
        src_off = (tileY*tilesW + tileX)*1024 + morton(bx&7,by&7)*16
    No bank/pipe swizzle (1D modes have no macro tile — verified: the
    tiled micro-tile index map is the identity on the 16x8 grid).
  * Proof vs the D3D11 reference (same authored atlas):
      - 4,458/8,192 blocks byte-exact at the mapped position;
      - every inked glyph cell lands in place (binary-ink sim >= 0.96 on
        all shared cells of font_0_0/font_0_1);
      - residual diffs are BC3 re-encode noise (PS4 ships a different
        encode of the same image) PLUS one authored difference: the PS4
        atlas omits glyph pair k=28 (g56 `適` / g57 `繰`) and repacks
        row0 one cell left. See docs/reverse/FFX_GNM_DETILE_2026-09-18.md.

Usage:
  python3 gnm_detile.py FILE.dds.phyre [--out DIR] [--glyph N]
  python3 gnm_detile.py GNM.phyre --verify D3D11.phyre [--csv OUT.csv]
"""
import argparse
import hashlib
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ryhpx_dds_reader import Cluster                 # proven RYHP/PHYR parser
from newkit_payload_extract import decode_dxt5, glyph_cell, COLS, ROWS, CW, CH

try:
    from PIL import Image
except ImportError:  # pragma: no cover
    Image = None

# GnmTileMode names (PS4 SDK / libGnm; the GnmTexture dw3[24:20] index)
TILE_MODES = {
    0x08: 'Display_LinearAligned', 0x09: 'Display_1dThin',
    0x0A: 'Display_2dThin', 0x0B: 'Display_2dXthick', 0x0C: 'Display_3dXthick',
    0x0D: 'Thin_1dThin', 0x0E: 'Thin_2dThin', 0x0F: 'Thin_2dXthick',
    0x10: 'Thin_3dXthick', 0x11: 'Thick_1dThick', 0x12: 'Thick_2dThick',
    0x13: 'Thick_2dXthick', 0x14: 'Thick_3dThick', 0x15: 'Thin_1dThick',
    0x16: 'Thin_2dThick', 0x17: 'Thin_2dXthick', 0x18: 'Thick_1dXthick',
    0x19: 'Thick_2dXthick', 0x1A: 'Thick_3dXthick', 0x1F: 'Thick_3dXthick',
}
# relative member offsets inside the serialized objects (proven by the
# packed-namespace member tables printed by ryhpx_dds_reader; GNM build =
# 64-bit pointers). tex_obj is the PTexture2D instance base.
OFF_TEXSTATE = 0x30      # PTexture2D.m_texState  (PTextureStateGNM, embedded)
OFF_BUFFERS  = 0x08      # PTextureStateGNM.m_buffers (PSharray<TexStateBuffer>)
OFF_UNION    = 0x08      # PSharray.m_u (union -> embedded PTextureStateBufferGNM)
OFF_GNMTEX   = 0x24      # PTextureStateBufferGNM.m_gnmTexture (embedded, 32B)


# ── GnmTexture (embedded register image) ────────────────────────────────────
def _tex_obj_off(c):
    """File offset of the PTexture2D-ish instance inside obj_data."""
    off = c.obj_data
    for il in c.ils:
        nm = c.classes[il[0] - 1]['name'] if 0 < il[0] <= len(c.classes) else ''
        if nm in ('PTexture2D', 'PTexture2DGNM'):
            return off
        off += il[2]
    return None


def gnm_texture_fields(c):
    """Decode the embedded sce::Gnm::Texture of a GNM phyre, or None."""
    if c.variant != 'GNM/GCM' or not c.platform.startswith('GNM'):
        return None
    to = _tex_obj_off(c)
    if to is None:
        return None
    g = to + OFF_TEXSTATE + OFF_BUFFERS + OFF_UNION + OFF_GNMTEX
    if g + 32 > c.obj_end:
        return None
    dw = struct.unpack_from('<8I', c.d, g)
    return {
        'file_off': g,
        'base_addr256': dw[0],
        'data_format': (dw[1] >> 20) & 0x3F,
        'num_format': (dw[1] >> 26) & 0xF,
        'width': (dw[2] & 0x3FFF) + 1,
        'height': ((dw[2] >> 14) & 0x3FFF) + 1,
        'dst_sel': tuple((dw[3] >> (3 * i)) & 7 for i in range(4)),
        'base_level': (dw[3] >> 12) & 0xF,
        'last_level': (dw[3] >> 16) & 0xF,
        'tile_mode': (dw[3] >> 20) & 0x1F,
        'tile_mode_name': TILE_MODES.get((dw[3] >> 20) & 0x1F, '?'),
        'pitch': ((dw[4] >> 13) & 0x3FFF) + 1,
        'depth': (dw[4] & 0x1FFF) + 1,
    }


# ── detiler ─────────────────────────────────────────────────────────────────
def _morton3(x, y):
    """3-bit Morton (Z-order) interleave: x -> even bits, y -> odd bits."""
    v = 0
    for b in range(3):
        v |= ((x >> b) & 1) << (2 * b) | ((y >> b) & 1) << (2 * b + 1)
    return v


_M3 = [[_morton3(x, y) for x in range(8)] for y in range(8)]


def detile_thin_1dthin(payload, w, h, block_bytes=16, block_px=4):
    """GNM kTileModeThin_1dThin -> linear row-major block order.

    Element = one compressed block; micro tile = 8x8 elements stored in
    Morton order; micro tiles row-major over the tile grid. Works for any
    BCn payload (block_bytes 8 for BC1/4, 16 for BC2/3/5/6/7); surfaces
    whose block dims are not multiples of 8 are padded per-tile (elements
    outside the surface are skipped).
    """
    bw, bh = (w + block_px - 1) // block_px, (h + block_px - 1) // block_px
    tw, th = (bw + 7) // 8, (bh + 7) // 8
    out = bytearray(bw * bh * block_bytes)
    for by in range(bh):
        trow = (by >> 3) * tw
        ey = by & 7
        for bx in range(bw):
            src = ((trow + (bx >> 3)) * 64 + _M3[ey][bx & 7]) * block_bytes
            dst = (by * bw + bx) * block_bytes
            out[dst:dst + block_bytes] = payload[src:src + block_bytes]
    return bytes(out)


# alias used by newkit_payload_extract (DXT5 = 16B blocks / 4px)
def detile_gnm_bc3(payload, w, h):
    return detile_thin_1dthin(payload, w, h, 16, 4)


# ── verification helpers ────────────────────────────────────────────────────
def block_stats(gnm_lin, ref_lin, w, h):
    """Per-16B-block compare of detiled GNM vs linear reference payload."""
    bw, bh = w // 4, h // 4
    exact = diffs = 0
    rows = []
    for by in range(bh):
        for bx in range(bw):
            i = (by * bw + bx) * 16
            if gnm_lin[i:i + 16] == ref_lin[i:i + 16]:
                exact += 1
            else:
                diffs += 1
            rows.append((bx, by, gnm_lin[i:i + 16] == ref_lin[i:i + 16]))
    return exact, diffs, rows


def cell_ink(rgba, w, x0, y0, cw, ch, thr=32):
    n = 0
    for y in range(y0, y0 + ch):
        o = (y * w + x0) * 4 + 3
        for x in range(cw):
            if rgba[o + x * 4] > thr:
                n += 1
    return n


def cell_ink_sim(rgba_a, rgba_b, w, x0, y0, cw, ch, thr=32):
    """Binary-ink agreement fraction over a cell (encoding-independent)."""
    same = 0
    for y in range(y0, y0 + ch):
        o = (y * w + x0) * 4 + 3
        for x in range(cw):
            if (rgba_a[o + x * 4] > thr) == (rgba_b[o + x * 4] > thr):
                same += 1
    return same / (cw * ch)


def extract_linear(c):
    """Linear (detiled) mip0 bytes for a parsed cluster."""
    ti = c.texture_info()
    w, h = ti['width'], ti['height']
    mip0 = ((w + 3) // 4) * ((h + 3) // 4) * 16
    payload = c.d[c.payload_off:c.payload_off + mip0]
    is_gnm = c.variant == 'GNM/GCM' and c.platform.startswith('GNM')
    if is_gnm:
        payload = detile_gnm_bc3(payload, w, h)
    return payload, w, h, is_gnm


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('phyre')
    ap.add_argument('--verify', help='linear (D3D11/GCM) phyre to compare against')
    ap.add_argument('--out', help='output dir for PNG artifacts')
    ap.add_argument('--glyph', type=int, default=22, help='glyph cell to crop')
    ap.add_argument('--csv', help='write per-block comparison CSV')
    args = ap.parse_args()

    c = Cluster(args.phyre)
    res = {'file': args.phyre, 'variant': c.variant, 'platform': c.platform,
           'payload_off': c.payload_off, 'payload_size': c.payload_size}
    gt = gnm_texture_fields(c)
    if gt:
        res['gnm_texture'] = gt
    ti = c.texture_info()
    res['texture'] = ti
    lin, w, h, is_gnm = extract_linear(c)
    res['detiled'] = is_gnm
    res['sha256_linear'] = hashlib.sha256(lin).hexdigest()[:16]
    rgba = decode_dxt5(lin, w, h)
    res['sha256_rgba'] = hashlib.sha256(rgba).hexdigest()[:16]

    tag = None
    if args.out and Image is not None:
        os.makedirs(args.out, exist_ok=True)
        stem = os.path.basename(args.phyre).replace('.dds.phyre', '')
        tag = 'GNMd_%s' % stem
        img = Image.frombytes('RGBA', (w, h), rgba)
        img.save(os.path.join(args.out, tag + '.png'))
        loc = glyph_cell(args.glyph)
        if loc is not None and (w, h) == (512, 256):
            _, row, col = loc
            cell = img.crop((col * CW, row * CH, col * CW + CW, row * CH + CH))
            cell.resize((CW * 4, CH * 4), Image.NEAREST).save(
                os.path.join(args.out, '%s_g%02d.png' % (tag, args.glyph)))
            res['glyph_cell'] = {'row': row, 'col': col}
        res['ink_px'] = cell_ink(rgba, w, 0, 0, w, h)

    if args.verify:
        cr = Cluster(args.verify)
        rlin, rw, rh, _ = extract_linear(cr)
        res['verify'] = {'file': args.verify, 'w': rw, 'h': rh}
        if (rw, rh) == (w, h):
            exact, diffs, rows = block_stats(lin, rlin, w, h)
            ref_rgba = decode_dxt5(rlin, w, h)
            px_diff = sum(1 for i in range(len(rgba)) if rgba[i] != ref_rgba[i])
            res['verify'].update({
                'blocks_exact': exact, 'blocks_diff': diffs,
                'rgba_byte_diff': px_diff, 'rgba_bytes': len(rgba),
                'cell_ink_sim_min': None, 'cells': [],
            })
            sims = []
            for r in range(ROWS):
                for cl in range(COLS):
                    gi, di = (cell_ink(rgba, w, cl * CW, r * CH, CW, CH),
                              cell_ink(ref_rgba, w, cl * CW, r * CH, CW, CH))
                    s = cell_ink_sim(rgba, ref_rgba, w, cl * CW, r * CH, CW, CH)
                    if gi or di:
                        res['verify']['cells'].append(
                            {'r': r, 'c': cl, 'gnm_ink': gi, 'ref_ink': di,
                             'ink_sim': round(s, 4)})
                        sims.append(s)
            res['verify']['cell_ink_sim_min'] = min(sims) if sims else None
            if args.csv:
                with open(args.csv, 'w') as f:
                    f.write('bx,by,byte_exact\n')
                    for bx, by, eq in rows:
                        f.write('%d,%d,%d\n' % (bx, by, 1 if eq else 0))
        else:
            res['verify']['error'] = 'dims differ'

    print(json.dumps(res, ensure_ascii=False))


if __name__ == '__main__':
    main()
