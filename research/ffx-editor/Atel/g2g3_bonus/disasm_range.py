#!/usr/bin/env python3
# Focused EV01 disasm: dump ops in [pc0,pc1] of a given .ebp with var resolution.
import os, sys, glob
ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
BASE = 0x1EC
NS = {0x0:'Common',0x1:'Movie',0x2:'Mount',0x3:'Battle',0x4:'SgEvent',0x5:'ChEvent',0x6:'Camera',0x7:'Map'}
def u32(b,o): return b[o]|(b[o+1]<<8)|(b[o+2]<<16)|(b[o+3]<<24)
def chunk0(d):
    offs,i=[],4
    while i+4<=len(d):
        v=u32(d,i)
        if v==0xFFFFFFFF: break
        offs.append(v); i+=4
    present=[o for o in offs[:-1] if o]
    return 0x40
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
        raw=vl[vi]; space=(raw>>25)&7
        return (raw&0xFFFFFF, space)
    return (None,None)
def main(path,pc0,pc1):
    d=open(path,'rb').read(); c0=chunk0(d); blob=d[c0:]
    cl,ss,vl=atel(blob); oplist=ops(blob,ss,cl)
    for pc,op,o in oplist:
        if pc<pc0 or pc>pc1: continue
        s=f"{pc:06x}  {op:02X}"
        if o is not None:
            s+=f" {o:04x}"
            if op in (0x9F,0xA0,0xA1,0xA2,0xA3,0xA4,0xA7):
                sl,sp=slot(vl,o)
                s+=f"  -> slot=0x{sl:03x} space={sp}" if sl is not None else "  -> ?"
            elif op in (0xD8,0xB5):
                s+=f"  -> {'CALL' if op==0xD8 else 'CALLW'} {NS.get((o>>12)&0xF,'?')}:{o&0xFFF:03X}"
            elif op==0xAE:
                v=o if o<0x8000 else o-0x10000; s+=f"  (={v})"
        print(s)
if __name__=='__main__':
    main(sys.argv[1], int(sys.argv[2],0), int(sys.argv[3],0))
