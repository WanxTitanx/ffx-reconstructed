# -*- coding: utf-8 -*-
import os, re, io, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")
root = r'FFXProjectEditor'
PT_ATTR = re.compile(r'(?P<attr>Text|Content|Header|ToolTip|Watermark|Placeholder|Description|Title|Label|Inscription)="(?P<val>[^"]*)"', re.I)
PT_WORD = re.compile(r"[\u00E3\u00F5\u00E1\u00E9\u00ED\u00F3\u00FA\u00E0\u00E8\u00EC\u00F2\u00F9\u00E2\u00EA\u00E9\u00F4\u00E7\u00F1]|não|para o|para a|usuario|usuario|voc|deseja|clique|salvar|carregar|fechar|cancelar|gravar|editar|deseja", re.I)

def decode(p):
    b=open(p,'rb').read()
    for enc in ('utf-8-sig','utf-16','latin-1'):
        try:
            return b.decode(enc)
        except Exception:
            continue
    return b.decode('utf-8', errors='replace')

def is_pt(s):
    if not s: return False
    s2=s.replace('\uFFFD','')
    if not s2: return False
    return bool(PT_WORD.search(s2)) and not s.startswith('{') and 'x:Static' not in s and 'res:Strings' not in s

total=0; byfile={}; examples=[]
for dp,_,fs in os.walk(root):
    if any(x in dp for x in ('obj','bin','Generated')): continue
    for f in fs:
        if not f.endswith('.axaml'): continue
        p=os.path.join(dp,f); rel=os.path.relpath(p).replace('\\','/')
        try: txt=decode(p)
        except Exception: continue
        for m in PT_ATTR.finditer(txt):
            val=m.group('val')
            if is_pt(val):
                ln=txt[:m.start()].count('\n')+1
                total+=1; byfile[rel]=byfile.get(rel,0)+1
                examples.append((rel,ln,m.group('attr'),val))
print('TOTAL literais PT em atributos AXAML:', total)
print('ARQUIVOS:', len(byfile))
print('=== exemplos ===')
for rel,ln,attr,val in sorted(examples, key=lambda x:(x[0],x[1])):
    print(f'{rel}:{ln} [{attr}] = {val!r}')
