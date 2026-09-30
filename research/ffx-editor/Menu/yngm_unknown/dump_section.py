#!/usr/bin/env python3
# dump_section.py — precise byte map of one YNGM record vs the serialized layout
# from FFX_RcBg_SerializeSceneBin@0x92B2F0: u32 k | u32 blobSize | blob[blobSize]
# | fixed 0x70/0x20/0x10/0x40/0x40.  usage: dump_section.py <mapout.vpa> <yngm_off>
import struct,sys
def u16(b,o): return struct.unpack_from('<H',b,o)[0]
def u32(b,o): return struct.unpack_from('<I',b,o)[0]
def f32(b,o): return struct.unpack_from('<f',b,o)[0]
b=open(sys.argv[1],'rb').read(); off=int(sys.argv[2],0)
f04=u32(b,off+4); tc,vc=u16(b,off+0x28),u16(b,off+0x2A); f14=u32(b,off+0x14); f20=u32(b,off+0x20)
rec_end=off+16+16*f04
pool_end=off+0x48+tc*20+vc*6
MARK=bytes.fromhex('1c0000000000f00144000000')+b'\x00'*8
m=b.find(MARK,pool_end,pool_end+96)
print('file=%s yngm=%#x f04=%d (payload=%dB) tri=%d vert=%d f14=%d f20=%d'%(sys.argv[1],off,f04,16*f04,tc,vc,f14,f20))
print('record [%#x..%#x)  next magic=%r'%(off,rec_end,b[rec_end:rec_end+4]))
print('serialized view: k=u32@%#x=%d  size=u32@%#x=%d'%(off+0x10,u32(b,off+0x10),off+0x14,f14))
print('  blob [%#x..%#x)  pool_end(count-based)=%#x  marker=%#x  blob_end==marker? %s'%(off+0x18,off+0x18+f14,pool_end,m,off+0x18+f14==m))
print('  extra pool bytes (pool_end..marker): %d'%(m-pool_end))
fx=off+0x18+f14  # fixed block start
print('  fixed block [%#x..%#x) 288B -> obj+0x20/0x90/0xB0/0xC0/0x100'%(fx,fx+0x120))
print('  slack after fixed reads: %d B'%(rec_end-(fx+0x120)))
def hx(o,n):
    return ' '.join('%02x'%c for c in b[o:o+n])
print('\n-- sub-header (blob[0:0x30] = YNGM+0x18..0x47) --')
for r in range(0,0x30,8):
    print('  blob+%02x: %s'%(r,hx(off+0x18+r,8)))
print('-- first tri + first verts --')
print('  tri0: %s'%hx(off+0x48,20))
print('  vert0..2: %s'%hx(off+0x48+tc*20,18))
print('-- extra pool region [pool_end..marker) --')
print('  %s'%hx(pool_end,m-pool_end))
print('-- fixed 288-B block (marker + meta) u32/f32 map --')
for r in range(0,0x120,16):
    o=fx+r
    vals_u=' '.join('%08X'%u32(b,o+4*j) for j in range(4))
    vals_f=' '.join('%11.4g'%f32(b,o+4*j) for j in range(4))
    print('  +%03x u32[%s] f32[%s]'%(r,vals_u,vals_f))
print('-- slack tail --')
print('  %s'%hx(fx+0x120,rec_end-(fx+0x120)))
