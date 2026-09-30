import json
import os
import re
import unicodedata

# ===== Fase 3: LINKADOR INTELIGENTE =====
# Para cada string do editor (resx + hardcoded), encontra no corpus EN do jogo a
# entrada correspondente por palavra-chave e, quando linkada, puxa as traducoes
# oficiais das outras regioes (mesmo arquivo/index/slot).

TEXT_ROOT = r'E:\Text'
LATIN_LANGS = ['es', 'fr', 'de', 'it']   # latinas decodificam perfeitamente
ALL_LANGS = LATIN_LANGS + ['ja', 'ko', 'zh']

# tokens de controle do codec FFX
TOKEN_RE = re.compile(r'<[^>]+>')

def clean(text):
    """Remove tokens de controle e normaliza (lowercase, sem acentos)."""
    t = TOKEN_RE.sub('', text or '')
    t = unicodedata.normalize('NFD', t)
    t = ''.join(c for c in t if not unicodedata.combining(c))
    return t.lower().strip()

# ---- 1. Carrega corpus EN (new_uspc = fonte oficial EN HD) ----
corpus = {}  # arquivo -> [(index, slot, text, clean)]
for fn in os.listdir(os.path.join(TEXT_ROOT, 'game_en_new')):
    if not fn.endswith('.json'):
        continue
    name = fn[:-5]
    with open(os.path.join(TEXT_ROOT, 'game_en_new', fn), encoding='utf-8') as f:
        data = json.load(f)
    corpus[name] = []
    for e in data:
        c = clean(e.get('Text', ''))
        if len(c) >= 3:
            corpus[name].append((e['Index'], e.get('Slot'), e.get('Text', ''), c))

# ---- 2. Indice invertido: palavra -> [(arquivo, index, slot, clean)] ----
WORD_RE = re.compile(r"[a-z0-9']+")
inverted = {}
for fname, entries in corpus.items():
    for (idx, slot, raw, c) in entries:
        for w in set(WORD_RE.findall(c)):
            if len(w) >= 4:  # palavras-chave significativas
                inverted.setdefault(w, []).append((fname, idx, slot, c))

# ---- 3. Carrega strings do editor ----
editor = json.load(open(os.path.join(TEXT_ROOT, 'editor_strings.json'), encoding='utf-8'))

# 3a. strings resx EN
editor_strings = []
for key, val in editor['resx'].items():
    editor_strings.append(('resx', key, val))

# 3b. literais hardcoded (sao majoritariamente PT; usamos os que sao EN/termos do jogo)
for rel, lits in editor['hardcoded'].items():
    for lit in lits:
        editor_strings.append((rel, lit['attr'], lit['value']))

# ---- 4. Linkagem ----
def best_match(text):
    """Acha a melhor entrada do jogo para o texto do editor.
    Estrategia: (a) igualdade limpa; (b) substrings longas; (c) palavras-chave raras."""
    c = clean(text)
    if len(c) < 4:
        return None, 0
    # (a) igualdade limpa
    for fname, entries in corpus.items():
        for (idx, slot, raw, ec) in entries:
            if ec == c:
                return (fname, idx, slot), 1.0
    # (b) substring: texto do editor contem texto do jogo (ou vice-versa) com >= 5 chars
    best, best_score = None, 0.0
    for fname, entries in corpus.items():
        for (idx, slot, raw, ec) in entries:
            if len(ec) >= 5:
                if ec in c or c in ec:
                    score = min(len(ec), len(c)) / max(len(ec), len(c))
                    if score > best_score:
                        best, best_score = (fname, idx, slot), score
    if best and best_score >= 0.85:
        return best, best_score
    # (c) palavra-chave rara: palavra do editor que aparece em poucas entradas do jogo
    words = [w for w in WORD_RE.findall(c) if len(w) >= 4]
    if not words:
        return None, 0
    rare = [w for w in words if 0 < len(inverted.get(w, [])) <= 3]
    if rare:
        for w in sorted(rare, key=lambda w: len(inverted[w])):
            fname, idx, slot, _ = inverted[w][0]
            return (fname, idx, slot), 0.55  # weak: marcado separadamente
    return None, 0

links = []
weak_links = []
for (origin, key, val) in editor_strings:
    c = clean(val)
    if len(c) < 4:
        continue
    target, score = best_match(val)
    if target is None:
        continue
    fname, idx, slot = target
    entry = {
        'origin': origin,
        'key': key,
        'editor_text': val,
        'match': {'file': fname, 'index': idx, 'slot': slot, 'score': round(score, 2)},
        'game_en': None,
        'translations': {},
    }
    # texto EN oficial
    for (i, s, raw, ec) in corpus[fname]:
        if i == idx and (slot is None or s == slot):
            entry['game_en'] = raw
            break
    # traducoes oficiais por regiao (mesmo arquivo/index/slot)
    for lang in ALL_LANGS:
        p = os.path.join(TEXT_ROOT, f'game_{lang}', fname + '.json')
        if not os.path.exists(p):
            continue
        with open(p, encoding='utf-8') as f:
            for e in json.load(f):
                if e['Index'] == idx and (slot is None or e.get('Slot') == slot):
                    entry['translations'][lang] = e.get('Text', '')
                    break
    if score >= 0.85:
        links.append(entry)
    else:
        weak_links.append(entry)

with open(os.path.join(TEXT_ROOT, 'linkage.json'), 'w', encoding='utf-8') as f:
    json.dump(links, f, ensure_ascii=False, indent=1)
with open(os.path.join(TEXT_ROOT, 'linkage_weak.json'), 'w', encoding='utf-8') as f:
    json.dump(weak_links, f, ensure_ascii=False, indent=1)

print('STRINGS EDITOR analisadas:', len(editor_strings))
print('LINKAGENS FORTES (score>=0.85):', len(links))
print('LINKAGENS FRACAS (palavra rara):', len(weak_links))
# estatistica por origem
from collections import Counter
print('--- FORTES por origem ---')
print(Counter(l['origin'].split('/')[0] if l['origin'] != 'resx' else 'resx' for l in links).most_common(8))
with_tr = [l for l in links if all(l['translations'].get(lg) for lg in LATIN_LANGS)]
print('FORTES com traducoes latinas completas:', len(with_tr))
for l in with_tr[:14]:
    print('-', l['key'], '| EN:', (l['game_en'] or '')[:40], '| ES:', (l['translations'].get('es') or '')[:28], '| DE:', (l['translations'].get('de') or '')[:28])

