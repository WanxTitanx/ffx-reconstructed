#!/usr/bin/env python3
# measure3.py — blob interior with CORRECT base (verts at blob+f20, not after tris)
import os, struct
from collections import Counter
ROOT="/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc"
MARK=bytes.fromhex('1c0000000000f00144000000')+b'\x00'*8
def u16(b,o): return struct.unpack_from('<H',b,o)[0]
def i16(b,o):
    v=u16(b,o); return v-0x10000 if v>=0x8000 else v
def u32(b,o): return struct.unpack_from('<I',b,o)[0]
def f32(b,o): return struct.unpack_from('<f',b,o)[0]
C=Counter; stats={k:C() for k in ('gap','gap_ff','gap_rest_nonzero','tail','tail_nonzero',
    'b00','b04','b14','b16','b18_20','b24_2c','b28_2c','vertY0','vertY0B','vidx_ok',
    'tri_pad','hdr0x30_47_zero','scale_sign','v7c_std','meta8_std','f14v','id0mod')}
ymin=9999;ymax=-9999;xmin=9999;xmax=-9999;zmin=9999;zmax=-9999
f20hist=C(); f14v=C(); id0mod=C()
for sub in ('map','btlmap'):
  for dp,_,fns in os.walk(os.path.join(ROOT,sub)):
    for fn in fns:
      if fn.lower()!='mapout.vpa': continue
      p=os.path.join(dp,fn); b=open(p,'rb').read()
      if len(b)<=0x80 or b[:4]!=b'MAP1': continue
      sec=u32(b,0x3C)
      if sec==0 or b[sec:sec+4]!=b'YNDT': continue
      off=sec+0x10; g=0
      while off+4<=len(b) and g<64:
        g+=1
        if b[off:off+4]==b'YNED': break
        if b[off:off+4]!=b'YNGM': break
        f04=u32(b,off+4); tc,vc=u16(b,off+0x28),u16(b,off+0x2A)
        f14=u32(b,off+0x14); f20=u32(b,off+0x20)
        rec_end=off+16+16*f04; blob=off+0x18
        tris_end=blob+0x30+tc*20; verts=blob+f20; verts_end=verts+vc*6
        gap=f20-(0x30+tc*20); tail=f14-(f20+vc*6)
        stats['gap'][gap]+=1; stats['tail'][tail]+=1
        gb=b[tris_end:verts]
        stats['gap_ff'][gb[:2]==b'\xff\xff']+=1
        stats['gap_rest_nonzero'][sum(1 for c in gb[2:] if c)]+=1
        tb=b[verts_end:blob+f14]
        stats['tail_nonzero'][sum(1 for c in tb if c)]+=1
        # sub-header fields
        stats['b00'][u32(b,blob)]+=1; stats['b04'][u32(b,blob+4)]+=1
        stats['b14'][u16(b,blob+0x14)]+=1; stats['b16'][u16(b,blob+0x16)]+=1
        stats['b18_20'][b[blob+0x18:blob+0x22]==b'\x00'*10]+=1
        stats['b24_2c'][b[blob+0x24:blob+0x2C]==b'\x00'*8]+=1
        stats['b28_2c'][b[blob+0x2C:blob+0x30]==b'\x00'*4]+=1
        stats['f14v'][f14==u32(b,blob+0x0C)]+=1  # blob+0x0C == f14?
        # tri pad byte & index validity vs vc
        badix=0; badpad=0
        for t in range(tc):
            tb2=blob+0x30+t*20
            if u16(b,tb2+0x12)!=0: badpad+=1
            for j in (0x0C,0x0E,0x10):
                if u16(b,tb2+j)>=vc: badix+=1
        stats['tri_pad'][badpad]+=1; stats['vidx_ok'][badix]+=1
        # vert stats at CORRECT base
        for i in range(vc):
            x,y,z=i16(b,verts+i*6),i16(b,verts+i*6+2),i16(b,verts+i*6+4)
            if y!=0: stats['vertY0']['nonzero']+=1
            else: stats['vertY0']['zero']+=1
            if z!=0: stats['vertY0B']['nonzero']+=1
            else: stats['vertY0B']['zero']+=1
            xmin=min(xmin,x);xmax=max(xmax,x);ymin=min(ymin,y);ymax=max(ymax,y);zmin=min(zmin,z);zmax=max(zmax,z)
        # meta end-anchored
        mel=rec_end-(b.find(MARK,verts_end,verts_end+96)+20) if b.find(MARK,verts_end,verts_end+96)>0 else 0
        m=b.find(MARK,verts_end,verts_end+96)
        if m>0:
            mt=m+20
            stats['id0mod'][u16(b,mt+0x0C)%64]+=1
            stats['meta8_std'][u32(b,mt+8)]+=1
            sc=f32(b,rec_end-136)
            stats['scale_sign']['pos' if sc>0 else 'nonpos']+=1
        off=rec_end
for k,c in stats.items():
    print('%-20s %s'%(k,c.most_common(14) if len(c)>1 else dict(c)))
print('vert ranges: x[%d..%d] y[%d..%d] z[%d..%d]'%(xmin,xmax,ymin,ymax,zmin,zmax))
