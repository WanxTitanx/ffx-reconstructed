#!/usr/bin/env python3
# Full-corpus writer scan for G2G3 bonus slots — every POPV/POPAR into targets.
import os, sys, glob
ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
BASE = 0x1EC
def u32(b,o): return b[o]|(b[o+1]<<8)|(b[o+2]<<16)|(b[o+3]<<24)
def chunk0(d):
    offs,i=[],4
    while i+4<=len(d):
        v=u32(d,i)
        if v==0xFFFFFFFF: break
        offs.append(v); i+=4
    present=[o for o in offs[:-1] if o]
    return 0x40,(present[1] if len(present)>1 else offs[-1])
def atel(blob):
    cl=u32(blob,0); ss=u32(blob,0x30); w0=u32(blob,0x38)
    vo=u32(blob,w0+0x14); io=u32(blob,w0+0x18)
    n=(io-vo)//8 if vo and io>vo else 0
    return cl,ss,[u32(blob,vo+8*k) for k in range(n)]
def ops(blob,ss,cl):
    end,i,out=ss+cl,ss,[]
    while i<end:
        op=blob[i]; pc=i-ss
        if op<0x80: out.append((pc,op,None)); i+=1; continue
        if i+3>end: break
        out.append((pc,op,blob[i+1]|blob[i+2]<<8)); i+=3
    return out
def slot(vl,vi):
    if vi<len(vl) and ((vl[vi]>>25)&7)==0: return vl[vi]&0xFFFFFF
    return None
targets=set(range(0x119,0x131))|{0x261,0x262,0x263,0x264,0x265}
hits={}
for p in sorted(glob.glob(ROOT+'/**/event/obj/**/*.ebp',recursive=True)):
    try:
        d=open(p,'rb').read(); c0,_=chunk0(d); blob=d[c0:]
        cl,ss,vl=atel(blob); oplist=ops(blob,ss,cl)
    except Exception: continue
    n=os.path.basename(p)
    for pc,op,o in oplist:
        if op in (0xA0,0xA1,0xA3,0xA4) and o is not None:
            s=slot(vl,o)
            if s in targets:
                hits.setdefault(n,[]).append((pc,op,s))
for n in sorted(hits):
    ss=hits[n]
    per={}
    for pc,op,s in ss: per.setdefault(s,[0,0]); per[s][0 if op in(0xA0,0xA1) else 1]+=1
    desc=', '.join(f"0x{s:03x}:{per[s][0]}v+{per[s][1]}a" for s in sorted(per))
    print(f"{n:28s} {len(ss):4d} stores  [{desc}]")
