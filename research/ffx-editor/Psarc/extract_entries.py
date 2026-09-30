#!/usr/bin/env python3
# extract_entries.py — smoke/sample-read extractor for the repaired FFX-2_Data psarc.
# Decodes selected entries straight from the archive (independent walker with the
# real ZSize semantics) and byte-compares them against the preserved extraction.
# Evidence tool for docs/reverse/FFX_PSARC_FFX2_REPAIR_2026-09-15.md — not a product.
import hashlib
import io
import json
import struct
import sys
import zlib

def read_exact(f, n):
    b = f.read(n)
    if len(b) != n:
        raise EOFError(f"short read {len(b)}/{n} at {f.tell()}")
    return b

def main():
    psarc, extraction_root, picks_json = sys.argv[1], sys.argv[2], sys.argv[3]
    picks = json.load(open(picks_json))
    with open(psarc, "rb", buffering=1024 * 1024) as f:
        hdr = read_exact(f, 32)
        magic, maj, mn, comp, toc_len, entry_sz, count, block_sz, flags = struct.unpack(">4sHH4sIIIII", hdr)
        assert magic == b"PSAR" and entry_sz == 30 and block_sz == 65536, "unexpected geometry"
        toc = read_exact(f, count * 30)
        zt = read_exact(f, toc_len - 32 - count * 30)
        def slot(i):
            o = i * 2
            return (zt[o] << 8) | zt[o + 1]
        # decode manifest (entry 0)
        zi, = struct.unpack(">I", toc[16:20])
        usize = int.from_bytes(toc[20:25], "big")
        off = int.from_bytes(toc[25:30], "big")
        assert zi == 0 and off == toc_len
        raw = io.BytesIO()
        pos, remaining, s = off, usize, zi
        while remaining > 0:
            expected = min(block_sz, remaining)
            z = slot(s); s += 1
            f.seek(pos)
            if z == expected and z != 0:
                raw.write(read_exact(f, expected)); pos += expected
            elif z == 0 and expected == block_sz:
                raw.write(read_exact(f, block_sz)); pos += block_sz
            else:
                raw.write(zlib.decompress(read_exact(f, z))); pos += z
            remaining -= expected
        names = raw.getvalue().decode("utf-8").split("\n")
        assert len(names) == count - 1
        print(f"manifest ok: {len(names)} names, {usize} bytes")

        def decode_entry(idx):
            base = idx * 30
            zi, = struct.unpack(">I", toc[base + 16:base + 20])
            usize = int.from_bytes(toc[base + 20:base + 25], "big")
            off = int.from_bytes(toc[base + 25:base + 30], "big")
            out = io.BytesIO()
            pos, remaining, s = off, usize, zi
            while remaining > 0:
                expected = min(block_sz, remaining)
                z = slot(s); s += 1
                f.seek(pos)
                if z == expected and z != 0:
                    out.write(read_exact(f, expected)); pos += expected
                elif z == 0 and expected == block_sz:
                    out.write(read_exact(f, block_sz)); pos += block_sz
                else:
                    out.write(zlib.decompress(read_exact(f, z))); pos += z
                remaining -= expected
            return out.getvalue()

        results = []
        for idx in picks:
            name = names[idx - 1]
            data = decode_entry(idx)
            src = extraction_root.rstrip("/") + "/" + name.lstrip("/")
            disk = open(src, "rb").read()
            equal = data == disk
            results.append((idx, name, len(data), len(disk), equal,
                            hashlib.sha256(data).hexdigest()))
            print(f"[{'OK' if equal else 'FAIL'}] idx={idx} size={len(data)} "
                  f"sha256={results[-1][5][:16]}... {name}")
    if not all(r[4] for r in results):
        sys.exit(1)
    print("ALL SAMPLE ENTRIES MATCH THE EXTRACTION BYTE-FOR-BYTE")

if __name__ == "__main__":
    main()
