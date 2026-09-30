import sys, os, struct, collections, csv, json, re
sys.path.insert(0,'/mnt/ssd-kingston/ffx-reconstructed/tools/match')
import lib_vs_exe as L

d=open('/home/wanderson/Documents/ffx-editor-main/work/_ppp_pool/FFX.exe','rb').read()
e=struct.unpack_from('<I',d,0x3c)[0]
nsec=struct.unpack_from('<H',d,e+6)[0]
sz=struct.unpack_from('<H',d,e+20)[0]
base=struct.unpack_from('<I',d,e+24+28)[0]
SECS=[]
for i in range(nsec):
    o=e+24+sz+i*40
    nm=d[o:o+8].rstrip(b'\x00').decode('latin-1')
    vs,va,rs,rp=struct.unpack_from('<IIII',d,o+8)
    SECS.append((nm,base+va,vs,rp,rs))
def read_va(va,n):
    for nm,v,vs,rp,rs in SECS:
        if v<=va<v+max(vs,rs):
            off=rp+(va-v); return d[off:off+n]
    return None
by_size=collections.defaultdict(list)
for r in csv.DictReader(open('/mnt/ssd-kingston/ffx-reconstructed/tools/match/inventory.tsv'),delimiter='\t'):
    by_size[int(r['size'])].append((int(r['start'],16), r['name']))
VA_HI=0x02600000
def eq(cand, ref):
    if len(cand)!=len(ref): return False
    mask=set()
    for k in range(len(cand)-3):
        if cand[k:k+4]==ref[k:k+4]: continue
        v=struct.unpack_from('<I',ref,k)[0]
        if 0x400000<=v<VA_HI: mask.update((k,k+1,k+2,k+3)); continue
        if k>=1 and cand[k-1]==ref[k-1] and ref[k-1] in (0xE8,0xE9): mask.update((k,k+1,k+2,k+3))
    for j in range(len(cand)):
        if cand[j]!=ref[j] and j not in mask: return False
    return True

def score_lib(path):
    data=open(path,'rb').read()
    members=L.parse_archive(data)
    conf=[]; amb=0; scanned=0
    for name, off, size in members:
        try: secs=L.coff_sections(data, off, size)
        except Exception: continue
        for s in secs:
            if not s['name'].startswith('.text'): continue
            b=s['text']
            if len(b)<16: continue
            # strip trailing zero padding to 16-byte boundary? keep exact first
            scanned+=1
            hits=[]
            for va, iname in by_size.get(len(b),()):
                ref=read_va(va,len(b))
                if ref and eq(b,ref): hits.append((va,iname))
            if len(hits)==1: conf.append((hits[0][0], hits[0][1], len(b), s['name']))
            elif len(hits)>1: amb+=1
    return conf, amb, scanned

SDK='/mnt/nvme-samsung/PSVITA SDK LEAk/PhyreEngine/Lib/Win32/vs2012'
LIBNAMES=['BulletCollision.lib','BulletDynamics.lib','LinearMath.lib','BulletMultiThreaded.lib',
          'lua.lib','expat.lib','squish.lib','SceHeatWave.lib','RecastNavigation.lib',
          'BulletCollisionD.lib','BulletDynamicsD.lib','LinearMathD.lib','luaD.lib']
allconf={}
for ln in LIBNAMES:
    p=os.path.join(SDK,ln)
    if not os.path.exists(p): continue
    conf,amb,sc=score_lib(p)
    tot=sum(c[2] for c in conf)
    print(f'{ln:26s} sections={sc:5d} confirmed={len(conf):4d} bytes={tot:7,d} ambiguous={amb}')
    allconf[ln]=conf
json.dump({k:[{'va':c[0],'idb_name':c[1],'size':c[2],'section':c[3]} for c in v] for k,v in allconf.items()},
          open('/mnt/ssd-kingston/ffx-reconstructed/recon/sdk_libs_confirmed.json','w'), indent=1)
print('\nwrote recon/sdk_libs_confirmed.json')
