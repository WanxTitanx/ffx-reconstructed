# -*- coding: utf-8 -*-
import os, re, io, collections, sys, json, hashlib
sys.stdout.reconfigure(encoding="utf-8", errors="replace")
root = r'FFXProjectEditor'
main = io.open(root+'/Modules/Main/Main_Window.axaml.cs', encoding='utf-8').read()
CTRL = set(re.findall(r'new ([A-Za-z0-9_]+_Control)\(\)', main))
# paleta PT (acentos + palavras-chave PT, para pegar strings sem acento)
PT = re.compile(r"[\u00e3\u00f5\u00e1\u00e9\u00ed\u00f3\u00fa\u00e0\u00e8\u00ec\u00f2\u00f9\u00e2\u00ea\u00f4\u00e7\u00f1\u00c3\u00d5\u00c1\u00c9\u00cd\u00d3\u00da\u00c0\u00c8\u00cc\u00d2\u00d9\u00c2\u00ca\u00d4\u00c7\u00d1]|n\u00e3o|para [ao]|usuario|vo[c?]|deseja|salvar|carregar|fechar|cancelar|gravar|editar|herdar|herdada|herdado|copiar|criar|destino|aviso|monstro|receita|falhar|falhou|campo|campos|inv\u00e1lido|bloco|perfil|mudan\u00e7|usu\u00e1do|comum|raro|qtd|selecion|fonte|pr\u00f3ximo|existe|encontrad|recompensa|combate|habilidade|usar|usado", re.I)
STR = re.compile(r'"((?:[^"\\]|\\.)*)"', re.S)

def decode(p):
    b=open(p,'rb').read()
    for enc in ('utf-8-sig','utf-16','latin-1'):
        try: return b.decode(enc)
        except: continue
    return b.decode('utf-8', errors='replace')
def strip_comments(txt):
    txt = re.sub(r'/\*.*?\*/', '', txt, flags=re.S)
    return re.sub(r'//[^\n]*', '', txt)

def is_active(pathseg):
    rel = pathseg
    parts = rel.split('/')
    if 'MonsterAiEditor2' in rel or 'SpiraForgeHub' in rel:
        return False
    if 'FfxLib' in parts:
        return True  # biblioteca usada pela UI
    # modulo ativo se algum controller da pasta esta roteado
    for c in parts:
        if c in CTRL: return True
    # dialogs/windows de um modulo ativo
    return False

def module_of(rel):
    parts=rel.split('/')
    if 'FfxLib' in parts: return 'FfxLib/'+(parts[parts.index('FfxLib')+1] if len(parts)>parts.index('FfxLib')+1 else '')
    if len(parts)>2 and parts[:2]==['FFXProjectEditor','Modules']: return parts[2]
    return parts[0]

res=collections.defaultdict(lambda: {'files':{}})
for dp,_,fs in os.walk(root):
    if any(x in dp for x in ('\\obj','\\bin','Generated')): continue
    for f in fs:
        if not (f.endswith('.cs') or f.endswith('.axaml')): continue
        p=os.path.join(dp,f); rel=os.path.relpath(p).replace('\\','/')
        if not is_active(rel): continue
        try: raw=decode(p)
        except: continue
        # .cs: remove comentarios; .axaml: analisa atributos de texto
        hits=[]
        if f.endswith('.cs'):
            code=strip_comments(raw)
            for i,line in enumerate(code.split('\n'),1):
                for m in STR.finditer(line):
                    s=m.group(1)
                    if 2<=len(s)<=160 and not s.startswith('{') and 'res:Strings' not in s and not s.startswith('res:') and PT.search(s) and s not in ('D:\\SteamLibrary\\steamapps\\common\\FINAL FANTASY FFX&FFX-2 HD Remaster\\magicFiles\\FFX','Custom_','inherit','copy'):
                        # evita constantes de modo/chave de config
                        if re.match(r'^(inherit|copy|copy-monster-ai|copy-monster-loot|inherit-base-ai|inherit-base-loot|pc|ps2|ps3)$', s, re.I): continue
                        hits.append((i,s))
        else:
            attr = re.compile(r'(?:Text|Content|Header|Title|ToolTip\\.Tip|Watermark|Inscription)="([^"]+)"', re.I)
            for m in attr.finditer(raw):
                s=m.group(1)
                if 2<=len(s)<=160 and not s.startswith('{') and PT.search(s):
                    ln=raw[:m.start()].count('\n')+1
                    hits.append((ln,s))
        if hits:
            mod=module_of(rel)
            res[mod]['files'][rel]=hits

out=[]
mods=sorted(res.items(), key=lambda kv: -sum(len(h) for h in kv[1]['files'].values()))
for mod,data in mods:
    total=sum(len(h) for h in data['files'].values())
    nfiles=len(data['files'])
    out.append((mod, total, nfiles, data['files']))
# dump json p/ usar no md
payload=[
  { "mod": mod, "total": total, "files": nfiles, "file_list": [
       { "path": p, "n": len(hs), "sample": hs[:4] }
       for p,hs in sorted(d.items())
   ] }
  for mod,total,nfiles,d in out
]
io.open('work/_i18n_inventory.json','w',encoding='utf-8').write(json.dumps(payload, ensure_ascii=False, indent=1))
print('TOTAL GERAL strings PT-UI em modulos ATIVOS:', sum(p['total'] for p in payload))
print('MODULOS:', len(payload))
for p in payload:
    print(f"  {p['mod']:38s} {p['total']:4d} str  em {p['files']:2d} arq")

