// ── VoiceInfoReader.cs ──────────────────────────────────────────────
// Standalone reader for FFX PS2 `voice/voiceinfo.bin` (research tool).
// NOT part of FFXProjectEditor — lives in research_tools/Audio/.
//
// FORMAT (empirical, 2026-09-16 — atlas §435 documents only "u16 LE offsets"):
//   The file is a flat little-endian u16 array (no header). Observed values
//   are mostly monotonically increasing offsets, but the sequence RESETS at
//   several points (e.g. jppc: value 0x0100 at index 0x2A) and contains
//   sentinel entries 0x0000 and 0xFFFF. Sizes: FFX1 jppc = 25,850 B
//   (12,925 u16), FFX2 uspc = 24,978 B (12,489 u16).
//
//   Segment hypothesis (UNPROVEN — marked UNKNOWN): each maximal run of
//   strictly increasing values is one sub-table (per voice bank / per
//   language / per scene) whose entries are offsets into a companion voice
//   data stream. The PS2 jppc/voice/ dir contains ONLY this file — the
//   pointed-at data lives inside the disc archives, so target resolution
//   cannot be validated from this file alone.
//
//   This reader enumerates facts only: entry count, sentinel counts,
//   segment boundaries (where the sequence decreases), per-segment ranges.
// ──────────────────────────────────────────────────────────────────
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace FevReference
{
    public sealed class VoiceInfoSegment
    {
        public int StartIndex;      // first u16 index of the segment
        public int Count;           // entries in this increasing run
        public ushort First;        // first offset value
        public ushort Last;         // last offset value
        public int Sentinels0;      // 0x0000 entries inside the run
        public int SentinelsF;      // 0xFFFF entries inside the run
    }

    public sealed class VoiceInfoFile
    {
        public int EntryCount;                       // total u16 entries
        public ushort[] Entries = Array.Empty<ushort>();
        public int Sentinel0Count;                   // total 0x0000
        public int SentinelFCount;                   // total 0xFFFF
        public int MonotonicViolations;              // entries[i] < entries[i-1]
        public List<VoiceInfoSegment> Segments = new();
    }

    public static class VoiceInfoReader
    {
        /// <summary>Parse the raw u16 table and segment it at monotonicity breaks.</summary>
        public static VoiceInfoFile Read(byte[] data)
        {
            if (data == null || data.Length < 2)
                throw new InvalidDataException("voiceinfo.bin too small");
            if ((data.Length & 1) != 0)
                throw new InvalidDataException("voiceinfo.bin has odd byte length — not a clean u16 table");

            var f = new VoiceInfoFile();
            int n = data.Length / 2;
            f.Entries = new ushort[n];
            f.EntryCount = n;
            for (int i = 0; i < n; i++)
                f.Entries[i] = (ushort)(data[i * 2] | (data[i * 2 + 1] << 8));

            VoiceInfoSegment seg = null;
            for (int i = 0; i < n; i++)
            {
                ushort v = f.Entries[i];
                if (v == 0x0000) f.Sentinel0Count++;
                if (v == 0xFFFF) f.SentinelFCount++;

                if (seg == null)
                {
                    seg = new VoiceInfoSegment { StartIndex = i, First = v };
                    f.Segments.Add(seg);
                }
                else
                {
                    // monotonic break = new segment (strict decrease on non-sentinel)
                    ushort prev = f.Entries[i - 1];
                    if (v < prev && prev != 0xFFFF && v != 0x0000 && v != 0xFFFF)
                    {
                        f.MonotonicViolations++;
                        seg.Last = prev;
                        seg = new VoiceInfoSegment { StartIndex = i, First = v };
                        f.Segments.Add(seg);
                    }
                }
                seg.Count++;
                if (v == 0x0000) seg.Sentinels0++;
                if (v == 0xFFFF) seg.SentinelsF++;
                seg.Last = v;
            }
            return f;
        }
    }
}
