# -*- coding: utf-8 -*-
"""
IFRT-2 (2026-08-02) — Survey fresco da Onda 3:
re-varre TODOS os .axaml (exceto MonsterAiEditor2*) e lista os literais
que ainda NAO sao {x:Static res:Strings.X}, classificados por frequencia.
"""
import os, re, collections, json, sys

# garante UTF-8 no console (evita crash cp1252 com \u2192 etc.)
if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8", errors="replace")

ROOT = r"C:\Users\wande\Documents\ffx-editor-main"
MODULES_DIR = os.path.join(ROOT, "FFXProjectEditor", "Modules")
ATTRS = ("Text=", "Content=", "Header=", "Watermark=", "ToolTip.Tip=")

skip_words = {"|", "\u00b7", "\u2022", "-", "\u2014"}

def iter_axaml():
    for root, dirs, files in os.walk(MODULES_DIR):
        for fn in files:
            if not fn.endswith(".axaml") or "MonsterAiEditor2" in fn:
                continue
            yield os.path.join(root, fn)

counter = collections.Counter()          # valor -> n
by_file = collections.defaultdict(list)  # arquivo -> [(attr, valor)]
total = 0
files_with = 0

for path in iter_axaml():
    txt = open(path, encoding="utf-8-sig").read()
    found = []
    for attr in ATTRS:
        for m in re.finditer(re.escape(attr) + r'"([^"{][^"]*)"', txt):
            v = m.group(1).strip()
            if not v or v.startswith("{") or len(v) < 3 or v in skip_words:
                continue
            # ja migrado?
            if "{x:Static res:Strings." in v:
                continue
            found.append((attr.rstrip("="), v))
    if found:
        files_with += 1
        rel = os.path.relpath(path, MODULES_DIR)
        for a, v in found:
            counter[v] += 1
            by_file[rel].append((a, v))
            total += 1

print(f"TOTAL literais restantes: {total} em {files_with} arquivos")
print(f"Valores unicos: {len(counter)}")
print()
multi = [(v, n) for v, n in counter.items() if n >= 2]
uni = [(v, n) for v, n in counter.items() if n == 1]
print(f"Com 2+ ocorrencias: {len(multi)} valores ({sum(n for _, n in multi)} literais)")
print(f"Unicos (1x): {len(uni)} valores")
print()
print("=== TOP 40 com 2+ ocorrencias ===")
for v, n in sorted(multi, key=lambda kv: -kv[1])[:40]:
    print(f"{n:3d} | {v!r}")
print()
print("=== AMOSTRA unicos (primeiros 50) ===")
for v, n in sorted(uni)[:50]:
    print(f"  1 | {v!r}")

# salva survey completo para a proxima etapa
out = {"total": total, "multi": [(v, n) for v, n in sorted(multi, key=lambda kv: -kv[1])],
       "uni": sorted(uni), "by_file": {k: v for k, v in by_file.items()}}
with open(os.path.join(ROOT, "work", "_i18n_onda3_survey.json"), "w", encoding="utf-8") as f:
    json.dump(out, f, ensure_ascii=False, indent=1)
print()
print("survey salvo em work/_i18n_onda3_survey.json")
