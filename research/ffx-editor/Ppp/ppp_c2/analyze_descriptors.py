import struct, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# RE offline: table2 (descriptors 32B) do 0021 — o que w20/w24/w28 apontam?
# Cadeia draw documentada: pppDrawMdl -> tabela de descritores 32B -> texture cache.
# Correlacionar os descriptors com as keys dos programs draw (0x0254, 0x0F90...).

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

pcount = struct.unpack_from("<H", D, root + 6)[0]
dcount = struct.unpack_from("<H", D, root + 8)[0]
t1 = struct.unpack_from("<I", D, root + 16)[0]
t2 = struct.unpack_from("<I", D, root + 20)[0]
t3 = struct.unpack_from("<I", D, root + 24)[0]
t4 = struct.unpack_from("<I", D, root + 28)[0]
print(f"root={root:#x} sections={pcount} descriptors={dcount} t1={t1:#x} t2={t2:#x} t3={t3:#x} t4={t4:#x}")

print("\n=== DESCRIPTORS (32B) ===")
for i in range(dcount):
    e = root + t2 + 32 * i
    w = struct.unpack_from("<8I", D, e)
    print(f"  desc#{i} @{e:#x}: ptr0={w[0]:#x} ptr4={w[1]:#x} ptr8={w[2]:#x} w12={w[3]:#x} w16={w[4]:#x} w20={w[5]:#x} w24={w[6]:#x} w28={w[7]:#x}")

# O que existe nos destinos de w20/w24/w28?
print("\n=== DESTINOS w20/w24/w28 (rel root) ===")
for i in range(dcount):
    e = root + t2 + 32 * i
    w = struct.unpack_from("<8I", D, e)
    for j, off in ((5, "w20"), (6, "w24"), (7, "w28")):
        if w[j] == 0:
            continue
        dest = root + w[j]
        if dest + 16 <= len(D):
            hdr = D[dest:dest + 16].hex(" ")
            print(f"  desc#{i}.{j} {off}={w[j]:#x} -> {dest:#x}: {hdr}")
