#!/usr/bin/env python3
"""
ATEL Bytecode Disassembler for FFX.exe
=======================================
Disassembles ATEL bytecode found in FFX binary data files (.bin, .battle, etc).

ATEL (Atelier) is FFX's stack-based bytecode VM with 5 channels:
  Channel 0 (0xBxxx): Movie — cutscenes, FMV, subtitles (466 opcodes)
  Channel 1 (0x7xxx): Battle — AI scripts, motion, camera (135 opcodes)
  Channel 2 (0x8xxx): Map — field graphics binding (38 opcodes)
  Channel 3 (0xDxxx): AbilityMap — Sphere Grid (2 opcodes)

Each opcode has 5 calling-convention variants:
  CALL (0), STATUS (1), INTRET (2), FLOATRET (3), CALLPOPA (4)

Binary format (per instruction):
  byte 0-1: opcode (16-bit LE) — high nibble = channel, low byte = opcode ID
  byte 2:   convention index (0-4)
  byte 3+:  optional operands (variable, decoded per-opcode)

Funcspace table at 0xC40E20 in FFX.exe maps [channel][opcode][convention] -> handler.

Usage:
    python atel_disassembler.py <file.bin>
    python atel_disassembler.py --hex 0xB000,0xB001,0xB004
    python atel_disassembler.py --filter battle --verbose file.bin
    python atel_disassembler.py --filter movie --hex 0xB029 file.bin
"""

import struct
import sys
import argparse
from typing import Dict, List, Optional, Tuple
from dataclasses import dataclass
from enum import IntEnum


class ATELChannel(IntEnum):
    MOVIE = 0xB
    BATTLE = 0x7
    MAP = 0x8
    ABILITY_MAP = 0xD


class Convention(IntEnum):
    CALL = 0
    STATUS = 1
    INTRET = 2
    FLOATRET = 3
    CALLPOPA = 4


CONVENTION_NAMES = {
    0: "CALL",
    1: "STATUS",
    2: "INTRET",
    3: "FLOATRET",
    4: "CALLPOPA",
}

CHANNEL_NAMES = {
    0xB: "Movie",
    0x7: "Battle",
    0x8: "Map",
    0xD: "AbilityMap",
}

# --- ATEL Battle opcodes (channel 1, 0x70xx) from batch_0020 ---

BATTLE_OPCODES: Dict[int, str] = {
    # Read / Getter
    0x7000: "ReadMoveElementProperty",
    # Terminate
    0x7001: "BtlTerminateEffect",
    0x7002: "BtlGetCalcResult",
    # Item / MP / Misc
    0x7003: "GiveItem",
    0x7004: "BtlUseChrMpLimit",
    # Motion control
    0x7005: "BtlStartMotion",
    0x7006: "StopMotion",
    # More getters
    0x7007: "BtlGetCalcResult2",
    # Terminate
    0x7008: "BtlTerminateDeath",
    # Status check
    0x7009: "DoesChrKnowCommand",
    # Set ops (BtlSet family, ~22 functions)
    0x7010: "BtlSetMotionSignal",
    0x7011: "BtlSetDamageMotion",
    0x7012: "BtlSetTexAnime",
    0x7013: "BtlSetEnMapID",
    0x7014: "SetGravity",
    0x7015: "BtlCheckMotion",
    0x7016: "BtlSetSub1",
    0x7017: "BtlSetSub2",
    0x7018: "BtlSetSub3",
    0x7019: "BtlSetSub4",
    0x701A: "BtlSetSub5",
    0x701B: "BtlSetSub6",
    # Direction ops (BtlDir family)
    0x7020: "BtlDirTarget",
    0x7021: "BtlSetAppear",
    0x7022: "BtlSetBodyHit",
    0x7023: "BtlDirBasic",
    0x7024: "SetSelfFloating",
    0x7025: "SetHeight",
    0x7026: "BtlDirSub1",
    0x7027: "BtlDirSub2",
    0x7028: "BtlDirSub3",
    0x7029: "BtlDirSub4",
    # Movement (BtlMove family)
    0x7030: "BtlSetNormalEffect",
    0x7031: "BtlSetHitEffect",
    0x7032: "BtlMove",
    0x7033: "BtlMoveAttack",
    0x7034: "BtlMoveSub1",
    0x7035: "BtlMoveSub2",
    0x7036: "BtlMoveSub3",
    0x7037: "BtlMoveSub4",
    # Command dispatch (AI decision)
    0x7040: "ChosenCommand",
    0x7041: "PerformCommand",
    0x7042: "ForcePerformCommand",
    0x7043: "OverrideDeathAnimationWithCommand",
    0x7044: "OverrideAttemptedCommand",
    0x7045: "BtlMoveVmWrapper",
    # Debug / Flow
    0x7050: "Print",
    0x7051: "EndBattle",
    # Scene runners
    0x7060: "runBtlSceneA",
    0x7061: "runBtlSceneB",
    # Request ops
    0x7070: "camReq",
    0x7071: "btlReqVoice",
    0x7072: "btlSoundEffect",
    0x7073: "btlReqMotion",
    # Camera setup
    0x7074: "camReqSetup",
    # Sound
    0x7075: "BtlSoundFade",
    0x7076: "BtlSoundRegister",
    0x7077: "BtlSoundSetParam",
    0x7078: "BtlSoundStop",
    # Check ops
    0x7080: "IsCounterattackAllowed",
    0x7081: "BtlCheckMove",
    0x7082: "BtlCheckBtlPos",
    0x7083: "BtlCheckDirFlag",
    0x7084: "BtlCheckDistance",
    # Getters
    0x7090: "BtlGetMoveFlag",
    0x7091: "BtlGetReflect",
    # Motion speed
    0x70A0: "BtlResetMotionSpeed",
    # Spline
    0x70F0: "GetSplineGlobalDataPtr",
}

# --- ATEL Movie opcodes (channel 0, 0xBxxx) from batch_0013 ---

MOVIE_OPCODES: Dict[int, str] = {
    0xB000: "InitMovieState",
    0xB001: "ClearArgBuffer",
    0xB002: "MovieFunc_B002",
    0xB003: "MovieFunc_B003",
    0xB004: "ResetVideoFlag",
    0xB005: "MovieFunc_B005",
    0xB006: "MovieFunc_B006",
    0xB007: "MovieFunc_B007",
    0xB008: "DebugOverlayClear",
    0xB009: "MovieFunc_B009",
    0xB010: "MovieFunc_B010",
    0xB011: "MovieFunc_B011",
    0xB012: "MovieFunc_B012",
    0xB029: "LoadFmv",
    0xB02A: "MovieFunc_B02A",
    0xB02B: "MovieFunc_B02B",
    0xB02C: "SetSubtitleActive",
    0xB030: "MovieFunc_B030",
    0xB040: "MovieFunc_B040",
    0xB050: "MovieFunc_B050",
    0xB060: "MovieFunc_B060",
    0xB068: "MovieFunc_B068",
}

# --- ATEL Map opcodes (channel 2, 0x8xxx) ---

MAP_OPCODES: Dict[int, str] = {
    0x804B: "MapFunc_804B",
    0x804C: "MapFunc_804C",
    0x804D: "MapFunc_804D",
    0x8050: "MapFunc_8050",
}

# --- ATEL AbilityMap opcodes (channel 3, 0xDxxx) ---

ABILITY_MAP_OPCODES: Dict[int, str] = {
    0xD000: "AbmapFuncD000_CALL",
    0xD020: "AbmapFuncD020_CALLPOPA",
}

ALL_OPCODES: Dict[int, str] = {}
ALL_OPCODES.update(BATTLE_OPCODES)
ALL_OPCODES.update(MOVIE_OPCODES)
ALL_OPCODES.update(MAP_OPCODES)
ALL_OPCODES.update(ABILITY_MAP_OPCODES)


@dataclass
class ATELInstruction:
    offset: int
    raw_bytes: bytes
    opcode: int
    channel: int
    opcode_id: int
    convention: int
    name: str
    operands: bytes = b""


def decode_opcode(word: int) -> Tuple[int, int]:
    """Extract channel (high nibble) and opcode_id (low byte) from 16-bit opcode."""
    channel = (word >> 12) & 0xF
    opcode_id = word & 0xFF
    # For Battle (0x7xxx), the full word is the opcode
    if channel == 0x7:
        opcode_id = word & 0x00FF
    return channel, opcode_id


def get_opcode_name(channel: int, opcode_id: int, full_opcode: int) -> str:
    """Look up the human-readable name for an opcode."""
    # Try full opcode first (for Battle which uses 0x70xx as flat IDs)
    if full_opcode in ALL_OPCODES:
        return ALL_OPCODES[full_opcode]
    # Fall back to low byte lookup in channel-specific table
    table = {
        0xB: MOVIE_OPCODES,
        0x7: BATTLE_OPCODES,
        0x8: MAP_OPCODES,
        0xD: ABILITY_MAP_OPCODES,
    }.get(channel, {})
    if opcode_id in table:
        return table[opcode_id]
    # Check all tables with full opcode
    for tbl in [BATTLE_OPCODES, MOVIE_OPCODES, MAP_OPCODES, ABILITY_MAP_OPCODES]:
        if full_opcode in tbl:
            return tbl[full_opcode]
    return f"Func{full_opcode:04X}"


def disassemble_bytes(data: bytes, base_offset: int = 0) -> List[ATELInstruction]:
    """
    Scan raw bytes for ATEL opcode patterns and decode them.

    ATEL instructions are variable-length. The core pattern is:
      2 bytes: opcode (LE uint16) — high nibble = channel, low byte = opcode ID
      1 byte:  convention (0-4)
      N bytes: operands (variable, typically 0-4 bytes per operand)

    Since we scan raw binary (not guaranteed bytecode), we look for
    known opcode patterns and decode what follows.
    """
    instructions: List[ATELInstruction] = []
    i = 0
    data_len = len(data)

    while i < data_len - 2:
        word = struct.unpack_from("<H", data, i)[0]
        channel = (word >> 12) & 0xF

        # Only consider valid ATEL channels
        if channel not in (0x7, 0x8, 0xB, 0xD):
            i += 1
            continue

        # Check if this opcode is known
        opcode_name = get_opcode_name(channel, word & 0xFF, word)
        is_known = not opcode_name.startswith("Func") or word in ALL_OPCODES

        # For unknown opcodes in valid channels, still decode if convention byte is valid
        if i + 2 < data_len:
            conv_byte = data[i + 2]
            if conv_byte <= 4:
                conv_name = CONVENTION_NAMES[conv_byte]
                # Read optional operands (next 0-4 bytes that look like data)
                operand_end = min(i + 7, data_len)
                operands = data[i + 3:operand_end]

                raw = data[i:i + 3]
                inst = ATELInstruction(
                    offset=base_offset + i,
                    raw_bytes=raw,
                    opcode=word,
                    channel=channel,
                    opcode_id=word & 0xFF,
                    convention=conv_byte,
                    name=opcode_name,
                    operands=operands,
                )
                instructions.append(inst)
                i += 3  # Advance past opcode + convention
                continue

        i += 1

    return instructions


def format_hexdump(data: bytes, offset: int = 0, width: int = 16) -> str:
    """Format bytes as hex dump lines."""
    lines = []
    for i in range(0, len(data), width):
        chunk = data[i:i + width]
        hex_str = " ".join(f"{b:02X}" for b in chunk)
        ascii_str = "".join(chr(b) if 32 <= b < 127 else "." for b in chunk)
        lines.append(f"  {offset + i:08X}  {hex_str:<{width * 3}}  {ascii_str}")
    return "\n".join(lines)


def format_instruction(inst: ATELInstruction, verbose: bool = False) -> str:
    """Format a single ATEL instruction for display."""
    channel_name = CHANNEL_NAMES.get(inst.channel, f"Ch{inst.channel}")
    conv_name = CONVENTION_NAMES.get(inst.convention, f"?{inst.convention}")

    line = f"  {inst.offset:08X}  {inst.opcode:04X}  {channel_name:12s}  {inst.name:40s}  {conv_name}"

    if verbose and inst.operands:
        op_hex = " ".join(f"{b:02X}" for b in inst.operands)
        line += f"  [{op_hex}]"

    return line


def filter_by_channel(instructions: List[ATELInstruction], channel_filter: str) -> List[ATELInstruction]:
    """Filter instructions by channel name."""
    channel_map = {
        "movie": 0xB,
        "battle": 0x7,
        "map": 0x8,
        "abilitymap": 0xD,
        "ability": 0xD,
        "abmap": 0xD,
    }
    target = channel_map.get(channel_filter.lower())
    if target is None:
        print(f"Unknown channel filter: {channel_filter}", file=sys.stderr)
        print(f"Valid filters: {', '.join(channel_map.keys())}", file=sys.stderr)
        sys.exit(1)
    return [i for i in instructions if i.channel == target]


def filter_by_hex(instructions: List[ATELInstruction], hex_values: List[int]) -> List[ATELInstruction]:
    """Filter instructions to only those matching specific hex opcode values."""
    return [i for i in instructions if i.opcode in hex_values]


def scan_for_opcodes(data: bytes, base_offset: int = 0) -> List[ATELInstruction]:
    """
    Aggressive scan: look for any 2-byte LE value in known ATEL ranges
    followed by a valid convention byte (0-4).
    """
    instructions = []
    data_len = len(data)
    seen = set()

    # Known opcode full values
    known_full = set(ALL_OPCODES.keys())

    i = 0
    while i < data_len - 2:
        word = struct.unpack_from("<H", data, i)[0]
        channel = (word >> 12) & 0xF

        if channel in (0x7, 0x8, 0xB, 0xD) and i + 2 < data_len:
            conv = data[i + 2]
            if conv <= 4:
                is_known = word in known_full
                if not is_known:
                    # Check if low byte matches any known opcode
                    low = word & 0xFF
                    tbl = {
                        0xB: MOVIE_OPCODES,
                        0x7: BATTLE_OPCODES,
                        0x8: MAP_OPCODES,
                        0xD: ABILITY_MAP_OPCODES,
                    }.get(channel, {})
                    is_known = low in tbl

                if is_known:
                    opcode_name = get_opcode_name(channel, word & 0xFF, word)
                    operands = data[i + 3:min(i + 7, data_len)]
                    inst = ATELInstruction(
                        offset=base_offset + i,
                        raw_bytes=data[i:i + 3],
                        opcode=word,
                        channel=channel,
                        opcode_id=word & 0xFF,
                        convention=conv,
                        name=opcode_name,
                        operands=operands,
                    )
                    instructions.append(inst)
        i += 1

    return instructions


def main():
    parser = argparse.ArgumentParser(
        description="ATEL Bytecode Disassembler for FFX.exe",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  %(prog)s file.bin                    Disassemble ATEL opcodes from binary
  %(prog)s --filter battle file.bin    Show only Battle opcodes
  %(prog)s --filter movie file.bin     Show only Movie opcodes
  %(prog)s --hex 0xB029,0xB004 file.bin  Show only specific opcodes
  %(prog)s --scan file.bin             Aggressive scan for all ATEL patterns
  %(prog)s --hexdump 0 64 file.bin     Show raw hex dump of first 64 bytes
  %(prog)s --stats file.bin            Show opcode frequency statistics
        """,
    )
    parser.add_argument("file", nargs="?", help="Binary file to disassemble")
    parser.add_argument("--filter", choices=["movie", "battle", "map", "abilitymap", "ability", "abmap"],
                        help="Filter by ATEL channel")
    parser.add_argument("--hex", help="Filter by hex opcode values (comma-separated, e.g. 0xB029,0xB004)")
    parser.add_argument("--scan", action="store_true", help="Aggressive scan for all ATEL patterns")
    parser.add_argument("--verbose", "-v", action="store_true", help="Show operand bytes")
    parser.add_argument("--hexdump", nargs=2, type=lambda x: int(x, 0),
                        metavar=("OFFSET", "LENGTH"), help="Show hex dump at offset/length")
    parser.add_argument("--stats", action="store_true", help="Show opcode frequency statistics")
    parser.add_argument("--offset", type=lambda x: int(x, 0), default=0,
                        help="Base offset for address display (default: 0)")

    args = parser.parse_args()

    if not args.file and not args.hex:
        parser.print_help()
        sys.exit(1)

    # Hex-only mode (no file needed)
    if args.hex and not args.file:
        hex_vals = [int(x.strip(), 16) for x in args.hex.split(",")]
        for val in hex_vals:
            channel = (val >> 12) & 0xF
            opcode_id = val & 0xFF
            name = get_opcode_name(channel, opcode_id, val)
            ch_name = CHANNEL_NAMES.get(channel, f"Ch{channel}")
            print(f"  0x{val:04X}  {ch_name:12s}  {name}")
        return

    # Read file
    try:
        with open(args.file, "rb") as f:
            data = f.read()
    except FileNotFoundError:
        print(f"File not found: {args.file}", file=sys.stderr)
        sys.exit(1)
    except PermissionError:
        print(f"Permission denied: {args.file}", file=sys.stderr)
        sys.exit(1)

    print(f"ATEL Disassembler — FFX.exe Bytecode")
    print(f"File: {args.file} ({len(data)} bytes)")
    print(f"{'=' * 90}")

    # Hex dump mode
    if args.hexdump:
        off, length = args.hexdump
        end = min(off + length, len(data))
        chunk = data[off:end]
        print(format_hexdump(chunk, off))
        return

    # Disassemble
    if args.scan:
        instructions = scan_for_opcodes(data, args.offset)
    else:
        instructions = disassemble_bytes(data, args.offset)

    # Apply filters
    if args.filter:
        instructions = filter_by_channel(instructions, args.filter)

    if args.hex:
        hex_vals = [int(x.strip(), 16) for x in args.hex.split(",")]
        instructions = filter_by_hex(instructions, hex_vals)

    if not instructions:
        print("No ATEL instructions found with current filters.")
        # Try a raw scan to hint
        raw_count = sum(1 for i in range(len(data) - 2)
                        if (data[i + 1] >> 4) & 0xF in (0x7, 0x8, 0xB, 0xD))
        if raw_count > 0:
            print(f"  ({raw_count} potential ATEL word patterns found; try --scan)")
        return

    # Stats mode
    if args.stats:
        from collections import Counter
        opcode_counts = Counter()
        channel_counts = Counter()
        conv_counts = Counter()
        for inst in instructions:
            opcode_counts[f"0x{inst.opcode:04X} {inst.name}"] += 1
            channel_counts[CHANNEL_NAMES.get(inst.channel, f"Ch{inst.channel}")] += 1
            conv_counts[CONVENTION_NAMES[inst.convention]] += 1

        print(f"\nOpcode Frequency (top 30):")
        for name, count in opcode_counts.most_common(30):
            print(f"  {count:5d}  {name}")

        print(f"\nChannel Distribution:")
        for ch, count in channel_counts.most_common():
            print(f"  {count:5d}  {ch}")

        print(f"\nConvention Distribution:")
        for conv, count in conv_counts.most_common():
            print(f"  {count:5d}  {conv}")

        print(f"\nTotal: {len(instructions)} instructions")
        return

    # Normal disassembly listing
    print(f"\n  {'Offset':8s}  {'Opcode':6s}  {'Channel':12s}  {'Name':40s}  {'Convention'}")
    print(f"  {'-' * 8}  {'-' * 6}  {'-' * 12}  {'-' * 40}  {'-' * 10}")

    for inst in instructions:
        print(format_instruction(inst, verbose=args.verbose))

    print(f"\nTotal: {len(instructions)} instructions")


if __name__ == "__main__":
    main()
