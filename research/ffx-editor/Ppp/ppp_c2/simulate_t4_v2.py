import struct, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

path = r"F:/ffx-reconstructed/extras/magicFiles/FFX/magic_0098.dll"
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

def f32(rec, off):
    return struct.unpack_from("<f", D, rec + off)[0]

def i32(rec, off):
    return struct.unpack_from("<i", D, rec + off)[0]

def sim_double(delta, frames=60):
    a = b = 0.0
    out = []
    for _ in range(frames):
        b += delta
        a += b
        out.append(a)
    return out

def sim_single(delta, frames=60):
    a = 0.0
    out = []
    for _ in range(frames):
        a += delta
        out.append(a)
    return out

for name, rec, model in [("SclMove 0x1C0F0", 0x1C0F0, "double"), ("Scale 0x1C1D0", 0x1C1D0, "single")]:
    vals = [f32(rec, 0x10 + k * 4) for k in range(4)]
    sim = sim_double if model == "double" else sim_single
    orig = sim(vals[0])
    mut = sim(vals[0] * 2.0)
    ratio = mut[-1] / orig[-1] if orig[-1] else 0
    print(f"{name}: X={vals[0]:.4f} Y={vals[1]:.4f} Z={vals[2]:.4f} W={vals[3]:.4f} | f59: {orig[-1]:.1f} -> {mut[-1]:.1f} ({ratio:.2f}x)")

rec = 0x19A30
vals = [i32(rec, 0x10 + k * 4) for k in range(4)]
orig = sim_double(float(vals[1]))
mut = sim_double(float(vals[1]) * 2.0)
ratio = mut[-1] / orig[-1] if orig[-1] else 0
print(f"AngAccele 0x19A30: X={vals[0]} Y={vals[1]} Z={vals[2]} W={vals[3]} (int32 graus) | f59: {orig[-1]:.1f} -> {mut[-1]:.1f} graus ({ratio:.2f}x)")
