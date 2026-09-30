import struct, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# RE offline: header do program (40B) — o que são +8..+36 além de next(+0)/key(+4)/slot_count(+38)?
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

# Caminha os programs e dumpar os headers
prog = sec + 16
vis = set()
progs = []
while True:
    prel = prog - sec
    if prel in vis:
        break
    vis.add(prel)
    n = struct.unpack_from("<i", D, prog)[0]
    sc = struct.unpack_from("<h", D, prog + 38)[0]
    if sc < 0 or sc > 256:
        break
    hdr = D[prog:prog + 40]
    progs.append((prog, hdr))
    if n == 0:
        break
    prog = sec + n

print(f"{len(progs)} programs")
for prog, hdr in progs[:6]:
    words = struct.unpack_from("<10I", D, prog)
    print(f"\nprogram @{prog:#x} (rel sec {prog-sec:#x}):")
    print(f"  +0 next={words[0]:#x}  +4 key={words[1]:#x}  +8={words[2]:#x} +12={words[3]:#x}")
    print(f"  +16={words[4]:#x} +20={words[5]:#x} +24={words[6]:#x} +28={words[7]:#x}")
    print(f"  +32={words[8]:#x} +36={words[9]:#x} +38 slot_count={struct.unpack_from('<h',D,prog+38)[0]}")
    # O que existe em section+w8, section+w12...?
    for off, label in ((2, "+8"), (3, "+12"), (4, "+16"), (5, "+20")):
        w = words[off]
        if w == 0 or w >= 0x40000:
            continue
        dst = sec + w
        if dst + 12 <= len(D):
            print(f"    {label}={w:#x} -> {dst:#x}: {D[dst:dst+12].hex(' ')}")
