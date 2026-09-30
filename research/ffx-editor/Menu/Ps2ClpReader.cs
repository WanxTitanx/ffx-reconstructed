// ── Ps2ClpReader ──────────────────────────────────────────────────────────────
// Standalone byte-level parser for the PS2 FFX menu "clip" format (.clp).
// Reference file: jppc/menu/menu.clp (16,384 bytes = 4 blocks of 4096).
//
// Format summary (empirically derived, 2026-08-19):
//   - The file is a fixed 16 KB container split into 4 blocks of 4096 bytes.
//   - Blocks 0 and 1 carry the menu clip/palette data and are byte-identical.
//   - Block 2 is all zeros (unused) in menu.clp.
//   - Block 3 carries a color palette (RGBA entries).
//   - Block 0/1 layout:
//       [0x000] 8x u32 BIG-ENDIAN cumulative entry counts (e.g. 0,7,16,24,35,48,55,64).
//                Section i spans entries [count[i], count[i+1]) of the 4-byte
//                entry array that starts at 0x20 (right after the header).
//       [0x020] 4-byte entries. Each entry is either:
//                  - an RGBA color (alpha byte != 0), e.g. 0x10101002, 0x000000FF;
//                  - a "pointer" entry (alpha byte == 0) whose RGB bytes encode an
//                    index into the same entry array (e.g. 0x00000047 -> entry 0x47).
//   - The 0x000000FF runs are opaque-black palette entries.
//
// NOTE: this is a RESEARCH parser. The exact menu semantics of each section
// (which menu element consumes which palette) require the PS2 game code, which
// is NOT present in the PC HD remaster binary (no ".clp" string exists there).
// ───────────────────────────────────────────────────────────────────────────────
using System;
using System.Collections.Generic;
using System.IO;

namespace ResearchTools.Menu
{
    public sealed class Ps2ClpEntry
    {
        public required int Index { get; init; }
        public required byte R { get; init; }
        public required byte G { get; init; }
        public required byte B { get; init; }
        public required byte A { get; init; }
        public bool IsPointer => A == 0x00 && (R | G | B) != 0x00;
        public int PointerIndex => (R << 16) | (G << 8) | B;
        public uint Raw => (uint)((R << 24) | (G << 16) | (B << 8) | A);
        public override string ToString() =>
            IsPointer ? $"#{Index} -> entry {PointerIndex}" : $"#{Index} RGBA({R:X2},{G:X2},{B:X2},{A:X2})";
    }

    public sealed class Ps2ClpSection
    {
        public required int Index { get; init; }
        public required int FirstEntry { get; init; }
        public required int EntryCount { get; init; }
        public required IReadOnlyList<Ps2ClpEntry> Entries { get; init; }
    }

    public sealed class Ps2ClpBlock
    {
        public required int BlockIndex { get; init; }
        public required int FileOffset { get; init; }
        public required uint[] Header { get; init; }
        public required IReadOnlyList<Ps2ClpSection> Sections { get; init; }
        public required IReadOnlyList<Ps2ClpEntry> Entries { get; init; }
    }

    public static class Ps2ClpReader
    {
        public const int BlockSize = 4096;
        public const int HeaderEntryCount = 8;
        public const int EntrySize = 4;

        public static IReadOnlyList<Ps2ClpBlock> Read(string path)
        {
            byte[] data = File.ReadAllBytes(path);
            return Read(data);
        }

        public static IReadOnlyList<Ps2ClpBlock> Read(byte[] data)
        {
            if (data.Length == 0 || data.Length % BlockSize != 0)
                throw new InvalidDataException($"CLP file size {data.Length} is not a multiple of {BlockSize}.");

            var blocks = new List<Ps2ClpBlock>();
            int blockCount = data.Length / BlockSize;
            for (int b = 0; b < blockCount; b++)
            {
                int baseOff = b * BlockSize;
                uint[] header = new uint[HeaderEntryCount];
                for (int i = 0; i < HeaderEntryCount; i++)
                    header[i] = ReadU32BE(data, baseOff + i * 4);

                // Parse sections only when the header looks like cumulative counts
                // (monotonic, small). Blocks 2/3 in menu.clp are raw palettes and
                // their "header" values are RGBA colors, not counts.
                bool looksLikeCounts = true;
                for (int i = 1; i < HeaderEntryCount; i++)
                {
                    if (header[i] < header[i - 1] || header[i] > 0x1000)
                    {
                        looksLikeCounts = false;
                        break;
                    }
                }

                var entries = new List<Ps2ClpEntry>();
                int dataStart = baseOff + HeaderEntryCount * 4;
                int entryCount = (BlockSize - HeaderEntryCount * 4) / EntrySize;
                for (int i = 0; i < entryCount; i++)
                {
                    int off = dataStart + i * EntrySize;
                    entries.Add(new Ps2ClpEntry
                    {
                        Index = i,
                        R = data[off],
                        G = data[off + 1],
                        B = data[off + 2],
                        A = data[off + 3],
                    });
                }

                var sections = new List<Ps2ClpSection>();
                if (looksLikeCounts)
                {
                    for (int s = 0; s < HeaderEntryCount; s++)
                    {
                        int first = (int)header[s];
                        int last = (s + 1 < HeaderEntryCount) ? (int)header[s + 1] : entryCount;
                        if (first > entryCount) continue;
                        var secEntries = new List<Ps2ClpEntry>();
                        for (int e = first; e < last && e < entryCount; e++)
                            secEntries.Add(entries[e]);
                        sections.Add(new Ps2ClpSection
                        {
                            Index = s,
                            FirstEntry = first,
                            EntryCount = secEntries.Count,
                            Entries = secEntries,
                        });
                    }
                }

                blocks.Add(new Ps2ClpBlock
                {
                    BlockIndex = b,
                    FileOffset = baseOff,
                    Header = header,
                    Sections = sections,
                    Entries = entries,
                });
            }
            return blocks;
        }

        private static uint ReadU32BE(byte[] data, int off) =>
            (uint)((data[off] << 24) | (data[off + 1] << 16) | (data[off + 2] << 8) | data[off + 3]);
    }
}
