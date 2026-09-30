#!/usr/bin/env python3
"""diff_names2.py — separa globals/funcs AUSENTES (copy sem nome) vs DIVERGENTES (copy tem outro nome).
Só os ausentes com nome bom viram apply_list.json."""
import json
import re

BAD = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_|unknown|dword_|byte_|word_|off_|qword_|unk_|asc_|a[A-Z])")

canon = json.load(open(r"F:\ffx-reconstructed\pseudocode\complete\canon_names.json", encoding="utf-8"))
copy = json.load(open(r"F:\ffx-reconstructed\pseudocode\complete\copy_names.json", encoding="utf-8"))

canon_f = {str(ea): name for ea, name in canon["funcs"]}
copy_f = {str(ea): name for ea, name in copy["funcs"]}
canon_g = {str(ea): name for ea, name in canon["globals"]}
copy_g = {str(ea): name for ea, name in copy["globals"]}

# AUSENTES: canon tem nome, copy nao tem NENHUM nome no ea
f_absent = []
f_divergent = []
for ea, name in canon_f.items():
    if ea not in copy_f:
        f_absent.append((int(ea), name))
    elif copy_f[ea] != name:
        f_divergent.append((int(ea), name, copy_f[ea]))

g_absent = []
g_divergent = []
for ea, name in canon_g.items():
    if ea not in copy_g:
        g_absent.append((int(ea), name))
    elif copy_g[ea] != name:
        g_divergent.append((int(ea), name, copy_g[ea]))

f_apply = [(ea, n) for ea, n in f_absent if not BAD.match(n)]
g_apply = [(ea, n) for ea, n in g_absent if not BAD.match(n)]

print(f"FUNCOES ausentes: {len(f_absent)} (aplicaveis: {len(f_apply)}) | divergentes: {len(f_divergent)}")
print(f"GLOBALS ausentes: {len(g_absent)} (aplicaveis: {len(g_apply)}) | divergentes: {len(g_divergent)}")

print("\n=== amostra globals ausentes aplicaveis ===")
for ea, name in sorted(g_apply)[:25]:
    print(f"  {ea:08X} {name}")
print("\n=== amostra funcoes ausentes aplicaveis ===")
for ea, name in sorted(f_apply)[:10]:
    print(f"  {ea:08X} {name}")

with open(r"F:\ffx-reconstructed\pseudocode\complete\apply_list.json", "w", encoding="utf-8") as f:
    json.dump({"funcs": f_apply, "globals": g_apply}, f, indent=1)
print(f"\napply_list.json: {len(f_apply)} funcs + {len(g_apply)} globals")
