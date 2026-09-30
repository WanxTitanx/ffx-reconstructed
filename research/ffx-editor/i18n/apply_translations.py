import json
import os
import re

# ===== Fase 4: APLICADOR de traducoes oficiais do jogo nos resx =====
# Usa linkage.json (links fortes): chave do editor -> traducao oficial do jogo.
# Aplica SOMENTE em chaves resx (as hardcoded ficam como dicionario de termos
# para a migracao futura) e limpa tokens de controle do codec (<C9>0 etc).

TEXT_ROOT = r'E:\Text'
RESX_DIR = r'FFXProjectEditor/Resources'
LANG_FILES = {
    'es': 'Strings.es.resx',
    'fr': 'Strings.fr.resx',
    'de': 'Strings.de.resx',
    'it': 'Strings.it.resx',
}

TOKEN_RE = re.compile(r'<[^>]+>')

def clean_game_text(text):
    """Remove tokens de controle FFX (<C9>0, <C18>0, <B>, </>...) e decodifica escapes."""
    t = TOKEN_RE.sub('', text or '')
    t = t.replace('&amp;', '&').replace('&lt;', '<').replace('&gt;', '>')
    return t.strip()

# ---- 1. Carrega linkage ----
links = json.load(open(os.path.join(TEXT_ROOT, 'linkage.json'), encoding='utf-8'))

# ---- 2. Filtra links com origem resx (aplicaveis agora) ----
resx_links = [l for l in links if l['origin'] == 'resx']
print('Links fortes totais:', len(links))
print('Links fortes de chaves resx:', len(resx_links))
for l in resx_links:
    print('  resx key:', l['key'], '| EN:', (l['game_en'] or '')[:40])

# ---- 3. Aplica nos resx das linguas latinas ----
applied = {lang: 0 for lang in LANG_FILES}
for lang, fname in LANG_FILES.items():
    path = os.path.join(RESX_DIR, fname)
    raw = open(path, encoding='utf-8').read()
    changed = False
    for l in resx_links:
        key = l['key']
        tr = l['translations'].get(lang)
        if not tr:
            continue
        clean_tr = clean_game_text(tr)
        if not clean_tr or '<' in clean_tr or '>' in clean_tr:
            continue  # traducao com tokens nao resolvidos (JA/KO/ZH) - pula
        # substitui <value>...</value> da chave
        pattern = re.compile(r'(<data name="' + re.escape(key) + r'"[^>]*>\s*<value>)(.*?)(</value>)', re.S)
        new_raw, n = pattern.subn(lambda m: m.group(1) + clean_tr + m.group(3), raw)
        if n > 0:
            raw = new_raw
            changed = True
            applied[lang] += 1
    if changed:
        with open(path, 'w', encoding='utf-8', newline='') as f:
            f.write(raw)
        print(f'[{lang}] aplicadas {applied[lang]} traducoes em {fname}')

# ---- 4. Dicionario de termos (para migracao futura dos hardcoded) ----
terms = {}
for l in links:
    en = clean_game_text(l.get('game_en') or l.get('editor_text') or '')
    if not en or len(en) > 60:
        continue
    trs = {lang: clean_game_text(l['translations'].get(lang, '')) for lang in LANG_FILES}
    trs = {k: v for k, v in trs.items() if v and '<' not in v and '>' not in v}
    if trs:
        terms.setdefault(en, {}).update(trs)
with open(os.path.join(TEXT_ROOT, 'terms_latin.json'), 'w', encoding='utf-8') as f:
    json.dump(terms, f, ensure_ascii=False, indent=1)
print('TERMOS unicos com traducao oficial:', len(terms))
for en in list(terms)[:10]:
    print('  ', en, '=>', terms[en])
