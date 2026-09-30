# -*- coding: utf-8 -*-
import os, re, io, collections, sys, json
sys.stdout.reconfigure(encoding="utf-8", errors="replace")
root = r'FFXProjectEditor'
main = io.open(root+'/Modules/Main/Main_Window.axaml.cs', encoding='utf-8').read()
CTRL = set(re.findall(r'new ([A-Za-z0-9_]+_Control)\(\)', main))
PT = re.compile(r"[\u00e3\u00f5\u00e1\u00e9\u00ed\u00f3\u00fa\u00e0\u00e8\u00ec\u00f2\u00f9\u00e2\u00ea\u00f4\u00e7\u00f1\u00c3\u00d5\u00c1\u00c9\u00cd\u00d3\u00da\u00c0\u00c8\u00cc\u00d2\u00d9\u00c2\u00ca\u00d4\u00c7\u00d1]|herdar|herdada|herdado|copiar|criar|destino|aviso|monstro|receita|falhar|falhou|campo|campos|inv\u00e1lido|bloco|perfil|mudan\u00e7|usu\u00e1do|comum|raro|qtd|selecion|fonte|pr\u00f3ximo|encontrad|recompensa|combate|habilidade|usar|usado|salvar|carregar|gravar|cancelar|fechar", re.I)
STR = re.compile(r'"((?:[^"\\]|\\.)*)"', re.S)
# contexto que indica UI visivel vs mensagem interna
def is_ui_context(line):
    if re.search(r'\.(Text|Content|Header|ToolTip|Title|Items|Message|Summary|Label)\s*[+=]', line): return True
    if re.search(r'(Summary|Message|Status|Note|Hint|Label|Title|Description|ToolTip)\s*[;=]', line): return True
    if 'SetTip(' in line or 'ToolTip' in line: return True
    return False
def decode(p):
    b=open(p,'rb').read()
    for enc in ('utf-8-sig','utf-16','latin-1'):
        try: return b.decode(enc)
        except: continue
    return b.decode('utf-8', errors='replace')
def strip_comments(txt):
    txt = re.sub(r'/\*.*?\*/', '', txt, flags=re.S)
    return re.sub(r'//[^\n]*', '', txt)
def module_of(rel):
    parts=rel.split('/')
    if len(parts)>2 and parts[:2]==['FFXProjectEditor','Modules']: return 'Modules/'+parts[2]
    if 'FfxLib' in parts: return 'FfxLib/'+(parts[parts.index('FfxLib')+1] if len(parts)>parts.index('FfxLib')+1 else '')
    return 'Other'

def is_active(rel):
    if 'MonsterAiEditor2' in rel or 'SpiraForgeHub' in rel: return False
    parts=rel.split('/')
    if 'FfxLib' in parts: return True
    for c in parts:
        if c in CTRL: return True
    if parts and parts[-1].startswith(('MonsterAi','CustomBossCreator','DifficultyDirector','FormationEditor','LiveBattleLab','EventExplorer','SphereGrid')):
        return True
    return False
res=collections.defaultdict(lambda: {})
for dp,_,fs in os.walk(root):
    if any(x in dp for x in ('\\obj','\\bin','Generated')): continue
    for f in fs:
        if not f.endswith('.cs'): continue
        p=os.path.join(dp,f); rel=os.path.relpath(p).replace('\\','/')
        if not is_active(rel): continue
        try: code=strip_comments(decode(p))
        except: continue
        hits=[]
        for i,line in enumerate(code.split('\n'),1):
            for m in STR.finditer(line):
                s=m.group(1)
                if 2<=len(s)<=160 and not s.startswith('{') and PT.search(s) and s not in ('inherit','copy'):
                    # exige contexto de UI (labels/summary) OU throw/retorno de status
                    if is_ui_context(line) or 'throw new' in line:
                        hits.append((i,s))
        if hits:
            mod=module_of(rel)
            res[mod][rel]=hits
payload=[
  { "mod": mod, "total": sum(len(h) for h in d.items()),
    "files": [ { "path": p, "n": len(h), "sample": h[:5] } for p,h in sorted(d.items()) ] }
  for mod,d in sorted(res.items(), key=lambda kv:-sum(len(h) for h in kv[1].values()))
]
io.open('work/_i18n_inventory2.json','w',encoding='utf-8').write(json.dumps(payload, ensure_ascii=False, indent=1))
print('TOTAL PT-UI (contexto UI/throw):', sum(p['total'] for p in payload))
print('MODULOS:', len(payload))
for p in payload:
    print(f"  {p['mod']:40s} {p['total']:4d} str em {len(p['files']):2d} arq")
