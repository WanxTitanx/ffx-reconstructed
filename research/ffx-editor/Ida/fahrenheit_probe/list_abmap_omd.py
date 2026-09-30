#!/usr/bin/env python3
"""Lista os .omd do eiichi_abmap_data (modelos do sphere grid)."""
import os
import sys

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
root = r"F:\ffx_ps2\ffx\eiichi_abmap_data"
omds = []
for dp, dn, fn in os.walk(root):
    for f in fn:
        if f.lower().endswith(".omd"):
            p = os.path.join(dp, f)
            omds.append((os.path.relpath(p, root), os.path.getsize(p)))
print(f"TOTAL omd: {len(omds)}")
for p, sz in sorted(omds):
    print(f"  {p}  {sz}")
