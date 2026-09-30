import struct, sys, json
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# SIMULADOR U1 COMPLETO do magic_0098 (2026-08-02):
# Interpreta TODOS os slots U1 (janela 16B em record+0x10..+0x1F) com os 3 modelos:
#   double-layer (SclMove/SclAccele/Accele/Move/AngAccele): layerB += delta; layerA += layerB
#   single-layer (Scale/Angle/Point): layerA += delta
#   loop (AngMoveLoop/AngleLoop): delta reaplicado (mesmo modelo single com reset opcional)
# Gera por frame (60): escala X/Y/Z acumulada (todos os SclMove/Scale somados), posicao (Move),
# angulo (Ang* em graus, int32). Compara antes/depois de mutar SclMove 0x1C0F0 (delta x2).

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

# fp.h do 0098: handler -> opcode (do parser C#)
H2OP = {1: "pppAngAccele", 6: "pppSclMove", 9: "pppAngle", 10: "pppScale"}

# Walk: roots -> sections -> programs -> slots
def walk():
    slots = []
    root = None
    for off in range(0, len(D) - 64, 4):
        tag = struct.unpack_from("<I", D, off)[0]
        if tag in (0x31, 0x32, 0x33) and 1 <= struct.unpack_from("<H", D, off + 6)[0] <= 64:
            root = off
            break
    pcount = struct.unpack_from("<H", D, root + 6)[0]
    t1 = struct.unpack_from("<I", D, root + 16)[0]
    sections = [struct.unpack_from("<I", D, root + t1 + 4 * i)[0] for i in range(pcount)]
    for srel in sections:
        s = root + srel
        prog = s + 16
        vis = set()
        while True:
            prel = prog - s
            if prel in vis or prog + 40 > len(D):
                break
            vis.add(prel)
            n = struct.unpack_from("<i", D, prog)[0]
            sc = struct.unpack_from("<h", D, prog + 38)[0]
            if sc < 0 or sc > 256:
                break
            for si in range(sc):
                sa = prog + 40 + 16 * si
                if sa + 16 > len(D):
                    break
                h = struct.unpack_from("<I", D, sa)[0]
                a8 = struct.unpack_from("<I", D, sa + 8)[0]
                rec = s + a8
                slots.append((h, rec))
            if n == 0:
                break
            prog = s + n
    return slots

slots = walk()

def u1_fields(rec, as_int=False):
    """4 valores da janela U1 (record+0x10..+0x1F); as_int = int32 (ângulos)."""
    fmt = "<i" if as_int else "<f"
    return [struct.unpack_from(fmt, D, rec + 0x10 + 4 * k)[0] for k in range(4)]

DOUBLE = {"pppSclMove", "pppSclAccele", "pppAccele", "pppMove", "pppAngAccele"}
SINGLE = {"pppScale", "pppAngle", "pppPoint"}

def simulate(mutate_rec=None, mutate_scale=1.0, frames=60):
    scale = [0.0, 0.0, 0.0]
    pos = [0.0, 0.0, 0.0]
    ang = [0.0, 0.0, 0.0]
    layers = {}
    out = []
    for f in range(frames):
        for h, rec in slots:
            op = H2OP.get(h)
            if op not in DOUBLE and op not in SINGLE:
                continue
            vals = u1_fields(rec, as_int=op.startswith("pppAng"))
            mult = mutate_scale if rec == mutate_rec else 1.0
            d = [v * mult for v in vals]
            key = (h, rec)
            # eixo principal por família: X para escala/posição, Y para ângulos (mira)
            axis = 1 if op.startswith("pppAng") else 0
            dv = d[axis]
            if op in DOUBLE:
                b, a = layers.get(key, (0.0, 0.0))
                b += dv
                a += b
                layers[key] = (b, a)
                acc = a
            else:
                acc = dv
            if op in ("pppSclMove", "pppSclAccele", "pppScale"):
                scale[0] += acc
                scale[1] += d[1] if op == "pppSclMove" else acc
                scale[2] += d[2]
            elif op == "pppMove":
                pos[0] += acc
                pos[1] += d[1]
                pos[2] += d[2]
            elif op.startswith("pppAng"):
                ang[axis] += acc
        out.append((scale[0], scale[1], scale[2], pos[0], ang[1]))
    return out

orig = simulate()
mut = simulate(mutate_rec=0x1C0F0, mutate_scale=2.0)

print("Frame | escala X orig | escala X mut | pos X orig | ang Y orig (graus)")
for i in range(0, 60, 6):
    print(f" {i:3d}  | {orig[i][0]:11.2f} | {mut[i][0]:11.2f} | {orig[i][3]:9.2f} | {orig[i][4]:9.2f}")

ratio = mut[-1][0] / orig[-1][0] if orig[-1][0] else 0
print(f"\nRazao final escala X: {ratio:.2f}x (mutacao x2 no SclMove 0x1C0F0)")
print(f"Escala total no frame 59: orig={orig[-1][0]:.1f} mut={mut[-1][0]:.1f}")
print(f"Posicao X frame 59: orig={orig[-1][3]:.1f} | Angulo Y frame 59: orig={orig[-1][4]:.1f} graus")
