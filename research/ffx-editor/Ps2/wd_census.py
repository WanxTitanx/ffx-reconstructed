#!/usr/bin/env python3
# ── w21-models-finish W2: census de classificação dos .wd (wave data) ─────────
# Corpus (READ-ORY): ffx/proj/sound/wave/*.wd (+ demais da árvore ffx/).
# Classifica por magic/header e valida o diretório de offsets u32 crescentes
# observado no sniff (smikado.wd: "WD" magic, u16 0x14, header ~0x54 B,
# depois u32s crescentes).
import struct, os, sys, collections

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx"

def u16(d, o): return struct.unpack_from("<H", d, o)[0]
def u32(d, o): return struct.unpack_from("<I", d, o)[0]

def classify(path):
    d = open(path, "rb").read()
    r = {"magic": d[:2].decode("latin1", "replace"), "size": len(d),
         "ver": None, "dir_ok": None, "n_dir": 0}
    if d[:2] != b"WD":
        r["cls"] = "NOT_WD"
        return r
    r["ver"] = u16(d, 2)
    # diretório de offsets: a partir de 0x54 (smikado), u32s estritamente
    # crescentes e < filesize, até quebrar
    off, prev, n = 0x54, 0, 0
    while off + 4 <= len(d):
        v = u32(d, off)
        if v <= prev or v >= len(d):
            break
        prev = v; n += 1; off += 4
    r["n_dir"] = n
    r["dir_ok"] = n >= 4
    r["cls"] = "WD_dir" if r["dir_ok"] else "WD_nodir"
    return r

if __name__ == "__main__":
    root = sys.argv[1] if len(sys.argv) > 1 else ROOT
    files = []
    for dp, _, fns in os.walk(root):
        for fn in fns:
            if fn.lower().endswith(".wd"): files.append(os.path.join(dp, fn))
    files.sort()
    tot = collections.Counter(); vers = collections.Counter()
    nodir, other_dirs = [], collections.Counter()
    for p in files:
        rel = os.path.relpath(p, root)
        r = classify(p)
        tot[r["cls"]] += 1
        if r["cls"].startswith("WD"): vers[r["ver"]] += 1
        if r["cls"] == "WD_nodir" and len(nodir) < 6:
            nodir.append((rel, r["size"]))
        if not rel.startswith("proj/sound/wave/"):
            other_dirs[rel.rsplit("/", 1)[0]] += 1
    print(f"=== WD CENSUS ({len(files)} arquivos sob {root}) ===")
    print("classes:", dict(tot))
    print("u16@2 (versão?) top:", vers.most_common(6))
    print("fora de proj/sound/wave/:", dict(other_dirs))
    if nodir: print("WD sem diretório (exemplos):", nodir)
