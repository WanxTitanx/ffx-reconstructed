# -*- coding: utf-8 -*-
"""IFRT-2 — Traduz ES/FR/DE/IT via DeepL (SO chaves ainda iguais ao EN).
Preserva manuais ES e traducoes existentes do pipeline; melhora o restante."""

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

# --- Chaves DeepL ---
env = {}
for line in ENV_FILE.read_text(encoding='utf-8').splitlines():
    line = line.strip()
    if '=' in line and not line.startswith('#'):
        k, v = line.split('=', 1)
        env[k.strip()] = v.strip()

KEYS = [env.get('DEEPL_API_KEY_2'), env.get('DEEPL_API_KEY_3'), env.get('DEEPL_API_KEY')]
KEYS = [k for k in KEYS if k]
URL = 'https://api-free.deepl.com/v2/translate'
print(f'Chaves DeepL: {len(KEYS)}', flush=True)

# --- Protecao de tokens (mesmo PROTECT_RE do pipeline) ---
PROTECT_RE = re.compile(
    r'[A-Za-z0-9_ .\\:]+\\[A-Za-z0-9_ .\\:]+'
    r'|[A-Za-zÀ-ÿ0-9_]+\.(?:bin|dll|txt|json|ini|exe|dat|bak|log|py|cs|axaml|resx|dds|phyre|gltf|vbf|pak|wav|fsb|mseq|mgvp|at3|msd|nsd|bsd|snd|sep|ebp|mac|evt|btl|mon|rps|psw|tbl|jpg|png|gif|bmp|ttf|otf|xml|yaml|yml|toml|cfg|conf|md)'
    r'|\b(?:magicFiles|ps3data|ffx_ps2|master|ATEL|DINPUT8|RT0|RT2|EBP|EV01|FTCX|MSEQ|VBF|DDS|GLTF|PHYRE|monmagic1|monmagic2|a_ability|arms_rate|kaizou|sum_grow|takara|buki_get|prepare|yunalesca|tidus|rikku|auron|wakka|lulu|kimahri|yuna|seymour|jecht|braska|sin|omega|bikanel|gagazet|maechen)\b'
)

def protect(text):
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
    toks = list(PROTECT_RE.finditer(original))
    out = text
    for i in range(count - 1, -1, -1):
        out = out.replace(f'<ptk{i}/>', toks[i].group(0))
    out = out.replace('&lt;', '<').replace('&gt;', '>').replace('&amp;', '&')
    return out

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

def load(lang):
    f = RESX / (f'Strings.{lang}.resx' if lang else 'Strings.resx')
    t = ET.parse(f)
    return t, {d.get('name'): (d.find('value').text if d.find('value') is not None else None)
               for d in t.getroot().findall('data')}

_, neutral = load('')

for lang, target in [('es', 'ES'), ('fr', 'FR'), ('de', 'DE'), ('it', 'IT')]:
    tree, data = load(lang)
    # SO chaves ainda iguais ao EN (preserva manuais e traducoes existentes)
    todo = [(k, neutral[k]) for k, v in data.items()
            if v == neutral.get(k) and neutral.get(k)]
    print(f'\n=== {lang}: {len(todo)} chaves ainda EN ===', flush=True)
    if not todo:
        continue

    translated = {}
    batch, batch_keys, batch_protected = [], [], []
    total_chars = 0

    for k, v in todo:
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
            time.sleep(1.5)

    if batch:
        results = deepl_translate(batch, target)
        for kk, res, (orig, n) in zip(batch_keys, results, batch_protected):
            translated[kk] = restore(res, orig, n)
        total_chars += sum(len(b) for b in batch)

    print(f'  {lang}: {len(translated)} traduzidas, ~{total_chars} chars', flush=True)

    root = tree.getroot()
    data_map = {d.get('name'): d for d in root.findall('data')}
    updated = 0
    for k, val in translated.items():
        if k in data_map:
            data_map[k].find('value').text = val
            updated += 1
    tree.write(RESX / f'Strings.{lang}.resx', encoding='utf-8', xml_declaration=True)
    print(f'  {lang}: {updated} chaves escritas', flush=True)

print('\n✓ ES/FR/DE/IT melhorados via DeepL!', flush=True)