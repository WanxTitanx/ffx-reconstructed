import struct, os

ROOTS = [r"/home/wanderson/Documents/ffx-editor-main/work/_val_bmsq/corpus_root/ffx/master/jppc/map", r"/home/wanderson/Documents/ffx-editor-main/work/_val_bmsq/corpus_root/ffx/master/jppc/btlmap"]

def u16(b, o): return struct.unpack_from('<H', b, o)[0]
def i16(b, o):
    v = u16(b, o); return v - 0x10000 if v >= 0x8000 else v
def u32(b, o): return struct.unpack_from('<I', b, o)[0]

def find_ring(b, blob_abs, limit=4096):
    """Return number of rings with sentinel (0x0080,0xFFFE) found in blob."""
    rings = 0
    cursor = blob_abs
    end = min(blob_abs + limit, len(b) - 4)
    while cursor + 12 <= end and rings < 16:
        verts = 0
        while cursor + 4 <= len(b):
            a = i16(b, cursor); bb = i16(b, cursor+2)
            if a == 0x0080 and bb == -2:
                cursor += 4
                if verts >= 3: rings += 1
                break
            verts += 1
            cursor += 4
            if verts > 64: break
        if verts > 64: break
    return rings

results = []
for ROOT in ROOTS:
    for dirpath, dirs, files in os.walk(ROOT):
        for f in files:
            if f.lower() == 'mapout.vpa':
                p = os.path.join(dirpath, f)
                b = open(p, 'rb').read()
                rel = p.replace(r"/home/wanderson/Documents/ffx-editor-main/work/_val_bmsq/corpus_root/ffx/master/jppc", '').lstrip('\/')
                if len(b) < 0x80 or b[0:4] != b'MAP1': continue
                meta = u32(b, 0x38); geom = u32(b, 0x18)
                if meta <= 0 or geom <= 0 or meta >= len(b) or geom >= len(b): continue
                disp_rel = u32(b, meta + 0x1C)
                disp_abs = meta + disp_rel
                if disp_rel <= 0 or disp_abs + 8 > len(b): continue
                pos = disp_abs
                best_geom = best_meta = 0
                for i in range(64):
                    if pos + 8 > len(b): break
                    key = u16(b, pos); tag = u16(b, pos+2); blob = u32(b, pos+4)
                    if key == 0 and tag == 0 and blob == 0: break
                    if tag in (0x0019, 0x0071, 0x0004):
                        g = find_ring(b, geom + blob)
                        m = find_ring(b, meta + blob)
                        best_geom = max(best_geom, g)
                        best_meta = max(best_meta, m)
                    if 0x0020 <= tag <= 0x0040 and key >= 0x0020: break
                    pos += 8
                if best_geom or best_meta:
                    results.append((rel, best_geom, best_meta))

results.sort(key=lambda r: -max(r[1], r[2]))
print(f"Files with rings: {len(results)}")
print(f"{'file':45s} {'geom+off':>8s} {'meta+off':>8s}")
for rel, g, m in results:
    print(f"{rel:45s} {g:8d} {m:8d}")
