#!/usr/bin/env python3
"""Procurar paths de fontes (.cpp/.h/.inl/.c) no exe — estrutura do projeto."""
import ida_bytes
import re

START = 0xB00000
END = 0xC00000
PAT = re.compile(rb"[A-Za-z0-9_./\\-]{6,}\.(?:cpp|h|inl|c|hpp|cc|cxx)(?:\s|\x00)")


def main():
    raw = ida_bytes.get_bytes(START, END - START) or b""
    hits = set()
    for m in PAT.finditer(raw):
        s = m.group().decode("ascii", "replace").strip("\x00 ")
        hits.add(s)
    print(f"paths de fonte: {len(hits)}", flush=True)
    for s in sorted(hits)[:50]:
        print(f"  {s[:110]}", flush=True)
    import json
    with open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\source_paths.json", "w", encoding="utf-8") as f:
        json.dump(sorted(hits), f, indent=1)


if __name__ == "__main__":
    main()
