import struct, sys
from collections import Counter
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Validacao independente do fuzz EditFuzz_0098_Onda1Families (GOAL 8h Onda 6):
# confirma que as familias novas (Rand 6/7/9B, KeHmgEff, DrawFilter, EiWindFun,
# NeiPointLight, KeMdlTfdUv3) EXISTEM no 0098 com records editaveis (janela provada).

data = open(r"F:/ffx-reconstructed/extras/magicFiles/FFX/magic_0098.dll", "rb").read()
pe = struct.unpack_from("<I", data, 0x3C)[0]
coff = pe + 4
num = struct.unpack_from("<H", data, coff + 2)[0]
opt = struct.unpack_from("<H", data, coff + 16)[0]
st = coff + 20 + opt
dp = None
for i in range(num):
    so = st + i * 40
    nm = bytes(data[so:so + 8]).rstrip(b"\x00")
    if nm == b".data":
        dp = struct.unpack_from("<I", data, so + 20)[0]

ONDA1 = {
    "pppRandChar": (4, 6), "pppRandShort": (4, 7), "pppRandInt": (4, 9), "pppRandCV": (4, 9),
    "pppKeHmgEff": (4, 12), "pppDrawFilter": (12, 24), "pppEiWindFun": (16, 36),
    "pppNeiPointLight": (4, 12), "pppKeMdlTfdUv3": (4, 57),
}
H2OP = {0: "pppAccele", 1: "pppAngAccele", 2: "pppSclAccele", 3: "pppColAccele", 4: "pppMove",
        5: "pppAngMove", 6: "pppSclMove", 7: "pppColMove", 8: "pppPoint", 9: "pppAngle",
        10: "pppScale", 11: "pppColor", 12: "pppRandFV", 13: "pppRandUpFV", 14: "pppRandDownFV",
        15: "pppRandIV", 16: "pppSRandFV", 17: "pppSRandUpFV", 18: "pppSRandDownFV", 19: "pppSMatrix",
        20: "pppMatrixXYZ", 21: "pppMatrixYXZ", 22: "pppMatrixScl", 23: "pppParMatrix", 24: "pppDrawMatrix",
        25: "pppDrawMatrixFront", 26: "pppDrawMdl", 27: "pppDrawMdl2", 28: "pppDrawMdlSemi2", 29: "pppDrawMdlTs2",
        30: "pppDrawShape", 31: "pppKeShpTail2", 32: "pppVertexAp", 33: "pppVertexApLc", 34: "pppKeBornRnd5"}

def walk():
    slots = []
    for off in range(0, len(data) - dp - 64, 4):
        tag = struct.unpack_from("<I", data, dp + off)[0]
        cnt = struct.unpack_from("<H", data, dp + off + 6)[0]
        if tag in (0x31, 0x32, 0x33) and 1 <= cnt <= 64:
            root = off
            break
    pcount = struct.unpack_from("<H", data, dp + root + 6)[0]
    t1 = struct.unpack_from("<I", data, dp + root + 16)[0]
    sections = [struct.unpack_from("<I", data, dp + root + t1 + 4 * i)[0] for i in range(pcount)]
    for srel in sections:
        s = root + srel
        prog = s + 16
        vis = set()
        while True:
            prel = prog - s
            if prel in vis or dp + prog + 40 > len(data):
                break
            vis.add(prel)
            n = struct.unpack_from("<i", data, dp + prog)[0]
            sc = struct.unpack_from("<h", data, dp + prog + 38)[0]
            if sc < 0 or sc > 256:
                break
            for si in range(sc):
                sa = dp + prog + 40 + 16 * si
                h = struct.unpack_from("<I", data, sa)[0]
                a8 = struct.unpack_from("<I", data, sa + 8)[0]
                rec = dp + s + a8
                op = H2OP.get(h)
                if op and op in ONDA1 and rec + 0x40 <= len(data):
                    win_start, win_width = ONDA1[op]
                    edit_off = win_start if win_start >= 8 else win_start + 4
                    if edit_off + 4 <= win_start + win_width:
                        slots.append((op, rec, win_start, win_width, edit_off))
            if n == 0:
                break
            prog = s + n
    return slots

slots = walk()
c = Counter(s[0] for s in slots)
print(f"slots Onda 1 no 0098: {len(slots)}")
for op in ONDA1:
    print(f"  {op:20s} janela {ONDA1[op][0]}+{ONDA1[op][1]:2d}B -> {c.get(op, 0)} slots editaveis")

edit_ok = sum(1 for s in slots if s[4] + 4 <= s[2] + s[3])
print(f"\ntotal slots com campo editavel (offset>=8, 4B): {edit_ok}")
print("VALIDACAO OK: familias Onda 1 presentes e editaveis no 0098" if edit_ok >= 10 else "INSUFICIENTE")
