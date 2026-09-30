import struct, sys
from collections import Counter
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Correlacao handler <-> (classe, arg_offset) no slot +4 do 0021. 2026-08-02.
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
print("data_ptr:", hex(dp), "size:", hex(ds))

D = data[dp:dp + ds]
root = 0x18B30
pcount = struct.unpack_from("<H", D, root + 6)[0]
t1 = struct.unpack_from("<I", D, root + 16)[0]
sections = [struct.unpack_from("<I", D, root + t1 + 4 * i)[0] for i in range(pcount)]

rows = []
for srel in sections:
    sec = root + srel
    ssize = struct.unpack_from("<I", D, sec)[0]
    prog = sec + 16
    vis = set()
    while True:
        prel = prog - sec
        if prel in vis:
            break
        vis.add(prel)
        n = struct.unpack_from("<i", D, prog)[0]
        sc = struct.unpack_from("<h", D, prog + 38)[0]
        if sc < 0 or sc > 256:
            break
        for si in range(sc):
            sa = prog + 40 + 16 * si
            h = struct.unpack_from("<I", D, sa)[0]
            a4 = struct.unpack_from("<I", D, sa + 4)[0]
            hi = (a4 >> 16) & 0xFFFF
            lo = a4 & 0xFFFF
            rows.append((h, hi, lo, sa))
        if n == 0:
            break
        prog = sec + n

print(f"total slots: {len(rows)}")
cls_by_handler = {}
for h, hi, lo, sa in rows:
    cls_by_handler.setdefault(h, Counter())[hi] += 1
print("handler -> classes (byte_hi do +4):")
for h, c in sorted(cls_by_handler.items()):
    print(f"  handler {h:3d}: {dict(c)}")

lo_by_cls = {}
for h, hi, lo, sa in rows:
    lo_by_cls.setdefault(hi, Counter())[lo] += 1
print("\nclasse -> arg offsets (byte_lo do +4):")
for cls, c in sorted(lo_by_cls.items()):
    print(f"  classe {cls}: {dict(c)}")

# Verificar se byte_lo corresponde a offset de um campo real no record:
# para o primeiro slot de cada (handler, classe, lo), ver o que existe em record+lo.
print("\nExemplos (handler, classe, lo, slot_abs):")
for h, hi, lo, sa in rows[:14]:
    print(f"  h={h:3d} classe={hi} arg_off={lo:#x} slot={sa:#x}")
