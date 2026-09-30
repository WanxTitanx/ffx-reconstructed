import struct, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Dump completo do primeiro node (+12) do 0021.
path = r"F:/ffx-reconstructed/extras/magicFiles/FFX/magic_0021.dll"
data = open(path, "rb").read()
pe = struct.unpack_from("<I", data, 0x3C)[0]
coff = pe + 4
num = struct.unpack_from("<H", data, coff + 2)[0]
opt = struct.unpack_from("<H", data, coff + 16)[0]
st = coff + 20 + opt
dp = None
for i in range(num):
    so = st + i * 40
    nm = data[so:so + 8].rstrip(b"\x00")
    if nm in (b".data", b"DATA"):
        dp = struct.unpack_from("<I", data, so + 20)[0]
D = data[dp:]
root = 0x18B30
sec = root + 0x40
prog = sec + 16
sa = prog + 40
a12 = struct.unpack_from("<I", D, sa + 12)[0]
print("slot1 +12:", hex(a12))
node = sec + a12
size = struct.unpack_from("<I", D, node)[0]
print(f"node em {node:#x} size={size:#x} ({size})")
b = D[node:node + min(size, 128)]
for r in range(0, len(b), 16):
    print(f"{r:04x}: {b[r:r + 16].hex(' ')}")
