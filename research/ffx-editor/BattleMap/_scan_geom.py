import struct, os
from collections import defaultdict

ROOT = r"D:\FFX Extracted\FFX\ffx_ps2\ffx\master\jppc\btlmap"

def u32(b, o): return struct.unpack_from('<I', b, o)[0]
def u16(b, o): return struct.unpack_from('<H', b, o)[0]
def f32(b, o): return struct.unpack_from('<f', b, o)[0]

groups = defaultdict(list)
for dirpath, dirs, files in os.walk(ROOT):
    for f in files:
        if f.lower() == 'mapout.vpa':
            p = os.path.join(dirpath, f)
            b = open(p, 'rb').read()
            rel = p.replace(ROOT, '').lstrip('/\\')
            geom = u32(b, 0x18)
            meta = u32(b, 0x38)
            if geom <= 0 or geom >= len(b):
                groups[('NO-GEOM',)].append((rel, None))
                continue
            g04 = u32(b, geom+4)
            g08 = u32(b, geom+8)
            g0c = f32(b, geom+0xC)
            g18 = u32(b, geom+0x18)
            g1c = u32(b, geom+0x1C)
            sig = (hex(g08), round(g0c,1), hex(g1c))
            groups[sig].append((rel, (g04, g08, g0c, g18, g1c)))

print(f"Distinct geometry signatures: {len(groups)}")
for sig, files in sorted(groups.items(), key=lambda x: -len(x[1])):
    print(f"\n=== {sig} ({len(files)} files) ===")
    for rel, g in files[:8]:
        if g: print(f"  {rel}: +4=0x{g[0]:08X} +8=0x{g[1]:08X} +C={g[2]:.1f} +18=0x{g[3]:X} +1C=0x{g[4]:X}")
        else: print(f"  {rel}: NO-GEOM")
    if len(files) > 8: print(f"  ... and {len(files)-8} more")
