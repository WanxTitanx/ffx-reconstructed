// _vbf_test.cs — harness for VbfReader/VbfWriter/VbfFile (research_tools/Ps2).
// Lane: FMT-ARCHIVE audit (2026-09-16). Mirrors the proven semantics of
// vbf_reader.py: SRYK header, MD5-path table, 32B entries, block list u16
// (0 = stored 64KB; else zlib-with-2B-header; last-block RAW when
// storedSize == remainder), MD5-of-header footer.
//
// Usage:
//   dotnet run --project _vbf_test.csproj -- <vbf> <verifyRoot> [sampleN]
//     verifyRoot = dir containing the vbf paths (e.g. extracted corpus root)
//   dotnet run --project _vbf_test.csproj -- --roundtrip
//     writer RT0: build a synthetic vbf in memory, re-read, byte-compare.
//
// Exit 0 only when every check passes.
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using FFXProjectEditor.FfxLib.Ps2;

class Program
{
    static int failures = 0;
    static void Check(bool ok, string what)
    {
        Console.WriteLine($"  [{(ok ? "OK" : "FAIL")}] {what}");
        if (!ok) failures++;
    }

    static int Main(string[] args)
    {
        if (args.Length >= 1 && args[0] == "--roundtrip")
            return Roundtrip();
        if (args.Length < 2)
        {
            Console.WriteLine("usage: _vbf_test <vbf> <verifyRoot> [sampleN] | --roundtrip");
            return 2;
        }
        string vbfPath = args[0];
        string root = args[1];
        int sample = args.Length > 2 ? int.Parse(args[2]) : 0;

        var vbf = VbfFile.Open(vbfPath);
        Console.WriteLine($"opened {vbfPath}: NumFiles={vbf.NumFiles}");
        var names = vbf.FileNames;
        Check(names.Count == (int)vbf.NumFiles, $"FileNames count {names.Count} == NumFiles {vbf.NumFiles}");

        // header/footer integrity already enforced inside VbfReader.Pr()
        // (bad footer -> VbfFormatException). Reaching here = footer MD5 OK.
        Check(true, "footer MD5 verified by reader (no exception on Load)");

        // MD5-path lookup round-trip: every listed name must be Contains().
        int miss = 0;
        foreach (var n in names)
            if (!vbf.Contains(n)) miss++;
        Check(miss == 0, $"Contains(name) hit for all entries (misses={miss})");

        // Extract + byte-compare vs corpus (all entries or an even sample).
        var idxs = new List<int>();
        if (sample > 0 && sample < names.Count)
        {
            double step = (double)names.Count / sample;
            for (int k = 0; k < sample; k++) idxs.Add((int)(k * step));
        }
        else for (int i = 0; i < names.Count; i++) idxs.Add(i);

        int ok = 0, bad = 0, missing = 0;
        foreach (int i in idxs)
        {
            string n = names[i];
            string disk = Path.Combine(root, n.Replace('/', Path.DirectorySeparatorChar));
            if (!File.Exists(disk)) { missing++; continue; }
            if (!vbf.TryExtract(n, out byte[]? d)) { bad++; Console.WriteLine($"    FAIL extract {n}"); continue; }
            byte[] refb = File.ReadAllBytes(disk);
            if (d!.Length == refb.Length && d.AsSpan().SequenceEqual(refb)) ok++;
            else { bad++; Console.WriteLine($"    FAIL bytes {n} ({d.Length} vs {refb.Length})"); }
        }
        Check(bad == 0, $"extract verify: {ok} ok / {bad} mismatch / {missing} missing (of {idxs.Count})");
        Console.WriteLine(failures == 0 ? "ALL CHECKS OK" : failures + " FAILURES");
        return failures == 0 ? 0 : 1;
    }

    // Writer RT0: synthesize entries (compressible, incompressible, empty,
    // exact-64KB, 64KB+small-tail), build vbf bytes, re-read, byte-compare.
    static int Roundtrip()
    {
        var rnd = new Random(20260916);
        var entries = new List<VbfFileEntry>
        {
            new("dir/a_compressible.bin", Fill(200000, 7)),
            new("dir/b_incompressible.bin", Rand(rnd, 65536 * 2 + 300)),
            new("dir/c_empty.bin", Array.Empty<byte>()),
            new("dir/d_exact64k.bin", Fill(65536, 3)),
            new("dir/e_small.bin", new byte[] { 1, 2, 3 }),
        };
        byte[] blob = VbfFile.RepackBytes(entries);
        Check(blob.Length > 16, $"repacked {blob.Length} bytes");
        Check(BitConverter.ToUInt32(blob, 0) == 1264144979u, "magic SRYK");

        var r = new VbfReader();
        r.Load(blob);
        Check(r.NumFiles == (ulong)entries.Count, $"NumFiles {r.NumFiles} == {entries.Count}");
        int ok = 0, bad = 0;
        foreach (var e in entries)
        {
            if (!r.TryExtractFile(e.Path, out byte[]? d)) { bad++; Console.WriteLine($"    FAIL missing {e.Path}"); continue; }
            if (d!.AsSpan().SequenceEqual(e.Data)) ok++;
            else { bad++; Console.WriteLine($"    FAIL bytes {e.Path} ({d.Length} vs {e.Data.Length})"); }
        }
        Check(bad == 0, $"roundtrip: {ok} ok / {bad} bad of {entries.Count}");
        Console.WriteLine(failures == 0 ? "ALL CHECKS OK" : failures + " FAILURES");
        return failures == 0 ? 0 : 1;
    }

    static byte[] Fill(int n, byte v) { var b = new byte[n]; Array.Fill(b, v); return b; }
    static byte[] Rand(Random r, int n) { var b = new byte[n]; r.NextBytes(b); return b; }
}
