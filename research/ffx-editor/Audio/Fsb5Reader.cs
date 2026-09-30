// ── Fsb5Reader.cs ──────────────────────────────────────────────────
// Standalone, self-contained FSB5 binary reader for reference / research.
// NOT part of FFXProjectEditor — research-only tool in work/research_tools/.
//
// Derived from:
//   - vgmstream/src/meta/fsb5.c (losnoco/vgmstream, vgmstream v1997+)
//   - fsbext.c 0.3.8a by Luigi Auriemma (TechToolKit/fsbext-src/)
//   - Empirical hex analysis of FFX PC SFX/Music FSB5 banks
//
// FSB5 is FMOD Studio SoundBank v5. FFX PC uses codec 7 (IMA ADPCM)
// for all SFX/Music banks. Channels are 1–2, sample rate 44100 or 48000.
//
// Sample data uses XBOX 4-bit IMA ADPCM (interleaved for stereo).
// Block layout: [L_hdr 4B][R_hdr 4B][L_data 32B][R_data 32B] = 72B
// ──────────────────────────────────────────────────────────────────
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Fsb5Reference
{
    // Codec IDs matching FMOD_SOUND_FORMAT_* enum
    public enum Fsb5Codec : uint
    {
        None = 0, Pcm8 = 1, Pcm16 = 2, Pcm24 = 3, Pcm32 = 4,
        PcmFloat = 5, GcAdpcm = 6, ImaAdpcm = 7, Vag = 8, HeVag = 9,
        Xma = 10, Mpeg = 11, Celt = 12, At9 = 13, Xwma = 14,
        Vorbis = 15
    }

    public class Fsb5Sample
    {
        public int Index;
        public uint NameHash;
        public long DataOffset;        // absolute offset in file
        public int DataSize;           // bytes of compressed data
        public int NumSamples;         // decoded sample count
        public int Channels;
        public int SampleRate;
        public string Name;
        public List<Fsb5ExtraFlag> ExtraFlags = new();
    }

    public class Fsb5ExtraFlag
    {
        public int Type;       // (raw >> 25) & 0x7F
        public int Size;       // (raw >> 1) & 0xFFFFFF
        public bool Continue;  // raw & 1
    }

    public class Fsb5Header
    {
        public const int BaseHeaderSize = 60;  // version 1
        public uint Version;
        public int NumSamples;
        public int SampleHeaderSize;
        public int NameTableSize;
        public int DataSize;
        public Fsb5Codec Codec;
        public uint Flags;
        public byte[] Hash = new byte[16];
        public byte[] SubHash = new byte[8];
        public List<Fsb5Sample> Samples = new();
    }

    public static class Fsb5Reader
    {
        const string Magic = "FSB5";
        static readonly int[] FreqTable = { 4000, 8000, 11000, 11025, 16000, 22050, 24000, 32000, 44100, 48000, 96000 };

        public static Fsb5Header Read(byte[] data)
        {
            if (data.Length < 60)
                throw new InvalidDataException("File too small for FSB5 header");
            if (Encoding.ASCII.GetString(data, 0, 4) != Magic)
                throw new InvalidDataException("Not an FSB5 file");

            var h = new Fsb5Header();
            int p = 4;
            h.Version = RU32(data, ref p);       // 0x04
            h.NumSamples = (int)RU32(data, ref p); // 0x08
            h.SampleHeaderSize = (int)RU32(data, ref p); // 0x0C
            h.NameTableSize = (int)RU32(data, ref p);    // 0x10
            h.DataSize = (int)RU32(data, ref p);          // 0x14
            h.Codec = (Fsb5Codec)RU32(data, ref p);       // 0x18

            // version-specific fields
            if (h.Version == 0)
                p += 4;  // skip extra u32

            // FIX 2026-09-16 (FMT-AUDIO audit): TWO u32 fields sit between codec
            // and the hash — 0x1C (zero/flags) and 0x20 (flags per the format doc
            // FFX_FEV_FSB_AUDIO_FORMATS_2026-08-19 §3.1) — then hash[16] @0x24 and
            // subhash[8] @0x34. The old code skipped only ONE u32, so hash was read
            // at 0x20 and p landed at 0x38 instead of 0x3C: every sample mode was
            // read 4 bytes early = shifted garbage (plausible-looking but wrong;
            // e.g. ffx_us_voice01 s0 decoded ns=4/doff=0xD6B36AE0 instead of the
            // real ns=91392/doff=0). Flags was declared in Fsb5Header but never
            // assigned — that was the skipped field.
            p += 4;                        // 0x1C: reserved/zero
            h.Flags = RU32(data, ref p);   // 0x20: flags
            Array.Copy(data, p, h.Hash, 0, 16); p += 16;    // 0x24..0x33
            Array.Copy(data, p, h.SubHash, 0, 8); p += 8;   // 0x34..0x3B
            // p = 0x3C = 60 = BaseHeaderSize — verified: voice01 s0 mode @0x3C
            // decodes ns=91392/doff=0/extra=1 and the full walk ends exactly at
            // hdrStart+SampleHeaderSize (0x96C) for all 119 records.

            // Read sample headers
            int hdrStart = p;
            for (int i = 0; i < h.NumSamples; i++)
            {
                // FIX 2026-09-15 (VALIDADOR-Restantes): bounds guard — on layouts the
                // reader does not model (e.g. FFX2 remaster Vorbis records) or on
                // truncated samples, the cursor 'p' can leave the buffer and the
                // unguarded RU32 below crashed with ArgumentOutOfRangeException
                // ('startIndex' inside BitConverter). Stop parsing gracefully;
                // well-formed files (record ends exactly at hdrStart+SampleHeaderSize)
                // are unaffected.
                if (p + 8 > data.Length || p + 8 > hdrStart + h.SampleHeaderSize) break;
                long mode = (long)RU32(data, ref p) | ((long)RU32(data, ref p) << 32);
                var s = new Fsb5Sample { Index = i };
                s.NameHash = (uint)(mode >> 32) & 0xFFFFFFFF; // low 32 of mode = packedOffset

                // Unpack mode (read as LE u64)
                s.NumSamples = (int)((mode >> 34) & 0x3FFFFFFF);
                s.DataOffset = ((mode >> 7) & 0x07FFFFFFL) << 5;
                int chBits = (int)((mode >> 5) & 3);
                s.Channels = chBits switch { 0 => 1, 1 => 2, 2 => 6, 3 => 8, _ => 1 };
                int freqIdx = (int)((mode >> 1) & 0x0F);
                s.SampleRate = freqIdx < FreqTable.Length ? FreqTable[freqIdx] : 44100;

                // Extra flags (bit 0)
                bool hasExtra = (mode & 1) != 0;
                if (hasExtra)
                {
                    // FIX 2026-09-15: also bound the extra-flag reads by the buffer
                    // length (logical bound alone let p run past the buffer on
                    // misparsed layouts). Guard only, parse logic unchanged.
                    while (p + 4 <= hdrStart + h.SampleHeaderSize && p + 4 <= data.Length)
                    {
                        uint ef = RU32(data, ref p);
                        var flag = new Fsb5ExtraFlag
                        {
                            Type = (int)((ef >> 25) & 0x7F),
                            Size = (int)((ef >> 1) & 0xFFFFFF),
                            Continue = (ef & 1) != 0
                        };
                        s.ExtraFlags.Add(flag);
                        p += flag.Size;
                        if (!flag.Continue) break;
                    }
                }
                // FIX 2026-09-16 (FMT-AUDIO audit): removed `else { p = hdrStart +
                // (i+1)*8; }` — sample records are VARIABLE length (8B mode + extra
                // flags), so once any earlier sample carried flags the absolute
                // reset rewound p into the middle of the header table and every
                // subsequent "sample" was garbage (real-world hit: ffx_music_bank00
                // .fsb desynced at s68, first flagless sample after 68 flagged ones;
                // parse died at 73/89). With no flags the cursor is already right
                // after the two RU32s — nothing to do.
                // Evidence: python byte-walk of the same bank lands p == hdrEnd
                // exactly (0x7AC) after all 89 records.

                h.Samples.Add(s);
            }

            // Name table
            // FIX 2026-09-15 (VALIDADOR-Restantes): CS0176 — BaseHeaderSize is a
            // const, must be qualified with the type name, not accessed via the
            // instance 'h'. Name qualification only, no behavior change.
            // FIX 2026-09-15 (2): bounds guards — (a) skip name-offset reads when the
            // declared region does not fit the buffer (truncated header dumps made
            // RU32 throw ArgumentOutOfRangeException); (b) skip individual names
            // whose absolute offset is negative or past the buffer (misparsed
            // layouts made Array.IndexOf throw on 'startIndex'). Guards only.
            int nameTableOff = Fsb5Header.BaseHeaderSize + h.SampleHeaderSize;
            if (h.NameTableSize > 0 && nameTableOff + h.NumSamples * 4 <= data.Length)
            {
                // Read name offsets
                int[] nameOffsets = new int[h.NumSamples];
                for (int i = 0; i < h.NumSamples; i++)
                    nameOffsets[i] = (int)RU32(data, nameTableOff + i * 4);

                // Read null-terminated strings
                // FIX 2026-09-15: bound by parsed sample count — after an early
                // break in the record loop h.Samples.Count < NumSamples and the
                // list indexer threw ArgumentOutOfRangeException('index').
                for (int i = 0; i < h.Samples.Count && i < nameOffsets.Length; i++)
                {
                    int absOff = nameTableOff + nameOffsets[i];
                    if (absOff >= 0 && absOff < data.Length)
                    {
                        int end = Array.IndexOf(data, (byte)0, absOff);
                        if (end < 0) end = data.Length;
                        h.Samples[i].Name = Encoding.ASCII.GetString(data, absOff, end - absOff);
                    }
                }
            }

            // Compute stream sizes
            // FIX 2026-09-15: iterate over the samples actually parsed — the loop
            // above may stop early (bounds guard), leaving h.Samples smaller than
            // h.NumSamples, which made this loop throw IndexOutOfRangeException.
            int dataStart = Fsb5Header.BaseHeaderSize + h.SampleHeaderSize + h.NameTableSize;
            for (int i = 0; i < h.Samples.Count; i++)
            {
                long nextOff = (i + 1 < h.Samples.Count)
                    ? h.Samples[i + 1].DataOffset
                    : h.DataSize;
                h.Samples[i].DataSize = (int)(nextOff - h.Samples[i].DataOffset);
            }

            return h;
        }

        static uint RU32(byte[] d, ref int p) { uint v = BitConverter.ToUInt32(d, p); p += 4; return v; }
        static uint RU32(byte[] d, int off) => BitConverter.ToUInt32(d, off);
    }
}
