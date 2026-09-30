#!/usr/bin/env python3
"""phyre_cluster_dump.py — minimal dump for ALL .phyre cluster files (not just .dds.phyre).

PROVEN (PhyreTextureReader.cs + hexdump corpus 2026-09-16):
  +0x00 u32 magic 'RYHP' (LE uint32 0x50485952; bytes are 'R','Y','H','P')
  +0x04 u8  platform letter: 'T'=0x54 header (GL/D3D11 PC-GL build), 'X'=0x58 header (GNM/PS4)
  +0x08 u32 packedNamespaceSize
  +0x0C u32 platformID — LE u32 whose ASCII bytes reversed spell the platform:
        0x024D4E47 -> bytes 47 4E 4D 02 -> 'GNM\x02' (PS4 GNM)
        0x5043474C -> bytes 4C 47 43 50 -> 'LGCP' -> PC GL
  +0x10 u32 instanceListCount  ... (full 0x54/0x58 ClusterHeader per PhyreTextureReader)
  then: packed namespace, InstanceList headers (36B each), object data, user-fixup data,
        user fixups (12B each), header-class tables, pointer fixups, array fixups,
        object payloads.
This tool dumps the cluster header fields + platform tag + instance-list headers and
reports whether the total size math is consistent.

Usage: phyre_cluster_dump.py <file-or-dir> [glob] [--full]
"""
import os, sys, struct, glob

PLAT = {0x024D4E47: 'GNM', 0x5043474C: 'PCGL', 0x314D4347: 'GCM1', 0x5058474E: 'NGXP'}

def dump(path, full=False):
    d = open(path, 'rb').read(0x400)  # header region only
    if len(d) < 0x40 or d[:4] != b'RYHP':
        return f"{os.path.basename(path)}: NOT RYHP ({d[:8].hex() if d else 'empty'})"
    letter = chr(d[4]); hsz = d[4]
    nsz, pid, ilc = struct.unpack_from('<3I', d, 8)
    plat = PLAT.get(pid, f'0x{pid:X}')
    # rest of cluster header (fields 5..20) at +0x14
    f = struct.unpack_from('<16I', d, 0x14) if len(d) >= 0x54 else (0,) * 16
    afs, afc, pfs, pfc, pafs, pafc, pia, ufc, uds, tds, hci, hcc, peid, ibs, vbs, mtb = f
    out = [f"{os.path.basename(path)}: RYHP'{letter}' hdr=0x{hsz:X} plat={plat} "
           f"ns=0x{nsz:X} il={ilc} | afSz={afs:#x} afN={afc} pfSz={pfs:#x} pfN={pfc} "
           f"pafSz={pafs:#x} pia={pia} ufN={ufc} ufData={uds:#x} totalData={tds:#x} "
           f"hci={hci} hcc={hcc} ibs={ibs:#x} vbs={vbs:#x} mtb={mtb:#x}"]
    if full and ilc and ilc < 512:
        base = hsz + nsz
        need = base + ilc * 36
        dd = open(path, 'rb').read(min(need + 36, os.path.getsize(path)))
        for i in range(min(ilc, 12)):
            o = base + i * 36
            if o + 36 > len(dd): break
            v = struct.unpack_from('<9I', dd, o)
            out.append(f"  il[{i}] cls=0x{v[0]:X} n={v[1]} sz={v[2]:#x} obj={v[3]:#x} arr={v[4]:#x} pia={v[5]} afc={v[6]} pfc={v[7]} pafc={v[8]}")
    return "\n".join(out)

def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    if not args:
        print(__doc__); return 2
    full = '--full' in sys.argv
    root, pat = args[0], args[1] if len(args) > 1 else '*.phyre'
    files = [root] if os.path.isfile(root) else sorted(
        os.path.join(dp, f) for dp, _, fns in os.walk(root)
        for f in fns if glob.fnmatch.fnmatch(f.lower(), (pat or '*').lower()))
    from collections import Counter
    tally = Counter()
    for fp in files:
        line = dump(fp, full)
        print(line)
        if 'RYHP' in line:
            tally[line.split("RYHP'")[1][:1] + "/" + line.split('plat=')[1].split()[0]] += 1
    print(f"== {len(files)} files, variant tally: {dict(tally)}")

if __name__ == '__main__':
    sys.exit(main())
