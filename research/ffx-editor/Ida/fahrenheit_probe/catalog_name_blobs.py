#!/usr/bin/env python3
"""Frente 7: cataloga os 95 blobs name_ptr+fn_ptr do .data num JSON + resumo."""
import ida_bytes
import ida_name
import json

START = 0xC00000
END = 0xE00000


def main():
    raw = ida_bytes.get_bytes(START, END - START) or b""
    pairs = []
    i = 0
    while i < len(raw) - 8:
        v = int.from_bytes(raw[i:i + 4], "little")
        if 0xB40000 <= v < 0xB90000:
            for j in range(i + 4, min(i + 0x44, len(raw) - 4), 4):
                fv = int.from_bytes(raw[j:j + 4], "little")
                if 0x400000 <= fv < 0xA00000:
                    pairs.append((START + i, v, fv))
                    break
        i += 4
    # agrupa em blobs
    blobs = []
    for p in pairs:
        if blobs and p[0] - blobs[-1][-1][0] < 0x100:
            blobs[-1].append(p)
        else:
            blobs.append([p])
    out = []
    for b in blobs:
        fn_names = []
        for _, _, fv in b[:6]:
            nm = ida_name.get_name(fv) or ""
            fn_names.append(nm[:40])
        out.append({"blob_ea": hex(b[0][0]), "entries": len(b),
                    "sample_fns": fn_names})
    with open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\name_blobs_catalog.json", "w", encoding="utf-8") as f:
        json.dump(out, f, indent=1, ensure_ascii=False)
    print(f"blobs: {len(out)}", flush=True)
    for b in out[:20]:
        print(f"  {b['blob_ea']} entries={b['entries']} fns={b['sample_fns'][:2]}", flush=True)


if __name__ == "__main__":
    main()
