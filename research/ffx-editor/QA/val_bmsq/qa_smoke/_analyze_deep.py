import struct, os

BASE = r"/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master"
def u16le(b, o): return struct.unpack_from("<H", b, o)[0]
def u16be(b, o): return struct.unpack_from(">H", b, o)[0]
def u32le(b, o): return struct.unpack_from("<I", b, o)[0]
def u32be(b, o): return struct.unpack_from(">I", b, o)[0]

def hexdump(data, off=0, length=None, width=16):
    if length is None: length = len(data) - off
    out = []
    for base in range(off, min(off+length, len(data)), width):
        chunk = data[base:base+width]
        hexs = " ".join(f"{b:02x}" for b in chunk)
        asc = "".join(chr(b) if 0x20 <= b < 0x7f else "." for b in chunk)
        out.append(f"{base:08x}  {hexs:<{width*3}}  {asc}")
    return "\n".join(out)

print("="*90)
print("### CLP — menu.clp (jppc/menu)")
print("="*90)
clp = open(os.path.join(BASE, "jppc", "menu", "menu.clp"), "rb").read()
print(f"Size: {len(clp)} (0x{len(clp):x})")
print("\nHeader (0x00-0x20) as u32 BE:")
for i in range(8):
    print(f"  [{i}] {u32be(clp, i*4):#08x}")
print("\nHeader (0x00-0x20) as u32 LE:")
for i in range(8):
    print(f"  [{i}] {u32le(clp, i*4):#08x}")

print("\nData 0x20-0x40 (32 bytes, 8 groups of 4):")
for i in range(8):
    o = 0x20 + i*4
    print(f"  @{o:04x}: {clp[o]:02x} {clp[o+1]:02x} {clp[o+2]:02x} {clp[o+3]:02x}")

print("\nSection @0x40 (first 64 bytes):")
print(hexdump(clp, 0x40, 64))

print("\nSection @0x40 u32 BE values:")
for i in range(8):
    print(f"  [{i}] {u32be(clp, 0x40+i*4):#08x}")

print("\nFull dump 0x00-0x100:")
print(hexdump(clp, 0, 0x100))

# Find where the 00 00 00 ff pattern starts
print("\nScanning for 00 00 00 ff runs (palette?):")
runs = []
i = 0
while i < len(clp) - 3:
    if clp[i:i+4] == b"\x00\x00\x00\xff":
        start = i
        while i < len(clp) - 3 and clp[i:i+4] == b"\x00\x00\x00\xff":
            i += 4
        runs.append((start, i))
    else:
        i += 1
print(f"  {len(runs)} runs of 00 00 00 ff")
for s, e in runs[:10]:
    print(f"  0x{s:04x}..0x{e:04x} ({e-s} bytes, {(e-s)//4} entries)")

# Check for other 4-byte repeating patterns
print("\nFirst 0x400 bytes as u32 LE values (first 64):")
for i in range(64):
    print(f"  {i:3d}: {u32le(clp, i*4):#010x}", end="")
    if i % 4 == 3: print()
print()

print("="*90)
print("### DCP — macrodic.dcp (jppc/menu)")
print("="*90)
dcp = open(os.path.join(BASE, "jppc", "menu", "macrodic.dcp"), "rb").read()
print(f"Size: {len(dcp)} (0x{len(dcp):x})")
print("\nHeader 0x00-0x40 as u32 LE:")
for i in range(16):
    print(f"  [{i:2d}] @0x{i*4:02x}: {u32le(dcp, i*4):#010x}")

offsets = [0x40, 0x640, 0xE00, 0x1AD0, 0x1AF0, 0x5680, len(dcp)]
print("\nTable boundaries:", [hex(o) for o in offsets])
for i in range(len(offsets)-1):
    sz = offsets[i+1] - offsets[i]
    print(f"  T{i+1}: 0x{offsets[i]:x}..0x{offsets[i+1]:x} = {sz} bytes = {sz//2} u16")

print("\nT1 @0x40 first 32 u16 (pairs):")
for i in range(16):
    o = 0x40 + i*4
    print(f"  pair[{i}]: {u16le(dcp,o):#06x} {u16le(dcp,o+2):#06x}")
print("\nT1 last 8 u16 (near 0x640):")
for i in range(4):
    o = 0x640 - 8 + i*4
    print(f"  @0x{o:x}: {u16le(dcp,o):#06x} {u16le(dcp,o+2):#06x}")

print("\nT2 @0x640 first 16 u16:")
for i in range(16):
    print(f"  {u16le(dcp, 0x640+i*2):#06x}", end=" ")
print()
print("\nT2 last 8 u16:")
for i in range(8):
    print(f"  {u16le(dcp, 0xE00-16+i*2):#06x}", end=" ")
print()

print("\nT3 @0xE00 first 16 u16:")
for i in range(16):
    print(f"  {u16le(dcp, 0xE00+i*2):#06x}", end=" ")
print()
print("\nT3 last 16 u16 (near 0x1AD0):")
for i in range(16):
    print(f"  {u16le(dcp, 0x1AD0-32+i*2):#06x}", end=" ")
print()

print("\nT4 @0x1AD0 (32 bytes):")
print(hexdump(dcp, 0x1AD0, 32))
print("  as u16 LE:", [hex(u16le(dcp, 0x1AD0+i*2)) for i in range(16)])

print("\nT5 @0x1AF0 first 16 u16:")
for i in range(16):
    print(f"  {u16le(dcp, 0x1AF0+i*2):#06x}", end=" ")
print()
print("\nT5 last 16 u16 (near 0x5680):")
for i in range(16):
    print(f"  {u16le(dcp, 0x5680-32+i*2):#06x}", end=" ")
print()

print("\nT6 @0x5680 first 16 u16:")
for i in range(16):
    print(f"  {u16le(dcp, 0x5680+i*2):#06x}", end=" ")
print()
print("\nT6 last 16 u16:")
for i in range(16):
    print(f"  {u16le(dcp, len(dcp)-32+i*2):#06x}", end=" ")
print()

# String pool analysis: T1 first offset 0x1ac
print("\nString pool start 0x1ac (first 128 bytes):")
print(hexdump(dcp, 0x1ac, 128))
