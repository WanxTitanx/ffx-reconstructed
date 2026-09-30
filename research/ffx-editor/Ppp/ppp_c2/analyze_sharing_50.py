import struct, sys, glob, os
from collections import Counter
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Record sharing em 50 DLLs: quantas têm records apontados por 2+ slots (compartilhados)
# e quantas têm conteudo duplicado (copias byte-identicas em offsets diferentes)?

def analyze(path):
    try:
        data = open(path, "rb").read()
    except Exception:
        return None
    if len(data) < 0x1000:
        return None
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if pe + 24 > len(data):
        return None
    coff = pe + 4
    num = struct.unpack_from("<H", data, coff + 2)[0]
    opt = struct.unpack_from("<H", data, coff + 16)[0]
    st = coff + 20 + opt
    dp = None
    for i in range(min(num, 20)):
        so = st + i * 40
        if so + 8 > len(data):
            break
        nm = data[so:so + 8].rstrip(b"\x00")
        if nm in (b".data", b"DATA"):
            dp = struct.unpack_from("<I", data, so + 20)[0]
    if dp is None:
        return None
    D = data[dp:]
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
    if t1 + 4 * pcount > len(D) - root:
        return None
    by_off = Counter()
    by_sha = Counter()
    for i in range(pcount):
        r = struct.unpack_from("<I", D, root + t1 + 4 * i)[0]
        if r >= len(D) - root:
            continue
        s = root + r
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
                if sa + 12 > len(D):
                    break
                a8 = struct.unpack_from("<I", D, sa + 8)[0]
                rec = s + a8
                if rec + 32 > len(D):
                    continue
                by_off[rec] += 1
                by_sha[D[rec:rec + 32]] += 1
            if n == 0:
                break
            prog = s + n
    return len(by_off), sum(1 for v in by_off.values() if v > 1), len(by_sha), sum(1 for v in by_sha.values() if v > 1)

files = sorted(glob.glob(r"F:/ffx-reconstructed/extras/magicFiles/FFX/magic_*.dll"))[::12][:50]
n_shared = n_dup = n_ok = 0
worst = []
for f in files:
    r = analyze(f)
    if r is None:
        continue
    n_ok += 1
    n_rec, sh_off, n_sha, sh_sha = r
    if sh_off:
        n_shared += 1
    if sh_sha:
        n_dup += 1
    worst.append((sh_sha, sh_off, os.path.basename(f), n_rec))
worst.sort(reverse=True)
print(f"analisadas: {n_ok}/50")
print(f"DLLs com offset compartilhado (2+ slots -> MESMO record): {n_shared}")
print(f"DLLs com conteudo duplicado (copias byte-identicas): {n_dup}")
print("top duplicacao:")
for sh_sha, sh_off, name, n_rec in worst[:8]:
    print(f"  {name}: {n_rec} records, {sh_sha} copias duplicadas, {sh_off} offsets compartilhados")
