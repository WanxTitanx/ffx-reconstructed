# FFX Reverse Engineering Toolkit

Python tools for FFX.exe reverse engineering, based on IDA Hex-Rays decompilation data.

## Tools

### 1. monster_bin_parser.py
Parse FFX monster .bin data files (individual monster stats, AI scripts, loot).

```bash
# Parse individual monster
python monster_bin_parser.py "D:/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/battle/mon/_m000/m000.bin"

# Parse kernel index
python monster_bin_parser.py --kernel "D:/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/battle/kernel/monster1.bin"

# Parse all monsters in directory
python monster_bin_parser.py --dir "D:/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/battle/mon/"
```

**Validated against:** FfxLib/Monster/Monster_Structs.cs (header=8, 7 section pointers)

### 2. atel_disassembler.py
Disassemble ATEL bytecode (scripting language for cutscenes, battles, maps).

```bash
# Disassemble a binary file
python atel_disassembler.py some_file.bin

# Filter by channel
python atel_disassembler.py --filter battle some_file.bin

# Scan for ATEL patterns
python atel_disassembler.py --scan some_file.bin
```

### 3. ctb_simulator.py
Simulate FFX's Conditional Turn-Based battle system.

```bash
# Run with default roster
python ctb_simulator.py

# Custom roster
python ctb_simulator.py --turns 20 --party "Tidus:40,Yuna:35,Auron:38" --monsters "Grat:20,Ochu:18"
```

### 4. sphere_grid_editor.py
Edit FFX's Sphere Grid nodes (217 nodes, 5 neighbors max).

```bash
# Generate demo grid
python sphere_grid_editor.py --generate 20 --list

# Show node details
python sphere_grid_editor.py --bin grid.bin --show 5

# Edit node
python sphere_grid_editor.py --bin grid.bin --edit 5 --pos "100,200,0" --type ability
```

### 5. ffx_damage_calculator.py
Calculate FFX damage with all 30+ modifiers.

```bash
# Demo calculation
python ffx_damage_calculator.py --demo

# Custom calculation
python ffx_damage_calculator.py --attacker "Tidus:50:30:20:none" --defender "Grat:100:10:0:fire"
```

## Data Files

Monster .bin files are at:
```
D:/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/battle/mon/_mXXX/mXXX.bin
D:/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/battle/kernel/monster1.bin
```

## Related

- Batch documentation: `F:\ffx-reconstructed\pseudocode\` (66 docs, 1.5MB)
- Editor parsers: `FFXProjectEditor/FfxLib/` (27 C# file parsers)
- IDA database: `F:\ffx-reconstructed\extras\ffxoficial_COPY.i64`
