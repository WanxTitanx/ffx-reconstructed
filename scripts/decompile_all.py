"""
FFX.exe mass decompilation driver.
Decompiles all Phyre_* and Engine_* functions in batches of 25,
saves pseudocode to JSON files organized by category.

Run via: python decompile_all.py
"""
import json
import os
import sys
import time
from pathlib import Path

# Output dirs
OUT_ROOT = Path("F:/ffx-reconstructed/pseudocode")
PHYRE_DIR = OUT_ROOT / "phyre"
ENGINE_DIR = OUT_ROOT / "engine"
OTHER_DIR = OUT_ROOT / "other"

for d in [PHYRE_DIR, ENGINE_DIR, OTHER_DIR]:
    d.mkdir(parents=True, exist_ok=True)

# We'll receive the function list via stdin as JSON
# Format: [{"addr": "0x...", "name": "...", "size": "0x..."}, ...]
functions = json.load(sys.stdin)
print(f"Loaded {len(functions)} functions to decompile", file=sys.stderr)

# Categorize
def category_for(name):
    if name.startswith("Phyre_"):
        return "phyre"
    if name.startswith("Engine_"):
        return "engine"
    return "other"

# Batch size
BATCH = 25

# Process in batches
total = len(functions)
batches = [functions[i:i+BATCH] for i in range(0, total, BATCH)]
print(f"Will produce {len(batches)} batches", file=sys.stderr)

# Output: one JSON per batch, named by index
# The actual decompilation is done by the caller via IDA MCP
# This script just writes the batch index file for tracking
for i, batch in enumerate(batches):
    out_file = OUT_ROOT / "batch_index" / f"batch_{i:04d}.json"
    out_file.parent.mkdir(parents=True, exist_ok=True)
    with open(out_file, "w") as f:
        json.dump({"batch_idx": i, "functions": batch}, f, indent=2)

print(f"Wrote {len(batches)} batch index files to {OUT_ROOT / 'batch_index'}", file=sys.stderr)
