#!/usr/bin/env python3
"""ryhpx_extract.py — extract a real .dds from an RYHP'X' (GNM/PS4) .dds.phyre.

Lane: Jarvis-DEVIN GNM-PAYLOAD (2026-09-17).
Doc: docs/reverse/FFX_FMT_GNM_PAYLOAD_2026-09-17.md

WHAT THIS KNOWS (all proven byte-exact against PC 'd3d11' twin payloads,
2,984/3,000 random pairs, see work/_gnm/detile_*.log):

  * The RYHPX "shared video memory blob" (payload_off..EOF) for a .dds.phyre
    starts with the texture pixel data at offset 0
    (PTextureStateBufferGNM.m_offsetInAllocatedBuffer == 0 in 1,500/1,500).
    mip levels follow back-to-back; each level occupies
    ceil(blocks_w/8)*ceil(blocks_h/8)*64*elemSize bytes (8x8-element tiles,
    small mips padded to a whole tile).

  * In-tile order = Morton/Z-order of the 64 elements; tiles in row-major
    order. "element" = one BCn 4x4 block (8B DXT1, 16B DXT3/DXT5) or one
    4-byte pixel (ARGB8). This is the PS4/GCN micro-tiling selected by
    T# tiling_index=13 (Gnm 2bThin family); no macro/pipe interleave is
    observed at any FFX size (2048x2048 DXT5 verified byte-exact).

  * Cube maps (PTextureCubeMapGNM, T# type=0xB, last_array=5) are stored
    MIP-MAJOR: for each mip level, all 6 faces contiguous (each face-mip
    padded to whole tiles), each mip-group padded up to a power of two.
    DDS wants face-major, so we reorder.

  * The serialized 32-byte Gnm::Texture (T#) sits at PTextureStateBufferGNM
    +0x24 (object +0x64 for the standard PTexture2D layout); it decodes as
    a standard GCN SQ_IMG_RSRC (see decode_tsharp). In-file base_address=0;
    the loader fixes it up to the shared vidmem base at runtime.

Format map (T# data_format -> Phyre name -> DDS):
  35 DXT1/BC1, 36 DXT3/BC2, 37 DXT5/BC3, 10 ARGB8 (stored BGRA, dst_sel
  [6,5,4,7], emitted as A8R8G8B8 so the byte order is untouched).

Usage:
  ryhpx_extract.py <in.dds.phyre> [out.dds]     extract one file
  ryhpx_extract.py --info <in.dds.phyre>      decode header/T# only
  ryhpx_extract.py --verify <gnm> <pc-twin>   byte-compare vs d3d11 twin
  ryhpx_extract.py --batch <dir> <outdir> N   extract N random files
"""
import os, sys, struct, random

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ryhpx_dds_reader import Cluster

TEXCLASSES = ('PTexture2D', 'PTexture2DGNM', 'PTextureCubeMap',
              'PTextureCubeMapGNM', 'PTexture3D', 'PTexture1D')

# Phyre format name -> (isBC, element bytes, DDS fourcc or None=uncompressed)
FMT = {
    'DXT1': (True, 8, b'DXT1'), 'BC1': (True, 8, b'DXT1'),
    'DXT3': (True, 16, b'DXT3'), 'BC2': (True, 16, b'DXT3'),
    'DXT5': (True, 16, b'DXT5'), 'BC3': (True, 16, b'DXT5'),
    'ARGB8': (False, 4, None), 'RGBA8': (False, 4, None),
    'XRGB8': (False, 4, None), 'RGB8': (False, 3, None),
}
# GCN IMG_DATA_FORMAT -> Phyre name (fallback when user-fixup string absent)
DFMT = {35: 'DXT1', 36: 'DXT3', 37: 'DXT5', 10: 'ARGB8', 34: 'BC4?', 38: 'BC5?'}

MORT = [[0] * 8 for _ in range(8)]
for _y in range(8):
    for _x in range(8):
        _m = 0
        for _b in range(3):
            _m |= ((_x >> _b) & 1) << (2 * _b) | ((_y >> _b) & 1) << (2 * _b + 1)
        MORT[_y][_x] = _m


def decode_tsharp(dw8):
    """8 LE dwords -> dict of GCN SI/CIK SQ_IMG_RSRC fields."""
    u0 = dw8[0] | dw8[1] << 32
    u1 = dw8[2] | dw8[3] << 32
    w4, w5 = dw8[4], dw8[5]
    return {
        'base_addr': (u0 & ((1 << 40) - 1)) << 8,
        'min_lod': (u0 >> 40) & 0xFFF,
        'data_format': (u0 >> 52) & 0x3F,
        'num_format': (u0 >> 58) & 0xF,
        'width': (u1 & 0x3FFF) + 1, 'height': ((u1 >> 14) & 0x3FFF) + 1,
        'perf_mod': (u1 >> 28) & 7, 'interlaced': (u1 >> 31) & 1,
        'dst_sel': [(u1 >> s) & 7 for s in (32, 35, 38, 41)],
        'base_level': (u1 >> 44) & 0xF, 'last_level': (u1 >> 48) & 0xF,
        'tiling_index': (u1 >> 52) & 0x1F, 'pow2pad': (u1 >> 57) & 1,
        'mtype2': (u1 >> 58) & 1, 'atc': (u1 >> 59) & 1,
        'type': (u1 >> 60) & 0xF,
        'depth': w4 & 0x1FFF, 'pitch': ((w4 >> 13) & 0x3FFF) + 1,
        'base_array': w5 & 0x1FFF, 'last_array': (w5 >> 13) & 0x1FFF,
    }


def tex_object(c):
    """(obj_off, class_name) of the first PTexture* instance."""
    off = c.obj_data
    for il in c.ils:
        nm = c.classes[il[0] - 1]['name'] if 0 < il[0] <= len(c.classes) else ''
        if nm in TEXCLASSES:
            return off, nm
        off += il[2]
    return None, None


def texture_record(c):
    """All proven fields of the texture object (64-bit GNM layout)."""
    off, nm = tex_object(c)
    if off is None:
        return None
    u32 = lambda o: struct.unpack_from('<I', c.d, o)[0]
    nbuf = u32(off + 0x38)                 # PSharray<PTextureStateBufferGNM>.count
    bufs = []
    for i in range(min(nbuf, 8)):
        b = off + 0x40 + i * 0x48          # m_u embedded array
        bufs.append({'offsetInAllocatedBuffer': u32(b + 0x10),
                     'tsharp': decode_tsharp(
                         [u32(b + 0x24 + 4 * j) for j in range(8)])})
    return {'class': nm, 'off': off,
            'format': c.texture_info().get('format'),
            'mipmapCount': u32(off + 0x10), 'maxMipLevel': u32(off + 0x14),
            'textureFlags': u32(off + 0x18),
            'width': u32(off + 0x28), 'height': u32(off + 0x2C),
            'nbuf': nbuf, 'bufs': bufs,
            'mipInfoCount': u32(off + 0x90)}   # PArray<PTextureMipInfoGNM>.count


def mip_tiled_size(w, h, isbc, eb, level):
    """Bytes occupied by one mip level in the tiled blob (padded to tiles)."""
    mw, mh = max(1, w >> level), max(1, h >> level)
    uw, uh = (mw + 3) // 4, (mh + 3) // 4 if isbc else (mw, mh)
    if not isbc:
        uw, uh = mw, mh
    tx, ty = (uw + 7) // 8, (uh + 7) // 8
    return tx * ty * 64 * eb, uw, uh


def detile_mip(blob, off, uw, uh, eb):
    """One mip level: Morton-ordered 8x8-element tiles -> linear rows."""
    tx = (uw + 7) // 8
    lin = bytearray(uw * uh * eb)
    for ey in range(uh):
        row = (ey >> 3) * tx * 64
        yi = ey & 7
        mr = MORT[yi]
        for ex in range(uw):
            src = off + (row + (ex >> 3) * 64 + mr[ex & 7]) * eb
            dst = (ey * uw + ex) * eb
            lin[dst:dst + eb] = blob[src:src + eb]
    return bytes(lin)


def extract_linear(c, rec):
    """Return (list of per-face mip-byte lists, format) — linear order."""
    t = rec['bufs'][0]['tsharp']
    fmt = rec['format'] or DFMT.get(t['data_format'])
    if fmt not in FMT:
        raise ValueError(f'unsupported format {fmt!r} (data_format {t["data_format"]})')
    isbc, eb, _ = FMT[fmt]
    w, h = rec['width'], rec['height'] or t['height']
    nlev = rec['mipmapCount'] + 1
    if rec['mipInfoCount']:
        nlev = max(1, min(nlev, rec['mipInfoCount']))
    blob = c.d[c.payload_off + rec['bufs'][0]['offsetInAllocatedBuffer']:]
    narr = t['last_array'] + 1 if t['type'] == 0xB else max(1, t['last_array'] + 1)
    is_cube = (t['type'] == 0xB)
    faces = []
    if is_cube or narr > 1:
        # mip-major: group g at groupOff, face f at +f*tiledSize, group
        # padded to next power of two (proven on skies_cube/reflection2).
        goff = 0
        lvl_faces = []
        for lv in range(nlev):
            tsz, uw, uh = mip_tiled_size(w, h, isbc, eb, lv)
            one = [detile_mip(blob, goff + f * tsz, uw, uh, eb)
                   for f in range(narr)]
            lvl_faces.append(one)
            grp = narr * tsz
            pad = 1 << (grp - 1).bit_length() if grp & (grp - 1) else grp
            goff += max(pad, 0x1000) if grp < 0x1000 else pad
            # FFX cubes: pow2 ceiling; min observed pad unit 0x1000
        faces = [[lvl_faces[lv][f] for lv in range(nlev)] for f in range(narr)]
    else:
        off = 0
        mips = []
        for lv in range(nlev):
            tsz, uw, uh = mip_tiled_size(w, h, isbc, eb, lv)
            mips.append(detile_mip(blob, off, uw, uh, eb))
            off += tsz
        faces = [mips]
    return faces, fmt, w, h


def dds_header(w, h, fmt, nlev, mip0_size, is_cube):
    """128-byte 'DDS '+DDS_HEADER for the linear payload that follows."""
    isbc, eb, fourcc = FMT[fmt]
    pf = bytearray(32)
    struct.pack_into('<I', pf, 0, 32)
    if fourcc:
        struct.pack_into('<I', pf, 4, 0x4)           # DDPF_FOURCC
        pf[8:12] = fourcc
    else:                                             # ARGB8 = stored BGRA
        struct.pack_into('<I', pf, 4, 0x41)           # DDPF_RGB|ALPHAPIXELS
        struct.pack_into('<IIII', pf, 12, 32,
                         0x00FF0000, 0x0000FF00, 0x000000FF)
        struct.pack_into('<I', pf, 28, 0xFF000000)
    caps1 = 0x1000                                    # TEXTURE
    if nlev > 1:
        caps1 |= 0x8 | 0x400000                       # MIPMAP|COMPLEX
    caps2 = 0
    if is_cube:
        caps1 |= 0x8                                  # COMPLEX
        caps2 = 0xFE00                                # CUBEMAP|6 faces
    flags = 0x1 | 0x2 | 0x4 | 0x8 | 0x80000           # CAPS|H|W|PF|LINEARSIZE
    if nlev > 1:
        flags |= 0x20000                              # MIPMAPCOUNT
    hdr = struct.pack('<4sI', b'DDS ', 124)
    hdr += struct.pack('<IIIIII', flags, h, w, mip0_size, 0, nlev)
    hdr += b'\0' * 44 + bytes(pf)
    hdr += struct.pack('<IIIII', caps1, caps2, 0, 0, 0)
    return hdr


def extract_dds(path):
    c = Cluster(path)
    rec = texture_record(c)
    if not rec:
        raise ValueError('no PTexture* instance')
    faces, fmt, w, h = extract_linear(c, rec)
    is_cube = len(faces) > 1
    mip0 = len(faces[0][0])
    out = dds_header(w, h, fmt, len(faces[0]), mip0, is_cube)
    for f in faces:
        out += b''.join(f)
    return out, rec, fmt


def main():
    args = sys.argv[1:]
    if not args:
        print(__doc__)
        return 1
    if args[0] == '--info':
        c = Cluster(args[1])
        rec = texture_record(c)
        print(rec['class'], c.texture_info())
        for i, b in enumerate(rec['bufs']):
            print(f'buf{i}: offInBuf=0x{b["offsetInAllocatedBuffer"]:X} T#={b["tsharp"]}')
        return 0
    if args[0] == '--verify':
        g, p = Cluster(args[1]), Cluster(args[2])
        rec = texture_record(g)
        faces, fmt, w, h = extract_linear(g, rec)
        lin = b''.join(b''.join(f) for f in faces)
        pb = p.d[p.payload_off:]
        # PC twin layout: 2D = linear chain; cube = face-major (same as ours)
        print('fmt=%s %dx%d nlev=%d  gnm_linear=0x%X pc=0x%X  %s'
              % (fmt, w, h, len(faces[0]), len(lin), len(pb),
                 'EXACT' if lin == pb[:len(lin)] else 'DIFF'))
        return 0 if lin == pb[:len(lin)] else 2
    if args[0] == '--batch':
        root, outdir, n = args[1], args[2], int(args[3])
        files = [os.path.join(dp, f) for dp, _, fns in os.walk(root)
                 for f in fns if f.endswith('.dds.phyre') and
                 '/gnm/' in (dp + '/').lower()]
        random.seed(1); random.shuffle(files)
        os.makedirs(outdir, exist_ok=True)
        ok = bad = 0
        for p in files[:n]:
            try:
                dds, rec, fmt = extract_dds(p)
                out = os.path.join(outdir, os.path.basename(p)[:-6])
                open(out, 'wb').write(dds)
                ok += 1
            except Exception as e:
                bad += 1
                print('FAIL', p, e)
        print(f'batch: ok={ok} bad={bad}')
        return 0 if not bad else 2
    out = args[1] if len(args) > 1 else args[0].rsplit('.', 2)[0] + '.dds'
    dds, rec, fmt = extract_dds(args[0])
    open(out, 'wb').write(dds)
    hh = rec['height'] or rec['bufs'][0]['tsharp']['height']
    print(f'{args[0]} -> {out}  ({fmt} {rec["width"]}x{hh} '
          f'class={rec["class"]} nbuf={rec["nbuf"]})')
    return 0


if __name__ == '__main__':
    sys.exit(main())
