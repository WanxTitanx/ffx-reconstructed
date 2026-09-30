// ── Ps2FmtReader ──────────────────────────────────────────────────────────────
// Standalone byte-level parser for the PS2 FFX menu font format (.fmt).
// Reference file: jppc/menu/battle.fmt (65,536 bytes = 256 glyphs).
//
// Format summary (empirically derived, 2026-08-19):
//   - Fixed stride of 256 bytes per glyph. All 12 .fmt files in jppc/menu are
//     exact multiples of 256 (64/128/256/512/832 glyphs).
//   - Glyph block layout (256 bytes):
//       [0x00] 1 byte 0x00 + ASCII "shape" string (up to ~63 bytes) + zero pad.
//              The designer encoded the glyph outline using ASCII characters
//              whose visual shape resembles the letter, e.g. "D" =
//              "diiiiid" + "tuxrrrr...xut", "O" = "diiiiiiid" + "txoqMMMMMRRR...qort".
//              Only the ~60 printable ASCII glyphs carry this string; the rest
//              (kana, punctuation) are all zeros here.
//       [0x40] 128 bytes of 8-bit indexed pixel data (zone 1: top of glyph).
//              Non-zero values are palette indices (e.g. 0x97/0x98 outline,
//              0x06 fill).
//       [0xC0] 64 bytes of 8-bit indexed pixel data (zone 2: body/bottom).
//   - The pixel values are indices into the game's font CLUT (not raw colors).
//
// NOTE: this is a RESEARCH parser. The PC HD remaster does not load .fmt files
// (it uses menu/D3D11/*.dds.phyre fonts instead), so the exact CLUT mapping is
// PS2-only.
// ───────────────────────────────────────────────────────────────────────────────
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ResearchTools.Menu
{
    public sealed class Ps2FmtGlyph
    {
        public required int Index { get; init; }
        public required int FileOffset { get; init; }
        public required string AsciiShape { get; init; }
        public required byte[] Zone1 { get; init; }   // 128 bytes @ 0x40
        public required byte[] Zone2 { get; init; }   // 64 bytes @ 0xC0
        public required byte[] Raw { get; init; }     // full 256-byte block
        public int NonZeroZone1 { get; init; }
        public int NonZeroZone2 { get; init; }
    }

    public sealed class Ps2FmtFile
    {
        public required int FileSize { get; init; }
        public required int GlyphCount { get; init; }
        public required IReadOnlyList<Ps2FmtGlyph> Glyphs { get; init; }
    }

    public static class Ps2FmtReader
    {
        public const int GlyphStride = 256;
        public const int Zone1Offset = 0x40;
        public const int Zone1Size = 128;
        public const int Zone2Offset = 0xC0;
        public const int Zone2Size = 64;

        public static Ps2FmtFile Read(string path) => Read(File.ReadAllBytes(path));

        public static Ps2FmtFile Read(byte[] data)
        {
            if (data.Length == 0 || data.Length % GlyphStride != 0)
                throw new InvalidDataException($"FMT file size {data.Length} is not a multiple of {GlyphStride}.");

            int glyphCount = data.Length / GlyphStride;
            var glyphs = new List<Ps2FmtGlyph>(glyphCount);

            for (int i = 0; i < glyphCount; i++)
            {
                int baseOff = i * GlyphStride;
                byte[] raw = new byte[GlyphStride];
                Array.Copy(data, baseOff, raw, 0, GlyphStride);

                byte[] zone1 = new byte[Zone1Size];
                Array.Copy(raw, Zone1Offset, zone1, 0, Zone1Size);
                byte[] zone2 = new byte[Zone2Size];
                Array.Copy(raw, Zone2Offset, zone2, 0, Zone2Size);

                // Extract the ASCII shape string: printable run starting at 0x01.
                var sb = new StringBuilder();
                for (int b = 1; b < Zone1Offset; b++)
                {
                    if (raw[b] >= 0x20 && raw[b] < 0x7F)
                        sb.Append((char)raw[b]);
                    else if (sb.Length > 0)
                        break;
                }

                int nz1 = 0, nz2 = 0;
                foreach (byte b in zone1) if (b != 0) nz1++;
                foreach (byte b in zone2) if (b != 0) nz2++;

                glyphs.Add(new Ps2FmtGlyph
                {
                    Index = i,
                    FileOffset = baseOff,
                    AsciiShape = sb.ToString(),
                    Zone1 = zone1,
                    Zone2 = zone2,
                    Raw = raw,
                    NonZeroZone1 = nz1,
                    NonZeroZone2 = nz2,
                });
            }

            return new Ps2FmtFile
            {
                FileSize = data.Length,
                GlyphCount = glyphCount,
                Glyphs = glyphs,
            };
        }
    }
}
