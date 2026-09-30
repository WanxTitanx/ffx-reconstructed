#!/usr/bin/env python3
# ffx2_savemap.py — FFX-2 ply_save / SaveData field-map extractor + corpus differ
#
# Lane: FFX2-FIELDS (wave-13 resume, 2026-09-17)
#
# WHAT: decodes the FFX-2 save payload (`Fahrenheit.FFX2.SaveData`, 0x16660 B at
# file+0x40) field-by-field, runs it over the save corpus, and emits per-field
# observed-value statistics + a byte-level diff map so the field map in
# docs/reverse/FFX2_SAVE_FIELDMAP_2026-09-17.md is evidence-backed.
#
# FIELD TABLE SOURCE (provenance — do not invent offsets):
#   * Utilities/fahrenheit/src/core/ffx2/savedata.cs  (0x16660 explicit struct)
#   * Utilities/fahrenheit/src/core/ffx2/plysave.cs   (0x80 PlySave record)
#   * Utilities/fahrenheit/src/core/ffx2/friendmon.cs (0xE38 FriendMonster)
#   * Utilities/fahrenheit/src/core/ffx2/savedata.cs::CupData
#   * docs/reverse/FFX_FMT_FFX2_SAVE_2026-09-17.md    (wrap sizes, header fields)
#   * docs/reverse/FFX_FMT_FFX2_CHECKSUM_2026-09-17.md (CRC-16 + copy offsets)
# Field offsets below are 1:1 transcriptions of the Fahrenheit [FieldOffset]
# attributes (LGPL-3.0). Semantics marked Fh="..." come from Fahrenheit comments;
# ".h" marks fields also present in the shipped jppc party.h/ply_save.h.
#
# WRAPS (file size → layout):
#   91808 (0x166A0)  PC ffx2_NNN / PS-Vita : full SaveData at 0x40
#   90736 (0x16270)  PS3-era .sav          : SAME SaveData layout, file truncated
#                    right after the CRC copy dword@0x16268 (+4 zero bytes).
#                    VERIFIED 2026-09-17: identical field decode on both wraps.
#   54312 / 54296    PS2-NA / E3-demo      : different (older) payload layout —
#                    header decode only, payload UNMAPPED here.
#
# USAGE:
#   ffx2_savemap.py dump    <save>                  # one save -> JSON decode
#   ffx2_savemap.py scan    <corpus.txt | files...> # per-field stats -> JSON
#   ffx2_savemap.py diff    <corpus.txt | files...> # region diff matrix -> JSON
#   ffx2_savemap.py verify  <save...>               # checksum + invariants
#   ffx2_savemap.py fields                          # field table -> CSV (stdout)
#
# corpus.txt format (produced by the wave-13 census): TSV
#   size <TAB> kind <TAB> sha1-12 <TAB> path

import json
import os
import struct
import sys
from collections import Counter

# ── CRC-16 (FFX1/FFX2 shared, incl. table[255]=0 quirk — FFX_FMT_FFX2_CHECKSUM) ──

def _crc_table():
    tbl = []
    for n in range(256):
        v = n << 8
        for _ in range(8):
            v = ((v << 1) ^ 0x1021) & 0xFFFF if (v & 0x8000) else (v << 1) & 0xFFFF
        tbl.append(v)
    tbl[255] = 0  # runtime-generated table only fills 0..254 — REQUIRED quirk
    return tbl

_CRC_TBL = _crc_table()

def crc16_ffx2(data):
    crc = 0xFFFF
    for b in data:
        crc = ((crc << 8) ^ _CRC_TBL[(b ^ (crc >> 8)) & 0xFF]) & 0xFFFF
    return crc ^ 0xFFFF

# ── US glyph table (FFX-2 charset — recovered wave-13, work/_ffx2fields) ──
# byte -> printable char. Built from the save/kernel US string blobs.

_US_GLYPH = {}
def _build_glyph():
    chars = (
        "0123456789 !”#$%&’()*+,-./:;<=>?"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_‘"
        "abcdefghijklmnopqrstuvwxyz{|}~·【】♪♥ "
        "“”— ¡↑↓←→¨«º »¿ÀÁÂÄçÈÉÊËÌÍÎÏÑÒÓÔÖÙÚÛÜß"
        "àáâäçèéêëìíîïñòóôöùúûü,ƒ„…'’•-~™ ›§©ª®±²³¼½¾×÷‹… ǎ★☆■∞"
    )
    for i, c in enumerate(chars):
        _US_GLYPH[0x30 + i] = c
_build_glyph()

def glyph_str(buf):
    """Decode a NUL-terminated FFX-2 US-charset string."""
    out = []
    for b in buf:
        if b == 0:
            break
        out.append(_US_GLYPH.get(b, f"<{b:02X}>"))
    return "".join(out)

# ── save file level ──

def wrap_kind(size):
    return {91808: "pc_vita", 90736: "ps3_era",
            54312: "ps2_na", 54296: "e3_demo"}.get(size, f"unknown_{size}")

# SaveData lives at file+0x40 for the 91808/90736 wraps.
SAVEDATA_OFF = 0x40

def load_save(path):
    raw = open(path, "rb").read()
    kind = wrap_kind(len(raw))
    sd = raw[SAVEDATA_OFF:] if kind in ("pc_vita", "ps3_era") else None
    return raw, kind, sd

def verify_checksum(raw, kind):
    """Returns dict(stored, calc, copy_val, match) or None for unmapped wraps."""
    if kind == "pc_vita":
        region_end, copy_off = 0x1626C, 0x16268
    elif kind == "ps3_era":
        region_end, copy_off = 0x16270, 0x16268
    elif kind == "ps2_na":
        region_end, copy_off = len(raw), len(raw) - 4
    else:
        return None
    buf = bytearray(raw[:region_end])
    struct.pack_into("<I", buf, copy_off, 0)
    calc = crc16_ffx2(buf[SAVEDATA_OFF:])
    stored = struct.unpack_from("<H", raw, 0x1A)[0]
    copy_val = struct.unpack_from("<I", raw, copy_off)[0]
    return {"stored": stored, "calc": calc, "copy_val": copy_val,
            "match": calc == stored, "copy_eq_stored": copy_val == stored}

def decode_header(raw):
    """File 0x00-0x40 header (FFX_FMT_FFX2_CHECKSUM §3)."""
    h = {}
    h["slot_u32_00"]      = struct.unpack_from("<I", raw, 0x00)[0]
    h["const_04"]         = struct.unpack_from("<I", raw, 0x04)[0]  # 0x02010001
    h["seed_08"]          = struct.unpack_from("<I", raw, 0x08)[0]
    h["seed_0C"]          = struct.unpack_from("<I", raw, 0x0C)[0]
    h["room_id_18"]       = struct.unpack_from("<H", raw, 0x18)[0]  # lo16 = map/room
    h["checksum_1A"]      = struct.unpack_from("<H", raw, 0x1A)[0]  # hi16 = CRC-16
    h["const_1C"]         = struct.unpack_from("<I", raw, 0x1C)[0]  # 0x100
    h["const_20"]         = struct.unpack_from("<I", raw, 0x20)[0]  # 1
    h["flag_28"]          = struct.unpack_from("<I", raw, 0x28)[0]  # 0x00XX0001
    return h

# ── field table ──
# (savedata_off, size_bytes, kind, name, provenance)
# kind: u8/u16/u32/i32 scalar | u8n/u16n/u32n arrays | bits16/bits32 bitfield |
#       bytes blob | sub (decoded by dedicated function)

FIELDS = [
    (0x0000, 2, "u16",  "current_room_id",            "Fh"),
    (0x0002, 2, "u16",  "last_room_id",               "Fh"),
    (0x0004, 2, "u16",  "now_eventjump_map_no",       "Fh"),
    (0x0006, 2, "u16",  "last_eventjump_map_no",      "Fh"),
    (0x0008, 2, "u16",  "now_eventjump_map_id",       "Fh"),
    (0x000A, 2, "u16",  "last_eventjump_map_id",      "Fh"),
    (0x000C, 1, "u8",   "current_spawnpoint",         "Fh"),
    (0x000D, 1, "u8",   "last_spawnpoint",            "Fh"),
    (0x000E, 2, "u16",  "atel_save_dic_index",        "Fh"),
    (0x0010, 1, "u8",   "atel_battle_scene_group",    "Fh"),
    (0x0011, 1, "u8",   "fade_mode",                  "Fh"),
    (0x0012, 1, "u8",   "fade_time",                  "Fh"),
    (0x0013, 1, "u8",   "battle_status",              "Fh bits:1=sys,2=dummy_enc"),
    (0x0018, 8, "bits", "flying_ship_pos",            "Fh: u32[2] bitfield"),
    (0x0020, 1, "u8",   "atel_is_push_member",        "Fh"),
    (0x0021, 3, "u8n",  "atel_push_frontline[3]",     "Fh"),
    (0x0024, 1, "u8",   "atel_push_party",            "Fh"),
    (0x0028, 1, "u8",   "is_cam_underwater",          "Fh"),
    (0x0029, 1, "u8",   "is_map_underwater",          "Fh"),
    (0x002B, 1, "u8",   "tk_event_new_game",          "Fh"),
    (0x002C, 32,"u32n", "affection[8]",               "Fh"),
    (0x004C, 80,"bits", "affection_room_flags[20]",   "Fh: u32[20], room_id<0x280"),
    (0x00B4, 2, "u16",  "item_map_x",                 "Fh"),
    (0x00B6, 2, "u16",  "item_map_y",                 "Fh"),
    (0x00BC, 4, "i32",  "time",                       "Fh"),
    (0x00D1, 1, "u8",   "albhed_rikku",               "Fh bool"),
    (0x00D2, 1, "u8",   "drop_shadow_mode",           "Fh"),
    (0x00D4, 2, "u16",  "atel_force_place_id_value",  "Fh"),
    (0x00D6, 1, "u8",   "atel_force_place_id",        "Fh bool"),
    (0x00D7, 1, "u8",   "atel_water_btl_effect",      "Fh"),
    (0x00D8, 4, "u32",  "on_memory_movie_file_no",    "Fh"),
    (0x00DC, 4, "u32",  "on_memory_movie_mode",       "Fh"),
    (0x00E0, 4, "u32",  "on_memory_movie",            "Fh"),
    (0x00E4, 4, "i32",  "rand_encounter_modifiers",   "Fh bits:8=no_fanfare,9=no_gameover,10=no_music"),
    (0x00E8, 2, "u16",  "btl_end_tag_always",         "Fh"),
    (0x00EA, 2, "u16",  "sphere_monitor",             "Fh"),
    (0x011C, 2, "u16",  "event_skip_room",            "Fh"),
    (0x011E, 2, "u16",  "event_skip_spawnpoint",      "Fh"),
    (0x0124, 2, "u16",  "event_skip_flag",            "Fh"),
    (0x0126, 2, "u16",  "event_skip_menu",            "Fh"),
    (0x0128, 4, "u32",  "light_id",                   "Fh"),
    (0x012C, 4, "u32",  "user_timer_upper",           "Fh: seconds"),
    (0x0130, 4, "u32",  "user_timer_lower",           "Fh: milliseconds"),
    (0x0134, 4, "u32",  "user_timer_status",          "Fh bits:1=up,2=down,3=stop?"),
    (0x0138, 4, "u32",  "voice_flag_count_all",       "Fh"),
    (0x013C, 4, "u32",  "voice_flag_crc",             "Fh"),
    (0x0140, 4, "u32",  "voice_flag_2",               "Fh: meaning unknown"),
    (0x0148, 4, "u32",  "save_clear_counter",         "Fh"),
    (0x01EC, 1, "u8",   "scenario_list",              "Fh: byte; region 0x1EC..0x44C unmapped"),
    (0x044D, 0x100,"sub","fiend_arena_cup_data",      "Fh CupData"),
    (0x0BEC, 2, "u16",  "story_progress",             "Fh"),
    (0x0D60, 4, "u32",  "experiment_attack_level",    "Fh"),
    (0x0D64, 4, "u32",  "experiment_defense_level",   "Fh"),
    (0x0D68, 4, "u32",  "experiment_special_level",   "Fh"),
    (0x10FC, 1, "u8",   "trap_pod_count",             "Fh"),
    (0x10FD, 8, "u8n",  "trap_pods[8]",               "Fh: S/M/L/SP per pod"),
    (0x1105, 8, "u8n",  "creature_tale_bonus[8]",     "Fh"),
    (0x110D, 8, "u8n",  "creature_tale_progression[8]","Fh"),
    (0x114C, 1, "u8",   "current_chapter",            "Fh"),
    (0x1188, 32,"u32n", "creature_ids[8]",            "Fh: captured creature ids"),
    (0x11B1, 1, "u8",   "recruited_creature_count",   "Fh"),
    (0x21EC, 0x4000,"bits","voice_flags[0x4000]",     "Fh: heard-voiceline bitfield"),
    (0x61F0, 4, "u32",  "result_card",                "Fh"),
    (0x6FD0, 4, "u32",  "walk_map",                   "Fh"),
    # ── btl_party block (party.h) ──
    (0x77D0, 4, "u32",  "config",                     "Fh/.h: bitfield (stereo,cursor,atb_wait,subtitle,...)"),
    (0x77D4, 4, "u32",  "unlocked_primers",           "Fh: bitfield primers 1..26"),
    (0x77D8, 4, "u32",  "gil",                        "Fh/.h"),
    (0x77DC, 4, "u32",  "play_time",                  "Fh/.h: 'always 0?' per Fh"),
    (0x77E0, 4, "u32",  "battle_time",                "Fh/.h: 'always 0?' per Fh"),
    (0x77E4, 4, "u32",  "battle_count",               "Fh/.h"),
    (0x77E8, 3, "u8n",  "party[3]",                   "Fh/.h: ply_save indices"),
    (0x77EB, 1, "u8",   "atb_speed",                  "Fh: 0 Slow 1 Normal 2 Fast"),
    (0x77EC, 16,"u16n", "item_type[8]",               "Fh/.h"),
    (0x77FC, 8, "u8n",  "item_num[8]",                "Fh/.h"),
    (0x7804, 8, "bits", "plate[2]",                   "Fh: i32[2] garment-grid bitfield"),
    (0x780C, 30,"u8n",  "dre_sphere[30]",             "Fh/.h: dresspheres owned"),
    (0x782C, 4, "i32",  "reserve5",                   "Fh/.h"),
    # ── end btl_party ──
    (0x7840, 0x80,"bits","event_flag[0x80]",          "Fh"),
    (0x7940, 0x88,"sub","inventory",                  "Fh: ids u16[0x44] + counts u8[0x44] @0x7B40"),
    (0x7C40, 0x20,"bits","inventory_check",           "Fh: bitfield, unknown size"),
    (0x7C60, 1, "u8",   "inventory_use",              "Fh: 'unused?'"),
    (0x7C80, 0x100,"sub","accessories",               "Fh: ids u16[0x80] + counts u8[0x80] @0x7D80"),
    (0x7E00, 1, "u8",   "accessory_check",            "Fh: 'unused?'"),
    (0x7E10, 1, "u8",   "accessory_use",              "Fh: 'unused?'"),
    (0x8020, 0x40,"bits","monster_meet[0x20]",        "Fh: u16[0x20] bitfield, monster<0x200"),
    (0x8060, 0x40,"bits","monster_defeat[0x20]",      "Fh"),
    (0x80A0, 0x40,"bits","monster_oversoul[0x20]",    "Fh"),
    (0x8120, 0x10,"bits","important_items[8]",        "Fh: u16[8] bitfield, key_item<0x80"),
    (0x81B0, 0xB80,"sub","ply_saves[23]",             "Fh/.h: 23 x 0x80 PlySave"),
    (0x8D30, 0x4A0,"bytes","ap_0x3 region",           "Fh: 2d [chr][ply_command 0x3XXX<0x250]"),
    (0x91D0, 0x1F44,"bytes","ap_0x8 region",          "Fh: 2d [chr][ability 0x8XXX<0x100]"),
    (0xB114, 4, "u32",  "save_crc (Fh)",              "Fh — NOT the file CRC (unused on PC, reads 0)"),
    (0xC8D0, 0x21C,"sub","learn[9][30]",              "Fh: LearnJobs u16[30] x 9 chars"),
    (0xCAEC, 0x398,"sub","character_names[23]",       "Fh: 23 x 40B Name"),
    (0xCE84, 0x398,"sub","character_names_default[23]","Fh: 'only used for captured monsters?'"),
    (0xD21C, 0x32C,"bytes","dress_up_count region",   "Fh: chr*0x5a + ?*0x1e + job usage counts"),
    (0xD548, 0x0E,"u8n","extend_party[0xE]",          "Fh"),
    (0xD570, 0x71C0,"sub","friend_monster[8]",        "Fh: 8 x 0xE38 FriendMonster"),
    (0x14730,0x1AF8,"bytes","dgn_save_data region",   "Fh: byte @0x14730 + tail to CRC copy"),
]

CRC_COPY_SD_OFF = 0x16228  # SaveData+0x16228 == file 0x16268 (91808/90736)

def file_off(sd_off):
    return sd_off + SAVEDATA_OFF

# ── sub-structure decoders ──

PLY_FIELDS = [  # within one 0x80 PlySave record (Fh plysave.cs / .h ply_save.h)
    (0x00, "name_ofs",  "H"), (0x02, "name_id",  "H"),
    (0x04, "bonus_hp",  "I"), (0x08, "bonus_mp",  "I"),
    (0x0C, "bonus_str", "B"), (0x0D, "bonus_def", "B"), (0x0E, "bonus_mag", "B"),
    (0x0F, "bonus_mdf", "B"), (0x10, "bonus_agi", "B"), (0x11, "bonus_lck", "B"),
    (0x12, "bonus_eva", "B"), (0x13, "bonus_acc", "B"),
    (0x14, "total_exp", "I"), (0x18, "exp",       "I"),
    (0x1C, "hp",        "I"), (0x20, "mp",        "I"),
    (0x24, "max_hp",    "I"), (0x28, "max_mp",    "I"),
    (0x2C, "ply_flags", "B"),
    (0x2D, "str", "B"), (0x2E, "def", "B"), (0x2F, "mag", "B"), (0x30, "mdf", "B"),
    (0x31, "agi", "B"), (0x32, "acc", "B"), (0x33, "eva", "B"), (0x34, "lck", "B"),
    (0x35, "level", "B"),
    (0x36, "job", "H"), (0x38, "plate", "H"),
    (0x3A, "accessory0", "H"), (0x3C, "accessory1", "H"),
    (0x3E, "abi_map", "H"),
    (0x40, "escape_count", "I"), (0x44, "enemies_defeated", "I"),
    (0x48, "deaths", "I"), (0x4C, "status", "I"),
    (0x50, "auto_ability0", "H"), (0x52, "auto_ability1", "H"), (0x54, "auto_ability2", "H"),
    (0x56, "before_job", "H"),
    (0x78, "creature", "H"), (0x7A, "size", "B"),
]

def decode_ply_saves(sd):
    base = 0x81B0
    out = []
    for i in range(0x17):
        rec = {"idx": i}
        off = base + i * 0x80
        for rel, name, fmt in PLY_FIELDS:
            rec[name] = struct.unpack_from("<" + fmt, sd, off + rel)[0]
        out.append(rec)
    return out

def decode_inventory(sd):
    ids, counts = [], []
    for i in range(0x44):
        iid = struct.unpack_from("<H", sd, 0x7940 + i * 2)[0]
        cnt = sd[0x7B40 + i]
        if iid or cnt:
            ids.append(iid); counts.append(cnt)
    return list(zip(ids, counts))

def decode_accessories(sd):
    out = []
    for i in range(0x80):
        aid = struct.unpack_from("<H", sd, 0x7C80 + i * 2)[0]
        cnt = sd[0x7D80 + i]
        if aid or cnt:
            out.append((aid, cnt))
    return out

def decode_names(sd, base):
    out = []
    for i in range(0x17):
        out.append(glyph_str(sd[base + i * 40: base + i * 40 + 40]))
    return out

def decode_learn(sd):
    out = []
    for c in range(9):
        jobs = struct.unpack_from("<30H", sd, 0xC8D0 + c * 60)
        out.append([j for j in jobs if j])
    return out

def decode_cup(sd):
    b = sd[0x44D:0x44D + 0x100]
    names = ["standard", "standard_hard", "grand", "grand_hard", "chocobo",
             "cactuar", "youth_league", "aeon", "fiend_world", "farplane"]
    d = {"entry_counts": {n: b[i] for i, n in enumerate(names)}}
    d["unlocked_cups_1"] = struct.unpack_from("<H", b, 0xEF)[0]
    d["skip_fiend_arena_intro"] = b[0xF2]
    d["unlocked_cups_2"] = struct.unpack_from("<H", b, 0xF5)[0]
    d["farplane_cup_unlocked"] = b[0xFC]
    return d

def decode_friend_monsters(sd):
    out = []
    for i in range(8):
        off = 0xD570 + i * 0xE38
        rec = sd[off:off + 0xE38]
        nz = sum(1 for b in rec if b)
        out.append({"idx": i, "nonzero_bytes": nz,
                    "commands_0x3": list(struct.unpack_from("<4H", rec, 0x0)),
                    "commands_0x8": list(struct.unpack_from("<4H", rec, 0x8))})
    return out

def _read(sd, off, size, kind):
    if off + size > len(sd):
        return None
    if kind == "u8":   return sd[off]
    if kind == "u16":  return struct.unpack_from("<H", sd, off)[0]
    if kind == "u32":  return struct.unpack_from("<I", sd, off)[0]
    if kind == "i32":  return struct.unpack_from("<i", sd, off)[0]
    if kind == "u8n":  return list(sd[off:off + size])
    if kind == "u16n": return list(struct.unpack_from(f"<{size//2}H", sd, off))
    if kind == "u32n": return list(struct.unpack_from(f"<{size//4}I", sd, off))
    if kind in ("bits", "bytes"):
        return sum(1 for b in sd[off:off + size] if b)  # nonzero-byte count
    return None

def dump_save(path):
    raw, kind, sd = load_save(path)
    d = {"path": path, "size": len(raw), "wrap": kind,
         "header": decode_header(raw),
         "checksum": verify_checksum(raw, kind)}
    if sd is None:
        d["payload"] = "UNMAPPED (PS2-era layout)"
        return d
    f = {}
    for off, size, knd, name, prov in FIELDS:
        if knd == "sub" or knd in ("bits", "bytes") and size > 0x40:
            continue  # handled below / too coarse as scalar
        f[name] = _read(sd, off, size, knd)
    d["fields"] = f
    d["ply_saves"] = decode_ply_saves(sd)
    d["inventory"] = decode_inventory(sd)
    d["accessories"] = decode_accessories(sd)
    d["character_names"] = decode_names(sd, 0xCAEC)
    d["character_names_default"] = decode_names(sd, 0xCE84)
    d["learn_jobs"] = decode_learn(sd)
    d["fiend_arena_cup_data"] = decode_cup(sd)
    d["friend_monster"] = decode_friend_monsters(sd)
    # nonzero coverage of big regions (for the diff map)
    for off, size, knd, name, prov in FIELDS:
        if knd in ("bits", "bytes"):
            d.setdefault("region_nonzero", {})[name] = _read(sd, off, size, "bytes")
    return d

# ── corpus scan: per-field stats ──

def iter_corpus(paths):
    for p in paths:
        if p.endswith(".txt"):
            for line in open(p, encoding="utf-8", errors="replace"):
                parts = line.rstrip("\n").split("\t")
                if len(parts) >= 4 and parts[0].isdigit():
                    yield parts[3]
        elif os.path.isdir(p):
            for root, _, files in os.walk(p):
                for fn in files:
                    yield os.path.join(root, fn)
        else:
            yield p

def scan(paths):
    stats = {}   # name -> {"n":int,"distinct":Counter,"min":..,"max":..}
    ply_stats = {}
    saves_seen, skipped = [], []
    for path in iter_corpus(paths):
        try:
            raw, kind, sd = load_save(path)
        except OSError:
            skipped.append(path); continue
        if sd is None:
            skipped.append(path); continue
        saves_seen.append({"path": path, "wrap": kind, "size": len(raw)})
        for off, size, knd, name, prov in FIELDS:
            if knd == "sub":
                continue
            v = _read(sd, off, size, knd)
            if v is None:
                continue
            s = stats.setdefault(name, {"n": 0, "distinct": Counter(),
                                        "min": None, "max": None})
            s["n"] += 1
            key = str(v) if not isinstance(v, list) else "list"
            if len(s["distinct"]) < 64 or key in s["distinct"]:
                s["distinct"][key] += 1
            if isinstance(v, int):
                s["min"] = v if s["min"] is None else min(s["min"], v)
                s["max"] = v if s["max"] is None else max(s["max"], v)
        # ply_save record-0 + populated records stats
        for rec in decode_ply_saves(sd):
            if rec["hp"] == 0 and rec["level"] == 0:
                continue
            for k_, v_ in rec.items():
                if k_ == "idx":
                    continue
                s = ply_stats.setdefault(k_, {"n": 0, "distinct": Counter(),
                                              "min": None, "max": None})
                s["n"] += 1
                key = str(v_)
                if len(s["distinct"]) < 64 or key in s["distinct"]:
                    s["distinct"][key] += 1
                if isinstance(v_, int):
                    s["min"] = v_ if s["min"] is None else min(s["min"], v_)
                    s["max"] = v_ if s["max"] is None else max(s["max"], v_)
    for s in list(stats.values()) + list(ply_stats.values()):
        s["distinct_count"] = len(s["distinct"])
        s["distinct"] = dict(s["distinct"].most_common(24))
    return {"saves": saves_seen, "skipped": skipped,
            "savedata_fields": stats, "ply_save_fields": ply_stats}

# ── diff: per-byte change map + region attribution ──

def diff(paths):
    files = []
    for path in iter_corpus(paths):
        try:
            raw, kind, sd = load_save(path)
        except OSError:
            continue
        if sd is None:
            continue
        files.append((path, bytes(sd)))
    if len(files) < 2:
        return {"error": "need >=2 saves"}
    maxlen = min(len(s) for _, s in files)
    vary = [0] * maxlen           # n saves where byte differs from save[0]
    nz = [0] * maxlen             # n saves where byte nonzero
    ref = files[0][1]
    for _, s in files[1:]:
        for i in range(maxlen):
            if s[i] != ref[i]:
                vary[i] += 1
            if s[i]:
                nz[i] += 1
    for i in range(maxlen):
        if ref[i]:
            nz[i] += 1
    # attribute varying bytes to known fields / gaps
    regions = []
    known = sorted((o, o + sz, n) for o, sz, _k, n, _p in FIELDS)
    cursor, gap_id = 0, 0
    for a, b, n in known:
        if a > cursor:
            regions.append((cursor, a, f"GAP_{gap_id:02d}")); gap_id += 1
        regions.append((a, min(b, maxlen), n)); cursor = max(cursor, b)
    if cursor < maxlen:
        regions.append((cursor, maxlen, f"GAP_{gap_id:02d}"))
    out_regions = []
    for a, b, n in regions:
        if a >= maxlen:
            break
        b = min(b, maxlen)
        ch = sum(1 for i in range(a, b) if vary[i])
        z = sum(1 for i in range(a, b) if nz[i])
        out_regions.append({"sd_off": f"0x{a:X}", "end": f"0x{b:X}",
                            "name": n, "size": b - a,
                            "varying_bytes": ch, "nonzero_saves_bytes": z})
    # top hot spots: consecutive varying-byte runs not inside a named field
    return {"n_saves": len(files), "ref": files[0][0],
            "regions": out_regions}

# ── CLI ──

def main(argv):
    if len(argv) < 2:
        print(__doc__); return 2
    mode = argv[1]
    if mode == "dump":
        print(json.dumps(dump_save(argv[2]), indent=1, default=str))
    elif mode == "scan":
        print(json.dumps(scan(argv[2:]), indent=1, default=str))
    elif mode == "diff":
        print(json.dumps(diff(argv[2:]), indent=1, default=str))
    elif mode == "verify":
        ok = True
        for p in argv[2:]:
            raw, kind, _sd = load_save(p)
            r = verify_checksum(raw, kind)
            print(f"{os.path.basename(p):32} {kind:8} {r}")
            ok = ok and bool(r and r["match"])
        return 0 if ok else 1
    elif mode == "fields":
        print("sd_off,sd_end,size,kind,name,provenance")
        for off, size, knd, name, prov in FIELDS:
            print(f"0x{off:05X},0x{off+size:05X},{size},{knd},{name},{prov}")
    else:
        print(__doc__); return 2
    return 0

if __name__ == "__main__":
    sys.exit(main(sys.argv))
