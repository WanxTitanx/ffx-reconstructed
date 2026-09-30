import struct, os, sys

ROOT = r"/home/wanderson/Documents/ffx-editor-main/work/_val_bmsq/corpus_root/ffx/master/jppc/btlmap"

def u16(b, o): return b[o] | (b[o+1] << 8)
def i16(b, o):
    v = u16(b, o); return v - 0x10000 if v >= 0x8000 else v
def u32(b, o): return b[o] | (b[o+1] << 8) | (b[o+2] << 16) | (b[o+3] << 24)

def classify(path):
    b = open(path, 'rb').read()
    if len(b) < 0x84:
        return (len(b), 0, 0, 0, 0, 0)
    geom = u32(b, 0x18)
    meta = u32(b, 0x38)
    ecmagic = u32(b, 0x80)
    ec84 = u32(b, 0x84)
    ec88 = u32(b, 0x88)
    ec8c = u32(b, 0x8C)
    ec90 = u32(b, 0x90)
    # meta block dispatch
    dispatch = 0
    if 0 < meta < len(b) - 4:
        dispatch = u32(b, meta + 0x1C)
    return (len(b), geom, meta, ecmagic, ec84, dispatch)

rows = []
for dirpath, dirs, files in os.walk(ROOT):
    for f in files:
        if f.lower() == 'mapout.vpa':
            p = os.path.join(dirpath, f)
            rows.append((p.replace(ROOT, '').lstrip('\/'),) + classify(p))

rows.sort(key=lambda r: r[1])
print(f"{'file':40s} {'size':>9s} {'geom':>8s} {'meta':>8s} {'ec!':>10s} {'ec84':>6s} {'disp':>8s}")
for r in rows:
    print(f"{r[0]:40s} {r[1]:9d} 0x{r[2]:06X} 0x{r[3]:06X} 0x{r[4]:08X} 0x{r[5]:04X} 0x{r[6]:06X}")
