import struct, sys, json
from collections import Counter
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Duplicatas de programas + cross-refs de records no 0098 (caminho B C3).
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

root = None
for off in range(0, len(D) - 64, 4):
    tag = struct.unpack_from("<I", D, off)[0]
    if tag in (0x31, 0x32, 0x33) and 1 <= struct.unpack_from("<H", D, off + 6)[0] <= 64:
        root = off
        break
pcount = struct.unpack_from("<H", D, root + 6)[0]
t1 = struct.unpack_from("<I", D, root + 16)[0]
sections = [struct.unpack_from("<I", D, root + t1 + 4 * i)[0] for i in range(pcount)]

progs = []  # (sec_idx, rel, abs_start, n_next, sc, hash)
for si, srel in enumerate(sections):
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
        body = D[prog:prog + 40 + 16 * max(sc, 0)]
        h = hash(body)  # ou md5
        progs.append({"sec": si, "rel": prel, "abs": prog, "n": n, "sc": sc,
                      "hash": hex(h & 0xFFFFFFFF), "len": len(body)})
        if n == 0:
            break
        prog = s + n

# duplicatas por hash
by_hash = {}
for p in progs:
    by_hash.setdefault(p["hash"], []).append(p)
dups = {h: v for h, v in by_hash.items() if len(v) > 1}
print(f"Programas: {len(progs)} | Hashes unicos: {len(by_hash)} | DUPLICATAS: {len(dups)} grupos")
for h, v in list(dups.items())[:8]:
    print(f"  {h}: {[(p['sec'], hex(p['rel']), p['sc'], p['len']) for p in v]}")

# cross-ref: slot +8 aponta para fora do proprio programa?
cross = 0
for p in progs:
    if p["sc"] <= 0:
        continue
    prog = p["abs"]
    for k in range(p["sc"]):
        sa = prog + 40 + 16 * k
        if sa + 16 > len(D):
            break
        a8 = struct.unpack_from("<I", D, sa + 8)[0]
        rec_abs = root + sections[p["sec"]] + a8
        # dentro do proprio programa (header + slots + records)?
        p_end = prog + 40 + 16 * p["sc"]
        if not (p_end <= rec_abs < p_end + 256):
            cross += 1
print(f"Slots com record FORA do bloco de slots do proprio programa: {cross}")
