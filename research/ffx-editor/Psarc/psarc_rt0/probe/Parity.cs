// Parity.cs — compress real logical blocks at zlib level 9 via .NET
// (CompressionLevel.SmallestSize == Z_BEST_COMPRESSION) and write the output
// next to the input for byte comparison against the original streams.
using System;
using System.IO;
using System.IO.Compression;

class Parity
{
    static int Main(string[] args)
    {
        foreach (string rawPath in Directory.GetFiles(args[0], "*.raw"))
        {
            byte[] raw = File.ReadAllBytes(rawPath);
            using var c = new MemoryStream();
            using (var z = new ZLibStream(c, CompressionLevel.SmallestSize, leaveOpen: true))
                z.Write(raw, 0, raw.Length);
            File.WriteAllBytes(Path.ChangeExtension(rawPath, ".net9"), c.ToArray());
        }
        return 0;
    }
}
