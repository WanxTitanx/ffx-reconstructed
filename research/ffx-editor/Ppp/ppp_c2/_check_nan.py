import struct, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

data = open(r"F:/ffx-reconstructed/extras/magicFiles/FFX/magic_0098.dll", "rb").read()
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
rec = 0x19A30
for k in range(4):
    off = rec + 0x10 + 4 * k
    raw = struct.unpack_from("<I", D, off)[0]
    fv = struct.unpack_from("<f", D, off)[0]
    print(f"AngAccele +0x{0x10 + 4 * k:02X}: u32={raw:#010x} f32={fv!r}")
