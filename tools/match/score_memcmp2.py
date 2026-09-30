#!/usr/bin/env python3
"""Score a candidate against Phyre_MemCmp_WithLength @ 0x617420 (144 bytes)."""

import re
import struct
import sys

EXE = r'/home/wanderson/Documents/ffx-editor-main/work/_ppp_pool/FFX.exe'
VA, SIZE = 0x617420, 144


def read_va(data: bytes, va: int, size: int) -> bytes:
    e = struct.unpack_from('<I', data, 0x3C)[0]
    nsec = struct.unpack_from('<H', data, e + 6)[0]
    sz = struct.unpack_from('<H', data, e + 20)[0]
    base = struct.unpack_from('<I', data, e + 24 + 28)[0]
    for i in range(nsec):
        o = e + 24 + sz + i * 40
        vs, rva, rs, rp = struct.unpack_from('<IIII', data, o + 8)
        vstart = base + rva
        if vstart <= va < vstart + max(vs, rs):
            off = rp + (va - vstart)
            return data[off : off + size]
    raise ValueError('unmapped')


def obj_bytes(disasm: str) -> bytes:
    out = bytearray()
    for line in disasm.splitlines():
        m = re.match(r'^\s+[0-9A-F]+:\s+((?:[0-9A-F]{2} )+?)\s{2,}\S', line)
        if m:
            try:
                out += bytes(int(b, 16) for b in m.group(1).split())
            except ValueError:
                pass
    return bytes(out)


def main() -> int:
    ref = read_va(open(EXE, 'rb').read(), VA, SIZE)
    got = obj_bytes(open(sys.argv[1], encoding='utf-8', errors='replace').read())
    n = min(len(got), len(ref))
    same = sum(1 for i in range(n) if got[i] == ref[i])
    first = next((i for i in range(n) if got[i] != ref[i]), n)
    print(f'got={len(got)} ref={len(ref)} agree={same}/{n}={100*same/max(n,1):.1f}% first=+{first}')
    if first < n:
        print(f'  ref: {ref[max(0,first-6):first+10].hex()}')
        print(f'  got: {got[max(0,first-6):first+10].hex()}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
