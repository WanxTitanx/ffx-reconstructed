# Strict call-convention recovery units

This directory contains 382 standalone MSVC C translation units whose generated machine code was verified byte-for-byte against FFX.exe at each unit's declared IDB address.

Each file preserves the recovered Hex-Rays function and its per-unit declarations. The call declarations use IDA's calling-convention map; for single-argument thiscall/fastcall calls, this is the first fastcall parameter and is passed in ECX. The full exported map is in recon/callconv_function_conventions.json. tools/match/export_call_conventions.py regenerates it from the IDB.

The units were compiled with Microsoft C/C++ 17.00.50727.1 for x86 using /nologo /TC /c /GS- /O2 /MD /Oy- /Oi. Their COFF .text REL32 relocations were resolved to target addresses in tools/match/inventory.tsv; the resulting full byte runs matched the PE at the declared function VAs. Per-function relocation offsets, target addresses, source hashes, original byte hashes, and target/IDB hashes are recorded in recon/callconv_recovered_exact.json (378 units) recon/callconv_o2_exact.json (2 units), and recon/callconv_o2_flags_exact.json (2 more units).

The broader manifest includes earlier matches made by a relocation-masked verifier. These files and the proof record identify the subset with full relocation-resolved byte equality.
