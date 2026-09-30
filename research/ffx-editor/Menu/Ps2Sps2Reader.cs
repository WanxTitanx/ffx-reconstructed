// ── Ps2Sps2Reader ─────────────────────────────────────────────────────────────
// Standalone byte-level parser for the PS2 FFX help-presentation format (.sps2).
// Reference file: jppc/help/dvdcopy.sps2 (39,992 bytes = 0x9C38).
//
// Format summary (empirically derived + IDA-confirmed, 2026-08-19):
//   Header (32 bytes, all u32 LITTLE-ENDIAN):
//       [0x00] magic   = 1 (constant across all 5 sample files)
//       [0x04] count   = number of pages (6 in dvdcopy.sps2; 155 in now_help.sps2)
//       [0x08] page_table_offset = offset of the page table (0x2D20 in dvdcopy.sps2)
//       [0x0C] clip_offset = offset of the clip-entry section (0x24, constant)
//       [0x10] offsets_offset = offset of the u32 offset table (0x84)
//       [0x14] field14 = ambiguous: equals file size in dvdcopy.sps2 (0x9C38)
//              but is smaller than the file in now_help.sps2 (0xBA5E0 vs 0xBB110);
//              possibly a data-end or secondary-table offset.
//       [0x18] 8 bytes padding (0xCC fill)
//
//   Clip-entry section @ clip_offset:
//       Fixed 12-byte records: 6x u16 LE (x_min, x_max, y_min, y_max, type,
//       sentinel=0xFFFF). dvdcopy.sps2 has 8 records (0x24..0x84).
//
//   Offset table @ offsets_offset:
//       u32 LE offsets into the page-data region. dvdcopy.sps2 has 70 entries
//       (0x19C..0x2C67). The table ends where the first offset points.
//
//   Page table @ page_table_offset:
//       8-byte records: (u32 LE page_offset, u16 LE count, u16 LE sentinel=0xFFFF).
//       The record count equals the header "count" field.
//
//   Page data @ page_offset:
//       A u16 command stream. The first 8 u16s are a page header (layout
//       parameters), followed by 12-byte clip records. 0xCCCC/0xCC00 values are
//       fill bytes (0xCC pattern) that appear when the stream is read as u16;
//       0xFFFF is a record terminator.
//
//   Loader (IDA, PC HD remaster): FFX_Scene_CreatePObject @ 0x88CDF0 reads the
//   file via Phyre_File_ReadEntireFile_ww using the path table at 0xC58E44
//   (10 hardcoded /help/*.sps2 paths). The consumer is the ATEL help screen
//   FFX_Atel_Movie_FuncB088 @ 0x770540.
//
// NOTE: this is a RESEARCH parser. The page command-stream semantics require
// the PS2 help-scene code, which is not fully recoverable from the PC binary.
// ───────────────────────────────────────────────────────────────────────────────
using System;
using System.Collections.Generic;
using System.IO;

namespace ResearchTools.Menu
{
    public sealed class Ps2Sps2Clip
    {
        public required int Index { get; init; }
        public required int FileOffset { get; init; }
        public required ushort XMin { get; init; }
        public required ushort XMax { get; init; }
        public required ushort YMin { get; init; }
        public required ushort YMax { get; init; }
        public required ushort Type { get; init; }
        public required ushort Sentinel { get; init; }
        public override string ToString() =>
            $"clip {Index} @0x{FileOffset:X}: rect({XMin},{XMax},{YMin},{YMax}) type={Type} sentinel=0x{Sentinel:X}";
    }

    public sealed class Ps2Sps2Page
    {
        public required int Index { get; init; }
        public required int FileOffset { get; init; }
        public required ushort Count { get; init; }
        public required ushort[] HeaderWords { get; init; }
        public required IReadOnlyList<Ps2Sps2Clip> Clips { get; init; }
    }

    public sealed class Ps2Sps2File
    {
        public required int FileSize { get; init; }
        public required uint Magic { get; init; }
        public required uint Count { get; init; }
        public required uint PageTableOffset { get; init; }
        public required uint ClipOffset { get; init; }
        public required uint OffsetsOffset { get; init; }
        public required uint Field14 { get; init; }
        public required uint[] Offsets { get; init; }
        public required IReadOnlyList<Ps2Sps2Clip> Clips { get; init; }
        public required IReadOnlyList<Ps2Sps2Page> Pages { get; init; }
    }

    public static class Ps2Sps2Reader
    {
        public const int HeaderSize = 32;
        public const int ClipSize = 12;   // 6x u16
        public const int PageTableEntrySize = 8; // u32 + u16 + u16

        public static Ps2Sps2File Read(string path) => Read(File.ReadAllBytes(path));

        public static Ps2Sps2File Read(byte[] data)
        {
            if (data.Length < HeaderSize)
                throw new InvalidDataException($"SPS2 file too small: {data.Length} bytes.");

            uint magic = ReadU32LE(data, 0x00);
            uint count = ReadU32LE(data, 0x04);
            uint pageTableOffset = ReadU32LE(data, 0x08);
            uint clipOffset = ReadU32LE(data, 0x0C);
            uint offsetsOffset = ReadU32LE(data, 0x10);
            uint field14 = ReadU32LE(data, 0x14);

            // Clip entries in the clip section.
            var clips = new List<Ps2Sps2Clip>();
            int clipEnd = (int)offsetsOffset;
            for (int off = (int)clipOffset; off + ClipSize <= clipEnd && off + ClipSize <= data.Length; off += ClipSize)
            {
                ushort xMin = ReadU16LE(data, off);
                ushort xMax = ReadU16LE(data, off + 2);
                ushort yMin = ReadU16LE(data, off + 4);
                ushort yMax = ReadU16LE(data, off + 6);
                ushort type = ReadU16LE(data, off + 8);
                ushort sentinel = ReadU16LE(data, off + 10);
                if (sentinel != 0xFFFF)
                    break; // not a clip record; stop
                clips.Add(new Ps2Sps2Clip
                {
                    Index = clips.Count,
                    FileOffset = off,
                    XMin = xMin, XMax = xMax, YMin = yMin, YMax = yMax,
                    Type = type, Sentinel = sentinel,
                });
            }

            // Offset table: read until the first offset value (table is contiguous).
            var offsets = new List<uint>();
            if (offsetsOffset > 0 && offsetsOffset < data.Length)
            {
                int firstOffset = (int)ReadU32LE(data, (int)offsetsOffset);
                int tableEnd = (firstOffset > (int)offsetsOffset) ? firstOffset : (int)clipOffset;
                for (int off = (int)offsetsOffset; off + 4 <= tableEnd && off + 4 <= data.Length; off += 4)
                    offsets.Add(ReadU32LE(data, off));
            }

            // Page table @ page_table_offset (from the header).
            var pages = new List<Ps2Sps2Page>();
            int pageTableOff = (int)pageTableOffset;
            for (int p = 0; p < (int)count; p++)
            {
                int off = pageTableOff + p * PageTableEntrySize;
                if (off + PageTableEntrySize > data.Length)
                    break;
                uint pageOffset = ReadU32LE(data, off);
                ushort pageCount = ReadU16LE(data, off + 4);
                ushort sentinel = ReadU16LE(data, off + 6);
                if (sentinel != 0xFFFF || pageOffset >= data.Length)
                    break;

                // Page header: first 8 u16s are layout params, then clip records.
                var headerWords = new ushort[8];
                for (int w = 0; w < 8; w++)
                    headerWords[w] = ReadU16LE(data, (int)pageOffset + w * 2);

                var pageClips = new List<Ps2Sps2Clip>();
                int cOff = (int)pageOffset + 16;
                int cEnd = (int)pageOffset + 16 + pageCount * ClipSize;
                for (int c = 0; c < pageCount && cOff + ClipSize <= cEnd && cOff + ClipSize <= data.Length; c++)
                {
                    ushort xMin = ReadU16LE(data, cOff);
                    ushort xMax = ReadU16LE(data, cOff + 2);
                    ushort yMin = ReadU16LE(data, cOff + 4);
                    ushort yMax = ReadU16LE(data, cOff + 6);
                    ushort type = ReadU16LE(data, cOff + 8);
                    ushort sent = ReadU16LE(data, cOff + 10);
                    pageClips.Add(new Ps2Sps2Clip
                    {
                        Index = c,
                        FileOffset = cOff,
                        XMin = xMin, XMax = xMax, YMin = yMin, YMax = yMax,
                        Type = type, Sentinel = sent,
                    });
                    cOff += ClipSize;
                }

                pages.Add(new Ps2Sps2Page
                {
                    Index = p,
                    FileOffset = (int)pageOffset,
                    Count = pageCount,
                    HeaderWords = headerWords,
                    Clips = pageClips,
                });
            }

            return new Ps2Sps2File
            {
                FileSize = data.Length,
                Magic = magic,
                Count = count,
                PageTableOffset = pageTableOffset,
                ClipOffset = clipOffset,
                OffsetsOffset = offsetsOffset,
                Field14 = field14,
                Offsets = offsets.ToArray(),
                Clips = clips,
                Pages = pages,
            };
        }

        private static ushort ReadU16LE(byte[] data, int off) =>
            (ushort)(data[off] | (data[off + 1] << 8));

        private static uint ReadU32LE(byte[] data, int off) =>
            (uint)(data[off] | (data[off + 1] << 8) | (data[off + 2] << 16) | (data[off + 3] << 24));
    }
}
