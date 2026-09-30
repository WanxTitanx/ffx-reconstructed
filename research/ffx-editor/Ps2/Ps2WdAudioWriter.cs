using System;
using System.Buffers.Binary;
using System.Collections.Generic;
using System.IO;

namespace FFXProjectEditor.FfxLib.Ps2
{
    // ── Ps2WdAudioWriter ──
    // PS2 .wd sound-bank writer with an INTERNAL SPU-ADPCM codec (decode + encode),
    // so no external vgmstream oracle is needed to round-trip audio.
    //
    // Proved layout (docs/history/FFX_PS2_WD_DESCRIPTOR_SEMANTICS_2026-06-02.md +
    // Ps2WdAudioReader / Ps2WdSoundReader):
    //   +0x00  char[2]  magic "WD"
    //   +0x02  u16      id
    //   +0x04  u32      bodySize (total SPU-ADPCM body bytes)
    //   +0x08  u32      nPrograms
    //   +0x0C  u32      nSamples
    //   +0x20  u32[nPrograms]  program-pointer table (prog[i] = descriptor base)
    //   desc[i] @ descBase + i*0x20 (0x20 bytes each):
    //     +0x00  u32  f0
    //     +0x04  u32  sampleBodyOffset (relative to bodyStart)
    //     +0x08  u32  loop (== sampleBodyOffset when no loop)
    //     +0x0C  u8   vol
    //     +0x0D  u8   pan
    //     +0x0E  u16  pitch (Q4.12)
    //     +0x10  u32  adsr1
    //     +0x14  u32  adsr2
    //     +0x18  u64  reserved (0)
    //   bodyStart = align32(descBase + nSamples*0x20); bodies 32-byte aligned.
    //
    // SPU-ADPCM: 16-byte blocks, 28 samples/block, 4-bit signed nibbles.
    //   block[0] = (filter << 4) | shift; block[1] = flags; block[2..16] = nibbles.
    //   filters: {0,0},{60,0},{115,-52},{98,-55},{122,-60}.
    //   decode: s = (nibble << 12) >> shift; s += (pred1*f0 + pred2*f1 + 32) >> 6.
    //
    // Credit: Ps2WdAudioWriter (formato WD + codec SPU-ADPCM RE por Jarvis-Maechen, 2026-08-19)
    internal sealed class Ps2WdSampleInput
    {
        public required short[] Pcm { get; init; }
        public uint F0 { get; init; }
        public uint Loop { get; init; }
        public byte Vol { get; init; } = 0xFF;
        public byte Pan { get; init; } = 0x40;
        public ushort Pitch { get; init; } = 0x4000;
        public uint Adsr1 { get; init; }
        public uint Adsr2 { get; init; } = 0x407F7F3C;
    }

    internal static class Ps2WdAudioWriter
    {
        const int DescSize = 0x20;
        const int OffsetTable = 0x20;
        const int SamplesPerBlock = 28;
        const int BlockSize = 16;
        const int BodyAlign = 32;

        static readonly int[] Filter0 = [0, 60, 115, 98, 122];
        static readonly int[] Filter1 = [0, 0, -52, -55, -60];

        // ── SPU-ADPCM decode ──
        public static short[] DecodeAdpcm(ReadOnlySpan<byte> body)
        {
            int blockCount = body.Length / BlockSize;
            short[] pcm = new short[blockCount * SamplesPerBlock];
            int pred1 = 0, pred2 = 0;
            int outIndex = 0;
            for (int b = 0; b < blockCount; b++)
            {
                int off = b * BlockSize;
                int shift = body[off] & 0x0F;
                int filter = (body[off] >> 4) & 0x0F;
                if (filter > 4) filter = 0; // defensive: unknown filter treated as flat
                int f0 = Filter0[filter], f1 = Filter1[filter];
                for (int n = 0; n < SamplesPerBlock; n++)
                {
                    int nibble = body[off + 2 + (n >> 1)];
                    nibble = (n & 1) == 0 ? nibble >> 4 : nibble & 0x0F;
                    if (nibble >= 8) nibble -= 16; // sign-extend 4-bit
                    int s = (nibble << 12) >> shift;
                    s += (pred1 * f0 + pred2 * f1 + 32) >> 6;
                    pred2 = pred1;
                    pred1 = s;
                    pcm[outIndex++] = (short)Math.Clamp(s, short.MinValue, short.MaxValue);
                }
            }
            return pcm;
        }

        // ── SPU-ADPCM encode ──
        public static byte[] EncodeAdpcm(ReadOnlySpan<short> pcm)
        {
            int blockCount = (pcm.Length + SamplesPerBlock - 1) / SamplesPerBlock;
            byte[] body = new byte[blockCount * BlockSize];
            int pred1 = 0, pred2 = 0;
            for (int b = 0; b < blockCount; b++)
            {
                int blockStart = b * SamplesPerBlock;
                int count = Math.Min(SamplesPerBlock, pcm.Length - blockStart);
                Span<short> block = stackalloc short[SamplesPerBlock];
                pcm.Slice(blockStart, count).CopyTo(block);

                // Find best (filter, shift) over the block by simulated decode error.
                int bestFilter = 0, bestShift = 0;
                long bestError = long.MaxValue;
                for (int filter = 0; filter < Filter0.Length; filter++)
                {
                    // FIX 2026-09-15 (FFX-STRUCTURES validation): renamed the candidate-filter
                    // locals f0/f1 -> cf0/cf1; they collided with the f0/f1 locals declared
                    // later in the enclosing block-scope (CS0136). Pure rename, zero semantic
                    // change (the two pairs are independent).
                    int cf0 = Filter0[filter], cf1 = Filter1[filter];
                    for (int shift = 0; shift <= 12; shift++)
                    {
                        long error = 0;
                        int p1 = pred1, p2 = pred2;
                        for (int i = 0; i < count; i++)
                        {
                            int predicted = (p1 * cf0 + p2 * cf1 + 32) >> 6;
                            int nibble = Math.Clamp((block[i] - predicted) >> shift, -8, 7);
                            int decoded = ((nibble << 12) >> shift) + predicted;
                            int diff = block[i] - decoded;
                            error += (long)diff * diff;
                            p2 = p1;
                            p1 = decoded;
                        }
                        if (error < bestError)
                        {
                            bestError = error;
                            bestFilter = filter;
                            bestShift = shift;
                        }
                    }
                }

                // Emit the block with the chosen filter/shift, carrying state across blocks.
                int off = b * BlockSize;
                int f0 = Filter0[bestFilter], f1 = Filter1[bestFilter];
                body[off] = (byte)((bestFilter << 4) | bestShift);
                body[off + 1] = (byte)(b == blockCount - 1 ? 0x01 : 0x00); // end flag on last block
                for (int n = 0; n < SamplesPerBlock; n++)
                {
                    int sample = n < count ? block[n] : 0;
                    int predicted = (pred1 * f0 + pred2 * f1 + 32) >> 6;
                    int nibble = Math.Clamp((sample - predicted) >> bestShift, -8, 7);
                    int decoded = ((nibble << 12) >> bestShift) + predicted;
                    pred2 = pred1;
                    pred1 = decoded;
                    int byteIndex = off + 2 + (n >> 1);
                    if ((n & 1) == 0)
                        body[byteIndex] = (byte)((nibble & 0x0F) << 4);
                    else
                        body[byteIndex] |= (byte)(nibble & 0x0F);
                }
            }
            return body;
        }

        // ── .wd bank build ──
        public static byte[] BuildBank(ushort id, IReadOnlyList<Ps2WdSampleInput> samples)
        {
            if (samples.Count == 0)
                throw new ArgumentException("WD bank needs at least one sample.", nameof(samples));

            int nSamp = samples.Count;
            int nProg = nSamp; // 1:1 layout (one sample per program, the common FFX case)
            int descBase = OffsetTable + 4 * nProg;
            int bodyStart = (descBase + nSamp * DescSize + BodyAlign - 1) & ~(BodyAlign - 1);

            // Encode each sample and pad its body to 32-byte alignment.
            var bodies = new byte[nSamp][];
            var sbo = new uint[nSamp];
            int bodySize = 0;
            for (int i = 0; i < nSamp; i++)
            {
                byte[] raw = EncodeAdpcm(samples[i].Pcm);
                int padded = (raw.Length + BodyAlign - 1) & ~(BodyAlign - 1);
                bodies[i] = new byte[padded];
                raw.CopyTo(bodies[i], 0);
                sbo[i] = (uint)bodySize;
                bodySize += padded;
            }

            byte[] d = new byte[bodyStart + bodySize];
            d[0] = (byte)'W'; d[1] = (byte)'D';
            WriteU16(d, 2, id);
            WriteU32(d, 4, (uint)bodySize);
            WriteU32(d, 8, (uint)nProg);
            WriteU32(d, 12, (uint)nSamp);

            // program-pointer table @0x20 (each program owns one descriptor)
            for (int i = 0; i < nProg; i++)
                WriteU32(d, OffsetTable + 4 * i, (uint)(descBase + i * DescSize));

            // descriptors
            for (int i = 0; i < nSamp; i++)
            {
                Ps2WdSampleInput s = samples[i];
                int p = descBase + i * DescSize;
                WriteU32(d, p + 0x00, s.F0);
                WriteU32(d, p + 0x04, sbo[i]);
                WriteU32(d, p + 0x08, s.Loop == 0 ? sbo[i] : s.Loop); // no-loop convention: loop == sbo
                d[p + 0x0C] = s.Vol;
                d[p + 0x0D] = s.Pan;
                WriteU16(d, p + 0x0E, s.Pitch);
                WriteU32(d, p + 0x10, s.Adsr1);
                WriteU32(d, p + 0x14, s.Adsr2);
                // +0x18 u64 reserved stays zero
            }

            // bodies
            int cursor = bodyStart;
            for (int i = 0; i < nSamp; i++)
            {
                bodies[i].CopyTo(d, cursor);
                cursor += bodies[i].Length;
            }
            return d;
        }

        public static void WriteToFile(string path, ushort id, IReadOnlyList<Ps2WdSampleInput> samples)
        {
            byte[] d = BuildBank(id, samples);
            File.WriteAllBytes(path, d);
        }

        // ── .wd bank decode ──
        public static IReadOnlyList<short[]> DecodeBank(byte[] d)
        {
            if (d.Length < 16 || d[0] != (byte)'W' || d[1] != (byte)'D')
                throw new InvalidDataException("Not a WD bank (missing 'WD' magic).");
            uint nProg = ReadU32(d, 8);
            uint nSamp = ReadU32(d, 12);
            if (nProg == 0 || nSamp == 0 || nProg > 4096 || nSamp > 65536)
                throw new InvalidDataException("WD bank has implausible program/sample counts.");

            // FIX 2026-09-15 (validation wave): descriptor table starts at the EXACT end of
            // the program-pointer table (0x20 + 4*nProg), matching the writer side above and
            // the anchor law proven by ps2_wd_reader.py (k == desc_end mod 16; reading a u32
            // "descBase" at 0x20 only worked for single-program banks — wave1253.wd failed).
            int descBase = OffsetTable + 4 * (int)nProg;
            int bodyStart = (descBase + (int)nSamp * DescSize + BodyAlign - 1) & ~(BodyAlign - 1);
            uint bodySize = ReadU32(d, 4);

            var sbo = new uint[nSamp];
            for (int i = 0; i < nSamp; i++)
                sbo[i] = ReadU32(d, descBase + i * DescSize + 4);
            uint sbo0 = sbo[0];

            var result = new List<short[]>();
            for (int i = 0; i < nSamp; i++)
            {
                int start = bodyStart + (int)(sbo[i] - sbo0);
                long end = i + 1 < nSamp ? sbo[i + 1] : sbo0 + bodySize;
                int size = (int)Math.Max(0, end - sbo[i]);
                if (start < 0 || start + size > d.Length)
                    throw new InvalidDataException($"WD sample {i} body out of range.");
                result.Add(DecodeAdpcm(d.AsSpan(start, size)));
            }
            return result;
        }

        static void WriteU16(byte[] d, int o, ushort v) => BinaryPrimitives.WriteUInt16LittleEndian(d.AsSpan(o), v);
        static void WriteU32(byte[] d, int o, uint v) => BinaryPrimitives.WriteUInt32LittleEndian(d.AsSpan(o), v);
        static uint ReadU32(byte[] d, int o) => BinaryPrimitives.ReadUInt32LittleEndian(d.AsSpan(o));
    }
}
