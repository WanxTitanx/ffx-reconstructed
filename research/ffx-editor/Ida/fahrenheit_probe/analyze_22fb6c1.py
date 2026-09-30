#!/usr/bin/env python3
"""Analisa o pool 0x22FB6C1 (41KB): onde tem dados nao-FF?"""
import ida_bytes


def main():
    start = 0x22FB6C1
    size = 40999
    raw = ida_bytes.get_bytes(start, size) or b""
    nonff = sum(1 for b in raw if b != 0xFF)
    print(f"bytes nao-FF: {nonff}/{size} ({100*nonff//size}%)", flush=True)
    # acha regioes com dados
    chunks = []
    in_chunk = False
    cstart = 0
    for i, b in enumerate(raw):
        if b != 0xFF and not in_chunk:
            in_chunk, cstart = True, i
        elif b == 0xFF and in_chunk:
            in_chunk = False
            if i - cstart >= 16:
                chunks.append((cstart, i))
    if in_chunk:
        chunks.append((cstart, len(raw)))
    print(f"regioes com dados (>=16B): {len(chunks)}", flush=True)
    for a, b in chunks[:20]:
        print(f"  +{hex(a)}..+{hex(b)} ({b-a}B)", flush=True)


if __name__ == "__main__":
    main()
