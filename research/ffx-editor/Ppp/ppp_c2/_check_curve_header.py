import struct, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Verifica se as curvas dos programs (0021) tem header u16 de 'end' antes do array
# (formato Curve do noclip: end = u16 + streamOffs).
path = r"F:/ffx-reconstructed/extras/magicFiles/FFX/magic_0021.dll"
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
root = 0x18B30
sec = root + 0x40

for target, label in [(0x14000, "prog1 +20"), (0x1A000, "prog1 +16"), (0x11000, "prog6 +20"), (0xE000, "prog6 +16")]:
    a = sec + target
    hdr = D[a - 8:a + 16]
    print(f"{label}: sec+{target:#x} = {a:#x}")
    print(f"  antes (8B): {hdr[:8].hex(' ')}")
    print(f"  inicio   : {hdr[8:].hex(' ')}")
