#!/usr/bin/env python3
"""gnm_modes_census.py — wave-19 GNM-MODES lane: tile_mode census across ALL
GNM `.phyre` payloads in the FFX corpus.

Residual of wave-18 GNM-DETILE (docs/reverse/FFX_GNM_DETILE_2026-09-18.md):
detile is PROVEN for tile_mode 0x0D (kTileModeThin_1dThin). This scanner asks:
does ANY shipped GNM payload declare a different tile mode?

Method: for every `.phyre` file under the GNM corpus roots (PS4 FFX_Data +
PS4FFX PKG extract, FFX-1 and FFX-2, deduped by GameData-relative path), parse
the RYHP'X' cluster with the proven `ryhpx_dds_reader.Cluster`, enumerate every
texture-object instance (PTexture2D*/PTextureCubeMap*/PTexture3D*/PTexture*Array*
ILs — NOT PTextureMipInfo/State/AtlasInfo which are helper classes), and decode
the embedded `sce::Gnm::Texture` (32B register image) at
  obj + m_texState(+0x30) + m_buffers(+0x08) + m_u(+0x08) + m_gnmTexture(+0x24)
— offsets resolved from the file's own packed-namespace member tables when
available (identical 48/8/8/36 in every sampled file; constants as fallback).

Recorded per descriptor: file, payload_idx (IL index), kind (dds/dae/ags/fx/
fgen), tile_mode + name, declared w/h, phyre format string, GNM data_format/
num_format ids, mip counts, element (block) bytes, detile_supported flag,
sha256 of the file.

Corpus layout note (verified 2026-09-19): the mission's `ffx_ps2/ffx/master`
trees contain ZERO `.phyre` files — their only GNM-marked content is
`new_*pc/help/*/GNM/*.sps2` (18 files on nvme-xpg, 0 on samsung; no T#-like
32B windows inside — not Phyre clusters). All real GNM payloads live in the
PS4 data trees below.

Usage:
  python3 gnm_modes_census.py --csv OUT.csv [--summary OUT.json] [--limit N]
"""
import argparse
import csv
import fnmatch
import glob
import hashlib
import json
import os
import struct
import sys
from collections import Counter

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ryhpx_dds_reader import Cluster
from gnm_detile import TILE_MODES

PS4X = '/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/PS4FFX/extracted'

# (game, root, preference) — preference orders canonical copies first so the
# dedupe keeps the wave-17-verified nvme copy for FFX-1.
def _roots():
    r = [('FFX', '/mnt/nvme-xpg/FFX_Data', 0)]
    for pat in ('FFX_Data_root', 'FFX_Data_P*', 'FFX_Data'):
        for p in sorted(glob.glob(os.path.join(PS4X, pat))):
            inner = os.path.join(p, 'FFX_Data')
            r.append(('FFX', inner if os.path.isdir(inner) else p, 1))
    for pat in ('FFX-2_Data_P*', 'FFX-2_Data'):
        for p in sorted(glob.glob(os.path.join(PS4X, pat))):
            inner = os.path.join(p, 'FFX-2_Data')
            r.append(('FFX-2', inner if os.path.isdir(inner) else p, 1))
    # nested partial re-extract inside ps4_extract/ (dup safety net)
    for p in sorted(glob.glob(os.path.join(PS4X, 'ps4_extract', '*'))):
        if not os.path.isdir(p):
            continue
        done = False
        for inner_name, game in (('FFX_Data', 'FFX'), ('FFX-2_Data', 'FFX-2')):
            inner = os.path.join(p, inner_name)
            if os.path.isdir(inner):
                r.append((game, inner, 2))
                done = True
        if not done:
            game = 'FFX-2' if 'FFX-2' in os.path.basename(p) else 'FFX'
            r.append((game, p, 2))
    r.append(('META', os.path.join(PS4X, 'MetaMenu'), 3))
    return r

# Texture-object instance classes (own an embedded m_texState -> GnmTexture).
# Helper classes (PTextureMipInfoGNM, PTextureStateGNM, PTextureStateBufferGNM,
# PTextureAtlasInfo, PSubTextureInfo, PTexture*Base, 'Texture') never appear as
# object ILs carrying a descriptor.
TEX_OBJ_CLASSES = {
    'PTexture2D', 'PTexture2DGNM', 'PTextureCubeMap', 'PTextureCubeMapGNM',
    'PTexture3D', 'PTexture3DGNM', 'PTexture1D', 'PTexture1DGNM',
    'PTexture2DArray', 'PTexture2DArrayGNM', 'PTexture1DArray',
    'PTexture1DArrayGNM', 'PTextureCubeMapArray', 'PTextureCubeMapArrayGNM',
    'PTexture2DMsaa', 'PTexture2DMsaaGNM',
}
NON_TEX_OBJ = {  # texture-named classes that are NOT descriptors owners
    'PTextureMipInfoGNM', 'PTextureStateGNM', 'PTextureStateBufferGNM',
    'PTextureAtlasInfo', 'PSubTextureInfo', 'PTexture2DBase',
    'PTextureCommonBase', 'Texture', 'PShaderParameterCaptureBufferTexture2D',
    'PShaderParameterCaptureBufferTextureBase',
    'PTexturePacker',   # 0x58B control object (m_border) — no GnmTexture
}

# fallback member offsets (proven w18; namespace-resolved when tables exist)
D_TEXSTATE, D_BUFFERS, D_UNION, D_GNMTEX = 0x30, 0x08, 0x08, 0x24

# GNM HW data_format id -> (name, element block bytes, block px span)
# BCn compressed: element = one block (8B for BC1/4, 16B for BC2/3/5/6/7).
# IDs proven by wave-17 (FFX_FMT_GNM_PAYLOAD §3): DXT1=35, DXT3=36, DXT5=37,
# ARGB8=10. Others mapped by Sea-Islands FMT convention (best-effort).
DATA_FORMATS = {
    0x0A: ('ARGB8', 4, 1),
    0x23: ('BC1/DXT1', 8, 4), 0x24: ('BC2/DXT3', 16, 4),
    0x25: ('BC3/DXT5', 16, 4),
    0x26: ('BC4', 8, 4), 0x27: ('BC5', 16, 4), 0x2A: ('BC6', 16, 4),
    0x2B: ('BC7', 16, 4),
}


def relkey(root, path):
    """Dedupe key: path relative to the innermost 'GameData/' dir if present."""
    p = path.replace('\\', '/')
    i = p.rfind('/GameData/')
    if i >= 0:
        return p[i + len('/GameData/'):]
    rp = os.path.relpath(path, root)
    return rp.replace('\\', '/')


def iter_phyre(root):
    for dp, _, fns in os.walk(root):
        for f in fns:
            if fnmatch.fnmatch(f.lower(), '*.phyre'):
                yield os.path.join(dp, f)


def tex_obj_offsets(c):
    """Yield (il_index, class_name, obj_file_off) for texture-object ILs."""
    off = c.obj_data
    for i, il in enumerate(c.ils):
        nm = c.classes[il[0] - 1]['name'] if 0 < il[0] <= len(c.classes) else ''
        if nm in TEX_OBJ_CLASSES:
            yield i, nm, off
        elif nm.startswith('PTexture') and nm not in NON_TEX_OBJ:
            yield i, nm, off          # unknown texture-ish class: try anyway
        off += il[2]


def _member_off(c, cls_names, member, default):
    for nm in cls_names:
        got = c._member(nm, member)
        if got is not None:
            return got
    return default


def decode_gnm_texture(c, obj_off, cls_name):
    """Decode the embedded sce::Gnm::Texture for one texture object."""
    o_ts = _member_off(c, (cls_name, cls_name + 'GNM', 'PTexture2DGNM',
                           'PTextureCubeMapGNM'), 'm_texState', D_TEXSTATE)
    o_bf = _member_off(c, ('PTextureStateGNM',), 'm_buffers', D_BUFFERS)
    o_un = _member_off(c, ('PSharray<PTextureStateBufferGNM>',), 'm_u', D_UNION)
    o_gt = _member_off(c, ('PTextureStateBufferGNM',), 'm_gnmTexture', D_GNMTEX)
    g = obj_off + o_ts + o_bf + o_un + o_gt
    if g + 32 > c.obj_end or g + 32 > len(c.d):
        return None
    dw = struct.unpack_from('<8I', c.d, g)
    return {
        'file_off': g,
        'base_addr256': dw[0],
        'data_format': (dw[1] >> 20) & 0x3F,
        'num_format': (dw[1] >> 26) & 0xF,
        'width': (dw[2] & 0x3FFF) + 1,
        'height': ((dw[2] >> 14) & 0x3FFF) + 1,
        'dst_sel': ''.join(str((dw[3] >> (3 * i)) & 7) for i in range(4)),
        'base_level': (dw[3] >> 12) & 0xF,
        'last_level': (dw[3] >> 16) & 0xF,
        'tile_mode': (dw[3] >> 20) & 0x1F,
        'pitch': ((dw[4] >> 13) & 0x3FFF) + 1,
        'depth': (dw[4] & 0x1FFF) + 1,
    }


def kind_of(path):
    b = os.path.basename(path).lower()
    for k in ('dds', 'dae', 'ags', 'fgen', 'fx', 'cgfx', 'bnk', 'ani', 'cam'):
        if ('.' + k) in b or b.startswith(k):
            return k
    return b.split('.', 1)[1].split('.')[0] if '.' in b else '?'


def sane_desc(gt):
    return (gt['data_format'] != 0 and 4 <= gt['width'] <= 16384
            and 4 <= gt['height'] <= 16384)


def scan_file(path, game, rel):
    rows = []
    try:
        c = Cluster(path)
    except Exception as e:  # noqa: BLE001 - record and continue
        return [{'game': game, 'rel': rel, 'file': path, 'kind': kind_of(path),
                 'variant': 'parse_fail', 'platform': '', 'payload_idx': -1,
                 'tex_class': '', 'tile_mode': '', 'tile_mode_name': '',
                 'width': '', 'height': '', 'format': '', 'data_format': '',
                 'num_format': '', 'elem_bytes': '', 'mips': '',
                 'payload_size': '', 'detile_supported': '',
                 'note': 'cluster_parse: %s' % e, 'sha256': ''}], {}
    sha = hashlib.sha256(c.d).hexdigest()[:16]
    is_gnm = c.variant == 'GNM/GCM' and c.platform.startswith('GNM')
    meta = {'variant': c.variant, 'platform': c.platform, 'is_gnm': is_gnm}
    ti = c.texture_info()
    objs = list(tex_obj_offsets(c)) if is_gnm else []
    if not is_gnm or not objs:
        note = ''
        if is_gnm and not objs:
            note = 'no_texture_il'
        rows.append({'game': game, 'rel': rel, 'file': path,
                     'kind': kind_of(path), 'variant': c.variant,
                     'platform': c.platform, 'payload_idx': -1, 'tex_class': '',
                     'tile_mode': '', 'tile_mode_name': '', 'width': ti.get('width', ''),
                     'height': ti.get('height', ''),
                     'format': ti.get('format', ''), 'data_format': '',
                     'num_format': '', 'elem_bytes': '', 'mips': '',
                     'payload_size': c.payload_size, 'detile_supported': 'n/a',
                     'note': note, 'sha256': sha})
        return rows, meta
    for il_idx, cls_name, obj_off in objs:
        gt = decode_gnm_texture(c, obj_off, cls_name)
        if gt is None:
            rows.append({'game': game, 'rel': rel, 'file': path,
                         'kind': kind_of(path), 'variant': c.variant,
                         'platform': c.platform, 'payload_idx': il_idx,
                         'tex_class': cls_name, 'tile_mode': '',
                         'tile_mode_name': 'desc_oob', 'width': '', 'height': '',
                         'format': ti.get('format', ''), 'data_format': '',
                         'num_format': '', 'elem_bytes': '', 'mips': '',
                         'payload_size': c.payload_size, 'detile_supported': '?',
                         'note': 'descriptor out of bounds', 'sha256': sha})
            continue
        tm = gt['tile_mode']
        finfo = DATA_FORMATS.get(gt['data_format'])
        note = '' if sane_desc(gt) else 'desc_suspect'
        rows.append({
            'game': game, 'rel': rel, 'file': path, 'kind': kind_of(path),
            'variant': c.variant, 'platform': c.platform,
            'payload_idx': il_idx, 'tex_class': cls_name,
            'tile_mode': '0x%02X' % tm,
            'tile_mode_name': TILE_MODES.get(tm, 'UNKNOWN'),
            'width': gt['width'], 'height': gt['height'],
            'format': ti.get('format', ''),
            'data_format': '0x%02X' % gt['data_format'],
            'num_format': '0x%X' % gt['num_format'],
            'elem_bytes': finfo[1] if finfo else '',
            'mips': '%d/%d' % (gt['base_level'], gt['last_level']),
            'payload_size': c.payload_size,
            'detile_supported': 'yes(Thin_1dThin)' if tm == 0x0D else 'NO',
            'note': note, 'sha256': sha})
    return rows, meta


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--csv', required=True)
    ap.add_argument('--summary', help='JSON summary output')
    ap.add_argument('--limit', type=int, default=0)
    ap.add_argument('--dups-csv', help='optional CSV of duplicate-copy hash checks')
    args = ap.parse_args()

    # ── inventory + dedupe by (game, GameData-relative path) ────────────────
    inv = {}          # (game, rel) -> [ (pref, path) ... ]
    n_scanned = 0
    for game, root, pref in _roots():
        if not os.path.isdir(root):
            continue
        for p in iter_phyre(root):
            n_scanned += 1
            inv.setdefault((game, relkey(root, p)), []).append((pref, p))
    keys = sorted(inv)
    if args.limit:
        keys = keys[:args.limit]
    print('inventory: %d raw .phyre, %d unique (game,relpath)' % (n_scanned, len(inv)),
          file=sys.stderr)

    # ── duplicate-copy hash verification ────────────────────────────────────
    dup_rows = []
    for k in keys:
        copies = inv[k]
        if len(copies) < 2:
            continue
        hashes = set()
        for _, p in copies:
            try:
                with open(p, 'rb') as fh:
                    hashes.add(hashlib.sha256(fh.read()).hexdigest()[:16])
            except OSError as e:
                hashes.add('ioerr:%s' % e)
        dup_rows.append((k[0], k[1], len(copies),
                         'same' if len(hashes) == 1 else 'DIFF', sorted(hashes)))
    if args.dups_csv:
        with open(args.dups_csv, 'w', newline='') as f:
            w = csv.writer(f)
            w.writerow(['game', 'rel', 'n_copies', 'verdict', 'sha256s'])
            w.writerows(dup_rows)
    dup_diff = sum(1 for r in dup_rows if r[3] == 'DIFF')
    print('dups: %d relpaths with >1 copy, %d with differing sha256'
          % (len(dup_rows), dup_diff), file=sys.stderr)

    # ── scan unique files ───────────────────────────────────────────────────
    all_rows = []
    stats = Counter()
    for i, k in enumerate(keys):
        copies = sorted(inv[k])
        game, rel = k
        # prefer non-empty canonical copies: sparse PKG extracts ship 0-byte
        # placeholders for relpaths whose real payload lives in another part
        nonempty = [c for c in copies if os.path.getsize(c[1]) > 0]
        path = (nonempty or copies)[0][1]
        rows, meta = scan_file(path, game, rel)
        all_rows.extend(rows)
        stats['variant/%s/%s' % (meta.get('variant'), meta.get('platform'))] += 1
        if meta.get('is_gnm'):
            stats['gnm_files'] += 1
            if all(r['payload_idx'] == -1 for r in rows):
                stats['gnm_no_tex/' + rows[0]['kind']] += 1
        if i and i % 20000 == 0:
            print('  %d/%d files...' % (i, len(keys)), file=sys.stderr)

    fields = ['game', 'rel', 'file', 'kind', 'variant', 'platform',
              'payload_idx', 'tex_class', 'tile_mode', 'tile_mode_name',
              'width', 'height', 'format', 'data_format', 'num_format',
              'elem_bytes', 'mips', 'payload_size', 'detile_supported',
              'note', 'sha256']
    with open(args.csv, 'w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=fields)
        w.writeheader()
        w.writerows(all_rows)

    # ── summary stats ───────────────────────────────────────────────────────
    tm_hist = Counter(r['tile_mode_name'] or '(none)'
                      for r in all_rows if r['payload_idx'] >= 0)
    fmt_hist = Counter(r['format'] for r in all_rows if r['payload_idx'] >= 0)
    dfmt_hist = Counter(r['data_format'] for r in all_rows if r['payload_idx'] >= 0)
    kind_hist = Counter(r['kind'] for r in all_rows)
    notes = Counter(r['note'] for r in all_rows if r['note'])
    summary = {
        'raw_phyre_seen': n_scanned,
        'unique_game_relpath': len(inv),
        'scanned': len(keys),
        'csv_rows': len(all_rows),
        'descriptors': sum(1 for r in all_rows if r['payload_idx'] >= 0),
        'tile_mode_hist': dict(tm_hist),
        'phyre_format_hist': dict(fmt_hist.most_common(30)),
        'gnm_data_format_hist': dict(dfmt_hist.most_common(40)),
        'kind_hist': dict(kind_hist.most_common(30)),
        'variant_hist': dict(stats),
        'notes': dict(notes),
        'dup_relpaths': len(dup_rows), 'dup_sha_diff': dup_diff,
    }
    print(json.dumps(summary, indent=1))
    if args.summary:
        with open(args.summary, 'w') as f:
            json.dump(summary, f, indent=1)


if __name__ == '__main__':
    main()
