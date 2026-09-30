#!/usr/bin/env python3
# ── ryhpx_dds_decode.py — pixel decoder for .dds.phyre (RYHPX/GNM/D3D11) ─────
#
# Companion to ryhpx_dds_reader.py (which only parses the RYHPX container and
# reports the PTexture2D header). This tool extracts the GPU payload and
# decodes the actual pixels to a PNG, so baked HD menu textures can be
# compared against PS2 .fmt/.clp renders (see
# docs/reverse/FFX_FMT_CLP_PALETTE_MAP_2026-09-17.md §7).
#
# Verified (menu_it/d3d11):  meswin/battle/strtex/face_* = DXT5, icon/worldmap
# = ARGB8.  Payload = the LAST `m_maxTextureBufferSize` bytes of the file
# (D3D11 layout; the GNM variant stores the same data but GPU-tile-scrambled,
# so decode D3D11 builds for a readable image).
#
# Requires: Pillow. Usage:
#   ryhpx_dds_decode.py <file.dds.phyre> <width> <height> <fmt> <out.png> [payload_off]
#     fmt      = DXT5 | ARGB8
#     payload_off (optional, hex/dec) overrides the default EOF-0x100000 guess.
# Example:
#   ryhpx_dds_decode.py meswin.dds.phyre 1024 1024 DXT5 meswin.png 0xA60
# ──────────────────────────────────────────────────────────────────────────────
import struct
import sys


def dxt5_decode(data, w, h):
    """Decode BC3/DXT5 -> rows of (r,g,b,a). 16 B per 4x4 block."""
    img = [[(0, 0, 0, 0)] * w for _ in range(h)]
    nbx, nby = w // 4, h // 4
    for by in range(nby):
        for bx in range(nbx):
            off = (by * nbx + bx) * 16
            a0, a1 = data[off], data[off + 1]
            abits = int.from_bytes(data[off + 2:off + 8], 'little')
            apal = [a0, a1]
            if a0 > a1:
                apal += [((6 - i) * a0 + i * a1) // 7 for i in range(1, 7)]
            else:
                apal += [((4 - i) * a0 + i * a1) // 5 for i in range(1, 5)] + [0, 255]
            c0, c1 = struct.unpack_from('<HH', data, off + 8)

            def c565(c):
                return ((c >> 11) * 255 // 31,
                        ((c >> 5) & 0x3f) * 255 // 63,
                        (c & 0x1f) * 255 // 31)
            C = [c565(c0), c565(c1)]
            C.append(tuple((2 * C[0][k] + C[1][k]) // 3 for k in range(3)))
            C.append(tuple((C[0][k] + 2 * C[1][k]) // 3 for k in range(3)))
            cbits = struct.unpack_from('<I', data, off + 12)[0]
            for py in range(4):
                for px in range(4):
                    ai = (abits >> (3 * (py * 4 + px))) & 7
                    ci = (cbits >> (2 * (py * 4 + px))) & 3
                    r, g, b = C[ci]
                    img[by * 4 + py][bx * 4 + px] = (r, g, b, apal[ai])
    return img


def argb8_decode(data, w, h):
    """Decode ARGB8 (stored B,G,R,A) -> rows of (r,g,b,a)."""
    img = []
    for y in range(h):
        row = []
        for x in range(w):
            b, g, r, a = data[(y * w + x) * 4:(y * w + x) * 4 + 4]
            row.append((r, g, b, a))
        img.append(row)
    return img


def payload_slice(path, payload_off=None):
    """Return (payload_bytes, offset). Default = last 0x100000 bytes (the
    common m_maxTextureBufferSize for the 1024x1024 DXT5 menu atlases)."""
    b = open(path, 'rb').read()
    if payload_off is None:
        payload_off = len(b) - 0x100000
    return b[payload_off:], payload_off


def main(argv):
    if len(argv) < 6:
        print(__doc__)
        return 1
    from PIL import Image
    path, w, h, fmt, out = argv[1], int(argv[2]), int(argv[3]), argv[4].upper(), argv[5]
    poff = int(argv[6], 0) if len(argv) > 6 else None
    payload, off = payload_slice(path, poff)
    if fmt == 'DXT5':
        img = dxt5_decode(payload, w, h)
    elif fmt == 'ARGB8':
        img = argb8_decode(payload, w, h)
    else:
        print('unsupported fmt %r (want DXT5|ARGB8)' % fmt)
        return 2
    im = Image.new('RGBA', (w, h))
    px = im.load()
    for y in range(h):
        for x in range(w):
            px[x, y] = img[y][x]
    im.save(out)
    print('payload @%#x -> %s (%dx%d %s)' % (off, out, w, h, fmt))
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
