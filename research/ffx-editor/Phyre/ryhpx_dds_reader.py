#!/usr/bin/env python3
"""ryhpx_dds_reader.py — standalone reader for RYHPX Phyre clusters (GNM/PS4).

Lane: Jarvis-DEVIN orchestrator (format gap closure, 2026-09-17).
Context: docs/reverse/FFX_FMT_GFXMAP_AUDIT_2026-09-16.md found ~42,277
`.dds.phyre` + ~1,314 `.dae.phyre` + ~623 `.ags.phyre` failing `bad header`
in every existing parser because they use the GNM variant `RYHP'X'`
(headerSize=0x58) instead of the PC `RYHP'T'` (0x54, PCGL/D3D11).

PROVEN this lane (corpus + the file's own packed namespace + PS3 SDK 3.70
PhyreEngine sources on disk under /mnt/nvme-samsung/PS33.70SDKOfflineInstaller):

  * PClusterHeaderBase = 0x48, 18 u32 fields, IDENTICAL for all variants
    (SDK: PhyreClusterHeader.h — marker,size,packedNamespaceSize,platformID,
    instanceListCount,arrayFixupSize/Count,pointerFixupSize/Count,
    pointerArrayFixupSize/Count,pointersInArraysCount,userFixupCount,
    userFixupDataSize,totalDataSize,headerClassInstanceCount,
    headerClassChildCount,physicsEngineID). The magic's own byte order marks
    file endianness: 'RYHP' = LE, 'PHYR' = BE.

  * Platform extension appended to the base (SDK sources):
      RYHP'T' 0x54 = D3D11/GL/GXM: +0x48 indexBufferSize, +0x4C vertexBufferSize,
                     +0x50 maxTextureBufferSize
      RYHP'X' 0x58 = GNM (PS4):   +0x48 sharedSystemMemoryBufferSize,
                     +0x4C sharedSystemMemoryBufferAlignment,
                     +0x50 sharedVideoMemoryBufferSize,
                     +0x54 sharedVideoMemoryBufferAlignment
      RYHP'H' 0x48 = Generic:     no extension (SDK "Generic" media files)
      PHYR    0x58 = GCM (PS3, big-endian): +0x48 vramBufferSize,
                     +0x4C vramBufferAlignment, +0x50 hostBufferSize,
                     +0x54 hostBufferAlignment
    The GNM field order is proven by the file's own serialized member table
    (PClusterHeaderGNM members carry valueOffset 0x48/0x4C/0x50/0x54).

  * platformID: u32 whose bytes REVERSED spell the platform tag —
    X: 0x474E4D02 -> 'GNM\\x02' (PS4). T: 0x5043474C -> 'PCGL' or
    0x44583131 -> 'DX11'. H: 0x474E5243 -> 'GNRC'. PHYR: 'GCM\\x00' (BE).

  * Everything after the header is IDENTICAL layout across variants:
    packed namespace @ headerSize (magic 0x01020304, size field ==
    PackedNamespaceSize; types/class descriptors/members/string table),
    instance-list headers (36B), object data, user fixup data + 12B table,
    header-class tables, compressed fixups, then the platform GPU payload:
      - GNM/GCM: ONE shared video/vram blob (+ shared system/host blob)
        ending exactly at EOF: filesize - payloadOff == vidSize + sysSize.
      - Generic (H): no payload (payloadOff == EOF).
      - D3D11/GL (T): index+vertex buffers then texture mip chain.

  * GNM objects use 64-bit pointer fields, so member offsets differ from
    D3D11 (PTexture2DGNM: m_mipmapCount@+0x10, m_maxMipLevel@+0x14,
    m_width@+0x28, m_height@+0x2C; D3D11 PTexture2D: +0x0C/+0x10/+0x1C/+0x20).
    This reader resolves member offsets from the packed namespace when
    available, falling back to the proven constants.

Usage:
  ryhpx_dds_reader.py <file.phyre>            dump one file
  ryhpx_dds_reader.py <dir> [pattern]         validate corpus (default *.phyre)
  ryhpx_dds_reader.py <dir> [pattern] --v     per-file lines while validating

Exit code: 0 ok / 1 usage / 2 any failures in batch mode.
"""
import os, sys, struct, fnmatch
from collections import Counter

NS_MAGIC = 0x01020304
BASE_FIELDS = (  # offset -> name (PClusterHeaderBase; SDK PhyreClusterHeader.h)
    (0x00, 'm_phyreMarker'), (0x04, 'm_size'), (0x08, 'm_packedNamespaceSize'),
    (0x0C, 'm_platformID'), (0x10, 'm_instanceListCount'), (0x14, 'm_arrayFixupSize'),
    (0x18, 'm_arrayFixupCount'), (0x1C, 'm_pointerFixupSize'), (0x20, 'm_pointerFixupCount'),
    (0x24, 'm_pointerArrayFixupSize'), (0x28, 'm_pointerArrayFixupCount'),
    (0x2C, 'm_pointersInArraysCount'), (0x30, 'm_userFixupCount'),
    (0x34, 'm_userFixupDataSize'), (0x38, 'm_totalDataSize'),
    (0x3C, 'm_headerClassInstanceCount'), (0x40, 'm_headerClassChildCount'),
    (0x44, 'm_physicsEngineID'))
TAILS = {  # headerSize -> (platform-ext field offsets, payload-law field names)
    0x58: ('GNM/GCM', ((0x48, 'm_sharedSystemMemoryBufferSize'),
                       (0x4C, 'm_sharedSystemMemoryBufferAlignment'),
                       (0x50, 'm_sharedVideoMemoryBufferSize'),
                       (0x54, 'm_sharedVideoMemoryBufferAlignment'))),
    0x54: ('D3D11/GL', ((0x48, 'm_indexBufferSize'),
                        (0x4C, 'm_vertexBufferSize'),
                        (0x50, 'm_maxTextureBufferSize'))),
    0x48: ('Generic', ()),
}
# For BE GCM files the 0x58 tail is vram/host instead of shared sys/vid —
# same offsets, renamed here only for the report.
GCM_TAIL = ((0x48, 'm_vramBufferSize'), (0x4C, 'm_vramBufferAlignment'),
            (0x50, 'm_hostBufferSize'), (0x54, 'm_hostBufferAlignment'))


def plat_name(pid, endian):
    # The platform tag is always stored MSB-first inside the u32: in a LE file
    # its bytes appear reversed on disk ('LGCP' -> 'PCGL'), in a BE file they
    # appear in natural order ('GCM\0'). Either way to_bytes('big') recovers it.
    b = pid.to_bytes(4, 'big')
    s = b.rstrip(b'\x00').decode('ascii', 'replace')
    if b and b[-1] < 0x20 and b[-1] != 0:
        s += f'\\x{b[-1]:02x}'
    return s


class Cluster:
    """Parsed RYHP cluster (LE T/X/H and BE PHYR variants).
    Raises ValueError on structurally bad input."""
    def __init__(self, path, d=None):
        self.path = path
        self.d = d if d is not None else open(path, 'rb').read()
        self._header()
        self._namespace()
        self._sections()
        self._validate()

    def _u32(self, off):
        return struct.unpack_from(self._e + 'I', self.d, off)[0]

    def _header(self):
        d = self.d
        if len(d) < 0x14:
            raise ValueError('too small')
        if d[:4] == b'RYHP':
            self._e = '<'
            self.hdr_size = d[4]
        elif d[:4] == b'PHYR':                     # big-endian file (PS3 GCM)
            self._e = '>'
            self.hdr_size = self._u32(4)
        else:
            raise ValueError('not RYHP/PHYR')
        if self.hdr_size not in TAILS or self.hdr_size > len(d):
            raise ValueError(f'bad header size 0x{self.hdr_size:X}')
        self.variant = TAILS[self.hdr_size][0]
        if self._e == '>' and self.hdr_size == 0x58:
            self.variant = 'GCM'
        self.h = {n: self._u32(off) for off, n in BASE_FIELDS}
        tail = GCM_TAIL if self.variant == 'GCM' else TAILS[self.hdr_size][1]
        self.h.update({n: self._u32(off) for off, n in tail})
        self.platform = plat_name(self.h['m_platformID'], self._e)

    def _namespace(self):
        d, hsz = self.d, self.hdr_size
        ns = self.h['m_packedNamespaceSize']
        if hsz + 0x20 > len(d):
            raise ValueError('namespace header out of bounds')
        u = lambda o: struct.unpack_from(self._e + 'I', d, o)[0]
        magic, nssz, tc, cc, mc, ss, dbc, dbs = (u(hsz + 4 * i) for i in range(8))
        if magic != NS_MAGIC:
            raise ValueError(f'bad namespace magic 0x{magic:X}')
        if nssz != ns:
            raise ValueError(f'namespace size mismatch {nssz:#x}!={ns:#x}')
        if hsz + ns > len(d):
            raise ValueError('namespace out of bounds')
        self.ns_types, self.ns_counts = tc, (cc, mc, ss)
        coff = hsz + 0x20 + 4 * tc
        self.classes, self.strings = [], b''
        if coff + 36 * cc + 24 * mc > len(d):
            return
        i32 = lambda o: struct.unpack_from(self._e + 'i', d, o)[0]
        raw = [[i32(coff + 36 * i + 4 * j) for j in range(9)] for i in range(cc)]
        moff = coff + 36 * cc
        rawm = [[u(moff + 24 * i + 4 * j) for j in range(6)] for i in range(mc)]
        so = moff + 24 * mc
        self.strings = d[so:so + ss] if so + ss <= len(d) else b''
        def S(o):
            if o >= len(self.strings):
                return '?'
            e = self.strings.find(b'\0', o)
            return self.strings[o:e if e >= 0 else len(self.strings)].decode('ascii', 'replace')
        mi = 0
        for c in raw:
            nmem = c[3]
            mems = {S(m[0]): (m[2], m[3]) for m in rawm[mi:mi + nmem]}
            self.classes.append({'name': S(c[2]), 'size': c[1] & 0xFFFFFF,
                                 'super': c[0], 'members': mems})
            mi += nmem

    def _sections(self):
        d, h = self.d, self.h
        hsz, ns, ilc = self.hdr_size, h['m_packedNamespaceSize'], h['m_instanceListCount']
        self.il_off = hsz + ns
        if ilc > 4096 or self.il_off + ilc * 36 > len(d):
            raise ValueError(f'bad instanceListCount {ilc}')
        u = lambda o: struct.unpack_from(self._e + 'I', d, o)[0]
        self.ils = [[u(self.il_off + i * 36 + 4 * j) for j in range(9)]
                    for i in range(ilc)]
        self.obj_data = self.il_off + ilc * 36               # ODS
        self.obj_end = self.obj_data + h['m_totalDataSize']  # ODE
        uf_tab = self.obj_end + h['m_userFixupDataSize']
        self.user_fixups = [[u(uf_tab + i * 12 + 4 * j) for j in range(3)]
                            for i in range(h['m_userFixupCount'])
                            if uf_tab + i * 12 + 12 <= len(d)]
        p = uf_tab + h['m_userFixupCount'] * 12
        p += h['m_headerClassInstanceCount'] * 4 + h['m_headerClassChildCount'] * 16
        p += h['m_pointerArrayFixupSize'] + h['m_pointerFixupSize'] + h['m_arrayFixupSize']
        self.payload_off = p                                  # PDO
        self.payload_size = len(d) - p

    def _validate(self):
        h = self.h
        if self.obj_end > len(self.d):
            raise ValueError('object data overruns file')
        if self.payload_off > len(self.d):
            raise ValueError('payload offset past EOF')
        if self.hdr_size == 0x58:                              # GNM + GCM
            if self.variant == 'GCM':
                want = h['m_vramBufferSize'] + h['m_hostBufferSize']
            else:
                want = (h['m_sharedVideoMemoryBufferSize'] +
                        h['m_sharedSystemMemoryBufferSize'])
            if self.payload_size != want:
                raise ValueError(
                    f'payload {self.payload_size:#x} != sharedBuffers {want:#x}')

    # ---- info extraction -------------------------------------------------
    def _member(self, cls_name, mem):
        for c in self.classes:
            if c['name'] == cls_name and mem in c['members']:
                return c['members'][mem][0]
        return None

    def texture_info(self):
        """Dict with class/format/asset/W/H/mips for PTexture2D-ish files."""
        info = {}
        ufd = self.d[self.obj_end:self.obj_end + self.h['m_userFixupDataSize']]
        strs = []
        for t, s, o in self.user_fixups:
            if o + s <= len(ufd):
                strs.append((t, ufd[o:o + s].rstrip(b'\0').decode('ascii', 'replace')))
        for t, s in strs:
            if s.startswith('P') and any(s == c['name'] for c in self.classes):
                info.setdefault('class', s)
            elif s and s.isascii() and s.isprintable() and 'format' not in info:
                info['format'] = s
        off = self.obj_data
        tex_obj = None
        for il in self.ils:
            cls = il[0]
            nm = self.classes[cls - 1]['name'] if 0 < cls <= len(self.classes) else ''
            if nm in ('PTexture2D', 'PTexture2DGNM', 'PTexture2DGL', 'PTexture2DD3D11',
                      'PTextureCubeMap', 'PTextureCubeMapGNM'):   # cube: same 0xA0 obj; m_height==0 (real dims in T#)
                tex_obj = off
            off += il[2]
        if tex_obj is not None:
            d = self.d
            gw = self._member('PTexture2DBase', 'm_width')
            gh = self._member('PTexture2DBase', 'm_height')
            gm = self._member('PTextureCommonBase', 'm_mipmapCount')
            gx = self._member('PTextureCommonBase', 'm_maxMipLevel')
            # fallbacks: 64-bit-ptr builds (GNM/GCM) 0x28/0x2C/0x10/0x14 ;
            # 32-bit-ptr builds (D3D11/GL/Generic) 0x1C/0x20/0x0C/0x10
            fb = (0x28, 0x2C, 0x10, 0x14) if self.hdr_size == 0x58 \
                else (0x1C, 0x20, 0x0C, 0x10)
            for key, got, fbo in (('width', gw, fb[0]), ('height', gh, fb[1]),
                                  ('mipmapCount', gm, fb[2]), ('maxMipLevel', gx, fb[3])):
                o = tex_obj + (got if got is not None else fbo)
                if o + 4 <= len(d):
                    info[key] = struct.unpack_from(self._e + 'I', d, o)[0]
        if self.ils:
            a = self.obj_data + self.ils[0][3]      # objectsSize -> array start
            e = self.d.find(b'\0', a, a + self.ils[0][4])
            if e > a:
                info['asset'] = self.d[a:e].decode('ascii', 'replace')
        return info


def dump_file(path):
    c = Cluster(path)
    h = c.h
    endian = 'LE' if c._e == '<' else 'BE'
    print(f"== {path}")
    print(f"   magic={c.d[:4].decode()} hdr=0x{c.hdr_size:X} {endian} "
          f"variant={c.variant} platform={c.platform} (0x{h['m_platformID']:08X})")
    for n in ('m_packedNamespaceSize', 'm_instanceListCount', 'm_totalDataSize',
              'm_userFixupCount', 'm_userFixupDataSize', 'm_arrayFixupSize',
              'm_pointerFixupSize', 'm_pointerArrayFixupSize',
              'm_headerClassInstanceCount', 'm_headerClassChildCount'):
        print(f"   {n} = {h[n]}")
    for n in h:
        if n.startswith('m_shared') or n.startswith('m_vram') or n.startswith('m_host') \
                or n in ('m_indexBufferSize', 'm_vertexBufferSize', 'm_maxTextureBufferSize'):
            print(f"   {n} = {h[n]:#x}")
    print(f"   namespace: types={c.ns_types} classes={c.ns_counts[0]} "
          f"members={c.ns_counts[1]} strs={c.ns_counts[2]:#x}")
    for i, il in enumerate(c.ils):
        nm = c.classes[il[0] - 1]['name'] if 0 < il[0] <= len(c.classes) else '?'
        print(f"   il[{i}] {nm} n={il[1]} size={il[2]:#x} obj={il[3]:#x} arr={il[4]:#x}")
    print(f"   payload @0x{c.payload_off:X} size=0x{c.payload_size:X} (EOF=0x{len(c.d):X})")
    ti = c.texture_info()
    if ti:
        print(f"   texture: {ti}")
    return c


def batch(root, pat):
    files = sorted(os.path.join(dp, f) for dp, _, fns in os.walk(root)
                   for f in fns if fnmatch.fnmatch(f.lower(), pat.lower()))
    ok, fails, variants, fmts = 0, [], Counter(), Counter()
    verbose = '--v' in sys.argv
    for p in files:
        try:
            c = Cluster(p)
            variants[f"{c.d[:4].decode('ascii','replace')}/{c.variant}/{c.platform}"] += 1
            ti = c.texture_info()
            if ti.get('format'):
                fmts[ti['format']] += 1
            ok += 1
            if verbose:
                print(f"OK  {p} payload@0x{c.payload_off:X}+0x{c.payload_size:X} {ti or ''}")
        except Exception as e:
            fails.append((p, str(e)))
            if verbose:
                print(f"FAIL {p}: {e}")
    print(f"== {len(files)} files under {root} ({pat}): ok={ok} fail={len(fails)}")
    print(f"   variants: {dict(variants)}")
    if fmts:
        print(f"   formats: {dict(fmts.most_common(12))}")
    for p, e in fails[:15]:
        print(f"   FAIL {p}: {e}")
    return 2 if fails else 0


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    if not args:
        print(__doc__)
        return 1
    if os.path.isfile(args[0]):
        try:
            dump_file(args[0])
            return 0
        except Exception as e:
            print(f"FAIL {args[0]}: {e}")
            return 2
    return batch(args[0], args[1] if len(args) > 1 else '*.phyre')

if __name__ == '__main__':
    sys.exit(main())
