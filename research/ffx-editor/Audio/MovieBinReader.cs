// ── MovieBinReader.cs ───────────────────────────────────────────────
// Standalone reader for FFX-2 PS2 `movie/movie.bin` (research tool).
// NOT part of FFXProjectEditor — lives in research_tools/Audio/ (video index
// is grouped with the media lane).
//
// FORMAT (empirical, 2026-09-16): the only observed instance is the FFX-2
//   disc stub (56 B, jppc + uspc). Its own readme.txt says the original PS2
//   movie payload (1.25 GB) was deleted and "all data" zeroed for the HD
//   re-release — yet the file still holds 14 × u32 records whose byte-0 is
//   always 0x04 and whose upper bytes carry a value with the 0x8000 flag bit
//   sometimes set:
//       u32 raw = 0xVVVVVVFF —  FF = flags/type byte (0x04 everywhere here),
//                               VVVVVV = 24-bit payload (bit23 = flag?)
//   Examples: 0x02CE4004 -> flags=0x04 val=0x02CE40 (183,872)
//             0x0EE98004 -> flags=0x04 val=0x0EE980 &flag23 (977,280|flag)
//   Semantics UNKNOWN: candidates are (a) DVD sector LBN/length pairs in the
//   original disc layout, (b) a per-movie byte-length table the code indexes
//   (moviefunc_ac.c "movie_file_size_tbl" per the readme). No FFX-1 copy of
//   movie.bin exists in the corpus — FFX-1 HD movies live in
//   ps3data/video/*.webm + *.dat float metadata, and the PS2 original stored
//   them as DVD-resident streams outside the extracted master tree.
//
//   This reader enumerates the raw u32 records + decoded flag/payload fields.
// ──────────────────────────────────────────────────────────────────
using System;
using System.Collections.Generic;
using System.IO;

namespace FevReference
{
    public sealed class MovieBinRecord
    {
        public int Index;
        public uint Raw;
        public int FlagByte;      // raw & 0xFF (0x04 in all observed records)
        public int Payload24;     // raw >> 8
        public bool Flag23;       // (raw & 0x8000_0000) != 0  — high bit of payload24
    }

    public static class MovieBinReader
    {
        public static List<MovieBinRecord> Read(byte[] data)
        {
            if (data == null || data.Length < 4 || (data.Length & 3) != 0)
                throw new InvalidDataException("movie.bin is not a u32 record table");
            var list = new List<MovieBinRecord>(data.Length / 4);
            for (int i = 0; i < data.Length / 4; i++)
            {
                uint raw = BitConverter.ToUInt32(data, i * 4);
                list.Add(new MovieBinRecord
                {
                    Index = i,
                    Raw = raw,
                    FlagByte = (int)(raw & 0xFF),
                    Payload24 = (int)(raw >> 8),
                    Flag23 = (raw & 0x8000_0000u) != 0
                });
            }
            return list;
        }
    }
}
