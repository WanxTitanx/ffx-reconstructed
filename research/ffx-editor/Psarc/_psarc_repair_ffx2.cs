// _psarc_repair_ffx2.cs — structural repair driver for the damaged FFX-2_Data.psarc
// (PS3, 7,160,419,009 bytes, zeroed tail from ~offset 5,783,944,717 to EOF).
//
// MISSION (docs/reverse/FFX_LOST_WORK_RECOVERY_2026-09-15.md item 1): rebuild the
// archive from the preserved extraction (PSARC_EXTRACTED/FFX-2) in the EXACT
// order/names/logical sizes of the original TOC. The result is RT1-proven: a
// structurally valid, navigable container (passes all 24 oracle rules), NOT
// byte-identical to the original — the zeroed data tail is unrecoverable
// (PS3-HUNT verdict: artifacts/2026-09-15/ps3-hunt/REPORT.md); entries whose
// data lived in the damaged region are packed as-is from the extraction
// (zero-filled logical content), so the rebuilt archive recompresses them into
// VALID zlib streams instead of the raw zeroed bytes the damaged original has.
//
// Adapted from the RT0 repack driver (work/psarc_rt0_2026-09-14/rt0/Rt0Program.cs,
// which proved byte-exact repack of FFX_Data.psarc). Differences vs RT0:
//   - the source archive is the DAMAGED FFX-2_Data.psarc, read in-place
//     (FileShare.Read, read-only) ONLY to recover header + TOC + manifest
//     (all of which live below the damaged tail and are intact);
//   - no byte-identity target: zsizes/offsets after the first damaged block are
//     expected (and allowed) to differ from the original.
//
// Usage:
//   dotnet run --project _psarc_repair_ffx2.csproj -- \
//       <damaged-original.psarc> <extraction-root> <output.psarc>
//
// Pipeline: parse header/TOC -> strict-decode manifest (entry 0) -> map every
// name to extraction-root/<name-without-leading-slash> -> validate existence +
// logical size against the TOC (abort on any mismatch) -> stream-build via
// PsarcWriter.BuildPsarcFromFiles (zlib level 9, multiblock manifest, oracle
// rules CE1-CE5/I3 baked into the writer).
//
// RESEARCH ONLY — not integrated into FFXProjectEditor.
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Text;
using Psarc;

static class PsarcRepairFfx2
{
    static int Main(string[] args)
    {
        if (args.Length != 3)
        {
            Console.Error.WriteLine(
                "usage: PsarcRepairFfx2 <damaged-original.psarc> <extraction-root> <output.psarc>");
            return 2;
        }
        string originalPath = args[0];
        string extractionRoot = args[1];
        string outputPath = args[2];
        var swTotal = Stopwatch.StartNew();

        // ── 1. Header + TOC of the damaged original (read-only, intact prefix) ──
        using var orig = new FileStream(originalPath, FileMode.Open, FileAccess.Read,
            FileShare.Read, bufferSize: 1024 * 1024);
        var hdr = new byte[32];
        ReadExact(orig, hdr, 32, 0, originalPath);
        if (Encoding.ASCII.GetString(hdr, 0, 4) != "PSAR") { Console.Error.WriteLine("bad magic"); return 1; }
        uint tocLength = ReadU32BE(hdr, 0x0C);
        uint entrySize = ReadU32BE(hdr, 0x10);
        uint count = ReadU32BE(hdr, 0x14);
        uint blockSize = ReadU32BE(hdr, 0x18);
        uint flags = ReadU32BE(hdr, 0x1C);
        if (entrySize != 30 || blockSize != 65536) { Console.Error.WriteLine("unexpected TOC geometry"); return 1; }
        long zsizesStart = 32 + (long)count * 30;
        long totalSlots = (tocLength - zsizesStart) / 2;
        Console.WriteLine($"original: toc_length={tocLength} entries={count} block_size={blockSize} flags={flags} slots={totalSlots}");

        // TOC entries (30 bytes each, file offset 0x20) + the full ZSizes table.
        // toc[i*30 ..] is entry i; entry fields: md5@0, zsize_index@16, size@20, offset@25.
        var toc = new byte[(long)count * 30];
        ReadExact(orig, toc, toc.Length, 0x20, originalPath);
        var zbuf = new byte[totalSlots * 2];
        ReadExact(orig, zbuf, zbuf.Length, zsizesStart, originalPath);
        var zsizes = new ushort[totalSlots];
        for (int i = 0; i < totalSlots; i++) zsizes[i] = (ushort)(zbuf[i * 2] << 8 | zbuf[i * 2 + 1]);

        // ── 2. Manifest (entry 0): strict block decode straight from the file ──
        uint e0Zi = ReadU32BE(toc, 16);
        long e0Size = (long)ReadU40(toc, 20);
        long e0Offset = (long)ReadU40(toc, 25);
        if (e0Zi != 0) { Console.Error.WriteLine("entry0 zsize_index != 0"); return 1; }
        if (e0Offset != (long)tocLength) { Console.Error.WriteLine("entry0 offset != toc_length"); return 1; }
        byte[] manifestRaw = DecodeEntry(orig, zsizes, e0Zi, e0Size, e0Offset, (int)blockSize, originalPath);
        string[] names = Encoding.UTF8.GetString(manifestRaw).Split('\n');
        if (names.Length != count - 1)
        {
            Console.Error.WriteLine($"manifest names {names.Length} != files {count - 1}");
            return 1;
        }
        Console.WriteLine($"manifest: {names.Length} names, {manifestRaw.Length} bytes (entry0 size {e0Size})");

        // ── 3. Map every TOC name to the preserved extraction; validate first ──
        // WHY validate everything BEFORE packing: a 15+ minute streaming build must
        // never fail (or worse, silently shrink an entry) because one source file
        // was missing or resized after extraction.
        var files = new List<PsarcSourceEntry>((int)count - 1);
        int missing = 0, sizeMismatch = 0;
        long totalLogical = 0;
        for (int i = 1; i < count; i++)
        {
            int e = i * 30;
            long size = (long)ReadU40(toc, e + 20);
            string rel = names[i - 1].TrimStart('/');
            string src = Path.Combine(extractionRoot, rel);
            long diskSize;
            try { diskSize = new FileInfo(src).Length; }
            catch (Exception)
            {
                missing++;
                if (missing <= 5) Console.Error.WriteLine($"  MISSING: {src}");
                continue;
            }
            if (diskSize != size)
            {
                sizeMismatch++;
                if (sizeMismatch <= 5) Console.Error.WriteLine($"  SIZE MISMATCH: {src} toc={size} disk={diskSize}");
                continue;
            }
            totalLogical += size;
            files.Add(new PsarcSourceEntry(names[i - 1], src));
        }
        Console.WriteLine($"corpus mapping: ok={files.Count}/{count - 1} missing={missing} sizeMismatch={sizeMismatch} totalLogical={totalLogical}");
        if (missing != 0 || sizeMismatch != 0 || files.Count != count - 1)
        {
            Console.Error.WriteLine("ABORT: extraction does not satisfy the TOC 1:1");
            return 1;
        }

        // ── 4. Streaming rebuild (single pass, in-place TOC patch — see writer) ──
        var swPack = Stopwatch.StartNew();
        PsarcWriter.BuildPsarcFromFiles(files, outputPath);
        swPack.Stop();
        long outSize = new FileInfo(outputPath).Length;
        Console.WriteLine($"packed: {outSize} bytes in {swPack.Elapsed} (original: {orig.Length})");
        Console.WriteLine($"total elapsed: {swTotal.Elapsed}");
        return 0;
    }

    /// <summary>Strict per-block decode of one entry straight from the archive,
    /// with the real-file ZSize semantics (stored tail == logical, 0 + full ==
    /// stored full block, else strict zlib). Used only for entry 0 (manifest):
    /// payload entries are re-read from the extraction, not from the archive.</summary>
    static byte[] DecodeEntry(FileStream fs, ushort[] zsizes, uint zi, long size, long offset,
        int blockSize, string path)
    {
        using var outMs = new MemoryStream((int)Math.Min(size, 64L * 1024 * 1024));
        long pos = offset, remaining = size;
        int slotIdx = (int)zi;
        var block = new byte[blockSize];
        while (remaining > 0)
        {
            int expected = (int)Math.Min(blockSize, remaining);
            ushort z = zsizes[slotIdx++];
            if (z == expected && z != 0)
            {
                ReadExact(fs, block, expected, pos, path);           // stored partial tail
                outMs.Write(block, 0, expected);
                pos += expected;
            }
            else if (z == 0 && expected == blockSize)
            {
                ReadExact(fs, block, blockSize, pos, path);          // stored full block
                outMs.Write(block, 0, blockSize);
                pos += blockSize;
            }
            else
            {
                var comp = new byte[z];                              // strict zlib stream
                ReadExact(fs, comp, z, pos, path);
                using var ms = new MemoryStream(comp);
                using var zl = new ZLibStream(ms, CompressionMode.Decompress);
                zl.CopyTo(outMs);
                pos += z;
            }
            remaining -= expected;
        }
        return outMs.ToArray();
    }

    static void ReadExact(FileStream fs, byte[] buffer, int count, long fileOffset, string path)
    {
        fs.Seek(fileOffset, SeekOrigin.Begin);
        int read = 0;
        while (read < count)
        {
            int k = fs.Read(buffer, read, count - read);
            if (k <= 0) throw new EndOfStreamException(
                $"unexpected EOF in {path} at {fs.Position} ({read}/{count} bytes)");
            read += k;
        }
    }

    static uint ReadU32BE(byte[] d, int o) =>
        (uint)((d[o] << 24) | (d[o + 1] << 16) | (d[o + 2] << 8) | d[o + 3]);

    static ulong ReadU40(byte[] d, int o)
    {
        ulong v = 0;
        for (int i = 0; i < 5; i++) v = (v << 8) | d[o + i];
        return v;
    }
}
