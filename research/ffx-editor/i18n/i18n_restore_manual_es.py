# -*- coding: utf-8 -*-
"""IFRT-2 — Restaura traducoes manuais ES por cima do automatico.
Mescla _i18n_tr_es_{1..5c}.py (qualidade real) no Strings.es.resx,
prioridade MANUAL > automatico. Chaves sem manual ficam como estao."""

import ast
import glob
import sys
import xml.etree.ElementTree as ET
from pathlib import Path

sys.stdout.reconfigure(encoding='utf-8')

resx_path = Path(r'C:\Users\wande\Documents\ffx-editor-main\FFXProjectEditor\Resources\Strings.es.resx')
manual_files = sorted(glob.glob(r'C:\Users\wande\Documents\ffx-editor-main\work\_i18n_tr_es_[1-5]*.py'))

# 1) Coletar todas as traducoes manuais (1..5c, exceto auto)
manual = {}
for f in manual_files:
    src = open(f, encoding='utf-8').read()
    tree = ast.parse(src)
    for node in ast.walk(tree):
        if isinstance(node, ast.Assign):
            for t in node.targets:
                if isinstance(t, ast.Name) and t.id == 'TR':
                    d = ast.literal_eval(node.value)
                    manual.update(d)
                    break
print(f'Manuais coletadas: {len(manual)} chaves de {len(manual_files)} arquivos')

# 2) Aplicar no resx (atualizar valor onde a chave existe; adicionar se faltar)
tree = ET.parse(resx_path)
root = tree.getroot()
existing = {data.get('name'): data for data in root.findall('data')}
updated = 0
added = 0
for key, value in manual.items():
    if not value or not value.strip():
        continue
    if key in existing:
        existing[key].find('value').text = value
        updated += 1
    else:
        data = ET.SubElement(root, 'data')
        data.set('name', key)
        data.set('xml:space', 'preserve')
        v = ET.SubElement(data, 'value')
        v.text = value
        added += 1

tree.write(resx_path, encoding='utf-8', xml_declaration=True)
print(f'✓ Strings.es.resx: {updated} atualizadas, {added} adicionadas (manual > automatico)')

# 3) Verificacao spot
es = {d.get('name'): (d.find('value').text if d.find('value') is not None else None)
      for d in ET.parse(resx_path).getroot().findall('data')}
for k in ['LangSelector', 'SessionControls', 'MainWinTagline', 'DashboardHeroSubtitle',
          'ActionSave', 'Mod_save_editor_Description']:
    print(f'  {k}: {es.get(k)!r}')