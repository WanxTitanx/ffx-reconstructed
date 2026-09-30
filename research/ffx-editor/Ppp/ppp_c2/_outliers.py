import struct, sys, glob
from collections import Counter
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Varre as DLLs atras de slots com larguras raras (1B..16B atipicas, 17B, 47B, 249B, 4096B)
# e mostra o contexto (handler, arquivo) para decidir se +4 e largura real.

WANT = {1, 5, 9, 10, 11, 13, 14, 17, 19, 21, 47, 60, 67, 75, 95, 100, 149, 249, 250, 256, 4096}

def analyze(path):
    d = open(path, "rb").read()
    if len(d) < 0x1000:
        return None
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    coff = pe + 4
    num = struct.unpack_from("<H", d, coff + 2)[0]
    opt = struct.unpack_from("<H", d, coff + 16)[0]
    st = coff + 20 + opt
    dp = None
    for i in range(min(num, 20)):
        so = st + i * 40
        nm = d[so:so + 8].rstrip(b"\x00")
        if nm in (b".data", b"DATA"):
            dp = struct.unpack_from("<I", d, so + 20)[0]
    if dp is None:
        return None
    D = d[dp:]
    root = None
    for off in range(0, min(len(D) - 64, 0x40000), 4):
        tag = struct.unpack_from("<I", D, off)[0]
        if tag in (0x31, 0x32, 0x33) and 1 <= struct.unpack_from("<H", D, off + 6)[0] <= 64:
            root = off
            break
    if root is None:
        return None
    pcount = struct.unpack_from("<H", D, root + 6)[0]
    t1 = struct.unpack_from("<I", D, root + 16)[0]
    hits = []
    for i in range(pcount):
        ti = root + t1 + 4 * i
        if ti + 4 > len(D):
            break
        r = struct.unpack_from("<I", D, ti)[0]
        if r >= len(D) - root:
            continue
        s = root + r
        prog = s + 16
        vis = set()
        while True:
            prel = prog - s
            if prel in vis or prog + 40 > len(D) or prog < 0:
                break
            vis.add(prel)
            n = struct.unpack_from("<i", D, prog)[0]
            sc = struct.unpack_from("<h", D, prog + 38)[0]
            if sc < 0 or sc > 256:
                break
            for si in range(sc):
                sa = prog + 40 + 16 * si
                if sa + 12 > len(D) or sa < 0:
                    break
                h = struct.unpack_from("<I", D, sa)[0]
                a4 = struct.unpack_from("<I", D, sa + 4)[0]
                lo = a4 & 0xFFFF
                if lo in WANT:
                    hits.append((h, lo, sa + 4 - root))
            if n == 0:
                break
            prog = s + n
    return hits

base = r"F:/ffx-reconstructed/extras/magicFiles/FFX"
found = Counter()
examples = {}
for f in sorted(glob.glob(base + "/magic_*.dll")):
    hs = analyze(f)
    if not hs:
        continue
    for h, w, off in hs[:3]:
        found[(h, w)] += 1
        examples.setdefault((h, w), (f.split("/")[-1], hex(off)))
print("Outliers encontrados (handler, largura):")
for (h, w), c in sorted(found.items(), key=lambda x: -x[1])[:25]:
    ex = examples[(h, w)]
    print(f"  h={h:3d} w={w:5d}B x{c:4d} ex: {ex[0]} @ data+{ex[1]}")
