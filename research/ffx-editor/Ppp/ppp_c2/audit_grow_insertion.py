import struct, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# AUDITORIA DE SEGURANCA DO GROW (2026-08-02):
# O insertion_point do grow = record_abs + RecordWidth (max(32, janela)). Se o record
# do slot tem uma regiao nativa MAIOR (NativeRecordWidth) ou se o insertion cai
# DENTRO do node apontado pelo +12 do slot (cadeia PppMem — nao coberta pelo
# InsertionPointCrossesDerivedStructures), o grow corrompe SILENCIOSAMENTE.
# Este script verifica no 0021 quantos slots teriam o insertion dentro do node.

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

risky = []
ok_slots = 0
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
            rec_abs = s + a8          # record do slot (rel section)
            insert = rec_abs + max(32, lo)  # insertion_point do grow atual
            node_abs = s + a12        # node da cadeia (+12)
            node_size = struct.unpack_from("<I", D, node_abs)[0] if node_abs + 4 <= len(D) else 0
            # node_size plausivel? multiplo de 16 entre 16 e 4096
            plausible = (16 <= node_size <= 4096) and (node_size % 16 == 0)
            in_node = plausible and (node_abs <= insert < node_abs + node_size)
            # insertion dentro do record nativo (lo > RecordWidth max(32,...))?
            in_native = insert < rec_abs + lo
            if in_node or in_native:
                risky.append((sa, a8, lo, rec_abs, insert, node_abs, node_size, plausible, in_node, in_native))
            else:
                ok_slots += 1
        if n == 0:
            break
        prog = s + n

print(f"slots OK (insertion fora do node e fora do nativo): {ok_slots}")
print(f"slots RISCOSOS: {len(risky)}")
for r in risky[:14]:
    sa, a8, lo, rec, ins, node, nsz, pl, in_node, in_nat = r
    print(f"  slot={sa:#x} rec={rec:#x} lo={lo:#x} insert={ins:#x} node={node:#x}(sz={nsz:#x} plausivel={pl}) in_node={in_node} in_native={in_nat}")
