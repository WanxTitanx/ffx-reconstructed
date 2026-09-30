import struct, os

BASE = r"/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master"
def u16le(b, o): return struct.unpack_from("<H", b, o)[0]
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
print("### FMT — battle.fmt (jppc/menu) — glyph blocks")
print("="*90)
fmt = open(os.path.join(BASE, "jppc", "menu", "battle.fmt"), "rb").read()
print(f"Size: {len(fmt)} (0x{len(fmt):x}) = {len(fmt)//256} glyphs x 256B")
for g in [0, 1, 2, 3, 0x20, 0x21, 0x7f, 0x80, 0xff]:
    o = g * 256
    print(f"\n--- Glyph {g:#04x} @0x{o:04x} ---")
    print(hexdump(fmt, o, 256))

print("\n=== Analyze glyph block structure across all 256 glyphs ===")
shape_lens = []
for g in range(256):
    o = g * 256
    # shape = ASCII from 0x01 until 0x00
    end = o + 1
    while end < o + 256 and 0x20 <= fmt[end] < 0x7f:
        end += 1
    shape = fmt[o+1:end].decode('ascii', errors='replace')
    shape_lens.append((g, end - (o+1), shape))
print("Glyphs with shape length > 0:", sum(1 for s in shape_lens if s[1] > 0), "of 256")
print("First 40 shapes:")
for g, ln, sh in shape_lens[:40]:
    print(f"  glyph {g:#04x}: len={ln:3d} shape='{sh}'")
print("Last 10 shapes:")
for g, ln, sh in shape_lens[-10:]:
    print(f"  glyph {g:#04x}: len={ln:3d} shape='{sh}'")
# distribution of shape lengths
from collections import Counter
print("Shape length distribution:", dict(Counter(ln for _, ln, _ in shape_lens)))

print("\n=== Pixel data zones (0x40-0xbf, 0xc0-0xff) ===")
for g in [0, 1, 0x20, 0x7f, 0xff]:
    o = g * 256
    z1 = fmt[o+0x40:o+0xc0]
    z2 = fmt[o+0xc0:o+0x100]
    nz1 = sum(1 for x in z1 if x != 0)
    nz2 = sum(1 for x in z2 if x != 0)
    print(f"  glyph {g:#04x}: zone@0x40 non-zero={nz1}/128, zone@0xc0 non-zero={nz2}/64")

print()
print("="*90)
print("### SPS2 — dvdcopy.sps2 (jppc/help)")
print("="*90)
sps2 = open(os.path.join(BASE, "jppc", "help", "dvdcopy.sps2"), "rb").read()
print(f"Size: {len(sps2)} (0x{len(sps2):x})")
print("Header u32 LE:")
for i in range(8):
    print(f"  [{i}] @0x{i*4:02x}: {u32le(sps2, i*4):#010x}")

count = u32le(sps2, 4)
data_off = u32le(sps2, 0x0c)
offs_off = u32le(sps2, 0x10)
print(f"\ncount={count}, data_offset=0x{data_off:x}, offsets_offset=0x{offs_off:x}")
print(f"\nData entries @0x{data_off:x} (each 12 bytes = 6 u16):")
for i in range(count):
    o = data_off + i*12
    vals = [u16le(sps2, o+j*2) for j in range(6)]
    print(f"  entry[{i}]: x_min={vals[0]:#06x} x_max={vals[1]:#06x} y_min={vals[2]:#06x} y_max={vals[3]:#06x} type={vals[4]:#06x} sentinel={vals[5]:#06x}")

print(f"\nOffsets table @0x{offs_off:x} (first 64 u32):")
for i in range(64):
    o = offs_off + i*4
    if o + 4 > len(sps2): break
    print(f"  [{i:3d}] {u32le(sps2, o):#010x}", end="")
    if i % 4 == 3: print()
print()

# Check what the offsets point to
print("Data at each offset (first 16):")
for i in range(16):
    o = offs_off + i*4
    target = u32le(sps2, o)
    if target < len(sps2):
        print(f"  [{i}] -> 0x{target:x}: {sps2[target:target+16].hex(' ')}")

print("\nFull dump 0x00-0x140:")
print(hexdump(sps2, 0, 0x140))
