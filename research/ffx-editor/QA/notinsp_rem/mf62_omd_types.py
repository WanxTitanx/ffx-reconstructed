#!/usr/bin/env python3
# M-F62 adjudication: legacy claims 106 enc_*.omd, same 0x20B header, types 7 (61 files,
# size 448B, packed1=0x80006, packed2=0x880006) vs 3 (45 files, size 384B, packed1=0x60005,
# packed2=0x880005). Verify by direct corpus scan (file sizes + u32 scan for packed marks).
import struct, collections
from pathlib import Path
root = Path("/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/yonishi_data/dat_et/encount/rsd")
files = sorted(root.glob("enc_*.omd"))
print("count:", len(files))
sizes = collections.Counter()
typecount = collections.Counter()
detail = []
for f in files:
    d = f.read_bytes()
    sizes[len(d)] += 1
    # locate packed constants anywhere in first 0x40 bytes (claim: section1 extra fields +0x04..+0x0F)
    t = None
    for off in range(0, min(len(d), 0x40) - 3):
        v = struct.unpack_from("<I", d, off)[0]
        if v == 0x80006:
            t = 7; break
        if v == 0x60005:
            t = 3; break
    typecount[t] += 1
    detail.append((f.name, len(d), t))
for name, sz, t in detail:
    print(f"{name} size={sz} type={t}")
print("\n=== SIZES ==="); [print(f"{v:3d} x {k}B") for k, v in sorted(sizes.items())]
print("=== TYPES (by packed mark) ==="); [print(f"{v:3d} x type {k}") for k, v in sorted(typecount.items(), key=lambda x: (x[0] is None, x[0]))]
# cross: type7 should all be 448B, type3 all 384B
mismatch = [(n, s, t) for n, s, t in detail if (t == 7 and s != 448) or (t == 3 and s != 384)]
print("size/type mismatches:", mismatch if mismatch else "NONE (61x type7=448B / 45x type3=384B expected)")
