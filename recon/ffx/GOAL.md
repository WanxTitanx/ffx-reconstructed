# FFX.exe reconstruction goal

## Active stage — readable, compiled C/C++ migration (2026-09-30)

The new objective is to replace instruction assembly progressively with readable
C/C++ that actually supplies the final executable's bytes. Follow
docs/superpowers/plans/2026-09-30-ffx-cpp-byte-identical.md. The historical mixed
reconstruction and modification milestones below remain established; they do
not mean the new migration is complete.

The initial control was rebuilt from public revision 0591e41b in an isolated
workspace. All three legacy C packages were freshly compiled with VS2012 x86
17.00.50727.1, their complete bodies verified, and the full vanilla executable
rebuilt with zero different bytes and the pinned SHA-256. The modification demo
was independently compiled twice and passed 101,400 native calls; the full
test suite passed 402 tests and 386 subtests. These are offline/native harness
checks, not gameplay. Receipts and initial metrics: recovered/control/.

The starting C contribution is 35,956 bytes, separate from 6,715,479 instruction
assembly bytes, 144 manual assembly bytes, 583,710 padding bytes and 48,775 data
bytes in .text. Credit comes from emitted provider intervals, not the match
catalog. Every promotion requires new compiler objects, full relocation and ABI
validation, complete-image equality, and a functional modification/disable cycle.
Failed or stale promoted providers must fail the build; no assembly fallback.
Intentional new behavior stays in the separate mods/ output with a different hash.

The first recovered provider, FFX_Math_Vec3Normalize at 0x0093D3D0, now contributes
102 newly compiled C bytes. Two fresh compiler runs and two full accepted vanilla
builds raise emitted C to 36,058 bytes and remove 46 assembly instruction records.
The PEs remain byte-identical. Native callee tests passed 331,776 comparisons,
including x87 modes and an intentionally failing control. Details and reproducible
commands are in recovered/README.md and recovered/HANDOFF.md. This is the first
promotion, not completion of the high-level source migration.

## Established mixed reconstruction and modification milestones

Primary goal: COMPLETE for the demonstrated source-modification workflow —
compile changed code/data into a standalone FFX.exe without runtime hooks.
Baseline milestone: COMPLETE for literal executable reconstruction, verified
2026-09-29. The mixed C/assembly/source-data build reproduces every original byte.
The separate mods/ workflow now provides the required implementation and proof.

## User clarification — modification is the primary outcome

The user's latest instruction accepts C, C++, assembly or a mixed reconstruction
method. Recovering every routine as high-level C/C++ is not a prerequisite.
Choose representations for dependable editing, rebuilding and testing of game
changes; preserve the exact existing executable and its acceptance evidence.

There are two separate acceptance cases:

1. With all modifications disabled, rebuild the original baseline and require
   complete literal equality, cmp success and the pinned SHA-256 below.
2. With a declared modification enabled, build a separate executable containing
   that change directly. Its bytes and hash may intentionally differ. Record the
   source changes, dependency/layout changes, expected binary differences and the
   new artifact hash. Do not weaken or repurpose the original-equality verifier to
   certify this different claim.

Operational completion requires a demonstrated source edit -> fresh changed
objects -> link -> behavior test cycle, including a change that needs additional
code/data space, correct symbol/relocation updates, and a disable/rebuild cycle
that returns to the exact baseline. The modified behavior must not require a
runtime injector, interception DLL, detour installer or trampoline patch of the
original routine. Ordinary statically linked calls and linker relocations are
part of the build and are not runtime hooks.

Historical gap confirmed at 85493c577: pe_link.link rejects any final hash other than
the original; text_build checks every chunk against original hashes; x86_source
requires retained instruction lengths. These are intentional baseline checks.
They do not establish support for edits, larger routines or changed layout.
Those gates remain intact. mod_compile/mod_objects/mod_layout/mod_link implement
the separate modification path; mod_acceptance independently verifies it.
High-level type/control-flow recovery should focus on the subsystems that need
editing; total assembly-to-C/C++ conversion is not the success metric.

Preserved baseline artifact: complete/FFX.exe. Historical evidence is retained
under complete/. Current clean baseline verification for the modification cycle
is mods/build/disabled/proof.json; its manifest and syscall audit are alongside it.
The full comparison covered 10,675,712 bytes,
found zero differences, verified all seven sections and 283,602 HIGHLOW sites,
and compared loaded images rebased to 0x10000000 and 0x50000000.

## Original-baseline acceptance

Rebuild the complete executable from reconstructed, inspectable source and
declared assets with a documented compiler/linker recipe. Compare the complete
result, not just individual functions, against the reference:

- File size: 10,675,712 bytes.
- SHA-256: 78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced.
- Architecture: PE32 x86. The observed source-matching compiler is VS2012
  17.00.50727.1; flags depend on the validated translation unit.

The final comparison must include code, data, resources, headers, imports,
padding, relocation tables and other linker-generated bytes. Copying the original
image, embedding original code blobs, or writing reference operands over compiler
output does not establish source reconstruction. Preserve any reconstructed
assembly as a distinct source category rather than claiming it is recovered C.

## Established work

The byteproof/ package contains reproducible C and assembly examples, a strict
candidate audit and regression tests for false acceptance. The c_leaf/ package
contains independently compiled C leaf reconstructions and records rejected
candidates. Their earlier reports identify isolated function bodies. The complete/
integration now combines them with c_reloc/, text_program/, pe_data/ and
pe_headers/ to rebuild the whole image and its actual symbol/relocation graph.

Use the JSON reports for counts and provenance. Multiple candidate objects,
compiler variants or repeated evidence must never count the same address twice.
Several original addresses may legitimately share one source implementation,
but all credited addresses still require complete byte comparisons.

## Resolved dependencies and representation

1. The 3,183 previously blocked C bodies now use real external C symbols and
   compiler-emitted COFF relocations. Their data/code dependencies are supplied
   by placed COFF definitions throughout the complete image.
2. The remaining native code is reconstructed as 2,142,911 explicit assembly
   instruction records, with symbols and real fixups. No original opcode-array
   fallback is accepted. Source types are checked against the native analysis map.
3. The complete builder integrates 5,894 C providers and one manual assembly
   provider, plus declared data/resources, exact padding and virtual zero storage.
   The C portion is 35,956 bytes; assembly represents the rest of the native code.
4. DOS/Rich/NT/section headers and all relocation blocks are rebuilt from fields.
   Imports, resource payloads and full section layout match the reference image.
5. Rebuilding the current prepared source uses no original executable input;
   a separate independent verifier reads it only after the candidate is linked.
   The bound source_only_audit records the exact syscall count and verifies no
   original-path or pre-existing-candidate opens during the traced build.
6. Final acceptance verifies the bound build audit and independently relinks all
   source objects in a fresh traced process. The complete input set, including the
   command launcher, and every manifest field must be reproduced exactly, as well
   as all 10,675,712 file bytes.
   An identical copy alone cannot receive a source-reconstruction proof.

High-level source refinement can continue where it enables practical editing.
Both acceptance cases above are now demonstrated. The comparison example adds
138 bytes of compiled code, 87 bytes of read-only data and a 136-byte writable
extent including zero storage, in three new PE sections. Seven authentic COFF
call references resolve to the new function. All 112 bytes of the old body remain
unchanged, with no trampoline. The original program entry point and imports remain.

The modified file has 10,677,248 bytes and SHA-256
f9adb847cebf552678e7b3283f7c3bff8a9e468140f7304e616b2195f5c319d4.
Its proof is mods/build/compare_demo/proof.json. Two fresh C compilations and
independent complete links reproduced every byte of the modification object, typed
LLVM IR, manifest and PE. Syscall audits bound 666 recorded inputs and fresh object/IR
creation and consumption. Compiler receipts include 15 ELF dependencies; 14 shared
libraries are proven read by both compiler invocations, and the kernel-loaded
interpreter is identified separately from the compiler ELF. Literal pointers into
the old image require symbolic bindings; ordinary integer constants remain valid.
The disabled build passed the original verifier and literal cmp.

The reproducible native harness passed 101,400 calls in images loaded at 0x400000,
0x10000000 and 0x50000000. It validates an actual relinked E8 operand, executes the
resolved callee, and checks comparison results, alignment, counters and ring data.
It does not execute the complete original caller or gameplay. Legacy C providers
are revalidated from their existing toolchain receipts; the modification object
is freshly compiled on both builds. See mods/README.md for the supported profile,
reproduction commands and explicit limits. Evidence snapshots are in mods/evidence/.

## Coordination

The peer's thread is codex://threads/01a0eba0-8b1f-7be0-bcec-2c2c7e0e58e0.
The shared project notice is recon/COORDINATION_COS_41719.md in the main checkout.
CoS work is isolated on cos/byteproof-41719. Main's independent work continues;
the existence of the notice is not evidence that the other agent has read it.

The persistent checkout is work/cos-byteproof-41719 inside the main project.
It incorporates main through c69ce8860. The completed integration passes 396
tests, including the new native modification harness. The earlier baseline
87,645-case native assembly result remains historical evidence. Full file identity, rather
than the earlier partial function counts, is the baseline acceptance measure.
Modification capability has separate acceptance requirements above.

This file records the goal and acceptance criteria in the repository. It does
not itself start an agent, enable a product mode, or schedule unattended execution.
