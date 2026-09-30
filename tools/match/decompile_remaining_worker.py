#!/usr/bin/env python3
"""Resume Hex-Rays decompilation safely across RuntimeError poisons.

Hex-Rays can raise RuntimeError on some functions; after that the current
idalib process returns MERR_BUSY for every later function. This worker records
the address that threw, closes the database, and exits 3. A .bat supervisor
restarts a fresh idalib process, skipping the recorded bad address and all
outputs already written.

Usage: py -3.11 decompile_remaining_worker.py <idb> <inventory> <outdir> <exclude_dir> <badfile>
"""
import os, sys, collections
import idapro
import ida_auto
import ida_hexrays

i64, inv_path, outdir, exclude_dir, badfile = sys.argv[1:]
os.makedirs(outdir, exist_ok=True)
inflight = badfile + '.inflight'
existing = set()
for d in (exclude_dir, outdir):
    if os.path.isdir(d):
        for n in os.listdir(d):
            if n.startswith('d') and n.endswith('.c'):
                try:
                    existing.add(int(n[1:-2], 16))
                except ValueError:
                    pass
bad = set()
if os.path.exists(badfile):
    for line in open(badfile, encoding='ascii', errors='ignore'):
        try: bad.add(int(line.strip(),16))
        except ValueError: pass
if os.path.exists(inflight):
    try:
        crashed_va = int(open(inflight, encoding='ascii').read().strip(), 16)
        bad.add(crashed_va)
        with open(badfile, 'a', encoding='ascii') as f:
            f.write('%08X\n' % crashed_va)
        print('skipping address from previous native crash: %08X' % crashed_va, flush=True)
    except (ValueError, OSError):
        pass

todo=[]
with open(inv_path,encoding='utf-8',errors='replace') as f:
    f.readline()
    for line in f:
        p=line.rstrip('\n').split('\t')
        if len(p)<6: continue
        va,size,name=int(p[0],16),int(p[2]),p[5]
        if va not in existing and va not in bad:
            todo.append((va,size,name))
print('worker todo=%d existing=%d skipped_runtime=%d'%(len(todo),len(existing),len(bad)),flush=True)

idapro.open_database(i64,False)
ida_auto.auto_wait()
if not ida_hexrays.init_hexrays_plugin():
    raise RuntimeError('Hex-Rays plugin unavailable')
wrote=0; none=0; exceptions=collections.Counter()
for i,(va,size,name) in enumerate(todo,1):
    # If the Windows process dies in native Hex-Rays code, the marker survives.
    with open(inflight, 'w', encoding='ascii') as f:
        f.write('%08X' % va)
    try:
        hf=ida_hexrays.hexrays_failure_t()
        cf=ida_hexrays.decompile(va,hf)
    except RuntimeError as e:
        with open(badfile,'a',encoding='ascii') as f: f.write('%08X\n'%va)
        try: os.remove(inflight)
        except OSError: pass
        print('POISON %08X %s; restart required'%(va,str(e)[:100]),flush=True)
        try: idapro.close_database(False)
        except: pass
        raise SystemExit(3)
    except Exception as e:
        try: os.remove(inflight)
        except OSError: pass
        exceptions[type(e).__name__]+=1
        none+=1
        continue
    if cf is None:
        try: os.remove(inflight)
        except OSError: pass
        none+=1
        continue
    path=os.path.join(outdir,'d%08X.c'%va)
    with open(path,'w',encoding='utf-8') as f:
        f.write('// Function: %s\n// Address: 0x%X\n// Size: 0x%X\n'%(name,va,size))
        f.write(str(cf))
    try: os.remove(inflight)
    except OSError: pass
    wrote+=1
    if wrote % 1000 == 0:
        print('progress wrote=%d scanned=%d none=%d'%(wrote,i,none),flush=True)
print('worker complete scanned=%d wrote=%d none=%d exceptions=%s'%(len(todo),wrote,none,dict(exceptions)),flush=True)
idapro.close_database(False)
