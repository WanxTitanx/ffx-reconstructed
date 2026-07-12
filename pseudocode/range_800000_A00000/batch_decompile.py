#!/usr/bin/env python
"""
Batch decompile all functions in 0x800000-0xA00000 range from IDA DB.
Run this inside IDA Pro with Hex-Rays decompiler.

Usage: File -> Script file... (or Alt+F7) in IDA Pro
"""

import os
import ida_funcs
import ida_hexrays
import ida_lines
import ida_kernwin

OUTPUT_DIR = os.path.join(ida_kernwin.get_idb_path(), "..", "pseudocode", "range_800000_A00000")
MIN_ADDR = 0x800000
MAX_ADDR = 0xA00000  # exclusive

os.makedirs(OUTPUT_DIR, exist_ok=True)

total = 0
success = 0
failed = 0

for ea in idautils.Functions():
    if ea < MIN_ADDR or ea >= MAX_ADDR:
        continue
    
    name = ida_funcs.get_func_name(ea)
    func = ida_funcs.get_func(ea)
    
    if name is None or name.startswith("."):
        continue
    
    safe_name = name.replace("?", "_").replace("@", "_").replace(":", "_").replace("<", "_").replace(">", "_").replace(" ", "_").replace("(", "_").replace(")", "_")
    safe_name = safe_name.replace("__", "_").strip("_")
    if not safe_name:
        safe_name = f"func_{ea:08X}"
    
    filename = f"{ea:08X}_{safe_name}.c"
    filepath = os.path.join(OUTPUT_DIR, filename)
    
    header = f"// Function: {name}\n// Address: 0x{ea:08X}\n// Size: 0x{func.size:X}\n\n"
    
    try:
        cfunc = ida_hexrays.decompile(ea)
        code = str(cfunc)
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(header)
            f.write(code)
            f.write("\n")
        success += 1
    except Exception as e:
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(header)
            f.write(f"// DECOMPILATION FAILED: {e}\n")
        failed += 1
    
    total += 1
    if total % 100 == 0:
        print(f"[{total}] Processed {total} functions...")

print(f"\n=== Complete ===")
print(f"Total: {total}")
print(f"Success: {success}")
print(f"Failed: {failed}")
print(f"Output: {OUTPUT_DIR}")
