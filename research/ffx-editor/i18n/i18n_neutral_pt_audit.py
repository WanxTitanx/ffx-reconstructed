#!/usr/bin/env python3
"""Analyze PT-BR values wrongly placed in the neutral Strings.resx.
Neutral resx = source of truth (EN). Find values that are clearly PT-BR.
Creates work/i18n_neutral_pt_audit.json for review. No file modifications.
"""
import json, re, xml.etree.ElementTree as ET, sys

NEUTRAL = r"C:\Users\wande\Documents\ffx-editor-main\FFXProjectEditor\Resources\Strings.resx"
PT = r"C:\Users\wande\Documents\ffx-editor-main\FFXProjectEditor\Resources\Strings.pt.resx"
OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\i18n_neutral_pt_audit.json"

def parse(path):
    tree = ET.parse(path)
    d = {}
    for data in tree.getroot().iter('data'):
        name = data.get('name')
        if name is None:
            continue
        val_el = data.find('value')
        d[name] = val_el.text if (val_el is not None and val_el.text is not None) else ''
    return d

# PT-BR markers (function words + accents + typical editor PT words)
ACC = set("áéíóúâêôãõçàÁÉÍÓÚÂÊÔÕÃÇÀ")
PT_WORDS = [
    "não", "também", "ainda", "quando", "porque", "porque", "será", "está", "para", "uma",
    "superfície", "sub-aba", "sub-abas", "ilha", "habilidade", "inimigo", "fase", "rota",
    "popup", "guarda", "esperando", "seleção", "recusou", "aplicou", "conseguiu", "clique",
    "abrir", "salvar", "fechar", "selecione", "edita", "editar", "desta", "desta", "deste",
    "este", "esta", "pílula", "autoritativo", "atrás", "customização", "equipamento", "lojas",
    "tesouros", "baús", "recompensas", "partição", "aleatória", "momentânea", "sobre",
    "opcional", "herda", "vários", "sequência", "encadeia", "próxima", "permite", "armazena",
    "recebe", "aplica", "respeita", "marcado", "váveis", "campo", "afeta", "das", "dos", "na",
    "no", "é", "são", "será utilizado", "vai", "ficará", "específico", "provável", "mostra",
    "exibe", "permite", "autoriza", "rituais", "rápidos",
]

def is_pt(v):
    low = v.lower()
    has_acc = any(c in ACC for c in v)
    if not has_acc:
        return False
    # strong signal: at least one PT function word OR 2+ accents
    word_hits = [w for w in PT_WORDS if w in low]
    # mojibake guard: if accented but text is gibberish encoded (common in corrupted), still PT
    if isinstance(word_hits, list) and len(word_hits) >= 1:
        return True
    n_acc = sum(1 for c in v if c in ACC)
    return n_acc >= 2

def main():
    neutral = parse(NEUTRAL)
    pt = parse(PT)
    pt_keys = set(pt.keys())
    hits = []
    for k, v in neutral.items():
        if is_pt(v):
            hits.append({
                "key": k,
                "value": v,
                "in_pt": k in pt_keys,
                "pt_value_if_missing": (pt.get(k, None)),
            })
    hits.sort(key=lambda x: x["key"])
    with open(OUT, "w", encoding="utf-8") as f:
        json.dump(hits, f, ensure_ascii=False, indent=2)
    print(f"NEUTRAL total keys: {len(neutral)}")
    print(f"PT keys in satellite: {len(pt_keys)}")
    print(f"PT-flagged in neutral: {len(hits)}")
    missing_from_pt = [h for h in hits if not h["in_pt"]]
    print(f"  flagged that are MISSING from Strings.pt.resx: {len(missing_from_pt)}")
    print(f"  flagged already present in pt.resx: {len(hits)-len(missing_from_pt)}")
    print("\nSample (first 10):")
    for h in hits[:10]:
        print(f"  [{h['key']}] in_pt={h['in_pt']} :: {h['value'][:60]}")

if __name__ == "__main__":
    main()
