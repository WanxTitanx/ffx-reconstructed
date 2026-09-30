#!/usr/bin/env python3
"""romdir_probe.py — IOPRP ROMDIR image prober + IRX census (stdlib-only).

Mission (Jarvis-ROMDIR, wave-17 lane 2026-09-18): full census of
`IOPRP234.IMG` from the FFX International PS2 disc — parse the ROMDIR
table, extract every embedded IOP module, identify name+version, and
classify standard-Sony vs Square-custom.  Also census the 10 standalone
*.IRX files shipped next to the image (shallow pass — IOPSOUND.IRX is
owned by a sibling lane and only gets header-level treatment).

FORMAT NOTES (verified against IOPRP234.IMG bytes, 2026-09-18):
  ROMDIR records — 16 bytes each, fields **LITTLE-ENDIAN** on this disc:
      +0   char name[10]   (NUL-padded)
      +10  u16 extinfo_size  (bytes this entry owns in the EXTINFO region)
      +12  u32 file_size
  Table ends with a 16-byte all-zero record.  Module bodies follow the
  table + EXTINFO region, 0x80-aligned, in ROMDIR order (all 15 bodies
  in this image land on 0x80 boundaries; align() below uses 16 which
  produces identical offsets here — noted honestly).
  (NB: the lane brief said "big-endian" — the disc image proves LE:
   ROMDIR size field reads 0x130 = 18*16+16, EXTINFO 0x244, LOADCORE
   body size 0x25f5; BE would give absurd values.  Recorded honestly.)

  EXTINFO region — sequential TLV records {u16 tag; u8 len; u8 type;
  u8 data[len]}, packed back-to-back; each ROMDIR entry owns
  extinfo_size bytes of it, in order:
      type 1: data = {u8 day(BCD); u8 month(BCD); u16 year}  -> build date
      type 2: tag = module version (BCD-ish, e.g. 0x0204 -> 2.04), len=0
      type 3: data = name/comment string (NUL-padded to 4)
  Verified: extinfo_size for every entry == sum of its sub-records.

  IRX (e_type 0xFF80 IOP module):
      moduleinfo:  {u16 tag; u16 version; char name[]} — sits right after
                   the ELF program headers in every module observed here
      export lib:  u32 magic 0x41c00000; u32 next; u16 ver; u16 flags;
                   char name[8]; u32 exports[] (module-vaddr pointers)
      import lib:  u32 magic 0x41e00000; u32 next; u16 ver; u16 flags;
                   char name[8]; stubs[] of {jr $ra (0x03e00008);
                   li $v0,ordinal (0x2400NNNN)} — 8 bytes each

USAGE
  python3 romdir_probe.py --img IOPRP234.IMG --extract work/_romdir
  python3 romdir_probe.py --irx-dir unipyx --csv-prefix out/irx
  python3 romdir_probe.py --img IOPRP234.IMG --irx-dir unipyx \
      --extract work/_romdir --csv-romdir romdir_modules.csv \
      --csv-irx irx_standalone_census.csv --strings

Exit code: 0 on success, 2 on argument errors, 1 on parse failure.
"""

import argparse
import csv
import hashlib
import os
import re
import struct
import sys

# ── helpers ────────────────────────────────────────────────────────────────

def u16(b, o): return struct.unpack_from('<H', b, o)[0]
def u32(b, o): return struct.unpack_from('<I', b, o)[0]


def align(n, a=16):
    return (n + a - 1) & ~(a - 1)


def bcd_ver(v):
    """Render a BCD-ish version word like 0x0204 -> '2.04'."""
    return '%d.%02x' % (v >> 8, v & 0xFF)


def ascii_at(b, o, maxlen=64):
    end = b.find(b'\x00', o, o + maxlen)
    if end < 0:
        end = min(len(b), o + maxlen)
    return b[o:end].decode('ascii', 'replace')


# ── ROMDIR / EXTINFO parsing ────────────────────────────────────────────────

def parse_romdir(data):
    """Parse a RESET+ROMDIR image. Returns dict with entries + layout."""
    if not data.startswith(b'RESET'):
        return None
    entries = []
    off = 0
    while off + 16 <= len(data):
        raw_name = data[off:off + 10].split(b'\x00', 1)[0]
        extinfo_size = u16(data, off + 10)
        fsize = u32(data, off + 12)
        if not raw_name:
            break
        try:
            nm = raw_name.decode('ascii')
        except UnicodeDecodeError:
            break
        if not re.match(r'^[A-Za-z0-9_.+\-]+$', nm):
            break
        entries.append({'name': nm, 'extinfo_size': extinfo_size,
                        'size': fsize, 'romdir_off': off})
        off += 16
    table_end = off + 16                      # + terminator record
    extinfo_sz = next((e['size'] for e in entries if e['name'] == 'EXTINFO'), 0)
    extinfo_off = table_end                   # extinfo region follows table
    body_start = align(extinfo_off + extinfo_sz)
    # assign body offsets (sequential, 16B-aligned, ROMDIR order)
    cursor = body_start
    for e in entries:
        if e['name'] in ('RESET', 'ROMDIR', 'EXTINFO'):
            e['data_off'] = None
            continue
        e['data_off'] = cursor if e['size'] else None
        if e['size']:
            cursor = align(cursor + e['size'])
    return {'entries': entries, 'table_end': table_end,
            'extinfo_off': extinfo_off, 'extinfo_size': extinfo_sz,
            'body_start': body_start, 'img_size': len(data)}


def parse_extinfo_region(data, romdir):
    """Walk the EXTINFO region as TLV sub-records, grouped per ROMDIR entry
    (each entry consumes extinfo_size bytes, in order)."""
    base = romdir['extinfo_off']
    pos = base
    for e in romdir['entries']:
        blob = data[pos:pos + e['extinfo_size']]
        pos += e['extinfo_size']
        sub = []
        p = 0
        while p + 4 <= len(blob):
            tag = u16(blob, p)
            ln = blob[p + 2]
            ty = blob[p + 3]
            payload = blob[p + 4:p + 4 + ln]
            sub.append({'tag': tag, 'len': ln, 'type': ty,
                        'data': payload, 'off': pos - e['extinfo_size'] + p})
            p += 4 + ln
        # digest into friendly fields
        e['ext_name'] = ''
        e['ext_version'] = ''
        e['ext_date'] = ''
        for s in sub:
            if s['type'] == 1 and s['len'] >= 4:
                day, mon = s['data'][0], s['data'][1]
                yr = u16(s['data'], 2)
                e['ext_date'] = '%04x-%02x-%02x' % (yr, mon, day)
            elif s['type'] == 2:
                e['ext_version'] = bcd_ver(s['tag'])
            elif s['type'] == 3:
                txt = s['data'].split(b'\x00', 1)[0].decode('ascii', 'replace')
                # first type-3 string wins (name); later ones -> comment
                if not e['ext_name']:
                    e['ext_name'] = txt
                else:
                    e['ext_name'] += ' | ' + txt
        e['ext_subs'] = sub
    return romdir['entries']


# ── IRX parsing ─────────────────────────────────────────────────────────────

ELF_MIN_HEADER = 52


def parse_elf32(buf, off=0):
    if len(buf) - off < ELF_MIN_HEADER or buf[off:off + 4] != b'\x7fELF':
        return None
    if buf[off + 4] != 1 or buf[off + 5] != 1:      # 32-bit LE only
        return None
    return {
        'e_type': u16(buf, off + 16), 'e_machine': u16(buf, off + 18),
        'e_entry': u32(buf, off + 24), 'e_phoff': u32(buf, off + 28),
        'e_shoff': u32(buf, off + 32), 'e_flags': u32(buf, off + 36),
        'e_phnum': u16(buf, off + 44), 'e_shnum': u16(buf, off + 48),
    }


def find_moduleinfo_structural(buf, elf):
    """Deterministic moduleinfo read — Sony IRX layout (verified on every
    module in this corpus, 2026-09-18): the .iopmod block sits at
    e_phoff + e_phnum*32 as {u32 id/link; u32 entry; u32 gp; u32 text_size;
    u32 data_size; u32 bss_size; u16 version; char name[4-aligned NUL]}.
    The u16 version is the LAST 2 bytes before the name — there is NO
    separate tag u16 (the earlier fuzzy scanner read the bss_size high
    half as "tag", which silently fails when bss >= 0x10000, and its
    BCD/length gates dropped 'hdd'/'pfs'/'mcserv'/'IopSoundDriver')."""
    if not elf:
        return None
    base = elf['e_phoff'] + elf['e_phnum'] * 32
    if base + 28 > len(buf):
        return None
    entry = u32(buf, base + 4)
    ver = u16(buf, base + 24)
    name = ascii_at(buf, base + 26, 40)
    # sanity: plausible BCD-ish version + printable name + entry sane
    if not (0x0100 <= ver <= 0x09FF):
        return None
    if not re.match(r'^[ -~]{2,40}$', name) or not re.search(r'[A-Za-z]', name):
        return None
    k = base + 26 + len(name)
    if k >= len(buf) or buf[k] != 0:
        return None
    if entry != elf['e_entry']:
        return None                      # block misaligned — don't trust
    return {'off': base + 24, 'tag': 0, 'ver': ver,
            'ver_str': bcd_ver(ver), 'name': name}


def find_moduleinfo(buf, lo=0, hi=None):
    """Fuzzy fallback: scan for {u16 tag; u16 version; char name[]}.
    Kept for non-standard layouts; the structural reader above is
    authoritative on this disc."""
    if hi is None:
        hi = min(len(buf), 0x4000)
    best = None
    i = lo
    while i + 8 < hi:
        tag = u16(buf, i)
        ver = u16(buf, i + 2)
        # version sanity: BCD-ish 0x0100..0x0999 (v1.00..v9.99)
        if 0x0100 <= ver <= 0x0999 and (ver & 0xF) <= 9 and \
                ((ver >> 4) & 0xF) <= 9 and (tag & 0xFF) == 0:
            j = i + 4
            nm = ascii_at(buf, j, 40)
            if re.match(r'^[ -~]{3,40}$', nm) and \
                    re.search(r'[A-Za-z]', nm) and '\x00' not in nm:
                # require NUL right after name within field pad
                k = j + len(nm)
                if k < len(buf) and buf[k] == 0 and len(nm) <= 36:
                    best = {'off': i, 'tag': tag, 'ver': ver,
                            'ver_str': bcd_ver(ver), 'name': nm}
                    break
        i += 2
    return best


def scan_irx_tables(buf):
    """Find export (0x41c00000) and import (0x41e00000) tables."""
    exports, imports = [], []
    for magic, sink in ((0x41c00000, exports), (0x41e00000, imports)):
        needle = struct.pack('<I', magic)
        i = 0
        while True:
            j = buf.find(needle, i)
            if j < 0:
                break
            i = j + 4
            if j + 20 > len(buf):
                continue
            ver = u16(buf, j + 8)
            flags = u16(buf, j + 10)
            raw_name = buf[j + 12:j + 20]
            # name must be mostly-printable ASCII
            nm = raw_name.split(b'\x00', 1)[0]
            try:
                name = nm.decode('ascii')
            except UnicodeDecodeError:
                continue
            if not re.match(r'^[ -~]{2,8}$', name) or not name.strip():
                continue
            if not (0x0100 <= ver <= 0x0FFF):
                continue
            nxt = u32(buf, j + 4)
            if nxt != 0 and not (0 <= nxt < 0x20000000):
                continue
            rec = {'off': j, 'ver': ver, 'ver_str': bcd_ver(ver),
                   'flags': flags, 'name': name, 'entries': []}
            if magic == 0x41e00000:
                # import stubs: pairs {0x03e00008; 0x2400NNNN}
                p = j + 20
                while p + 8 <= len(buf) and u32(buf, p) == 0x03e00008 \
                        and (u32(buf, p + 4) & 0xFFFF0000) == 0x24000000:
                    rec['entries'].append(u32(buf, p + 4) & 0xFFFF)
                    p += 8
            else:
                # exports: u32 pointers until next magic/non-pointer
                p = j + 20
                while p + 4 <= len(buf):
                    v = u32(buf, p)
                    if v == 0x41c00000 or v == 0x41e00000:
                        break
                    if v == 0 and len(rec['entries']) > 0:
                        break            # terminator
                    if v == 0:
                        p += 4
                        continue
                    if v < 0x20 or v > 0x02000000:
                        break
                    rec['entries'].append(v)
                    p += 4
                    if len(rec['entries']) > 512:
                        break
            sink.append(rec)
    return exports, imports


STRING_RE = re.compile(rb'[ -~]{5,}')


def strings_census(buf, needles):
    """ASCII strings >=5 + needle hit list."""
    strs = [m.group().decode('ascii', 'replace')
            for m in STRING_RE.finditer(buf)]
    hits = {}
    for n in needles:
        nl = n.lower()
        for s in strs:
            if nl in s.lower():
                hits.setdefault(n, []).append(s)
                break
    return strs, hits


def func_est(buf):
    """Crude function census: count `addiu $sp,$sp,-N` prologues
    (bytes: imm16-hi>=0x80 then BD 27). Honest estimate only."""
    n = 0
    i = buf.find(b'\xbd\x27')
    while i >= 0:
        if i > 0 and buf[i - 1] >= 0x80:
            n += 1
        i = buf.find(b'\xbd\x27', i + 2)
    return n


# ── classification ──────────────────────────────────────────────────────────

# known Sony IOP module / library names (IOPRP boot set + disc modules +
# common SDK modules — anything else is a custom-module suspect)
SONY_MODULES = {
    # kernel / IOPRP boot set
    'loadcore', 'sifcmd', 'sifman', 'threadman', 'ioman', 'iomanx',
    'modload', 'fileio', 'cdvdman', 'cdvdfsv', 'loadfile', 'timemani',
    'romdrv', 'eesync', 'sysclib', 'stdio', 'intrman', 'sysmem',
    'excepman', 'ssbusc', 'dmacman', 'pgpio', 'timrman', 'vblank',
    'heaplib', 'iopreboot', 'iopmtrap', 'deci2', 'romfs', 'rom0',
    # disc-shipped standalone Sony modules
    'sio2man', 'mcman', 'mcserv', 'padman', 'libsd', 'mtapman',
    'atad', 'dev9', 'hdd', 'pfs', 'poweroff', 'dvrfs', 'dvrfile',
    'usbd', 'usbmass', 'smap', 'smaplg', 'speed', 'audiop', 'ilink',
    'smem', 'cdfs', 'msifrpc', 'secrman', 'imgdrv', 'xloadfile',
    'eeloadfile', 'addsub', 'putchar', 'dbcman', 'netcnf', 'inet',
    'lanman', 'pppoe', 'dnas', 'modem', 'kbddrv', 'mousedrv',
    'ps2snd', 'clearspu', 'iopdebug', 'sior', 'siod', 'sio2d',
    'mcxman', 'mcxserv', 'pad2', 'padxman', 'sifinit', 'sio',
    'memory_card', 'cdvd_stm', 'osd', 'emulate', 'flash',
}

# needles that make a module worth flagging for a deeper lane
LANE_NEEDLES = [
    'voice', 'VOICE', 'Voice', 'atel', 'ATEL', 'Atel', 'font', 'FONT',
    'cdrom', 'CDROM', 'cdvd', 'CDVD', 'sceCd', 'vag', 'VAG', '.vag',
    'spu', 'SPU', 'stream', 'Stream', 'STREAM', 'pcm', 'PCM', 'wave',
    'WAVE', 'hd0:', 'pfs0:', 'host0:', 'mc0:', 'hdd', '__system',
    'network', 'SMAP', 'ilink', 'iLINK', 'usb', 'USB', 'deci2', 'DECI2',
    'host:', 'rom0:', 'Copyright', '(c)', 'PsII', 'keropi', 'square',
    'SQUARE', 'debug', 'DEBUG', '.c"', 'Error', 'error',
]


# Square-proprietary module identities seen on this disc (moduleinfo names
# verified 2026-09-18).  IOPSOUND = Square's own IOP sound driver (the
# "IopSoundDriver" module) — NOT a Sony lib; it sits on top of libsd.
SQUARE_MODULES = {
    'iopsounddriver', 'iopsound',
}


def classify(name, mod_name, exports, custom_names=SQUARE_MODULES):
    """Return (classification, reason)."""
    base = name.lower()
    if base.endswith('.irx'):
        base = base[:-4]                 # 'HDD.IRX' -> 'hdd'
    cand = {base, base.rstrip('0123456789')}
    if mod_name:
        cand.add(mod_name.lower())
    for e in exports:
        cand.add(e['name'].lower())
    if any(c in custom_names for c in cand):
        return 'square-custom', 'Square-proprietary module'
    if any(c in SONY_MODULES for c in cand):
        return 'sony', 'name in Sony module set'
    return 'unknown', 'name not in Sony set — suspect'


# ── top-level census of one IRX image (file or embedded) ───────────────────

def census_irx(buf, label, needles=None, do_strings=True):
    """Census one IRX image. Returns a flat dict of findings."""
    info = parse_elf32(buf)
    out = {'label': label, 'size': len(buf)}
    if not info:
        out['elf'] = None
        return out
    out['elf'] = info
    out['moduleinfo'] = find_moduleinfo_structural(buf, info) or \
        find_moduleinfo(buf)
    exports, imports = scan_irx_tables(buf)
    out['exports'] = exports
    out['imports'] = imports
    out['func_est'] = func_est(buf)
    if do_strings:
        strs, hits = strings_census(buf, needles or LANE_NEEDLES)
        out['n_strings'] = len(strs)
        out['needle_hits'] = hits
        # collect a few notable strings for the CSV/report
        notable = []
        for s in strs:
            if any(k in s for k in ('(', ')', '%s', 'rom0:', 'host', ':',
                                    'Error', 'error', 'Version', 'PsII')) \
                    and len(s) < 80:
                notable.append(s)
        out['notable'] = notable[:12]
    mi = out.get('moduleinfo')
    cls, why = classify(label, mi['name'] if mi else '', exports)
    out['classification'] = cls
    out['cls_reason'] = why
    return out


# ── main ────────────────────────────────────────────────────────────────────

def main():
    ap = argparse.ArgumentParser(
        description='IOPRP ROMDIR prober + IRX census (FFX wave-17 lane)')
    ap.add_argument('--img', help='IOPRP*.IMG / RESET+ROMDIR image path')
    ap.add_argument('--extract', metavar='DIR',
                    help='extract embedded modules to DIR')
    ap.add_argument('--irx', nargs='*', default=[],
                    help='standalone IRX files to census')
    ap.add_argument('--irx-dir', help='census every *.IRX in DIR')
    ap.add_argument('--csv-romdir', help='write embedded-module CSV')
    ap.add_argument('--csv-irx', help='write standalone-IRX CSV')
    ap.add_argument('--strings', action='store_true',
                    help='include string/needle census')
    ap.add_argument('--verbose', '-v', action='store_true')
    args = ap.parse_args()
    if not args.img and not args.irx and not args.irx_dir:
        ap.error('need --img or --irx/--irx-dir')

    romdir_rows = []
    if args.img:
        data = open(args.img, 'rb').read()
        rd = parse_romdir(data)
        if not rd:
            print('!! %s: not a RESET+ROMDIR image' % args.img)
            return 1
        parse_extinfo_region(data, rd)
        print('== %s ==' % os.path.basename(args.img))
        print('romdir entries: %d  extinfo: 0x%X@0x%X  body@0x%X  size %d'
              % (len(rd['entries']), rd['extinfo_size'], rd['extinfo_off'],
                 rd['body_start'], rd['img_size']))
        if args.extract:
            os.makedirs(args.extract, exist_ok=True)
        for e in rd['entries']:
            if e['name'] in ('RESET', 'ROMDIR', 'EXTINFO'):
                print('  %-10s  table entry (extinfo=%d)' %
                      (e['name'], e['extinfo_size']))
                continue
            body = data[e['data_off']:e['data_off'] + e['size']]
            cen = census_irx(body, e['name'], do_strings=args.strings)
            ok = bool(cen.get('elf'))
            mi = cen.get('moduleinfo') or {}
            exps = cen.get('exports', [])
            imps = cen.get('imports', [])
            note = []
            if not ok:
                note.append('NO-ELF at computed offset')
            if args.strings:
                hits = cen.get('needle_hits', {})
                flag = [k for k in hits if k.lower() in (
                    'voice', 'atel', 'font', 'vag', '.vag', 'cdrom',
                    'cdvd', 'scecd')]
                if flag:
                    note.append('lane-flag:' + ','.join(sorted(set(flag))))
            row = {
                'module': e['name'],
                'romdir_off': '0x%X' % e['romdir_off'],
                'data_off': '0x%X' % (e['data_off'] or 0),
                'size': e['size'],
                'extinfo_name': e['ext_name'],
                'extinfo_version': e['ext_version'],
                'extinfo_date': e['ext_date'],
                'moduleinfo_name': mi.get('name', ''),
                'moduleinfo_ver': mi.get('ver_str', ''),
                'elf_entry': '0x%X' % cen['elf']['e_entry'] if ok else '',
                'exports_n': len(exps),
                'imports_n': len(imps),
                'export_libs': ';'.join(
                    '%s v%s(%d)' % (x['name'], x['ver_str'],
                                   len(x['entries'])) for x in exps),
                'import_libs': ';'.join(
                    '%s v%s(%d)' % (x['name'], x['ver_str'],
                                   len(x['entries'])) for x in imps),
                'func_est': cen.get('func_est', 0),
                'classification': cen.get('classification', ''),
                'notes': ' | '.join(note),
            }
            romdir_rows.append(row)
            print('  %-10s @0x%-6X %6dB  extinfo="%s" v%s (%s)  '
                  'mi="%s" v%s  exp=%d imp=%d f~%d  %s' % (
                      e['name'], e['data_off'] or 0, e['size'],
                      e['ext_name'][:28], e['ext_version'], e['ext_date'],
                      mi.get('name', ''), mi.get('ver_str', ''),
                      len(exps), len(imps), cen.get('func_est', 0),
                      cen.get('classification', '?')))
            if args.verbose:
                for x in exps:
                    print('      export %-10s v%-5s %d entries' %
                          (x['name'], x['ver_str'], len(x['entries'])))
                for x in imps:
                    print('      import %-10s v%-5s %d stubs' %
                          (x['name'], x['ver_str'], len(x['entries'])))
            if args.extract and e['size']:
                outp = os.path.join(args.extract, e['name'] + '.irx')
                with open(outp, 'wb') as f:
                    f.write(body)

    irx_rows = []
    irx_files = list(args.irx)
    if args.irx_dir:
        for fn in sorted(os.listdir(args.irx_dir)):
            if fn.lower().endswith('.irx'):
                irx_files.append(os.path.join(args.irx_dir, fn))
    for path in irx_files:
        buf = open(path, 'rb').read()
        base = os.path.basename(path)
        cen = census_irx(buf, base, do_strings=True)
        mi = cen.get('moduleinfo') or {}
        exps = cen.get('exports', [])
        imps = cen.get('imports', [])
        hits = cen.get('needle_hits', {})
        flag = sorted({k for k in hits if k.lower() in (
            'voice', 'atel', 'font', 'vag', '.vag', 'cdrom', 'cdvd',
            'scecd', 'spu', 'stream', 'hd0:', 'pfs0:', 'network')})
        row = {
            'file': base,
            'path': path,
            'size': len(buf),
            'sha256_12': hashlib.sha256(buf).hexdigest()[:12],
            'elf_entry': '0x%X' % cen['elf']['e_entry'] if cen.get('elf')
            else '',
            'moduleinfo_name': mi.get('name', ''),
            'moduleinfo_ver': mi.get('ver_str', ''),
            'moduleinfo_tag': '0x%04X' % mi['tag'] if mi else '',
            'exports_n': len(exps),
            'imports_n': len(imps),
            'export_libs': ';'.join(
                '%s v%s(%d)' % (x['name'], x['ver_str'], len(x['entries']))
                for x in exps),
            'import_libs': ';'.join(
                '%s v%s(%d)' % (x['name'], x['ver_str'], len(x['entries']))
                for x in imps),
            'func_est': cen.get('func_est', 0),
            'classification': cen.get('classification', ''),
            'lane_flags': ';'.join(flag),
            'notable_strings': ' | '.join(cen.get('notable', [])[:8]),
            'notes': '',
        }
        irx_rows.append(row)
        print('  %-14s %7dB  mi="%s" v%s tag=%s  exp=%d imp=%d f~%-4d %s%s'
              % (base, len(buf), mi.get('name', ''), mi.get('ver_str', ''),
                 '0x%04X' % mi['tag'] if mi else '-', len(exps), len(imps),
                 cen.get('func_est', 0), cen.get('classification', '?'),
                 '  FLAGS:' + ','.join(flag) if flag else ''))
        if args.verbose:
            for x in exps:
                print('      export %-10s v%-5s %d entries' %
                      (x['name'], x['ver_str'], len(x['entries'])))
            for x in imps:
                print('      import %-10s v%-5s %d stubs' %
                      (x['name'], x['ver_str'], len(x['entries'])))

    if args.csv_romdir and romdir_rows:
        with open(args.csv_romdir, 'w', newline='') as f:
            w = csv.DictWriter(f, fieldnames=list(romdir_rows[0].keys()))
            w.writeheader()
            w.writerows(romdir_rows)
        print('wrote %s (%d rows)' % (args.csv_romdir, len(romdir_rows)))
    if args.csv_irx and irx_rows:
        with open(args.csv_irx, 'w', newline='') as f:
            w = csv.DictWriter(f, fieldnames=list(irx_rows[0].keys()))
            w.writeheader()
            w.writerows(irx_rows)
        print('wrote %s (%d rows)' % (args.csv_irx, len(irx_rows)))
    return 0


if __name__ == '__main__':
    sys.exit(main())
