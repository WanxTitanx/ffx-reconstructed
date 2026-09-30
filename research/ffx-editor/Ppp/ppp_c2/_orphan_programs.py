import struct, sys, json
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Analise de programas orfaos: quantos programs existem vs quantos sao referenciados
# por slots (a2+8 = rel do record). Programas nao referenciados = candidatos a
# reutilizacao para variantes (caminho B do C3).

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

# walker (mesmo do parser)
root = None
for off in range(0, len(D) - 64, 4):
    tag = struct.unpack_from("<I", D, off)[0]
    if tag in (0x31, 0x32, 0x33) and 1 <= struct.unpack_from("<H", D, off + 6)[0] <= 64:
        root = off
        break
pcount = struct.unpack_from("<H", D, root + 6)[0]
t1 = struct.unpack_from("<I", D, root + 16)[0]
sections = [struct.unpack_from("<I", D, root + t1 + 4 * i)[0] for i in range(pcount)]

programs = []  # (sec_idx, prog_rel)
referenced = set()  # (sec_idx, prog_rel) dos records usados por slots
slot_counts = {}
for si, srel in enumerate(sections):
    s = root + srel
    prog = s + 16
    vis = set()
    while True:
        prel = prog - s
        if prel in vis or prog + 40 > len(D):
            break
        vis.add(prel)
        programs.append((si, prel))
        n = struct.unpack_from("<i", D, prog)[0]
        sc = struct.unpack_from("<h", D, prog + 38)[0]
        if sc < 0 or sc > 256:
            break
        cnt = 0
        for k in range(sc):
            sa = prog + 40 + 16 * k
            if sa + 16 > len(D):
                break
            a8 = struct.unpack_from("<I", D, sa + 8)[0]
            # record relativo ao section
            rec_abs = s + a8
            # qual programa contem rec_abs?
            for pi, (psi, pprel) in enumerate(programs):
                pstart = root + sections[psi] + 16 + pprel
                pend = pstart + abs(struct.unpack_from("<i", D, root + sections[psi] + 16 + pprel)[0] or 40)
                if pstart <= rec_abs < pstart + 200:
                    referenced.add((psi, pprel))
                    break
            cnt += 1
        slot_counts[(si, prel)] = cnt
        if n == 0:
            break
        prog = s + n

orphans = [p for p in programs if p not in referenced]
print(f"Programas totais: {len(programs)}")
print(f"Programas referenciados por slots: {len(referenced)}")
print(f"PROGRAMAS ORFAOS: {len(orphans)}")
for p in orphans[:20]:
    print("  sec", p[0], "rel", hex(p[1]))
