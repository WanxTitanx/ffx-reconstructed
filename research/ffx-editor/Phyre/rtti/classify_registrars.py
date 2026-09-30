#!/usr/bin/env python3
"""Classify catalog functions: registrador (calls FinalizeRegistration) vs nao."""
import json, os, re
import idautils, idc

FINALIZE = 0x43C230
CTOR = 0x575410
OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\phyre_rtti"
with open(os.path.join(OUT, "PHYRE_RTTI_CATALOG_20260731.json"), encoding="utf-8-sig") as f:
    cat = json.load(f)

# Functions that call FinalizeRegistration
finalize_callers = set()
for x in idautils.XrefsTo(FINALIZE):
    f = idc.get_func_attr(x.frm, idc.FUNCATTR_START)
    if f != idc.BADADDR:
        finalize_callers.add(f)

# For catalog classes: does the function call finalize? (via code xrefs)
import ida_funcs
results = []
for cname, c in sorted(cat["classes"].items()):
    ea = int(c["addr"], 16)
    calls_finalize = ea in finalize_callers
    # check indirect: any func in catalog that calls ctor also calls finalize
    results.append((cname, c["addr"], len(c["members"]), calls_finalize))

non_reg = [r for r in results if not r[3]]
print(f"TOTAL={len(results)} NON_REGISTRADORAS={len(non_reg)}")
print("=== NAO chama FinalizeRegistration (candidatas a non-registradoras) ===")
for cname, addr, nm, cf in non_reg:
    print(f"  {cname} @ {addr} ({nm} members)")

reg = [r for r in results if r[3]]
print(f"\n=== Registradoras: {len(reg)} ===")
