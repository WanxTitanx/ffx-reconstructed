// Ps2PlyModelReader.cs
// Standalone reader for the PS2 FFX .ply polygon mesh (MatEditor toolchain).
// RE: textual source format of the Square MatEditor; compiled to .chr/.mgrp/.omd.
// Cross-validated against 230 real files in yonishi_data/dat_et/encount{,2}/rsd/ and
// yonishi_data/dat_ov/mag_XXXX/rsd/.
// RESEARCH ONLY -- not integrated into FFXProjectEditor.
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;

namespace Ps2
{
    // .ply = ASCII mesh "@PLY940102".
    // Layout:
    //   @PLY940102
    //   # Created by MatEditor
    //   # Number of Vertices, Normals, and Polygons
    //   NV NN NP
    //   # Vertex
    //   <NV lines of "X Y Z" floats>
    //   # Normal
    //   <NN lines of "X Y Z" floats>
    //   # Polygon
    //   <NP lines of "flag v0 v1 v2 v3 n0 n1 n2 n3">
    //
    // Polygon line = ALWAYS 9 tokens:
    //   flag : 1 = quad (4 vertices), 0 = triangle (v3 = 0 degenerate)
    //   v0..v3 : vertex indices into the Vertex section
    //   n0..n3 : normal indices into the Normal section (n3 unused for triangles)
    // Observed: NP (polygon count) == .ma2 item count for every file (1 material/polygon).
    // Counts observed: NV 6..86, NN 5..42, NP 5..84. Mixed flag 0/1 files exist
    // (e.g. enc_003.ply = 3 quads + 2 triangles).
    public sealed class Ps2PlyModel
    {
        public string Magic { get; init; } = "";
        public int VertexCount { get; init; }
        public int NormalCount { get; init; }
        public int PolygonCount { get; init; }
        public IReadOnlyList<Vec3> Vertices { get; init; } = Array.Empty<Vec3>();
        public IReadOnlyList<Vec3> Normals { get; init; } = Array.Empty<Vec3>();
        public IReadOnlyList<PlyPolygon> Polygons { get; init; } = Array.Empty<PlyPolygon>();
        public string SourcePath { get; init; } = "";

        public readonly record struct Vec3(float X, float Y, float Z);
        public readonly record struct PlyPolygon(int Flag, int V0, int V1, int V2, int V3, int N0, int N1, int N2, int N3)
        {
            public bool IsQuad => Flag == 1;
        }

        public static Ps2PlyModel? Read(string path)
        {
            if (!File.Exists(path)) return null;
            string[] lines;
            try { lines = File.ReadAllLines(path); }
            catch { return null; }
            if (lines.Length == 0 || !lines[0].StartsWith("@PLY", StringComparison.Ordinal)) return null;

            int nv = 0, nn = 0, np = 0;
            var verts = new List<Vec3>();
            var norms = new List<Vec3>();
            var polys = new List<PlyPolygon>();
            string section = "";
            bool countsRead = false;

            for (int i = 0; i < lines.Length; i++)
            {
                string line = lines[i].Trim();
                if (line.Length == 0) continue;

                // Section comment headers (these start with # but are NOT ignored)
                if (line.StartsWith("# Vertex", StringComparison.OrdinalIgnoreCase)) { section = "v"; continue; }
                if (line.StartsWith("# Normal", StringComparison.OrdinalIgnoreCase)) { section = "n"; continue; }
                if (line.StartsWith("# Polygon", StringComparison.OrdinalIgnoreCase)) { section = "p"; continue; }

                // Skip all other comments and the magic line
                if (line.StartsWith("@") || line.StartsWith("#")) continue;

                // Counts line: "NV NN NP" (first numeric line before any section)
                if (!countsRead)
                {
                    string[] c = line.Split([' ', '\t'], StringSplitOptions.RemoveEmptyEntries);
                    if (c.Length >= 3
                        && int.TryParse(c[0], out nv)
                        && int.TryParse(c[1], out nn)
                        && int.TryParse(c[2], out np))
                    {
                        countsRead = true;
                        continue;
                    }
                }

                string[] parts = line.Split([' ', '\t'], StringSplitOptions.RemoveEmptyEntries);
                switch (section)
                {
                    case "v" when parts.Length >= 3:
                        if (TryVec3(parts, out var v)) verts.Add(v);
                        break;
                    case "n" when parts.Length >= 3:
                        if (TryVec3(parts, out var n)) norms.Add(n);
                        break;
                    case "p" when parts.Length >= 9:
                        if (TryPoly(parts, out var p)) polys.Add(p);
                        break;
                }
            }

            return new Ps2PlyModel
            {
                Magic = lines[0].Trim(),
                VertexCount = nv,
                NormalCount = nn,
                PolygonCount = np,
                Vertices = verts,
                Normals = norms,
                Polygons = polys,
                SourcePath = path
            };
        }

        static bool TryVec3(string[] parts, out Vec3 v)
        {
            v = default;
            if (float.TryParse(parts[0], NumberStyles.Float, CultureInfo.InvariantCulture, out float x)
                && float.TryParse(parts[1], NumberStyles.Float, CultureInfo.InvariantCulture, out float y)
                && float.TryParse(parts[2], NumberStyles.Float, CultureInfo.InvariantCulture, out float z))
            {
                v = new Vec3(x, y, z);
                return true;
            }
            return false;
        }

        static bool TryPoly(string[] parts, out PlyPolygon p)
        {
            p = default;
            if (int.TryParse(parts[0], out int flag)
                && int.TryParse(parts[1], out int v0)
                && int.TryParse(parts[2], out int v1)
                && int.TryParse(parts[3], out int v2)
                && int.TryParse(parts[4], out int v3)
                && int.TryParse(parts[5], out int n0)
                && int.TryParse(parts[6], out int n1)
                && int.TryParse(parts[7], out int n2)
                && int.TryParse(parts[8], out int n3))
            {
                p = new PlyPolygon(flag, v0, v1, v2, v3, n0, n1, n2, n3);
                return true;
            }
            return false;
        }
    }
}
