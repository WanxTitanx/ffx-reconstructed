# Register-allocation experiments

These are small compiler probes, not a separately counted reconstruction lane.
The accepted source forms are promoted into c_leaf and rebuilt there with its
input-manifest checks. The final c_leaf proof is authoritative for coverage.

VS2012 17.00.50727.1, x86, /O2 /MD /GS- /Oy- /Oi /arch:IA32 /Gy:

| Probe | Target | Observed result |
| --- | --- | --- |
| leaf_00000001 | 0x74bf00 and 0x7501a0 | All 46 bytes equal, zero object relocations |
| leaf_00000002 | 0x76b2f0 | All 26 bytes equal, zero object relocations |
| leaf_00000004 | 0x76b2f0 | Same emitted instructions as probe 2; probe 2 is simpler C |
| leaf_00000003 | 0x76b2f0 | Different ECX/EDX allocation; rejected |
| leaf_00000005 | 0x76b2f0 | Different size and control flow; rejected |

For vector scaling, returning the input pointer keeps it in EAX, matching the
reference. A void return allowed MSVC to allocate EAX to the output pointer.
The matching signature reproduces the observed return register; it does not
recover an original source declaration or typedef by itself.

For the array sum, post-decrement in the loop condition and post-increment in
the load reproduce ECX as the count and EDX as the input pointer. A guarded
do/while version reverses that allocation. Matching behavior alone would not
have detected the difference.

The probe batch uses /TP and extern C because probe 4 declares a loop variable in
its initializer. The promoted probes 1 and 2 are valid C and must also pass the
ordinary C build. No compiler output is modified to obtain the matches.
