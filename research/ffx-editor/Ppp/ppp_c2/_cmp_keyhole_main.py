# -*- coding: utf-8 -*-
"""Compara keyhole (nomeada) com main/alt (brutas) por assinatura de handlers."""
import json

K = r"C:\Users\wande\Documents\ffx-editor-main\work\ppp_c2\dispatch_keyhole_named.json"
A = r"C:\Users\wande\Documents\ffx-editor-main\work\ppp_c2\dispatch_tables_all.json"

k = json.load(open(K, encoding="utf-8"))
a = json.load(open(A, encoding="utf-8"))
m, al = a["main"], a["alt"]


def hsig(e):
    """(p8,pC,p1C) normalizado como hex string."""
    out = []
    for f in ("p8", "pC", "p1C"):
        v = e[f]
        if isinstance(v, dict):
            out.append(v["va"])
        else:
            out.append(v)
    return tuple(out)


print(f"{'i':>2} {'opcode':<20} {'main_ids':<46} {'alt_ids'}")
for e in k:
    kh = hsig(e)
    hits = [i for i, x in enumerate(m) if hsig(x) == kh]
    hitsA = [i for i, x in enumerate(al) if hsig(x) == kh]
    hs = str(hits[:6]) + ("..." if len(hits) > 6 else "")
    ha = str(hitsA[:6]) + ("..." if len(hitsA) > 6 else "")
    print(f"{e['i']:>2} {e['opcode']:<20} {hs:<46} {ha}")

# resumo: quantas keyhole entries tem match EXATO com a main na MESMA posicao relativa?
# e quantas chaves de opcode (p0 string) coincidem entre keyhole e main
def p0v(e):
    v = e["p0"]
    return v if isinstance(v, str) else v["va"]

m_p0 = {p0v(x) for x in m}
k_p0 = {p0v(x) for x in k}
print()
print("keyhole p0 strings presentes na main:", len(k_p0 & m_p0), "/", len(k_p0))
