// Ps2FtcFontReader.cs - PS2 FFX FTCX font file reader (research tool)
// Source: FFX PS2 jppc/menu/base.ftc + fahrenheit/src/core/ftcx.cs
// Date: 2026-08-19, RE by Jarvis-GENERAL

using System;
using System.IO;
using System.Text;

namespace Ps2ResearchTools
{
    /// <summary>
    /// PS2 FFX FTCX font file reader. Format documented in:
    /// docs/reverse/FFX_FTC_FONT_FORMAT_2026-08-19.md
    /// </summary>
    public class Ps2FtcFontReader
    {
        public struct FtcxHeader
        {
            public uint   Magic;
            public ushort Reserved1;      // always 200 (must be > 199)
            public ushort Reserved2;      // always 1556
            public ushort Type;           // 0=menu, 2=battle, 3=help
            public ushort Reserved3;
            public uint   Reserved4;
            public uint   TileCount;
            public ushort TileWidth;      // always 14
            public ushort TileHeight;     // always 18
            public uint   Padding1;
            public uint   Padding2;
            public uint   ImageDataPtr;
            public uint   ImageDataSize;
            public ushort ImageWidth;
            public ushort ImageHeight;
            public uint   ImagePadding;
            public uint   WidthTablePtr;
            public uint   WidthTableSize;
            public uint   WidthPad1;
            public uint   WidthPad2;
        }

        public FtcxHeader Header { get; private set; }
        public byte[] ImageData { get; private set; }
        public byte[] WidthTable { get; private set; }
        public string FilePath { get; private set; }

        public int TileSlots =>
            (Header.ImageWidth / Header.TileWidth) *
            (Header.ImageHeight / Header.TileHeight);
        public int TilesPerRow => Header.ImageWidth / Header.TileWidth;
        public int TileRows => Header.ImageHeight / Header.TileHeight;
        public int RowStride => Header.ImageWidth / 2;
        // FIX 2026-09-15 (validation wave): magic corrected to the real little-endian
        // FTCX value 0x58435446 per errata A3-E1 (0x58544346 spells "FCTX" and matches
        // ZERO real files; census 1,534/1,534 — see FFX_CODEC scripts + validation report).
        public bool IsValid => Header.Magic == 0x58435446;
        public bool HasImage => Header.ImageDataSize > 0;

        public static Ps2FtcFontReader FromFile(string path)
        {
            var r = new Ps2FtcFontReader { FilePath = path };
            byte[] d = File.ReadAllBytes(path);
            if (d.Length < 64) throw new InvalidDataException("Too small");
            r.Header = Parse(d);
            if (!r.IsValid) throw new InvalidDataException($"Not FTCX: 0x{r.Header.Magic:X}");
            if (r.Header.ImageDataPtr + r.Header.ImageDataSize <= d.Length)
                r.ImageData = new ReadOnlySpan<byte>(d,
                    (int)r.Header.ImageDataPtr, (int)r.Header.ImageDataSize).ToArray();
            if (r.Header.WidthTablePtr + r.Header.WidthTableSize <= d.Length)
                r.WidthTable = new ReadOnlySpan<byte>(d,
                    (int)r.Header.WidthTablePtr, (int)r.Header.WidthTableSize).ToArray();
            return r;
        }

        public int GetPixel(int x, int y)
        {
            if (ImageData == null) return 0;
            int off = y * RowStride + x / 2;
            if (off < 0 || off >= ImageData.Length) return 0;
            return (x & 1) == 0 ? (ImageData[off] >> 4) & 0xF : ImageData[off] & 0xF;
        }

        public int GetWidth(int i) =>
            WidthTable != null && i >= 0 && i < WidthTable.Length ? WidthTable[i] : 0;

        public string GlyphAscii(int idx, string p = " .:-=+*#%@")
        {
            if (ImageData == null) return "(no data)";
            int tx = (idx % TilesPerRow) * Header.TileWidth;
            int ty = (idx / TilesPerRow) * Header.TileHeight;
            var sb = new StringBuilder();
            for (int y = 0; y < Header.TileHeight; y++)
            {
                for (int x = 0; x < Header.TileWidth; x++)
                {
                    int v = GetPixel(tx + x, ty + y);
                    sb.Append(p[Math.Min(v * (p.Length - 1) / 15, p.Length - 1)]);
                }
                if (y < Header.TileHeight - 1) sb.AppendLine();
            }
            return sb.ToString();
        }

        public override string ToString()
            => $"FTCX[{Path.GetFileName(FilePath)}] t={Header.Type} " +
               $"tiles={Header.TileCount} {Header.TileWidth}x{Header.TileHeight} " +
               $"img={Header.ImageWidth}x{Header.ImageHeight} slots={TileSlots}";

        static FtcxHeader Parse(byte[] d) => new FtcxHeader
        {
            Magic=Br.U32(d,0), Reserved1=Br.U16(d,4), Reserved2=Br.U16(d,6),
            Type=Br.U16(d,8), Reserved3=Br.U16(d,0x0A), Reserved4=Br.U32(d,0x0C),
            TileCount=Br.U32(d,0x10), TileWidth=Br.U16(d,0x14),
            TileHeight=Br.U16(d,0x16), Padding1=Br.U32(d,0x18),
            Padding2=Br.U32(d,0x1C), ImageDataPtr=Br.U32(d,0x20),
            ImageDataSize=Br.U32(d,0x24), ImageWidth=Br.U16(d,0x28),
            ImageHeight=Br.U16(d,0x2A), ImagePadding=Br.U32(d,0x2C),
            WidthTablePtr=Br.U32(d,0x30), WidthTableSize=Br.U32(d,0x34),
            WidthPad1=Br.U32(d,0x38), WidthPad2=Br.U32(d,0x3C),
        };

        static class Br
        {
            public static uint U32(byte[] d, int o) =>
                (uint)d[o]|((uint)d[o+1]<<8)|((uint)d[o+2]<<16)|((uint)d[o+3]<<24);
            public static ushort U16(byte[] d, int o) =>
                (ushort)(d[o]|((uint)d[o+1]<<8));
        }
    }
}
