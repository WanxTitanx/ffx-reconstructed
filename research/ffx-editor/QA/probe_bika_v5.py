#!/usr/bin/env python3
# probe_bika_v5.py - valida a heuristica de fallback por similaridade de blocos (estilo rsync)
# que sera implementada no EncounterIndexBridge C#. Para cada battle unmatched, escolhe
# o 0e/ com MAIOR fração de blocos de 256B compartilhados (>= limiar). Aqui: probe bika02_00.
import glob, os, sys
sys.stdout.reconfigure(encoding="utf-8")

BTL_ROOT = r"D:\FFX Extracted\FFX\ffx_ps2\ffx\master\jppc\battle\btl"
NOCLIP0E = r"C:\Users\wande\Downloads\Compressed\noclip.website-39605028765aa2cfaf2cea175f01f3a77cd99c2e\noclip.website-39605028765aa2cfaf2cea175f01f3a77cd99c2e\data\FinalFantasyX\0e"

BLOCK = 256
MIN_SCORE = 0.50

def fnv(b, off, n):
    h = 2166136261
    for i in range(off, off + n):
        h ^= b[i]
        h = (h * 16777619) & 0xFFFFFFFF
    return h

def blocks(b):
    s = set()
    for off in range(0, len(b) - BLOCK, BLOCK):
        s.add(fnv(b, off, BLOCK))
    return s

def decode2(b, off):
    return b[off] | (b[off + 1] << 8)

PROBE = "bika02_00"
a = open(os.path.join(BTL_ROOT, PROBE, PROBE + ".bin"), "rb").read()
a_blocks = blocks(a)

# indice: blocoHash -> [fileIndex]
enc_blocks = {}   # fi -> set de hashes
enc_ids = []
block_index = {}
for f in sorted(glob.glob(os.path.join(NOCLIP0E, "*.bin"))):
    with open(f, "rb") as fh:
        b = fh.read()
    fi = len(enc_ids)
    enc_ids.append(os.path.basename(f))
    s = blocks(b)
    enc_blocks[fi] = s
    for h in s:
        block_index.setdefault(h, []).append(fi)

total = len(a_blocks)
scores = {}
for h in a_blocks:
    for fi in block_index.get(h, []):
        scores[fi] = scores.get(fi, 0) + 1

best = sorted(scores.items(), key=lambda kv: -kv[1])[:10]
print(f"{PROBE}.bin  blocos_unicos={total}")
print("top candidatos por fracao de blocos compartilhados:")
for fi, cnt in best:
    score = cnt / total
    name = enc_ids[fi]
    # diff real byte-a-byte
    bb = open(os.path.join(NOCLIP0E, name), "rb").read()
    d = sum(1 for i in range(min(len(a), len(bb))) if a[i] != bb[i]) if len(a) == len(bb) else -1
    print(f"  {name:10} score={score:.2f} (blocos {cnt}/{total}) byte_diff={'%d (%.2f%%)' % (d, 100.0*d/len(a)) if d>=0 else 'n/a'}")

# escolha segundo a heuristica
fi0, cnt0 = best[0] if best else (-1, 0)
score0 = cnt0 / total if total else 0.0
chosen = best[0][0] if best and score0 >= MIN_SCORE else -1
print("\nESCOLHA da heuristica (limiar %.2f):" % MIN_SCORE)
if chosen >= 0:
    print(f"  {PROBE} -> {enc_ids[chosen]} (score={score0:.2f})")
else:
    print(f"  (nenhum candidato acima do limiar; manteria SEM MATCH)")

# contagem global de quantos unmatched ganhariam fallback por este metodo
print("\nvarredura global (unmatched -> candidato de menor score):")
import hashlib
enc_by_hash = {}
for f in sorted(glob.glob(os.path.join(NOCLIP0E, "*.bin"))):
    with open(f, "rb") as fh:
        enc_by_hash.setdefault(hashlib.sha256(fh.read()).hexdigest(), os.path.basename(f))

# reusar block_index global pronto
unmatched_fixed = 0
unmatched_total = 0
for d in sorted(os.listdir(BTL_ROOT)):
    binp = os.path.join(BTL_ROOT, d, d + ".bin")
    if not os.path.isfile(binp):
        continue
    with open(binp, "rb") as fh:
        bb = fh.read()
    h = hashlib.sha256(bb).hexdigest()
    if h in enc_by_hash:
        continue  # ja tem match exato
    unmatched_total += 1
    ab = blocks(bb)
    tt = len(ab)
    sc = {}
    for hh in ab:
        for fi in block_index.get(hh, []):
            sc[fi] = sc.get(fi, 0) + 1
    if not sc:
        continue
    fii, c = max(sc.items(), key=lambda kv: kv[1])
    if tt and c / tt >= MIN_SCORE:
        unmatched_fixed += 1
print(f"  unmatched={unmatched_total}  ->  com fallback>=limiar: {unmatched_fixed}")
print(f"  (fracao que passou a abrir: {100.0*unmatched_fixed/max(1,unmatched_total):.1f}%)")