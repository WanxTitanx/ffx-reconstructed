#!/usr/bin/env python3
"""parse_chd.py — parse MSVC RTTI COL->CHD->BaseClassArray->BCD->TD for every
has_col vtable in vtables2.json. Local parse over dumped .rdata/.data bins.

RTTI layout (MSVC x86):
  COL:  sig(4) offset(4) cdOffset(4) pTD(4) pCHD(4)
  CHD:  sig(4) attributes(4) numBaseClasses(4) pBaseClassArray(4)
  BCA:  DWORD[numBaseClasses] -> ptr to BCD
  BCD:  pTD(4) numContainedBases(4) mdisp(4) pdisp(4) vdisp(4) attributes(4)
  TD:   pVFTable(4) spare(4) name(char[]; '.?AV..')
numBaseClasses includes the class itself (index 0 = self BCD).
numContainedBases(BCD) = number of DIRECT bases of that class.
Array order = DFS pre-order: [self, B1, B1-subtree..., B2, B2-subtree...]
"""
import json, struct, sys, os
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida/vtable_recon')
from msvc_demangle import demangle_type_desc

VR = '/home/wanderson/Documents/ffx-editor-main/work/_vtable_recon/'
REGIONS = [(0xB0C8C0, VR + 'rdata.bin'), (0xC0A000, VR + 'ext.bin'),
           (0xC0A000, VR + 'ext2.bin')]
bufs = {}
for base, f in REGIONS:
    data = open(f, 'rb').read()
    # later regions only add coverage where earlier lacks
    bufs.setdefault(base, data)


def region(a):
    for base in sorted(bufs):
        if base <= a < base + len(bufs[base]):
            return base


def dword_at(a):
    b = region(a)
    return None if b is None else struct.unpack_from('<I', bufs[b], a - b)[0]


def cstring_at(a, mx=400):
    b = region(a)
    if b is None:
        return None
    buf = bufs[b]
    off = a - b
    e = buf.find(b'\x00', off, min(off + mx, len(buf)))
    if e < 0:
        return None
    return buf[off:e].decode('ascii', 'replace')


def is_ptr(v):
    return v is not None and (v & 3) == 0 and region(v) is not None


def parse_td(td):
    """Return demangled class name from TypeDescriptor, or None."""
    name = cstring_at(td + 8)
    if not name or not name.startswith('.?'):
        return None
    return demangle_type_desc(name), name


def parse_chd(chd):
    sig = dword_at(chd)
    attrs = dword_at(chd + 4)
    nb = dword_at(chd + 8)
    bca = dword_at(chd + 0xC)
    if sig != 0 or nb is None or nb < 1 or nb > 64 or not is_ptr(bca):
        return None
    entries = []
    for i in range(nb):
        pbcd = dword_at(bca + 4 * i)
        if not is_ptr(pbcd):
            return None
        ptd = dword_at(pbcd)
        ncb = dword_at(pbcd + 4)
        mdisp = dword_at(pbcd + 8)
        pdisp = dword_at(pbcd + 0xC)
        vdisp = dword_at(pbcd + 0x10)
        battrs = dword_at(pbcd + 0x14)
        if not is_ptr(ptd) or ncb is None or ncb > 64:
            return None
        t = parse_td(ptd)
        if not t:
            return None
        entries.append({'bcd': pbcd, 'td': ptd, 'cls': t[0], 'mangled': t[1],
                        'ncb': ncb, 'mdisp': mdisp, 'pdisp': pdisp,
                        'vdisp': vdisp, 'attrs': battrs})
    return {'chd': chd, 'attrs': attrs, 'nb': nb, 'bca': bca, 'entries': entries}


def direct_bases(entries):
    """Entries are DFS pre-order; ncb[i] = subtree size of i (all descendants).
    Direct bases = level-0 frontier: i=1; i += 1+ncb[i] while i<n.
    Returns (direct_idx_list, ok) where ok = frontier consumed exactly n."""
    n = len(entries)
    if n == 1:
        return [], entries[0]['ncb'] == 0
    direct = []
    i = 1
    while i < n:
        direct.append(i)
        i += 1 + entries[i]['ncb']
    return direct, i == n


if __name__ == '__main__':
    vt = json.load(open(VR + 'vtables2.json'))
    # quick check on FFXApplication and a couple small ones
    for e in vt:
        if e.get('has_col') and e.get('class') in ('FFXApplication',) or (
                e.get('has_col') and e.get('nbases') in (2, 3)):
            chd = dword_at(int(e['col'], 16) + 0x10)
            p = parse_chd(chd)
            if not p:
                print(e['vtable'], e.get('class'), 'CHD PARSE FAIL', hex(chd))
                continue
            di, ok = direct_bases(p['entries'])
            print('===', e['vtable'], e.get('class'), 'nb=', p['nb'],
                  'direct:', di, 'ok=', ok)
            for i, en in enumerate(p['entries']):
                print(f"  [{i}] {en['cls'][:60]} ncb={en['ncb']} mdisp={en['mdisp']} "
                      f"pdisp={en['pdisp']:#x} attrs={en['attrs']:#x} bcd={en['bcd']:#x}")
            if e.get('class') == 'FFXApplication':
                pass
