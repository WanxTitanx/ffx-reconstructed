# FFX.exe Decompilation — Batch 29 (FFX Math Utilities)

**Database:** ffxoficial_COPY.i64 (session ffx-session-002)
**Date:** 2026-07-28
**Scope:** `FFX_Math_*` (197 funcs) — vector math, matrix ops, quaternion, angle utilities, spline eval, random

---

## Summary

FFX's native math library has **197 functions** covering the full 3D math pipeline: Vec2/Vec3/Vec4 operations, Matrix4x4 transforms (rotate/scale/translate/compose/inverse), quaternion SLERP, angle normalization (10+ variants), cubic spline evaluation, projection math, ray-triangle intersection, and random jitter. The library is **heavily specialized** — Vec4MulScalar alone has 6+ variants for different register/scratchpad layouts.

| Category | Functions | Key Operations |
|----------|-----------|----------------|
| Vec4 operations | ~60 | Assign, Copy, Mul, Add, Sub, Normalize, Scale, Transform, Clamp, Scratch buffers |
| Vec3 operations | ~30 | Mul, Scale, Normalize, Cross, Magnitude, Diff, Distance, Clamp, Transform |
| Matrix4x4 | ~30 | Multiply, Identity, RotateX/Y/Z, Compose, Inverse, Projection, View, TransformVec4 |
| Angle utilities | ~20 | NormalizeAngle (×10 variants), RadToDeg, WrapAngle, DirectionFromAngle |
| Float operations | ~15 | Sqrt, Lerp, AddInPlace, MulInPlace, SubInPlace, Clamp |
| Spline/Cubic | 6 | EvalCubicSpline, ComputeCubicSplineCoeffs (1D + 3D) |
| Vec2 operations | ~10 | ClassifyDirection, Atan2, Diff, RotateTranslate |
| Random | 3 | RandomFloat01, RandomJitterScale ×2 |
| Quaternion | 2 | Slerp, ToMatrix |
| Projection | ~10 | SetupProjectionViewport, Project2D, Project3DToScreen, BuildProjectionMatrix |
| Misc | ~10 | Pow2CeilExponent, BarycentricRay, RatioSquared, Waveform, RangeCompare |

`★ Insight ─────────────────────────────────────`
- **Vec4MulScalar tem 6+ variantes porque o PS2 tinha scratchpad** — a vasta maioria das funções Vec4Scratch* (Vec4CopyThruScratch, Vec4MulScalarScratch, etc) são code relics da era PS2, onde o scratchpad de 16KB era um bank de memória separado que exigia cópia explícita. No PC, viram `memcpy` glorificados mas os símbolos sobreviveram.
- **10+ variantes de NormalizeAngle** — esse é o maior número de overloads pra uma operação em todo FFX.exe. Cada subsistema (Field, Battle, Camera, AI, UI) implementou sua própria normalização angular com ranges diferentes (−π a π, 0 a 2π, 0 a 360, etc). Isso sugere **falta de padronização na codebase original**.
- **QuatSlerp usa x87 FPU** — a função usa `long double` (80-bit x87) em vez de `float`. O FFX.exe foi compilado com FPU x87 (não SSE) para operações escalares, o que é típico do MSVC 2012 em modo /arch:SSE (mas ainda usa x87 para trig/transcendentais).
- **SinCos table de 12 steps** — tabela pré-computada de seno/cosseno com 12 steps (30° increments). Usada para animações de câmera e interpolação quick-and-dirty em vez de chamar sin/cos reais.
`─────────────────────────────────────────────────`

---

## Detailed Function Analysis

### Vec4 Subsystem (60 functions)

The Vec4 type is FFX's **primary vector type** (not Vec3). 4-component vectors (XYZ + W) used for positions, colors, and transforms.

**Assign/Copy variants:**
- `FFX_Math_Vec4Assign` — set all 4 components from params
- `FFX_Math_Vec4AssignCopy` — copy vector a → b
- `FFX_Math_Vec4AssignCopy2` — copy vector a → b (different register allocation)
- `FFX_Math_Vec4AssignCopy_w` — copy with W-component override
- `FFX_Math_Vec4AssignReverse` — copy with component reversal (WZYX)
- `FFX_Math_Vec4AssignReverse_w` — reverse + W override
- `FFX_Math_Vec4Copy` — raw copy
- `FFX_Math_Vec4Copy_qword` — copy as qword (2 dwords)

**Arithmetic:**
- `FFX_Math_Vec4MulScalar` — multiply vector by scalar
- `FFX_Math_Vec4MulScalar2` through `FFX_Math_Vec4MulScalar6` — same op, diff register
- `FFX_Math_Vec4Add4D` — add 4 vectors
- `FFX_Math_Vec4Sub4D` — subtract vector
- `FFX_Math_Vec4AddTransform` — add with transform context
- `FFX_Math_Vec4SubTransform` — subtract with transform context
- `FFX_Math_Vec4Mul` — component-wise multiply
- `FFX_Math_Vector4MulPerComponent` — per-component multiply

**Scratchpad variants (PS2 legacy):**
- `FFX_Math_Vec4ScratchInit` — init scratchpad vector
- `FFX_Math_Vec4CopyToScratchAndReverse` — copy to scratch + reverse
- `FFX_Math_Vec4CopyThruScratch` — copy through scratch
- `FFX_Math_Vec4CopyThruScratch2` — copy through scratch 2
- `FFX_Math_Vec4Add3DScratch` — add using scratch
- `FFX_Math_Vec4Add3DScratch_2/4/5` — same, more variants
- `FFX_Math_Vec4MulScalarScratch` — mul scalar in scratch
- `FFX_Math_Vec4MulScalarScratch_2/3/5/6` — same, more variants
- `FFX_Math_Vec4Sub3DScratch` — sub in scratch
- `FFX_Math_Vec4Sub3DScratch_2` — sub in scratch 2

**Normalize/Clamp:**
- `FFX_Math_Vec4Normalize` — normalize vector to unit length
- `FFX_Math_Vec4Clamp` — clamp components to range
- `FFX_Math_Vec4LengthWithGlobal` — compute length using global
- `FFX_Math_Vector4LengthWithBias` — length with bias
- `FFX_Math_Vector4LengthSqrtBias` — length sqrt with bias

**Float <-> Fixed16:**
- `FFX_Math_Float4ToFixed16` — float4 → 16-bit fixed
- `FFX_Math_Vec4FloatToInt16` — float → int16 vector
- `FFX_Math_Vec4Int16ToFloat` — int16 → float vector
- `FFX_Math_Vec4TransformFloat16` — transform float16 vector
- `FFX_Math_Vec4ToInt16_16` — vec4 to int16/16

**The scratchpad variants** show the PS2 legacy clearly. The PS2's EE (Emotion Engine) had a 16KB scratchpad that was faster than main memory. Virtuos's PC port kept the scratchpad abstraction as regular memory copies.

### Vec3 Subsystem (30 functions)

- `FFX_Math_Vec3Assign` — assign all 3 components
- `FFX_Math_Vec3Copy` — copy
- `FFX_Math_Vec3SetXYZ` — set XYZ
- `FFX_Math_Vec3SetFields` — set individual fields
- `FFX_Math_Vec3Set100` — set to (1,0,0)
- `FFX_Math_Vec3Scale` — scale by scalar
- `FFX_Math_Vec3MulScalar10` — multiply by scalar 10
- `FFX_Math_Vec3MulScalarStore` — multiply + store
- `FFX_Math_Vec3Mul3Scalars` — mul each component by different scalar
- `FFX_Math_Vec3Sub` — subtract
- `FFX_Math_Vec3Diff` — compute difference
- `FFX_Math_Vec3Diff_B` — diff variant
- `FFX_Math_Vec3Normalize` — normalize to unit
- `FFX_Math_Vec3Cross` — cross product
- `FFX_Math_Vec3MagnitudeSqrt` — magnitude via sqrt
- `FFX_Math_Vector3Delta` — delta
- `FFX_Math_Vector3SubAndNormalize` — subtract then normalize
- `FFX_Math_Vector3DiffWithBias` — diff with bias
- `FFX_Math_Vector3Distance_structural` — 3D distance
- `FFX_Math_Vector3LengthXZ` — 2D length (XZ plane)
- `FFX_Math_Vector3TransformByMatrixRow` — transform by matrix row

### Matrix4x4 Subsystem (30 functions)

- `FFX_Math_Matrix4x4MulGlobal` — 4x4 multiply (global matrix)
- `FFX_Math_Matrix4x4TripleMul` — A×B×C triple multiply
- `FFX_Math_Matrix4x4RotateX/Y/Z` — rotation matrix around axis
- `FFX_Math_Matrix4x4_InverseTransform` — inverse transform
- `FFX_Math_Matrix4x4Identity` — identity matrix
- `FFX_Math_Matrix4x4FromColumns` — build from 4 column vectors
- `FFX_Math_Matrix4x4TransformCopy` — transform + copy
- `FFX_Math_Matrix4x4CopyWithTranslation` — copy with translation override
- `FFX_Math_Matrix4x4TransposeAndCopy` — transpose + copy
- `FFX_Math_IdentityMatrix44` — identity
- `FFX_Math_UniformScaleMatrix44` — uniform scale matrix
- `FFX_Math_ScaleMatrix44FromVector` — non-uniform scale
- `FFX_Math_MultiplyMatrix44_structural` — multiply 4x4
- `FFX_Math_MatrixInverseProject` — inverse projection

**Compose variants (composition order matters):**
- `FFX_Math_ComposeMatrixZYX` — compose (Z×Y×X rotation order)
- `FFX_Math_ComposeMatrixRotateYXZ` — rotate YXZ
- `FFX_Math_ComposeMatrixRotateXZY` — rotate XZY
- `FFX_Math_ComposeMatrixTranslateZYX` — translate ZYX
- `FFX_Math_ComposeMatrixTranslateXYZ` — translate XYZ
- `FFX_Math_ComposeMatrixTranslateXZY` — translate XZY
- `FFX_Math_ComposeMatrixTranslateYZX` — translate YZX
- `FFX_Math_ComposeTransformFromGlobals_structural` — transform from globals
- `FFX_Math_ComposeTransformExtended_structural` — extended transform

**The 7+ compose variants** show that FFX uses multiple Euler angle conventions for different subsystems (camera, character, cutscene).

### Angle Utilities (20 functions)

- `FFX_Math_NormalizeAngle` — base normalize
- `FFX_Math_NormalizeAngleRad` — normalize to [-π, π]
- `FFX_Math_NormalizeAngleRad2` — variant 2
- `FFX_Math_NormalizeAngleRadOpt` — optimized variant
- `FFX_Math_NormalizeAngle_Pi` — normalize to [0, π]
- `FFX_Math_NormalizeAngleRadian` — normalize radian
- `FFX_Math_NormalizeAngleRadians` — normalize radians
- `FFX_Math_NormalizeAngleRadians_Dup` — duplicate
- `FFX_Math_NormalizeAngleDebug` — debug version
- `FFX_Math_NormalizeAngle2PI` — normalize to [0, 2π]
- `FFX_Math_NormalizeAngleDelta` — normalize delta
- `FFX_Math_NormalizeAngles4` — batch normalize 4 angles
- `FFX_Math_RadToDeg` — radians → degrees
- `FFX_Math_WrapAngleRad` — wrap angle
- `FFX_Math_AngleTo270Ref` — angle to 270 reference
- `FFX_Math_DirectionFromAngleNeg` — direction from neg angle
- `FFX_Math_Distance2DXZ` — 2D distance from angle
- `FFX_Math_PolarToDirection` — polar → direction
- `FFX_Math_ComputeFixedAngle_structural` — compute fixed angle

**The 10+ NormalizeAngle variants** exist because each subsystem defined its own — no shared math utility in the original PS2 codebase.

### Key Function: QuatSlerp (0x845310, ~120B)

```c
float* FFX_Math_QuatSlerp(float *q1, float *q2, float t, float *result) {
    // Compute dot product
    cosOmega = q1[0]*q2[0] + q1[1]*q2[1] + q1[2]*q2[2] + q1[3]*q2[3];
    
    // Handle negative dot — negate one quaternion for shortest arc
    if (cosOmega < 0.0) {
        cosOmega = -cosOmega;
        q2neg = (-q2[0], -q2[1], -q2[2], -q2[3]);
    } else {
        q2neg = q2;
    }
    
    // If nearly parallel, use linear interpolation (avoid div by 0)
    if (1.0 - cosOmega <= 0.0001) {
        // LERP: result = (1-t)*q1 + t*q2
        // ...
    } else {
        // SLERP: result = (sin((1-t)*ω)/sin ω)*q1 + (sin(t*ω)/sin ω)*q2
        omega = acos(cosOmega);
        invSin = 1.0 / sin(omega);
        k1 = sin((1-t) * omega) * invSin;
        k2 = sin(t * omega) * invSin;
        result = k1*q1 + k2*q2neg;
    }
    return result;
}
```

The slerp handles both LERP (for near-parallel quaternions) and SLERP (for general case). The threshold `0.0001` matches common game engine slerp implementations.

### Key Function: Init12StepSinCosTable (0x82e620, ~80B)

```c
void FFX_Math_Init12StepSinCosTable() {
    // Pre-compute 13 sin/cos pairs at 30° (π/6) intervals
    // π = 6.283184051513672 (τ = 2π, misnamed as "v0")
    // step = 12 divisions
    for (i = 0; i < 13; i++) {
        angle = 2*PI * (float)i / 12.0;
        sinTable[i] = sin(angle);
        cosTable[i] = cos(angle);
    }
}
```

**Key insight:** The constant `6.283184051513672` is NOT π — it's **τ (tau = 2π)**. The variable name `v0` in Hex-Rays hides this. The table is for **12-step (30°) rotations** — probably used for camera rotation or actor facing where precise angles aren't needed.

### Random Number Generation

```c
// Random float in [0, 1)
float FFX_Math_RandomFloat01() {
    return (float)rand() / RAND_MAX;
}

// Random jitter with scale
void FFX_Math_RandomJitterScale_structural(input, scale) {
    // Apply random perturbation within ±scale
    result = input + (RandomFloat01() * 2.0 - 1.0) * scale;
}
```

The random functions use C `rand()` (not a custom PRNG). This is MSVCR110's `rand()` — **not cryptographically secure**, and **not deterministic** across platforms. FFX likely used this only for visual effects (particle jitter, camera shake), not for battle RNG (which has its own seed in the battle system, as seen in batch_0012).

### Cubic Spline Interpolation

```c
// 1D cubic spline: eval at t
float FFX_Math_EvalCubicSpline(knots, coeffs, t);

// Compute coefficient matrix from knots
void FFX_Math_ComputeCubicSplineCoeffs(knots, coeffs);

// 3D cubic spline: eval position at t
void FFX_Math_EvalCubicSpline3D(knots, coeffs, t, result);

// 3D coefficient computation
void FFX_Math_ComputeCubicSplineCoeffs3D(knots, coeffs);
```

Used for **camera path interpolation** (cutscenes) and **actor movement** (field scripting). The 1D variant handles individual float parameters (e.g., zoom), while the 3D variant handles position paths.

### Clamp Variants

- `FFX_Math_ClampInt` — int clamp
- `FFX_Math_Clamp0to99` — clamp to [0, 99]
- `FFX_Math_ClampVec3Min` — vec3 minimum clamp
- `FFX_Math_ClampVec3Max` — vec3 maximum clamp
- `FFX_Math_Clamp0To200` (via Dbg) — clamp to [0, 200]

### Matrix Build from Axes (LookAt)

```c
void FFX_Math_BuildMatrixFromAxes(forward, up, right, result) {
    // Build orthonormal basis from 2 vectors
    // Standard look-at formulation
}

void FFX_Math_LookAtMatrix(position, target, up, result) {
    // Full look-at view matrix
}
```

These are **camera setup functions** — `BuildMatrixFromAxes` constructs a rotation matrix from 2 vectors (forward + up), while `LookAtMatrix` builds the full view matrix from position + target + up.

---

## Category Summary Table

| Category | Count | Address Range | Key Function |
|----------|-------|---------------|--------------|
| Vec4 | ~60 | 0x710f10-0x937610 | Vec4MulScalarScratch_6 |
| Vec3 | ~30 | 0x710f80-0x93d440 | Vec3Cross |
| Matrix4x4 | ~30 | 0x7c14d0-0x93d960 | Matrix4x4TripleMul |
| Angle utilities | ~20 | 0x7c0440-0x92de30 | NormalizeAngle variants |
| Float operations | ~15 | 0x74b700-0x839df0 | LerpFloatDamped |
| Spline/Cubic | 6 | 0x7e9d30-0x7ea1e0 | EvalCubicSpline3D |
| Vec2 | ~10 | 0x728ec0-0x7ea8e0 | Vec2Atan2 |
| Random | 3 | 0x72f500-0x7e6690 | RandomFloat01 |
| Quaternion | 2 | 0x845310-0x845450 | QuatSlerp |
| Projection | ~10 | 0x7ec8b0-0x93d960 | BuildProjectionMatrix |
| Misc | ~10 | 0x929910-0xa57000 | Pow2CeilExponent |

---

## Key Findings

1. **197 funções Math** — 11 categorias cobrindo vetor, matrix, quat, spline, ângulo, projeção, random.

2. **PS2 scratchpad relics** — as 15+ funções Vec4Scratch* são herança do PS2 EE scratchpad de 16KB. No PC são memcpy com wrapper.

3. **10+ variantes de NormalizeAngle** — cada subsistema implementou sua própria normalização. Falta de padronização na codebase PS2 original.

4. **7+ variantes de ComposeMatrix** — múltiplas convenções de Euler (ZYX, XYZ, YXZ, XZY, ZYX, etc). Cada subsistema escolheu uma diferente.

5. **QuatSlerp usa x87 80-bit** — `long double` para precisão extra em animações de câmera.

6. **SinCos table 12-step (30°)** — tabela pré-computada para rotações baratas de câmera/ator.

7. **rand() do MSVCRT** — `RandomFloat01` usa `rand()` do C padrão. Battle RNG tem seed própria (batch_0012), não depende disso.

8. **6+ variantes de Vec4MulScalar** — cada uma otimizada para um contexto de registro específico (compiler-generated code bloat do MSVC 2012).

9. **Vec4 é o tipo primário** — FFX usa Vec4 (XYZ+W) para quase tudo, não Vec3. W component é carregado mas frequentemente ignorado.

10. **Cubic spline 1D + 3D** — usado para caminhos de câmera em cutscenes e movimento de atores no field.

11. **Fixed16 conversion** — `Vec4FloatToInt16` / `Vec4Int16ToFloat` / `Float4ToFixed16` mostram que o renderer interno ainda usa fixed-point para algumas operações (herança PS2 que não requer precisão total).

12. **BuildProjectionMatrix** — construção manual de matrix de projeção perspectiva (fov, near/far, aspect). Não usa D3DXMatrixPerspectiveFovLH — FFX implementa própria.

13. **View matrix build** — `BuildViewMatrix` + `BuildMatrixFromAxes` implementam look-at manual sem D3DX ou PhyreEngine helper.

14. **x87 FPU vs SSE** — apesar do MSVC 2012 suportar SSE, as funções escalares (sqrt, sin, cos, acos) usam x87. Só funções bulk (Vec4Add4D) usariam SSE.

15. **InterpWaveform** — interpolação por waveform (provavelmente seno/cosseno para animações oscilantes como flutuação de ator ou pulse de luz).

---

## What's Next?

- **batch_0030**: Field Map loading (243 funcs) — the asset loading pipeline that uses these math functions

---

**Note:** 197 math functions is LARGE for in-house math lib. Most engines reuse a small set of templated functions. FFX's Math library suggests the PS2-era code was ported **without consolidation** — every subsystem kept its own math helpers, leading to massive duplication.
