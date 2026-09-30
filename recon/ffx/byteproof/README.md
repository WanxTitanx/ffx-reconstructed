# FFX reconstruction: exact-byte evidence

Reference executable: 10,675,712 bytes, SHA-256
78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced.
The original executable is verification input, never generated output.

## Verified implementations

| Original address | Function | Source | Exact bytes |
| --- | --- | --- | ---: |
| 0x401020 | FFX_memcmp | ../ffx_memcmp.c, VS2012 x86 | 112 |
| 0x617420 | Phyre_MemCmp_WithLength | ../phyre_memcmp_with_length.S, GNU assembler | 144 |

Both bodies match every byte, including instruction encodings and padding.
The assembly function also packages as an i386 COFF object with zero relocations.
Its 87,645 native i386 test cases cover unsigned keys/lengths, zero length,
payload alignment, every mismatch position through 64 bytes, comparison direction,
and randomized input. No reference bytes are embedded to generate these functions.

The assembly source is an instruction reconstruction. It does not close recovery
of a C/C++ expression that makes MSVC emit the Phyre_MemCmp_WithLength prologue.
The C memcmp image is a code-generation fixture, not a runnable game executable.

## Reproduce

From the worktree root, on Linux with GNU binutils and GCC supporting i386:

~~~sh
python3 -m unittest discover -s tools/match -p 'test_*.py' -v
python3 tools/match/verify_mcwl.py
~~~

The C memcmp recipe uses VS2012 Express 17.00.50727.1, with compilation options
/GS- /O2 /MD /Oy- /Oi /GL, followed by /LTCG. Stage ffx_memcmp.c, build_memcmp.bat
and build_memcmp.py together in an independent Windows folder. The helper needs
Python on that host. With the repository layout preserved, the defaults resolve
../ffx_memcmp.c and build_c automatically. The explicit session staging command was:

~~~bat
C:\IDA_DB\cos41719\build_memcmp.bat --source C:\IDA_DB\cos41719\ffx_memcmp.c --output-dir C:\IDA_DB\cos41719\build_c
~~~

Retrieve the generated image, build.log, build-manifest.json and inputs/ snapshots
together. The helper snapshots input files, compiles the snapshot, captures logs,
rejects inputs changed during the build, and publishes the success manifest last.

~~~sh
python3 tools/match/verify_ffx_memcmp.py recon/ffx/byteproof/build_c/ffx_memcmp.exe
~~~

The proof JSON files under build/ and build_c/ identify the reference, code
body, compiler, inputs and verification results. The C build manifest binds its
input snapshots to its output image; a stale source/recipe must be rejected.

## Cached-candidate audit

~~~sh
python3 tools/match/audit_exact.py \
  --project /mnt/ssd-kingston/ffx-reconstructed \
  --output-dir recon/ffx/byteproof/audit
~~~

Eight cached disassembly groups produce **695 distinct exact function bodies,
49,771 code bytes** under a conservative unique-boundary rule, minimum 16 bytes.
The audit.json file includes one hashed evidence record per address. Expanded
per-group reports can be regenerated. Duplicate translation-unit emissions do
not increase coverage. This is a subset audit, not a replacement for the historical
2,944-function relocation-masked discovery catalog or a whole-program rebuild.

FFX_GS_DecompressTiledTexture at 0x90e2e0, size 698, has a stale inventory hash:

* Recorded: e74647ae1dd8beacb12adcb1da9c259773ec730e513e28fcfc90c7ca0d5d44b2.
* Pinned executable: a0bcaf90a12a791b523f8314ca96bcf02e18137ed413bbca8c3e7495ca88b9bf.

The strict matcher rejects this inventory by default. The audit explicitly
quarantines the row: it receives no coverage but remains a competitor during
uniqueness checking. Removing a bad-hash competitor could otherwise create a
false unique match. The shared inventory is unchanged.

## Acceptance changes

The historical matcher treated sliding four-byte windows resembling addresses
and E8/E9 bytes inside immediates as relocations. It accepted different
constants, including b8efbeaddec3 versus b801004000c3, without relocation evidence.
The default comparison is now exact. The explicit --heuristic-candidates option
retains discovery behavior with an unverified classification. Unresolved calls
are not exact matches.

The inventory verifier returns failure for wrong hashes, incomplete PE ranges,
invalid sizes, duplicate addresses and malformed or empty inventories. Symbol
attribution imports its sibling matcher instead of a different checkout. Candidate
snapshots are hashed and parsed from the same bytes.

Existing discovery callers may report fewer hits under the stronger default.
This changes acceptance evidence; it does not establish that every excluded
candidate is semantically wrong. Relocatable candidates need actual COFF records,
independently established symbol targets and a reproducible link before receiving
credit for their final linked bytes.

## C leaf reconstruction

The separate ../c_leaf/ lane synthesizes bounded C operations before compilation,
then checks real VS2012 function sections. Each address is selected before the
build, rather than inferred from a coincidental match afterward. Its reports
distinguish successful implementations from rejected candidates. Original PE
base relocations are checked in addition to COFF relocations: a literal with
pointer-shaped bits cannot silently replace a relocatable address.

## Remaining whole-program work

This package does not claim a rebuilt 10,675,712-byte executable. Full C/C++
recovery, remaining function bodies, data, imports, original placement, linker
content, resources and the final file comparison remain distinct requirements.
Completion requires a reproducible full build and the reference SHA-256.

The separate reverser/checker workflow follows the approach described by
[ReAgent](https://github.com/Dryxio/reagent). ReAgent itself distinguishes its
structural and configured validation from proof of whole-program equivalence.
