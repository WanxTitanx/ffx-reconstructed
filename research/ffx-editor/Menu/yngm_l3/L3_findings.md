# YNGM L3 — last residuals: evidence notes (2026-09-15)

Lane: FFX-STRUCTURES / YNGM-L3. IDA: idalib MCP @192.168.122.85:8745,
IDB `C:\IDA_DB\ffxoficial.exe.i64` (saved). Corpus: jppc map+btlmap, 262 ok
files / 295 sections.

## Item 1 — const68 (u16 @obj+0x28 / u32 @blob+0x16) — DEAD CONSTANT on PC

Writer: `FFX_RcBg_BuildVertexDeclFromMeshData@0x927BE0` emits BOTH copies as
literal 68: `*(u32*)(blob+0x16) = 68` (0x927cae) and `*(u16*)(obj+0x28) = 68`
(0x927d33). On-disk the prologue carries `44 00 00 00` at marker+8.

Reader enumeration (all functions that ever touch the blob or the param block):
- blob readers: draw-node builder `0x717700` reads blob+0x04 (hdrSize=32 →
  group list), +0x08 (ofsVerts → s16 pool), +0x10 (primTotal countdown) and
  group headers (+1 primType, +2 count) — NEVER +0x16.
  `FFX_RcBg_CalcBufferSize@0x928270` reads +0x0C,+0x14. `ForcePrimAlphaTo128@
  0x928460` reads +0x10 + group headers. `CalcElementOffsets@0x9282C0` reads
  group headers. `Dbg_LoadGuideRsdFromHost@0x938080` reads +0x08,+0x12
  (vertCount, to zero Y). insn_query op_any=22 (0x16) on the blob walkers: 0.
- param-block readers (a3 = obj+0x20): builder reads a3+0 (u32 28 → node+176),
  a3+0x18..0x1B (tint RGBA), a3+0x1B (alpha >>=1), a3+0x20 (matA ptr deref).
  insn_query op_any=40 (0x28) on 0x928020/0x91D880/0x938590/0x717700: 0 hits.
- Object-level: InitSceneObject memsets +0x20..0x8F; SerializeSceneBin fills
  +0x20..0x8F wholesale; nobody branches on or copies +0x28 out.

VERDICT: dead format constant on PC. Written unconditionally by the only
writer; zero readers in the complete consumer set. Likely a PS2-era tag of the
serialized-OMD pipeline (plausibly a decl/format id inside the 28-B param
packet — see item 2). Semantics not recoverable from this binary.

## Item 2 — u32 28 in the 20-B prologue — CONSUMED + size-packet semantics

`BuildVertexDeclFromMeshData` writes `*(u32*)(obj+0x20) = 28` (0x927d20)
followed by `obj+0x24 = sg_packet` (global), `+0x28 = u16 68`, `+0x2A = 0`,
`+0x2C/+0x30/+0x34 = 0`, `+0x38 = 0x80808080`, `+0x3C = 0`,
`+0x40 = &g_rcMatPers`, `+0x50 = &g_rcMatWorldView`, `+0x64 = 0`.

Consumer: `FFX_RcBg_BuildDrawNodeFromSceneBin@0x717700` (renamed; was
`FFX_AudioSdStream_IoCompletionThread_structural`) at 0x717be3:
`node+176 = *(u32*)a3` — the value 28 is copied verbatim into the PPP draw
node. Downstream node+176 reader lives in the Phyre submit path (not traced
further — out of YNGM scope).

Semantic bound: obj+0x24..0x3F = exactly 28 bytes. u32 28 = self-describing
length of the trailing "param packet" {sg_packet, u16 68, pad, tint RGBA} —
matches the L2 hypothesis "tamanho do preâmbulo" with sharper framing:
28 = sizeof the packet following the length field.

## Item 3 — Aux pool (auxCount×6 B after verts) — SEMANTICS BOUNDED

Writer mechanics (0x927BE0): `v10 = align16(6 * meshData[0x0C])`;
`Size = v7 + v9 + v10 + 32`; `blob+0x14 = meshData+0x0C` (auxCount);
`blob+0x0C = v20 + v7 + 32` — note blob+0x0C EXCLUDES the aux pool ⇒
**blob+0x0C is ofsAuxPool / end-of-main-data, not total blobSize**
(refinement over L2 label; identical when aux=0 ⇒ invisible in corpus).

`CalcBufferSize@0x928270` returns `blob[0x0C] + align16(6*auxCount)` — the aux
pool IS part of the serialized footprint (SaveGuideMap writes it out).

Producer side: `meshData+0x0C` = auxCount. Only two call sites on PC:
- `FieldDebug→FFX_RcBg_BuildGuideObjFromRsd@0x93A280` (renamed) hardcodes
  meshData+0x0C = 0 (0x93a3d0).
- `FFX_RcBg_BuildDeclFromMeshSubset@0x927FA0` maps its `a5` param to it —
  but has NO external callers (xrefs: self only). Dead wrapper on PC.

Reader side: NO function reads the aux pool or auxCount beyond size
accounting (CalcBufferSize). The draw-node builder indexes verts via
blob+0x08 only.

VERDICT: aux pool = second s16-XYZ vertex stream appended after the main pool
(aligned16), sized by auxCount, offset = blob+0x0C. Vestigial on PC: reserved
+ serialized but never consumed. Almost surely a parallel vertex-attribute
stream of the OMD pipeline (normals / secondary coords for prim types >0).
Guide corpus: aux=0 in 295/295 — field semantics PARTIAL (structure proven,
content semantics unobservable).

## Item 4 — AABB↔raw coords — RESOLVED

Code chain: `ComputeQuantScaleDiv4000@0x921410` (renamed; was
SceneProcessTick) = maxAbs(AABB)/4000 = ScaleDiv10.
`QuantizeVertPoolToS16@0x9281D0` (renamed; was BtlUI): s16 =
(int)(float_vert / ScaleDiv10) — TRUNC toward zero (Vec4FloatToInt4@0x808C70
does a C `(int)` cast). `SetScale10@0x928540`: mat4 diag = 10×ScaleDiv10.

⇒ **float_vert = s16 × (mat4diag/10)**; AABB = bounds of the PRE-quantization
float verts (ComputeAABB over the RSD float4 array), stored {x,0,z,1.0}.
The earlier `AABB == scale×bounds(s16)` test failed 0/295 because it used the
raw diag (missing the /10).

Measured (aabb_probe.py, 295 sections; step = diag/10):
- P2 single-section: |AABB − s16bounds×(diag/10)| < 1 quant step in 168/240
  and < 2 steps in 240/240; worst residual 0.0908 units (~0.95 steps);
  "pred inside AABB" (truncation signature) 181/240.
- P3 multi-section: vs UNION of per-section s16 bounds, residual ≤ 2.9 steps
  in 52/55 (worst 2.90; the 3 outliers are union-vs-own artifacts in 3+-
  section files) — consistent with SaveGuideMap@0x938590 unioning
  float-space X/Z across sections (y/w copied from section 0).
- P4: maxAbs(AABB)/4000 == diag/10 within 1e-4 for 233/240 single, 45/55
  multi (multi breaks exactly where union extended past own bounds);
  max err 0.0278.
- AABB.y = 0 in 295/295 (flat XZ plane; Y zeroed at load by 0x938080 anyway).

CONSUMER: `FFX_BuildGuideMeshDimensions@0x91D880` — w = max.x−min.x,
d = max.z−min.z, dim = max(w,d); center via `SceneAllocArray@0x9213D0`. This is
the minimap overlay sizing. The runtime AABB in the draw node is ALSO
recomputed from expanded verts (builder writes node+152..172), so the
serialized AABB feeds only the dimensions/center path.

## Item 5 — 7 short-meta sections (metaLen 260) — REVISION FINGERPRINT

Files (all single-section, all sec 0):
  btlmap: sins05_a (11 tris), test00_b (77)
  map:    bvyt07 (51), bvyt08 (51), bvyt14 (52), kami06 (110), mcfr10 (253)

Correlations:
- btlmap is NOT the discriminator: corpus has only 3 btlmap files with guides
  (lmyt01_a long + these 2) — small-sample artifact.
- THE fingerprint: `ps2MatPtrA` = 0x00290080 in EXACTLY the 6 files
  {sins05_a, bvyt07, bvyt08, bvyt14, kami06, mcfr10} — 6/6 sections with that
  ptr are short. test00_b = 0x00232B90 (an even older build). Current-revision
  files: 0x0029E800 (159 sections) and assorted others.
- Same-content control: bvyt06 vs bvyt07/08 — identical mesh (51 tris, 54
  verts, same AABB {0.347,−15}..{9.8,21.8}, same scale 0.0545) exported under
  BOTH revisions → metaLen carries zero content information.
- Structural diff (byte-level, bvyt06 vs bvyt07): identical fields, but the
  gap between meta head (+0x20) and AABBmin is 28 B not 44 B — i.e. the old
  revision's serialized param block was 0x60 (96 B) vs today's 0x70 (112 B).
  ⇒ `SaveGuideMap`'s `CalcBufferSize + 296` hardcode IS the current revision.

RUNTIME CONSEQUENCE (errata vs L2 "8 B into YNED, inofensivo"):
SerializeSceneBin reads fixed sizes: 0x70+0x20+0x10+0x40+0x40 = 288 B.
- Long (280+16... post-blob 296 B): lands exact, 8 B pad unread.
- Short (post-blob 280 B): every end-anchored field is read 16 B LATE:
  obj+0x90 "AABB" = {disk AABBmax, reserved-zeros} (verified all 7 files;
  test00_b's max slot even eats 'YNED' bytes → −1.998e18),
  obj+0xC0 scale diag[0] = 0 (all 7), obj+0x100 tail = 'YNED' garbage.
  Total overrun past rec_end = 8 B into YNED — that part of L2 was right,
  but "inofensivo" is wrong: AABB becomes degenerate (min=max_disk,
  max=0) → BuildGuideMeshDimensions yields NEGATIVE w/d and dim<0 for
  these 7 maps; scale=0 → GetScaleDiv10=0 → 1/0 downstream. Bounded note:
  these maps ship and run, so the corrupt serialized object is either masked
  by the ffxmap.id fallback mesh at draw time or produces a subtly wrong
  minimap — needs runtime test to fully qualify; the byte-level misread
  itself is proven.

## Bonus refinements discovered en route

- Alpha 0x80 is RUNTIME-FORCED: ForcePrimAlphaTo128@0x928460 writes byte 128
  at rec+3,+7,+11 (+15 if primType≥4) over whatever the file has. The on-disk
  alpha bytes are don't-care.
- The serialized-object path DOES dereference the stale mat pointers:
  builder `qmemcpy(node, *(a3+0x20), 0x40)` = obj+0x40 = ps2MatPtrA. On disk
  these are frozen PS2 EE addresses (0x0029xxxx). If DrawCharWithSound ever
  ran on a serialized YNGM object it would fault on PC — implying guide
  objects never reach that proc (guide feeds SetGuideMeshSource →
  BuildGuideMeshDimensions instead), or it's a latent crash. Nuance vs the
  L2 "inert" wording.
- ps2MatPtrA/B = adjacent PS2 globals, distance 0x4000 in the 0x290080
  cluster (A−B = 0x4000 there), 0x40 in others — they're two pointers into
  the PS2 matrix area, not necessarily 64 B apart.
- BuildDeclFromMeshSubset@0x927FA0 is DEAD on PC (no callers) — the generic
  multi-pool path is vestigial.
- Dbg_LoadGuideRsdFromHost zeroes vertex Y → flat guide even for authored 3-D
  source data.

## IDB changes (all saved via idb_save → C:\IDA_DB\ffxoficial.exe.i64)

Renames:
  0x717700 FFX_AudioSdStream_IoCompletionThread_structural → FFX_RcBg_BuildDrawNodeFromSceneBin
  0x710FB0 FFX_AudioSdStream_BgmCompletionHandler           → FFX_RcBg_BuildDrawNodeVfx
  0x93A280 FFX_FieldDebug_LoadTextFile                      → FFX_RcBg_BuildGuideObjFromRsd
  0x921410 FFX_Render_SceneProcessTick                      → FFX_RcBg_ComputeQuantScaleDiv4000
  0x9281D0 FFX_BtlUI_ConvertIconCoordsInt16                 → FFX_RcBg_QuantizeVertPoolToS16
  0x928460 FFX_RcBg_FillVertexBufferByte                    → FFX_RcBg_ForcePrimAlphaTo128

Comments set: 0x717700, 0x710FB0, 0x927BE0, 0x928270, 0x928460, 0x938590,
0x938080, 0x921410, 0x9281D0, 0x928540, 0x91D880, 0x9213D0, 0x92B2F0,
0x93A280.
