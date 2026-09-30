import struct, os

BASE = r"D:\FFX Extracted\FFX\ffx_ps2\ffx\master"
def u16le(b, o): return struct.unpack_from("<H", b, o)[0]
def u32le(b, o): return struct.unpack_from("<I", b, o)[0]

def hexdump(data, off=0, length=None, width=16):
    if length is None: length = len(data) - off
    out = []
    for base in range(off, min(off+length, len(data)), width):
        chunk = data[base:base+width]
        hexs = " ".join(f"{b:02x}" for b in chunk)
        asc = "".join(chr(b) if 0x20 <= b < 0x7f else "." for b in chunk)
        out.append(f"{base:08x}  {hexs:<{width*3}}  {asc}")
    return "\n".join(out)

# ---- DCP string pool decode ----
print("="*90)
print("### DCP — string pool decode")
print("="*90)
dcp = open(os.path.join(BASE, "jppc", "menu", "macrodic.dcp"), "rb").read()

# T1 pairs: (start, end) offsets. First pair (0x1ac, 0x1b2).
# The data at 0x1ac is itself u16 offsets. Let's decode the strings.
# Try: string pool base = 0x1ac, T1 offsets point to u16 entries that are offsets into pool.
# Let's just decode Shift-JIS strings starting at various points.
def decode_sjis(data, off, maxlen=64):
    out = []
    i = off
    while i < len(data) and i < off + maxlen:
        b = data[i]
        if b == 0:
            break
        if b < 0x80:
            out.append(chr(b))
            i += 1
        elif i + 1 < len(data):
            try:
                out.append(bytes([b, data[i+1]]).decode('shift_jis'))
            except:
                out.append(f"[{b:02x}{data[i+1]:02x}]")
            i += 2
        else:
            break
    return "".join(out)

# T1: 384 pairs. Let's decode the first 20 macro strings.
# The pair (start,end) — string is at [start, end) in the file.
print("T1 macro strings (first 30):")
for i in range(30):
    o = 0x40 + i*4
    s = u16le(dcp, o)
    e = u16le(dcp, o+2)
    if s == 0 and e == 0:
        print(f"  macro[{i:3d}]: (empty)")
        continue
    raw = dcp[s:e]
    txt = decode_sjis(raw, 0, len(raw))
    print(f"  macro[{i:3d}]: 0x{s:04x}..0x{e:04x} ({e-s:3d}B) = '{txt}'")

# T2: single offsets. Decode first 20.
print("\nT2 strings (first 20):")
for i in range(20):
    o = 0x640 + i*2
    s = u16le(dcp, o)
    if s == 0:
        print(f"  [0x{i:04x}]: (empty)")
        continue
    # find end = next offset
    e = u16le(dcp, o+2)
    if e <= s:
        # null terminated
        e = s
        while e < len(dcp) and dcp[e] != 0:
            e += 1
    raw = dcp[s:e]
    txt = decode_sjis(raw, 0, len(raw))
    print(f"  [0x{i:04x}]: 0x{s:04x}..0x{e:04x} = '{txt}'")

# T3: single offsets. Decode first 20.
print("\nT3 strings (first 20):")
for i in range(20):
    o = 0xE00 + i*2
    s = u16le(dcp, o)
    if s == 0:
        print(f"  [0x{i:04x}]: (empty)")
        continue
    e = u16le(dcp, o+2)
    if e <= s:
        e = s
        while e < len(dcp) and dcp[e] != 0:
            e += 1
    raw = dcp[s:e]
    txt = decode_sjis(raw, 0, len(raw))
    print(f"  [0x{i:04x}]: 0x{s:04x}..0x{e:04x} = '{txt}'")

# T5: single offsets. Decode first 20.
print("\nT5 strings (first 20):")
for i in range(20):
    o = 0x1AF0 + i*2
    s = u16le(dcp, o)
    if s == 0:
        print(f"  [0x{i:04x}]: (empty)")
        continue
    e = u16le(dcp, o+2)
    if e <= s:
        e = s
        while e < len(dcp) and dcp[e] != 0:
            e += 1
    raw = dcp[s:e]
    txt = decode_sjis(raw, 0, len(raw))
    print(f"  [0x{i:04x}]: 0x{s:04x}..0x{e:04x} = '{txt}'")

# T6: single offsets. Decode first 20.
print("\nT6 strings (first 20):")
for i in range(20):
    o = 0x5680 + i*2
    s = u16le(dcp, o)
    if s == 0:
        print(f"  [0x{i:04x}]: (empty)")
        continue
    e = u16le(dcp, o+2)
    if e <= s:
        e = s
        while e < len(dcp) and dcp[e] != 0:
            e += 1
    raw = dcp[s:e]
    txt = decode_sjis(raw, 0, len(raw))
    print(f"  [0x{i:04x}]: 0x{s:04x}..0x{e:04x} = '{txt}'")

# Determine actual entry counts per table (count non-zero, monotonic entries)
print("\n=== Table entry counts (non-zero, monotonic) ===")
for name, base, end in [("T1", 0x40, 0x640), ("T2", 0x640, 0xE00), ("T3", 0xE00, 0x1AD0), ("T5", 0x1AF0, 0x5680), ("T6", 0x5680, len(dcp))]:
    n = 0
    last = -1
    for o in range(base, end, 2):
        v = u16le(dcp, o)
        if v == 0:
            break
        if v < last:
            break
        last = v
        n += 1
    print(f"  {name}: {n} entries (monotonic non-zero)")

# ---- CLP block structure ----
print()
print("="*90)
print("### CLP — block structure (64 blocks x 256B)")
print("="*90)
clp = open(os.path.join(BASE, "jppc", "menu", "menu.clp"), "rb").read()
print("Block headers (8 u32 BE each) for blocks 0-7:")
for b in range(8):
    o = b * 256
    vals = [struct.unpack_from(">I", clp, o + i*4)[0] for i in range(8)]
    print(f"  block {b}: {[hex(v) for v in vals]}")

# Check if all blocks identical
blocks = [clp[b*256:(b+1)*256] for b in range(64)]
uniq = set(blocks)
print(f"\nUnique blocks: {len(uniq)} of 64")
# Find which blocks are identical to block 0
same_as_0 = [b for b in range(64) if blocks[b] == blocks[0]]
print(f"Blocks identical to block 0: {same_as_0}")
# Show distinct block patterns
from collections import Counter
c = Counter(blocks)
print(f"Block distribution: {[(i, n) for i, (blk, n) in enumerate(c.most_common())]}")

# Dump block 1 and block 2 headers
print("\nBlock 1 (0x100-0x1ff):")
print(hexdump(clp, 0x100, 0x100))
