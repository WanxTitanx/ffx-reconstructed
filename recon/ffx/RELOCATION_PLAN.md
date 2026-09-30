# Data, relocation and PE integration implementation plan

Goal: continue GOAL.md from b21c9ead7 through real symbol dependencies and final-image comparison.
Architecture: retain the existing relocation-free C proof; build a new symbol-backed translation unit
for the rejected functions, derive data symbols from actual PE/analysis evidence, and link original-address
sections using relocation records. No reference code blobs, operand patching, guessed relocation masks,
or stubs receive coverage. Full executable completion requires the pinned complete-file SHA-256.
Toolchain: VS2012 17.00.50727.1 x86; Python analysis/build/verifiers; COFF and PE32.

## Constraints and execution

- Work only in this preserved branch; coordinate via the main checkout's recon/COORDINATION_COS_41719.md.
- ReAgent reference: Dryxio/reagent at d12cea338c61898b06a86fe8adb25275fa9d5615. Root AGENTS.md fetch
  returned 404; README and docs/agent-setup.md describe evidence, dependency order, independent checking,
  real build/runtime gates, and explicit unknown results. The local project AGENTS.md continues to apply.
- Inspect actual relocation sites and follow pointers transitively before selecting data boundaries.
- Emit C symbolic references and actual COFF relocations; validate exact site/type/symbol/addend.
- Data, code, imports and resource leaves need provenance and declared ownership; unresolved items remain unresolved.
- Retain immutable inputs, generator/recipe/helper hashes, tool identities and full outputs; detect drift before/after.
- Tests must reject wrong targets, wrong relocation widths/types, false instruction offsets, stale source,
  overlapping ranges, duplicate addresses, malformed files, and unbacked virtual memory reads.
- Integration creates a new image from generated objects and declarations, never modifies the reference.
- Compare full file, sections, directory structure and every covered range; functional checks supplement exact bytes.

## Tasks

1. Inspect relocation frontier and reachable data/code graph; record peer ownership and evidence sources.
2. Test and implement symbol-backed C plus strict COFF relocation reader; compile all reachable pending bodies.
3. Test and implement source/data layout linking and PE structural emission with unresolved-dependency rejection.
4. Resolve exposed downstream dependencies, repeat compiler/link/image validation, preserve negative probes.
5. Commit integrated results and a concrete blocker only if an external dependency actually prevents further work.
