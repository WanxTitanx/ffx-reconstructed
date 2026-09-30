using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text;

namespace FFXProjectEditor.FfxLib.Ps2
{
    internal sealed class VbfFormatException : Exception
    {
        public VbfFormatException(string m) : base(m) { }
        public VbfFormatException(string m, Exception i) : base(m, i) { }
    }
    // VbfReader (portado de kaldaien/VBFExtract ← topher-au, 2026-08-19; adaptado para o FFXProjectEditor)
    internal sealed class VbfReader
    {
        public const uint Magic = 1264144979;
        public const int BlockSize = 65536;
        public ulong NumFiles => _n;
        string? _fp; byte[]? _d; ushort[] _bl = []; uint[] _bls = []; string[] _md5s = [];
        Dictionary<string, int> _mi = new(StringComparer.Ordinal); ulong _n;
        ulong[] _os = []; ulong[] _so = []; byte[] _st = []; string[]? _fn;
        public void Load(string p) { _fp = p; _d = null; using var fs = File.Open(p, FileMode.Open, FileAccess.Read, FileShare.Read); Pr(fs); }
        public void Load(byte[] b) { if (b == null) throw new ArgumentNullException(nameof(b)); _fp = null; _d = b; using var ms = new MemoryStream(b, false); Pr(ms); }
        public IReadOnlyList<string> FileNames => _fn ??= RFL();
        public bool ContainsFile(string p) => _mi.ContainsKey(CMD5(p));
        public bool TryExtractFile(string p, out byte[]? d) { d = null; if (!_mi.TryGetValue(CMD5(p), out int i)) return false; d = EB(i); return true; }
        public bool ExtractFileContents(string p, string o) { if (!TryExtractFile(p, out byte[]? d)) return false; File.WriteAllBytes(o, d); return true; }
        public string[] RFL() { if (_n == 0) return []; var t = Encoding.UTF8.GetString(_st).Trim((char)0); var l = t.Split((char)0); if ((ulong)l.Length != _n) throw new VbfFormatException("count mismatch"); return l; }
        void Pr(Stream fs)
        {
            using var br = new BinaryReader(fs, Encoding.UTF8, leaveOpen: true);
            uint m = br.ReadUInt32(); if (m != Magic) throw new VbfFormatException("bad magic");
            uint hl = br.ReadUInt32(); ulong nf = br.ReadUInt64();
            if (nf > 0xFFFFFF) throw new VbfFormatException("too many files");
            if (fs.Length < 16 + 48L * (long)nf + 4) throw new VbfFormatException("truncated");
            int n = (int)nf; _n = nf; _md5s = new string[n]; _bls = new uint[n]; _os = new ulong[n]; _so = new ulong[n];
            _mi = new Dictionary<string, int>(n, StringComparer.Ordinal);
            for (int i = 0; i < n; i++) { var h = br.ReadBytes(16); if (h.Length != 16) throw new VbfFormatException("md5 truncated"); _md5s[i] = Convert.ToHexString(h); _mi[_md5s[i]] = i; }
            for (int i = 0; i < n; i++) { _bls[i] = br.ReadUInt32(); br.ReadUInt32(); _os[i] = br.ReadUInt64(); _so[i] = br.ReadUInt64(); br.ReadUInt64(); }
            uint sts = br.ReadUInt32(); if (sts < 4) throw new VbfFormatException("st invalid");
            _st = br.ReadBytes((int)sts - 4); if (_st.Length != (int)sts - 4) throw new VbfFormatException("st truncated");
            ulong bc = 0; foreach (ulong s in _os) { bc += s / BlockSize; if (s % BlockSize != 0) bc++; }
            _bl = new ushort[bc]; try { for (int i = 0; i < (int)bc; i++) _bl[i] = br.ReadUInt16(); } catch (EndOfStreamException) { throw new VbfFormatException("bl truncated"); }
            if (hl < 16 || (long)hl + 16 > fs.Length) throw new VbfFormatException("hl invalid");
            fs.Seek(0, SeekOrigin.Begin); var hb = new byte[hl]; fs.ReadExactly(hb);
            fs.Seek(-16, SeekOrigin.End); var ft = new byte[16]; fs.ReadExactly(ft);
            if (!MD5.HashData(hb).AsSpan().SequenceEqual(ft)) throw new VbfFormatException("footer mismatch");
        }
        byte[] EB(int fi)
        {
            ulong os = _os[fi]; int bc = (int)(os / BlockSize); int br = (int)(os % BlockSize);
            if (br != 0) bc++; else br = BlockSize;
            ulong so = _so[fi]; int bls = (int)_bls[fi];
            using Stream src = _d != null ? new MemoryStream(_d, false) : File.Open(_fp!, FileMode.Open, FileAccess.Read, FileShare.Read);
            src.Seek((long)so, SeekOrigin.Begin); using var o = new MemoryStream();
            for (int bi = 0; bi < bc; bi++)
            {
                int bl = _bl[bls + bi]; if (bl == 0) bl = BlockSize;
                var cb = new byte[bl]; src.ReadExactly(cb);
                int ds = bi != bc - 1 ? BlockSize : br; byte[] db;
                if (bl != BlockSize) {
                    if (bi == bc - 1 && bl == br) db = cb;
                    else { try { db = new byte[ds]; using var d = new DeflateStream(new MemoryStream(cb, 2, bl - 2), CompressionMode.Decompress); d.ReadExactly(db); } catch (Exception ex) { throw new VbfFormatException(ex.Message, ex); } }
                } else db = cb;
                o.Write(db, 0, ds);
            }
            return o.ToArray();
        }
        static string CMD5(string p) { var n = p.Replace((char)92, (char)47).ToLowerInvariant(); return Convert.ToHexString(MD5.HashData(Encoding.UTF8.GetBytes(n))); }
    }
}