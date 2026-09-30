using System;
using System.Collections.Generic;
using System.IO;
namespace FFXProjectEditor.FfxLib.Ps2
{
    // VbfFile (portado de kaldaien/VBFExtract ← topher-au, 2026-08-19; adaptado para o FFXProjectEditor)
    internal sealed class VbfFile
    {
        readonly VbfReader _r; public string VbfPath { get; } public ulong NumFiles => _r.NumFiles; public IReadOnlyList<string> FileNames => _r.FileNames;
        VbfFile(string vp, VbfReader r) { VbfPath = vp; _r = r; }
        public static VbfFile Open(string vp) { var r = new VbfReader(); r.Load(vp); return new VbfFile(vp, r); }
        public bool Contains(string ip) => _r.ContainsFile(ip); public bool TryExtract(string ip, out byte[]? d) => _r.TryExtractFile(ip, out d); public bool Extract(string ip, string op) => _r.ExtractFileContents(ip, op);
        public int ExtractAll(string od) { Directory.CreateDirectory(od); int c = 0; foreach (var n in FileNames) { if (!_r.TryExtractFile(n, out byte[]? d)) continue; var dest = Path.Combine(od, n.Replace((char)47, Path.DirectorySeparatorChar)); var dir = Path.GetDirectoryName(dest); if (!string.IsNullOrEmpty(dir)) Directory.CreateDirectory(dir); File.WriteAllBytes(dest, d); c++; } return c; }
        public static void Repack(string id, string o) => VbfWriter.BuildVbf(id, o); public static void Repack(IReadOnlyList<VbfFileEntry> f, string o) => VbfWriter.BuildVbf(f, o); public static byte[] RepackBytes(IReadOnlyList<VbfFileEntry> f) => VbfWriter.BuildVbfBytes(f);
    }
}