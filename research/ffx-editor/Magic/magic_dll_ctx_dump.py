#!/usr/bin/env python3
"""magic_dll_ctx_dump.py — minimal dump for magic_NNNN.dll (PE32 + embedded PPP ctx).

PROVEN FILE FORMAT (FfxLib/MagicDll/MagicDllFile.cs + atlas §8.16 + MAGIC_DLL_ATLAS.md):
  MS-DOS 'MZ' header → e_lfanew@0x3C → 'PE\0\0' → COFF (numSections@+2, optHdrSize@+16)
  → section table (40B entries: name8, vsize, va, rawsize, rawptr).
  Sections observed across 581-file corpus: .text .rdata .data .rsrc .reloc
  The .data section carries the embedded effect ctx: PPP resource roots + programs.

PPP ROOT (MagicDllRoot — PARSER_SPEC §2.1):
  +0  u32 tag            0x31 / 0x32 observed
  +4  u32 mirror count   u16 hi == u16 lo
  +6  u16 primary_count  +8 u16 descriptor_count  +10 u16 count3  +12 u16 count4
  +16 u32 table1 rel     +20 u32 table2 rel (32B descriptors)  +24 u32 table3 rel  +28 u32 table4 rel (8B)
This tool parses the PE, dumps the section table, locates .data, and scans .data for
PPP root candidates (tag 0x31/0x32 + sane counts + in-range table offsets).

Usage: magic_dll_ctx_dump.py <file-or-dir> [glob]
"""
import os, sys, struct, glob

def pe_sections(d):
    if len(d) < 64 or d[:2] != b'MZ':
        raise ValueError('not MZ')
    pe = struct.unpack_from('<I', d, 0x3C)[0]
    if d[pe:pe + 4] != b'PE\0\0':
        raise ValueError('not PE')
    nsec = struct.unpack_from('<H', d, pe + 6)[0]
    optsz = struct.unpack_from('<H', d, pe + 20)[0]
    tab = pe + 24 + optsz
    secs = []
    for i in range(nsec):
        o = tab + i * 40
        name = d[o:o + 8].rstrip(b'\0').decode('ascii', 'replace')
        vsz, va, rsz, rp = struct.unpack_from('<4I', d, o + 8)
        secs.append((name, vsz, va, rsz, rp))
    return secs

def scan_roots(data):
    """scan .data for PPP root candidates (port of find_ppp_resource_roots)."""
    out = []
    for o in range(0, len(data) - 32, 4):
        tag, mirror = struct.unpack_from('<2I', data, o)
        if tag not in (0x31, 0x32):
            continue
        if (mirror >> 16) != (mirror & 0xFFFF) or (mirror & 0xFFFF) == 0:
            continue
        pc, dc, c3, c4 = struct.unpack_from('<4H', data, o + 6)
        t1, t2, t3, t4 = struct.unpack_from('<4I', data, o + 16)
        if not (0 < pc <= 0x200 and dc <= 0x400 and c3 <= 0x400 and c4 <= 0x400):
            continue
        if not all(0 <= t < len(data) for t in (t1, t2, t3, t4)):
            continue
        # tables are non-decreasing; empty tables (count=0) share the next table's
        # offset (e.g. magic_0010: c3=0 -> t3==t4). strict '<' misses those roots.
        if not (t1 <= t2 <= t3 <= t4):
            continue
        # consistency: zero count => table offset equal to following table offset
        if (pc == 0 and t1 != t2) or (dc == 0 and t2 != t3) or (c3 == 0 and t3 != t4):
            continue
        out.append((o, tag, mirror & 0xFFFF, pc, dc, c3, c4, t1, t2, t3, t4))
    return out

def dump(path):
    d = open(path, 'rb').read()
    secs = pe_sections(d)
    dat = next((s for s in secs if s[0].lower() == '.data'), None)
    if dat is None:
        return f"{os.path.basename(path)}: no .data section"
    name, vsz, va, rsz, rp = dat
    raw = d[rp:rp + min(rsz, len(d) - rp)]
    roots = scan_roots(raw)
    sec_s = ' '.join(f'{s[0]}@{s[4]:X}+{s[3]:X}' for s in secs)
    out = [f"{os.path.basename(path)} ({len(d)}B): PE32 sects={len(secs)} [{sec_s}]",
           f"  .data rva=0x{va:X} raw=0x{rp:X}+0x{rsz:X} roots={len(roots)}"]
    for r in roots[:4]:
        o, tag, cnt, pc, dc, c3, c4, t1, t2, t3, t4 = r
        out.append(f"  root@data+0x{o:X} tag=0x{tag:X} n={cnt} primary={pc} desc={dc} c3={c3} c4={c4} t=[{t1:X},{t2:X},{t3:X},{t4:X}]")
    return "\n".join(out)

def main():
    if len(sys.argv) < 2:
        print(__doc__); return 2
    root, pat = sys.argv[1], sys.argv[2] if len(sys.argv) > 2 else '*.dll'
    files = [root] if os.path.isfile(root) else sorted(
        os.path.join(dp, f) for dp, _, fns in os.walk(root)
        for f in fns if glob.fnmatch.fnmatch(f.lower(), (pat or '*').lower()))
    ok = 0
    from collections import Counter
    rc = Counter()
    for f in files:
        try:
            line = dump(f)
            ok += 1
            for l in line.splitlines():
                if 'roots=' in l:
                    rc[l.split('roots=')[1].strip()] += 1
            print(line)
        except Exception as e:
            print(f"{os.path.basename(f)}: FAIL {e}")
    print(f"== {ok}/{len(files)} parsed; roots histogram: {dict(rc)}")

if __name__ == '__main__':
    sys.exit(main())
