// Rt0Program.cs — RT0 repack driver (work scratch, not part of the repo source).
// Repacks the extracted FFX corpus back into a .psarc using the CORRECTED
// PsarcWriter, in the exact order of the original manifest (decoded here
// directly from the real archive, independently of the oracle artifacts).
//   usage: rt0pack <real.psarc> <corpusRoot> <out.psarc>
// Steps:
//   1. decode the real manifest (multiblock walk, strict semantics);
//   2. map every manifest name to corpusRoot/<name-without-leading-slash> and
//      verify existence + size == descriptor (fail fast, list up to 5 problems);
//   3. PsarcWriter.BuildPsarcFromFiles(sources, out.psarc) in manifest order;
//   4. report timings + slot/entry counters for cross-checking.
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Text;
using Psarc;

class Rt0Program
{
    static int Main(string[] args)
    {
        if (args.Length != 3)
        {
            Console.WriteLine("usage: rt0pack <real.psarc> <corpusRoot> <out.psarc>");
            return 2;
        }
        string real = args[0], root = args[1], outPath = args[2];
        var swAll = Stopwatch.StartNew();

        // ── 1. Decode the original manifest ──
        byte[] hdr;
        int tocLength, count, blockSize;
        byte[] tocBlob;
        ushort[] zs;
        using (var f = File.OpenRead(real))
        {
            hdr = new byte[32];
            ReadExact(f, hdr, 32, real);
            tocLength = BE32(hdr, 12);
            count = BE32(hdr, 20);
            blockSize = BE32(hdr, 24);
            tocBlob = new byte[count * 30];
            ReadExact(f, tocBlob, tocBlob.Length, real);
            int tableBytes = tocLength - 32 - count * 30;
            byte[] zblob = new byte[tableBytes];
            ReadExact(f, zblob, tableBytes, real);
            zs = new ushort[tableBytes / 2];
            for (int i = 0; i < zs.Length; i++) zs[i] = (ushort)((zblob[i * 2] << 8) | zblob[i * 2 + 1]);
        }
        Console.WriteLine($"real: toc_length={tocLength} entries={count} block_size={blockSize} slots={zs.Length}");

        long e0Size = BE40(tocBlob, 20);
        long e0Off = BE40(tocBlob, 25);
        byte[] manifestRaw;
        using (var f = File.OpenRead(real))
        {
            f.Seek(e0Off, SeekOrigin.Begin);
            var ms = new MemoryStream();
            long remaining = e0Size;
            int slot = 0;
            while (remaining > 0)
            {
                int expected = (int)Math.Min(blockSize, remaining);
                int z = zs[slot];
                byte[] blk;
                int consume;
                if (z == expected && z != 0) { blk = new byte[z]; ReadExact(f, blk, z, real); consume = z; }
                else if (z == 0 && expected == blockSize) { blk = new byte[blockSize]; ReadExact(f, blk, blockSize, real); consume = blockSize; }
                else
                {
                    byte[] comp = new byte[z];
                    ReadExact(f, comp, z, real);
                    using var s = new MemoryStream(comp);
                    using var dz = new ZLibStream(s, CompressionMode.Decompress);
                    using var o = new MemoryStream();
                    dz.CopyTo(o);
                    blk = o.ToArray();
                    if (blk.Length != expected) throw new InvalidDataException(
                        $"manifest block {slot}: inflated {blk.Length}, expected {expected}");
                    consume = z;
                }
                ms.Write(blk, 0, blk.Length);
                remaining -= blk.Length;
                slot++;
            }
            manifestRaw = ms.ToArray();
        }
        string manifestText = Encoding.UTF8.GetString(manifestRaw);
        string[] names = manifestText.Split('\n');
        bool noTrailingLf = !manifestText.EndsWith("\n");
        bool allSlash = Array.TrueForAll(names, n => n.StartsWith("/"));
        Console.WriteLine($"manifest: {names.Length} names, {manifestText.Length} bytes, noTrailingLF={noTrailingLf}, allStartSlash={allSlash}");
        if (!noTrailingLf || !allSlash || names.Length != count - 1)
        {
            Console.WriteLine("MANIFEST DECODE MISMATCH — aborting");
            return 1;
        }

        // ── 2. Map names to corpus files and verify sizes ──
        var sources = new List<PsarcSourceEntry>(names.Length);
        int missing = 0, sizeMismatch = 0;
        long totalLogical = 0;
        for (int i = 0; i < names.Length; i++)
        {
            string p = Path.Combine(root, names[i].TrimStart('/'));
            long descSize = BE40(tocBlob, (i + 1) * 30 + 20);
            FileInfo fi;
            try { fi = new FileInfo(p); } catch (Exception) { fi = null; }
            if (fi == null || !fi.Exists)
            {
                if (++missing <= 5) Console.WriteLine($"  MISSING: {names[i]}");
                continue;
            }
            if (fi.Length != descSize)
            {
                if (++sizeMismatch <= 5)
                    Console.WriteLine($"  SIZE MISMATCH: {names[i]} corpus={fi.Length} descriptor={descSize}");
                continue;
            }
            totalLogical += descSize;
            sources.Add(new PsarcSourceEntry(names[i], p));
        }
        Console.WriteLine($"corpus mapping: ok={sources.Count}/{names.Length} missing={missing} sizeMismatch={sizeMismatch} totalLogical={totalLogical}");
        if (missing > 0 || sizeMismatch > 0 || sources.Count != names.Length)
        {
            Console.WriteLine("CORPUS MAPPING FAILED — aborting");
            return 1;
        }

        // ── 3. Repack with the corrected writer, in manifest order ──
        var swPack = Stopwatch.StartNew();
        PsarcWriter.BuildPsarcFromFiles(sources, outPath);
        swPack.Stop();
        var fiOut = new FileInfo(outPath);
        Console.WriteLine($"packed: {fiOut.Length} bytes in {swPack.Elapsed} (real: {new FileInfo(real).Length})");
        Console.WriteLine($"total elapsed: {swAll.Elapsed}");
        return 0;
    }

    static int BE32(byte[] d, int o) => (d[o] << 24) | (d[o + 1] << 16) | (d[o + 2] << 8) | d[o + 3];
    static long BE40(byte[] d, int o)
    {
        long v = 0;
        for (int i = 0; i < 5; i++) v = (v << 8) | d[o + i];
        return v;
    }
    static void ReadExact(FileStream f, byte[] buf, int count, string what)
    {
        int read = 0;
        while (read < count)
        {
            int k = f.Read(buf, read, count - read);
            if (k <= 0) throw new EndOfStreamException($"EOF reading {what} at {f.Position}");
            read += k;
        }
    }
}
