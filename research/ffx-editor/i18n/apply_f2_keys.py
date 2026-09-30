#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Aplica as 54 chaves F2_ faltantes nos 3 arquivos i18n (com backup atomico).
# Idempotente: so insere props/<data> que ainda nao existem. Padrao identico ao usado
# pelo pipeline i18n fase 2 (Strings.cs: getter via nameof; resx: <data xml:space=preserve>).
import json, io, os, shutil, time
base = r"C:\Users\wande\Documents\ffx-editor-main"
merged = json.load(io.open(base + r"\work\_f2_merged.json", encoding="utf-8"))

CS   = base + r"\FFXProjectEditor\Resources\Strings.cs"
RESX = base + r"\FFXProjectEditor\Resources\Strings.resx"
PT   = base + r"\FFXProjectEditor\Resources\Strings.pt.resx"

ts = time.strftime("%Y%m%d_%H%M%S")
for p in (CS, RESX, PT):
    shutil.copy2(p, p + f".i18n_bak_{ts}")
print("backups:", ts)

def esc(s):
    return s.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;")

# ---------- Strings.cs: add missing props before the final closing brace ----------
cs = io.open(CS, encoding="utf-8", newline="").read()
lines = cs.split("\n")
existing_cs = set()
for l in lines:
    m = None
    import re
    m = re.search(r"public static string (F2_[A-Za-z0-9_]+) =>", l)
    if m:
        existing_cs.add(m.group(1))
new_props = [k for k in merged if k not in existing_cs]
print("strings.cs props a adicionar:", len(new_props))
if new_props:
    # rebuild: inserir bloco antes da ultima '}' no top-level da classe
    block = "\n".join(
        "    public static string {0} => Get(nameof({0}));".format(k)
        for k in sorted(new_props)
    )
    # find last '}' line (class close)
    last = len(lines) - 1
    while last >= 0 and lines[last].strip() != "}":
        last -= 1
    if last < 0:
        raise SystemExit("nao achei fechamento da classe em Strings.cs")
    insertion = "".join([lines[i] + "\n" for i in range(last)]) + block + "\n" + lines[last] + "\n"
    cs = insertion
    io.open(CS, "w", encoding="utf-8", newline="").write(cs)
    print("Strings.cs atualizado")
# ---------- helper: insert <data> into a .resx before closing </root> ----------
def apply_resx(path, kv, lang):
    data = io.open(path, encoding="utf-8", newline="").read()
    # existing names
    import re
    names = set(re.findall(r'name="([A-Za-z0-9_]+)"', data))
    to_add = [k for k in kv if k not in names]
    print(f"{lang}: <data> a adicionar = {len(to_add)}")
    if not to_add:
        return
    close = data.rfind("</root>")
    if close < 0:
        raise SystemExit(f"</root> nao encontrado em {path}")
    prepend = "\n".join(
        '  <data name="%s" xml:space="preserve"><value>%s</value></data>' % (k, esc(kv[k]))
        for k in sorted(to_add)
    )
    insert = "\n" + prepend + "\n"
    data = data[:close] + insert + data[close:]
    io.open(path, "w", encoding="utf-8", newline="").write(data)
    print(f"{lang}: {path} atualizado")

apply_resx(RESX, {k: v["en"] for k, v in merged.items()}, "RESX(EN)")
apply_resx(PT,   {k: v["pt"] for k, v in merged.items()}, "PT")
print("DONE")

