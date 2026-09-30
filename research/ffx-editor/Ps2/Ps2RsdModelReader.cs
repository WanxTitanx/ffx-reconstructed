// Ps2RsdModelReader.cs
// Standalone reader for the PS2 FFX .rsd model bundle manifest (MatEditor toolchain).
// RE: textual source format of the Square MatEditor; compiled to .chr/.mgrp/.omd.
// Cross-validated against 230 real files in yonishi_data/dat_et/encount{,2}/rsd/ and
// yonishi_data/dat_ov/mag_XXXX/rsd/.
// RESEARCH ONLY -- not integrated into FFXProjectEditor.
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Ps2
{
    // .rsd = ASCII manifest "@RSD940102" that points at the sibling model files.
    // Layout (all lines ASCII, CRLF or LF, '#' = comment):
    //   @RSD940102
    //   # Created by MatEditor
    //   PLY=<name>.PLY      -> mesh geometry (see Ps2PlyModelReader)
    //   MAT=<name>.MA2      -> material table (see Ps2Ma2MaterialReader)
    //   GRP=<name>.GRP      -> group table (optional; only ripou*.grp exist)
    //   # Number of TIM(Texture) Files
    //   NTEX=<n>
    //   TEX[0]=<name>.tm2   -> texture, resolved in sibling ..\tim\ folder
    //   VGR=<name>.VGR      -> vertex group table (optional)
    // Observed: every real .rsd has exactly NTEX=1. Keys are case-insensitive
    // (files are .PLY/.MA2/.GRP/.VGR uppercase, textures lowercase .tm2).
    public sealed class Ps2RsdManifest
    {
        public string Magic { get; init; } = "";
        public string PlyName { get; init; } = "";
        public string MatName { get; init; } = "";
        public string GrpName { get; init; } = "";
        public string VgrName { get; init; } = "";
        public int TextureCount { get; init; }
        public IReadOnlyList<string> TextureNames { get; init; } = Array.Empty<string>();
        public string SourcePath { get; init; } = "";

        public static Ps2RsdManifest? Read(string path)
        {
            if (!File.Exists(path)) return null;
            string[] lines;
            try { lines = File.ReadAllLines(path); }
            catch { return null; }
            if (lines.Length == 0 || !lines[0].StartsWith("@RSD", StringComparison.Ordinal)) return null;

            string ply = "", mat = "", grp = "", vgr = "";
            int ntex = 0;
            var tex = new List<string>();
            foreach (string raw in lines)
            {
                string line = raw.Trim();
                if (line.StartsWith("PLY=", StringComparison.OrdinalIgnoreCase)) ply = line[4..].Trim();
                else if (line.StartsWith("MAT=", StringComparison.OrdinalIgnoreCase)) mat = line[4..].Trim();
                else if (line.StartsWith("GRP=", StringComparison.OrdinalIgnoreCase)) grp = line[4..].Trim();
                else if (line.StartsWith("VGR=", StringComparison.OrdinalIgnoreCase)) vgr = line[4..].Trim();
                else if (line.StartsWith("NTEX=", StringComparison.OrdinalIgnoreCase))
                    int.TryParse(line[5..].Trim(), out ntex);
                else if (line.StartsWith("TEX[", StringComparison.OrdinalIgnoreCase))
                {
                    int eq = line.IndexOf('=');
                    if (eq >= 0)
                    {
                        string t = line[(eq + 1)..].Trim();
                        if (t.Length > 0) tex.Add(t);
                    }
                }
            }

            return new Ps2RsdManifest
            {
                Magic = lines[0].Trim(),
                PlyName = ply,
                MatName = mat,
                GrpName = grp,
                VgrName = vgr,
                TextureCount = ntex,
                TextureNames = tex,
                SourcePath = path
            };
        }

        // Resolves the texture path: .rsd lives in <dir>/rsd/, textures in <dir>/tim/.
        public string? ResolveTexturePath(string textureName)
        {
            string dir = Path.GetDirectoryName(SourcePath) ?? "";
            string timDir = Path.Combine(dir, "..", "tim");
            string candidate = Path.Combine(timDir, textureName);
            return File.Exists(candidate) ? candidate : null;
        }

        public string? ResolveSiblingPath(string fileName)
        {
            string dir = Path.GetDirectoryName(SourcePath) ?? "";
            string candidate = Path.Combine(dir, fileName);
            return File.Exists(candidate) ? candidate : null;
        }
    }
}
