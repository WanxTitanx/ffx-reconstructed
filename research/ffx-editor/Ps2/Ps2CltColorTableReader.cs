// Ps2CltColorTableReader.cs - PS2 FFX CLUT reader (research tool)
// Format: raw 4096 bytes = 256 RGBA entries (4 bytes each)
// Source: FFX PS2 yonishi_data/dat/c_*.clt
// Date: 2026-08-19, RE by Jarvis-GENERAL

using System;
using System.IO;

namespace Ps2ResearchTools
{
    /// <summary>
    /// PS2 FFX CLUT (Color LookUp Table) reader.
    /// Each .clt file is exactly 4096 bytes = 256 entries x 4 bytes (RGBA).
    /// Byte order: R, G, B, A (PS2 GS 32-bit CLUT format).
    /// Alpha 0x80 = fully opaque, 0x00 = transparent.
    /// A .txc texture indexes into a .clt to get final colors.
    /// One .txc can have multiple .clt palettes (up to 4: c_XXXX_0..3).
    /// </summary>
    public class Ps2CltColorTableReader
    {
        public const int ENTRY_SIZE = 4;
        public const int MAX_ENTRIES = 256;

        public byte[] RawData { get; private set; }
        public string FilePath { get; private set; }
        public int EntryCount => RawData != null ? RawData.Length / ENTRY_SIZE : 0;

        public struct CltEntry
        {
            public byte R;
            public byte G;
            public byte B;
            public byte A;
            public override string ToString() => $"({R},{G},{B},{A})";
        }

        public static Ps2CltColorTableReader FromFile(string path)
        {
            var r = new Ps2CltColorTableReader { FilePath = path };
            r.RawData = File.ReadAllBytes(path);
            return r;
        }

        public CltEntry GetEntry(int index)
        {
            int off = index * ENTRY_SIZE;
            if (RawData == null || off + 4 > RawData.Length)
                return new CltEntry();
            return new CltEntry
            {
                R = RawData[off],
                G = RawData[off + 1],
                B = RawData[off + 2],
                A = RawData[off + 3],
            };
        }

        public override string ToString()
            => $"CLUT[{System.IO.Path.GetFileName(FilePath)}] {EntryCount} entries";
    }
}
