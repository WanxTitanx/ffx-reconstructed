# -*- coding: utf-8 -*-
"""IFRT-2 — Traduz JA/KO/ZH via DeepL API com protecao de tokens.
- Le o Strings.resx (neutro EN)
- Protege paths/nomes de arquivo/siglas com tags XML <ptkN/> (DeepL preserva com tag_handling=xml)
- Envia lotes de 50 textos por request (limite DeepL)
- Restaura tokens e escreve Strings.{ja,ko,zh}.resx"""

import json
import re
import sys
import time
import urllib.request
import urllib.error
import xml.etree.ElementTree as ET
from pathlib import Path

sys.stdout.reconfigure(encoding='utf-8')

WORK = Path(r'C:\Users\wande\Documents\ffx-editor-main\work')
RESX = Path(r'C:\Users\wande\Documents\ffx-editor-main\FFXProjectEditor\Resources')
ENV_FILE = Path(r'C:\Users\wande\Documents\ffx-mod-website\.env.local')

# --- Chaves DeepL do .env.local ---
env = {}
for line in ENV_FILE.read_text(encoding='utf-8').splitlines():
    line = line.strip()
    if '=' in line and not line.startswith('#'):
        k, v = line.split('=', 1)
        env[k.strip()] = v.strip()

KEYS = [env.get('DEEPL_API_KEY_2'), env.get('DEEPL_API_KEY_3'), env.get('DEEPL_API_KEY')]
KEYS = [k for k in KEYS if k]
URL = 'https://api-free.deepl.com/v2/translate'
print(f'Chaves DeepL: {len(KEYS)} | URL: {URL}')

# --- Protecao de tokens (mesmo PROTECT_RE do pipeline final) ---
PROTECT_RE = re.compile(
    r'[A-Za-z0-9_ .\\:]+\\[A-Za-z0-9_ .\\:]+'
    r'|[A-Za-zÀ-ÿ0-9_]+\.(?:bin|dll|txt|json|ini|exe|dat|bak|log|py|cs|axaml|resx|dds|phyre|gltf|vbf|pak|wav|fsb|mseq|mgvp|at3|msd|nsd|bsd|snd|sep|ebp|mac|evt|btl|mon|rps|psw|tbl|jpg|png|gif|bmp|ttf|otf|xml|yaml|yml|toml|cfg|conf|md)'
    r'|\b(?:magicFiles|ps3data|ffx_ps2|master|ATEL|DINPUT8|RT0|RT2|EBP|EV01|FTCX|MSEQ|VBF|DDS|GLTF|PHYRE|monmagic1|monmagic2|a_ability|arms_rate|kaizou|sum_grow|takara|buki_get|prepare|yunalesca|tidus|rikku|auron|wakka|lulu|kimahri|yuna|seymour|jecht|braska|sin|omega|bikanel|gagazet|maechen)\b'
)

def protect(text):
    """Escapa XML por segmento e substitui tokens por tags <ptkN/>."""
    def esc(s):
        return s.replace('&', '&amp;').replace('<', '&lt;').replace('>', '&gt;')
    parts, last, idx = [], 0, 0
    for m in PROTECT_RE.finditer(text):
        parts.append(esc(text[last:m.start()]))
        parts.append(f'<ptk{idx}/>')
        idx += 1
        last = m.end()
    parts.append(esc(text[last:]))
    return ''.join(parts), idx

def restore(text, original, count):
    """Substitui tags <ptkN/> pelos tokens originais e desescapa XML restante."""
    toks = list(PROTECT_RE.finditer(original))
    out = text
    for i in range(count - 1, -1, -1):
        out = out.replace(f'<ptk{i}/>', toks[i].group(0))
    # desescapar XML restante (DeepL pode ter re-escapeado)
    out = out.replace('&lt;', '<').replace('&gt;', '>').replace('&amp;', '&')
    return out

# --- Chamada DeepL com fallback de chaves ---
def deepl_translate(texts, target_lang):
    payload = json.dumps({
        'text': texts,
        'target_lang': target_lang,
        'tag_handling': 'xml',
        'split_sentences': '0',
    }).encode('utf-8')
    last_err = None
    for key in KEYS:
        try:
            req = urllib.request.Request(
                URL, data=payload,
                headers={'Authorization': f'DeepL-Auth-Key {key}', 'Content-Type': 'application/json'})
            with urllib.request.urlopen(req, timeout=60) as resp:
                data = json.loads(resp.read().decode('utf-8'))
            return [t['text'] for t in data['translations']]
        except urllib.error.HTTPError as e:
            last_err = f'HTTP {e.code}: {e.read().decode("utf-8", "replace")[:200]}'
            if e.code == 429 or e.code >= 500:
                time.sleep(2)
                continue
            break
        except Exception as e:
            last_err = str(e)
    raise RuntimeError(f'DeepL falhou para {target_lang}: {last_err}')

# --- Carregar neutro ---
t = ET.parse(RESX / 'Strings.resx')
neutral = {d.get('name'): (d.find('value').text if d.find('value') is not None else None)
           for d in t.getroot().findall('data')}
print(f'Neutro: {len(neutral)} chaves')

# --- Traduzir por idioma ---
for lang, target in [('ja', 'JA'), ('ko', 'KO'), ('zh', 'ZH')]:
    # ja/ko/zh sao copias do neutro (EN) — regenerar tudo
    entries = [(k, v) for k, v in neutral.items() if v]
    print(f'\n=== {lang} ({len(entries)} chaves) ===')
    translated = {}
    batch = []
    batch_keys = []
    batch_protected = []
    total_chars = 0

    for k, v in entries:
        protected, n = protect(v)
        batch.append(protected)
        batch_keys.append(k)
        batch_protected.append((v, n))
        if len(batch) >= 50:
            results = deepl_translate(batch, target)
            for kk, res, (orig, n) in zip(batch_keys, results, batch_protected):
                translated[kk] = restore(res, orig, n)
            total_chars += sum(len(b) for b in batch)
            batch, batch_keys, batch_protected = [], [], []
            print(f'  +{len(translated)} chaves...', flush=True)
            time.sleep(1.5)  # rate limit DeepL free (~1 req/s)

    if batch:
        results = deepl_translate(batch, target)
        for kk, res, (orig, n) in zip(batch_keys, results, batch_protected):
            translated[kk] = restore(res, orig, n)
        total_chars += sum(len(b) for b in batch)

    print(f'  {lang}: {len(translated)} traduzidas, ~{total_chars} chars')

    # Escrever no resx
    resx_path = RESX / f'Strings.{lang}.resx'
    tree = ET.parse(resx_path)
    root = tree.getroot()
    data_map = {d.get('name'): d for d in root.findall('data')}
    updated = 0
    for k, val in translated.items():
        if k in data_map:
            data_map[k].find('value').text = val
            updated += 1
    tree.write(resx_path, encoding='utf-8', xml_declaration=True)
    print(f'  {lang}: {updated} chaves escritas em Strings.{lang}.resx')

print('\n✓ JA/KO/ZH traduzidos via DeepL!')