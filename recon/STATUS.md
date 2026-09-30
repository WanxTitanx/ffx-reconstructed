# FFX.exe byte-identical reconstruction — current status

## Target and verification basis

Target: `FFX.exe`, 10,675,712 bytes, SHA256 `78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced`.
Ground truth: `tools/match/inventory.tsv`, 66,557 IDA function entries / 6,518,294 code bytes.

The current manifest contains **19,593 unique addresses / 864,146 code bytes**. Of these, **16,148 carry strict byte proofs**: 7,395 `corpus-rel32-exact`, 5,419 `masked-rel32-exact`, 988 `dir32-rel32-exact`, 782 `phyre-rel32-exact`, 670 `lib-rel32-exact`, 382 `coff-rel32-exact`, 173 `sdk-pool-exact`, 106 `phyre-sdk-exact`, 75 `arch-ia32-exact`, 71 `retry-rel32-exact`, 61 `edx-rel32-exact`, 16 `complete-rel32-exact`, 5 `string-sym-exact`, 4 `flagmatrix-rel32-exact` and 1 `nearmiss-exact`. The remaining 3,445 entries still use the relocation-masked comparator and remain candidates. Every entry has the same size as its IDB function. The manifest is `recon/matched_functions.json`.

| Measure | Verified |
|---|---:|
| Unique functions | **19,593 / 66,557 (29.43%)** |
| Code bytes | **864,146 / 6,518,294 (13.26%)** |
| Strict resolved functions | **16,148 / 66,557 (24.26%)** |
| Strict resolved code bytes | **319,826 / 6,518,294 (4.90%)** |
| Strict library sections (code and data) | **891 sections** |

## String-symbol separator defect — 2026-09-30

`msvc_strings.address` matched the decoded literal without stripping the `@` that terminates the symbol name, so every reference whose literal had no `?$AA` marker looked for `"...@"` and failed. Of the 133 distinct string symbols referenced by the regenerated batch, only 48 resolved; stripping one trailing `@` raises it to 64. That closed five more functions, including `FFX_Abmap_SphereGridDebugDump` (1,891 bytes).

Along the way the 85 near-miss functions (1-4 bytes from the image) were recompiled under eight flag variants: only four closed, three of which were already strict, so one new function came from that. The near misses are register-allocation differences such as `mov eax,[eax]` against `mov eax,[ecx]`, not a flag recipe.

Receipt: `recon/string_sym_rel32_exact.json`.

## Corpus generator declaration-order defect — 2026-09-30

Only 422 of the 3,531 masked units with a recoverable source compiled. Diagnosing all 3,109 failures by first error code showed **2,816 were `C2061` on line 1** with a message like `syntax error : identifier 'DEAD___2_YAPAXIPAX_Z'`. The cause was in `gen_pseudocode_chunks.transform`: it prepended the per-unit `extern` declarations ahead of the shared prelude, so a declaration was the first line of the file while the `_DWORD` typedef it uses came 50 lines later.

`transform` now inserts the declarations after the last `typedef`/`#define` of the body. Recompiling the same 3,531 units raised the compiling count from **422 to 1,796 (4.3x)**. That did not translate into strict proofs: of the newly compiling units, 1,503 are size mismatches, 155 have unresolved relocations and 138 resolve but differ in the instruction stream — a concrete example, `0x4010b0`, emits `74 09` (`je +9`) where the image has `75 05` (`jne +5`), an inverted branch. So the defect was real and is fixed, but the remaining gap is code generation, as before.

## Full Phyre SDK pool sweep — 2026-09-30

All nine PhyreEngine pools (`phyre_ia32full_dis`, `phyre_ia32_dis`, `phyre_all_dis`, `phyre_g_dis`, `phyre_fi2_dis`, `phyre_fi3_dis`, `phyre_gs_dis`, `phyre_w_dis`, `phyre_z_dis`) were swept for unit blobs that occur literally in the image and fill exactly one inventory function. 1,187 such functions were found; 106 were not previously strict (**81 new addresses** that were absent from the manifest entirely, plus **25 that had been masked**), adding 1,649 bytes.

Receipt: `recon/phyre_sdk_rel32_exact.json`.

## `/arch:IA32` flag sweep — 2026-09-30

The earlier flag matrix omitted `/arch:IA32`, which this repository already documents as required for x87-heavy Phyre and Physics translation units. Adding it (plus `/O1` and `/Ob1` variants of it, and `/arch:SSE2` for contrast) over the same 3,531 masked units produced **75 new byte-exact functions** (2,256 bytes) — `Vector3_Normalize`, `Math_Sqrtf`, `PCamera_SetFieldX/Y/Z` and similar x87 users — against only 4 from the entire earlier six-variant matrix. `/arch:IA32` and `/O2 /Ob1 /arch:IA32` tie at 75; `/O1` adds none beyond those.

Receipt: `recon/arch_ia32_rel32_exact.json`.

## PhyreCore source build investigated — 2026-09-30

The SDK also ships the engine sources at `Core/` (1,033 `.cpp`) plus `Include/`, which had never been compiled. The official build settings were recovered from `Build/Props/PhyreCommon.props`: `MaxSpeed` (`/O2`), `IntrinsicFunctions` (`/Oi`), `WholeProgramOptimization=false` (`/GL-`), `MultiThreadedDLL` (`/MD`), `FunctionLevelLinking` (`/Gy`), `RuntimeTypeInfo=false` (`/GR-`), with `/GS-` and `/DNDEBUG` for release.

A sample of the tree was compiled against those flags. It does not build: the include chain reaches third-party SDKs that the leaked package does not contain — `Cg/cgGL.h` and `Cg/cg.h` (NVIDIA Cg), `fmod.hpp` (FMOD Studio), `d3dx11.h` (DirectX Effects) and `iggy.h` (Scaleform). Those are exactly the dependencies the STATUS already lists as missing.

This closes the last unexplored source front. Every path that could have produced ready-made source — the shipped libraries in all toolchain and architecture variants, the Bullet source, the Lua source, and now `Core/` — has been checked, and the concrete blocker is identified for each.

## Independent re-verification — 2026-09-30

The acceptance pipeline was run again on the current source and passed end to end: the disabled baseline reassembles to **10,675,712 bytes, `cmp` identical** to the reference, SHA-256 `78ce3439...b5ced`; the modification build was replayed in an empty directory with the whole manifest, object, IR and PE equal between the two builds; and the native harness executed 101,400 calls across three load bases. The modified executable is `f9adb847...c319d4`. This is the same result the earlier turn reported, re-established on the current tree rather than carried forward.

A manifest integrity audit also passed: all 19,510 entries exist in `inventory.tsv` with the **same name and size**, and every one has readable reference bytes at its declared VA.

Two further coverage rules were tested and produced nothing: no masked entry shares a VA with a proven interval, and none lies wholly inside a strictly larger proven span. The section-coverage rule only ever applied to the 32 `lua-src` entries already promoted.

## Lua source build and section-coverage proofs — 2026-09-30

The SDK ships the Lua **source** at `External/lua` (Lua 5.2, 34 units). All 34 compiled on the VM with `/O2 /Oi /MD`. Measured against the shipped `lua.lib`, only **2 of 821** compiled function blobs match a blob in the library — the same "binary is not this source" result as Bullet, so the source build adds nothing directly.

It did expose a real gap in the strict library check, though. A verified section proves every inventory function that **starts at its VA and is no longer than it**, because those bytes are a prefix of bytes already proved equal. The check required an exact size match, so a function one byte shorter than its verified section was rejected. Applying coverage instead promotes **32 `lua-src` functions** (3,266 bytes) whose VA had already been proved but whose sizes differed by a few bytes.

Receipt: `recon/lib_rel32_exact.json` (now records `section_size` and the coverage rule).

## Bullet source build from the SDK — 2026-09-30

The SDK also ships the Bullet **source** at `External/Bullet` (v2.77, 156 `.cpp`), separate from the prebuilt `.lib`. The project files there gave the original flags (`/O2 /Ob1-2 /Oi /GS- /MD /arch:SSE2 /GL-`), so `LinearMath` was rebuilt from that source on the VM: all five translation units compiled, and the objects do contain the Bullet symbols (`?btAlignedAllocDefault@@YAPAXIH@Z`, `?btAlignedFreeInternal@@YAXPAX@Z`, the `btVector3` constructors).

None of the 87 functions in those objects occurs literally in the image. The allocator entry points are six-byte `jmp dword ptr [__imp__...]` import thunks, and the rest are inlined by the linker, so a source build cannot be matched against the linked image without also reproducing the inlining decisions. This is the same conclusion the masked-library lane reached from the other direction: the shipped binary is a different build than the shipped source.

## SDK library variants exhausted — 2026-09-30

The PhyreEngine SDK ships 208 `.lib` files across `Win32/{vs2012,vs2013,vs2015,vs2017}` and `Win64`, and only the vs2012 Win32 set had been swept. The other Win32 variants were checked: vs2013 proves 336 sections, vs2015 148 and vs2017 141, but the **union across all four is still exactly 891 sections and 779 whole functions** — the newer toolchains add no function the vs2012 build does not already prove. Each variant alone found only 3-7 masked candidates. `Win64` is AMD64 (machine `0x8664`) and cannot match the x86 image at all.

That closes the library front: the remaining 688 masked `lib:*` entries are not recoverable from any shipped binary of the SDK.

## Receipt audit — 2026-09-30

Every claim in the manifest was re-checked against the reference PE and against the receipt that backs it. Each of the ten `*rel32_exact.json` receipts plus the three `callconv_*` receipts was read back and every entry re-hashed: **zero hash mismatches**, and **every one of the 15,929 strict entries is covered by a receipt**. The earlier gap of 380 entries was a hole in the audit script, which looked only at `*rel32_exact.json` while the call-convention lane stores its proofs in `callconv_*.json`; adding those closed it. Two receipt entries point outside the inventory (they are section-level, not function-level) and are not counted as functions.

This matters because the library lane had already been found to claim 210 entries that a fresh run could not reproduce. The audit is the check that the same defect is not hiding in another lane; it is not.

## Library lane rebuilt on a single deterministic run — 2026-09-30

The library receipt had accumulated by merging the output of runs made with different verifier versions, and re-running the committed verifier reproduced only 477 of the 687 entries it claimed. That is an accounting defect rather than a verification result, so the lane was rebuilt from one run and its receipt now records `reproducible: true`.

Two defects were found and fixed while doing it. A relocation patches a **four-byte field**, but the earlier wildcard matcher treated only the first byte as unknown, so correctly locatable sections were rejected. And `?btAlignedFreeInternal` / `?btAlignedAllocInternal` are not where the Bullet allocator bodies come from: they were **undefined references** inside the object that defines the function, so looking up their VA was the wrong question.

With both fixed, one deterministic run proves 891 sections, of which 779 are whole inventory functions. That is 110 promoted and 159 demoted against the previous manifest, so the honest count went **down** while the evidence got stronger. The wildcard placement is well behaved on its own terms: measured against the relocation-free-only baseline it adds 749 provable sections and loses none.

## Compiler-flag matrix — 2026-09-30

Every masked entry with a recoverable source (3,531 units) was recompiled under six optimisation variants (`/O1 /Oi`, `/O2 /Ob1 /Oi`, `/O2 /Oi-`, `/O2 /Os /Oi`, `/O2 /GS`, `/O2 /Oi`) — 21,186 compilations, 10,776 objects. Exactly **four** functions became byte-exact (`0x4d1df0`, `0x4d1e20`, `0x4d1e90`, `0x60bb10`, all `Phyre_Loose_*`, under `/O1` or `/O2 /Os`). The remaining candidates are not a flag-recipe problem: the same 9,081 produced a size mismatch and 778 resolved but differed in the instruction stream.

Receipt: `recon/flagmatrix_rel32_exact.json`.

## Remaining candidates — measured 2026-09-30

The 3,532 masked entries are dominated by real code-generation differences, not by unresolved references. Re-compiling every candidate that has a recoverable source (3,531 units, the only masked entry without any pool source is one `pseudocode-corpus` body) with the current generator produced 422 objects and **zero** additional byte-exact matches; the rest split into 266 same-size/different-bytes, 94 unresolved-relocation and 62 size mismatches.

The same split holds for the entries whose relocations already resolve: of 197 such cases, 194 differ from the image inside the instruction stream, not at a patch site. The differences are register allocation, `mov` versus `fld`, `or` versus `and`, and similar scheduling choices that a source rewrite has to close one function at a time. No shared systematic cause remains to exploit.

## Full disassembly-pool sweep — 2026-09-30

The single-unit Phyre check was generalized: every compiled-object disassembly pool under `tools/match` was swept, and a blob that occurs literally in the image and fills exactly one inventory function of the same size counts as a byte-for-byte proof. That found 1,636 functions in total, 173 of which were not previously strict. Receipt: `recon/sdk_pools_rel32_exact.json`.

The limits of this criterion matter: it needs the blob to appear verbatim, so a unit whose relocations the linker patched is invisible to it, and it proves the bytes rather than the source. The pools that contributed most are `fresh_dis` (462), `phyre_all_dis` (452) and `bullet_all_dis` (150).

## PhyreEngine SDK source verification — 2026-09-30

The `phyre_*_dis` pools are disassemblies of units compiled from the shipped PhyreEngine 3.21 sources under several flag variants. Locating each unit's `.text` blob literally in the image and requiring the containing inventory function to have exactly that size proved 782 more functions (54,733 bytes). The unit-to-account mapping is `recon/phyre_rel32_exact.json`.

## MSVC string-literal resolution — 2026-09-30

Most 6-byte functions are `mov eax, offset <literal>`, so their only relocation is a `DIR32` against a string. Resolving those exposed two defects: the relocation parser returned the `(`string')` annotation instead of the symbol name, and the `??_C@` grammar was wrong for literals whose size and hash share one prefix segment. `tools/match/msvc_strings.py` now implements the documented scheme (`?$XY` is one byte, `?5` is a space, `?$AA` ends the literal) and reports an address only when the decoded bytes occur exactly once in the image. This promoted 632 functions to strict proofs. Note that `?5` is a space; `%` is `?$CF`, which the earlier table had wrong.

## Strict corpus promotion — 2026-09-30

All 21,962 fresh corpus units were recompiled with VS2012 17.00.50727.1, and every COFF `.text` `REL32` field was resolved against `tools/match/inventory.tsv` before comparison. 7,397 units then matched the PE byte-for-byte at their declared IDB address (109,576 bytes; 5,162 candidate relocations, with 1,956 functions carrying at least one). Each promoted entry's bytes were re-hashed directly from the reference PE and agreed with the verifier output.

Receipt: `recon/corpus_rel32_exact.json`; sources: `recon/ffx/corpus/sources.tar.gz`; verifier: `tools/match/strict_rel32_verify.py`.

## Relocation-masked promotion — 2026-09-30

Every entry that was still relocation-masked but had a recompilable source was rebuilt with VS2012 17.00.50727.1 and re-verified with the same REL32-resolving comparator. 11,370 units were recompiled (9,379 built; the remainder are raw Hex-Rays pools that still need generator repair) and **5,419 functions moved to strict equality** (49,352 bytes), with zero hash disagreement against the reference PE.

Receipt: `recon/masked_rel32_exact.json`; sources: `recon/ffx/corpus/sources_masked.tar.gz`.

## Generator typedef repair — 2026-09-30

1,991 units failed to compile because Hex-Rays signatures referenced opaque types the emitted unit never declared (`lua_State`, `LARGE_INTEGER`, `HMODULE`, `HRESULT`, `SIZE_T`, `__m128`, and similar). The generator prelude now defines them, and the missing declarations were injected into the affected units. 339 units compiled; 71 then matched the reference PE byte-for-byte with REL32 resolution.

Receipt: `recon/retry_rel32_exact.json`.

## Callee-cleanup signature repair — 2026-09-30

449 units compiled a body identical to the PE except for the epilogue `ret imm16`: the reference clears more argument bytes than the emitted C signature implied, because a `__thiscall`/fastcall callee's cleanup was not represented. Dummy EDX/stack parameters were inserted to match the observed cleanup, the units were recompiled, and 61 then matched byte-for-byte with REL32 resolution.

Receipt: `recon/edx_rel32_exact.json`; sources: `recon/ffx/corpus/sources_edx.tar.gz`.

## DIR32 data-pointer resolution — 2026-09-30

1,172 masked functions were previously rejected because their COFF objects carry `DIR32` relocations against data symbols, not code. The IDA name map records the VA of each named data item, so a `DIR32` whose symbol has exactly one name-mapped VA is resolved directly. 359 functions resolved this way and 343 then matched the reference PE byte-for-byte.

Receipt: `recon/dir32_rel32_exact.json`.

## Raw-layout generator support — 2026-09-30

The corpus generator only scanned `pseudocode/*/*.c` and required a `// Address:` marker, so the raw bodies under `pseudocode/complete/<range>/` were never emitted. `own_name()` now recovers the defined symbol from the body itself (needed because those bodies carry no marker), which also stops the unit from declaring itself `extern`. 1,455 such units were generated and compiled; 16 matched byte-for-byte.

Receipt: `recon/complete_rel32_exact.json`.

## SDK static-library strict verification — 2026-09-30

The `lib:*` manifest entries came from a masked library sweep. `tools/match/strict_lib_verify.py` places each `.lib` member's `.text` in the PE by a relocation-free anchor, resolves every COFF `REL32`/`DIR32` through the object's own symbol table, and requires literal equality. 524 sections matched across BulletCollision, BulletDynamics, LinearMath, lua, SceHeatWave and RecastNavigation; 436 of them are whole inventory functions and now carry strict proofs.

Receipt: `recon/lib_rel32_exact.json`.

Two verifier defects were fixed after the first library pass. COFF relocation symbol indices are raw symbol-table slots, so auxiliary records must be kept in place rather than skipped. Section-relative symbols (local labels such as `$LN5`, and `.rdata` constants such as `__real@3f800000` and `__xmm@...`) now resolve against the VA where the object's own section was placed. Cross-member and cross-archive resolution were also added: every placed object publishes the VAs of the symbols it defines, the object's own library is consulted before the global map (release and debug archives define the same names), and the IDA name map fills the remaining gaps. Together these lifted the verified section count from 524 to 2,165, of which 681 are whole inventory functions.

Anchoring was also made practical: a 16-byte window index over the image (stride 4, since entry points are aligned) replaces per-candidate image scans, and every anchor is confirmed over the full window before it is accepted, so a short accidental match cannot misplace a section.

A second anchoring pass places the sections that have no relocation-free window at all, which is the normal shape of a COMDAT inline body: once enough of the library is placed, the symbols the section references are known, so the section is patched and matched literally. This added 1,317 placed sections and, after re-validating every library run against the reference PE, 803 whole inventory functions now carry library proofs; 835 sections in total, including data, are verified byte-for-byte.

## Full-image build milestone — 2026-09-29

`recon/ffx/complete/FFX.exe` is a literal rebuild of the 10,675,712-byte
reference executable, SHA-256
`78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced`.
The committed proof records all bytes compared with zero differences, 637
verified source/build inputs, a source-backed link, zero raw-code-blob fallbacks
and zero masked bytes. A local audit independently confirmed the artifact hash
and byte-for-byte equality with the reference.

The image is built from 5,894 C providers, explicit symbolic assembly and
declared data/assets, including 2,142,911 assembly instruction records. This
reconstructs the complete executable exactly; it does not recover the original
high-level C++ source. The hook-free compile/relink workflow and demonstration
package are in `recon/ffx/mods/`.

## Evidence source breakdown

Counts below are deduplicated by IDB address and sum to the manifest totals.

| Evidence source | Functions | Bytes |
|---|---:|---:|
| SDK static libraries | 1,160 | 400,833 |
| Hex-Rays corpus, matched at declared address | 14,386 | 208,631 |
| Phyre SDK source and compile variants | 1,349 | 114,043 |
| COFF object dumps, COFF-aware function splitting | 572 | 68,255 |
| Lua SDK source | 403 | 36,009 |
| Strict per-function Hex-Rays pseudocode candidates | 135 | 6,305 |
| Exact mangled-symbol attribution | 749 | 4,555 |
| Other SDK source | 8 | 330 |
| Lua `/GS` variant | 1 | 146 |
| FFX source | 1 | 112 |
| Strict COFF REL32 call-convention recovery | 382 | 4,158 |

## Verified toolchain findings

- Toolchain: VS2012 Express 17.00.50727.1 on Windows 11 VM `windows11-dev-next`.
- Proven function compile flags include `/nologo /c /GS- /O2 /MD /Oy- /Oi`; `/arch:IA32` is necessary for x87-heavy Phyre functions.
- `/Oi` reproduces the MSVC memcmp intrinsic expansion. For affected code, `/GL` + `/LTCG` changes code generation; the full Phyre link graph still does not make that variant match more broadly.
- The verifier is `tools/match/definitive_match.py`. For COFF objects with multiple functions/internal labels, use `tools/match/definitive_match3.py`: function boundaries are where instruction offsets restart at 0; internal labels such as `$LN35` do not start functions.
- For Hex-Rays objects with a known `// Address: 0x...`, `tools/match/corpus_va_verify2.py` merges dumpbin internal labels and wrapped instruction bytes, then compares at the declared address.

## Strict COFF REL32 recovery

The recovered unit branches contained single-argument calls to IDA-typed `__thiscall`/`__fastcall` callees. The old emitted C declared them as cdecl, adding stack pushes and changing code bytes. The exporter and unit rewriter now preserve the ECX calling convention for that case.

Pass A rewrote 5,051 recovered units; 1,356 compiled. Address-and-size matching with relocation masks produced 511 variants at 379 addresses. The strict verifier resolved 528 COFF `.text` `REL32` fields across those variants; 510 object variants then matched every byte, representing 378 unique functions (3,543 bytes). One same-size variant failed after fixups and was rejected.

Pass B started from 697 same-size byte mismatches. Correcting 18 single-argument calling-convention declarations and recompiling with the original /O2 flags produced two more strict exact functions (202 bytes).

Pass C recompiled the same 697 sources under /O2 /Ob1 /Oi and /O2 /Oi-. Both variants reproduced the two Pass B functions and found two additional strict exact functions (413 bytes).

Across the three passes, 382 unique functions (4,158 bytes) now have full byte-equality proofs. The 18,764 earlier matches remain relocation-masked until individually resolved.

Sources: `recon/recovered_callconv_sources/`. Calling-convention map: `recon/callconv_function_conventions.json`. Full per-function proofs: `recon/callconv_recovered_exact.json` and `recon/callconv_o2_exact.json`. Verifier: `tools/match/strict_rel32_verify.py`.

This strict subset does not change the proof limits of the earlier 18,764 relocation-masked entries; those remain candidates under the prior matcher until their relocations are resolved independently.

## Decompilation coverage

The imported `pseudocode/` tree contains 19,064 files: 8,813 non-placeholder files and 10,251 `NOT EXTRACTED` placeholders. I added `tools/match/decompile_missing.py` and a restartable worker, `tools/match/decompile_remaining_worker.py`, using IDA 9.2 idalib / Hex-Rays from Python 3.11 on the VM.

The first pass produced 25,759 files. A recovery pass over the remaining addresses produced **40,749 additional decompilations**. It restarted idalib after native Hex-Rays exceptions; 17 addresses caused access violations and were skipped. After recovery, only **49 of 66,557** inventory addresses had no output: those 17 exception addresses and 32 addresses for which Hex-Rays returned no function body.

Of the 40,749 additional units, 21,962 compiled with the current transformation. Address verification found:

| Result | Units |
|---|---:|
| Exact bytes at declared address | 8,709 |
| Already covered by a prior source | 1,328 |
| New exact address at that time | 7,381 |
| Compiled size differed from IDB size | 12,556 |
| Same size, different bytes | 697 |
| No object produced | 18,787 |

These outcomes are from the fresh-decompilation batch and use address attribution, not size-based guessing.

## Corpus transformation

`tools/match/gen_pseudocode_chunks.py` plus `tools/match/analyze_globals.py` repairs Hex-Rays output for VS2012: IDA types and helper macros, `__usercall` annotations, vftable/array markers, truncated-body markers, missing callee declarations, and evidence-based data-global types.

The generator compile rate rose from **5,492/8,769 (62.6%)** to **6,607/8,769 (75.4%)** on the measured VM runs. A 204-file stratified sample increased from 129 to 152 compiling files. Compile rate alone does not prove parity; only the byte verifier contributes matches.

## Remaining scope and known limits

The manifest currently leaves **47,413 functions / 5,675,330 code bytes** unmatched. These family buckets use the current IDB name with direct FFX_ and Phyre_ prefix matching:

| Unmatched family | Functions | Bytes |
|---|---:|---:|
| FFX-native (`FFX_*`) | 17,567 | 3,152,714 |
| Phyre (`Phyre_*`) | 14,194 | 1,264,023 |
| Other named / unnamed families | 15,652 | 1,258,593 |

Some code is not available in the supplied SDK: FMOD Studio, Havok, Scaleform and DirectX Effects dependencies are missing. Several candidate libraries were verified absent or unrelated to the target (including expat). Upstream libwebm does not contain the binary's parser symbols; the MKV parser is a private fork.

The objective is **not complete**. Continue recovering source/decompilation and validating candidates against original addresses. Never promote an ambiguous byte match to a verified function without additional address or symbol evidence.
