#!/usr/bin/env python3
# ── sps2_reader.py — PS2 FFX `.sps2` help/movie presentation file reader ────────
#
# Loader (IDA, PC HD remaster): FFX_Sps2_LoadProjectFileBuffer @ 0x88CDF0
# (a.k.a. FFX_Scene_CreatePObject in the 2026-08-19 notes) reads the file via
# Phyre_File_ReadEntireFile_ww; consumer is the ATEL help screen. Runtime item
# record size = 312 bytes (proven: every page span == count*312 exactly).
#
# Two on-disk variants exist (corpus: ffx_ps2/ffx/master, 82 files):
#
#   v1 "page+item" files (jppc/help*, *_page.sps2 in new_*pc):
#     0x00  u32 magic = 1
#     0x04  u32 nPages
#     0x08  u32 pageTableOff          (== end of item-stream region)
#     0x0C  u32 clipOff = 0x24        (constant)
#     0x10  u32 itemOffTabOff         (u32 offset table -> item streams)
#     0x14  u32 pageDataEnd           (== end of last page's 312B array;
#                                      trailing index table runs to EOF)
#     0x18  8B pad (0xCC fill in dvdcopy/test_proj; live data in others)
#     clips @0x24:  (clipEnd=offTab) n x 12B: (u16 x0,x1,y0,y1,u16 type,u16 FFFF)
#     item offset table @itemOffTabOff: u32 file offsets to item streams
#     item streams: serialized tag-trees (see TAG_*), text in FFX encoding
#     page table @pageTableOff: nPages x 8B: (u32 dataOff, u16 count, u16 FFFF)
#     page data: count x 312B item records
#     tail @pageDataEnd..EOF: 8B records (u16 cmd, 0, u16 arg, 0) — semantic TBD
#
#   v2 "item-table only" files (new_*pc/help/<name>/<name>.sps2):
#     count=0, clipOff=0, offTab @0x24, field08 == EOF (item region end).
#     The *_page.sps2 sibling keeps the full v1 layout (often byte-identical
#     to the legacy jppc file).
#
# Item stream tag set (u16 LE opcodes, low byte always 0x0B):
#   F00B node-open + 16B header: (u8 sub,u8 cls)(u8 kind,u8 pad)(u16 x,u16 y)
#                                (u32 f8)(u32 id; hi16 always 0 in corpus)
#   F10B children/list-open ; F20B node-close ; F30B list-separator
#   F40B + 8B (u16 fl, u16 ref, u16 idx, u16 flags) + optional text
#   F60B + 12B (u16 a,u16 b,u16 c,u16 pad,u16 seq,u16 z)
#   F70B + 4B  u32 file-offset link -> a 312B page record (record-aligned)
#   F80B + 12B (u16 a,u16 b,u16 c,u16 d,u16 idx,u16 z)
#   F90B marker (0B payload, always followed by F40B)
#   FA0B + 4B u32 + text run (ends at next tag; NUL-terminated when last)
#   Non-tag bytes between tags = FFX-encoded text (incl. 2-byte glyphs whose
#   lead can be 0x0B — disambiguated by parse position, not by value).
#
# stdlib only. Usage: sps2_reader.py <file.sps2|.sbin> [...]  (summary + validate)
# ──────────────────────────────────────────────────────────────────────────────
import os
import struct
import sys

ITEM_SIZE = 312
CLIP_SIZE = 12          # 6 x u16
PAGE_ENT_SIZE = 8       # u32 + u16 + u16
SBIN_DESC_SIZE = 16     # 8B params + u32 off + u32 off

# tag opcodes (high byte of u16; low byte is always 0x0B)
TAG_NODE_OPEN = 0xF0    # +16B node header
TAG_LIST_OPEN = 0xF1    # opens child/value list
TAG_NODE_CLOSE = 0xF2
TAG_LIST_END = 0xF3     # separates sibling groups inside a list
TAG_PROP_TXT = 0xF4     # +8B fields + optional text
TAG_PROP_12A = 0xF6     # +12B
TAG_LINK = 0xF7         # +4B u32 file offset -> page-item record
TAG_PROP_12B = 0xF8     # +12B
TAG_MARK = 0xF9         # 0B; always precedes F4 in corpus
TAG_PROP_STR = 0xFA     # +4B u32 + text run
TAG_BYTES = frozenset(range(0xF0, 0xFB))  # F5 never observed; keep range open

# fixed payload sizes after the 2B tag (text-bearing tags return None)
TAG_PAYLOAD = {0xF0: 16, 0xF1: 0, 0xF2: 0, 0xF3: 0, 0xF4: 8,
               0xF6: 12, 0xF7: 4, 0xF8: 12, 0xF9: 0}


def _u16(d, o):
    return struct.unpack_from('<H', d, o)[0]


def _s16(d, o):
    return struct.unpack_from('<h', d, o)[0]


def _u32(d, o):
    return struct.unpack_from('<I', d, o)[0]


def is_tag(d, p):
    """True if bytes at p look like a tag opcode (0x0B, 0xF0..0xFA)."""
    return d[p] == 0x0B and p + 1 < len(d) and d[p + 1] in TAG_BYTES


def parse_item_stream(rec):
    """Parse one item stream -> dict(nodes=event list, errors, texts).

    Layout: [lead text bytes] node-tree [trailing text] [pad].
    Text runs = non-tag bytes; a run may end at a tag or at NUL padding.
    """
    n = len(rec)
    pos = 0
    events = []          # (kind, offset, payload)
    errors = []
    depth = 0
    while pos < n:
        if is_tag(rec, pos):
            op = rec[pos + 1]
            if op == TAG_NODE_OPEN:
                h = rec[pos + 2:pos + 18]
                events.append(('open', pos, {
                    'sub': h[0], 'cls': h[1], 'kind': h[2], 'pad': h[3],
                    'x': _u16(h, 4), 'y': _u16(h, 6),
                    'f8': _u32(h, 8), 'id': _u32(h, 12)}))
                depth += 1
                pos += 18
            elif op == TAG_PROP_STR:
                # u32 then text run until next tag
                j = pos + 6
                while j < n and not is_tag(rec, j):
                    j += 1
                events.append(('str', pos, {'u32': _u32(rec, pos + 2),
                                            'text': rec[pos + 6:j]}))
                pos = j
            elif op == TAG_PROP_TXT:
                # 8B fields + optional text run until next tag
                j = pos + 10
                while j < n and not is_tag(rec, j):
                    j += 1
                events.append(('ptxt', pos, {
                    'fl': _u16(rec, pos + 2), 'ref': _u16(rec, pos + 4),
                    'idx': _u16(rec, pos + 6), 'flags': _u16(rec, pos + 8),
                    'text': rec[pos + 10:j]}))
                pos = j
            elif op == TAG_LINK:
                events.append(('link', pos, {'target': _u32(rec, pos + 2)}))
                pos += 6
            elif op == TAG_PROP_12A or op == TAG_PROP_12B:
                vals = struct.unpack_from('<6H', rec, pos + 2)
                events.append(('p12', pos, {'op': op, 'u16s': vals}))
                pos += 14
            elif op in (TAG_LIST_OPEN, TAG_NODE_CLOSE, TAG_LIST_END, TAG_MARK):
                name = {0xF1: 'lopen', 0xF2: 'close', 0xF3: 'lend',
                        0xF9: 'mark'}[op]
                if op == TAG_NODE_CLOSE:
                    depth -= 1
                events.append((name, pos, None))
                pos += 2
            else:  # pragma: no cover - defensive
                pos += 2
        else:
            # data run: text glyphs / bare u16 values inside lists
            j = pos
            while j < n and not is_tag(rec, j):
                j += 1
            events.append(('data', pos, rec[pos:j]))
            pos = j
    # The stream is a *sequence* of top-level nodes: a stray trailing F20B
    # closes the implicit stream root (depth -1) and a root may be left open
    # at EOF (depth +1). 46/67994 corpus streams hit this; treat |d|<=1 as ok.
    if abs(depth) > 1:
        errors.append(f'unbalanced node depth {depth}')
    elif depth != 0:
        events.append(('note', n, f'implicit-root depth {depth}'))
    return {'events': events, 'errors': errors}


def parse_sps2(d):
    """Parse a .sps2 blob -> dict. Raises ValueError on structural breaks."""
    if len(d) < 32:
        raise ValueError('too small')
    magic, n_pages, ptab, clip_off, otab, f14 = struct.unpack_from('<6I', d, 0)
    if magic != 1:
        raise ValueError(f'bad magic {magic:#x}')
    out = {'magic': magic, 'pages': [], 'clips': [], 'items': [],
           'item_offsets': [], 'n_pages': n_pages, 'page_table_off': ptab,
           'clip_off': clip_off, 'item_table_off': otab, 'page_data_end': f14,
           'header_tail': d[0x18:0x20], 'variant': 'v1' if n_pages else 'v2',
           'errors': []}
    # ── clip table (v1 only) ──
    if clip_off and otab > clip_off:
        for o in range(clip_off, otab - CLIP_SIZE + 1, CLIP_SIZE):
            x0, x1, y0, y1, typ, sent = struct.unpack_from('<6H', d, o)
            if sent != 0xFFFF:
                break
            out['clips'].append({'off': o, 'x0': x0, 'x1': x1,
                                 'y0': y0, 'y1': y1, 'type': typ})
    # ── item offset table ──
    item_end = ptab if (n_pages and 0 < ptab < len(d)) else min(f14 or len(d), len(d))
    # v2: field08 holds EOF (item region end)
    if n_pages == 0 and ptab and ptab <= len(d):
        item_end = ptab
    if otab and otab < len(d):
        first = _u32(d, otab)
        if otab < first <= len(d):
            offs = []
            p = otab
            while p + 4 <= first:
                v = _u32(d, p)
                if v == 0 or v >= len(d):
                    break
                offs.append(v)
                p += 4
            out['item_offsets'] = offs
            for i, o in enumerate(offs):
                e = offs[i + 1] if i + 1 < len(offs) else item_end
                if e <= o or o >= len(d):
                    continue
                st = parse_item_stream(d[o:min(e, len(d))])
                st['index'] = i
                st['file_off'] = o
                out['items'].append(st)
                out['errors'].extend(f'item{i}: {m}' for m in st['errors'])
    # ── page table + 312B records ──
    if n_pages and ptab and ptab + n_pages * PAGE_ENT_SIZE <= len(d):
        for p in range(n_pages):
            off, cnt, sent = struct.unpack_from('<IHH', d, ptab + p * 8)
            recs = []
            for i in range(cnt):
                o = off + i * ITEM_SIZE
                if o + ITEM_SIZE > len(d):
                    break
                recs.append(parse_item_record(d, o))
            out['pages'].append({'index': p, 'data_off': off, 'count': cnt,
                                 'sentinel': sent, 'records': recs})
    # ── trailing index table ──
    if n_pages and f14 and f14 < len(d):
        tail = []
        for o in range(f14, len(d) - 7, 8):
            tail.append(struct.unpack_from('<4H', d, o))
        out['tail'] = tail
    return out


def parse_item_record(d, o):
    """Decode one 312B page-item record at offset o."""
    u = lambda x: _u16(d, o + x)
    s = lambda x: _s16(d, o + x)
    slots = []
    for i in range(16):
        b = o + 0x30 + i * 12
        slots.append({'sel': _s16(d, b), 'flags': _u16(d, b + 2),
                      'val': _u32(d, b + 4), 'ext': _u32(d, b + 8)})
    return {
        'type': u(0x00), 'flags': u(0x02),
        'x': s(0x04), 'y': s(0x06), 'w': u(0x08), 'h': u(0x0A),
        'x2': s(0x0C), 'y2': s(0x0E),
        'f14': u(0x14), 'ref': u(0x16), 'sel18': s(0x18), 'pool': u(0x1A),
        'f1c': u(0x1C), 'f1e': u(0x1E),
        's20': s(0x20), 'v22': u(0x22), 's24': s(0x24), 'v26': s(0x26),
        's28': s(0x28), 'v2a': u(0x2A),
        'rgba': d[o + 0x2C:o + 0x30],
        'slots': slots,
        'f_f0': _u32(d, o + 0xF0), 'f_f4': u(0xF4), 'f_f6': u(0xF6),
        'f_f8': u(0xF8), 'f_fa': u(0xFA), 'f_fc': u(0xFC), 'f_fe': s(0xFE),
        's_100': s(0x100), 'f_104': _u32(d, o + 0x104), 's_10c': s(0x10C),
        'v_10e': u(0x10E), 'f_110': u(0x110),
        'v_118': u(0x118), 'v_11a': u(0x11A), 'v_11c': u(0x11C),
        'v_11e': u(0x11E), 'v_120': u(0x120), 'v_122': u(0x122),
        'v_124': u(0x124), 'v_126': u(0x126),
    }


def parse_sbin(d):
    """Parse a .sbin texture bundle: 16B header + n 16B descriptors."""
    if len(d) < 16:
        raise ValueError('too small')
    magic, ndesc = struct.unpack_from('<II', d, 0)
    descs = []
    for i in range(ndesc):
        o = 0x10 + i * SBIN_DESC_SIZE
        if o + 16 > len(d):
            break
        a, b = struct.unpack_from('<II', d, o + 8)
        descs.append({'params': d[o:o + 8], 'off_a': a, 'off_b': b,
                      'size': b - a if b >= a else -1})
    return {'magic': magic, 'n_desc': ndesc, 'descs': descs,
            'file_size': len(d)}


def summarize(path):
    d = open(path, 'rb').read()
    ext = os.path.splitext(path)[1].lower()
    if ext == '.sbin':
        s = parse_sbin(d)
        print(f'{path}: SBIN magic={s["magic"]} descs={s["n_desc"]} '
              f'size=0x{s["file_size"]:X}')
        for i, r in enumerate(s['descs']):
            print(f'  desc{i}: params={r["params"].hex()} '
                  f'a=0x{r["off_a"]:X} b=0x{r["off_b"]:X} span=0x{r["size"]:X}')
        return 0
    if ext == '.rbin':
        print(f'{path}: RBIN {len(d)}B '
              f'{"stub" if d[4:] == bytes(len(d) - 4) else "nonempty"}')
        return 0
    f = parse_sps2(d)
    nrec = sum(len(p['records']) for p in f['pages'])
    print(f'{path}: {f["variant"]} pages={f["n_pages"]} clips={len(f["clips"])} '
          f'items={len(f["items"])} records={nrec} '
          f'tail={len(f.get("tail", []))} errs={len(f["errors"])}')
    for m in f['errors'][:5]:
        print('   !', m)
    return 1 if f['errors'] else 0


if __name__ == '__main__':
    rc = 0
    for p in sys.argv[1:]:
        try:
            rc |= summarize(p)
        except Exception as e:  # noqa: BLE001 - research tool
            print(f'{p}: FAIL {e}')
            rc |= 2
    sys.exit(rc)
