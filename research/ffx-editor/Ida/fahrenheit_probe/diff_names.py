#!/usr/bin/env python3
"""diff_names.py — compara canon_names.json vs copy_names.json e mostra divergencias."""
import json
import re

BAD = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_|unknown|dword_|byte_|word_|off_|qword_|unk_|asc_|a[A-Z])")

canon = json.load(open(r"F:\ffx-reconstructed\pseudocode\complete\canon_names.json", encoding="utf-8"))
copy = json.load(open(r"F:\ffx-reconstructed\pseudocode\complete\copy_names.json", encoding="utf-8"))

canon_f = {str(ea): name for ea, name in canon["funcs"]}
copy_f = {str(ea): name for ea, name in copy["funcs"]}
canon_g = {str(ea): name for ea, name in canon["globals"]}
copy_g = {str(ea): name for ea, name in copy["globals"]}

print(f"canon: {len(canon_f)} funcs + {len(canon_g)} globals")
print(f"copy : {len(copy_f)} funcs + {len(copy_g)} globals")

# FUNCOES: canon que faltam na copy
f_missing = []
for ea, name in canon_f.items():
    if ea not in copy_f:
        f_missing.append((int(ea), name))
    elif copy_f[ea] != name:
        f_missing.append((int(ea), f"{name} (copy tem: {copy_f[ea]})"))
# FUNCOES: copy que faltam na canon
f_copy_only = [(int(ea), name) for ea, name in copy_f.items() if ea not in canon_f]

# GLOBALS: canon que faltam na copy
g_missing = []
for ea, name in canon_g.items():
    if ea not in copy_g:
        g_missing.append((int(ea), name))
    elif copy_g[ea] != name:
        g_missing.append((int(ea), f"{name} (copy tem: {copy_g[ea]})"))
g_copy_only = [(int(ea), name) for ea, name in copy_g.items() if ea not in canon_g]

print(f"\n=== FUNCOES: canon-only (faltam na copy): {len(f_missing)} ===")
good = [x for x in f_missing if not BAD.match(x[1].split()[0])]
bad = [x for x in f_missing if BAD.match(x[1].split()[0])]
print(f"  nomes bons: {len(good)} | auto (sub_/loc_/etc): {len(bad)}")
for ea, name in sorted(good)[:15]:
    print(f"  {ea:08X} {name}")
print(f"\n=== FUNCOES: copy-only (a copy tem a mais): {len(f_copy_only)} ===")
for ea, name in sorted(f_copy_only)[:10]:
    print(f"  {ea:08X} {name}")

print(f"\n=== GLOBALS: canon-only (faltam na copy): {len(g_missing)} ===")
ggood = [x for x in g_missing if not BAD.match(x[1].split()[0])]
gbad = [x for x in g_missing if BAD.match(x[1].split()[0])]
print(f"  nomes bons: {len(ggood)} | auto: {len(gbad)}")
for ea, name in sorted(ggood)[:15]:
    print(f"  {ea:08X} {name}")
print(f"\n=== GLOBALS: copy-only (a copy tem a mais): {len(g_copy_only)} ===")
for ea, name in sorted(g_copy_only)[:10]:
    print(f"  {ea:08X} {name}")

# salva os diffs aplicaveis
out = {
    "funcs_canon_only": [[ea, n.split(" (")[0]] for ea, n in good],
    "globals_canon_only": [[ea, n.split(" (")[0]] for ea, n in ggood],
}
with open(r"F:\ffx-reconstructed\pseudocode\complete\diff_to_apply.json", "w", encoding="utf-8") as f:
    json.dump(out, f, indent=1)
print(f"\ndiff_to_apply.json: {len(out['funcs_canon_only'])} funcs + {len(out['globals_canon_only'])} globals")
