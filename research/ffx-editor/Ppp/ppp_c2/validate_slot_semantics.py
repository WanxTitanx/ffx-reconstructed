import struct, sys, json
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Validacao offline da semantica do slot 16B (descoberta do dispatcher 0x7170F0):
#   +0  = handler_table_index (u32)
#   +4  = argument_relative (u32 — varia por slot)
#   +8  = primary_callback_relative (rel. SECTION)
#   +12 = secondary_callback_relative (rel. SECTION)
# Hipoteses a testar no corpus (0021):
#   H1: +8 aponta para um record valido (inicio de um callback record)
#   H2: +12 aponta para o MESMO record ou para outra estrutura (counted table?)
#   H3: +4 contém um valor pequeno (0x04..0x20) — ponteiro? indice? flag?
# 2026-08-02, Jarvis-PPP-C2C3.

path = r"F:/ffx-reconstructed/extras/magicFiles/FFX/magic_0021.dll"
data = open(path, "rb").read()

# PE: achar .data
pe = struct.unpack_from("<I", data, 0x3C)[0]
coff = pe + 4
num = struct.unpack_from("<H", data, coff + 2)[0]
opt = struct.unpack_from("<H", data, coff + 16)[0]
st = coff + 20 + opt
data_ptr = data_size = None
for i in range(num):
    so = st + i * 40
    name = data[so:so + 8].rstrip(b"\0")
    vsz = struct.unpack_from("<I", data, so + 8)[0]
    rsz = struct.unpack_from("<I", data, so + 16)[0]
    rp = struct.unpack_from("<I", data, so + 20)[0]
    if name in (b".data", b"DATA"):
        data_ptr, data_size = rp, rsz
print(f".data: ptr={data_ptr:#x} size={data_size:#x}")

D = data[data_ptr:data_ptr + data_size]

# Root do 0021 = 0x18B30 (do PARSER_SPEC). Sections, programs, slots via walker simplificado.
root = 0x18B30
pcount = struct.unpack_from("<H", D, root + 6)[0]
t1 = struct.unpack_from("<I", D, root + 16)[0]
sections = [struct.unpack_from("<I", D, root + t1 + 4 * i)[0] for i in range(pcount)]

slots_all = []
for srel in sections:
    sec = root + srel
    sec_size = struct.unpack_from("<I", D, sec)[0]
    rel8 = struct.unpack_from("<i", D, sec + 8)[0]
    rel12 = struct.unpack_from("<i", D, sec + 12)[0]
    prog = sec + 16
    visited = set()
    while True:
        prel = prog - sec
        if prel in visited:
            break
        visited.add(prel)
        n = struct.unpack_from("<i", D, prog)[0]
        sc = struct.unpack_from("<h", D, prog + 38)[0]
        if sc < 0 or sc > 256:
            break
        for si in range(sc):
            sabs = prog + 40 + 16 * si
            h = struct.unpack_from("<I", D, sabs)[0]
            a4 = struct.unpack_from("<I", D, sabs + 4)[0]
            a8 = struct.unpack_from("<I", D, sabs + 8)[0]
            a12 = struct.unpack_from("<I", D, sabs + 12)[0]
            slots_all.append({"abs": sabs, "handler": h, "w4": a4, "w8": a8, "w12": a12,
                              "sec": sec, "sec_size": sec_size, "rel8": rel8, "rel12": rel12})
        if n == 0:
            break
        prog = sec + n

print(f"total slots: {len(slots_all)}")

# H1: +8 aponta para um byte que parece inicio de record (handler/type pequeno?)
ok8 = sum(1 for s in slots_all if 0 < s["w8"] < s["sec_size"])
print(f"H1: slots com +8 dentro da section: {ok8}/{len(slots_all)}")

# H2: +12 — o que aponta?
w12_vals = {}
for s in slots_all:
    w12_vals.setdefault(s["w12"], []).append(s["abs"])
print(f"H2: valores unicos de +12: {len(w12_vals)}")
for v, abses in sorted(w12_vals.items())[:10]:
    print(f"    +12={v:#x} ({len(abses)} slots, ex. abs {abses[0]:#x})")

# +12 coincide com rel8/rel12 (counted tables) ou com records (+8)?
rel8_set = {s["rel8"] for s in slots_all}
rel12_set = {s["rel12"] for s in slots_all}
w12_set = set(w12_vals)
print(f"    rel8 usado: {sorted(rel8_set)}, rel12: {sorted(rel12_set)}")
print(f"    +12 coincide com rel8: {bool(w12_set & rel8_set)}, com rel12: {bool(w12_set & rel12_set)}")

# H3: distribuição de +4
w4_hist = {}
for s in slots_all:
    w4_hist[s["w4"]] = w4_hist.get(s["w4"], 0) + 1
print(f"H3: valores unicos de +4: {len(w4_hist)} — top:")
for v, c in sorted(w4_hist.items(), key=lambda kv: -kv[1])[:12]:
    print(f"    +4={v:#x} ({c} slots)")

# +12 vs +8: +12 aponta para o mesmo record de +8? (mesma base sec)
same = sum(1 for s in slots_all if s["w8"] == s["w12"])
print(f"slots onde +8 == +12: {same}")
