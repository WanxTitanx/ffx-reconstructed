#!/usr/bin/env python3
# kernel_table_reader.py — FFX kernel/data-table .bin reader + validator (research-only, read-only)
#
# PURPOSE : single per-format READER for the kernel table family (battle/kernel/*.bin non-text
#           tables + the menu/lastmiss strays). Decodes EVERY record of every file it is pointed
#           at, validates header invariants + field domains, and emits machine-usable stats
#           (JSON + CSV) for the FMT-KERNEL audit lane.
#
# SOURCES : record layouts mirror the proven C# parsers in FFXProjectEditor/FfxLib/*
#           (EntryListFile.cs, Ability_Command.cs, Ability_Gear.cs, AutoAbility_File.cs,
#           EquipmentStruct.cs, KeyItem_File.cs, ShopTable_File.cs, Customization_File.cs,
#           Treasure_File.cs, BukiGetTreasureCatalog_File.cs, WeaponNameTable_File.cs,
#           MixTable_File.cs, PlayerKernel_File.cs, SphereGrid_File.cs, EncounterTable_File.cs,
#           MonX_File.cs, MemoryBtl.cs). item_get.bin layout = Fahrenheit ChrLoot (0x118B,
#           work/_external_research/fahrenheit/src/core/ffx/battle/btldrop.cs). Formats with no
#           proven layout get a GENERIC byte/word grid decode and are flagged "unproven".
#
# USAGE   : python3 kernel_table_reader.py [--out DIR] [ROOT_DIR ...]
#           ROOT_DIR may be a single .bin file, a kernel dir (…/battle/kernel), a locale dir
#           (…/jppc — scans battle/kernel + menu/abilitymap.bin), or a tree root
#           (…/master — scans every */battle/kernel under it).
#           Default: the canonical vanilla master tree + the mission corpora below.
#
# OUTPUT  : <out>/kernel_read_<tag>.json  — full per-file, per-record stats + anomalies
#           <out>/kernel_read_<tag>.csv   — one line per file (shape + verdict)
#           <out>/fieldstats_<tag>.json   — per-format per-field value distribution
#
# LANE    : FMT-KERNEL audit (onda Formatos), 2026-09-16. Read-only on corpus.

import os, sys, json, struct, hashlib, collections

REPO = "/home/wanderson/Documents/ffx-editor-main"
OUT_DIR = os.path.join(REPO, "work", "_fmt_kernel")

DEFAULT_ROOTS = [
    "/mnt/nvme-xpg/ffx_ps2/ffx/master",                                   # pristine vanilla (9 locale trees)
    "/mnt/nvme-xpg/FFX_Data/GameData/PS3Data/de_lockit",                  # PS3 German lockit subset
    "/mnt/nvme-samsung/editor-stage/mods/Spira Reforge/sin-clean-bins/kernel",  # Spira Reforge modded kernel
    "/mnt/nvme-samsung/FFX Extracted/FFX2/ffx_ps2/ffx2/master",           # FFX-2 lastmiss kernel (lm_*)
]

# ----------------------------------------------------------------------------- generic helpers

def sha12(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for c in iter(lambda: f.read(1 << 20), b""):
            h.update(c)
    return h.hexdigest()[:12]

def u16(b, o):  return struct.unpack_from("<H", b, o)[0]
def i16(b, o):  return struct.unpack_from("<h", b, o)[0]
def u32(b, o):  return struct.unpack_from("<I", b, o)[0]
def i32(b, o):  return struct.unpack_from("<i", b, o)[0]
def s8(b, o):   return struct.unpack_from("<b", b, o)[0]

STATUS_NAMES = ["Death","Zombie","Petrify","Poison","BreakPower","BreakMagic","BreakArmor",
                "BreakMental","Confuse","Berserk","Provoke","Threaten","Sleep","Silence",
                "Darkness","Shell","Protect","Reflect","NulTide","NulBlaze","NulShock",
                "NulFrost","Regen","Haste","Slow"]

class FieldStats:
    """Accumulates min/max/nonzero/distinct-values for one logical field."""
    def __init__(self):
        self.n = 0; self.min = None; self.max = None; self.nonzero = 0
        self.vals = collections.Counter()
    def add(self, v):
        self.n += 1
        self.min = v if self.min is None else min(self.min, v)
        self.max = v if self.max is None else max(self.max, v)
        if v != 0: self.nonzero += 1
        if len(self.vals) < 4096 or v in self.vals:
            self.vals[v] += 1
    def out(self):
        top = self.vals.most_common(8)
        return {"n": self.n, "min": self.min, "max": self.max, "nonzero": self.nonzero,
                "distinct": len(self.vals), "top": [[v, c] for v, c in top]}

class Ctx:
    def __init__(self, fmt):
        self.fmt = fmt
        self.fields = collections.OrderedDict()   # name -> FieldStats
        self.anoms = []
        self.rows = 0
        self.string_ref_max = 0
        self.string_ref_oob = 0
        self.pool_size = 0       # max pool seen (reporting only)
        self.cur_pool = 0        # CURRENT file's pool — bounds check must be per-file
    def f(self, name, v):
        fs = self.fields.get(name)
        if fs is None:
            fs = self.fields[name] = FieldStats()
        fs.add(v)
    def sref(self, off):
        """track a string-pool offset reference — bounds-checked against the
        CURRENT file's pool (cur_pool). FIX 2026-09-17: previously compared
        against the per-format max pool, which masked real per-file violations
        (de_lockit w_name.bin rows 159-169 refs run 3-444B past EOF)."""
        self.string_ref_max = max(self.string_ref_max, off)
        if self.cur_pool and off >= self.cur_pool:
            self.string_ref_oob += 1

def parse_excel_header(b):
    """20B EntryListFile/IndexedFixedTableHeader. Returns dict or None if not Excel."""
    if len(b) < 20:
        return None
    sig = b[0]
    unk = b[1:8]
    minidx, maxidx, esize, tsize, toff = struct.unpack_from("<hhhHi", b, 8)
    if sig != 1 or unk != b"\x00" * 7 or toff != 0x14 or esize <= 0:
        return None
    rows = maxidx - minidx + 1
    if rows < 0:
        return None
    data_end = toff + rows * esize
    return {"min_index": minidx, "max_index": maxidx, "esize": esize, "tsize": tsize,
            "toff": toff, "rows": rows, "data_end": data_end,
            "pool": len(b) - data_end,
            "tsize_ok": ((rows * esize) & 0xFFFF) == tsize,
            "fits": data_end <= len(b)}

def read_tsinfo(b, o):
    """4B TextScriptInfo {u16 offset, u16 scriptId}"""
    return u16(b, o), u16(b, o + 2)

# ----------------------------------------------------------------------------- record decoders
# Each decoder takes (ctx, record_bytes, global_index) and feeds ctx.fields.

def dec_tsinfo4(ctx, r, gi, base=0, names=("name", "unused1", "desc", "unused2")):
    for i, nm in enumerate(names):
        off, sid = read_tsinfo(r, base + i * 4)
        ctx.f(f"{nm}.offset", off); ctx.f(f"{nm}.scriptId", sid)
        ctx.sref(off)

ABILITY_COMMAND_FIELDS = [
    # (name, offset, size, signed)
    ("anim1Id", 0x00, 2, True), ("anim2Id", 0x02, 2, True),
    ("iconId", 0x04, 1, False), ("casterAnimId", 0x05, 1, False),
    ("menuFlags", 0x06, 1, False), ("subSubMenuCat", 0x07, 1, False),
    ("subMenuCat", 0x08, 1, False), ("characterUser", 0x09, 1, True),
    ("targetFlags", 0x0A, 1, False), ("targetsAllowed", 0x0B, 1, False),
    ("misc1Flags", 0x0C, 1, False), ("misc2Flags", 0x0D, 1, False),
    ("misc3Flags", 0x0E, 1, False), ("misc4Flags", 0x0F, 1, False),
    ("damageFlags", 0x10, 1, False), ("stealGil", 0x11, 1, False),
    ("previewFlags", 0x12, 1, False), ("damageTypeFlags", 0x13, 1, False),
    ("moveRank", 0x14, 1, False), ("costMp", 0x15, 1, False),
    ("costOverdrive", 0x16, 1, False), ("critBonus", 0x17, 1, False),
    ("damageFormula", 0x18, 1, False), ("attackAccuracy", 0x19, 1, False),
    ("attackPower", 0x1A, 1, False), ("hitCount", 0x1B, 1, False),
    ("shatterChance", 0x1C, 1, False), ("elementFlags", 0x1D, 1, False),
    ("statusFlags", 0x44, 2, False), ("statBuffFlags", 0x46, 2, False),
    ("overdriveCategory", 0x48, 1, False), ("statBuffValue", 0x49, 1, False),
    ("specialBuffFlags", 0x4A, 2, False),
]

def dec_ability_command(ctx, r, gi, base=0x10, trunc=None):
    """Ability_Command payload (76B) starting at rec-relative `base`. trunc=last byte offset
    exclusive for the legacy 84B monmagic (68B ability part — fields past 0x43 do not exist)."""
    lim = len(r) if trunc is None else min(len(r), trunc)
    for name, off, sz, sgn in ABILITY_COMMAND_FIELDS:
        if base + off + sz > lim:
            continue
        v = {1: s8 if sgn else lambda b, o: b[o],
             2: i16 if sgn else u16}[sz](r, base + off)
        ctx.f(f"ac.{name}", v)
    # status chance 25B @0x1E, status duration 13B @0x37
    if base + 0x1E + 25 <= lim:
        for i in range(25):
            ctx.f(f"ac.statusChance[{STATUS_NAMES[i]}]", r[base + 0x1E + i])
    if base + 0x37 + 13 <= lim:
        for i in range(13):
            ctx.f(f"ac.statusDuration[{i}]", r[base + 0x37 + i])

def dec_command(ctx, r, gi):
    """command.bin / item.bin — 96B: 4×TSInfo + Ability_Command(76B) + ExtraCommandInfo(4B)"""
    dec_tsinfo4(ctx, r, gi)
    dec_ability_command(ctx, r, gi, base=0x10)
    ctx.f("extra.orderingIndexInMenu", r[0x5C])
    ctx.f("extra.sphereTypeForSphereGrid", s8(r, 0x5D))
    ctx.f("extra.unk1", r[0x5E]); ctx.f("extra.unk2", r[0x5F])

def dec_monmagic(ctx, r, gi):
    """monmagic1/2.bin — 92B: 4×TSInfo + Ability_Command(76B), NO ExtraCommandInfo."""
    dec_tsinfo4(ctx, r, gi)
    dec_ability_command(ctx, r, gi, base=0x10)

def dec_monmagic84(ctx, r, gi):
    """monmagic.bin (legacy, jppc/inpc only) — 84B: 4×TSInfo + 68B.
    The 68B ability part matches Ability_Command[0x00..0x43] (statusChance[0..21] only);
    fields from 0x44 (statusFlags..specialBuffFlags) DO NOT EXIST — the record ends 8B early.
    Content is NOT a monmagic1 prefix (refuted in FFX_KERNEL_STRIDES_2026-09-15 §7)."""
    dec_tsinfo4(ctx, r, gi)
    dec_ability_command(ctx, r, gi, base=0x10, trunc=0x54)
    # measure tail usage: bytes rec+0x46..0x53 documented always-zero in vanilla
    nz_tail = sum(1 for x in r[0x46:0x54] if x)
    ctx.f("tail_0x46_0x53_nonzero", nz_tail)

def dec_a_ability(ctx, r, gi):
    """a_ability.bin — 108B: 4×TSInfo + Ability_Gear(92B). Offsets per AutoAbility_File.cs."""
    dec_tsinfo4(ctx, r, gi)
    ctx.f("ag.sosFlag", r[0x10]); ctx.f("ag.elementStrike", r[0x11])
    ctx.f("ag.elementAbsorb", r[0x12]); ctx.f("ag.elementImmune", r[0x13])
    ctx.f("ag.elementResist", r[0x14]); ctx.f("ag.elementWeak", r[0x15])
    for i in range(25):
        ctx.f(f"ag.statusInflict[{STATUS_NAMES[i]}]", r[0x16 + i])
    for i in range(13):
        ctx.f(f"ag.statusDuration[{i}]", r[0x2F + i])
    for i in range(25):
        ctx.f(f"ag.statusResist[{STATUS_NAMES[i]}]", r[0x3C + i])
    ctx.f("ag.statIncreaseAmount", r[0x55])
    ctx.f("ag.statIncreaseFlags", u16(r, 0x56))
    ctx.f("ag.autoStatusesPermanent", u16(r, 0x58))
    ctx.f("ag.autoStatusesTemporal", u16(r, 0x5A))
    ctx.f("ag.autoStatusesExtra", u16(r, 0x5C))
    ctx.f("ag.extraStatusInflict", u16(r, 0x5E))
    ctx.f("ag.extraStatusImmunities", u16(r, 0x60))
    for i in range(5):
        ctx.f(f"ag.abilityFlags{0x62 + i:X}", r[0x62 + i])
    ctx.f("ag.unknownByte67", r[0x67]); ctx.f("ag.icon", r[0x68])
    ctx.f("ag.groupIndex", r[0x69]); ctx.f("ag.groupLevel", r[0x6A])
    ctx.f("ag.internationalBonusIndex", r[0x6B])

def dec_c_ability(ctx, r, gi):
    """c_ability.bin — 20B: 4×TSInfo + u16 commandRef + u16 pad.
    commandRef = command GameIndex (0x3000+cmdIdx) for 81/84 rows; rows 27-29
    hold a permuted triplet (0x301C/0x301D/0x301B) — the field is a *reference*,
    not rowIndex+0x3000. Table = per-command auxiliary/help text bundle
    (UNPROVEN role name; structure proven)."""
    dec_tsinfo4(ctx, r, gi)
    ctx.f("commandRef", u16(r, 0x10))
    ctx.f("pad0x12", u16(r, 0x12))
    ctx.f("commandRef_eq_0x3000_plus_idx", 1 if u16(r, 0x10) == 0x3000 + gi else 0)

def dec_equipment(ctx, r, gi):
    """weapon.bin / shop_arms.bin — 22B EquipmentStruct."""
    ctx.f("nameId", u16(r, 0x00)); ctx.f("exists", r[0x02])
    ctx.f("flags", r[0x03]); ctx.f("character", s8(r, 0x04))
    ctx.f("type", r[0x05]); ctx.f("characterEquipped", s8(r, 0x06))
    ctx.f("unk7", r[0x07]); ctx.f("damageFormula", r[0x08])
    ctx.f("power", r[0x09]); ctx.f("critBonus", r[0x0A])
    ctx.f("slotCount", r[0x0B]); ctx.f("modelId", u16(r, 0x0C))
    for i in range(4):
        v = u16(r, 0x0E + i * 2)
        ctx.f(f"ability{i + 1}", v)
        ctx.f(f"ability{i + 1}.category", (v >> 12) & 0xF)

def dec_buki_get(ctx, r, gi):
    """buki_get.bin — 16B: u8 flags/owner/gearType/unk03/dmgFormula/power/crit/slots + 4×u16 abilities."""
    ctx.f("flags", r[0x00]); ctx.f("owner", r[0x01]); ctx.f("gearType", r[0x02])
    ctx.f("unknown03", r[0x03]); ctx.f("damageFormula", r[0x04])
    ctx.f("power", r[0x05]); ctx.f("critBonus", r[0x06]); ctx.f("slotCount", r[0x07])
    for i in range(4):
        ctx.f(f"ability{i + 1}", u16(r, 0x08 + i * 2))

def dec_takara(ctx, r, gi):
    """takara.bin — 4B Treasure_Entry {kind u8, quantity u8, itemId u16}.
    Corpus-verified kind domain (jppc+inpc, 996 recs): 0=Gil(itemId unused=0),
    2=Item(itemId=item GameIndex 0x2xxx), 5=Gear(itemId=raw gear-catalog index,
    NOT a GameIndex), 0xA=KeyItem(itemId=0xAxxx). kind=1 NEVER occurs —
    the older doc table {1=Item,2=Weapon} is REFUTED by corpus pairing."""
    ctx.f("kind", r[0]); ctx.f("quantity", r[1]); ctx.f("itemId", u16(r, 2))
    ctx.f("itemId.category", (u16(r, 2) >> 12) & 0xF)

def dec_important(ctx, r, gi):
    """important.bin — 20B KeyItemEntry (KeyItem_File.cs): 4×TSInfo
    (name, dash, description, other — AuxiliaryText1/2 fill the old 'reserved'
    8B; verified 0/2432 offsets OOB across corpora) + 4×u8
    {itemType=primer flag, itemValue, icon, number=sort order}."""
    dec_tsinfo4(ctx, r, gi, names=("name", "dash", "desc", "other"))
    ctx.f("itemType", r[0x10]); ctx.f("itemValue", r[0x11])
    ctx.f("icon", r[0x12]); ctx.f("number", r[0x13])

def dec_shop(ctx, r, gi):
    """item_shop.bin / arms_shop.bin — 34B: u16 unusedPrice + 16×u16 slots."""
    ctx.f("unusedPrice", u16(r, 0))
    for i in range(16):
        v = u16(r, 0x02 + i * 2)
        ctx.f(f"slot{i}", v); ctx.f(f"slot{i}.category", (v >> 12) & 0xF)

def dec_i32(ctx, r, gi):
    """arms_rate.bin / item_rate.bin — 4B i32."""
    ctx.f("value_i32", i32(r, 0))

def dec_item_get(ctx, r, gi):
    """item_get.bin — 280B ChrLoot (Fahrenheit btldrop.cs): per-monster spoils.
    Index space == global monster index (366 rows)."""
    ctx.f("gil", u16(r, 0x00)); ctx.f("ap", u16(r, 0x02))
    ctx.f("ap_overkill", u16(r, 0x04)); ctx.f("ronso_rage", u16(r, 0x06))
    ctx.f("drop_chance_primary", r[0x08]); ctx.f("drop_chance_secondary", r[0x09])
    ctx.f("steal_chance", r[0x0A]); ctx.f("drop_chance_equipment", r[0x0B])
    for tag, base in (("item_loot", 0x0C), ("item_loot_overkill", 0x18)):
        for k, nm in enumerate(("primary_common", "primary_rare", "secondary_common", "secondary_rare")):
            v = u16(r, base + k * 2)
            ctx.f(f"{tag}.{nm}", v); ctx.f(f"{tag}.{nm}.category", (v >> 12) & 0xF)
        for k, nm in enumerate(("primary_common", "primary_rare", "secondary_common", "secondary_rare")):
            ctx.f(f"{tag}.amount_{nm}", r[base + 8 + k])
    ctx.f("steal.item_common", u16(r, 0x24)); ctx.f("steal.item_rare", u16(r, 0x26))
    ctx.f("steal.amount_common", r[0x28]); ctx.f("steal.amount_rare", r[0x29])
    ctx.f("steal.item_bribe", u16(r, 0x2A)); ctx.f("steal.amount_bribe", r[0x2C])
    e = 0x2D
    ctx.f("equip.slot_count", r[e]); ctx.f("equip.dmg_formula", r[e + 1])
    ctx.f("equip.crit_bonus", r[e + 2]); ctx.f("equip.power", r[e + 3])
    ctx.f("equip.ability_count", r[e + 4])
    chars = ["tidus", "yuna", "auron", "kimahri", "wakka", "lulu", "rikku"]
    for ci, cname in enumerate(chars):
        for kind, kb in (("wpn", e + 5 + ci * 32), ("arm", e + 5 + ci * 32 + 16)):
            for j in range(8):
                v = u16(r, kb + j * 2)
                ctx.f(f"equip.{cname}.{kind}{j}", v)
                if v:
                    ctx.f(f"equip.{cname}.{kind}{j}.category", (v >> 12) & 0xF)
    ctx.f("zanmato_level", r[0x112])
    tail_nz = sum(1 for x in r[0x113:0x118] if x)
    ctx.f("tail_0x113_0x117_nonzero", tail_nz)

def dec_customization(ctx, r, gi):
    """kaizou.bin / sum_grow.bin — 8B {target u16, result u16, item u16, primary u8, secondary u8}.
    Corpus-verified: kaizou secondaryValue is always 0 (unused in gear recipes).
    sum_grow: secondaryValue==1 EXACTLY for the 10 stat-growth recipes where
    result.category==0 (result = raw stat enum 0..9, not a GameIndex);
    ability recipes use result=command GameIndex 0x3xxx with secondary=0."""
    ctx.f("target", u16(r, 0)); ctx.f("result", u16(r, 2)); ctx.f("item", u16(r, 4))
    ctx.f("primaryValue", r[6]); ctx.f("secondaryValue", r[7])
    ctx.f("result.category", (u16(r, 2) >> 12) & 0xF)
    ctx.f("item.category", (u16(r, 4) >> 12) & 0xF)

def dec_prepare(ctx, r, gi):
    """prepare.bin — 224B: 112×u16 result GameIndex (Mix matrix row).
    Corpus-verified: ALL nonzero cells are category 3 (command GameIndex
    0x3xxx — Mix results are command abilities, not items)."""
    nz = 0
    for i in range(112):
        v = u16(r, i * 2)
        if v: nz += 1
        ctx.f("result.value", v); ctx.f("result.category", (v >> 12) & 0xF)
    ctx.f("row_nonzero_results", nz)

def dec_sphere(ctx, r, gi):
    """sphere.bin — 16B: 4 text-ref words + behavior/activates/range/specialRole/reserved."""
    dec_tsinfo4(ctx, r, gi, names=("desc_jp", "simpl_jp"))   # 2 TSInfo pairs (8B)
    ctx.f("behavior", u16(r, 0x08)); ctx.f("activates", u16(r, 0x0A))
    ctx.f("range", r[0x0C]); ctx.f("specialRole", r[0x0D])
    ctx.f("reserved0x0E", u16(r, 0x0E))

def dec_panel(ctx, r, gi):
    """panel.bin — 24B: 4×(off,key) text refs + nodeEffect/learnedMove/increase/appearance."""
    for i, nm in enumerate(("desc", "simpl", "extra1", "extra2")):
        off, key = u16(r, i * 4), u16(r, i * 4 + 2)
        ctx.f(f"{nm}.offset", off); ctx.f(f"{nm}.key", key); ctx.sref(off)
    ctx.f("nodeEffectBitfield", u16(r, 0x10)); ctx.f("learnedMove", u16(r, 0x12))
    ctx.f("increaseAmount", u16(r, 0x14)); ctx.f("appearanceType", u16(r, 0x16))

def dec_ply_save(ctx, r, gi):
    """ply_save.bin — 148B PlayerSaveEntry (PlayerKernel_File.cs)."""
    ctx.f("baseHp", i32(r, 0x04)); ctx.f("baseMp", i32(r, 0x08))
    for i, nm in enumerate(("str", "def", "mag", "mdef", "agi", "luck", "eva", "acc")):
        ctx.f(f"base_{nm}", r[0x0C + i])
    ctx.f("currentAp", i32(r, 0x18)); ctx.f("currentHp", i32(r, 0x1C))
    ctx.f("currentMp", i32(r, 0x20)); ctx.f("maxHp", i32(r, 0x24)); ctx.f("maxMp", i32(r, 0x28))
    ctx.f("equippedWeaponIndex", r[0x2D]); ctx.f("equippedArmorIndex", r[0x2E])
    for i, nm in enumerate(("str", "def", "mag", "mdef", "agi", "luck", "eva", "acc")):
        ctx.f(f"cur_{nm}", r[0x2F + i])
    ctx.f("poisonDamagePercent", r[0x37]); ctx.f("overdriveMode", r[0x38])
    ctx.f("overdriveCurrent", r[0x39]); ctx.f("overdriveMax", r[0x3A])
    ctx.f("sphereLevelsAvailable", r[0x3B]); ctx.f("sphereLevelsUsed", r[0x3C])
    ctx.f("encounterCount", i32(r, 0x50)); ctx.f("killCount", i32(r, 0x54))
    # undecoded regions tracked as nonzero tails
    for a, b_, tag in ((0x00, 0x04, "head_0x00_0x03"), (0x14, 0x18, "unk_0x14_0x17"),
                       (0x2C, 0x2D, "unk_0x2C"), (0x3D, 0x50, "unk_0x3D_0x4F"),
                       (0x58, 0x94, "tail_0x58_0x93")):
        ctx.f(f"{tag}_nonzero", sum(1 for x in r[a:b_] if x))

def dec_ply_rom(ctx, r, gi):
    """ply_rom.bin — 44B PlayerRomEntry (PlayerKernel_File.cs)."""
    ctx.f("head_0x00_0x0F_nonzero", sum(1 for x in r[0x00:0x10] if x))
    ctx.f("genreByte", r[0x10])
    ctx.f("apReqA", r[0x11]); ctx.f("apReqB", r[0x12]); ctx.f("apReqC", r[0x13])
    ctx.f("apReqMax", i32(r, 0x14))
    for i, nm in enumerate(("hp", "mp", "str", "def", "mag", "mdef", "agi", "eva", "acc")):
        ctx.f(f"{nm}CoefA", r[0x18 + i * 2]); ctx.f(f"{nm}CoefB", r[0x19 + i * 2])
    ctx.f("tailFlags", u16(r, 0x2A))

def dec_monster(ctx, r, gi):
    """monster1/2/3.bin — 128B: 5×TSInfo + MonsterStatSheet(108B)."""
    for i, nm in enumerate(("name", "sensor", "unused1", "scan", "unused2")):
        off, sid = read_tsinfo(r, i * 4)
        ctx.f(f"ts.{nm}.offset", off); ctx.f(f"ts.{nm}.scriptId", sid); ctx.sref(off)
    ctx.f("hp", u32(r, 0x14)); ctx.f("mp", u32(r, 0x18)); ctx.f("hpOverkill", u32(r, 0x1C))
    for i, nm in enumerate(("str", "def", "mag", "mdef", "agi", "luck", "eva", "acc")):
        ctx.f(nm, r[0x20 + i])
    ctx.f("propertyFlags", i16(r, 0x28)); ctx.f("poisonDamage", r[0x2A])
    ctx.f("elemAbsorb", r[0x2B]); ctx.f("elemImmune", r[0x2C])
    ctx.f("elemResist", r[0x2D]); ctx.f("elemWeak", r[0x2E])
    for i in range(25):
        ctx.f(f"statusResist[{STATUS_NAMES[i]}]", s8(r, 0x2F + i))
    ctx.f("autoStatus1", u16(r, 0x48)); ctx.f("autoStatus2", u16(r, 0x4A))
    ctx.f("autoStatus3", u16(r, 0x4C)); ctx.f("extraImmunities", u16(r, 0x4E))
    for i in range(16):
        v = u16(r, 0x50 + i * 2)
        ctx.f(f"ability{i}", v)
        if v: ctx.f(f"ability{i}.category", (v >> 12) & 0xF)
    ctx.f("forcedAction", u16(r, 0x70)); ctx.f("monsterId", i16(r, 0x72))
    ctx.f("modelId", i16(r, 0x74)); ctx.f("ctbIconId", r[0x76])
    ctx.f("doomCount", s8(r, 0x77)); ctx.f("arenaId", s8(r, 0x78))
    ctx.f("pad79", r[0x79]); ctx.f("model2Id", i16(r, 0x7A))
    ctx.f("pad_0x7C_0x7F_nonzero", sum(1 for x in r[0x7C:0x80] if x))

def dec_w_name(ctx, r, gi):
    """w_name.bin — 72B: 7×(off,key) regular + 7×(off,key) simplified + 7×u16 models + u16 final."""
    for i in range(7):
        off, key = u16(r, i * 4), u16(r, i * 4 + 2)
        ctx.f(f"regular{i}.offset", off); ctx.f(f"regular{i}.key", key); ctx.sref(off)
    for i in range(7):
        off, key = u16(r, 0x1C + i * 4), u16(r, 0x1E + i * 4)
        ctx.f(f"simplified{i}.offset", off); ctx.f(f"simplified{i}.key", key); ctx.sref(off)
    for i in range(7):
        v = u16(r, 0x38 + i * 2)
        ctx.f(f"model{i}", v); ctx.f(f"model{i}.category", (v >> 12) & 0xF)
    ctx.f("finalWord", u16(r, 0x46))

def dec_ctb_base(ctx, r, gi):
    """ctb_base.bin — 2B u16 per AGI value (1..255)."""
    ctx.f("ctbTick", u16(r, 0))

def dec_u16_grid(ctx, r, gi):
    """Generic fallback: decode record as u16 words w<N> + per-byte histogram fields."""
    for i in range(0, len(r) - 1, 2):
        ctx.f(f"w{i // 2:02d}", u16(r, i))
    if len(r) % 2:
        ctx.f(f"b{len(r) - 1}", r[-1])
    ctx.f("row_nonzero", sum(1 for x in r if x))

# ----------------------------------------------------------------------------- non-Excel formats

def dec_btl(b, ctx):
    """btl.bin — 2-chunk encounter container (EncounterTable_File.cs)."""
    res = {"fields": {}, "anoms": []}
    if len(b) != 0x1000 or u32(b, 0) != 2:
        res["anoms"].append("unexpected size/signature")
    c0, c1, end = u32(b, 4), u32(b, 8), u32(b, 12)
    res.update(sig=u32(b, 0), chunk0=c0, chunk1=c1, fileEnd=end,
               n_tables=(c1 - c0) // 0x0E)
    n = res["n_tables"]
    maps = collections.Counter()
    total_groups = total_form = 0
    for i in range(n):
        o = c0 + i * 0x0E
        tid, doff, foff = u16(b, o), u16(b, o + 2), u16(b, o + 4)
        mapname = b[o + 6:o + 12].split(b"\x00")[0].decode("ascii", "replace")
        unk = u16(b, o + 0x0C)
        ctx.f("hdr.id", tid); ctx.f("hdr.dataOffset", doff)
        ctx.f("hdr.formationOffset", foff); ctx.f("hdr.unk0C", unk)
        maps[mapname] += 1
        # payload: u8 totalFormations, u8 groupCount, then groups
        p = c1 + doff
        if p + 2 > len(b):
            res["anoms"].append(f"table {i} dataOffset OOB")
            continue
        gc = b[p + 1]
        ctx.f("pl.totalFormations", b[p]); ctx.f("pl.groupCount", gc)
        rel = 2
        for g in range(gc):
            go = p + rel
            if go + 5 > len(b):
                res["anoms"].append(f"table {i} group {g} OOB"); break
            fc = b[go]
            ctx.f("grp.formationCount", fc); ctx.f("grp.battlefield", u16(b, go + 1))
            ctx.f("grp.grace", b[go + 3]); ctx.f("grp.totalWeight", b[go + 4])
            for j in range(fc):
                fo = go + 5 + j * 2
                if fo + 2 > len(b):
                    break
                ctx.f("frm.id", b[fo]); ctx.f("frm.weight", b[fo + 1])
                total_form += 1
            rel += 5 + fc * 2
            total_groups += 1
    res["maps"] = dict(maps.most_common())
    res["groups"] = total_groups; res["formations"] = total_form
    return res

def dec_magic_bin(b, ctx):
    """magic.bin — 1024×u16 identity table (strictly u16[i]==i verified)."""
    ok = all(u16(b, i * 2) == i for i in range(1024)) if len(b) >= 2048 else False
    ctx.f("identity_holds", 1 if ok else 0)
    return {"identity": ok}

def dec_albhed(b, ctx):
    """albhed.bin — CJK-only non-Excel: 10×u32 duplicated-offset pairs + string blob."""
    pairs = []
    for i in range(10):
        v = u32(b, i * 8); w = u32(b, i * 8 + 4)
        pairs.append((v, w)); ctx.f(f"pair{i}.a", v); ctx.f(f"pair{i}.dup_eq", 1 if v == w else 0)
    blob = b[0x50:]
    strs = [s for s in blob.split(b"\x00") if s]
    return {"pairs": pairs, "strings": len(strs), "blob_len": len(blob)}

def dec_abilitymap(b, ctx):
    """menu/abilitymap.bin — ABMap cell grid (NOT Excel). Generic word grid over file."""
    for i in range(0, min(len(b), 0x2000) - 1, 2):
        ctx.f(f"w{i // 2:04d}", u16(b, i))

def dec_ffx2_lm(b, ctx):
    """FFX-2 lastmiss kernel lm_*.bin — u32 header @0x10 (NOT the FFX Excel 20B header).
    Fields measured: w4..w7 @0x10..0x1F then table body. UNPROVEN semantics."""
    hdr = {"w0": u32(b, 0), "w4": u32(b, 0x10), "w5": u32(b, 0x14),
           "w6": u32(b, 0x18), "w7": u32(b, 0x1C)}
    body = b[0x20:]
    for i in range(0, len(body) - 1, 2):
        ctx.f(f"body_w{i // 2:04d}", u16(body, i))
    return hdr

# ----------------------------------------------------------------------------- driver

# filename -> (decoder_key, human note)
EXCEL_FORMATS = {
    "command.bin":    (dec_command,   "96B = 4xTSInfo + Ability_Command(76B) + ExtraCommandInfo(4B)"),
    "item.bin":       (dec_command,   "96B = 4xTSInfo + Ability_Command(76B) + ExtraCommandInfo(4B)"),
    "monmagic1.bin":  (dec_monmagic,  "92B = 4xTSInfo + Ability_Command(76B)"),
    "monmagic2.bin":  (dec_monmagic,  "92B = 4xTSInfo + Ability_Command(76B)"),
    "monmagic.bin":   (dec_monmagic84,"84B legacy = 4xTSInfo + Ability_Command[0..0x43] (68B); refuted as monmagic1-prefix"),
    "a_ability.bin":  (dec_a_ability, "108B = 4xTSInfo + Ability_Gear(92B)"),
    "c_ability.bin":  (dec_c_ability, "20B = 4xTSInfo + u16 packedRef + u16 pad (UNPROVEN)"),
    "monster1.bin":   (dec_monster,   "128B = 5xTSInfo + MonsterStatSheet(108B)"),
    "monster2.bin":   (dec_monster,   "128B = 5xTSInfo + MonsterStatSheet(108B)"),
    "monster3.bin":   (dec_monster,   "128B = 5xTSInfo + MonsterStatSheet(108B)"),
    "weapon.bin":     (dec_equipment, "22B EquipmentStruct"),
    "shop_arms.bin":  (dec_equipment, "22B EquipmentStruct (gear catalog)"),
    "buki_get.bin":   (dec_buki_get,  "16B BukiGetTreasureEntry"),
    "takara.bin":     (dec_takara,    "4B Treasure_Entry"),
    "important.bin":  (dec_important, "20B KeyItemEntry"),
    "item_shop.bin":  (dec_shop,      "34B ShopEntry (16 item slots)"),
    "arms_shop.bin":  (dec_shop,      "34B ShopEntry (16 gear-catalog slots)"),
    "item_rate.bin":  (dec_i32,       "4B i32 price/rate per item-domain index (UNPROVEN domain)"),
    "arms_rate.bin":  (dec_i32,       "4B i32 gil price per a_ability index"),
    "item_get.bin":   (dec_item_get,  "280B ChrLoot per-monster spoils (Fahrenheit)"),
    "kaizou.bin":     (dec_customization, "8B GearCustomizationEntry"),
    "sum_grow.bin":   (dec_customization, "8B AeonCustomizationEntry"),
    "prepare.bin":    (dec_prepare,   "224B = 112xu16 Mix result matrix row"),
    "sphere.bin":     (dec_sphere,    "16B SphereGridEntry"),
    "panel.bin":      (dec_panel,     "24B SphereGridNodeTypeEntry"),
    "ply_save.bin":   (dec_ply_save,  "148B PlayerSaveEntry"),
    "ply_rom.bin":    (dec_ply_rom,   "44B PlayerRomEntry"),
    "ctb_base.bin":   (dec_ctb_base,  "2B u16 CTB tick per AGI"),
    "st_number.bin":  (dec_u16_grid,  "4B u16 pair (UNPROVEN)"),
    "sum_assure.bin": (dec_u16_grid,  "12B (UNPROVEN)"),
    "menu.bin":       (dec_u16_grid,  "28B single-record (UNPROVEN)"),
    "menu_panel.bin": (dec_u16_grid,  "32B single-record (UNPROVEN)"),
    "party.bin":      (dec_u16_grid,  "132B single-record (UNPROVEN)"),
    "amapdata.bin":   (dec_u16_grid,  "32B x 32 ABMap data (UNPROVEN)"),
    "w_name.bin":     (dec_w_name,    "72B WeaponNameEntry"),
}
NON_EXCEL = {"btl.bin": dec_btl, "magic.bin": dec_magic_bin, "albhed.bin": dec_albhed,
             "abilitymap.bin": dec_abilitymap}
FFX2_FORMATS = {"lm_command.bin", "lm_capacity.bin", "lm_accesary.bin",
                "lm_monster.bin", "lm_mes.bin", "lm_floorname.bin", "lm_trap.bin",
                "lm_dress.bin", "lm_warehouse.bin", "lm_player.bin", "lm_item.bin"}

def collect_files(root):
    """Yield (tag, relpath, abspath) for every kernel .bin under `root`."""
    root = os.path.normpath(root)
    if os.path.isfile(root):
        yield os.path.basename(os.path.dirname(root)) + "/" + os.path.basename(root), root
        return
    # direct kernel dir?
    for fn in sorted(os.listdir(root)):
        p = os.path.join(root, fn)
        if os.path.isfile(p) and (fn.endswith(".bin") or fn.endswith(".$$$") or fn == "file"):
            yield os.path.join(os.path.basename(root), fn), p
    # locale trees
    for loc in sorted(os.listdir(root)):
        kd = os.path.join(root, loc, "battle", "kernel")
        if os.path.isdir(kd):
            for fn in sorted(os.listdir(kd)):
                p = os.path.join(kd, fn)
                if os.path.isfile(p) and not fn.startswith("."):
                    yield f"{loc}/battle/kernel/{fn}", p
        kd = os.path.join(root, loc, "lastmiss", "kernel")
        if os.path.isdir(kd):
            for fn in sorted(os.listdir(kd)):
                p = os.path.join(kd, fn)
                if os.path.isfile(p) and not fn.startswith("."):
                    yield f"{loc}/lastmiss/kernel/{fn}", p
        # menu/abilitymap.bin
        am = os.path.join(root, loc, "menu", "abilitymap.bin")
        if os.path.isfile(am):
            yield f"{loc}/menu/abilitymap.bin", am

def read_file(rel, path, ctxs, file_rows):
    b = open(path, "rb").read()
    fn = os.path.basename(rel)
    row = {"file": rel, "size": len(b), "sha12": sha12(path)}
    hdr = parse_excel_header(b)
    if hdr:
        row.update(kind="excel", **{k: hdr[k] for k in
                   ("min_index", "max_index", "esize", "rows", "data_end", "pool",
                    "tsize_ok", "fits")})
        if not hdr["tsize_ok"] or not hdr["fits"]:
            row.setdefault("anoms", []).append("header invariant fail")
        dec, note = EXCEL_FORMATS.get(fn, (dec_u16_grid, "generic u16 grid (UNPROVEN)"))
        row["decoder"] = dec.__name__; row["layout"] = note
        ctx = ctxs.setdefault(fn, Ctx(fn))
        ctx.pool_size = max(ctx.pool_size, hdr["pool"])
        ctx.cur_pool = hdr["pool"]
        if hdr["rows"] * hdr["esize"] and hdr["data_end"] <= len(b):
            for i in range(hdr["rows"]):
                o = hdr["toff"] + i * hdr["esize"]
                try:
                    dec(ctx, b[o:o + hdr["esize"]], hdr["min_index"] + i)
                    ctx.rows += 1
                except Exception as e:
                    ctx.anoms.append(f"{rel} rec {i}: {e}")
                    row.setdefault("anoms", []).append(f"rec {i} decode: {e}")
    elif fn in NON_EXCEL:
        ctx = ctxs.setdefault(fn, Ctx(fn))
        try:
            extra = NON_EXCEL[fn](b, ctx)
            row.update(kind="non-excel", decoder=NON_EXCEL[fn].__name__, detail=extra)
            ctx.rows += 1
        except Exception as e:
            row.update(kind="non-excel", anoms=[f"decode: {e}"])
    elif fn in FFX2_FORMATS:
        ctx = ctxs.setdefault(fn, Ctx(fn))
        try:
            hh = dec_ffx2_lm(b, ctx)
            row.update(kind="ffx2-lastmiss", decoder="dec_ffx2_lm", header=hh)
            ctx.rows += 1
        except Exception as e:
            row.update(kind="ffx2-lastmiss", anoms=[f"decode: {e}"])
    else:
        row["kind"] = "unhandled"
    file_rows.append(row)

def main():
    # FIX 2026-09-17: naive `[a for a in argv if not a.startswith("--")]` leaked the
    # `--out` VALUE into `roots` (scanning the output dir as a corpus root). Parse
    # explicitly so `--out DIR` consumes both tokens.
    args = sys.argv[1:]
    outdir = OUT_DIR
    if any(a in ("-h", "--help") for a in args):
        print(__doc__ or "")
        print("Usage: kernel_table_reader.py [--out DIR] [ROOT_DIR ...]")
        print("No roots  -> DEFAULT_ROOTS (xpg master, de_lockit, sin-clean, FFX-2 master)")
        sys.exit(0)
    if "--out" in args:
        i = args.index("--out")
        if i + 1 < len(args):
            outdir = args[i + 1]
            del args[i:i + 2]
        else:
            args.pop(i)
    roots = [a for a in args if not a.startswith("--")]
    if not roots:
        roots = DEFAULT_ROOTS
    os.makedirs(outdir, exist_ok=True)

    ctxs = {}          # filename -> Ctx (aggregated across corpora)
    file_rows = []
    for root in roots:
        if not os.path.isdir(root) and not os.path.isfile(root):
            print(f"!! missing root: {root}")
            continue
        tag = os.path.basename(root.rstrip("/")) or root
        for rel, path in collect_files(root):
            read_file(rel, path, ctxs, file_rows)

    # ---- per-format field stats
    fs_out = {}
    for fn, ctx in sorted(ctxs.items()):
        fs_out[fn] = {
            "files_read": ctx.rows,
            "anomalies": ctx.anoms[:50],
            "anomaly_count": len(ctx.anoms),
            "string_ref_max": ctx.string_ref_max,
            "string_ref_oob": ctx.string_ref_oob,
            "fields": {k: v.out() for k, v in ctx.fields.items()},
        }

    stamp = "all" if len(roots) > 1 else (os.path.basename(roots[0].rstrip("/")) or "out")
    jpath = os.path.join(outdir, f"kernel_read_{stamp}.json")
    cpath = os.path.join(outdir, f"kernel_read_{stamp}.csv")
    fpath = os.path.join(outdir, f"fieldstats_{stamp}.json")
    with open(jpath, "w") as f:
        json.dump({"roots": roots, "files": file_rows}, f, indent=1, default=str)
    cols = ["file", "kind", "size", "min_index", "max_index", "esize", "rows",
            "data_end", "pool", "tsize_ok", "fits", "decoder", "layout", "sha12"]
    with open(cpath, "w") as f:
        f.write(",".join(cols) + "\n")
        for r in file_rows:
            f.write(",".join(str(r.get(c, "")) for c in cols).replace("\n", " ") + "\n")
    with open(fpath, "w") as f:
        json.dump(fs_out, f, indent=1, default=str)

    print(f"files read: {len(file_rows)}  formats decoded: {len(ctxs)}")
    n_anom = sum(v["anomaly_count"] for v in fs_out.values())
    print(f"decode anomalies: {n_anom}")
    for fn, v in sorted(fs_out.items()):
        flag = f"  !! {v['anomaly_count']} anoms" if v["anomaly_count"] else ""
        oob = f"  !! {v['string_ref_oob']} oob string refs" if v["string_ref_oob"] else ""
        print(f"  {fn:22s} files={v['files_read']:4d} fields={len(v['fields']):4d} "
              f"srefmax={v['string_ref_max']}{oob}{flag}")
    print(f"\nwrote {jpath}\n      {cpath}\n      {fpath}")

if __name__ == "__main__":
    main()
