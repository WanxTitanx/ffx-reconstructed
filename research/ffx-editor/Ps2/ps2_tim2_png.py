#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""ps2_tim2_png.py — stdlib TIM2 (PS2 .tm2) -> RGBA decoder + PNG writer.

Promoted from work/_wave13/tim2_png.py (wave-13 corpus lane, 2026-09-18);
extended to decode 16bpp direct-color textures (GS PSMCT16, TIM2
imageType 1) in addition to 8bpp indexed (PSMT8, imageType 5), which is
required for the `dat_et/encount/tim/bg_1.tm2` direct-color page.

TIM2 layout used here (matches corpus; see ps2_tim2_dump.py for the full
dump tool):
    +0x00 char[4] "TIM2"
    +0x10 u32 totalSize | u32 clutSize | u32 imageSize
    +0x1C u16 headerSize | u16 clutColors
    +0x20 u8 pictFormat | u8 mipMapCount | u8 clutType | u8 imageType
    +0x24 u16 width | u16 height
    +0x28 u64 GsTex0  (TBP=bits0-13, TBW=bits14-19, PSM=bits20-25,
                       CBP=bits37-50, CPSM=bits55-58, CSM=bits61-62)
    +0x40 image data (imageSize bytes), then CLUT (clutSize bytes)

Supported imageType (TIM2 enum, NOT raw GS PSM):
    5 = PSMT8   8bpp indexed -> CLUT is 256 x RGBA32, stored in INDEX
        order (the file order already matches index order; the CSM2
        block-interleave only applies when uploading to GS VRAM).
    1 = PSMCT16 16bpp direct -> u16 per pixel, GS RGB5A1 layout
        (bits 0-4 R, 5-9 G, 10-14 B, 15 A). Alpha bit rendered opaque.

PS2 CLUT alpha convention: 0x80 == fully opaque -> scaled x2 (cap 255).

Usage: ps2_tim2_png.py FILE.tm2...   (writes FILE.png next to each input)
"""
import os
import struct
import sys
import zlib

# TIM2 imageType enum -> human name (corpus-observed subset)
IMG_TYPES = {0: "none", 1: "PSMCT16", 2: "PSMCT24", 3: "PSMCT32",
             4: "PSMT4", 5: "PSMT8"}


def write_png(path, w, h, rgba):
    """rgba = bytearray w*h*4."""
    def chunk(tag, data):
        c = tag + data
        return struct.pack('>I', len(data)) + c + struct.pack('>I', zlib.crc32(c) & 0xFFFFFFFF)
    raw = bytearray()
    stride = w * 4
    for y in range(h):
        raw.append(0)
        raw += rgba[y * stride:(y + 1) * stride]
    ihdr = struct.pack('>IIBBBBB', w, h, 8, 6, 0, 0, 0)
    png = b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', ihdr) + \
        chunk(b'IDAT', zlib.compress(bytes(raw), 6)) + chunk(b'IEND', b'')
    open(path, 'wb').write(png)


def tm2_header(d):
    """Parse the TIM2 picture header. Returns a dict."""
    if d[:4] != b'TIM2':
        raise ValueError('not tim2')
    total, clut_sz, img_sz = struct.unpack_from('<3I', d, 0x10)
    hdr_sz, ncol = struct.unpack_from('<2H', d, 0x1C)
    pict_fmt, n_mip, clut_type, img_type = struct.unpack_from('<4B', d, 0x20)
    w, h = struct.unpack_from('<2H', d, 0x24)
    tex0 = struct.unpack_from('<Q', d, 0x28)[0]
    return {'total': total, 'clutSize': clut_sz, 'imageSize': img_sz,
            'headerSize': hdr_sz, 'ncol': ncol, 'mipmaps': n_mip,
            'clutType': clut_type, 'imageType': img_type, 'w': w, 'h': h,
            'tbp': tex0 & 0x3FFF, 'tbw': (tex0 >> 14) & 0x3F,
            'psm': (tex0 >> 20) & 0x3F, 'cbp': (tex0 >> 37) & 0x3FFF,
            'cpsm': (tex0 >> 55) & 0xF}


def load_tm2(path):
    """Return (w, h, rgba bytearray, info dict) for a TIM2 file."""
    d = open(path, 'rb').read()
    info = tm2_header(d)
    w, h = info['w'], info['h']
    img = d[0x40:0x40 + info['imageSize']]
    clut = d[0x40 + info['imageSize']:0x40 + info['imageSize'] + info['clutSize']]
    rgba = bytearray(w * h * 4)
    it = info['imageType']
    if it == 5 or (it not in IMG_TYPES and info['ncol']):
        # 8bpp indexed
        for i in range(w * h):
            idx = img[i] if i < len(img) else 0
            c = idx * 4
            if c + 4 <= len(clut):
                r, g, b, a = clut[c], clut[c + 1], clut[c + 2], clut[c + 3]
                a = min(255, a * 2)  # PS2 alpha 0x80 == opaque
            else:
                r = g = b = idx
                a = 255
            o = i * 4
            rgba[o:o + 4] = bytes((r, g, b, a))
    elif it == 1:
        # 16bpp direct color — GS PSMCT16: R5|G5<<5|B5<<10|A<<15
        for i in range(w * h):
            v = struct.unpack_from('<H', img, i * 2)[0] if i * 2 + 2 <= len(img) else 0
            r = ((v & 0x1F) << 3) | ((v & 0x1F) >> 2)
            g = (((v >> 5) & 0x1F) << 3) | (((v >> 5) & 0x1F) >> 2)
            b = (((v >> 10) & 0x1F) << 3) | (((v >> 10) & 0x1F) >> 2)
            a = 255 if (v & 0x8000) else 255  # render opaque; A bit is GS-side
            o = i * 4
            rgba[o:o + 4] = bytes((r, g, b, a))
    else:
        raise ValueError('unsupported imageType %d (%s)' % (it, IMG_TYPES.get(it, '?')))
    return w, h, rgba, info


if __name__ == '__main__':
    for p in sys.argv[1:]:
        w, h, rgba, info = load_tm2(p)
        out = os.path.splitext(p)[0] + '.png'
        write_png(out, w, h, rgba)
        print('%s -> %s (%dx%d, imgType=%d %s, tbp=%d cbp=%d)' %
              (p, out, w, h, info['imageType'],
               IMG_TYPES.get(info['imageType'], '?'), info['tbp'], info['cbp']))
