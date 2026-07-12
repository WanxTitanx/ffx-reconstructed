#!/usr/bin/env python
"""
Full batch decompiler for range 0x800000 - 0xA00000.
Run this inside IDA Pro 7.x with Hex-Rays decompiler.

Instructions:
  File -> Script file... (or Alt+F7) in IDA Pro
  OR paste into IDAPython console

Output: Each function saved as pseudocode/range_800000_A00000/<addr>_<name>.c
"""

import os
import ida_funcs
import ida_hexrays
import idautils
import ida_kernwin
import ida_pro

OUTPUT_DIR = os.path.join(
    os.path.dirname(ida_kernwin.get_idb_path()),
    "ffx_reconstructed", "pseudocode", "range_800000_A00000"
)
MIN_ADDR = 0x800000
MAX_ADDR = 0xA00000  # exclusive

os.makedirs(OUTPUT_DIR, exist_ok=True)

total = 0
success = 0
failed = 0
errors = []

print("=" * 60)
print("Batch decompiler: 0x800000 - 0xA00000")
print(f"Output: {OUTPUT_DIR}")
print("=" * 60)

for ea in idautils.Functions():
    if ea < MIN_ADDR or ea >= MAX_ADDR:
        continue
    
    name = ida_funcs.get_func_name(ea)
    func = ida_funcs.get_func(ea)
    if not func or not name:
        continue

    # Sanitize name for filename
    safe_name = name
    for ch in '?@:<> \"()[]{}|\\^*`\'!$&;=#%~':
        safe_name = safe_name.replace(ch, '_')
    safe_name = safe_name.strip('_').replace('__', '_')[:64]
    if not safe_name:
        safe_name = f"func_{ea:08X}"

    filename = f"{ea:08X}_{safe_name}.c"
    filepath = os.path.join(OUTPUT_DIR, filename)

    header = (
        f"// Function: {name}\n"
        f"// Address: 0x{ea:08X}\n"
        f"// Size: 0x{func.size:X}\n\n"
    )

    try:
        cfunc = ida_hexrays.decompile(ea)
        code = str(cfunc)
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(header + code + "\n")
        success += 1
    except Exception as e:
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(header + f"// DECOMPILATION FAILED: {e}\n")
        failed += 1
        errors.append((hex(ea), name, str(e)))

    total += 1
    if total % 500 == 0:
        print(f"[{total}] Processed {total} functions...")

print(f"\n{'=' * 60}")
print(f"RESULTS:")
print(f"  Total:     {total}")
print(f"  Success:   {success}")
print(f"  Failed:    {failed}")
print(f"  Output:    {OUTPUT_DIR}")
print(f"{'=' * 60}")

if errors:
    print(f"\nErrors ({len(errors)}):")
    for addr, name, err in errors[:20]:
        print(f"  {addr} {name}: {err}")
    if len(errors) > 20:
        print(f"  ... and {len(errors) - 20} more")
