#!/usr/bin/env python3
# ── map1_families.py — MAP1 (mapout.vpa) family classifier + decoders (families 2/3/4) ──
#
# Purpose: classify every mapout.vpa of the PS2 corpus by encounter-zone family and
# decode the zone payloads for families 2 (float32 transform, mihn), 3 (indirect
# triangle, kami) and 4 (YNDT/YNGM guide map). Family 1 (s16 sentinel-framed rings,
# bika) is decoded here as well for cross-checking because it shares the s16 stream
# machinery — the product decoder (FfxLib MapoutVpa_EncounterZones) already covers it.
#
# RE grounding (see docs/reverse/FFX_CODEC_P1_MAP1_2026-09-14.md for the full method):
#   - Runtime consumer 0x9097C0 FFX_FieldMap_ProcessMapDataBlob treats the 0x80-byte
#     MAP1 header as a DWORD SLOT TABLE: v2[4]=+0x10 scene(YNDT/YNPR/YNSC/YNTM),
#     v2[5]=+0x14 GS DMA packet (eC!), v2[14]=+0x38 PPP resource (meta/dispatch),
#     v2[15]=+0x3C guide map -> Yn_GuideMapSetData -> StringLoadHelper (0x91AA60),
#     v2[16]=+0x40 Yn_FpSetData. FFX_FieldMap_CheckMagicMAP (0x907F00) is the generic
#     slot reader: returns blob + u32(blob + 4*idx + 16) when magic == "MAP1".
#     There is NO family selector field in the header: families are encodings of the
#     zone blobs referenced by the meta-block dispatch table (offline source data for
#     the ffxmap.id runtime compilation).
#   - Dispatch table: meta block at u32@0x38; table at meta+u32(meta+0x1C); rows of
#     8 bytes {u16 key, u16 tag, u32 blobOff}; blobOff is RELATIVE TO THE GEOMETRY
#     SLOT u32@0x18 (verified: meta+off lands on the u16 index tail that closes the
#     table in every probed file; geom+off lands on structured payload).
#   - Zone tags: 0x19, 0x71, 0x0004. Consecutive zone rows advance by 0x32 (50B)
#     in families 1/2/4-style streams.
#
# Derived layouts (this file, measured on the 491-file corpus 2026-09-14):
#   Family 1 (s16 sentinel-framed): stream of 16B triangle records
#     {3x (s16 X, s16 Z), (u16 flags, -2)}; flags observed: 0x00,0x01,0x30,0x31,
#     0x80,0x81,0xB0,0xB1 optionally OR 0x8000; scale 1/256.
#   Family 2 (float32 transform, mihn): zone blob = 50B (0x32) record, mostly
#     zeros/identity floats (1.0f x3, -4.0f observed); the actual sentinel-framed
#     ring stream lives elsewhere in the geometry block (found by scan). The
#     record->ring reference mechanism is RE-PENDING (documented as a limitation;
#     nothing is invented).
#   Family 3 (indirect triangle, kami): blob = {u16 count, u16 pad0} then 32B
#     records: {3x (s16 X, s16 Z) verts @+0x00, 3x u32 reloc @+0x0C (all in
#     [0x80000000,0x82000000)), 4x u16 indices @+0x18 (p,q,r,0)}.
#   Family 4 (YNDT guide): section at u32@0x3C: "YNDT", "YNGM" @+0x10,
#     u16 triCount @+0x38, u16 vertCount @+0x3A, u16 const 68 @+0x3E,
#     triCount x 20B records @+0x58 {3x u32 0x80xxxxxx, u16 iA,iB,iC, u16 0},
#     vertex pool IMMEDIATELY after (no padding!) = vertCount x 6B (s16 X,Y,Z),
#     "YNED" end marker at a VARIABLE distance (matrix/painting data between).
#     ERRATA vs FFX_STRUCTURE_COMPLETE §11.29 measured here:
#       * "+0x44 triCount dup" is FALSE corpus-wide (0/262)
#       * vertex-pool alignment padding does NOT exist (0/262) — the legacy C#
#         skip-zeros loop skips REAL (0,0,0) vertices
#       * "Y always 0" is FALSE (nonzero-Y vertices in 185/262 files)
#
# Credits: container/dispatch model from docs/reverse/FFX_STRUCTURE_COMPLETE_2026-09-14.md
# §8.13/§11.29 and research_tools/BattleMap/MapoutVpa_EncounterZones_Full.cs (family-1
# reference decoder, 2026-08-19); families 2/3 layouts, base-slot proof and family-4
# errata derived in this tool (FFX-STRUCTURES lane, CODEC-BUILDER wave 3, 2026-09-14).
#
# ── 2026-09-15 UPDATE (FFX-STRUCTURES lane, subagent MAP1-FAM23) — record stream ──
# The dispatch table is a SIZE-TAGGED RECORD STREAM, closing families 2-3:
#   * LAW (corpus-wide, 139 distinct tags / ~1400 rows): the u16 `tag` of a dispatch
#     row IS the record size in u16 units (size = 2*tag). Consecutive rows sorted by
#     offset tile the record region contiguously (measured: exact tiling in every
#     probed file; see docs/reverse/FFX_MAP1_FAMILIES_23_2026-09-15.md).
#   * The zone "families" 2/3 are CONTENT SHAPES of that stream, and streams RUN
#     ACROSS chunk boundaries (a dispatch row is a zone-ownership window over a
#     continuous record stream; boundaries may cut records mid-way, e.g. kami03 +2).
#   * ERRATA (vs 2026-09-14 reading): the "relocation pointers" of family 3 are
#     RGBA COLORS (same finding as YNGM errata Y3): alpha byte 0x80 dominant, plus
#     0x5B/0xC8/0x40/0x20/0x1C/0x00 ramps (cdsp00). The [0x80000000,0x82000000)
#     "band" was alpha=0x80 + small blue channel, not an address range.
# Content shapes derived (sliding-anchor decoders below):
#   soup32  32B {u32 id/pad, 3x u32 packed (s16 X, s16 Z) verts, 3x u32 RGBA,
#                u16 p, u16 q}                      — kami03 (F3 strict)
#   paint20 20B {u32 0x40, 3x u32 RGBA, u16 j, u16 i} — mtgz00/kino04/mtgz02
#   quad40  40B {4x u32 packed verts, 4x u32 RGBA, 4x u16 idx} — idx either
#            +1 grid quads (bsyt01/bvyt09/mtgz01) or pool refs (bsil00/cdsp00)
#   edge24  24B {4x u32 RGBA, 4x u16 idx}            — mtgz00 tail (edge strip)
#   range16 16B {u32 start, u32 end, u32 id, u16 f, u16 k} — kino05 (pool ranges)
#   xform   0x32 float transform records (F2, mihn00) — unchanged from 2026-09-14
#
# Usage:
#   python3 map1_families.py <corpus_ffx_ps2_root> [--out DIR]
#     corpus root = directory that contains ffx/master/jppc/{map,btlmap}
# Emits (deterministic, no timestamps):
#   DIR/map1_families_report.json  — per-file records + aggregate
#   DIR/map1_families_dump.txt     — stable per-file dump
# Exit code 0 unless the corpus root is missing.
#
# RESEARCH TOOL — stdlib only, no game data is modified.

import argparse
import json
import os
import struct
import sys
from collections import Counter

HSZ = 0x80                    # MAP1 header size
ZONE_TAGS = (0x19, 0x71, 0x0004)
SENT_FLAGS = {0x00, 0x01, 0x30, 0x31, 0x80, 0x81, 0xB0, 0xB1}  # | 0x8000 optional
S16_SCALE = 1.0 / 256.0
REL_LO, REL_HI = 0x80000000, 0x82000000  # alpha-0x80 color band (legacy "relocs")
MAX_DISPATCH_ROWS = 512
MAX_F3_RECORDS = 8192
MAX_F1_TRIANGLES = 65536
MAX_STREAM_RECORDS = 65536    # safety cap for the record-stream decoders

# Alphas observed in color slots of the record stream (2026-09-15 corpus survey):
# 0x80 dominant; 0x5B (kami03), 0xC8 (mtgz00), 0x40/0x20/0x1C/0x00 (cdsp00 ramps).
COLOR_ALPHAS = {0x00, 0x1C, 0x20, 0x40, 0x5B, 0x80, 0xC8}


def u16(b, o): return struct.unpack_from('<H', b, o)[0]
def i16(b, o):
    v = u16(b, o)
    return v - 0x10000 if v >= 0x8000 else v
def u32(b, o): return struct.unpack_from('<I', b, o)[0]


def fourcc(b, o):
    if o + 4 > len(b):
        return None
    return b[o:o + 4].decode('ascii', 'replace').replace('\x00', '')


# ── header / dispatch ──────────────────────────────────────────────────────────

def parse_header(b):
    """Slot-table view of the 0x80-byte MAP1 header (runtime model of 0x9097C0)."""
    slots = {}
    for off in (0x10, 0x14, 0x18, 0x1C, 0x20, 0x38, 0x3C, 0x40):
        v = u32(b, off) if len(b) >= off + 4 else 0
        slots['%02X' % off] = {'off': v, 'magic': fourcc(b, v) if 0 < v < len(b) - 4 else None}
    return slots


def read_dispatch(b):
    """Read 8B rows {key,tag,blobOff} until terminator/implausible offset.

    WHY these stop rules: the table is followed by a u16 index tail; reading past
    the table produces packed-u16 garbage. Real rows always have blobOff >= the
    table's own relative offset (blobs live after the table) and land in-bounds
    when geom-based. Both rules were verified on bika03/mihn00/kami03/azit00.
    """
    geom = u32(b, 0x18) if len(b) >= 0x1C else 0
    meta = u32(b, 0x38) if len(b) >= 0x3C else 0
    if not (0 < meta < len(b) - 0x20):
        return geom, meta, None, []
    drel = u32(b, meta + 0x1C)
    dabs = meta + drel
    if not (0 < drel and dabs + 8 <= len(b)):
        return geom, meta, None, []
    rows = []
    pos = dabs
    for _ in range(MAX_DISPATCH_ROWS):
        if pos + 8 > len(b):
            break
        k, t, o = u16(b, pos), u16(b, pos + 2), u32(b, pos + 4)
        if k == 0 and t == 0 and o == 0:
            break
        if o < drel or o >= len(b) or geom + o + 0x20 > len(b):
            break  # past-table garbage (packed u16 tail)
        rows.append({'key': k, 'tag': t, 'off': o, 'blob': geom + o})
        pos += 8
    return geom, meta, dabs, rows


def zone_rows(rows, b):
    """Zone-tagged rows whose blob is fully in bounds for shape sniffing."""
    return [r for r in rows
            if r['tag'] in ZONE_TAGS and 0 <= r['blob'] and r['blob'] + 0x32 <= len(b)]


# ── shape sniffing ─────────────────────────────────────────────────────────────

def is_sent_pair(b, o):
    """(flags, -2) sentinel of the s16-framed triangle stream at byte offset o."""
    if o + 4 > len(b) or o % 2:
        return False
    return i16(b, o + 2) == -2 and (u16(b, o) & 0x7FFF) in SENT_FLAGS


def blob_shape(b, blob):
    """Classify a zone blob by content.

    Strictness is deliberate — the corpus contains several family-3 VARIANTS
    (measured 2026-09-14): mtgz00/kino04 pack 20B records {u32 0x40, 3x in-band
    u32, 2x u16 idx} without the kami03 count prefix; bsyt01/bsil00 point at
    record interiors with pattern fill (0x80808080/0x80555555/...). Those are
    reported as 'reloc_frag' (container-parse) instead of pretending the
    kami03 layout applies. Sentinel pairs alone (kami00 map area) are likewise
    not enough for family 1: >=2 framed records are required.
    """
    if blob + 0x32 > len(b):
        return 'oob'
    # F2: identity-scale floats (1.0f / -4.0f) at 2-byte alignment
    for o in range(blob, blob + 0x32, 2):
        if u32(b, o) in (0x3F800000, 0xC0800000):
            return 'float32'
    # F1: >=2 sentinel-framed 16B triangle records in the first 0x40 bytes
    sents = sum(1 for o in range(blob, blob + 0x40, 2) if is_sent_pair(b, o))
    if sents >= 2:
        return 's16framed'
    # F3 strict: kami03-canonical count prefix + at least `count` valid records
    first = blob + ((4 - blob % 4) % 4)
    has_band = False
    for o in range(first, blob + 0x20, 4):
        if all(REL_LO <= u32(b, o + 4 * k) < REL_HI for k in range(3)):
            has_band = True
            break
    if has_band:
        d = decode_f3(b, blob)
        if (d and d['pad_field'] == 0 and 1 <= d['count_field'] <= 4096
                and d['run_len'] >= d['count_field']):
            return 'reloc32'
        return 'reloc_frag'
    if all(c == 0 for c in b[blob:blob + 0x20]):
        return 'zeros'
    return 'unframed'


# ── family 1: sentinel-framed s16 triangle stream ─────────────────────────────

def decode_s16_stream(b, start, end):
    """Self-synchronizing extraction of 16B triangle records in [start, end).

    WHY self-sync: zone rows sit 0x32 (50B) apart while records are 16B, so row
    anchors are NOT record-aligned (measured: azit-style files share the same
    0x32 stride). We resync on the (flags,-2) sentinel, which is unambiguous.
    """
    tris = []
    o = start
    while o + 16 <= min(end, len(b)) and len(tris) < MAX_F1_TRIANGLES:
        if is_sent_pair(b, o + 12):
            verts = [(i16(b, o) * S16_SCALE, i16(b, o + 2) * S16_SCALE),
                     (i16(b, o + 4) * S16_SCALE, i16(b, o + 6) * S16_SCALE),
                     (i16(b, o + 8) * S16_SCALE, i16(b, o + 10) * S16_SCALE)]
            tris.append({'off': o, 'flags': u16(b, o + 12), 'verts': verts})
            o += 16
        else:
            o += 2
    return tris


# ── family 2: 0x32-strided transform records + separate ring stream ───────────

def decode_f2_records(b, zrows):
    """50B transform records anchored at each zone row (stride 0x32 measured)."""
    recs = []
    for r in zrows:
        blob = r['blob']
        if blob + 0x32 > len(b):
            continue
        words = [u32(b, blob + 4 * i) for i in range(12)]
        recs.append({
            'key': r['key'], 'tag': r['tag'], 'blob': blob,
            'u32': words,
            'floats_1p0': sum(1 for w in words if w == 0x3F800000),
            'float_neg4': any(w == 0xC0800000 for w in words),
            'tail_u16': u16(b, blob + 0x30),
        })
    return recs


def scan_ring_stream(b, lo, hi):
    """Locate the biggest sentinel-framed triangle stream in [lo, hi) via -2 scan.

    Uses bytes.find(b'\\xfe\\xff') to jump between candidates: full-region Python
    loops over multi-MB geometry blocks are too slow for a 491-file corpus.
    """
    best = (0, 0, 0)  # (count, start, end)
    o = lo
    while True:
        o = b.find(b'\xfe\xff', o, hi)
        if o < 0 or o + 2 > len(b):
            break
        if o % 2 == 0 and o + 2 <= len(b):
            prev = o - 2
            if prev >= lo and (u16(b, prev) & 0x7FFF) in SENT_FLAGS:
                # dense neighborhood check: >=4 sentinels within 0x100 bytes
                seg = b[o:o + 0x100]
                n = seg.count(b'\xfe\xff')
                if n >= 4:
                    start = o
                    tris = decode_s16_stream(b, start - 0x200 if start - 0x200 >= lo else lo, min(start + 0x400, hi))
                    if tris and len(tris) > best[0]:
                        best = (len(tris), tris[0]['off'], tris[-1]['off'] + 16)
                    o += 0x400
                    continue
        o += 2
    return best


# ── family 3: count-prefixed 32B indirect-triangle records ────────────────────

def decode_f3(b, blob):
    """{u16 count, u16 pad} + N x 32B {verts[3], relocs[3], idx[4]}.

    Records validated by the reloc band invariant (3x u32 in [0x80000000,
    0x82000000)) — 22/22 on kami03 during derivation. The run may extend past
    `count` (multiple groups share the grid); we report both numbers.
    """
    if blob + 4 > len(b):
        return None
    count = u16(b, blob)
    pad = u16(b, blob + 2)
    recs = []
    o = blob + 4
    while o + 32 <= len(b) and len(recs) < MAX_F3_RECORDS:
        relocs = (u32(b, o + 0x0C), u32(b, o + 0x10), u32(b, o + 0x14))
        if not all(REL_LO <= r < REL_HI for r in relocs):
            break
        recs.append({
            'off': o,
            'verts': [(i16(b, o) * S16_SCALE, i16(b, o + 2) * S16_SCALE),
                      (i16(b, o + 4) * S16_SCALE, i16(b, o + 6) * S16_SCALE),
                      (i16(b, o + 8) * S16_SCALE, i16(b, o + 10) * S16_SCALE)],
            'raw_verts': [i16(b, o + 2 * k) for k in range(6)],
            'relocs': ['%08X' % r for r in relocs],
            'idx': [u16(b, o + 0x18 + 2 * k) for k in range(4)],
        })
        o += 32
    return {'count_field': count, 'pad_field': pad, 'records': recs,
            'run_len': len(recs), 'extent_end': o}


# ── family 4: YNDT/YNGM guide map (§11.29 decode + measured errata) ───────────

def decode_yndt(b):
    y = u32(b, 0x3C) if len(b) >= 0x40 else 0
    if not (0 < y and y + 0x58 < len(b)) or b[y:y + 4] != b'YNDT':
        return None
    out = {'section': y, 'yngm': fourcc(b, y + 0x10)}
    if b[y + 0x10:y + 0x14] != b'YNGM':
        out['error'] = 'no YNGM at +0x10'
        return out
    tc, vc = u16(b, y + 0x38), u16(b, y + 0x3A)
    out.update({'triCount': tc, 'vertCount': vc,
                'const68': u16(b, y + 0x3E) == 68,
                'hdr44': u16(b, y + 0x44)})  # NOT a triCount dup (measured 0/262)
    if tc == 0 or vc == 0 or tc > 4096 or vc > 4096:
        out['error'] = 'counts out of range'
        return out
    tris_end = y + 0x58 + tc * 20
    if tris_end + vc * 6 > len(b):
        out['error'] = 'tri/pool OOB'
        return out
    tris, bad_idx, bad_sent = [], 0, 0
    for k in range(tc):
        o = y + 0x58 + k * 20
        sent = [u32(b, o), u32(b, o + 4), u32(b, o + 8)]
        if not all(REL_LO <= s < REL_HI for s in sent):
            bad_sent += 1
        ia, ib, ic = u16(b, o + 12), u16(b, o + 14), u16(b, o + 16)
        if ia >= vc or ib >= vc or ic >= vc:
            bad_idx += 1
        tris.append({'i': (ia, ib, ic), 'sent': ['%08X' % s for s in sent]})
    # Vertex pool: IMMEDIATELY after tri records — no alignment padding exists
    # (measured 0/262; the legacy skip-zeros loop drops real (0,0,0) vertices).
    pool = tris_end
    verts, nonzero_y = [], 0
    for k in range(vc):
        o = pool + k * 6
        if i16(b, o + 2) != 0:
            nonzero_y += 1
        verts.append((i16(b, o), i16(b, o + 2), i16(b, o + 4)))
    yned = b.find(b'YNED', pool + vc * 6)
    out.update({'tris': tris, 'bad_sentinel': bad_sent, 'bad_index': bad_idx,
                'pool': pool, 'verts': verts, 'nonzero_y_verts': nonzero_y,
                'yned_at': yned if yned >= 0 else None,
                'yned_gap': (yned - (pool + vc * 6)) if yned >= 0 else None})
    return out


# ── record stream: dispatch walk + content-shape decoders (2026-09-15) ─────────
#
# WHY this section exists: the 2026-09-14 reading treated each zone blob in
# isolation ("0x32-strided records", "rows pointing at record interiors"). The
# 2026-09-15 corpus survey proved the dispatch table is a size-tagged record
# stream (size = 2*tag) whose records tile the region contiguously when rows are
# sorted by offset, and whose CONTENT streams (soup/paint/quad/edge/range) run
# across chunk boundaries. Decoders below classify contiguous runs of that walk.

def rgba_str(v):
    """u32 (LE bytes R,G,B,A) -> 'RRGGBBAA' display string."""
    return '%02X%02X%02X%02X' % (v & 0xFF, (v >> 8) & 0xFF, (v >> 16) & 0xFF, v >> 24)


def is_color(v):
    """Color-slot test. Alphas 0x80/0x5B/0xC8/0x40/0x20/0x1C accept any RGB
    (real paint colors with varied channels). Alpha 0x00 is accepted ONLY for
    gray words (R==G==B, incl. 0): cdsp00 uses 0x00070707/0x00010101/0x00000000,
    and the gray restriction is what stops raw i16 streams (znkd03) from
    false-positiving through near-zero words."""
    a = v >> 24
    if a in (0x80, 0x5B, 0xC8, 0x40, 0x20, 0x1C):
        return True
    if a == 0x00:
        r, g, bl = v & 0xFF, (v >> 8) & 0xFF, (v >> 16) & 0xFF
        return r == g == bl
    return False


def packed_vert_ok(v):
    """u32 carrying two s16 map coords: both halves in the plausible band
    (non-negative, < 0x8000; measured soup/quad verts sit in ~[0x100, 0x8000))."""
    x, z = v & 0xFFFF, v >> 16
    return 0 <= x < 0x8000 and 0 <= z < 0x8000 and (x | z) != 0


def soup32_ok(b, o):
    if o + 32 > len(b) or u16(b, o + 2) != 0:
        return False
    if not all(packed_vert_ok(u32(b, o + 4 * k)) for k in (1, 2, 3)):
        return False
    return all(is_color(u32(b, o + 0x10 + 4 * k)) for k in range(3))


def paint20_ok(b, o):
    """20B paint triangle. Two measured arrangements of the same record:
      mtgz00/kino04: {u32 const 0x40, 3x RGBA, u16 j, u16 i}
      maca00:        {3x RGBA, u16 j, u16 i, u32 const 0x84}
    The j/i pairs follow the same (n+3,n) ladder in both, so the const word is
    a per-file primitive marker, not a field with independent meaning."""
    if o + 20 > len(b):
        return False
    if u32(b, o) == 0x40:
        return all(is_color(u32(b, o + 4 + 4 * k)) for k in range(3))
    if u32(b, o + 0x10) == 0x84:
        return all(is_color(u32(b, o + 4 * k)) for k in range(3))
    return False


def quad40_ok(b, o):
    """40B quad record: {4x u32 packed verts @+0, 4x u32 RGBA @+0x10,
    4x u16 idx @+0x20}. Measured idx styles: +1 grid quads (c1==c0+1,
    r1==r0+1 — bsyt01/bvyt09/mtgz01) or arbitrary pool indices
    (bsil00/cdsp00); both accepted, style reported at decode time."""
    if o + 40 > len(b):
        return False
    if not all(packed_vert_ok(u32(b, o + 4 * k)) for k in range(4)):
        return False
    if not all(is_color(u32(b, o + 0x10 + 4 * k)) for k in range(4)):
        return False
    return all(u16(b, o + 0x20 + 2 * k) < 0x4000 for k in range(4))


def edge24_ok(b, o):
    if o + 24 > len(b):
        return False
    cols = [u32(b, o + 4 * k) for k in range(4)]
    if not all(is_color(c) for c in cols):
        return False
    # anti-aliasing (mihn00 zeros): require a real paint signal — an 0x80-alpha
    # color (dominant corpus alpha) and at least 2 distinct indices.
    if not any((c >> 24) == 0x80 for c in cols):
        return False
    idx = [u16(b, o + 0x10 + 2 * k) for k in range(4)]
    return all(i < 0x4000 for i in idx) and len(set(idx)) >= 2


def range16_ok(b, o):
    """kino05 pool range: {u32 start, u32 end, u32 id, u16 f, u16 k}."""
    if o + 16 > len(b):
        return False
    a, c, d = u32(b, o), u32(b, o + 4), u32(b, o + 8)
    return 0 < a < c < 0x200000 and d < 0x10000 and (c - a) < 0x10000


# Signature-strength order: exact markers first (paint20's literal 0x40,
# range16's strict monotonic ranges), then structural shapes, weakest last.
# range16 MUST precede quad40: range words (small ints) satisfy quad40's loose
# order-(a) test whenever an alpha-0x00 color lands in a color slot.
SHAPES = (
    ('paint20', 20, paint20_ok),
    ('range16', 16, range16_ok),
    ('quad40', 40, quad40_ok),
    ('soup32', 32, soup32_ok),
    ('edge24', 24, edge24_ok),
)
CLASSIFY_SLOTS = 256          # sampling cap per (shape, anchor) probe


def walk_dispatch(b, rows, geom):
    """Sorted-by-offset walk of the dispatch rows as size-tagged records.

    Each row covers [geom+off, geom+off+2*tag). The walk reports contiguity:
    adjacent rows in offset order are expected to tile exactly (the corpus
    stride law). Returns (walk, n_contig, n_pairs, gaps) where walk entries
    carry {row, start, end} and gaps lists (prev_end, next_start) breaks.
    """
    srows = sorted(rows, key=lambda r: r['off'])
    walk = [{'row': r, 'start': geom + r['off'], 'end': geom + r['off'] + 2 * r['tag']}
            for r in srows]
    n_pairs, n_contig, gaps = 0, 0, []
    for a, c in zip(walk, walk[1:]):
        n_pairs += 1
        if c['start'] == a['end']:
            n_contig += 1
        else:
            gaps.append((a['end'], c['start']))
    return walk, n_contig, n_pairs, gaps


def classify_run(b, start, end):
    """Best (shape, anchor, hits, slots) for a contiguous walk run.

    Chunks are zone windows over CONTINUOUS streams and may cut records at both
    ends, so the record grid can be offset from the run start by up to one full
    record — hence the sliding anchor over [0, size). Paint20's exact-0x40
    marker and quad48's grid+1 law are immune to the anchor aliasing that a
    20B stream read at 32B stride would otherwise produce; shape precedence in
    SHAPES resolves ties toward the stronger signature.
    """
    best = (None, 0, 0, 0, 0.0)  # (shape, anchor, hits, slots, rate)
    n = end - start
    for name, size, ok in SHAPES:
        if n < size:
            continue
        for anchor in range(0, size):
            slots = hits = 0
            o = start + anchor
            while o + size <= end and slots < CLASSIFY_SLOTS:
                slots += 1
                if ok(b, o):
                    hits += 1
                o += size
            # majority of valid records AND at least 2 slots (a single slot is
            # indistinguishable from noise); compare by RATE so a smaller record
            # size cannot win merely by sampling more slots from the same run.
            rate = (hits / slots) if slots else 0.0
            if slots >= 2 and hits * 2 > slots and rate > best[4]:
                best = (name, anchor, hits, slots, rate)
    return best[:4]


def decode_run_records(b, start, end, shape, anchor):
    """Materialize the first VALID records of a classified run (bounded sample).

    Runs can start mid-stream over mixed content (znkd03: i16 zone data before
    the soup), so records that fail the shape validator are skipped — a sample
    must show real records, not the mixed prefix."""
    size = dict((s[0], s[1]) for s in SHAPES)[shape]
    ok = dict((s[0], s[2]) for s in SHAPES)[shape]
    recs = []
    o = start + anchor
    while o + size <= end and len(recs) < 8:
        if ok(b, o):
            recs.append(_decode_one(b, o, shape))
        o += size
    return recs


def _decode_one(b, o, shape):
    if shape == 'soup32':
        return {'off': o, 'id': u16(b, o),
                'verts': [(i16(b, o + 4), i16(b, o + 6)),
                          (i16(b, o + 8), i16(b, o + 10)),
                          (i16(b, o + 0xC), i16(b, o + 0xE))],
                'colors': [rgba_str(u32(b, o + 0x10 + 4 * k)) for k in range(3)],
                'pq': (u16(b, o + 0x1C), u16(b, o + 0x1E))}
    if shape == 'paint20':
        if u32(b, o) == 0x40:
            return {'off': o,
                    'colors': [rgba_str(u32(b, o + 4 + 4 * k)) for k in range(3)],
                    'ji': (u16(b, o + 0x10), u16(b, o + 0x12))}
        return {'off': o,
                'colors': [rgba_str(u32(b, o + 4 * k)) for k in range(3)],
                'ji': (u16(b, o + 0x0C), u16(b, o + 0x0E)),
                'const84': True}
    if shape == 'quad40':
        # unified layout: verts@0, colors@0x10, idx@0x20; idx style reported
        # ('grid' when the +1 law holds, 'pool' for arbitrary indices)
        idx = [u16(b, o + 0x20 + 2 * k) for k in range(4)]
        grid = (idx[1] == idx[0] + 1 and idx[3] == idx[2] + 1 and idx[0] < 0x4000)
        return {'off': o, 'idx_style': 'grid' if grid else 'pool',
                'grid': idx,
                'verts': [(i16(b, o + 4 * k), i16(b, o + 4 * k + 2))
                          for k in range(4)],
                'colors': [rgba_str(u32(b, o + 0x10 + 4 * k)) for k in range(4)]}
    if shape == 'edge24':
        return {'off': o,
                'colors': [rgba_str(u32(b, o + 4 * k)) for k in range(4)],
                'idx': [u16(b, o + 0x10 + 2 * k) for k in range(4)]}
    if shape == 'range16':
        return {'off': o, 'start': u32(b, o), 'end': u32(b, o + 4),
                'id': u32(b, o + 8),
                'fk': (u16(b, o + 0xC), u16(b, o + 0xE))}
    return {'off': o}


def analyze_stream(b, rows, geom):
    """File-level record-stream analysis: walk + contiguous-run classification."""
    walk, n_contig, n_pairs, gaps = walk_dispatch(b, rows, geom)
    # merge the walk into contiguous runs
    runs = []
    for w in walk:
        if runs and runs[-1][1] == w['start']:
            runs[-1][1] = w['end']
            runs[-1][2].append(w['row'])
        else:
            runs.append([w['start'], w['end'], [w['row']]])
    out_runs = []
    for s, e, rrows in runs:
        shape, anchor, hits, slots = classify_run(b, s, e)
        entry = {'start': s, 'end': e, 'size': e - s, 'rows': len(rrows),
                 'keys': sorted({r['key'] for r in rrows}),
                 'tags': sorted({r['tag'] for r in rrows})}
        if shape:
            entry.update({'shape': shape, 'anchor': anchor,
                          'records': hits, 'slots': slots})
            entry['sample'] = decode_run_records(b, s, e, shape, anchor)
        else:
            # mixed runs (descriptor rows interleaved with paint/soup rows):
            # fall back to classifying the individual rows large enough to hold
            # a record — keeps a real decode for files like mtgz01/kino04.
            row_shapes = []
            for w in walk:
                if not (s <= w['start'] < e) or w['end'] - w['start'] < 20:
                    continue
                rshape, ranchor, rhits, rslots = classify_run(b, w['start'], w['end'])
                if rshape:
                    row_shapes.append({'start': w['start'], 'end': w['end'],
                                       'key': w['row']['key'], 'tag': w['row']['tag'],
                                       'shape': rshape, 'anchor': ranchor,
                                       'records': rhits, 'slots': rslots})
            if row_shapes:
                entry['row_shapes'] = row_shapes
        out_runs.append(entry)
    return {'walk_pairs': n_pairs, 'walk_contig': n_contig,
            'walk_gaps': len(gaps),
            'first_blob': walk[0]['start'] if walk else None,
            'walk_end': walk[-1]['end'] if walk else None,
            'runs': out_runs}




# ── per-file pipeline ──────────────────────────────────────────────────────────

def analyze_file(path, root=None):
    with open(path, 'rb') as f:
        b = f.read()
    rel = os.path.relpath(path, root) if root else path
    res = {'file': rel, 'path': path, 'size': len(b), 'status': 'ok'}
    if len(b) < 4 or b[:4] != b'MAP1':
        res['status'] = 'bad-magic'
        return res
    if len(b) <= HSZ + 4:
        res['status'] = 'stub'
        return res
    res['slots'] = parse_header(b)
    geom, meta, dabs, rows = read_dispatch(b)
    res['geom'], res['meta'], res['dispatch'] = geom, meta, dabs
    if meta == 0 or dabs is None:
        # distinguish the legacy categories
        res['status'] = 'nometa' if (meta == 0 or not (0 < meta < len(b))) else 'nodispatch'
        res['yndt'] = decode_yndt(b)
        return res
    res['rows'] = len(rows)
    # record-stream walk + content-shape classification (2026-09-15; additive key)
    res['stream'] = analyze_stream(b, rows, geom)
    zr = zone_rows(rows, b)
    res['zone_rows'] = len(zr)
    shapes = [blob_shape(b, r['blob']) for r in zr]
    res['zone_shapes'] = dict(Counter(shapes))
    # file-level blob family: strict decoders win in priority order (reloc32 >
    # float32 > s16framed) whenever ANY zone blob validates strictly; the first
    # non-zero shape is the container-parse fallback (unframed/reloc_frag).
    fam_shape = 'none'
    for want in ('reloc32', 'float32', 's16framed'):
        if want in shapes:
            fam_shape = want
            break
    if fam_shape == 'none' and zr:
        fam_shape = next((s for s in shapes if s != 'zeros'), 'zeros')
    res['blob_family'] = fam_shape
    if fam_shape == 's16framed':
        lo = min(r['blob'] for r in zr)
        hi = max(r['blob'] for r in zr) + 0x400
        tris = decode_s16_stream(b, lo, min(hi, len(b)))
        res['f1'] = {'triangles': len(tris),
                     'first_off': tris[0]['off'] if tris else None,
                     'last_off': (tris[-1]['off'] + 16) if tris else None,
                     'flags_seen': sorted({t['flags'] for t in tris})}
    elif fam_shape == 'float32':
        res['f2'] = {'records': decode_f2_records(b, zr)}
        cnt, s, e = scan_ring_stream(b, geom, meta if meta > geom else len(b))
        res['f2']['ring_stream'] = {'triangles': cnt, 'start': s, 'end': e,
                                    'note': 'record->ring reference RE-pending'}
    elif fam_shape == 'reloc32':
        anchor = next(r['blob'] for r, s in zip(zr, shapes) if s == 'reloc32')
        res['f3'] = decode_f3(b, anchor)
        # keep the report bounded: summary + first records (run_len and
        # extent_end remain the authoritative fields of the same dict)
        res['f3']['records_sample'] = res['f3']['records'][:6]
        del res['f3']['records']
    elif zr:
        res['raw_zone_blobs'] = [{'key': r['key'], 'tag': r['tag'],
                                  'off': r['off'],
                                  'bytes': b[r['blob']:r['blob'] + 0x20].hex()}
                                 for r in zr[:8]]
        res['limitation'] = ('zone blobs in-bounds but framing not fully derived '
                             '(unframed / zeros / reloc_frag family-3 variants); '
                             'container-parse with raw bytes only — see res[stream] '
                             'for the 2026-09-15 record-stream decode of these files')
    res['yndt'] = decode_yndt(b)
    if res['yndt'] and 'tris' in res['yndt']:
        # trim heavy vertex arrays from the JSON record (kept in dump)
        res['yndt']['verts'] = res['yndt']['verts'][:4]
        res['yndt']['tris'] = res['yndt']['tris'][:4]
    return res


# ── corpus driver ──────────────────────────────────────────────────────────────

def iter_corpus(root):
    hits = []
    for dirpath, _dirs, files in os.walk(root):
        for fn in files:
            if fn.lower() == 'mapout.vpa':
                hits.append(os.path.join(dirpath, fn))
    return sorted(hits)


def main():
    ap = argparse.ArgumentParser(description='MAP1 mapout.vpa family classifier/decoder')
    ap.add_argument('root', help='corpus root containing ffx/master/jppc/{map,btlmap}')
    ap.add_argument('--out', default='work/map1_families_out', help='output directory')
    args = ap.parse_args()
    if not os.path.isdir(args.root):
        print('missing corpus root: %s' % args.root, file=sys.stderr)
        return 2
    os.makedirs(args.out, exist_ok=True)
    paths = iter_corpus(args.root)
    results = [analyze_file(p, args.root) for p in paths]

    # aggregate
    agg = Counter(r['status'] for r in results)
    fam = Counter(r.get('blob_family', '-') for r in results)
    yndt_ok = sum(1 for r in results if r.get('yndt') and 'tris' in r.get('yndt', {}))
    yndt_bad = sum(1 for r in results if r.get('yndt') and 'error' in r['yndt'])
    yndt_idx_ok = sum(1 for r in results if r.get('yndt') and r['yndt'].get('bad_index') == 0
                      and 'tris' in r['yndt'])
    f3_run_eq = sum(1 for r in results if 'f3' in r and r['f3']['run_len'] >= r['f3']['count_field'])
    # record-stream aggregates (2026-09-15)
    with_stream = [r for r in results if 'stream' in r]
    pairs = sum(r['stream']['walk_pairs'] for r in with_stream)
    contig = sum(r['stream']['walk_contig'] for r in with_stream)
    ngaps = sum(r['stream']['walk_gaps'] for r in with_stream)
    files_walk_exact = sum(1 for r in with_stream
                           if r['stream']['walk_gaps'] == 0 and r['stream']['walk_pairs'] > 0)
    shape_files = Counter()
    shape_records = Counter()
    for r in with_stream:
        shapes = {run.get('shape') for run in r['stream']['runs'] if run.get('shape')}
        shapes |= {rs['shape'] for run in r['stream']['runs']
                   for rs in run.get('row_shapes', [])}
        for s in shapes:
            shape_files[s] += 1
        for run in r['stream']['runs']:
            if run.get('shape'):
                shape_records[run['shape']] += run['records']
            for rs in run.get('row_shapes', []):
                shape_records[rs['shape']] += rs['records']
    summary = {
        'corpus_root': args.root,
        'files': len(results),
        'status_counts': dict(agg),
        'blob_family_counts': dict(fam),
        'yndt_section_present': yndt_ok + yndt_bad,
        'yndt_decoded_ok': yndt_ok,
        'yndt_index_invariants_ok': yndt_idx_ok,
        'f3_count_le_run': f3_run_eq,
        'stream_walk_pairs': pairs,
        'stream_walk_contig': contig,
        'stream_walk_gaps': ngaps,
        'stream_files_walk_exact': files_walk_exact,
        'stream_shape_files': dict(shape_files),
        'stream_shape_records': dict(shape_records),
    }
    with open(os.path.join(args.out, 'map1_families_report.json'), 'w') as f:
        json.dump({'summary': summary, 'files': results}, f, indent=1)
    with open(os.path.join(args.out, 'map1_families_dump.txt'), 'w') as f:
        for r in results:
            f.write('=' * 78 + '\n')
            f.write('%s  size=%d status=%s fam=%s\n' %
                    (r['file'], r['size'], r['status'], r.get('blob_family', '-')))
            if 'zone_shapes' in r:
                f.write('  zone_rows=%d shapes=%s\n' % (r['zone_rows'], r['zone_shapes']))
            st = r.get('stream')
            if st:
                f.write('  stream: walk pairs=%d contig=%d gaps=%d [%s..%s]\n' %
                        (st['walk_pairs'], st['walk_contig'], st['walk_gaps'],
                         hex(st['first_blob']) if st['first_blob'] is not None else '-',
                         hex(st['walk_end']) if st['walk_end'] is not None else '-'))
                for run in st['runs']:
                    if 'shape' in run:
                        f.write('    run [0x%X..0x%X) rows=%d keys=%s tags=%s -> %s '
                                'anchor=%d records=%d/%d\n' %
                                (run['start'], run['end'], run['rows'],
                                 [hex(k) for k in run['keys']],
                                 [hex(t) for t in run['tags']],
                                 run['shape'], run['anchor'], run['records'], run['slots']))
                    for rs in run.get('row_shapes', []):
                        f.write('    row [0x%X..0x%X) key=0x%X tag=0x%X -> %s '
                                'anchor=%d records=%d/%d\n' %
                                (rs['start'], rs['end'], rs['key'], rs['tag'],
                                 rs['shape'], rs['anchor'], rs['records'], rs['slots']))
            if 'f1' in r:
                f.write('  f1: %d triangles\n' % r['f1']['triangles'])
            if 'f2' in r:
                recs = r['f2']['records']
                f.write('  f2: %d transform records; ring_stream=%s\n' %
                        (len(recs), r['f2']['ring_stream']))
                for rec in recs[:6]:
                    f.write('    rec key=%d tag=0x%X blob=0x%X 1p0x%d neg4=%s tail=%d\n' %
                            (rec['key'], rec['tag'], rec['blob'], rec['floats_1p0'],
                             rec['float_neg4'], rec['tail_u16']))
            if 'f3' in r:
                d = r['f3']
                f.write('  f3: count_field=%d run_len=%d extent_end=0x%X\n' %
                        (d['count_field'], d['run_len'], d['extent_end']))
                for rec in d['records_sample']:
                    f.write('    rec @0x%X raw=%s relocs=%s idx=%s\n' %
                            (rec['off'], rec['raw_verts'], rec['relocs'], rec['idx']))
            if r.get('yndt') and 'tris' in r['yndt']:
                y = r['yndt']
                f.write('  yndt: tris=%d verts=%d const68=%s hdr44=%d bad_idx=%d '
                        'nonzero_y=%d yned_gap=%s\n' %
                        (y['triCount'], y['vertCount'], y['const68'], y['hdr44'],
                         y['bad_index'], y['nonzero_y_verts'], y['yned_gap']))
            elif r.get('yndt'):
                f.write('  yndt: %s\n' % r['yndt'])
    print(json.dumps(summary, indent=1))
    return 0


if __name__ == '__main__':
    sys.exit(main())
