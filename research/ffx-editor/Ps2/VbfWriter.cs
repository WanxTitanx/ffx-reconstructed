using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
namespace FFXProjectEditor.FfxLib.Ps2
{
    internal sealed record VbfFileEntry(string Path, byte[] Data);
    // VbfWriter (portado de kaldaien/VBFExtract ← topher-au, 2026-08-19; adaptado para o FFXProjectEditor)
    internal static class VbfWriter
    {
        public const uint Magic = 1264144979; public const int BlockSize = 65536; const uint IgnoredEntryField = 4002806;
        public static void BuildVbf(string id, string o) { if (!Directory.Exists(id)) throw new DirectoryNotFoundException("dir not found"); var df = Directory.EnumerateFiles(id, "*.*", SearchOption.AllDirectories).OrderBy(p => p, StringComparer.OrdinalIgnoreCase).ToArray(); using var v = new FileStream(o, FileMode.Create, FileAccess.ReadWrite); BC(v, df.Length, i => FN(id, df[i].ToLowerInvariant()), i => new FileInfo(df[i]).Length, i => File.OpenRead(df[i])); }
        public static void BuildVbf(IReadOnlyList<VbfFileEntry> f, string o) { using var v = new FileStream(o, FileMode.Create, FileAccess.ReadWrite); BC(v, f.Count, i => NP(f[i].Path), i => f[i].Data.LongLength, i => new MemoryStream(f[i].Data, false)); }
        public static byte[] BuildVbfBytes(IReadOnlyList<VbfFileEntry> f) { using var v = new MemoryStream(); BC(v, f.Count, i => NP(f[i].Path), i => f[i].Data.LongLength, i => new MemoryStream(f[i].Data, false)); return v.ToArray(); }
        static void BC(Stream vbf, int fc, Func<int, string> gp, Func<int, long> gs, Func<int, Stream> os) { var h = new byte[fc][]; var sz = new ulong[fc]; var fo = new ulong[fc]; var so = new ulong[fc]; var bls = new uint[fc];
            using (var stt = new MemoryStream()) { for (int i = 0; i < fc; i++) { var nb = Encoding.UTF8.GetBytes(gp(i)); h[i] = MD5.HashData(nb); fo[i] = (uint)stt.Position; stt.Write(nb, 0, nb.Length); stt.WriteByte(0); sz[i] = (ulong)gs(i); } var st = stt.ToArray(); using var w = new BinaryWriter(vbf, Encoding.UTF8, leaveOpen: true);
                w.Write(Magic); w.Write((uint)0); w.Write((ulong)fc); foreach (var hh in h) w.Write(hh); long pbi = w.BaseStream.Position; w.BaseStream.Seek(32L * fc, SeekOrigin.Current); w.Write((uint)st.Length + 4); w.Write(st);
                ulong bc = 0; foreach (var s in sz) { bc += s / BlockSize; if (s % BlockSize != 0) bc++; } var bs = new ushort[bc]; long bsp = w.BaseStream.Position; long vhl = bsp + 2L * (long)bc; w.BaseStream.Seek(vhl, SeekOrigin.Begin); int cb = 0;
                for (int fi = 0; fi < fc; fi++) { using var sf = os(fi); long fb = sf.Length / BlockSize; if (sf.Length % BlockSize != 0) fb++; bls[fi] = (uint)cb; so[fi] = (ulong)vbf.Position;
                    for (int bi = 0; bi < fb; bi++) { bool last = bi == fb - 1; long ssz = BlockSize; if (last) ssz = sf.Length - sf.Position; var sb = new byte[ssz]; sf.ReadExactly(sb); byte[] db; if (!last) { using var dm = new MemoryStream(); using (var ds = new DeflateStream(dm, CompressionMode.Compress)) ds.Write(sb); db = dm.ToArray(); } else db = sb;
                        if (db.Length >= BlockSize || last) { db = sb; bs[cb] = db.Length == BlockSize ? (ushort)0 : (ushort)ssz; } else { w.Write((ushort)0); bs[cb] = (ushort)(db.Length + 2); } w.Write(db); cb++; } }
                w.BaseStream.Seek(bsp, SeekOrigin.Begin); foreach (var s in bs) w.Write(s); w.BaseStream.Seek(pbi, SeekOrigin.Begin); for (int f = 0; f < fc; f++) { w.Write(bls[f]); w.Write(IgnoredEntryField); w.Write(sz[f]); w.Write(so[f]); w.Write(fo[f]); }
                vbf.Seek(4, SeekOrigin.Begin); w.Write((uint)vhl); vbf.Seek(0, SeekOrigin.Begin); var buf = new byte[(int)vhl]; vbf.ReadExactly(buf); var fh = MD5.HashData(buf); vbf.Seek(0, SeekOrigin.End); vbf.Write(fh); } }
        static string FN(string id, string fn) { return fn.Substring(id.Length + 1).Replace((char)92, (char)47); }
        static string NP(string p) { return p.Replace((char)92, (char)47).ToLowerInvariant(); }
    }
}