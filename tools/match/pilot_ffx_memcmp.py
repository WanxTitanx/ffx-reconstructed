#!/usr/bin/env python3
"""Pilot: rebuild one real FFX.exe function with VS2012 and diff bytes.

FFX_memcmp @ 0x401020 is 112 bytes of hand-readable x86: a 4-way unrolled
dword loop with byte tail. We write the obvious C, compile it with the
VS2012 toolchain on the Windows VM, and compare machine bytes.

Usage: pilot_ffx_memcmp.py <FFX.exe>  ->  writes pilot_ffx_memcmp.c + .asm ref
"""

import struct
import sys

VA = 0x401020
SIZE = 112

C_SOURCE = r'''
int __cdecl FFX_memcmp(const void *a, const void *b, unsigned int n)
{
    const unsigned int *pa = (const unsigned int *)a;
    const unsigned int *pb = (const unsigned int *)b;
    const unsigned char *ca;
    const unsigned char *cb;
    unsigned int q = n >> 2;
    unsigned int r = n & 3;
    unsigned int i;
    for (i = 0; i < q; i++) {
        if (pa[i] != pb[i])
            break;
    }
    if (i != q)
        return -1;
    ca = (const unsigned char *)(pa + q);
    cb = (const unsigned char *)(pb + q);
    while (r--) {
        if (*ca != *cb)
            return -1;
        ca++;
        cb++;
    }
    return 0;
}
'''


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
    raise ValueError(f'VA {va:#x} not mapped')


def main() -> int:
    exe = sys.argv[1]
    data = open(exe, 'rb').read()
    ref = read_va(data, VA, SIZE)
    open('pilot_ffx_memcmp.c', 'w').write(C_SOURCE)
    open('pilot_ffx_memcmp.ref.bin', 'wb').write(ref)
    print(f'reference bytes ({SIZE}):')
    print(ref.hex())
    print('wrote pilot_ffx_memcmp.c and pilot_ffx_memcmp.ref.bin')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
