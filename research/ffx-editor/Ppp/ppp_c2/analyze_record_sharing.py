import struct, sys
from collections import Counter
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Record sharing: quantos slots apontam para o MESMO record (mesmo SHA/offset)?
# 0021 vs 0098 — o 0098 mostrou records duplicados (mesmo SHA em offsets diferentes);
# aqui medimos: (a) slots por record_offset, (b) offsets duplicados por conteudo (SHA).

def analyze(path):
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
        if tag not in (0x31, 0x32, 0x33):
            continue
        pc = struct.unpack_from("<H", D, off + 6)[0]
        if 1 <= pc <= 64:
            root = off
            break
    if root is None:
        return None
    pcount = struct.unpack_from("<H", D, root + 6)[0]
    t1 = struct.unpack_from("<I", D, root + 16)[0]
    sections = [struct.unpack_from("<I", D, root + t1 + 4 * i)[0] for i in range(pcount)]
    by_off = Counter()
    by_sha = Counter()
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
                a8 = struct.unpack_from("<I", D, sa + 8)[0]
                rec = s + a8
                by_off[rec] += 1
                blob = D[rec:rec + 32]
                by_sha[blob] += 1
            if n == 0:
                break
            prog = s + n
    shared_off = {k: v for k, v in by_off.items() if v > 1}
    shared_sha = {k: v for k, v in by_sha.items() if v > 1}
    return len(by_off), len(shared_off), len(by_sha), len(shared_sha)

for dll in ["magic_0021.dll", "magic_0098.dll"]:
    r = analyze(rf"F:/ffx-reconstructed/extras/magicFiles/FFX/{dll}")
    if r:
        n_off, sh_off, n_sha, sh_sha = r
        print(f"{dll}: {n_off} records unicos por offset | {sh_off} offsets compartilhados (2+ slots) | {n_sha} conteudos unicos | {sh_sha} conteudos duplicados")
