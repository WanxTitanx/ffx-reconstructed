using System;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;

class Probe
{
    static int Main(string[] args)
    {
        // arg1: file, arg2: offset, arg3: length  -> try strict zlib decode
        string path = args[0];
        int off = int.Parse(args[1]), len = int.Parse(args[2]);
        byte[] d = File.ReadAllBytes(path);
        Console.WriteLine($"first bytes: {Convert.ToHexString(d, off, Math.Min(8, len))}");
        try
        {
            using var ms = new MemoryStream(d, off, len);
            using var z = new ZLibStream(ms, CompressionMode.Decompress);
            using var o = new MemoryStream();
            z.CopyTo(o);
            Console.WriteLine($"ZLibStream decode OK: {o.Length} bytes, sha256={Convert.ToHexString(SHA256.HashData(o.ToArray()))}");
        }
        catch (Exception e) { Console.WriteLine("ZLibStream decode FAIL: " + e.Message); }

        // roundtrip: compress those decoded bytes ourselves at SmallestSize and re-decode
        try
        {
            using var ms = new MemoryStream(d, off, len);
            using var z = new ZLibStream(ms, CompressionMode.Decompress);
            using var o = new MemoryStream();
            z.CopyTo(o);
            byte[] raw = o.ToArray();
            using var c = new MemoryStream();
            using (var zc = new ZLibStream(c, CompressionLevel.SmallestSize, leaveOpen: true))
                zc.Write(raw, 0, raw.Length);
            byte[] comp = c.ToArray();
            Console.WriteLine($"recompress SmallestSize: {comp.Length} bytes (orig stream {len}); first={Convert.ToHexString(comp, 0, 2)}; identical={comp.Length == len && Convert.ToHexString(comp) == Convert.ToHexString(d, off, len)}");
            using var ms2 = new MemoryStream(comp);
            using var z2 = new ZLibStream(ms2, CompressionMode.Decompress);
            using var o2 = new MemoryStream();
            z2.CopyTo(o2);
            Console.WriteLine($"own-stream redecode OK: {o2.Length} bytes");
        }
        catch (Exception e) { Console.WriteLine("roundtrip FAIL: " + e.Message); }
        return 0;
    }
}
