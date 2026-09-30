#!/usr/bin/env python3
# ── EV01 (.ebp) SaveData-variable miner — PUSHV/POPV operand -> save_ram offset ──
#
# Lane: FFX-STRUCTURES / EV01-MINER · 2026-09-14 · Python stdlib only.
# Research tool: does NOT ship in the editor; read-only over the extracted corpus.
#
# PURPOSE
#   The FFX save block ("dicionário ATEL", save_ram[0..0x21EC), VA 0x112CA90 in
#   FFX.exe HD) is read/written by EV01 field/event scripts through the ATEL VM
#   variable opcodes (fahrenheit names: PUSHV/POPV/POPVL/PUSHAR/POPAR/POPARL/
#   PUSHARP). The engine side (FFX_VM_ResolveMemoryAddress@0x86C270 +
#   FFX_ScriptOp_SceneStateRead*@0x8791A0..0x8791E0 / FFX_FieldVM_Store*
#   @0x879200..0x8792C0) applies NO bound on the offset, so the ONLY way to know
#   which save areas the event corpus actually touches is to mine the operands
#   in the 397 .ebp files. This script does exactly that.
#
# DECODE CHAIN (all steps proven — see docs/reverse/FFX_EV01_SAVEVAR_MINING_2026-09-14.md)
#   1. .ebp = EV01 container: u32 chunk-offset table @0x04 (0 = absent chunk,
#      sentinel 0xFFFFFFFF, entry before sentinel = EOF == filesize), chunks
#      0x40-aligned. Chunk slot 0 = ATEL blob (present in 397/397, per
#      FFX_EVENT_EBP_FORMAT_REFERENCE_2026-06-05.md §1).
#   2. ATEL blob header: codeLen u32@0x00, totalLen u32@0x10, scriptStart
#      u32@0x30, workerCount u16@0x36, worker-offset table u32[]@0x38.
#   3. Worker[0] header (== fahrenheit AtelScriptHeader, 0x38 B):
#      offset_var_table@+0x14, offset_int_table@+0x18 (var table ends there).
#   4. Variable descriptors, 8 bytes each: u32 lo + u32 hi.
#        lo bits 28-31 : element TYPE (0=u8 1=s8 2=u16 3=s16 4=u32 5=s32 6=f32;
#                        7 also 1-byte stride — FFX_FieldVM_PushArrayOperand@0x86E0F0)
#        lo bits 25-27 : LOCATION (FFX_VM_ResolveMemoryAddress switch):
#                        0=SaveData, 1=CommonVars, 2=Data, 3=Private, 4=Shared,
#                        5=IntRegisters, 6=EventData
#        lo bit  24    : unknown flag (0 in the whole corpus)
#        lo bits  0-23 : SLOT (24-bit byte offset within the location base)
#        hi u16 @+4    : element_count (runtime clamps index to count-1)
#   5. Bytecode walk [scriptStart, scriptStart+codeLen): length rule is
#      universal (FFX_Atel_FetchOpcode@0x869D00): opcode byte & 0x80 -> 3 bytes
#      with u16 LE operand, else 1 byte. Walk closes EXACTLY on codeLen for
#      100% of the corpus (self-validation).
#   6. Variable-access opcodes (byte values; interpreter cases are the low-7
#      numbers 0x1F-0x24/0x27):
#        0x9F PUSHV  read scalar var[idx]            (case 0x1F -> ReadArrayToStack idx=0)
#        0xA0 POPV   store scalar var[idx], mode 0   (case 0x20)
#        0xA1 POPVL  store scalar var[idx], mode 1   (case 0x21)
#        0xA2 PUSHAR read var[idx][stack_index]      (case 0x22 -> PopStackValue)
#        0xA3 POPAR  store var[idx][stack_index]     (case 0x23, mode 128)
#        0xA4 POPARL store var[idx][stack_index]     (case 0x24, mode 129)
#        0xA7 PUSHARP push element ADDRESS (by-ref)  (case 0x27)
#      The u16 operand is a variable-table INDEX (validated: 0 out-of-range
#      operands across the whole corpus).
#   7. SaveData variables (LOCATION 0): save_ram/Fh offset = SLOT + 0x1EC.
#      The +0x1EC constant is NOT from a single decompile line — it is the
#      uniform empirical delta anchored by three independent field families
#      (slot -> Fh):
#        CalmLandsQuest 0x8D -> 0x279, EnergyBlast 0x104 -> 0x2F0,
#        ControllableCharInLuca 0x14B -> 0x337, OmegaRuins 0x1D2 -> 0x3BE,
#        ThunderPlains 0x205 -> 0x3F1, LightningBolts/Dodges 0x210/0x212 ->
#        0x3FC/0x3FE   (fahrenheit ffx/savedata.cs FieldOffsets)
#        DarkValefor..DarkAnima 0xA9D..0xAA3 -> 0xC89..0xC8F
#        (FFXED registry bit fields, label "Dark * Defeated")
#        BlitzCapacity 0x1392 -> 0x157E (IDA memset in
#        FFX_Encounter_InitStatusEffectBuffers@0x784660), BlitzTechniques
#        0x1266 -> 0x1452, BlitzContracts 0x152A -> 0x1716, BlitzSalary/
#        CostPerGame 0x1798 -> 0x1984, BlitzLeaguePrize 0x1810 -> 0x19FC
#        (FFXED registry + fahrenheit BlitzballData).
#      CAVEAT (honesty): FFX_Field_InitScriptWorkerDefaults@0x871130 sets
#      Controller+0x2C (the ResolveMemoryAddress SaveData base) to
#      AtelGetEventSaveRamAdrs()+123 = save_ram+0x7B as a DEFAULT; the +0x1EC
#      base must be established by another writer in the field path (not in
#      the session artifacts). The three cross-validated anchor families above
#      make +0x1EC the operative mapping for slot interpretation.
#
# CAVEATS / LIMITS
#   - Only PUSHV/POPV-family accesses are mined. Scene-state bits
#     (save_ram+0x4C..0x9C, 640 bits, FFX_FieldVM_Set/Clear/TestSceneStateBit
#     @0x85E6F0/0x85E490/0x85E970) are reached through native CALLs, not these
#     opcodes — and are in fact UNREACHABLE by SaveData slots (they would need
#     negative slots: 0x4C-0x1EC < 0).
#   - Array variables are attributed with their FULL DECLARED SPAN
#     (slot .. slot + count*stride) when classifying into save regions; the
#     base-slot histogram counts accesses at the base slot only.
#   - "Fh offset" == save_ram byte offset == Fahrenheit offset == file offset
#     - 0x40 (editor offset - 0x40), per FFX_SAVE_EVENTFLAGS_IDA_2026-09-14 §1.2.
#
# CREDITS
#   - Variable name table: Karifean/FFXDataParser ScriptConstants.putSaveDataVariable
#     (names only, no code) — mirrored in FFXProjectEditor/FfxLib/Ai/
#     AiSaveDataVariableNames.cs.
#   - fahrenheit (LGPL) savedata.cs field offsets used as anchors (names/facts
#     only, no code). ATEL VM semantics from our own IDA decompiles
#     (work/_ev01_mining/, work/_eventflags_re/callers_decompiled.json).
#
# USAGE
#   python3 ev01_savevar_mining.py [--root <ffx_ps2 dir>] [--json out.json]
#     [--top N]   (default 25; top-offsets table size)
#   Default root: /mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2

import argparse
import json
import os
import struct
import sys
from collections import Counter, defaultdict

DEFAULT_ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"

# SaveData base delta: Fh offset = slot + SAVEDATA_BASE.
SAVEDATA_BASE = 0x1EC

TYPE_NAMES = {0: "u8", 1: "s8", 2: "u16", 3: "s16", 4: "u32", 5: "s32", 6: "f32", 7: "u8x"}
TYPE_STRIDE = {0: 1, 1: 1, 2: 2, 3: 2, 4: 4, 5: 4, 6: 4, 7: 1}
LOCATION_NAMES = {0: "SaveData", 1: "CommonVars", 2: "Data", 3: "Private",
                  4: "Shared", 5: "IntRegisters", 6: "EventData"}

# Variable-access opcodes (byte values) -> (mnemonic, access class).
VAR_OPS = {
    0x9F: ("PUSHV", "read"),
    0xA0: ("POPV", "store"),
    0xA1: ("POPVL", "store"),
    0xA2: ("PUSHAR", "read"),
    0xA3: ("POPAR", "store"),
    0xA4: ("POPARL", "store"),
    0xA7: ("PUSHARP", "addr"),
}

# FFXDataParser saveData slot names (credit: Karifean/FFXDataParser, names only).
SLOT_NAMES = {
    0x008D: "CalmLandsQuestProgressionFlags",
    0x0092: "MushroomRockRoadTreasureFlags",
    0x00A8: "WobblyChocoboRecordMinutes",
    0x00A9: "WobblyChocoboRecordSeconds",
    0x00AA: "WobblyChocoboRecordTenths",
    0x00AB: "DodgerChocoboRecordMinutes",
    0x00AC: "DodgerChocoboRecordSeconds",
    0x00AD: "DodgerChocoboRecordTenths",
    0x00AE: "HyperDodgerChocoboRecordMinutes",
    0x00AF: "HyperDodgerChocoboRecordSeconds",
    0x00B0: "HyperDodgerChocoboRecordTenths",
    0x00B1: "CatcherChocoboRecordMinutes",
    0x00B2: "CatcherChocoboRecordSeconds",
    0x00B3: "CatcherChocoboRecordTenths",
    0x00CE: "BikanelTreasureFlags1",
    0x00CF: "BikanelTreasureFlags2",
    0x00D0: "BikanelTreasureFlags3",
    0x0104: "EnergyBlastProgressionFlags",
    0x0115: "BesaidVillageTreasureFlags",
    0x014B: "ControllableCharacterInLuca",
    0x0193: "DebugSkipJechtIntroScenes",
    0x01C0: "KilikaForestTreasureFlags",
    0x01C5: "BesaidTreasureFlags",
    0x01CD: "MacalaniaTreasureFlags",
    0x01D2: "OmegaRuinsProgressionFlags",
    0x01D4: "HomeProgressionFlags",
    0x0205: "ThunderPlainsProgressionFlags",
    0x0208: "LightningDodgingRewardsToPickUpFlags",
    0x0210: "LightningDodgingTotalBolts",
    0x0212: "LightningDodgingTotalDodges",
    0x0214: "LightningDodgingHighestConsecutiveDodges",
    0x024C: "BlitzballWakkaPowerProgress",
    0x0A00: "GameMoment",           # == fahrenheit story_progress@Fh 0xBEC (derived)
    0x0A34: "GilLentToOAka",
    0x0A38: "MacalaniaPricesChosenForOAka",
    0x0A4A: "SaveSphereInstructionsSeen",
    0x0A60: "AlBhedPrimersCollectedCount",
    0x0A88: "BlitzballTeamPlayerCount",
    0x0A93: "JechtSpheresCollectedCount",
    0x0A95: "AirshipDestinationUnlocks",
    0x0A99: "CactuarGuardiansBeaten",
    0x0A9A: "AlBhedPrimersInstructionsSeen",
    0x0A9B: "RemiemRaceTreasureFlags",
    0x0A9D: "DarkValeforCompletionFlags",
    0x0A9E: "DarkIfritCompletionFlags",
    0x0A9F: "DarkIxionCompletionFlags",
    0x0AA0: "DarkShivaCompletionFlags",
    0x0AA1: "DarkBahamutCompletionFlags",
    0x0AA2: "DarkYojimboCompletionFlags",
    0x0AA3: "DarkAnimaCompletionFlags",
    0x0AA4: "DarkMagusSistersCompletionFlags",
    0x0AA5: "PenanceUnlockState",
    0x141A: "BlitzballTeamPlayers",
    0x1465: "BlitzballEnemyTeam",
    0x152A: "BlitzballPlayerContractDurations",
    0x1798: "BlitzballPlayerCostPerGame",
    0x1810: "BlitzballLeaguePrizeIndex",
    0x1816: "BlitzballTournamentPrizeIndex",
    0x181C: "BlitzballLeagueTopScorerPrizeIndex",
    0x181E: "BlitzballTournamentTopScorerPrizeIndex",
    # Newly identified during this mining run (Fh anchors, see doc §5):
    0x1266: "BlitzTechniquesArray",        # Fh 0x1452, 60x5 u8 (FFXED Technique 1-5)
    0x1392: "BlitzTechniqueCapacity",      # Fh 0x157E, 60xu8 (IDA memset @0x784660)
    0x13CE: "BlitzPlayerLevel",            # Fh 0x15BA, 60xu8 (FFXED Level)
    0x1566: "BlitzGamesWon",               # Fh 0x1752, u16 (FFXED Games Won)
    0x1568: "BlitzPlayerExperience",       # Fh 0x1754, 60xu16 (FFXED Experience)
    0x1820: "BlitzTechPages1",             # Fh 0x1A0C (fahrenheit uncovered tech page 1)
    0x1910: "BlitzTechPages2",             # Fh 0x1AFC (fahrenheit uncovered tech page 2)
}

# Save regions in Fh (save_ram) coordinates. Order matters (first match wins).
REGIONS = [
    ("header_state",  0x000, 0x04C, "room/spawn/affection header state"),
    ("scene_bits",    0x04C, 0x09C, "per-scene flag bitfield (20 u32, 640 bits) — native-call only, slots cannot reach (needs slot < 0)"),
    ("pre_g2",        0x09C, 0x279, "between scene bits and G2 story flags"),
    ("g2_story",      0x279, 0x400, "G2 named story/quest fields (fahrenheit progression_flags_*)"),
    ("gap_g2_g3",     0x400, 0x5EC, "gap between G2 and G3"),
    ("g3_story",      0x5EC, 0xCD8, "G3 named story/quest fields"),
    ("gap3_lower",    0xCD8, 0x11EC, "GAP3-lower 'ATEL workarea' (file 0x0D18-0x122B) — THE MISSION TARGET"),
    ("gap3_blitz",    0x11EC, 0x1984, "GAP3-blitz state (file 0x122C-0x19C4)"),
    ("blitz_tail",    0x1984, 0x21EC, "fahrenheit BlitzballData (salary/prizes/tech pages), file 0x19C4+"),
    ("post_dict",     0x21EC, 1 << 24, "beyond the ATEL dictionary (SG table area+) — would be out-of-dictionary writes"),
]
# Mission ranges called out explicitly in the report:
MISSION_RANGES = {"scene_bits", "gap3_lower"}


def region_of(fh):
    for name, lo, hi, _doc in REGIONS:
        if lo <= fh < hi:
            return name
    return "post_dict"


def u16(b, o):
    return b[o] | (b[o + 1] << 8)


def u32(b, o):
    return b[o] | (b[o + 1] << 8) | (b[o + 2] << 16) | (b[o + 3] << 24)


class EbpParseError(Exception):
    pass


def parse_ebp_chunk0(data, path):
    """EV01 container -> (start, end) of chunk slot 0 (ATEL blob)."""
    if len(data) < 0x40 or data[:4] != b"EV01":
        raise EbpParseError("bad magic")
    offs, i = [], 4
    while i + 4 <= len(data):
        v = u32(data, i)
        if v == 0xFFFFFFFF:
            break
        offs.append(v)
        i += 4
    if not offs or offs[0] != 0x40:
        raise EbpParseError("chunk table malformed")
    eof = offs[-1]
    present = [o for o in offs[:-1] if o]
    if not present or present[0] != 0x40:
        raise EbpParseError("chunk 0 absent")
    start = 0x40
    end = present[1] if len(present) > 1 else eof
    if end <= start or end > len(data):
        raise EbpParseError("chunk 0 empty/out of range")
    return start, end


def parse_atel_blob(blob, path):
    """ATEL blob -> dict with header fields, var descriptors, and code bounds."""
    if len(blob) < 0x40:
        raise EbpParseError("blob too small")
    code_len = u32(blob, 0x00)
    total_len = u32(blob, 0x10)
    script_start = u32(blob, 0x30)
    worker_count = u16(blob, 0x36)
    if worker_count == 0 or 0x38 + 4 * worker_count > len(blob):
        worker_count = 1  # defensive: only worker[0] is needed here
    w0 = u32(blob, 0x38)
    if w0 <= 0 or w0 + 0x28 > len(blob):
        raise EbpParseError("worker[0] descriptor out of range")
    vars_off = u32(blob, w0 + 0x14)
    int_off = u32(blob, w0 + 0x18)  # var table ends where int-pool table starts
    var_count = 0
    if vars_off and int_off > vars_off and int_off <= len(blob):
        var_count = (int_off - vars_off) // 8
    vars = []
    for k in range(var_count):
        lo = u32(blob, vars_off + 8 * k)
        hi = u32(blob, vars_off + 8 * k + 4)
        vars.append((lo, hi))
    return {
        "code_len": code_len, "total_len": total_len,
        "script_start": script_start, "worker_count": worker_count,
        "var_count": var_count, "vars": vars,
    }


def walk_code(blob, script_start, code_len):
    """Linear opcode walk. Returns (accesses, closed_exactly, op_histogram).

    accesses: list of (pc, opcode, operand). closed_exactly: the walk consumed
    exactly code_len bytes (self-validation of the bit7 length rule)."""
    i, end = script_start, script_start + code_len
    accesses, hist = [], Counter()
    closed = False
    if code_len > 0 and end <= len(blob):
        while i < end:
            op = blob[i]
            if op & 0x80:
                if i + 3 > end:
                    break
                hist[op] += 1
                operand = blob[i + 1] | (blob[i + 2] << 8)
                if op in VAR_OPS:
                    accesses.append((i - script_start, op, operand))
                i += 3
            else:
                hist[op] += 1
                i += 1
        closed = i == end
    return accesses, closed, hist


def mine(root, top_n):
    files = []
    for dirpath, _dirnames, filenames in os.walk(root):
        for fn in filenames:
            if fn.lower().endswith(".ebp"):
                files.append(os.path.join(dirpath, fn))
    files.sort()

    stats = {
        "files_found": len(files),
        "files_parsed": 0,
        "files_walk_closed": 0,
        "parse_errors": Counter(),
        "var_descriptors": Counter(),      # by location id
        "var_op_hist": Counter(),          # by opcode byte
        "saveslots": Counter(),            # SaveData slot -> n accesses
        "saveslot_files": defaultdict(set),  # slot -> set of .ebp names
        "saveslot_ops": defaultdict(Counter),  # slot -> per-op-class counts
        "slot_meta": {},                   # slot -> (type, count) seen (mode)
        "region_files": defaultdict(set),  # region -> files touching it
        "region_slots": defaultdict(set),  # region -> unique slots
        "region_accesses": Counter(),      # region -> n access ops (base-slot attribution)
        "range_reads": Counter(),
        "range_stores": Counter(),
        "per_file": [],                    # (name, var_total, sd_vars, sd_accesses)
        "bad_var_index": 0,
        "min_slot": None,
        "max_slot": 0,
        "max_fh_span": 0,
    }

    for path in files:
        name = os.path.basename(path)
        try:
            with open(path, "rb") as fh:
                data = fh.read()
            s, e = parse_ebp_chunk0(data, path)
            blob = data[s:e]
            at = parse_atel_blob(blob, path)
        except EbpParseError as ex:
            stats["parse_errors"][str(ex)] += 1
            continue
        stats["files_parsed"] += 1

        for lo, _hi in at["vars"]:
            stats["var_descriptors"][(lo >> 25) & 7] += 1

        accesses, closed, _hist = walk_code(blob, at["script_start"], at["code_len"])
        stats["files_walk_closed"] += closed

        sd_access_n = 0
        sd_vars = set()
        for pc, op, vi in accesses:
            stats["var_op_hist"][op] += 1
            if vi >= at["var_count"]:
                stats["bad_var_index"] += 1
                continue
            lo, hi = at["vars"][vi]
            if ((lo >> 25) & 7) != 0:  # not SaveData
                continue
            slot = lo & 0xFFFFFF
            typ = lo >> 28
            count = hi & 0xFFFF
            _mn, cls = VAR_OPS[op]
            fh_off = slot + SAVEDATA_BASE
            span_end = fh_off + max(count, 1) * TYPE_STRIDE.get(typ, 1)
            stats["saveslots"][slot] += 1
            stats["saveslot_files"][slot].add(name)
            stats["saveslot_ops"][slot][cls] += 1
            # keep the most-common (type,count) seen for the slot
            key = (typ, count)
            stats["slot_meta"].setdefault(slot, Counter())[key] += 1
            if stats["min_slot"] is None or slot < stats["min_slot"]:
                stats["min_slot"] = slot
            if slot > stats["max_slot"]:
                stats["max_slot"] = slot
            if span_end > stats["max_fh_span"]:
                stats["max_fh_span"] = span_end
            # base-slot region attribution (per access op)
            r = region_of(fh_off)
            stats["region_files"][r].add(name)
            stats["region_slots"][r].add(slot)
            stats["region_accesses"][r] += 1
            if cls == "read":
                stats["range_reads"][r] += 1
            elif cls == "store":
                stats["range_stores"][r] += 1
            sd_access_n += 1
            sd_vars.add(slot)

        stats["per_file"].append(
            (name, at["var_count"], len(sd_vars), sd_access_n))

    return files, stats


def fmt_hex(v):
    return f"0x{v:04X}"


def main():
    ap = argparse.ArgumentParser(
        description="EV01 (.ebp) SaveData-variable miner: PUSHV/POPV-family "
                    "operands -> save_ram/Fh offsets, histograms and per-region "
                    "script counts over the extracted event corpus.")
    ap.add_argument("--root", default=DEFAULT_ROOT, help="ffx_ps2 extraction root")
    ap.add_argument("--json", metavar="OUT", help="optional deterministic JSON dump")
    ap.add_argument("--top", type=int, default=25, help="top-offsets table size")
    args = ap.parse_args()

    files, st = mine(args.root, args.top)

    print("=" * 78)
    print("EV01 SaveData mining — PUSHV/POPV-family operands over .ebp corpus")
    print("=" * 78)
    print(f"root: {args.root}")
    print(f"files found/parsed: {st['files_found']} / {st['files_parsed']}"
          + (f"  (errors: {dict(st['parse_errors'])})" if st["parse_errors"] else ""))
    print(f"bytecode walks closing exactly on codeLen: {st['files_walk_closed']}"
          f" / {st['files_parsed']}")
    print(f"variable descriptors by location: "
          f"{ {LOCATION_NAMES.get(k, k): v for k, v in sorted(st['var_descriptors'].items())} }")
    print(f"variable-access opcodes seen: "
          f"{ {f'{k:02X} {VAR_OPS[k][0]}': v for k, v in sorted(st['var_op_hist'].items())} }")
    print(f"out-of-range var operands (must be 0): {st['bad_var_index']}")
    print(f"SaveData accesses total: {sum(st['saveslots'].values())}"
          f" | unique slots: {len(st['saveslots'])}"
          f" | slot range: {fmt_hex(st['min_slot'] or 0)}..{fmt_hex(st['max_slot'])}"
          f" | max Fh span end: {fmt_hex(st['max_fh_span'])}")

    print()
    print("-" * 78)
    print(f"REGION TABLE (Fh = slot + 0x{SAVEDATA_BASE:X}; base-slot attribution)")
    print("-" * 78)
    print(f"{'region':<12} {'Fh range':<17} {'scripts':>8} {'slots':>6} {'accesses':>9}"
          f" {'reads':>8} {'stores':>8}")
    for name, lo, hi, _doc in REGIONS:
        nf = len(st["region_files"].get(name, ()))
        ns = len(st["region_slots"].get(name, ()))
        na = st["region_accesses"].get(name, 0)
        rd = st["range_reads"].get(name, 0)
        wr = st["range_stores"].get(name, 0)
        rng = f"{fmt_hex(lo)}..{fmt_hex(hi if hi < (1 << 24) else 0x21EC+0x1000)}"
        star = "  <-- MISSION" if name in MISSION_RANGES else ""
        print(f"{name:<12} {rng:<17} {nf:>8} {ns:>6} {na:>9} {rd:>8} {wr:>8}{star}")
    print()
    print("NOTE scene_bits [0x4C,0x9C): SaveData slots cannot reach it "
          "(would need slot < 0); per-scene bits are set via native calls "
          "(FFX_FieldVM_Set/Clear/TestSceneStateBit).")

    print()
    print("-" * 78)
    print(f"TOP {args.top} SaveData slots by access count")
    print("-" * 78)
    print(f"{'slot':>8} {'Fh':>8} {'file+0x40':>10} {'type':>5} {'cnt':>4}"
          f" {'accesses':>9} {'rd':>7} {'wr':>7} {'ad':>6}  {'#ebp':>5}  name")
    for slot, n in st["saveslots"].most_common(args.top):
        meta = st["slot_meta"][slot].most_common(1)[0][0]
        typ, cnt = meta
        oc = st["saveslot_ops"][slot]
        name = SLOT_NAMES.get(slot, "")
        print(f"{fmt_hex(slot):>8} {fmt_hex(slot + SAVEDATA_BASE):>8}"
              f" {fmt_hex(slot + SAVEDATA_BASE + 0x40):>10} {TYPE_NAMES.get(typ, '?'):>5}"
              f" {cnt:>4} {n:>9} {oc.get('read', 0):>7} {oc.get('store', 0):>7}"
              f" {oc.get('addr', 0):>6}  {len(st['saveslot_files'][slot]):>5}  {name}")

    print()
    print("-" * 78)
    print("GAP3-lower drill-down (Fh 0xCD8..0x11EB = file 0x0D18..0x122B, 'workarea')")
    print("-" * 78)
    gap3_slots = sorted(s for s in st["saveslots"]
                        if 0xCD8 <= s + SAVEDATA_BASE < 0x11EC)
    if not gap3_slots:
        print("NO SaveData slots map into GAP3-lower — zero PUSHV/POPV accesses")
        print("from the whole 397-file corpus touch Fh 0xCD8..0x11EB.")
    else:
        for slot in gap3_slots:
            fl = sorted(st["saveslot_files"][slot])
            print(f"slot {fmt_hex(slot)} Fh {fmt_hex(slot + SAVEDATA_BASE)}"
                  f" accesses={st['saveslots'][slot]} files({len(fl)}): "
                  + ", ".join(fl[:12]) + (" ..." if len(fl) > 12 else ""))

    print()
    print("-" * 78)
    print("Files with most SaveData accesses (top 15)")
    print("-" * 78)
    for name, nv, sdv, sda in sorted(st["per_file"], key=lambda x: -x[3])[:15]:
        print(f"{name:<28} vars={nv:>4} sd_vars={sdv:>3} sd_accesses={sda:>5}")

    if args.json:
        out = {
            "meta": {
                "tool": "research_tools/Atel/ev01_savevar_mining.py",
                "lane": "FFX-STRUCTURES/EV01-MINER",
                "date": "2026-09-14",
                "root": args.root,
                "savedata_base": SAVEDATA_BASE,
                "fh_note": "Fh = save_ram offset = file offset - 0x40 = slot + 0x1EC",
            },
            "totals": {
                "files_found": st["files_found"],
                "files_parsed": st["files_parsed"],
                "walks_closed": st["files_walk_closed"],
                "parse_errors": dict(st["parse_errors"]),
                "var_descriptors_by_location": {
                    LOCATION_NAMES.get(k, k): v
                    for k, v in sorted(st["var_descriptors"].items())},
                "var_op_histogram": {f"{k:02X}": v
                                     for k, v in sorted(st["var_op_hist"].items())},
                "bad_var_index": st["bad_var_index"],
                "savedata_accesses": sum(st["saveslots"].values()),
                "unique_slots": len(st["saveslots"]),
                "min_slot": st["min_slot"], "max_slot": st["max_slot"],
            },
            "regions": {
                name: {"fh_lo": lo, "fh_hi": hi if hi < (1 << 24) else None,
                       "doc": doc,
                       "files": len(st["region_files"].get(name, ())),
                       "slots": len(st["region_slots"].get(name, ())),
                       "accesses": st["region_accesses"].get(name, 0),
                       "reads": st["range_reads"].get(name, 0),
                       "stores": st["range_stores"].get(name, 0)}
                for name, lo, hi, doc in REGIONS},
            "slots": {
                str(slot): {
                    "fh": slot + SAVEDATA_BASE,
                    "file": slot + SAVEDATA_BASE + 0x40,
                    "name": SLOT_NAMES.get(slot, ""),
                    "type": TYPE_NAMES.get(st["slot_meta"][slot].most_common(1)[0][0][0], "?"),
                    "elem_count": st["slot_meta"][slot].most_common(1)[0][0][1],
                    "accesses": st["saveslots"][slot],
                    "reads": st["saveslot_ops"][slot].get("read", 0),
                    "stores": st["saveslot_ops"][slot].get("store", 0),
                    "addr": st["saveslot_ops"][slot].get("addr", 0),
                    "ebp_files": sorted(st["saveslot_files"][slot]),
                }
                for slot in sorted(st["saveslots"])},
        }
        with open(args.json, "w", encoding="utf-8") as fh:
            json.dump(out, fh, indent=1, sort_keys=True, ensure_ascii=False)
        print(f"\nJSON dump written: {args.json}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
