# Standalone executable modification plan

Goal: build declared source changes directly into FFX.exe while preserving the
unmodified whole-file SHA-256 baseline. Mixed reconstructed C/assembly is allowed.
The specification is GOAL.md, especially its two separate acceptance cases.

Architecture: compile an explicitly declared, freestanding C/C++ translation unit
into fresh i386 COFF. Link its code and data into appended PE sections. Resolve
original call and pointer references through their actual COFF records and a
declared replacement symbol map. No injector, runtime patch, trampoline or binary
input supplies modified code. Existing baseline guards remain unchanged.

- [x] Compile immutable declared source/header snapshots; bind tool, recipe and object.
- [x] Validate replacement boundaries and explicit incoming references; reject unsupported
      short branches/interior entry points rather than silently leaving stale callers.
- [x] Extend PE headers and regenerate HIGHLOW from actual linked objects.
- [x] Execute changed code with added data, resolving a real relinked call operand.
- [x] Replay build independently; verify full differences, imports and rebasing.
- [x] Rebuild with modifications disabled and require literal baseline equality.
- [x] Review, commit and update the shared Codex coordination notice.

Files: mod_compile.py owns compiler/source receipts; mod_link.py owns static symbol
replacement and source-object integration; mod_layout.py owns PE growth; a separate
acceptance command owns independent rebuild, trace and behavioral evidence. Tests
must reject undeclared compiler inputs, stale objects, missing symbols, overlapping
replacements, out-of-range references and header/relocation capacity overflow.

Preserve recon/ffx/complete and the main checkout. New outputs use recon/ffx/mods.
Worker 1 reviewed reference hazards and implemented the pinned boundary loader.
Worker 2 implemented PE growth and produced the first native harness in /tmp.
The parent integrated that harness into the repository, added repeatable three-base
execution, and owns compilation, static linking, acceptance and output protection.

Validation: 396 tests passed; 101,400 native calls passed; baseline cmp exit 0;
full object, typed IR, manifest and image equal across independent modified builds. The native test
executes the callee selected by an authentic call operand, not full gameplay.

Final entry-guard correction: decoded branches inside a compiled provider must
retain their actual numeric target for admission checks. A source-style symbolic
description alone is not evidence of a COFF relocation. Six regression subcases
first reproduced silent acceptance of unrelocated near calls, short jumps and
far calls entering a replacement or its interior; the correction rejects all six.
Actual relocated calls still relink, unrelated destinations remain allowed, and
internal branches of preserved original bodies remain unchanged.

The final review findings are resolved: compiler ELF libraries are fingerprinted
and consumed by the traced compiler; typed IR rejects literal old-image pointers
without misclassifying scalar constants; COFF $ subsections use linker ordering
and their declared alignment. A genuine Clang/PE-linker comparison confirmed
contiguous four-byte table entries at offsets 0, 4 and 8. The real source-only
build rejected the absolute-pointer fixture before publishing a PE or manifest.
The kernel-loaded ELF interpreter is identified separately. Fixed compiler debug
directory options make the fresh IR deterministic without editing its output.
See mods/evidence/review-worker1.json for the bounded independent review and
review-parent.json for the subsequent integration, fixes and final validation.
