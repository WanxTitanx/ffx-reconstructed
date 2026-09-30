data = open('/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/menu/menu.clp', 'rb').read()
d2 = open('/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/uspc/menu/menu.clp', 'rb').read()
# per-4KB-block diff summary
for b in range(4):
    a = data[b*0x1000:(b+1)*0x1000]
    c = d2[b*0x1000:(b+1)*0x1000]
    ndiff = sum(1 for i in range(len(a)) if a[i]!=c[i])
    print(f"block {b}: {ndiff} differing bytes")
# dump block 0 structure: find table + palette layout
print("\n=== block 0 layout ===")
# The 8-entry table @0x0, 7-entry @0x40, 7-entry @0xC0, 5-entry @0x100
# dump 0x140-0x180 (between 5-entry table end and 0x180 palette)
print("0x140-0x180:", data[0x140:0x180].hex())
# where does the 0x180 palette end?
print("0x180-0x1C0:", data[0x180:0x1C0].hex())
print("0x1C0-0x200:", data[0x1C0:0x200].hex())
# check 0x200 region structure
print("\n0x200-0x240:", data[0x200:0x240].hex())
# what's the next table after 0x200?
# scan for u32 BE tables in block 0
import struct
for start in range(0x140, 0x1000, 4):
    vals = []
    pos = start
    while pos + 4 <= 0x1000:
        v = struct.unpack_from('>I', data, pos)[0]
        if v > 0x1000 or v == 0xFFFFFFFF:
            break
        vals.append(v)
        pos += 4
    if len(vals) >= 3 and all(vals[i] < vals[i+1] for i in range(len(vals)-1)):
        print(f"  table @0x{start:X}: {len(vals)} entries: {[hex(x) for x in vals[:8]]}")
