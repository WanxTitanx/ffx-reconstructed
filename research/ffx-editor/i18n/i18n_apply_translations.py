# -*- coding: utf-8 -*-
"""IFRT-2 — Aplica traducoes ES/FR/DE/IT nos resx satellites.
Le work/_i18n_tr_{lang}_auto.py e atualiza Strings.{lang}.resx."""

import ast
import sys
import xml.etree.ElementTree as ET
from pathlib import Path

sys.stdout.reconfigure(encoding='utf-8')

resx_dir = Path(r'C:\Users\wande\Documents\ffx-editor-main\FFXProjectEditor\Resources')

for lang in ['es', 'fr', 'de', 'it']:
    print(f"\n=== Aplicando {lang.upper()} ===")
    
    # Carregar traducoes
    tr_file = Path(f'C:\\Users\\wande\\Documents\\ffx-editor-main\\work\\_i18n_tr_{lang}_auto.py')
    with open(tr_file, 'r', encoding='utf-8') as f:
        source = f.read()
    tree = ast.parse(source)
    tr_dict = None
    for node in ast.walk(tree):
        if isinstance(node, ast.Assign):
            for target in node.targets:
                if isinstance(target, ast.Name) and target.id == 'TR':
                    tr_dict = ast.literal_eval(node.value)
                    break
    
    if not tr_dict:
        print(f"✗ ERRO: nao achou TR em {tr_file}")
        continue
    
    print(f"✓ Carregadas {len(tr_dict)} traducoes")
    
    # Carregar resx
    resx_path = resx_dir / f'Strings.{lang}.resx'
    tree = ET.parse(resx_path)
    root = tree.getroot()
    
    # Atualizar/adicionar chaves
    updated = 0
    added = 0
    existing = {data.get('name'): data for data in root.findall('data')}
    
    for key, value in tr_dict.items():
        if value and value.strip():  # so aplica se tem valor nao-vazio
            if key in existing:
                # Atualizar existente
                existing[key].find('value').text = value
                updated += 1
            else:
                # Adicionar nova
                data = ET.SubElement(root, 'data')
                data.set('name', key)
                data.set('xml:space', 'preserve')
                value_elem = ET.SubElement(data, 'value')
                value_elem.text = value
                added += 1
    
    # Salvar
    tree.write(resx_path, encoding='utf-8', xml_declaration=True)
    print(f"✓ {resx_path.name}: {updated} atualizadas, {added} adicionadas")

print("\n✓ Todas as traducoes latinas aplicadas!")