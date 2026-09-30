import struct, os

ROOT = r"D:\FFX Extracted\FFX\ffx_ps2\ffx\master\jppc\btlmap"

def u32(b, o): return struct.unpack_from('<I', b, o)[0]

rows = []
for dirpath, dirs, files in os.walk(ROOT):
    for f in files:
        if f.lower() == 'mapout.vpa':
            p = os.path.join(dirpath, f)
            b = open(p, 'rb').read()
            if len(b) < 0xC0: continue
            rel = p.replace(ROOT, '').lstrip('/\\')
            ec = [u32(b, 0x80 + 4*i) for i in range(14)]
            rows.append((rel, ec))

# Group by ec[0..5] signature
from collections import defaultdict
groups = defaultdict(list)
for rel, ec in rows:
    sig = tuple(ec[0:6])
    groups[sig].append((rel, ec))

print(f"Total files: {len(rows)}, distinct eC! signatures: {len(groups)}")
for sig, files in sorted(groups.items(), key=lambda x: -len(x[1])):
    print(f"\n=== sig {[hex(s) for s in sig]} ({len(files)} files) ===")
    for rel, ec in files[:6]:
        print(f"  {rel}: ec={[hex(x) for x in ec[:6]]} ...")
    if len(files) > 6:
        print(f"  ... and {len(files)-6} more")
