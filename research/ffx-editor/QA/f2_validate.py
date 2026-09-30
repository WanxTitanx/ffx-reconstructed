#!/usr/bin/env python3
# ── F2 validation: prove the small-RAW-block patch in work/_vbf_reader.py ──
# Lane: FFX-STRUCTURES / MICRO-FIXES (2026-09-14).
# Method: load the PATCHED module (importlib, no copy), extract the 3 proof
# files from FFX2_Data.vbf into /tmp only, and compare byte-identical against
# the on-disk Topher extraction (pairs documented in
# docs/reverse/FFX_FFX2_MATERIAL_SURVEY_2026-09-14.md section 3.4).
import importlib.util, hashlib, os, sys

REPO = "/home/wanderson/Documents/ffx-editor-main"
VBF2 = "/mnt/nvme-samsung/SteamLibrary/steamapps/common/FINAL FANTASY FFX&FFX-2 HD Remaster/data/FFX2_Data.vbf"
DISK_ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX2"

spec = importlib.util.spec_from_file_location("vbf_reader_patched", os.path.join(REPO, "work/_vbf_reader.py"))
mod = importlib.util.module_from_spec(spec)
spec.loader.exec_module(mod)  # module-level demo runs against FFX_Data.vbf (index-only)
print("--- module loaded (demo tail above was the FFX_Data.vbf index) ---")

r = mod.VbfReader(VBF2)

PAIRS = [
    ("version_config/japan.txt", True),
    ("ffx_ps2/ffx2/master/uspc/menu/base.ftc", True),
    ("version_config/northamerica.txt", False),  # no disk pair (Topher .NET path bug); check content+known sha
]

def sha(p):
    h = hashlib.sha256()
    with open(p, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 16), b""):
            h.update(chunk)
    return h.hexdigest()

results = []
for name, has_disk in PAIRS:
    out = "/tmp/_f2_" + name.replace("/", "_")
    ok = r.extract(name, out)
    if not ok:
        results.append((name, "EXTRACT_FAIL", "-"))
        continue
    vs = sha(out)
    if has_disk:
        dp = os.path.join(DISK_ROOT, name)
        ds = sha(dp)
        same = open(out, "rb").read() == open(dp, "rb").read()
        results.append((name, "BYTE-IDENTICAL" if same else "MISMATCH",
                        f"vbf={vs[:16]}... disk={ds[:16]}... size={os.path.getsize(out)}"))
    else:
        content = open(out, "rb").read()
        good = content == b"1:1,2,3" and vs.startswith("43011b9e0c61d894e3a9")
        results.append((name, "CONTENT-OK (1:1,2,3 + sha prefix 43011b9e...)" if good else f"UNEXPECTED {content!r}",
                        f"sha={vs[:16]}... size={os.path.getsize(out)}"))

print("\n=== F2 VALIDATION RESULTS ===")
allok = True
for name, verdict, extra in results:
    bad = verdict not in ("BYTE-IDENTICAL",) and not verdict.startswith("CONTENT-OK")
    allok &= not bad
    print(f"[{'FAIL' if bad else ' OK '}] {name}: {verdict} | {extra}")
sys.exit(0 if allok else 1)
