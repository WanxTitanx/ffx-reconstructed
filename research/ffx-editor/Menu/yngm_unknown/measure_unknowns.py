#!/usr/bin/env python3
# measure_unknowns.py — YNGM-UNKNOWN lane (2026-09-15)
#
# Validates across the 491-file corpus:
#  A) UNKNOWN_A (YNGM+0x04) = record payload length in 16-B units — the generic
#     RSD scene-stream stride consumed by FFX_Render_ParseSceneBinData@0x921D60
#     (next record = rec + 16 + 16*count; magic dispatch via YN** table @0xC5E480).
#  B) The "matrices/paint" gap = per-section [extra pool + 20-B marker + 276-B
#     meta tail] then the NEXT YNGM record (chain), ending at YNED.
#  C) Inner serialization (FFX_RcBg_SerializeSceneBin@0x92B2F0):
#     +0x10 u32 k, +0x14 u32 blobSize, blob[blobSize], then 0x70/0x20/0x10/0x40/0x40.
#
# Read-only on the corpus. Stdlib only.
import os, struct, sys, json
from collections import Counter

ROOT = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc"
HSZ, SLOT, YREL = 0x80, 0x3C, 0x10
MARK = bytes.fromhex('1c0000000000f00144000000') + b'\x00' * 8

def u16(b,o): return struct.unpack_from('<H',b,o)[0]
def i16(b,o):
    v=u16(b,o); return v-0x10000 if v>=0x8000 else v
def u32(b,o): return struct.unpack_from('<I',b,o)[0]
def f32(b,o): return struct.unpack_from('<f',b,o)[0]

def iter_corpus(root):
    hits=[]
    for sub in ('map','btlmap'):
        base=os.path.join(root,sub)
        if not os.path.isdir(base): continue
        for dp,_,fns in os.walk(base):
            for fn in fns:
                if fn.lower()=='mapout.vpa': hits.append(os.path.join(dp,fn))
    return sorted(hits)

def yndt_section(b):
    """offset of the guide YNDT section (MAP1 slot +0x3C) or None."""
    if len(b) <= HSZ or b[:4]!=b'MAP1': return None,'not-map1/stub'
    sec = u32(b,SLOT)
    if sec==0 or sec+4>len(b) or b[sec:sec+4]!=b'YNDT': return None,'no-guide'
    if b[sec+0x10:sec+0x14]==b'YNED': return sec,'empty-guide'
    return sec,'ok'

def walk_sections(b, sec):
    """Walk the record chain using the +0x04 stride law. Returns (sections, verdict)."""
    out=[]; off=sec+YREL; guard=0
    while True:
        guard+=1
        if guard>64: return out,'runaway'
        if off+4>len(b): return out,'oob'
        mg=b[off:off+4]
        if mg==b'YNED': return out,'ok'
        if mg!=b'YNGM': return out,'bad-magic@0x%X'%off
        f04=u32(b,off+4)
        tc,vc=u16(b,off+0x28),u16(b,off+0x2A)
        rec_end = off + 16 + 16*f04          # stride law
        nxt = b[rec_end:rec_end+4] if rec_end+4<=len(b) else b''
        out.append({'off':off,'f04':f04,'tri':tc,'vert':vc,
                    'f14':u32(b,off+0x14),'f20':u32(b,off+0x20),'f24':u32(b,off+0x24),
                    'f10':u32(b,off+0x10),'f1c':u32(b,off+0x1C),'f2e':u16(b,off+0x2E),
                    'rec_end':rec_end,'next_magic':nxt.decode('ascii','replace')})
        off=rec_end

def section_detail(b, s):
    """Full inner layout of one YNGM section."""
    off=s['off']; tc,vc=s['tri'],s['vert']
    pool_end = off + 0x48 + tc*20 + vc*6
    m = b.find(MARK, pool_end, pool_end+96)
    blob_start = off+0x18
    blob_end = blob_start + s['f14']
    meta_start = m+20 if m>=0 else -1
    rec_end = s['rec_end']
    d = dict(s)
    d['pool_end']=pool_end
    d['marker_at']=m
    d['extra_pool']= (m-pool_end) if m>=0 else None
    d['meta_len']= (rec_end - meta_start) if m>=0 else None
    d['blob_covers'] = blob_end            # YNGM-relative end of serialized blob
    d['blob_end_minus_marker'] = (blob_end - m) if m>=0 else None
    # serialized model: const(4)+size(4)+blob(f14) then fixed 272 (0x70+0x20+0x10+0x40+0x40)
    d['serial_end'] = off+0x10 + 4 + 4 + s['f14'] + 272
    d['serial_slack'] = rec_end - d['serial_end']
    # candidate: does f14 reach exactly the marker? or meta? or pool_end?
    d['f14_to_marker'] = (m - blob_end) if m>=0 else None   # 0 => blob ends AT marker
    d['f14_to_poolend'] = blob_end - pool_end               # >0 => blob covers extra pool
    # meta tail fields (if meta exists and >= 0x114)
    if m>=0 and rec_end-meta_start>=0x114:
        mt=meta_start
        d['meta_u32_0']=u32(b,mt)
        d['meta_rgba']='%08X'%u32(b,mt+4)
        d['meta_id0']=u16(b,mt+0x0C); d['meta_id1']=u16(b,mt+0x0E)
        d['meta_id2']=u16(b,mt+0x1C); d['meta_id3']=u16(b,mt+0x1E)
        # homogeneous points region and matrices sampled as floats
        d['meta_pts']=[round(f32(b,mt+x),4) for x in (0x58,0x5C,0x60,0x64,0x68,0x6C,0x70,0x74)]
        d['meta_scale']=[round(f32(b,mt+x),6) for x in (0x8C,0x9C,0xAC)]
        d['meta_tail4']=' '.join('%02x'%c for c in b[rec_end-4:rec_end])
    return d

def main():
    paths=iter_corpus(ROOT)
    stats=Counter(); sections=[]; fails=[]
    f04_hist=Counter(); meta_lens=Counter(); marker_ok=0; marker_missing=[]
    f14_to_marker=Counter(); slack=Counter(); rgba=Counter(); extra_hist=Counter()
    for p in paths:
        b=open(p,'rb').read()
        rel=os.path.relpath(p,ROOT)
        sec,st=yndt_section(b)
        stats[st]+=1
        if st!='ok': continue
        secs,verdict=walk_sections(b,sec)
        stats['walk_'+verdict]+=1
        if verdict!='ok': fails.append((rel,verdict))
        for i,s in enumerate(secs):
            s['file']=rel; s['idx']=i; s['nsec']=len(secs)
            det=section_detail(b,s)
            sections.append(det)
            f04_hist[s['f04']]+=1
            meta_lens[det.get('meta_len')]+=1
            if det['marker_at'] is not None and det['marker_at']>=0: marker_ok+=1
            else: marker_missing.append((rel,i))
            if det.get('f14_to_marker') is not None: f14_to_marker[det['f14_to_marker']]+=1
            if det.get('serial_slack') is not None: slack[det['serial_slack']]+=1
            if det.get('meta_rgba'): rgba[det['meta_rgba']]+=1
            if det.get('extra_pool') is not None: extra_hist[det['extra_pool']]+=1
    # verify the stride law count: every non-last section's next must be YNGM, last must be YNED
    stride_ok=sum(1 for s in sections if s['next_magic'] in ('YNGM','YNED'))
    print('== corpus status =='); [print('  %s: %d'%(k,v)) for k,v in sorted(stats.items())]
    print('total sections:', len(sections))
    print('stride law next-magic ok:', stride_ok, '/', len(sections))
    print('walk failures:', fails[:10])
    print('marker found:', marker_ok, '/', len(sections), 'missing:', marker_missing[:5])
    print('meta_len hist:', dict(meta_lens))
    print('extra_pool hist:', dict(sorted(extra_hist.items())))
    print('f14_to_marker (0 = blob ends AT marker):', dict(sorted(f14_to_marker.items())))
    print('serial_slack (payload bytes after the 5 fixed reads):', dict(sorted(slack.items())))
    print('meta rgba hist:', dict(rgba))
    print('f04: min %d max %d  distinct %d'%(min(f04_hist),max(f04_hist),len(f04_hist)))
    print('f04 top:', f04_hist.most_common(8))
    json.dump(sections, open('sections_all.json','w'), indent=1)
    # dump for the report
    with open('measure_output.txt','w') as f:
        f.write('stride law: %d/%d sections land on YNGM/YNED\n'%(stride_ok,len(sections)))
        f.write('sections: %d  files ok: %d\n'%(len(sections),stats.get('ok',0)))
        f.write('f04 range %d..%d, distinct %d\n'%(min(f04_hist),max(f04_hist),len(f04_hist)))
        f.write('meta_len %s\nextra_pool %s\nf14_to_marker %s\nslack %s\n'%(dict(meta_lens),dict(sorted(extra_hist.items())),dict(sorted(f14_to_marker.items())),dict(sorted(slack.items()))))
    return 0

if __name__=='__main__':
    sys.exit(main())
