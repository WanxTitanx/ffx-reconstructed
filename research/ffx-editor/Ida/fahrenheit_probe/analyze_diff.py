#!/usr/bin/env python3
"""analyze_diff.py — analisa os globals canon-only (prefixos/qualidade) para aplicar seletivamente."""
import json
import re
from collections import Counter

data = json.load(open(r"F:\ffx-reconstructed\pseudocode\complete\diff_to_apply.json", encoding="utf-8"))
gl = data["globals_canon_only"]
print(f"globals canon-only: {len(gl)}")

# prefixos
pref = Counter()
for ea, name in gl:
    m = re.match(r"^([A-Za-z_][A-Za-z0-9_]*)", name)
    p = (m.group(1)[:12] if m else "?") + "_"
    pref[p] += 1

print("\n=== prefixos mais comuns ===")
for p, c in pref.most_common(25):
    print(f"  {p:<14} {c}")

# categorias de qualidade
ffx = [x for x in gl if re.match(r"^(FFX|Phyre|fnt|Font|Mscd|Menu|Battle|Field|Magic|Snd|Seq|Lp|Ppp|Ke|Btl|Map|Eve|Ui|Gd|Dvd|Tk|Tbl|Pm)", x[1])]
generic = [x for x in gl if re.match(r"^(ColorF|First_|Second|Third|Last|Prev|Next|Value|Item|Node|Entry|Ptr|List|Array|String|Buffer|Data|Info|Count|Size|Name|Type|Flag|Status|Result|Param|Arg|Local|Global|Temp|Tmp|Ret|Res|Ctx|Ctx_|self|this|it_|v_|a_|b_|c_|d_|e_|f_|x_|y_|z_|w_|s_|i_|n_|p_|q_|r_|t_|u_|h_|m_|k_|o_|l_|j_|g_|d_|w_)", x[1])]
rest = [x for x in gl if x not in ffx and x not in generic]
print(f"\n=== qualidade ===")
print(f"  FFX/Phyre/sistemas FFX: {len(ffx)}")
print(f"  genericos (ColorF_, First_, ...): {len(generic)}")
print(f"  outros: {len(rest)}")

print("\n=== amostra FFX/Phyre (aplicar!) ===")
for ea, name in sorted(ffx)[:20]:
    print(f"  {ea:08X} {name}")
print("\n=== amostra 'outros' ===")
for ea, name in sorted(rest)[:20]:
    print(f"  {ea:08X} {name}")
