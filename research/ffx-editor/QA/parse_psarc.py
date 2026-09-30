import struct
p = "/tmp/test_sdk.psarc"
d = open(p, "rb").read()
print("size", len(d))
print("magic", d[:4])
print("major_minor", d[4:8].hex())
print("compression", d[8:12])
print("start_of_data", struct.unpack("<I", d[0x0C:0x10])[0])
print("size_of_entry", struct.unpack("<I", d[0x10:0x14])[0])
print("files_count", struct.unpack("<I", d[0x14:0x18])[0])
print("block_size", struct.unpack("<I", d[0x18:0x1C])[0])
print("zero", struct.unpack("<I", d[0x1C:0x20])[0])
e0 = d[0x20:0x20+30]
print("entry0 hex", e0.hex())
