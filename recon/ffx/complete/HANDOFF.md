# Final handoff — complete literal FFX.exe reconstruction

Initial complete-image implementation: 1df8255e0b963ef25ab51a9c1fd59d979406f432.
Prior relocation milestone: 643b8f48c.
Branch: cos/byteproof-41719. Main integration base remains c69ce8860;
the external Codex peer's later main work was not overwritten or merged.

Target and candidate both have 10,675,712 bytes and SHA-256
78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced.

The binary is at recon/ffx/complete/FFX.exe in this worktree. The complete
source, supporting tools, receipts and final proof are committed. Binary caches
remain local and can be rebuilt with the recipes documented in README.md.

## Evidence

- proof.json: literal comparison of all file bytes, zero differences; seven PE
  sections, twenty import DLLs, 283,602 actual HIGHLOW sites and the full checked input set.
- Loaded-image comparisons at 0x10000000 and 0x50000000 match 37,212,160 mapped
  bytes at each base. These simulate loader mapping/relocation, not gameplay.
- tests.log: 313 passing regression tests. Native MCWL semantic build: 87,645 cases.
- source_only_audit.json and build.trace.gz: traced full native code/data rebuild,
  including child processes; open counts are recomputed and bound to proof.json.
- manifest.json: exact source snapshots, real placed symbols and COFF relocations,
  per-section hashes, build/tool identities and the complete emitted image hash.

## Representation

This is mixed reconstructed C and explicit symbolic assembly, with declared
data/resources. It is not a claim to have recovered the original high-level C++
project. The final image uses 5,894 C providers, one manual assembly provider,
and 2,142,911 explicit instruction records. Source assembly retains encoding
choices and symbolic operands, not raw native instruction byte arrays.

All 3,183 formerly blocked C bodies are integrated with actual symbols and
compiler-emitted COFF fixups. Declared data owns every file-backed byte and BSS
tail. The complete PE is built anew; the reference is not patched or reused as
the output container. Stub code in the older functional scaffold is not linked.

## Review findings resolved

The encoder rejects malformed operand ownership and silent immediate narrowing.
MCWL compilation uses immutable source snapshots and a build receipt. Text record
kinds are validated against the native analysis map and reviewed exceptions, so
instruction ranges cannot be relabeled as data blobs. Every BSS tail has an exact
source partition. The final relocation table must equal the actual COFF write-site
union. Original-read absence is supported by syscall evidence, not by claiming
the Python wrapper is an operating-system sandbox.

The later P1 acceptance finding is addressed by complete_acceptance.py. The gate
rejects empty inputs, duplicate paths, redirected snapshots, reference-file inputs,
nonzero masks/code blobs and a manifest permitting reference reads. It validates
the retained source-only audit and performs a fresh traced linker replay in a
separate process. The complete generated manifest must equal the claimed one;
this derives the expected source closure instead of trusting an input count.
The replay's image, receipt, trace and log hashes are bound into proof.json.
Regression tests include the original equal-file/forged-manifest counterexample.
Both traces must show the recorded execve, successful opens of every input and
creation of the output image/manifest. Unrelated clean traces are rejected.
The complete runtime argv must match the trusted interpreter, scripts, source
root and output directory. Prefix matches, alternate scripts with the same
basenames, hidden --link-only arguments and reads of a pre-existing candidate
are rejected. Freshly emitted .tmp files remain allowed.
run_source_only.py is explicitly included in the linker's source input closure;
runpy's replacement of __main__ cannot hide this executable dependency.

The shared peer notice is recon/COORDINATION_COS_41719.md in the main checkout,
for codex://threads/01a0eba0-8b1f-7be0-bcec-2c2c7e0e58e0. This notice and the
local commits are the handoff; no read acknowledgement from that external thread
has been observed. High-level C++ refinement can continue independently of the
now-satisfied byte-identical executable goal.
