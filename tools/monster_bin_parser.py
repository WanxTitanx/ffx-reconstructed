#!/usr/bin/env python3
"""
FFX Monster .bin Parser
=======================
Parses FFX monster data files (ATEL bytecode scripts).

File types:
- monster1.bin, monster2.bin, monster3.bin: Kernel index tables
- _mXXX/mXXX.bin: Individual monster data (per-monster ATEL scripts)

Struct layout (from IDA decompilation of FFX_Btl_LoadMonsterBins):
- Header: 4 bytes (magic/version)
- Monster count: 2 bytes
- Per-monster entry: variable size (name, stats, ATEL script refs)

Usage:
    python monster_bin_parser.py <path_to_bin>
    python monster_bin_parser.py --kernel <path_to_monster1.bin>
    python monster_bin_parser.py --dir <path_to_mon_directory>
"""

import struct
import sys
import os
from pathlib import Path
from dataclasses import dataclass, field
from typing import List, Optional


@dataclass
class MonsterHeader:
    """Header of a monster .bin file."""
    magic: int = 0
    version: int = 0
    monster_count: int = 0
    data_offset: int = 0


@dataclass
class MonsterEntry:
    """A single monster entry in the kernel index."""
    index: int = 0
    name_offset: int = 0
    data_offset: int = 0
    data_size: int = 0
    stats_offset: int = 0
    ai_script_offset: int = 0


@dataclass
class MonsterStats:
    """Monster stats block (approximate from IDA analysis)."""
    hp: int = 0
    mp: int = 0
    strength: int = 0
    magic: int = 0
    defense: int = 0
    magic_def: int = 0
    agility: int = 0
    luck: int = 0
    evasion: int = 0
    magic_evasion: int = 0
    ap_value: int = 0
    gil_value: int = 0
    element_weakness: int = 0
    element_resist: int = 0
    element_immunity: int = 0
    status_resist: int = 0


class MonsterBinParser:
    """Parser for FFX monster .bin files."""

    # Known monster names from FFX (indexed by _mXXX directory number)
    MONSTER_NAMES = {
        0: "Sin", 1: "Sahagin", 2: "Garuda", 3: "Dual Horn",
        4: "Green Dragon", 5: "Valkyrie", 6: "Chimera", 7: "Machea",
        8: "Funguar", 9: "Ochu", 10: "Nooj", 11: "Gippal",
        12: "Baralai", 13: "Noora", 14: "Paine", 15: "Seymour",
        16: "Yunalesca", 17: "Brask", 18: "Jecht", 19: "Tidus",
    }

    def __init__(self, filepath: str):
        self.filepath = filepath
        self.data = None
        self.header = MonsterHeader()
        self.entries: List[MonsterEntry] = []

    def load(self) -> bool:
        """Load the binary file."""
        try:
            with open(self.filepath, 'rb') as f:
                self.data = f.read()
            return True
        except FileNotFoundError:
            print(f"Error: File not found: {self.filepath}")
            return False
        except Exception as e:
            print(f"Error loading file: {e}")
            return False

    def parse_header(self) -> MonsterHeader:
        """Parse the file header."""
        if not self.data or len(self.data) < 4:
            return self.header

        # Read first 4 bytes as header
        self.header.magic = struct.unpack_from('<I', self.data, 0)[0]

        # Try to detect format based on magic
        if self.header.magic == 0x00000001:
            # Kernel index format (monster1.bin)
            if len(self.data) >= 6:
                self.header.monster_count = struct.unpack_from('<H', self.data, 4)[0]
        elif self.header.magic == 0x00640000:
            # Individual monster format (mXXX.bin)
            self.header.version = (self.header.magic >> 16) & 0xFFFF
            self.header.monster_count = 1

        return self.header

    def parse_kernel_index(self) -> List[MonsterEntry]:
        """Parse kernel index file (monster1.bin)."""
        if not self.data:
            return []

        entries = []
        offset = 6  # Skip header (4 bytes magic + 2 bytes count)

        for i in range(self.header.monster_count):
            if offset + 16 > len(self.data):
                break

            entry = MonsterEntry()
            entry.index = i

            # Read entry fields (2-byte aligned)
            entry.name_offset = struct.unpack_from('<H', self.data, offset)[0]
            entry.data_offset = struct.unpack_from('<H', self.data, offset + 2)[0]
            entry.data_size = struct.unpack_from('<H', self.data, offset + 4)[0]
            entry.stats_offset = struct.unpack_from('<H', self.data, offset + 6)[0]
            entry.ai_script_offset = struct.unpack_from('<H', self.data, offset + 8)[0]

            entries.append(entry)
            offset += 16  # Each entry is 16 bytes

        self.entries = entries
        return entries

    def parse_monster_data(self) -> Optional[MonsterStats]:
        """Parse individual monster data file."""
        if not self.data or len(self.data) < 32:
            return None

        stats = MonsterStats()

        # Parse stats block (approximate offsets from IDA analysis)
        # These offsets are based on the monster data structure
        try:
            # HP is typically at offset 0x0E (14 bytes into data)
            stats.hp = struct.unpack_from('<H', self.data, 0x0E)[0]
            stats.mp = struct.unpack_from('<H', self.data, 0x10)[0]

            # Stats follow after HP/MP
            stats.strength = struct.unpack_from('<B', self.data, 0x14)[0]
            stats.magic = struct.unpack_from('<B', self.data, 0x15)[0]
            stats.defense = struct.unpack_from('<B', self.data, 0x16)[0]
            stats.magic_def = struct.unpack_from('<B', self.data, 0x17)[0]
            stats.agility = struct.unpack_from('<B', self.data, 0x18)[0]
            stats.luck = struct.unpack_from('<B', self.data, 0x19)[0]
            stats.evasion = struct.unpack_from('<B', self.data, 0x1A)[0]
            stats.magic_evasion = struct.unpack_from('<B', self.data, 0x1B)[0]

            # AP/Gil values
            stats.ap_value = struct.unpack_from('<H', self.data, 0x1C)[0]
            stats.gil_value = struct.unpack_from('<H', self.data, 0x1E)[0]

            # Element affinities (2 bytes each)
            stats.element_weakness = struct.unpack_from('<H', self.data, 0x20)[0]
            stats.element_resist = struct.unpack_from('<H', self.data, 0x22)[0]
            stats.element_immunity = struct.unpack_from('<H', self.data, 0x24)[0]
            stats.status_resist = struct.unpack_from('<H', self.data, 0x26)[0]

        except struct.error:
            pass  # Partial parse is OK

        return stats

    def extract_atel_script(self, offset: int, size: int) -> bytes:
        """Extract ATEL bytecode script from monster data."""
        if not self.data or offset + size > len(self.data):
            return b''
        return self.data[offset:offset + size]

    def scan_for_patterns(self) -> dict:
        """Scan for known patterns in the binary."""
        if not self.data:
            return {}

        patterns = {}

        # Look for ATEL bytecode patterns
        # ATEL opcodes start with specific byte sequences
        atel_markers = []
        for i in range(len(self.data) - 1):
            # ATEL Battle opcodes are in 0x70xx range
            byte1 = self.data[i]
            byte2 = self.data[i + 1] if i + 1 < len(self.data) else 0
            if byte1 == 0x70 and 0x00 <= byte2 <= 0xFF:
                atel_markers.append(i)

        patterns['atel_opcodes'] = atel_markers[:20]  # First 20 matches

        # Look for text strings (null-terminated ASCII)
        strings = []
        i = 0
        while i < len(self.data) - 1:
            if 0x20 <= self.data[i] < 0x7F and self.data[i + 1] == 0x00:
                # Start of a potential string
                j = i
                while j < len(self.data) and self.data[j] != 0x00:
                    j += 1
                if j - i > 2:  # Minimum string length
                    try:
                        s = self.data[i:j].decode('ascii', errors='ignore')
                        strings.append((i, s))
                    except:
                        pass
                i = j + 1
            else:
                i += 1

        patterns['strings'] = strings[:50]  # First 50 strings

        return patterns

    def print_hex_dump(self, offset: int = 0, length: int = 64):
        """Print hex dump of file content."""
        if not self.data:
            return

        end = min(offset + length, len(self.data))
        for i in range(offset, end, 16):
            hex_str = ' '.join(f'{b:02x}' for b in self.data[i:i+16])
            ascii_str = ''.join(chr(b) if 32 <= b < 127 else '.' for b in self.data[i:i+16])
            print(f'{i:08x}: {hex_str:<48s} {ascii_str}')

    def summary(self):
        """Print summary of parsed data."""
        print(f"\n{'='*60}")
        print(f"FFX Monster .bin Parser")
        print(f"{'='*60}")
        print(f"File: {self.filepath}")
        print(f"Size: {len(self.data) if self.data else 0} bytes")
        print(f"Magic: 0x{self.header.magic:08X}")
        print(f"Monster count: {self.header.monster_count}")

        if self.entries:
            print(f"\nKernel entries ({len(self.entries)}):")
            for entry in self.entries[:10]:
                print(f"  [{entry.index:3d}] name@0x{entry.name_offset:04X} "
                      f"data@0x{entry.data_offset:04X} size={entry.data_size} "
                      f"stats@0x{entry.stats_offset:04X} ai@0x{entry.ai_script_offset:04X}")

        # Scan for patterns
        patterns = self.scan_for_patterns()
        if patterns.get('atel_opcodes'):
            print(f"\nATEL opcode markers found: {len(patterns['atel_opcodes'])}")
            for addr in patterns['atel_opcodes'][:5]:
                print(f"  0x{addr:04X}")

        if patterns.get('strings'):
            print(f"\nStrings found: {len(patterns['strings'])}")
            for addr, s in patterns['strings'][:10]:
                print(f"  0x{addr:04X}: {s[:40]}")


def parse_kernel_directory(dirpath: str):
    """Parse all monster .bin files in a directory."""
    monster_dir = Path(dirpath)

    # Find kernel files
    kernel_files = list(monster_dir.glob('monster*.bin'))
    if kernel_files:
        print(f"\nFound {len(kernel_files)} kernel files:")
        for kf in kernel_files:
            parser = MonsterBinParser(str(kf))
            if parser.load():
                parser.parse_header()
                parser.parse_kernel_index()
                parser.summary()

    # Find individual monster directories
    mon_dirs = sorted([d for d in monster_dir.iterdir()
                      if d.is_dir() and d.name.startswith('_m')])

    if mon_dirs:
        print(f"\nFound {len(mon_dirs)} monster directories:")
        for md in mon_dirs[:5]:  # Show first 5
            bin_files = list(md.glob('*.bin'))
            for bf in bin_files:
                parser = MonsterBinParser(str(bf))
                if parser.load():
                    parser.parse_header()
                    stats = parser.parse_monster_data()
                    print(f"\n  {md.name}/{bf.name}:")
                    print(f"    Size: {len(parser.data)} bytes")
                    if stats:
                        print(f"    HP={stats.hp} MP={stats.mp} STR={stats.strength} "
                              f"DEF={stats.defense} AGI={stats.agility}")


def main():
    if len(sys.argv) < 2:
        print("Usage:")
        print("  python monster_bin_parser.py <file.bin>")
        print("  python monster_bin_parser.py --kernel <path_to_monster1.bin>")
        print("  python monster_bin_parser.py --dir <path_to_mon_directory>")
        return

    if sys.argv[1] == '--kernel':
        filepath = sys.argv[2] if len(sys.argv) > 2 else 'monster1.bin'
        parser = MonsterBinParser(filepath)
        if parser.load():
            parser.parse_header()
            parser.parse_kernel_index()
            parser.summary()
            parser.print_hex_dump(0, 128)

    elif sys.argv[1] == '--dir':
        dirpath = sys.argv[2] if len(sys.argv) > 2 else '.'
        parse_kernel_directory(dirpath)

    else:
        filepath = sys.argv[1]
        parser = MonsterBinParser(filepath)
        if parser.load():
            parser.parse_header()
            parser.parse_monster_data()
            parser.summary()
            parser.print_hex_dump(0, 128)


if __name__ == '__main__':
    main()
