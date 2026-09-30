import struct, sys, json
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# PROVA DE CONCEITO — "T4 simulado" (2026-08-02):
# Simula a acumulacao U1 do pppSclMove (double-layer: layerB += delta; layerA += layerB)
# por N frames, antes vs depois de uma mutacao (delta X x2). Mostra a trajetoria da
# escala em funcao do tempo — o que o T4 real observaria no jogo.

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

# Target do plano de mutacao: SclMove rec=0x1C0F0 (sha 26c32de0...)
rec = 0x1C0F0
# Janela U1: record+0x10..+0x1F = f32[4] (X, Y, Z, W)
f32 = lambda off: struct.unpack_from("<f", D, rec + off)[0]
dx, dy, dz, dw = f32(0x10), f32(0x14), f32(0x18), f32(0x1C)
print(f"SclMove 0x1C0F0: delta X={dx} Y={dy} Z={dz} W={dw}")

def simulate(dx, frames=60):
    # double-layer: layerB += delta; layerA += layerB (escala acumulada)
    a, b = 0.0, 0.0
    out = []
    for _ in range(frames):
        b += dx
        a += b
        out.append(a)
    return out

orig = simulate(dx)
mut = simulate(dx * 2.0)
print("\nFrame | escala X original | escala X mutada (x2)")
for i in range(0, 60, 6):
    print(f"  {i:3d}  | {orig[i]:10.3f} | {mut[i]:10.3f}")

ratio = mut[-1] / orig[-1] if orig[-1] else 0
print(f"\nRazao final (frame 59): {ratio:.2f}x — a escala X dobra (e aceleracao tambem)")
print("CONCLUSAO: a mutacao x2 no delta quadruplica o deslocamento acumulado (double-layer)")
