// _psarc_test.cs — harness for the oracle-corrected PsarcWriter (2026-09-14).
// The invariants asserted here mirror the format-oracle rules H4/H7/I3/I4/M3/
// B1/B2/B3 from docs/reverse/FFX_PSARC_WRITER_ORACLE_2026-09-14.md. For the
// full 24-rule audit of the produced archive, run afterwards:
//   python3 research_tools/Psarc/psarc_oracle.py test_out.psarc --expect-flags 2
// Exit code 0 only when every invariant holds.
//
// Fixture coverage:
//   - compressible files (zlib blocks) + round-trip;
//   - an EMPTY entry (must reserve exactly one zero zsize slot — rule I3);
//   - incompressible data of 2 full blocks + partial tail (full stored blocks
//     encode ZSize==0; the stored partial tail encodes ZSize==logical — CE5);
//   - 2-byte files (zlib never shrinks them: every one exercises a stored
//     partial tail with ZSize==logical);
//   - a manifest > 65536 raw bytes (multiblock: chained zsize slots — CE2/CE4).
using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Text;
using Psarc;

class Program
{
    static int failures = 0;

    static void Check(bool ok, string what)
    {
        Console.WriteLine($"  [{(ok ? "OK" : "FAIL")}] {what}");
        if (!ok) failures++;
    }

    static void Main()
    {
        var files = new List<PsarcFileEntry>
        {
            new("/subdir/pattern2.dat", MakeData(5678)),
            new("/subdir/pattern1.dat", MakeData(1234)),
            new("/subdir/pattern3.dat", MakeData(91011)),
            new("/subdir/pattern4.dat", MakeData(121314)),
            new("/subdir/empty.dat", Array.Empty<byte>()),
            new("/subdir/incompressible.bin", MakeData(65536 * 2 + 300)),
        };
        var expectedPaths = new List<string>();
        foreach (var f in files) expectedPaths.Add(f.Path);
        for (int k = 0; k < 2400; k++)
        {
            string p = $"/gen/dir_{k % 97:D2}/file_{k:D4}_payload_name_padding.bin";
            files.Add(new PsarcFileEntry(p, new byte[] { (byte)k, (byte)(k >> 8) }));
            expectedPaths.Add(p);
        }

        byte[] psarc = PsarcWriter.BuildPsarcBytes(files);
        File.WriteAllBytes("test_out.psarc", psarc);
        Console.WriteLine("psarc size: " + psarc.Length);

        // ── Header ──
        Console.WriteLine("magic: " + Encoding.ASCII.GetString(psarc, 0, 4));
        Console.WriteLine("major_minor: " + (psarc[4] << 8 | psarc[5]) + "." + (psarc[6] << 8 | psarc[7]));
        Console.WriteLine("compression: " + Encoding.ASCII.GetString(psarc, 8, 4));
        int tocLength = ReadU32BE(psarc, 0x0C);
        int sizeOfEntry = ReadU32BE(psarc, 0x10);
        int filesCount = ReadU32BE(psarc, 0x14);
        int blockSize = ReadU32BE(psarc, 0x18);
        int flags = ReadU32BE(psarc, 0x1C);
        Console.WriteLine($"toc_length={tocLength} size_of_entry={sizeOfEntry} files_count={filesCount} block_size={blockSize} flags={flags}");
        Check(Encoding.ASCII.GetString(psarc, 0, 4) == "PSAR", "H1 magic PSAR");
        Check((psarc[4] << 8 | psarc[5], psarc[6] << 8 | psarc[7]) == (1, 4), "H2 version 1.4");
        Check(Encoding.ASCII.GetString(psarc, 8, 4) == "zlib", "H3 compression zlib");
        Check(sizeOfEntry == 30, "H5 toc_entry_size 30");
        Check(blockSize == 65536, "H6 block_size 65536");
        Check(flags == 2, "H7 flags@0x1C == 2 (CE1)");

        int zsizesStart = 0x20 + filesCount * 30;

        // ── Manifest (entry 0): multiblock decode, LF join, no trailing LF ──
        var (manifest, manifestEnd, manifestZsizes) = WalkEntry(psarc, 0, zsizesStart, blockSize);
        string expectedManifest = string.Join("\n", expectedPaths);
        string gotManifest = Encoding.UTF8.GetString(manifest);
        Check(gotManifest == expectedManifest, "M1/M3 manifest == join(paths,'\\n') with NO trailing LF (CE3)");
        Check(manifest.Length == expectedManifest.Length && manifest[^1] != (byte)'\n', "M3 last byte is not LF");
        int manifestSlots = (manifest.Length + blockSize - 1) / blockSize;
        Check(manifestZsizes.Count == manifestSlots && manifestSlots >= 2,
            $"CE2 multiblock manifest: {manifestZsizes.Count} slots (raw {manifest.Length} bytes, expected {manifestSlots} blocks, >= 2)");
        foreach (int z in manifestZsizes)
            if (z >= 65536) { Check(false, "CE4 manifest zsize slot < 65536"); break; }

        // ── TOC structure: entry0 special, chain, offsets, toc_length ──
        Check(ReadU32BE(psarc, 0x20 + 16) == 0, "I1 entry0 zsize_index == 0");
        byte[] e0md5 = Slice(psarc, 0x20, 16);
        bool zeros = true;
        foreach (var b in e0md5) zeros &= b == 0;
        Check(zeros, "I1 entry0 MD5 all zeros");
        Check((long)Read40BE(psarc, 0x20 + 25) == tocLength, "I1 entry0 offset == toc_length");
        Check((long)Read40BE(psarc, 0x20 + 20) == manifest.Length, "entry0 logical size == manifest bytes");

        int totalSlots = manifestSlots;
        long expectedOffset = manifestEnd;
        int expectedIndex = manifestSlots;
        bool chainOk = true, offsetsOk = true;
        var roundtripOk = true;
        for (int i = 1; i < filesCount; i++)
        {
            int e = 0x20 + i * 30;
            int zi = ReadU32BE(psarc, e + 16);
            ulong usize = Read40BE(psarc, e + 20);
            long off = (long)Read40BE(psarc, e + 25);
            int nblocks = (int)((usize + (ulong)blockSize - 1) / (ulong)blockSize);
            int reserved = usize == 0 ? 1 : nblocks;
            if (zi != expectedIndex) { chainOk = false; Console.WriteLine($"    entry{i} zsize_index={zi} expected={expectedIndex}"); }
            if (off != expectedOffset) { offsetsOk = false; Console.WriteLine($"    entry{i} offset={off} expected={expectedOffset}"); }
            expectedIndex += reserved;
            totalSlots += reserved;

            if (usize == 0)
            {
                int slot = ReadU16BE(psarc, zsizesStart + zi * 2);
                Check(slot == 0, $"I3 empty entry{i} reserved slot value == 0");
            }
            else
            {
                var (data, end, _) = WalkEntry(psarc, i, zsizesStart, blockSize);
                byte[] orig = files[i - 1].Data;
                if (data.Length != orig.Length || Convert.ToHexString(data) != Convert.ToHexString(orig))
                { roundtripOk = false; Console.WriteLine($"    entry{i} roundtrip FAILED"); }
                expectedOffset = end;
            }
        }
        Check(chainOk, "I3 zsize_index chain sequential (incl. empty-entry reserved slots)");
        Check(offsetsOk, "I4 offset chain contiguous");
        Check(roundtripOk, "B3 round-trip: every entry decodes to its original bytes");
        Check(tocLength == 32 + filesCount * 30 + totalSlots * 2,
            $"H4 toc_length arithmetic (toc={tocLength}, slots={totalSlots})");
        Check(psarc.Length == expectedOffset, "B4 EOF exact (no bytes after last entry)");

        // ── Stored-block encodings (CE5) on the incompressible entry ──
        // entry 6 = incompressible.bin (index 5 in `files`, TOC entry 6): two full
        // stored blocks (ZSize==0) + one stored tail of 300 (ZSize==300).
        int zi6 = ReadU32BE(psarc, 0x20 + 6 * 30 + 16);
        int s0 = ReadU16BE(psarc, zsizesStart + zi6 * 2);
        int s1 = ReadU16BE(psarc, zsizesStart + (zi6 + 1) * 2);
        int s2 = ReadU16BE(psarc, zsizesStart + (zi6 + 2) * 2);
        Check(s0 == 0 && s1 == 0, $"CE5 full stored blocks encode ZSize==0 (got {s0},{s1})");
        Check(s2 == 300, $"CE5 stored partial tail encodes ZSize==logical (got {s2}, want 300)");

        Console.WriteLine(failures == 0 ? "ALL INVARIANTS OK" : failures + " FAILURES");
        Environment.Exit(failures == 0 ? 0 : 1);
    }

    /// <summary>Decodes one entry per the real-format block semantics:
    /// ZSize==logical (non-zero) -> stored raw tail; ZSize==0 with a full
    /// expected block -> stored raw 65536; otherwise strict zlib.</summary>
    static (byte[] data, long endOffset, List<int> zsizes) WalkEntry(
        byte[] psarc, int entryIdx, int zsizesStart, int blockSize)
    {
        int e = 0x20 + entryIdx * 30;
        int zi = ReadU32BE(psarc, e + 16);
        ulong usize = Read40BE(psarc, e + 20);
        long pos = (long)Read40BE(psarc, e + 25);
        var ms = new MemoryStream();
        var zs = new List<int>();
        long remaining = (long)usize;
        while (remaining > 0)
        {
            int slot = ReadU16BE(psarc, zsizesStart + (zi + zs.Count) * 2);
            zs.Add(slot);
            int expected = (int)Math.Min(blockSize, remaining);
            byte[] blk;
            if (slot == expected && slot != 0)
            {
                blk = Slice(psarc, pos, expected);                 // stored partial tail
                pos += expected;
            }
            else if (slot == 0 && expected == blockSize)
            {
                blk = Slice(psarc, pos, blockSize);                // stored full block
                pos += blockSize;
            }
            else
            {
                blk = ZLibDecompress(psarc, (int)pos, slot);       // strict zlib
                pos += slot;                                       // compressed bytes on disk
            }
            ms.Write(blk, 0, blk.Length);
            remaining -= blk.Length;
        }
        return (ms.ToArray(), pos, zs);
    }

    static byte[] MakeData(int n)
    {
        var r = new Random(n);
        var d = new byte[n];
        r.NextBytes(d);
        return d;
    }

    static byte[] Slice(byte[] d, long off, int len)
    {
        var b = new byte[len];
        Array.Copy(d, off, b, 0, len);
        return b;
    }

    static int ReadU32BE(byte[] d, int o) => (d[o] << 24) | (d[o + 1] << 16) | (d[o + 2] << 8) | d[o + 3];
    static int ReadU16BE(byte[] d, int o) => (d[o] << 8) | d[o + 1];
    static ulong Read40BE(byte[] d, int o)
    {
        ulong v = 0;
        for (int i = 0; i < 5; i++) v = (v << 8) | d[o + i];
        return v;
    }
    static byte[] ZLibDecompress(byte[] d, int off, int len)
    {
        using var ms = new MemoryStream(d, off, len);
        using var z = new ZLibStream(ms, CompressionMode.Decompress);
        using var outMs = new MemoryStream();
        z.CopyTo(outMs);
        return outMs.ToArray();
    }
}
