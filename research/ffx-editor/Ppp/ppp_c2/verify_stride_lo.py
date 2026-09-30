import struct, sys
from collections import Counter
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# TESTE DECISIVO: o record do slot SEGUINTE (mesmo programa) começa em record+lo?
# Se sim, lo (u16 baixo do +4) = TAMANHO REAL DO RECORD (stride de callback).
# 2026-08-02, Jarvis-PPP-C2C3.

data = open(r"F:/ffx-reconstructed/extras/magicFiles/FFX/magic_0021.dll", "rb").read()
pe = struct.unpack_from("<I", data, 0x3C)[0]
coff = pe + 4
num = struct.unpack_from("<H", data, coff + 2)[0]
opt = struct.unpack_from("<H", data, coff + 16)[0]
st = coff + 20 + opt
dp = ds = None
for i in range(num):
    so = st + i * 40
    nm = data[so:so + 8].rstrip(b"\x00")
    if nm in (b".data", b"DATA"):
        dp = struct.unpack_from("<I", data, so + 20)[0]
        ds = struct.unpack_from("<I", data, so + 16)[0]
D = data[dp:dp + ds]
root = 0x18B30
pcount = struct.unpack_from("<H", D, root + 6)[0]
t1 = struct.unpack_from("<I", D, root + 16)[0]
sections = [struct.unpack_from("<I", D, root + t1 + 4 * i)[0] for i in range(pcount)]

# Coleta slots com: handler, +4 (hi/lo), +8 (record rel), program index
progs = []
for srel in sections:
    sec = root + srel
    ssize = struct.unpack_from("<I", D, sec)[0]
    prog = sec + 16
    vis = set()
    pi = 0
    while True:
        prel = prog - sec
        if prel in vis:
            break
        vis.add(prel)
        n = struct.unpack_from("<i", D, prog)[0]
        sc = struct.unpack_from("<h", D, prog + 38)[0]
        if sc < 0 or sc > 256:
            break
        slots = []
        for si in range(sc):
            sa = prog + 40 + 16 * si
            h = struct.unpack_from("<I", D, sa)[0]
            a4 = struct.unpack_from("<I", D, sa + 4)[0]
            a8 = struct.unpack_from("<I", D, sa + 8)[0]
            lo = a4 & 0xFFFF
            hi = (a4 >> 16) & 0xFFFF
            slots.append({"abs": sa, "h": h, "hi": hi, "lo": lo, "rec": a8})
        progs.append((pi, slots))
        pi += 1
        if n == 0:
            break
        prog = sec + n

# Para cada programa: slots ordenados por record. O stride real entre records
# consecutivos deve ser lo[i] se lo = tamanho do record.
total = 0
ok = 0
mismatches = []
for pi, slots in progs:
    ss = sorted(slots, key=lambda s: s["rec"])
    for i in range(len(ss) - 1):
        stride = ss[i + 1]["rec"] - ss[i]["rec"]
        if stride <= 0 or stride > 4096:
            continue
        total += 1
        if stride == ss[i]["lo"]:
            ok += 1
        else:
            mismatches.append((pi, ss[i]["abs"], ss[i]["h"], ss[i]["lo"], stride))

print(f"STRIDE lo==proximo record: {ok}/{total}")
print("mismatches (program, slot, handler, lo, stride_real):")
for m in mismatches[:20]:
    print(f"  {m}")

# Também: distribuição de lo por handler
lo_by_h = {}
for pi, slots in progs:
    for s in slots:
        lo_by_h.setdefault(s["h"], Counter())[s["lo"]] += 1
print("\nhandler -> lo:")
for h, c in sorted(lo_by_h.items()):
    print(f"  h={h:3d}: {dict(c)}")
