#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""ps2_phyre_cluster.py — RYHP(X) Phyre cluster object resolver.

Resolves the serialized object graph inside FFX `*.dae.phyre` /
`*.dds.phyre` / `*.ags.phyre` files (GNM 'X' variant seen in
PS3Data/chr/*/mdl/GNM/, also handles LE 'T'/'H' and BE 'PHYR' headers).

Built on the proven header/namespace layout of
`research_tools/Phyre/ryhpx_dds_reader.py` (2026-09-17) plus the
fixup/pointer machinery recovered from the PhyreEngine 3.1.5 SDK
sources on disk (PS3_SDK_3_70_PhyreEngine):

  - PInstanceListHeader = 9 u32 (classID,count,size,objectsSize,
    arraysSize,pointersInArraysCount,arrayFixupCount,pointerFixupCount,
    pointerArrayFixupCount) — Core/Serialization/PhyreInstanceListHeader.
  - Object data region per list = objectsSize bytes of objects followed
    by arraysSize bytes of array ("external") data.
  - File order after object data:
      userFixupData | userFixups(12B: typeID,size,offset)
      | headerClassInstances(4B) | headerClassChildren(16B)
      | compressedPointerArrayFixups | compressedPointerFixups
      | compressedArrayFixups | GPU payload
    (PClusterReaderBinary::loadCluster/fixupDataPointers).
  - Fixup streams are VLQ-compressed blocks, one block per run of
    fixups sharing a source offset/member (PhyreFixupCompression.cpp):
      matchType u8 = packType|mask ; template.unpackSource (VLQ som,
      bit0 = PE_FIXUP_SOURCE_OFFSET) ; optional common-target VLQ ;
      payload by packType (ALL/ALL_GROUPED/INCLUSIVE/EXCLUSIVE/
      BITMASK/RAW/STRIDED — see decompress_block()).
  - PPointerFixup: source member-or-offset -> destinationObject
    {list,id}+destinationOffset (class target) OR destList.arrayData
    +destinationOffset (POD target); arrayIndex selects a slot inside
    pointer arrays (Core/Serialization/Internal/
    PhyreClusterReaderBinary.cpp ~L1350).
  - PArrayFixup: source member -> {count, offset} where offset indexes
    the SOURCE list's own array-data region (fixupDataPointers).

Resolved pointers are returned as file offsets so callers can read
objects/arrays without emulating the loader. Member IDs used by
class-data-member fixups index the class's serialized member list in
namespace order (kept by the ordered member list, not a dict).

Usage:
    import ps2_phyre_cluster
    c = ps2_phyre_cluster.Cluster(path)
    c.resolve()                       # decompress + apply all fixups
    obj = c.object('PMesh', 2)        # -> (file_off, size)
    val = c.u32(off)  c.f32(off) ...  # raw reads
    tgt = c.ptr(obj_off + 0x08)       # resolved pointer -> file_off|None
"""
import struct
import sys

sys.path.insert(0, "/home/wanderson/Documents/ffx-editor-main/research_tools/Phyre")
import ryhpx_dds_reader as base


def vlq(d, p):
    """PhyreVLQUnpack — 7-bit groups, cont bit 0x80."""
    r = 0
    sh = 0
    while True:
        b = d[p]
        p += 1
        r |= (b & 0x7F) << sh
        sh += 7
        if not (b & 0x80):
            return r, p


# packType values (PFixupPackType, PhyreFixupCompression.cpp)
PK_ALL, PK_GROUPED, PK_INCL, PK_EXCL, PK_MASK, PK_RAW, PK_STRIDED = range(7)
# shared mask bits
M_SRCOFF_MEMBER = 0x01      # EXCLUDE_SOURCE_OFFSET_OR_MEMBER
M_SRCOBJ = 0x02             # EXCLUDE_SOURCE_OBJECT_ID (added, never in stream)
# pointer-fixup mask bits
PM_ARRIDX, PM_USER, PM_LIST, PM_DESTOFF = 0x08, 0x10, 0x20, 0x40
# array-fixup mask bit
AM_COUNT = 0x08


class Fixup(object):
    __slots__ = ("som", "src_obj", "dest_id", "dest_list", "dest_off",
                 "arr_idx", "user_id", "count", "offset")

    def __init__(self):
        self.som = 0
        self.src_obj = 0
        self.dest_id = 0
        self.dest_list = 0
        self.dest_off = 0
        self.arr_idx = 0
        self.user_id = 0xFFFFFFFF
        self.count = 0
        self.offset = 0

    def is_member(self):
        return not (self.som & 0x80000000)

    def member_id(self):
        return self.som

    def src_offset(self):
        return self.som & 0x7FFFFFFF


def _read_ids(d, p, mode, obj_count):
    """Yield source object IDs for INCL/EXCL/MASK/STRIDED payloads."""
    if mode == PK_INCL:
        n, p = vlq(d, p)
        ids = []
        for _ in range(n):
            if obj_count < 256:
                ids.append(d[p]); p += 1
            else:
                v, p = vlq(d, p); ids.append(v)
        return ids, p
    if mode == PK_EXCL:
        n, p = vlq(d, p)
        excl = set()
        for _ in range(n):
            if obj_count < 256:
                excl.add(d[p]); p += 1
            else:
                v, p = vlq(d, p); excl.add(v)
        return [o for o in range(obj_count) if o not in excl], p
    if mode == PK_MASK:
        nbytes = obj_count // 8 + (1 if obj_count & 7 else 0)
        bm = d[p:p + nbytes]
        p += nbytes
        return [o for o in range(obj_count) if bm[o >> 3] & (1 << (o & 7))], p
    if mode == PK_STRIDED:
        first, p = vlq(d, p)
        stride, p = vlq(d, p)
        n, p = vlq(d, p)
        return [first + i * stride for i in range(n)], p
    raise ValueError("bad id mode %d" % mode)


def decompress(d, p, kind, fixup_count, obj_count):
    """Decompress one fixup stream for one instance list.
    kind = 'ptr' (PPointerFixup) or 'arr' (PArrayFixup).
    Returns (list_of_Fixup, new_p)."""
    out = []
    while len(out) < fixup_count:
        mt = d[p]; p += 1
        pack = mt & 7
        mask = mt & ~7
        mf = mask | M_SRCOFF_MEMBER
        if obj_count == 1:
            mf |= M_SRCOBJ
        # template source
        som, p = vlq(d, p)
        tpl = Fixup()
        tpl.som = (som >> 1) | (0x80000000 if som & 1 else 0)
        if kind == 'ptr' and (mask & PM_LIST):
            tpl.dest_list, p = vlq(d, p)

        def unpack_fx(fx):
            nonlocal p
            if kind == 'ptr':
                if not (mf & PM_USER):
                    ufid, p = vlq(d, p)
                    fx.user_id = ufid - 1 if ufid else 0xFFFFFFFF
                if fx.user_id == 0xFFFFFFFF:
                    fx.dest_id, p = vlq(d, p)
                    if not (mf & PM_LIST):
                        fx.dest_list, p = vlq(d, p)
                    if not (mf & PM_DESTOFF):
                        fx.dest_off, p = vlq(d, p)
                if not (mf & PM_ARRIDX):
                    fx.arr_idx, p = vlq(d, p)
            else:
                if not (mf & AM_COUNT):
                    fx.count, p = vlq(d, p)
                fx.offset, p = vlq(d, p)

        def unpack_full(fx):
            nonlocal p
            if not (mf & M_SRCOFF_MEMBER):
                s, p = vlq(d, p)
                fx.som = (s >> 1) | (0x80000000 if s & 1 else 0)
            if not (mf & M_SRCOBJ):
                fx.src_obj, p = vlq(d, p)
            unpack_fx(fx)

        def emit(src_id, with_fx):
            fx = Fixup()
            fx.som = tpl.som
            fx.dest_list = tpl.dest_list
            fx.src_obj = src_id
            if with_fx:
                unpack_fx(fx)
            out.append(fx)

        if pack == PK_ALL:
            for i in range(obj_count):
                emit(i, True)
        elif pack in (PK_INCL, PK_EXCL, PK_MASK, PK_STRIDED):
            ids, p = _read_ids(d, p, pack, obj_count)
            if pack in (PK_INCL, PK_EXCL):
                for i in ids:
                    emit(i, False)
                for fx in out[-len(ids):]:
                    unpack_fx(fx)
            else:
                for i in ids:
                    emit(i, True)
        elif pack == PK_RAW:
            n, p = vlq(d, p)
            for _ in range(n):
                fx = Fixup()
                fx.dest_list = tpl.dest_list
                fx.som = tpl.som
                unpack_full(fx)
                out.append(fx)
        elif pack == PK_GROUPED:
            produced = 0
            while produced < obj_count:
                gpack = d[p]; p += 1
                tf = Fixup()
                tf.som = tpl.som
                tf.dest_list = tpl.dest_list
                unpack_fx(tf)
                ids, p = _read_ids(d, p, gpack, obj_count)
                for i in ids:
                    fx = Fixup()
                    fx.som = tf.som
                    fx.src_obj = i
                    fx.dest_id, fx.dest_list, fx.dest_off = \
                        tf.dest_id, tf.dest_list, tf.dest_off
                    fx.arr_idx, fx.user_id = tf.arr_idx, tf.user_id
                    fx.count, fx.offset = tf.count, tf.offset
                    out.append(fx)
                produced += len(ids)
        else:
            raise ValueError("bad packType %d @%#x" % (pack, p))
    return out, p


class Cluster(base.Cluster):
    """ryhpx_dds_reader.Cluster + ordered members + fixup resolution."""

    def _namespace(self):
        super()._namespace()
        # redo member collection keeping ORDER (member IDs index this list)
        d, hsz = self.d, self.hdr_size
        u = lambda o: struct.unpack_from(self._e + 'I', d, o)[0]
        tc, cc, mc = self.ns_types, self.ns_counts[0], self.ns_counts[1]
        coff = hsz + 0x20 + 4 * tc
        moff = coff + 36 * cc
        i32 = lambda o: struct.unpack_from(self._e + 'i', d, o)[0]
        rawm = [[u(moff + 24 * i + 4 * j) for j in range(6)]
                for i in range(mc)]

        def S(o):
            if o >= len(self.strings):
                return '?'
            e = self.strings.find(b'\0', o)
            return self.strings[o:e if e >= 0 else len(self.strings)
                                ].decode('ascii', 'replace')
        mi = 0
        for c in self.classes:
            nmem = len(c['members'])
            c['member_list'] = [
                {'name': S(m[0]), 'off': m[2], 'type': m[3],
                 'flags': m[4], 'size': m[5]}
                for m in rawm[mi:mi + nmem]]
            mi += nmem

    # ---- fixup machinery -------------------------------------------------
    def fixup_streams(self):
        """Locate the 3 compressed fixup streams. Returns dict of slices."""
        h = self.h
        p = self.obj_end + h['m_userFixupDataSize'] + \
            h['m_userFixupCount'] * 12 + \
            h['m_headerClassInstanceCount'] * 4 + \
            h['m_headerClassChildCount'] * 16
        pa = self.d[p:p + h['m_pointerArrayFixupSize']]
        p += h['m_pointerArrayFixupSize']
        pf = self.d[p:p + h['m_pointerFixupSize']]
        p += h['m_pointerFixupSize']
        af = self.d[p:p + h['m_arrayFixupSize']]
        return {'parr': pa, 'ptr': pf, 'arr': af, 'end': p +
                h['m_arrayFixupSize']}

    def resolve(self):
        """Decompress all fixups and compute resolved pointer targets.
        Fills self.lists[] = [{'name','base','stride','count','arr_base',
        'arr_size'}] and self.ptrmap {file_off_of_ptr_field: target}."""
        d = self.d
        self.lists = []
        off = self.obj_data
        for il in self.ils:
            clsid, n, sz, objsz, arrsz = il[0], il[1], il[2], il[3], il[4]
            nm = self.classes[clsid - 1]['name'] \
                if 0 < clsid <= len(self.classes) else '?'
            self.lists.append({'name': nm, 'cls': clsid, 'base': off,
                               'count': n, 'size': sz, 'objsz': objsz,
                               'stride': objsz // n if n else 0,
                               'arr_base': off + objsz, 'arr_size': arrsz})
            off += sz
        streams = self.fixup_streams()
        self.ptr_fixups = []     # (src_list_idx, Fixup)
        self.arr_fixups = []
        self.parr_fixups = []
        p = 0
        for li, il in enumerate(self.ils):
            fxs, p = decompress(streams['parr'], p, 'arr',
                                il[8], il[1])
            self.parr_fixups += [(li, f) for f in fxs]
        p = 0
        for li, il in enumerate(self.ils):
            fxs, p = decompress(streams['ptr'], p, 'ptr',
                                il[7], il[1])
            self.ptr_fixups += [(li, f) for f in fxs]
        p = 0
        for li, il in enumerate(self.ils):
            fxs, p = decompress(streams['arr'], p, 'arr',
                                il[6], il[1])
            self.arr_fixups += [(li, f) for f in fxs]

        # Apply: compute the file offset of every pointer field and its
        # resolved target.
        self.ptrmap = {}         # ptr_field_file_off -> target file_off
        self.arrays = {}         # array_member_file_off -> (count, data_off)

        # Global member table: member IDs in fixups index the namespace's
        # serialized member list across ALL classes, in order (proven on
        # s024.dae.phyre: id 0x15a -> PString.m_buffer@0).
        self.gmember = []
        for ci, cl in enumerate(self.classes):
            for m in cl.get('member_list', []):
                self.gmember.append((ci, m['off']))

        def member_off(li, fx):
            """Byte offset of the fixed-up field inside source object."""
            if fx.is_member():
                if fx.member_id() < len(self.gmember):
                    return self.gmember[fx.member_id()][1]
                return fx.member_id()
            return fx.src_offset()

        for li, f in self.arr_fixups + self.parr_fixups:
            lst = self.lists[li]
            mo = member_off(li, f)
            field_off = lst['base'] + f.src_obj * lst['stride'] + mo
            self.arrays[field_off] = (f.count, lst['arr_base'] + f.offset,
                                      f.arr_idx if f.arr_idx else None)

        for li, f in self.ptr_fixups:
            lst = self.lists[li]
            mo = member_off(li, f)
            src = lst['base'] + f.src_obj * lst['stride'] + mo
            # destination
            tgt = None
            if f.user_id != 0xFFFFFFFF:
                tgt = ('user', f.user_id)
            else:
                dl = self.lists[f.dest_list]
                if self._dest_is_pod(f, li):
                    tgt = dl['arr_base'] + f.dest_off
                else:
                    tgt = dl['base'] + f.dest_id * dl['stride'] + f.dest_off
            self.ptrmap[src] = (tgt, f.arr_idx)

    def _dest_is_pod(self, f, src_li):
        """Heuristic: destination is POD array data iff the destination
        list's objects have no class members at that offset — i.e. the
        offset lands past objectsSize (into array data) or the target
        class is a plain-data class (PMatrix4/PVertexStream/PInt32...).
        We approximate the SDK: class target when dest_off resolves
        inside a dest object AND the dest class is a PBase descendant.
        Simplest robust rule: if dest_off >= dest object's stride, it
        must be POD array data; else treat as object pointer."""
        dl = self.lists[f.dest_list]
        if f.dest_off >= dl['stride'] and dl['stride']:
            return True
        return False

    # ---- convenience -----------------------------------------------------
    def object(self, cls_name, idx=0, which=0):
        """file offset of object `idx` in the first list named cls_name."""
        hits = [l for l in self.lists if l['name'] == cls_name]
        if not hits:
            raise KeyError(cls_name)
        l = hits[which]
        return l['base'] + idx * l['stride']

    def list_named(self, cls_name):
        return [l for l in self.lists if l['name'] == cls_name]

    def u32(self, o):
        return struct.unpack_from(self._e + 'I', self.d, o)[0]

    def u16(self, o):
        return struct.unpack_from(self._e + 'H', self.d, o)[0]

    def u8(self, o):
        return self.d[o]

    def f32(self, o):
        return struct.unpack_from(self._e + 'f', self.d, o)[0]

    def ptr(self, field_off):
        """Resolved target of pointer field at file offset, or None."""
        v = self.ptrmap.get(field_off)
        return v[0] if v else None

    def array(self, member_off):
        """(count, data_file_off) for an array member field, or None."""
        v = self.arrays.get(member_off)
        if v:
            return v[0], v[1]
        return None


if __name__ == "__main__":
    c = Cluster(sys.argv[1])
    c.resolve()
    print("lists:")
    for i, l in enumerate(c.lists):
        print("  [%d] %s n=%d base=%#x stride=%#x arr=%#x+%#x"
              % (i, l['name'], l['count'], l['base'], l['stride'],
                 l['arr_base'], l['arr_size']))
    print("ptr fixups=%d arr fixups=%d parr fixups=%d"
          % (len(c.ptr_fixups), len(c.arr_fixups), len(c.parr_fixups)))
    print("arrays resolved=%d ptrs resolved=%d"
          % (len(c.arrays), len(c.ptrmap)))
