// Ps2TxcBinaryReader.cs
// Standalone reader for PS2 FFX binary .txc textures (yonishi_data/dat/t_*.txc).
// RE: FFX PS2 yonishi_data (magic/effect texture sheets), 2026-08-19, Jarvis-GENERAL.
// RESEARCH ONLY -- not integrated into FFXProjectEditor.
//
// Format (binary variant, NO header):
//   - Raw 8bpp indexed pixels, row-major, no header, no magic.
//   - File size is exactly W*H bytes.
//       * 65536  bytes = 256x256
//       * 131072 bytes = 256x512  (icon/effect sheet, width 256)
//   - Each byte is an index into a paired CLUT (.clt, 4096 B = 256 RGBA).
//   - Naming: t_XXXX_N.txc pairs with c_XXXX_N.clt (same key + frame index N).
//     One texture key can have up to 4 palettes (c_XXXX_0..3).
//
// The .clt color table is parsed by Ps2CltColorTableReader (RGBA, alpha 0x80 opaque).
// This reader exposes the raw index buffer + inferred dimensions and can build a
// System.Drawing.Bitmap preview when a CLUT is supplied.
// FIX 2026-09-15 (FFX-STRUCTURES validation): add missing `using Ps2ResearchTools;`
// (BuildPreview/SavePreviewPng take a Ps2CltColorTableReader from the sibling
// namespace Ps2ResearchTools -> CS0246 when compiled standalone).
//
// TEXT VARIANT (2026-09-17, Jarvis-MAP, residual audit FFX_FMT_GFX_RESIDUALS):
//   4 of 30 corpus .txc are NOT raw binary but ASCII C-array dumps of u32 words
//   ("0x01111110,0x00011000,..." -- comma-separated, optional // comments).
//     * 512  words -> 2048 packed bytes = 4bpp sheet (nibble stream, e.g. num_16/font,
//       paired .clc has 16 colors) -> we unpack nibbles to 4096 index bytes (64x64).
//     * 16384 words -> 65536 bytes = 8bpp 256x256 sheet (tyle8/meteo_1, .clc has 256).
//   Nibble order is low-first, matching PSMT4 byte ordering; pixel-to-tile swizzle
//   of the original dev toolchain is NOT proven, so dimensions remain INFERRED.
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;
using Ps2ResearchTools;

namespace Ps2
{
    /// <summary>
    /// Binary .txc texture reader. Raw 8bpp indexed pixels, no header.
    /// </summary>
    public sealed class Ps2TxcBinaryReader
    {
        public const int Size256x256 = 65536;   // 256*256
        public const int Size256x512 = 131072;  // 256*512

        public byte[] Indices { get; private set; } = Array.Empty<byte>();
        public string FilePath { get; private set; } = "";
        public int Width { get; private set; }
        public int Height { get; private set; }
        /// <summary>"binary" (raw 8bpp) or "text-u32" (ASCII C-array variant).</summary>
        public string Variant { get; private set; } = "binary";

        /// <summary>
        /// Inferred width for the given raw byte count (256x256, 256x512, or square).
        /// </summary>
        public static int InferWidth(int byteCount)
        {
            // Perfect-square buffers (e.g. 4096 B unpacked 4bpp sheets) report WxW;
            // the standard corpus sizes are always 256-wide.
            if (byteCount != Size256x256 && byteCount != Size256x512)
            {
                int s = (int)Math.Sqrt(byteCount);
                if (s * s == byteCount) return s;
            }
            return 256;
        }

        /// <summary>Inferred height for the given raw byte count.</summary>
        public static int InferHeight(int byteCount)
        {
            switch (byteCount)
            {
                case Size256x256: return 256;
                case Size256x512: return 512;
                default:
                    // Any other size: assume square if a perfect square, else 256-wide.
                    int s = (int)Math.Sqrt(byteCount);
                    return s * s == byteCount ? s : byteCount / 256;
            }
        }

        /// <summary>
        /// Loads a .txc, inferring dimensions from the file size.
        /// Detects the ASCII C-array text variant and decodes it to index bytes first.
        /// </summary>
        public static Ps2TxcBinaryReader FromFile(string path)
        {
            byte[] data = File.ReadAllBytes(path);
            byte[]? decoded = TryDecodeTextVariant(data);
            if (decoded != null)
            {
                return new Ps2TxcBinaryReader
                {
                    Indices = decoded,
                    Width = InferWidth(decoded.Length),
                    Height = InferHeight(decoded.Length),
                    FilePath = path,
                    Variant = "text-u32",
                };
            }
            return FromBytes(data, InferWidth(data.Length), InferHeight(data.Length), path);
        }

        /// <summary>
        /// If the buffer is the ASCII C-array variant, returns the decoded index
        /// buffer (nibbles unpacked for the 4bpp case); otherwise null.
        /// </summary>
        private static byte[]? TryDecodeTextVariant(byte[] data)
        {
            // Fast reject: binary .txc start with raw index bytes; the text variant
            // starts with optional whitespace then literally "0x".
            int i = 0;
            while (i < data.Length && char.IsWhiteSpace((char)data[i])) i++;
            if (i + 1 >= data.Length || data[i] != (byte)'0' || data[i + 1] != (byte)'x')
                return null;

            var words = new List<uint>();
            var text = Encoding.ASCII.GetString(data, i, data.Length - i);
            foreach (Match m in Regex.Matches(text, @"0x([0-9a-fA-F]{1,8})"))
                words.Add(Convert.ToUInt32(m.Groups[1].Value, 16));
            if (words.Count == 0) return null;

            // Emit the 4 bytes of each u32 (little-endian), i.e. the raw packed image.
            byte[] packed = new byte[words.Count * 4];
            for (int w = 0; w < words.Count; w++)
                BitConverter.GetBytes(words[w]).CopyTo(packed, w * 4);

            if (packed.Length == 2048)
            {
                // 4bpp packed nibble stream -> 4096 index bytes (64x64 inferred).
                // Low nibble = even pixel (PSMT4 byte order).
                var px = new byte[packed.Length * 2];
                for (int b = 0; b < packed.Length; b++)
                {
                    px[b * 2] = (byte)(packed[b] & 0x0F);
                    px[b * 2 + 1] = (byte)(packed[b] >> 4);
                }
                return px;
            }
            // 8bpp: each u32 = 4 consecutive index bytes (65536 -> 256x256).
            return packed;
        }

        /// <summary>Loads a .txc with explicit dimensions (for non-standard sizes).</summary>
        public static Ps2TxcBinaryReader FromFile(string path, int width, int height)
            => FromBytes(File.ReadAllBytes(path), width, height, path);

        public static Ps2TxcBinaryReader FromBytes(byte[] data, int width, int height, string path = "")
        {
            if (data.Length != checked(width * height))
                throw new InvalidDataException(
                    $"txc size {data.Length} does not match {width}x{height} = {width * height}.");
            return new Ps2TxcBinaryReader
            {
                Indices = data,
                Width = width,
                Height = height,
                FilePath = path,
            };
        }

        /// <summary>Returns the palette index at (x, y).</summary>
        public byte GetIndex(int x, int y)
        {
            if (x < 0 || x >= Width || y < 0 || y >= Height)
                throw new ArgumentOutOfRangeException(nameof(x), "Coordinates outside texture bounds.");
            return Indices[y * Width + x];
        }

        /// <summary>
        /// Builds a 32bpp ARGB preview bitmap using the given CLUT.
        /// Alpha 0x80 (PS2 opaque) is doubled to 0xFF for display.
        /// </summary>
        public Bitmap BuildPreview(Ps2CltColorTableReader clut)
        {
            var bmp = new Bitmap(Width, Height, PixelFormat.Format32bppArgb);
            var rect = new Rectangle(0, 0, Width, Height);
            var bd = bmp.LockBits(rect, ImageLockMode.WriteOnly, PixelFormat.Format32bppArgb);
            try
            {
                int stride = bd.Stride;
                var row = new byte[stride];
                for (int y = 0; y < Height; y++)
                {
                    for (int x = 0; x < Width; x++)
                    {
                        var e = clut.GetEntry(Indices[y * Width + x]);
                        int o = x * 4;
                        row[o + 0] = e.B;
                        row[o + 1] = e.G;
                        row[o + 2] = e.R;
                        row[o + 3] = (byte)(e.A == 0 ? 0 : 0xFF); // 0x80 opaque -> 0xFF
                    }
                    Marshal.Copy(row, 0, bd.Scan0 + y * stride, stride);
                }
            }
            finally
            {
                bmp.UnlockBits(bd);
            }
            return bmp;
        }

        /// <summary>Saves the preview PNG to disk (requires a paired .clt).</summary>
        public void SavePreviewPng(string pngPath, Ps2CltColorTableReader clut)
        {
            using var bmp = BuildPreview(clut);
            bmp.Save(pngPath, ImageFormat.Png);
        }
    }
}
