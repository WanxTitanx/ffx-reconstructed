using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Numerics;
using FFXProjectEditor.Diagnostics;

namespace FFXProjectEditor.FfxLib.MagicDll;

// ── MonsterMagicVm ─────────────────────────────────────────────────────────────
//
// Port of noclip.website MonsterMagic VM (actor.ts processOp ~55 opcodes +
// processMonsterParticle ~20 opcodes + ActorMagicManager state machine).
//
// This VM interprets the 16-bit bytecode emitted by parseActorMagicCommands()
// (actor.ts:688-708) which lives inside the actor particle data section of
// PS2 magic/field files (e.g. monster .chr particle data).
//
// The bytecode is read from Int16Array; each instruction consumes 1+ words.
// Opcodes 0x00-0xFF cover the full dispatch table; the VM manages:
//   - 4 execution threads per state (MagicThread)
//   - vec[0..5] accumulation (vecs[j] += vecs[j+2] every tick)
//   - particle emitters (basic MonsterEmitter + full Emitter bridge)
//   - flipbook display, drip trails, billboard matrix construction
//
// Constants (from noclip TypeScript):
//   FRAME_RATE = 30, FLIPBOOK_SCALE = 16, TAU = 2*pi, ANGLE_UNIT = 0x1000 = 2pi
//
// ────────────────────────────────────────────────────────────────────────────────
// MonsterMagicVm (portado de noclip.website actor.ts, 2026-08-19)
// ────────────────────────────────────────────────────────────────────────────────

// ── Enums ──────────────────────────────────────────────────────────────────────

/// <summary>Position mode for particles (actor.ts:1181-1185).</summary>
public enum MonsterPosMode
{
    Default = 0,
    Radial  = 2,
    Bone    = 4,
}

/// <summary>VecOp mode for vec-to-position conversion (actor.ts:1298-1301).</summary>
public enum MonsterVecOp
{
    Default = 0,
    Angle   = 3,
}

// ── Lightweight vector helpers ──────────────────────────────────────────────────

/// <summary>
/// Mutable 4-component float vector, used as the building block for vec[0..5],
/// color, scaleAndAngle, etc. in the MonsterMagic VM.
/// </summary>
public sealed class Vec4
{
    public float X, Y, Z, W;

    public Vec4() { }
    public Vec4(float x, float y, float z, float w) { X = x; Y = y; Z = z; W = w; }

    public float this[int i]
    {
        get => i switch { 0 => X, 1 => Y, 2 => Z, 3 => W, _ => throw new IndexOutOfRangeException() };
        set { switch (i) { case 0: X = value; break; case 1: Y = value; break; case 2: Z = value; break; case 3: W = value; break; } }
    }

    public void CopyFrom(Vec4 other) { X = other.X; Y = other.Y; Z = other.Z; W = other.W; }
    public void Zero() { X = Y = Z = W = 0; }
    public void Set(float x, float y, float z, float w) { X = x; Y = y; Z = z; W = w; }
    public void Scale(float s) { X *= s; Y *= s; Z *= s; W *= s; }

    /// <summary>Accumulate: this += other.</summary>
    public void Add(Vec4 other) { X += other.X; Y += other.Y; Z += other.Z; W += other.W; }
}

// ── MagicThread ────────────────────────────────────────────────────────────────

/// <summary>Single execution thread within a MonsterMagicState (actor.ts:1085-1090).</summary>
public sealed class MagicThread
{
    /// <summary>Current program pointer (Int16Array index). -1 = dead.</summary>
    public int Pointer = -1;

    /// <summary>Remaining sleep ticks. 0 = running.</summary>
    public int Timer;

    /// <summary>Saved return pointer (set by CALL).</summary>
    public int Saved = -1;

    /// <summary>True if this thread runs in the render phase.</summary>
    public bool Render;
}

// ── MonsterParticle ────────────────────────────────────────────────────────────

/// <summary>Individual particle state driven by processMonsterParticle (actor.ts:768-784).</summary>
public sealed class MonsterParticle
{
    public readonly float[] Pos   = new float[3];
    public readonly float[] Vel   = new float[3];
    public readonly float[] Accel = new float[3];

    /// <summary>[0]=scale, [1]=scaleVel, [2]=angle, [3]=angleVel</summary>
    public readonly float[] ScaleAndAngle = new float[4];

    /// <summary>[0]=R, [1]=G, [2]=B, [3]=A  (0..1 range)</summary>
    public readonly float[] Color    = new float[4];
    /// <summary>[0]=R, [1]=G, [2]=B, [3]=A  (velocity)</summary>
    public readonly float[] ColorVel = new float[4];

    public float T;
    public float Lifetime;
    public int   FlipbookIndex;
    public int   Ptr = -1;
    public MonsterPosMode PosMode;
    public readonly float[] Center = new float[3];
    public bool ShouldLoop;

    public MonsterParticle(MonsterEmitter emitter)
    {
        Emitter = emitter;
    }

    public MonsterEmitter Emitter { get; }
}

// ── MonsterEmitter ─────────────────────────────────────────────────────────────

/// <summary>
/// Basic particle emitter managed by MonsterMagicVm. Not the full noclip
/// ParticleSystem emitter; this is the simpler version used inside the
/// MonsterMagic VM for cheap flipbook-based particles.
/// </summary>
public sealed class MonsterEmitter
{
    private readonly MonsterMagicState _owner;
    private readonly short[] _data;

    public MonsterParticle[] Particles { get; }
    public int NextIndex;

    public MonsterEmitter(MonsterMagicState owner, int count, short[] data)
    {
        _owner = owner;
        _data  = data;
        Particles = new MonsterParticle[count];
        for (int i = 0; i < count; i++)
            Particles[i] = new MonsterParticle(this);
    }

    public void Emit(int offs, float[] pos)
    {
        MonsterParticle p = Particles[NextIndex++];
        NextIndex %= Particles.Length;
        p.Ptr = offs;
        Array.Copy(pos, p.Pos, 3);
        p.Vel[0] = p.Vel[1] = p.Vel[2] = 0;
        p.Accel[0] = p.Accel[1] = p.Accel[2] = 0;
        p.Lifetime = 0;
        p.T = 0;
    }
}
// ── FlipbookState ──────────────────────────────────────────────────────────────

/// <summary>Billboard flipbook display state (actor.ts:1248-1289).</summary>
public sealed class FlipbookState
{
    public readonly int Flipbook;
    public readonly int AlphaSource;
    public readonly int ScaleSource;
    public float Frame;
    public readonly bool Rotation;

    public FlipbookState(int flipbook, int var0, int var1, bool rotation)
    {
        Flipbook = flipbook;
        Rotation = rotation;
        ScaleSource = var0 == 1 ? 0 : var1 == 1 ? 1 : -1;
        AlphaSource = var0 == 2 ? 0 : var1 == 2 ? 1 : -1;
    }
}

// ── DripState ──────────────────────────────────────────────────────────────────

/// <summary>Drip/trail state (actor.ts:1097-1245).</summary>
public sealed class DripState
{
    private readonly bool _stretchy;
    public readonly float[][] Points;
    public readonly float[] PrevPos = new float[3];
    public int NextIndex;
    public MonsterMagicState OtherState;
    public bool Full;
    private float _savedLength;
    private readonly float _floorOffset;

    public MonsterMagicState State { get; }
    public int FlipbookIndex { get; }

    public DripState(MonsterMagicState state, int flipbook, int count)
    {
        State = state;
        FlipbookIndex = flipbook;
        Points = new float[count][];
        for (int i = 0; i < count; i++)
            Points[i] = new float[3];
        OtherState = state;
    }

    private DripState(MonsterMagicState state, int flipbook, int count, float floorOffset, float[] pos)
        : this(state, flipbook, count)
    {
        _stretchy = true;
        _floorOffset = floorOffset;
        for (int i = 0; i < count; i++)
            Array.Copy(pos, Points[i], 3);
        OtherState = state.Parent!;
    }

    public static DripState CreateStretchy(MonsterMagicState state, int flipbook, int count,
        float floorOffset, float[] pos)
        => new DripState(state, flipbook, count, floorOffset, pos);

    public void Emit(float[] statePos)
    {
        if (_stretchy)
        {
            DripEmit(statePos);
            return;
        }
        OtherState = State;
        Array.Copy(statePos, Points[NextIndex], 3);
        NextIndex++;
        if (NextIndex == Points.Length)
        {
            NextIndex = 0;
            Full = true;
        }
        int idx = Step(NextIndex);
        _savedLength = 0;
        for (int i = 0; i < Points.Length - 1; i++)
        {
            if (idx == 0 && !Full) break;
            int prev = Step(idx);
            _savedLength += Vec3Dist(Points[idx], Points[prev]);
            idx = Step(idx);
        }
    }

    private void DripEmit(float[] pos)
    {
        MonsterMagicState parent = State.Parent!;
        // spacing = vecs[1][3] / (16 * points.length)
        float spacing = parent.Vecs[1].W / (16f * Points.Length);
        float[] dir = new float[3];
        dir[0] = parent.Vecs[1].X / 256f;
        dir[1] = parent.Vecs[1].Y / 256f;
        dir[2] = parent.Vecs[1].Z / 256f;
        Array.Copy(Points[0], PrevPos, 3);
        Array.Copy(pos, Points[0], 3);

        for (int i = 0; i < Points.Length; i++)
        {
            if (i > 0)
            {
                float[] diff = new float[3];
                Vec3Sub(diff, Points[i], Points[i - 1]);
                Vec3Add(diff, diff, dir);
                Vec3NormalizeToLength(diff, spacing);
                Vec3Add(Points[i], Points[i - 1], diff);
            }
        }
    }

    private int Step(int idx)
    {
        int next = _stretchy ? idx + 1 : idx - 1;
        if (next >= Points.Length) return 0;
        if (next < 0) return Points.Length - 1;
        return next;
    }

    // ── Vec3 helpers ───────────────────────────────────────────────────────
    private static float Vec3Dist(float[] a, float[] b)
    {
        float dx = a[0] - b[0], dy = a[1] - b[1], dz = a[2] - b[2];
        return MathF.Sqrt(dx * dx + dy * dy + dz * dz);
    }
    private static void Vec3Sub(float[] r, float[] a, float[] b)
    { r[0] = a[0] - b[0]; r[1] = a[1] - b[1]; r[2] = a[2] - b[2]; }
    private static void Vec3Add(float[] r, float[] a, float[] b)
    { r[0] = a[0] + b[0]; r[1] = a[1] + b[1]; r[2] = a[2] + b[2]; }
    private static void Vec3NormalizeToLength(float[] v, float len)
    {
        float mag = MathF.Sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        if (mag < 1e-8f) return;
        float s = len / mag;
        v[0] *= s; v[1] *= s; v[2] *= s;
    }
}

// ── MonsterMagicState ──────────────────────────────────────────────────────────

/// <summary>
/// Per-effect execution state in the MonsterMagic VM (actor.ts:1291-1347).
/// Each state has 4 threads, 6 vec4 accumulators, a position, flags, and
/// references to sub-resources (emitter, flipbook, drip).
/// </summary>
public sealed class MonsterMagicState
{
    public readonly float[] Pos = new float[3];
    public readonly Vec4[] Vecs = new Vec4[6];
    public MonsterMagicState? Parent;
    public int Origin;
    public bool Errored;
    public bool Alive = true;
    public int Flags;
    public readonly int[] LoopCounts = new int[4];
    public float Scale;
    public MonsterVecOp VecOp = MonsterVecOp.Default;
    public bool SetPos = true;
    public MonsterMagicState? VecBaseState;
    public MonsterMagicState?[] SavedChildren = new MonsterMagicState?[8];
    public int MatrixSource;
    public bool AtCamera;
    public readonly MagicThread[] Threads = new MagicThread[4];
    public MonsterEmitter? BasicEmitter;
    public DripState? Drip;
    public FlipbookState? Flipbook;
    public float DepthShift;
    public readonly float[] Color = { 1f, 1f, 1f, 1f };

    public MonsterMagicState(int addr)
    {
        for (int i = 0; i < 6; i++)
            Vecs[i] = new Vec4();
        for (int i = 0; i < Threads.Length; i++)
            Threads[i] = new MagicThread();
        Threads[0].Pointer = addr;
    }

    /// <summary>
    /// Convert vecs[1] into a world position according to VecOp mode
    /// (actor.ts:1326-1346).
    /// </summary>
    public void DoVecOp()
    {
        switch (VecOp)
        {
            case MonsterVecOp.Default:
                Pos[0] = Vecs[1].X / 16f;
                Pos[1] = Vecs[1].Y / 16f;
                Pos[2] = Vecs[1].Z / 16f;
                break;

            case MonsterVecOp.Angle:
                float[] basePos = VecBaseState?.Pos ?? new float[3];
                Pos[0] = basePos[0];
                Pos[1] = basePos[1];
                Pos[2] = basePos[2];
                const float TAU = 2.0f * MathF.PI;
                float angle = Vecs[1].Z * TAU / 0x1000f;
                float r = Vecs[1].X / 16f;
                Pos[0] += r * MathF.Sin(angle);
                Pos[1] += Vecs[1].Y / 16f;
                Pos[2] += r * MathF.Cos(angle);
                break;

            default:
                DebugLog.Warn("MagicMonsterVm", $"Unhandled VecOp {VecOp}");
                break;
        }
    }
}

// ── MagicRenderContext ─────────────────────────────────────────────────────────

/// <summary>Context passed into processOp during VM execution (actor.ts:1349-1356).</summary>
public sealed class MagicRenderContext
{
    public MonsterMagicState State = null!;
    public float[][] Bones = Array.Empty<float[]>(); // bone matrices (flattened 4x4)
    public MagicThread Thread = null!;
    public bool GotEndAll;
    public int Flags;
    public readonly float[] ClearColor = { 1f, 1f, 1f };
}
