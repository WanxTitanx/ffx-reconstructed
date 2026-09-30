// ─────────────────────────────────────────────────────────────────────
//  ParticleVmInterpreter — C# port of noclip.website particle.ts
//
//  STATUS (2026-09-15, backlog-close audit): STUB / TRUNCATED.
//  This file contains ONLY the constants and enums of the intended port.
//  The interpreter itself (opcode dispatch, ~80 opcodes, 50+ data-format
//  parsers, emitter state machine, instruction class hierarchy) was lost
//  to truncation and was never completed — none of it exists here.
//  An earlier header claimed a "fully functional" update/simulation VM;
//  that claim was false and is retracted (audit finding F70).
//
//  Classification per docs/reverse/FFX_STRUCTURE_AUDIT_KERNEL_BATTLE_
//  MAGIC_2026-09-13.md finding F70: reference-only (noclip-derived),
//  NOT verified byte-level against game binaries. Byte-level proof
//  exists only for the .tbl catalogs. To revive this port, re-port from
//  work/noclip_reference/particle.ts (5708 lines, intact)
//  + work/noclip_reference/instruction_table_20260802.json (80 entries).
//
//  Source: noclip.website particle.ts (2026-08-19, 5708 lines)
//         + docs/reverse/NOCLIP_WEBSITE_FFX_COMPLETE_2026-08-19.md §6
//         + work/noclip_reference/instruction_table_20260802.json
// ─────────────────────────────────────────────────────────────────────

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Numerics;
using System.Runtime.CompilerServices;

namespace FFXProjectEditor.FfxLib.Magic
{
    // ═════════════════════════════════════════════════════════════════
    //  Constants (particle.ts:18-19, 1108, 5316, 5390-5391)
    // ═════════════════════════════════════════════════════════════════

    public static class ParticleConstants
    {
        public const int VecCount = 26;
        public const float FrameRate = 30f;
        public const int FlipbookVertexStride = 2 + 4 + 2;
        public const float FlipbookScale = 16f;
        public const int TrailPointCount = 256;
        public const uint EndTime = 0xFFFFF000;
        public const float EmitterMaxTime = 0x70000;
        public const float EmitterDoneTimer = -0x1000;
    }

    // ═════════════════════════════════════════════════════════════════
    //  Enums (particle.ts:166-170, 185-189, 746-751, etc.)
    // ═════════════════════════════════════════════════════════════════

    public enum ParticleDistribution { Uniform = 0, Triangle = 1, Cusp = 2 }
    public enum RandomRangeMode { Symmetric = 0, Positive = 1, Negative = 2 }
    public enum ClusterMode { Default = 0, Moving = 1, Camera = 2, Fixed = 3 }
    public enum GeoPosMode { Default = 0, Origin = 1, Camera = 2 }
    public enum DepthSpace { Emitter = 0, View = 1, World = 2 }
    public enum BillboardType { None = 0, Full = 1, YOnly = 2 }
    public enum EmitterState { Running = 0, Ending = 1, Waiting = 2 }
    public enum GeometryPrimitive { ColorTri = 0, TexTri = 1, ColorQuad = 2, TexQuad = 3 }

    [Flags]
    public enum ChainFlags : ushort
    {
        None = 0, Active = 0x0001, FixedLength = 0x0002, HitMax = 0x0004,
        Orphaned = 0x0008, Remove = 0x0010, DoneGrowing = 0x0020,
        DoneAtMax = 0x0080, FixedTarget = 0x0100, InheritPos = 0x0200,
        NormDir = 0x0400, Reverse = 0x1000, Attracted = 0x2000,
    }

    [Flags]
    public enum BindingFlags : ushort
    {
        None = 0, Actor = 1, Layer = 2, Material = 4, Part = 8,
        ParentMask = 0x0F, Hide = 0x10, IgnoreScale = 0x20,
        SetScale = 0x40, Stationary = 0x100, Position = 0x8000,
    }

    public enum EulerOrder { Xyz = 0, Yxz = 1, Zxy = 2, Xzy = 3, Yzx = 4, Zyx = 5 }
    public enum GeoParticleMode { Default = 0, Blur = 1, BlurZ = 2, Mask = 7, Fog = 8 }

    // FIX 2026-09-15 (VALIDADOR-Restantes): file was truncated at the last enum —
    // the namespace opened at line 25 was never closed, so the file did not
    // compile (CS1513). Only the missing closing brace was added; the file
    // remains a stub (constants + enums only, interpreter classes not ported yet).
}
