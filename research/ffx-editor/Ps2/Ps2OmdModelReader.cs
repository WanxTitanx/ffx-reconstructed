// Ps2OmdModelReader.cs
// Standalone reader for PS2 FFX .omd (2D sprite mesh) format used by the
// Sphere Grid (Abmap) system for cursor, lights, spheres, and grade indicators.
// RE: FFX_Menu2D_RenderCaptureNoTexture (0xA657C0), FFX_Menu2D_BuildNoTextureVertices.
// Cross-validated against real files in eiichi_abmap_data/omd/.
// RESEARCH ONLY -- not integrated into FFXProjectEditor.
// FIX 2026-09-15 (FFX-STRUCTURES validation): add missing `using System.IO;`
// (File/InvalidDataException were unresolved -> CS0103/CS0246 in standalone build).
using System;
using System.IO;
using System.Text;
namespace Ps2
{
    // .omd: 2D sprite mesh format
    // Found in: eiichi_abmap_data/omd/*.omd, yonishi_data/.../enc_*.omd
    // Header(0x20): count(u32=4), sec1off(u32), sec2off(u32), sec3off(u32), entryCount(i16), vertCount(i16), u14(i16), u16(i16), 8B reserved
    // Section1: typeDependent mesh entries; Section2: vertex array(3xi16 stride 6); Section3: ref vertex array
    public sealed class Ps2OmdFile
    {
        public uint SectionCount { get; init; }
        public uint Section1Offset { get; init; }
        public uint Section2Offset { get; init; }
        public uint Section3Offset { get; init; }
        public short EntryCount { get; init; }
        public short VertexCount { get; init; }
        public byte EntryType { get; init; }
        public OmdVertex[] Vertices { get; init; } = Array.Empty<OmdVertex>();
        public OmdVertex[] RefVertices { get; init; } = Array.Empty<OmdVertex>();
        public OmdSection[] Sections { get; init; } = Array.Empty<OmdSection>();
        public record struct OmdVertex(short X, short Y, short Z);
        public record struct OmdSection(byte Type, ushort Count, OmdEntry[] Entries);
        // Raw entry fields (indices are type-dependent; see doc table)
        public record struct OmdEntry(
            byte C0, byte C1, byte C2, byte C3,
            ushort I0, ushort I1, ushort I2, ushort I3,
            ushort H0, ushort H1, ushort H2, ushort H3,
            ushort H4, ushort H5);

        public static Ps2OmdFile Read(string path) => Read(File.ReadAllBytes(path));
        public static Ps2OmdFile Read(byte[] data)
        {
            if (data.Length < 0x20) throw new InvalidDataException("Too small for .omd header");
            uint s1 = BitConverter.ToUInt32(data, 4);
            uint s2 = BitConverter.ToUInt32(data, 8);
            uint s3 = BitConverter.ToUInt32(data, 0x0C);
            short vc = BitConverter.ToInt16(data, 0x12);
            byte et = data[s1 + 1];
            // FIX 2026-09-15 (FFX-STRUCTURES validation): cast vc to int —
            // Math.Max(short,int-literal) is ambiguous between the short and int
            // overloads (CS0121); widening first is semantics-identical.
            var v = ReadVerts(data, (int)s2, Math.Max((int)vc, 0));
            int rc = s3 > s2 ? (data.Length - (int)s3) / 6 : 0;
            var rv = ReadVerts(data, (int)s3, rc);
            var sections = ReadSections(data, (int)s1);
            return new Ps2OmdFile
            {
                SectionCount = BitConverter.ToUInt32(data, 0),
                Section1Offset = s1, Section2Offset = s2, Section3Offset = s3,
                EntryCount = BitConverter.ToInt16(data, 0x10),
                VertexCount = vc, EntryType = et,
                Vertices = v, RefVertices = rv,
                Sections = sections
            };
        }
        // Section header (0x10B): +0x00 u8 0 | +0x01 u8 type | +0x02 u16 count | +0x04..+0x0F extra
        // Entry strides by type (see FFX_Menu2D_RenderCaptureNoTexture switch @0xA65B24):
        //   0=0x14,1=0x1C,2=0x20,3=0x28,4=0x18,5=0x20,6=0x28,7=0x30
        private static readonly int[] TypeStride = { 0x14, 0x1C, 0x20, 0x28, 0x18, 0x20, 0x28, 0x30 };
        private static OmdSection[] ReadSections(byte[] d, int sec1Off)
        {
            var list = new System.Collections.Generic.List<OmdSection>();
            int p = sec1Off;
            while (p + 0x10 <= d.Length)
            {
                byte type = d[p + 1];
                ushort count = BitConverter.ToUInt16(d, p + 2);
                if (type > 7) break; // terminator / non-section
                var entries = new OmdEntry[count];
                int stride = TypeStride[type];
                int ep = p + 0x10;
                for (int i = 0; i < count && ep + stride <= d.Length; i++, ep += stride)
                {
                    entries[i] = new OmdEntry(
                        d[ep], d[ep + 1], d[ep + 2], d[ep + 3],
                        BitConverter.ToUInt16(d, ep + 0x0C), BitConverter.ToUInt16(d, ep + 0x0E),
                        BitConverter.ToUInt16(d, ep + 0x10), BitConverter.ToUInt16(d, ep + 0x12),
                        BitConverter.ToUInt16(d, ep + 0x14), BitConverter.ToUInt16(d, ep + 0x16),
                        BitConverter.ToUInt16(d, ep + 0x18), BitConverter.ToUInt16(d, ep + 0x1A),
                        BitConverter.ToUInt16(d, ep + 0x1C), BitConverter.ToUInt16(d, ep + 0x1E));
                }
                list.Add(new OmdSection(type, count, entries));
                p += 0x10 + count * stride;
            }
            return list.ToArray();
        }
        private static OmdVertex[] ReadVerts(byte[] d, int off, int n)
        {
            var r = new OmdVertex[n];
            for (int i = 0; i < n; i++)
            {
                int o = off + i * 6;
                r[i] = new OmdVertex(BitConverter.ToInt16(d, o), BitConverter.ToInt16(d, o + 2), BitConverter.ToInt16(d, o + 4));
            }
            return r;
        }
    }
}
