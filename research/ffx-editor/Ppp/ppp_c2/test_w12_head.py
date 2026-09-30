import struct, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# TESTE DECISIVO: o primeiro u32 em section+w12 == ParameterOffset (lo do +4)?
# Se sim: +0xC aponta para um header de node/chain cujo campo 0 = tamanho do
# record do handler — CONFIRMA a semantica do +4 como largura nativa.
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

pcount = struct.unpack_from("<H", D, root + 6)[0]
t1 = struct.unpack_from("<I", D, root + 16)[0]
sections = [struct.unpack_from("<I", D, root + t1 + 4 * i)[0] for i in range(pcount)]

rows = []
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
            a4 = struct.unpack_from("<I", D, sa + 4)[0]
            a8 = struct.unpack_from("<I", D, sa + 8)[0]
            a12 = struct.unpack_from("<I", D, sa + 12)[0]
            lo = a4 & 0xFFFF
            # primeiro u32 na regiao apontada por +12 (rel. section)
            head = struct.unpack_from("<I", D, sec + a12)[0] if sec + a12 + 4 <= len(D) else -1
            rows.append((lo, a12, head))
        if n == 0:
            break
        prog = s + n

ok = sum(1 for lo, a12, head in rows if head == lo)
print(f"w12[0:4] == ParameterOffset: {ok}/{len(rows)}")
print("exemplos (lo, w12, w12[0]):")
for lo, a12, head in rows[:18]:
    print(f"  lo={lo:#x} w12={a12:#x} head={head:#x} match={head==lo}")

# Distribuicao de w12[0] quando NAO bate
from collections import Counter
no = Counter(head for lo, a12, head in rows if head != lo)
print("w12[0] quando nao bate:", dict(no.most_common(8)))
