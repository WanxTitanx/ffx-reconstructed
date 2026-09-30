import struct, os

ROOT = r"D:\FFX Extracted\FFX\ffx_ps2\ffx\master\jppc\btlmap"

def u16(b, o): return struct.unpack_from('<H', b, o)[0]
def i16(b, o):
    v = u16(b, o); return v - 0x10000 if v >= 0x8000 else v
def u32(b, o): return struct.unpack_from('<I', b, o)[0]

def analyze(path):
    b = open(path, 'rb').read()
    if len(b) < 0x80 or b[0:4] != b'MAP1': return None
    meta = u32(b, 0x38)
    if meta <= 0 or meta >= len(b): return None
    disp_rel = u32(b, meta + 0x1C)
    disp_abs = meta + disp_rel
    if disp_rel <= 0 or disp_abs + 8 > len(b): return None
    entries = []
    pos = disp_abs
    for i in range(256):
        if pos + 8 > len(b): break
        key = u16(b, pos); tag = u16(b, pos+2); blob = u32(b, pos+4)
        if key == 0 and tag == 0 and blob == 0: break
        entries.append((key, tag, blob))
        pos += 8
    # Analyze each blob at meta+blobOff
    results = []
    for (key, tag, blob_off) in entries:
        blob_abs = meta + blob_off
        if blob_abs < 0 or blob_abs >= len(b): continue
        # Check for s16 sentinel (0x0080, -2)
        sentinel_found = False
        for off in range(blob_abs, min(blob_abs+4096, len(b)-4), 2):
            if i16(b, off) == 0x0080 and i16(b, off+2) == -2:
                sentinel_found = True
                break
        # Check if data looks like triangle indices (all values < 4096, no sentinel)
        vals = [u16(b, blob_abs + 2*i) for i in range(min(64, (len(b)-blob_abs)//2))]
        maxv = max(vals) if vals else 0
        minv = min(vals) if vals else 0
        results.append((key, tag, blob_off, sentinel_found, maxv, minv))
    return results

rows = []
for dirpath, dirs, files in os.walk(ROOT):
    for f in files:
        if f.lower() == 'mapout.vpa':
            p = os.path.join(dirpath, f)
            rel = p.replace(ROOT, '').lstrip('/\\')
            res = analyze(p)
            if res is None:
                rows.append((rel, 'NO-DISPATCH', ''))
            else:
                sent = sum(1 for r in res if r[3])
                tags = ','.join(f"0x{r[1]:04X}" for r in res[:8])
                maxv = max((r[4] for r in res), default=0)
                rows.append((rel, f'{len(res)} entries, {sent} sentinel, maxidx={maxv}', tags))

rows.sort(key=lambda r: r[1])
for r in rows:
    print(f"{r[0]:40s} {r[1]:45s} tags={r[2]}")
