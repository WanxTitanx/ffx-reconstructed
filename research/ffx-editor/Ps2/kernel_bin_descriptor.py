#!/usr/bin/env python3
# [NOT_INSP_BATCH3 2026-09-15] Reproduz o parse do descritor de range dos kernel .bin
# (layout provado no decompile de FFX_Table_GetEntryByIdRange@0x7AB890 do ffxoficial.exe.i64).
# Uso: python3 kernel_bin_descriptor.py <file.bin...>
import struct, sys, os
for p in sys.argv[1:]:
    d = open(p,'rb').read(20)
    count, = struct.unpack_from('<H', d, 0)
    mn, mx, st, ex = struct.unpack_from('<4H', d, 8)
    off, = struct.unpack_from('<I', d, 16)
    print(f"{os.path.basename(p)}: count={count} min={mn} max={mx} stride={st} extra=0x{ex:X} dataOffset={off} size={os.path.getsize(p)}")
