# Onda 2 - verifica literais residuais nos .axaml (exceto MonsterAiEditor2)
import os, re, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from _i18n_onda2_migrate import COMMON, REUSE, ATTRS, MODULES_DIR

res = 0
for root, dirs, files in os.walk(MODULES_DIR):
    for fn in files:
        if not fn.endswith(".axaml") or "MonsterAiEditor2" in fn:
            continue
        txt = open(os.path.join(root, fn), encoding="utf-8-sig").read()
        for attr in ATTRS:
            for key, en, pt in COMMON:
                for val in (en, pt):
                    if f'{attr}="{val}"' in txt:
                        print("RESIDUAL", os.path.join(root, fn), attr, repr(val))
                        res += 1
            for (ra, rv), _k in REUSE.items():
                if f'{ra}="{rv}"' in txt:
                    print("RESIDUAL-REUSE", os.path.join(root, fn), ra, repr(rv))
                    res += 1
print("residuais Onda 2:", res)
