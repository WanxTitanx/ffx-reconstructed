import struct, sys
from collections import Counter
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Validacao cross-DLL da descoberta do +4 (2026-08-02):
# 0021: ParameterOffset (u16 baixo) 100% deterministico por handler.
# Aqui: 0098/0086/0087 — o mesmo handler index tem o MESMO ParameterOffset?
# Se sim, o mapeamento handler->largura e GLOBAL (nao por efeito).

def walk(path):
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
    root_candidates = []
    # varredura de candidatos a root: tag 0x31/0x32/0x33 + counts plausiveis
    for off in range(0, len(D) - 64, 4):
        tag = struct.unpack_from("<I", D, off)[0]
        if tag not in (0x31, 0x32, 0x33):
            continue
        pc = struct.unpack_from("<H", D, off + 6)[0]
        if not (1 <= pc <= 64):
            continue
        root_candidates.append(off)
        if len(root_candidates) > 3:
            break
    rows = []
    for root in root_candidates:
        pcount = struct.unpack_from("<H", D, root + 6)[0]
        t1 = struct.unpack_from("<I", D, root + 16)[0]
        if t1 >= len(D) - root:
            continue
        sections = []
        ok = True
        for i in range(pcount):
            r = struct.unpack_from("<I", D, root + t1 + 4 * i)[0]
            if r >= len(D) - root:
                ok = False
                break
            sections.append(r)
        if not ok:
            continue
        for srel in sections:
            s = root + srel
            if s + 56 > len(D):
                continue
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
                    a4 = struct.unpack_from("<I", D, sa + 4)[0]
                    rows.append((h, a4 & 0xFFFF, (a4 >> 16) & 0xFFFF))
                if n == 0:
                    break
                prog = s + n
    return rows

for dll in ["magic_0098.dll", "magic_0086.dll", "magic_0087.dll"]:
    rows = walk(rf"F:/ffx-reconstructed/extras/magicFiles/FFX/{dll}")
    by_h = {}
    for h, lo, hi in rows:
        by_h.setdefault(h, Counter())[lo] += 1
    multi = {h: dict(c) for h, c in by_h.items() if len(c) > 1}
    his = sorted({hi for _, _, hi in rows})
    print(f"{dll}: {len(rows)} slots, {len(by_h)} handlers, handlers com lo MULTIPLO: {len(multi)}")
    if multi:
        for h, c in list(multi.items())[:5]:
            print(f"    h={h}: {c}")
    print(f"    Flags (hi) vistos: {his}")
