#!/usr/bin/env python3
# ============================================================================
# diff_saves.py — FFX HD save structural RE (lane FFX-STRUCTURES / SAVE-STRUCT-RE)
# PURPOSE : byte-diff pairs of real FFX saves and classify changed bytes by the
#           G-module map (atlas §11.17/§11.32/§11.37, Fahrenheit offsets).
# WHY     : RE-09/RE-29 need field deltas from real gameplay progression; the
#           atlas G-offsets were derived from Fahrenheit structs and never
#           validated against real save diffs (payload@0 layout proven by the
#           2026-09-14 hunt: file offset = fahrenheit + 0x40).
# OUTPUT  : work/_saves_re/diffs/<pair>.json + decode_probe.json + summary tables.
# MAINT   : read-only over corpora; no game/editor files touched.
# ============================================================================
import json, os, hashlib, struct, sys

REPO = "/home/wanderson/Documents/ffx-editor-main"
HUNT = os.path.join(REPO, "work/_saves_hunt/corpus")
TAS = os.path.join(REPO, "Utilities/FFX_TAS_Python/tas_saves")
OUT = os.path.join(REPO, "work/_saves_re/diffs")
os.makedirs(OUT, exist_ok=True)

PAYLOAD_END = 0x64F8  # 25848 payload (file bytes 0..0x64F7 for PC 26880 saves)

# ── Module map: (key, label, file_start, file_end) — file = fahrenheit + 0x40 ──
# Sources: FFX_STRUCTURE_COMPLETE_2026-09-14.md §11.17 sec.4 table (Fahrenheit col).
MODULES = [
    ("HDR",  "Header interno (slot/flags/CRC/assinatura)", 0x0000, 0x0040),  # Fh payload header
    ("G1",   "Early Game State (room/spawn/time/affection)", 0x0040, 0x02B9),  # Fh 0x000-0x278
    ("G2",   "Progression Flags (+lightning)", 0x02B9, 0x0441),  # Fh 0x279-0x400
    ("GAP2", "gap G2->G3 (nao mapeado)", 0x0441, 0x062C),
    ("G3",   "Story/World State (story_progress/celestiais)", 0x062C, 0x0D18),  # Fh 0x5EC-0xCD7
    ("GAP3", "gap G3->G4 (bb player data ed 0x1492-0x1A7B vive aqui)", 0x0D18, 0x19C4),
    ("G4",   "BlitzballData (custos/premios/techs)", 0x19C4, 0x21CC),  # Fh 0x1984-0x218B
    ("GAP4", "gap G4->SG", 0x21CC, 0x21EC),
    ("SG",   "SphereGrid runtime (nos/links/cursor)", 0x21EC, 0x350C),  # Fh 0x21AC-0x34CB
    ("GAP5", "gap SG->G5", 0x350C, 0x3D4C),
    ("G5",   "Core Identity (config/gil/party/counters)", 0x3D4C, 0x3E0C),  # Fh 0x3D0C-0x3DCB
    ("G6",   "Event Flags", 0x3E0C, 0x3F0C),  # Fh 0x3DCC
    ("G11",  "Inventory (ids[256]u16+counts[256]u8)", 0x3F0C, 0x420C),  # Fh 0x3ECC
    ("G7",   "Items Acquired/Used", 0x420C, 0x424C),  # Fh 0x41CC
    ("G8",   "Monsters (capt/seen/defeated)", 0x424C, 0x44CC),  # Fh 0x420C
    ("G9",   "Key Items (128 bits)", 0x44CC, 0x44DC),  # Fh 0x448C
    ("EQP",  "Equipment (200x22B)", 0x44DC, 0x560C),  # Fh 0x449C
    ("G12",  "PlySave (18x148B)", 0x560C, 0x6074),  # Fh 0x55CC
    ("G10",  "Commands Used (18x22u16)", 0x6074, 0x638C),  # Fh 0x6034
    ("NAM",  "Character Names (18x20B)", 0x638C, 0x64F4),  # Fh 0x634C
    ("CRC",  "CRC trailer (u16@0x64F4)", 0x64F4, 0x64F6),
    ("PAD",  "padding final payload", 0x64F6, 0x64F8),
    ("TAIL", "PC tail (1032B, so' 26880)", 0x64F8, 0x6900),
]

# ── FFXED char table (FfxSaveStringCodec.cs): 48-57 digits, 58-79 punct, 80-141 A-z ──
def build_char_table():
    t = ['?'] * 256
    for i in range(48, 58): t[i] = chr(48 + i - 48)
    punct = " !\"#$%&'()*+,-./:;<=>?"
    for k, c in enumerate(punct): t[58 + k] = c
    for i in range(80, 142): t[i] = chr(ord('A') + i - 80)
    return t
CHT = build_char_table()

def decode_name(buf, off):
    out = []
    for i in range(20):
        b = buf[off + i]
        if b == 0: break
        out.append(CHT[b] if b < 256 else '?')
    return ''.join(out)

def sha16(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f: h.update(f.read())
    return h.hexdigest()[:16]

def u8(b, o):  return b[o]
def u16(b, o): return struct.unpack_from('<H', b, o)[0]
def u32(b, o): return struct.unpack_from('<I', b, o)[0]

# ── Semantic probe: decode atlas-known fields to validate offsets against reality ──
def probe(buf):
    p = {}
    p['slot_u32@0'] = u32(buf, 0x00)
    p['crc_hdr@0x1A'] = hex(u16(buf, 0x1A))
    p['crc_trailer@0x64F4'] = hex(u16(buf, 0x64F4))
    p['cur_room@0x40(Fh0)'] = u16(buf, 0x40)
    p['last_room@0x42(Fh2)'] = u16(buf, 0x42)
    p['spawn@0x4C(FhC)'] = u8(buf, 0x4C)
    p['saved_spawn@0xF8(FhB8)'] = u8(buf, 0xF8)
    p['saved_room@0xFA(FhBA)'] = u16(buf, 0xFA)
    p['game_time_s@0xFC(FhBC)'] = u32(buf, 0xFC)
    p['affection0_7@0x6C(Fh2C)'] = [u32(buf, 0x6C + 4*i) for i in range(8)]
    p['story_prog@0xC2C(FhBEC)'] = u16(buf, 0xC2C)
    p['battle_count@0x3D54(Fh3D14)'] = u32(buf, 0x3D54)
    p['gil@0x3D88(Fh3D48)'] = u32(buf, 0x3D88)
    p['party_front@0x3D98(Fh3D58)'] = [u8(buf, 0x3D98 + i) for i in range(3)]
    inv_ids = [u16(buf, 0x3F0C + 2*i) for i in range(256)]
    inv_cnt = [u8(buf, 0x40CC + i) for i in range(256)]
    nz = [(i, inv_ids[i], inv_cnt[i]) for i in range(256) if inv_ids[i] != 0 or inv_cnt[i] != 0]
    p['inv_nonzero(first12)@0x3F0C'] = nz[:12]
    p['inv_nonzero_count'] = len(nz)
    p['mon_capt_sum@0x424C'] = sum(buf[0x424C + i] for i in range(512))
    p['mon_seen_bits@0x444C'] = sum(bin(u16(buf, 0x444C + 2*i)).count('1') for i in range(32))
    p['mon_defe_bits@0x448C'] = sum(bin(u16(buf, 0x448C + 2*i)).count('1') for i in range(32))
    p['key_items_bits@0x44CC'] = sum(bin(u16(buf, 0x44CC + 2*i)).count('1') for i in range(8))
    p['names@0x638C'] = [decode_name(buf, 0x638C + 20*i) for i in range(18)]
    return p

def diff_pair(path_a, path_b, label):
    with open(path_a, 'rb') as f: a = f.read()
    with open(path_b, 'rb') as f: b = f.read()
    n = min(len(a), len(b))
    raw_diffs = [o for o in range(n) if a[o] != b[o]]
    # classify by module
    per_mod = {}
    for key, _, s, e in MODULES:
        ds = [o for o in raw_diffs if s <= o < e]
        if ds: per_mod[key] = ds
    # contiguous runs (merge gaps <= 3 bytes for readability)
    def _runs(ds):
        rs = []
        for o in ds:
            if rs and o - rs[-1][1] <= 3: rs[-1][1] = o
            else: rs.append([o, o])
        return [{'s': hex(s), 'e': hex(e), 'len': e - s + 1} for s, e in rs]
    mod_summary = {k: len(v) for k, v in per_mod.items()}
    res = {
        'pair': label,
        'a': {'path': path_a, 'size': len(a), 'sha16': hashlib.sha256(a).hexdigest()[:16]},
        'b': {'path': path_b, 'size': len(b), 'sha16': hashlib.sha256(b).hexdigest()[:16]},
        'bytes_compared': n,
        'total_diff_bytes': len(raw_diffs),
        'diff_bytes_by_module': mod_summary,
        'diff_runs': _runs(raw_diffs),
        'diff_runs_by_module': {k: _runs(v) for k, v in per_mod.items()},
    }
    return res, a, b

def main():
    which = sys.argv[1] if len(sys.argv) > 1 else 'all'

    if which in ('all', 'user'):
        # (a) user progression 000 vs 011
        res, a, b = diff_pair(os.path.join(HUNT, 'user_ffx_000'),
                              os.path.join(HUNT, 'user_ffx_011'), 'user_000_vs_011')
        with open(os.path.join(OUT, 'user_000_vs_011.json'), 'w') as f:
            json.dump(res, f, indent=1)
        with open(os.path.join(REPO, 'work/_saves_re/probe_user000.json'), 'w') as f:
            json.dump(probe(a), f, indent=1, ensure_ascii=False)
        with open(os.path.join(REPO, 'work/_saves_re/probe_user011.json'), 'w') as f:
            json.dump(probe(b), f, indent=1, ensure_ascii=False)
        print('user_000_vs_011:', res['total_diff_bytes'], 'diff bytes;',
              json.dumps(res['diff_bytes_by_module']))

    if which in ('all', 'tas'):
        # (b) TAS chain: all adjacent pairs in numeric order
        import re
        files = sorted(os.listdir(TAS), key=lambda x: int(re.search(r'\d+', x).group()))
        pairs = list(zip(files[:-1], files[1:]))
        results = []
        agg = {}
        for fa, fb in pairs:
            label = f'tas_{fa}_vs_{fb}'
            res, a, b = diff_pair(os.path.join(TAS, fa), os.path.join(TAS, fb), label)
            results.append(res)
            for k, v in res['diff_bytes_by_module'].items():
                agg.setdefault(k, {'pairs': 0, 'bytes': 0})
                agg[k]['pairs'] += 1
                agg[k]['bytes'] += v
        with open(os.path.join(OUT, 'tas_chain.json'), 'w') as f:
            json.dump({'pairs': results, 'aggregate': agg,
                       'n_pairs': len(pairs)}, f, indent=1)
        # probes: first, mid, last
        for tag, fn in (('first', files[0]), ('mid', files[len(files)//2]), ('last', files[-1])):
            with open(os.path.join(TAS, fn), 'rb') as f:
                with open(os.path.join(REPO, f'work/_saves_re/probe_tas_{tag}_{fn}.json'), 'w') as g:
                    json.dump(probe(f.read()), g, indent=1, ensure_ascii=False)
        print(f'tas chain: {len(pairs)} pairs')
        for k in sorted(agg, key=lambda x: -agg[x]['bytes']):
            print(f'  {k:5s} pairs_touched={agg[k]["pairs"]:3d} total_diff_bytes={agg[k]["bytes"]}')

    if which in ('all', 'conv'):
        # (c) converter Steam (26880, payload@0 + tail) vs PS2 (25848, payload only)
        res, a, b = diff_pair(os.path.join(HUNT, 'converter_steam'),
                              os.path.join(HUNT, 'converter_ps2'), 'conv_steam_vs_ps2')
        with open(os.path.join(OUT, 'conv_steam_vs_ps2.json'), 'w') as f:
            json.dump(res, f, indent=1)
        with open(os.path.join(REPO, 'work/_saves_re/probe_conv_steam.json'), 'w') as f:
            json.dump(probe(a), f, indent=1, ensure_ascii=False)
        with open(os.path.join(REPO, 'work/_saves_re/probe_conv_ps2.json'), 'w') as f:
            json.dump(probe(b), f, indent=1, ensure_ascii=False)
        print('conv_steam_vs_ps2:', res['total_diff_bytes'], 'diff bytes;',
              json.dumps(res['diff_bytes_by_module']))

if __name__ == '__main__':
    main()
