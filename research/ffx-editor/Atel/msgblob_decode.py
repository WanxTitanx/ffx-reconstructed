#!/usr/bin/env python3
# ── msgblob_decode.py — FFX MsgBlob item→worker→label resolver ──────────────
#
# Lane: Jarvis-MSGBLOB (2026-09-18). Stdlib-only, no repo deps.
#
# Builds on the PROVEN MsgBlob record grammar of
# research_tools/Atel/menuscript_menublob.py (FFX_MsgBlob_WalkSectionItemIndex
# @0x797420) and the binding program of FFX_Atel_SetupMenuBlobScripts @0x7976B0
# (docs/reverse/FFX_MENUSCRIPT_OPS_2026-09-18.md §5).
#
# What it does
# ------------
# 1. Parses a battle encounter pack (signature-8 container) and its MsgBlob
#    (header ptr[1]) into item -> {secIdx, slotBase, map[]} records.
# 2. Scans the pack's ATEL chunk-0 script workers for PUSHII constants and
#    resolves embedded GameIndex references against the kernel name tables:
#       cat 3 -> battle/kernel/command.bin      (character commands)
#       cat 4 -> battle/kernel/monmagic1.bin    (monster/aeon magic 1)
#       cat 6 -> battle/kernel/monmagic2.bin    (monster/aeon magic 2)
#       cat 2 -> battle/kernel/item.bin         (consumables)
#       cat 8 -> battle/kernel/a_ability.bin    (auto-abilities)
#    (GameIndex encoding: (category<<12)|index — see
#    FFXProjectEditor/FfxLib/Common/FfxCommon_Util.cs.)
# 3. Decodes the pack text section (header ptr[4]) — a duplicated-offset
#    table of FFX-encoded strings — via the locale ffxsjistbl_* glyph table
#    (docs/reverse/FFX_SJIS_ENCODING_COMPLETE_2026-08-19.md).
# 4. Emits an item -> label table with honest verdicts (PROVEN / PARTIAL /
#    OPEN / NEVER-BOUND / NOT-BOUND-HERE).  Labels are only claimed where a
#    worker's pushed GameIndex resolves to a real kernel name; the +0xC0
#    bound-script-id consumer is NOT located (OPEN), so most menu rows are
#    dynamic/native-resolved and are marked accordingly — nothing is
#    fabricated.
#
# Usage
# -----
#   msgblob_decode.py --pack PACK.bin [--kernel KDIR] [--locale jp|us]
#   msgblob_decode.py --item N  [--pack PACK.bin] [--kernel KDIR]
#   msgblob_decode.py --labels [--pack PACK.bin] [--kernel KDIR] [--csv]
#   msgblob_decode.py --text  [--pack PACK.bin] [--locale jp|us] [--first N]
#
# Defaults: pack = jppc system_01.bin, kernel = jppc battle/kernel dir.
# ────────────────────────────────────────────────────────────────────────────
import argparse
import struct
import sys

CORPUS = ('/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc')
DEF_PACK = CORPUS + '/battle/btl/system_01/system_01.bin'
DEF_KERNEL = CORPUS + '/battle/kernel'
DEF_GLYPH = {'jp': CORPUS + '/ffx_encoding/ffxsjistbl_jp.bin',
             'us': CORPUS + '/ffx_encoding/ffxsjistbl_us.bin'}


def u16(b, o):
    return struct.unpack_from('<H', b, o)[0]


def u32(b, o):
    return struct.unpack_from('<I', b, o)[0]


# ── Pack / MsgBlob grammar (PROVEN @0x797420) ────────────────────────────────

def pack_ptrs(b):
    """Signature-8 pack: u32 sig @0, u32 ptr table @4."""
    sig = u32(b, 0)
    ptrs = [u32(b, 4 + 4 * i) for i in range(11)]
    return sig, ptrs


def parse_blob(b, base):
    """MsgBlob @ base.  Port of menuscript_menublob.parse_blob.

    Returns {lane1Base, count, secIdx[], secRecs[], sections[]}.
    secRecs[i] = {slotBase, mapOff}; sections[i] = {n, map[]}.
    """
    lane1 = b[base]
    count = b[base + 1]
    sec_idx = list(b[base + 2: base + 2 + count])
    tab0 = (count + 1) // 2
    nsec = max([s for s in sec_idx if s != 0xFF], default=-1) + 1
    recs, secs = [], []
    for i in range(nsec):
        v6 = tab0 + 2 * i
        slot = u16(b, base + 4 + 2 * (v6 - 1))
        moff = u16(b, base + 4 + 2 * v6)
        n = u16(b, base + moff) if moff else 0
        mp = [u16(b, base + moff + 2 + 2 * j) for j in range(n)] if n else []
        recs.append({'slotBase': slot, 'mapOff': moff})
        secs.append({'n': n, 'map': mp})
    return {'lane1Base': lane1, 'count': count, 'secIdx': sec_idx,
            'secRecs': recs, 'sections': secs, 'base': base}


def item_record(blob, item):
    """item -> {sec, slotLo, valid[(subIdx, workerIdx)]} or None."""
    if item >= blob['count']:
        return None
    s = blob['secIdx'][item]
    if s == 0xFF:
        return None
    rec = blob['secRecs'][s]
    sec = blob['sections'][s]
    valid = [(j, m) for j, m in enumerate(sec['map']) if m != 0xFFFF]
    return {'sec': s, 'slotLo': rec['slotBase'] & 0xFF,
            'mapOff': rec['mapOff'], 'n': sec['n'], 'valid': valid}


# ── ATEL chunk-0 worker constant scan ────────────────────────────────────────

def atel_chunk0(b, ptrs):
    """chunk0 = bytes ptr[0] .. ptr[1] (ATEL script).  Returns blob bytes."""
    return b[ptrs[0]:ptrs[1]]


def atel_workers(b):
    """Minimal ATEL header walk -> worker EP code offsets.

    Header (rel chunk0): +0x14 workerCount, +0x30 codeStart,
    +0x38 .. workerOffTable (u32[n] rel-to-scriptBase, worker descriptor
    offsets — descriptors are 0x34 B each).  Each descriptor +0x20 ->
    u32 epTableOff (rel scriptBase); epTable = u16[n] code offsets rel
    to codeStart (0-terminated).
    """
    code_len = u32(b, 0x00)
    code_off = u32(b, 0x30)          # scriptCodeOff rel to scriptBase
    nwork = u16(b, 0x34)
    workers = []
    for w in range(nwork):
        woff = u32(b, 0x38 + 4 * w)
        if woff == 0 or woff + 0x34 > len(b):
            workers.append({'eps': []})
            continue
        fcount = u16(b, woff + 0x08)
        ftab = u32(b, woff + 0x20)
        eps = []
        for k in range(fcount):
            v = u32(b, ftab + 4 * k)
            if code_off + v < len(b):
                eps.append(code_off + v)
        workers.append({'eps': eps})
    return {'workers': workers, 'codeOff': code_off, 'codeLen': code_len}


# ATEL opcode bytes that take a u16 immediate operand (from atel_disasm OPS):
# PUSHII/PUSHI/PUSHF/POPV/POPF/POPI/PUSHP/CALL/CALLPOPA/jumps use &0x80 opcodes
# with a 2-byte operand.  We scan PUSHII (0xAE) / PUSHI (0xAD) / PUSHF (0xAF).

def worker_consts(b, worker, code_off):
    """Collect u16 PUSHII/PUSHI args in all of a worker's EPs (ordered)."""
    vals = []
    for start in worker['eps']:
        pos = start
        guard = 0
        while guard < 8000 and pos < len(b):
            guard += 1
            op = b[pos]
            if op & 0x80:
                arg = u16(b, pos + 1)
                if op in (0xAE, 0xAD):
                    vals.append(arg)
                pos += 3
            else:
                pos += 1
                if op in (0x40, 0x34, 0x3C, 0x3D, 0x3E, 0x3F):
                    break
    return vals


# ── Kernel name tables (signature-1 files, shared layout) ────────────────────
# header: u32 sig, u32 0, u32 0, u16 minidx, u16 maxidx, u16 esize,
#         u32 tsize, u32 tableOff ; records esize B; first u16 of a record's
#         TSInfo block = offset of its name in the trailing string blob
#         (blob starts at tableOff + rows*esize).

def load_kernel_names(path, glyph):
    """Return {idx: name} for a kernel .bin (command/monmagic/item/…)."""
    try:
        b = open(path, 'rb').read()
    except OSError:
        return {}
    if len(b) < 0x14:
        return {}
    minidx, maxidx, esize, _tsize, toff = struct.unpack_from('<hhhHi', b, 8)
    if esize <= 0 or toff <= 0:
        return {}
    rows = maxidx - minidx + 1
    dend = toff + rows * esize
    out = {}
    for i in range(minidx, maxidx + 1):
        rec = toff + (i - minidx) * esize
        o = u16(b, rec)
        if o:
            out[i] = ffx_text(b, dend + o, glyph)
    return out


# ── FFX text decoder (FFX_SJIS_ENCODING_COMPLETE_2026-08-19) ─────────────────

BANK_LEADS = {0x2C: 0, 0x2D: 0, 0x2E: 0, 0x2F: 0,   # bank0 base.ftc  (-8992)
              0x2A: 1, 0x2B: 1,                      # bank1 event FTCX (-8784)
              0x28: 2, 0x29: 2,                      # bank2           (-8368)
              0x26: 3, 0x27: 3,                      # bank3           (-7952)
              0x06: 5}                               # bank5           (-1296)
BANK_BIAS = {0: -8992, 1: -8784, 2: -8368, 3: -7952, 5: -1296}
CTRL_NAMES = {0x03: 'endblk', 0x09: 'speaker', 0x0A: 'color',
              0x0B: 'btn', 0x0C: 'var', 0x10: 'wait', 0x12: 'num',
              0x13: 'voice', 0x23: 'unk23', 0x24: 'unk24', 0x25: 'unk25'}


def load_glyph(path):
    try:
        return open(path, 'rb').read().decode('utf-8')
    except (OSError, UnicodeDecodeError):
        return ''


def ffx_text(b, o, glyph, limit=48):
    """Decode an FFX-encoded string at b[o:].  1B glyphs = byte-0x30 index
    into glyph table; 2B = (lead,idx) via bank bias; control bytes shown as
    <NN>."""
    out = []
    i = 0
    while o + i < len(b) and i < limit:
        c = b[o + i]
        if c == 0:
            break
        if c >= 0x30:
            idx = c - 0x30
            out.append(glyph[idx] if idx < len(glyph) else '<%02x>' % c)
            i += 1
        elif c in BANK_LEADS and o + i + 1 < len(b):
            bank = BANK_LEADS[c]
            idx = 208 * c + b[o + i + 1] + BANK_BIAS[bank]
            out.append(glyph[idx] if 0 <= idx < len(glyph)
                       else '<g%d>' % idx)
            i += 2
        else:
            out.append('<%02x>' % c)
            i += 1
    return ''.join(out)


def pack_text_records(b, ptrs, glyph):
    """ptr[4] text chunk: u32 off-pairs {a,a} then FFX strings."""
    base = ptrs[4]
    if not base or base >= len(b):
        return []
    recs = []
    i = 0
    while base + i * 8 + 8 <= len(b):
        a = u32(b, base + i * 8)
        c = u32(b, base + i * 8 + 4)
        if a == 0 or a != c or a > len(b):
            break
        recs.append(ffx_text(b, base + a, glyph))
        i += 1
    return recs


# ── GameIndex resolution ─────────────────────────────────────────────────────

def build_tables(kernel, glyph):
    # NOTE (corpus-verified): command.bin stores names in the *latin/US*
    # font table even in jppc; monmagic/item/a_ability use the locale (jp)
    # table.  Load each with its own glyph map.
    us = load_glyph(DEF_GLYPH['us'])
    return {
        3: load_kernel_names(kernel + '/command.bin', us),
        4: load_kernel_names(kernel + '/monmagic1.bin', glyph),
        6: load_kernel_names(kernel + '/monmagic2.bin', glyph),
        2: load_kernel_names(kernel + '/item.bin', glyph),
        8: load_kernel_names(kernel + '/a_ability.bin', glyph),
    }


def gameindex_names(consts, tables):
    """Ordered unique kernel names for the GameIndex consts found."""
    seen = set()
    out = []
    for v in consts:
        cat, idx = v >> 12, v & 0xFFF
        if cat in tables and idx in tables[cat] and idx not in seen:
            seen.add(idx)
            out.append((v, tables[cat][idx]))
    return out


# ── Label verdicts ───────────────────────────────────────────────────────────

NEVER_BOUND = {23, 24, 36, 116} | set(range(94, 107)) | set(range(127, 137))
AEON_FAMILY = set(range(33, 41))          # hardcoded aeon-menu bindings
ENCOUNTER_FAMILY = set(range(41, 56))     # bound in encounter packs, not sys01

# item -> (verdict, label) for bindings whose worker constants resolve to a
# kernel name in the standard pack (corpus-verified this lane).
def label_for(item, slot, worker_consts_list, tables):
    names = gameindex_names(worker_consts_list, tables)
    if item == 37 and any(n == 'Zanmato' for _, n in names):
        return ('PROVEN', 'aeon menu: Yojimbo '
                '(Dismiss/Daigoro/Kozuka/Wakizashi/Zanmato)')
    if item == 38 and any(n == 'Camisade' for _, n in names):
        return ('PROVEN', 'aeon menu: Cindy (white+black magic, Camisade, '
                'Delta Attack)')
    if item == 39 and any(n == 'Razzia' for _, n in names):
        return ('PROVEN', 'aeon menu: Sandy (buffs/heals, Razzia, '
                'Delta Attack)')
    if item == 40 and any(n == 'Passado' for _, n in names):
        return ('PROVEN', 'aeon menu: Mindy (drain, Passado, Delta Attack)')
    if names:
        # item with kernel-name refs but role not fully separated
        return ('PARTIAL', 'refs ' + ';'.join(n for _, n in names[:4]))
    if item in AEON_FAMILY:
        return ('PARTIAL', 'aeon-menu slot (standard-aeon family; '
                'no cmd-list in slot worker)')
    if not worker_consts_list:
        return ('OPEN', 'empty/stub slot worker (dynamic, native-resolved)')
    return ('OPEN', 'actor-entity slot (spawn/motion cfg; name native)')


# ── CLI ──────────────────────────────────────────────────────────────────────

def cmd_pack(pack, kernel, glyph):
    b = open(pack, 'rb').read()
    sig, ptrs = pack_ptrs(b)
    print('pack: %s' % pack)
    print('  sig=%d size=%#x' % (sig, len(b)))
    for i, p in enumerate(ptrs):
        if p:
            print('  ptr[%d]=%#x' % (i, p))
    blob = parse_blob(b, ptrs[1])
    print('MsgBlob @%#x: lane1Base=%d count=%d nsec=%d' %
          (ptrs[1], blob['lane1Base'], blob['count'], len(blob['secRecs'])))
    present = [i for i, s in enumerate(blob['secIdx']) if s != 0xFF]
    print('  present items (%d): %s' % (len(present), present))
    absent = [i for i in range(blob['count']) if blob['secIdx'][i] == 0xFF]
    print('  absent  items (%d): %s' % (len(absent), absent))
    c0 = atel_chunk0(b, ptrs)
    aw = atel_workers(c0)
    print('ATEL chunk0: %d workers, codeLen=%#x' %
          (len(aw['workers']), aw['codeLen']))
    if ptrs[4]:
        recs = pack_text_records(b, ptrs, glyph)
        print('text chunk @%#x: %d records (battle chatter, not labels)'
              % (ptrs[4], len(recs)))
        for i, s in enumerate(recs[:6]):
            print('    [%d] %s' % (i, s))


def cmd_item(item, pack, kernel, glyph):
    b = open(pack, 'rb').read()
    sig, ptrs = pack_ptrs(b)
    blob = parse_blob(b, ptrs[1])
    rec = item_record(blob, item)
    print('pack %s' % pack)
    if rec is None:
        print('item %d: absent (secIdx=0xFF or out of range)' % item)
        return
    print('item %d: sec=%d slotBase=%d (slotGlobal lane0=%d, lane1=%d)'
          % (item, rec['sec'], rec['slotLo'], rec['slotLo'],
             blob['lane1Base'] + rec['slotLo']))
    print('  map n=%d  valid sub-idx->worker: %s' % (rec['n'], rec['valid']))
    c0 = atel_chunk0(b, ptrs)
    aw = atel_workers(c0)
    slot = rec['slotLo']
    tables = build_tables(kernel, glyph)
    # label evidence can live in the slot ctx worker (per-item data, e.g. the
    # aeon command lists) AND/OR the dispatched workers (map values, e.g. the
    # shared handler carrying a command id).  Collect consts from both.
    consts = []
    if slot < len(aw['workers']):
        consts += worker_consts(c0, aw['workers'][slot], aw['codeOff'])
        print('  setup worker w%d: %d EPs, %d consts' %
              (slot, len(aw['workers'][slot]['eps']), len(consts)))
    for sub, w in rec['valid']:
        if w < len(aw['workers']):
            dc = worker_consts(c0, aw['workers'][w], aw['codeOff'])
            dn = gameindex_names(dc, tables)
            if dn:
                print('  dispatched w%d (sub%d): %s' %
                      (w, sub, '; '.join(n for _, n in dn)))
            consts += dc
    names = gameindex_names(consts, tables)
    for v, n in names:
        print('    GameIndex %#06x -> %s' % (v, n))
    verdict, label = label_for(item, slot, consts, tables)
    print('  verdict=%s label=%s' % (verdict, label))


def cmd_labels(pack, kernel, glyph, as_csv):
    b = open(pack, 'rb').read()
    sig, ptrs = pack_ptrs(b)
    blob = parse_blob(b, ptrs[1])
    c0 = atel_chunk0(b, ptrs)
    aw = atel_workers(c0)
    tables = build_tables(kernel, glyph)
    rows = []
    # bound loop items + hardcoded (from MENUSCRIPT-OPS §5)
    loop = list(range(5, 33)) + list(range(41, 56)) + \
        list(range(79, 107)) + list(range(109, 137))
    hard = [33, 34, 35, 37, 38, 39, 40]
    sid = {}
    for i in range(5, 33):
        sid[i] = i - 5
    for i in range(41, 56):
        sid[i] = i - 41
    for i in range(79, 107):
        sid[i] = i - 79
    for i in range(109, 137):
        sid[i] = i - 109
    sid.update({33: 28, 34: 29, 35: 30, 37: 14, 38: 15, 39: 16, 40: 17})
    bound = set(loop) | set(hard)
    for item in range(blob['count']):
        rec = item_record(blob, item)
        is_bound = item in bound
        if item in NEVER_BOUND:
            verdict, label = 'NEVER-BOUND', 'no pack authors section'
        elif not is_bound:
            verdict, label = ('STRUCTURAL',
                              'non-binding section (menu-root/aux)')
        else:
            if rec is None:
                if item in ENCOUNTER_FAMILY:
                    verdict, label = (
                        'PARTIAL',
                        'encounter-bound (per-pack worker; e.g. '
                        'Scan@bjyt02_00, Cancel@hiku15_00, stub@sins03_00)')
                else:
                    verdict, label = 'NOT-BOUND-HERE', 'absent in this pack'
            else:
                slot = rec['slotLo']
                consts = worker_consts(c0, aw['workers'][slot],
                                       aw['codeOff']) \
                    if slot < len(aw['workers']) else []
                # fold in dispatched-worker consts (pack-bound commands live
                # there, not in the slot ctx worker).
                for sub, w in rec['valid']:
                    if w < len(aw['workers']):
                        consts += worker_consts(c0, aw['workers'][w],
                                                aw['codeOff'])
                verdict, label = label_for(item, slot, consts, tables)
        sec = rec['sec'] if rec else ''
        slot = rec['slotLo'] if rec else ''
        rows.append((item, sec, slot, sid.get(item, ''), label, verdict))
    # ctx-3 branch (MENUSCRIPT-OPS §5): LookupSourceEntry(3, i+20, {61,4,64})
    # writes i+20 — actor-context records, label = the actor's name (dynamic).
    for msg in (61, 4, 64):
        for i in range(8):
            rows.append(('actor%d+20' % i, '', 'ctx3',
                         i + 20, 'actor slot (msg %d; dynamic name)' % msg,
                         'PARTIAL'))
    if as_csv:
        print('item,secIdx,workerIdx,scriptId,label,verdict')
    else:
        print('%-5s %-6s %-9s %-8s %-52s %s' %
              ('item', 'secIdx', 'worker', 'scriptId', 'label', 'verdict'))
    for r in rows:
        if as_csv:
            print('%s,%s,%s,%s,"%s",%s' %
                  (r[0], r[1], r[2], r[3], r[4].replace('"', "'"), r[5]))
        else:
            print('%-5s %-6s %-9s %-8s %-52s %s' %
                  (r[0], r[1], r[2], r[3], r[4][:52], r[5]))


def cmd_text(pack, glyph, first):
    b = open(pack, 'rb').read()
    _, ptrs = pack_ptrs(b)
    recs = pack_text_records(b, ptrs, glyph)
    print('%d text records in %s ptr[4]' % (len(recs), pack))
    for i, s in enumerate(recs[:first]):
        print('%3d %s' % (i, s))


def main():
    ap = argparse.ArgumentParser(
        description='FFX MsgBlob item->worker->label resolver')
    ap.add_argument('--pack', default=DEF_PACK)
    ap.add_argument('--kernel', default=DEF_KERNEL)
    ap.add_argument('--locale', default='jp', choices=['jp', 'us'])
    ap.add_argument('--item', type=int)
    ap.add_argument('--labels', action='store_true')
    ap.add_argument('--text', action='store_true')
    ap.add_argument('--first', type=int, default=30)
    ap.add_argument('--csv', action='store_true')
    a = ap.parse_args()
    glyph = load_glyph(DEF_GLYPH[a.locale])
    if a.item is not None:
        cmd_item(a.item, a.pack, a.kernel, glyph)
    elif a.labels:
        cmd_labels(a.pack, a.kernel, glyph, a.csv)
    elif a.text:
        cmd_text(a.pack, glyph, a.first)
    else:
        cmd_pack(a.pack, a.kernel, glyph)


if __name__ == '__main__':
    sys.exit(main())
