#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# stub_taxonomy.py — consolidated evidence generator for FFX_STUB_TAXONOMY_2026-09-15.
# Lane: Jarvis-DEVIN/FFX-STRUCTURES (research-only; reads corpus read-only, writes
# only under work/_stub_taxonomy/ and artifacts/2026-09-15/stub-taxonomy/).
#
# Produces:
#   artifacts/.../ftc80_census.tsv        — per tree/dir/type/count distribution of 80B .ftc
#   artifacts/.../ftc80_sha_groups.tsv    — all distinct sha256 groups of 80B .ftc + members
#   artifacts/.../bin_stub_taxonomy.tsv   — .bin groups by (size, sha) classified by CONTENT
#   artifacts/.../bin_empty_stubs.tsv     — every empty-table / all-zero .bin instance
#   artifacts/.../itpc_test_inventory.tsv — new_itpc te/test* x {ps3,psv}: size+sha
#   artifacts/.../itpc_test_matrix.tsv    — cross-locale presence of the 14 test names
#   artifacts/.../itpc_test_decoded.txt   — decoded strings (US/Latin table + controls)
#   artifacts/.../zero_byte_placeholders.txt
#   artifacts/.../summary.txt             — headline numbers
#
# Format notes (all proven in this scan, see doc):
#   * "pair-format" .bin  = N x {u32 off, u32 off_dup} (off==off_dup in ALL observed files)
#                           + string pool; first u32 == 8*N == pool start.
#     Empty table = pool of N cells "03 00" (NEWLINE+NUL) => size == 10*N.
#   * 80B .ftc = 64B constant skeleton (FTCX, ver 0x061400C8, +0x08 type,
#     +0x10 used-count) + 16B width table (count bytes + 0x07 fill).
import csv, glob, hashlib, os, re, struct, sys, collections

M = "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master"
REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
OUT = os.path.join(REPO, "artifacts/2026-09-15/stub-taxonomy")
DUMPS = os.path.join(REPO, "work/_stub_taxonomy/dumps")
os.makedirs(OUT, exist_ok=True)
os.makedirs(DUMPS, exist_ok=True)

TREES = ["inpc","jppc","new_chpc","new_depc","new_frpc","new_itpc",
         "new_jppc","new_krpc","new_sppc","new_uspc","uspc"]

def sha16(path):
    return hashlib.sha256(open(path,'rb').read()).hexdigest()[:12]

def census_rows():
    for f in sorted(glob.glob(os.path.join(REPO,'artifacts/2026-09-15/parity-locale/locale_census_*.tsv'))):
        tree = os.path.basename(f)[len('locale_census_'):-4]
        with open(f) as fh:
            for r in csv.DictReader(fh, delimiter='\t'):
                yield tree, r['relpath'], int(r['bytes']), r['sha256']

# ---------- FFX text decoder (US/Latin table lifted from FfxEncoding.us.cs) ----------
def load_us_table():
    src = open(os.path.join(REPO,'FFXProjectEditor/FfxLib/Encoding/FfxEncoding.us.cs'),
               encoding='utf-8-sig').read()
    tbl = {}
    for m in re.finditer(r"\{\s*(\d+),\s*'(.)'\s*\}", src):
        tbl[int(m.group(1))] = m.group(2)
    return tbl

US = load_us_table()
CTRL = {0:'<NULL>',3:'<NL>',10:'<FMT>',19:'<NAME>',7:'<C7>',8:'<C8>',9:'<C9>'}
NAMES = {48:'<TIDUS>',49:'<YUNA>',50:'<AURON>',51:'<KIMAHRI>',52:'<WAKKA>',
         53:'<LULU>',54:'<RIKKU>',55:'<SEYMOUR>',56:'<VALEFOR>',57:'<IFRIT>',
         58:'<IXION>',59:'<SHIVA>',60:'<BAHAMUT>',61:'<ANIMA>',62:'<YOJIMBO>',
         63:'<CINDY>',64:'<SANDY>',65:'<MINDY>'}
FMT = {65:'</>',67:'<W>',177:'<B>',82:'<FMT52>'}

def decode_string(b):
    """Decode one NUL-terminated FFX string (US/Latin locale table)."""
    out, i = [], 0
    while i < len(b):
        c = b[i]
        if c == 0: break
        if c == 3: out.append('<NL>'); i += 1; continue
        if c == 10 and i+1 < len(b): out.append(FMT.get(b[i+1], f'<FMT{b[i+1]}>')); i += 2; continue
        if c == 19 and i+1 < len(b): out.append(NAMES.get(b[i+1], f'<NAME:{b[i+1]}>')); i += 2; continue
        if c < 48:
            if 0x26 <= c <= 0x2F or c == 6:   # 2-byte glyph leads (banks)
                if i+1 < len(b): out.append(f'<G{c:02x}:{b[i+1]:02x}>'); i += 2; continue
            out.append(CTRL.get(c, f'<C{c}>')); i += 1; continue
        out.append(US.get(c, f'<{c:02x}>')); i += 1
    return ''.join(out)

def pair_offsets(d):
    """Return (n_entries, [(off,aux)]) for pair-format files, else (0, []).
    Entry = {u16 off, u16 aux} stored twice (2 identical 4B records = 8B/entry).
    First u16 == 8*N == pool start in every observed file."""
    if len(d) < 8: return 0, []
    first = struct.unpack('<H', d[:2])[0]
    if first == 0 or first > len(d) or first % 8: return 0, []
    n = first // 8
    ents = []
    for i in range(n):
        off, aux, off2, aux2 = struct.unpack('<HHHH', d[i*8:i*8+8])
        if (off, aux) != (off2, aux2) or off >= len(d):
            return 0, []
        ents.append((off, aux))
    return n, ents

def classify_bin(d):
    """-> (class, n_entries, detail)."""
    if all(b == 0 for b in d): return 'ALL-ZERO', 0, ''
    n, ents = pair_offsets(d)
    if not n: return 'OTHER', 0, ''
    pool = d[n*8:]
    empty = len(pool) % 2 == 0 and len(pool) >= 2*n and \
            all(pool[i:i+2] == b'\x03\x00' for i in range(0, len(pool), 2))
    if empty: return 'EMPTY-TABLE', n, f'cells={len(pool)//2}'
    if any(aux for _, aux in ents): return 'REAL-TEXT-AUX', n, 'aux!=0'
    return 'REAL-TEXT', n, ''

def hexdump(path, tag):
    d = open(path,'rb').read()
    lines = [f"# {tag}  size={len(d)} sha256={hashlib.sha256(d).hexdigest()[:12]}"]
    for off in range(0, len(d), 16):
        ch = d[off:off+16]
        hexs = ' '.join(f'{b:02x}' for b in ch)
        asc = ''.join(chr(b) if 32 <= b < 127 else '.' for b in ch)
        lines.append(f"{off:08x}  {hexs:<47}   {asc}")
    fn = os.path.join(DUMPS, tag.replace(':','_').replace('/','_') + '.hex')
    open(fn,'w').write('\n'.join(lines) + '\n')
    return fn

# ============================ 1) .ftc census ============================
ftc_rows = list(census_rows())
ftc80_groups = collections.defaultdict(list)
ftc80_stats = collections.Counter()
ftc_all_sizes = collections.Counter()
for tree, rp, sz, sha in ftc_rows:
    if not rp.endswith('.ftc'): continue
    p = os.path.join(M, tree, rp)
    d = open(p,'rb').read(64)
    if d[:4] != b'FTCX': continue
    ftc_all_sizes[sz] += 1
    if sz != 80: continue
    typ = struct.unpack('<I', d[8:12])[0]
    cnt = struct.unpack('<I', d[16:20])[0]
    d1 = 'battle/btl' if rp.startswith('battle/btl') else \
         'event_obj' if rp.startswith('event/obj') else rp.split('/')[0]
    ftc80_stats[(tree, d1, typ, cnt)] += 1
    full = open(p,'rb').read()
    wprefix = full[64:64+cnt].hex()
    ftc80_groups[sha].append((tree, rp, typ, cnt, wprefix))

with open(os.path.join(OUT,'ftc80_census.tsv'),'w') as f:
    f.write('tree\tdir\ttype\tcount\tfiles\n')
    for (tree,d1,typ,cnt),n in sorted(ftc80_stats.items()):
        f.write(f'{tree}\t{d1}\t{typ}\t{cnt}\t{n}\n')

with open(os.path.join(OUT,'ftc80_sha_groups.tsv'),'w') as f:
    f.write('sha16\tn_members\ttype\tcount\twidth_hex\tsample_member\n')
    for sha, mem in sorted(ftc80_groups.items(), key=lambda kv:-len(kv[1])):
        t,r,typ,cnt,wp = mem[0]
        f.write(f'{sha[:12]}\t{len(mem)}\t{typ}\t{cnt}\t{wp}\t{t}:{r}\n')

with open(os.path.join(OUT,'ftc_size_histogram.tsv'),'w') as f:
    f.write('size\tfiles\n')
    for sz,n in sorted(ftc_all_sizes.items()):
        f.write(f'{sz}\t{n}\n')

# ============================ 2) .bin taxonomy ============================
bin_groups = collections.defaultdict(list)   # (size, sha12) -> members
bin_rows_all = []
for tree, rp, sz, sha in ftc_rows:
    if not rp.endswith('.bin'): continue
    if not (rp.startswith('battle/btl') or rp.startswith('event/obj')): continue
    if not tree.startswith('new_'): continue
    p = os.path.join(M, tree, rp)
    d = open(p,'rb').read()
    cls, n, det = classify_bin(d)
    bin_rows_all.append((tree, rp, sz, sha[:12], cls, n))
    if sz <= 300 or cls in ('ALL-ZERO','EMPTY-TABLE'):
        bin_groups[(sz, sha[:12], cls, n)].append((tree, rp))

with open(os.path.join(OUT,'bin_stub_taxonomy.tsv'),'w') as f:
    f.write('size\tsha16\tclass\tn_entries\tn_members\tmembers\n')
    for (sz, sha, cls, n), mem in sorted(bin_groups.items()):
        memstr = ';'.join(f'{t}:{r}' for t,r in mem)
        f.write(f'{sz}\t{sha}\t{cls}\t{n}\t{len(mem)}\t{memstr}\n')

with open(os.path.join(OUT,'bin_empty_stubs.tsv'),'w') as f:
    f.write('tree\trelpath\tsize\tsha16\tclass\tn_entries\n')
    for t,r,sz,sha,cls,n in sorted(bin_rows_all):
        if cls in ('ALL-ZERO','EMPTY-TABLE'):
            f.write(f'{t}\t{r}\t{sz}\t{sha}\t{cls}\t{n}\n')

with open(os.path.join(OUT,'bin_class_summary.tsv'),'w') as f:
    f.write('tree\tdir\tclass\tfiles\n')
    cc = collections.Counter()
    for t,r,sz,sha,cls,n in bin_rows_all:
        d1 = 'battle/btl' if r.startswith('battle/btl') else 'event_obj'
        cc[(t,d1,cls)] += 1
    for k,v in sorted(cc.items()):
        f.write('\t'.join(map(str,k)) + f'\t{v}\n')

# ============================ 3) new_itpc test exclusives ============================
tests = ['test03','test14','test20','test23','test24','test25','test26',
         'test30','test31','test32','test35','test36','test38','test40']
inv = []
for name in tests:
    for plat in ('obj_ps3','obj_psv'):
        rp = f'event/{plat}/te/{name}/{name}.bin'
        p = os.path.join(M,'new_itpc',rp)
        if os.path.exists(p):
            d = open(p,'rb').read()
            cls, n, det = classify_bin(d)
            inv.append((name, plat, len(d), hashlib.sha256(d).hexdigest()[:16], cls, n))
        rp2 = f'event/{plat}/te/{name}/{name}.ftc'
        p2 = os.path.join(M,'new_itpc',rp2)
        if os.path.exists(p2):
            d = open(p2,'rb').read()
            inv.append((name, plat+'(ftc)', len(d), hashlib.sha256(d).hexdigest()[:16], 'FTCX', 0))
with open(os.path.join(OUT,'itpc_test_inventory.tsv'),'w') as f:
    f.write('name\tplatform\tsize\tsha16\tclass\tn_entries\n')
    for row in inv:
        f.write('\t'.join(map(str,row))+'\n')

# cross-locale matrix for the test names (.bin and .ftc)
mat = {}
for f_ in sorted(glob.glob(os.path.join(REPO,'artifacts/2026-09-15/parity-locale/locale_relpath_matrix.tsv'))):
    for r in csv.DictReader(open(f_), delimiter='\t'):
        rp = r['relpath']
        m = re.match(r'event/obj_ps[3v]/te/(test\d+)/\1\.(bin|ftc)$', rp)
        if m and m.group(1) in tests:
            mat[rp] = {t: r[t] for t in TREES}
with open(os.path.join(OUT,'itpc_test_matrix.tsv'),'w') as f:
    f.write('relpath\t' + '\t'.join(TREES) + '\n')
    for rp, row in sorted(mat.items()):
        f.write(rp + '\t' + '\t'.join(row[t] for t in TREES) + '\n')

# decoded strings — all 14 itpc ps3 files (same as psv except test20)
dec_lines = []
for name in tests:
    p = os.path.join(M,'new_itpc',f'event/obj_ps3/te/{name}/{name}.bin')
    d = open(p,'rb').read()
    n, ents = pair_offsets(d)
    dec_lines.append(f'### new_itpc {name}.bin  size={len(d)} entries={n}')
    for i, (off, aux) in enumerate(ents):
        s = decode_string(d[off:])
        dec_lines.append(f'  [{i:>3}] @{off:#06x}: {s}')
        if i >= 14 and n > 17:
            dec_lines.append(f'  ... ({n-15} more entries)')
            break
    dec_lines.append('')
open(os.path.join(OUT,'itpc_test_decoded.txt'),'w').write('\n'.join(dec_lines))

# ============================ 4) 0-byte placeholders ============================
zb = []
for tree, rp, sz, sha in ftc_rows:
    if sz == 0:
        zb.append((tree, rp, sha))
with open(os.path.join(OUT,'zero_byte_placeholders.txt'),'w') as f:
    for t,r,s in zb:
        f.write(f'{t}\t{r}\t0\t{s}\n')

# ============================ 5) extra hexdumps ============================
# representative 80B .ftc across trees + one member of each .bin sha group
extra = [
 ('new_jppc','event/obj_ps3/bs/bsil0500/bsil0500.ftc'),
 ('new_krpc','event/obj_ps3/bj/bjyt1200/bjyt1200.ftc'),
 ('new_chpc','battle/btl/genk00_40/genk00_40.ftc'),
 ('new_jppc','battle/btl/mihn00_01/mihn00_01.ftc'),
]
for t,r in extra:
    hexdump(os.path.join(M,t,r), f'ftc80_{t}_{os.path.basename(r)}')
for (sz,sha,cls,n),mem in sorted(bin_groups.items()):
    if cls in ('ALL-ZERO','EMPTY-TABLE'):
        t,r = mem[0]
        hexdump(os.path.join(M,t,r), f'bin{sz}_{sha}_{t}_{os.path.basename(r)}')

# ============================ 6) summary ============================
S = []
S.append(f'80B .ftc files: {sum(ftc80_stats.values())} in {len(ftc80_groups)} distinct sha groups')
pt = collections.Counter()
for (tree,d1,typ,cnt),n in ftc80_stats.items(): pt[tree] += n
S.append(f'  per tree: {dict(pt)}')
pc = collections.Counter()
for (tree,d1,typ,cnt),n in ftc80_stats.items(): pc[d1] += n
S.append(f'  per dir : {dict(pc)}')
pty = collections.Counter()
for (tree,d1,typ,cnt),n in ftc80_stats.items(): pty[typ] += n
S.append(f'  per type: {dict(pty)}')
S.append(f'non-80B FTCX sizes: {dict(sorted((k,v) for k,v in ftc_all_sizes.items() if k!=80))}')
S.append('')
S.append('new_* .bin classification (battle/btl + event obj):')
cc2 = collections.Counter()
for t,r,sz,sha,cls,n in bin_rows_all:
    d1 = 'battle/btl' if r.startswith('battle/btl') else 'event_obj'
    cc2[(d1,cls)] += 1
for k,v in sorted(cc2.items()): S.append(f'  {k}: {v}')
S.append('')
S.append('EMPTY-TABLE sizes: ' + str(dict(sorted(collections.Counter(
    sz for t,r,sz,sha,cls,n in bin_rows_all if cls=='EMPTY-TABLE').items()))))
S.append('ALL-ZERO sizes: ' + str(dict(sorted(collections.Counter(
    sz for t,r,sz,sha,cls,n in bin_rows_all if cls=='ALL-ZERO').items()))))
S.append('')
S.append(f'itpc test files inventoried: {len(inv)}')
S.append(f'0-byte files: {len(zb)} -> ' + '; '.join(f'{t}:{r}' for t,r,s in zb))
open(os.path.join(OUT,'summary.txt'),'w').write('\n'.join(S)+'\n')
print('\n'.join(S))
print('\nWROTE:', OUT)
