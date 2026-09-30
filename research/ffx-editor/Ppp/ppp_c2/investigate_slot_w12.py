import struct, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Investiga o +0xC do slot (valores unicos pequenos): o que existe em section+w12?
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
sec_size = struct.unpack_from("<I", D, sec)[0]
print("section abs:", hex(sec), "size:", hex(sec_size))

# Coleta todos os +12 dos slots
pcount = struct.unpack_from("<H", D, root + 6)[0]
t1 = struct.unpack_from("<I", D, root + 16)[0]
sections = [struct.unpack_from("<I", D, root + t1 + 4 * i)[0] for i in range(pcount)]
w12s = []
for srel in sections:
    s = root + srel
    prog = s + 16
    vis = set()
    while True:
        prel = prog - s
        if prel in vis:
            break
        vis.add(prel)
        n = struct.unpack_from("<i", D, prog)[0]
        sc = struct.unpack_from("<h", D, prog + 38)[0]
        if sc < 0 or sc > 256:
            break
        for si in range(sc):
            sa = prog + 40 + 16 * si
            w12s.append(struct.unpack_from("<I", D, sa + 12)[0])
        if n == 0:
            break
        prog = s + n

print("total +12:", len(w12s), "unicos:", len(set(w12s)))
print("menor:", min(w12s), "maior:", max(w12s))

# Dump das 5 primeiras regioes apontadas (+12 como rel. section)
for w12 in sorted(set(w12s))[:6]:
    a = sec + w12
    if a + 48 <= len(D):
        b = D[a:a + 48]
        print(f"\nsection+{w12:#x} (abs {a:#x}):")
        for r in range(0, 48, 16):
            print(f"  {r:02x}: {b[r:r+16].hex(' ')}")
