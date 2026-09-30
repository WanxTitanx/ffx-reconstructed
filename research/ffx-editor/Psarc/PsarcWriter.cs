// PsarcWriter.cs
// Standalone .psarc (PhyreEngine archive) writer.
// RE: spec docs/reverse/FFX_STRUCTURE_COMPLETE_2026-08-17.md 11.4 + cross-validated
//     against the real PS3 SDK sample (PS3SDK/SDK3.60/.../fios/simple/data/test.psarc)
//     and FFX_Data.psarc, 2026-08-19, Jarvis-GENERAL.
// FIX 2026-09-14 (Jarvis-FFXSTRUCTURES): aligned with the executable format oracle
//     docs/reverse/FFX_PSARC_WRITER_ORACLE_2026-09-14.md (24 rules H1..X2 measured
//     on the real FFX_Data.psarc). Five legacy divergences corrected:
//       CE1  header u32BE@0x1C Flags = 2 (bit1, absolute paths) -- legacy wrote 0;
//       CE2  manifest is MULTIBLOCK: the raw name table is split into 65536-byte
//            chunks, each compressed as an INDEPENDENT zlib stream with one zsize
//            slot each (real file: 78 streams), chained via zsize_index;
//       CE3  manifest names joined with '\n' and NO trailing LF;
//       CE4  (closed by CE2) every manifest slot < 65536, so the u16 zsize can
//            never truncate a >131072-byte single stream anymore;
//       CE5  a stored block encodes ZSize == its LOGICAL length; ZSize==0 is ONLY
//            the u16-unrepresentable full 65536-byte stored block (never a tail).
//     Additionally required by the oracle rules and the RT0 repack of the real
//     corpus:
//       - an empty entry (size 0) reserves exactly ONE zero zsize slot (rule I3;
//         the real file has 5 such entries at indices 351/1256/17138/17139/68076);
//       - blocks compress at zlib level 9 (CompressionLevel.SmallestSize, which
//         maps to Z_BEST_COMPRESSION): the real file reproduces byte-exactly at
//         level 9 only (oracle recompress probe, 78/78 manifest streams + 200/200
//         asset samples; level 8 already fails);
//       - BuildPsarcFromFiles: streaming file-backed build. The FFX corpus is
//         13.5 GB logical (5.5 GB packed) and cannot round-trip through the
//         in-memory API; toc_length depends only on logical sizes, so the
//         header/TOC/zsize table are written as placeholders and patched after
//         the payload pass.
// RESEARCH ONLY -- not integrated into FFXProjectEditor.
//
// Format (all multi-byte fields BIG-ENDIAN):
//   Header (0x20):
//     +0x00 char[4]  magic "PSAR"
//     +0x04 u16      major_version = 1
//     +0x06 u16      minor_version = 4
//     +0x08 char[4]  compression_type "zlib"
//     +0x0C u32      toc_length == 32 + count*30 + total_slots*2; == data offset
//                    of the manifest (entry 0)
//     +0x10 u32      toc_entry_size = 30
//     +0x14 u32      files_count  (real files + 1 manifest entry)
//     +0x18 u32      block_size = 65536
//     +0x1C u32      flags = 2 (bit1 = absolute paths; measured on the corpus)
//   TOC (files_count * 30 bytes):
//     +0x00 byte[16] MD5 hash of the path (entry 0 = all zeros)
//     +0x10 u32      zsize_index (index into the ZSizes table of the first block)
//     +0x14 40-bit   uncompressed_size
//     +0x19 40-bit   offset (absolute file offset of the first data block)
//   ZSizes table: flat array of u16 BE, one per block, in file order. An empty
//     entry (size 0) reserves one slot with value 0. Per referenced slot:
//       ZSize == logical length     -> stored raw bytes (partial block = tail)
//       ZSize == 0 AND full 65536   -> stored raw full block (u16 cannot hold 65536)
//       otherwise                   -> one zlib stream of ZSize bytes
//   Manifest (entry 0 data): names UTF-8, joined by '\n', NO final '\n', split
//     into ceil(len/65536) INDEPENDENT zlib blocks (real file: 78 streams).
//   Data blocks: zlib level 9, 65536 logical bytes each; a block is stored raw
//     when compression does not shrink it strictly below its logical length.
//
// Layout order in the file: Header, TOC, ZSizes, Manifest blocks, then data.
// Entry 0 is the manifest entry (MD5 all zeros, offset = toc_length).
// The real files are entries 1..N, so files_count = N + 1.
using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text;

namespace Psarc
{
    /// <summary>A single file to pack into a .psarc, with its bytes in memory.</summary>
    public sealed record PsarcFileEntry(string Path, byte[] Data);

    /// <summary>
    /// A file to pack whose bytes are streamed from disk. Used for large archives:
    /// the FFX corpus is 13.5 GB logical and cannot be held in memory.
    /// </summary>
    public sealed record PsarcSourceEntry(string Path, string SourceFile);

    /// <summary>
    /// Builds .psarc archives. API mirrors the VBF writer (BuildVbf-style):
    /// pass an ordered list of (path, data) entries and get a .psarc byte stream,
    /// or use BuildPsarcFromFiles to stream file-backed inputs straight to disk.
    /// </summary>
    public static class PsarcWriter
    {
        public const uint Magic = 0x50534152;   // "PSAR"
        public const ushort MajorVersion = 1;
        public const ushort MinorVersion = 4;
        public const uint SizeOfEntry = 30;
        public const uint BlockSize = 65536;
        // WHY: the real FFX_Data.psarc stores 2 here (bit1 = absolute paths;
        // oracle rule H7 / errata A3 / counterexample CE1). The legacy writer
        // wrote 0 and failed H7 on every output.
        public const uint Flags = 2;

        /// <summary>Builds a .psarc from an ordered list of in-memory entries and writes it to a file.</summary>
        public static void BuildPsarc(IReadOnlyList<PsarcFileEntry> files, string outputPath)
        {
            File.WriteAllBytes(outputPath, BuildPsarcBytes(files));
        }

        /// <summary>Builds a .psarc from an ordered list of in-memory entries and returns the bytes.</summary>
        public static byte[] BuildPsarcBytes(IReadOnlyList<PsarcFileEntry> files)
        {
            if (files == null) throw new ArgumentNullException(nameof(files));
            int n = files.Count;

            // 1. Manifest (entry 0 data): names joined by '\n' with NO trailing LF,
            //    split into 65536-byte chunks, each compressed independently.
            string[] paths = new string[n];
            for (int i = 0; i < n; i++) paths[i] = NormalizePath(files[i].Path);
            byte[] manifestRaw = Encoding.UTF8.GetBytes(string.Join("\n", paths));
            var manifestBlocks = EncodeSequence(manifestRaw);

            // 2. Compress each file into blocks of BlockSize; track zsize_index per
            //    file. The manifest blocks occupy the first slots (zsize_index 0).
            var blocks = new List<List<(byte[] Payload, int Length, ushort ZSize)>>(n);
            var zsizeIndex = new List<int>(n);
            var flatZsizes = new List<ushort>();
            foreach (var b in manifestBlocks) flatZsizes.Add(b.ZSize);
            foreach (var f in files)
            {
                var fileBlocks = new List<(byte[] Payload, int Length, ushort ZSize)>();
                zsizeIndex.Add(flatZsizes.Count);
                byte[] data = f.Data ?? Array.Empty<byte>();
                for (int off = 0; off < data.Length; off += (int)BlockSize)
                {
                    int len = (int)Math.Min(BlockSize, data.Length - off);
                    byte[] chunk = new byte[len];
                    Array.Copy(data, off, chunk, 0, len);
                    var enc = EncodeBlock(chunk, len);
                    fileBlocks.Add(enc);
                    flatZsizes.Add(enc.ZSize);
                }
                // WHY reserved zero slot: an empty entry must still consume exactly
                // one slot (value 0) so the zsize-index chain stays sequential
                // (oracle I3; real file: 5 empty entries). Skipping the slot broke
                // every later entry's zsize_index.
                if (data.Length == 0) flatZsizes.Add(0);
                blocks.Add(fileBlocks);
            }

            // 3. Compute layout. files_count = n + 1 (entry 0 = manifest).
            int count = n + 1;
            long startOfData = 32 + (long)count * SizeOfEntry + flatZsizes.Count * 2;
            long dataOffset = startOfData;
            foreach (var b in manifestBlocks) dataOffset += b.Length;

            // offsets[i] = absolute offset of file i first data block (i = 0..n-1).
            var offsets = new long[n];
            for (int i = 0; i < n; i++)
            {
                offsets[i] = dataOffset;
                foreach (var blk in blocks[i]) dataOffset += blk.Length;
            }

            // 4. Assemble.
            using var ms = new MemoryStream();
            var bw = new BinaryWriter(ms);
            WriteHeader(bw, (uint)startOfData, count);
            // TOC entry 0 = manifest (MD5 all zeros, zsize_index 0, offset = toc_length).
            WriteEntry(bw, new byte[16], 0, manifestRaw.Length, startOfData);
            for (int i = 0; i < n; i++)
                WriteEntry(bw, MD5.HashData(Encoding.UTF8.GetBytes(paths[i])),
                    (uint)zsizeIndex[i], files[i].Data?.LongLength ?? 0, offsets[i]);
            foreach (var z in flatZsizes) WriteU16BE(bw, z);
            foreach (var b in manifestBlocks) bw.Write(b.Payload, 0, b.Length);
            for (int i = 0; i < n; i++)
                foreach (var blk in blocks[i]) bw.Write(blk.Payload, 0, blk.Length);
            bw.Flush();
            return ms.ToArray();
        }

        /// <summary>
        /// Streams a .psarc to outputPath from file-backed inputs, in list order
        /// (the list order IS the manifest order). Single pass with an in-place
        /// patch: toc_length is fully determined by the logical sizes (known via
        /// FileInfo before any compression), so the header, TOC and ZSizes table
        /// are first written as zero placeholders of the exact final length; the
        /// payload blocks are streamed after them; the header/TOC/table are then
        /// patched at offset 0, because zsizes and entry offsets only become
        /// known during compression.
        /// </summary>
        public static void BuildPsarcFromFiles(IReadOnlyList<PsarcSourceEntry> files, string outputPath)
        {
            if (files == null) throw new ArgumentNullException(nameof(files));
            int n = files.Count;

            string[] paths = new string[n];
            long[] sizes = new long[n];
            for (int i = 0; i < n; i++)
            {
                paths[i] = NormalizePath(files[i].Path);
                sizes[i] = new FileInfo(files[i].SourceFile).Length;
            }

            byte[] manifestRaw = Encoding.UTF8.GetBytes(string.Join("\n", paths));
            var manifestBlocks = EncodeSequence(manifestRaw);

            long totalSlots = manifestBlocks.Count;
            foreach (long s in sizes) totalSlots += ReservedSlots(s);
            long tocLength = 32 + (long)(n + 1) * SizeOfEntry + totalSlots * 2;

            var zsizeTable = new ushort[totalSlots];
            var md5s = new byte[n][];
            var zsizeIdx = new uint[n];
            var offsets = new long[n];
            int slotCursor = 0;
            foreach (var b in manifestBlocks) zsizeTable[slotCursor++] = b.ZSize;

            using var fs = new FileStream(outputPath, FileMode.Create, FileAccess.Write,
                FileShare.None, bufferSize: 1024 * 1024);
            var bw = new BinaryWriter(fs);

            // Placeholders for header + TOC + ZSizes table (exact final length).
            bw.Write(new byte[tocLength]);

            // Entry 0 payload: manifest blocks (kept in RAM; the real one is ~5 MB).
            foreach (var b in manifestBlocks) bw.Write(b.Payload, 0, b.Length);
            long dataOffset = tocLength;
            foreach (var b in manifestBlocks) dataOffset += b.Length;

            var chunk = new byte[BlockSize];
            for (int i = 0; i < n; i++)
            {
                zsizeIdx[i] = (uint)slotCursor;
                offsets[i] = dataOffset;
                md5s[i] = MD5.HashData(Encoding.UTF8.GetBytes(paths[i]));
                if (sizes[i] == 0)
                {
                    // WHY: same reserved zero slot as the in-memory path (oracle I3).
                    zsizeTable[slotCursor++] = 0;
                    continue;
                }
                using (var src = new FileStream(files[i].SourceFile, FileMode.Open,
                    FileAccess.Read, FileShare.Read, bufferSize: 1024 * 1024))
                {
                    long remaining = sizes[i];
                    while (remaining > 0)
                    {
                        int len = (int)Math.Min(BlockSize, remaining);
                        ReadExact(src, chunk, len, files[i].SourceFile);
                        var enc = EncodeBlock(chunk, len);
                        bw.Write(enc.Payload, 0, enc.Length);
                        zsizeTable[slotCursor++] = enc.ZSize;
                        dataOffset += enc.Length;
                        remaining -= len;
                    }
                }
            }

            // Patch header + TOC + ZSizes table with the real values.
            fs.Seek(0, SeekOrigin.Begin);
            WriteHeader(bw, (uint)tocLength, n + 1);
            WriteEntry(bw, new byte[16], 0, manifestRaw.Length, tocLength);
            for (int i = 0; i < n; i++)
                WriteEntry(bw, md5s[i], zsizeIdx[i], sizes[i], offsets[i]);
            foreach (var z in zsizeTable) WriteU16BE(bw, z);
            if (fs.Position != tocLength)
                throw new IOException(
                    $"patched prefix ends at {fs.Position}, expected toc_length {tocLength}");
            bw.Flush();
        }

        // ── Shared encoding helpers (single source of truth for both paths) ──

        /// <summary>Splits raw bytes into 65536-byte chunks and encodes each
        /// chunk independently (multiblock; oracle CE2).</summary>
        static List<(byte[] Payload, int Length, ushort ZSize)> EncodeSequence(byte[] raw)
        {
            var list = new List<(byte[] Payload, int Length, ushort ZSize)>();
            for (int off = 0; off < raw.Length || list.Count == 0; off += (int)BlockSize)
            {
                int len = (int)Math.Min(BlockSize, raw.Length - off);
                byte[] chunk = new byte[len];
                Array.Copy(raw, off, chunk, 0, len);
                list.Add(EncodeBlock(chunk, len));
            }
            return list;
        }

        /// <summary>zsize slots reserved by an entry: one per 65536-byte block,
        /// or exactly one zero slot for an empty (size 0) entry (oracle I3).</summary>
        static long ReservedSlots(long logicalSize) =>
            logicalSize <= 0 ? 1 : (logicalSize + BlockSize - 1) / BlockSize;

        /// <summary>
        /// Real-file block encoding (oracle B1/B2 + rs-utils convention): keep the
        /// zlib stream only when it is STRICTLY smaller than the raw block,
        /// otherwise store the raw bytes. A stored PARTIAL block (necessarily the
        /// entry tail) encodes ZSize == its logical length; a stored FULL 65536
        /// block encodes ZSize == 0 because 65536 does not fit in u16.
        /// ZSize==0 for a partial block is invalid (legacy counterexample CE5).
        /// </summary>
        static (byte[] Payload, int Length, ushort ZSize) EncodeBlock(byte[] chunk, int len)
        {
            byte[] compressed = CompressZlib(chunk, len);
            if (compressed.Length < len)
                return (compressed, compressed.Length, (ushort)compressed.Length);
            if (len == (int)BlockSize)
                return (chunk, len, 0);
            return (chunk, len, (ushort)len);
        }

        /// <summary>zlib level 9 (CompressionLevel.SmallestSize, which .NET's
        /// zlib wrapper maps to Z_BEST_COMPRESSION = 9). WHY: the real
        /// FFX_Data.psarc streams reproduce byte-exactly at level 9 only (oracle
        /// recompress probe: 78/78 manifest + 200/200 asset samples; level 8
        /// already fails 4/78). CompressionLevel.Optimal maps to zlib default
        /// (level 6) and does NOT reproduce the original streams.</summary>
        static byte[] CompressZlib(byte[] data, int count)
        {
            using var outMs = new MemoryStream();
            using (var z = new ZLibStream(outMs, CompressionLevel.SmallestSize, leaveOpen: true))
                z.Write(data, 0, count);
            return outMs.ToArray();
        }

        static void ReadExact(FileStream src, byte[] buffer, int count, string source)
        {
            int read = 0;
            while (read < count)
            {
                int k = src.Read(buffer, read, count - read);
                if (k <= 0)
                    throw new EndOfStreamException(
                        $"unexpected EOF reading {source} at {src.Position} ({read}/{count} bytes)");
                read += k;
            }
        }

        static string NormalizePath(string p)
        {
            if (string.IsNullOrEmpty(p)) return "/";
            if (!p.StartsWith("/", StringComparison.Ordinal)) p = "/" + p;
            return p.Replace('\\', '/');
        }

        static void WriteHeader(BinaryWriter bw, uint tocLength, int count)
        {
            bw.Write((byte)'P'); bw.Write((byte)'S'); bw.Write((byte)'A'); bw.Write((byte)'R');
            WriteU16BE(bw, MajorVersion);
            WriteU16BE(bw, MinorVersion);
            bw.Write(Encoding.ASCII.GetBytes("zlib"));
            WriteU32BE(bw, tocLength);
            WriteU32BE(bw, SizeOfEntry);
            WriteU32BE(bw, (uint)count);
            WriteU32BE(bw, BlockSize);
            WriteU32BE(bw, Flags); // WHY CE1: 2 (absolute paths); legacy wrote 0.
        }

        static void WriteEntry(BinaryWriter bw, byte[] md5, uint zsizeIndex, long size, long offset)
        {
            bw.Write(md5);
            WriteU32BE(bw, zsizeIndex);
            Write40BE(bw, (ulong)size);
            Write40BE(bw, (ulong)offset);
        }

        static void WriteU16BE(BinaryWriter bw, ushort v) { bw.Write((byte)(v >> 8)); bw.Write((byte)(v & 0xFF)); }
        static void WriteU32BE(BinaryWriter bw, uint v)
        {
            bw.Write((byte)(v >> 24)); bw.Write((byte)(v >> 16));
            bw.Write((byte)(v >> 8)); bw.Write((byte)(v & 0xFF));
        }
        static void Write40BE(BinaryWriter bw, ulong v)
        {
            bw.Write((byte)((v >> 32) & 0xFF));
            bw.Write((byte)((v >> 24) & 0xFF));
            bw.Write((byte)((v >> 16) & 0xFF));
            bw.Write((byte)((v >> 8) & 0xFF));
            bw.Write((byte)(v & 0xFF));
        }
    }
}
