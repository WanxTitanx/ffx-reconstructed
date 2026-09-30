// Fixtures.cs — regenerate the legacy counterexample fixtures (oracle doc §4)
// with the CORRECTED writer, to prove CE1..CE5 are closed on the exact shapes
// that used to fail (800/1600 plain, 1600ent = high-entropy names that used to
// overflow the manifest u16 zsize).
using System;
using System.Collections.Generic;
using System.IO;
using Psarc;

class Fixtures
{
    static int Main(string[] args)
    {
        string outDir = args[0];
        // 800 files, 1-byte content (legacy: I3/I4/B3 FAIL at 79,200-byte manifest).
        Build(outDir + "/writer_fixed_800.psarc", 800, false);
        // 1600 files, 1-byte content (legacy: I3/I4/B3 FAIL at 235,200-byte manifest).
        Build(outDir + "/writer_fixed_1600.psarc", 1600, false);
        // 1600 high-entropy names (legacy: CE4 u16 overflow, 147,952-byte stream).
        Build(outDir + "/writer_fixed_1600ent.psarc", 1600, true);
        return 0;
    }

    static void Build(string path, int n, bool entropy)
    {
        var files = new List<PsarcFileEntry>(n);
        var rng = new Random(20260914);
        for (int i = 0; i < n; i++)
        {
            string name = entropy
                ? "/r/" + RandName(rng) + "/" + i
                : "/dir_" + (i % 13) + "/file_" + i + "_payload_name_padding.bin";
            files.Add(new PsarcFileEntry(name, new byte[] { (byte)i }));
        }
        PsarcWriter.BuildPsarc(files, path);
        Console.WriteLine($"{path}: {new FileInfo(path).Length} bytes");
    }

    static string RandName(Random r)
    {
        const string letters = "abcdefghijklmnopqrstuvwxyz";
        var c = new char[48];
        for (int i = 0; i < c.Length; i++) c[i] = letters[r.Next(26)];
        return new string(c);
    }
}
