#!/usr/bin/env python3
"""
FFX File Format Scanner
=======================
Scans FFX extracted files and identifies formats based on magic bytes and headers.

Usage:
    python ffx_file_scanner.py --dir "D:/FFX Extracted/FFX/ffx_ps2/ffx/master/"
    python ffx_file_scanner.py --file some_file.bin
    python ffx_file_scanner.py --scan-all "D:/FFX Extracted/FFX/ffx_ps2/ffx/master/"
"""

import os
import sys
import struct
import argparse
from pathlib import Path
from collections import Counter

# Known magic signatures
MAGIC_SIGNATURES = {
    b'\x01\x00\x00\x00': 'Binary v1 (sbin/rbin/dcp)',
    b'\x08\x00\x00\x00': 'Monster data (mXXX.bin)',
    b'\x77\x77\x77\x77': 'Motion group (mgrp)',
    b'FTCX': 'Font/texture cache (ftc)',
    b'MAP1': 'Map data (vpa)',
    b'PHYR': 'PhyreEngine cluster (.phyre)',
    b'\x1bLua': 'Lua bytecode',
    b'PK': 'ZIP archive',
    b'Rar': 'RAR archive',
    b'7z': '7-Zip archive',
    b'GCM': 'PS3 GCM texture',
    b'DDS': 'DirectDraw Surface',
    b'BMP': 'Bitmap image',
    b'PNG': 'PNG image',
    b'JFIF': 'JPEG image',
    b'OggS': 'Ogg container',
    b'RIFF': 'RIFF container (WAV/AVI)',
    b'FORM': 'IFF container',
    b'Cull': 'Cull data (collision)',
    b'NavM': 'Navigation mesh',
    b'VTX': 'Vertex data',
    b'IDX': 'Index data',
    b'MAT': 'Material data',
    b'SHAD': 'Shader data',
    b'ANIM': 'Animation data',
    b'SKELE': 'Skeleton data',
    b'MESH': 'Mesh data',
    b'SCENE': 'Scene data',
    b'WORLD': 'World data',
    b'LIGHT': 'Light data',
    b'CAM': 'Camera data',
    b'FONT': 'Font data',
    b'TEXT': 'Text data',
    b'SOUND': 'Sound data',
    b'MUSIC': 'Music data',
    b'VIDEO': 'Video data',
    b'SCRIPT': 'Script data',
    b'EVENT': 'Event data',
    b'QUEST': 'Quest data',
    b'BATTLE': 'Battle data',
    b'ENCOUNTER': 'Encounter data',
    b'FORMULA': 'Formula data',
    b'STATUS': 'Status effect data',
    b'ELEMENT': 'Element data',
    b'ABILITY': 'Ability data',
    b'COMMAND': 'Command data',
    b'ITEM': 'Item data',
    b'EQUIP': 'Equipment data',
    b'WEAPON': 'Weapon data',
    b'ARMOR': 'Armor data',
    b'ACCESSORY': 'Accessory data',
    b'MATERIAL': 'Material data',
    b'SKILL': 'Skill data',
    b'SPELL': 'Spell data',
    b'OVERDRIVE': 'Overdrive data',
    b'LIMIT': 'Limit break data',
    b'SUMMON': 'Summon data',
    b'AEON': 'Aeon data',
    b'SPHERE': 'Sphere grid data',
    b'NODE': 'Node data',
    b'LINK': 'Link data',
    b'PATH': 'Path data',
    b'WAYPOINT': 'Waypoint data',
    b'TRIGGER': 'Trigger data',
    b'ZONE': 'Zone data',
    b'AREA': 'Area data',
    b'REGION': 'Region data',
    b'WORLD_MAP': 'World map data',
    b'MINIMAP': 'Minimap data',
    b'HUD': 'HUD data',
    b'MENU': 'Menu data',
    b'DIALOG': 'Dialog data',
    b'VOICE': 'Voice data',
    b'BGM': 'Background music data',
    b'SFX': 'Sound effect data',
    b'AMBIENT': 'Ambient sound data',
    b'CUTSCENE': 'Cutscene data',
    b'CINEMATIC': 'Cinematic data',
    b'FMV': 'Full motion video data',
    b'TUTORIAL': 'Tutorial data',
    b'HINT': 'Hint data',
    b'TIPS': 'Tips data',
    b'Achievement': 'Achievement data',
    b'Leaderboard': 'Leaderboard data',
    b'SAVE': 'Save data',
    b'LOAD': 'Load data',
    b'CONFIG': 'Config data',
    b'OPTIONS': 'Options data',
    b'SETTINGS': 'Settings data',
    b'LANGUAGE': 'Language data',
    b'LOCAL': 'Localization data',
    b'REGION': 'Region data',
    b'PLATFORM': 'Platform data',
    b'BUILD': 'Build data',
    b'VERSION': 'Version data',
    b'COPYRIGHT': 'Copyright data',
    b'LICENSE': 'License data',
    b'AUTHOR': 'Author data',
    b'TITLE': 'Title data',
    b'DESCRIPTION': 'Description data',
    b'KEYWORDS': 'Keywords data',
    b'CATEGORY': 'Category data',
    b'TAG': 'Tag data',
    b'Rating': 'Rating data',
    b'REVIEW': 'Review data',
    b'COMMENT': 'Comment data',
    b'NOTE': 'Note data',
    b'FLAG': 'Flag data',
    b'MARK': 'Mark data',
    b'TAG': 'Tag data',
    b'LABEL': 'Label data',
    b'GROUP': 'Group data',
    b'SET': 'Set data',
    b'LIST': 'List data',
    b'ARRAY': 'Array data',
    b'MAP': 'Map data',
    b'TABLE': 'Table data',
    b'INDEX': 'Index data',
    b'OFFSET': 'Offset data',
    b'POINTER': 'Pointer data',
    b'ADDRESS': 'Address data',
    b'SYMBOL': 'Symbol data',
    b'NAME': 'Name data',
    b'ID': 'ID data',
    b'KEY': 'Key data',
    b'VALUE': 'Value data',
    b'DATA': 'Generic data',
    b'INFO': 'Info data',
    b'META': 'Metadata',
    b'HEADER': 'Header data',
    b'FOOTER': 'Footer data',
    b'BLOCK': 'Block data',
    b'CHUNK': 'Chunk data',
    b'SEGMENT': 'Segment data',
    b'PART': 'Part data',
    b'SECTION': 'Section data',
    b'RECORD': 'Record data',
    b'ENTRY': 'Entry data',
    b'ITEM': 'Item data',
    b'ROW': 'Row data',
    b'COL': 'Column data',
    b'CELL': 'Cell data',
    b'PIXEL': 'Pixel data',
    b'VOXEL': 'Voxel data',
    b'SAMPLE': 'Sample data',
    b'FRAME': 'Frame data',
    b'KEYFRAME': 'Keyframe data',
    b'CURVE': 'Curve data',
    b'PATH': 'Path data',
    b'SPLINE': 'Spline data',
    b'BEZIER': 'Bezier data',
    b'POLYGON': 'Polygon data',
    b'VERTEX': 'Vertex data',
    b'EDGE': 'Edge data',
    b'FACE': 'Face data',
    b'NORMAL': 'Normal data',
    b'COLOR': 'Color data',
    b'UV': 'UV data',
    b'TEXCOORD': 'Texture coordinate data',
    b'BONE': 'Bone data',
    b'JOINT': 'Joint data',
    b'SKELETON': 'Skeleton data',
    b'ANIMATION': 'Animation data',
    b'MORPH': 'Morph data',
    b'BLEND': 'Blend data',
    b'TRANSFORM': 'Transform data',
    b'MATRIX': 'Matrix data',
    b'QUATERNION': 'Quaternion data',
    b'EULER': 'Euler angle data',
    b'AXIS': 'Axis data',
    b'ORIGIN': 'Origin data',
    b'PIVOT': 'Pivot data',
    b'BOUNDS': 'Bounds data',
    b'AABB': 'Axis-aligned bounding box data',
    b'OBB': 'Oriented bounding box data',
    b'SPHERE': 'Sphere data',
    b'CAPSULE': 'Capsule data',
    b'PLANE': 'Plane data',
    b'RAY': 'Ray data',
    b'LINE': 'Line data',
    b'TRIANGLE': 'Triangle data',
    b'QUAD': 'Quad data',
    b'BOX': 'Box data',
    b'CYLINDER': 'Cylinder data',
    b'CONE': 'Cone data',
    b'TORUS': 'Torus data',
    b'GRID': 'Grid data',
    b'MESH': 'Mesh data',
    b'PATCH': 'Patch data',
    b'SUBDIV': 'Subdivision data',
    b'NURBS': 'NURBS data',
    b'BSPLINE': 'B-spline data',
    b'BEZIER': 'Bezier data',
    b'HERMITE': 'Hermite data',
    b'CATMULL': 'Catmull-Rom data',
    b'LAGRANGE': 'Lagrange data',
    b'LINEAR': 'Linear data',
    b'NEAREST': 'Nearest data',
    b'BILINEAR': 'Bilinear data',
    b'TRILINEAR': 'Trilinear data',
    b'ANISOTROPIC': 'Anisotropic data',
    b'POINT': 'Point data',
    b'LINE': 'Line data',
    b'TRIANGLE': 'Triangle data',
    b'QUAD': 'Quad data',
    b'POLYGON': 'Polygon data',
    b'MESH': 'Mesh data',
    b'PATCH': 'Patch data',
    b'SUBDIV': 'Subdivision data',
    b'NURBS': 'NURBS data',
    b'BSPLINE': 'B-spline data',
    b'BEZIER': 'Bezier data',
    b'HERMITE': 'Hermite data',
    b'CATMULL': 'Catmull-Rom data',
    b'LAGRANGE': 'Lagrange data',
    b'LINEAR': 'Linear data',
    b'NEAREST': 'Nearest data',
    b'BILINEAR': 'Bilinear data',
    b'TRILINEAR': 'Trilinear data',
    b'ANISOTROPIC': 'Anisotropic data',
}

def scan_file(filepath):
    """Scan a single file and identify its format."""
    try:
        with open(filepath, 'rb') as f:
            header = f.read(256)

        if len(header) < 4:
            return None

        # Check magic signatures
        for magic, description in MAGIC_SIGNATURES.items():
            if header.startswith(magic):
                return {
                    'path': str(filepath),
                    'size': os.path.getsize(filepath),
                    'magic': magic.hex(),
                    'format': description,
                    'header_hex': header[:32].hex()
                }

        # Check for common patterns
        if header[:4] == b'\x00\x00\x00\x00':
            return {
                'path': str(filepath),
                'size': os.path.getsize(filepath),
                'magic': '00000000',
                'format': 'Zero-filled (possible stub)',
                'header_hex': header[:32].hex()
            }

        # Check for text files
        try:
            text = header.decode('ascii', errors='ignore')
            if all(c.isprintable() or c in '\n\r\t' for c in text[:100]):
                return {
                    'path': str(filepath),
                    'size': os.path.getsize(filepath),
                    'magic': 'TEXT',
                    'format': 'Text file',
                    'header_hex': header[:32].hex()
                }
        except:
            pass

        return {
            'path': str(filepath),
            'size': os.path.getsize(filepath),
            'magic': header[:4].hex(),
            'format': 'Unknown',
            'header_hex': header[:32].hex()
        }

    except Exception as e:
        return None

def scan_directory(dirpath, max_files=1000):
    """Scan all files in a directory."""
    results = []
    count = 0

    for root, dirs, files in os.walk(dirpath):
        for filename in files:
            if count >= max_files:
                return results

            filepath = os.path.join(root, filename)
            result = scan_file(filepath)
            if result:
                results.append(result)
                count += 1

    return results

def main():
    parser = argparse.ArgumentParser(description='FFX File Format Scanner')
    parser.add_argument('--dir', type=str, help='Directory to scan')
    parser.add_argument('--file', type=str, help='Single file to scan')
    parser.add_argument('--scan-all', type=str, help='Scan all files in directory')
    parser.add_argument('--max', type=int, default=1000, help='Max files to scan')

    args = parser.parse_args()

    if args.file:
        result = scan_file(args.file)
        if result:
            print(f"File: {result['path']}")
            print(f"Size: {result['size']} bytes")
            print(f"Magic: {result['magic']}")
            print(f"Format: {result['format']}")
            print(f"Header: {result['header_hex']}")

    elif args.dir or args.scan_all:
        dirpath = args.dir or args.scan_all
        print(f"Scanning {dirpath}...")
        results = scan_directory(dirpath, args.max)

        # Count formats
        format_counts = Counter(r['format'] for r in results)

        print(f"\nScanned {len(results)} files")
        print(f"\nFormat distribution:")
        for fmt, count in format_counts.most_common():
            print(f"  {fmt}: {count}")

    else:
        parser.print_help()

if __name__ == '__main__':
    main()
