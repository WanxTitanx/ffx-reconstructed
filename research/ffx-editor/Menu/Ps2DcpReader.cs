// ── Ps2DcpReader ──────────────────────────────────────────────────────────────
// Standalone byte-level parser for the PS2 FFX menu macro-dictionary format (.dcp).
// Reference file: jppc/menu/macrodic.dcp (23,248 bytes = 0x5AD0).
//
// Format summary (empirically derived + matches the editor's existing
// MacroDictionary_File reader in FFXProjectEditor/FfxLib/Text/):
//   - Header: 16x u32 LITTLE-ENDIAN slot offsets. Slots with value 0 are absent.
//     In macrodic.dcp the present slots are 6,7,8,9,11,13 -> offsets
//     0x40, 0x640, 0xE00, 0x1AD0, 0x1AF0, 0x5680.
//   - Each chunk at a present offset:
//       [0x00] u16 LE = size of the entry table in bytes (N).
//               Entry count = N / 4.
//       [0x04] N/4 entries of (u16 regular_offset, u16 simplified_offset).
//               The offsets are relative to the chunk start.
//       [N]    String pool of null-terminated Shift-JIS strings.
//               regular_offset == simplified_offset means the macro has no
//               simplified (Chinese) variant.
//   - Loaded by the game via FFX_File_LoadFormationBin (0x88CA30 in the PC
//     HD remaster binary) using the format string "%smenu/%s.dcp".
//
// NOTE: the editor already ships a full read/write implementation
// (MacroDictionary_File). This standalone reader exists purely as a
// self-contained reference for the byte-level format.
// ───────────────────────────────────────────────────────────────────────────────
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ResearchTools.Menu
{
    public sealed class Ps2DcpEntry
    {
        public required int Index { get; init; }
        public required int RegularOffset { get; init; }
        public required int SimplifiedOffset { get; init; }
        public required byte[] RegularBytes { get; init; }
        public required byte[] SimplifiedBytes { get; init; }
        public bool HasSimplified => RegularOffset != SimplifiedOffset;
    }

    public sealed class Ps2DcpChunk
    {
        public required int SlotIndex { get; init; }
        public required int FileOffset { get; init; }
        public required int EntryCount { get; init; }
        public required IReadOnlyList<Ps2DcpEntry> Entries { get; init; }
        public required byte[] PoolBytes { get; init; }
    }

    public sealed class Ps2DcpFile
    {
        public required int FileSize { get; init; }
        public required uint[] HeaderSlots { get; init; }
        public required IReadOnlyList<Ps2DcpChunk> Chunks { get; init; }
    }

    public static class Ps2DcpReader
    {
        public const int SlotCount = 16;

        public static Ps2DcpFile Read(string path) => Read(File.ReadAllBytes(path));

        public static Ps2DcpFile Read(byte[] data)
        {
            if (data.Length < SlotCount * 4)
                throw new InvalidDataException($"DCP file too small: {data.Length} bytes.");

            uint[] slots = new uint[SlotCount];
            for (int i = 0; i < SlotCount; i++)
                slots[i] = ReadU32LE(data, i * 4);

            var chunks = new List<Ps2DcpChunk>();
            for (int i = 0; i < SlotCount; i++)
            {
                int off = (int)slots[i];
                if (off == 0 || off >= data.Length)
                    continue;

                int first = ReadU16LE(data, off);
                int count = first / 4;
                if (count <= 0 || off + 4 + count * 4 > data.Length)
                    continue;

                var entries = new List<Ps2DcpEntry>();
                for (int e = 0; e < count; e++)
                {
                    int eOff = off + 4 + e * 4;
                    int reg = ReadU16LE(data, eOff);
                    int simp = ReadU16LE(data, eOff + 2);
                    byte[] regBytes = ReadNullTerminated(data, off + reg);
                    byte[] simpBytes = (reg == simp) ? Array.Empty<byte>() : ReadNullTerminated(data, off + simp);
                    entries.Add(new Ps2DcpEntry
                    {
                        Index = e,
                        RegularOffset = reg,
                        SimplifiedOffset = simp,
                        RegularBytes = regBytes,
                        SimplifiedBytes = simpBytes,
                    });
                }

                int poolStart = off + 4 + count * 4;
                int poolEnd = (i + 1 < SlotCount && slots[i + 1] != 0)
                    ? (int)slots[i + 1]
                    : data.Length;
                byte[] pool = new byte[Math.Max(0, poolEnd - poolStart)];
                Array.Copy(data, poolStart, pool, 0, pool.Length);

                chunks.Add(new Ps2DcpChunk
                {
                    SlotIndex = i,
                    FileOffset = off,
                    EntryCount = count,
                    Entries = entries,
                    PoolBytes = pool,
                });
            }

            return new Ps2DcpFile
            {
                FileSize = data.Length,
                HeaderSlots = slots,
                Chunks = chunks,
            };
        }

        private static byte[] ReadNullTerminated(byte[] data, int off)
        {
            if (off < 0 || off >= data.Length)
                return Array.Empty<byte>();
            int end = off;
            while (end < data.Length && data[end] != 0)
                end++;
            byte[] result = new byte[end - off];
            Array.Copy(data, off, result, 0, result.Length);
            return result;
        }

        private static ushort ReadU16LE(byte[] data, int off) =>
            (ushort)(data[off] | (data[off + 1] << 8));

        private static uint ReadU32LE(byte[] data, int off) =>
            (uint)(data[off] | (data[off + 1] << 8) | (data[off + 2] << 16) | (data[off + 3] << 24));
    }
}
