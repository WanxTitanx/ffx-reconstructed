# Verified standalone-modification checkpoint

This directory preserves the completed acceptance run, not input binaries for
the builder. Re-run tools/match/mod_acceptance.py --native-demo after changing
source or tools; an old proof is not an approval of changed inputs.

Results: 396 unit/integration tests passed. The native harness executed 101,400
calls across 0x00400000, 0x10000000 and 0x50000000, checking the real linked call
target, return values, alignments, counters and comparison records. It did not
execute the complete original caller or gameplay.

The unchanged and disabled executables are both 10,675,712 bytes with SHA-256
78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced.
Both external cmp commands exited 0 against the original.

The source-built example is 10,677,248 bytes with SHA-256
f9adb847cebf552678e7b3283f7c3bff8a9e468140f7304e616b2195f5c319d4.
The complete object, typed IR, manifest and image matched an independent fresh
compile and link byte for byte. The trace bound 666 recorded inputs and fresh
compiler object/IR creation and consumption. Receipts fingerprint 15 ELF
dependencies: 14 libraries read by both compiler invocations and the separately
identified kernel-loaded interpreter. Seven call operands resolve to the new code;
the original 112-byte body was preserved. There are 99 changed existing file
positions and 1,536 appended bytes, all recorded in the manifest.

Files:

- proof.json, manifest.json.gz, source_only_audit.json and build.trace.gz preserve
  the candidate build and whole-file acceptance. The compressed manifest contains
  its original exact JSON bytes, including every input and relocation record.
- replay-manifest.json.gz, replay-source_only_audit.json and replay-build.trace.gz
  preserve the independent process. Decompressing both manifests yields identical
  bytes; the replay object and detailed temporary outputs remain in mods/build.
- baseline-proof.json, baseline-manifest.json.gz, baseline-audit.json and
  baseline-build.trace.gz preserve the clean disabled build and its complete
  manifest. The build/verification logs are retained alongside them. Active snapshots are in
  mods/build/disabled; older complete/ evidence remains historical and untouched.
- native-report.json and test-suite.log record the executable behavior checks
  and the full test run. Native source and startup are committed beside this
  directory; each acceptance run freshly compiles the harness from those sources.
- review-worker1.json records the completed bounded independent review and its
  historical test counts. review-parent.json records subsequent fixes and final
  integration validation; it does not relabel the worker's review as a review of
  later parent changes.
- negative-address.json and its log record rejection of an actual source-only
  build containing a literal old-image pointer, before publication of an output.
  subsection-layout.json records a genuine Clang/PE-linker comparison confirming
  subsection ordering and declared four-byte alignment at offsets 0, 4 and 8.

The legacy C providers are checked against their retained compilation receipts.
The modified C object is freshly compiled in each independent process. Baseline
text/data assembly is refreshed before capturing modification input snapshots;
all later freshness comparisons remain literal, including serialized JSON.
