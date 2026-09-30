import struct

path = r"/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/menu/menu.clp"
data = open(path, "rb").read()
print(f"size: {len(data)} (0x{len(data):X}) = {len(data)//4096} blocks of 4096")

# For each 4KB block, dump the first 0x40 bytes (header) and check for offset tables
for block in range(4):
    base = block * 4096
    hdr = struct.unpack(">8I", data[base:base+32])
    print(f"\n=== Block {block} @ 0x{base:04X} ===")
    print(f"  header u32 BE: {[hex(x) for x in hdr]}")
    # Check if header values look like offsets (small, non-decreasing)
    # Dump first 0x200 bytes as u32 BE
    vals = []
    for off in range(0, 0x200, 4):
        v = struct.unpack(">I", data[base+off:base+off+4])[0]
        vals.append(v)
    # Find runs of small non-decreasing values
    print("  first 0x200 as u32 BE:", [hex(v) for v in vals[:32]])
