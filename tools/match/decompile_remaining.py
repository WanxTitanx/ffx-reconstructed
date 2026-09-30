#!/usr/bin/env python3
"""Decompile inventory functions missing from all supplied output directories.

Inputs: IDB, inventory TSV, output directory, then one or more directories to
exclude. Waits for IDA auto-analysis before asking Hex-Rays.
"""
import os, sys, collections
import idapro
import ida_auto
import ida_funcs
import ida_hexrays

i64, inv_path, outdir, *excluded = sys.argv[1:]
os.makedirs(outdir, exist_ok=True)
existing = set()
for d in excluded:
    if not os.path.isdir(d):
        continue
    for n in os.listdir(d):
        if n.startswith('d') and n.endswith('.c'):
            try:
                existing.add(int(n[1:-2], 16))
            except ValueError:
                pass

todo = []
with open(inv_path, encoding='utf-8', errors='replace') as f:
    f.readline()
    for line in f:
        p = line.rstrip('\n').split('\t')
        if len(p) < 6:
            continue
        va, size, name = int(p[0],16), int(p[2]), p[5]
        if va not in existing and not os.path.exists(os.path.join(outdir, 'd%08X.c' % va)):
            todo.append((va,size,name))
print('excluded addresses:',len(existing),'to decompile:',len(todo),flush=True)

idapro.open_database(i64, False)
ida_auto.auto_wait()
if not ida_hexrays.init_hexrays_plugin():
    raise RuntimeError('Hex-Rays plugin unavailable')
print('auto-analysis complete',flush=True)

ok=0; none=0; exceptions=collections.Counter()
for i,(va,size,name) in enumerate(todo,1):
    try:
        hf=ida_hexrays.hexrays_failure_t()
        cf=ida_hexrays.decompile(va,hf)
    except Exception as e:
        cf=None
        exceptions[type(e).__name__]+=1
    if cf is None:
        none+=1
        continue
    with open(os.path.join(outdir,'d%08X.c'%va),'w',encoding='utf-8') as f:
        f.write('// Function: %s\n// Address: 0x%X\n// Size: 0x%X\n'%(name,va,size))
        f.write(str(cf))
    ok+=1
    if ok%500==0:
        print('progress scanned=%d/%d wrote=%d none=%d'%(i,len(todo),ok,none),flush=True)
print('finished scanned=%d wrote=%d none=%d exceptions=%s'%(len(todo),ok,none,dict(exceptions)),flush=True)
idapro.close_database(False)

