#!/usr/bin/env python3
"""
PhyreEngine .phyre Universal Parser
===================================
Parses PhyreEngine cluster files (.phyre) from both PS3 (big-endian, PHYR magic)
and PC (little-endian, RYHP magic, DX11 renderer).

Format:
  Offset  Size  Field
  0x00    4B    Magic: "PHYR" (BE) or "RYHP" (LE)
  0x04    4B    Version: 88 (PS3) or 84 (PC)
  0x08    4B    Data size (BE on PS3, LE on PC)
  0x0C    4B    Renderer: "GCM\0" (PS3) or "DX11" (PC)
  0x10    ...   Platform-specific data follows

Detection:
  - Magic "PHYR" → PS3 format (big-endian, version 88)
  - Magic "RYHP" → PC format (little-endian, version 84)

Usage:
  python phyre_parser.py --file <.phyre file>
  python phyre_parser.py --dir <directory>
  python phyre_parser.py --compare <ps3.phyre> <pc.phyre>
"""

import os
import sys
import struct
import argparse
from pathlib import Path

MAGIC_PHYS = b'PHYR'  # PS3 big-endian
MAGIC_RYHP = b'RYHP'  # PC little-endian


def detect_endianness(header):
    """Detect endianness from magic."""
    if header[:4] == MAGIC_PHYS:
        return 'big', 'PHYR', 'GCM'
    elif header[:4] == MAGIC_RYHP:
        return 'little', 'RYHP', 'DX11'
    return None, None, None


def parse_header(data):
    """Parse .phyre file header."""
    if len(data) < 16:
        return None

    endian, magic, renderer = detect_endianness(data)
    if not endian:
        return None

    endian_char = '>' if endian == 'big' else '<'

    version = struct.unpack(f'{endian_char}I', data[4:8])[0]
    data_size = struct.unpack(f'{endian_char}I', data[8:12])[0]
    renderer_tag = data[12:16].decode('ascii', errors='ignore').strip('\x00')

    # Platform-specific data starts at offset 0x10
    platform_data = data[16:]

    return {
        'magic': magic,
        'endianness': endian,
        'version': version,
        'data_size': data_size,
        'renderer': renderer_tag,
        'platform_data_size': len(platform_data),
    }


def analyze_file(filepath):
    """Analyze a single .phyre file."""
    try:
        with open(filepath, 'rb') as f:
            data = f.read()
    except Exception as e:
        return None

    info = parse_header(data)
    if not info:
        return None

    info['path'] = str(filepath)
    info['file_size'] = len(data)
    info['file_size_match'] = info['data_size'] == len(data) - 16

    return info


def main():
    parser = argparse.ArgumentParser(description='PhyreEngine .phyre Universal Parser')
    parser.add_argument('--file', type=str, help='Single .phyre file')
    parser.add_argument('--dir', type=str, help='Directory to scan')
    parser.add_argument('--compare', type=str, nargs=2, help='Compare PS3 vs PC .phyre')
    parser.add_argument('--max', type=int, default=100)

    args = parser.parse_args()

    if args.compare:
        ps3_path, pc_path = args.compare
        ps3_info = analyze_file(ps3_path)
        pc_info = analyze_file(pc_path)

        if not ps3_info or not pc_info:
            print("Error: could not read both files")
            return

        print(f"{'Field':20s} {'PS3 (PHYR/BE)':20s} {'PC (RYHP/LE)':20s}")
        print("-" * 60)
        print(f"{'Version':20s} {ps3_info['version']:20d} {pc_info['version']:20d}")
        print(f"{'Data Size':20s} {ps3_info['data_size']:20d} {pc_info['data_size']:20d}")
        print(f"{'File Size':20s} {ps3_info['file_size']:20d} {pc_info['file_size']:20d}")
        print(f"{'Renderer':20s} {ps3_info['renderer']:20s} {pc_info['renderer']:20s}")
        print(f"{'Platform Data':20s} {ps3_info['platform_data_size']:20d} {pc_info['platform_data_size']:20d}")

    elif args.file:
        info = analyze_file(args.file)
        if not info:
            print("Error: not a valid .phyre file")
            return
        print(f"File: {info['path']}")
        print(f"File Size: {info['file_size']} bytes")
        print(f"Format: {info['magic']} ({info['endianness']}-endian)")
        print(f"Version: {info['version']}")
        print(f"Renderer: {info['renderer']}")
        print(f"Data Size: {info['data_size']} bytes")
        print(f"Size Match: {'YES' if info['file_size_match'] else 'MISMATCH'}")

    elif args.dir:
        dirpath = Path(args.dir)
        phyre_count = 0
        ps3_count = 0
        pc_count = 0

        for f in dirpath.rglob('*.phyre'):
            if phyre_count >= args.max:
                break
            info = analyze_file(str(f))
            if info:
                phyre_count += 1
                if info['endianness'] == 'big':
                    ps3_count += 1
                else:
                    pc_count += 1

        print(f"Scanned: {phyre_count} .phyre files")
        print(f"  PS3 (PHYR, big-endian): {ps3_count}")
        print(f"   PC (RYHP, little-endian): {pc_count}")

    else:
        parser.print_help()


if __name__ == '__main__':
    main()
