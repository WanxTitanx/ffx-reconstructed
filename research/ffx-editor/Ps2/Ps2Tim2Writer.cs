using System;
using System.Buffers.Binary;
using System.Collections.Generic;
using System.IO;

namespace FFXProjectEditor.FfxLib.Ps2
{
    // ── Ps2Tim2Writer ──
    // TIM2 texture encoder for the PS2 indexed-8bpp variant found in FFX
    // (menu/help/battle-presentation textures). Emits a file that the
    // Ps2Tim2Reader classifies as "indexed_8bpp_candidate" (Native preview).
    //
    // Header layout (offsets matched to Ps2Tim2Reader):
    //   +0x00  char[4]  magic "TIM2"
    //   +0x04  u32      version/format (0 = v3)
    //   +0x08  u32      total file size (informational, not reader-validated)
    //   +0x0C  u32      picture count (1)
    //   +0x10  u32      picture block size (header + clut + image)
    //   +0x14  u32      paletteBytes (1024 for 8bpp)
    //   +0x18  u32      imageBytes (W*H for 8bpp)
    //   +0x1C  u16      picture header size (0x30)
    //   +0x1E  u16      color count (256)
    //   +0x23  u8       bpp marker (5 = 8bpp indexed)
    //   +0x24  u16      width
    //   +0x26  u16      height
    //   +0x28  u8[24]   reserved (zero)
    // Body layout (spec'd TIM2 order): CLUT 1024 B @0x40, then image W*H B.
    //   CLUT entries are BGRA with 7-bit alpha (PS2 convention; the reader's
    //   NormalizePs2Alpha doubles it back for preview).
    // File size formula: 0x40 + paletteBytes + imageBytes (reader-validated).
    //
    // Note: Ps2Tim2Reader.TryBuildPreviewBitmap currently assumes image-first
    // (clutOffset = 0x40 + imageBytes) — its own warning says "CLUT order may
    // still be wrong". This writer emits the spec'd CLUT-first order.
    //
    // Credit: Ps2Tim2Writer (formato TIM2 RE por Jarvis-Maechen, 2026-08-19)
    internal static class Ps2Tim2Writer
    {
        public const int HeaderSize = 0x40;
        public const int PaletteBytes = 1024;
        public const int ColorCount = 256;

        // ── Encode ──
        public static byte[] Encode(int width, int height, IReadOnlyList<uint> clutArgb, IReadOnlyList<byte> indices)
        {
            if (width <= 0 || height <= 0)
                throw new ArgumentOutOfRangeException(nameof(width), "TIM2 dimensions must be positive.");
            if (clutArgb.Count != ColorCount)
                throw new ArgumentException($"TIM2 8bpp CLUT must have exactly {ColorCount} entries.", nameof(clutArgb));

            int pixelCount = checked(width * height);
            if (indices.Count != pixelCount)
                throw new ArgumentException($"TIM2 index buffer must have exactly W*H = {pixelCount} entries.", nameof(indices));

            int totalSize = HeaderSize + PaletteBytes + pixelCount;
            byte[] d = new byte[totalSize];

            d[0] = (byte)'T'; d[1] = (byte)'I'; d[2] = (byte)'M'; d[3] = (byte)'2';
            WriteU32(d, 0x04, 0);                // version/format (v3)
            WriteU32(d, 0x08, (uint)totalSize);  // total file size
            WriteU32(d, 0x0C, 1);                // picture count
            WriteU32(d, 0x10, (uint)totalSize);  // picture block size
            WriteU32(d, 0x14, PaletteBytes);     // palette bytes
            WriteU32(d, 0x18, (uint)pixelCount); // image bytes
            WriteU16(d, 0x1C, 0x30);             // picture header size
            WriteU16(d, 0x1E, ColorCount);       // color count
            d[0x23] = 5;                         // bpp marker (8bpp indexed)
            WriteU16(d, 0x24, (ushort)width);
            WriteU16(d, 0x26, (ushort)height);
            // 0x28..0x3F stays zero (reserved)

            // ── CLUT @0x40 (BGRA, alpha 7-bit) ──
            int clut = HeaderSize;
            for (int i = 0; i < ColorCount; i++)
            {
                uint c = clutArgb[i];
                d[clut + 0] = (byte)(c & 0xFF);                // B
                d[clut + 1] = (byte)((c >> 8) & 0xFF);         // G
                d[clut + 2] = (byte)((c >> 16) & 0xFF);        // R
                d[clut + 3] = (byte)(((c >> 24) & 0xFF) >> 1); // A (7-bit PS2)
                clut += 4;
            }

            // ── Image @0x40+1024 (palette indices) ──
            int img = HeaderSize + PaletteBytes;
            for (int i = 0; i < pixelCount; i++)
                d[img + i] = indices[i];

            return d;
        }

        public static void Write(Stream stream, int width, int height, IReadOnlyList<uint> clutArgb, IReadOnlyList<byte> indices)
        {
            byte[] d = Encode(width, height, clutArgb, indices);
            stream.Write(d, 0, d.Length);
        }

        public static void WriteToFile(string path, int width, int height, IReadOnlyList<uint> clutArgb, IReadOnlyList<byte> indices)
        {
            using var fs = new FileStream(path, FileMode.Create, FileAccess.Write, FileShare.None);
            Write(fs, width, height, clutArgb, indices);
        }

        static void WriteU16(byte[] d, int o, ushort v) => BinaryPrimitives.WriteUInt16LittleEndian(d.AsSpan(o), v);
        static void WriteU32(byte[] d, int o, uint v) => BinaryPrimitives.WriteUInt32LittleEndian(d.AsSpan(o), v);
    }
}
