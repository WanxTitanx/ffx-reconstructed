# -*- coding: utf-8 -*-
"""Exibe as 32 entries nomeadas da keyhole dispatch table."""
import json

d = json.load(open(r"C:\Users\wande\Documents\ffx-editor-main\work\ppp_c2\dispatch_keyhole_named.json", encoding="utf-8"))
print("entries:", len(d))


def nm(x):
    return x["name"] if x["name"] else ("-" if x["kind"] == "null" else "?")


for r in d:
    print(
        f"{r['i']:2d} {r['entry_va']}  {r['opcode'] or '':<18} "
        f"p0={nm(r['p0']):<24} p8={nm(r['p8']):<32} pC={nm(r['pC']):<28} p1C={nm(r['p1C'])}"
    )
