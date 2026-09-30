import sys, struct
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

base = r"F:/ffx-reconstructed/extras/magicFiles/FFX"
for f in ["magic_0053.dll", "magic_0065.dll", "magic_0709.dll"]:
    d = open(base + "/" + f, "rb").read()
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    coff = pe + 4
    num = struct.unpack_from("<H", d, coff + 2)[0]
    opt = struct.unpack_from("<H", d, coff + 16)[0]
    st = coff + 20 + opt
    dp = None
    for i in range(num):
        so = st + i * 40
        nm = d[so:so + 8].rstrip(b"\x00")
        if nm in (b".data", b"DATA"):
            dp = struct.unpack_from("<I", d, so + 20)[0]
            vs = struct.unpack_from("<I", d, so + 8)[0]
            rs = struct.unpack_from("<I", d, so + 16)[0]
    D = d[dp:dp + rs]
    print("===", f, "data offset", hex(dp), "vsize", hex(vs), "raw", hex(rs))
    # todos os tags no raw
    for o in range(0, len(D) - 64, 4):
        tag = struct.unpack_from("<I", D, o)[0]
        if tag in (0x31, 0x32, 0x33):
            cnt = struct.unpack_from("<H", D, o + 6)[0]
            t1 = struct.unpack_from("<I", D, o + 16)[0]
            print(f"  tag {tag:#x} @ raw+{o:#x} count={cnt} t1_rel={t1:#x} u8[4]={D[o+4]} u16[6]={cnt} u32[8]={struct.unpack_from('<I',D,o+8)[0]:#x}")
