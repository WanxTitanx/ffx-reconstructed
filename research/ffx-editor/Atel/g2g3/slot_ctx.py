#!/usr/bin/env python3
# G2G3-COUNTERS: for given SaveData slots, dump every var-access instruction in
# the 397-.ebp corpus with decoded context, and classify what each STORE writes.
# Reuses the proven EV01 walk from research_tools/Atel/ev01_savevar_mining.py.
import os, sys, json, glob
from collections import Counter, defaultdict

DEFAULT_ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2"
SAVEDATA_BASE = 0x1EC
VAR_OPS = {0x9F:"PUSHV",0xA0:"POPV",0xA1:"POPVL",0xA2:"PUSHAR",0xA3:"POPAR",0xA4:"POPARL",0xA7:"PUSHARP"}
NS = {0x00:'Common',0x10:'Math',0x20:'SgEvent',0x30:'ChEvent',0x50:'Field',
      0x60:'Camera',0x70:'Battle',0x80:'Map',0x90:'Mount',0xA0:'Movie',
      0xB0:'Debug',0xC0:'AbiMap',0x40:'EVT40'}

def u16(b,o): return b[o]|(b[o+1]<<8)
def u32(b,o): return b[o]|(b[o+1]<<8)|(b[o+2]<<16)|(b[o+3]<<24)

def parse_ebp_chunk0(data):
    if data[:4]!=b'EV01': return None
    offs,i=[],4
    while i+4<=len(data):
        v=u32(data,i)
        if v==0xFFFFFFFF: break
        offs.append(v); i+=4
    present=[o for o in offs[:-1] if o]
    if not present or present[0]!=0x40: return None
    return 0x40,(present[1] if len(present)>1 else offs[-1])

def parse_atel_blob(blob):
    code_len=u32(blob,0); script_start=u32(blob,0x30); w0=u32(blob,0x38)
    vars_off=u32(blob,w0+0x14); int_off=u32(blob,w0+0x18)
    n=(int_off-vars_off)//8 if vars_off and int_off>vars_off else 0
    vars=[(u32(blob,vars_off+8*k),u32(blob,vars_off+8*k+4)) for k in range(n)]
    return code_len,script_start,vars

def walk(blob, script_start, code_len):
    ops=[]; i=script_start; end=script_start+code_len
    while i<end:
        op=blob[i]
        if not (op&0x80): ops.append((i-script_start,op,None)); i+=1; continue
        if i+3>end: break
        ops.append((i-script_start,op,blob[i+1]|(blob[i+2]<<8))); i+=3
    return ops

def dec(op,operand,vars):
    if op in (0xD8,0xB5,0xB6):
        ns=(operand>>8)&0xFF
        m={0xD8:'CALL',0xB5:'CALLW',0xB6:'CALLNW'}[op]
        return f"{m} {NS.get(ns&0xF0,hex(ns))}:{operand&0xFF:02X}"
    if op==0xAE:
        v=operand if operand<0x8000 else operand-0x10000
        return f"PUSHI {v}"
    if op==0x9F or op in (0xA0,0xA1):
        tag={0x9F:'PUSHV',0xA0:'POPV',0xA1:'POPVL'}[op]
        if operand<len(vars):
            lo,hi=vars[operand]
            return f"{tag} vi={operand} [slot {lo&0xFFFFFF:#x} t{(lo>>25)&7} type{(lo>>28)&0xF} cnt{hi&0xFFFF}]"
        return f"{tag} vi={operand}"
    if op in (0xA2,0xA3,0xA4,0xA7):
        tag={0xA2:'PUSHAR',0xA3:'POPAR',0xA4:'POPARL',0xA7:'PUSHARP'}[op]
        if operand<len(vars):
            lo,hi=vars[operand]
            return f"{tag} vi={operand} [slot {lo&0xFFFFFF:#x} cnt{hi&0xFFFF}]"
        return f"{tag} vi={operand}"
    if op==0xAD: return f"PUSHPOOL {operand}"
    if op==0xAF: return f"PUSHF pool={operand}"
    if op==0xD7: return f"JMP? ->{operand:#x}"
    if op==0x0E: return f"JIF ->{operand:#x}"
    if op in (0x29,): return "DUP?"
    if op in (0x36,0x38): return f"{op:02X} (setelem?)"
    if op==0x25: return "25"
    if op==0x06: return "EQ?"
    if op==0x0A: return "0A"
    if op==0x0B: return "0B"
    if op==0x3C: return "POP?"
    if op==0x2C: return "2C"
    if op==0x77: return "77"
    if op==0x54: return "54"
    if op==0xB0: return f"B0 {operand:#x}"
    if op==0xB3: return f"B3 {operand:#x}"
    return f"{op:02X}"+(f" {operand:04X}" if operand is not None else "")

def classify_store(ops, idx, vars):
    """For a store op at ops[idx], walk back to find the pushed value."""
    # find last PUSH/CALL-producer within ~6 ops before
    for j in range(idx-1, max(-1,idx-8), -1):
        pc,op,operand=ops[j]
        if op==0xAE:
            v=operand if operand<0x8000 else operand-0x10000
            return f"const {v}"
        if op in (0xD8,0xB5,0xB6):
            ns=(operand>>8)&0xFF
            return f"ret {NS.get(ns&0xF0,hex(ns))}:{operand&0xFF:02X}"
        if op==0x9F:
            return f"var vi={operand}"
        if op in (0xA2,0xA7):
            return f"arr vi={operand}"
        if op==0xAF: return f"pool {operand}"
        if op==0xAD: return f"poolvar {operand}"
        if op==0x29: return "dup"
    return "?"

def main():
    targets=[int(x,0) for x in sys.argv[1].split(',')]  # slots (hex)
    ctx=int(sys.argv[2]) if len(sys.argv)>2 else 22
    root=DEFAULT_ROOT
    files=sorted(glob.glob(os.path.join(root,'ffx/master/jppc/event/obj','**','*.ebp'),recursive=True))
    print('files:',len(files))
    hits=defaultdict(list)
    store_src=defaultdict(Counter)
    for path in files:
        data=open(path,'rb').read()
        ch=parse_ebp_chunk0(data)
        if not ch: continue
        s,e=ch; blob=data[s:e]
        code_len,script_start,vars=parse_atel_blob(blob)
        ops=walk(blob,script_start,code_len)
        # map var-index -> slot for SaveData vars
        for idx,(pc,op,operand) in enumerate(ops):
            if op not in VAR_OPS or operand is None or operand>=len(vars): continue
            lo,hi=vars[operand]
            loc=(lo>>25)&7
            if loc!=0: continue
            slot=lo&0xFFFFFF
            if slot in targets:
                hits[slot].append((path,idx,pc,op,operand,ops,vars))
                if VAR_OPS[op] in ('POPV','POPVL','POPAR','POPARL'):
                    store_src[slot][classify_store(ops,idx,vars)]+=1
    for slot in targets:
        hs=hits.get(slot,[])
        print(f"\n{'='*70}\nSLOT {slot:#x}  (Fh {slot+SAVEDATA_BASE:#x})  accesses={len(hs)}")
        print('store sources:',dict(store_src.get(slot,{})))
        # group by file
        byfile=defaultdict(list)
        for h in hs: byfile[h[0]].append(h)
        print('files:',len(byfile))
        # print full context for first N files
        shown=0
        for path,fl in sorted(byfile.items()):
            if shown>=4: break
            shown+=1
            print(f"\n  ---- {os.path.basename(path)} ({len(fl)} hits) ----")
            for (p,idx,pc,op,operand,ops,vars) in fl[:3]:
                lo,hi=vars[operand]
                print(f"   hit @{pc:05x} {VAR_OPS[op]} vi={operand} slot={lo&0xFFFFFF:#x} cnt={hi&0xFFFF}")
                for pc2,op2,operand2 in ops[max(0,idx-ctx):idx+6]:
                    mark='>>>' if pc2==pc else '   '
                    print(f"   {mark} @{pc2:05x}: {dec(op2,operand2,vars)}")
                print()
if __name__=='__main__':
    main()
