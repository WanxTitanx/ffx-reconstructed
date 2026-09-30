import struct

path = r"/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/menu/menu.clp"
data = open(path, "rb").read()
print(f"size: {len(data)} (0x{len(data):X})")

# Scan for runs of u32 BE values that are small (< 0x4000) and non-decreasing -> offset tables
print("\n--- candidate offset tables (u32 BE, non-decreasing, < 0x4000) ---")
for off in range(0, len(data) - 4, 4):
    vals = []
    o = off
    while o + 4 <= len(data):
        v = struct.unpack(">I", data[o:o+4])[0]
        if v >= 0x4000:
            break
        if vals and v < vals[-1]:
            break
        vals.append(v)
        o += 4
    if len(vals) >= 4:
        print(f"0x{off:04X}: {len(vals)} vals: {[hex(v) for v in vals[:12]]}{'...' if len(vals)>12 else ''}")
