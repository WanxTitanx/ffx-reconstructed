import struct, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Curvas dos programs (0021): o que +16/+20 apontam — arrays de bytes crescentes.
# Hipótese: timing frame->valor (curva de animação). Verificar comprimentos e padrões.

data = open(r"F:/ffx-reconstructed/extras/magicFiles/FFX/magic_0021.dll", "rb").read()
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
vis = set()
rows = []
while True:
    prel = prog - sec
    if prel in vis:
        break
    vis.add(prel)
    n = struct.unpack_from("<i", D, prog)[0]
    sc = struct.unpack_from("<h", D, prog + 38)[0]
    if sc < 0 or sc > 256:
        break
    words = struct.unpack_from("<10I", D, prog)
    rows.append((prog, words))
    if n == 0:
        break
    prog = sec + n

print(f"{len(rows)} programs")
for prog, w in rows:
    key = w[1]
    c16, c20 = w[4], w[5]
    info = []
    for c, label in ((c16, "+16"), (c20, "+20")):
        if c == 0 or c >= 0x40000:
            info.append(f"{label}=0")
            continue
        dst = sec + c
        # comprimento presumido: até o próximo valor que pareça header (u32 grande)
        arr = D[dst:dst + 256]
        info.append(f"{label}={c:#x}->{dst:#x}: {arr[:12].hex(' ')}...")
    print(f"key={key:#x} next={w[0]:#x}: {' | '.join(info)}")

# Análise: as curvas têm comprimentos fixos? Tamanho das regiões (diff entre starts).
starts = sorted({w[4] for w in rows if 0 < w[4] < 0x40000} | {w[5] for w in rows if 0 < w[5] < 0x40000})
print("\nstarts unicos de curvas:", [hex(s) for s in starts])
for i in range(len(starts) - 1):
    print(f"  {starts[i]:#x} .. {starts[i+1]:#x} = {starts[i+1]-starts[i]} bytes")
