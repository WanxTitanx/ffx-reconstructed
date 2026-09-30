// Ps2AnmAnimationReader.cs
// Standalone reader for PS2 FFX .anm (texture descriptor) and .an2 (UV-scroll)
// formats used by the Sphere Grid (Abmap) and Magic Host systems.
// RE: FFX_SphereGrid_InitRuntimeStateFromAbmapResources, FFX_Abmap_InitPlacementGrid.
// Cross-validated against real files in eiichi_abmap_data/anm/ and maho/anm/.
// RESEARCH ONLY -- not integrated into FFXProjectEditor.
// FIX 2026-09-15 (FFX-STRUCTURES validation): add missing `using System.IO;`
// (File/InvalidDataException were unresolved -> CS0103/CS0246 in standalone build).
using System;
using System.IO;
using System.Text;
namespace Ps2
{
    // .anm: Magic texture descriptor + animation table
    // Found in: eiichi_abmap_data/maho/anm/*.anm
    // Layout: magic(0346) + 12B reserved + strLen(u32) + texName(str) + uv(8x u16) + fc(u16) + flag(u16) + 40B reserved + table(N x 8B)
    public sealed class Ps2AnmFile
    {
        public uint Magic { get; init; }
        public string TextureName { get; init; } = "";
        public ushort[] UvData { get; init; } = Array.Empty<ushort>();
        public ushort FrameCount { get; init; }
        public ushort UnknownFlag { get; init; }
        public AnmTableEntry[] Table { get; init; } = Array.Empty<AnmTableEntry>();
        public AnmUvGeometry[] UvGeometry { get; init; } = Array.Empty<AnmUvGeometry>();
        public record struct AnmTableEntry(uint KeyframeIndex, uint TargetValue);
        // UV geometry descriptor (entries 4-11 of the table): i16 coords + scroll + RGBA
        public record struct AnmUvGeometry(short MinX, short MinY, short MaxX, short MaxY, byte R, byte G, byte B, byte A);
        public static Ps2AnmFile Read(string path) => Read(File.ReadAllBytes(path));
        public static Ps2AnmFile Read(byte[] data)
        {
            if (data.Length < 0x14) throw new InvalidDataException("Too small for .anm header");
            uint magic = BitConverter.ToUInt32(data, 0);
            if (magic != 0x0346) throw new InvalidDataException($"Bad .anm magic: 0x{magic:X8}");
            uint strLen = BitConverter.ToUInt32(data, 0x10);
            if (strLen > 256 || 0x14 + strLen > data.Length)
                throw new InvalidDataException($"Invalid string length: {strLen}");
            string texName = Encoding.ASCII.GetString(data, 0x14, (int)strLen).TrimEnd('\0');
            int p = 0x14 + (int)strLen;
            ushort[] uv = new ushort[8];
            for (int i = 0; i < 8; i++) uv[i] = BitConverter.ToUInt16(data, p + i * 2);
            ushort fc = BitConverter.ToUInt16(data, p + 16);
            ushort uf = BitConverter.ToUInt16(data, p + 18);
            int tableStart = p + 60; // 40B reserved after fc/flag
            int ec = (data.Length - tableStart) / 8;
            var t = new AnmTableEntry[ec];
            for (int i = 0; i < ec; i++)
            {
                int o = tableStart + i * 8;
                t[i] = new AnmTableEntry(BitConverter.ToUInt32(data, o), BitConverter.ToUInt32(data, o + 4));
            }
            // UV geometry descriptor region (entries 4-11 = file offset tableStart+0x20 .. +0x60).
            // These are i16 UV rectangle coords + scroll rates + RGBA, NOT keyframe pairs.
            var uvGeo = new AnmUvGeometry[Math.Min(8, Math.Max(0, ec - 4))];
            for (int i = 0; i < uvGeo.Length; i++)
            {
                int o = tableStart + (4 + i) * 8;
                uvGeo[i] = new AnmUvGeometry(
                    BitConverter.ToInt16(data, o), BitConverter.ToInt16(data, o + 2),
                    BitConverter.ToInt16(data, o + 4), BitConverter.ToInt16(data, o + 6),
                    data[o + 8], data[o + 9], data[o + 10], data[o + 11]);
            }
            return new Ps2AnmFile { Magic = magic, TextureName = texName, UvData = uv, FrameCount = fc, UnknownFlag = uf, Table = t, UvGeometry = uvGeo };
        }
    }

    // .an2: UV-scroll animation
    // Found in: eiichi_abmap_data/anm/*.an2, maho/anm/*.an2
    // Layout: magic(0346) + fc(u16) + fc2(u16) + 4B reserved + 0(u16) + fileSize(u16) + firstFrameOff(u16) + 0x200(u16) + pairs + frames(0x40 each)
    public sealed class Ps2An2File
    {
        public uint Magic { get; init; }
        public ushort FrameCount { get; init; }
        public ushort FileSize { get; init; }
        public ushort FirstFrameOffset { get; init; }
        public An2Frame[] Frames { get; init; } = Array.Empty<An2Frame>();
        public record struct An2Frame(
            ushort C0, ushort C1, ushort C2, ushort C3,
            float ScaleA, float ScaleB,
            short MinX, short MinY, short MaxX, short MaxY,
            byte R0, byte G0, byte B0, byte A0,
            byte R1, byte G1, byte B1, byte A1);
        public static Ps2An2File Read(string path) => Read(File.ReadAllBytes(path));
        public static Ps2An2File Read(byte[] data)
        {
            if (data.Length < 0x20) throw new InvalidDataException("Too small for .an2 header");
            uint magic = BitConverter.ToUInt32(data, 0);
            if (magic != 0x0346) throw new InvalidDataException($"Bad .an2 magic: 0x{magic:X8}");
            ushort fc = BitConverter.ToUInt16(data, 4);
            ushort fs = BitConverter.ToUInt16(data, 0x0E);
            ushort ff = BitConverter.ToUInt16(data, 0x10);
            var frames = new An2Frame[fc];
            for (int f = 0; f < fc; f++)
            {
                int off = fc <= 1 ? ff : BitConverter.ToUInt16(data, 0x14 + f * 8);
                if (off + 0x40 > data.Length) break;
                frames[f] = new An2Frame(
                    BitConverter.ToUInt16(data, off), BitConverter.ToUInt16(data, off + 2),
                    BitConverter.ToUInt16(data, off + 4), BitConverter.ToUInt16(data, off + 6),
                    BitConverter.ToSingle(data, off + 0x10), BitConverter.ToSingle(data, off + 0x14),
                    BitConverter.ToInt16(data, off + 0x20), BitConverter.ToInt16(data, off + 0x22),
                    BitConverter.ToInt16(data, off + 0x2C), BitConverter.ToInt16(data, off + 0x2E),
                    data[off + 0x38], data[off + 0x39], data[off + 0x3A], data[off + 0x3B],
                    data[off + 0x3C], data[off + 0x3D], data[off + 0x3E], data[off + 0x3F]);
            }
            return new Ps2An2File { Magic = magic, FrameCount = fc, FileSize = fs, FirstFrameOffset = ff, Frames = frames };
        }
    }
}
