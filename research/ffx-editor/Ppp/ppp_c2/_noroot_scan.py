import sys, struct
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

base = r"F:/ffx-reconstructed/extras/magicFiles/FFX"
for f in ["magic_0052.dll", "magic_0053.dll", "magic_0064.dll", "magic_0065.dll", "magic_0709.dll"]:
    d = open(base + "/" + f, "rb").read()
    print("===", f, len(d))
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    coff = pe + 4
    num = struct.unpack_from("<H", d, coff + 2)[0]
    opt = struct.unpack_from("<H", d, coff + 16)[0]
    st = coff + 20 + opt
    for i in range(num):
        so = st + i * 40
        nm = d[so:so + 8].rstrip(b"\x00")
        vs = struct.unpack_from("<I", d, so + 8)[0]
        rs = struct.unpack_from("<I", d, so + 16)[0]
        # procura root tag 0x31/0x32/0x33 no .data
        dp = struct.unpack_from("<I", d, so + 20)[0] if nm in (b".data", b"DATA") else None
        if dp is not None:
            D = d[dp:dp + min(rs, 0x1000)]
            tags = [hex(struct.unpack_from("<I", D, o)[0]) for o in range(0, len(D) - 4, 4) if struct.unpack_from("<I", D, o)[0] in (0x31, 0x32, 0x33)]
            print("  sec", nm, "vsize", hex(vs), "rawsize", hex(rs), "tags31-33 no inicio:", tags[:5])
        else:
            print("  sec", nm, "vsize", hex(vs), "rawsize", hex(rs))
