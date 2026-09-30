# Symbol-backed C reconstruction

This package replaces the numeric pointer constants in the prior rejected leaf
jobs with real external C symbols. VS2012 x86 17.00.50727.1 emits 828 independent
function sections, each containing one actual IMAGE_REL_I386_DIR32 relocation.
The selected sections instantiate 3,183 original functions (19,420 bytes).

tools/match/symbolic_verify.py validates immutable build inputs, checks each
COFF site/type/symbol/addend against the selected operation and original PE
relocation directory, applies the actual relocation using explicit layout
bindings, and requires literal equality of the complete function body.

The 3,183 comparisons pass. This proves the function bodies under the declared
bindings; it does not prove the bodies of all referenced data/code symbols.
That transitive closure is handled by the PE integration. proof.json keeps
data_dependency_closure_verified and whole_executable_reconstructed false.
There is no operand masking, reference-byte insertion, or post-compiler editing.

## Reproduce

Run python3 tools/match/symbolic_leaf.py from the worktree. Stage the generated
package, its build.bat, relocation_build.py and leaf_build.py on the Windows VM,
then run build.bat. The build compiles retained source snapshots in a fresh
directory and publishes the build-manifest last. Fetch build/ and run
python3 tools/match/symbolic_verify.py against the pinned original.

The native VS2012 source build uses /c /GS- /MD /Oi /arch:IA32 /Gy and the
three O2/O1/Oy variants already established by the leaf pipeline. Compiler and
backend DLL hashes are recorded in the manifest. Executing the verification
never modifies the original executable.
