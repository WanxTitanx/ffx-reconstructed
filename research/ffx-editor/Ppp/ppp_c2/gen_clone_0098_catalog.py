import json, struct, sys
from pathlib import Path

sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 4 GOAL 8h (2026-08-02, Jarvis-MAGIC) — Catalogo de knobs editaveis do clone 0098.
# Lista TODOS os slots U1 (janela +0x10..+0x1F) com opcode, record, valores atuais e
# sugestao de mutacao — a "superficie de edicao" do clone Death Custom (C3 Caminho A).

SRC = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX\magic_0098.dll")
data = SRC.read_bytes()

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
D = data[dp:]

# fp.h do 0098 (MagicKnownEffectHandlers)
H2OP = {0: "pppAccele", 1: "pppAngAccele", 2: "pppSclAccele", 3: "pppColAccele", 4: "pppMove",
        5: "pppAngMove", 6: "pppSclMove", 7: "pppColMove", 8: "pppPoint", 9: "pppAngle",
        10: "pppScale", 11: "pppColor", 12: "pppRandFV", 13: "pppRandUpFV", 14: "pppRandDownFV",
        15: "pppRandIV", 16: "pppSRandFV", 17: "pppSRandUpFV", 18: "pppSRandDownFV", 19: "pppSMatrix",
        20: "pppMatrixXYZ", 21: "pppMatrixYXZ", 22: "pppMatrixScl", 23: "pppParMatrix", 24: "pppDrawMatrix",
        25: "pppDrawMatrixFront", 26: "pppDrawMdl", 27: "pppDrawMdl2", 28: "pppDrawMdlSemi2", 29: "pppDrawMdlTs2",
        30: "pppDrawShape", 31: "pppKeShpTail2", 32: "pppVertexAp", 33: "pppVertexApLc", 34: "pppKeBornRnd5"}

U1 = {"pppSclMove", "pppSclAccele", "pppAccele", "pppMove", "pppAngAccele", "pppScale", "pppAngle", "pppPoint", "pppAngMove"}

def walk():
    slots = []
    for off in range(0, len(D) - 64, 4):
        tag = struct.unpack_from("<I", D, off)[0]
        if tag in (0x31, 0x32, 0x33) and 1 <= struct.unpack_from("<H", D, off + 6)[0] <= 64:
            root = off
            break
    pcount = struct.unpack_from("<H", D, root + 6)[0]
    t1 = struct.unpack_from("<I", D, root + 16)[0]
    sections = [struct.unpack_from("<I", D, root + t1 + 4 * i)[0] for i in range(pcount)]
    for srel in sections:
        s = root + srel
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
                a8 = struct.unpack_from("<I", D, sa + 8)[0]
                rec = s + a8
                slots.append((h, rec))
            if n == 0:
                break
            prog = s + n
    return slots

slots = walk()
knobs = []
for h, rec in slots:
    op = H2OP.get(h)
    if op not in U1:
        continue
    if rec + 0x20 > len(D):
        continue
    vals = [struct.unpack_from("<f", D, rec + 0x10 + 4 * k)[0] for k in range(4)]
    ints = [struct.unpack_from("<i", D, rec + 0x10 + 4 * k)[0] for k in range(4)]
    knob = {"opcode": op, "handler": h, "record": hex(rec),
            "f32": [round(v, 4) for v in vals],
            "int32": ints,
            "sugestao_mutacao": "X(+0x10) x2" if op not in ("pppAngle", "pppAngMove", "pppAngAccele") else "Y(+0x14) x2"}
    knobs.append(knob)

out = {"dll": "magic_0098.dll", "effect": "Death", "total_slots_ppp": len(slots),
       "knobs_u1": len(knobs), "knobs": knobs,
       "nota": "Catalogo gerado pelo parser C#-equivalente (walker Python); a verdade de parse e o editor C# (581/581 RT0).",
       "generated": "2026-08-02", "lane": "Jarvis-MAGIC"}
p = Path(r"work\_t4_prep\clone_0098_knob_catalog.json")
p.write_text(json.dumps(out, ensure_ascii=False, indent=1), encoding="utf-8")

from collections import Counter
c = Counter(k["opcode"] for k in knobs)
print(f"slots PPP totais: {len(slots)} | knobs U1: {len(knobs)}")
print("por familia:", dict(c))
print(f"catalogo: {p}")
