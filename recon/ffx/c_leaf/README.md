# Address-selected C leaf reconstruction

This lane recognizes a small explicit set of x86 instruction shapes and writes
C operations for their parameters, constants and field accesses. It embeds no
machine-code arrays and does not patch compiled output. Unknown shapes are ignored.

Current verified result: **329 distinct C implementations, 2,710 intended original
function addresses, 16,424 code bytes**. All accepted bodies match complete original
function ranges and have no COFF or original PE base relocations. The 3,183 rejected
addresses remain in proof.json with no coverage credit.

Many original functions share the same small body. The number of distinct C
implementations therefore differs from the number of target addresses. This
package does not reconstruct their final linker placement or the full executable.
The minimum selected body length is four bytes. Counts should not be compared
directly with the separate cached-candidate audit, which uses a 16-byte minimum.

All rejected functions require their original PE base relocations and data-symbol
definitions; they cannot be replaced by plain integer constants. The previous
register-allocation differences in the two Vec4 scalar-multiply bodies and
FFX_Math_SumDwordArray are closed by the source forms documented in ../register_probe/.
They passed the normal C compilation, not just the isolated C++ probe. Every
selected relocation-free body now matches. Math and copy templates preserve
the observed parameter slots, return register and x87 operation order.

## Reproduce

~~~sh
python3 tools/match/leaf_reconstruct.py prepare
~~~

Stage ffx_leaf.c, jobs.json, build.bat and leaf_build.py from this folder together
in an independent Windows directory with Python available as py -3. The original
x86 compiler is VS2012 Express 17.00.50727.1. Run build.bat, then retrieve its
build/ directory, including objects, build.log, build-manifest.json and retained
inputs/ snapshots.

The three recorded variants use /GS- /MD /Oi /arch:IA32 /Gy, with /O2 /Oy-,
/O1 /Oy-, or /O2 /Oy. Only actual byte equality counts; a flag recipe by itself
does not establish a match.

~~~sh
python3 tools/match/leaf_reconstruct.py verify
python3 -m unittest discover -s tools/match -p test_leaf_reconstruct.py -v
~~~

The builder compiles immutable input snapshots in a fresh temporary directory,
checks current and retained inputs before/after each compile, captures its log,
and publishes the build manifest only after every step succeeds. Inherited
compiler flags are cleared. A failed build invalidates an earlier success receipt.

The verifier binds source, selected jobs, recipe, helper, objects and log by
SHA-256. It checks the current original inventory, rejects duplicate or overlapping
target ranges, and invalidates stale proof on failure. The original executable
is pinned. Generated source represents candidates,
including unsuccessful ones; proof.json alone identifies accepted implementations.

ECX-only member bodies use ABI-equivalent single-argument fastcall C functions.
The original C++ class names and field types are not claimed recovered merely
because the body bytes agree. Proper linker symbols, data definitions and final
placement are still required for a whole-program build.
