// ─────────────────────────────────────────────────────────────────────────────
// FFX PS2 .mgrp (motion-group) animation format — STANDALONE REFERENCE PARSER
// ─────────────────────────────────────────────────────────────────────────────
// Purpose: complete, self-contained reader for the FFX PS2 `.mgrp` body-motion
//   animation container. No FFXProjectEditor dependencies — compile standalone:
//     csc Ps2MgrpAnimationReader.cs            (or add to any net8.0 project)
//   Run modes (see Main):
//     dump <file.mgrp>                         container + record/group table dump
//     decode <file.mgrp> [record] [group]      decode one clip, print channel stats
//     verify <file.mgrp>                       decode every clip, assert invariants
//     sample <file.mgrp> <record> <group>      print per-frame TRS for target 0
//
// Why this format (RE provenance):
//   The FFX HD Remaster (FFX.exe) reimplemented the PS2 motion decoder NATIVELY
//   in x86 — it does NOT emulate the PS2 VU0 path. All functions are named in the
//   canonical IDA database (FFX_recon.i64, image base 0x400000):
//     FFX_Mgrp_RelocateMseqRecordPointers        @0x837040  container/record reloc
//     FFX_Mgrp_BindMseqToActiveInstance          @0x837B40  subid -> group -> record
//     FFX_Mseq_InitChannelTracks                 @0x839A00  a2 header + 2-bit modes
//     FFX_Mseq_AdvanceKeyedChannelCursors        @0x839550  delta-RLE keyframe codec
//     FFX_Mseq_EvaluateKeyedChannelsAtFrame      @0x839440  per-frame eval + LERP
//     FFX_Mseq_WriteSampledTransformChannels     @0x838300  dequant -> bone TRS
//     FFX_Mseq_S16ToUnitFloat                    @0x839E50  int16 / 4096
//   The codec was validated byte-exact across the whole PS2 corpus (1281 .mgrp,
//   1778 clips, 222,080 keyed streams, 0 decode errors) in 2026-06-03 lane.
//   Docs: docs/reverse/FFX_MGRP_FORMAT_VALIDATED_2026-08-01.md (this lane; the previously cited FFX_MGRP_FORMAT_COMPLETE_2026-08-19.md does not exist),
//         docs/history/FFX_MGRP_CHANNEL_LAYOUT_2026-06-03.md,
//         docs/history/FFX_MGRP_NATIVE_DECODE_CRACKED_2026-06-03.md.
//   Prior decoder (RuntimeTools/MgrpPs2AnimExportLab/MgrpDecoder.cs) is the
//   glTF-exporter sibling; this file is the standalone reference/teaching reader.
//
// MAINT notes:
//   - All offsets are little-endian. All file offsets are relative to file start
//     (the runtime relocates them to absolute pointers on load).
//   - The record table lives at the END of the file (offset = u32@0x0C), NOT at
//     offset 0x14. SIZE LAW: fileSize == dataLen + motionCount*20.
//   - The a2 field at +4 is frameRate = 7680 (fixed-point 8.8 = 30 fps * 256).
//     Earlier docs misread the bytes `00 1e` as big-endian 0x001E "magic"; the
//     little-endian value is 0x1E00 = 7680.
//   - The "channel-table" at offA is the MOTION/sequence list (subid variants),
//     NOT the keyed streams. The clip data comes from the group-table (offB)
//     entry ptrB -> a2 block.
// ─────────────────────────────────────────────────────────────────────────────
using System;
using System.Buffers.Binary;
using System.Collections.Generic;
using System.IO;

namespace FFXProjectEditor.FfxLib.Ps2
{
    // ── Shared little-endian primitives ───────────────────────────────────────
    internal static class MgrpBits
    {
        public static ushort U16(byte[] d, int o) => BinaryPrimitives.ReadUInt16LittleEndian(d.AsSpan(o));
        public static uint U32(byte[] d, int o) => BinaryPrimitives.ReadUInt32LittleEndian(d.AsSpan(o));
        public static short S16(byte[] d, int o) => (short)BinaryPrimitives.ReadUInt16LittleEndian(d.AsSpan(o));
        public static int Sx(int v, int bits) { int m = 1 << (bits - 1); return (v ^ m) - m; } // sign-extend
        public static float S16Unit(short s) => Sx(s & 0xFFFF, 16) / 4096.0f;  // FFX_Mseq_S16ToUnitFloat
    }

    // ── Container: header + record table ─────────────────────────────────────
    // [0x00] u32 flag        always 0
    // [0x04] u32 motionCount number of MSEQ records (0 = stub, 1 = resident, 8 = regmot)
    // [0x08] u32 reserved    always 0
    // [0x0C] u32 dataLen     offset of the record table (== fileSize - motionCount*20)
    // [0x14] data region     a2 blocks, mode streams, keyed streams, tables
    // [dataLen] record table motionCount records x 20B
    internal sealed class MgrpFile
    {
        public byte[] Data = Array.Empty<byte>();
        public uint Flag, MotionCount, Reserved, DataLen;
        public List<MgrpRecord> Records = new();

        public static MgrpFile? Load(string path)
        {
            try { return Parse(File.ReadAllBytes(path)); } catch { return null; }
        }

        public static MgrpFile? Parse(byte[] d)
        {
            if (d.Length < 0x14) return null;
            var f = new MgrpFile { Data = d };
            f.Flag = MgrpBits.U32(d, 0x00);
            f.MotionCount = MgrpBits.U32(d, 0x04);
            f.Reserved = MgrpBits.U32(d, 0x08);
            f.DataLen = MgrpBits.U32(d, 0x0C);
            // SIZE LAW: the record table is the last motionCount*20 bytes.
            if (f.DataLen + f.MotionCount * 20 != (uint)d.Length) return null;
            for (int r = 0; r < f.MotionCount; r++)
            {
                int ro = (int)f.DataLen + r * 20;
                f.Records.Add(new MgrpRecord
                {
                    Index = r,
                    F0 = MgrpBits.U32(d, ro),
                    Subid = MgrpBits.U32(d, ro + 4),
                    ChannelCount = MgrpBits.U16(d, ro + 8),
                    GroupCount = MgrpBits.U16(d, ro + 10),
                    OffA = MgrpBits.U32(d, ro + 12),
                    OffB = MgrpBits.U32(d, ro + 16),
                });
            }
            return f;
        }
    }

    // ── MSEQ record (20B) ────────────────────────────────────────────────────
    // [+0]  u32 f0    always 0
    // [+4]  u32 subid packed motion id: monId = subid & 0xFFF, groupNibble = (subid>>12)&0xF
    // [+8]  u16 a     channel-table entry count (motion/sequence list)
    // [+10] u16 b     group-table entry count (each entry = one clip)
    // [+12] u32 offA  channel-table offset (motions list — NOT the keyed streams)
    // [+16] u32 offB  group-table offset (clip table; entry ptrB -> a2 block)
    internal sealed class MgrpRecord
    {
        public int Index;
        public uint F0, Subid;
        public int ChannelCount, GroupCount;
        public uint OffA, OffB;
        public uint MonId => Subid & 0xFFF;
        public uint GroupNibble => (Subid >> 12) & 0xF;
        public List<MgrpGroupEntry> Groups = new();
    }

    // ── Group-table entry (16B) — one clip ───────────────────────────────────
    // [+0]  u32 f0   always 0
    // [+4]  u32 f4   always 2
    // [+8]  u32 ptrA prelude pointer (frame table / preamble)
    // [+12] u32 ptrB a2 sub-clip block pointer  <<< the animation data lives here
    internal sealed class MgrpGroupEntry
    {
        public int Index;
        public uint F0, F4, PtrA, PtrB;
    }

    // ── a2 sub-clip block (16B header) ───────────────────────────────────────
    // [+0]  u16 frameCount  number of frames in the clip
    // [+2]  u16 targetCount number of bones the clip addresses (channels = 9 * min(targetCount, skeletonBoneCount))
    // [+4]  u16 frameRate   fixed-point 8.8 = 7680 (30 fps * 256)
    // [+6]  u16 extraCount  event-region entry count (8B each; sound/trigger, semantics not decoded)
    // [+8]  u32 modeOff     offset of 2-bit mode stream, relative to a2
    // [+12] u32 keyedOff    offset of keyed/const value region, relative to a2
    // [+16] u32 extraOff    offset of event region, relative to a2 (only if extraCount>0)
    internal sealed class MgrpClip
    {
        public int FrameCount, TargetCount, FrameRate, ExtraCount;
        public int ModeOff, KeyedOff, ExtraOff;
        public int ModeBase, ValueBase;          // absolute file offsets
        public List<MgrpChannel> Channels = new();
        public int ValueConsumed;                // bytes walked in the value region
        public int ClipEnd;                      // absolute offset where this clip ends (next clip / table)
    }

    // ── One channel (one component of one target bone) ───────────────────────
    // comp order: 0=rotX 1=rotY 2=rotZ 3=trX 4=trY 5=trZ 6=scX 7=scY 8=scZ
    // mode: 0=const 0.0, 1=const 1.0, 2=const int16 (2B in value region), 3=keyed delta-RLE
    internal sealed class MgrpChannel
    {
        public int Target;      // bone index within the clip (channel / 9)
        public int Comp;        // 0..8 component index (channel % 9)
        public int Mode;        // 0/1/2/3
        public bool IsAngle => Comp < 3;   // rotation channels interpolate with angle wrap
        public float Const;     // modes 0/1/2 (unit float, int16/4096)
        public short[]? Samples; // mode 3: one raw int16 sample per frame (pre-dequant)
        public int BlockLen;    // mode 3: byte length of the stream (incl. 2B length prefix)
        public string CompName => Ps2MgrpAnimationReader.CompNames[Comp];
    }

    internal static class Ps2MgrpAnimationReader
    {
        public static readonly string[] CompNames =
            { "rotX","rotY","rotZ","trX","trY","trZ","scX","scY","scZ" };

        // ── Resolve a record's group table (offB) ─────────────────────────────
        public static void LoadGroups(MgrpFile f, MgrpRecord rec)
        {
            rec.Groups.Clear();
            for (int g = 0; g < rec.GroupCount; g++)
            {
                int eo = (int)rec.OffB + 16 * g;
                if (eo + 16 > f.Data.Length) break;
                rec.Groups.Add(new MgrpGroupEntry
                {
                    Index = g,
                    F0 = MgrpBits.U32(f.Data, eo),
                    F4 = MgrpBits.U32(f.Data, eo + 4),
                    PtrA = MgrpBits.U32(f.Data, eo + 8),
                    PtrB = MgrpBits.U32(f.Data, eo + 12),
                });
            }
        }

        // ── Decode one clip (a2 block) into channels ──────────────────────────
        // FFX_Mseq_InitChannelTracks @0x839A00. boneCount = skeleton bone count
        // (from the .chr) used to clamp targetCount; pass 0 to skip clamping.
        public static MgrpClip? DecodeClip(MgrpFile f, MgrpGroupEntry grp, int boneCount)
        {
            var d = f.Data;
            int a2 = (int)grp.PtrB;
            if (a2 <= 0 || a2 + 16 > d.Length) return null;
            var clip = new MgrpClip
            {
                FrameCount = MgrpBits.U16(d, a2 + 0),
                TargetCount = MgrpBits.U16(d, a2 + 2),
                FrameRate = MgrpBits.U16(d, a2 + 4),
                ExtraCount = MgrpBits.U16(d, a2 + 6),
                ModeOff = (int)MgrpBits.U32(d, a2 + 8),
                KeyedOff = (int)MgrpBits.U32(d, a2 + 12),
                ExtraOff = (int)MgrpBits.U32(d, a2 + 16),
            };
            if (clip.FrameCount <= 0 || clip.FrameCount > 4096) return null;
            if (boneCount > 0) clip.TargetCount = Math.Min(clip.TargetCount, boneCount);
            clip.ModeBase = a2 + clip.ModeOff;
            clip.ValueBase = a2 + clip.KeyedOff;
            int nchan = 9 * clip.TargetCount;
            if (clip.ModeBase < 0 || clip.ModeBase + (nchan * 2 + 7) / 8 > d.Length) return null;

            // 2-bit mode stream, LSB-first, continuous bitstream.
            // channel order: target-major, 9 comps per target.
            int modeBit = 0;
            int vp = clip.ValueBase;
            for (int c = 0; c < nchan; c++)
            {
                int bytei = clip.ModeBase + (modeBit >> 3);
                int shift = modeBit & 7;
                int mode = (d[bytei] >> shift) & 3;
                modeBit += 2;
                var ch = new MgrpChannel { Target = c / 9, Comp = c % 9, Mode = mode };
                switch (mode)
                {
                    case 0: ch.Const = 0.0f; break;                          // const 0.0
                    case 1: ch.Const = 1.0f; break;                          // const 1.0 (rest scale)
                    case 2: ch.Const = MgrpBits.S16Unit(MgrpBits.S16(d, vp)); vp += 2; break;  // const int16
                    case 3:                                                  // KEYED delta-RLE
                        int L = MgrpBits.U16(d, vp);
                        ch.BlockLen = L;
                        ch.Samples = DecodeDeltaRle(d, vp + 2, clip.FrameCount);
                        vp += L;
                        break;
                }
                clip.Channels.Add(ch);
            }
            clip.ValueConsumed = vp - clip.ValueBase;
            // Clip end = value region end + event region + 4-align pad.
            clip.ClipEnd = vp + 8 * clip.ExtraCount;
            clip.ClipEnd = (clip.ClipEnd + 3) & ~3;
            return clip;
        }

        // ── Delta-RLE keyframe codec ──────────────────────────────────────────
        // FFX_Mseq_AdvanceKeyedChannelCursors @0x839550. Produces exactly
        // `nframes` int16 samples (pre-dequant). Control byte c:
        //   c < 0x80            -> 7-bit signed delta (sign_extend7)
        //   c & 0x80 && c & 0x40 -> 14-bit signed delta (sign_extend14((c&0x3F)|(next<<6)))
        //   c & 0x80 && !(c&0x40)-> RUN: hold current delta for (c&0x3F) extra frames
        // Every frame: sample = (sample + delta) & 0xFFFF (int16 wrap).
        public static short[] DecodeDeltaRle(byte[] d, int pos, int nframes)
        {
            int delta = 0, sample = 0, run = 0;
            var outp = new short[nframes];
            for (int i = 0; i < nframes; i++)
            {
                if (run != 0) run--;
                else if (pos < d.Length)
                {
                    int c = d[pos++];
                    // FIX 2026-09-15 (FFX-STRUCTURES validation): qualify Sx ->
                    // MgrpBits.Sx (CS0103; Sx lives in the sibling static class
                    // MgrpBits, every other helper here is already qualified).
                    if (c < 0x80) delta = MgrpBits.Sx(c & 0x7F, 7);
                    else if ((c & 0x40) != 0)
                    {
                        if (pos < d.Length) { int lo = c & 0x3F, hi = d[pos++]; delta = MgrpBits.Sx(lo | (hi << 6), 14); }
                    }
                    else run = c & 0x3F;
                }
                sample = MgrpBits.Sx((sample + delta) & 0xFFFF, 16);
                outp[i] = (short)sample;
            }
            return outp;
        }

        // ── Dequant: raw int16 sample -> unit float ───────────────────────────
        // FFX_Mseq_S16ToUnitFloat @0x839E50: unit = int16 / 4096.
        public static float SampleToUnit(short s) => MgrpBits.S16Unit(s);

        // ── Full local TRS of one target at an integer frame (subframe = 0) ───
        // Dequant per FFX_Mseq_WriteSampledTransformChannels @0x838300:
        //   rot X/Y/Z   rad = WrapRadiansPi(unit * 2pi) = int16 * pi/2048
        //   trans X/Y/Z t   = unit * instScale * 4096 = int16 * instScale
        //   scale X/Y/Z s   = unit = int16 / 4096
        // instScale = *(model+56) * 0.001 (per-instance; pass 0.001f if unknown).
        public static (float Rx, float Ry, float Rz, float Tx, float Ty, float Tz, float Sx, float Sy, float Sz)
            SampleTarget(MgrpClip clip, int target, int frame, float instScale)
        {
            float rx = 0, ry = 0, rz = 0, tx = 0, ty = 0, tz = 0, sx = 1, sy = 1, sz = 1;
            foreach (var ch in clip.Channels)
            {
                if (ch.Target != target) continue;
                float v = ch.Mode != 3 ? ch.Const : MgrpBits.S16Unit(ch.Samples![Math.Min(frame, ch.Samples.Length - 1)]);
                switch (ch.Comp)
                {
                    case 0: rx = WrapPi(2 * Math.PI * v); break;
                    case 1: ry = WrapPi(2 * Math.PI * v); break;
                    case 2: rz = WrapPi(2 * Math.PI * v); break;
                    case 3: tx = v * instScale * 4096f; break;
                    case 4: ty = v * instScale * 4096f; break;
                    case 5: tz = v * instScale * 4096f; break;
                    case 6: sx = v; break;
                    case 7: sy = v; break;
                    case 8: sz = v; break;
                }
            }
            return (rx, ry, rz, tx, ty, tz, sx, sy, sz);
        }

        static float WrapPi(double a)
        {
            const double PI = Math.PI;
            while (a > PI) a -= 2 * PI;
            while (a < -PI) a += 2 * PI;
            return (float)a;
        }

        // ── Coherence metric (validation aid) ─────────────────────────────────
        // Fraction of adjacent-sample steps <= 64. Random noise ~0.5; real motion
        // curves are 0.9+. Used by the corpus gate to prove the codec is right.
        public static float Coherence(short[] samples)
        {
            if (samples.Length < 2) return 1f;
            int small = 0;
            for (int i = 0; i < samples.Length - 1; i++)
                if (Math.Abs(samples[i + 1] - samples[i]) <= 64) small++;
            return (float)small / (samples.Length - 1);
        }

        // ═════════════════════════════════════════════════════════════════════
        // CLI entry (compile standalone; run modes documented at top of file)
        // ═════════════════════════════════════════════════════════════════════
        public static int Main(string[] args)
        {
            if (args.Length < 2) { PrintUsage(); return 1; }
            string mode = args[0], path = args[1];
            var f = MgrpFile.Load(path);
            if (f == null) { Console.Error.WriteLine($"not a valid .mgrp (SIZE LAW failed): {path}"); return 1; }
            Console.WriteLine($"file={path} size={f.Data.Length} flag={f.Flag} motionCount={f.MotionCount} dataLen={f.DataLen}");
            foreach (var rec in f.Records)
            {
                LoadGroups(f, rec);
                Console.WriteLine($"  record[{rec.Index}] subid=0x{rec.Subid:X8} (monId={rec.MonId} grpNib={rec.GroupNibble}) a={rec.ChannelCount} b={rec.GroupCount} offA=0x{rec.OffA:X} offB=0x{rec.OffB:X}");
                if (mode == "dump") continue;
                foreach (var grp in rec.Groups)
                {
                    var clip = DecodeClip(f, grp, 0);
                    if (clip == null) { Console.WriteLine($"    group[{grp.Index}] ptrB=0x{grp.PtrB:X} DECODE FAILED"); continue; }
                    int keyed = 0, c0 = 0, c1 = 0, c2 = 0;
                    foreach (var ch in clip.Channels) { if (ch.Mode == 3) keyed++; else if (ch.Mode == 0) c0++; else if (ch.Mode == 1) c1++; else c2++; }
                    float minCoh = 1f;
                    foreach (var ch in clip.Channels) if (ch.Mode == 3) minCoh = Math.Min(minCoh, Coherence(ch.Samples!));
                    Console.WriteLine($"    group[{grp.Index}] ptrB=0x{grp.PtrB:X} frames={clip.FrameCount} targets={clip.TargetCount} rate={clip.FrameRate} extra={clip.ExtraCount} modes[0/1/2/3]={c0}/{c1}/{c2}/{keyed} valConsumed={clip.ValueConsumed} clipEnd=0x{clip.ClipEnd:X} minCoh={minCoh:F3}");
                    if (mode == "sample" && grp.Index == (args.Length > 4 ? int.Parse(args[4]) : 0))
                    {
                        for (int fr = 0; fr < Math.Min(clip.FrameCount, 8); fr++)
                        {
                            var t = SampleTarget(clip, 0, fr, 0.001f);
                            Console.WriteLine($"      f{fr}: rot=({t.Rx:F4},{t.Ry:F4},{t.Rz:F4}) tr=({t.Tx:F4},{t.Ty:F4},{t.Tz:F4}) sc=({t.Sx:F4},{t.Sy:F4},{t.Sz:F4})");
                        }
                    }
                }
            }
            if (mode == "verify")
            {
                int clips = 0, streams = 0, bad = 0;
                foreach (var rec in f.Records)
                    foreach (var grp in rec.Groups)
                    {
                        var clip = DecodeClip(f, grp, 0);
                        if (clip == null) { bad++; continue; }
                        clips++;
                        foreach (var ch in clip.Channels)
                            if (ch.Mode == 3)
                            {
                                streams++;
                                if (ch.Samples!.Length != clip.FrameCount) bad++;
                            }
                    }
                Console.WriteLine($"verify: clips={clips} keyedStreams={streams} bad={bad}");
            }
            return 0;
        }

        static void PrintUsage()
        {
            Console.WriteLine("usage: Ps2MgrpAnimationReader <dump|decode|verify|sample> <file.mgrp> [record] [group]");
        }
    }
}
