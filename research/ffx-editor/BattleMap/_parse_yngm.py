#!/usr/bin/env python3
# ── _parse_yngm.py — YNGM (Guide Map) record parser for mapout.vpa ──
#
# Purpose: parse the YNGM guide-map records inside the YNDT container referenced
# by MAP1 header slot u32@0x3C (the guide-zone section) of every mapout.vpa in
# the PS2 corpus. See docs/reverse/FFX_YNGM_LAYOUT_2026-09-15.md.
#
# This REPLACES the legacy broken script research_tools/{,QA/}_parse_yngm.py
# (removed 2026-09-15), which had three fatal bugs, all fixed here:
#   1. struct '<6I6H' unpacks only 12 values — indexing hdr[16]/hdr[17] raised
#      IndexError before any parsing happened.
#   2. Hard-coded Windows paths (D:/FFX Extracted/...) — corpus root is now a
#      CLI argument (Linux/WSL mount friendly).
#   3. Record walk required sentinel == 0x80FFFFFF, but records legitimately
#      carry other RGBA values (bika03 uses 0x80A0A0A0/0x80000000), so the
#      walk stopped at record 0 and triCount was never used as the authority.
#
# 2026-09-15 (YNGM-UNKNOWN lane, second pass): layout REWRITTEN to the runtime
# semantics proven by IDA decompiles of the PC consumer chain:
#   - YNGM+0x04 (ex-UNKNOWN_A) = record payload length in 16-B units, read by
#     FFX_Render_ParseSceneBinData@0x921D60 as the chain stride
#     (next = rec + 16 + 16*len16). 295/295 sections land on YNGM/YNED.
#   - The record body is a serialized "SceneBin" consumed verbatim by
#     FFX_RcBg_SerializeSceneBin@0x92B2F0: u32 flags(=6), u32 blobSize, blob,
#     then fixed 0x70/0x20/0x10/0x40/0x40 blocks = the SceneObject field image.
#   - The blob is a generic mesh-decl (written at runtime by
#     FFX_RcBg_BuildVertexDeclFromMeshData@0x927BE0): 32-B header
#     {u32 0, u32 hdrSize=32, u32 ofsVerts, u32 blobSize, u16 primTotal,
#      u16 vertCount, u16 auxCount, u16 const68, u32 0, u32 0}, then prim groups
#     at blob+0x20 ({u8 0, u8 primType, u16 primCount, u8 aux, u8 0, u32 0,
#     u32 0} + count*g_OmdPrimSize[type] records), a u16 0xFFFF group-list
#     terminator, align16 pad, then verts (s16 x,y,z) at blob+ofsVerts,
#     align16, then an aux pool (auxCount*6B, 0 in the guide corpus).
#     ofsVerts = 32 + align16(16 + Σ(count*primSize[type]+16)) — for the guide
#     stream (1 group of type-0 20-B prims): = 32 + align16(20*tri+32).
#     blobSize = ofsVerts + align16(6*vertCount) (+ align16(6*auxCount)).
#     Both formulas verify EXACTLY on 295/295 sections.
#   - After the blob: a fixed 20-B prologue {u32 28, u32 stale PS2 sg_packet
#     ptr (0x01F00000), u16 68, u16 0, u32 0, u32 0} — the serialized image of
#     SceneObject+0x20..0x33 — then the "meta" block (end-anchored at rec_end):
#     head {u32 0, u32 RGBA tint (0x80808080), u32 0, u32 stale PS2 mat4 ptr A,
#     zeros, u32 stale PS2 mat4 ptr B (=ptrA-64, adjacent globals), zeros},
#     then at rec_end-184: AABBmin vec4 (x,0,z,1.0), rec_end-168: AABBmax,
#     rec_end-152: reserved vec4 (0), rec_end-136..-72: 4x4 uniform-scale
#     matrix, rec_end-72..-8: 4x4 identity matrix, rec_end-8: pad.
#     Two meta revisions exist: 276 B (288 sections) and 260 B (7 sections:
#     sins05_a, test00_b, bvyt07/08/14, kami06, mcfr10) — the short form just
#     carries 16 B less zero-pad before the AABB; the runtime's fixed-size
#     reads over-run 8 B into YNED for those (harmless, lands in matB pad).
#
# Corpus partition (491 files): 103 stubs, 124 no-guide, 2 empty-guide
# (bvyt11/hiku00), 262 with YNGM chains (295 sections total: 240 files ×1,
# 15 ×2, 6 ×3, 1 ×7).
#
# Usage:
#   python3 _parse_yngm.py <corpus_ffx_ps2_root> [--out DIR]
# Emits:
#   DIR/yngm_report.json — per-file sections + aggregate stats
#   DIR/yngm_dump.txt    — stable per-file dump (first records/verts only)
#
# RESEARCH TOOL — stdlib only, no game data is modified.

import argparse
import json
import os
import struct
import sys
from collections import Counter

HSZ = 0x80                    # MAP1 header size
GUIDE_SLOT = 0x3C             # MAP1 header slot -> YNDT guide container
YNGM_REL = 0x10               # first record offset inside the YNDT section
MAX_TRIS = 4096               # sanity ceiling (corpus max: 998)
MAX_VERTS = 4096              # sanity ceiling (corpus max: 586)
MAX_SECTIONS = 64
MARKER = bytes.fromhex('1c0000000000f00144000000') + b'\x00' * 8


def u16(b, o): return struct.unpack_from('<H', b, o)[0]
def i16(b, o):
    v = u16(b, o)
    return v - 0x10000 if v >= 0x8000 else v
def u32(b, o): return struct.unpack_from('<I', b, o)[0]
def f32(b, o): return struct.unpack_from('<f', b, o)[0]
def a16(n): return (n + 15) & ~15


# ── YNGM record decode ────────────────────────────────────────────────────────

def decode_record(b, off):
    """Decode one YNGM record at file offset `off`. Returns (dict, next_off)."""
    rec = {'off': off}
    f04 = u32(b, off + 4)                       # payloadLen16 (stride authority)
    rec_end = off + 16 + 16 * f04
    rec['payloadLen16'] = f04
    rec['rec_end'] = rec_end
    rec['hdr08'] = u16(b, off + 8)              # reserved (0)
    rec['sceneSlotIdx'] = u16(b, off + 0x0A)    # target scene slot (0 in corpus)
    rec['hdr0C'] = u32(b, off + 0x0C)           # reserved (0)
    rec['objFlags'] = u32(b, off + 0x10)        # -> SceneObject+0x10 (=6)
    blob_size = u32(b, off + 0x14)              # -> serialized blobSize
    rec['blobSize'] = blob_size
    blob = off + 0x18
    # blob 32-B header
    rec['blob'] = {
        'reserved0': u32(b, blob),
        'hdrSize': u32(b, blob + 4),            # =32
        'ofsVerts': u32(b, blob + 8),           # vertex pool offset in blob
        'blobSize': u32(b, blob + 0x0C),        # == blobSize (self)
        'primTotal': u16(b, blob + 0x10),       # == triCount (1 group)
        'vertCount': u16(b, blob + 0x12),
        'auxCount': u16(b, blob + 0x14),        # 0 in guide corpus
        'const68': u16(b, blob + 0x16),         # 68 const
        'zero18': u32(b, blob + 0x18),
        'zero1C': u32(b, blob + 0x1C),
    }
    tc, vc = rec['blob']['primTotal'], rec['blob']['vertCount']
    rec['triCount'], rec['vertCount'] = tc, vc
    # prim group header at blob+0x20 (16 B): {u8 0, u8 type, u16 count, u8 aux,
    # u8 0, u32 0, u32 0}
    rec['group'] = {
        'flag0': b[blob + 0x20], 'primType': b[blob + 0x21],
        'primCount': u16(b, blob + 0x22), 'aux': b[blob + 0x24],
    }
    # prims: 20-B each (type 0): RGBA x3 + u16 iA,iB,iC + u16 pad
    pbase = blob + 0x30
    tris, bad_idx, bad_alpha = [], 0, 0
    colors = Counter()
    for k in range(tc):
        o = pbase + k * 20
        rgba = [u32(b, o), u32(b, o + 4), u32(b, o + 8)]
        for c in rgba:
            colors['%08X' % c] += 1
            if (c >> 24) != 0x80:
                bad_alpha += 1
        ia, ib, ic = u16(b, o + 12), u16(b, o + 14), u16(b, o + 16)
        if ia >= vc or ib >= vc or ic >= vc:
            bad_idx += 1
        tris.append({'i': (ia, ib, ic), 'rgba': ['%08X' % c for c in rgba],
                     'pad': u16(b, o + 18)})
    rec['tris'] = tris
    rec['bad_index'] = bad_idx
    rec['bad_alpha'] = bad_alpha
    rec['pad16_nonzero'] = sum(1 for t in tris if t['pad'] != 0)
    rec['colors'] = dict(colors)
    # group-list terminator + pad, then verts at blob+ofsVerts
    term_at = pbase + tc * 20
    rec['termFFFF'] = u16(b, term_at)           # 0xFFFF expected
    vbase = blob + rec['blob']['ofsVerts']
    rec['verts'] = [(i16(b, vbase + i * 6), i16(b, vbase + i * 6 + 2),
                     i16(b, vbase + i * 6 + 4)) for i in range(vc)]
    rec['nonzero_y_verts'] = sum(1 for v in rec['verts'] if v[1] != 0)
    # exact layout invariants (proven 295/295):
    rec['ofsVerts_exact'] = rec['blob']['ofsVerts'] == 32 + a16(20 * tc + 32)
    rec['blobSize_exact'] = blob_size == rec['blob']['ofsVerts'] + a16(6 * vc)
    # 20-B prologue (SceneObject+0x20 image) then meta, end-anchored at rec_end
    mk = blob + blob_size
    rec['marker_ok'] = b[mk:mk + 20] == MARKER
    mt = mk + 20
    rec['meta_len'] = rec_end - mt
    rec['meta_head'] = {
        'reserved0': u32(b, mt), 'tint': '%08X' % u32(b, mt + 4),
        'reserved8': u32(b, mt + 8),
        'ps2MatPtrA': '0x%08X' % u32(b, mt + 0x0C),
        'ps2MatPtrB': '0x%08X' % u32(b, mt + 0x1C),
    }
    rec['aabb_min'] = [f32(b, rec_end - 184 + 4 * i) for i in range(4)]
    rec['aabb_max'] = [f32(b, rec_end - 168 + 4 * i) for i in range(4)]
    rec['vec4_b0'] = [f32(b, rec_end - 152 + 4 * i) for i in range(4)]
    rec['mat_scale'] = [f32(b, rec_end - 136 + 4 * i) for i in range(16)]
    rec['mat_ident'] = [f32(b, rec_end - 72 + 4 * i) for i in range(16)]
    rec['meta_rev'] = 'long' if rec['meta_len'] == 276 else 'short'
    return rec, rec_end


def decode_yngm(b):
    """Struct-walk the YNDT guide container at MAP1 slot +0x3C.

    Returns a dict; 'status' is one of:
      ok / no-guide-section / empty-guide / trunc-yndt / bad-yngm-magic /
      counts-oor / layout-oob / bad-chain-magic
    """
    if len(b) < HSZ + 4:
        return {'status': 'short-file'}
    sec = u32(b, GUIDE_SLOT)
    out = {'slot_3C': sec}
    if sec == 0 or sec + 4 > len(b) or b[sec:sec + 4] != b'YNDT':
        out['status'] = 'no-guide-section'
        return out
    if b[sec + 0x10:sec + 0x14] == b'YNED':
        out['status'] = 'empty-guide'
        return out
    if sec + YNGM_REL + 0x48 > len(b):
        out['status'] = 'trunc-yndt'
        return out
    if b[sec + YNGM_REL:sec + YNGM_REL + 4] != b'YNGM':
        out['status'] = 'bad-yngm-magic'
        return out
    sections = []
    off = sec + YNGM_REL
    for _ in range(MAX_SECTIONS):
        if off + 4 > len(b):
            out['status'] = 'chain-oob'
            break
        mg = b[off:off + 4]
        if mg == b'YNED':
            out['status'] = 'ok'
            break
        if mg != b'YNGM':
            out['status'] = 'bad-chain-magic'
            break
        rec, off = decode_record(b, off)
        sections.append(rec)
    else:
        out['status'] = 'runaway'
    out['sections'] = sections
    if sections and out.get('status') != 'ok':
        return out
    # legacy-compatible top-level view = first section
    if sections:
        s0 = sections[0]
        out.update({'yngm': s0['off'], 'triCount': s0['triCount'],
                    'vertCount': s0['vertCount'], 'status': 'ok',
                    'bad_index': sum(s['bad_index'] for s in sections),
                    'bad_alpha': sum(s['bad_alpha'] for s in sections),
                    'nsec': len(sections)})
    return out


# ── corpus driver ──────────────────────────────────────────────────────────────

def iter_corpus(root):
    hits = []
    for sub in ('map', 'btlmap'):
        base = os.path.join(root, sub)
        if not os.path.isdir(base):
            continue
        for dirpath, _dirs, files in os.walk(base):
            for fn in files:
                if fn.lower() == 'mapout.vpa':
                    hits.append(os.path.join(dirpath, fn))
    return sorted(hits)


def analyze_file(path, root=None):
    with open(path, 'rb') as f:
        b = f.read()
    res = {'file': os.path.relpath(path, root) if root else path,
           'size': len(b), 'magic': b[:4].decode('ascii', 'replace')}
    if b[:4] != b'MAP1':
        res['status'] = 'not-map1'
        return res
    if len(b) <= HSZ:
        res['status'] = 'stub'
        return res
    res.update(decode_yngm(b))
    return res


def main():
    ap = argparse.ArgumentParser(description='YNGM guide-map parser for mapout.vpa')
    ap.add_argument('root', help='corpus root containing ffx/master/jppc/{map,btlmap}')
    ap.add_argument('--out', default='work/_yngm_re', help='output directory')
    args = ap.parse_args()
    if not os.path.isdir(args.root):
        print('missing corpus root: %s' % args.root, file=sys.stderr)
        return 2
    os.makedirs(args.out, exist_ok=True)
    paths = iter_corpus(args.root)
    results = []
    for p in paths:
        r = analyze_file(p, args.root)
        if r.get('status') == 'ok':
            for s in r['sections']:
                s['verts_sample'] = s.pop('verts')[:4]
                s['tris_sample'] = s.pop('tris')[:4]
        results.append(r)

    ok = [r for r in results if r.get('status') == 'ok']
    secs = [s for r in ok for s in r['sections']]
    global_colors = Counter()
    for s in secs:
        global_colors.update(s['colors'])
    summary = {
        'corpus_root': args.root,
        'files': len(results),
        'status_counts': dict(Counter(r['status'] for r in results)),
        'ok_files': len(ok),
        'sections': len(secs),
        'sections_per_file': dict(Counter(r['nsec'] for r in ok)),
        'total_bad_index': sum(s['bad_index'] for s in secs),
        'total_bad_alpha': sum(s['bad_alpha'] for s in secs),
        'pad16_nonzero': sum(s['pad16_nonzero'] for s in secs),
        'nonzero_y_verts': sum(s['nonzero_y_verts'] for s in secs),
        'total_verts': sum(s['vertCount'] for s in secs),
        'total_tris': sum(s['triCount'] for s in secs),
        'ofsVerts_exact': '%d/%d' % (sum(s['ofsVerts_exact'] for s in secs), len(secs)),
        'blobSize_exact': '%d/%d' % (sum(s['blobSize_exact'] for s in secs), len(secs)),
        'termFFFF_ok': '%d/%d' % (sum(s['termFFFF'] == 0xFFFF for s in secs), len(secs)),
        'marker_ok': '%d/%d' % (sum(s['marker_ok'] for s in secs), len(secs)),
        'meta_len_hist': dict(Counter(s['meta_len'] for s in secs)),
        'tint_hist': dict(Counter(s['meta_head']['tint'] for s in secs)),
        'sceneSlotIdx_hist': dict(Counter(s['sceneSlotIdx'] for s in secs)),
        'objFlags_hist': dict(Counter(s['objFlags'] for s in secs)),
        'auxCount_hist': dict(Counter(s['blob']['auxCount'] for s in secs)),
        'primType_hist': dict(Counter(s['group']['primType'] for s in secs)),
        'primCount_eq_triCount': '%d/%d' % (
            sum(s['group']['primCount'] == s['triCount'] for s in secs), len(secs)),
        'top_colors': global_colors.most_common(10),
    }
    with open(os.path.join(args.out, 'yngm_report.json'), 'w') as f:
        json.dump({'summary': summary, 'files': results}, f, indent=1)
    with open(os.path.join(args.out, 'yngm_dump.txt'), 'w') as f:
        for r in results:
            f.write('=' * 78 + '\n')
            f.write('%s  size=0x%X status=%s\n' % (r['file'], r['size'], r['status']))
            if r['status'] != 'ok':
                continue
            for s in r['sections']:
                f.write('  yngm@0x%X len16=%d tris=%d verts=%d bad_idx=%d bad_alpha=%d\n'
                        % (s['off'], s['payloadLen16'], s['triCount'], s['vertCount'],
                           s['bad_index'], s['bad_alpha']))
                f.write('    blob: ofsVerts=%d(%s) blobSize=%d(%s) aux=%d primCount=%d\n'
                        % (s['blob']['ofsVerts'], s['ofsVerts_exact'],
                           s['blobSize'], s['blobSize_exact'],
                           s['blob']['auxCount'], s['group']['primCount']))
                f.write('    meta: len=%d(%s) tint=%s ps2ptrs=%s/%s aabb=%s..%s scale=%.5f\n'
                        % (s['meta_len'], s['meta_rev'], s['meta_head']['tint'],
                           s['meta_head']['ps2MatPtrA'], s['meta_head']['ps2MatPtrB'],
                           tuple(round(v, 2) for v in s['aabb_min']),
                           tuple(round(v, 2) for v in s['aabb_max']),
                           s['mat_scale'][0]))
                for t in s['tris_sample'][:2]:
                    f.write('    tri i=%s rgba=%s pad=%d\n' % (t['i'], t['rgba'], t['pad']))
                for v in s['verts_sample'][:3]:
                    f.write('    vert %s\n' % (v,))
    print(json.dumps(summary, indent=1))
    return 0


if __name__ == '__main__':
    sys.exit(main())
