import struct, sys, glob, os, json
from collections import Counter
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Cobertura COMPLETA do corpus (2026-08-02): 581 DLLs.
# Coleta: handlers usados, larguras nativas (ParameterOffset), indices globais.

def analyze(path):
    try:
        data = open(path, "rb").read()
    except Exception:
        return None
    if len(data) < 0x1000:
        return None
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    if pe + 24 > len(data):
        return None
    coff = pe + 4
    num = struct.unpack_from("<H", data, coff + 2)[0]
    opt = struct.unpack_from("<H", data, coff + 16)[0]
    st = coff + 20 + opt
    dp = None
    for i in range(min(num, 20)):
        so = st + i * 40
        if so + 8 > len(data):
            break
        nm = data[so:so + 8].rstrip(b"\x00")
        if nm in (b".data", b"DATA"):
            dp = struct.unpack_from("<I", data, so + 20)[0]
    if dp is None:
        return None
    D = data[dp:]
    root = None
    for off in range(0, min(len(D) - 64, 0x40000), 4):
        tag = struct.unpack_from("<I", D, off)[0]
        if tag in (0x31, 0x32, 0x33) and 1 <= struct.unpack_from("<H", D, off + 6)[0] <= 64:
            root = off
            break
    if root is None:
        return None
    pcount = struct.unpack_from("<H", D, root + 6)[0]
    t1 = struct.unpack_from("<I", D, root + 16)[0]
    if t1 + 4 * pcount > len(D) - root:
        return None
    handlers = Counter()
    widths = Counter()
    for i in range(pcount):
        r = struct.unpack_from("<I", D, root + t1 + 4 * i)[0]
        if r >= len(D) - root:
            continue
        s = root + r
        prog = s + 16
        vis = set()
        while True:
            prel = prog - s
            if prel in vis or prog + 40 > len(D) or prog < 0:
                break
            vis.add(prel)
            n = struct.unpack_from("<i", D, prog)[0]
            sc = struct.unpack_from("<h", D, prog + 38)[0]
            if sc < 0 or sc > 256:
                break
            for si in range(sc):
                sa = prog + 40 + 16 * si
                if sa + 12 > len(D) or sa < 0:
                    break
                h = struct.unpack_from("<I", D, sa)[0]
                a4 = struct.unpack_from("<I", D, sa + 4)[0]
                lo = a4 & 0xFFFF
                if h <= 255:
                    handlers[h] += 1
                if 0 < lo <= 4096:
                    widths[lo] += 1
            if n == 0:
                break
            prog = s + n
    return handlers, widths

all_h = Counter()
all_w = Counter()
n_ok = 0
n_fail = 0
per_dll = {}
files = sorted(glob.glob(r"F:/ffx-reconstructed/extras/magicFiles/FFX/magic_*.dll"))
for f in files:
    r = analyze(f)
    if r is None:
        n_fail += 1
        continue
    n_ok += 1
    h, w = r
    all_h.update(h)
    all_w.update(w)
    per_dll[os.path.basename(f)] = {"handlers": len(h), "slots": sum(h.values())}

print(f"DLLs analisadas: {n_ok}/{len(files)} (falhas: {n_fail})")
print(f"Slots totais: {sum(all_h.values())}")
print(f"Handlers distintos (indices): {len(all_h)}")
print(f"Larguras nativas distintas: {len(all_w)}")
print("\nHistograma de larguras (ParameterOffset):")
for w, c in sorted(all_w.items()):
    print(f"  {w:5d}B: {c:8d} slots")
print("\nTop 15 handlers (indices):")
for h, c in all_h.most_common(15):
    print(f"  h={h:3d}: {c}")

json.dump({
    "dlls_analisadas": n_ok,
    "dlls_total": len(files),
    "slots_totais": sum(all_h.values()),
    "handlers_distintos": len(all_h),
    "larguras": dict(all_w),
    "top_handlers": [{"handler": h, "slots": c} for h, c in all_h.most_common(20)],
}, open(r"C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/coverage_all_result.json", "w"), indent=1)
print("\ncoverage_all_result.json salvo")
