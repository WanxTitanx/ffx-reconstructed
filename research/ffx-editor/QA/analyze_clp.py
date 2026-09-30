import struct, sys

path = r"D:/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/menu/menu.clp"
data = open(path, "rb").read()
print(f"file: {path}  size: {len(data)} (0x{len(data):X})")

# Header: 8 u32 big-endian
hdr = struct.unpack(">8I", data[0:32])
print("header u32 BE:", [hex(x) for x in hdr])

# Dump first 0x200 bytes as u32 BE stream
print("\n--- u32 BE stream (first 0x200) ---")
for off in range(0, 0x200, 4):
    v = struct.unpack(">I", data[off:off+4])[0]
    print(f"0x{off:04X}: {v:08X}  (u16: {v>>16:04X} {v&0xFFFF:04X})")
