# CoS 41719 / Codex reconstruction coordination

Target: FFX.exe SHA-256
`78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced`.
Peer thread supplied by the user:
`codex://threads/01a0eba0-8b1f-7be0-bcec-2c2c7e0e58e0`.

## Claimed lane — 2026-09-29

CoS 41719 is working in `/tmp/ffx-byteproof-41719`, branch
`cos/byteproof-41719`, based on `fdf319a44`. Reserved work:
strict byte comparison, matcher regression tests, reproducible proof for
`Phyre_MemCmp_WithLength` at `0x617420`. Existing SDK sweeps and aggregate
coverage files remain owned by the Codex peer. No VM job directories are shared.

## Confirmed validation defect

`equal_modulo_relocations` in `tools/match/definitive_match.py` treats every
sliding four-byte window resembling an address as relocatable, without COFF
relocation evidence. It also recognizes E8/E9 inside instruction immediates.
These executed reproductions both returned `(True, 4)`:

```python
equal_modulo_relocations(bytes.fromhex("b8efbeaddec3"),
                        bytes.fromhex("b801004000c3"))
equal_modulo_relocations(bytes.fromhex("b8e8020000c3"),
                        bytes.fromhex("b8e8010000c3"))
```

These are different constants, not proven relocations. Existing masked matches
are discovery candidates until checked using exact bytes or actual relocations
and independently resolved symbol targets. The current 2,944-function aggregate
is therefore not a proof of exact linked bytes or a rebuilt executable.

The strict lane will preserve heuristic discovery as an explicitly named mode,
make exact comparison the acceptance default, and publish separate audit data
without silently rewriting the existing coverage. This file is a coordination
notice; receipt by the other agent has not yet been confirmed.

## Available checkpoint: 202aa3e4

CoS committed the strict verifier and proof package on cos/byteproof-41719:
202aa3e4, based on fdf319a44. No main source or aggregate has been overwritten.
The existing main masked-discovery reports still require independent validation.

Verified results available in the isolated worktree:

- Phyre_MemCmp_WithLength at 0x617420: 144/144 exact bytes from assembly source;
  zero COFF relocations; 87,645 native i386 semantic cases passed. Recovery of
  a C/C++ expression emitting the exact prologue remains open.
- FFX_memcmp at 0x401020: fresh VS2012 17.00.50727.1 compilation from C,
  112/112 exact bytes. A build-time manifest binds source/recipe/helper snapshots,
  compiler log and candidate image; current-source changes invalidate proof.
- Eight cached disassembly groups audited without masks: 695 unique bodies,
  49,771 bytes. Full audit with per-VA hashes is under recon/ffx/byteproof/audit.
- Separate C leaf lane currently reproduces 327 distinct C implementations at
  2,707 original function addresses, 16,306 bytes, with no COFF or original PE
  HIGHLOW relocations. Its final build-provenance hardening is in progress.

Important inventory defect: at 0x90e2e0 (698 bytes), the recorded hash is
e74647ae1dd8beacb12adcb1da9c259773ec730e513e28fcfc90c7ca0d5d44b2,
but the pinned executable gives
a0bcaf90a12a791b523f8314ca96bcf02e18137ed413bbca8c3e7495ca88b9bf.
The exact audit excludes this row from credit while retaining it as a uniqueness
competitor. Do not silently rewrite the reference hash to make a test pass.

The current leaf exclusions are meaningful: 3,183 bodies depend on original PE
base relocations, and three have different register allocation. None are credited.
These are function-body proofs and explicitly do not claim a complete FFX.exe.

## Final verified checkpoint for this lane — 2026-09-29

The temporary path and old commit identifiers above are historical. The worktree
is now /mnt/ssd-kingston/ffx-reconstructed/work/cos-byteproof-41719, branch
cos/byteproof-41719, rebased onto main at c69ce8860. Current local commits:

- 9869f793d: exact comparator, inventory validation and isolated build proofs.
- fb1c6613f: generated C, reproducible leaf build, provenance and duplicate guards.
- 57e8f8096: integration with the newer symbol tools; sibling import for symbol_bulk.
- b21c9ead7: persistent checkpoint and refreshed proof paths.

Fresh verification after moving the worktree: 97/97 tests passed; all C leaf
objects verified against the pinned original; both isolated proofs passed;
87,645 native i386 semantic cases passed. The final C leaf total is 329 distinct
implementations at 2,710 original addresses, 16,424 bytes. The two Vec4-scale
register differences and the array-sum difference are resolved in C and recompiled.
The only 3,183 excluded leaf targets are real unresolved PE relocation dependencies.

The four evidence groups (fresh leaf C, isolated C, isolated assembly, cached
disassembly) have 3,407 unique addresses and 66,451 bytes in total, with no overlap.
This is function-body coverage, not a rebuilt executable. The historical masked
catalog remains preserved, with its interpretation corrected in this branch's
recon/STATUS.md. The goal and remaining dependencies are in recon/ffx/GOAL.md.

Build manifests retain the exact source, jobs, recipe and helper snapshots;
current inputs, object files, compiler logs and inventory are checked before
acceptance. Changed inputs and duplicate or overlapping ranges fail closed.

No source changes or merges were applied to the peer's main checkout. This shared
file and the local branch are the handoff; receipt by the external Codex thread
has still not been acknowledged.

## Continued ownership — real relocations and PE integration

CoS has resumed work/cos-byteproof-41719 from b21c9ead7 at the user's request.
Reserved scope: the 3,183 relocation-dependent leaf candidates, their referenced
data symbols and transitive relocation dependencies, source-backed linking and PE
layout integration. Existing main SDK/pseudocode reconstruction remains available
for the Codex peer without overlapping writes. CoS will not regenerate the old
masked aggregate as acceptance evidence. Please report any overlapping active
work here; notification does not by itself imply the peer has read this file.

## COMPLETE — whole-image source build, 2026-09-29

The reserved integration work is complete on cos/byteproof-41719:

- 643b8f48c resolves all 3,183 previously blocked pointer-bearing C bodies.
- 1df8255e0b963ef25ab51a9c1fd59d979406f432 integrates the complete source-built PE.
- cff7115cd retains the final syscall trace, build/test logs and complete handoff.

Worktree: /mnt/ssd-kingston/ffx-reconstructed/work/cos-byteproof-41719
Artifact: recon/ffx/complete/FFX.exe inside that worktree.
File size: 10,675,712 bytes. SHA-256:
78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced.

Independent full-file comparison found zero different bytes. Seven sections,
twenty imported DLLs and 283,602 actual HIGHLOW sites match. Source snapshots,
real COFF definitions and relocation records are bound by retained receipts;
636 final build inputs are verified. Two rebased loaded images match all
37,212,160 mapped bytes, and 281 tooling tests plus 87,645 native routine cases
pass. Full rebuild under syscall tracing opened no original executable path.

The source is intentionally mixed C/assembly: 5,894 C providers plus one manual
assembly provider and 2,142,911 explicit x86 instruction records. This is full
literal executable reconstruction, not recovered original high-level C++.
The old functional scaffold/stubs do not supply any final code bytes. No code
blob fallback, mismatch patching or relocation masking is used by this build.

See complete/README.md, HANDOFF.md, proof.json, manifest.json and
source_only_audit.json for commands and evidence. No active write scope remains
for this lane. Main's later SDK/pseudocode work is preserved independently;
no main merge or source overwrite was performed. The external Codex thread's
acknowledgement of this notice has not been observed.

## Acceptance hardening — 85493c577

The final verifier previously proved byte equality but could issue a source-backed
claim for a forged manifest with an empty input list. Commit 85493c577 fixes that
gate on cos/byteproof-41719. It requires strict zero-mask/no-reference claims,
valid nonempty snapshots and a fresh traced linker replay whose complete manifest
and image must match the claimed result. The observed source-only audit is checked
and bound to the proof, including exact trusted execve argv, every input open and
output creation. Alternate launcher paths, hidden --link-only arguments, unrelated
traces, and reads of an already-existing candidate are rejected. The command
launcher is now an explicit source dependency rather than being lost under runpy.

Executed validation: 313 tooling tests passed; the actual forged-manifest
counterexample using a separate 10,675,712-byte copy is rejected. A fresh complete
build and the final acceptance replay both passed. The exact input closure is now
637 entries. Full build: 6,191 opens across 36 processes; replay: 3,561 opens.
Neither trace opens the original or an existing candidate to supply output bytes.
All file bytes remain identical and the SHA-256 remains
78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced.

Receipts, traces, test evidence, the new acceptance module and regressions are
committed. The representation remains mixed C/assembly; no claim of recovered
original C++ source or globally optimal compiler settings is implied. No peer-main
source files were overwritten or merged by this correction.

## User clarification — primary goal is direct executable modification

The latest instruction supersedes mandatory full assembly-to-C/C++ conversion.
The user accepts any dependable reconstruction method; the purpose is to edit
game behavior and build a new FFX.exe without runtime hooks. The exact executable
and its verified receipts are the unmodified baseline, not proof that this
broader editing workflow is complete.

Required separation: unmodified build must retain cmp/full-hash identity;
modified builds must use separate outputs, declared source changes, fresh changed
objects, audited linking and behavioral validation. Their hashes intentionally
differ when their bytes differ. Do not relax the baseline verifier or present a
modified artifact as identical to the original.

Before treating the project as modification-ready, demonstrate an edit and an
expanded code/data routine integrated directly through symbols and relocations,
without runtime injection/detours, plus a disabled-mod build returning to the
exact baseline. Current pe_link/text_build fixed hashes and x86 instruction-size
checks protect fidelity but do not provide that capability. Focus high-level
recovery where it enables the intended modifications, rather than converting all
assembly solely to increase a language-coverage count.

The preserved worktree's recon/ffx/GOAL.md records these acceptance requirements.
No new code ownership is claimed by this clarification, and no main source files
were changed. This shared note is a handoff, not evidence that the external Codex
thread has read it.

## Active standalone modification lane

CoS resumes cos/byteproof-41719 from 392f0150b. Reserved new files are
tools/match/mod_*.py, their tests, and recon/ffx/mods plus modification docs.
The baseline verifier and complete/FFX.exe remain intact. Scope is fresh compiled
modification objects, static symbol replacement, added code/data PE space, and
independent build/behavior acceptance. Main SDK/reconstruction work remains with
the Codex peer. This notice does not establish receipt by the external thread.

## Standalone modification checkpoint — def69026c

The implementation and fresh acceptance evidence are committed on
cos/byteproof-41719 at def69026c in the preserved worktree. Reserved mod_*.py
files are now tracked, including compiler, object/symbol linking, PE growth,
boundary admission, safe output, native execution and independent acceptance.
See recon/ffx/mods/README.md and mods/evidence/ for reproduction and exact receipts.

The fresh full acceptance command completed successfully: disabled baseline
reassembly and independent link passed whole-file cmp at the original SHA-256;
two fresh modification compilations/links reproduced the complete object,
manifest and PE. The example resolves seven original call operands to compiled
code, adds three PE sections, preserves the original 112-byte function body, and
has SHA-256 2e3ddab8356ee675d69b5638049f0c59b639bdb4193ac642ded8aac44286bc82.
The syscall audit binds 650 source inputs and fresh compiler creation/consumption.

374 tests and 101,400 native comparison calls passed across three load bases.
Native execution checks the callee selected by an authentic relinked call; it
does not run the whole original caller or gameplay. Legacy C providers retain
their verified toolchain receipts; no new legacy VM compilation was claimed.

The final independent source review is still in progress; any necessary fixes
will follow this checkpoint. Main source files and the peer lane remain untouched.
This shared notice is the handoff; acknowledgement by the Codex thread has not
been observed.

## Completed modification integration — 926971109

The follow-up is committed on cos/byteproof-41719 at 926971109, following
def69026c. The preserved worktree is clean. The bounded independent review is
recorded in recon/ffx/mods/evidence/review-worker1.json; subsequent parent fixes
and final integration results are recorded separately in review-parent.json.
All reported defects were addressed and validated.

Final acceptance command:
`recon/ffx/.venv-asm/bin/python tools/match/mod_acceptance.py --native-demo`
completed with exit 0 after the final source changes. The suite passed 396 tests.
Both independent modification builds produced literally identical COFF objects,
typed LLVM IR, full manifests and full PE files. The audit binds 666 inputs,
fresh compiler object/IR creation and consumption, and 15 ELF dependencies:
14 libraries read by both compiler invocations and a separately fingerprinted
kernel-loaded interpreter. No original executable was opened during either build.

The final modified executable has 10,677,248 bytes and SHA-256
f9adb847cebf552678e7b3283f7c3bff8a9e468140f7304e616b2195f5c319d4.
Seven original call operands resolve to the new compiled routine; the original
112-byte body stays unchanged. New section payloads contain 138 code bytes,
87 read-only bytes and a 136-byte writable extent. The corrected declared COFF
alignment explains the new candidate hash relative to the prior checkpoint.
The manifest accounts for 99 changed existing file positions and 1,536 appended
bytes. All 101,400 native checks passed across 0x00400000, 0x10000000 and 0x50000000.

The fresh disabled build and preserved complete/FFX.exe both passed literal cmp
against the original: 10,675,712 bytes, zero differences, SHA-256
78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced.

Hardening includes rejection of unrelocated compiled-provider branches, typed
literal-pointer admission, actual ELF compiler closure, deterministic compiler
IR emission, literal object/IR replay comparison, and correct COFF subsection
ordering/alignment. The actual source-only build rejected a literal old-image
pointer before publishing a PE or manifest. A genuine Clang/PE-linker probe
confirmed contiguous table offsets 0, 4 and 8 under declared four-byte alignment.

The demonstrated workflow is complete: source edit, fresh object/data, static
link, native behavior validation, and disable/rebuild to exact baseline. Native
tests execute the callee selected by an authentic call operand, not the entire
original caller or gameplay. Legacy C objects retain verified toolchain receipts;
no full legacy VM recompilation is claimed. Computed addresses, ABI and gameplay
effects require tests specific to each modification. Main source work remains
with the Codex peer; this notice does not establish external acknowledgement.
