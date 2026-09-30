import re

data = open('D:/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/menu/menu.clp', 'rb').read()
# find ASCII runs
runs = re.findall(rb'[\x20-\x7e]{4,}', data)
print(f"ASCII runs in jppc/menu/menu.clp ({len(data)}B):")
for r in runs[:40]:
    print(f"  @0x{data.find(r):04X}: {r.decode('ascii')}")

# compare with uspc
import os
uspc = 'D:/FFX Extracted/FFX/ffx_ps2/ffx/master/uspc/menu/menu.clp'
if os.path.exists(uspc):
    d2 = open(uspc, 'rb').read()
    print(f"\nuspc/menu/menu.clp: {len(d2)}B, identical={d2==data}")
    # find differing regions
    diffs = [i for i in range(min(len(data),len(d2))) if data[i]!=d2[i]]
    if diffs:
        # group into ranges
        ranges = []
        start = prev = diffs[0]
        for d in diffs[1:]:
            if d - prev > 1:
                ranges.append((start, prev))
                start = d
            prev = d
        ranges.append((start, prev))
        print(f"  diff ranges ({len(ranges)}): {[(hex(a),hex(b)) for a,b in ranges[:20]]}")
