#!/usr/bin/env python3
"""Scan: procura blobs com padrao name_ptr (0xBxxxxx) seguido de fn_ptr (0x4xxxxx-0x9xxxxx).

Identifica tabelas de nomes de handlers (como a do PPP em 0xC3DC28).
"""
import ida_bytes


def main():
    # varre .data inteiro em busca de dword que aponta p/ string (0xB40000-0xB90000)
    # seguido (ate 0x40 bytes depois) de dword que aponta p/ funcao (0x400000-0x9FFFFF)
    start = 0xC00000
    end = 0xE00000
    raw = ida_bytes.get_bytes(start, end - start) or b""
    hits = []
    i = 0
    while i < len(raw) - 8:
        v = int.from_bytes(raw[i:i + 4], "little")
        if 0xB40000 <= v < 0xB90000:
            # procura fn_ptr nos proximos 0x40 bytes
            for j in range(i + 4, min(i + 0x44, len(raw) - 4), 4):
                fv = int.from_bytes(raw[j:j + 4], "little")
                if 0x400000 <= fv < 0xA00000:
                    hits.append((start + i, start + j, v, fv))
                    break
        i += 4
    print(f"blobs name_ptr+fn_ptr: {len(hits)}", flush=True)
    # agrupa por proximidade (mesmo blob)
    blobs = []
    for h in hits:
        if blobs and h[0] - blobs[-1][-1][0] < 0x100:
            blobs[-1].append(h)
        else:
            blobs.append([h])
    print(f"blobs agrupados: {len(blobs)}", flush=True)
    for b in blobs[:20]:
        print(f"  blob @ {hex(b[0][0])}: {len(b)} entries (ex: {hex(b[0][2])}->{hex(b[0][3])})", flush=True)


if __name__ == "__main__":
    main()
