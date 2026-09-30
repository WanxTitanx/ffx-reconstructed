#!/usr/bin/env python3
# find F6 <label> markers and the code following them
import os, sys
BASE=0x1EC
NS={0x0:'Common',0x1:'Movie',0x2:'Mount',0x3:'Battle',0x4:'SgEvent',0x5:'ChEvent',0x6:'Camera',0x7:'Map'}
def u32(b,o): return b[o]|(b[o+1]<<8)|(b[o+2]<<16)|(b[o+3]<<24)
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
    if vi<len(vl):
        raw=vl[vi]; return (raw&0xFFFFFF,(raw>>25)&7)
    return (None,None)
def opstr(op,o,vl):
    s=f"{op:02X}"
    if o is None: return s
    s+=f" {o:04x}"
    if op in (0x9F,0xA0,0xA1,0xA2,0xA3,0xA4,0xA7):
        sl,sp=slot(vl,o); s+=f" [slot=0x{sl:03x} sp={sp}]" if sl is not None else " [?]"
    elif op in (0xD8,0xB5): s+=f" {'CALL' if op==0xD8 else 'CALLW'} {NS.get((o>>12)&0xF,'?')}:{o&0xFFF:03X}"
    elif op==0xAE: s+=f" (={o if o<0x8000 else o-0x10000})"
    return s
path=sys.argv[1]; label=int(sys.argv[2],0); span=int(sys.argv[3],0) if len(sys.argv)>3 else 60
d=open(path,'rb').read(); blob=d[0x40:]
cl,ss,vl=atel(blob); oplist=ops(blob,ss,cl)
found=None
for i,(pc,op,o) in enumerate(oplist):
    if op==0xF6 and o==label:
        found=i
        print(f"--- label {label} @ {pc:06x} ---")
        for pc2,op2,o2 in oplist[i:i+span]:
            print(f"{pc2:06x}  {opstr(op2,o2,vl)}")
        break
if found is None: print(f"label {label} not found")
