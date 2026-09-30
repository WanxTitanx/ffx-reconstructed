# -*- coding: utf-8 -*-
"""IFRT-2 — REGENERA FR/DE do zero a partir do EN (fix da corrupcao de indice do 1o run).
Ordem: glossario oficial > domain dict > frases EN > dicionario PT. Indices corretos: fr=0, de=1, it=2."""

import re
import sys
import xml.etree.ElementTree as ET
from pathlib import Path

sys.stdout.reconfigure(encoding='utf-8')
sys.path.insert(0, r'C:\Users\wande\Documents\ffx-editor-main\work')

import importlib.util

def load_module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m

# Glossario oficial (do JSON)
import json
glossary = json.load(open(r'C:\Users\wande\Documents\ffx-editor-main\work\_i18n_glossary.json', encoding='utf-8'))['oficial']

# Domain dict EN (136 termos)
d1 = load_module('d1', r'C:\Users\wande\Documents\ffx-editor-main\work\_i18n_domain_dict_1.py')
d2 = load_module('d2', r'C:\Users\wande\Documents\ffx-editor-main\work\_i18n_domain_dict_2.py')
DOMAIN = {**d1.DOMAIN_1, **d2.DOMAIN_2}

# Frases EN
ep = load_module('ep', r'C:\Users\wande\Documents\ffx-editor-main\work\_i18n_en_phrases.py')
EN_PHRASES = ep.EN_PHRASES

# Dicionario PT
pt_a = load_module('pta', r'C:\Users\wande\Documents\ffx-editor-main\work\_i18n_pt_dict_a.py')
pt_b1 = load_module('ptb1', r'C:\Users\wande\Documents\ffx-editor-main\work\_i18n_pt_dict_b1.py')
pt_c1 = load_module('ptc1', r'C:\Users\wande\Documents\ffx-editor-main\work\_i18n_pt_dict_c1.py')
pt_c2 = load_module('ptc2', r'C:\Users\wande\Documents\ffx-editor-main\work\_i18n_pt_dict_c2.py')
pt_c3 = load_module('ptc3', r'C:\Users\wande\Documents\ffx-editor-main\work\_i18n_pt_dict_c3.py')
PT = {}
for d in (pt_a.PT_DICT_A, pt_b1.PT_DICT_B1, pt_c1.PT_DICT_C1, pt_c2.PT_DICT_C2, pt_c3.PT_DICT_C3):
    PT.update(d)

RESX = Path(r'C:\Users\wande\Documents\ffx-editor-main\FFXProjectEditor\Resources')

def load(lang):
    f = RESX / (f'Strings.{lang}.resx' if lang else 'Strings.resx')
    t = ET.parse(f)
    return t, {d.get('name'): d for d in t.getroot().findall('data')}

def word_sub(text, mapping, idx):
    for term, tup in mapping.items():
        target = tup[idx]
        new = re.sub(r'\b' + re.escape(term) + r'\b', target, text, flags=re.IGNORECASE)
        if new != text:
            text = new
    return text

def phrase_sub(text, mapping, idx):
    for phrase, tup in mapping.items():
        new = re.sub(re.escape(phrase), tup[idx], text, flags=re.IGNORECASE)
        if new != text:
            text = new
    return text

def full_translate(text_en, idx, lang):
    """Aplica todas as camadas na ordem correta."""
    text = text_en
    # 1. Glossario oficial (termos exatos, case-sensitive para nomes proprios)
    for term_en, trans in glossary.items():
        if lang in trans:
            text = re.sub(r'\b' + re.escape(term_en) + r'\b', trans[lang], text)
    # 2. Domain dict EN
    text = word_sub(text, DOMAIN, idx)
    # 3. Frases EN
    text = phrase_sub(text, EN_PHRASES, idx)
    # 4. Dicionario PT
    text = word_sub(text, PT, idx)
    return text

# Regenerar FR e DE COMPLETOS a partir do neutro
_, neutral = load('')
for lang, idx in [('fr', 0), ('de', 1)]:
    tree, data = load(lang)
    changed = 0
    for key, elem in data.items():
        n_elem = neutral.get(key)
        if n_elem is None:
            continue
        nval = n_elem.find('value').text if n_elem.find('value') is not None else None
        if nval is None:
            continue
        tr = full_translate(nval, idx, lang)
        elem.find('value').text = tr
        if tr != nval:
            changed += 1
    tree.write(RESX / f'Strings.{lang}.resx', encoding='utf-8', xml_declaration=True)
    print(f'{lang}: regenerado ({changed} traduzidas vs EN)')

# Spot check de sanidade
print()
for lang, idx in [('es', 0), ('fr', 0), ('de', 1), ('it', 2)]:
    t, d = load(lang)
    diff = sum(1 for k, v in d.items()
               if v.find('value') is not None and neutral.get(k) is not None
               and v.find('value').text != neutral[k].find('value').text)
    print(f'{lang}: {diff} ({diff/len(d)*100:.1f}%)')
    print(f'  SessionControls: {d.get("SessionControls").find("value").text!r}')
    print(f'  Mod_home_Title: {d.get("Mod_home_Title").find("value").text!r}')