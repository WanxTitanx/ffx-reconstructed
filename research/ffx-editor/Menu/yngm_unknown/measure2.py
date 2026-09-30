#!/usr/bin/env python3
# measure2.py — YNGM-UNKNOWN phase 2: semantic constraints on remaining fields.
# Corpus-wide stats for: record header u16s, blob sub-header fields, extra pool
# content class, meta tail fields (AABB, vec4, matrices, id pairs, marker).
import os, struct, json
from collections import Counter
ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc"
HSZ, SLOT = 0x80, 0x3C
MARK = bytes.fromhex('1c0000000000f00144000000') + b'\x00'*8
def u16(b,o): return struct.unpack_from('<H',b,o)[0]
def i16(b,o):
    v=u16(b,o); return v-0x10000 if v>=0x8000 else v
def u32(b,o): return struct.unpack_from('<I',b,o)[0]
def f32(b,o): return struct.unpack_from('<f',b,o)[0]
def files():
    hits=[]
    for sub in ('map','btlmap'):
        base=os.path.join(ROOT,sub)
        for dp,_,fns in os.walk(base):
            for fn in fns:
                if fn.lower()=='mapout.vpa': hits.append(os.path.join(dp,fn))
    return sorted(hits)
def yndt(b):
    if len(b)<=HSZ or b[:4]!=b'MAP1': return None
    sec=u32(b,SLOT)
    if sec==0 or sec+4>len(b) or b[sec:sec+4]!=b'YNDT': return None
    return sec
def walk(b,sec):
    out=[]; off=sec+0x10; g=0
    while True:
        g+=1
        if g>64 or off+4>len(b): return out
        mg=b[off:off+4]
        if mg==b'YNED': return out
        if mg!=b'YNGM': return out
        f04=u32(b,off+4)
        out.append(off); off=off+16+16*f04

C=lambda:Counter()
stats={k:C() for k in ('h08','h0a','h0c','h0e','f10','f20_resid48','f20_resid30','f20_resid_rec',
                       'meta0','meta8','rgba','id0','id0hi','id2','id2hi','iddelta',
                       'minw','maxw','miny','maxy','minx_lt_maxx','minz_lt_maxz',
                       'v7c','matA_kind','matB_kind','extrapool_nonzero','extrapool_tail0',
                       'markervar','tridup','tri_exceeds_vert','tri_exceeds_pool')}
ext_samples=[]
vert_ranges=[]
for p in files():
    b=open(p,'rb').read(); sec=yndt(b)
    if sec is None: continue
    for off in walk(b,sec):
        tc,vc=u16(b,off+0x28),u16(b,off+0x2A)
        f04=u32(b,off+4); f14=u32(b,off+0x14); f20=u32(b,off+0x20)
        rec_end=off+16+16*f04
        stats['h08'][u16(b,off+8)]+=1; stats['h0a'][u16(b,off+0x0A)]+=1
        stats['h0c'][u16(b,off+0x0C)]+=1; stats['h0e'][u16(b,off+0x0E)]+=1
        stats['f10'][u32(b,off+0x10)]+=1
        stats['f20_resid48'][f20-(0x48+tc*20)]+=1
        stats['f20_resid30'][f20-(0x30+tc*20)]+=1
        stats['f20_resid_rec'][f20-(0x30+tc*20+vc*6)]+=1  # vs pool_end blob-rel
        stats['tridup'][u16(b,off+0x3A)-tc]+=1
        # indices range
        worst=0; worstp=0
        for t in range(tc):
            tb=off+0x48+t*20
            for j in (0x0C,0x0E,0x10):
                ix=u16(b,tb+j)
                if ix>=vc: worst+=1
                # vs physical pool incl extra
                poolend=off+0x48+tc*20+vc*6
                m=b.find(MARK,poolend,poolend+96)
                physvc=vc+(m-poolend)//6 if m>0 else vc
                if ix>=physvc: worstp+=1
        stats['tri_exceeds_vert'][worst]+=1
        stats['tri_exceeds_pool'][worstp]+=1
        # vert coord ranges
        vb=off+0x48+tc*20
        if tc:
            xs=[i16(b,vb+i*6) for i in range(vc)]
            ys=[i16(b,vb+i*6+2) for i in range(vc)]
            zs=[i16(b,vb+i*6+4) for i in range(vc)]
            vert_ranges.append((min(xs),max(xs),min(ys),max(ys),min(zs),max(zs)))
        # extra pool content
        m=b.find(MARK,off+0x48+tc*20+vc*6,off+0x48+tc*20+vc*6+96)
        if m>0:
            ext=b[off+0x48+tc*20+vc*6:m]
            nz=sum(1 for c in ext if c)
            stats['extrapool_nonzero'][nz]+=1
            stats['extrapool_tail0'][len(ext)-nz]+=1
            if len(ext_samples)<12 and nz: ext_samples.append((os.path.relpath(p,ROOT),off,ext.hex()))
            # meta
            mt=m+20; mel=rec_end-mt
            stats['markervar'][b[m:m+20]==MARK]+=1
            stats['meta0'][u32(b,mt)]+=1; stats['meta8'][u32(b,mt+8)]+=1
            stats['rgba']["%08X"%u32(b,mt+4)]+=1
            stats['id0'][u16(b,mt+0x0C)]+=1; stats['id0hi'][u16(b,mt+0x0E)]+=1
            stats['id2'][u16(b,mt+0x1C)]+=1; stats['id2hi'][u16(b,mt+0x1E)]+=1
            stats['iddelta'][u16(b,mt+0x0C)-u16(b,mt+0x1C)]+=1
            mn=[f32(b,mt+0x5C+4*i) for i in range(4)]
            mx=[f32(b,mt+0x6C+4*i) for i in range(4)]
            stats['minw'][mn[3]]+=1; stats['maxw'][mx[3]]+=1
            stats['miny'][mn[1]]+=1; stats['maxy'][mx[1]]+=1
            stats['minx_lt_maxx'][mn[0]<mx[0]]+=1
            stats['minz_lt_maxz'][mn[2]<mx[2]]+=1
            stats['v7c'][tuple(f32(b,mt+0x7C+4*i) for i in range(4))]+=1
            mA=[f32(b,mt+0x8C+4*i) for i in range(16)]
            mB=[f32(b,mt+0xCC+4*i) for i in range(16)]
            def kind(mm):
                if mm==[1.0 if i in(0,5,10,15) else 0.0 for i in range(16)]: return 'identity'
                if mm[5]==mm[0] and mm[10]==mm[0] and mm[15]==1.0 and all(mm[i]==0.0 for i in range(16) if i not in (0,5,10,15)):
                    return 'uniform_scale'
                return 'other'
            stats['matA_kind'][kind(mA)]+=1; stats['matB_kind'][kind(mB)]+=1
for k,c in stats.items():
    items=c.most_common(12)
    print('%-18s %s'%(k,items if len(c)<=12 else str(items)+' ... (%d distinct)'%len(c)))
print('\nvert coord ranges across sections: x[%d..%d] y[%d..%d] z[%d..%d]'%(
    min(v[0] for v in vert_ranges),max(v[1] for v in vert_ranges),
    min(v[2] for v in vert_ranges),max(v[3] for v in vert_ranges),
    min(v[4] for v in vert_ranges),max(v[5] for v in vert_ranges)))
print('\nextra pool samples:')
for s in ext_samples: print(' ',s)
