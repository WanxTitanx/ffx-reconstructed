import struct, os

ROOTS = [r"D:\FFX Extracted\FFX\ffx_ps2\ffx\master\jppc\map", r"D:\FFX Extracted\FFX\ffx_ps2\ffx\master\jppc\btlmap"]

def u16(b, o): return struct.unpack_from('<H', b, o)[0]
def i16(b, o):
    v = u16(b, o); return v - 0x10000 if v >= 0x8000 else v
def u32(b, o): return struct.unpack_from('<I', b, o)[0]

def editor_parse(b):
    """Replicate MapoutVpa_EncounterZones.ParseBytes logic."""
    if len(b) < 4 or b[0:4] != b'MAP1': return 'badmagic'
    if len(b) <= 128: return 'stub'
    meta = u32(b, 0x38); geom = u32(b, 0x18)
    if meta <= 0 or meta >= len(b) or geom <= 0 or geom >= len(b): return 'nometa'
    disp_rel = u32(b, meta + 0x1C)
    disp_abs = meta + disp_rel
    if disp_rel <= 0 or disp_abs + 8 > len(b): return 'nodispatch'
    entries = []
    pos = disp_abs
    for i in range(128):
        if pos + 8 > len(b): break
        key = u16(b, pos); tag = u16(b, pos+2); blob = u32(b, pos+4)
        if key == 0 and tag == 0 and blob == 0: break
        if tag in (0x0019, 0x0071, 0x0004):
            entries.append((key, tag, blob))
        if 0x0020 <= tag <= 0x0040 and key >= 0x0020: break
        pos += 8
    zones = 0
    for (key, tag, blob_off) in entries:
        blob_abs = geom + blob_off
        if blob_abs < 0 or blob_abs >= len(b): continue
        polys = extract_polys(b, blob_abs)
        polys = [p for p in polys if 3 <= len(p) <= 32]
        if polys: zones += 1
    return f'{zones}'

def extract_polys(b, blob_abs):
    polys = []
    cursor = blob_abs
    end = min(blob_abs + 2048, len(b) - 4)
    while cursor + 12 <= end and len(polys) < 16:
        verts = []
        while cursor + 4 <= len(b):
            a = i16(b, cursor); bb = i16(b, cursor+2)
            if a == 0x0080 and bb == -2:
                cursor += 4; break
            verts.append((a, bb))
            cursor += 4
            if len(verts) > 64: break
        if len(verts) < 3: break
        polys.append(verts)
    return polys

from collections import Counter
stats = Counter()
ok_files = []
for ROOT in ROOTS:
    for dirpath, dirs, files in os.walk(ROOT):
        for f in files:
            if f.lower() == 'mapout.vpa':
                p = os.path.join(dirpath, f)
                b = open(p, 'rb').read()
                rel = p.replace(r"D:\FFX Extracted\FFX\ffx_ps2\ffx\master\jppc", '').lstrip('/\\')
                r = editor_parse(b)
                stats[r] += 1
                if r not in ('0',):
                    ok_files.append((rel, r))

print("=== Corpus stats (491 files) ===")
for k, v in sorted(stats.items()):
    print(f"  {k}: {v}")
print("\n=== Files with zones ===")
for rel, r in sorted(ok_files):
    print(f"  {rel}: {r} zones")
