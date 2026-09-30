# Complete source-built FFX.exe

The acceptance artifact is proof.json. It requires literal whole-file equality,
the complete nonempty source/build input closure, a verified syscall audit bound
to this manifest and candidate, and a fresh linker replay in a separate traced
process. The replay must reproduce both every image byte and every manifest
field, including the exact input set, section records, relocations and statistics.
Import/header and two loaded-image rebasing comparisons then run independently.
A matching file copy with an empty, incomplete or contradictory manifest is
rejected. A failed verification removes the previous proof.

Target: 10,675,712 bytes, PE32 x86, SHA-256
78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced.

## What is reconstructed

This is an inspectable mixed C/assembly reconstruction, not recovery of the
original C++ project. The full native code is represented by explicit x86
instruction fields and symbolic references, with independently compiled C
providers replacing the portions reconstructed in C. The assembler creates
fresh instructions from those fields; it does not decode reference code,
import original instruction byte arrays, or patch mismatched compiler bytes
during a build.

The current .text plan contains 2,142,911 explicit assembly instructions,
5,894 C function providers, one manual assembly provider, typed data islands,
and declared alignment. C providers contribute 35,956 bytes; the remaining
native code is assembly source. This must not be described as complete
high-level C/C++ recovery.

Data, strings and resource payloads are declared separately in assembly sources.
Address-bearing fields use symbol references and actual COFF relocations.
Uninitialized storage has explicit virtual allocation. DOS fields, the seven
DOS-stub instructions, Rich records, NT headers, directories, section table,
and ordered base-relocation entries are emitted from structured source fields.

## Rebuild on the current host

From the preserved worktree:

    recon_root="$(pwd -P)"
    strace -f -s 4096 -yy -e trace=open,openat,openat2,execve -o "$recon_root/recon/ffx/complete/build.trace" "$recon_root/recon/ffx/.venv-asm/bin/python" "$recon_root/tools/match/run_source_only.py" "$recon_root/tools/match/rebuild_complete.py" > recon/ffx/complete/build.log 2>&1
    recon/ffx/.venv-asm/bin/python tools/match/complete_acceptance.py record-audit
    recon/ffx/.venv-asm/bin/python tools/match/verify_complete_image.py

The first command assembles every text/data source chunk and links FFX.exe,
while tracing opens and process exits, including child processes. Retained C
objects are admitted only after their build-time source/jobs/recipe snapshots
are checked. The second command binds the trace, log, manifest and candidate.
The third command independently opens the original for literal comparison,
verifies that audit, and runs a fresh linker replay under strace. This replay
must not open the original or the candidate being certified. Its trace and log
are retained under acceptance/ and bound to proof.json. It also compares the
mapped image at 0x10000000 and 0x50000000; these are loader-model checks, not gameplay.

Audit validation requires successful execve of the recorded command, successful
opens of every manifest input, and creation of the actual image/manifest outputs.
A successful but unrelated trace cannot certify the build. The command uses
absolute script paths so the captured execve matches the recorder's exact argv.

The exact open counts and trace hashes are in source_only_audit.json and the
independent_source_link_replay field of proof.json. Both are recomputed during
acceptance. The Python guard by itself is not an operating-system sandbox or
a security boundary. strace is mandatory for final acceptance on this host.

--link-only on rebuild_complete.py is the acceptance replay path. It validates
and links the retained objects; it does not claim to recompile the C providers.
The full-build command above reassembles every prepared text/data source. The
separate C build recipes below establish their original compiler receipts.

The source formats use Python 3, iced-x86 1.21.0, native i386 COFF data
assembly through Clang, GNU assembler for the manual MCWL provider, and the
project's strict COFF/PE linker. Exact native-tool hashes and commands are
retained in build receipts. The C bodies use VS2012 17.00.50727.1 x86;
their documented package commands are under ../c_leaf/, ../c_reloc/, and
../byteproof/. Build helpers compile retained snapshots, clear inherited
compiler flags, reject changed inputs, and publish receipts last.

After rebuilding a C provider or changing an assembly generator, regenerate
the source-selection plan before rebuilding the image:

    recon/ffx/.venv-asm/bin/python tools/match/text_program.py prepare

Preparation is analysis: it reads the reference and the IDA typing export.
It is deliberately separate from the source-only build. The committed source
packages already contain the prepared declarations.

## Evidence and ownership

manifest.json records every placed object, source input hashes, the complete
HIGHLOW site set, resolved symbol count, imports and section hashes.
The linker rejects missing labels, overlapping objects, undeclared file gaps,
stale sources, invalid BSS declarations, mismatched relocation sites and any
final digest other than the pinned target. Relocation sites are derived from
actual COFF objects, then checked against the structured PE table.

The generated executable and large rebuild caches stay in this worktree.
Committed source declarations, compiler receipts and final verification
evidence provide the rebuild path. No changes to the original game executable
or to the other agent's main source tree are required.
