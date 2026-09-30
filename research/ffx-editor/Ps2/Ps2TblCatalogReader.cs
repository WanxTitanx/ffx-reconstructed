using System;
using System.Buffers.Binary;
using System.IO;

namespace FFXProjectEditor.FfxLib.Ps2
{
    // ── Ps2TblCatalogReader ──
    // FFX PS2 .tbl model catalog reader/writer.
    // Source: docs/reverse/FFX_STRUCTURE_COMPLETE_2026-08-17.md §8.19.
    //
    // These files live in chr/<categoria>/<categoria>.tbl and map a resource ID
    // (the array position) to a model index (the value), which resolves the
    // actual .chr file under chr/<categoria>/<model>/mdl/<model>.chr.
    //
    // Format (verified against real files, all little-endian):
    //   u16 count
    //   u16 indices[count]
    // Real sizes match exactly: mon.tbl 698B (348), npc.tbl 480B (239),
    // obj.tbl 236B (117), pc.tbl 72B (35), skl.tbl 86B (42). The indices are
    // mostly sequential but NOT contiguous (gaps exist, e.g. npc.tbl skips 7).
    //
    // MAINT: the count is u16, NOT u32 — a u32 read of mon.tbl's first 4 bytes
    // (0x5C01 0000) would yield 0x15C = 348 only by coincidence of the second
    // u16 being 0; npc.tbl (0xEF00 0100) proves the header is u16.
    public enum Ps2TblCatalogType
    {
        Unknown,
        Mon,
        Npc,
        Obj,
        Pc,
        Skl,
        Sum,
        Wep
    }

    internal sealed class Ps2TblCatalog
    {
        public Ps2TblCatalogType Type;
        public byte[] RawData = Array.Empty<byte>();
        public ushort Count;
        public ushort[] Indices = Array.Empty<ushort>();
        public string Summary => $"{Type} catalog: {Count} entries";
    }

    internal static class Ps2TblCatalogReader
    {
        const int HeaderSize = 2;

        public static Ps2TblCatalog? ReadFile(string path)
        {
            try
            {
                return ParseBytes(File.ReadAllBytes(path), InferType(path));
            }
            catch
            {
                return null;
            }
        }

        public static Ps2TblCatalog? ParseBytes(byte[] data, Ps2TblCatalogType type)
        {
            if (data.Length < HeaderSize)
                return null;

            ushort count = U16(data, 0);
            int needed = HeaderSize + count * 2;
            if (data.Length < needed)
                return null;

            var catalog = new Ps2TblCatalog { Type = type, RawData = data, Count = count };
            catalog.Indices = new ushort[count];
            for (int i = 0; i < count; i++)
                catalog.Indices[i] = U16(data, HeaderSize + i * 2);
            return catalog;
        }

        // ── Type inference ──
        // The file is conventionally named after its category and sits in a
        // folder of the same name (chr/mon/mon.tbl). Prefer the file stem,
        // fall back to the parent directory name.
        static Ps2TblCatalogType InferType(string path)
        {
            string stem = Path.GetFileNameWithoutExtension(path);
            string dir = Path.GetFileName(Path.GetDirectoryName(path) ?? "");
            string key = stem.Length > 0 ? stem : dir;
            switch (key.ToLowerInvariant())
            {
                case "mon": return Ps2TblCatalogType.Mon;
                case "npc": return Ps2TblCatalogType.Npc;
                case "obj": return Ps2TblCatalogType.Obj;
                case "pc": return Ps2TblCatalogType.Pc;
                case "skl": return Ps2TblCatalogType.Skl;
                case "sum": return Ps2TblCatalogType.Sum;
                case "wep": return Ps2TblCatalogType.Wep;
                default: return Ps2TblCatalogType.Unknown;
            }
        }

        static ushort U16(byte[] d, int o) => BinaryPrimitives.ReadUInt16LittleEndian(d.AsSpan(o));
    }

    // ── Ps2TblCatalogWriter ──
    // Re-emits a .tbl catalog preserving byte-identical output when no edits
    // are made (RT0). When the caller resizes Indices (Count changed), the
    // file is rebuilt from scratch.
    internal static class Ps2TblCatalogWriter
    {
        const int HeaderSize = 2;

        public static void Write(Ps2TblCatalog catalog, Stream stream)
        {
            int expected = HeaderSize + catalog.Count * 2;
            byte[] output;
            if (catalog.RawData.Length == expected && catalog.Indices.Length == catalog.Count)
            {
                output = (byte[])catalog.RawData.Clone();
                WriteU16(output, 0, catalog.Count);
                for (int i = 0; i < catalog.Count; i++)
                    WriteU16(output, HeaderSize + i * 2, catalog.Indices[i]);
            }
            else
            {
                output = new byte[expected];
                WriteU16(output, 0, catalog.Count);
                for (int i = 0; i < catalog.Count; i++)
                    WriteU16(output, HeaderSize + i * 2, catalog.Indices[i]);
            }
            stream.Write(output, 0, output.Length);
        }

        public static void WriteToFile(Ps2TblCatalog catalog, string path)
        {
            using var fs = new FileStream(path, FileMode.Create, FileAccess.Write, FileShare.None);
            Write(catalog, fs);
        }

        public static byte[] RoundTrip(byte[] input, Ps2TblCatalogType type)
        {
            var catalog = Ps2TblCatalogReader.ParseBytes(input, type);
            if (catalog == null)
                throw new InvalidDataException("Failed to parse .tbl catalog");
            using var ms = new MemoryStream(input.Length);
            Write(catalog, ms);
            return ms.ToArray();
        }

        static void WriteU16(byte[] d, int o, ushort v) => BinaryPrimitives.WriteUInt16LittleEndian(d.AsSpan(o), v);
    }
}
