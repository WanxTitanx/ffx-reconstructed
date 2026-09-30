// _psarc_repair_ffx2_v2.cs — upgrade of the RT1 structural repair: inject the
// 13 damaged /ffx_ps2/* entries from the PS4 FFX-2 extraction (parity proven:
// exact TOC logical sizes 13/13 + family headers byte-consistent with healthy
// siblings — see docs/reverse/FFX_PSARC_FFX2_REPAIR_V2_2026-09-15.md).
//
// MISSION: same rebuild as _psarc_repair_ffx2.cs (RT1-proven), but for every
// TOC name that has a file under <override-root>/<name-without-leading-slash>
// the packer reads THAT file instead of the (zero-filled) PS3 extraction copy.
// The override source is the cross-platform PS2-era data shipped in the PS4
// release (FFX-2_Data_P1), assumed byte-identical to the PS3 original because
// the logical sizes match the PS3 TOC exactly and the family headers match the
// 35 healthy .chr siblings of the same TOC (residual risk documented).
//
// SAFETY: a strict size check against the original TOC is enforced for EVERY
// entry (override or not) — any mismatch aborts before the 15-minute build.
// The damaged original is only ever opened read-only for header+TOC+manifest.
//
// Adapted from _psarc_repair_ffx2.cs (2026-09-15, RT1); sole behavioural delta
// is the override-root selection in the mapping phase. Writer untouched
// (PsarcWriter.cs, RT0/RT1-proven, zlib level 9).
//
// Usage:
//   dotnet run --project _psarc_repair_ffx2_v2.csproj -- \
//       <damaged-original.psarc> <extraction-root> <override-root> <output.psarc>
//
// RESEARCH ONLY — not integrated into FFXProjectEditor.
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Text;
using Psarc;

static class PsarcRepairFfx2V2
{
    static int Main(string[] args)
    {
        if (args.Length != 4)
        {
            Console.Error.WriteLine(
                "usage: PsarcRepairFfx2V2 <damaged-original.psarc> <extraction-root> <override-root> <output.psarc>");
            return 2;
        }
        string originalPath = args[0];
        string extractionRoot = args[1];
        string overrideRoot = args[2];
        string outputPath = args[3];
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

        // ── 3. Map every TOC name to a source; override-root wins when present ──
        // WHY validate everything BEFORE packing: a 15+ minute streaming build must
        // never fail (or worse, silently shrink an entry) because one source file
        // was missing or resized. Overrides are held to the SAME strict TOC size
        // check as extraction files — a PS4 file whose size differs from the PS3
        // TOC means parity is broken and the whole run must abort (do not inject).
        var files = new List<PsarcSourceEntry>((int)count - 1);
        int missing = 0, sizeMismatch = 0, overridden = 0;
        long totalLogical = 0, overriddenLogical = 0;
        for (int i = 1; i < count; i++)
        {
            int e = i * 30;
            long size = (long)ReadU40(toc, e + 20);
            string rel = names[i - 1].TrimStart('/');
            string src = Path.Combine(extractionRoot, rel);
            string ovr = Path.Combine(overrideRoot, rel);
            bool useOverride = File.Exists(ovr);
            string chosen = useOverride ? ovr : src;
            long diskSize;
            try { diskSize = new FileInfo(chosen).Length; }
            catch (Exception)
            {
                missing++;
                if (missing <= 5) Console.Error.WriteLine($"  MISSING: {chosen}");
                continue;
            }
            if (diskSize != size)
            {
                sizeMismatch++;
                Console.Error.WriteLine($"  SIZE MISMATCH ({(useOverride ? "OVERRIDE" : "extraction")}): {chosen} toc={size} disk={diskSize}");
                continue;
            }
            if (useOverride)
            {
                overridden++;
                overriddenLogical += size;
                Console.WriteLine($"  OVERRIDE[{overridden}]: {names[i - 1]} ({size} B) <- {ovr}");
            }
            totalLogical += size;
            files.Add(new PsarcSourceEntry(names[i - 1], chosen));
        }
        Console.WriteLine($"corpus mapping: ok={files.Count}/{count - 1} missing={missing} sizeMismatch={sizeMismatch} overridden={overridden} overriddenLogical={overriddenLogical} totalLogical={totalLogical}");
        if (missing != 0 || sizeMismatch != 0 || files.Count != count - 1 || overridden == 0)
        {
            Console.Error.WriteLine("ABORT: extraction+override does not satisfy the TOC 1:1 (or no override found)");
            return 1;
        }

        // ── 4. Streaming rebuild (single pass, in-place TOC patch — see writer) ──
        var swPack = Stopwatch.StartNew();
        PsarcWriter.BuildPsarcFromFiles(files, outputPath);
        swPack.Stop();
        long outSize = new FileInfo(outputPath).Length;
        Console.WriteLine($"packed: {outSize} bytes in {swPack.Elapsed} (v1 repaired: 5,789,019,583)");
        Console.WriteLine($"total elapsed: {swTotal.Elapsed}");
        return 0;
    }

    /// <summary>Strict per-block decode of one entry straight from the archive,
    /// with the real-file ZSize semantics (stored tail == logical, 0 + full ==
    /// stored full block, else strict zlib). Used only for entry 0 (manifest):
    /// payload entries are re-read from extraction/override sources.</summary>
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
