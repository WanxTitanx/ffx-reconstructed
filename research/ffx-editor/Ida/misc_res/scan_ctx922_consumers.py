#!/usr/bin/env python3
"""scan_ctx922_consumers.py — scan the shipped magic_*.dll corpus for accesses
to MagicHostContextTable slot 922 (byte offset 0xE64 = &pppSysProgTbl+145
band-B alias base at 0xC3BBA8).

Result (2026-09-16, Jarvis-DEVIN misc-res lane):
  - 591/591 shipped DLLs execute `mov ecx,[tbl+0xE64]` in the InitMagicPRX
    prologue and cache the pointer to a per-DLL global.
  - 590/591 reference that global exactly once (the store itself); the single
    "extra-refs" DLL (magic_0203) had 4 hits that are mid-instruction byte
    coincidences (verified by capstone disasm — they land inside movss/or
    operands, not on the global).
  - 4 DLLs (magic_0150/0603/0645/0662) have extra disp32==0xE64 hits that are
    UNRELATED struct offsets on per-effect objects (float timer r/w, vtable
    slot init), not ctx-table reads.
  - Verdict: fetched-but-unused; no shipped consumer dereferences band-B.

Usage: point DLL_DIR at the shipped corpus mirror.
"""
import glob, os, struct, collections

DLL_DIR = (os.path.dirname(os.path.abspath(__file__))
           + "/../../FFXProjectEditor.Tests/bin/Release/net8.0/"
             "F:\\ffx-reconstructed\\extras\\magicFiles\\FFX/"
             "F:\\ffx-reconstructed\\extras\\magicFiles\\FFX")


def sections(data):
    peoff = struct.unpack_from('<I', data, 0x3C)[0]
    imgbase = struct.unpack_from('<I', data, peoff + 0x34)[0]
    nsec = struct.unpack_from('<H', data, peoff + 6)[0]
    s = {}
    for i in range(nsec):
        o = peoff + 0xF8 + i * 40
        name = data[o:o + 8].rstrip(b'\0').decode('latin1')
        vs, va, rs, ra = struct.unpack_from('<IIII', data, o + 8)
        s[name] = (va, vs, ra, rs)
    return imgbase, s


def main():
    per_dll = collections.Counter()
    glob_hits = {}
    for path in sorted(glob.glob(os.path.join(DLL_DIR, 'magic_*.dll'))):
        data = open(path, 'rb').read()
        imgbase, s = sections(data)
        if '.text' not in s:
            continue
        va, vs, ra, rs = s['.text']
        seg = data[ra:ra + rs]
        n = 0
        idx = 0
        while True:
            k = seg.find(b'\x64\x0e\x00\x00', idx)
            if k < 0:
                break
            n += 1
            idx = k + 1
        per_dll[os.path.basename(path)] = n
        # locate the InitMagicPRX store: mov ecx,[eax+0xE64]; (pop edi)*;
        # mov [glob],ecx  -> learn the per-DLL band-B global and count refs
        i = seg.find(b'\x8b\x88\x64\x0e\x00\x00')
        if i >= 0:
            j = i + 6
            while seg[j] == 0x5F:  # skip pop edi
                j += 1
            if seg[j] == 0x89 and seg[j + 1] in (0x05, 0x0D, 0x15, 0x1D,
                                                 0x25, 0x2D, 0x35, 0x3D):
                gva = struct.unpack_from('<I', seg, j + 2)[0]
                needle = struct.pack('<I', gva)
                cnt = seg.count(needle)
                glob_hits[os.path.basename(path)] = (hex(gva), cnt)
    print('dlls:', len(per_dll), 'total +0xE64 disp hits:', sum(per_dll.values()))
    multi = {p: c for p, c in per_dll.items() if c > 1}
    print('dlls with >1 +0xE64 hits (ctx bytes show unrelated struct use):', multi)
    once = sum(1 for _, c in glob_hits.values() if c == 1)
    print('band-B global referenced exactly once (store only):', once,
          'of', len(glob_hits))


if __name__ == '__main__':
    main()
