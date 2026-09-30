import struct, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# RE offline: table3 (u32) e table4 (8B) do root — o que contêm?
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
c3 = struct.unpack_from("<H", D, root + 10)[0]
c4 = struct.unpack_from("<H", D, root + 12)[0]
t3 = struct.unpack_from("<I", D, root + 24)[0]
t4 = struct.unpack_from("<I", D, root + 28)[0]
print(f"c3={c3} c4={c4} t3={t3:#x} t4={t4:#x}")
print("TABLE3 (u32, rel root):")
for i in range(c3):
    v = struct.unpack_from("<I", D, root + t3 + 4 * i)[0]
    extra = ""
    if root + v + 8 <= len(D):
        extra = D[root + v:root + v + 8].hex(" ")
    print(f"  [{i}] {v:#x} -> root+{v:#x}: {extra}")
print("TABLE4 (8B, rel root):")
for i in range(c4):
    e = root + t4 + 8 * i
    a, b = struct.unpack_from("<II", D, e)
    print(f"  [{i}] a={a:#x} b={b:#x}")
