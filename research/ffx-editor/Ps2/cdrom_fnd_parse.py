#!/usr/bin/env python3
"""cdrom_fnd_parse.py — decoder/cross-mapper for the FFX PS2 cdrom.* index set.

Mission (Jarvis-CDFND, wave-17 lane 2026-09-18): close the `.clp`<->`.fmt`
filename<->file-id gap left OPEN by the SLPS-MIPS wave
(`docs/reverse/FFX_SLPS_MIPS_2026-09-18.md` §1f/§7h). The runtime binds
resources by `(grp, slot) -> index = fid[grp] + slot -> mdg[index] -> LBA`
with ZERO filename strings; the dev-side name directory `cdrom.fnd` maps
index -> dev path. This tool decodes every table in the set and emits the
full dir map.

SOURCE FILES (dev master tree, found in the FFX/X-2 HD PSARC at
  ExtrasExtras/FFXX2HDREMASTER/PSARC_EXTRACTED/FFX/ffx_ps2/ffx/proj/):
  battle/jp/cddata/cdrom.id   80 B   self-describing disc header
                                     {u32 x8?, "FINAL_FANTASY_X"}; fields
                                     embed id/fat/fid sector+size (see .def)
  battle/jp/cddata/cdrom.fid  130 B  65 x s16 group base indices (-1 empty)
  battle/jp/cddata/cdrom.fnd  811 KB {u32 count; u32 off[count]; strs}
                                     index -> "host0:/ffx/..." dev path
  battle/jp/cddata/cdrom.mdg  128 KB 32768 x u32 extent records
                                     {trailer8:8, flags:2, lba:22}
                                     size = (lba[i+1]-lba[i])*2048 - top8*8
  battle/jp/cddata/cdrom.mde  128 KB same layout, alternate mastering FAT:
                                     identical top8/flags; LBA = mdg LBA +
                                     1 sector per fid group base (cumulative
                                     +1..+39). Every group start sits on a
                                     fresh sector (1 reserved/group).
                                     NOT on retail disc (.sc masters mdg).
  battle/jp/cddata/cdrom.def  C hdr  _cdindex_* group ids, _menu_* slot ids,
                                     fixed-sector constants
  battle/jp/cddata/cdrom.sc   mastering script (DiscName SLPM-67513)
  battle/jp/cddata/cdrom_cd.fnd / cdrom_lc.fnd — variant name tables
  prog/cdidx/<region>/cdrom.{fid,id,mdg} — per-region fid/id/mdg sets

ON-DISC COPIES (FFX International SLPS_250.88 ISO — verified present):
  LBA 279  cdrom.id  (48 B used; byte-identical to cddata copy)
  LBA 280  cdrom.mdg FAT (64 sectors; LBAs differ from SLPM master)
  LBA 344  cdrom.fid (130 B; byte-identical to cddata copy)
  (cdrom.fnd is NOT on disc — dev-only, loaded via host:/host0: paths;
   gated by the host-mode check at SLPS 0x2D93F8, loader 0x1AD0E8.)

RUNTIME MODEL (proven in SLPS_250.88, this lane + wave-15):
  index = fid[grp] + slot            (SLPS 0x163168: lh fid[grp], + slot)
  lba   = base + (mdg[index]&0x3FFFFF)  (SLPS 0x163138; base=*(0x30DAAC))
  size  = (lba[i+1]-lba[i])*2048 - (mdg[i]>>24)*8   (SLPS 0x163090 shape)
  bit31 of the mdg dword -> size getter returns 0 early (SLPS 0x1630B4);
  empirically those entries still carry real extents (base.ftc etc.),
  and the same trailer formula yields exact file sizes.

USAGE
  cdrom_fnd_parse.py --info
  cdrom_fnd_parse.py --fid
  cdrom_fnd_parse.py --resolve 0x12 0x13        # grp,slot -> path/lba/size
  cdrom_fnd_parse.py --group 0x12
  cdrom_fnd_parse.py --csv out.csv              # full dir table
  cdrom_fnd_parse.py --verify [--limit N]       # compare ISO extent vs master
  cdrom_fnd_parse.py --sc                       # dump mastering-script list
  cdrom_fnd_parse.py --mde                      # mdg<->mde delta runs vs fid
  cdrom_fnd_parse.py --fnd-variant fnd|cd|lc

Defaults point at the canonical corpus paths; override with --cddata,
--iso, --master. stdlib only. Exit 0 ok, 2 usage, 4 missing input.
"""

import argparse
import csv
import os
import re
import struct
import sys

CDDATA = ('/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/'
          'FFXX2HDREMASTER/PSARC_EXTRACTED/FFX/ffx_ps2/ffx/proj/'
          'battle/jp/cddata')
ISO = ('/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/'
       'Final Fantasy X International (Japan) (En,Ja).iso')
MASTER = ('/mnt/ssd-kingston/ffx-reconstructed/ExtrasExtras/'
          'FFXX2HDREMASTER/PSARC_EXTRACTED/FFX/ffx_ps2/ffx/master')

# on-disc fixed sectors (cdrom.def: _cd_id_sector/_cd_fat_sector/_cd_fid_sector)
DISC_ID_LBA, DISC_FAT_LBA, DISC_FID_LBA = 279, 280, 344
DISC_FAT_SECTORS = 64

# _cdindex_* group ids -> names (cdrom.def "Module Header").
# Group 0 has no _cdindex_ macro — it is the implicit system/boot group
# (ISO-visible files + sizetbl/modulesize + country_txt).
GROUP_NAMES = {
    0: 'system', 1: 'ROOT', 2: 'akaza', 3: 'mon_gra_inter_us', 4: 'menu_inter_us',
    5: 'yonishi', 6: 'katano', 7: 'battle_us', 8: 'sugimoto',
    9: 'menu_text_us', 10: 'eiichi', 11: 'battle_scene_us', 12: 'event',
    13: 'battle', 14: 'battle_scene', 15: 'battle_player',
    16: 'battle_monster', 17: 'effect', 18: 'menu', 19: 'map', 20: 'chr',
    21: 'movie', 22: 'sound', 23: 'battle_sound', 24: 'event_base',
    25: 'event_voice', 26: 'battle_map', 27: 'battle_voice', 28: 'chr_pc',
    29: 'chr_mon', 30: 'chr_npc', 31: 'chr_sum', 32: 'chr_wep',
    33: 'chr_obj', 34: 'chr_skl', 35: 'effect_camera', 36: 'effect_read',
    37: 'menu2', 38: 'music', 39: 'menu_text', 40: 'battle_weapon',
    41: 'battle_extdata', 42: 'menu2save', 43: 'battle_weapon_summon',
    44: 'soundwave', 45: 'soundmusic', 46: 'event_bmotion', 47: 'shop',
    48: 'mon_gra', 49: 'movie2', 50: 'dvd_last',
}

LBA_MASK = 0x3FFFFF          # SLPS 0x163138: mdg[i] & (lui 0x3f | 0xffff)
FLAG_BIT23 = 0x00800000      # observed on repeated-LBA alias entries
FLAG_BIT31 = 0x80000000      # size getter early-outs (SLPS 0x1630B4)


def _read(p):
    with open(p, 'rb') as f:
        return f.read()


def parse_fnd(path):
    """cdrom.fnd -> (count, [offset...], [path...]). Layout:
    {u32 count; u32 off[count]; char blob[]}. Strings are NUL-terminated
    absolute offsets into the file. Empty slots share the next offset."""
    d = _read(path)
    count = struct.unpack('<I', d[:4])[0]
    offs = struct.unpack(f'<{count}I', d[4:4 + count * 4])
    tbl_end = 4 + count * 4
    paths = []
    for o in offs:
        if o < tbl_end or o >= len(d):
            paths.append(None)
            continue
        e = d.index(b'\0', o)
        paths.append(d[o:e].decode('ascii', 'replace'))
    return count, offs, paths


def parse_fid(path):
    """cdrom.fid -> [s16...] group base indices; -1 = group not on this disc."""
    d = _read(path)
    return list(struct.unpack(f'<{len(d) // 2}h', d))


def parse_mdg_bytes(d):
    return list(struct.unpack(f'<{len(d) // 4}I', d))


def parse_id(path_or_bytes):
    d = path_or_bytes if isinstance(path_or_bytes, (bytes, bytearray)) \
        else _read(path_or_bytes)
    words = struct.unpack(f'<{len(d) // 4}I', d[:len(d) // 4 * 4])
    name = d[0x40:].split(b'\0')[0].decode('ascii', 'replace') \
        if len(d) > 0x40 else ''
    return words, name


def parse_def(path):
    """cdrom.def -> {macro: int}; pulls _cdindex_*, _menu_* and _cd_*_sector."""
    txt = _read(path).decode('ascii', 'replace')
    out = {}
    for m in re.finditer(r'#define\s+(\w+)\s+(-?0x[0-9a-fA-F]+|-?\d+)', txt):
        try:
            out[m.group(1)] = int(m.group(2), 0)
        except ValueError:
            pass
    return out


def parse_sc(path):
    """cdrom.sc -> ordered [(kind, arg1, arg2)] for File/Layout lines."""
    rows = []
    for ln in _read(path).decode('ascii', 'replace').splitlines():
        m = re.match(r'\s*(File|Layout)\s+(?:"([^"]+)"|(\S+))?(?:\s+"([^"]+)")?',
                     ln)
        if m:
            rows.append((m.group(1), m.group(2) or m.group(3), m.group(4)))
    return rows


def mdg_lba(e):
    return e & LBA_MASK


def mdg_size(entries, i):
    """size = (lba[i+1]-lba[i])*2048 - top8*8  (SLPS 0x163090 shape).
    Returns 0 when the dword's bit31 is set (the getter's early-out) or
    when i is the last entry."""
    if i + 1 >= len(entries) or (entries[i] & FLAG_BIT31):
        return 0
    return (mdg_lba(entries[i + 1]) - mdg_lba(entries[i])) * 2048 \
        - (entries[i] >> 24) * 8


def load_disc_tables(iso_path):
    """Read the on-disc cdrom.{id,mdg,fid} copies at the fixed sectors."""
    with open(iso_path, 'rb') as f:
        f.seek(DISC_ID_LBA * 2048)
        did = f.read(2048)
        f.seek(DISC_FAT_LBA * 2048)
        mdg = f.read(DISC_FAT_SECTORS * 2048)
        f.seek(DISC_FID_LBA * 2048)
        fid = f.read(2048)[:130]
    return did, mdg, fid


def iso_extent(iso_path, lba, size):
    with open(iso_path, 'rb') as f:
        f.seek(lba * 2048)
        return f.read(size)


def group_of_index(fidv, idx):
    """Find (grp, slot) such that fid[grp] <= idx < next nonempty base."""
    best, base = -1, -1
    for g, b in enumerate(fidv):
        if 0 <= b <= idx and b > base:
            best, base = g, b
    return (best, idx - base) if best >= 0 else (-1, -1)


def cmd_info(a):
    did, mdg_d, fid_d = load_disc_tables(a.iso)
    cdd_id = _read(os.path.join(a.cddata, 'cdrom.id'))
    cdd_fid = _read(os.path.join(a.cddata, 'cdrom.fid'))
    cdd_mdg = _read(os.path.join(a.cddata, 'cdrom.mdg'))
    words, name = parse_id(did[:80])
    print(f'iso            : {a.iso}')
    print(f'cddata         : {a.cddata}')
    print(f'cdrom.id disc  : {words[:12]} name={name!r}')
    print(f'cdrom.id cddata: {parse_id(cdd_id)[0][:12]} name={parse_id(cdd_id)[1]!r}')
    print(f'id  on-disc == cddata : {did[:80] == cdd_id}')
    print(f'fid on-disc == cddata : {fid_d == cdd_fid}')
    e1, e2 = parse_mdg_bytes(mdg_d), parse_mdg_bytes(cdd_mdg)
    diffs = sum(1 for x, y in zip(e1, e2) if x != y)
    print(f'mdg entries={len(e1)}  on-disc vs cddata differing: {diffs}')
    d = parse_def(os.path.join(a.cddata, 'cdrom.def'))
    for k in ['_cd_id_sector', '_cd_id_size', '_cd_fat_sector',
              '_cd_fat_size', '_cd_fid_sector', '_cd_fid_size',
              '_cd_fat_data_size']:
        print(f'  def {k} = {d.get(k)}')


def cmd_fid(a):
    fidv = parse_fid(os.path.join(a.cddata, 'cdrom.fid'))
    for g, b in enumerate(fidv):
        nm = GROUP_NAMES.get(g, '?')
        print(f'group {g:2d} {nm:24s} base={b}')


def resolve(a, grp, slot):
    fidv = parse_fid(os.path.join(a.cddata, 'cdrom.fid'))
    _, mdg_d, _ = load_disc_tables(a.iso)
    E = parse_mdg_bytes(mdg_d)
    fn = {'fnd': 'cdrom.fnd', 'cd': 'cdrom_cd.fnd',
          'lc': 'cdrom_lc.fnd'}[a.fnd_variant]
    _, _, paths = parse_fnd(os.path.join(a.cddata, fn))
    if not (0 <= grp < len(fidv)):
        return None
    base = fidv[grp]
    if base < 0:
        return None
    idx = base + slot
    path = paths[idx] if idx < len(paths) else None
    e = E[idx] if idx < len(E) else 0
    return dict(grp=grp, slot=slot, index=idx,
                group_name=GROUP_NAMES.get(grp, '?'), path=path,
                lba=mdg_lba(e), size=mdg_size(E, idx),
                top8=e >> 24, flags=(e >> 22) & 3, bit31=bool(e & FLAG_BIT31))


def cmd_resolve(a):
    grp = int(a.resolve[0], 0)
    slot = int(a.resolve[1], 0)
    r = resolve(a, grp, slot)
    if r is None:
        print('not resolvable (empty group or out of range)')
        return
    print(r)


def cmd_group(a):
    fidv = parse_fid(os.path.join(a.cddata, 'cdrom.fid'))
    g = int(a.group, 0)
    base = fidv[g]
    nxt = min((b for b in fidv if b > base), default=-1)
    for s_ in range((nxt - base) if nxt > base else 64):
        r = resolve(a, g, s_)
        if r:
            print(f"g{g} s{s_:3d} idx={r['index']:6d} lba={r['lba']:8d} "
                  f"sz={r['size']:8d} f={r['flags']} b31={int(r['bit31'])} "
                  f"{r['path']}")


def cmd_csv(a):
    fidv = parse_fid(os.path.join(a.cddata, 'cdrom.fid'))
    _, mdg_d, _ = load_disc_tables(a.iso)
    E = parse_mdg_bytes(mdg_d)
    fn = {'fnd': 'cdrom.fnd', 'cd': 'cdrom_cd.fnd',
          'lc': 'cdrom_lc.fnd'}[a.fnd_variant]
    cnt, offs, paths = parse_fnd(os.path.join(a.cddata, fn))
    with open(a.csv, 'w', newline='') as f:
        w = csv.writer(f)
        w.writerow(['index', 'group', 'group_name', 'slot', 'lba',
                    'size_bytes', 'top8', 'flags_22_23', 'bit31',
                    'master_exists', 'master_size_eq', 'path'])
        for i in range(cnt):
            g, s_ = group_of_index(fidv, i)
            e = E[i] if i < len(E) else 0
            p = paths[i] or ''
            rel = p.replace('host0:/ffx/master/', '')
            mf = os.path.join(a.master, rel) if p.startswith('host0:/ffx/master/') else ''
            mex = os.path.exists(mf) if mf else False
            sz = mdg_size(E, i)
            meq = ''
            if mex:
                meq = str(os.path.getsize(mf) == sz)
            w.writerow([i, g, GROUP_NAMES.get(g, '?'), s_, mdg_lba(e),
                        sz, e >> 24, (e >> 22) & 3,
                        int(bool(e & FLAG_BIT31)), mex, meq, p])
    print(f'wrote {a.csv}: {cnt} rows')


def cmd_verify(a):
    fidv = parse_fid(os.path.join(a.cddata, 'cdrom.fid'))
    _, mdg_d, _ = load_disc_tables(a.iso)
    E = parse_mdg_bytes(mdg_d)
    fn = {'fnd': 'cdrom.fnd', 'cd': 'cdrom_cd.fnd',
          'lc': 'cdrom_lc.fnd'}[a.fnd_variant]
    cnt, _, paths = parse_fnd(os.path.join(a.cddata, fn))
    ok = bad = miss = nosize = 0
    badrows = []
    rng = range(cnt) if a.limit is None else range(min(a.limit, cnt))
    for i in rng:
        p = paths[i]
        if not p or not p.startswith('host0:/ffx/master/'):
            continue
        mf = os.path.join(a.master, p.replace('host0:/ffx/master/', ''))
        if not os.path.exists(mf):
            miss += 1
            continue
        sz = mdg_size(E, i)
        if sz <= 0:
            nosize += 1
            continue
        d = iso_extent(a.iso, mdg_lba(E[i]), sz)
        m = _read(mf)
        if d == m:
            ok += 1
        else:
            bad += 1
            badrows.append((i, p, sz, len(m)))
    print(f'verify: byte-identical={ok} mismatch={bad} '
          f'master-missing={miss} no-extent={nosize}')
    for r in badrows[:20]:
        print('  MISMATCH idx=%d %s iso=%dB master=%dB'
              % (r[0], r[1], r[2], r[3]))


def cmd_sc(a):
    rows = parse_sc(os.path.join(a.cddata, 'cdrom.sc'))
    for i, r in enumerate(rows):
        print(f'{i:5d} {r[0]:7s} {r[1] or "":24s} {r[2] or ""}')


def cmd_mde(a):
    """Diff cdrom.mde vs cdrom.mdg (wave-18). Every differing record differs
    only in the low-22 LBA field; the delta rises by exactly +1 at each
    populated fid group base (cumulative +1..+39) -> the mde layout inserts
    one reserved sector per module group."""
    E1 = parse_mdg_bytes(_read(os.path.join(a.cddata, 'cdrom.mdg')))
    E2 = parse_mdg_bytes(_read(os.path.join(a.cddata, 'cdrom.mde')))
    fidv = parse_fid(os.path.join(a.cddata, 'cdrom.fid'))
    bases = {b: g for g, b in enumerate(fidv) if b >= 0}
    non_lba = sum(1 for x, y in zip(E1, E2)
                  if x != y and (x & ~LBA_MASK) != (y & ~LBA_MASK))
    runs = []
    cur, start = None, 0
    for i in range(len(E1)):
        dl = mdg_lba(E2[i]) - mdg_lba(E1[i])
        if dl != cur:
            if cur is not None:
                runs.append((start, i - 1, cur))
            cur, start = dl, i
    runs.append((start, len(E1) - 1, cur))
    print(f'entries={len(E1)} non-LBA-field diffs={non_lba} '
          f'delta-runs={len(runs)}')
    for s, e, dl in runs:
        mark = f'  fid[{bases[s]}]={s} ' \
               f'({GROUP_NAMES.get(bases[s], "?")})' if s in bases else ''
        print(f'idx {s:5d}-{e:5d}  delta +{dl:2d}{mark}')


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument('--cddata', default=CDDATA)
    ap.add_argument('--iso', default=ISO)
    ap.add_argument('--master', default=MASTER)
    ap.add_argument('--fnd-variant', default='fnd',
                    choices=['fnd', 'cd', 'lc'])
    ap.add_argument('--info', action='store_true')
    ap.add_argument('--fid', action='store_true')
    ap.add_argument('--resolve', nargs=2, metavar=('GRP', 'SLOT'))
    ap.add_argument('--group', metavar='GRP')
    ap.add_argument('--csv', metavar='OUT')
    ap.add_argument('--verify', action='store_true')
    ap.add_argument('--limit', type=int, default=None)
    ap.add_argument('--sc', action='store_true')
    ap.add_argument('--mde', action='store_true')
    a = ap.parse_args()
    if not os.path.isdir(a.cddata):
        sys.exit(f'missing cddata dir {a.cddata}')
    did = None
    if a.info:
        cmd_info(a); did = 1
    if a.fid:
        cmd_fid(a); did = 1
    if a.resolve:
        cmd_resolve(a); did = 1
    if a.group is not None:
        cmd_group(a); did = 1
    if a.csv:
        cmd_csv(a); did = 1
    if a.verify:
        cmd_verify(a); did = 1
    if a.sc:
        cmd_sc(a); did = 1
    if a.mde:
        cmd_mde(a); did = 1
    if did is None:
        ap.print_help()
        return 2
    return 0


if __name__ == '__main__':
    sys.exit(main())
