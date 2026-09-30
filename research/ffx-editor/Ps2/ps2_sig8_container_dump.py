#!/usr/bin/env python3
"""ps2_sig8_container_dump.py — minimal dump for the FFX PS2 "Signature=N" pointer-table
.bin container family (battle/mon/_mNNN/mNNN.bin monster files AND battle/btl/areaNN_XX.bin
battle formation files).

PROVEN layout (matches FfxLib Monster_Structs.MonsterHeaderFile + atlas §8.10/§11.3):
  +0x00 u32 signature   — 8 = full container (monsters + most formations), 7 = short variant
  +0x04 u32 ptr[0]      — sig8: AiFilePointer      / formations: script chunk0 (ATEL)
  +0x08 u32 ptr[1]      — sig8: WorkerFilePointer  / formations: chunk1
  +0x0C u32 ptr[2]      — sig8: StatSheetPointer   / formations: chunk2
  +0x10 u32 ptr[3]      — sig8: SpoilsFilePointer  / formations: chunk3 (anchor groups)
  +0x14 u32 ptr[4]      — sig8: LootFilePointer    / formations: 0 or extra
  +0x18 u32 ptr[5]      — sig8: AudioFilePointer
  +0x1C u32 ptr[6]      — sig8: TextFilePointer    / sig7: FileSize
  +0x20 u32 ptr[7]      — sig8: FileSize
  +0x24..+0x33          — 16B padding (overlaps first section start at 0x30 for sig8)
sig7 files: 8 ints header (0x24 bytes of fields + pad to 0x30), FileSize lives at +0x1C and
is the file size rounded up to the next 8-byte boundary in some files (e.g. kino03_02).

Lane: onda Formatos (FFX_FMT_GFXMAP_AUDIT_2026-09-16). Read-only dump, no writer.
Usage: ps2_sig8_container_dump.py <file-or-dir> [glob]
"""
import os, sys, struct, glob

def dump(path):
    d = open(path, 'rb').read()
    if len(d) < 0x34:
        return f"{path}: SMALL ({len(d)}B)"
    sig = struct.unpack_from('<I', d, 0)[0]
    ints = struct.unpack_from('<8I', d, 4)
    info = [f"sig={sig}"]
    if sig == 8:
        names = ['ai', 'worker', 'statsheet', 'spoils', 'loot', 'audio', 'text', 'FILESIZE']
        for n, v in zip(names, ints):
            info.append(f"{n}=0x{v:X}" if v else f"{n}=0")
        # section spans (sorted nonzero ptrs + filesize)
        spans = sorted(set(v for v in ints if v))
        if ints[7] != len(d):
            info.append(f"!! FILESIZE=0x{ints[7]:X} != actual 0x{len(d):X}")
        info.append("spans=" + ",".join(f"0x{a:X}-0x{b:X}" for a, b in zip(spans, spans[1:] + [len(d)])))
    elif sig == 7:
        # short variant: 7 ptr fields then FileSize at +0x1C
        ptrs = ints[:6]
        fsz = ints[6]
        info.append("ptrs=" + ",".join(f"0x{v:X}" for v in ptrs))
        info.append(f"fsz@1C=0x{fsz:X} actual=0x{len(d):X}")
    else:
        info.append("!! unknown signature")
        info.append("hdr=" + " ".join(f"{v:08x}" for v in ints))
    return f"{os.path.basename(path)} ({len(d)}B): " + " ".join(info)

def main():
    if len(sys.argv) < 2:
        print(__doc__); return 2
    root, pat = sys.argv[1], sys.argv[2] if len(sys.argv) > 2 else None
    files = [root] if os.path.isfile(root) else sorted(
        os.path.join(dp, f) for dp, _, fns in os.walk(root)
        for f in fns if glob.fnmatch.fnmatch(f.lower(), (pat or '*').lower()))
    from collections import Counter
    sigs = Counter()
    for f in files:
        line = dump(f)
        print(line)
        if 'sig=' in line:
            sigs[line.split('sig=')[1].split()[0]] += 1
    print(f"== {len(files)} files, signature tally: {dict(sigs)}")

if __name__ == '__main__':
    sys.exit(main())
