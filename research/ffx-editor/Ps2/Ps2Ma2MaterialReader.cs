// Ps2Ma2MaterialReader.cs
// Standalone reader for the PS2 FFX .ma2 material table (MatEditor toolchain).
// RE: textual source format of the Square MatEditor; compiled to .chr/.mgrp/.omd.
// Cross-validated against 230 real files (2348 items) in yonishi_data/dat_et/encount{,2}/rsd/
// and yonishi_data/dat_ov/mag_XXXX/rsd/.
// RESEARCH ONLY -- not integrated into FFXProjectEditor.
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;

namespace Ps2
{
    public sealed class Ps2Material
    {
        public int Index { get; init; }
        public int TextureFlag { get; init; }
        public int CompiledSize { get; init; }
        public uint TextureId { get; init; }
        public char Flag1 { get; init; } // 'F' or 'G'
        public char Flag2 { get; init; } // 'H' = textured, 'G' = untextured
        public int Separator { get; init; }
        public UvCoord Uv0 { get; init; }
        public UvCoord Uv1 { get; init; }
        public UvCoord Uv2 { get; init; }
        public UvCoord Uv3 { get; init; }
        public Color4 Rgba0 { get; init; }
        public Color4 Rgba1 { get; init; }
        public Color4 Rgba2 { get; init; }
        public Color4 Rgba3 { get; init; }

        public bool IsTextured => Flag2 == 'H';
        public string TextureIdHex => TextureId.ToString("X8");

        public readonly record struct UvCoord(ushort U, ushort V);
        public readonly record struct Color4(byte R, byte G, byte B, byte A);
    }

    public sealed class Ps2Ma2File
    {
        public string Magic { get; init; } = "";
        public int ItemCount { get; init; }
        public IReadOnlyList<Ps2Material> Items { get; init; } = Array.Empty<Ps2Material>();
        public string SourcePath { get; init; } = "";

        public static Ps2Ma2File? Read(string path)
        {
            if (!File.Exists(path)) return null;
            string[] lines;
            try { lines = File.ReadAllLines(path); }
            catch { return null; }
            if (lines.Length == 0 || !lines[0].StartsWith("@MAT", StringComparison.Ordinal)) return null;

            int count = 0;
            var items = new List<Ps2Material>();
            bool countRead = false;

            for (int i = 0; i < lines.Length; i++)
            {
                string line = lines[i].Trim();
                if (line.Length == 0) continue;
                if (line.StartsWith("@") || line.StartsWith("#")) continue;

                if (!countRead)
                {
                    if (int.TryParse(line, out count))
                    {
                        countRead = true;
                        continue;
                    }
                }

                string[] tokens = line.Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
                if (tokens.Length >= 25 && int.TryParse(tokens[0], out _))
                {
                    Ps2Material? m = ParseItem(tokens);
                    if (m != null) items.Add(m);
                }
            }

            return new Ps2Ma2File
            {
                Magic = lines[0].Trim(),
                ItemCount = count,
                Items = items,
                SourcePath = path
            };
        }

        static Ps2Material? ParseItem(string[] t)
        {
            if (!int.TryParse(t[0], out int index)) return null;
            if (!int.TryParse(t[1], out int texFlag)) return null;
            if (!int.TryParse(t[2], out int size)) return null;
            if (!uint.TryParse(t[3], NumberStyles.HexNumber, null, out uint texId)) return null;

            if (t.Length >= 9 && t[7].Length == 1 && t[8].Length == 1)
            {
                char f1 = t[7][0];
                char f2 = t[8][0];

                if (f2 == 'H')
                {
                    // Textured: 34 tokens
                    // index texFlag size texId f1 f2 f3 flag1 H sep
                    // u1 v1 u2 v2 u3 v3 u4 v4   (tokens 10..17)
                    // r1 g1 b1 a1 r2 g2 b2 a2 r3 g3 b3 a3 r4 g4 b4 a4  (tokens 18..33)
                    if (t.Length < 34) return null;
                    int sep = int.TryParse(t[9], out int s) ? s : 0;
                    return new Ps2Material
                    {
                        Index = index, TextureFlag = texFlag, CompiledSize = size,
                        TextureId = texId, Flag1 = f1, Flag2 = f2, Separator = sep,
                        Uv0 = ParseUv(t, 10), Uv1 = ParseUv(t, 12),
                        Uv2 = ParseUv(t, 14), Uv3 = ParseUv(t, 16),
                        Rgba0 = ParseRgba(t, 18), Rgba1 = ParseRgba(t, 22),
                        Rgba2 = ParseRgba(t, 26), Rgba3 = ParseRgba(t, 30)
                    };
                }
                if (f2 == 'G')
                {
                    // Untextured: 25 tokens (no sep, no UVs)
                    // index texFlag size texId f1 f2 f3 flag1 G
                    // r1 g1 b1 a1 r2 g2 b2 a2 r3 g3 b3 a3 r4 g4 b4 a4
                    if (t.Length < 25) return null;
                    return new Ps2Material
                    {
                        Index = index, TextureFlag = texFlag, CompiledSize = size,
                        TextureId = texId, Flag1 = f1, Flag2 = f2, Separator = 0,
                        Uv0 = default, Uv1 = default, Uv2 = default, Uv3 = default,
                        Rgba0 = ParseRgba(t, 9), Rgba1 = ParseRgba(t, 13),
                        Rgba2 = ParseRgba(t, 17), Rgba3 = ParseRgba(t, 21)
                    };
                }
            }
            return null;
        }

        static Ps2Material.UvCoord ParseUv(string[] t, int off)
        {
            ushort u = ushort.TryParse(t[off], out ushort u0) ? u0 : (ushort)0;
            ushort v = ushort.TryParse(t[off + 1], out ushort v0) ? v0 : (ushort)0;
            return new Ps2Material.UvCoord(u, v);
        }

        static Ps2Material.Color4 ParseRgba(string[] t, int off)
        {
            byte r = byte.TryParse(t[off], out byte r0) ? r0 : (byte)0;
            byte g = byte.TryParse(t[off + 1], out byte g0) ? g0 : (byte)0;
            byte b = byte.TryParse(t[off + 2], out byte b0) ? b0 : (byte)0;
            byte a = byte.TryParse(t[off + 3], out byte a0) ? a0 : (byte)0;
            return new Ps2Material.Color4(r, g, b, a);
        }
    }
}
