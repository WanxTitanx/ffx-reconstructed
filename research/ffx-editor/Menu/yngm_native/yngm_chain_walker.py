#!/usr/bin/env python3
# YNGM chain walker (2026-09-15, Jarvis-YNGM lane FFX-STRUCTURES)
# Proves the "gap" before YNED in mapout.vpa guide YNDT sections is a CHAIN of
# additional YNGM sections (each: header 0x48 + 20B tris + 6B verts + extra pool
# + 20B marker 1c000000 0000f001 44000000+8 zeros + meta tail ~260-276B).
# Usage: yngm_chain_walker.py <mapout.vpa> <yngm_abs_offset>
import struct, sys

MARK = bytes.fromhex('1c0000000000f00144000000') + b'\x00' * 8

def walk(data, off):
    n = 0
    while True:
        assert data[off:off+4] == b'YNGM', f"bad magic at {off:#x}"
        f04, = struct.unpack_from('<I', data, off+4)
        tri, vert = struct.unpack_from('<HH', data, off+0x28)
        pool_end = off + 0x48 + tri*20 + vert*6
        m = data.find(MARK, pool_end, pool_end+64)
        assert m >= 0, f"marker missing after pool {pool_end:#x}"
        tail = data[m+len(MARK):]
        nxt, yned = tail.find(b'YNGM'), tail.find(b'YNED')
        end = min(x for x in (nxt, yned) if x >= 0)
        meta = tail[:end]
        rgba, = struct.unpack_from('<I', meta, 4)
        id0, id1 = struct.unpack_from('<HH', meta, 12)
        print(f"[{n}] off={off:#x} f04={f04} tri={tri} vert={vert} "
              f"extra_pool={m-pool_end}B rgba={rgba:08x} ids=({id0},{id1}) meta={len(meta)}B")
        n += 1
        if yned >= 0 and (nxt < 0 or yned < nxt):
            assert data[m+len(MARK)+yned:m+len(MARK)+yned+4] == b'YNED'
            print(f"chain OK: {n} sections -> YNED at {m+len(MARK)+yned:#x}")
            return
        off = m + len(MARK) + nxt

if __name__ == '__main__':
    walk(open(sys.argv[1], 'rb').read(), int(sys.argv[2], 0))
