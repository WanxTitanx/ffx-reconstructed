#!/usr/bin/env python3
"""
FFX VBF (Virtuos Big File) Extractor
=====================================

Extracts files from VBF archives used by FFX HD PC port (and FFXII HD).
VBF is the Virtuos replacement for PSARC (PS3 format).

Format: SRYK signature -> header (hashes + file entries + name table + block sizes) ->
        64KB zlib-compressed data blocks -> 16-byte MD5 footer.

Based on reverse engineering of the Haskell vbf-fs tool by Michivi
and binary analysis of FFX_Data.vbf.

Usage:
    python vbf_extractor.py list   <archive.vbf>
    python vbf_extractor.py info   <archive.vbf>
    python vbf_extractor.py extract <archive.vbf> <entry_path> [-o output]
    python vbf_extractor.py unpack <archive.vbf> [-o output_dir]
    python vbf_extractor.py search <archive.vbf> <pattern>

Examples:
    python vbf_extractor.py list ffx_data.vbf
    python vbf_extractor.py search ffx_data.vbf ".phyre"
    python vbf_extractor.py extract ffx_data.vbf "data/ffx/battle/btl_001.bin" -o ./out
    python vbf_extractor.py unpack ffx_data.vbf -o ./extracted
"""

import argparse
import hashlib
import os
import struct
import sys
import zlib
from dataclasses import dataclass, field
from pathlib import Path
from typing import BinaryIO, Optional

VBF_SIGNATURE = b"SRYK"
VBF_BLOCK_SIZE = 65536  # 64 KB
VBF_HASH_SIZE = 16  # MD5


@dataclass
class VBFFileEntry:
    """A single file entry in the VBF archive."""
    start_block: int   # uint32 - index of first data block
    _reserved: int     # uint32 - always 0
    size: int          # uint64 - uncompressed size in bytes
    offset: int        # uint64 - absolute data offset in archive
    name_offset: int   # uint64 - offset into name table

    @property
    def block_count(self) -> int:
        return (self.size + VBF_BLOCK_SIZE - 1) // VBF_BLOCK_SIZE if self.size > 0 else 0


@dataclass
class VBFHeader:
    """Parsed VBF archive header."""
    header_length: int
    num_files: int
    hashes: list       # list of 16-byte MD5 hashes
    entries: list      # list of VBFFileEntry
    name_table: bytes
    block_sizes: list  # list of uint16 per block


@dataclass
class VBFEntry:
    """Fully resolved entry with path and block info."""
    path: str
    entry: VBFFileEntry
    blocks: list       # list of (offset, raw_size) tuples


def md5_hash(data: bytes) -> bytes:
    return hashlib.md5(data).digest()


def read_u16(f: BinaryIO) -> int:
    return struct.unpack("<H", f.read(2))[0]


def read_u32(f: BinaryIO) -> int:
    return struct.unpack("<I", f.read(4))[0]


def read_u64(f: BinaryIO) -> int:
    return struct.unpack("<Q", f.read(8))[0]


def parse_header(f: BinaryIO) -> VBFHeader:
    """Parse the VBF archive header."""
    sig = f.read(4)
    if sig != VBF_SIGNATURE:
        raise ValueError(f"Invalid VBF signature: {sig!r} (expected {VBF_SIGNATURE!r})")

    header_length = read_u32(f)
    num_files = read_u64(f)

    hashes = []
    for _ in range(num_files):
        hashes.append(f.read(VBF_HASH_SIZE))

    entries = []
    for _ in range(num_files):
        start_block = read_u32(f)
        reserved = read_u32(f)
        size = read_u64(f)
        offset = read_u64(f)
        name_offset = read_u64(f)
        entries.append(VBFFileEntry(start_block, reserved, size, offset, name_offset))

    name_table_size = read_u32(f)
    name_table = f.read(name_table_size - 4)

    total_blocks = sum(e.block_count for e in entries)
    block_sizes = []
    for _ in range(total_blocks):
        block_sizes.append(read_u16(f))

    return VBFHeader(header_length, num_files, hashes, entries, name_table, block_sizes)


def resolve_name(entry: VBFFileEntry, name_table: bytes) -> str:
    """Resolve file path from name table offset."""
    offset = entry.name_offset
    end = name_table.find(b"\x00", offset)
    if end == -1:
        end = len(name_table)
    return name_table[offset:end].decode("utf-8", errors="replace")


def decompress_block(data: bytes, block_size_field: int, block_data_size: int) -> bytes:
    """
    Decompress a single data block.
    block_size_field: value from the block size table (0 = passthrough)
    block_data_size: actual bytes read from archive for this block
    """
    if block_size_field == 0:
        # Passthrough: full uncompressed 64KB block (or partial at end of file)
        return data
    elif block_size_field < VBF_BLOCK_SIZE and block_size_field > 0:
        if block_size_field == block_data_size:
            # Compressed: decompress
            return zlib.decompress(data, 15)
        else:
            # Partial uncompressed block (size < 64KB, not compressed)
            return data
    else:
        return data


def get_block_raw_size(block_size_field: int, fallback: int = VBF_BLOCK_SIZE) -> int:
    """Get the raw (archive-stored) size of a block."""
    if block_size_field == 0:
        return fallback  # passthrough = full block
    else:
        return block_size_field  # compressed or partial


def extract_entry_data(f: BinaryIO, entry: VBFFileEntry, block_sizes: list,
                       header_length: int) -> bytes:
    """Extract and decompress a single entry's data blocks."""
    blocks = []
    for i in range(entry.block_count):
        block_idx = entry.start_block + i
        size_field = block_sizes[block_idx] if block_idx < len(block_sizes) else 0

        is_last = (i == entry.block_count - 1)
        if is_last:
            remaining = entry.size - (entry.block_count - 1) * VBF_BLOCK_SIZE
            raw_size = min(remaining, VBF_BLOCK_SIZE)
        else:
            raw_size = VBF_BLOCK_SIZE

        f.seek(entry.offset + blocks[-1][1] if blocks else entry.offset)
        compressed_data = f.read(get_block_raw_size(size_field, raw_size))
        decompressed = decompress_block(compressed_data, size_field, len(compressed_data))
        blocks.append((decompressed, len(compressed_data)))

    return b"".join(d for d, _ in blocks)


def parse_vbf(filepath: str) -> tuple[VBFHeader, list[VBFEntry]]:
    """Parse a VBF file and return header + resolved entries."""
    with open(filepath, "rb") as f:
        header = parse_header(f)

        entries = []
        for i, raw_entry in enumerate(header.entries):
            path = resolve_name(raw_entry, header.name_table)

            # Compute block offsets
            blocks = []
            current_offset = raw_entry.offset
            for j in range(raw_entry.block_count):
                block_idx = raw_entry.start_block + j
                size_field = header.block_sizes[block_idx] if block_idx < len(header.block_sizes) else 0
                raw_block_size = get_block_raw_size(size_field)
                blocks.append((current_offset, raw_block_size))
                current_offset += raw_block_size

            entries.append(VBFEntry(path, raw_entry, blocks))

    return header, entries


# --- Commands ---

def cmd_info(args):
    """Print archive info."""
    header, entries = parse_vbf(args.archive)
    total_uncompressed = sum(e.entry.size for e in entries)
    total_blocks = sum(e.entry.block_count for e in entries)

    print(f"VBF Archive: {args.archive}")
    print(f"  Signature:     SRYK")
    print(f"  Header size:   {header.header_length} bytes")
    print(f"  Files:         {header.num_files}")
    print(f"  Data blocks:   {total_blocks}")
    print(f"  Uncompressed:  {total_uncompressed:,} bytes ({total_uncompressed / (1024*1024):.1f} MB)")

    # Count by extension
    ext_counts = {}
    for e in entries:
        ext = Path(e.path).suffix.lower() or "(no ext)"
        ext_counts[ext] = ext_counts.get(ext, 0) + 1
    print(f"\n  File types ({len(ext_counts)} unique):")
    for ext, count in sorted(ext_counts.items(), key=lambda x: -x[1])[:20]:
        print(f"    {ext:20s}  {count:6d}")


def cmd_list(args):
    """List all files in the archive."""
    header, entries = parse_vbf(args.archive)

    for i, e in enumerate(entries):
        size = e.entry.size
        if size >= 1024 * 1024:
            size_str = f"{size / (1024*1024):.1f} MB"
        elif size >= 1024:
            size_str = f"{size / 1024:.1f} KB"
        else:
            size_str = f"{size} B"
        print(f"{i:6d}  {size_str:>10s}  {e.path}")

    print(f"\n  Total: {len(entries)} files")


def cmd_extract(args):
    """Extract a single file by path."""
    header, entries = parse_vbf(args.archive)

    match = None
    for e in entries:
        if e.path == args.entry:
            match = e
            break

    if match is None:
        # Try partial match
        for e in entries:
            if args.entry.lower() in e.path.lower():
                if match is None:
                    match = e
                else:
                    print(f"Multiple matches found. Use exact path.", file=sys.stderr)
                    print(f"  Candidate 1: {match.path}")
                    print(f"  Candidate 2: {e.path}")
                    return 1

    if match is None:
        print(f"Entry not found: {args.entry}", file=sys.stderr)
        return 1

    with open(args.archive, "rb") as f:
        data = extract_entry_data(f, match.entry, header.block_sizes, header.header_length)

    output = args.output
    if output:
        os.makedirs(os.path.dirname(output) or ".", exist_ok=True)
        with open(output, "wb") as of:
            of.write(data)
        print(f"Extracted: {match.path} -> {output} ({len(data):,} bytes)")
    else:
        sys.stdout.buffer.write(data)
    return 0


def cmd_unpack(args):
    """Unpack the entire archive to a directory."""
    header, entries = parse_vbf(args.archive)

    output_dir = args.output or Path(args.archive).stem
    os.makedirs(output_dir, exist_ok=True)

    total = len(entries)
    extracted = 0
    errors = 0

    with open(args.archive, "rb") as f:
        for i, e in enumerate(entries):
            try:
                data = extract_entry_data(f, e.entry, header.block_sizes, header.header_length)
                out_path = os.path.join(output_dir, e.path.replace("\\", "/"))
                os.makedirs(os.path.dirname(out_path), exist_ok=True)
                with open(out_path, "wb") as of:
                    of.write(data)
                extracted += 1
            except Exception as ex:
                print(f"  ERROR [{i+1}/{total}] {e.path}: {ex}", file=sys.stderr)
                errors += 1

            if (i + 1) % 1000 == 0 or (i + 1) == total:
                print(f"  Progress: {i+1}/{total} ({extracted} extracted, {errors} errors)")

    print(f"\nDone. Extracted {extracted}/{total} files to {output_dir}/")
    if errors:
        print(f"  {errors} errors encountered.")
    return 0 if errors == 0 else 1


def cmd_search(args):
    """Search for entries matching a pattern."""
    header, entries = parse_vbf(args.archive)

    pattern = args.pattern.lower()
    matches = [(i, e) for i, e in enumerate(entries) if pattern in e.path.lower()]

    if not matches:
        print(f"No entries matching '{args.pattern}'")
        return 1

    for i, e in matches:
        size = e.entry.size
        if size >= 1024 * 1024:
            size_str = f"{size / (1024*1024):.1f} MB"
        elif size >= 1024:
            size_str = f"{size / 1024:.1f} KB"
        else:
            size_str = f"{size} B"
        print(f"{i:6d}  {size_str:>10s}  {e.path}")

    print(f"\n  Matched: {len(matches)}/{len(entries)} files")
    return 0


def main():
    parser = argparse.ArgumentParser(
        description="FFX VBF (Virtuos Big File) Archive Extractor",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=__doc__,
    )
    sub = parser.add_subparsers(dest="command", help="Command to run")

    # info
    p_info = sub.add_parser("info", help="Show archive info")
    p_info.add_argument("archive", help="Path to .vbf file")

    # list
    p_list = sub.add_parser("list", help="List all entries")
    p_list.add_argument("archive", help="Path to .vbf file")

    # extract
    p_extract = sub.add_parser("extract", help="Extract a single file")
    p_extract.add_argument("archive", help="Path to .vbf file")
    p_extract.add_argument("entry", help="Entry path within the archive")
    p_extract.add_argument("-o", "--output", help="Output file path")

    # unpack
    p_unpack = sub.add_parser("unpack", help="Unpack entire archive")
    p_unpack.add_argument("archive", help="Path to .vbf file")
    p_unpack.add_argument("-o", "--output", help="Output directory")

    # search
    p_search = sub.add_parser("search", help="Search entries by pattern")
    p_search.add_argument("archive", help="Path to .vbf file")
    p_search.add_argument("pattern", help="Substring to search for")

    args = parser.parse_args()
    if not args.command:
        parser.print_help()
        return 1

    cmds = {
        "info": cmd_info,
        "list": cmd_list,
        "extract": cmd_extract,
        "unpack": cmd_unpack,
        "search": cmd_search,
    }
    return cmds[args.command](args)


if __name__ == "__main__":
    sys.exit(main() or 0)
